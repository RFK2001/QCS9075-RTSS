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
* GENERATED ON : Sat Apr 13 20:51:47 IST 2024           
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
const Can_DataBaudConfigPtrType Can_DataBaudrate_0_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_0_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_0_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_0_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_0_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_0_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_1_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_0_UT =
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
  TRUE,
  /*Can_TrcvCompDelay*/
  0u,
   /*Can_TrcvCompDelayFilterLength*/
  0u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_2_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_3_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_4_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_7_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_5_8_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_7_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_6_8_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_0_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_1_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_2_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_3_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_4_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_5_UT =
{
  /*Can_Baudrate*/
  5000u,
  /*Can_ControllerPropSeg*/
  7u,
  /*Can_ControllerPhaseSeg1*/
  3u,
  /*Can_ControllerPhaseSeg2*/
  3u,
  /*Can_ControllerSyncSeg*/
  3u,
    /*Can_BRPValue*/
  0u,
  /*Can_DelayEnable*/
  TRUE,
  /*Can_TrcvCompDelay*/
  13u,
   /*Can_TrcvCompDelayFilterLength*/
  1u,
  /*Can_BrsSwitch*/
  TRUE
};

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_6_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_7_UT =
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

const Can_DataBaudConfigPtrType Can_DataBaudrate_7_8_UT =
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
const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_0_UT[] = 
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
    &Can_DataBaudrate_0_0_UT
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
    &Can_DataBaudrate_0_1_UT
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
    &Can_DataBaudrate_0_2_UT
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
    &Can_DataBaudrate_0_3_UT
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
    &Can_DataBaudrate_0_4_UT
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
    &Can_DataBaudrate_0_5_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_1_UT[] = 
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
    NULL_PTR
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
    &Can_DataBaudrate_1_1_UT
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
    &Can_DataBaudrate_1_2_UT
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
    &Can_DataBaudrate_1_3_UT
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
    &Can_DataBaudrate_1_4_UT
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
    &Can_DataBaudrate_1_5_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_2_UT[] = 
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
    &Can_DataBaudrate_2_0_UT
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
    &Can_DataBaudrate_2_1_UT
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
    &Can_DataBaudrate_2_2_UT
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
    &Can_DataBaudrate_2_3_UT
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
    &Can_DataBaudrate_2_4_UT
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
    &Can_DataBaudrate_2_5_UT
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
    &Can_DataBaudrate_2_6_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_3_UT[] = 
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
    &Can_DataBaudrate_3_0_UT
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
    &Can_DataBaudrate_3_1_UT
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
    &Can_DataBaudrate_3_2_UT
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
    &Can_DataBaudrate_3_3_UT
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
    &Can_DataBaudrate_3_4_UT
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
    &Can_DataBaudrate_3_5_UT
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
    &Can_DataBaudrate_3_6_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_4_UT[] = 
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
    &Can_DataBaudrate_4_0_UT
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
    &Can_DataBaudrate_4_1_UT
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
    &Can_DataBaudrate_4_2_UT
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
    &Can_DataBaudrate_4_3_UT
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
    &Can_DataBaudrate_4_4_UT
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
    &Can_DataBaudrate_4_5_UT
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
    &Can_DataBaudrate_4_6_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_5_UT[] = 
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
    &Can_DataBaudrate_5_0_UT
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
    &Can_DataBaudrate_5_1_UT
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
    &Can_DataBaudrate_5_2_UT
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
    &Can_DataBaudrate_5_3_UT
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
    &Can_DataBaudrate_5_4_UT
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
    &Can_DataBaudrate_5_5_UT
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
    &Can_DataBaudrate_5_6_UT
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
    &Can_DataBaudrate_5_7_UT
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
    &Can_DataBaudrate_5_8_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_6_UT[] = 
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
    &Can_DataBaudrate_6_0_UT
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
    &Can_DataBaudrate_6_1_UT
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
    &Can_DataBaudrate_6_2_UT
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
    &Can_DataBaudrate_6_3_UT
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
    &Can_DataBaudrate_6_4_UT
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
    &Can_DataBaudrate_6_5_UT
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
    &Can_DataBaudrate_6_6_UT
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
    &Can_DataBaudrate_6_7_UT
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
    &Can_DataBaudrate_6_8_UT
  }
};

