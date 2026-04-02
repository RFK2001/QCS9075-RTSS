/*
==============================================================================

FILE: ClockClient.c

DESCRIPTION:
  Clock driver System Call ( SW1/EL1 ) module interface.

==============================================================================

$Header: $

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
#include "types.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "err_fatal.h"
#include "Clock.h"

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId     = CLOCK_GET_HANDLE_HVC_ID;
    uint32_t paramId   = CLOCK_GET_HANDLE_PARAM_ID;
    uint32_t arg1      = (uint32_t)hClient;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_GETCLOCKID_HVC_ID;
    uint32_t paramId  = CLOCK_GETCLOCKID_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)szName;
    uint32_t arg3     = (uint32_t)pId;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId   = CLOCK_ENABLECLOCKEX_HVC_ID;
    uint32_t paramId = CLOCK_ENABLECLOCKEX_PARAM_ID;
    uint32_t arg1    = (uint32_t)hClient;
    uint32_t arg2    = (uint32_t)ClockId;
    uint32_t arg3    = (uint32_t)nFlags;
    uint32_t arg4    = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

     uint32_t hvcId   = CLOCK_DISABLECLOCKEX_HVC_ID;
     uint32_t paramId = CLOCK_DISABLECLOCKEX_PARAM_ID;
     uint32_t arg1    = (uint32_t)hClient;
     uint32_t arg2    = (uint32_t)ClockId;
     uint32_t arg3    = (uint32_t)nFlags;
     uint32_t arg4    = 0;

     if( TRUE == xSyscallIsPrivilegedMode() )
     {
         if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
         {
             err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
         }
     }
     else
     {
         if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
         {
             err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
         }
     }

     /*NOTE: parameter id will return with rsp->data[0], clock result */
     ulResult = paramId;

     return ulResult;
}
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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId   = CLOCK_SETCLOCKFREQUENCY_HVC_ID;
    uint32_t paramId = CLOCK_SETCLOCKFREQUENCY_PARAM_ID;
    uint32_t arg1    = (uint32_t)hClient;
    uint32_t arg2    = (uint32_t)ClockId;
    uint32_t arg3    = nFreq;
    /* Indirect parameter to syscall, if args more than 4 */
    uint32_t args[2] = { (uint32)eMatch, (uint32)pnResultFreq };
    uint32_t arg4    = ( uint32_t ) args;


    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_GETCLOCKFREQUENCY_HVC_ID;
    uint32_t paramId  = CLOCK_GETCLOCKFREQUENCY_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)ClockId;
    uint32_t arg3     = (uint32_t)pnFrequencyHz;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_ISCLOCKENABLED_HVC_ID;
    uint32_t paramId  = CLOCK_ISCLOCKENABLED_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)ClockId;
    uint32_t arg3     = (uint32_t)pbIsEnabled;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_ISCLOCKON_HVC_ID;
    uint32_t paramId  = CLOCK_ISCLOCKON_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)ClockId;
    uint32_t arg3     = (uint32_t)pbIsOn;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}
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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_RESETBLOCK_HVC_ID;
    uint32_t paramId  = CLOCK_RESETBLOCK_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)ClockId;
    uint32_t arg3     = (uint32_t)eReset;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId    = CLOCK_RESET_HVC_ID;
    uint32_t paramId  = CLOCK_RESET_PARAM_ID;
    uint32_t arg1     = (uint32_t)hClient;
    uint32_t arg2     = (uint32_t)ClockId;
    uint32_t arg3     = (uint32_t)eReset;
    uint32_t arg4     = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}
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
CLOCK_FUNC ClockResult Clock_SleepEntry( void )
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId     = CLOCK_SLEEP_ENTRY_HVC_ID;
    uint32_t paramId   = CLOCK_SLEEP_ENTRY_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
CLOCK_FUNC ClockResult Clock_SleepExit( void )
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId     = CLOCK_SLEEP_EXIT_HVC_ID;
    uint32_t paramId   = CLOCK_SLEEP_EXIT_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

CLOCK_FUNC ClockResult Clock_ResetCore
(
  int cpu_num
)
{
  uint32 ulResult = CLOCK_SUCCESS;
  uint32_t hvcId     = CLOCK_RESET_CORE_HVC_ID;
  uint32_t paramId   = CLOCK_RESET_CORE_PARAM_ID;
  uint32_t arg1      = cpu_num;
  uint32_t arg2      = 0;
  uint32_t arg3      = 0;
  uint32_t arg4      = 0;

  if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
  {
      err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
  }

  /*NOTE: parameter id will return with rsp->data[0], clock result */
  ulResult = paramId;

  return ulResult;
}

/* =========================================================================
**  Function : Clock_NodeRefCountDump
** =========================================================================*/
/**
  This function prints the Ref counts (vote count) of all SAIL clocks

  @return
  CLOCK_SUCCESS
  CLOCK_ERROR

  @dependencies
  None.
*/
CLOCK_FUNC ClockResult Clock_NodeRefCountDump ( void )
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId     = CLOCK_NODEREFCOUNTDUMP_HVC_ID;
    uint32_t paramId   = CLOCK_NODEREFCOUNTDUMP_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}

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
CLOCK_FUNC ClockResult Clock_GetVoltageRailCorner ( ClockHandle hClient, const char *szName, rail_voltage_level   *eGetCorner)
{
    uint32 ulResult = CLOCK_SUCCESS;

    uint32_t hvcId     = CLOCK_GETVOLTAGERAILCORNER_HVC_ID;
    uint32_t paramId   = CLOCK_GETVOLTAGERAILCORNER_PARAM_ID;
    uint32_t arg1      = (uint32_t)hClient;
    uint32_t arg2      = (uint32_t)szName;
    uint32_t arg3      = (uint32_t)eGetCorner;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(CLOCK, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    /*NOTE: parameter id will return with rsp->data[0], clock result */
    ulResult = paramId;

    return ulResult;
}
