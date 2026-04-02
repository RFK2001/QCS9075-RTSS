#ifndef __CLOCK_H__
#define __CLOCK_H__

/*
==============================================================================

FILE: Clock.h

DESCRIPTION:
  Clock driver public interface.

==============================================================================

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/clock/public/Clock.h#1 $

==============================================================================
Copyright (c) 2018-2019 QUALCOMM Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR
==============================================================================

*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "ClockDefs.h"
#include "stdbool.h"
#include "stdint.h"

#define CLOCK_FUNC  __attribute__ ( ( section ("clock_func" ) ) )

/*=========================================================================
      Top-Level Functions
==========================================================================*/
/* =========================================================================
**  Function : Clock_GetHandle
** =========================================================================*/
/**
  Get the clock handle.

  This function returns the clock handle.

  @return
  CLOCK_SUCCESS -- handle in param1.
  
  @param hClient [out] Handle to the client.

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_GetHandle
(
  ClockHandle *hClient
);

/* =========================================================================
**  Function : Clock_DriverInit
** =========================================================================*/
/**
  Initialize the clock driver.

  This function initializes the clock driver, it is the main init entry
  point.

  @return
  CLOCK_SUCCESS -- Init was successful.
  CLOCK_ERROR -- Initialization failed.

  @dependencies
  None.
*/

CLOCK_FUNC ClockResult Clock_DriverInit
(
  void
);


/* =========================================================================
**  Function : Clock_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @return
  CLOCK_SUCCESS -- Init was successful.
  CLOCK_ERROR -- Initialization failed.

  @dependencies
  None.
*/

CLOCK_FUNC ClockResult Clock_DriverDeInit
(
  void
);


/* =========================================================================
**  Function : ClockStub_DriverDeInit
** =========================================================================*/
/**
  De-initialize the clock driver stub.

  This function shuts-down the clock driver.  It is not expected to ever
  be called.

  @return
  CLOCK_SUCCESS -- Init was successful.
  CLOCK_ERROR -- Initialization failed.

  @dependencies
  None.
*/

CLOCK_FUNC ClockResult ClockStub_DriverDeInit
(
  void
);

/* =========================================================================
**  Function : Clock_GetClockId
** =========================================================================*/
/**
 
  This function gets the clock ID using the clock name

  @param hClient [in] Handle to the client.
  @param szName [in] String name to lookup.
  @param pId [out] Pointer to the ID to be filled in.

  @return
  CLOCK_SUCCESS -- Init was successful.
  CLOCK_ERROR -- Initialization failed.

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_GetClockId
(
  ClockHandle hClient, 
  const char  *szName,
  ClockIdType *pId
);

/* =========================================================================
**  Function : Clock_EnableClockEx
** =========================================================================*/
/**
 
  This function enables a clock

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to enable.
  @param nFlags [in] API-specific flags. See CLOCK_ENABLE_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_INTERNAL -- Unable to enable clock.
  CLOCK_SUCCESS -- Clock was enabled.

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_EnableClockEx
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t nFlags
);

#define Clock_EnableClock(hClient, ClockId) \
  Clock_EnableClockEx(hClient, ClockId, 0)

/* =========================================================================
**  Function : Clock_DisableClockEx
** =========================================================================*/
/**
  Disables a clock.

  This function removes the client's vote to disable a specified clock. The clock
  will only be disabled when the reference count reaches 0.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to disable.
  @param nFlags [in] API-specific flags. See CLOCK_DISABLE_FLAG_* for options.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_INTERNAL -- Unable to disable clock.
  CLOCK_SUCCESS -- Call was successful (although the clock may still be enabled).
*/
CLOCK_FUNC ClockResult Clock_DisableClockEx
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t nFlags
);
#define Clock_DisableClock(hClient, ClockId) \
  Clock_DisableClockEx(hClient, ClockId, 0)

