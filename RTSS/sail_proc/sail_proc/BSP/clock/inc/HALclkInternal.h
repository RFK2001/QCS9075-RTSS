#ifndef __HALCLKINTERNAL_H__
#define __HALCLKINTERNAL_H__
/*
==============================================================================

FILE:         HALclkInternal.h

DESCRIPTION:
  Internal definitions for the clock HAL module.

==============================================================================

                             Edit History

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/inc/HALclkInternal.h#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------- 
09/11/12   ll      Added PLL Type (SR, SR2) field to PLL Context typedef
07/18/11   vs      Ported from the latest clock driver.

==============================================================================
            Copyright (c) 2011-2015 QUALCOMM Technologies, Incorporated.
                    All Rights Reserved.
                  QUALCOMM Proprietary/GTDR
==============================================================================
*/

/*============================================================================

                     INCLUDE FILES FOR MODULE

============================================================================*/

#include "stdbool.h"
#include "stdint.h"
#include <HALclk.h>


/*============================================================================

             DEFINITIONS AND DECLARATIONS FOR MODULE

=============================================================================*/


/* ============================================================================
**    Definitions
** ==========================================================================*/

/*
 * ENCODE_NOT_2D / ENCODE_NOT_N_MINUS_M
 *
 * Macros to return the inverted value of the 2D field or (N - M)
 * in a type 1 mux structure.  Used to prepare the value for writing
 * to the hardware register field.
 */
#define ENCODE_NOT_2D(mux)         (~(mux)->nN)
#define ENCODE_NOT_N_MINUS_M(mux)  (~((mux)->nN - (mux)->nM))

/*
 * DECODE_NOT_2D / DECODE_NOT_N_MINUS_M
 *
 * Macros to  unwind the inverted value of the 2D field or (N - M)
 * read from a type 1 mux register.  Used to find a match for a mux
 * config with a BSP entry.
 */
#define DECODE_NOT_2D(nNot2DVal)                     (~(nNot2DVal))
#define DECODE_NOT_N_MINUS_M(nNotNMinusMVal, nMVal)  (~(nNotNMinusMVal) + nMVal)

/*
 * DIVIDER
 *
 * Macro to return the normalized divider for a given mux structure.
 * Just subtracts 1 unless the value is already 0.
 */
#define DIVIDER(mux)  ((mux)->nDivider ? (mux)->nDivider - 1 : 0)

/*
 * HALF_DIVIDER
 *
 * Macro to return the normalized half divider for a given mux structure.
 * NOTE: Expecting (2 * divider) value as input.
 */
#define HALF_DIVIDER(mux)  ((mux)->nDiv2x ? (((mux)->nDiv2x) - 1) : 0)

/*
 * HAL_CLK_FMSK
 *
 * Define a register mask data structure given the register name
 * and field.
 */
#define HAL_CLK_FMSK(io, field)   \
  {                               \
    HWIO_ADDR(io),                \
    HWIO_FMSK(io, field)          \
  }


/*
 * HAL_CLK_FMSKI
 *
 * Define a register mask data structure given the index, register name
 * and field.
 */
#define HAL_CLK_FMSKI(io,index,field)   \
  {                               \
    HWIO_ADDR(io,index),         \
    HWIO_FMSK(io, field)          \
  }


/*
 * HAL_CLK_FMSKM
 *
 * Define a register mask data structure given the register name
 * and a mask.
 */
#define HAL_CLK_FMSKM(io, mask)   \
  {                               \
    HWIO_ADDR(io),                \
    mask                          \
  }


/*
 * Define an invalid source index for error detection.
 */
#define HAL_CLK_SOURCE_INDEX_INVALID 0xFFFFFFFF

/* HAL specific flags */
#define HAL_CLK_FLAG_DOMAIN_HW_CLK_CONTROL         0x01


/* ============================================================================
**    Typedefs
** ==========================================================================*/

