/*
===========================================================================
*/
/**
    @file  sailhyp_xbl_guid.c
    @brief sailhyp xbl guid implementation
*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/sailhyp/sailhyp_xbl_guid.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include "types.h"
#include "elfloader.h"
#include "xbl_def.h"
#include "sailhyp_xbl.h"

/*===========================================================================
                           MACROS
===========================================================================*/



/*===========================================================================
                               VARIABLES
============================================================================*/
#define XBL_GUID_COLUMN_MAX      2
const char *sailImageGuid[XBL_IMAGE_ID_MAX][XBL_GUID_COLUMN_MAX] =
{
    /* primary GUID                secondary GUID      */
    {SAIL_SW1_GUID_PRIMARY,        SAIL_SW1_GUID_BACKUP},        /* sw1 */
    {SAIL_SW2_GUID_PRIMARY,        SAIL_SW2_GUID_BACKUP},        /* sw2 */
    {SAIL_SW3_GUID_PRIMARY,        SAIL_SW3_GUID_BACKUP},        /* sw3 */
    {SAIL_SW4_GUID_PRIMARY,        SAIL_SW4_GUID_BACKUP},        /* sw4 */
    {SAIL_SEC_ELF_GUID_PRIMARY,    SAIL_SEC_ELF_GUID_BACKUP},    /* sec elf GUID pair */
    {SAIL_DBG_POLICY_GUID_PRIMARY, SAIL_DBG_POLICY_GUID_BACKUP}, /* dbg policy GUID pair */
    {SAIL_HYP_GUID_PRIMARY,        SAIL_HYP_GUID_BACKUP}         /* SAIL HYP */
};

const char* sailhyp_xbl_boot_get_guid(eXblImageIdType image_id, boolean primary_guid)
{
    const char* guid = NULL;
    uint32_t colIdx = (primary_guid == TRUE)? 0 : 1;

    if (image_id < XBL_IMAGE_ID_MAX)
    {
        return sailImageGuid[image_id][colIdx];
    }
    else
    {
        return NULL;
    }
}
