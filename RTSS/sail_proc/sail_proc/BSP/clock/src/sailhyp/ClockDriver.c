/*
===========================================================================
*/
/**
  @file ClockDriver.c

  Interface implementation file for the clock device driver.
*/
/*
  ====================================================================

  Copyright (c) 2021 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/src/sailhyp/ClockDriver.c#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include <stdlib.h>
#include <string.h>
#include "ClockDriver.h"
#include "HALclk.h"
#include "ClockSWEVT.h"
#include "debug_log.h"
#include "busywait.h"
#include "chipinfo.h"
#include "sailbsp_mutex.h"
#include "HALhwio.h"
#include "HALclkHWIO.h"
#include "target.h"
#include "sail_csr_hwio.h"
#include "sailheap.h"
#include "pmicapi.h"
#include "common_functions.h"

/*=========================================================================
      Externs
==========================================================================*/

extern ClockBSPType ClockBSP;


/*=========================================================================
      Macros
==========================================================================*/
#define CPU_BOOTUP_VOLTAGE_CORNER     RAIL_VOLTAGE_LEVEL_NOM
#define SAIL_CPU_CLOCK_NAME           "sailss_cc_cpu_cluster0_clk"


#define CLOCK_IS_CONTROLLABLE(n, c) \
  (!CLOCK_FLAG_IS_SET(n, INTERNAL_CONTROL) || \
   CLOCK_FLAG_IS_SET(((ClockClientCtxt *)(c)), INTERNAL_CONTROL))

#define CLOCK_LOCAL_CLIENT_ID 0

#define CLOCK_PD_NAME_LEN 32

#define CLOCK_FLAG_CLEAR_INIT_MASK   ( CLOCK_FLAG_INTERNAL_CONTROL | CLOCK_FLAG_READ_ONLY |   \
                                      CLOCK_FLAG_DOMAIN_FORCE_SETTINGS )

#define CLOCK_XO_SRC_FREQ 19
/*=========================================================================
      Type Definitions
==========================================================================*/

/*
 * GetId function type.
 */
typedef ClockResult (*ClockGetIdFn) (ClockHandle, const char *, ClockIdType *);


/*=========================================================================
      Data
==========================================================================*/

/*
 * Main clock driver context.
 */
static ClockDrvCtxt Clock_DriverCtxt;
static ClockClientCtxt pClient;


/*
 * Object-specific GetId function pointers.
 */
static ClockGetIdFn ClockGetIdFunctions[] =
{
  Clock_GetSourceId,
  Clock_GetPowerDomainId,
  Clock_GetClockId,
  Clock_GetDebugMuxId,
};

/*
 * Clock Log Default Configuration.
 *
 */
ClockLogType ClockLogDefaultConfig[] =
{
  {
     .nLogSize        =  4096,
     .nGlobalLogFlags =  0x90ff
  }
};

typedef struct
{
  const char* szName;
  uint32 freq_in_mHz;
}SAILInitClocks;

static SAILInitClocks EarlyInitClocks[] =
{
    /* sailss_cc_cpu_core_clk_src RCG clock configuration */ 
    { "sailss_cc_cpu_cluster0_clk",       1593 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster0_apb_cbc_clk",  0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster0_atbd_cbc_clk", 0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster0_atbi_cbc_clk", 0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster0_cnt_cbc_clk",  0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster0_ph2_clk",      0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster1_clk",          0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_cluster1_ph2_clk",      0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_asild_noc_partial_clk",     0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_asild_noc_cpu_qx_clk",      0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram0_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram1_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram2_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram3_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram4_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_sram5_axi_clk",             0 }, //sailss_cc_cpu_core_clk_src
    { "sailss_cc_cpu_csr_clk",             100 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_tcsr_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_asilb_noc_qh_clk",          0 }, //sailss_cc_sail_noc_center_qh_clk_src
  //{ "sailss_cc_safe_apb_bdg_clk",          0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_asild_noc_qh_clk",          0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_asild_noc_wdt_clk",         0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_ipcc_core_clk",             0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_tlmm_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt0_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt1_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt2_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt3_ahb_clk",              0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt0_timer_clk",            0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt1_timer_clk",            0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt2_timer_clk",            0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_wdt3_timer_clk",            0 }, //sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_acmu0_ahb_clk",             0 }, // sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_acmu1_ahb_clk",             0 }, // sailss_cc_sail_noc_center_qh_clk_src
    { "sailss_cc_asilb_noc_apb_clk",        19 }, //sailss_cc_qdss_apb_tsctr_clk_src
    { "sailss_cc_asild_noc_tsctr_clk",       0 }, //sailss_cc_qdss_apb_tsctr_clk_src
    { "sailss_cc_apb_clk",                   0 }, //sailss_cc_qdss_apb_tsctr_clk_src
    { "sailss_cc_asilb_noc_atb_clk",        240}, //sailss_cc_qdss_atb_b_clk_src
    { "sailss_cc_asild_noc_atb_clk",          0}, //sailss_cc_qdss_atb_b_clk_src
    { "sailss_cc_asilb_noc_partial_clk",    200}, //sailss_cc_asilb_noc_qx_clk_src
    { "sailss_cc_asilb_noc_qx_clk",           0}, //sailss_cc_asilb_noc_qx_clk_src
    { "sailss_cc_asild_data_clk",             0}, //sailss_cc_asilb_noc_qx_clk_src
    { "sailss_cc_asilb_noc_qosgen_extref_clk",0}, //sailss_cc_xo_clk_src
    { "sailss_cc_xo_div4_clk",                0}, //sailss_cc_xo_clk_src
    { "sailss_cc_frq_measure_ref_clk",        0}, //sailss_cc_xo_clk_src
    { "sailss_cc_asilb_noc_qspi_ahb_clk",   166}, //sailss_cc_asilb_qspi_qh_clk_src	
    { "sailss_cc_asild_noc_bmtx_qh_clk",    100}, //sailss_cc_bmtx_noc_qh_clk_src
    { "sailss_cc_ahb_clk",                    0}, //sailss_cc_bmtx_noc_qh_clk_src
    { "sailss_cc_asild_noc_dma_clk",        400}, //sailss_cc_asild_noc_dma_clk_src
    { "sailss_cc_asild_noc_dma_apb_clk",      0}, //sailss_cc_asild_noc_dma_clk_src
    //{ "sailss_cc_debug_clk",                  0},
    { "sailss_cc_demet_clk",                  0}, //sailss_cc_pwr_ctrl_xo_clk_src
    { "sailss_cc_qupv3_wrap0_core_2x_clk",  200}, //sailss_cc_qupv3_wrap0_core_2x_clk_src
    { "sailss_cc_qupv3_wrap0_core_clk",       0}, //sailss_cc_qupv3_wrap0_core_2x_clk_src
    { "sailss_cc_lpm_ahb_clk",              200}, //sailss_cc_asild_noc_qup_clk_src
    { "sailss_cc_lpm_pram_clk",               0}, //sailss_cc_asild_noc_qup_clk_src
    { "sailss_cc_qupv3_wrap0_m_ahb_clk",      0}, //sailss_cc_asild_noc_qup_clk_src	
    { "sailss_cc_qupv3_wrap0_s_ahb_clk",      0}, //sailss_cc_asild_noc_qup_clk_src
    { "sailss_cc_asild_noc_qup_clk",          0}, //sailss_cc_asild_noc_qup_clk_src	
    {"sailss_cc_acmu0_ro_clk",               19}, //sailss_cc_acmu0_ro_clk_src, PLL5 even
    {"sailss_cc_acmu1_ro_clk",               19}, //sailss_cc_acmu1_ro_clk_src, PLL6 even
    {"sailss_cc_error_clk",                  19}, //sailss_cc_error_clk_src, PLL6 even
    { "sailss_cc_acmu0_core_clk",            19}, // sailss_cc_acmu0_core_clk_src
    { "sailss_cc_acmu1_core_clk",            19}, // sailss_cc_acmu1_core_clk_src
};

static SAILInitClocks LateInitClocks[] =
{
  { "sailss_cc_cpu_cluster0_clk",           1843}, //sailss_cc_cpu_core_clk_src
  { "sailss_cc_asilb_noc_atb_clk",           300}, //sailss_cc_qdss_atb_b_clk_src
  { "sailss_cc_asilb_noc_partial_clk",       240}, //sailss_cc_asilb_noc_qx_clk_src
  { "sailss_cc_asild_noc_dma_clk",           500}, //sailss_cc_asild_noc_dma_clk_src
};
/*=========================================================================
      Functions
==========================================================================*/

/*=========================================================================
**  Function : Clock_InsertLLNode
** =========================================================================*/
/*
  See ClockDriver.h.
*/
void Clock_InsertLLNode
(
  ClockLLNodeType **pListHead,
  ClockLLNodeType  *pNode
)
{
  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pListHead || !pNode)
  {
    return;
  }

  /*-----------------------------------------------------------------------*/
  /* Insert node at beginning of list.                                     */
  /*-----------------------------------------------------------------------*/

  pNode->pNext = *pListHead;
  *pListHead = pNode;

} /* END Clock_InsertLLNode */


/*=========================================================================
**  Function : Clock_RemoveLLNode
** =========================================================================*/
/*
  See ClockDriver.h.
*/
ClockResult Clock_RemoveLLNode
(
  ClockLLNodeType **pListHead,
  ClockLLNodeType  *pNode,
  ClockCleanupFunc  pfCleanup
)
{
  ClockLLNodeType *pTemp;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pListHead || !pNode)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Check if node being removed is positioned at the list head.           */
  /*-----------------------------------------------------------------------*/

  if (pNode == *pListHead)
  {
    *pListHead = pNode->pNext;
  }

  /*-----------------------------------------------------------------------*/
  /* Remove node by joining adjacent neighbors.                            */
  /*-----------------------------------------------------------------------*/

  else
  {
    for (pTemp = *pListHead; pTemp; pTemp = pTemp->pNext)
    {
      if (pTemp->pNext == pNode)
      {
        break;
      }
    }

    if (!pTemp)
    {
      return CLOCK_ERROR_NOT_FOUND;
    }

    else
    {
      pTemp->pNext = pNode->pNext;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Cleanup memory allocated for node.                                    */
  /*-----------------------------------------------------------------------*/

  if (pfCleanup)
  {
    pfCleanup(pNode);
  }

  return CLOCK_SUCCESS;

} /* END Clock_RemoveLLNode */


/*=========================================================================
**  Function : Clock_InvokeClientCallbacks
** =========================================================================*/
/**
  Traverses through per-resource type callback linked list & invokes client
  callbacks for a given resource ID & event type.

  @param nId                 [in] -- Resource identifier
  @param eEvent              [in] -- Event type

  @return
  None.
*/
static void Clock_InvokeClientCallbacks
(
  ClockIdType            nId,
  ClockCallbackEventType eEvent
)
{
  ClockCallbackData      pData = NULL;
  ClockCallbackNodeType *pHead, *pTemp;
  ClockIdCategoryType    nCat = CLOCK_GET_ID_CATEGORY(nId);

  ClockDrvCtxt          *pDrvCtxt = Clock_GetDrvCtxt();

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (nCat >= CLOCK_ID_CATEGORY_TOTAL ||
      eEvent >= CLOCK_CALLBACK_EVENT_NUM_TYPES)
  {
    return;
  }

  /*-----------------------------------------------------------------------*/
  /* Get the callback linked list head based on the resource type.         */
  /* NOTE: Only power domains supported currently.                         */
  /*-----------------------------------------------------------------------*/

  pHead = pDrvCtxt->pCallbacks[nCat];

  /*
   * Check if there are any callbacks in the linked list
   */
  if (pHead == NULL)
  {
    return;
  }

  /*
   * Traverse the linked list
   */
  for (pTemp = pHead; pTemp;
       pTemp = (ClockCallbackNodeType*)pTemp->LLNode.pNext)
  {
    if ((pTemp->nResourceID == nId   ) &&
        (pTemp->eEvent      == eEvent))
    {
      /* Logging */
      if (CLOCK_GLOBAL_FLAG_IS_SET(LOG_CALLBACK))
      {
        DEBUG_LOG(SAIL_DEBUG,"Callback 0x%x start for event %d and resource ID 0x%x \r\n", (uint32_t)pTemp->pfnCallback, eEvent, nId);
      }

      /* Invoke the client callback */
      pTemp->pfnCallback(
        pTemp->CallbackCtxt, pTemp->eEvent,
        pTemp->nResourceID, pData);

      /* Logging */
      if (CLOCK_GLOBAL_FLAG_IS_SET(LOG_CALLBACK))
      {
        DEBUG_LOG(SAIL_DEBUG,"Callback 0x%x end for event %d and resource ID 0x%x \r\n",
          (uint32_t)pTemp->pfnCallback, eEvent, nId);
      }
    }
  }

  return;
}

/* =========================================================================
**  Function : Clock_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @return
  CLOCK_SUCCESS -- Deinititialization was successful.
  CLOCK_ERROR -- Deinitialization failed.

  @dependencies
  None.
*/

ClockResult Clock_DriverDeInit
(
  void
)
{
  /*-----------------------------------------------------------------------*/
  /* Shut-down complete.                                                   */
  /*-----------------------------------------------------------------------*/

  return CLOCK_SUCCESS;

} /* END Clock_DriverDeInit */


/* =========================================================================
**  Function : ClockStub_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver stub.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @return
  CLOCK_SUCCESS -- Deinititialization was successful.
  CLOCK_ERROR -- Deinitialization failed.

  @dependencies
  None.
*/

ClockResult ClockStub_DriverDeInit
(
  void
)
{
  /*-----------------------------------------------------------------------*/
  /* Shut-down complete.                                                   */
  /*-----------------------------------------------------------------------*/

#if 0

  ClockClientCtxt *pClient;
  ClockPDCtxt     *pPD;
  ClockResult      eResult;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClient = (ClockClientCtxt *)hClient;
  pPD = pClient->pPD;
  CORE_VERIFY(pPD && pPD->pClients);

  /*-----------------------------------------------------------------------*/
  /* Remove client from linked list.                                       */
  /*-----------------------------------------------------------------------*/

  eResult = CLOCK_REMOVE_LL_NODE(&pPD->pClients, pClient, Clock_CleanupClient);
  CORE_VERIFY(CLOCK_SUCCESS == eResult);

  /*-----------------------------------------------------------------------*/
  /* Cleanup PD if no clients remain.                                      */
  /*-----------------------------------------------------------------------*/

  if (!pPD->pClients)
  {
    CORE_VERIFY(pDrvCtxt->pPDs);
    eResult = CLOCK_REMOVE_LL_NODE(&pDrvCtxt->pPDs, pPD, Clock_CleanupPD);
    CORE_VERIFY(CLOCK_SUCCESS == eResult);
  }

#endif


  return CLOCK_SUCCESS;

} /* END ClockStub_DriverDeInit */


/* =========================================================================
**  Function : Clock_GetClientRefCount
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockClientRefCountType * Clock_GetClientRefCount
(
  ClockHandle              hClient,
  ClockClientRefCountType *pClients
)
{
  ClockClientRefCountType *pClient;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClients)
  {
    return NULL;
  }

  /*-----------------------------------------------------------------------*/
  /* Search through linked list for this client.                           */
  /*-----------------------------------------------------------------------*/

  for (pClient = pClients; pClient; pClient = pClient->pNext)
  {
    if (pClient->hClient == hClient)
    {
      break;
    }
  }

  return pClient;

} /* END of Clock_GetClientRefCount */


