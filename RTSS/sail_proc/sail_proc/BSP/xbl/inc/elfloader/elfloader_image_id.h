/*
===========================================================================
*/
/**
    @file  elfloader_image_id.h
    @brief elfloader's image id definition

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
#ifndef __ELF_LOADER_IMAGE_ID_H__
#define __ELF_LOADER_IMAGE_ID_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "xbl_def.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**********************************************************
 * Query sec img id from GUID
 *
 *
 * @param guidString [IN]
 *   GUID
 * @param pnImageId [OUT]
 *   sec img id
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderGetImageId(const char *guidString, uint16 *pnImageId, uint8 *pIdx);

#endif /*__ELF_AUTH_H__*/

/**********************************************************************************************************
**                                  End of file                                                          **
**********************************************************************************************************/
