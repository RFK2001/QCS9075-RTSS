/*
===========================================================================
*/
/**
    @file  blacklist.c
    @brief Spinor blacklist functions that restrict access to the driver.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailhyp/blacklist.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "blacklist.h"

#define OSPI_BLACKLIST_ENTRY_MAX_NUM    20


typedef struct {
    uint32_t ulStartAddr;
    uint32_t ulSize;
    eSpinorProtectType eProtectAttrib;
} blackListEntryType;

static blackListEntryType blacklist[OSPI_BLACKLIST_ENTRY_MAX_NUM];

/**********************************************************
 * Resets the entire blacklist
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void blacklistReset(void)
{
    memset(blacklist, 0, sizeof(blacklist));
}

/**********************************************************
 * Checks if the region exists and the index of the region if available
 *
 * @param ulStartAddr [IN]
 *   Blacklist entry address.
 *
 * @param ulSize [IN]
 *   Blacklist entry size.
 *
 * @param ulIndex [IN/OUT]
 *    Index of the region
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean blacklistIsRegionExist(uint32_t ulStartAddr, uint32_t ulSize, uint32_t* ulIndex)
{
    for (uint16_t i = 0; i < OSPI_BLACKLIST_ENTRY_MAX_NUM; i++)
    {
        if (blacklist[i].ulSize != 0)
        {
            if( (blacklist[i].ulSize == ulSize ) && (blacklist[i].ulStartAddr == ulStartAddr ) )
            {
                *ulIndex = i;
                return TRUE;
            }
        }
    }
    *ulIndex = OSPI_BLACKLIST_ENTRY_MAX_NUM;
    return FALSE;
}

/**********************************************************
 * Get the attribute at index specified
 *
 * @param ulIndex [IN]
 *   Index of the blacklist.
 *
 * @param eAttrib [IN/OUT]
 *    pointer to Attribute of the region
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean blacklistGetAttrib(uint32_t ulIndex, eSpinorProtectType* eAttrib)
{
    if (ulIndex<OSPI_BLACKLIST_ENTRY_MAX_NUM)
    {
        *eAttrib = blacklist[ulIndex].eProtectAttrib;
        return TRUE;
    }

    *eAttrib = SPINOR_PROTECT_MAX;
    return FALSE;
}

/**********************************************************
 * Add an entry to the blacklist
 *
 * @param ulStartAddr [IN]
 *   Blacklist entry start address.
 *
 * @param ulSize [IN]
 *   Blacklist entry size.
 *
 * @param eAttrib [IN]
 *    Protection type to add for the region
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean blacklistAddEntry(uint32_t ulStartAddr, uint32_t ulSize, eSpinorProtectType eAttrib)
{
    uint32_t ulIndex=0;
    if (0 == ulSize)
    {
        return FALSE;
    }

    /* Check if region already exists then update the attributes */
    if(TRUE == blacklistIsRegionExist(ulStartAddr,ulSize,&ulIndex))
    {
        /* If the attribute update is to disable protection, remove the entry */
        if (SPINOR_PROTECT_NONE == eAttrib)
        {
            blacklist[ulIndex].ulStartAddr    = 0;
            blacklist[ulIndex].ulSize         = 0;
            blacklist[ulIndex].eProtectAttrib = SPINOR_PROTECT_NONE;
            return TRUE;
        }

        blacklist[ulIndex].ulStartAddr    = ulStartAddr;
        blacklist[ulIndex].ulSize         = ulSize;
        blacklist[ulIndex].eProtectAttrib = eAttrib;

        return TRUE;
    }
    else
    {

        /* If the region is moved to no protect, nothing to remove or add */
        if (SPINOR_PROTECT_NONE == eAttrib)
        {
            return TRUE;
        }

        /* Update the entry in the vacant location */
        for (int i = 0; i < OSPI_BLACKLIST_ENTRY_MAX_NUM; i++)
        {
            if (blacklist[i].ulSize == 0)
            {
                blacklist[i].ulStartAddr    = ulStartAddr;
                blacklist[i].ulSize         = ulSize;
                blacklist[i].eProtectAttrib = eAttrib;
                return TRUE;
            }
        }
    }
    return FALSE;
}

/**********************************************************
 * Check if a range is blacklisted or not against the list
 *
 * @param ulStartAddr [IN]
 *   Blacklist entry start address.
 *
 * @param ulSize [IN]
 *   Blacklist entry size.
 *
 * @param eAttrib [IN]
 *    Protection type to check for the region
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean blacklistCheck(uint32_t ulStartAddr, uint32_t ulSize, eSpinorProtectType eAttrib)
{
    uint32_t endAddr = ulStartAddr + ulSize - 1;
    uint32_t blackListEntryEndAddr;
    uint32_t blackListEntryStartAddr;
    eSpinorProtectType blackListEntryAttrib;

    //eAttrib passed here is the attribute that we need to check. if the attribute is protected return true

    for (int i = 0; i < OSPI_BLACKLIST_ENTRY_MAX_NUM; i++)
    {
        if (blacklist[i].ulSize == 0)
        {
            continue;
        }
        blackListEntryStartAddr = blacklist[i].ulStartAddr;
        blackListEntryEndAddr   = blackListEntryStartAddr + blacklist[i].ulSize - 1;
        blackListEntryAttrib    = blacklist[i].eProtectAttrib;

        /* [start, X, end] */
        if (blackListEntryStartAddr <= ulStartAddr && ulStartAddr <= blackListEntryEndAddr)
        {
            if (eAttrib == (blackListEntryAttrib & eAttrib))
            {
                return TRUE;
            }
        }

        if (blackListEntryStartAddr <= endAddr && endAddr <= blackListEntryEndAddr)
        {
            if (eAttrib == (blackListEntryAttrib & eAttrib))
            {
                return TRUE;
            }
        }

        /* Check if the blacklist region lies within the region being checked */
        if (( ulStartAddr <= blackListEntryStartAddr &&  blackListEntryStartAddr <= endAddr))
        {
            if (eAttrib == (blackListEntryAttrib & eAttrib))
            {
                return TRUE;
            }
        }
    }
    return FALSE;
}


