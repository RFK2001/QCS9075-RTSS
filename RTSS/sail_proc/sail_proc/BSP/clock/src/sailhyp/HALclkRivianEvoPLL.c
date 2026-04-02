/*
==============================================================================

FILE:         HALclkRivianevoPLL.c

DESCRIPTION:
  This file contains the clock HAL code for the Rivian Evo PLL control.
  These PLLs are of the Rivian Evo PLL variety.

==============================================================================
            Copyright (c) 2021 QUALCOMM Technologies Incorporated. All Rights Reserved.
                    QUALCOMM Proprietary and Confidential.
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
#include "HALclkRivianEvoPLL.h"
#include "chipinfodefs.h"


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * HAL_CLK_PLL_MODE_ACTIVE
 */
#define HAL_CLK_PLL_MODE_ACTIVE  \
  (HWIO_FMSK(PLL_MODE, PLL_LOCK_DET)  | \
   HWIO_FMSK(PLL_MODE, PLL_RESET_N))

/*
 * HAL_CLK_LOCK_TIMEOUT_US
 *
 * Timeout in US for PLL_LOCK_DET to get set.
 */
#define HAL_CLK_LOCK_TIMEOUT_US 50

/*
 * CLOCK_WAIT_FOR_PLL_LOCK
 *
 * Flag for whether to wait for the PLL to lock or not.
 */
#define CLOCK_WAIT_FOR_PLL_LOCK TRUE

/* ============================================================================
**    Data Declarations
** ==========================================================================*/

/*
 * HAL_clk_RivianvoPLLControl
 *
 * Control function array for the Rivianevo PLLs.
 */
HAL_clk_SourceControlType HAL_clk_RivianevoPLLControl =
{
  .Enable           = HAL_clk_RivianevoPLLEnable,
  .Disable          = HAL_clk_RivianevoPLLDisable,
  .IsEnabled        = HAL_clk_RivianevoPLLIsEnabled,
  .Config           = HAL_clk_RivianevoPLLConfig,
  .ConfigPLL        = HAL_clk_RivianevoPLLConfigPLL,
  .DetectPLLConfig  = HAL_clk_RivianevoPLLDetectPLLConfig,
  .EnableVote       = HAL_clk_RivianevoPLLEnableVote,
  .DisableVote      = HAL_clk_RivianevoPLLDisableVote,
  .IsVoteEnabled    = HAL_clk_RivianevoPLLIsVoteEnabled,
  .IsPLLConfigEqual = HAL_clk_RivianevoPLLIsPLLConfigEqual,
  .IsCalibrated     = HAL_clk_RivianevoPLLIsCalibrated,
  .SetCalConfig     = HAL_clk_RivianevoPLLSetCalConfig,
  .SetRegSettings   = HAL_clk_RivianevoPLLSetRegSettings,
  .GetRegSettings   = HAL_clk_RivianevoPLLGetRegSettings,
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/* ===========================================================================
**  HAL_clk_RivianevoPLLEnableVote
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLEnableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;
  bool     bResult = FALSE;
  
  if ( pSource->VoterRegister.nAddr != 0 )
  {

    /*
     * Set the appropriate bit.
     */
    nVal = inpdw(pSource->VoterRegister.nAddr) | pSource->VoterRegister.nMask;
    outpdw(pSource->VoterRegister.nAddr, nVal);

  /*
   * Wait for the PLL to go active during the 15 us timeout period.
   */
    bResult =
      HAL_clk_ValidateRegSetTimeout(
        HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
        HAL_CLK_PLL_MODE_ACTIVE,
        HAL_CLK_LOCK_TIMEOUT_US);

  }
  return bResult;

} /* END HAL_clk_RivianevoPLLEnableVote */


/* ===========================================================================
**  HAL_clk_RivianevoPLLDisableVote
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLDisableVote
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nVal;

  if ( pSource->VoterRegister.nAddr != 0 )
  {
    /*
     * Clear the appropriate bit.
     */
    nVal = inpdw(pSource->VoterRegister.nAddr) & (~pSource->VoterRegister.nMask);
    outpdw(pSource->VoterRegister.nAddr, nVal);
  }

} /* END HAL_clk_RivianevoPLLDisableVote */


/* ===========================================================================
**  HAL_clk_RivianevoPLLIsVoteEnabled
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLIsVoteEnabled
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

} /* END HAL_clk_RivianevoPLLIsVoteEnabled */

/* ===========================================================================
**  HAL_clk_RivianevoPLLEnable
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLEnable
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
  if (HAL_clk_RivianevoPLLIsEnabled(pSource))
  {
    return TRUE;
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Assert PLL bypass.
   * This latches L value.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_BYPASSNL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);
  
   /*
   * Assert the reset_n field to put the PLL in standby state.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_RESET_N);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);
  
  /*
   * Set OPMODE to Run State
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);
 
  /*
   * Wait for the PLL to lock during the 15 us timeout period.
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
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Assert the output control field.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_OUTCTRL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  return TRUE;

} /* END HAL_clk_RivianevoPLLEnable */


