/**************************************************************************************************
** Copyright (c) 2022 Qualcomm Technologies, Inc.                                                **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : ClockSyscall.c
    Component Name     : clock
    Description        : Clock HVC Syscall table and wrapper define in this module
    $Header:  $
    $DateTime:  $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "ClockDriver.h"
#include "HALclk.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "types.h"



/* =========================================================================
**  Function : ClockSyscall_GetHandle
** =========================================================================*/
/**

  Clock System Call Wrapper

  Get the clock handle.

  This function returns the clock handle.

  @return
  HVC_SUCCESS

  @param hClient [out] Handle to the client.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @dependencies
  None.
*/
uint32 ClockSyscall_GetHandle
(
  ClockHandle *hClient,
  sailbsp_hvc_rsp_t *rsp
)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] = Clock_GetHandle( hClient);

    return HVC_SUCCESS;
}


/* =========================================================================
**  Function : ClockSyscall_GetClockId
** =========================================================================*/
/**

  Clock System Call Wrapper

  This function gets the clock ID using the clock name

  @param hClient [in] Handle to the client.
  @param szName [in] String name to lookup.
  @param pId [out] Pointer to the ID to be filled in.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_GetClockId
(
  ClockHandle hClient,
  const char  *szName,
  ClockIdType *pId,
  sailbsp_hvc_rsp_t *rsp
)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_GetClockId( hClient, szName, pId );

    return HVC_SUCCESS ;
}

/* =========================================================================
**  Function : ClockSyscall_EnableClockEx
** =========================================================================*/
/**

  Clock System Call Wrapper

  This function enables a clock

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to enable.
  @param nFlags [in] API-specific flags. See CLOCK_ENABLE_FLAG_* for options.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_EnableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t nFlags,
  sailbsp_hvc_rsp_t *rsp
)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] = Clock_EnableClockEx( hClient, ClockId, nFlags );

    return HVC_SUCCESS;
}
/* =========================================================================
**  Function : ClockSyscall_DisableClockEx
** =========================================================================*/
/**
  Disables a clock.

  This function removes the client's vote to disable a specified clock. The clock
  will only be disabled when the reference count reaches 0.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to disable.
  @param nFlags [in] API-specific flags. See CLOCK_DISABLE_FLAG_* for options.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS
*/
uint32 ClockSyscall_DisableClockEx
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t nFlags,
  sailbsp_hvc_rsp_t *rsp
)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] = Clock_DisableClockEx( hClient, ClockId, nFlags );

    return HVC_SUCCESS;
}
/* =========================================================================
**  Function : ClockSyscall_SetClockFrequency
** =========================================================================*/
/**

  Clock System Call Wrapper

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
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
*/
uint32 ClockSyscall_SetClockFrequency
(
  ClockHandle hClient,
  ClockIdType ClockId,
  uint32_t nFreq,
  ClockFrequencyType eMatch,
  uint32_t *pnResultFreq,
  sailbsp_hvc_rsp_t *rsp
)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_SetClockFrequency( hClient, ClockId, nFreq, eMatch, pnResultFreq );

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : ClockSyscall_GetClockFrequency
** =========================================================================*/
/**
  Clock System Call Wrapper

  Gets the frequency of a clock.

  This function retrieves the current frequency of a clock in Hz. This is
  independent of whether or not the clock is running. Note that only clocks
  controlled on the local processor can have the frequency retrieved.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pnFrequencyHz [out] Pointer to uint32_t to fill in with the frequency. A value of zero indicates that the frequency could not be determined.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
*/
uint32 ClockSyscall_GetClockFrequency ( ClockHandle hClient,
                                        ClockIdType ClockId,
                                        uint32_t *pnFrequencyHz,
                                        sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_GetClockFrequency( hClient, ClockId, pnFrequencyHz );

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : ClockSyscall_IsClockEnabled
** =========================================================================*/
/**
  Clock System Call Wrapper

  Gets the frequency of a clock.

  This function checks whether a specified clock is enabled or disabled. Note
  that this is not necessarily equivalent to the clock being active. A clock may
  be disabled by the local processor, but enabled by another one. Or if the
  hardware is misconfigured the clock may be enabled, but not actively toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsEnabled [in/out] Status of check.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
  Clock_IsOn
*/
uint32 ClockSyscall_IsClockEnabled ( ClockHandle hClient,
                                     ClockIdType ClockId,
                                     bool *pbIsEnabled,
                                     sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_IsClockEnabled( hClient, ClockId, pbIsEnabled );

    return HVC_SUCCESS;
}
/* =========================================================================
**  Function : ClockSyscall_IsClockOn
** =========================================================================*/
/**
  Clock System Call Wrapper

  Gets the frequency of a clock.

  If the clock is on, it means the clock is not just enabled, but is actually
  toggling.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock to check.
  @param pbIsOn [in/out] Status of check.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
  Clock_IsEnabled
*/
uint32 ClockSyscall_IsClockOn ( ClockHandle hClient,
                                ClockIdType ClockId,
                                bool *pbIsOn,
                                sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_IsClockOn( hClient, ClockId, pbIsOn );

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : ClockSyscall_ResetBlock
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
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
*/
uint32 ClockSyscall_ResetBlock ( ClockHandle hClient,
                                 ClockIdType ClockId,
                                 ClockResetType eReset,
                                 sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_ResetBlock( hClient, ClockId,eReset );

    return HVC_SUCCESS;
}



/* =========================================================================
**  Function : ClockSyscall_Reset
** =========================================================================*/
/**
  Controls the reset assertion for a clock branch.

  This function allows resetting the hardware on the specified clock branch. The
  resetting is destructive to the hardware and requires reconfiguration after
  the reset is deasserted.

  @param hClient [in] Handle to the client.
  @param ClockId [in] Clock for which to set the Reset state.
  @param eReset [in] Type of reset: assert, deassert, or pulse.
  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @see_also
  Clock_GetId
*/
uint32 ClockSyscall_Reset ( ClockHandle hClient,
                            ClockIdType ClockId,
                            ClockResetType eReset,
                            sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_Reset( hClient, ClockId,eReset );

    return HVC_SUCCESS;
}
/* =========================================================================
**  Function : ClockSyscall_SleepEntry
** =========================================================================*/
/**
  This function execute the sleep entery sequence

  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_SleepEntry( sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_SleepEntry();

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : ClockSyscall_SleepExit
** =========================================================================*/
/**
  This function execute the sleep Exit sequence

  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_SleepExit( sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_SleepExit();

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : ClockSyscall_ResetCore
** =========================================================================*/
/**
  This function resets a core

  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_ResetCore(int cpu_num, sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_ResetCore(cpu_num);

    return HVC_SUCCESS;
}

/* =========================================================================
**  Function : Clock_NodeRefCountDump
** =========================================================================*/
/**
  This function prints the ref count of all sail cc clocks

  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_NodeRefCountDump ( sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_NodeRefCountDump();

    return HVC_SUCCESS;
}


/* =========================================================================
**  Function : Clock_GetVoltageRailCorner
** =========================================================================*/
/**
  GGet the voltage corner of a given rail.

  @param rsp [out], ClockResult( clockrsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 ClockSyscall_GetVoltageRailCorner ( ClockHandle hClient, const char *szName, rail_voltage_level   *eGetCorner,  sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return clock result */
    rsp->data[0] =  Clock_GetVoltageRailCorner ( hClient, szName, eGetCorner );

    return HVC_SUCCESS;
}
/*
 * uint32 ClockSyscall_GetHandle( ClockHandle *hClient,
 *                                sailbsp_hvc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CLOCK_GET_HANDLE_HVC_ID,
                    CLOCK_GET_HANDLE_PARAM_ID,
                    0,
                    ClockSyscall_GetHandle);

/*
 * uint32 ClockSyscall_GetClockId ( ClockHandle hClient,
 *                                  const char  *szName,
 *                                  ClockIdType *pId,
 *                                  sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL(CLOCK_GETCLOCKID_HVC_ID,
                    CLOCK_GETCLOCKID_PARAM_ID,
                    0,
                    ClockSyscall_GetClockId);

/*
 * uint32 ClockSyscall_EnableClockEx ( ClockHandle hClient,
 *                                     ClockIdType ClockId,
 *                                     uint32_t nFlags,
 *                                     sailbsp_hvc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CLOCK_ENABLECLOCKEX_HVC_ID,
                    CLOCK_ENABLECLOCKEX_PARAM_ID,
                    0,
                    ClockSyscall_EnableClockEx);

/*
 * uint32 ClockSyscall_DisableClockEx ( ClockHandle hClient,
 *                                      ClockIdType ClockId,
 *                                      uint32_t nFlags,
 *                                      sailbsp_hvc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CLOCK_DISABLECLOCKEX_HVC_ID,
                    CLOCK_DISABLECLOCKEX_PARAM_ID,
                    0,
                    ClockSyscall_DisableClockEx);

/*
 * uint32 ClockSyscall_SetClockFrequency( ClockHandle hClient,
                                          ClockIdType ClockId,
                                          uint32_t nFreq,
                                          ClockFrequencyType eMatch,
                                          uint32_t *pnResultFreq,
                                          sailbsp_hvc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CLOCK_SETCLOCKFREQUENCY_HVC_ID,
                    CLOCK_SETCLOCKFREQUENCY_PARAM_ID,
                    0,
                    ClockSyscall_SetClockFrequency);



/*
 * uint32 ClockSyscall_GetClockFrequency ( ClockHandle hClient,
                                           ClockIdType ClockId,
                                           uint32_t *pnFrequencyHz,
                                           sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_GETCLOCKFREQUENCY_HVC_ID,
                     CLOCK_GETCLOCKFREQUENCY_PARAM_ID,
                     0,
                     ClockSyscall_GetClockFrequency );
/*
 * uint32 ClockSyscall_IsClockEnabled ( ClockHandle hClient,
                                        ClockIdType ClockId,
                                        bool *pbIsEnabled,
                                        sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_ISCLOCKENABLED_HVC_ID,
                     CLOCK_ISCLOCKENABLED_PARAM_ID,
                     0,
                     ClockSyscall_IsClockEnabled );

/*
 * uint32 ClockSyscall_IsClockOn ( ClockHandle hClient,
                                   ClockIdType ClockId,
                                   bool *pbIsOn,
                                   sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_ISCLOCKON_HVC_ID,
                     CLOCK_ISCLOCKON_PARAM_ID,
                     0,
                     ClockSyscall_IsClockOn );

/*
 * uint32 ClockSyscall_ResetBlock ( ClockHandle hClient,
                                    ClockIdType ClockId,
                                    ClockResetType eReset,
                                    sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_RESETBLOCK_HVC_ID,
                     CLOCK_RESETBLOCK_PARAM_ID,
                     0,
                     ClockSyscall_ResetBlock );
/*
 * uint32 ClockSyscall_Reset ( ClockHandle hClient,
                               ClockIdType ClockId,
                               ClockResetType eReset,
                               sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_RESET_HVC_ID,
                     CLOCK_RESET_PARAM_ID,
                     0,
                     ClockSyscall_Reset );

/*
 * uint32 ClockSyscall_SleepEntry ( sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_SLEEP_ENTRY_HVC_ID,
                     CLOCK_SLEEP_ENTRY_PARAM_ID,
                     0,
                     ClockSyscall_SleepEntry );
/*
 * uint32 ClockSyscall_SleepExit ( sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_SLEEP_EXIT_HVC_ID,
                     CLOCK_SLEEP_EXIT_PARAM_ID,
                     0,
                     ClockSyscall_SleepExit );

/*
 * uint32 ClockSyscall_ResetCore ( int cpu_num, sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_RESET_CORE_HVC_ID,
                     CLOCK_RESET_CORE_PARAM_ID,
                     0,
                     ClockSyscall_ResetCore );

/*
 * uint32 ClockSyscall_GetVoltageRailCorner ( ClockHandle hClient, const char *szName, rail_voltage_level   *eGetCorner,  sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_GETVOLTAGERAILCORNER_HVC_ID,
                     CLOCK_GETVOLTAGERAILCORNER_PARAM_ID,
                     0,
                     ClockSyscall_GetVoltageRailCorner );

/*
 * uint32 ClockSyscall_NodeRefCountDump ( sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CLOCK_NODEREFCOUNTDUMP_HVC_ID,
                     CLOCK_NODEREFCOUNTDUMP_PARAM_ID,
                     0,
                     ClockSyscall_NodeRefCountDump );