/* =========================================================================
**  Function : Clock_InsertRefCountClient
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockResult Clock_InsertRefCountClient
(
  ClockHandle               hClient,
  ClockClientRefCountType **pClients
)
{
  ClockClientRefCountType *pTemp;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClients)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if client node already present in linked list.          */
  /*-----------------------------------------------------------------------*/

  for (pTemp = *pClients; pTemp; pTemp = pTemp->pNext)
  {
    if (pTemp->hClient == hClient)
    {
      return CLOCK_SUCCESS;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Create new reference count node for this client/node tuple.           */
  /*-----------------------------------------------------------------------*/

  pTemp = (ClockClientRefCountType *)sailheap_malloc(sizeof(ClockClientRefCountType));
  if (!pTemp)
  {
    return CLOCK_ERROR_INSUFFICIENT_MEMORY;
  }

  pTemp->hClient = hClient;

  /*
   * Insert into linked list.
   */
  CLOCK_INSERT_LL_NODE(pClients, pTemp);

  return CLOCK_SUCCESS;

} /* END Clock_InsertRefCountClient */


/* =========================================================================
**  Function : Clock_RemoveRefCountClient
** =========================================================================*/
/*
 * TODO
*/

ClockResult Clock_RemoveRefCountClient
(
  ClockHandle               hClient,
  ClockClientRefCountType **pClients
)
{
  ClockClientRefCountType *pTemp;
  ClockResult              eResult;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClients)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Look for client ref count in linked list.                             */
  /*-----------------------------------------------------------------------*/

  for (pTemp = *pClients; pTemp; pTemp = pTemp->pNext)
  {
    if (pTemp->hClient == hClient)
    {
      break;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Return SUCCESS if client already removed.                             */
  /*-----------------------------------------------------------------------*/

  if (!pTemp)
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Remove from linked list.                                              */
  /*-----------------------------------------------------------------------*/

  eResult = CLOCK_REMOVE_LL_NODE(pClients, pTemp, sailheap_free);
  if (eResult != CLOCK_SUCCESS)
  {
    return eResult;
  }

  return CLOCK_SUCCESS;

} /* END Clock_RemoveRefCountClient */

#if 0
/*=========================================================================
**  Function : Clock_CleanupClient
** =========================================================================*/
/**
  TODO
*/
void Clock_CleanupClient
(
  void *pData
)
{
  ClockBSPType            *pBSP = Clock_GetDrvCtxt()->pBSP;
  ClockClientCtxt         *pClient;
  ClockResult              eResult;
  uint32_t                 i;
  ClockIdType              nClockId;
  ClockIdType              nSourceId;
  ClockIdType              nPowerDomainId;
  ClockClientRefCountType *pClockRefClient;
  
  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pData)
  {
    return;
  }

  pClient = (ClockClientCtxt *)pData;

  /*-----------------------------------------------------------------------*/
  /* Release reference counting contexts for all node types.               */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < pBSP->nNumClocks; i++)
  {
    pClockRefClient = Clock_GetClientRefCount((ClockHandle)pClient,
      pBSP->aClocks[i].pClients);
    
    if (!pClockRefClient)
    {
      continue;
    }
    
    eResult = Clock_GetClockId((ClockHandle)pClient, pBSP->aClocks[i].szName, &nClockId);
      
    /*-----------------------------------------------------------------------*/
    /* Disable the clock until reference count for this client becomes 0.    */
    /*-----------------------------------------------------------------------*/
  
    while (CLOCK_REF_COUNT_TOTAL(pClockRefClient) > 0)
    {
      eResult = Clock_DisableClock((ClockHandle)pClient, nClockId);
      if (eResult != CLOCK_SUCCESS)
      {
        DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
          "Unable to disable clock[%s]: client: %s",
          pBSP->aClocks[i].szName, pClient->szName);
      }
    }
    
     /*-----------------------------------------------------------------------*/
     /* Remove refcount client type for this client in this clock node        */
     /*-----------------------------------------------------------------------*/
 
    eResult = Clock_RemoveRefCountClient((ClockHandle)pClient,
      &pBSP->aClocks[i].pClients);
    if (eResult != CLOCK_SUCCESS)
    {
      DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
        "Unable to remove ref count for clock[%s]: client: %s",
        pBSP->aClocks[i].szName, pClient->szName);
    }
  }

  for (i = 0; i < pBSP->nNumSources; i++)
  {
    pClockRefClient = Clock_GetClientRefCount((ClockHandle)pClient,
      pBSP->aSources[i]->pClients);

    if (!pClockRefClient)
    {
      continue;
    }
     
    eResult = Clock_GetSourceId((ClockHandle)pClient, pBSP->aSources[i]->szName, &nSourceId);
      
    /*-----------------------------------------------------------------------*/
    /* Disable the source until reference count for this client becomes 0.   */
    /*-----------------------------------------------------------------------*/
  
    while (CLOCK_REF_COUNT_TOTAL(pClockRefClient) > 0)
    {
      eResult = Clock_DisableSource((ClockHandle)pClient, nSourceId);
      if (eResult != CLOCK_SUCCESS)
      {
        DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
          "Unable to disable Source[%s]: client: %s",
          pBSP->aSources[i]->szName, pClient->szName);
      }
    }
    

    eResult = Clock_RemoveRefCountClient((ClockHandle)pClient,
      &pBSP->aSources[i]->pClients);
    if (eResult != CLOCK_SUCCESS)
    {
      DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
        "Unable to remove ref count for source[%s]: client: %s",
        pBSP->aSources[i]->szName, pClient->szName);
    }
  }

  for (i = 0; i < pBSP->nNumPowerDomains; i++)
  {
     pClockRefClient = Clock_GetClientRefCount((ClockHandle)pClient,
       pBSP->aPowerDomains[i].pClients);
     if (!pClockRefClient)
     {
       continue;
     }
     eResult = Clock_GetPowerDomainId((ClockHandle)pClient, pBSP->aPowerDomains[i].szName, &nPowerDomainId);
     
     /*-----------------------------------------------------------------------------*/
     /* Disable the Power Domain until reference count for this client becomes 0.   */
     /*-----------------------------------------------------------------------------*/
  
     while (CLOCK_REF_COUNT_TOTAL(pClockRefClient) > 0)
     {
       eResult = Clock_DisablePowerDomain((ClockHandle)pClient, nPowerDomainId);
       if (eResult != CLOCK_SUCCESS)
       {
         DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
           "Unable to disable PowerDomain[%s]: client: %s",
           pBSP->aPowerDomains[i].szName, pClient->szName);
       }
     }

     eResult = Clock_RemoveRefCountClient((ClockHandle)pClient,
       &pBSP->aPowerDomains[i].pClients);
     if (eResult != CLOCK_SUCCESS)
     {
       DALSYS_LogEvent(DALDEVICEID_CLOCK, DALSYS_LOGEVENT_INFO,
         "Unable to remove ref count for PowerDomain[%s]: client: %s",
         pBSP->aPowerDomains[i].szName, pClient->szName);
     }
  }

  /*-----------------------------------------------------------------------*/
  /* Release allocated memory.                                             */
  /*-----------------------------------------------------------------------*/

  if (pClient->szName)
  {
    sailheap_free(pClient->szName);
  }

  sailheap_free(pClient);

} /* END Clock_CleanupClient */


/*=========================================================================
**  Function : Clock_CleanupPD
** =========================================================================*/
/**
  TODO
*/
void Clock_CleanupPD
(
  void *pData
)
{
  ClockPDCtxt *pPD;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pData)
  {
    return;
  }

  pPD = (ClockPDCtxt *)pData;

  /*-----------------------------------------------------------------------*/
  /* Hook for image processing.                                            */
  /*-----------------------------------------------------------------------*/

  if (Clock_DestroyPDEventProcess)
  {
    Clock_DestroyPDEventProcess(pPD);
  }

  /*-----------------------------------------------------------------------*/
  /* Release allocated memory.                                             */
  /*-----------------------------------------------------------------------*/

  if (pPD->szName)
  {
    sailheap_free(pPD->szName);
  }

  sailheap_free(pPD);

} /* END Clock_CleanupPD */
#endif

/* =========================================================================
**  Function : Clock_GetId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();  
  ClockIdType   nId;
  ClockGetIdFn  fGetId;
  ClockResult   eResult;
  uint32        i;
  
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  } 

  if (!hClient || !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  for (i = 0; i < SIZEOF_ARRAY(ClockGetIdFunctions); i++)
  {
    fGetId = ClockGetIdFunctions[i];
    eResult = fGetId(hClient, szName, &nId);
    if (eResult == CLOCK_SUCCESS)
    {
      *pId = nId;
      return CLOCK_SUCCESS;
    }
  }

  *pId = CLOCK_ID_INVALID;
  return CLOCK_ERROR_NOT_FOUND;

} /* END Clock_GetId */


/* =========================================================================
**  Function : Clock_GetClockId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetClockId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockBSPType  *pBSP = pDrvCtxt->pBSP;
  ClockNodeType *pClock;
  uint32_t       nIndex;;
  ClockResult    eResult;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Search the array of clock nodes, break if we find a match             */
  /*-----------------------------------------------------------------------*/

  pClock = NULL;
  for (nIndex = 0; nIndex < pBSP->nNumClocks; nIndex++)
  {
    if (strcmp(szName, pBSP->aClocks[nIndex].szName) == 0)
    {
      pClock = &pBSP->aClocks[nIndex];
      break;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Return a pointer to the clock node if found, otherwise return NULL    */
  /*-----------------------------------------------------------------------*/

  if (pClock)
  {
    *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_CLOCK, nIndex);

    /*
     * Create ref count node for this client/clock tuple.
     */
    eResult = Clock_InsertRefCountClient(hClient, &pClock->pClients);
    return eResult;
  }
  else
  {
    *pId = CLOCK_ID_INVALID;
    return CLOCK_ERROR_NOT_FOUND;
  }

} /* END Clock_GetClockId */


/*=========================================================================
**  Function : Clock_GetClockNode
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockNodeType *Clock_GetClockNode
(
  ClockIdType ClockId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockIdCategoryType  nCat = (ClockIdCategoryType)CLOCK_GET_ID_CATEGORY(ClockId);
  uint32_t             nIdx = CLOCK_GET_ID_INDEX(ClockId);

  if (nCat == CLOCK_ID_CATEGORY_CLOCK && nIdx < pDrvCtxt->pBSP->nNumClocks)
  {
    return &pDrvCtxt->pBSP->aClocks[nIdx];
  }

  return NULL;

} /* END Clock_GetClockNode */


/*=========================================================================
**  Function : Clock_InitDFSDomain
** =========================================================================*/
/**
  Initialize a DFS domain.

  @param  *pDomain [in] -- DFS domain to initialize.

  @return
  CLOCK_SUCCESS -- Initialization was successful.
  CLOCK_ERROR -- Initialization failed.
*/

static ClockResult Clock_InitDFSDomain
(
  ClockDomainNodeType *pDomain
)
{
  HAL_clk_ClockMuxConfigType  DetectedCfg = {0};
  const ClockSourceMapType   *pSourceMap;
  ClockMuxConfigType         *pFreqConfig;
  rail_voltage_level          eVRegLevel;
  ClockResult                 eResult;
  uint32_t                    nFreqHz;
  uint32_t                    nDFSStates;
  uint32_t                    nSize;
  uint32_t                    i;
  uint32_t                    nDenom;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*
   * If DFS isn't enabled in HW, then there is nothing to do.
   */
  if (!HAL_clk_IsClockDomainDFSEnabled(&pDomain->HALDomain))
  {
    return CLOCK_SUCCESS;
  }

  CLOCK_FLAG_SET(pDomain, DFS_CONTROLLED);

  /*-----------------------------------------------------------------------*/
  /* Allocate new BSP array to store DFS configurations.                   */
  /*-----------------------------------------------------------------------*/

  nDFSStates = pDomain->HALDomain.nDFSStates;
  pDomain->nBSPLen = nDFSStates;

  nSize = nDFSStates * sizeof(ClockMuxConfigType);
  pDomain->aBSP = sailheap_malloc(nSize);
  if(NULL == pDomain->aBSP)
  {
    DEBUG_LOG(SAIL_ERROR,"Unable to allocate %d bytes for Clock DFS array. \r\n", nSize);

    return CLOCK_ERROR_INSUFFICIENT_MEMORY;
  }

  //DALSYS_memset(pDomain->aBSP, 0, nSize);
  memset(pDomain->aBSP, 0, nSize);

  /*-----------------------------------------------------------------------*/
  /* Initialize new BSP array with dynamically detected DFS configs.       */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < nDFSStates; i++)
  {
    HAL_clk_DetectDFSMuxConfig(&pDomain->HALDomain, &DetectedCfg, i);

    eResult =
      Clock_GetMappedSource(pDomain->aSourceMap, DetectedCfg.nMuxSel, &pSourceMap);
    if (eResult != CLOCK_SUCCESS || pSourceMap->nFreqHz == 0)
    {
      DEBUG_LOG(SAIL_ERROR, "Unable to map mux input to source for DFS domain. \r\n");
      return CLOCK_ERROR_INTERNAL;
    }

    nDenom = DetectedCfg.nDiv2x;
    nFreqHz = ((pSourceMap->nFreqHz * 2 + nDenom / 2) / nDenom);

    if (DetectedCfg.nM)
    {
      nDenom = DetectedCfg.nN;
      nFreqHz =
        (uint32_t)(((uint64)nFreqHz * DetectedCfg.nM + nDenom / 2) / nDenom);
    }

    eResult = Clock_GetRequiredCorner(pDomain->aFMax, nFreqHz, &eVRegLevel);
    if (eResult != CLOCK_SUCCESS)
    {
      /*
       * Frequency from boot exceeds our known max, so the fmax has most
       * likely changed. Default to Turbo until the local BSP data is
       * updated.
       */
      eVRegLevel = RAIL_VOLTAGE_LEVEL_TUR;
      DEBUG_LOG(SAIL_DEBUG,"DFS frequency exceeds known max. Assuming Turbo. \r\n");
    }

    pFreqConfig = &pDomain->aBSP[i];
    pFreqConfig->nFreqHz = nFreqHz;
    pFreqConfig->eVRegLevel = eVRegLevel;
    pFreqConfig->pSource = pSourceMap->pSource;

	//TODO - implement memscpy and use it below
    memcpy(&pFreqConfig->HALConfig, &DetectedCfg, sizeof(DetectedCfg));
  }

  return CLOCK_SUCCESS;

} /* END Clock_InitDFSDomain */


/*=========================================================================
**  Function : Clock_InitDFSDomains
** =========================================================================*/
/**
  Initialize DFS domains.

  @return
  CLOCK_SUCCESS -- Initialization was successful.
  CLOCK_ERROR -- Initialization failed.
*/

static ClockResult Clock_InitDFSDomains
(
  void
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockDomainNodeType *pDomain;
  ClockResult          eResult;
  uint32_t             i;

  for (i = 0; i < pDrvCtxt->pBSP->nNumDomains; i++)
  {
    pDomain = pDrvCtxt->pBSP->aDomains[i];
    if (pDomain->HALDomain.nDFSStates > 0)
    {
      eResult = Clock_InitDFSDomain(pDomain);
      if (eResult != CLOCK_SUCCESS)
      {
        return CLOCK_ERROR;
      }
    }
  }

  return CLOCK_SUCCESS;

} /* END Clock_InitDFSDomains */


/* =========================================================================
**  Function : Clock_EnableDFS
** =========================================================================*/
/**
  Enable DFS control for a clock domain.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to enable DFS control.
*/

ClockResult Clock_EnableDFS
(
  ClockHandle hClient,
  ClockIdType ClockId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockDomainNodeType *pDomain;
  ClockMuxConfigType  *pConfig;
  ClockNodeType       *pClock;
  ClockResult          eResult;
  uint32_t             i;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  if (!pClock->pDomain || pClock->pDomain->HALDomain.nDFSStates == 0)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  pDomain = pClock->pDomain;
  if (CLOCK_FLAG_IS_SET(pDomain, DFS_CONTROLLED))
  {
    return CLOCK_SUCCESS;
  }

  /*
   * Write DFS-supported configurations to HW.
   */
  for (i = 0; i < pDomain->nBSPLen; i++)
  {
    pConfig = &pDomain->aBSP[i];
    if (pConfig->HALConfig.nDFSIdx != 0xFF &&
        Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      HAL_clk_ConfigDFSMux(&pDomain->HALDomain, &pConfig->HALConfig);
    }
  }

  /*
   * Enable DFS control in HW.
   */
  HAL_clk_EnableDFS(&pDomain->HALDomain);

  /*
   * Now that DFS is configured and enabled in HW, initialize the driver node
   * to detect and dynamically create new BSP array from configured DFS HW
   * settings.
   */
  eResult = Clock_InitDFSDomain(pDomain);
  if (eResult != CLOCK_SUCCESS)
  {
    return CLOCK_ERROR_INTERNAL;
  }

  return CLOCK_SUCCESS;

} /* END Clock_EnableDFS */


/* =========================================================================
**  Function : Clock_InitClockDomain
** =========================================================================*/
/**
  Initializes a clock domain.

  This function initializes a clock domain, generally as a result of a call to
  Clock_EnableClockDomain().

  @param  hClient [in] -- Requesting client.
  @param *pClockDomain [in] -- Pointer to a clock domain node.

  @return
  CLOCK_SUCCESS -- The domain was successfully initialized.
  CLOCK_ERROR -- The domain was not enabled.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

ClockResult Clock_InitClockDomain
(
  ClockHandle          hClient,
  ClockDomainNodeType *pClockDomain
)
{
  ClockDrvCtxt               *pDrvCtxt = Clock_GetDrvCtxt();
  HAL_clk_ClockMuxConfigType  DetectedConfig = {0};
  HAL_clk_ClockMuxConfigType *pSafeMuxConfig;
  const ClockMuxConfigType   *pFreqConfig;
  ClockResult                 eResult;
  uint32_t                    i;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClockDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (!pClockDomain->aBSP ||
      pClockDomain->pActiveMuxConfig ||
      CLOCK_FLAG_IS_SET(pClockDomain, DFS_CONTROLLED))
  {
    return CLOCK_SUCCESS;
  }

  HAL_clk_DetectClockMuxConfig(&pClockDomain->HALDomain, &DetectedConfig);

  for (i = 0; i < pClockDomain->nBSPLen; i++)
  {
    pFreqConfig = &pClockDomain->aBSP[i];
    if (!Clock_IsBSPSupported(&pFreqConfig->HWVersion))
    {
      continue;
    }

    /*
     * Check if this configuration matches what was detected.
     */
    if (HAL_clk_IsClockMuxConfigEqual(&DetectedConfig, &pFreqConfig->HALConfig))
    {
      /*
       * If the frequency config has a source to configure, then
       * detect the source configuration as well.
       */
      if (pFreqConfig->pSource && pFreqConfig->pSourceFreqConfig)
      {
        eResult = Clock_DetectSourceConfig(pFreqConfig->pSource);
        if (eResult != CLOCK_SUCCESS)
        {
          return CLOCK_ERROR;
        }
      }

      /*
       * If there is no source component or the active source configuration
       * matches, then we've found the active domain configuration.
       */
      if (!pFreqConfig->pSource ||
          !pFreqConfig->pSourceFreqConfig ||
           pFreqConfig->pSource->pActiveFreqConfig == pFreqConfig->pSourceFreqConfig)
      {
        pClockDomain->pActiveMuxConfig = pFreqConfig;
        pClockDomain->pSource = pFreqConfig->pSource;
        break;
      }
    }
  }

  /*
   * If we didn't find a match for the detected configuration in the BSP data
   * and the detected configuration isn't the default safe configuration, then
   * return an error. Don't flag an error for the safe configuration since it
   * doesn't have any dependencies and including it in every domains BSP
   * data is expensive.
   */
  if (pClockDomain->pActiveMuxConfig == NULL)
  {
    pSafeMuxConfig = &pDrvCtxt->pBSP->SafeMuxConfig;
    if (!HAL_clk_IsClockMuxConfigEqual(&DetectedConfig, pSafeMuxConfig))
    {
      return CLOCK_ERROR;
    }
  }

  return CLOCK_SUCCESS;

} /* END Clock_InitClockDomain */


