/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
/* Can Post Build Loadable Configuration Source file */
/******************************************************************************/
/**
* AUTOMATICALLY GENERATED FILE. DO NOT EDIT.   
* GENERATED ON : Tue Jun 18 21:04:07 IST 2024           
* 
* file: Can_PBcfg.c
*
* Description: This is a CAN Pre-Compile configuration Header file for CAN 
*              Module.
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver   Who    Date          Changes
* ----- ----  --------   ----------------------------------------------------
* </pre>
*
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

#include "Can_PBcfg.h"
#include "Can.h"

/* [SWS_BSW_00059] Published information elements. */
#define CAN_VENDOR_ID_PBCFG_C   184u
#define CAN_MODULE_ID_PBCFG_C   80u

#define CAN_AR_RELEASE_MAJOR_VERSION_PBCFG_C     4u
#define CAN_AR_RELEASE_MINOR_VERSION_PBCFG_C     8u
#define CAN_AR_RELEASE_REVISION_VERSION_PBCFG_C  0u

#define CAN_SW_MAJOR_VERSION_PBCFG_C     1u
#define CAN_SW_MINOR_VERSION_PBCFG_C     0u
#define CAN_SW_PATCH_VERSION_PBCFG_C     0u


/*******************************************************************************
**                      CAN Configuration Pointer                             **
*******************************************************************************/

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_0_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_1_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_2_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_3_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_4_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_7 =
{
  /*Can_Baudrate*/
  10000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  7u,
   /*Can_TrcvCompDelayFilterLength*/
  8u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_5_8 =
{
  /*Can_Baudrate*/
  11428u,
  /*Can_ControllerPropSeg*/
  3u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  6u,
   /*Can_TrcvCompDelayFilterLength*/
  2u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_7 =
{
  /*Can_Baudrate*/
  10000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  7u,
   /*Can_TrcvCompDelayFilterLength*/
  8u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_6_8 =
{
  /*Can_Baudrate*/
  11428u,
  /*Can_ControllerPropSeg*/
  3u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  6u,
   /*Can_TrcvCompDelayFilterLength*/
  2u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_0 =
{
  /*Can_Baudrate*/
  500u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  9u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_1 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_2 =
{
  /*Can_Baudrate*/
  250u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  19u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_3 =
{
  /*Can_Baudrate*/
  1000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  4u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  FALSE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_4 =
{
  /*Can_Baudrate*/
  2000u,
  /*Can_ControllerPropSeg*/
  2u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  3u,
  /*Can_DelayEnable*/
  FALSE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_5 =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  8u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  2u,
  /*Can_ControllerSyncSeg*/
  2u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  1u,
   /*Can_TrcvCompDelayFilterLength*/
  4u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_6 =
{
  /*Can_Baudrate*/
  8000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  9u,
   /*Can_TrcvCompDelayFilterLength*/
  3u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_7 =
{
  /*Can_Baudrate*/
  10000u,
  /*Can_ControllerPropSeg*/
  4u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  7u,
   /*Can_TrcvCompDelayFilterLength*/
  8u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_DataBaudConfigPtrType Can_DataBaudrate_7_8 =
{
  /*Can_Baudrate*/
  11428u,
  /*Can_ControllerPropSeg*/
  3u,
  /*Can_ControllerPhaseSeg1*/
  1u,
  /*Can_ControllerPhaseSeg2*/
  0u,
  /*Can_ControllerSyncSeg*/
  0u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  6u,
   /*Can_TrcvCompDelayFilterLength*/
  2u,
  /*Can_BrsSwitch*/
  TRUE
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_0[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_0_5
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_1[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_1_5
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_2[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_2_6
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_3[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_3_6
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_4[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_4_6
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_5[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_6
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_7
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_5_8
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_6[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_6
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_7
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_6_8
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_7[] = 
{
  {
    /* Can_Baudrate   */
    500u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    9u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_0
  },   {
    /* Can_Baudrate   */
    250u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    19u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_1
  },   {
    /* Can_Baudrate   */
    125u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    39u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_2
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_3
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_4
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_5
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_6
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_7
  },   {
    /* Can_Baudrate   */
    1000u,
    /* Can_ControllerPropSeg   */
    8u,
    /* Can_ControllerPhaseSeg1   */
    3u,
    /* Can_ControllerPhaseSeg2   */
    2u,
    /* Can_ControllerSyncSeg   */
    2u,
    /*Can_NominalBRPValue*/
    4u,
    /* Can_DataBaudRatePtr */
    &Can_DataBaudrate_7_8
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_0 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_1 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_2 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_3 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_4 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_5 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_6 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  4,
  /*Can_Fifo1BufferCount*/
  4,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  4,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  73,
  /*Can_RxBufferStartAdd*/
  145,
  /*Can_TxEventFIFOStartAdd*/
  163,
  /*Can_TxBufferStartAdd*/
  171
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_MsgRamConfigType CanMsgRamConfig_7 = 
{  
  /*Can_TxFIFOUsed*/
  TRUE,
  /*Can_TxQUEUEUsed*/
  FALSE,
  /*Can_TxEventFIFOUsed*/
  TRUE,
  /*Can_RxFIFO0Used*/
  TRUE,
  /*Can_RxFIFO1Used*/
  TRUE,
  /*Can_RxBufferUsed*/
  TRUE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_ON,
  /*Can_RxMAXBufferDLC*/
  7,
  /*Can_RxMAXFIFO1DLC*/
  7,
  /*Can_RxMAXFIFO0DLC*/
  7,
  /*Can_TxMAXBufferDLC*/
  7,
  /*Can_StdandardIDFiltersCount*/
  1,
  /*Can_ExtendedIDFiltersCount*/
  0,
  /*Can_Fifo0BufferCount*/
  2,
  /*Can_Fifo1BufferCount*/
  2,
  /*Can_DedicatedRxBufferCount*/
  1,
  /*Can_TxEventFIFOCount*/
  2,
  /*Can_TxFIFOQueueCount*/
  4,
  /*Can_TxBufferCount*/
  1,
  /*Can_FilterListSTDStartAdd*/
  0x0,
  /*Can_FilterListEXTStartAdd*/
  1,
  /*Can_RxFIFO0StartAdd*/
  1,
  /*Can_RxFIFO1StartAdd*/
  37,
  /*Can_RxBufferStartAdd*/
  73,
  /*Can_TxEventFIFOStartAdd*/
  91,
  /*Can_TxBufferStartAdd*/
  95
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_CtrlConfigType Can_ActiveCtrlList[] =
{
  {
    /* Can Controller actual ID*/
    0u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8000000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_INTERRUPT_ON_WATERMARK,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_INTERRUPT,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_0,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    6u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_0,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    1u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8010000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_1,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    6u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_1,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    2u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8020000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_2,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    7u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_2,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    3u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8030000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_3,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    7u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_3,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    4u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8040000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_4,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    7u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_4,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    5u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8050000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_5,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    9u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_5,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    6u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8060000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_6,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    9u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_6,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  },
  {
    /* Can Controller actual ID*/
    7u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8070000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_POLLING,
    /*Can Controller Rx Preocessing Mode*/
    CAN_POLLING,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_7,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    TRUE,
    /*CanNumBaudrates*/
    9u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_7,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    1u,
    /*Rx FIFO1 watermark level*/
    1u,
    /* Loopback Enable */
    FALSE
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_TxHOHType Can_TxObjConfig[]=
{
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_0,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    0,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_1,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    0,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_5,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    1,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_6,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    1,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_10,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    2,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_11,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    2,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_15,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    3,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_16,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    3,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_20,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    4,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_21,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    4,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_25,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    5,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_26,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    5,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_30,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    6,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_31,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    6,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_35,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxBuffer,
    /*Can_TxBufferIndex*/
    0u,
    /*Can_HwTxObjectCtrlrId*/
    7,
    /*CanFd_PaddingValue*/
    170u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwTxObjectId*/
    CAN_HW_OBJ_36,
    /*Can_HwTxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*Can_TxMsgBufType*/
    CAN_TxFIFO,
    /*Can_TxBufferIndex*/
    255u,
    /*Can_HwTxObjectCtrlrId*/
    7,
    /*CanFd_PaddingValue*/
    204u,
    /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_TriggerTxEnable*/
    STD_ON
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_0[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_3[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_6[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_9[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_12[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_15[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_18[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_HwFilterConfigType Can_HwFilter_22[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_RxHOHType Can_RxObjConfig[]=
{
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_2,
    /*Can_HwRxObjectCtrlrId*/
    0u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_0
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_3,
    /*Can_HwRxObjectCtrlrId*/
    0u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_4,
    /*Can_HwRxObjectCtrlrId*/
    0u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_7,
    /*Can_HwRxObjectCtrlrId*/
    1u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_3
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_8,
    /*Can_HwRxObjectCtrlrId*/
    1u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_9,
    /*Can_HwRxObjectCtrlrId*/
    1u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_12,
    /*Can_HwRxObjectCtrlrId*/
    2u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_6
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_13,
    /*Can_HwRxObjectCtrlrId*/
    2u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_14,
    /*Can_HwRxObjectCtrlrId*/
    2u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_17,
    /*Can_HwRxObjectCtrlrId*/
    3u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_9
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_18,
    /*Can_HwRxObjectCtrlrId*/
    3u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_19,
    /*Can_HwRxObjectCtrlrId*/
    3u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_22,
    /*Can_HwRxObjectCtrlrId*/
    4u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_12
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_23,
    /*Can_HwRxObjectCtrlrId*/
    4u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_24,
    /*Can_HwRxObjectCtrlrId*/
    4u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_27,
    /*Can_HwRxObjectCtrlrId*/
    5u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_15
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_28,
    /*Can_HwRxObjectCtrlrId*/
    5u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_29,
    /*Can_HwRxObjectCtrlrId*/
    5u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_32,
    /*Can_HwRxObjectCtrlrId*/
    6u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_18
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_33,
    /*Can_HwRxObjectCtrlrId*/
    6u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_34,
    /*Can_HwRxObjectCtrlrId*/
    6u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_39,
    /*Can_HwRxObjectCtrlrId*/
    7u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO1,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_37,
    /*Can_HwRxObjectCtrlrId*/
    7u,
    /*Can_RxBufferIndex*/
    0u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_22
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  },
  {
    /*Can_HwRxObjectId*/
    CAN_HW_OBJ_38,
    /*Can_HwRxObjectCtrlrId*/
    7u,
    /*Can_RxBufferIndex*/
    255u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxFIFO0,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
    /*CanFd_RxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    NULL_PTR
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
static const Can_TxRxObjMappingType Can_TxRxObjMap[]=
{
  {
    CAN_TXOBJ,
    0u
  },  {
    CAN_TXOBJ,
    1u
  },  {
    CAN_RXOBJ,
    0u
  },  {
    CAN_RXOBJ,
    1u
  },  {
    CAN_RXOBJ,
    2u
  },  {
    CAN_TXOBJ,
    2u
  },  {
    CAN_TXOBJ,
    3u
  },  {
    CAN_RXOBJ,
    3u
  },  {
    CAN_RXOBJ,
    4u
  },  {
    CAN_RXOBJ,
    5u
  },  {
    CAN_TXOBJ,
    4u
  },  {
    CAN_TXOBJ,
    5u
  },  {
    CAN_RXOBJ,
    6u
  },  {
    CAN_RXOBJ,
    7u
  },  {
    CAN_RXOBJ,
    8u
  },  {
    CAN_TXOBJ,
    6u
  },  {
    CAN_TXOBJ,
    7u
  },  {
    CAN_RXOBJ,
    9u
  },  {
    CAN_RXOBJ,
    10u
  },  {
    CAN_RXOBJ,
    11u
  },  {
    CAN_TXOBJ,
    8u
  },  {
    CAN_TXOBJ,
    9u
  },  {
    CAN_RXOBJ,
    12u
  },  {
    CAN_RXOBJ,
    13u
  },  {
    CAN_RXOBJ,
    14u
  },  {
    CAN_TXOBJ,
    10u
  },  {
    CAN_TXOBJ,
    11u
  },  {
    CAN_RXOBJ,
    15u
  },  {
    CAN_RXOBJ,
    16u
  },  {
    CAN_RXOBJ,
    17u
  },  {
    CAN_TXOBJ,
    12u
  },  {
    CAN_TXOBJ,
    13u
  },  {
    CAN_RXOBJ,
    18u
  },  {
    CAN_RXOBJ,
    19u
  },  {
    CAN_RXOBJ,
    20u
  },  {
    CAN_TXOBJ,
    14u
  },  {
    CAN_TXOBJ,
    15u
  },  {
    CAN_RXOBJ,
    22u
  },  {
    CAN_RXOBJ,
    23u
  },  {
    CAN_RXOBJ,
    21u
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
const Can_ConfigType Can_Config =
{ 

  /* Pointer to controller configurations */
  &Can_ActiveCtrlList[0],

  /* Number of Tx Hardware Objects */
  16u,

  /* Pointer to Configuration of Hardware Objects (HTH)*/
  &Can_TxObjConfig[0],

  /* Number of Rx Hardware Objects */
  24u,

  /* Pointer to Configuration of Hardware Objects (HRH)*/
  &Can_RxObjConfig[0],
  Can_TxRxObjMap
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

/*******************************************************************************
**                      VERSION CHECK                                         **
*******************************************************************************/
/* SW version check of *.h/c of the own module */
#if ((CAN_SW_MAJOR_VERSION_PBCFG_C != CAN_SW_MAJOR_VERSION) || \
    (CAN_SW_MINOR_VERSION_PBCFG_C != CAN_SW_MINOR_VERSION) || \
    (CAN_SW_PATCH_VERSION_PBCFG_C != CAN_SW_PATCH_VERSION))
    //#error "The SW version number of Can_PBcfg.c and Can.h are different."
#endif
#ifdef __cplusplus
}
#endif
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/

