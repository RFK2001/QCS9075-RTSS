/*
===========================================================================
*/
/**
    @file  elfloader_auth.c
    @brief sec_auth integration implementation

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/elfloader/elfloader_auth.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "elf_header.h"
#include "elf_util.h"
#include "elfloader_def.h"
#include "elfloader_auth.h"
#include "sail_sec_img_info.h"
#include "sail_sec_apis.h"
#include "sailbsp_mutex.h"
#include "xbl_mem.h"
#include "xbl_diag.h"
#include "chipinfo.h"
#include "uclib_env.h"
#include "uclib_hash.h"
#include "uclib_err.h"

static mutex_t g_xAuthAllocMutex;

boolean vElfAuthInit(void *pbl_shared_info)
{
  (void)mutex_init(&g_xAuthAllocMutex);
  return sail_sec_init(pbl_shared_info);
}

boolean bElfloaderAuthAllocateImgCtx(uint32_t sec_img_id)
{
  mutex_lock(&g_xAuthAllocMutex);

  /* Check if image context already allocated for this image (possible synchronization failure) */
  sail_sec_img_ctx_t *p_img_ctx = (sail_sec_img_ctx_t *)sail_sec_img_info_get_img_ctx(sec_img_id);
  if (NULL != p_img_ctx)
  {
    mutex_unlock(&g_xAuthAllocMutex);
    return FALSE;
  }

  /* Allocate image context */
  p_img_ctx = (sail_sec_img_ctx_t*)xblMalloc(sizeof(sail_sec_img_ctx_t));
  if (NULL == p_img_ctx)
  {
    mutex_unlock(&g_xAuthAllocMutex);
    return FALSE;
  }
  (void)memset(p_img_ctx, 0, sizeof(sail_sec_img_ctx_t));
  
  /* Save image context */
  sail_sec_img_info_save_img_ctx(sec_img_id, (uint32_t)p_img_ctx);
  
  mutex_unlock(&g_xAuthAllocMutex);
  
  return TRUE;
}

void bElfloaderAuthFreeImgCtx(uint32_t sec_img_id)
{
  mutex_lock(&g_xAuthAllocMutex);
  
  /* Get image context */
  sail_sec_img_ctx_t *p_img_ctx = (sail_sec_img_ctx_t *)sail_sec_img_info_get_img_ctx(sec_img_id);
  if (NULL != p_img_ctx)
  {
    /* Delete image context */
    sail_sec_img_info_delete_img_ctx(sec_img_id);
    xblFree(p_img_ctx);
  }
  
  mutex_unlock(&g_xAuthAllocMutex);
}

boolean bElfloaderAuthIsAuthEnabled(void)
{
    return sail_sec_secboot_hw_is_auth_enabled(SECBOOT_HW_APPS_CODE_SEGMENT);
}

boolean bElfloaderAuthCheckSecImgAuth( uint8_t coreId, BootLoaderInfoType *pInfo)
{
    sec_img_auth_error_type ret = SEC_IMG_AUTH_SUCCESS;
       
    ret = sail_sec_img_auth_hash_elf_segments ( pInfo->g_nImageId );
    if (SEC_IMG_AUTH_SUCCESS != ret)
    {
        XBL_LOG_ERROR("%s: Error in calling sail_sec_img_auth_hash_elf_segments. core_id = %d, sec_imng_id = 0x%x, ret = 0x%x\n\r",
                      __func__, coreId, pInfo->g_nImageId, ret);
    }

    return ret == SEC_IMG_AUTH_SUCCESS;
}

static void vDumpElfHeader(Elf32_Ehdr *ehdr)
{
    XBL_LOG_INFO("%s: %d %d %d"
                 "entry=0x%x, phoff=0x%x, eflags=0x%x, ehsize=0x%x, phentsize=0x%x, phnum=0x%x\n\r",
                 __func__, ehdr->e_ident[0],  ehdr->e_ident[1],  ehdr->e_ident[2],
                 ehdr->e_entry, ehdr->e_phoff, ehdr->e_flags, ehdr->e_ehsize, ehdr->e_phentsize, ehdr->e_phnum);
}
boolean bElfloaderAuthValidateElf(uint8_t coreId, uint16_t secImgId, Elf32_Ehdr *ehdr)
{
    sec_img_auth_error_type ret = SEC_IMG_AUTH_SUCCESS;
    if (ehdr == NULL)
    {
        return false;
    }
 
    ret = sail_sec_img_auth_validate_elf ( ELF_CLASS_32, (const void*)ehdr, sizeof(Elf32_Ehdr) );
    if (SEC_IMG_AUTH_SUCCESS != ret)
    {
        XBL_LOG_ERROR("%s: error in calling sail_sec_img_auth_validate_elf, core_id = %d, ret = 0x%x, sec_img_id = 0x%x\n\r",
                      __func__, coreId, ret, secImgId);
        vDumpElfHeader(ehdr);
    }

    return ret == SEC_IMG_AUTH_SUCCESS;
}