/* ===========================================================================
**  HAL_clk_RivianevoPLLDisable
**
**  The appropriate disable mode is executed based on the eMode argument.
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLDisable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  uint32_t  nModeVal;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);
  
   /*
   * Put the PLL in reset mode
   */
  nModeVal |= (HWIO_FMSK(PLL_MODE, PLL_RESET_N) |
                HWIO_FMSK(PLL_MODE, PLL_BYPASSNL));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Wait 2 ticks of the output main clock.
   */
  HAL_clk_BusyWait(1);

  /*
   * De-assert the PLL mode.
   */
  nModeVal &= ~HWIO_PLL_MODE_RMSK; 
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

} /* END HAL_clk_RivianevoPLLDisable */


/* ===========================================================================
**  HAL_clk_RivianevoPLLIsEnabled
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLIsEnabled
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

} /* END HAL_clk_RivianevoPLLIsEnabled */


/* ===========================================================================
**  HAL_clk_RivianevoPLLConfig
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLConfig
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

    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_ODD_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_ODD_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_AUX_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_MAIN_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_MAIN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_MAIN_EN, 0);
      break;
    default:
      break;
  }

} /* END HAL_clk_RivianevoPLLConfig */


/* ===========================================================================
**  HAL_clk_RivianPLLConfigPLLSlew
**
**  Returns:
**    boolean - TRUE if successfully configured.
**           FALSE if unable to detect that the PLL successfully locked.
** ======================================================================== */

static boolean HAL_clk_RivianevoPLLConfigPLLSlew
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  boolean                      bTriggerUpdate
)
{
  boolean  bResult;

  /*
   * Program L value.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_L_VAL, pSource, PLL_L_VAL, pConfig->nL);

  /*
   * Check if the update will be triggered later.
   */
  if (bTriggerUpdate != TRUE)
  {
    return TRUE;
  }

  /*
   * Latch in the new configuration values.
   * Trigger latch of new configuration using async update handshake
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_LATCH_INPUT, 0x1);

  /*
   * Poll PLL_MODE[PLL_ACK_LATCH] until high.
   */
  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_ACK_LATCH),
      HAL_CLK_LOCK_TIMEOUT_US);
  if (bResult != TRUE)
  {
    return bResult;
  }

  /*
   * Clear PLL_MODE[PLL_LATCH_INPUT] equal to zero.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_LATCH_INPUT, 0x0);

  /*
   * Poll PLL_MODE[PLL_ACK_LATCH] until low.
   */
  bResult =
    HAL_clk_ValidateRegClearTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_ACK_LATCH),
      HAL_CLK_LOCK_TIMEOUT_US);
  if (bResult != TRUE)
  {
    return bResult;
  }

  /*
   * Wait 11 ticks of PLL ref_clk (@ XO, this is 570 ns) for the PLL to change.
   * if it is going to do so.  However, if the frequency change is small,
   * PLL_LOCK_DET will remain at one.
   */
  HAL_clk_BusyWait(1);

  /*
   * Wait for the PLL to lock during the timeout period.
   */
  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_LOCK_DET),
      HAL_CLK_LOCK_TIMEOUT_US);

  return bResult;

} /* END HAL_clk_RivianPLLConfigPLLSlew */


/* ===========================================================================
**  HAL_clk_RivianPLLConfigPLLNormal
**
**  Returns:
**    boolean - TRUE if successfully configured. FALSE otherwise.
** ======================================================================== */

