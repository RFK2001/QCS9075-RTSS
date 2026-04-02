#ifndef _SAIL_SEC_CONFIG_H
#define _SAIL_SEC_CONFIG_H

/*===========================================================================
 Copyright (c) 2022-23 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#include "secboot_swid.h"
#include "sail_sec_subsys.h"
#include "util.h"

SAILSECSubsys subsys_info[] =
{
  {
    .sw_id = SECBOOT_SAIL_SW1_SW_TYPE,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
    {
    .sw_id = SECBOOT_SAIL_SW2_SW_TYPE,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
    {
    .sw_id = SECBOOT_SAIL_SW3_SW_TYPE,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
    {
    .sw_id = SECBOOT_SAIL_SW4_SW_TYPE,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
  {
    .sw_id = SECBOOT_APDP_SW_TYPE,
    .cfg =
    {
      .subsys_init = sail_dp_init,
    },
  },
  {
    .sw_id = SECBOOT_SEC_ELF_SW_TYPE ,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
  {
    .sw_id = SECBOOT_QTI_MISC_SW_TYPE,
    .cfg =
    {
      .subsys_init = misc_init,
    },
  },
  {
    .sw_id = SECBOOT_OEM_MISC_SW_TYPE,
    .cfg =
    {
      .subsys_init = NULL,
    },
  },
};
const int subsys_info_size = ARR_SIZE(subsys_info);
#endif /* _SAIL_SEC_CONFIG_H */
