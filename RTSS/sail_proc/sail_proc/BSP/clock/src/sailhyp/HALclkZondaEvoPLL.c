/*
==============================================================================

FILE:         HALclkZondaevoPLL.c

DESCRIPTION:
  This file contains the clock HAL code for the Zondaevo PLL control.
  These PLLs are of the Zondaevo PLL variety.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/src/sailhyp/HALclkZondaEvoPLL.c#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
05/07/20   ra      Created

==============================================================================
    Copyright (c) 2020-2021 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include "HALhwio.h"
#include "HALclkGenericPLL.h"
#include "HALclkZondaEvoPLL.h"
#include "chipinfodefs.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * HAL_CLK_PLL_MODE_*
 *
 * Definitions for configuring the PLLn_MODE register.
 */
#define HAL_CLK_PLL_MODE_ACTIVE  \
  (HWIO_FMSK(PLL_MODE, PLL_LOCK_DET)  | \
   HWIO_FMSK(PLL_MODE, PLL_BYPASSNL) | \
   HWIO_FMSK(PLL_MODE, PLL_RESET_N))


/*
 * HAL_CLK_LOCK_TIMEOUT_US
 *
 * Timeout in usec for PLL_LOCK_DET to get set.
 * For Zondaevo, this is 50us worst-case lock time.
 */
#define HAL_CLK_LOCK_TIMEOUT_US 50


/* ============================================================================
**    Data Declarations
** ==========================================================================*/

/*
 * HAL_clk_ZondaevoPLLControl
 *
 * Control function array for the Zondaevo PLLs.
 */
HAL_clk_SourceControlType HAL_clk_ZondaevoPLLControl =
{
  .Enable           = HAL_clk_ZondaevoPLLEnable,
  .Disable          = HAL_clk_ZondaevoPLLDisable,
  .IsEnabled        = HAL_clk_ZondaevoPLLIsEnabled,
  .Config           = HAL_clk_ZondaevoPLLConfig,
  .ConfigPLL        = HAL_clk_ZondaevoPLLConfigPLL,
  .DetectPLLConfig  = HAL_clk_ZondaevoPLLDetectPLLConfig,
  .EnableVote       = HAL_clk_ZondaevoPLLEnableVote,
  .DisableVote      = HAL_clk_ZondaevoPLLDisableVote,
  .IsVoteEnabled    = HAL_clk_ZondaevoPLLIsVoteEnabled,
  .IsPLLConfigEqual = HAL_clk_ZondaevoPLLIsPLLConfigEqual,
  .IsCalibrated     = HAL_clk_ZondaevoPLLIsCalibrated,
  .SetCalConfig     = HAL_clk_ZondaevoPLLSetCalConfig,
  .SetRegSettings   = HAL_clk_ZondaevoPLLSetRegSettings,
  .GetRegSettings   = HAL_clk_ZondaevoPLLGetRegSettings,
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/* ===========================================================================
**  HAL_clk_ZondaevoPLLEnableVote
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLEnableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;
  bool     bResult;

  /*
   * Set the appropriate bit.
   */
  nVal = inpdw(pSource->VoterRegister.nAddr) | pSource->VoterRegister.nMask;
  outpdw(pSource->VoterRegister.nAddr, nVal);

  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HAL_CLK_PLL_MODE_ACTIVE,
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_ZondaevoPLLEnableVote */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLDisableVote
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLDisableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;

  /*
   * Clear the appropriate bit.
   */
  nVal = inpdw(pSource->VoterRegister.nAddr) & ~pSource->VoterRegister.nMask;
  outpdw(pSource->VoterRegister.nAddr, nVal);

} /* END HAL_clk_ZondaevoPLLDisableVote */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLIsVoteEnabled
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLIsVoteEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  /*
   * Check the appropriate bit.
   */
  if (inpdw(pSource->VoterRegister.nAddr) & pSource->VoterRegister.nMask)
  {
    return TRUE;
  }

  return FALSE;

} /* END HAL_clk_ZondaevoPLLIsVoteEnabled */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLPostDivToHW
**
** ======================================================================== */

static uint32_t HAL_clk_ZondaevoPLLPostDivToHW (uint32_t nDivider)
{
  switch (nDivider)
  {
    case 0:
    case 1:   return 0; /* Divide-by-1 */
    case 2:   return 1; /* Divide-by-2 */
    case 4:   return 3; /* Divide-by-4 */
    case 8:   return 2; /* Divide-by-8 */
    default:
      return 0;
  }

} /* END HAL_clk_ZondaevoPLLPostDivToHW */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLPostDivFromHW
**
** ======================================================================== */