static bool HAL_clk_RivianevoPLLConfigPLLNormal
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  uint32_t nUserVal;
  uint32_t nAuxDiv, nEvenDiv;
  boolean  bPLLInFSMMode, bPLLInReset;

  /*
   * Check PLL mode.
   */
  bPLLInFSMMode = HAL_CLK_PLL_HWIO_INF(PLL_USER_CTL, pSource, ENABLE_VOTE_RUN);
  bPLLInReset = !HAL_CLK_PLL_HWIO_INF(PLL_MODE, pSource, PLL_RESET_N);

  /*
   * Disable the PLL if already out of reset.
   */
  if (!bPLLInReset)
  {
    HAL_clk_RivianevoPLLDisable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  /*
   * Program L value.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_L_VAL, pSource, PLL_L_VAL, pConfig->nL);

  /*
   * Get the CONFIG value and clear out fields we will configure.
   */
  nUserVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  nUserVal &= ~(HWIO_FMSK(PLL_USER_CTL, PRE_DIV_RATIO) |
                HWIO_FMSK(PLL_USER_CTL_U, POST_DIV_RATIO_AUX) |
                HWIO_FMSK(PLL_USER_CTL, POST_DIV_RATIO_EVEN));

  /*
   * Program the pre-div value (div-1 to div-8).
   */
  if (pConfig->nPreDiv <= 8 && pConfig->nPreDiv > 0)
  {
    nUserVal |= HWIO_FVAL(PLL_USER_CTL, PRE_DIV_RATIO, (pConfig->nPreDiv - 1));
  }

  /*
   * Program the post-div values.
   */
  nAuxDiv = pConfig->PostDivs.Rivianevo.nAux;
  nEvenDiv = pConfig->PostDivs.Rivianevo.nEven;
  if (nEvenDiv > 0)
  {
    nEvenDiv--;
  }
  nUserVal |= HWIO_FVAL(PLL_USER_CTL_U, POST_DIV_RATIO_AUX, nAuxDiv);
  nUserVal |= HWIO_FVAL(PLL_USER_CTL, POST_DIV_RATIO_EVEN, nEvenDiv);

  /*
   * Finally program the USER_CTL register.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL, pSource, nUserVal);

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
   * Don't wait for the PLL to lock if it's in FSM mode since
   * the PLL_OUTCTRL won't toggle absent client voting.
   */
  if (!bPLLInReset)
  {
   HAL_clk_RivianevoPLLEnable(pSource, !bPLLInFSMMode, NULL);
  }

  return TRUE;

} /* END HAL_clk_RivianevoPLLConfigPLLNormal */

/* ===========================================================================
**  HAL_clk_RivianevoPLLConfigPLL
**
**  Returns:
**    boolean - TRUE if successfully configured. FALSE otherwise.
** ======================================================================== */

static bool HAL_clk_RivianevoPLLConfigPLL
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  HAL_clk_SourceConfigMode     eMode
)
{
  bool bResult = FALSE;

  /*
   * Program the appropriate config sequence.
   */
  if (eMode == HAL_CLK_SOURCE_CONFIG_MODE_NORMAL)
  {
    bResult = HAL_clk_RivianevoPLLConfigPLLNormal(pSource, pConfig);
  }
  else if(eMode == HAL_CLK_SOURCE_CONFIG_MODE_SLEW)
  {
    bResult = HAL_clk_RivianevoPLLConfigPLLSlew(pSource, pConfig, TRUE);
  }
  else if (eMode == HAL_CLK_SOURCE_CONFIG_MODE_PENDING)
  {
    bResult = HAL_clk_RivianevoPLLConfigPLLSlew(pSource, pConfig, FALSE);
  }

  return bResult;

} /* END HAL_clk_RivianevoPLLConfigPLL */


/* ===========================================================================
**  HAL_clk_RivianevoPLLDetectPLLConfig
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLDetectPLLConfig
(
  HAL_clk_SourceDescType *pSource,
  HAL_clk_PLLConfigType  *pConfig
)
{
  uint32_t nRegVal;

  /*
   * Clear all config values not modified in this function.
   */
  pConfig->nFracVal = 0;

  /*
   * Read L value.
   */
  pConfig->nL = HAL_CLK_PLL_HWIO_INF(PLL_L_VAL, pSource, PLL_L_VAL);

  /*
   * No reference clock mux, so default to 0.
   */
  pConfig->nSource = 0;

  /*
   * Read USER_CTL register.
   */
  nRegVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);

  /*
   * Get the pre divider.
   */
  pConfig->nPreDiv =
    HAL_CLK_PLL_HWIO_INFV(PLL_USER_CTL, pSource, PRE_DIV_RATIO, nRegVal) + 1;

  /*
   * Get the post divider.
   */
  pConfig->PostDivs.Rivianevo.nEven =
    HAL_CLK_PLL_HWIO_INFV(PLL_USER_CTL, pSource, POST_DIV_RATIO_EVEN, nRegVal)
    + 1;

  pConfig->PostDivs.Rivianevo.nAux =
    HAL_CLK_PLL_HWIO_INFV(PLL_USER_CTL_U, pSource, POST_DIV_RATIO_AUX, nRegVal);

  /*
   * Add 1 for case where field is 0.  Otherwise leave as is.
   */
  if (pConfig->PostDivs.Rivianevo.nAux == 0)
  {
    pConfig->PostDivs.Rivianevo.nAux++;
  }

} /* END HAL_clk_RivianevoPLLDetectPLLConfig */