/* =========================================================================
**  Function : Clock_EnableClockDomain
** =========================================================================*/
/**
  Enables a clock domain.

  This function enables a clock domain, generally as a result of a call to
  Clock_EnableClock().

  @param  hClient [in] -- Requesting client.
  @param *pClockDomain [in] -- Pointer to a clock domain node.
  @param  nClockFlags  [in] -- Flags for any clock attributes.

  @return
  CLOCK_SUCCESS -- The domain was successfully enabled.
  CLOCK_ERROR -- The domain was not enabled.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

ClockResult Clock_EnableClockDomain
(
  ClockHandle          hClient,
  ClockDomainNodeType *pClockDomain,
  uint32_t             nClockFlags
)
{
  ClockResult          eResult;
  bool                 bSuppressibleRequest;
  ClockVRegRequestType VRegRequest;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClockDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize domain if not done yet.                                    */
  /*-----------------------------------------------------------------------*/

  if (pClockDomain->aBSP != NULL &&
      pClockDomain->pActiveMuxConfig == NULL)
  {
    eResult = Clock_InitClockDomain(hClient, pClockDomain);
    if (eResult != CLOCK_SUCCESS)
    {
      return CLOCK_ERROR_INTERNAL;
    }
  }

  /* Check if the clock or domain are suppressible */
  if ((nClockFlags & CLOCK_FLAG_SUPPRESSIBLE) != 0 ||
      CLOCK_FLAG_IS_SET(pClockDomain, SUPPRESSIBLE))
  {
    bSuppressibleRequest = true;
  }
  else
  {
    bSuppressibleRequest = false;
  }

  /*-----------------------------------------------------------------------*/
  /* Only enable on ref count transition from 0 -> 1.                      */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_REF_COUNT(pClockDomain, bSuppressibleRequest))
  {
    /* If this domain has a controllable source, enable it first */
    if (pClockDomain->pSource != NULL)
    {
      eResult = Clock_EnableSourceInternal(hClient, pClockDomain->pSource, bSuppressibleRequest);
      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }

    if (!CLOCK_FLAG_IS_SET(pClockDomain, DOMAIN_HOLD_VREG_REQUEST) &&
        pClockDomain->pActiveMuxConfig != NULL)
    {
      VRegRequest.eVRegLevel = pClockDomain->pActiveMuxConfig->eVRegLevel;

      /*
       * Voltage request is only suppressible when no required client requests
       * have been issued.
       * This first required client request will result in a required voltage
       * request to override the previously issued suppressible request.
       */
      VRegRequest.bSuppressible = bSuppressibleRequest && !CLOCK_REF_COUNT_REQ(pClockDomain);
      Clock_VoltageRequest(pClockDomain->nRailMask, &pClockDomain->VRegRequest, &VRegRequest);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Increment ref count for domain.                                       */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_INC(pClockDomain, bSuppressibleRequest);

  /*-----------------------------------------------------------------------*/
  /* Restore domain to its active configuration after enabling it, since   */
  /* it was set to a safe frequency before disabling.                      */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_REF_COUNT_TOTAL(pClockDomain) == 1 &&
      pClockDomain->pActiveMuxConfig &&
      !CLOCK_FLAG_IS_SET(pClockDomain, DFS_CONTROLLED))
  {
    HAL_clk_ConfigClockMux(&pClockDomain->HALDomain,
      &pClockDomain->pActiveMuxConfig->HALConfig);
  }

  return CLOCK_SUCCESS;

} /* END Clock_EnableClockDomain */


/* =========================================================================
**  Function : Clock_DisableClockDomain
** =========================================================================*/
/**
  Disables a clock domain.

  This function disables a clock domain, generally as a result of a call to
  Clock_DisableClock().

  @param  hClient [in] -- Requesting client.
  @param *pClockDomain [in] -- Pointer to a clock domain node.
  @param  nClockFlags  [in] -- Flags for any clock attributes.

  @return
  CLOCK_SUCCESS -- The domain was successfully disabled.
  CLOCK_ERROR -- The domain was not disabled.

  @dependencies
  The clock mutex must be locked prior to calling this function.
*/

ClockResult Clock_DisableClockDomain
(
  ClockHandle          hClient,
  ClockDomainNodeType *pClockDomain,
  uint32_t             nClockFlags
)
{
  ClockDrvCtxt         *pDrvCtxt = Clock_GetDrvCtxt();
  ClockResult           eResult;
  bool                  bSuppressibleRequest;
  ClockVRegRequestType  VRegRequest;
  uint32_t              nTimeout = 0;
  bool                  bIsOn;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pClockDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /* Check if the clock or domain are suppressible */
  if ((nClockFlags & CLOCK_FLAG_SUPPRESSIBLE) != 0 ||
      CLOCK_FLAG_IS_SET(pClockDomain, SUPPRESSIBLE))
  {
    bSuppressibleRequest = true;
  }
  else
  {
    bSuppressibleRequest = false;
  }

  if (CLOCK_REF_COUNT_TOTAL(pClockDomain) == 1)
  {

    /*-----------------------------------------------------------------------*/
    /* In some cases when disabling the last clock in a domain that is       */
    /* configured to a low frequency, it can take extra time for the clock   */
    /* root to receive the "off" signal.  If the "off" signal has not been   */
    /* received before switching the domain to the safe configuration, the   */
    /* clock domain can be left in an unexpected state and lock up during    */
    /* the switch. To avoid reconfiguring the domain root before it receives */
    /* the "off" signal, if there are no more clocks enabled in this domain, */
    /* wait for the root-off signal from HW.                                 */
    /*                                                                       */
    /* If this "off" signal has not been received before the source is       */
    /* turned off, the clock domain can be left in an unexpected state,      */
    /* causing a hang when switching the domain frequency.  To avoid         */
    /* disabling the source before the clock domain receives this off signal,*/
    /* if there are no more clocks enabled in this domain, wait for the      */
    /*root-off signal from HW.                                               */
    /*-----------------------------------------------------------------------*/

    if (CLOCK_FLAG_IS_SET(pClockDomain, DOMAIN_WAIT_FOR_ROOT_OFF))
    {
      if (HAL_clk_IsClockDomainSupported(&pClockDomain->HALDomain, HAL_CLK_CLOCK_DOMAIN_API_ISON))
      {
        bIsOn = HAL_clk_IsClockDomainOn(&pClockDomain->HALDomain);

        while ((bIsOn == true) && (nTimeout++ < 150000))
        {
          //DALSYS_BusyWait(1);
          busywait(1);
          bIsOn = HAL_clk_IsClockDomainOn(&pClockDomain->HALDomain);
        }

        if (nTimeout == 150000)
        {
          DEBUG_LOG(SAIL_ERROR, "Clock domain root did not turn off after all domain clocks are off \r\n");
          return CLOCK_ERROR_INTERNAL;
        }
      }
    }

    /*
     * Set domain to a safe configuration prior to disabling it to ensure
     * source and voltage dependencies are satisfied if some other entity
     * (HW or SW) enables it without our knowledge.
     */
    if (pClockDomain->pActiveMuxConfig &&
        !CLOCK_FLAG_IS_SET(pClockDomain, DFS_CONTROLLED))
    {
      HAL_clk_ConfigClockMux(&pClockDomain->HALDomain, &pDrvCtxt->pBSP->SafeMuxConfig);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Only disable on ref count transition from 1 -> 0.                     */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_REF_COUNT(pClockDomain, bSuppressibleRequest) == 1)
  {
    /*
     * We disable the source for the last insuppressible clock even if
     * another suppressible clock is still enabled because we need to keep
     * reference counting within the source.
     */
    if (pClockDomain->pSource != NULL)
    {
      eResult = Clock_DisableSourceInternal(hClient, pClockDomain->pSource,
        bSuppressibleRequest);
      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }

    /*
     * If there is no suppressible reference count, just remove the voltage
     * request. If there is a suppressible reference count, then update the
     * voltage request to be suppressible.
     */
    if (!CLOCK_FLAG_IS_SET(pClockDomain, DOMAIN_HOLD_VREG_REQUEST) &&
        pClockDomain->pActiveMuxConfig != NULL)
    {
      if (!CLOCK_REF_COUNT(pClockDomain, !bSuppressibleRequest))
      {
        VRegRequest.eVRegLevel = RAIL_VOLTAGE_LEVEL_OFF;
        VRegRequest.bSuppressible = bSuppressibleRequest;
      }
      else
      {
        VRegRequest.eVRegLevel = pClockDomain->pActiveMuxConfig->eVRegLevel;
        VRegRequest.bSuppressible = !bSuppressibleRequest;
      }

      Clock_VoltageRequest(pClockDomain->nRailMask, &pClockDomain->VRegRequest, &VRegRequest);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Decrement ref count for domain.                                       */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_DEC(pClockDomain, bSuppressibleRequest);

  return CLOCK_SUCCESS;

} /* END Clock_DisableClockDomain */


/* =========================================================================
**  Function : Clock_EnableClock
** =========================================================================*/
/*
  Clock_EnableEx implementation for ClockNodeType.
*/

ClockResult Clock_EnableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  ClockResult              eResult;
  bool                     bIsOn;
  //uint32_t                 nTimeout = 0;
  ClockDrvCtxt            *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType           *pClock;
  ClockClientRefCountType *pClientRefCount;
  bool                     bSuppressibleRequest;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Get reference count for this client.                                  */
  /*-----------------------------------------------------------------------*/

  pClientRefCount = Clock_GetClientRefCount(hClient, pClock->pClients);
  if (!pClientRefCount)
  {
    DEBUG_LOG(SAIL_ERROR, "Unable to find client for source \r\n");

    return CLOCK_ERROR_INTERNAL;
  }

  /*-----------------------------------------------------------------------*/
  /* Get reference counts for this client and clock.                       */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  /*-----------------------------------------------------------------------*/
  /* Only enable on ref count transition from 0 -> 1.                      */
  /*-----------------------------------------------------------------------*/

  bSuppressibleRequest = CLOCK_FLAG_IS_SET(pClock, SUPPRESSIBLE) ||
                         CLOCK_FLAG_IS_SET(pClock->pDomain, SUPPRESSIBLE);
  if (!CLOCK_REF_COUNT(pClock, bSuppressibleRequest))
  {
    /* Enable the domain first */
    eResult = Clock_EnableClockDomain(pDrvCtxt->hClient,
      pClock->pDomain, pClock->nFlags);
    if (eResult != CLOCK_SUCCESS)
    {
      mutex_unlock(&pDrvCtxt->hLock);
      return CLOCK_ERROR_INTERNAL;
    }

    /* Enable the clock */
    HAL_clk_EnableClock(&pClock->HALClock);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_STATE_CHANGE) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_STATE_CHANGE))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Enabled: 1) \r\n", pClock->szName);
    }

    /* Determine whether this clock supports "IsOn" API functionality */
    if (!CLOCK_API_FLAG_IS_SET(nFlags, ENABLE, DONT_WAIT_FOR_CLOCK_ON) &&
        HAL_clk_IsClockSupported(&pClock->HALClock, HAL_CLK_CLOCK_API_ISON))
    {
      bIsOn = HAL_clk_IsClockOn(&pClock->HALClock);

      /* Wait for the clock to turn ON */
      //while (!bIsOn && nTimeout++ < 150)
      /* disp hf clock takes longer than 1000us */
      while (!bIsOn)
      {
        //DALSYS_BusyWait(1);
    	busywait(1);
        bIsOn = HAL_clk_IsClockOn(&pClock->HALClock);
      }

      /* Return error if the clock does not turn ON */
      if(!bIsOn)
      {
        DEBUG_LOG(SAIL_ERROR,"Unable to turn ON clock: %s. \r\n", pClock->szName);
        mutex_unlock(&pDrvCtxt->hLock);
        return CLOCK_ERROR;
      }
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Increment ref count for client and clock.                             */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_INC(pClock, bSuppressibleRequest);
  CLOCK_REF_COUNT_INC(pClientRefCount, bSuppressibleRequest);

  /*-----------------------------------------------------------------------*/
  /* Log clock enable event                                                */
  /*-----------------------------------------------------------------------*/

  Clock_SWEvent(
    CLOCK_EVENT_CLOCK_STATUS,
    3,
    pClock->nUniqueId,
    1, CLOCK_REF_COUNT_TOTAL(pClock));

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_EnableClock */


/* =========================================================================
**  Function : Clock_DisableClock
** =========================================================================*/
/*
  Clock_DisableEx implementation for ClockNodeType.
*/

ClockResult Clock_DisableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  ClockResult              eResult;
  ClockDrvCtxt            *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType           *pClock;
  ClockClientRefCountType *pClientRefCount;
  bool                     bSuppressibleRequest;
  bool                     bIsOn;
  uint32_t                 nTimeout = 0;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if the clock should not be disabled.                    */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_FLAG_IS_SET(pClock, DO_NOT_DISABLE) ||
      CLOCK_GLOBAL_FLAG_IS_SET(DO_NOT_DISABLE_CLOCKS))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Get reference count for this client.                                  */
  /*-----------------------------------------------------------------------*/

  pClientRefCount = Clock_GetClientRefCount(hClient, pClock->pClients);
  if (!pClientRefCount)
  {
    DEBUG_LOG(SAIL_ERROR,"Unable to find client(%x) for source: %s.", 
              hClient, pClock->szName);


    return CLOCK_ERROR_INTERNAL;
  }

  mutex_lock(&pDrvCtxt->hLock);


  /*-----------------------------------------------------------------------*/
  /* Short-circuit if client doesn't have outstanding enable requests.     */
  /*-----------------------------------------------------------------------*/

  bSuppressibleRequest = CLOCK_FLAG_IS_SET(pClock, SUPPRESSIBLE) ||
                         CLOCK_FLAG_IS_SET(pClock->pDomain, SUPPRESSIBLE);
  if (!CLOCK_REF_COUNT(pClientRefCount, bSuppressibleRequest))
  {
    mutex_unlock(&pDrvCtxt->hLock);
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Only disable on ref count transition from 1 -> 0.                     */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_REF_COUNT(pClock, bSuppressibleRequest) == 1)
  {
    /* Disable the clock */
    HAL_clk_DisableClock(&pClock->HALClock);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_STATE_CHANGE) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_STATE_CHANGE))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Enabled: 0) \r\n", pClock->szName);
    }

    if (CLOCK_API_FLAG_IS_SET(nFlags, DISABLE, WAIT_FOR_CLOCK_OFF) &&
        HAL_clk_IsClockSupported(&pClock->HALClock, HAL_CLK_CLOCK_API_ISON))
    {
      bIsOn = HAL_clk_IsClockOn(&pClock->HALClock);

      /* Wait for the clock to turn OFF */
      while (bIsOn && nTimeout++ < 150)
      {
        //DALSYS_BusyWait(1);
    	busywait(1);
        bIsOn = HAL_clk_IsClockOn(&pClock->HALClock);
      }

      /* Log a warning if the clock does not OFF */
      if (bIsOn)
      {
        DEBUG_LOG(SAIL_ERROR,"Unable to turn OFF clock: %s. \r\n", pClock->szName);
      }
    }

    /* Disable the domain */
    eResult = Clock_DisableClockDomain(pDrvCtxt->hClient,
      pClock->pDomain, pClock->nFlags);

    if (eResult != CLOCK_SUCCESS)
    {
      mutex_unlock(&pDrvCtxt->hLock);
      return CLOCK_ERROR_INTERNAL;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Decrement client ref count if non-zero.                               */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_DEC(pClientRefCount, bSuppressibleRequest);
  CLOCK_REF_COUNT_DEC(pClock, bSuppressibleRequest);

  /*-----------------------------------------------------------------------*/
  /* Log clock disable event                                               */
  /*-----------------------------------------------------------------------*/

  Clock_SWEvent(
    CLOCK_EVENT_CLOCK_STATUS,
    3,
    pClock->nUniqueId,
    0, CLOCK_REF_COUNT_TOTAL(pClock));

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_DisableClock */


/* =========================================================================
**  Function : Clock_FindClockConfig
** =========================================================================*/
/*
  See ClockDriver.h.
*/

ClockResult Clock_FindClockConfig
(
  ClockDomainNodeType *pDomain,
  uint32_t             nFreqHz,
  ClockFrequencyType   eMatch,
  ClockMuxConfigType **pMatchingConfig
)
{
  uint32_t            nAtLeastFrequency = 0xFFFFFFFF;
  ClockMuxConfigType *pAtLeastConfig = NULL;
  uint32_t            nAtMostFrequency = 0;
  ClockMuxConfigType *pAtMostConfig = NULL;
  ClockMuxConfigType *pMaxConfig = NULL;
  uint32_t            nMaxFrequency = 0;
  ClockMuxConfigType *pBSPConfig;
  uint32_t            i;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pDomain || !pMatchingConfig)
  {
    return CLOCK_ERROR;
  }

  /* Loop over all configurations */
  for (i = 0; i < pDomain->nBSPLen; i++)
  {
    pBSPConfig = &pDomain->aBSP[i];

    /*
     * Skip configurations that aren't for this chip or version.
     */
    if (!Clock_IsBSPSupported(&pBSPConfig->HWVersion))
    {
      continue;
    }

    /* Stop if we find an exact match */
    if (pBSPConfig->nFreqHz == nFreqHz)
    {
      *pMatchingConfig = pBSPConfig;
      return CLOCK_SUCCESS;
    }

    /*
     * Update the maximum frequency seen so far
     */
    if (pBSPConfig->nFreqHz > nMaxFrequency)
    {
      nMaxFrequency = pBSPConfig->nFreqHz;
      pMaxConfig = pBSPConfig;
    }

    /* Look for the lowest at-least frequency */
    if ((pBSPConfig->nFreqHz > nFreqHz) &&
        (pBSPConfig->nFreqHz < nAtLeastFrequency))
    {
      nAtLeastFrequency = pBSPConfig->nFreqHz;
      pAtLeastConfig = pBSPConfig;
    }
    /* Look for the highest at-most frequency */
    else if ((pBSPConfig->nFreqHz < nFreqHz) &&
             (pBSPConfig->nFreqHz > nAtMostFrequency))
    {
      nAtMostFrequency = pBSPConfig->nFreqHz;
      pAtMostConfig = pBSPConfig;
    }
  }

  /* Select a config based on the match criteria */
  switch (eMatch)
  {
    case CLOCK_FREQUENCY_HZ_AT_LEAST:
      if (pAtLeastConfig != NULL)
      {
        *pMatchingConfig = pAtLeastConfig;
        return CLOCK_SUCCESS;
      }
      break;

    case CLOCK_FREQUENCY_HZ_AT_MOST:
      if (pAtMostConfig != NULL)
      {
        *pMatchingConfig = pAtMostConfig;
        return CLOCK_SUCCESS;
      }
      break;

    case CLOCK_FREQUENCY_HZ_CLOSEST:
      if ((pAtLeastConfig != NULL) && (pAtMostConfig == NULL))
      {
        *pMatchingConfig = pAtLeastConfig;
        return CLOCK_SUCCESS;
      }
      else if ((pAtMostConfig != NULL) && (pAtLeastConfig == NULL))
      {
        *pMatchingConfig = pAtMostConfig;
        return CLOCK_SUCCESS;
      }
      else if ((pAtLeastConfig != NULL) && (pAtMostConfig != NULL))
      {
        /* Select the closest match, select the lowest in case of a tie */
        if ((nAtLeastFrequency - nFreqHz) < (nFreqHz - nAtMostFrequency))
        {
          *pMatchingConfig = pAtLeastConfig;
          return CLOCK_SUCCESS;
        }
        else
        {
          *pMatchingConfig = pAtMostConfig;
          return CLOCK_SUCCESS;
        }
      }
      break;

    case CLOCK_FREQUENCY_HZ_AT_LEAST_OR_MAX:
      if (pAtLeastConfig != NULL)
      {
        *pMatchingConfig = pAtLeastConfig;
        return CLOCK_SUCCESS;
      }
      else if (pMaxConfig != NULL)
      {
        *pMatchingConfig = pMaxConfig;
        return CLOCK_SUCCESS;
      }
      break;

    default:
      break;
  }

  /* No match was found */
  *pMatchingConfig = NULL;

  return CLOCK_ERROR;

} /* END Clock_FindClockConfig */


