#ifndef __BLACKLIST_H__
#define __BLACKLIST_H__
/*
===========================================================================
*/
/**
    @file  ospi_blacklist.h
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/sailhyp/blacklist.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "spinor_cm_defs.h"

/**********************************************************
 * Resets the entire blacklist
 *
 * @param none 
 *
 * @return void [OUT]
 *
 **********************************************************/
void blacklistReset(void);

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
boolean blacklistAddEntry(uint32_t ulStartAddr, uint32_t ulSize, eSpinorProtectType eAttrib);

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
boolean blacklistIsRegionExist(uint32_t ulStartAddr, uint32_t ulSize, uint32_t* ulIndex);

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
boolean blacklistGetAttrib(uint32_t ulIndex, eSpinorProtectType* eAttrib);

/**********************************************************
 * Check if a range is blacklisted or not against the list
 *
 * @param ulStartAddr [IN]
 *   Blacklist entry start address.
 *
 * @param ulSize [IN]
 *   Blacklist entry size.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean blacklistCheck(uint32_t ulStartAddr, uint32_t ulSize, eSpinorProtectType eAttrib);

#endif /* __BLACKLIST_H__ */
