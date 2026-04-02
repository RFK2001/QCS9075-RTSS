/*
==============================================================================

FILE:         HALclkPongoevoPLL.c

DESCRIPTION:
  This file contains the clock HAL code for the Pongoevo PLL control.
  These PLLs are of the Pongoevo PLL variety.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/src/sailhyp/HALclkPongoEvoPLL.c#1 $

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

#include <stdio.h>
#include "HALhwio.h"
#include "HALclkGenericPLL.h"
#include "HALclkPongoEvoPLL.h"
#include "HALclkHWIO.h"
#include "sail_security_control_hwio.h"

/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/

#define TWO_POINT_CALIB_PONGO_PLL

/*
 * HAL_CLK_PLL_MODE_*
 *
 * Definitions for configuring the PLLn_MODE register.
 */
#define HAL_CLK_PLL_MODE_ACTIVE  \
  (HWIO_FMSK(PLL_MODE, PLL_LOCK_DET)  | \
   HWIO_FMSK(PLL_MODE, PLL_RESET_N))
   
/*
 * HAL_CLK_LOCK_TIMEOUT_US
 *
 * Timeout in usec for PLL_LOCK_DET to get set.
 * For Pongoevo, this is 50us worst-case lock time.  However, when
 * the PLL is sourced from RO, it may take longer for initial lock, 
 * up to 1.5 ms.
 */
#define HAL_CLK_LOCK_TIMEOUT_US 1500


/* ============================================================================
**    Data Declarations
** ==========================================================================*/

/*
 * HAL_clk_PongoevoPLLControl
 *
 * Control function array for the Pongoevo PLLs.
 */
HAL_clk_SourceControlType HAL_clk_PongoevoPLLControl =
{
  .Enable           = HAL_clk_PongoevoPLLEnable,
  .Disable          = HAL_clk_PongoevoPLLDisable,
  .IsEnabled        = HAL_clk_PongoevoPLLIsEnabled,
  .Config           = HAL_clk_PongoevoPLLConfig,
  .ConfigPLL        = HAL_clk_PongoevoPLLConfigPLL,
  .DetectPLLConfig  = HAL_clk_PongoevoPLLDetectPLLConfig,
  .IsPLLConfigEqual = HAL_clk_PongoevoPLLIsPLLConfigEqual,
  .IsCalibrated     = HAL_clk_PongoevoPLLIsCalibrated,
  .SetCalConfig     = HAL_clk_PongoevoPLLSetCalConfig,
  .SetRegSettings   = HAL_clk_PongoevoPLLSetRegSettings,
  .GetRegSettings   = HAL_clk_PongoevoPLLGetRegSettings,
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/


/* ===========================================================================
**  HAL_clk_PongoevoPLLPostDivToHW
**
** ======================================================================== */

static uint32_t HAL_clk_PongoevoPLLPostDivToHW (uint32_t nDivider)
{
  if (nDivider)
  {
    nDivider--;
  }

  return nDivider;

} /* END HAL_clk_PongoevoPLLPostDivToHW */


/* ===========================================================================
**  HAL_clk_PongoevoPLLPostDivFromHW
**
** ======================================================================== */

static uint32_t HAL_clk_PongoevoPLLPostDivFromHW (uint32_t nDivider)
{
  return nDivider + 1;

} /* END HAL_clk_PongoevoPLLPostDivFromHW */



/* ===========================================================================
**  HAL_clk_PongoevoPLLEnable
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLEnable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  bool     bResult;

  /*
   * Check if PLL is already enabled and return
   */
  if (HAL_clk_PongoevoPLLIsEnabled(pSource))
  {
    return true;
  }

  /*
   * Set the PLL opmode to run mode.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_RUN);
  
  /*
   * Take PLL out of reset, which will switch to configured OPMODE.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_RESET_N, 1);

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
    return false;
  }

#ifdef TWO_POINT_CALIB_PONGO_PLL
  /* Second calibration request to improve accuracy */
  HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL_U, pSource, REQUEST_CAL, 1);
  HAL_clk_BusyWait(1);
  HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL_U, pSource, REQUEST_CAL, 0);
#endif
  
  /*
   * Enable the PLL outputs.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_OUTCTRL, 1);
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_CLOCK_SELECT, 1);

  return true;

} /* END HAL_clk_PongoevoPLLEnable */


/* ===========================================================================
**  HAL_clk_PongoevoPLLDisable
**
** ======================================================================== */