/* =========================================================================
**  Function : Clock_SetClockConfig
** =========================================================================*/
/*
  See ClockDriver.h.
*/

ClockResult Clock_SetClockConfig
(
  ClockHandle          hClient,
  ClockDomainNodeType *pDomain,
  ClockMuxConfigType  *pNewConfig
)
{
  ClockDrvCtxt             *pDrvCtxt = Clock_GetDrvCtxt();
  ClockSourceNodeType      *pNewSource;
  ClockResult               eResult;
  bool                      bVoltageRequest;
  bool                      bSlewing;
  bool                      bStub;
  ClockVRegRequestType      VRegRequest;
  const ClockMuxConfigType *pActiveConfig;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !pDomain || !pNewConfig)
  {
    return CLOCK_ERROR;
  }
  if (CLOCK_FLAG_IS_SET(pDomain, STUB_HW_RUMI) &&
      (PlatformInfo_Platform() == PLATFORMINFO_TYPE_RUMI ||
       PlatformInfo_Platform() == PLATFORMINFO_TYPE_VIRTIO))
  {
    bStub = true;
  }
  else
  {
    bStub = false;
  }

  pActiveConfig = pDomain->pActiveMuxConfig;

  /*
   * If the domain is currently disabled, just update the domain's active
   * configuration without updating the RCG since disabled domains are parked
   * in a safe configuration. The new configuration will be applied when
   * enabling the domain.
   *
   * The domain's source will not be configured when being enabled, so that
   * configuration needs to happen here.
   */
  if (CLOCK_REF_COUNT_TOTAL(pDomain)== 0)
  {
    pDomain->pSource = pNewConfig->pSource;
    pDomain->pActiveMuxConfig = pNewConfig;
    if (pDomain->pSource && pNewConfig->pSourceFreqConfig)
    {
      eResult = Clock_ConfigSource(pDomain->pSource, pNewConfig->pSourceFreqConfig);
      if (eResult != CLOCK_SUCCESS)
      {
        return CLOCK_ERROR_INTERNAL;
      }
    }

    return CLOCK_SUCCESS;
  }

  /*
   * Determine if we should make a voltage request.  We do so if this
   * domain is not configured to make requests when enabled, or if it
   * is thus configured and is currently enabled.
   */
  bVoltageRequest = !CLOCK_FLAG_IS_SET(pDomain, DOMAIN_HOLD_VREG_REQUEST);

  /*
   * Voltage requests to make if necessary.
   */
  VRegRequest.eVRegLevel = pNewConfig->eVRegLevel;
  VRegRequest.bSuppressible = (CLOCK_REF_COUNT_REQ(pDomain) == 0);

  /*
   * If we are increasing the voltage requirement, do so now.
   */
  if ((bVoltageRequest == true) &&
      (pNewConfig->eVRegLevel > pDomain->VRegRequest.eVRegLevel))
  {
    Clock_VoltageRequest(pDomain->nRailMask, &pDomain->VRegRequest, &VRegRequest);
  }

  pNewSource = pNewConfig->pSource;

  bSlewing =
    (pActiveConfig &&
     pNewConfig->pSourceFreqConfig != pActiveConfig->pSourceFreqConfig &&
     pNewSource == pDomain->pSource);
  if (bSlewing)
  {
    /*
     * Slewing to different PLL outputs isn't supported, since the driver
     * doesn't know the divider configurations for the dividers based on
     * the mux select in the domain and thus can't determine proper sequencing.
     */
    if (pNewConfig->HALConfig.nMuxSel != pActiveConfig->HALConfig.nMuxSel)
    {
      return CLOCK_ERROR_INTERNAL;
    }

    /*
     * If the domain divider is increasing, then it needs to be updated
     * before slewing the PLL to prevent temporarily slewing above
     * the target frequency.
     */
    if (!CLOCK_FLAG_IS_SET(pDomain, DFS_CONTROLLED) &&
        pNewConfig->HALConfig.nDiv2x > pActiveConfig->HALConfig.nDiv2x &&
        !bStub)
    {
      HAL_clk_ConfigClockMux(&pDomain->HALDomain, &pNewConfig->HALConfig);
    }
  }

  /*
   * Configure the source if required.
   */
  if (pNewSource != NULL && pNewConfig->pSourceFreqConfig != NULL)
  {
    eResult = Clock_ConfigSource(pNewSource, pNewConfig->pSourceFreqConfig);
    if (eResult != CLOCK_SUCCESS)
    {
      // TODO error!
      return eResult;
    }
  }

  /*
   * If the domain is active, and the new source is different from the
   * current one then we enable the new source.
   */
  if (pDomain->pSource != pNewSource &&
      pNewSource != NULL)
  {
    /*
     * If there are insuppressible clocks enabled in this clock domain then we
     * need to make an insuppressible request on the new source.
     */
    if (CLOCK_REF_COUNT_REQ(pDomain) > 0)
    {
      eResult = Clock_EnableSourceInternal(pDrvCtxt->hClient, pNewSource, false);
      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }

    /*
     * If there are suppressible clocks enabled in this clock domain then we
     * need to make a suppressible request on the new source.
     */
    if (CLOCK_REF_COUNT_SUPP(pDomain) > 0)
    {
      eResult = Clock_EnableSourceInternal(pDrvCtxt->hClient, pNewSource, true);
      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }
  }

  /*
   * Configure the clock MUX
   */
  if (!CLOCK_FLAG_IS_SET(pDomain, DFS_CONTROLLED) &&
      (!bSlewing ||
       pNewConfig->HALConfig.nDiv2x <= pActiveConfig->HALConfig.nDiv2x) &&
      !bStub)
  {
    HAL_clk_ConfigClockMux(&pDomain->HALDomain, &pNewConfig->HALConfig);
  }

  /*
   * If we are decreasing the voltage requirement, do so now.
   */
  if ((bVoltageRequest == true) &&
      (pNewConfig->eVRegLevel < pDomain->VRegRequest.eVRegLevel))
  {
    Clock_VoltageRequest(pDomain->nRailMask, &pDomain->VRegRequest, &VRegRequest);
  }

  /*
   * If the domain is active, and the new source is different from the
   * current then we disable the old source.
   */
  if (pDomain->pSource != pNewSource &&
      pDomain->pSource != NULL)
  {
    /*
     * If there are insuppressible clocks enabled in this clock domain then we
     * need to remove the insuppressible request on the old source.
     */
    if (CLOCK_REF_COUNT_REQ(pDomain) > 0)
    {
      eResult = Clock_DisableSourceInternal(pDrvCtxt->hClient, pDomain->pSource, false);

      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }

    /*
     * If there are suppressible clocks enabled in this clock domain then we
     * need to remove the suppressible request on the old source.
     */
    if (CLOCK_REF_COUNT_SUPP(pDomain) > 0)
    {
      eResult = Clock_DisableSourceInternal(pDrvCtxt->hClient, pDomain->pSource, true);

      if (eResult != CLOCK_SUCCESS)
      {
        return eResult;
      }
    }
  }

  /*
   * Free previous configuration if it was dynamically allocated.
   */
  if (CLOCK_FLAG_IS_SET(pDomain, DOMAIN_DYNAMIC_CONFIG) &&
      pDomain->pActiveMuxConfig != pNewConfig)
  {
    CLOCK_FLAG_CLEAR(pDomain, DOMAIN_DYNAMIC_CONFIG);
    sailheap_free((void *)pDomain->pActiveMuxConfig);
  }

  /* Link the domain node to the new source node and update the active config */
  pDomain->pSource = pNewSource;
  pDomain->pActiveMuxConfig = pNewConfig;

  return CLOCK_SUCCESS;

} /* END Clock_SetClockConfig */


/* =========================================================================
**  Function : Clock_SetClockFrequency
** =========================================================================*/
/*
  Clock_SetFrequencyEx implementation for ClockNodeType.
*/

ClockResult Clock_SetClockFrequency
(
  ClockHandle         hClient,
  ClockIdType         ClockId,
  uint32_t            nFreq,
  ClockFrequencyType  eMatch,
  uint32_t           *pnResultFreq
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType       *pClock;
  ClockDomainNodeType *pDomain;
  ClockMuxConfigType  *pNewConfig = NULL;
  ClockResult          eResult;
  uint32_t             nFreqHz;
  uint32_t             nMult;
  uint32_t             nResultFreq;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pDomain = pClock->pDomain;

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  if (pDomain == NULL)
  {
    return CLOCK_ERROR_INTERNAL;
  }

  if (pDomain->aBSP == NULL)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  /* Initialize the output parameter */
  if (pnResultFreq != NULL)
  {
    *pnResultFreq = 0;
  }

  /* Convert to Hz if necessary. */
  if (eMatch >= CLOCK_FREQUENCY_MHZ_AT_LEAST)
  {
    nMult = 1000000;
    nFreqHz = nFreq * 1000000;
    eMatch -= CLOCK_FREQUENCY_MHZ_AT_LEAST;
  }
  else if (eMatch >= CLOCK_FREQUENCY_KHZ_AT_LEAST)
  {
    nMult = 1000;
    nFreqHz = nFreq * 1000;
    eMatch -= CLOCK_FREQUENCY_KHZ_AT_LEAST;
  }
  else
  {
    nMult = 1;
    nFreqHz = nFreq;
  }

  /* Look for a valid configuration */
  eResult = Clock_FindClockConfig(pDomain, nFreqHz, eMatch,
                                  &pNewConfig);

  if ((eResult != CLOCK_SUCCESS) || (pNewConfig == NULL))
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  mutex_lock(&pDrvCtxt->hLock);

  /* If the new config is the same as the active config, we're done */
  nResultFreq = 0;
  if (pNewConfig != pDomain->pActiveMuxConfig)
  {
    eResult = Clock_SetClockConfig(hClient, pDomain, pNewConfig);
    if (eResult == CLOCK_SUCCESS)
    {
      nResultFreq = pNewConfig->nFreqHz / nMult;

      if (CLOCK_FLAG_IS_SET(pClock, LOG_FREQ_CHANGE) ||
          CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_FREQ_CHANGE))
      {
        DEBUG_LOG(SAIL_DEBUG,"%s (Freq: %d) \r\n",
                pClock->szName, pNewConfig->nFreqHz);
      }

      /*
       * Only send out SW event when successful.
       */
      Clock_SWEvent(
        CLOCK_EVENT_CLOCK_FREQ,
        2,
        pClock->nUniqueId,
        ((nResultFreq) * nMult) );
    }
    else
    {
      eResult = CLOCK_ERROR_INTERNAL;
    }
  }
  else
  {
    nResultFreq = pDomain->pActiveMuxConfig->nFreqHz / nMult;
  }

  if (pnResultFreq != NULL)
  {
    *pnResultFreq = nResultFreq;
  }

  mutex_unlock(&pDrvCtxt->hLock);

  return eResult;

} /* END Clock_SetClockFrequency */


/* =========================================================================
**  Function : Clock_SetClockDivider
** =========================================================================*/
/*
  Clock_SetDivider implementation for ClockNodeType.
*/

ClockResult Clock_SetClockDivider
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nDivider
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Configure the hardware divider.                                       */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  HAL_clk_ConfigClockDivider(&pClock->HALClock, nDivider);

  /* Logging */
  if (CLOCK_FLAG_IS_SET(pClock, LOG_CONFIG_CHANGE) ||
      CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_CONFIG_CHANGE))
  {
    DEBUG_LOG(SAIL_ERROR,"%s (Clock Divider: %d) \r\n",
            pClock->szName, nDivider);
  }

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_SetClockDivider */

/* =========================================================================
**  Function : Clock_ResetClock
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_ResetBlock
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (CLOCK_GET_ID_CATEGORY(ClockId) != CLOCK_ID_CATEGORY_CLOCK)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Reset clock.                                                          */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  if (eReset == CLOCK_RESET_ASSERT || eReset == CLOCK_RESET_PULSE)
  {
    HAL_clk_ResetClock(&pClock->HALClock, true);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_RESET) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_RESET))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Reset: 1) \r\n", pClock->szName);
    }
  }

  if (eReset == CLOCK_RESET_DEASSERT || eReset == CLOCK_RESET_PULSE)
  {
    HAL_clk_ResetClock(&pClock->HALClock, false);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_RESET) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_RESET))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Reset: 0) \r\n", pClock->szName);
    }
  }

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_ResetClock */


/* =========================================================================
**  Function : Clock_ResetClockBranch
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_Reset
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (CLOCK_GET_ID_CATEGORY(ClockId) != CLOCK_ID_CATEGORY_CLOCK)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Reset clock.                                                          */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  if (eReset == CLOCK_RESET_ASSERT || eReset == CLOCK_RESET_PULSE)
  {
    HAL_clk_ResetClockBranch(&pClock->HALClock, true);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_RESET) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_RESET))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (ResetBranch: 1) \r\n", pClock->szName);
    }
  }

  if (eReset == CLOCK_RESET_DEASSERT || eReset == CLOCK_RESET_PULSE)
  {
    HAL_clk_ResetClockBranch(&pClock->HALClock, false);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pClock, LOG_RESET) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_RESET))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (ResetBranch: 0) \r\n", pClock->szName);
    }
  }

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_ResetClockBranch */


/* =========================================================================
**  Function : Clock_IsClockEnabled
** =========================================================================*/
/*
  Clock_IsEnabled implementation for ClockNodeType.
*/

ClockResult Clock_IsClockEnabled
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsEnabled
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId || !pbIsEnabled)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);

  /*-----------------------------------------------------------------------*/
  /* Initialize the output argument here.                                  */
  /*-----------------------------------------------------------------------*/

  *pbIsEnabled = false;

  /*-----------------------------------------------------------------------*/
  /* Get state from the HAL.                                               */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  *pbIsEnabled = HAL_clk_IsClockEnabled(&pClock->HALClock);

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_IsClockEnabled */


/* =========================================================================
**  Function : Clock_IsClockOn
** =========================================================================*/
/*
  Clock_IsOn implementation for ClockNodeType.
*/

ClockResult Clock_IsClockOn
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsOn
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId || !pbIsOn)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the output argument here.                                  */
  /*-----------------------------------------------------------------------*/

  *pbIsOn = false;

  /*-----------------------------------------------------------------------*/
  /* Get state from the HAL.                                               */
  /*-----------------------------------------------------------------------*/
  mutex_lock(&pDrvCtxt->hLock);

  *pbIsOn = HAL_clk_IsClockOn(&pClock->HALClock);

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_IsClockOn */