/*
 * HAL_clk_RegisterMaskType
 *
 * Contains a register address and mask, used for setting and clearing
 * a given set of bits.
 *
 * nAddr - Address of the register (32-bit).
 * nMask - 32-bit mask.
 */
typedef struct
{
  uintptr_t nAddr;
  uint32_t  nMask;
} HAL_clk_RegisterMaskType;


/*
 * HAL_clk_ClockRegistersType
 *
 * nBranchAddr  - Clock branch address/offset.
 * nResetAddr   - Clock block reset address/offset.
 * mHWVotable   - Register/mask for HW votable configuration setup.
 */
typedef struct
{
  uintptr_t                 nBranchAddr;
  uintptr_t                 nResetAddr;
  HAL_clk_RegisterMaskType  mHWVotable;
} HAL_clk_ClockRegistersType;


/*
 * HAL_clk_ClockControlType
 *
 * Set of function pointers used to control a clock.
 *
 * Enable           - Enable the given clock.
 * Disable          - Disable the given clock.
 * IsEnabled        - Check if the given clock is enabled.
 * IsOn             - Check if the given clock is on.
 * Reset            - Assert or deassert the reset for given clock group.
 * Config           - Configure the given clock.
 * DetectConfig     - Return the current configuration for the clock.
 * ConfigDivider    - Set the divider for the clock in question.
 * DetectDivider    - Return the current divider for the clock in question.
 * Invert           - Inverts the clock signal.
 * ResetBranch      - Assert or deassert the reset for given clock branch.
 */
typedef struct
{
  void (*Enable)           ( HAL_clk_ClockDescType  *pmClockDesc );
  void (*Disable)          ( HAL_clk_ClockDescType  *pmClockDesc );
  bool (*IsEnabled)        ( HAL_clk_ClockDescType  *pmClockDesc );
  bool (*IsOn)             ( HAL_clk_ClockDescType  *pmClockDesc );
  void (*Reset)            ( HAL_clk_ClockDescType  *pmClockDesc, bool bAssert );
  bool (*IsReset)          ( HAL_clk_ClockDescType  *pmClockDesc );
  void (*Config)           ( HAL_clk_ClockDescType  *pmClockDesc, HAL_clk_ClockConfigType eConfig );
  void (*DetectConfig)     ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t *pnConfig, bool *pbValid );
  void (*ConfigDivider)    ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t nDiv );
  void (*DetectDivider)    ( HAL_clk_ClockDescType  *pmClockDesc, uint32_t *pnDiv );
  void (*Invert)           ( HAL_clk_ClockDescType  *pmClockDesc, bool bInvert );
  void (*ResetBranch)      ( HAL_clk_ClockDescType  *pmClockDesc, bool bAssert );
  void (*GetRegisterSettings)  ( HAL_clk_ClockDescType  *pmClockDesc, HAL_clk_ClockRegSettingsType *pmSetting );
} HAL_clk_ClockControlType;


/*
 * HAL_clk_SourceControlType
 *
 * Set of function pointers used to control a clock source.
 *
 * Enable          - Enable the given source.
 * Disable         - Disable the given source.
 * IsEnabled       - Check if the given source is enabled.
 * Config          - Configure the given source.
 * ConfigPLL       - Configure the given PLL source parameters.
 * DetectPLLConfig - Get the current configuration for the source.
 * EnableVote      - Enable vote the given source.
 * DisableVote     - Disable vote the given source.
 * IsVoteEnabled   - Check if the given source vote is enabled.
 */
