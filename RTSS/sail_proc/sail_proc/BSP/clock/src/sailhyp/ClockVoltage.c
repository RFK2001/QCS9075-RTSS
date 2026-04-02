/*
===========================================================================
*/
/**
  @file ClockVoltage.c

  Digital voltage management interface implementation for the clock
  device driver.
*/
/*
  ====================================================================

  Copyright (c) 2021 Qualcomm Technologies Incorporated.  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================
  $Header $
  $DateTime $
  $Author $

  when       who     what, where, why
  --------   ---     -------------------------------------------------

  ====================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/

#include <stdio.h>
#include "ClockDriver.h"
#include "ClockSWEVT.h"
#include "debug_log.h"
#include "types.h"
//#include "arc_wrapper.h"


/*=========================================================================
      Constants and Macros
==========================================================================*/
const RailPerStringMapType rail_perf_string_table [] =
{
  {RAIL_VOLTAGE_LEVEL_RET         ,"RAIL_VOLTAGE_LEVEL_RET          "}, //0x10 ,  // 16
  {RAIL_VOLTAGE_LEVEL_SVS_L1      ,"RAIL_VOLTAGE_LEVEL_SVS_L1       "}, //0xC0 ,  // 192
  {RAIL_VOLTAGE_LEVEL_NOM         ,"RAIL_VOLTAGE_LEVEL_NOM          "}, //0x100,  // 256
  {RAIL_VOLTAGE_LEVEL_TUR         ,"RAIL_VOLTAGE_LEVEL_TUR          "}, //0x180,  // 384

};
/*=========================================================================
      Functions
==========================================================================*/

const char * Clock_GetPerfStringName
(
  rail_voltage_level   eCorner
);
/* =========================================================================
**  Function : Clock_UpdateVoltageRequests
** =========================================================================*/
/**
  Updates the current voltage request.

  This function updates the current voltage request for a particular voltage
  regulator configuration.

  @param *pDrvCtxt [in] -- Context pointer, the driver context in this case.
  @param pVRegConfig -- The voltage regulator configuration to update.
  @param eNewLevel -- New voltage level to configure.

  @return
  Clock_SUCCESS -- Request was successful.
  Clock_ERROR   -- Request failed.

  @dependencies
  None.
*/

static ClockResult Clock_UpdateVoltageRequests
(
  ClockRailType       *pRail,
  ClockVRegConfigType *pVRegConfig,
  rail_voltage_level   eNewLevel
)
{
  ClockCornerRefCountType *pRefCount;
  rail_voltage_level       eMinLevel;
  uint32_t                 i;
  const char               *szName = NULL;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pRail || !pVRegConfig)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Check if new min has changed.                                         */
  /*-----------------------------------------------------------------------*/

  if (eNewLevel > pVRegConfig->eMinLevel)
  {
    eMinLevel = eNewLevel;
  }
  else
  {
    eMinLevel = (rail_voltage_level)0;
    for (i = 0; i < RAIL_VOLTAGE_LEVEL_NUM_LEVELS; i++)
    {
      pRefCount = &pVRegConfig->aCornerRefCounts[i];
      if (pRefCount->eCorner == 0)
      {
        break;
      }

      if (pRefCount->nRefCount > 0 && pRefCount->eCorner > eMinLevel)
      {
        eMinLevel = pRefCount->eCorner;
      }
    }
  }

  /*-----------------------------------------------------------------------*/
  /* Update request if minimum level is different.                         */
  /*-----------------------------------------------------------------------*/

  if (eMinLevel != pVRegConfig->eMinLevel)
  {

      pVRegConfig->eMinLevel = eMinLevel;

      /* Get the at-least Supported Perf Level for the current Platform */
      for (i = 0; i < SIZEOF_ARRAY(rail_perf_string_table); i++)
      {
         /* Not Supported - max perf level */
         if( eMinLevel > rail_perf_string_table[( SIZEOF_ARRAY(rail_perf_string_table) - 1U )].perf_level_val)
         {
            return CLOCK_ERROR;
         }
         if (eMinLevel <= rail_perf_string_table[i].perf_level_val)
         {
            eMinLevel =  rail_perf_string_table[i].perf_level_val;
            break;
         }
      }

      szName = Clock_GetPerfStringName(eMinLevel);
      if(strncmp("/vcs/vdd_sail", pRail->szName, strlen("/vcs/vdd_sail")) == 0)
      {
         DEBUG_LOG(SAIL_INFO, "[Clock Info] Voltage Rail - \"%s\" new perf level - %s\n\r", pRail->szName, szName );
      }
      //TODO: ADD PMIC API
  }

  return CLOCK_SUCCESS;

} /* END Clock_UpdateVoltageRequests */