/* =========================================================================
**  Function : Clock_IsPowerDomainOn
** =========================================================================*/
/*
  Clock_IsOn implementation for ClockPowerDomainNodeType.
*/

ClockResult Clock_IsPowerDomainOn
(
  ClockHandle  hClient,
  ClockIdType  PowerDomainId,
  bool        *pbIsOn
)
{
  ClockDrvCtxt             *pDrvCtxt = Clock_GetDrvCtxt();
  ClockPowerDomainNodeType *pPowerDomain;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !PowerDomainId || !pbIsOn)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pPowerDomain = Clock_GetPowerDomainNode(PowerDomainId);
  if (!pPowerDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the output argument here.                                  */
  /*-----------------------------------------------------------------------*/

  *pbIsOn = false;

  /*-----------------------------------------------------------------------*/
  /* Get state from the HAL.                                               */
  /*-----------------------------------------------------------------------*/

  mutex_lock(&pDrvCtxt->hLock);

  *pbIsOn = HAL_clk_IsPowerDomainOn(&pPowerDomain->HALPowerDomain);

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_IsPowerDomainOn */


/* =========================================================================
**  Function : Clock_GetClockFrequency
** =========================================================================*/
/*
  Clock_GetFrequency implementation for ClockNodeType.
*/

ClockResult Clock_GetClockFrequency
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId || !pnFrequencyHz)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (!pClock->pDomain)
  {
    return CLOCK_ERROR_INTERNAL;
  }

  if (pClock->pDomain->pActiveMuxConfig)
  {
    *pnFrequencyHz = pClock->pDomain->pActiveMuxConfig->nFreqHz;
    return CLOCK_SUCCESS;
  }

  *pnFrequencyHz = 0;
  return CLOCK_ERROR_NOT_INITIALIZED;

} /* END Clock_GetClockFrequency */

/* =========================================================================
**  Function : Clock_GetDebugMuxId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetDebugMuxId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  ClockDrvCtxt *pDrvCtxt = Clock_GetDrvCtxt();
  ClockBSPType *pBSP = pDrvCtxt->pBSP;
  uint32_t      nIndex;
  bool          bFound;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Search the array of clock nodes, break if we find a match             */
  /*-----------------------------------------------------------------------*/

  bFound = false;

  for (nIndex = 0; nIndex < pBSP->nNumDebugMuxes; nIndex++)
  {
    if (strcmp(szName, pBSP->aDebugMuxes[nIndex]->szName) == 0)
    {
      bFound = true;
      break;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Return a pointer to the clock node if found, otherwise return NULL    */
  /*-----------------------------------------------------------------------*/

  if (bFound)
  {
    *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_DEBUGMUX, nIndex);
    return CLOCK_SUCCESS;
  }
  else
  {
    *pId = CLOCK_ID_INVALID;
    return CLOCK_ERROR_NOT_FOUND;
  }

} /* END Clock_GetDebugMuxId */


/*=========================================================================
**  Function : DebugMux_GetDebugMuxNode
** =========================================================================*/
/**
  See DebugMuxDriver.h
*/

ClockDebugMuxType *Clock_GetDebugMuxNode
(
  ClockIdType DebugMuxId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockIdCategoryType  nCat = (ClockIdCategoryType)CLOCK_GET_ID_CATEGORY(DebugMuxId);
  uint32_t             nIdx = CLOCK_GET_ID_INDEX(DebugMuxId);

  if (nCat == CLOCK_ID_CATEGORY_DEBUGMUX &&
      nIdx < pDrvCtxt->pBSP->nNumDebugMuxes)
  {
    return pDrvCtxt->pBSP->aDebugMuxes[nIdx];
  }

  return NULL;

} /* END Clock_GetDebugMuxNode */


/*=========================================================================
**  Function : Clock_GetDebugMuxInputDiv
** =========================================================================*/
/**
  Get the divider applied to the specific mux input.

  @param *pDebugMux        [in] -- Pointer to debug mux.
  @param  nMuxSel          [in] -- Mux select value for which to return the divider.

  @return
  Divide value applied to input specified by nMuxSel.

  @dependencies
  None.
*/

static uint32_t Clock_GetDebugMuxInputDiv
(
  ClockDebugMuxType *pDebugMux,
  uint32_t           nMuxSel
)
{
  ClockDebugMuxInputDivType *pInputDiv;

  if (!pDebugMux || !pDebugMux->anInputDivs)
  {
    return 1;
  }

  for (pInputDiv = pDebugMux->anInputDivs;
       pInputDiv->nMuxSel != CLOCK_DEBUG_MUX_INPUT_DIV_END;
       pInputDiv++)
  {
    if (pInputDiv->nMuxSel == nMuxSel)
    {
      return MAX(1, pInputDiv->nDivider);
    }
  }

  return 1;

} /* END Clock_GetDebugMuxInputDiv */


/* =========================================================================
**  Function : Clock_MeasureDebugMuxInput
** =========================================================================*/
/*
  Clock_MeasureFrequencyEx implementation for ClockDebugMuxType.
*/

ClockResult Clock_MeasureDebugMuxInput
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t     nDebugMuxSel,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt      *pDrvCtxt = Clock_GetDrvCtxt();
  uint32_t           nMultiplier;
  ClockDebugMuxType *pDebugMux;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId || !pnFrequencyHz)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pDebugMux = Clock_GetDebugMuxNode(ClockId);
  if (!pDebugMux)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Configure requested mux.                                              */
  /*-----------------------------------------------------------------------*/

  nMultiplier = MAX(1, pDebugMux->nDivider);
  nMultiplier *= Clock_GetDebugMuxInputDiv(pDebugMux, nDebugMuxSel);

  HAL_clk_ConfigDebugMux(&pDebugMux->HALDebugMux, nDebugMuxSel);

  /*-----------------------------------------------------------------------*/
  /* Configure parent muxes.                                               */
  /*-----------------------------------------------------------------------*/

  for (; pDebugMux->pParent != NULL; pDebugMux = pDebugMux->pParent)
  {
    nMultiplier *= MAX(1, pDebugMux->pParent->nDivider);
    nMultiplier *= Clock_GetDebugMuxInputDiv(pDebugMux->pParent,
      pDebugMux->nParentSel);

    HAL_clk_ConfigDebugMux(&pDebugMux->pParent->HALDebugMux,
      pDebugMux->nParentSel);
  }

  /*-----------------------------------------------------------------------*/
  /* Calculate frequency.                                                  */
  /*-----------------------------------------------------------------------*/

  HAL_clk_CalcDebugMuxFreq(&pDebugMux->HALDebugMux, pnFrequencyHz);
  *pnFrequencyHz *= nMultiplier;

  return CLOCK_SUCCESS;

} /* END Clock_MeasureDebugMuxInput */


/* =========================================================================
**  Function : Clock_MeasureClockFrequency
** =========================================================================*/
/*
  Clock_MeasureFrequencyEx implementation for ClockNodeType.
*/

ClockResult Clock_MeasureClockFrequency
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockIdType    DebugMuxId;
  ClockNodeType *pClock;
  ClockResult    eResult;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (pClock->pDebugMux == NULL ||
      pClock->HALClock.nDebugMuxSel == HAL_CLK_NO_DEBUG_MUX_SEL)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  eResult = Clock_GetDebugMuxId(pDrvCtxt->hClient, pClock->pDebugMux->szName,
    &DebugMuxId);
  if (eResult != CLOCK_SUCCESS)
  {
    return eResult;
  }

  return Clock_MeasureDebugMuxInput(
    hClient,
    DebugMuxId,
    pClock->HALClock.nDebugMuxSel,
    pnFrequencyHz);

} /* END Clock_MeasureClockFrequency */


/* =========================================================================
**  Function : Clock_GetPowerDomainId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetPowerDomainId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  ClockDrvCtxt             *pDrvCtxt = Clock_GetDrvCtxt();
  ClockBSPType             *pBSP = Clock_GetDrvCtxt()->pBSP;
  ClockPowerDomainNodeType *pPowerDomain;
  ClockResult               eResult;
  uint32_t                  nIndex;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient|| !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Search the array of power domain nodes, break if we find a match      */
  /*-----------------------------------------------------------------------*/

  pPowerDomain = NULL;
  for (nIndex = 0; nIndex < pBSP->nNumPowerDomains; nIndex++)
  {
    if (strcmp(szName, pBSP->aPowerDomains[nIndex].szName) == 0)
    {
      pPowerDomain = &pBSP->aPowerDomains[nIndex];
      break;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Return a pointer to the power domain node if found, otherwise NULL    */
  /*-----------------------------------------------------------------------*/

  if (pPowerDomain)
  {
    *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_POWERDOMAIN, nIndex);

    /*
     * Create ref count node for this client/powerdomain tuple.
     */
    eResult = Clock_InsertRefCountClient(hClient, &pPowerDomain->pClients);
    return eResult;
  }
  else
  {
    *pId = CLOCK_ID_INVALID;
    return CLOCK_ERROR_NOT_FOUND;
  }

} /* END Clock_GetPowerDomainId */


/*=========================================================================
**  Function : Clock_GetPowerDomainNode
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockPowerDomainNodeType *Clock_GetPowerDomainNode
(
  ClockIdType PowerDomainId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockIdCategoryType  nCat = (ClockIdCategoryType)CLOCK_GET_ID_CATEGORY(PowerDomainId);
  uint32_t             nIdx = CLOCK_GET_ID_INDEX(PowerDomainId);

  if (nCat == CLOCK_ID_CATEGORY_POWERDOMAIN &&
      nIdx < pDrvCtxt->pBSP->nNumPowerDomains)
  {
    return &pDrvCtxt->pBSP->aPowerDomains[nIdx];
  }

  return NULL;

} /* END Clock_GetPowerDomainNode */


/* =========================================================================
**  Function : Clock_EnablePowerDomain
** =========================================================================*/
/*
  Clock_EnableEx implementation for ClockPowerDomainNodeType.
*/

ClockResult Clock_EnablePowerDomain
(
  ClockHandle hClient,
  ClockIdType PowerDomainId
)
{
  ClockDrvCtxt             *pDrvCtxt = Clock_GetDrvCtxt();
  ClockPowerDomainNodeType *pPowerDomain;
  ClockClientRefCountType  *pClientRefCount;
  bool                      bSuppressibleRequest;
  ClockVRegRequestType      VRegRequest;
  ClockResult               eResult;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !PowerDomainId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pPowerDomain = Clock_GetPowerDomainNode(PowerDomainId);
  if (!pPowerDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pPowerDomain, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Get reference count for this client.                                  */
  /*-----------------------------------------------------------------------*/

  pClientRefCount = Clock_GetClientRefCount(hClient, pPowerDomain->pClients);
  if (!pClientRefCount)
  {
    DEBUG_LOG(SAIL_ERROR,"Unable to find client(%x) for power domain: %s. \r\n", hClient, pPowerDomain->szName);
    return CLOCK_ERROR_INTERNAL;
  }

  mutex_unlock(&pDrvCtxt->hLock);

  /*-----------------------------------------------------------------------*/
  /* Only enable on ref count transition from 0 -> 1.                      */
  /*-----------------------------------------------------------------------*/

  bSuppressibleRequest = CLOCK_FLAG_IS_SET(pPowerDomain, SUPPRESSIBLE);
  if (!CLOCK_REF_COUNT(pPowerDomain, bSuppressibleRequest))
  {
    /*
     * Check if a client has registered for pre-enable callbacks
     */
    if (pPowerDomain->nCallbackCount)
    {
      Clock_InvokeClientCallbacks(
        PowerDomainId, CLOCK_CALLBACK_EVENT_PRE_ENABLE);
    }

    /*
     * Request MOL (minimum operating level) on the parent rail
     * before enabling the power domain.
     */
    if (pPowerDomain->nRailMask)
    {
      VRegRequest.eVRegLevel = RAIL_VOLTAGE_LEVEL_MIN_SVS;
      VRegRequest.bSuppressible = bSuppressibleRequest;

      eResult = Clock_VoltageRequest(pPowerDomain->nRailMask,
        &pPowerDomain->VRegRequest, &VRegRequest);
      if (eResult != CLOCK_SUCCESS)
      {
    	mutex_unlock(&pDrvCtxt->hLock);
        return CLOCK_ERROR_INTERNAL;
      }
    }

    /*
     * Enable the power domain.
     */
    HAL_clk_EnablePowerDomain(&pPowerDomain->HALPowerDomain);

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pPowerDomain, LOG_STATE_CHANGE) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_POWER_DOMAIN_STATE_CHANGE))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Enabled: 1) \r\n", pPowerDomain->szName);
    }

    /*
     * Check if a client has registered for post-enable callbacks
     */
    if (pPowerDomain->nCallbackCount)
    {
      Clock_InvokeClientCallbacks(
        PowerDomainId, CLOCK_CALLBACK_EVENT_POST_ENABLE);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Increment ref counts.                                                 */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_INC(pClientRefCount, bSuppressibleRequest);
  CLOCK_REF_COUNT_INC(pPowerDomain, bSuppressibleRequest);

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_EnablePowerDomain */


/* =========================================================================
**  Function : Clock_DisablePowerDomain
** =========================================================================*/
/*
  Clock_DisableEx implementation for ClockPowerDomainNodeType.
*/

ClockResult Clock_DisablePowerDomain
(
  ClockHandle hClient,
  ClockIdType PowerDomainId
)
{
  ClockDrvCtxt             *pDrvCtxt = Clock_GetDrvCtxt();
  ClockPowerDomainNodeType *pPowerDomain;
  ClockClientRefCountType  *pClientRefCount;
  bool                      bSuppressibleRequest;
  ClockVRegRequestType      VRegRequest;
  boolean                   bResult;
  ClockResult               eResult;
  
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !PowerDomainId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pPowerDomain = Clock_GetPowerDomainNode(PowerDomainId);
  if (!pPowerDomain)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pPowerDomain, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if the clock should not be disabled.                    */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_FLAG_IS_SET(pPowerDomain, DO_NOT_DISABLE) ||
      CLOCK_GLOBAL_FLAG_IS_SET(DO_NOT_DISABLE_POWER_DOMAINS))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Get reference count for this client.                                  */
  /*-----------------------------------------------------------------------*/

  pClientRefCount = Clock_GetClientRefCount(hClient, pPowerDomain->pClients);
  if (!pClientRefCount)
  {
    DEBUG_LOG(SAIL_ERROR,"Unable to find client(%x) for power domain: %s. \r\n", hClient, pPowerDomain->szName);
    return CLOCK_ERROR_INTERNAL;
  }

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if client doesn't have any outstanding enable requests. */
  /*-----------------------------------------------------------------------*/

  bSuppressibleRequest = CLOCK_FLAG_IS_SET(pPowerDomain, SUPPRESSIBLE);
  if (!CLOCK_REF_COUNT(pClientRefCount, bSuppressibleRequest))
  {
    return CLOCK_SUCCESS;
  }

  mutex_lock(&pDrvCtxt->hLock);

  /*-----------------------------------------------------------------------*/
  /* Only disable on ref count transition from 1 -> 0.                     */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_REF_COUNT(pPowerDomain, bSuppressibleRequest) == 1)
  {
    /*
     * Check if a client has registered for pre-disable callbacks
     */
    if (pPowerDomain->nCallbackCount)
    {
      Clock_InvokeClientCallbacks(
        PowerDomainId, CLOCK_CALLBACK_EVENT_PRE_DISABLE);
    }

    HAL_clk_DisablePowerDomain(&pPowerDomain->HALPowerDomain);

    /*
     * Check if a client has registered for post-disable callbacks
     */
    if (pPowerDomain->nCallbackCount)
    {
      Clock_InvokeClientCallbacks(
        PowerDomainId, CLOCK_CALLBACK_EVENT_POST_DISABLE);
    }

    /*
     * Remove vote on the parent rail.
     */
    if (pPowerDomain->nRailMask)
    {
      /*
       * Wait for power domain to turn off before removing the parent vote,
       * since the rail is still required during the collapse sequence.
       */
      bResult = HAL_clk_WaitForPowerDomainOff(&pPowerDomain->HALPowerDomain);
      if (!bResult)
      {
        return CLOCK_ERROR_INTERNAL;
      }

      VRegRequest.eVRegLevel = RAIL_VOLTAGE_LEVEL_OFF;
      VRegRequest.bSuppressible = bSuppressibleRequest;

      eResult = Clock_VoltageRequest(pPowerDomain->nRailMask,
        &pPowerDomain->VRegRequest, &VRegRequest);
      if (eResult != CLOCK_SUCCESS)
      {
    	mutex_unlock(&pDrvCtxt->hLock);
        return CLOCK_ERROR_INTERNAL;
      }
    }

    /* Logging */
    if (CLOCK_FLAG_IS_SET(pPowerDomain, LOG_STATE_CHANGE) ||
        CLOCK_GLOBAL_FLAG_IS_SET(LOG_POWER_DOMAIN_STATE_CHANGE))
    {
      DEBUG_LOG(SAIL_DEBUG,"%s (Enabled: 0) \r\n", pPowerDomain->szName);
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Decrement ref counts.                                                 */
  /*-----------------------------------------------------------------------*/

  CLOCK_REF_COUNT_DEC(pClientRefCount, bSuppressibleRequest);
  CLOCK_REF_COUNT_DEC(pPowerDomain, bSuppressibleRequest);

  mutex_unlock(&pDrvCtxt->hLock);

  return CLOCK_SUCCESS;

} /* END Clock_DisablePowerDomain */


/* =========================================================================
**  Function : Clock_ConfigureClock
** =========================================================================*/
/*
  Clock_Configure implementation for ClockNodeType.
*/

ClockResult Clock_ConfigureClock
(
  ClockHandle     hClient,
  ClockIdType     ClockId,
  ClockConfigType eConfig
)
{
  ClockResult    eResult = CLOCK_SUCCESS;
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockNodeType *pClock;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !ClockId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pClock = Clock_GetClockNode(ClockId);
  if (!pClock)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pClock, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /*-----------------------------------------------------------------------*/
  /* Handle request.                                                       */
  /*-----------------------------------------------------------------------*/

  mutex_lock(&pDrvCtxt->hLock);

  switch (eConfig)
  {
    case CLOCK_CONFIG_HW_CTL_ON:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_HW_CTL_ON);
      break;

    case CLOCK_CONFIG_HW_CTL_OFF:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_HW_CTL_OFF);
      break;

    case CLOCK_CONFIG_MEM_CORE_FORCE_ON:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_CORE_FORCE_ON);
      break;

    case CLOCK_CONFIG_MEM_CORE_DONT_FORCE_ON:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_CORE_DONT_FORCE_ON);
      break;

    case CLOCK_CONFIG_MEM_PERIPH_FORCE_ON:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_PERIPH_FORCE_ON);
      break;

    case CLOCK_CONFIG_MEM_PERIPH_DONT_FORCE_ON:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_PERIPH_DONT_FORCE_ON);
      break;

    case CLOCK_CONFIG_MEM_PERIPH_FORCE_OFF:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_PERIPH_FORCE_OFF);
      break;

    case CLOCK_CONFIG_MEM_PERIPH_DONT_FORCE_OFF:
      HAL_clk_ConfigClock(&pClock->HALClock, HAL_CLK_CONFIG_MEM_PERIPH_DONT_FORCE_OFF);
      break;

    case CLOCK_CONFIG_DFS_ENABLE:
      eResult = Clock_EnableDFS(hClient, ClockId);
      break;

    default:
      eResult = CLOCK_ERROR_NOT_SUPPORTED;
  }

  mutex_unlock(&pDrvCtxt->hLock);

  return eResult;

} /* END Clock_ConfigureClock */

