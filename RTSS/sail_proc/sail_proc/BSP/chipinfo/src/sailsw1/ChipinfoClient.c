/*
==============================================================================

FILE: ChipinfoClient.c

DESCRIPTION:
  Chipinfo driver System Call ( SW1/EL1 ) module interface.

==============================================================================

$Header: $

==============================================================================
Copyright (c) 2018-2025 QUALCOMM Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR
==============================================================================

*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "stdbool.h"
#include "stdint.h"
#include "types.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "err_fatal.h"

/*=========================================================================
      Top-Level Functions
==========================================================================*/


/* =========================================================================
**  Function : ChipInfo_GetChipVersion
** =========================================================================*/
/**
  Get the chip version.

  This function returns the chip version.

  @return
  Chip Version.

  @dependencies
  None.
*/
CHIPINFO_FUNC ChipInfoVersionType ChipInfo_GetChipVersion(void)
{
  ChipInfoVersionType nVersion = 0;

    uint32_t hvcId     = CHIPINFO_GET_CHIP_VERSION_HVC_ID;
    uint32_t paramId   = CHIPINFO_GET_CHIP_VERSION_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    nVersion = paramId;

  return nVersion;
} /* END ChipInfo_GetChipVersion */


/* =========================================================================
**  Function : ChipInfo_GetSailChipVersion
** =========================================================================*/
/**
  Get the SAIL chip version.

  This function returns the SAIL chip version.

  @return
  SAIL Chip version.

  @dependencies
  None.
*/
CHIPINFO_FUNC ChipInfoVersionType ChipInfo_GetSailChipVersion(void)
{
  ChipInfoVersionType nVersion = 0;

    uint32_t hvcId     = CHIPINFO_GET_SAIL_CHIP_VERSION_HVC_ID;
    uint32_t paramId   = CHIPINFO_GET_SAIL_CHIP_VERSION_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    nVersion = paramId;

  return nVersion;
} /* END ChipInfo_GetChipVersion */


/* =========================================================================
**  Function : ChipInfo_GetChipId
** =========================================================================*/
/**
  Get the chip ID.

  This function returns the chip ID.

  @return
  Chip Id

  @dependencies
  None.
*/
CHIPINFO_FUNC ChipInfoIdType ChipInfo_GetChipId(void)
{
  ChipInfoIdType nVersion = 0;

    uint32_t hvcId     = CHIPINFO_GET_CHIP_ID_HVC_ID;
    uint32_t paramId   = CHIPINFO_GET_CHIP_ID_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    nVersion = paramId;

  return nVersion;
} /* END ChipInfo_GetChipId */


/* =========================================================================
**  Function : PlatformInfo_Platform
** =========================================================================*/
/**

  Get the platform type.

  This function returns the platform type.

  @return
  SVC_SUCCESS

  @param rsp [out], PlatformInfoPlatformType

  @dependencies
  None.
*/


CHIPINFO_FUNC PlatformInfoPlatformType PlatformInfo_Platform(void)
{
    PlatformInfoPlatformType xPlatformType = PLATFORMINFO_TYPE_UNKNOWN;

    uint32_t hvcId     = CHIPINFO_GET_PLATFORM_HVC_ID;
    uint32_t paramId   = CHIPINFO_GET_PLATFORM_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    xPlatformType = paramId;

    return xPlatformType;
}/* END PlatformInfo_Platform */



/* =========================================================================
**  Function : ChipInfo_GetChipFamily
** =========================================================================*/
/**
  Get the chip family.

  This function returns the chip family.

  @return
  Chip Family Type.

  @dependencies
  None.
*/
CHIPINFO_FUNC ChipInfoFamilyType ChipInfo_GetChipFamily(void)
{
  ChipInfoFamilyType nVersion = 0;

    uint32_t hvcId     = CHIPINFO_GET_CHIP_FAMILY_HVC_ID;
    uint32_t paramId   = CHIPINFO_GET_CHIP_FAMILY_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	err_fatal(CHIPINFO, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    nVersion = paramId;

  return nVersion;
} /* END ChipInfo_GetChipFamily */