typedef struct
{
  bool (*Enable)           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
  void (*Disable)          ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceDisableModeType eMode, void *pData );
  bool (*IsEnabled)        ( HAL_clk_SourceDescType *pSource );
  void (*Config)           ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceConfigType eConfig );
  bool (*ConfigPLL)        ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig, HAL_clk_SourceConfigMode eMode );
  void (*DetectPLLConfig)  ( HAL_clk_SourceDescType *pSource, HAL_clk_PLLConfigType *pmConfig );
  bool (*EnableVote)       ( HAL_clk_SourceDescType *pSource );
  void (*DisableVote)      ( HAL_clk_SourceDescType *pSource );
  bool (*IsVoteEnabled)    ( HAL_clk_SourceDescType *pSource );
  bool (*IsPLLConfigEqual) ( const HAL_clk_PLLConfigType  *pConfigA, const HAL_clk_PLLConfigType  *pConfigB);
  bool (*IsCalibrated)     ( HAL_clk_SourceDescType *pSource );
  bool (*SetCalConfig)     ( HAL_clk_SourceDescType *pSource, const HAL_clk_PLLConfigType *pmConfig);
  void (*SetRegSettings)   ( HAL_clk_SourceDescType *pSource, const HAL_clk_SourceRegSettingsType *pmSettings );
  void (*GetRegSettings)   ( HAL_clk_SourceDescType *pSource, HAL_clk_SourceRegSettingsType *pmSettings);
} HAL_clk_SourceControlType;


/*
 * HAL_clk_ClockDomainControlType
 * 
 * ConfigMux         - Configure the given clock mux.
 * DetectMuxConfig   - Return the current configuration of the mux for the clock. 
 * IsOn              - Returns whether the RCG domain is on or not.
 * EnableDFS          - The enable function DFS supported clock domains.
 * IsDFSEnabled       - Returns whether DFS is enabled on this domain.
 * ConfigDFSMux       - DFS configuration for DFS-supported domains.
 * DetectDFSMuxConfig - Reads the HW to detect the current DFS configuration.
 * SetACDConfig       - Set the ACD configuration for performance level changes.
 */
typedef struct
{
  bool (*ConfigMux)          ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, const HAL_clk_ClockMuxConfigType *pmConfig );
  void (*DetectMuxConfig)    ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig );
  bool (*IsOn)               ( HAL_clk_ClockDomainDescType *pmClkDomainDesc );
  void (*EnableDFS)          ( HAL_clk_ClockDomainDescType *pmClkDomainDesc );
  bool (*IsDFSEnabled)       ( HAL_clk_ClockDomainDescType *pmClkDomainDesc );
  void (*ConfigDFSMux)       ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig );
  void (*DetectDFSMuxConfig) ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, HAL_clk_ClockMuxConfigType *pmConfig, uint32_t nPerfLevel );
  void (*SetACDConfig)       ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, uint32_t nDVMVal );
  void (*GetRegSettings)     ( HAL_clk_ClockDomainDescType *pmClkDomainDesc, HAL_clk_DomainRegSettingsType *pmSettings);
} HAL_clk_ClockDomainControlType;


/*
 * HAL_clk_PowerDomainControlType
 * 
 * Enable    - Enable power domain.
 * Disable   - Disable power domain.
 * IsEnabled - Check whether power domain is enabled.
 */
typedef struct
{
  void (*Enable)    ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
  void (*Disable)   ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
  bool (*IsEnabled) ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
  bool (*IsOn)      ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
} HAL_clk_PowerDomainControlType;


/*
 * HAL_clk_DividerControlType
 * 
 * ConfigDivider - Configure the divide value.
 * DetectDivider - Detect the divide value.
 */
typedef struct
{
  void (*ConfigDivider) ( HAL_clk_DividerDescType *pmDividerDesc, uint32_t nDiv );
  void (*DetectDivider) ( HAL_clk_DividerDescType *pmDividerDesc, uint32_t *pnDiv );
} HAL_clk_DividerControlType;


/*
 * HAL_clk_DebugMuxControlType
 *
 * ConfigMux  - Configure the debug mux.
 * CalcFreq   - Calculate frequency of the configured mux input.
 */
typedef struct
{
  void (*ConfigMux) ( HAL_clk_DebugMuxDescType *pmDebugMux, uint32_t nMuxSel );
  void (*CalcFreq)  ( HAL_clk_DebugMuxDescType *pmDebugMux, uint32_t *pnFreqHz );
} HAL_clk_DebugMuxControlType;