/* =========================================================================
**  Function : Clock_GetSourceId
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetSourceId
(
  ClockHandle  hClient,
  const char  *szName,
  ClockIdType *pId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockBSPType        *pBSP = pDrvCtxt->pBSP;
  ClockSourceNodeType *pSource;
  ClockResult          eResult;
  uint32_t             nIndex;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !szName || !pId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Search the array of source nodes, break if we find a match            */
  /*-----------------------------------------------------------------------*/

  pSource = NULL;
  for (nIndex = 0; nIndex < pBSP->nNumSources; nIndex++)
  {
    if (strcmp(szName, pBSP->aSources[nIndex]->szName) == 0)
    {
      pSource = pBSP->aSources[nIndex];
      break;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Return a pointer to the source node if found, otherwise return NULL   */
  /*-----------------------------------------------------------------------*/

  if (pSource)
  {
    *pId = CLOCK_MAKE_ID(CLOCK_ID_CATEGORY_SOURCE, nIndex);

    /*
     * Create ref count node for this client/source tuple.
     */
    eResult = Clock_InsertRefCountClient(hClient, &pSource->pClients);
    return eResult;
  }
  else
  {
    *pId = CLOCK_ID_INVALID;
    return CLOCK_ERROR_NOT_FOUND;
  }

} /* END Clock_GetSourceId */


/*=========================================================================
**  Function : Source_GetSourceNode
** =========================================================================*/
/**
  See SourceDriver.h
*/

ClockSourceNodeType *Clock_GetSourceNode
(
  ClockIdType SourceId
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockIdCategoryType  nCat = (ClockIdCategoryType)CLOCK_GET_ID_CATEGORY(SourceId);
  uint32_t             nIdx = CLOCK_GET_ID_INDEX(SourceId);

  if (nCat == CLOCK_ID_CATEGORY_SOURCE && nIdx < pDrvCtxt->pBSP->nNumSources)
  {
    return pDrvCtxt->pBSP->aSources[nIdx];
  }

  return NULL;

} /* END Clock_GetSourceNode */


/* =========================================================================
**  Function : Clock_EnableSource
** =========================================================================*/
/*
  Clock_EnableEx implementation for ClockSourceNodeType.
*/

ClockResult Clock_EnableSource
(
  ClockHandle hClient,
  ClockIdType SourceId
)
{
  ClockResult          eResult;
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockSourceNodeType *pSource;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !SourceId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pSource = Clock_GetSourceNode(SourceId);
  if (!pSource)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pSource, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  mutex_lock(&pDrvCtxt->hLock);

  eResult = Clock_EnableSourceInternal(hClient, pSource, CLOCK_FLAG_IS_SET(pSource, SUPPRESSIBLE));

  mutex_unlock(&pDrvCtxt->hLock);

  return eResult;

} /* END Clock_EnableSource */


/* =========================================================================
**  Function : Clock_DisableSource
** =========================================================================*/
/*
  Clock_DisableEx implementation for ClockSourceNodeType.
*/

ClockResult Clock_DisableSource
(
  ClockHandle hClient,
  ClockIdType SourceId
)
{
  ClockResult          eResult;
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockSourceNodeType *pSource;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !SourceId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pSource = Clock_GetSourceNode(SourceId);
  if (!pSource)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pSource, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  mutex_lock(&pDrvCtxt->hLock);

  eResult = Clock_DisableSourceInternal(hClient, pSource, CLOCK_FLAG_IS_SET(pSource, SUPPRESSIBLE));

  mutex_unlock(&pDrvCtxt->hLock);

  return eResult;

} /* END Clock_DisableSource */


/* =========================================================================
**  Function : Clock_SetSourceFrequency
** =========================================================================*/
/*
  Clock_SetFrequencyEx implementation for ClockSourceNodeType.
*/

ClockResult Clock_SetSourceFrequency
(
  ClockHandle         hClient,
  ClockIdType         SourceId,
  uint32_t            nFreq,
  ClockFrequencyType  eMatch,
  uint32_t           *pnResultFreq
)
{
  const ClockSourceFreqConfigType *pNewConfig = NULL;
  ClockDrvCtxt                    *pDrvCtxt = Clock_GetDrvCtxt();
  ClockSourceNodeType             *pSource;
  ClockResult                      eResult;
  uint32_t                         nFreqHz;
  uint32_t                         nMult;
  uint32_t                         nResultFreq;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !SourceId)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pSource = Clock_GetSourceNode(SourceId);
  if (!pSource)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Verify client has permissions.                                        */
  /*-----------------------------------------------------------------------*/

  if (!CLOCK_IS_CONTROLLABLE(pSource, hClient))
  {
    return CLOCK_ERROR_NOT_ALLOWED;
  }

  /* Initialize output parameter */
  if (pnResultFreq != NULL)
  {
    *pnResultFreq = 0;
  }

  /* Convert to Hz if necessary. */
  if (eMatch >= CLOCK_FREQUENCY_MHZ_AT_LEAST)
  {
    nMult = 1000000;
    nFreqHz = nFreq * 1000000;
    eMatch -= CLOCK_FREQUENCY_MHZ_AT_LEAST;
  }
  else if (eMatch >= CLOCK_FREQUENCY_KHZ_AT_LEAST)
  {
    nMult = 1000;
    nFreqHz = nFreq * 1000;
    eMatch -= CLOCK_FREQUENCY_KHZ_AT_LEAST;
  }
  else
  {
    nMult = 1;
    nFreqHz = nFreq;
  }

  /* Look for a valid configuration */
  eResult =
    Clock_FindSourceConfig(
      pSource->aBSP,
      pSource->nBSPLen,
      nFreqHz,
      eMatch,
      &pNewConfig);

  if ((eResult != CLOCK_SUCCESS) || (pNewConfig == NULL))
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  mutex_lock(&pDrvCtxt->hLock);

  nResultFreq = 0;

  /* If the new config is the same as the active config, we're done */
  if (pNewConfig != pSource->pActiveFreqConfig)
  {
    eResult = Clock_ConfigSource(pSource, pNewConfig);
    if (eResult == CLOCK_SUCCESS)
    {
      nResultFreq = pNewConfig->nFreqHz / nMult;

      if (CLOCK_FLAG_IS_SET(pSource, LOG_FREQ_CHANGE) ||
          CLOCK_GLOBAL_FLAG_IS_SET(LOG_CLOCK_FREQ_CHANGE))
      {
        DEBUG_LOG(SAIL_DEBUG,"%s (Freq: %d) \r\n",
          pSource->szName, pNewConfig->nFreqHz);
      }

      /*
       * Only send out SW event when successful.
       */
      Clock_SWEvent(
        CLOCK_EVENT_SOURCE_FREQ,
        2,
        0, /* TODO: log source identifier */
        nResultFreq * nMult);
    }
    else
    {
      eResult = CLOCK_ERROR_INTERNAL;
    }
  }
  else
  {
    nResultFreq = pSource->pActiveFreqConfig->nFreqHz;
  }

  if (pnResultFreq != NULL)
  {
    *pnResultFreq = nResultFreq;
  }

  mutex_unlock(&pDrvCtxt->hLock);
  return eResult;

} /* END Clock_SetSourceFrequency */


/* =========================================================================
**  Function : Clock_GetSourceFrequency
** =========================================================================*/
/*
  Clock_GetFrequency implementation for ClockSourceNodeType.
*/

ClockResult Clock_GetSourceFrequency
(
  ClockHandle  hClient,
  ClockIdType  SourceId,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt        *pDrvCtxt = Clock_GetDrvCtxt();
  ClockSourceNodeType *pSource;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!hClient || !SourceId || !pnFrequencyHz)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate clock resource id.                                           */
  /*-----------------------------------------------------------------------*/

  pSource = Clock_GetSourceNode(SourceId);
  if (!pSource)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  if (pSource->pActiveFreqConfig != NULL)
  {
    *pnFrequencyHz = pSource->pActiveFreqConfig->nFreqHz;
    return CLOCK_SUCCESS;
  }

  *pnFrequencyHz = 0;
  return CLOCK_ERROR_NOT_INITIALIZED;

} /* END Clock_GetSourceFrequency */

/*=========================================================================
**  Function : Clock_IsBSPSupported
** =========================================================================*/
/**
 *
  See ClockDriver.h
*/

