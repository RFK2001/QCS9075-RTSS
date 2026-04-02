#ifndef __HALCLKGENERIC_H__
#define __HALCLKGENERIC_H__
/*
==============================================================================

FILE:         HALclkGeneric.h

DESCRIPTION:
  Internal, chipset specific definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/inc/HALclkGeneric.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------- 
06/19/13   vt      Added RO control for spmi clks
10/08/12   ll      Corrected CLK_DIV_FMSK value
07/11/11   vs      Created.

==============================================================================
            Copyright (c) 2011 - 2015 Qualcomm Technologies Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include "stdbool.h"
#include "stdint.h"
#include "HALclkInternal.h"



/* ============================================================================
**    Definitions
** ==========================================================================*/


/*
 * Common root clock configuration registers and their relative offset to
 * the first register (*_CMD_CGR)
 */
#define HAL_CLK_CMD_REG_OFFSET                                         0UL
#define HAL_CLK_CFG_REG_OFFSET                                         0x4UL
#define HAL_CLK_M_REG_OFFSET                                           0x8UL
#define HAL_CLK_N_REG_OFFSET                                           0xCUL
#define HAL_CLK_D_REG_OFFSET                                           0x10UL
#define HAL_CLK_CMD_DFSR_REG_OFFSET                                    0x14UL
#define HAL_CLK_PERF_DFSR_REG_OFFSET                                   0x1CUL
#define HAL_CLK_PERF_M_DFSR_REG_OFFSET                                 0x5CUL
#define HAL_CLK_PERF_N_DFSR_REG_OFFSET                                 0x9CUL
#define HAL_CLK_PERF_D_DFSR_REG_OFFSET                                 0xDCUL


/*
 * Common block fields/masks
 */
#define HAL_CLK_BLOCK_CTRL_REG_BLK_ARES_FMSK                           0x00000001UL


/*
 * Common root clock command fields/masks (*_CMD_RCGR)
 */
#define HAL_CLK_CMD_CGR_ROOT_OFF_FMSK                                  0x80000000UL
#define HAL_CLK_CMD_CGR_ROOT_EN_FMSK                                   0x00000002UL
#define HAL_CLK_CMD_CFG_UPDATE_FMSK                                    0x00000001UL
#define HAL_CLK_CMD_CFG_UPDATE_SHFT                                    0UL


/*
 * Common root clock config fields/masks (*_CFG_RCGR)
 */
#define HAL_CLK_CFG_CGR_HW_CLK_CONTROL_FMSK                            0x00100000UL
#define HAL_CLK_CFG_CGR_HW_CLK_CONTROL_SHFT                            0x14UL
#define HAL_CLK_CFG_CGR_MODE_FMSK                                      0x00003000UL
#define HAL_CLK_CFG_CGR_MODE_SHFT                                      0xcUL
#define HAL_CLK_CFG_CGR_SRC_SEL_FMSK                                   0x00000700UL
#define HAL_CLK_CFG_CGR_SRC_SEL_SHFT                                   0x8UL
#define HAL_CLK_CFG_CGR_SRC_DIV_FMSK                                   0x0000001FUL
#define HAL_CLK_CFG_CGR_SRC_DIV_SHFT                                   0UL

#define HAL_CLK_CFG_CFG_DUAL_EDGE_MODE_VAL                             0x2UL
#define HAL_CLK_CFG_CFG_BYPASS_MODE_VAL                                0UL


/*
 * Common root clock DFS command fields/masks (*_CMD_DFSR)
 */
#define HAL_CLK_CMD_DFSR_RCG_SW_CTRL_FMSK                              0xFFFF8000UL
#define HAL_CLK_CMD_DFSR_RCG_SW_CTRL_SHFT                              15UL
#define HAL_CLK_CMD_DFSR_SW_PERF_STATE_FMSK                            0x7800UL
#define HAL_CLK_CMD_DFSR_SW_PERF_STATE_SHFT                            11UL
#define HAL_CLK_CMD_DFSR_SW_OVERRIDE_FMSK                              0x400UL
#define HAL_CLK_CMD_DFSR_SW_OVERRIDE_SHFT                              10UL
#define HAL_CLK_CMD_DFSR_HW_CLK_CONTROL_FMSK                           0x20UL
#define HAL_CLK_CMD_DFSR_HW_CLK_CONTROL_SHFT                           5UL
#define HAL_CLK_CMD_DFSR_DFS_EN_FMSK                                   0x1UL
#define HAL_CLK_CMD_DFSR_DFS_EN_SHFT                                   0UL


/*
 * Common clock branch fields/masks (*_CBCR register)
 */
#define HAL_CLK_BRANCH_CTRL_REG_CLK_OFF_FMSK                           0xF0000000UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_OFF_SHFT                           28UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_DIV_FMSK                           0x01FF0000UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_DIV_SHFT                           16UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_FORCE_MEM_CORE_ON_FMSK             0x00004000UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_FORCE_MEM_PERIPH_ON_FMSK           0x00002000UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_FORCE_MEM_PERIPH_OFF_FMSK          0x00001000UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_ARES_FMSK                          0x00000004UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_ARES_SHFT                          2UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_HW_CTL_FMSK                        0x00000002UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_HW_CTL_SHFT                        1UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_ENABLE_FMSK                        0x00000001UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_ENABLE_SHFT                        0UL

