#ifndef __HALCLKLUCIDEVOPLL_H__
#define __HALCLKLUCIDEVOPLL_H__
/*
==============================================================================

FILE:         HALclkLucidEVOPLL.h

DESCRIPTION:
  Internal, chipset specific PLL definitions for the clock HAL module.

==============================================================================
            Copyright (c) 2020 Qualcomm Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/


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
#define HWIO_PLL_MODE_OFFS                                              0x00000000UL
#define HWIO_PLL_OPMODE_OFFS                                            0x00000004UL
#define HWIO_PLL_STATE_OFFS                                             0x00000008UL
#define HWIO_PLL_STATUS_OFFS                                            0x0000000CUL
#define HWIO_PLL_L_VAL_OFFS                                             0x00000010UL
#define HWIO_PLL_ALPHA_VAL_OFFS                                         0x00000014UL
#define HWIO_PLL_USER_CTL_OFFS                                          0x00000018UL
#define HWIO_PLL_USER_CTL_U_OFFS                                        0x0000001CUL
#define HWIO_PLL_CONFIG_CTL_OFFS                                        0x00000020UL
#define HWIO_PLL_CONFIG_CTL_U_OFFS                                      0x00000024UL
#define HWIO_PLL_CONFIG_CTL_U1_OFFS                                     0x00000028UL
#define HWIO_PLL_TEST_CTL_OFFS                                          0x0000002CUL
#define HWIO_PLL_TEST_CTL_U_OFFS                                        0x00000030UL
#define HWIO_PLL_TEST_CTL_U1_OFFS                                       0x00000034UL

/*
 * PLL_MODE register definitions.
 */
#define HWIO_PLL_MODE_PLL_LOCK_DET_BMSK                                 0x80000000UL
#define HWIO_PLL_MODE_PLL_LOCK_DET_SHFT                                       0x1fUL
#define HWIO_PLL_MODE_PLL_LOCK_DET_FINE_BMSK                            0x40000000UL
#define HWIO_PLL_MODE_PLL_LOCK_DET_FINE_SHFT                                  0x1eUL
#define HWIO_PLL_MODE_PLL_ENABLE_STATUS_BMSK                            0x20000000UL
#define HWIO_PLL_MODE_PLL_ENABLE_STATUS_SHFT                                  0x1dUL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_BMSK                                  0x4000UL
#define HWIO_PLL_MODE_PLL_LATCH_INPUT_SHFT                                     0xeUL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_BMSK                                    0x2000UL
#define HWIO_PLL_MODE_PLL_ACK_LATCH_SHFT                                       0xdUL
#define HWIO_PLL_MODE_PCAL_NOT_DONE_BMSK                                     0x100UL
#define HWIO_PLL_MODE_PCAL_NOT_DONE_SHFT                                       0x8UL
#define HWIO_PLL_MODE_OUT_ODD_HW_CTL_BMSK                                     0x20UL
#define HWIO_PLL_MODE_OUT_ODD_HW_CTL_SHFT                                      0x5UL
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_BMSK                                    0x10UL
#define HWIO_PLL_MODE_OUT_EVEN_HW_CTL_SHFT                                     0x4UL
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_BMSK                                     0x8UL
#define HWIO_PLL_MODE_OUT_MAIN_HW_CTL_SHFT                                     0x3UL
#define HWIO_PLL_MODE_PLL_RESET_N_BMSK                                         0x4UL
#define HWIO_PLL_MODE_PLL_RESET_N_SHFT                                         0x2UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_BMSK                                         0x1UL
#define HWIO_PLL_MODE_PLL_OUTCTRL_SHFT                                         0x0UL

/*
 * PLL_L_VAL register definitions.
 */
#define HWIO_PLL_L_VAL_PLL_CAL_L_VAL_BMSK                               0xffff0000UL
#define HWIO_PLL_L_VAL_PLL_CAL_L_VAL_SHFT                                     0x10UL
#define HWIO_PLL_L_VAL_PLL_L_VAL_BMSK                                       0xffffUL
#define HWIO_PLL_L_VAL_PLL_L_VAL_SHFT                                          0x0UL

/*
 * PLL_ALPHA_VAL register definitions.
 *   These fields are defined implicitly here because the bits in this register
 *   are overloaded depending on the value of PLL_USER_CTL[FRAC_FORMAT_SEL].
 */