const Can_NominalBaudConfigPtrType Can_ControllerBaudrateConfig_7_UT[] = 
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
    &Can_DataBaudrate_7_0_UT
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
    &Can_DataBaudrate_7_1_UT
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
    &Can_DataBaudrate_7_2_UT
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
    &Can_DataBaudrate_7_3_UT
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
    &Can_DataBaudrate_7_4_UT
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
    &Can_DataBaudrate_7_5_UT
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
    &Can_DataBaudrate_7_6_UT
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
    &Can_DataBaudrate_7_7_UT
  },   {
    /* Can_Baudrate   */
    0u,
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
    &Can_DataBaudrate_7_8_UT
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
const Can_MsgRamConfigType CanMsgRamConfig_0_UT = 
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
   128,
   /*Can_ExtendedIDFiltersCount*/
   64,
   /*Can_Fifo0BufferCount*/
   64,
   /*Can_Fifo1BufferCount*/
   64,
   /*Can_DedicatedRxBufferCount*/
   64,
   /*Can_TxEventFIFOCount*/
   32,
   /*Can_TxFIFOQueueCount*/
   10,
   /*Can_TxBufferCount*/
   5,
   /*Can_FilterListSTDStartAdd*/
   0x0,
   /*Can_FilterListEXTStartAdd*/
   128,
   /*Can_RxFIFO0StartAdd*/
   256,
   /*Can_RxFIFO1StartAdd*/
   1408,
   /*Can_RxBufferStartAdd*/
   2560,
   /*Can_TxEventFIFOStartAdd*/
   3712,
   /*Can_TxBufferStartAdd*/
   3776
};


const Can_MsgRamConfigType CanMsgRamConfig_1_UT = 
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
   128,
   /*Can_ExtendedIDFiltersCount*/
   64,
   /*Can_Fifo0BufferCount*/
   64,
   /*Can_Fifo1BufferCount*/
   64,
   /*Can_DedicatedRxBufferCount*/
   64,
   /*Can_TxEventFIFOCount*/
   32,
   /*Can_TxFIFOQueueCount*/
   10,
   /*Can_TxBufferCount*/
   5,
   /*Can_FilterListSTDStartAdd*/
   0x0,
   /*Can_FilterListEXTStartAdd*/
   128,
   /*Can_RxFIFO0StartAdd*/
   256,
   /*Can_RxFIFO1StartAdd*/
   1408,
   /*Can_RxBufferStartAdd*/
   2560,
   /*Can_TxEventFIFOStartAdd*/
   3712,
   /*Can_TxBufferStartAdd*/
   3776
  };

const Can_MsgRamConfigType CanMsgRamConfig_2_UT = 
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
  STD_OFF,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_ON,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_ON,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_OFF,
  /*Can_RxMAXBufferDLC*/
   7,
   /*Can_RxMAXFIFO1DLC*/
   7,
   /*Can_RxMAXFIFO0DLC*/
   7,
   /*Can_TxMAXBufferDLC*/
   7,
   /*Can_StdandardIDFiltersCount*/
   128,
   /*Can_ExtendedIDFiltersCount*/
   64,
   /*Can_Fifo0BufferCount*/
   64,
   /*Can_Fifo1BufferCount*/
   64,
   /*Can_DedicatedRxBufferCount*/
   64,
   /*Can_TxEventFIFOCount*/
   32,
   /*Can_TxFIFOQueueCount*/
   10,
   /*Can_TxBufferCount*/
   5,
   /*Can_FilterListSTDStartAdd*/
   0x0,
   /*Can_FilterListEXTStartAdd*/
   128,
   /*Can_RxFIFO0StartAdd*/
   256,
   /*Can_RxFIFO1StartAdd*/
   1408,
   /*Can_RxBufferStartAdd*/
   2560,
   /*Can_TxEventFIFOStartAdd*/
   3712,
   /*Can_TxBufferStartAdd*/
   3776
 };