static void HAL_clk_PongoevoPLLDisable
(
  HAL_clk_SourceDescType        *pSource,
  HAL_clk_SourceDisableModeType  eMode,
  void                          *pData
)
{
  /*
   * Disable the PLL outputs.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_OUTCTRL, 0);

  /*
   * Wait 2 ticks of the output main clock.
   */
  HAL_clk_BusyWait(1);
  
  /*
   * Disable the PLL.
   */
  if (eMode == HAL_CLK_SOURCE_DISABLE_MODE_STANDBY)
  {
    HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_STANDBY);
  }
  else
  {
    HAL_CLK_PLL_HWIO_OUT(PLL_OPMODE, pSource, HAL_PLL_OPMODE_STANDBY);
    HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_RESET_N, 0);
  }

} /* END HAL_clk_PongoevoPLLDisable */


/* ===========================================================================
**  HAL_clk_PongoevoPLLIsEnabled
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLIsEnabled
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

} /* END HAL_clk_PongoevoPLLIsEnabled */


/* ===========================================================================
**  HAL_clk_PongoevoPLLConfig
**
** ======================================================================== */

static void HAL_clk_PongoevoPLLConfig
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
    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_TEST_EN, 0);
      break;

    case HAL_CLK_CONFIG_PLL_TEST_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_TEST_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_ENABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_EN, 1);
      break;

    case HAL_CLK_CONFIG_PLL_EVEN_OUTPUT_DISABLE:
      HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL, pSource, PLLOUT_EVEN_EN, 0);
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

} /* END HAL_clk_PongoevoPLLConfig */


/* ===========================================================================
**  HAL_clk_PongoevoPLLConfigPLLNormal
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLConfigPLLNormal
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  uint32_t nUserVal;
  bool     bPLLEnabled = false;


  /*
   * Check PLL mode.
   */
  bPLLEnabled = HAL_clk_PongoevoPLLIsEnabled(pSource);

  /*
   * Disable the PLL.
   */
  if (bPLLEnabled)
  {
    HAL_clk_PongoevoPLLDisable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  /* Select internal DCO (internally generated 38.4MHz) for output. */
  HAL_CLK_PLL_HWIO_OUTF(PLL_USER_CTL_U, pSource, INTERNAL_CLOCK_SELECTION, 2);

  /*
   * Program L values.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_L_VAL, pSource, pConfig->nL);
  
  /*
   * Turn off the output.
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_OUTCTRL, 0);

  
  /*
   * XO must be made available
   */
  HAL_CLK_PLL_HWIO_OUTF(PLL_MODE, pSource, PLL_CAL_XO_PRESENT, 0x1);

  
  while ( HAL_CLK_PLL_HWIO_INF(PLL_MODE, pSource, PLL_IN_CALIBRATION) != 0 );
 
  /*
   * Get the CONFIG value and clear out fields we will configure.
   */
  nUserVal  =  HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);
  nUserVal &= ~HWIO_FMSK(PLL_USER_CTL, POST_DIV_RATIO_MAIN);
  nUserVal &= ~HWIO_FMSK(PLL_USER_CTL, POST_DIV_RATIO_EVEN);

  /*
   * Program the post-div value.
   */
  nUserVal |= HWIO_FVAL(PLL_USER_CTL, POST_DIV_RATIO_MAIN,
    HAL_clk_PongoevoPLLPostDivToHW(pConfig->PostDivs.Pongoevo.nMain));

  nUserVal |= HWIO_FVAL(PLL_USER_CTL, POST_DIV_RATIO_EVEN,
    HAL_clk_PongoevoPLLPostDivToHW(pConfig->PostDivs.Pongoevo.nEven));

  /*
   * Enable MAIN_OUT_ENA bit.
   */
  nUserVal |= HWIO_FMSK(PLL_USER_CTL, PLLOUT_MAIN_EN);

  /*
   * Finally program the USER_CTL register.
   */
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL, pSource, nUserVal);


  /*
   * Enable the PLL if it was on before.
   */
  if (bPLLEnabled)
  {
    HAL_clk_PongoevoPLLEnable(pSource, HAL_CLK_SOURCE_DISABLE_MODE_NORMAL, NULL);
  }

  return true;

} /* END HAL_clk_PongoevoPLLConfigPLLNormal */


/* ===========================================================================
**  HAL_clk_PongoevoPLLConfigPLLSlew
**
**  Returns:
**    bool - true if successfully configured.
**              false if unable to detect that the PLL successfully locked.
** ======================================================================== */