#define HAL_CLK_BRANCH_CTRL_REG_CLK_ON_VAL_1                           0x0UL
#define HAL_CLK_BRANCH_CTRL_REG_CLK_ON_VAL_2                           0x2UL


/*
 * Common distributed switch control fields (*_GDSCR register)
 */
#define HAL_CLK_GDSCR_PWR_ON_FMSK                                      0x80000000UL
#define HAL_CLK_GDSCR_PWR_ON_SHFT                                      31UL
#define HAL_CLK_GDSCR_RETAIN_FF_ENABLE_BMSK                            0x800UL
#define HAL_CLK_GDSCR_RETAIN_FF_ENABLE_SHFT                            11UL
#define HAL_CLK_GDSCR_EN_ALL_FMSK                                      0x000000C0UL
#define HAL_CLK_GDSCR_CLAMP_IO_FMSK                                    0x00000030UL
#define HAL_CLK_GDSCR_SW_COLLAPSE_FMSK                                 0x00000001UL
#define HAL_CLK_GDSCR_SW_COLLAPSE_SHFT                                 0UL

/*
 * Common divider fields (*_CDIVR register)
 */
#define HAL_CLK_CDIVR_CLK_DIV_FMSK                                     0x0000000FUL
#define HAL_CLK_CDIVR_CLK_DIV_SHFT                                     0UL


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/

/*
 * Clock control functions
 */
void HAL_clk_GenericEnable           ( HAL_clk_ClockDescType  *pmClockDesc );
void HAL_clk_GenericDisable          ( HAL_clk_ClockDescType  *pmClockDesc );
bool HAL_clk_GenericIsEnabled        ( HAL_clk_ClockDescType  *pmClockDesc );
bool HAL_clk_GenericIsOn             ( HAL_clk_ClockDescType  *pmClockDesc );
void HAL_clk_GenericInvert           ( HAL_clk_ClockDescType  *pmClockDesc, bool bInvert );
void HAL_clk_GenericReset            ( HAL_clk_ClockDescType  *pmClockDesc, bool bAssert );
bool HAL_clk_GenericIsReset          ( HAL_clk_ClockDescType  *pmClockDesc );
void HAL_clk_GenericConfig           ( HAL_clk_ClockDescType  *pmClockDesc, HAL_clk_ClockConfigType eConfig );
void HAL_clk_GenericDetectConfig     ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t *pnConfig, bool *pbValid );
void HAL_clk_GenericConfigDivider    ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t nDiv );
void HAL_clk_GenericDetectDivider    ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t *pnDiv );
void HAL_clk_GenericResetBranch      ( HAL_clk_ClockDescType  *pmClockDesc, bool bAssert );
void HAL_clk_GenericClockGetRegSetting(HAL_clk_ClockDescType  *pmClockDesc, HAL_clk_ClockRegSettingsType *pmSetting);


/*
 * Clock domain control functions
 */
bool HAL_clk_GenericConfigMux             ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, const HAL_clk_ClockMuxConfigType * );
void HAL_clk_GenericDetectMuxConfig       ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig );
bool HAL_clk_GenericConfigDomainMux       ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, const HAL_clk_ClockMuxConfigType *pmConfig );
void HAL_clk_GenericDetectDomainMuxConfig ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig );
bool HAL_clk_GenericDomainIsOn            ( HAL_clk_ClockDomainDescType *pmClockDomainDesc );
void HAL_clk_GenericEnableDFS             ( HAL_clk_ClockDomainDescType *pmClockDomainDesc );
bool HAL_clk_GenericDomainIsDFSEnabled    ( HAL_clk_ClockDomainDescType *pmClockDomainDesc );
void HAL_clk_GenericConfigDFSMux          ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_ClockMuxConfigType  *pmConfig );
void HAL_clk_GenericDetectDFSMuxConfig    ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig, uint32_t nPerfLevel );
void HAL_clk_GenericGetDomainRegSetting   ( HAL_clk_ClockDomainDescType *pmClockDomainDesc, HAL_clk_DomainRegSettingsType *pmSettings);

/*
 * Clock power domain control functions
 */
void HAL_clk_GenericPowerDomainEnable    ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
void HAL_clk_GenericPowerDomainDisable   ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
bool HAL_clk_GenericPowerDomainIsEnabled ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
bool HAL_clk_GenericPowerDomainIsOn      ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );


/*
 * Divider control functions
 */
void HAL_clk_GenericDividerConfigDivider ( HAL_clk_DividerDescType  *pmDividerDesc, uint32_t nDiv );
void HAL_clk_GenericDividerDetectDivider ( HAL_clk_DividerDescType  *pmDividerDesc, uint32_t *pnDiv );


/*
 * Source control functions
 */
bool HAL_clk_GenericIsPLLConfigEqual (const HAL_clk_PLLConfigType *pConfigA, const HAL_clk_PLLConfigType *pConfigB);

#endif  /* __HALCLKGENERIC_H__ */