boolean bElfloaderAuthGetHashSegmentIdx(uint8_t coreId, uint16_t secImgId, Elf32_Phdr *phdr, uint16 phnum, uint16 *pnHashIdx)
{
    uint32 phdr_flags;

    if (NULL == phdr || NULL == pnHashIdx )
    {
        return FALSE;
    }

    *pnHashIdx = 0;
    for(uint16 index = 0; index < phnum; index++)
    {
        phdr_flags = elfUtilGetProgramHeaderFlags(&phdr[index]);

        /* Check for the hash segment program header to parse QC header */
        if(MI_PBT_SEGMENT_TYPE_VALUE(phdr_flags) == MI_PBT_HASH_SEGMENT)
        {
            *pnHashIdx = index;
            return TRUE;
        }
    }
    return FALSE;
}

boolean elfLoaderAuthGetHashDigest(uint8_t *doubleHashContainer, hashSegmentType* hashSegment, uint32_t doubleHashSize)
{
    int retVal;
    
    //Get the environment
    env_t *env = ucenv_get_env();
    
    //Acquire the handle using the env
    UCLIB_MD_HANDLE h = uclib_hash_new(env);

    if((doubleHashContainer != NULL) && (hashSegment != NULL) && (doubleHashSize !=0) && (h != NULL))
    {
        UCLIB_ENGINE_TYPE eng = UCLIB_CE_BAM;
        
        retVal = uclib_hash_init(h, UCLIB_SHA2_384, eng);
        if (UCLIB_SUCCESS != retVal)
        {
            (void)uclib_hash_free(h);
            XBL_LOG_ERROR("%s: Error in hash init, ret = 0x%x\n\r", __func__, retVal);
            goto end;
        }
        
        retVal = uclib_hash_update(h, hashSegment->hash, hashSegment->ulHashSize);
        if (UCLIB_SUCCESS != retVal)
        {
            (void)uclib_hash_free(h);
            XBL_LOG_ERROR("%s: Error in hash digest calculation, ret = 0x%x\n\r", __func__, retVal);
            goto end;
        }

        retVal = uclib_hash_final(h, doubleHashContainer, doubleHashSize);
        if (UCLIB_SUCCESS != retVal)
        {
            (void)uclib_hash_free(h);
            XBL_LOG_ERROR("%s: Error in hash digest calculation, ret = 0x%x\n\r", __func__, retVal);
            goto end;
        }
        (void)uclib_hash_free(h);
        return TRUE;
    }
    end:
        return FALSE;
}

boolean bElfloaderAuthSecImgVerifyMeta(uint8_t coreId, BootLoaderInfoType *pInfo, sec_img_auth_whitelist_area_param_t *whitelist)
{
    sec_img_auth_error_type ret = SEC_IMG_AUTH_SUCCESS;


    if (pInfo->load_List != NULL)
    {
        /* Pass the whitelist to sec auth lib */
        ret = sail_sec_img_auth_verify_metadata ( pInfo->g_nImageId, &pInfo->g_ehdr, pInfo->g_phdr_info.phdr, pInfo->g_hashSegment.hash,
                                                whitelist->count, whitelist->area, sizeof(sec_img_auth_whitelist_area_t));
    }
    else 
    {
        /* Pass the whitelist to sec auth lib */
        ret = sail_sec_img_auth_verify_metadata ( pInfo->g_nImageId, &pInfo->g_ehdr, pInfo->g_phdr_info.phdr, pInfo->g_hashSegment.hash,
                                                0, NULL, sizeof(sec_img_auth_whitelist_area_t));
    }
    if (SEC_IMG_AUTH_SUCCESS != ret)
    {
        XBL_LOG_ERROR("%s: Error in calling sail_sec_img_auth_verify_metadata. core_id = %d, sec_img_id = 0x%x, ret = 0x%x\n\r",
                      __func__, coreId, pInfo->g_nImageId, ret);
    }

end:
    return ret == SEC_IMG_AUTH_SUCCESS;
}

boolean bElfloaderAuthIsSegmentLoadable(uint8_t coreId, Elf32_Ehdr *pehdr, Elf32_Phdr *phdr)
{
    uint32 phdr_type;
    uint32 phdr_flags;
    boolean loadable = FALSE;
    
    phdr_type  = phdr->p_type;
    phdr_flags = phdr->p_flags;

    loadable = (phdr_type == MI_PBT_ELF_PT_LOAD  &&
                MI_PBT_PAGE_MODE_VALUE(phdr_flags) == MI_PBT_NON_PAGED_SEGMENT  &&
                MI_PBT_ACCESS_TYPE_VALUE(phdr_flags) != MI_PBT_NOTUSED_SEGMENT  &&
                /* hash segment to be loaded explicitly to fixed buffer */
                MI_PBT_SEGMENT_TYPE_VALUE(phdr_flags) != MI_PBT_HASH_SEGMENT   &&
                MI_PBT_ACCESS_TYPE_VALUE(phdr_flags) != MI_PBT_SHARED_SEGMENT);
    return loadable;
}


