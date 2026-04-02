#ifndef __HALCLKRivianEVOPLL_H__
#define __HALCLKRivianEVOPLL_H__
/*
==============================================================================

FILE:         HALclkRivianevoPLL.h

DESCRIPTION:
  Internal, chipset specific PLL definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/inc/HALclkRivianEvoPLL.h#1 $

when       who     what, where, why
--------   ---     -----------------------------------------------------------
05/07/20   ra     Created.

==============================================================================
    Copyright (c) 2021 QUALCOMM Technologies Incorporated.
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
#define HWIO_PLL_OPMODE_OFFS                                0x00000004UL
#define HWIO_PLL_STATE_OFFS                                 0x00000008UL
#define HWIO_PLL_STATUS_OFFS                                0x0000000CUL
#define HWIO_PLL_L_VAL_OFFS                                 0x00000010UL
#define HWIO_PLL_USER_CTL_OFFS                              0x00000014UL
#define HWIO_PLL_USER_CTL_U_OFFS                            0x00000018UL
#define HWIO_PLL_CONFIG_CTL_OFFS                            0x0000001CUL
#define HWIO_PLL_CONFIG_CTL_U_OFFS                          0x00000020UL
#define HWIO_PLL_CONFIG_CTL_U1_OFFS                         0x00000024UL
#define HWIO_PLL_TEST_CTL_OFFS                              0x00000028UL
#define HWIO_PLL_TEST_CTL_U_OFFS                            0x0000002CUL
#define HWIO_PLL_FUSA_STATUS_OFFS                           0x00000080UL


/*
 * PLL_MODE register definitions.
 */
#define HWIO_PLL_MODE_RMSK                                  0xFFFFFFFFUL
#define HWIO_PLL_MODE_PLL_LOCK_DET_BMSK                     0x80000000UL
#define HWIO_PLL_MODE_PLL_LOCK_DET_SHFT                             31UL
#define HWIO_PLL_MODE_FREQ_LOCK_DET_BMSK                    0x40000000UL
#define HWIO_PLL_MODE_FREQ_LOCK_DET_SHFT                            30UL
#define HWIO_PLL_MODE_PLL_ENABLE_STATUS_BMSK                0x20000000UL
#define HWIO_PLL_MODE_PLL_ENABLE_STATUS_SHFT                        29UL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_BMSK                      0x4000UL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_SHFT                          14UL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_BMSK                        0x2000UL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_SHFT                            13UL
#define HWIO_PLL_MODE_OUT_AUX_HW_CTL_BMSK                         0x40UL
#define HWIO_PLL_MODE_OUT_AUX_HW_CTL_SHFT                            6UL
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_BMSK                        0x10UL
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_SHFT                           4UL
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_BMSK                         0x8UL
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_SHFT                           3UL
#define HWIO_PLL_MODE_PLL_RESET_N_BMSK                             0x4UL
#define HWIO_PLL_MODE_PLL_RESET_N_SHFT                               2UL
#define HWIO_PLL_MODE_PLL_BYPASSNL_BMSK                            0x2UL
#define HWIO_PLL_MODE_PLL_BYPASSNL_SHFT                              1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_BMSK                             0x1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_SHFT                               0UL

/*
 * PLL_L_VAL register definitions.
 */
#define HWIO_PLL_L_VAL_PLL_L_VAL_BMSK                              0xFFUL
#define HWIO_PLL_L_VAL_PLL_L_VAL_SHFT                                0UL

/*
 * PLL_USER_CTL register definitions.
 */
#define HWIO_PLL_USER_CTL_RMSK                              0xFFFFFFFFUL
#define HWIO_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_BMSK        0x8000000UL
#define HWIO_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_SHFT               27UL
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_BMSK              0x4000000UL
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_SHFT                     26UL
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_BMSK               0x2000000UL
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_SHFT                      25UL
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_BMSK                 0x1C00000UL
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_SHFT                        22UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK              0x3C00UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                  10UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_BMSK                     0x10UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_SHFT                        4UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX_EN_BMSK                       0x8UL
#define HWIO_PLL_USER_CTL_PLLOUT_AUX_EN_SHFT                         3UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_BMSK                      0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_SHFT                        1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_BMSK                      0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_SHFT                        0UL
/*
 * PLL_USER_CTL_U register definitions.
 */
#define HWIO_PLL_USER_CTL_U_RMSK                            0xFFFFFFFFUL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_STAY_LOW_BMSK           0x1000000UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_STAY_LOW_SHFT                  24UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_STAY_HIGH_BMSK           0x800000UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_STAY_HIGH_SHFT                 23UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_BMSK          0x400000UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_REPLICA_EN_SHFT              0x16UL
#define HWIO_PLL_USER_CTL_U_FREQ_BAND_BMSK                     0xC0000UL
#define HWIO_PLL_USER_CTL_U_FREQ_BAND_SHFT                          18UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_SEL_BMSK                  0x30000UL
#define HWIO_PLL_USER_CTL_U_LOCK_DET_SEL_SHFT                       16UL
#define HWIO_PLL_USER_CTL_U_VCO_DIVIDER_BMSK                    0x8000UL
#define HWIO_PLL_USER_CTL_U_VCO_DIVIDER_SHFT                        15UL
#define HWIO_PLL_USER_CTL_U_PDIV_RATIO_EVEN_BMSK                0x7800UL
#define HWIO_PLL_USER_CTL_U_PDIV_RATIO_EVEN_SHFT                    11UL
#define HWIO_PLL_USER_CTL_U_POST_DIV_RATIO_AUX_BMSK              0x780UL
#define HWIO_PLL_USER_CTL_U_POST_DIV_RATIO_AUX_SHFT                  7UL
#define HWIO_PLL_USER_CTL_U_PDIV_RATIO_AUX_BMSK                   0x78UL
#define HWIO_PLL_USER_CTL_U_PDIV_RATIO_AUX_SHFT                      3UL


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
static bool HAL_clk_RivianevoPLLEnable           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static void HAL_clk_RivianevoPLLDisable          ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static bool HAL_clk_RivianevoPLLIsEnabled        ( HAL_clk_SourceDescType *pSource );
static void HAL_clk_RivianevoPLLConfig           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceConfigType eConfig );
static bool HAL_clk_RivianevoPLLConfigPLL        ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig, HAL_clk_SourceConfigMode eMode );
static void HAL_clk_RivianevoPLLDetectPLLConfig  ( HAL_clk_SourceDescType *pSource, HAL_clk_PLLConfigType *pmConfig );
static bool HAL_clk_RivianevoPLLEnableVote       ( HAL_clk_SourceDescType *pSource );
static void HAL_clk_RivianevoPLLDisableVote      ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_RivianevoPLLIsVoteEnabled    ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_RivianevoPLLIsPLLConfigEqual ( const HAL_clk_PLLConfigType *pConfigA, const HAL_clk_PLLConfigType *pConfigB );
static bool HAL_clk_RivianevoPLLIsCalibrated     ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_RivianevoPLLSetCalConfig     ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig );
static void HAL_clk_RivianevoPLLSetRegSettings   ( HAL_clk_SourceDescType *pSource, const HAL_clk_SourceRegSettingsType *pmSettings );
static void HAL_clk_RivianevoPLLGetRegSettings   ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceRegSettingsType *pmSettings);

#endif  /* __HALCLKRivianEVOPLL_H__ */