static uint32_t HAL_clk_ZondaevoPLLPostDivFromHW (uint32_t nDivider)
{
  switch (nDivider)
  {
    case 0:   return 1; /* Divide-by-1 */
    case 1:   return 2; /* Divide-by-2 */
    case 2:   return 8; /* Divide-by-8 */
    case 3:   return 4; /* Divide-by-4 */
    default:
      return 1;
  }

} /* END HAL_clk_ZondaevoPLLPostDivFromHW */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLEnable
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLEnable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32_t nModeVal;
  bool     bResult = FALSE;

  /*
   * Check if PLL is already enabled and return
   */
  if (HAL_clk_ZondaevoPLLIsEnabled(pSource))
  {
    return TRUE;
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * De-assert PLL bypass.
   * This latches L and Alpha values.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_BYPASSNL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * De-assert PLL reset.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_RESET_N);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Set desired operational mode.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);

  /*
   * Wait for the PLL to lock within the timeout period.
   */

  bResult =
      HAL_clk_ValidateRegSetTimeout(
        HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
        HWIO_FMSK(PLL_MODE, PLL_LOCK_DET),
        HAL_CLK_LOCK_TIMEOUT_US);    
   
  /*
   * Return immediately if the lock detect failed.
   */
  if (!bResult)
  {
    return FALSE;
  }

  /*
   * Put the PLL in active mode
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_OUTCTRL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  return TRUE;

} /* END HAL_clk_ZondaevoPLLEnable */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLDisable
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLDisable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32_t nModeVal;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * First clear the output enable bit
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, PLL_OUTCTRL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Put the PLL in off state
   */
  nModeVal &= ~(HWIO_FMSK(PLL_MODE, PLL_RESET_N) |
                HWIO_FMSK(PLL_MODE, PLL_BYPASSNL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

} /* END HAL_clk_ZondaevoPLLDisable */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLIsEnabled
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLIsEnabled
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nModeVal;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Check whether the PLL is enabled.
   */
  return ((nModeVal & HAL_CLK_PLL_MODE_ACTIVE) == HAL_CLK_PLL_MODE_ACTIVE);

} /* END HAL_clk_ZondaevoPLLIsEnabled */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLConfig
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLConfig
(
  HAL_clk_SourceDescType   *pSource,
  HAL_clk_SourceConfigType  eConfig
)
{
  /*
   * Take action.
   */
  switch (eConfig)
  {
    case HAL_CLK_CONFIG_PLL_FSM_MODE_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, ENABLE_VOTE_RUN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_FSM_MODE_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, ENABLE_VOTE_RUN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX2_ENABLE, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX2_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX2_ENABLE, 1);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX_ENABLE, 0);
      break;

    case HAL_CLK_CONFIG_PLL_AUX_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX_ENABLE, 1);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_TEST_ENABLE, 0);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_TEST_ENABLE, 1);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_MAIN_ENABLE, 1);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_MAIN_ENABLE, 0);
      break;
      
    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_ENABLE, 1);
      break;
      
    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_ENABLE, 0);
      break;

    default:
      break;
  }

} /* END HAL_clk_ZondaevoPLLConfig */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLConfigPLLNormal
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLConfigPLLNormal
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  uint32_t nModeVal;
  uint32_t nUserVal;
  bool     bPLLEnabled = FALSE;
  uint32_t bPLLInFSMMode = 0;
  uint16_t nFracVal = 0;

  /*
   * Check PLL FSM mode.
   */
  bPLLInFSMMode = HAL_CLK_PLL_HWIO_INF(PLL_USER_CTL, pSource, ENABLE_VOTE_RUN);

  /*
   * Check PLL mode.
   */
  bPLLEnabled = HAL_clk_ZondaevoPLLIsEnabled(pSource);

  /*
   * Disable the PLL.
   */
  if (bPLLEnabled)
  {
    HAL_clk_ZondaevoPLLDisable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Program L/Alpha values.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_L_VAL, pSource, PLL_L, pConfig->nL);
  
  /*
   * Get the CONFIG value and clear out fields we will configure.
   */
  nUserVal  =  HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);
  nUserVal &= ~(HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE) |
                HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE) |
                HWIO_FMSK(PLL_USER_CTL_U, PRE_DIV_2_ENABLE) |
                HWIO_FMSK(PLL_USER_CTL_U, POST_DIV_CONTROL));

  /*
   * Program the pre-div value (div-1 to div-2).
   */
  if (pConfig->nPreDiv <= 2 && pConfig->nPreDiv > 0)
  {
    nUserVal |= HWIO_FVAL(PLL_USER_CTL_U, PRE_DIV_2_ENABLE, (pConfig->nPreDiv - 1));
  }

  /*
   * Program the post-div value.
   */
  nUserVal |= HWIO_FVAL(PLL_USER_CTL_U, POST_DIV_CONTROL,
    HAL_clk_ZondaevoPLLPostDivToHW(pConfig->PostDivs.Zondaevo.nAux));

  /*
   *  Check fractional output or integer output.
   */
  if (pConfig->eFracMode == HAL_CLK_PLL_FRAC_MODE_MN)
  {
    /*
     * MN Mode
     */
    nFracVal = (uint16_t)(pConfig->nFracVal & 0x0000FFFF);
    nFracVal |= (uint16_t)((pConfig->nFracVal & 0xFFFF0000) >> 8);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE);
  }
  else
  {
    /*
     * Default to Alpha mode
     */
    nFracVal = (uint16_t)pConfig->nFracVal;
    nUserVal &= ~HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE);
  }
    
    
  HAL_CLK_PLL_HWIO_OUTF(PLL_ALPHA_VAL, pSource, PLL_ALPHA_VAL,nFracVal);

  /*
   * Finally program the USER_CTL_U register.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL_U, pSource, nUserVal);
  
  
   /*
   * For FSM, set the rest_n to bring the PLL out of reset as part of the 
   * steps to enable FSM mode.  This is a one-time programming.
   */
  if (bPLLInFSMMode)
  {
    HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_RESET_N, 1);
  }

  /*
   * Enable the PLL if it was on before.
   */
  if (bPLLEnabled)
  {
    HAL_clk_ZondaevoPLLEnable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  return TRUE;

} /* END HAL_clk_ZondaevoPLLConfigPLLNormal */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLConfigPLLSlew
**
**  Returns:
**    bool - TRUE if successfully configured.
**              FALSE if unable to detect that the PLL successfully locked.
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLConfigPLLSlew
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  bool bResult;
  uint32_t nUserVal, nFracVal;

  /*
   * Program L value.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_L_VAL, pSource,PLL_L, pConfig->nL);
  
  /*
   *  Program alpha val
   */
  nUserVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);
  if (pConfig->eFracMode == HAL_CLK_PLL_FRAC_MODE_MN)
  {
    /*
     * MN Mode
     */
    nFracVal = (uint16_t)(pConfig->nFracVal & 0x0000FFFF);
    nFracVal |= (uint16_t)((pConfig->nFracVal & 0xFFFF0000) >> 8);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE);
  }
  else
  {
    /*
     * Default to Alpha mode
     */
    nFracVal = (uint16_t)pConfig->nFracVal;
    nUserVal &= ~HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE);
    nUserVal |= HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE);
  }
    
    
  HAL_CLK_PLL_HWIO_OUTF(PLL_ALPHA_VAL, pSource, PLL_ALPHA_VAL,nFracVal);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL_U, pSource, nUserVal);

  /*
   * Wait for 11 or more PLL clk_ref ticks for PLL_LOCK_DET to transition to 0.
   * When using a reference clock of XO, the wait requirement is 570 ns.
   */
  HAL_clk_BusyWait(1);

  /*
   * Wait for the PLL to lock during the expected timeout period.
   */
 bResult =
     HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_LOCK_DET),
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_ZondaevoPLLConfigPLLSlew */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLConfigPLL
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLConfigPLL
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  HAL_clk_SourceConfigMode     eMode
)
{
  bool bResult = FALSE;

  switch (eMode)
  {
    case HAL_CLK_SOURCE_CONFIG_MODE_NORMAL:
      bResult = HAL_clk_ZondaevoPLLConfigPLLNormal(pSource, pConfig);
      break;
    case HAL_CLK_SOURCE_CONFIG_MODE_SLEW:
      bResult = HAL_clk_ZondaevoPLLConfigPLLSlew(pSource, pConfig);
      break;
    default:
      bResult = FALSE;
      break;
  }

  return bResult;

} /* END HAL_clk_ZondaevoPLLConfigPLL */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLDetectPLLConfig
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLDetectPLLConfig
(
  HAL_clk_SourceDescType *pSource,
  HAL_clk_PLLConfigType  *pConfig
)
{
  uint32_t nConfigVal;
  uint32_t nMode;
  uint32_t nPostDiv;

  /*
   * Clear all config values not modified in this function.
   */
  pConfig->nMode = 0;

  /*
   * Read current L and Alpha values.
   */
  nMode = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);

  /*
   * Check to see if fractional value is enabled
   */
  pConfig->nFracVal = HAL_CLK_PLL_HWIO_INF(PLL_ALPHA_VAL, pSource,PLL_ALPHA_VAL);
  if ( nMode & HWIO_FMSK(PLL_USER_CTL_U, PLL_FRAC_MODE_ENABLE) )
  {
    if ( nMode & HWIO_FMSK(PLL_USER_CTL_U, FRAC_ALPHA_MN_MODE) )
    {
      pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_MN;
    }
    else
    {
      pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_ALPHA;
    }
  }
  else
  {
    pConfig->eFracMode = HAL_CLK_PLL_FRAC_MODE_UNKNOWN;
  }

  /*
   * Read current L-Val
   */
  pConfig->nL = HAL_CLK_PLL_HWIO_INF(PLL_L_VAL, pSource,PLL_L);

  /*
   * Determine the oscillator source.
   */
  pConfig->nSource = 0;

  /*
   * Get the pre and post dividers.
   */
  nConfigVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);
  pConfig->nPreDiv = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL_U, PRE_DIV_2_ENABLE))
                      >> (HWIO_SHFT(PLL_USER_CTL_U, PRE_DIV_2_ENABLE))) + 1;
  nPostDiv  = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL_U, POST_DIV_CONTROL))
                          >> HWIO_SHFT(PLL_USER_CTL_U, POST_DIV_CONTROL));
  nPostDiv = HAL_clk_ZondaevoPLLPostDivFromHW(nPostDiv);
  pConfig->PostDivs.Zondaevo.nAux = nPostDiv;

} /* END HAL_clk_ZondaevoPLLDetectPLLConfig */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLIsPLLConfigEqual
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLIsPLLConfigEqual
(
  const HAL_clk_PLLConfigType  *pConfigA,
  const HAL_clk_PLLConfigType  *pConfigB
)
{
  uint32_t nMainDivA, nMainDivB;

  if (HAL_clk_GenericIsPLLConfigEqual(pConfigA, pConfigB))
  {
    /* Treat div-0 and div-1 as the same thing. */
    nMainDivA = MAX(1, pConfigA->PostDivs.Zondaevo.nAux);
    nMainDivB = MAX(1, pConfigB->PostDivs.Zondaevo.nAux);

    if (nMainDivA == nMainDivB)
    {
      return TRUE;
    }
  }

  return FALSE;

} /* END HAL_clk_ZondaevoPLLIsPLLConfigEqual */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLIsCalibrated
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLIsCalibrated
(
  HAL_clk_SourceDescType *pSource
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_ZondaevoPLLIsCalibrated */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLSetCalConfig
**
** ======================================================================== */

static bool HAL_clk_ZondaevoPLLSetCalConfig
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_ZondaevoPLLSetCalConfig */


/* ===========================================================================
**  HAL_clk_ZondaevoPLLSetRegSettings
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLSetRegSettings
(
  HAL_clk_SourceDescType              *pSource,
  const HAL_clk_SourceRegSettingsType *pmSettings
)
{
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL,    pSource, pmSettings->nConfigCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U,  pSource, pmSettings->nConfigCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U1, pSource, pmSettings->nConfigCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL,      pSource, pmSettings->nTestCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U,    pSource, pmSettings->nTestCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U1,   pSource, pmSettings->nTestCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL,      pSource, pmSettings->nUserCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL_U,    pSource, pmSettings->nUserCtl1);

} /* END HAL_clk_ZondaevoPLLSetRegSettings */

/* ===========================================================================
**  HAL_clk_ZondaevoPLLGetRegSettings
**
** ======================================================================== */

static void HAL_clk_ZondaevoPLLGetRegSettings
(
  HAL_clk_SourceDescType              *pSource,
  HAL_clk_SourceRegSettingsType       *pmSettings
)
{
  pmSettings->nConfigCtl = HAL_CLK_PLL_HWIO_IN(PLL_CONFIG_CTL, pSource);
  pmSettings->nConfigCtl1 = HAL_CLK_PLL_HWIO_IN(PLL_CONFIG_CTL_U, pSource);
  pmSettings->nConfigCtl2 = HAL_CLK_PLL_HWIO_IN(PLL_CONFIG_CTL_U1, pSource);
  pmSettings->nTestCtl = HAL_CLK_PLL_HWIO_IN(PLL_TEST_CTL, pSource);
  pmSettings->nTestCtl1 = HAL_CLK_PLL_HWIO_IN(PLL_TEST_CTL_U, pSource);
  pmSettings->nTestCtl2 = HAL_CLK_PLL_HWIO_IN(PLL_TEST_CTL_U1, pSource);
  pmSettings->nUserCtl = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  pmSettings->nUserCtl1 = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);
  pmSettings->nMode = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);
  pmSettings->nFracVal = HAL_CLK_PLL_HWIO_IN(PLL_ALPHA_VAL, pSource);
  pmSettings->nLVal = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pSource);
  pmSettings->nState = HAL_CLK_PLL_HWIO_IN(PLL_STATE, pSource);
  pmSettings->nOpmode = HAL_CLK_PLL_HWIO_IN(PLL_OPMODE, pSource);
  
} /* END HAL_clk_ZondaevoPLLGetRegSettings */