/* ===========================================================================
**  HAL_clk_RivianevoPLLIsPLLConfigEqual
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLIsPLLConfigEqual
(
  const HAL_clk_PLLConfigType  *pConfigA,
  const HAL_clk_PLLConfigType  *pConfigB
)
{
  uint32_t nEvenDivA, nEvenDivB;
  uint32_t nAuxDivA, nAuxDivB;

  if (HAL_clk_GenericIsPLLConfigEqual(pConfigA, pConfigB))
  {
    /* Treat div-0 and div-1 as the same thing. */
    nEvenDivA = MAX(1, pConfigA->PostDivs.Rivianevo.nEven);
    nEvenDivB = MAX(1, pConfigB->PostDivs.Rivianevo.nEven);
    nAuxDivA  = MAX(1, pConfigA->PostDivs.Rivianevo.nAux);
    nAuxDivB  = MAX(1, pConfigB->PostDivs.Rivianevo.nAux);

    if (nEvenDivA == nEvenDivB && nAuxDivA  == nAuxDivB)
    {
      return TRUE;
    }
  }

  return FALSE;

} /* END HAL_clk_RivianevoPLLIsPLLConfigEqual */


/* ===========================================================================
**  HAL_clk_RivianevoPLLIsCalibrated
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLIsCalibrated
(
  HAL_clk_SourceDescType *pSource
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_RivianevoPLLIsCalibrated */


/* ===========================================================================
**  HAL_clk_RivianevoPLLSetCalConfig
**
** ======================================================================== */

static bool HAL_clk_RivianevoPLLSetCalConfig
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  /* No calibration required. */
  return TRUE;

} /* HAL_clk_RivianevoPLLSetCalConfig */


/* ===========================================================================
**  HAL_clk_RivianevoPLLEnableNormal
**
**  PLL initial bringup.
**  When in the off state, the bias is off and draws no power.
**  This procedure results in calibration being performed.
**
**  This procedure applies only to Rivian PLL type.
**
**  Returns:
**    boolean - TRUE if successfully enabled. FALSE otherwise.
** ======================================================================== */

static bool HAL_clk_RivianevoPLLEnableNormal
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t nModeVal;
  boolean  bResult;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Assert PLL bypass.
   * This latches L value.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_BYPASSNL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);
  
   /*
   * Assert the reset_n field to put the PLL in standby state.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_RESET_N);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Set OPMODE to Run State
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);
 
  /*
   * Wait for the PLL to lock during the 15 us timeout period.
   */
  bResult =
    HAL_clk_ValidateRegSetTimeout(
      HAL_CLK_PLL_HWIO_ADDR(PLL_MODE, pSource),
      HWIO_FMSK(PLL_MODE, PLL_LOCK_DET),
      HAL_CLK_LOCK_TIMEOUT_US);

  /*
   * Return immediately if the lock failed.
   */
  if (!bResult)
  {
    return FALSE;
  }

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);

  /*
   * Assert the output control field.
   */
  nModeVal |= HWIO_FMSK(PLL_MODE, PLL_OUTCTRL);
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  return TRUE;

} /* END HAL_clk_RivianevoPLLEnableNormal */


/* ===========================================================================
**  HAL_clk_RivianevoPLLDisableToStandby
**
**  PLL shutdown to standby state.
**  This procedure leaves the bias on:
**    skips calibration when enabling via HAL_clk_RivianPLLEnableFromStandby.
**    draws 75-100 micro amps while in standby mode.
**
**  This procedure applies only to Rivian PLL type.
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLDisableToStandby
(
  HAL_clk_SourceDescType *pSource
)
{
  uint32_t  nModeVal;

  /*
   * Read current mode value.
   */
  nModeVal = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);
  
  /*
   * Put the PLL in reset mode
   */
  nModeVal |= (HWIO_FMSK(PLL_MODE, PLL_RESET_N));
  HAL_CLK_PLL_HWIO_OUT(PLL_MODE, pSource, nModeVal);

  /*
   * Wait 2 ticks of the output main clock.
   */
  HAL_clk_BusyWait(1);

  /*
   * Set OPMODE to Standby State
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_STANDBY);
  
} /* END HAL_clk_RivianevoPLLDisableToStandby */


/* ===========================================================================
**  HAL_clk_RivianevoPLLSetRegSettings
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLSetRegSettings
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
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL,      pSource, pmSettings->nUserCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL_U,    pSource, pmSettings->nUserCtl1);

} /* END HAL_clk_RivianevoPLLSetRegSettings */

/* ===========================================================================
**  HAL_clk_RivianevoPLLGetRegSettings
**
** ======================================================================== */

static void HAL_clk_RivianevoPLLGetRegSettings
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
  pmSettings->nUserCtl = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  pmSettings->nUserCtl1 = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL_U, pSource);
  pmSettings->nMode = HAL_CLK_PLL_HWIO_IN(PLL_MODE, pSource);
  pmSettings->nLVal = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pSource);
  pmSettings->nState = HAL_CLK_PLL_HWIO_IN(PLL_STATE, pSource);
  pmSettings->nOpmode = HAL_CLK_PLL_HWIO_IN(PLL_OPMODE, pSource);
  
} /* END HAL_clk_RivianevoPLLGetRegSettings */