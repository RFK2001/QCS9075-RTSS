/*
===========================================================================
*/
/**
    @file  xbl_hvc_event.h
    @brief Header of xbl event types

*/
/*
    ===========================================================================

    Copyright (c) 2023 - 2025 Qualcomm Technologies, Inc.
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

    $Header: 
    $DateTime: 
    $Author: 

    ===========================================================================
*/

/* Include header file guard */
#ifndef XBL_HVC_EVENT_H
#define XBL_HVC_EVENT_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "xbl_def.h"


/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

/* Event ids for XBL trap */
typedef enum
{
    XBL_EL1_EVENT_LOADER_OPEN = 0,                 /* LOADER_OPEN Event Id */
    XBL_EL1_EVENT_LOADER_POLL = 1,                 /* LOADER_POLL Event Id */
    XBL_EL1_EVENT_GET_BOOT_INFO = 2,               /* Get Boot info */
    XBL_EL1_EVENT_GET_GUID = 3,                    /* Get GUID */
    XBL_EL1_EVENT_GET_HASH_DGST = 4,               /* Get double hash */
    XBL_EL1_EVENT_MAX_NUM = 5,                     /* Max num of events */
}XblEl1EventIdType;


typedef struct 
{
   const char * imgName;          /* [IN]*/
   uint32_t     FlashPartition;   /* [IN] */
   uint32_t     FlashGptId ;      /* [IN] */
   char       * imgGuid ;         /* [OUT] */
} XblGetImageGuidType ;

typedef struct 
{
    XBLBootInfoType * xBootInfo;      /* [OUT] */ 
    uint32_t          ulArraySize;    /* [IN] */
}XblGetBootInfoType ;


/* XBL HVC Event Types */
typedef struct {
    union
    {
        xbl_boot_params_t   * xBootParams;      /* XBL_EL1_EVENT_LOADER_OPEN [IN] */
        uint32                ulEntryPoint;     /* XBL_EL1_EVENT_LOADER_POLL [OUT] entry point */
        XblGetImageGuidType   xGetImageGuid;    /* XBL_EL1_EVENT_GET_GUID  */
        XblGetBootInfoType    xGetBootInfo;     /* XBL_EL1_EVENT_GET_BOOT_INFO */
        xbl_digestHashType  * xGetHashDigest;   /* XBL_EL1_EVENT_GET_HASH_DIGEST */
    };

} XblHvcEventType;

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/


#endif /* XBL_HVC_EVENT_H */

/**********************************************************************************************************
**                                        End of file                                                    **
**********************************************************************************************************/
