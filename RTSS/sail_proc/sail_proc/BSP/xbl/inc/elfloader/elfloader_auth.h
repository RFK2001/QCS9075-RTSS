/*
===========================================================================
*/
/**
    @file  elfloader_auth.h
    @brief Header of elf loader auth sub-module

*/
/*
    ===========================================================================

    Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/elfloader/elfloader_auth.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/* Include header file guard */
#ifndef __ELF_LOADER_AUTH_H__
#define __ELF_LOADER_AUTH_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
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
 * allocate image context
 *
 *
 * @param sec_img_id [IN]
 *   security Image Id
 *
 * @return boolean [OUT]
 *   True: pass.
 *
 **********************************************************/
boolean bElfloaderAuthAllocateImgCtx(uint32_t sec_img_id);
/**********************************************************
 * free image context
 *
 *
 * @param sec_img_id [IN]
 *   security Image Id
 *
 * @return None
 *
 **********************************************************/
void bElfloaderAuthFreeImgCtx(uint32_t sec_img_id);
/**********************************************************
 * auth init
 *
 *
 * @param None
 *
 * @return boolean [OUT]
 *   True: pass.
 *
 **********************************************************/
 boolean vElfAuthInit(void *pbl_shared_info);
/**********************************************************
 * Verify elf header using sec auth lib
 *
 *
 * @param coreId [IN]
 *   core ID
 * @param secImgId [IN]
 *   security Image Id
 * @param ehdr [IN]
 *   elf header
 *
 * @return boolean [OUT]
 *   True: pass.
 *
 **********************************************************/
boolean bElfloaderAuthValidateElf(uint8_t coreId, uint16_t secImgId, Elf32_Ehdr *ehdr);
/**********************************************************
 * Get hash segment index in phdr array
 *
 *
  * @param coreId [IN]
 *   core ID
 * @param secImgId [IN]
 *   security Image Id
 * @param phdr [IN]
 *   Pointer to program header
  * @param phnum [IN]
 *   number of program header
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderAuthGetHashSegmentIdx(uint8_t coreId, uint16_t secImgId, Elf32_Phdr *phdr, uint16 phnum, uint16 *pnHashIdx);
/**********************************************************
 * Get hash Digest for given hash segment
 *
 *
 * @param doubleHashContainer [IN]
 *   doubleHashContainer as a destination buffer for hash digest
 * @param hashSegment [IN]
 *   hashSegment input for hash calculation
 * @param hashSize [IN]
 *   hashSize gives the size of hash container
 * @return boolean [OUT]
 *   TRUE if success.
 *
 **********************************************************/
boolean elfLoaderAuthGetHashDigest(uint8_t *doubleHashContainer, hashSegmentType* hashSegment, uint32_t doubleHashSize);
/**********************************************************
 * Verify image metadata including the signature verification
 *
 *
 * @param coreId [IN]
 *   core ID
 * @param pInfo [IN]
 *   Image info pointer
  * @param whitelist [IN]
 *   sec img mem region whitelist
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderAuthSecImgVerifyMeta(uint8_t coreId, BootLoaderInfoType *pInfo, sec_img_auth_whitelist_area_param_t *whitelist);
/**********************************************************
 * Is the segment loadable?
 *
 *
 * @param coreId [IN]
 *   core ID
 * @param ehdr [IN]
 *   Pointer to elf header
 * @param phdr [IN]
 *   Pointer to program header
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderAuthIsSegmentLoadable(uint8_t coreId, Elf32_Ehdr          *pehdr, Elf32_Phdr *phdr);
/**********************************************************
 * Check if the secure boot is enabled in this device
 *
 *
 * @param NULL
 *
 * @return boolean [OUT]
 *   TRUE: enabled.
 *
 **********************************************************/
boolean bElfloaderAuthIsAuthEnabled(void);
/**********************************************************
 * Secure boot verification
 *
 *
 * @param coreId [IN]
 *   core ID
 * @param pInfo [IN]
 *   Boot image info
 *
 * @return boolean [OUT]
 *   TRUE: pass.
 *
 **********************************************************/
boolean bElfloaderAuthCheckSecImgAuth(uint8_t coreId, BootLoaderInfoType *pInfo);

#endif /*__ELF_AUTH_H__*/

/**********************************************************************************************************
**                                  End of file                                                          **
**********************************************************************************************************/