/* =========================================================================
**  Function : Clock_GetCornerRefCount
** =========================================================================*/
/*
  Get the reference count structure for a given voltage corner.
*/

static ClockCornerRefCountType *Clock_GetCornerRefCount
(
  ClockVRegConfigType *pVRegConfig,
  rail_voltage_level   eCorner
)
{
  ClockCornerRefCountType *pRefCount;
  uint32_t                 i;

  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pVRegConfig)
  {
    return NULL;
  }

  for (i = 0; i < RAIL_VOLTAGE_LEVEL_NUM_LEVELS; i++)
  {
    pRefCount = &pVRegConfig->aCornerRefCounts[i];
    if (pRefCount->eCorner == eCorner)
    {
      return pRefCount;
    }
    else if (pRefCount->eCorner == 0)
    {
      pRefCount->eCorner = eCorner;
      return pRefCount;
    }
  }

  DEBUG_LOG(SAIL_ERROR,"Not enough space to aggregate voltage request.");
  return NULL;

} /* END Clock_GetCornerRefCount */

/* =========================================================================
**  Function : Clock_NodeRefCountDump
** =========================================================================*/
/*
  This function prints the ref count of all sail cc clocks
*/

ClockResult Clock_NodeRefCountDump(void)
{
    ClockDrvCtxt    *pDrvCtxt      = Clock_GetDrvCtxt();
    uint32_t        nIdx           = 0U;
    uint32_t        ulEnableClock  = 0U;
    ClockHandle     hClient;
    Clock_GetHandle(&hClient);
    uint32_t ulDomainActivFreq = 0;

    for (nIdx = 0U; nIdx < pDrvCtxt->pBSP->nNumClocks; nIdx++)
    {
        ClockNodeType   *pClock = &pDrvCtxt->pBSP->aClocks[nIdx];

        if((strncmp("sailss_cc", pClock->szName, strlen("sailss_cc")) == 0) && (pClock->pDomain != NULL))
        {
            ulDomainActivFreq = 0;
            if ( (pClock->pDomain->pActiveMuxConfig != NULL) && (pClock->RefCount.nRequired ) )
            {
                ulDomainActivFreq = pClock->pDomain->pActiveMuxConfig->nFreqHz;
            }

            if( (&pClock->HALClock) != NULL)
            {
                ulEnableClock = HAL_clk_IsClockOn(&pClock->HALClock);
            }
            else
            {
                ulEnableClock = 0;
            }

            DEBUG_LOG(SAIL_ERROR,"%s, ref-%d, en - %d, freq dom- %d\n\r", pClock->szName,
                                                                          ulEnableClock,
                                                                          pClock->RefCount.nRequired,
                                                                          ulDomainActivFreq);
        }
    }
    return CLOCK_SUCCESS;
}/* END Clock_NodeRefCountDump */

/* =========================================================================
**  Function : Clock_GetVoltageRailCorner
** =========================================================================*/
/*
  Get the voltage corner of a given rail.
*/