const Can_MsgRamConfigType CanMsgRamConfig_3_UT = 
{  
  /*Can_TxFIFOUsed*/
  FALSE,
  /*Can_TxQUEUEUsed*/
  TRUE,
  /*Can_TxEventFIFOUsed*/
  FALSE,
  /*Can_RxFIFO0Used*/
  FALSE,
  /*Can_RxFIFO1Used*/
  FALSE,
  /*Can_RxBufferUsed*/
  FALSE,
  /*Can_AcceptNonMatchFrameSTDRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameSTDRXFIFO1*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO0*/
  STD_OFF,
  /*Can_AcceptNonMatchFrameEXTRXFIFO1*/
  STD_OFF,
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

const Can_MsgRamConfigType CanMsgRamConfig_4_UT = 
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

const Can_MsgRamConfigType CanMsgRamConfig_5_UT = 
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

const Can_MsgRamConfigType CanMsgRamConfig_6_UT = 
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

const Can_MsgRamConfigType CanMsgRamConfig_7_UT = 
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
const Can_CtrlConfigType Can_ActiveCtrlList_UT[] =
{
  {
    /* Can Controller actual ID*/
    0u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8000000u,
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
    Can_ControllerBaudrateConfig_0_UT,
    #if( CAN_PARTITION_SUPPORT_ENABLE == STD_ON)
    /*update with CanControllerEcucPartitionPtr*/
    NULL_PTR,
    #endif
    /*update with CanWakeupSourcePtr*/
    NULL_PTR,
    /*FD Mode enabled*/
    FALSE,
    /*CanNumBaudrates*/
    6u,
    /*CanMsgRamConfig*/
    &CanMsgRamConfig_0_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
  },
  {
    /* Can Controller actual ID*/
    1u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8010000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_INTERRUPT_ON_NEW_ENTRY,
    /*Can Controller Rx Preocessing Mode*/
    CAN_INTERRUPT_ON_NEW_ENTRY,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_INTERRUPT,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_1_UT,
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
    &CanMsgRamConfig_1_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
  },
  {
    /* Can Controller actual ID*/
    2u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8020000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_INTERRUPT_ON_NEW_ENTRY,
    /*Can Controller Rx Preocessing Mode*/
    CAN_INTERRUPT_ON_NEW_ENTRY,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_2_UT,
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
    &CanMsgRamConfig_2_UT,
    /*Can_DMAEnable*/
    TRUE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
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
    Can_ControllerBaudrateConfig_3_UT,
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
    &CanMsgRamConfig_3_UT,
    /*Can_DMAEnable*/
    TRUE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
  },
  {
    /* Can Controller actual ID*/
    4u,
    /* Can Controller base address*/
    (CanBaseAddressType*) 0xF8040000u,
    /*Can Controller Tx Preocessing Mode*/
    CAN_MIXED,
    /*Can Controller Rx Preocessing Mode*/
    CAN_MIXED,
    /*CanWakeupProcessing*/
    CAN_POLLING,
    /*CanBusoffProcessing*/
    CAN_POLLING,
    /*Wakeup Support*/
    FALSE,
    /*Default baud rate*/
    0u,
    /*Can baud Configuration*/
    Can_ControllerBaudrateConfig_4_UT,
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
    &CanMsgRamConfig_4_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
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
    Can_ControllerBaudrateConfig_5_UT,
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
    &CanMsgRamConfig_5_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
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
    Can_ControllerBaudrateConfig_6_UT,
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
    &CanMsgRamConfig_6_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
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
    Can_ControllerBaudrateConfig_7_UT,
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
    &CanMsgRamConfig_7_UT,
    /*Can_DMAEnable*/
    FALSE,
    /*timestamp Prescalar*/
    9u,
    /*Tx FIFO watermark level*/
    2u,
    /*Rx FIFO0 watermark level*/
    2u,
    /*Rx FIFO1 watermark level*/
    2u,
    /* Loopback Enable */
    CAN_LOOPBACK_DISABLED
  }
};
#define CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"

#define CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
#include "Can_MemMap.h"
const Can_TxHOHType Can_TxObjConfig_UT[]=
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
    CAN_OBJECT_PL_8,
    /*Can_TriggerTxEnable*/
    STD_OFF
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
    CAN_OBJECT_PL_48,
    /*Can_TriggerTxEnable*/
    STD_OFF
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

const Can_HwFilterConfigType Can_HwFilter_0_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_3_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_6_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_9_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_12_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_15_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_18_UT[]=
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

const Can_HwFilterConfigType Can_HwFilter_22_UT[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0u,
    /*Can_HwFilterValue*/
    0x50u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }
};

