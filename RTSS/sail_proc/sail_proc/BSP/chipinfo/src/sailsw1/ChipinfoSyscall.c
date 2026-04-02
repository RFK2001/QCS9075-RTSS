/**************************************************************************************************
** Copyright (c) 2022-2025 Qualcomm Technologies, Inc.                                           **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : ChipinfoSyscall.c
    Component Name     : chipinfo
    Description        : Chipinfo HVC Syscall table and wrapper define in this module
    $Header:  $
    $DateTime:  $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "types.h"


/* =========================================================================
**  Function : ChipInfoSyscall_GetPlatformInfo
** =========================================================================*/
/**

  Chip info System Call Wrapper

  Get the platform Type like RUMI, ADP

  This function returns the platform type.

  @return
  SVC_SUCCESS

  @param rsp [out], PlatformInfoPlatformType

  @dependencies
  None.
*/

CHIPINFO_FUNC uint32 ChipInfoSyscall_GetPlatformInfo(sailbsp_svc_rsp_t *rsp)
{
  
  rsp->data[0] = PlatformInfo_Platform();

  return SVC_SUCCESS;
} /* END ChipInfoSyscall_GetPlatformInfo */


/* =========================================================================
**  Function : ChipInfoSyscall_GetChipVersion
** =========================================================================*/
/**

  Chip info System Call Wrapper

  Get the chip version.

  This function returns the chip version.

  @return
  SVC_SUCCESS

  @param rsp [out], ChipVersion

  @dependencies
  None.
*/
CHIPINFO_FUNC uint32 ChipInfoSyscall_GetChipVersion(sailbsp_svc_rsp_t *rsp)
{
  
  rsp->data[0] = ChipInfo_GetChipVersion();

  return SVC_SUCCESS;
} /* END ChipInfoSyscall_GetChipVersion */


/* =========================================================================
**  Function : ChipInfoSyscall_GetSailChipVersion
** =========================================================================*/
/**

  Chip info System Call Wrapper

  Get the SAIL chip version.

  This function returns the SAIL chip version.

  @return
  SVC_SUCCESS

  @param rsp [out], SAIL chip version

  @dependencies
  None.
*/
CHIPINFO_FUNC uint32 ChipInfoSyscall_GetSailChipVersion(sailbsp_svc_rsp_t *rsp)
{
  
  rsp->data[0] = ChipInfo_GetSailChipVersion();

  return SVC_SUCCESS;
} /* END ChipInfoSyscall_GetSailChipVersion */


/* =========================================================================
**  Function : ChipInfoSyscall_GetChipId
** =========================================================================*/
/**

  Chip info System Call Wrapper

  Get the chip Id.

  This function returns the chip Id.

  @return
  SVC_SUCCESS

  @param rsp [out], Chip Id

  @dependencies
  None.
*/
CHIPINFO_FUNC uint32 ChipInfoSyscall_GetChipId(sailbsp_svc_rsp_t *rsp)
{
  
  rsp->data[0] = ChipInfo_GetChipId();

  return SVC_SUCCESS;
} /* END ChipInfoSyscall_GetChipId */


/* =========================================================================
**  Function : ChipInfoSyscall_GetChipFamily
** =========================================================================*/
/**

  Chip info System Call Wrapper

  Get the chip family.

  This function returns the chip family.

  @return
  SVC_SUCCESS

  @param rsp [out], Chip Family

  @dependencies
  None.
*/
CHIPINFO_FUNC uint32 ChipInfoSyscall_GetChipFamily(sailbsp_svc_rsp_t *rsp)
{
  
  rsp->data[0] = ChipInfo_GetChipFamily();

  return SVC_SUCCESS;
} /* END ChipInfoSyscall_GetChipFamily */



/*
 * uint32 ChipInfoSyscall_GetChipVersion(sailbsp_svc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CHIPINFO_GET_CHIP_VERSION_HVC_ID,
                    CHIPINFO_GET_CHIP_VERSION_PARAM_ID,
                    0,
                    ChipInfoSyscall_GetChipVersion);


/*
 * uint32 ChipInfoSyscall_GetSailChipVersion(sailbsp_svc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CHIPINFO_GET_SAIL_CHIP_VERSION_HVC_ID,
                    CHIPINFO_GET_SAIL_CHIP_VERSION_PARAM_ID,
                    0,
                    ChipInfoSyscall_GetSailChipVersion);


/*
 * uint32 ChipInfoSyscall_GetChipId(sailbsp_svc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CHIPINFO_GET_CHIP_ID_HVC_ID,
                    CHIPINFO_GET_CHIP_ID_PARAM_ID,
                    0,
                    ChipInfoSyscall_GetChipId);


/*
 * uint32 ChipInfoSyscall_GetChipFamily(sailbsp_svc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CHIPINFO_GET_CHIP_FAMILY_HVC_ID,
                    CHIPINFO_GET_CHIP_FAMILY_PARAM_ID,
                    0,
                    ChipInfoSyscall_GetChipFamily);

/*
 * uint32 ChipInfoSyscall_GetPlatformInfo(sailbsp_svc_rsp_t *rsp)
 */
SAIL_DEFINE_SYSCALL(CHIPINFO_GET_PLATFORM_HVC_ID,
                    CHIPINFO_GET_PLATFORM_PARAM_ID,
                    0,
                    ChipInfoSyscall_GetPlatformInfo);