ClockResult Clock_GetVoltageRailCorner
(
  ClockHandle          hClient,
  const char           *szName,
  rail_voltage_level   *eGetCorner
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockRailType *pRail    = NULL;
  ClockResult    xReturn  = CLOCK_SUCCESS;
  uint32_t       i;
  rail_voltage_level       eMinLevel;
  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if ( hClient != (ClockHandle)NULL )
  {
      xReturn = CLOCK_ERROR;

      for (i = 0; i < pDrvCtxt->pBSP->nNumRails; i++)
      {
        if (strcmp(szName, pDrvCtxt->pBSP->aRails[i]->szName) == 0)
        {
          pRail      = pDrvCtxt->pBSP->aRails[i];
          break;
        }
      }
      if(pRail != NULL)
      {
          /* Get the at-least Supported Perf Level for the current Platform */
          for (i = 0; i < SIZEOF_ARRAY(rail_perf_string_table); i++)
          {
             /* Not Supported - max perf level */
             if( pRail->VRegConfig.eMinLevel > rail_perf_string_table[ ( SIZEOF_ARRAY(rail_perf_string_table) - 1U ) ].perf_level_val)
             {
                return CLOCK_ERROR;
             }
             if (pRail->VRegConfig.eMinLevel <= rail_perf_string_table[i].perf_level_val)
             {
                *eGetCorner =  rail_perf_string_table[i].perf_level_val;
                break;
             }
          }
      }
      else
      {
          xReturn = CLOCK_ERROR;
      }
  }
  else
  {
      xReturn = CLOCK_ERROR;
  }

  return xReturn;

} /* END Clock_GetVoltageRailCorner */
/* =========================================================================
**  Function : Clock_GetPerfStringName
** =========================================================================*/
/*
  Get the voltage corner String Name.
*/

const char * Clock_GetPerfStringName
(
  rail_voltage_level   eCorner
)
{
  uint32_t                 i;
  const char               *szName = NULL;

  for (i = 0; i < SIZEOF_ARRAY(rail_perf_string_table); i++)
  {
    if (rail_perf_string_table[i].perf_level_val == eCorner)
    {
        szName =  rail_perf_string_table[i].perf_level_name;
        break;
    }
  }

  return szName;
} /* END Clock_GetPerfStringName */

/* =========================================================================
**  Function : Clock_VoltageRequest
** =========================================================================*/
/*
  See ClockDriver.h
*/

ClockResult Clock_VoltageRequest
(
  uint32_t              nRailMask,
  ClockVRegRequestType *pCurrentRequest,
  ClockVRegRequestType *pNewRequest
)
{
  ClockVRegConfigType     *pCurrentVRegConfig, *pNewVRegConfig;
  ClockCornerRefCountType *pCurrentRefCount, *pNewRefCount;
  ClockBSPType            *pBSP = Clock_GetDrvCtxt()->pBSP;
  ClockRailType           *pRail;
  uint8_t                  nIndex;

    /*-----------------------------------------------------------------------*/
    /* Validate arguments.                                                   */
    /*-----------------------------------------------------------------------*/

  if (!pCurrentRequest || !pNewRequest)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  /*-----------------------------------------------------------------------*/
  /* Find new minimum level.                                               */
  /*-----------------------------------------------------------------------*/

  if (pCurrentRequest->eVRegLevel == pNewRequest->eVRegLevel &&
      pCurrentRequest->bSuppressible == pNewRequest->bSuppressible)
  {
    return CLOCK_SUCCESS;
  }


  for (nIndex = 0;
       nIndex < pBSP->nNumRails && nIndex < CLOCK_MAX_RAIL_INDICES;
       nIndex++)
  {
    if (!CLOCK_RAIL_MASK_SET(nRailMask, nIndex))
    {
      continue;
    }

    pRail = pBSP->aRails[nIndex];

    if (pCurrentRequest->bSuppressible)
    {
      pCurrentVRegConfig = &pRail->VRegConfigSuppressible;
    }
    else
    {
      pCurrentVRegConfig = &pRail->VRegConfig;
    }

    if (pNewRequest->bSuppressible)
    {
      pNewVRegConfig = &pRail->VRegConfigSuppressible;
    }
    else
    {
      pNewVRegConfig = &pRail->VRegConfig;
    }

    /*-----------------------------------------------------------------------*/
    /* All domains default to OFF at init, but the ClientCount for OFF will  */
    /* not reflect this.  So we cannot track clients for the OFF voltage     */
    /* level, but this is ok since it is the "do not care" level.            */
    /*-----------------------------------------------------------------------*/

    if (pCurrentRequest->eVRegLevel != RAIL_VOLTAGE_LEVEL_OFF)
    {
      pCurrentRefCount =
        Clock_GetCornerRefCount(pCurrentVRegConfig, pCurrentRequest->eVRegLevel);
      if (!pCurrentRefCount)
      {
        return CLOCK_ERROR;
      }

      if (pCurrentRefCount->nRefCount > 0)
      {
        pCurrentRefCount->nRefCount--;
      }
    }

    if (pNewRequest->eVRegLevel != RAIL_VOLTAGE_LEVEL_OFF)
    {
      pNewRefCount =
        Clock_GetCornerRefCount(pNewVRegConfig, pNewRequest->eVRegLevel);
      if (!pNewRefCount)
      {
        return CLOCK_ERROR;
      }

      pNewRefCount->nRefCount++;
    }

    /*-----------------------------------------------------------------------*/
    /* Update voltage requests */
    Clock_UpdateVoltageRequests(pRail, pNewVRegConfig,
      pNewRequest->eVRegLevel);
    Clock_UpdateVoltageRequests(pRail, pCurrentVRegConfig,
      RAIL_VOLTAGE_LEVEL_OFF);
  }

  pCurrentRequest->eVRegLevel = pNewRequest->eVRegLevel;
  pCurrentRequest->bSuppressible = pNewRequest->bSuppressible;

  /*-----------------------------------------------------------------------*/
  /* Success.                                                              */
  /*-----------------------------------------------------------------------*/

  return CLOCK_SUCCESS;

} /* END Clock_VoltageRequest */


