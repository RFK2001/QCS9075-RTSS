/*
===========================================================================
*/
/**
    @file  elfloader_loadlist.h
    @brief elfloader loadlist definition

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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

/* Include header file guard */
#ifndef ELF_LOADER_LOADLIST_H
#define ELF_LOADER_LOADLIST_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "xbl_def.h"
#include "elf_header.h"
#include "elfloader_def.h"
#include "sec_img_auth.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/


/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**********************************************************
 * Get image's memory region whitelist
 *
 *
 * @param imageId [IN]
 *   XBL defined imageId
 * @param in_whitelist [IN]
 *   RAM's mem region whitelist
 *
 * @param in_whitelist [OUT]
 *   RAM's memory region whitelist in sec auth defined strust

 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
int xElfloaderGetSecImageLoadlist(xbl_mem_loadlist_param_t *in_mem_loadlist,
                                  sec_img_auth_whitelist_area_param_t **out_sec_loadlist);
/**********************************************************
 * Free sec auth lib's whitelist struct
 *
 *
 * @param whitelist [IN]
 *   sec auth's whitelist pointer
 *
 * @return void [OUT]
 *   NULL.
 *
 **********************************************************/
void vElfloaderPutSecImageLoadlist(sec_img_auth_whitelist_area_param_t ** ppLoadlist);
/**********************************************************
 * Check if the RAM address range fall into the given RAM mem whitelist
 *
 *
 * @param ramStartAddr [IN]
 *   RAM start address
 * @param size [IN]
 *   RAM mem size in bytes
 * @param whitelistParam [IN]
 *   RAM mem whitelist
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderCheckLoadList(uint32 ramStartAddr, uint32 size, sec_img_auth_whitelist_area_param_t *loadListParam);

#endif /*ELF_LOADER_LOADLIST_H*/

/**********************************************************************************************************
**                                  End of file                                                          **
**********************************************************************************************************/