const Can_HwFilterConfigType Can_HwFilter_23_UT[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0x100u,
    /*Can_HwFilterValue*/
    0x101u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }
};

const Can_HwFilterConfigType Can_HwFilter_24_UT[]=
{
  {
  /*Can_HwFilterMode*/
    CAN_DUALID,
    /*Can_HwFilterMaskValue*/
    0x10000155u,
    /*Can_HwFilterValue*/
    0x10000156u,
    /*Can Hardware filter interrupt line*/
	0xFFu,

  }
};

const Can_RxHOHType Can_RxObjConfig_UT[]=
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
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_0_UT
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
        /*CanFd_TxPayloadLength*/
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
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
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
    1u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_3_UT
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
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_3_UT
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
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_3_UT
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
    2u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_EXTENDED_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_6_UT
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
    CAN_EXTENDED_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_6_UT
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
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_6_UT
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
    3u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_MIXED_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_9_UT
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
    CAN_MIXED_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_9_UT
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
    CAN_MIXED_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_9_UT
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
    4u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_12_UT
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
        /*CanFd_TxPayloadLength*/
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
        /*CanFd_TxPayloadLength*/
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
    5u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_15_UT
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
        /*CanFd_TxPayloadLength*/
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
        /*CanFd_TxPayloadLength*/
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
    6u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_18_UT
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
        /*CanFd_TxPayloadLength*/
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
        /*CanFd_TxPayloadLength*/
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
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_24_UT
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
    7u,
    /*Can_RxMsgBufType*/
    /*add check for number of buffers configured*/
    CAN_RxDedicatedBuffer,
    /*Can_HwRxObjHandle*/
    CAN_FULL,
    /*CanIdType*/
    CAN_STANDARD_ID,
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    1u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_22_UT
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
        /*CanFd_TxPayloadLength*/
    CAN_OBJECT_PL_64,
    /*Can_HWFilterCount*/
    0u,
    /**Can_HwFilterPtr*/
    Can_HwFilter_23_UT
    #if(CAN_MIXED_MODE_ENABLE == STD_ON)
    /* Object polling Enabled */
    , FALSE
    #endif
  }
};

const Can_TxRxObjMappingType Can_TxRxObjMap_UT[]=
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

const Can_ConfigType Can_Config_UT =
{ 

  /* Pointer to controller configurations */
  &Can_ActiveCtrlList_UT[0],

  /* Number of Tx Hardware Objects */
  16u,

  /* Pointer to Configuration of Hardware Objects (HTH)*/
  &Can_TxObjConfig_UT[0],

  /* Number of Rx Hardware Objects */
  24u,

  /* Pointer to Configuration of Hardware Objects (HRH)*/
  &Can_RxObjConfig_UT[0],
  Can_TxRxObjMap_UT
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

