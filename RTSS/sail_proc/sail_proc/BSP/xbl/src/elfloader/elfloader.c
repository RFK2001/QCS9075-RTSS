/*
===========================================================================
*/
/**
    @file  boot_loader.c
    @brief Implementation of boot loader

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/elfloader/elfloader.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "elf_header.h"
#include "elf_util.h"
#include "elfloader_def.h"
#include "elfloader.h"
#include "elfloader_auth.h"
#include "xbl_mem.h"
#include "elfloader_storage.h"
#include "elfloader_loadlist.h"
#include "elfloader_image_id.h"
#include "xbl_diag.h"
#include "xbl_sec_swiv.h"
#include "HALhwio.h"
#include "common_functions.h"

static boolean g_bInitDone;

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
int nElfloaderInit(void *pbl_shared_info)
{
    uint64 warm_boot_status = in_dword(WARM_BOOT_STATUS);

    if ( DEVICE_IS_IN_WARM_BOOT != warm_boot_status )
    {
    if (FALSE == vElfAuthInit(pbl_shared_info))
    {
        XBL_LOG_ERROR("%s: Error. Auth init failed\n\r", __func__);
        return -1;
    }
    }

    g_bInitDone = TRUE;
    return 0;
}

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
void vElfloaderDeinit(void)
{
}

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
int nElfLoaderUpdate(eXblStorageType eStorageType, uint32_t ulRamBase, uint32_t ulRamSize)
{
    return nStorageUpdate(eStorageType, ulRamBase, ulRamSize);
}

/**********************************************************
 * Get image ID as well as partition size and start addr
 *
 *
 * @param coreId [IN]
 *  core ID
 *
 * @param guidString [IN]
 *  Image GUID
 *
 * @return BootLoaderInfoType [OUT]
 *  pxLoaderInfo struct
 *
 **********************************************************/
static BootLoaderInfoType *nBootLoaderPreload(uint8_t coreId, const char *guidString, int *pStatus)
{
    BootLoaderInfoType *pxLoaderInfo = NULL;

    *pStatus = XBL_SUCCESS;
    do
    {
        pxLoaderInfo = xblMalloc(sizeof(BootLoaderInfoType));
        if (NULL == pxLoaderInfo)
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, no mem\n\r", __func__, coreId);
            *pStatus = XBL_ERROR_NO_MEM;
            break;
        }

        (void)memset(pxLoaderInfo, 0, sizeof(BootLoaderInfoType));
        (void)sailbsp_strlcpy(pxLoaderInfo->g_guidString, guidString, GUID_SIZE);
        if (0 != nStorageOpen(&pxLoaderInfo->g_spinor_handle))
        {
            XBL_LOG_ERROR("%s: Error. Cannot open storage driver\n\r", __func__);
            xblFree(pxLoaderInfo);
            pxLoaderInfo = NULL;
            *pStatus = XBL_ERROR_STORAGE_OPEN;
            break;
        }

        if (FALSE == bElfloaderGetImageId( pxLoaderInfo->g_guidString, &pxLoaderInfo->g_nImageId, &pxLoaderInfo->g_nIdx) )
        {
            xStorageClose(pxLoaderInfo->g_spinor_handle);
            xblFree(pxLoaderInfo);
            pxLoaderInfo = NULL;
            *pStatus = XBL_ERROR_NOT_SUPPORTED;
            break;
        }
        if (0 != nStorageGetPartition( pxLoaderInfo->g_spinor_handle, guidString, &pxLoaderInfo->g_partition.ulStartAddr, &pxLoaderInfo->g_partition.ulSize) )
        {
            xStorageClose(pxLoaderInfo->g_spinor_handle);
            XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, guid = '%s', cannot get partition\n\r",
                          __func__, coreId, pxLoaderInfo->g_nImageId, guidString);
            xblFree(pxLoaderInfo);
            *pStatus = XBL_ERROR_NO_PARTITION;
            pxLoaderInfo = NULL;
            break;
        }
    }while (0);

   return pxLoaderInfo;
}

