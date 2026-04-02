#ifndef __HALCLKZondaEVOPLL_H__
#define __HALCLKZondaEVOPLL_H__
/*
==============================================================================

FILE:         HALclkZondaevoPLL.h

DESCRIPTION:
  Internal, chipset specific PLL definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/inc/HALclkZondaEvoPLL.h#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
05/07/20   ra     Created.

==============================================================================
    Copyright (c) 2020-2021 QUALCOMM Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include "stdbool.h"
#include "HALclkInternal.h"


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * Registers for programming operational mode
 */
#define HAL_PLL_OPMODE_STANDBY  0x0UL
#define HAL_PLL_OPMODE_RUN      0x1UL
#define HAL_PLL_OPMODE_FREEZE   0x3UL


/*
 * PLL register offsets.
 */
#define HWIO_PLL_MODE_OFFS                                  0x00000000UL
#define HWIO_PLL_L_VAL_OFFS                                 0x00000004UL
#define HWIO_PLL_ALPHA_VAL_OFFS                             0x00000008UL
#define HWIO_PLL_USER_CTL_OFFS                              0x0000000cUL
#define HWIO_PLL_USER_CTL_U_OFFS                            0x00000010UL
#define HWIO_PLL_CONFIG_CTL_OFFS                            0x00000014UL
#define HWIO_PLL_CONFIG_CTL_U_OFFS                          0x00000018UL
#define HWIO_PLL_CONFIG_CTL_U1_OFFS                         0x0000001cUL
#define HWIO_PLL_TEST_CTL_OFFS                              0x00000020UL
#define HWIO_PLL_TEST_CTL_U_OFFS                            0x00000024UL
#define HWIO_PLL_TEST_CTL_U1_OFFS                           0x00000028UL
#define HWIO_PLL_OPMODE_OFFS                                0x0000002cUL
#define HWIO_PLL_SSC_OFFS                                   0x00000030UL
#define HWIO_PLL_DROOP_CTL_OFFS                             0x00000034UL
#define HWIO_PLL_STATUS_OFFS                                0x00000038UL
#define HWIO_PLL_STATE_OFFS                                 0x0000003cUL


/*
 * PLL_MODE register definitions.
 */
#define HWIO_PLL_MODE_PLL_LOCK_DET_BMSK                         0x80000000UL
#define HWIO_PLL_MODE_PLL_LOCK_DET_SHFT                               0x1fUL
#define HWIO_PLL_MODE_FREQ_LOCK_DET_BMSK                    0x40000000UL
#define HWIO_PLL_MODE_FREQ_LOCK_DET_SHFT                          0x1eUL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_BMSK                      0x4000UL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_SHFT                         0xeUL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_BMSK                        0x2000UL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_SHFT                           0xdUL
#define HWIO_PLL_MODE_PLL_RESET_N_BMSK                             0x4UL
#define HWIO_PLL_MODE_PLL_RESET_N_SHFT                             0x2UL
#define HWIO_PLL_MODE_PLL_BYPASSNL_BMSK                            0x2UL
#define HWIO_PLL_MODE_PLL_BYPASSNL_SHFT                            0x1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_BMSK                             0x1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_SHFT                             0x0UL

/*
 * PLL_L_VAL register definitions.
 */
#define HWIO_PLL_L_VAL_PLL_L_BMSK                                 0xFFUL
#define HWIO_PLL_L_VAL_PLL_L_SHFT                                  0x0UL

/*
 * PLL_ALPHA_VAL register definitions.
 */
#define HWIO_PLL_ALPHA_VAL_PLL_ALPHA_VAL_BMSK                   0xFFFFUL
#define HWIO_PLL_ALPHA_VAL_PLL_ALPHA_VAL_SHFT                      0x0UL

/*
 * PLL_USER_CTL register definitions.
 */
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_BMSK               0x2000000UL
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_SHFT                    0x19UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_ENABLE_BMSK                 0x10UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_ENABLE_SHFT                  0x4UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX_ENABLE_BMSK                   0x8UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX_ENABLE_SHFT                   0x3UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX2_ENABLE_BMSK                  0x4UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX2_ENABLE_SHFT                  0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_ENABLE_BMSK                  0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_ENABLE_SHFT                  0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_ENABLE_BMSK                  0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_ENABLE_SHFT                  0x0UL


/*
 * PLL_USER_CTL_U register definitions.
 */
#define HWIO_PLL_USER_CTL_U_FRAC_ALPHA_MN_MODE_BMSK            0x10000000UL
#define HWIO_PLL_USER_CTL_U_FRAC_ALPHA_MN_MODE_SHFT                 0x1cUL
#define HWIO_PLL_USER_CTL_U_PLL_FRAC_MODE_ENABLE_BMSK          0x2000000UL
#define HWIO_PLL_USER_CTL_U_PLL_FRAC_MODE_ENABLE_SHFT               0x19UL
#define HWIO_PLL_USER_CTL_U_PRE_DIV_2_ENABLE_BMSK                 0x20000UL
#define HWIO_PLL_USER_CTL_U_PRE_DIV_2_ENABLE_SHFT                   0x11UL
#define HWIO_PLL_USER_CTL_U_POST_DIV_CONTROL_BMSK                  0x3000UL
#define HWIO_PLL_USER_CTL_U_POST_DIV_CONTROL_SHFT                    0xcUL


/* ============================================================================
**    External Definitions
** ==========================================================================*/


/* ============================================================================
**    External Definitions
** ==========================================================================*/


/* ============================================================================
**    Functions
** ==========================================================================*/

/*
 * Source control functions.  These can be used if some of the control
 * needs to be overridden by a specific PLL.
 */
static bool HAL_clk_ZondaevoPLLEnable           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static void HAL_clk_ZondaevoPLLDisable          ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static bool HAL_clk_ZondaevoPLLIsEnabled        ( HAL_clk_SourceDescType *pSource );
static void HAL_clk_ZondaevoPLLConfig           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceConfigType eConfig );
static bool HAL_clk_ZondaevoPLLConfigPLL        ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig, HAL_clk_SourceConfigMode eMode );
static void HAL_clk_ZondaevoPLLDetectPLLConfig  ( HAL_clk_SourceDescType *pSource, HAL_clk_PLLConfigType *pmConfig );
static bool HAL_clk_ZondaevoPLLEnableVote       ( HAL_clk_SourceDescType *pSource );
static void HAL_clk_ZondaevoPLLDisableVote      ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_ZondaevoPLLIsVoteEnabled    ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_ZondaevoPLLIsPLLConfigEqual ( const HAL_clk_PLLConfigType *pConfigA, const HAL_clk_PLLConfigType *pConfigB );
static bool HAL_clk_ZondaevoPLLIsCalibrated     ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_ZondaevoPLLSetCalConfig     ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig );
static void HAL_clk_ZondaevoPLLSetRegSettings   ( HAL_clk_SourceDescType *pSource, const HAL_clk_SourceRegSettingsType *pmSettings );
static void HAL_clk_ZondaevoPLLGetRegSettings   ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceRegSettingsType *pmSettings);

#endif  /* __HALCLKZondaEVOPLL_H__ */

