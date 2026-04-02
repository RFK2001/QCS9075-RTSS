#ifndef ISD_COMMON_DEF_H
#define ISD_COMMON_DEF_H

/*
===========================================================================
*/
/**
  @file isd_common_def.h
  @brief Public interface include file for isd common definitions.
*/
/*
  ===========================================================================

  Copyright (c) 2023 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================
*/

#include "types.h"

typedef enum
{
  ISD_FATAL_ERR_SEC_FUSE_HR = 0x01UL,
  ISD_FATAL_ERR_SAILSW1_LOAD_FAIL = 0x02UL,
  ISD_FATAL_ERR_SAILSW2_LOAD_FAIL = 0x03UL,
  ISD_FATAL_ERR_SAILSW3_LOAD_FAIL = 0x04UL,
  ISD_FATAL_ERR_SAILSW4_LOAD_FAIL = 0x05UL,
  ISD_FATAL_ERR_SAILSECELF_LOAD_FAIL = 0x06UL,
  ISD_FATAL_ERR_SAILDP_LOAD_FAIL = 0x07UL,
  ISD_FATAL_ERR_MAX = 0xFFFFFFFFUL,
}ISD_ErrCode_sailboot;

#endif