/**********************************************************
 * Close spinor handle and free memory used by pxLoaderInfo 
 *
 *
 * @param coreId [IN]
 *  core ID
 *
 * @param pxLoaderInfo [IN]
 *  Loader info
 *
 * @return void
 *
 **********************************************************/
static void xBootLoaderPostload(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    if (pxLoaderInfo != NULL)
    {
        if (pxLoaderInfo->g_spinor_handle != NULL)
        {
            xStorageClose(pxLoaderInfo->g_spinor_handle);
        }
        vElfloaderPutSecImageLoadlist(&pxLoaderInfo->load_List);
        xblFree(pxLoaderInfo->g_phdr_info.phdr);
        xblFree(pxLoaderInfo->g_hashSegment.hash);
        xblFree(pxLoaderInfo);
    }
}

/**********************************************************
 * Read Program Headers from storage device (NOR-Flash/DDR)
 *
 *
 * @param coreId [IN]
 *  core ID
 *
 * @param pxLoaderInfo [IN]
 *  Loader info
 *
 * @return int [OUT]
 *  XBL_OK_NOT_DONE/ERROR.
 * 
 **********************************************************/
static int nBootLoaderReadPhdrs(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    uint32 sz = (uint32)pxLoaderInfo->g_phdr_info.phnum * (uint32)pxLoaderInfo->g_phdr_info.phentsize;
    uint32 offset = pxLoaderInfo->g_partition.ulStartAddr + pxLoaderInfo->g_ehdr.e_phoff;

    if (0 != nStorageRead ( pxLoaderInfo->g_spinor_handle, offset, sz, (uint8 *)pxLoaderInfo->g_phdr_info.phdr))
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, read phdr\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR;
    }
    return XBL_OK_NOT_DONE;
}


/**********************************************************
 * Read Elf Header
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
int nElfLoaderReadElfHeader(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    boolean bRet;

    if (0 != nStorageRead ( pxLoaderInfo->g_spinor_handle, pxLoaderInfo->g_partition.ulStartAddr, sizeof(pxLoaderInfo->g_ehdr), (uint8 *)&pxLoaderInfo->g_ehdr ))                                  
    {
        XBL_LOG_ERROR("%s: Error in ELF header reading. core_id = %d, sec_img_id = 0x%x\n\r",
                      __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_READ_STORAGE;
    }
    
    return XBL_OK_NOT_DONE;
}

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
int nElfLoaderAuthElfHeader(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    boolean bRet = TRUE;
	
    bRet = bElfloaderAuthValidateElf ( coreId, pxLoaderInfo->g_nImageId, &pxLoaderInfo->g_ehdr );                                                                                                                                                                   

    if (FALSE == bRet)
    {
        XBL_LOG_ERROR("%s: Error in ELF header validation(no ELF or corrupted ELF header), core_id = %d, sec_img_id = 0x%x\n\r",
                    __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_ELF;
    }

    return XBL_OK_NOT_DONE;
}

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
int nElfLoaderLoadProgramHeader (uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    int ret = XBL_OK_NOT_DONE;

         /* get phdr size and num. Then malloc phdr mem */                                                                                                                                              
    pxLoaderInfo->g_phdr_info.phnum = elfUtilGetphnum ( &pxLoaderInfo->g_ehdr );                                                                                                             
    pxLoaderInfo->g_phdr_info.phentsize = elfUtilGetphentsize ( &pxLoaderInfo->g_ehdr );                                                                                                    

    if ( pxLoaderInfo->g_phdr_info.phnum == 0U || pxLoaderInfo->g_phdr_info.phentsize == 0U )
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, phdr is zero\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_PHDR;
    }
    pxLoaderInfo->g_phdr_info.memsize = (uint32)pxLoaderInfo->g_phdr_info.phnum * (uint32)pxLoaderInfo->g_phdr_info.phentsize;
    pxLoaderInfo->g_phdr_info.phdr = xblMalloc( pxLoaderInfo->g_phdr_info.memsize );
    if (NULL == pxLoaderInfo->g_phdr_info.phdr)
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, no mem for phdr\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_PHDR;
    }
    ret = nBootLoaderReadPhdrs(coreId, pxLoaderInfo);                                                                                                                                                                                                                                                       
    if ( XBL_OK_NOT_DONE != ret)
    {
        XBL_LOG_ERROR("%s: Error in PHDR reading. core_id = %d, sec_img_id = 0x%x\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_READ_STORAGE;
    }

    return ret;
}

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
int nElfLoaderLoadHashSegment (uint8_t coreId, BootLoaderInfoType *pxLoaderInfo)
{
    uint16 nHashIdx = 0;
    
   /* find hash segment */
    if (FALSE == bElfloaderAuthGetHashSegmentIdx(coreId, pxLoaderInfo->g_nImageId, pxLoaderInfo->g_phdr_info.phdr,                                                                          
                                                 pxLoaderInfo->g_phdr_info.phnum, &nHashIdx))
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, no hash index found\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_PHDR;
    }
    pxLoaderInfo->g_hashSegment.ulHashSize = elfUtilGetSegmentMemsz(&pxLoaderInfo->g_phdr_info.phdr[nHashIdx]);
    pxLoaderInfo->g_hashSegment.hash = xblMalloc(pxLoaderInfo->g_hashSegment.ulHashSize);
    if (NULL == pxLoaderInfo->g_hashSegment.hash)
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, no mem for hash\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_PHDR;
    }
    /* read hashsegment */
    uint32 ulHashBase = elfUtilGetSegmentOffset(&pxLoaderInfo->g_phdr_info.phdr[nHashIdx]);                                                                                                  
    if (ulHashBase == 0U)
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, cannot get segment offset\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_INVALID_PHDR;
    }
    ulHashBase += pxLoaderInfo->g_partition.ulStartAddr;
    if (0 != nStorageRead ( pxLoaderInfo->g_spinor_handle, ulHashBase, pxLoaderInfo->g_hashSegment.ulHashSize, (uint8 *)pxLoaderInfo->g_hashSegment.hash ))
    {
        XBL_LOG_ERROR("%s: Error in hash table reading. core_id = %d, sec_img_id = 0x%x\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_READ_STORAGE;
    }

    return XBL_OK_NOT_DONE;
    
}