#define HWIO_PLL_ALPHA_VAL_PLL_ALPHA_VAL_BMSK                               0xffffUL
#define HWIO_PLL_ALPHA_VAL_PLL_ALPHA_VAL_SHFT                                  0x0UL
#define HWIO_PLL_ALPHA_VAL_M_VAL_BMSK                                         0xffUL
#define HWIO_PLL_ALPHA_VAL_M_VAL_SHFT                                          0x8UL
#define HWIO_PLL_ALPHA_VAL_N_VAL_BMSK                                         0xffUL
#define HWIO_PLL_ALPHA_VAL_N_VAL_SHFT                                          0x0UL

/*
 * PLL_USER_CTL register definitions.
 */
#define HWIO_PLL_USER_CTL_FRAC_FORMAT_SEL_BMSK                          0x10000000UL
#define HWIO_PLL_USER_CTL_FRAC_FORMAT_SEL_SHFT                                0x1cUL
#define HWIO_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_BMSK                    0x8000000UL
#define HWIO_PLL_USER_CTL_LATCH_INTERFACE_BYPASS_SHFT                         0x1bUL
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_BMSK                          0x4000000UL
#define HWIO_PLL_USER_CTL_OFF_WHEN_NO_VOTE_SHFT                               0x1aUL
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_BMSK                           0x2000000UL
#define HWIO_PLL_USER_CTL_ENABLE_VOTE_RUN_SHFT                                0x19UL
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_BMSK                             0x1c00000UL
#define HWIO_PLL_USER_CTL_PRE_DIV_RATIO_SHFT                                  0x16UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_ODD_BMSK                          0x3c000UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_ODD_SHFT                              0xeUL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_BMSK                          0x3c00UL
#define HWIO_PLL_USER_CTL_POST_DIV_RATIO_EVEN_SHFT                             0xaUL
#define HWIO_PLL_USER_CTL_RESERVE_BIT5_BMSK                                   0x20UL
#define HWIO_PLL_USER_CTL_RESERVE_BIT5_SHFT                                    0x5UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_BMSK                                 0x10UL
#define HWIO_PLL_USER_CTL_PLLOUT_TEST_EN_SHFT                                  0x4UL
#define HWIO_PLL_USER_CTL_RESERVE_BIT3_BMSK                                    0x8UL
#define HWIO_PLL_USER_CTL_RESERVE_BIT3_SHFT                                    0x3UL
#define HWIO_PLL_USER_CTL_PLLOUT_ODD_EN_BMSK                                   0x4UL
#define HWIO_PLL_USER_CTL_PLLOUT_ODD_EN_SHFT                                   0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_BMSK                                  0x2UL
#define HWIO_PLL_USER_CTL_PLLOUT_EVEN_EN_SHFT                                  0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_BMSK                                  0x1UL
#define HWIO_PLL_USER_CTL_PLLOUT_MAIN_EN_SHFT                                  0x0UL

/*
 * PLL_USER_CTL_U register definitions.
 */
#define HWIO_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_BMSK                   0x40000UL
#define HWIO_PLL_USER_CTL_U_LOCK_DETECTOR_SELECTION_SHFT                      0x12UL
#define HWIO_PLL_USER_CTL_U_TYPE_2_MODE_SELECTION_BMSK                     0x20000UL
#define HWIO_PLL_USER_CTL_U_TYPE_2_MODE_SELECTION_SHFT                        0x11UL
#define HWIO_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_BMSK                  0x10000UL
#define HWIO_PLL_USER_CTL_U_BANG_BANG_MODE_SELECTION_SHFT                     0x10UL
#define HWIO_PLL_USER_CTL_U_REF_CLK_AT_OUT_BMSK                             0x2000UL
#define HWIO_PLL_USER_CTL_U_REF_CLK_AT_OUT_SHFT                                0xdUL
#define HWIO_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_BMSK                      0x1800UL
#define HWIO_PLL_USER_CTL_U_SCALE_FREQ_ON_RESTART_SHFT                         0xbUL
#define HWIO_PLL_USER_CTL_U_CALIB_CTRL_BMSK                                    0xeUL
#define HWIO_PLL_USER_CTL_U_CALIB_CTRL_SHFT                                    0x1UL
#define HWIO_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_BMSK                        0x1UL
#define HWIO_PLL_USER_CTL_U_USE_ONLY_FINE_LOCK_DET_SHFT                        0x0UL

/*
 * PLL_TEST_CTL register definitions.
 */
#define HWIO_PLL_TEST_CTL_STATUS_EN_BMSK                                     0x100UL
#define HWIO_PLL_TEST_CTL_STATUS_EN_SHFT                                         8UL
#define HWIO_PLL_TEST_CTL_STATUS_SEL_BMSK                                   0x7c00UL
#define HWIO_PLL_TEST_CTL_STATUS_SEL_SHFT                                       10UL


#endif  /* __HALCLKLUCIDEVOPLL_H__ */