/*
 * HAL_clk_ClockDescType
 *
 * Description of a clock, including required data to control the
 * clock.
 *
 * mRegisters  - (optional) Set of registers used by the
 *               common clock control functions (HAL_clk_ClockControl*).
 * pmControl   - Pointer to the control functions for this clock.  If NULL
 *               then the clock is not supported.
 * nDebugMuxSel - Input select value for this clock on its debug mux.
 *               
 */
struct HAL_clk_ClockDescType
{
  HAL_clk_ClockRegistersType  mRegisters;
  HAL_clk_ClockControlType   *pmControl;
  uint32_t                    nDebugMuxSel;
};


/*
 * HAL_clk_ClockDomainDescType
 *
 * Description of a clock domain, including required data to control the
 * clock domain.
 * 
 * nCGRAddr          - (First) Clock generation register address/offset.
 * pmControl         - Pointer to the control functions for this domain.
 * nMNDWidth         - Width of MND counter.
 * nDFSStates        - Max number of DFS states.
 */
struct HAL_clk_ClockDomainDescType
{
  uintptr_t                        nCGRAddr;
  HAL_clk_ClockDomainControlType  *pmControl;
  uint8                            nMNDWidth;
  uint8                            nDFSStates;
  uint8                            nFlags;
};


/*
 * HAL_clk_SourceDescType
 *
 * Description of a clock source, including control functions.
 *
 * nAddr          - Source base address.
 * VoterRegister  - Register/mask for HW votable configuration setup.
 * pmControl      - Pointer to the control functions for this source.  If NULL
 *                  then the source is not supported.
 */
struct HAL_clk_SourceDescType
{
  uintptr_t                    nAddr;
  HAL_clk_RegisterMaskType     VoterRegister;
  HAL_clk_SourceControlType   *pmControl;
};


/*
 * HAL_clk_PowerDomainDescType
 *
 * Description of a power domain, including control functions.
 *
 * nGDSCRAddr           - Global distributed switch controller (GDSC) register address.
 * nGDSHWCtrlAddr       - Global distributed switch controller (GDSC) hardware ctrl addr
 * VoterRegister  - Register/mask for HW votable configuration setup.
 * pmControl            - Pointer to the control functions for this power domain.  If
 *                        NULL then the power domain is not supported. 
 */
struct HAL_clk_PowerDomainDescType
{
  uintptr_t                        nGDSCRAddr;
  uintptr_t                        nGDSHWCtrlAddr;
  HAL_clk_RegisterMaskType     VoterRegister;
  HAL_clk_PowerDomainControlType  *pmControl;
};


/*
 * HAL_clk_DividerDescType
 *
 * Description of a clock divider, including control functions.
 *
 * nAddr      - Clock divider base address.
 * pmControl  - Pointer to the control functions for this power domain. If
 *              NULL then the power domain is not supported. 
 */
struct HAL_clk_DividerDescType
{
  uintptr_t                   nAddr;
  HAL_clk_DividerControlType *pmControl;
};


/*
 * HAL_clk_DebugMuxDescType
 *
 * Description of a debug mux, including required data to control the
 * clock.
 *
 * pmControl   - Pointer to the control functions for this debug mux. If NULL
 *               then the debug mux is not supported.
 */
struct HAL_clk_DebugMuxDescType
{
  HAL_clk_DebugMuxControlType *pmControl;
};


/*============================================================================

               FUNCTION DEFINITIONS FOR MODULE

============================================================================*/


bool HAL_clk_WaitForClockOn        ( HAL_clk_ClockDescType  *pmClockDesc );
bool HAL_clk_WaitForClockOff       ( HAL_clk_ClockDescType  *pmClockDesc );
bool HAL_clk_WaitForPowerDomainOff ( HAL_clk_PowerDomainDescType *pmPowerDomainDesc );
void    HAL_clk_BusyWait           ( uint32_t uSec );

#endif /* !HALCLKINTERNAL_H */

