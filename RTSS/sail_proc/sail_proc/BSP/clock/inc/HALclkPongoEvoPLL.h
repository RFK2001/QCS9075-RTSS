#ifndef __HALCLKPongoevoPLL_H__
#define __HALCLKPongoevoPLL_H__
/*
==============================================================================

FILE:         HALclkPongoevoPLL.h

DESCRIPTION:
  Internal, chipset specific PLL definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/inc/HALclkPongoEvoPLL.h#1 $

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
#define HWIO_PLL_L_VAL_OFFS                                 0x00000010UL
#define HWIO_PLL_USER_CTL_OFFS                              0x00000014UL
#define HWIO_PLL_USER_CTL_U_OFFS                            0x00000018UL
#define HWIO_PLL_CONFIG_CTL_OFFS                            0x0000001CUL
#define HWIO_PLL_CONFIG_CTL_U_OFFS                          0x00000020UL
#define HWIO_PLL_CONFIG_CTL_U1_OFFS                         0x00000024UL
#define HWIO_PLL_CONFIG_CTL_U2_OFFS                         0x00000028UL
#define HWIO_PLL_TEST_CTL_OFFS                              0x0000002CUL
#define HWIO_PLL_TEST_CTL_U_OFFS                            0x00000030UL
#define HWIO_PLL_TEST_CTL_U1_OFFS                           0x00000034UL
#define HWIO_PLL_TEST_CTL_U2_OFFS                           0x00000038UL
#define HWIO_PLL_TEST_CTL_U3_OFFS                           0x0000003CUL
#define HWIO_PLL_STATUS_OFFS                                0x0000000CUL

/*
 * PLL_MODE register definitions.
 */
#define HWIO_PLL_MODE_PLL_LOCK_DET_BMSK                      0x80000000UL
#define HWIO_PLL_MODE_PLL_LOCK_DET_SHFT                            0x1fUL
#define HWIO_PLL_MODE_PLL_CLOCK_SELECT_BMSK                      0x1000UL
#define HWIO_PLL_MODE_PLL_CLOCK_SELECT_SHFT                         0xCUL
#define HWIO_PLL_MODE_PLL_CAL_XO_PRESENT_BMSK                     0x400UL
#define HWIO_PLL_MODE_PLL_CAL_XO_PRESENT_SHFT                       0xAUL
#define HWIO_PLL_MODE_PLL_IN_CALIBRATION_BMSK                     0x200UL
#define HWIO_PLL_MODE_PLL_IN_CALIBRATION_SHFT                       0x9UL
#define HWIO_PLL_MODE_PLL_RESET_N_BMSK                              0x4UL
#define HWIO_PLL_MODE_PLL_RESET_N_SHFT                              0x2UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_BMSK                              0x1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_SHFT                              0x0UL


/*
 * PLL_USER_CTL register definitions.
 */
 
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK                      0x400UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                        0xAUL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_MAIN_BMSK                      0x3C0UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_MAIN_SHFT                        0x6UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_BMSK                            0x10UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_SHFT                             0x4UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_BMSK                             0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_SHFT                             0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_BMSK                             0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_SHFT                             0x0UL

/*
 * PLL_USER_CTL_U register definitions.
 */
 
#define HWIO_PLL_USER_CTL_U_XO_CLK_AT_OUT_BMSK                          0x2000UL
#define HWIO_PLL_USER_CTL_U_XO_CLK_AT_OUT_SHFT                          0xDUL

#define HWIO_PLL_USER_CTL_U_INTERNAL_CLOCK_SELECTION_BMSK               0x300000UL
#define HWIO_PLL_USER_CTL_U_INTERNAL_CLOCK_SELECTION_SHFT               20UL

#define HWIO_PLL_USER_CTL_U_REQUEST_CAL_BMSK                            0x400UL
#define HWIO_PLL_USER_CTL_U_REQUEST_CAL_SHFT                            10UL

/*
 * PLL_CONFIG_CTL_U2 register definitions.
 */
#define HWIO_PLL_CONFIG_CTL_U2_TEMPCOMP_K_DEFAULT_BMSK                   0xffffUL
#define HWIO_PLL_CONFIG_CTL_U2_TEMPCOMP_K_DEFAULT_SHFT                   0UL

/*
 * PLL_TEST_CTL_U1 register definitions.
 */
#define HWIO_PLL_TEST_CTL_U1_FORCE_TDO_PCAL_VALUE_BMSK                    0x3e00UL
#define HWIO_PLL_TEST_CTL_U1_FORCE_TDO_PCAL_VALUE_SHFT                    9UL

#define HWIO_PLL_TEST_CTL_U1_FORCE_PCAL_VALUE_BMSK                        0x7c000UL
#define HWIO_PLL_TEST_CTL_U1_FORCE_PCAL_VALUE_SHFT                        14UL

#define HWIO_PLL_TEST_CTL_U1_ENABLE_PCODE_CAL_BMSK                        0x100UL
#define HWIO_PLL_TEST_CTL_U1_ENABLE_PCODE_CAL_SHFT                        8UL

/*
 * PLL_TEST_CTL_U2 register definitions.
 */
#define HWIO_PLL_TEST_CTL_U2_DISABLE_PCAL_BMSK                         0x1UL
#define HWIO_PLL_TEST_CTL_U2_DISABLE_PCAL_SHFT                          0UL

/* ============================================================================
**    Functions
** ==========================================================================*/

/*
 * Source control functions.  These can be used if some of the control
 * needs to be overridden by a specific PLL.
 */
static bool HAL_clk_PongoevoPLLEnable           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static void HAL_clk_PongoevoPLLDisable          ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
static bool HAL_clk_PongoevoPLLIsEnabled        ( HAL_clk_SourceDescType *pSource );
static void HAL_clk_PongoevoPLLConfig           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceConfigType eConfig );
static bool HAL_clk_PongoevoPLLConfigPLL        ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig, HAL_clk_SourceConfigMode eMode );
static void HAL_clk_PongoevoPLLDetectPLLConfig  ( HAL_clk_SourceDescType *pSource, HAL_clk_PLLConfigType *pmConfig );
static bool HAL_clk_PongoevoPLLIsPLLConfigEqual ( const HAL_clk_PLLConfigType *pConfigA, const HAL_clk_PLLConfigType *pConfigB);
static bool HAL_clk_PongoevoPLLIsCalibrated     ( HAL_clk_SourceDescType *pSource );
static bool HAL_clk_PongoevoPLLSetCalConfig     ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig );
static void HAL_clk_PongoevoPLLSetRegSettings   ( HAL_clk_SourceDescType *pSource, const HAL_clk_SourceRegSettingsType *pmSettings );
static void HAL_clk_PongoevoPLLGetRegSettings   ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceRegSettingsType *pmSettings);
#endif  /* __HALCLKPongoevoPLL_H__ */