/* =========================================================================
**  Function : Clock_SetClockFrequency
** =========================================================================*/
/**
  Sets the frequency of a clock.

  This function requests a frequency change for a specified clock. The driver
  selects the exact frequency based on the matching argument, which allows
  requesting a minimum or approximate frequency. There is no support for
  concurrent requests; the last request will be serviced and override any other
  minimum frequency requests.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the frequency.
  @param nFreq [in] Clock frequency in Hz, kHz, or MHz, depending on the eMatch parameter.
  @param eMatch [in] Type of match request.
  @param pnResultFreq [out] The programmed clock frequency in the same units as nFreq; can be NULL if the resulting frequency does not need to be checked. Note that the result is truncated to the units requested.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid clock ID.
  CLOCK_ERROR_INTERNAL -- Unable to set clock config or invalid domain.
  CLOCK_ERROR_NOT_SUPPORTED -- A matching frequency was not found or domain config is null.
  CLOCK_SUCCESS -- Requested clock frequency was found and programmed.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_SetClockFrequency
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t nFreq,
  ClockFrequencyType eMatch, 
  uint32_t *pnResultFreq
);

/* =========================================================================
**  Function : Clock_GetClockFrequency
** =========================================================================*/
/**
  Gets the frequency of a clock.

  This function retrieves the current frequency of a clock in Hz. This is
  independent of whether or not the clock is running. Note that only clocks
  controlled on the local processor can have the frequency retrieved.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pnFrequencyHz [out] Pointer to uint32_t to fill in with the frequency. A value of zero indicates that the frequency could not be determined.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier or frequency was invalid
  CLOCK_SUCCESS -- Clock was valid. The frequency may or may not have been retrieved (see function description).

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_GetClockFrequency
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t *pnFrequencyHz
);

/* =========================================================================
**  Function : Clock_IsClockEnabled
** =========================================================================*/
/**
  Checks the enabled state of a clock.

  This function checks whether a specified clock is enabled or disabled. Note
  that this is not necessarily equivalent to the clock being active. A clock may
  be disabled by the local processor, but enabled by another one. Or if the
  hardware is misconfigured the clock may be enabled, but not actively toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsEnabled [in/out] Status of check.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid parameter provided.
  CLOCK_ERROR -- Unable to determine clock status.
  CLOCK_SUCCESS -- Status returned in pbIsEnabled parameter.

  @see_also
  Clock_GetId
  Clock_IsOn
*/
CLOCK_FUNC ClockResult Clock_IsClockEnabled
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  bool *pbIsEnabled
);

/* =========================================================================
**  Function : Clock_IsClockOn
** =========================================================================*/
/**
  Checks whether a clock is on.

  If the clock is on, it means the clock is not just enabled, but is actually
  toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsOn [in/out] Status of check.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Invalid parameter provided.
  CLOCK_ERROR -- Unable to determine clock status.
  CLOCK_SUCCESS -- Status returned in pbIsOn parameter.

  @see_also
  Clock_GetId
  Clock_IsEnabled
*/
CLOCK_FUNC ClockResult Clock_IsClockOn
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  bool *pbIsOn
);

/* =========================================================================
**  Function : Clock_SetClockDivider
** =========================================================================*/
/**
  Sets the divider for a clock.

  This function programs the divider for a specified clock. This functionality
  only applies to a small subset of clocks that have independent dividers off
  the main domain.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the divider.
  @param nDivider [in] Clock divider in logical units; 0 is invalid.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Requested clock ID was valid. Divider value may or may  not be correct.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_SetClockDivider
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t nDivider
);


/* =========================================================================
**  Function : Clock_ConfigClock
** =========================================================================*/
/**
  Configures a clock.

  This function configures a clock based on predefined configuration modes.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param eConfig [in] Clock configuration.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_ERROR_OUT_OF_RANGE_PARAMETER -- Configuration is not supported/invalid.
  CLOCK_SUCCESS -- Call was successful.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_ConfigClock
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  ClockConfigType eConfig
);

/* =========================================================================
**  Function : Clock_MeasureClockFrequency
** =========================================================================*/
/**
  Measures the frequency of a clock.

  This function measures the current frequency of a clock in Hz using hardware
  counting circuits. This functionality  depends on the presence of this
  hardware support, as well as being available on the current processor. It also
  requires that the clock can be enabled, which must be possible from the
  current environment. The frequency measurement is accurate to within a few
  kHz. The measurement takes a long time (at least a few milliseconds) and is
  intended only for testing purposes, not any real modes of operation.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pnFrequencyHz [out] Pointer to uint32_t to fill in with the frequency. A value of zero indicates that the frequency could not be determined.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid, or frequency pointer was null.
  CLOCK_SUCCESS -- Clock frequency was measured successfully.

  @dependencies

  @side_effects

  @see_also
  Clock_GetId
  Clock_MeasureDebugMuxInput
  Clock_GetFrequency
*/
CLOCK_FUNC ClockResult Clock_MeasureClockFrequency
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  uint32_t *pnFrequencyHz
);