bool Clock_IsBSPSupported
(
  const ClockHWVersionType *pHWVersion
)
{
  uint32_t                 nHWVersion, nHWMaxVersion, nHWMinVersion;
  ChipInfoIdType 	     eChipId;
  const ChipInfoIdType *aeChipInfoId;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pHWVersion)
  {
    return false;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate chip family. If not provided then we do not check.           */
  /*-----------------------------------------------------------------------*/

  if ( (pHWVersion->eChipInfoFamily != 0) &&
       (pHWVersion->eChipInfoFamily != ChipInfo_GetChipFamily()) )
  {
    return false;
  }

  /*-----------------------------------------------------------------------*/
  /* Ensure the specific chip ID is supported.                             */
  /*-----------------------------------------------------------------------*/

  aeChipInfoId = pHWVersion->aeChipInfoId;

  if (aeChipInfoId != NULL)
  {
    eChipId = ChipInfo_GetChipId();

    while (*aeChipInfoId < CHIPINFO_NUM_IDS)
    {
      if (eChipId == *aeChipInfoId)
      {
        break;
      }

      aeChipInfoId++;
    }

    if (*aeChipInfoId == CHIPINFO_NUM_IDS)
    {
      return false;
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Get the actual hardware revision.                                     */
  /*-----------------------------------------------------------------------*/

  nHWVersion = HAL_clk_GetChipVersion();

  nHWMinVersion =
    CHIPINFO_VERSION(pHWVersion->Min.nMajor, pHWVersion->Min.nMinor);
  nHWMaxVersion =
    CHIPINFO_VERSION(pHWVersion->Max.nMajor, pHWVersion->Max.nMinor);

  /*-----------------------------------------------------------------------*/
  /* No chip version data implies support in all HW versions.              */
  /*-----------------------------------------------------------------------*/

  if ( (nHWMinVersion == 0) && (nHWMaxVersion == 0) )
  {
    return true;
  }

  /*-----------------------------------------------------------------------*/
  /* Validate the HW version falls within the min/max.                     */
  /*-----------------------------------------------------------------------*/

  if ( (nHWVersion >= nHWMinVersion) && (nHWVersion < nHWMaxVersion) )
  {
    return true;
  }
  else
  {
    return false;
  }
}


/*=========================================================================
**  Function : Clock_GetDomainNumPerfLevels
** =========================================================================*/
/**
  See ClockDriver.h
*/

uint32_t Clock_GetDomainNumPerfLevels
(
  ClockDomainNodeType *pDomain
)
{
  ClockMuxConfigType  *pConfig;
  uint32               i;
  uint32               nNumLevels = 0;

  if (!pDomain || !pDomain->aBSP)
  {
    return 0;
  }

  for (i = 0; i < pDomain->nBSPLen; i++)
  {
    pConfig = &pDomain->aBSP[i];
    if (Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      nNumLevels++;
    }
  }

  return nNumLevels;
}


/*=========================================================================
**  Function : Clock_GetDomainPerfLevelConfig
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockMuxConfigType *Clock_GetDomainPerfLevelConfig
(
  ClockDomainNodeType *pDomain,
  uint32               nPerfLevel
)
{
  ClockMuxConfigType  *pConfig;
  uint32               i;
  uint32               nCurLevel;

  if (!pDomain || !pDomain->aBSP)
  {
    return NULL;
  }

  for (i = 0, nCurLevel = 0; i < pDomain->nBSPLen; i++)
  {
    pConfig = &pDomain->aBSP[i];
    if (Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      if (nCurLevel == nPerfLevel)
      {
        return pConfig;
      }

      nCurLevel++;
    }
  }

  return NULL;
}


/* =========================================================================
**  Function : Clock_QueryClock
** =========================================================================*/
/**
  Clock_Query implementation for ClockNodeType.
*/

ClockResult Clock_QueryClock
(
  ClockHandle            hClient,
  ClockIdType            ClockId,
  ClockQueryType         eQuery,
  uint32_t               nPerfLevel,
  ClockQueryResultType  *pResult
)
{
  ClockNodeType       *pClock;
  ClockDomainNodeType *pDomain;
  ClockMuxConfigType  *pFreqConfig;
  const char          *szName = "";
  ClockBSPType        *pBSP = Clock_GetDrvCtxt()->pBSP;
  uint8_t              i, nCount;

  pClock = Clock_GetClockNode(ClockId);
  if (!hClient || !pClock || !pResult)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pDomain = pClock->pDomain;
  if (!pDomain)
  {
    return CLOCK_ERROR_INTERNAL;
  }

  pResult->eType = eQuery;

  /*-----------------------------------------------------------------------*/
  /* Handle top-level object queries.                                      */
  /*-----------------------------------------------------------------------*/

  switch (eQuery)
  {
    case CLOCK_QUERY_NUM_PERF_LEVELS:
      pResult->Data.nNumPerfLevels = Clock_GetDomainNumPerfLevels(pDomain);
      return CLOCK_SUCCESS;

    case CLOCK_QUERY_RAIL_NAME:
        for (i = 0, nCount = 0; i < pBSP->nNumRails && i < CLOCK_MAX_RAIL_INDICES; i++)
        {
          /* Skip rails not included in mask */
          if (!CLOCK_RAIL_MASK_SET(pDomain->nRailMask, i))
          {
            continue;
          }
          /* Stop if found the desired rail instance in bit mask */
          if (nCount == nPerfLevel)
          {
            szName = pBSP->aRails[i]->szName;
            break;
          }
          /* Keep searching for next rail in mask */
          nCount++;
        }

        sailbsp_strlcpy(pResult->Data.szRailName, szName, CLOCK_MAX_NAME_LEN);
        return CLOCK_SUCCESS;

    case CLOCK_QUERY_DFS_ENABLED:
      pResult->Data.bDFSEnabled =
        HAL_clk_IsClockDomainDFSEnabled(&pDomain->HALDomain);
      return CLOCK_SUCCESS;

    case CLOCK_QUERY_REF_COUNT:
      pResult->Data.nRefCount = CLOCK_REF_COUNT_TOTAL(pClock);
      return CLOCK_SUCCESS;

    default:
      break;
  }

  /*-----------------------------------------------------------------------*/
  /* Handle performance level queries.                                     */
  /*-----------------------------------------------------------------------*/

  pFreqConfig = Clock_GetDomainPerfLevelConfig(pDomain, nPerfLevel);
  if (!pFreqConfig)
  {
    return CLOCK_ERROR_NOT_SUPPORTED;
  }

  switch (eQuery)
  {
    case CLOCK_QUERY_PERF_LEVEL_FREQ_HZ:
      pResult->Data.nPerfLevelFreqHz = pFreqConfig->nFreqHz;
      break;

    case CLOCK_QUERY_PERF_LEVEL_CORNER:
      pResult->Data.ePerfLevelCorner = pFreqConfig->eVRegLevel;
      break;

    case CLOCK_QUERY_PERF_LEVEL_DFS_IDX:
      pResult->Data.nPerfLevelDFSIdx = pFreqConfig->HALConfig.nDFSIdx;
      break;

    case CLOCK_QUERY_PERF_LEVEL_SRC_NAME:
      if (pFreqConfig->pSource)
      {
        szName = pFreqConfig->pSource->szName;
      }
      if((sailbsp_strlcpy(pResult->Data.szPerfLevelSrcName, szName, CLOCK_MAX_NAME_LEN)) >= CLOCK_MAX_NAME_LEN)
      {
        return CLOCK_ERROR_INTERNAL;
      }
      break;

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

  return CLOCK_SUCCESS;

} /* END Clock_QueryClock */


/* =========================================================================
**  Function : Clock_GetHighestFreqConfig
** =========================================================================*/
/**
  Get the highest frequency configuration supported by domain.

  @param *pDomain[in] -- Pointer to a clock domain.

  @return
  Non-NULL  -- Highest configuration found.
  NULL      -- No supported configurations found.

  @dependencies
  None.
*/

static ClockMuxConfigType * Clock_GetHighestFreqConfig
(
  ClockDomainNodeType *pDomain
)
{
  ClockMuxConfigType  *pConfig;
  int32                i;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pDomain || !pDomain->aBSP)
  {
    return NULL;
  }

  for (i = pDomain->nBSPLen - 1; i >= 0; i--)
  {
    pConfig = &pDomain->aBSP[i];
    if (Clock_IsBSPSupported(&pConfig->HWVersion))
    {
      return pConfig;
    }
  }

  return NULL;

}; /* END Clock_GetHighestFreqConfig */

/* =========================================================================
**  Function : Clock_GetRequiredCorner
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockResult Clock_GetRequiredCorner
(
  const ClockFMaxType *aFMax,
  uint32_t             nFreqHz,
  rail_voltage_level  *peVRegLevel
)
{
  const ClockFMaxType *pFMax;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!aFMax || !peVRegLevel)
  {
    return CLOCK_ERROR;
  }

  for (pFMax = aFMax; pFMax->nMaxFreqHz; pFMax++)
  {
    if (!Clock_IsBSPSupported(&pFMax->HWVersion))
    {
      continue;
    }

    if (pFMax->nMaxFreqHz >= nFreqHz)
    {
      *peVRegLevel = pFMax->eVRegLevel;
      return CLOCK_SUCCESS;
    }
  }

  return CLOCK_ERROR;

} /* END Clock_GetRequiredCorner */


/* =========================================================================
**  Function : Clock_GetMappedSource
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockResult Clock_GetMappedSource
(
  const ClockSourceMapType   *aSourceMap,
  uint32_t                    nMuxSel,
  const ClockSourceMapType  **pMatchingSourceMap
)
{
  const ClockSourceMapType *pSourceMap;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!aSourceMap || !pMatchingSourceMap)
  {
    return CLOCK_ERROR;
  }

  for (pSourceMap = aSourceMap;
       pSourceMap->nMuxSel != CLOCK_SOURCE_MAP_END; pSourceMap++)
  {
    if (!Clock_IsBSPSupported(&pSourceMap->HWVersion))
    {
      continue;
    }

    if (pSourceMap->nMuxSel == nMuxSel)
    {
      *pMatchingSourceMap = pSourceMap;
      return CLOCK_SUCCESS;
    }
  }

  return CLOCK_ERROR;

} /* END Clock_GetMappedSource */

/* =========================================================================
**  Function : Clock_GetRailNode
** =========================================================================*/
/**
  See ClockDriver.h
*/
ClockRailType *Clock_GetRailNode
(
  const char *szRail
)
{
  int            i;
  ClockBSPType  *pBSP = Clock_GetDrvCtxt()->pBSP;
  ClockRailType *pRail = NULL;

  if (!szRail)
  {
    return NULL;
  }

  for (i = 0; i < pBSP->nNumRails; i++)
  {
    if (!strcmp(pBSP->aRails[i]->szName, szRail))
    {
      pRail = pBSP->aRails[i];
      break;
    }
  }

  return pRail;
}

/*=========================================================================
**  Function : Clock_GetDrvCtxt
** =========================================================================*/
/**
  See ClockDriver.h
*/

ClockDrvCtxt * Clock_GetDrvCtxt
(
  void
)
{
  static boolean first_entry = FALSE;
  if(FALSE == first_entry)
  {
	Clock_DriverCtxt.hClient =(ClockHandle) &pClient;
  }
  
  return &Clock_DriverCtxt;

} /* END of Clock_GetDrvCtxt */

ClockResult Clock_GetHandle
(
  ClockHandle *hClient
)
{
  *hClient = (ClockHandle)&pClient;
  return CLOCK_SUCCESS;
} /* END of Clock_GetHandle */

/* =========================================================================
**  Function : Clock_InitClocks
** =========================================================================*/
/**
  This function enables all the required clocks

  @return
  CLOCK_SUCCESS -- Initialization was successful.
  CLOCK_ERROR   -- Initialization failed.

  @dependencies
  None.
*/
static ClockResult Clock_InitClocks
(
  ClockDrvCtxt *pDrvCtxt,
  SAILInitClocks clks[],
  uint32_t size,
  uint32_t clockVoteEnableFlag
)
{
  ClockResult       eResult = CLOCK_ERROR;
  ClockIdType       nClockId = 0;
  uint32_t          nFreqHz;

  for(int i=0; i<size; i++)
  {
    eResult = Clock_GetClockId(pDrvCtxt->hClient,clks[i].szName,(ClockIdType *)&nClockId);
    if ( CLOCK_SUCCESS == eResult )
    {
      if(0 < clks[i].freq_in_mHz)
      {
        eResult = Clock_SetClockFrequency (pDrvCtxt->hClient, nClockId, clks[i].freq_in_mHz, CLOCK_FREQUENCY_MHZ_AT_LEAST,&nFreqHz);
        if(CLOCK_SUCCESS != eResult)
        {
          DEBUG_LOG(SAIL_ERROR,"Failed to set frequency of %dMHz for %s \r\n",clks[i].freq_in_mHz, clks[i].szName);
          break;
        }
      }
      if(true == clockVoteEnableFlag)
      {
        eResult = Clock_EnableClock(pDrvCtxt->hClient, nClockId);
        if ( CLOCK_SUCCESS != eResult )
        {
          DEBUG_LOG(SAIL_ERROR,"Failed to enable %s \r\n",clks[i].szName);
          break;
        }
      }
    }
    else
    {
      DEBUG_LOG(SAIL_ERROR,"Failed to find clockId for %s \r\n",clks[i].szName);
      break;
    }	
  }
  return eResult;
}

/* =========================================================================
**  Function : Clock_LateInitClocks
** =========================================================================*/
/**
  This function sets the frequency to turbo for the required clocks

  @return
  CLOCK_SUCCESS -- Turbo frequency setting was successful.
  CLOCK_ERROR -- Turbo frequency setting failed.

  @dependencies
  None.
*/
ClockResult Clock_LateInitClocks
(
  void
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockResult    eResult  = CLOCK_SUCCESS;

  if( CLOCK_SUCCESS != Clock_InitClocks(pDrvCtxt, LateInitClocks,  SIZEOF_ARRAY( LateInitClocks) , false ) )
  {
      eResult = CLOCK_ERROR;
  }
  return eResult;
}


/* =========================================================================
**  Function : Clock_SleepClocksSwitchXO
** =========================================================================*/
/**
  This function sets the freq of sleep init clocks to 19.2Mhz and change source to xo

  @return
  CLOCK_SUCCESS -- Sleep init frequency setting was successful.
  CLOCK_ERROR   -- Sleep init frequency setting failed.

  @dependencies
  None.
*/
static ClockResult Clock_SleepClocksSwitchXO
(
  void
)
{
  ClockDrvCtxt       *pDrvCtxt  = Clock_GetDrvCtxt();
  ClockResult         eResult   = CLOCK_ERROR;
  ClockIdType         nClockId  = 0;
  uint32_t            nFreqHz;

  for(int i= SIZEOF_ARRAY(EarlyInitClocks)-1; i >= 0; i--)
  {
    eResult = Clock_GetClockId(pDrvCtxt->hClient,EarlyInitClocks[i].szName,(ClockIdType *)&nClockId);
    if ( CLOCK_SUCCESS == eResult )
    {
      if(0 < EarlyInitClocks[i].freq_in_mHz)
      {
        eResult = Clock_SetClockFrequency (pDrvCtxt->hClient, nClockId, CLOCK_XO_SRC_FREQ, CLOCK_FREQUENCY_MHZ_AT_LEAST,&nFreqHz);
        if(CLOCK_SUCCESS != eResult)
        {
          DEBUG_LOG(SAIL_ERROR,"SleepInitXOClocks - Failed to set frequency of %dMHz for %s \r\n",EarlyInitClocks[i].freq_in_mHz, EarlyInitClocks[i].szName);
          break;
        }
      }
    }
    else
    {
      DEBUG_LOG(SAIL_ERROR,"SleepInitXOClocks - Failed to find clockId for %s \r\n",EarlyInitClocks[i].szName);
      break;
    }
  }
  return eResult;
}
/* =========================================================================
**  Function : Clock_SleepEntry
** =========================================================================*/
/**
  This function execute the sleep entery sequence

  @return
  CLOCK_SUCCESS -- Sleep entry sequence success
  CLOCK_ERROR -- Sleep entry sequence failure

  @dependencies
  None.
*/
ClockResult Clock_SleepEntry
(
  void
)
{
    ClockDrvCtxt       *pDrvCtxt        = Clock_GetDrvCtxt();
    ClockResult         eResult         = CLOCK_SUCCESS;
    uint32_t            nTimeout        = 150000;
    ClockIdType         nClockId        = 0;

    const char *pll6SrcClocks[] =
    {
        "sailss_cc_acmu1_ro_clk", //sailss_cc_acmu1_ro_clk_src, PLL6 even
        "sailss_cc_error_clk"   , //sailss_cc_error_clk_src, PLL6 even
    };

    /*
    * STEP 1: Switch the sleep clk GFMUX to choose from RO PLL (PLL5)
    */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR, CLK_SEL, 1);

    /* Wait for the clock to be switched to RO PLL */
    nTimeout = 150000;
    while( ( !( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR, RO_PLL_SEL_STATUS) ) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    /*
     * STEP 2: Switch below RCG to PLL5 even source - SRC3 'sailss_cc_pll5_out_even',
     * SAILSS_CLKCTL_SAILSS_CC_SWAO_CFG_RCGR
     * SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CFG_RCGR
     * SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CFG_RCGR
     * SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CFG_RCGR
     * SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CFG_RCGR
     * NOTE: SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CFG_RCGR , already switched to pll5 even, no need
     * explicitly switch to PLL5
     */
    nTimeout = 150000;
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_CFG_RCGR,SRC_SEL, 3 );
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_CMD_RCGR, UPDATE, 1 );
    while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_SWAO_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    nTimeout = 150000;
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CFG_RCGR,SRC_SEL, 3 );
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CMD_RCGR, UPDATE, 1 );
    while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    nTimeout = 150000;
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CFG_RCGR,SRC_SEL, 3 );
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CMD_RCGR, UPDATE, 1 );
    while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    nTimeout = 150000;
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CFG_RCGR,SRC_SEL, 3 );
    HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CMD_RCGR, UPDATE, 1 );
    while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    /*
    * STEP 3a: set freq to 19.2 to make sure all clocks are sourced from xo
    */
    if ( CLOCK_SUCCESS != Clock_SleepClocksSwitchXO() )
    {
        eResult = CLOCK_ERROR;
    }

    /*
    * STEP 3b: disable below pll6 sourced clocks and switched xo by enabling through CBCR Reg
    *  {"sailss_cc_acmu1_ro_clk"}, //sailss_cc_acmu1_ro_clk_src, PLL6 even
    *  {"sailss_cc_error_clk",  }, //sailss_cc_error_clk_src, PLL6 even
    */
    for(int i = 0; i < SIZEOF_ARRAY(pll6SrcClocks); i++)
    {
        if ( CLOCK_SUCCESS == Clock_GetClockId(pDrvCtxt->hClient,(const char *)pll6SrcClocks[i],(ClockIdType *)&nClockId ) )
        {
            if ( CLOCK_SUCCESS != Clock_DisableClock(pDrvCtxt->hClient, nClockId ) )
            {
                eResult = CLOCK_ERROR;
            }
        }
        else
        {
            eResult = CLOCK_ERROR;
        }
    }
    /* switched xo by enabling through CBCR Reg */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ERROR_CBCR, CLK_ENABLE, 1);
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_ACMU1_RO_CBCR, CLK_ENABLE, 1);

    return eResult;
}


/* =========================================================================
**  Function : Clock_SleepExit
** =========================================================================*/
/**
  This function execute the sleep Exit sequence

  @return
  CLOCK_SUCCESS -- Sleep exit sequence success
  CLOCK_ERROR   -- Sleep exit sequence failure

  @dependencies
  None.
*/
ClockResult Clock_SleepExit
(
  void
)
{
    ClockResult         eResult         = CLOCK_SUCCESS;
    ClockDrvCtxt       *pDrvCtxt        = Clock_GetDrvCtxt();
    uint32_t            nTimeout        = 0;
    ClockIdType         nClockId        = 0;
    ChipInfoIdType      xChipInfo       = CHIPINFO_ID_UNKNOWN;

    xChipInfo = ChipInfo_GetChipId();

    const char *pll6SrcClocks[] =
    {
        "sailss_cc_acmu1_ro_clk", //sailss_cc_acmu1_ro_clk_src, PLL6 even
        "sailss_cc_error_clk"   , //sailss_cc_error_clk_src, PLL6 even
    };

    /*
    * STEP 1a: switch the below clocks to PLL6
    *  {"sailss_cc_acmu1_ro_clk"}, //sailss_cc_acmu1_ro_clk_src, PLL6 even
    *  {"sailss_cc_error_clk"   }, //sailss_cc_error_clk_src, PLL6 even
    */
    for(int i = 0; i < SIZEOF_ARRAY(pll6SrcClocks); i++)
    {
        if ( CLOCK_SUCCESS == Clock_GetClockId(pDrvCtxt->hClient,(const char *)pll6SrcClocks[i],(ClockIdType *)&nClockId ) )
        {
            if ( CLOCK_SUCCESS != Clock_EnableClock(pDrvCtxt->hClient, nClockId ) )
            {
                eResult = CLOCK_ERROR;
            }
        }
        else
        {
            eResult = CLOCK_ERROR;
        }
    }
    /*
     * STEP 1b: Program the clocks to Nominal Frequecy
     */
    if ( CLOCK_SUCCESS !=  Clock_InitClocks(pDrvCtxt, EarlyInitClocks, SIZEOF_ARRAY( EarlyInitClocks ) , false ) )
    {
        eResult = CLOCK_ERROR;
    }


    /*
     * STEP 1c: Program the clocks to turbo Frequecy
     */
    /* NOTE: Turbo switching only for ADAS and ADAS_H only and it depends on PMIC in SAIL*/
    if ( TRUE == bSailPmicPresent() )
    {
        if ( CLOCK_SUCCESS !=  Clock_InitClocks(pDrvCtxt, LateInitClocks, SIZEOF_ARRAY( LateInitClocks ) , false ) )
        {
            eResult = CLOCK_ERROR;
        }
    }

    /*
       * STEP 2: Switch below RCG to xo even source -  SRC0 'sailss_safe_tcxo_mx',
       * SAILSS_CLKCTL_SAILSS_CC_SWAO_CFG_RCGR
       * SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CFG_RCGR
       * SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CFG_RCGR
       * SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CFG_RCGR
       * SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CFG_RCGR
       * NOTE: SAILSS_CLKCTL_SAILSS_CC_BMTX_NOC_QH_CFG_RCGR , already switched, no need
       * explicitly switch to PLL5
       */
      nTimeout = 150000;
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_CFG_RCGR,SRC_SEL, 0 );
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_CMD_RCGR, UPDATE, 1 );
      while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_SWAO_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
      {
          nTimeout--;
      }
      if(0 == nTimeout)
      {
          eResult = CLOCK_ERROR;
      }

      nTimeout = 150000;
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CFG_RCGR,SRC_SEL, 0 );
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CMD_RCGR, UPDATE, 1 );
      while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_SWAO_TS_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
      {
          nTimeout--;
      }
      if(0 == nTimeout)
      {
          eResult = CLOCK_ERROR;
      }

      nTimeout = 150000;
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CFG_RCGR,SRC_SEL, 0 );
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CMD_RCGR, UPDATE, 1 );
      while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_TSCSS_1_CNTR_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
      {
          nTimeout--;
      }
      if(0 == nTimeout)
      {
          eResult = CLOCK_ERROR;
      }

      nTimeout = 150000;
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CFG_RCGR,SRC_SEL, 0 );
      HWIO_OUTF( SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CMD_RCGR, UPDATE, 1 );
      while( ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_PWR_CTRL_XO_CMD_RCGR, UPDATE) ) && ( nTimeout > 0 ) )
      {
          nTimeout--;
      }
      if(0 == nTimeout)
      {
          eResult = CLOCK_ERROR;
      }

    /*
     * STEP 3: switch the sleep clk GFMUX to choose from XO source
     */
    HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR, CLK_SEL, 0);

    /* Wait for the clock to be switched to RO PLL */
    nTimeout = 150000;
    while( ( ! ( HWIO_INF(SAILSS_CLKCTL_SAILSS_CC_XO_RO_GFMUX_MUXR, BI_TCXO_SEL_STATUS) ) ) && ( nTimeout > 0 ) )
    {
        nTimeout--;
    }
    if(0 == nTimeout)
    {
        eResult = CLOCK_ERROR;
    }

    return eResult;
}

/* =========================================================================
**  Function : Clock_ConfigureCPU
** =========================================================================*/
/**
  Configure CPU to max frequency.
*/

