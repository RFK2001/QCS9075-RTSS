
#ifndef __SAIL_UPDATER_CMN_H__
#define __SAIL_UPDATER_CMN_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_cmn.h
    @brief Public common interface declaration for the Sail Updater.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/


#include "types.h"

/* Status Return Type */
typedef enum
{
    SAIL_UPDATER_STATUS_SUCCESS = 0,          /* Success */
    SAIL_UPDATER_STATUS_FAIL,                 /* Failure */
    SAIL_UPDATER_Q_BUF_FULL,                  /* Queue Buffer Full */
    SAIL_UPDATER_INVALID_HDR_CRC,             /* Message Header CRC Invalid */
    SAIL_UPDATER_INVALID_HDR_PARAM,           /* Message Header Parameters Invalid */
    SAIL_UPDATER_INVALID_MSG_ID,              /* Message ID Invalid */
    SAIL_UPDATER_INVALID_HELLO_MSG,           /* Hello not received correctly */
    SAIL_UPDATER_INVALID_VERSION,             /* Invalid Version */
    SAIL_UPDATER_INVALID_BUF_ADDR,            /* Invalid Buffer Address */
    SAIL_UPDATER_INVALID_BUF_SIZE,            /* Invalid Buffer Size */
    SAIL_UPDATER_UNALIGNED_BUF_SIZE,          /* Unaligned Buffer Size */
    SAIL_UPDATER_INVALID_BUF_CRC,             /* Invalid Buffer CRC */
    SAIL_UPDATER_SPINOR_OPERATION_FAIL,       /* Error from SPINOR Layer */
    SAIL_UPDATER_INVALID_IMG_NAME,            /* Invalid Image Name */
    SAIL_UPDATER_INVALID_PARTITION_ID,        /* Invalid Partition ID */
    SAIL_UPDATER_INVALID_GPT_ID,              /* Invalid GPT ID */
    SAIL_UPDATER_INVALID_NUM_OF_IMAGES,       /* Invalid number of Images */
    SAIL_UPDATER_BOOT_INFO_UNAVAILABLE,       /* Boot Info for all images not available. Try again later.
                                                 Data in the other buffers may be invalid */
    SAIL_UPDATER_GPT_INVALID,                 /* Invalid GPT */
    SAIL_UPDATER_ALT_GPT_INVALID,             /* Alternate/Backup GPT Invalid*/
    SAIL_UPDATER_GPT_HEADERCRC_INVALID,       /* Invalid GPT Header CRC */
    SAIL_UPDATER_GPT_PARTITIONCRC_INVALID,    /* Invalid Parition Entry CRC */
    SAIL_UPDATER_INVALID_OFFSET,              /* Invalid Offset due to offset beyond partition size*/
    SAIL_UPDATER_UNALIGNED_OFFSET,            /* Unaligned offset*/
    SAIL_UPDATER_UNALIGNED_SIZE,              /* Unaligned Read Size */
    SAIL_UPDATER_INVALID_SIZE,                /* Invalid Read Size */
    SAIL_UPDATER_INVALID_ERASE_BLOCK,         /* Invalid Erase Block*/

    SAIL_UPDATER_STATUS_MAX = 0x7FFFFFFF      /* Max type */
}SAILUpdaterStatusType_e;

/*OTA states*/
typedef enum
{
   OTA_IN_PROGRESS = 0x0,                        /* Flashing to a B partition initiated. Don’t use B for normal boot */
   OTA_UPDATE_START    = 0x1,                    /* OTA about to start update GPT SW1 */
   OTA_BOOTING  = 0x2,                           /* OTA boot in progress */ //->in xbl if state update start change state to OTA booting update retry cnt
   OTA_ROLLBACK = 0x3,                           /* OTA boot failed. Rollback in progress */
   OTA_DISABLED = 0x4,                           /* OTA not initiated. Regular boot */
   OTA_DONE = 0x5,                               /* OTA state with no 1+1 redundancy */
   OTA_REBOOT_CORRUPTED = 0x55,                  /* OTA Reboot Corrupted Incase all state are Invalid*/
   OTA_INVALID = 0xFF                            /* Invalid OTA State */
}SAILUpdaterOTAStateValType;

#endif /* __SAIL_UPDATER_CMN_H__ */