int nElfLoaderGetDigestHash (BootLoaderInfoType *pxLoaderInfo, uint8_t *hashContainer, uint32_t containerSize)
{
    if (NULL == pxLoaderInfo->g_hashSegment.hash)
    {
        XBL_LOG_ERROR("%s: Error, image_id: %d, hash segment is Null\n\r", __func__, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_DIGEST_HASH;
    }
    
    /* Get the hash digest for the hash segment */
    if(!(elfLoaderAuthGetHashDigest(hashContainer, &pxLoaderInfo->g_hashSegment, containerSize)))
    {
        XBL_LOG_ERROR("%s: Error, image_id: %d, hash digest calculation failed\n\r", __func__, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_DIGEST_HASH;
    }
    
    return XBL_SUCCESS;
}

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
int nElfLoaderAllocateImageCtxt(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo)
{
    bool  bRet = bElfloaderAuthAllocateImgCtx(pxLoaderInfo->g_nImageId);                                                                                                                             
    if (FALSE == bRet)
    {
        XBL_LOG_ERROR("%s: Error in allocating image context. core_id = %d, sec_img_id = 0x%x\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        return XBL_ERROR_NO_MEM;
    }

    return XBL_OK_NOT_DONE;
}

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
int nElfLoaderVerify_Meta_Data(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo, sec_img_auth_whitelist_area_param_t *whitelistParam)
{
  bool bRet = TRUE;

    bRet = bElfloaderAuthSecImgVerifyMeta(coreId, pxLoaderInfo, whitelistParam);
    if (FALSE == bRet)
    {
        XBL_LOG_ERROR("%s: Error in signature verification. core_id = %d, sec_img_id = 0x%x\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
        bElfloaderAuthFreeImgCtx(pxLoaderInfo->g_nImageId);
        return XBL_ERROR_AUTH;
    }

    return XBL_OK_NOT_DONE;
}

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
int nElfLoaderLoadPhdrSegments(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo)
{
    uint32 ulRamVAddr;
    uint32 offset;
    uint32 memsz;
    uint32 filesz;
    boolean bAuthEnabled;
    pxLoaderInfo->count_loadable_segments = 0;
    pxLoaderInfo->count_loaded_segments   = 0;

    /* Need to call sec auth lib always so that we do not need to check
     * if sec boot is enabled here
     */

    /* load each loadable segment */
    for (uint16 i = 0; i < pxLoaderInfo->g_phdr_info.phnum; i++)                                                                                                                                
    {
        if (FALSE == bElfloaderAuthIsSegmentLoadable( coreId, &pxLoaderInfo->g_ehdr, &pxLoaderInfo->g_phdr_info.phdr[i]))
        {
            continue;
        }
        /* load this segment */
        ulRamVAddr = elfUtilGetSegmentDestVaddr ( &pxLoaderInfo->g_phdr_info.phdr[i] );
        offset     = elfUtilGetSegmentOffset ( &pxLoaderInfo->g_phdr_info.phdr[i] ) + pxLoaderInfo->g_partition.ulStartAddr;
        memsz      = elfUtilGetSegmentMemsz ( &pxLoaderInfo->g_phdr_info.phdr[i] );
        filesz     = elfUtilGetSegmentFilesz ( &pxLoaderInfo->g_phdr_info.phdr[i] );
        if ( memsz > 0U )
        {  
            pxLoaderInfo->count_loadable_segments++;
        }

        if ( NULL != pxLoaderInfo->load_List )
        {
            boolean bStatus = FALSE;
            bStatus = bElfloaderCheckLoadList(ulRamVAddr, memsz, pxLoaderInfo->load_List);
            if ( TRUE == pxLoaderInfo->bBlackList && TRUE == bStatus)
            {
                /* Load list is black list and this segment
                 * falls into the load_list so skip loading
                 * this segment.
                 */
                 continue;
            }
            else if (FALSE == pxLoaderInfo->bBlackList && FALSE == bStatus)
            {
                /* Load list is white list list and this segment
                 * does not fall into the load_list so skip loading
                 * this segment.
                 */
                 continue;
            }
            else
            {
                //  do nothing
            }
        }
        if ( memsz > 0U )
        {

            if ( filesz > 0U )
            {
                if ( 0 != nStorageRead ( pxLoaderInfo->g_spinor_handle, offset, filesz, (uint8 *)ulRamVAddr ))
                {
                    XBL_LOG_ERROR("%s: Error in segment reading. core_id = %d, sec_img_id = 0x%x\n\r", __func__, coreId, pxLoaderInfo->g_nImageId);
                    bElfloaderAuthFreeImgCtx(pxLoaderInfo->g_nImageId);
                    return XBL_ERROR;
                }
            }
            if ( memsz > filesz )
            {
                // zero the ZI region
                ulRamVAddr += filesz;
                (void)memset ( (uint8_t *)ulRamVAddr, 0, (memsz - filesz) );
            }
            pxLoaderInfo->count_loaded_segments++;
            // Storage driver already did cache flush and invalidate. No need to do again. 
        }
    }

    return XBL_OK_NOT_DONE;

}

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
int nElfLoaderVerifySwiv(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo)
{
    /* SAIL SW1/2/3 SWIV check */
    if((pxLoaderInfo->g_nImageId == (uint16)SECBOOT_SAIL_SW1_SW_TYPE) || (pxLoaderInfo->g_nImageId == (uint16)SECBOOT_SAIL_SW2_SW_TYPE) || (pxLoaderInfo->g_nImageId == (uint16)SECBOOT_SAIL_SW3_SW_TYPE))                  
    {
        int32_t swiv_status = xbl_sec_swiv(pxLoaderInfo->g_spinor_handle,
                                           pxLoaderInfo->g_nImageId,
                                           (Elf_Class)pxLoaderInfo->g_ehdr.e_ident[ELFINFO_CLASS_INDEX],
                                           pxLoaderInfo->g_phdr_info.phdr,
                                           pxLoaderInfo->g_ehdr.e_phnum,
                                           pxLoaderInfo->g_partition.ulStartAddr);
        if(swiv_status == SWIV_SUCCESS)
        {
            XBL_LOG_INFO("%s: SWIV - Image Verification Success for SW Image = 0x%x \n\r", __func__, pxLoaderInfo->g_nImageId);
        }
        else
        {
            XBL_LOG_ERROR("%s: SWIV - Image Verification failed for core = %d, sec_img_id = 0x%x, ret = %d \n\r", __func__, coreId, pxLoaderInfo->g_nImageId, swiv_status);
            bElfloaderAuthFreeImgCtx(pxLoaderInfo->g_nImageId);
            return XBL_ERROR;
        }
    }

    return XBL_OK_NOT_DONE;
}

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
 * @param pulEntryPointVaddr [IN]
 *  entry point virtual address
 * 
 * @return  int [OUT]
 *  XBL_SUCCESS/ERROR
 * 
**********************************************************/
int nElfLoaderSecureHashVerify(uint8_t coreId, BootLoaderInfoType * pxLoaderInfo)
{
    bool bRet = TRUE;

    bRet = bElfloaderAuthCheckSecImgAuth ( coreId, pxLoaderInfo );
    if (TRUE == bRet)
    {
        bElfloaderAuthFreeImgCtx(pxLoaderInfo->g_nImageId);
        return XBL_SUCCESS;
    }
    else
    {
        XBL_LOG_ERROR("%s: Error in segment hash verification, core_id = %d, sec_img_id = 0x%x\n\r",
                      __func__, coreId, pxLoaderInfo->g_nImageId);
        bElfloaderAuthFreeImgCtx(pxLoaderInfo->g_nImageId);
        return XBL_ERROR_HASH;
    }

}

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
int nElfLoaderPollState( uint8_t coreId, BootLoaderInfoType *pxLoaderInfo, uint32_t *pulEntryPoint)
{

    int ret ;
    /* Check for valid coreID */
    if ( coreId < 0U || coreId > 3U )
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, invalid core_id \n\r", __func__, coreId);
        ret = XBL_ERROR_INVALID_PARAM;
        //goto load_elf_end;
        return ret; //expect caller to do error fatal

    }

    /* If pxLoaderInfo is NULL then return -1 */
    if ( NULL == pxLoaderInfo )
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, null pointer\n\r", __func__, coreId);
        ret = XBL_ERROR_NULL_POINTER;
        return ret;
    }                                                                                           
    
    /* Set entry point to invalid address such as 0xdeadbeef */
    *pulEntryPoint = 0xdeadbeefU;

    ret = nElfLoaderLoad_State(coreId, pxLoaderInfo, pulEntryPoint, pxLoaderInfo->load_List);

    /* Check if state machine failed */
    if (XBL_SUCCESS != ret && XBL_OK_NOT_DONE != ret)
    {
            XBL_LOG_ERROR("%s: Error in ELF loading, core_id = %d, sec_image_id = %d, status = %d\n\r",
            __func__, coreId, pxLoaderInfo->g_nImageId, ret);
    }
 
    /* Close spinor handle, free memory */
    load_elf_end:

        if (ret != XBL_OK_NOT_DONE && pxLoaderInfo != NULL)
        {
            /* Loadlist is freed in the post load func */
            xBootLoaderPostload (coreId, pxLoaderInfo);
        }
        return ret;

}

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
int nElfloaderLoad_Open( uint8_t coreId,
                         const char *guidString,
                         xbl_mem_loadlist_param_t* load_List,
                         boolean bBlackList,
                         BootLoaderInfoType ** pxLoaderInfo_ptr_addr)
{
    int ret                          = XBL_OK_NOT_DONE;
    boolean res                      = FALSE;
    BootLoaderInfoType *pxLoaderInfo = NULL;

	/* Check for valid coreID */
	if ( coreId < 0U || coreId > 3U )
	{
			XBL_LOG_ERROR("%s: Error, core_id = %d, invalid core_id \n\r", __func__, coreId);
			ret = XBL_ERROR_INVALID_PARAM;
			return ret;
	}

  /* If the parameters are NULL return XBL_ERROR_NULL_POINTER */
    if ( NULL == guidString ||
         NULL == pxLoaderInfo_ptr_addr ||
         *pxLoaderInfo_ptr_addr != NULL )
    {
        XBL_LOG_ERROR("%s: Error, core_id = %d, null pointer\n\r", __func__, coreId);
        ret = XBL_ERROR_NULL_POINTER;
        return ret;
    }

    /**
     *  Get imageId corresponding to GuidString.
     *  Get starting address and size of the partition
     */
    pxLoaderInfo = nBootLoaderPreload ( coreId, guidString, &ret);
    if ( NULL == pxLoaderInfo )
    {
        XBL_LOG_ERROR("%s: Error in pre loading, core_id = %d, ret = %d\n\r", __func__, coreId, ret);
        return ret;
    }

    pxLoaderInfo->next_state = PRE_LOADING;
    /* Disable on-demand loading authentication until bug is fixed */
    
    /* If whitelist by user is NULL pointer 
    *   Case 1: whitelist == NULL
    *           Boot the entire software
    *           First entry in array of global struct that contains the starting addess
                    and end address of the (entire) software pointed out by guid
    *   Case 2: whitelist != NULL
    *           Check the user whitelist and the global whitelist. 
    *           Check if the user whitelist does not violate the boundry condition.
    */
    if (load_List != NULL)
    {
        ret = xElfloaderGetSecImageLoadlist(load_List, &pxLoaderInfo->load_List);
        if (XBL_SUCCESS != ret)
        {
            XBL_LOG_ERROR("%s: Error in whitelist/Blacklist conversion, core_id = %d\n\r",
                          __func__, coreId);
            goto end;
        }
    }
    pxLoaderInfo->bBlackList = bBlackList;
    pxLoaderInfo->next_state = LOAD_ELF_HDR;
    ret = XBL_OK_NOT_DONE;
end:
    if (ret == XBL_OK_NOT_DONE)
    {
        *pxLoaderInfo_ptr_addr = pxLoaderInfo;
    }
    else
    {
        xBootLoaderPostload (coreId, pxLoaderInfo);
    }
    return ret;
}

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
int nElfLoaderLoad_State(uint8_t coreId, BootLoaderInfoType *pxLoaderInfo,
                         uint32_t *pulEntryPointVaddr,
                         sec_img_auth_whitelist_area_param_t *whitelistParam)
{
    int ret = XBL_SUCCESS;

    switch (pxLoaderInfo->next_state)
    {

    case LOAD_ELF_HDR :
        ret = nElfLoaderReadElfHeader(coreId, pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {    
            pxLoaderInfo->next_state = AUTH_ELF_HDR;
        }
        break;
    
    case AUTH_ELF_HDR:
        ret = nElfLoaderAuthElfHeader(coreId, pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {    
            pxLoaderInfo->next_state = PROGRAM_HDR;
        }
        break;
    
    case PROGRAM_HDR: 
        ret = nElfLoaderLoadProgramHeader(coreId,pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {    
            pxLoaderInfo->next_state = HASH_SEGMENT;
        }
        break;

    case HASH_SEGMENT:
        ret = nElfLoaderLoadHashSegment(coreId,pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {    
            pxLoaderInfo->next_state = ALLOCATE_IMG_CTXT;
        }
        break;
    
    case ALLOCATE_IMG_CTXT:
        ret = nElfLoaderAllocateImageCtxt(coreId,pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {    
            pxLoaderInfo->next_state = VERIFY_META;
        }
        break;

    case VERIFY_META:
        ret = nElfLoaderVerify_Meta_Data(coreId, pxLoaderInfo, whitelistParam);
        if (ret == XBL_OK_NOT_DONE)
        {
            pxLoaderInfo->next_state = LOAD_PHDR_SEG;
        }
        break;

    case LOAD_PHDR_SEG:
        ret = nElfLoaderLoadPhdrSegments(coreId, pxLoaderInfo);
        if (ret == XBL_OK_NOT_DONE)
        {
            pxLoaderInfo->next_state = VERIFY_SWIV;
        }
        break;

    case VERIFY_SWIV:
        ret = XBL_OK_NOT_DONE;        
        ret = nElfLoaderVerifySwiv(coreId,pxLoaderInfo);
        
        /* Change state if authentication skipped or authentication completed succesfully */
        if (ret == XBL_OK_NOT_DONE)
        {
            pxLoaderInfo->next_state = SECURE_HASH_VERIFY;
        }
        break;
    
    case SECURE_HASH_VERIFY: 
        
        /* If Authentication is enabled, do hash verification */
         ret = nElfLoaderSecureHashVerify(coreId, pxLoaderInfo);
        
        /* Image Loading Complete */
        if (ret == XBL_SUCCESS)
        {
            pxLoaderInfo->next_state = DONE_LOAD;
            *pulEntryPointVaddr = elfUtilGetEntryPointVaddr ( &pxLoaderInfo->g_ehdr );
        }
        break;
    
    default:
        ret = XBL_ERROR;
        break;

    }

    return ret;
}

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
int nBootLoaderErase(uint8_t coreId, const char *guidString)
{
    int status = XBL_ERROR_STORAGE_DRIVER;
    uint32_t ulStartAddr;
    uint32_t ulSize;
    uint32_t block_count;
    uint32_t pages_per_block;
    uint32_t page_size_bytes;
    uint32_t block_sz;
    void *pHandle = NULL;
    
    do
    {
        if (XBL_SUCCESS != nStorageOpen(&pHandle))
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, spinor open failed\n\r",
                          __func__, coreId);
            break;
        }
        if (0 != nStorageGetMemInfo ( pHandle, &block_count, &pages_per_block, &page_size_bytes ))
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, guid = '%s', cannot get mem info\n\r",
                          __func__, coreId, guidString);
            break;

        }
        block_sz = pages_per_block * page_size_bytes;
        if (block_sz == 0U)
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, pages_per_block = %d, page_sz = %d, guid = '%s', invalid block size from mem info\n\r",
                          __func__, coreId, pages_per_block, page_size_bytes, guidString);
            break;
        }
        if (0 != nStorageGetPartition( pHandle, guidString, &ulStartAddr, &ulSize))
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, guid = '%s', cannot get partition\n\r",
                          __func__, coreId, guidString);
            break;
        }
        ulStartAddr /= block_sz;
        ulSize /= block_sz;
        if ( 0 != nStorageErase ( pHandle, ulStartAddr, ulSize))
        {
             XBL_LOG_ERROR("%s: Error, core_id = %d, guid = '%s', erase error\n\r",
                           __func__, coreId, guidString);
            break;
        }
        status = XBL_SUCCESS;
    }while (0);
    if ( pHandle != NULL )
    {
        xStorageClose(pHandle);
    }
   return status;
}

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
boolean bBootLoaderCheckElfHeader(uint8_t coreId, const char *guidString)
{
    Elf32_Ehdr ehdr;
    boolean status = FALSE;
    uint32_t ulStartAddr;
    uint32_t ulSize;
    void *pHandle = NULL;
    do
    {
        if (XBL_SUCCESS != nStorageOpen(&pHandle))
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, spinor open failed\n\r",
                          __func__, coreId);
            break;
        }
        if ( 0 != nStorageGetPartition( pHandle, guidString, &ulStartAddr, &ulSize ) )
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, guid = '%s', cannot get partition\n\r",
                          __func__, coreId, guidString);
            break;
        }
        if (0 != nStorageRead ( pHandle, ulStartAddr, sizeof(ehdr), (uint8 *)&ehdr ))
        {
            XBL_LOG_ERROR("%s: Error in ELF header reading. core_id = %d, guid=%s\n\r",
                          __func__, coreId, guidString);
            break;
        }
        status = elfUtilVerifyElfHeader(&ehdr);
    }while (0);
    if ( pHandle != NULL )
    {
        xStorageClose(pHandle);
    }
    return status;
}