static bool HAL_clk_PongoevoPLLConfigPLLSlew
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  /*
   * No slewing ability.
   */
  return FALSE;

} /* END HAL_clk_PongoevoPLLConfigPLLSlew */


/* ===========================================================================
**  HAL_clk_PongoevoPLLConfigPLL
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLConfigPLL
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig,
  HAL_clk_SourceConfigMode     eMode
)
{
  bool bResult = false;

  switch (eMode)
  {
    case HAL_CLK_SOURCE_CONFIG_MODE_NORMAL:
      bResult = HAL_clk_PongoevoPLLConfigPLLNormal(pSource, pConfig);
      break;
    case HAL_CLK_SOURCE_CONFIG_MODE_SLEW:
      bResult = HAL_clk_PongoevoPLLConfigPLLSlew(pSource, pConfig);
      break;
    default:
      bResult = false;
      break;
  }

  return bResult;

} /* END HAL_clk_PongoevoPLLConfigPLL */


/* ===========================================================================
**  HAL_clk_PongoevoPLLDetectPLLConfig
**
** ======================================================================== */

static void HAL_clk_PongoevoPLLDetectPLLConfig
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
  nMode = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);

  /*
   * Read current L-Val
   */
  pConfig->nL = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pSource);

  /*
   * Determine the oscillator source.
   */
  pConfig->nSource = 0;

  nConfigVal = HAL_CLK_PLL_HWIO_IN(PLL_USER_CTL, pSource);

  /*
   * No pre-divider.
   */
  pConfig->nPreDiv = 0;

  /*
   * Main divider.
   */
  nPostDiv  = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, POST_DIV_RATIO_MAIN))
                          >> HWIO_SHFT(PLL_USER_CTL, POST_DIV_RATIO_MAIN));
  nPostDiv = HAL_clk_PongoevoPLLPostDivFromHW(nPostDiv);
  pConfig->PostDivs.Pongoevo.nMain = nPostDiv;

  /*
   * Even divider.
   */
  nPostDiv  = ((nConfigVal & HWIO_FMSK(PLL_USER_CTL, POST_DIV_RATIO_EVEN))
                          >> HWIO_SHFT(PLL_USER_CTL, POST_DIV_RATIO_EVEN));
  nPostDiv = HAL_clk_PongoevoPLLPostDivFromHW(nPostDiv);
  pConfig->PostDivs.Pongoevo.nEven = nPostDiv;

} /* END HAL_clk_PongoevoPLLDetectPLLConfig */


/* ===========================================================================
**  HAL_clk_PongoevoPLLIsPLLConfigEqual
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLIsPLLConfigEqual
(
  const HAL_clk_PLLConfigType  *pConfigA,
  const HAL_clk_PLLConfigType  *pConfigB
)
{
  uint32_t nMainDivA, nMainDivB;
  uint32_t nEvenDivA, nEvenDivB;

  if (HAL_clk_GenericIsPLLConfigEqual(pConfigA, pConfigB))
  {
    /* Treat div-0 and div-1 as the same thing. */
    nMainDivA = MAX(1, pConfigA->PostDivs.Pongoevo.nMain);
    nMainDivB = MAX(1, pConfigB->PostDivs.Pongoevo.nMain);
    nEvenDivA = MAX(1, pConfigA->PostDivs.Pongoevo.nEven);
    nEvenDivB = MAX(1, pConfigB->PostDivs.Pongoevo.nEven);

    if (nMainDivA == nMainDivB && nEvenDivA == nEvenDivB)
    {
      return true;
    }
  }

  return false;

} /* END HAL_clk_PongoevoPLLIsPLLConfigEqual */


/* ===========================================================================
**  HAL_clk_PongoevoPLLIsCalibrated
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLIsCalibrated
(
  HAL_clk_SourceDescType *pSource
)
{
  /* No calibration supported */
  
  return true;

} /* HAL_clk_PongoevoPLLIsCalibrated */


/* ===========================================================================
**  HAL_clk_PongoevoPLLSetCalConfig
**
** ======================================================================== */

static bool HAL_clk_PongoevoPLLSetCalConfig
(
  HAL_clk_SourceDescType      *pSource,
  const HAL_clk_PLLConfigType *pConfig
)
{
  /* No calibration supported */
  return true;

} /* HAL_clk_PongoevoPLLSetCalConfig */


/* ===========================================================================
**  HAL_clk_PongoevoPLLSetRegSettings
**
** ======================================================================== */