/* =========================================================================
**  Function : Clock_QueryClock
** =========================================================================*/
/**
  Query information about about a clock.

  This function queries information about a clock or one of its performance
  levels.

  Note: The CLOCK_QUERY_PERF_LEVEL_* queries use the nPerfLevel argument
        to determine which performance level to query. All other query types
        ignore this argument.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to query the frequency plan.
  @param eQuery[in] Query to perform.
  @param nPerfLevel[in] Performance level index to query.
  @param pResult[out] Query result.

  @return
  CLOCK_ERROR_NOT_SUPPORTED -- Query type or performance level not supported.
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid, or pResult was NULL.
  CLOCK_SUCCESS -- Query result successfully placed in pResult.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_QueryClock
(
  ClockHandle hClient, 
  ClockIdType ClockId, 
  ClockQueryType eQuery, 
  uint32_t nPerfLevel, 
  ClockQueryResultType *pResult
);

/* =========================================================================
**  Function : Clock_DeassertCoreReset
** =========================================================================*/
/**
  Deasserts core level reset. Called to bring secondary cores out of reset

  @param core [in] core number.

  @return
  None

*/
CLOCK_FUNC void Clock_DeassertCoreReset(uint8_t core);

/* =========================================================================
**  Function : Clock_DeassertClusterReset
** =========================================================================*/
/**
  Deasserts cluster level reset. Called to bring other clusters out of reset

  @param cluster [in] cluster number.

  @return
  None

*/
CLOCK_FUNC void Clock_DeassertClusterReset(uint8_t cluster);

/* =========================================================================
**  Function : Clock_ResetCore
** =========================================================================*/
/**
  This function resets a core

  @param cpu_num [in] core number.

  @return
  None

*/
CLOCK_FUNC ClockResult Clock_ResetCore(int cpu_num);

/* =========================================================================
**  Function : Clock_ResetBlock
** =========================================================================*/
/**
  Controls the reset assertion for a clock functional group.

  This function allows resetting hardware in the functional group of the
  specified clock, also known as a 'block-level' reset. All clocks within the
  same functional group share the same reset, so the reset only needs to be
  applied to a single clock within that group. The resetting is destructive to
  the hardware and requires reconfiguration after the reset is deasserted.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the Reset state.
  @param eReset [in] Type of reset: assert, deassert, or pulse.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Clock reset was successfully applied.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_ResetBlock
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
);

/* =========================================================================
**  Function : Clock_Reset
** =========================================================================*/
/**
  Controls the reset assertion for a clock branch.

  This function allows resetting the hardware on the specified clock branch. The
  resetting is destructive to the hardware and requires reconfiguration after
  the reset is deasserted.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the Reset state.
  @param eReset [in] Type of reset: assert, deassert, or pulse.

  @return
  CLOCK_ERROR_INVALID_PARAMETER -- Clock identifier was invalid.
  CLOCK_SUCCESS -- Clock reset was successfully applied.

  @see_also
  Clock_GetId
*/
CLOCK_FUNC ClockResult Clock_Reset
(
  ClockHandle    hClient,
  ClockIdType    ClockId,
  ClockResetType eReset
);

/* =========================================================================
**  Function : Clock_ReInitMDClockBSP
** =========================================================================*/
/*
  This function clears the MD clocks clients data and reference counts.

  @param
  None

  @return
  CLOCK_ERROR
  CLOCK_SUCCESS

*/
CLOCK_FUNC ClockResult Clock_ReInitMDClockBSP(void);

/* =========================================================================
**  Function : Clock_LateInitClocks
** =========================================================================*/
/*
  This function sets turbo frequency for the required clocks post Pmic init.

  @param
  None

  @return
  CLOCK_ERROR
  CLOCK_SUCCESS

*/
CLOCK_FUNC ClockResult Clock_LateInitClocks(void);

/* =========================================================================
**  Function : Clock_SleepEntry
** =========================================================================*/
/**
  This function execute the sleep entery sequence

  @return
  CLOCK_SUCCESS -- Sleep entry sequence success
  CLOCK_ERROR -- Sleep exit sequence failure

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_SleepEntry( void );

/* =========================================================================
**  Function : Clock_SleepExit
** =========================================================================*/
/**
  This function execute the sleep Exit sequence

  @return
  CLOCK_SUCCESS -- Sleep entry sequence success
  CLOCK_ERROR -- Sleep exit sequence failure

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_SleepExit( void );

/* =========================================================================
**  Function : Clock_NodeRefCountDump
** =========================================================================*/
/**
  This function prints the ref count of all sail cc clocks

  @return
  CLOCK_SUCCESS
  CLOCK_ERROR

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_NodeRefCountDump(void);

/* =========================================================================
**  Function : Clock_GetVoltageRailCorner
** =========================================================================*/
/**
  This function get current volatge corner for a given rail

  @return
  CLOCK_SUCCESS
  CLOCK_ERROR

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_GetVoltageRailCorner ( ClockHandle hClient, const char *szName, rail_voltage_level   *eGetCorner);

#endif /* __CLOCK_H__ */