/* =========================================================================
**  Function : Clock_VoltageSuspend
** =========================================================================*/
/*
  See ClockDriver.h
*/

ClockResult Clock_VoltageSuspend
(
  ClockRailType *pRail
)
{
  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pRail)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pRail->bSuspendVoltageRequest = true;

  return CLOCK_SUCCESS;

} /* END Clock_VoltageSuspend */


/* =========================================================================
**  Function : Clock_VoltageResume
** =========================================================================*/
/*
  See ClockDriver.h
*/

ClockResult Clock_VoltageResume
(
  ClockRailType *pRail,
  bool           bUpdate
)
{
  /*-----------------------------------------------------------------------*/
  /* Validate arguments.                                                   */
  /*-----------------------------------------------------------------------*/

  if (!pRail)
  {
    return CLOCK_ERROR_INVALID_PARAMETER;
  }

  pRail->bSuspendVoltageRequest = false;

  /*-----------------------------------------------------------------------*/
  /* Make a voltage request when resuming from suspension.                 */
  /*-----------------------------------------------------------------------*/

  if (bUpdate)
  {

  }

  return CLOCK_SUCCESS;

} /* END Clock_VoltageResume */


/* =========================================================================
**  Function : Clock_InitVoltage
** =========================================================================*/
/*
  See ClockDriver.h
*/

ClockResult Clock_InitVoltage
(
  void
)
{
  ClockDrvCtxt  *pDrvCtxt = Clock_GetDrvCtxt();
  ClockRailType *pRail;
  uint32_t       i;

  /*-----------------------------------------------------------------------*/
  /* Create callback event to initialize the remote node client.           */
  /*-----------------------------------------------------------------------*/

  for (i = 0; i < pDrvCtxt->pBSP->nNumRails; i++)
  {
    pRail = pDrvCtxt->pBSP->aRails[i];
    // TODO: Add PMIC init API here, this Vote would go to Ext PMIC via I2C.
    // DEBUG_LOG(SAIL_INFO,"Voltage Rails %s.\n\r", pRail->szName);
  }

  return CLOCK_SUCCESS;

} /* END Clock_InitVoltage */