static void HAL_clk_PongoevoPLLSetRegSettings
(
  HAL_clk_SourceDescType              *pSource,
  const HAL_clk_SourceRegSettingsType *pmSettings
)
{
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL,    pSource, pmSettings->nConfigCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U,  pSource, pmSettings->nConfigCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U1, pSource, pmSettings->nConfigCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_CONFIG_CTL_U2, pSource, pmSettings->nConfigCtl3);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL,      pSource, pmSettings->nTestCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U,    pSource, pmSettings->nTestCtl1);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U1,   pSource, pmSettings->nTestCtl2);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U2,   pSource, pmSettings->nTestCtl3);
  HAL_CLK_PLL_HWIO_OUT(PLL_TEST_CTL_U3,   pSource, pmSettings->nTestCtl4);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL,      pSource, pmSettings->nUserCtl);
  HAL_CLK_PLL_HWIO_OUT(PLL_USER_CTL_U,    pSource, pmSettings->nUserCtl1);

#ifdef TWO_POINT_CALIB_PONGO_PLL

  uint32_t nK = 0; /* K temp coefficient */
  /*
   * Apply 2 point calibration to the PLL as per Pongo_Evo HPG:
   * Section 5.1 Turning on the PLL (OFF -> RUN + 2pt FACTORY CAL)
   *
   */
  if(HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL5_PLL_MODE) == pSource->nAddr )
  {

      nK = HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW9_MSB, SAIL_PLL5_K );

      if (nK)
      {
          HAL_CLK_PLL_HWIO_OUTF( PLL_CONFIG_CTL_U2, pSource, TEMPCOMP_K_DEFAULT, nK );

          HAL_CLK_PLL_HWIO_OUTF(PLL_TEST_CTL_U2, pSource, DISABLE_PCAL, 1);
          HAL_CLK_PLL_HWIO_OUTF(PLL_TEST_CTL_U1, pSource, ENABLE_PCODE_CAL, 1);

          HAL_CLK_PLL_HWIO_OUTF( PLL_TEST_CTL_U1,
                                 pSource,
                                 FORCE_TDO_PCAL_VALUE,
                                 (( HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW10_LSB, SAIL_PLL5_TDOPCODE ) ) << 2));

          HAL_CLK_PLL_HWIO_OUTF( PLL_TEST_CTL_U1,
                                 pSource,
                                 FORCE_PCAL_VALUE,
                                 (( HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW10_LSB, SAIL_PLL5_RDOPCODE  ) ) << 2));
      }
  }

  if(HWIO_ADDR(SAILSS_CLKCTL_SAILSS_CC_PLL6_PLL_MODE) == pSource->nAddr)
  {

      nK = HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW10_MSB, SAIL_PLL6_K );

      if (nK)
      {
          HAL_CLK_PLL_HWIO_OUTF( PLL_CONFIG_CTL_U2, pSource, TEMPCOMP_K_DEFAULT, nK );

          HAL_CLK_PLL_HWIO_OUTF(PLL_TEST_CTL_U2, pSource, DISABLE_PCAL, 1);
          HAL_CLK_PLL_HWIO_OUTF(PLL_TEST_CTL_U1, pSource, ENABLE_PCODE_CAL, 1);

          HAL_CLK_PLL_HWIO_OUTF( PLL_TEST_CTL_U1,
                                 pSource,
                                 FORCE_TDO_PCAL_VALUE,
                                 (( HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW11_LSB, SAIL_PLL6_TDOPCODE ) ) << 2));


          HAL_CLK_PLL_HWIO_OUTF( PLL_TEST_CTL_U1,
                                 pSource,
                                 FORCE_PCAL_VALUE,
                                 (( HWIO_INF( SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW11_LSB, SAIL_PLL6_RDOPCODE  ) ) << 2));
      }
  }
#endif
} /* END HAL_clk_PongoevoPLLSetRegSettings */

/* ===========================================================================
**  HAL_clk_PongoevoPLLGetRegSettings
**
** ======================================================================== */

static void HAL_clk_PongoevoPLLGetRegSettings
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
  pmSettings->nLVal = HAL_CLK_PLL_HWIO_IN(PLL_L_VAL, pSource);
  pmSettings->nOpmode = HAL_CLK_PLL_HWIO_IN(PLL_OPMODE, pSource);
  pmSettings->nState = HAL_CLK_PLL_HWIO_IN(PLL_STATE, pSource);
} /* END HAL_clk_PongoevoPLLGetRegSettings */
