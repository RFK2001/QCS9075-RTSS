/*
===========================================================================
*/
/**
    @file  elfloader.h
    @brief Header of elf loader public API

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/public/elfloader/elfloader.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/* Include header file guard */
#ifndef   ELF_LOADER_H
#define   ELF_LOADER_H

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "elf_header.h"
#include "xbl_def.h"
#include "sec_img_auth.h"
#include "elfloader_def.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**********************************************************
 * Init elf loader
 *
 *
 * @param pbl_shared_info [IN]
 *   void ptr to boot_pbl_shared_data_type struct
 *
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int nElfloaderInit(void *pbl_shared_info);
/**********************************************************
 * Deinit elf loader
 *
 *
 * @param NA [IN]
 *   NA
 *
 * @return void
 *
 **********************************************************/
void vElfloaderDeinit(void);

/**********************************************************
 * Erase image per GUID
 *
 *
  * @param coreId [IN]
 *   core ID
 *
 * @param guidString [IN]
 *   Image GUID
 *
 * @return int [OUT]
 *   status. 0 is success
 *
 **********************************************************/
int nBootLoaderErase(uint8_t coreId, const char *guidString);
/**********************************************************
 * Check ELF header per GUID
 *
 *
  * @param coreId [IN]
 *   core ID
 *
 * @param guidString [IN]
 *   Image GUID
 *
 * @return boolean [OUT]
 *   TRUE: not empty, FALSE: empty or error
 *
 **********************************************************/
boolean bBootLoaderCheckElfHeader(uint8_t coreId, const char *guidString);

/**********************************************************
 * Update the storage type for XBL (NOR-Flash/DDR)
 *
 *
 * @param eStorageType [IN]
 *   eXblStorageType
 *
 * @param ulRamBase [IN]
 *   uint32_t
 *
 * @param ulRamSize [IN]
 *   uint32_t
 *
 * @return int [OUT]
 *   XBL_SUCCESS
 * 
 **********************************************************/
int nElfLoaderUpdate(eXblStorageType eStorageType, uint32_t ulRamBase, uint32_t ulRamSize);
/**********************************************************
 * Image Loading State machine
 *
 *
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @param pulEntryPointVaddr [IN]
 *  entry point virtual address
 * 
 * @param  sec_img_whitelist [IN]
 *  image list
 * 
 * @return int [OUT]
 *  XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int nElfLoaderLoad_State(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo, uint32 *pulEntryPointVaddr,
                         sec_img_auth_whitelist_area_param_t* whitelistParam );
/**********************************************************
 * Polls the loading state machine until the state machine returns a success or error
 *
 *
 * @param coreId [IN]
 *  core ID
 *    
 * @param pxLoaderInfo [IN]
 *  Loader Info
 * 
 * @return int [OUT]
 *  XBL_SUCCESS/ERROR.
 * 
 **********************************************************/
int nElfLoaderPollState( uint8_t coreId, BootLoaderInfoType *pxLoaderInfo, uint32_t *pulEntryPoint );
/**********************************************************
 * Pre-loading initialization for pxLoader and image list
 *
 *
 * @param coreId [IN]
 *  core ID
 *
 * @param guidString [IN]
 *  Image GUID
 *
 * @param pulEntryPointVaddr [IN]
 *  entry point pointer
 *
 * @param load_List [IN]
 *  RAM mem list
 * 
 * @param pxLoaderInfo_ptr_addr [IN]
 *  addr of pxLoaderInfo ptr 
 *   
 * @return int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 *
 **********************************************************/
int nElfloaderLoad_Open(uint8_t coreId, const char *guidString,
                        xbl_mem_loadlist_param_t* load_List,
                        boolean bBlackList,
                        BootLoaderInfoType ** pxLoaderInfo_ptr_addr);
/**********************************************************
 * Load Elf Header
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderReadElfHeader(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo);
/**********************************************************
 * Authenticate Elf Header
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderAuthElfHeader(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo);
/**********************************************************
 * Load Program Header
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderLoadProgramHeader(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo);
/**********************************************************
 * Load Hash Segment
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderLoadHashSegment(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo);
/**********************************************************
 * Get Hash digest for the hash segment
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 *
 * @param hashContainer [IN]
 *  Digest hash container
 * 
 * @param containerSize [IN]
 *  Digest hash container size
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderGetDigestHash(BootLoaderInfoType *pxLoaderInfo, uint8_t *hashContainer, uint32_t containerSize);
/**********************************************************
 * Allocate Image Context
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderAllocateImageCtxt(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo);
/**********************************************************
 * Verify Image MetaData
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @param whitelistParam [IN]
 *  Image whitelist
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderVerify_Meta_Data(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo, sec_img_auth_whitelist_area_param_t *whitelistParam);
/**********************************************************
 * Load Program Header Segments
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 * 
**********************************************************/
int nElfLoaderLoadPhdrSegments(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo);
/**********************************************************
 * Software Image Verification of SAIL images
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_OK_NOT_DONE/ERROR
 *  
**********************************************************/
int nElfLoaderVerifySwiv(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo);
/**********************************************************
 * Secure Hash Verification
 * 
 * 
 * @param coreId [IN]
 *  core ID
 * 
 * @param pxLoaderInfo [IN]
 *  Loader info
 * 
 * @return  int [OUT]
 *  XBL_SUCCESS/ERROR
 * 
**********************************************************/
int nElfLoaderSecureHashVerify(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo);

#endif /* ELF_LOADER_H */

/**********************************************************************************************************
**                                        End of file                                                    **
**********************************************************************************************************/