static ClockResult Clock_ConfigureCPU
(
  ClockNodeType     *pClock,
  rail_voltage_level eCorner
)
{
  ClockDomainNodeType             *pDomain;
  uint32_t                         i;
  ClockMuxConfigType              *pBSPConfig = NULL;
  ClockSourceNodeType             *pSource;
  const ClockSourceFreqConfigType *pSourceFreqConfig;
  HAL_clk_PLLConfigType            DetectedConfig = {0};
  HAL_clk_ClockMuxConfigType       DetectedMuxConfig = {0};
  bool                             bResult;

  pDomain = pClock->pDomain;

   /* Loop over all configurations */
  for (i = 0; i < pDomain->nBSPLen; i++)
  {
    pBSPConfig = &pDomain->aBSP[i];
    if (Clock_IsBSPSupported(&pBSPConfig->HWVersion) &&
        pBSPConfig->eVRegLevel >= eCorner)
    {
      break;
    }
  }

  if(pBSPConfig == NULL)
  {
    return CLOCK_ERROR_INTERNAL;
  }

  pSource = pBSPConfig->pSource;
  pSourceFreqConfig = pBSPConfig->pSourceFreqConfig;

  HAL_clk_DetectPLLConfig(&pSource->HALSource, &DetectedConfig);
  HAL_clk_DetectClockMuxConfig(&pDomain->HALDomain, &DetectedMuxConfig);

  if ( HAL_clk_IsSourceEnabled(&pSource->HALSource))
  {
    if (pSourceFreqConfig->HALConfig.nL >= DetectedConfig.nL)
    {
      if ( HAL_clk_ConfigClockMux(&pDomain->HALDomain, &pBSPConfig->HALConfig) == FALSE)
      {
        return CLOCK_ERROR_INTERNAL;
      }
    }

    bResult = HAL_clk_ConfigPLL(&pSource->HALSource, &pSourceFreqConfig->HALConfig, HAL_CLK_SOURCE_CONFIG_MODE_SLEW);
    if (bResult != true)
    {
      return CLOCK_ERROR_INTERNAL;
    }

    if (pSourceFreqConfig->HALConfig.nL < DetectedConfig.nL)
    {
      if ( HAL_clk_ConfigClockMux(&pDomain->HALDomain, &pBSPConfig->HALConfig) == FALSE)
      {
        return CLOCK_ERROR_INTERNAL;
      }
    }
  }
  else
  {
    /*
     * This scenario happens during standalone validations where PLL is not bought up.
     */
    return CLOCK_ERROR_INTERNAL;
  }

  return CLOCK_SUCCESS;
}

/* =========================================================================
**  Function : Clock_DriverInit
** =========================================================================*/
/**
  Initialize the clock driver.

  This function initializes the clock driver, it is the main init entry
  point.

  @return
  CLOCK_SUCCESS -- Initialization was successful.
  CLOCK_ERROR -- Initialization failed.

  @dependencies
  None.
*/

ClockResult Clock_DriverInit
(
  void
)
{
  ClockResult                  eResult;
  ClockDrvCtxt                *pDrvCtxt = Clock_GetDrvCtxt();
  HAL_clk_ContextType          HALClkCtxt = {0};
  uint32_t                     nLogSize;
  ClockClientCtxt             *pClient;
  ClockIdType                  CPUClockId;
  ClockNodeType               *pClock;

  /*-----------------------------------------------------------------------*/
  /* Hookup BSP data linked to target built in this image.                 */
  /*-----------------------------------------------------------------------*/

  pDrvCtxt->pBSP = &ClockBSP;

  /*-----------------------------------------------------------------------*/
  /* Initialize mutex.                                                     */
  /*-----------------------------------------------------------------------*/
  mutex_init(&pDrvCtxt->hLock);

  /*-----------------------------------------------------------------------*/
  /* Get our property handle.                                              */
  /*-----------------------------------------------------------------------*/
  nLogSize = ClockLogDefaultConfig[0].nLogSize;
  pDrvCtxt->pBSP->nFlags |= ClockLogDefaultConfig[0].nGlobalLogFlags;

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }

  /*-----------------------------------------------------------------------*/
  /* Initialize the clock HAL.                                             */
  /*-----------------------------------------------------------------------*/

  /*
   * Use DALSys busy wait function for HAL modules.
   */
  //HALClkCtxt.BusyWait = (void (*)(uint32_t))DALSYS_BusyWait;
  HALClkCtxt.BusyWait = (void (*)(uint32_t))busywait;

  /*
   * Get chip version to send to the HAL.
   */
  HALClkCtxt.nChipVersion = ChipInfo_GetChipVersion();
  HALClkCtxt.nChipId = ChipInfo_GetChipId();
  HALClkCtxt.nChipFamily = ChipInfo_GetChipFamily();

  HAL_clk_Init(&HALClkCtxt);


  pClient = (ClockClientCtxt *)pDrvCtxt->hClient;
  CLOCK_FLAG_SET(pClient, INTERNAL_CONTROL);

  /*-----------------------------------------------------------------------*/
  /* Init voltage module.                                                  */
  /*-----------------------------------------------------------------------*/

  eResult = Clock_InitVoltage();
  if (eResult != CLOCK_SUCCESS)
  {
    DEBUG_LOG(SAIL_ERROR,"Clock_InitVoltage failed. \r\n");
    return CLOCK_ERROR;
  }

  /*-----------------------------------------------------------------------*/
  /* Init DFS domains.                                                     */
  /*-----------------------------------------------------------------------*/

  eResult = Clock_InitDFSDomains();
  if (eResult != CLOCK_SUCCESS)
  {
    DEBUG_LOG(SAIL_ERROR,"Clock_InitDFSDomains failed. \r\n");
    return CLOCK_ERROR;
  }

  /*-----------------------------------------------------------------------*/
  /* Issue Clock request.                                              */
  /*-----------------------------------------------------------------------*/
  eResult = Clock_InitClocks(pDrvCtxt, EarlyInitClocks, SIZEOF_ARRAY(EarlyInitClocks), true);
  if (eResult != CLOCK_SUCCESS)
  {
	DEBUG_LOG(SAIL_ERROR,"Clock_EarlyInitClocks failed. \r\n");
	return CLOCK_ERROR;
  }
  
  /*-----------------------------------------------------------------------*/
  /* Initialize CPU config.                                              */
  /*-----------------------------------------------------------------------*/
  eResult = Clock_GetClockId(pDrvCtxt->hClient, SAIL_CPU_CLOCK_NAME, &CPUClockId);
  if (eResult == CLOCK_SUCCESS)
  {
    pClock = Clock_GetClockNode(CPUClockId);
    if (!pClock || !pClock->pDomain || !pClock->pDomain->aBSP)
    {
      return CLOCK_ERROR_INTERNAL;
    }
    
    if (Clock_ConfigureCPU(pClock, CPU_BOOTUP_VOLTAGE_CORNER) != CLOCK_SUCCESS)
    {
      return CLOCK_ERROR_INTERNAL;
    }
  }
  return CLOCK_SUCCESS;

} /* END Clock_DriverInit */

/* =========================================================================
**  Function : Clock_EnableEx
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_EnableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
   ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_EnableClockEx(hClient, ClockId, nFlags);

    case CLOCK_ID_CATEGORY_SOURCE:
      return Clock_EnableSource(hClient, ClockId);

    case CLOCK_ID_CATEGORY_POWERDOMAIN:
      return Clock_EnablePowerDomain(hClient, ClockId);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_EnableEx */


/* =========================================================================
**  Function : Clock_DisableEx
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_DisableEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nFlags
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_DisableClockEx(hClient, ClockId, nFlags);

    case CLOCK_ID_CATEGORY_SOURCE:
      return Clock_DisableSource(hClient, ClockId);

    case CLOCK_ID_CATEGORY_POWERDOMAIN:
      return Clock_DisablePowerDomain(hClient, ClockId);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_DisableEx */


/* =========================================================================
**  Function : Clock_SetFrequencyEx
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_SetFrequencyEx
(
  ClockHandle          hClient,
  ClockIdType          ClockId,
  uint32_t             nFreq,
  ClockFrequencyType   eMatch,
  uint32_t            *pnResultFreq,
  uint32_t             nFlags
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_SetClockFrequency(hClient, ClockId, nFreq, eMatch, pnResultFreq);

    case CLOCK_ID_CATEGORY_SOURCE:
      return Clock_SetSourceFrequency(hClient, ClockId, nFreq, eMatch, pnResultFreq);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_SetFrequencyEx */


/* =========================================================================
**  Function : Clock_IsEnabled
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_IsEnabled
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsEnabled
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_IsClockEnabled(hClient, ClockId, pbIsEnabled);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_IsEnabled */


/* =========================================================================
**  Function : Clock_IsOn
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_IsOn
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  bool        *pbIsOn
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();

  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_IsClockOn(hClient, ClockId, pbIsOn);

    case CLOCK_ID_CATEGORY_POWERDOMAIN:
      return Clock_IsPowerDomainOn(hClient, ClockId, pbIsOn);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_IsOn */


/* =========================================================================
**  Function : Clock_GetFrequency
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_GetFrequency
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_GetClockFrequency(hClient, ClockId, pnFrequencyHz);

    case CLOCK_ID_CATEGORY_SOURCE:
      return Clock_GetSourceFrequency(hClient, ClockId, pnFrequencyHz);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_GetFrequency */


/* =========================================================================
**  Function : Clock_MeasureFrequency
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_MeasureFrequencyEx
(
  ClockHandle  hClient,
  ClockIdType  ClockId,
  uint32_t     nMuxSel,
  uint32_t    *pnFrequencyHz
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_MeasureClockFrequency(hClient, ClockId, pnFrequencyHz);

    case CLOCK_ID_CATEGORY_DEBUGMUX:
      return Clock_MeasureDebugMuxInput(hClient, ClockId, nMuxSel, pnFrequencyHz);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_MeasureFrequency */


/* =========================================================================
**  Function : Clock_Configure
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_Configure
(
  ClockHandle     hClient,
  ClockIdType     ClockId,
  ClockConfigType eConfig
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_ConfigureClock(hClient, ClockId, eConfig);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_Configure */


/* =========================================================================
**  Function : Clock_SetDivider
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_SetDivider
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t    nDivider
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_SetClockDivider(hClient, ClockId, nDivider);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_SetDivider */


/* =========================================================================
**  Function : Clock_Query
** =========================================================================*/
/*
  See Clock.h
*/

ClockResult Clock_Query
(
  ClockHandle            hClient,
  ClockIdType            ClockId,
  ClockQueryType         eQuery,
  uint32_t               nPerfLevel,
  ClockQueryResultType  *pResult
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();   
  /*-----------------------------------------------------------------------*/
  /* Short-circuit if driver is stubbed.                                   */
  /*-----------------------------------------------------------------------*/

  if (CLOCK_GLOBAL_FLAG_IS_SET(STUB_API))
  {
    return CLOCK_SUCCESS;
  }  
  
  switch (CLOCK_GET_ID_CATEGORY(ClockId))
  {
    case CLOCK_ID_CATEGORY_CLOCK:
      return Clock_QueryClock(hClient, ClockId, eQuery, nPerfLevel, pResult);

    default:
      return CLOCK_ERROR_NOT_SUPPORTED;
  }

} /* END Clock_Query */

/* =========================================================================
**  Function : Clock_DeassertCoreReset
** =========================================================================*/
/*
  See Clock.h
*/
void Clock_DeassertCoreReset(uint8_t core)
{
  switch(core)
  {
    case 1:
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CPUPORESET1_SW_CTRL, RESET, 0x0);
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CORE1_RESET_SW_CTRL, RESET, 0x0);
      break;
    case 2:
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CPUPORESET0_SW_CTRL, RESET, 0x0);
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE0_RESET_SW_CTRL, RESET, 0x0);
      break;
    case 3:
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CPUPORESET1_SW_CTRL, RESET, 0x0);
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE1_RESET_SW_CTRL, RESET, 0x0);
      break;
    default:
      break;
  }
} /* END Clock_DeassertCoreReset */

/* =========================================================================
**  Function : Clock_DeassertClusterReset
** =========================================================================*/
/*
  See Clock.h
*/
void Clock_DeassertClusterReset(uint8_t cluster)
{
  switch(cluster)
  {
    case 1:
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CBCR, CLK_ENABLE, 0x1);
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_TOP_RESET_SW_CTRL, RESET, 0x0);
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_PRESETDBG_SW_CTRL, RESET, 0x0);
      break;
    default:
       return;
  }
} /* END Clock_DeassertClusterReset */


/* =========================================================================
**  Function : Clock_ResetCore
** =========================================================================*/
/*
  See Clock.h
*/
ClockResult Clock_ResetCore(int cpu_num)
{
  ClockResult result = CLOCK_SUCCESS;
  switch (cpu_num)
  {
    case 0:
	  HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER0_CPU0_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CORE0_RESET_SW_CTRL, RESET, 0x1);
      __asm__ volatile("isb" ::: "memory");
      __asm__ volatile("dsb sy" ::: "memory");
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CORE0_RESET_SW_CTRL, RESET, 0x0);
      break;
    case 1:
	  HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CORE1_RESET_SW_CTRL, RESET, 0x1);
      __asm__ volatile("isb" ::: "memory");
      __asm__ volatile("dsb sy" ::: "memory");
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER0_CORE1_RESET_SW_CTRL, RESET, 0x0);
      break;
    case 2:
	  HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE0_RESET_SW_CTRL, RESET, 0x1);
      __asm__ volatile("isb" ::: "memory");
      __asm__ volatile("dsb sy" ::: "memory");
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE0_RESET_SW_CTRL, RESET, 0x0);
      break;
    case 3:
	  HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE1_RESET_SW_CTRL, RESET, 0x1);
      __asm__ volatile("isb" ::: "memory");
      __asm__ volatile("dsb sy" ::: "memory");
      HWIO_OUTF(SAILSS_CLKCTL_SAILSS_CC_CPU_CLUSTER1_CORE1_RESET_SW_CTRL, RESET, 0x0);
      break;
    default:
      result = CLOCK_ERROR;
      break;
  }
  return result;
} /* END Clock_ResetCore */


/* =========================================================================
**  Function : Clock_ReInitMDClockBSP
** =========================================================================*/
/*
  See Clock.h
*/
ClockResult Clock_ReInitMDClockBSP(void)
{
    ClockDrvCtxt    *pDrvCtxt = Clock_GetDrvCtxt();
    uint32_t        nIdx      = 0U;
    ClockHandle     hClient;
    Clock_GetHandle(&hClient);

    for (nIdx = 0U; nIdx < pDrvCtxt->pBSP->nNumClocks; nIdx++)
    {
        ClockNodeType   *pClock = &pDrvCtxt->pBSP->aClocks[nIdx];
        uintptr_t       pAddr   = pClock->HALClock.mRegisters.nBranchAddr;

        if ((pAddr >= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE) &&
                (pAddr <= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE + SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_SIZE))
        {
            pClock->nFlags &= CLOCK_FLAG_CLEAR_INIT_MASK; /* Clear initialized flags */
            pClock->RefCount.nRequired = 0U;
            pClock->RefCount.nSuppressible = 0U;

            if( Clock_RemoveRefCountClient( hClient, &pClock->pClients ) != CLOCK_SUCCESS )
            {
                return CLOCK_ERROR;
            }
        }
    }

    for (nIdx = 0U; nIdx < pDrvCtxt->pBSP->nNumDomains; nIdx++)
    {
        ClockDomainNodeType *pDomain = pDrvCtxt->pBSP->aDomains[nIdx];
        uintptr_t           pAddr    = pDomain->HALDomain.nCGRAddr;

        if ((pAddr >= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE) &&
                (pAddr <= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE + SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_SIZE))
        {
            pDomain->nFlags &= CLOCK_FLAG_CLEAR_INIT_MASK; /* Clear initialized flags */
            pDomain->pActiveMuxConfig = NULL;
            pDomain->RefCount.nRequired = 0U;
            pDomain->RefCount.nSuppressible = 0U;
        }
    }

    for (nIdx = 0U; nIdx < pDrvCtxt->pBSP->nNumSources; nIdx++)
    {
        ClockSourceNodeType *pSource = pDrvCtxt->pBSP->aSources[nIdx];
        uintptr_t           pAddr    = pSource->HALSource.nAddr;

        if ((pAddr >= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE) &&
                (pAddr <= (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE + SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_SIZE)))
        {
            pSource->nFlags &= CLOCK_FLAG_CLEAR_INIT_MASK; /* Clear initialized flags */
            pSource->RefCount.nRequired = 0U;
            pSource->RefCount.nSuppressible = 0U;

            if( Clock_RemoveRefCountClient( hClient, &pSource->pClients ) != CLOCK_SUCCESS )
            {
                return CLOCK_ERROR;
            }
            pSource->pActiveFreqConfig = NULL;
        }
    }

    for (nIdx = 0U; nIdx < pDrvCtxt->pBSP->nNumPowerDomains; nIdx++)
    {
        ClockPowerDomainNodeType    *pPDomain = &pDrvCtxt->pBSP->aPowerDomains[nIdx];
        uintptr_t                   pAddr     = pPDomain->HALPowerDomain.nGDSCRAddr;

        if ((pAddr >= SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE) &&
                (pAddr <= (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE + SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE_SIZE)))
        {
            pPDomain->nFlags &= CLOCK_FLAG_CLEAR_INIT_MASK; /* Clear initialized flags */
            pPDomain->RefCount.nRequired = 0U;
            pPDomain->RefCount.nSuppressible = 0U;

            if( Clock_RemoveRefCountClient( hClient, &pPDomain->pClients ) != CLOCK_SUCCESS )
            {
                return CLOCK_ERROR;
            }
            pPDomain->VRegRequest.eVRegLevel = RAIL_VOLTAGE_LEVEL_OFF;
            pPDomain->VRegRequest.eVRegLevel = false;
            pPDomain->nCallbackCount = 0;
        }
    }

    return CLOCK_SUCCESS;
}
