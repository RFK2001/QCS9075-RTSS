/**************************************************************************************************
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : xbl_tests.c
    Component Name     : xbl
    Description        : xbl driver interface test file
    $Header:
    $DateTime: 
    $Author:
=================================================================================================*/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "types.h"
#include "debug_log.h"
#include "tests.h"
#include "sailel1_xbl_api.h"
#include "xbl_hvc_event.h"
#include "sailel1_xbl_syscall.h"

/* Check if hvc paramId is equal to rsp->data[0]  */
static TESTerrorType_e eXblVerifyInvalidEvent( void )
{
    TESTerrorType_e status = MODULE_TEST_PASSED;
    XblHvcEventType event;
    xbl_boot_params_t boot_param;
    int ret = XBL_SUCCESS;

    memset(&boot_param, 0, sizeof(boot_param) );  
    memset(&event, 0, sizeof(XblHvcEventType));
    XblEl1EventIdType eventId = XBL_EL1_EVENT_MAX_NUM;
    ret = sailEl1XblSysCall(eventId, &event);
    if (ret ==  XBL_ERROR_INVALID_PARAM)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: PASSED\n\r", __func__);
    }
    else
    {
        status = MODULE_TEST_FAILED;
        DEBUG_LOG(SAIL_ERROR, "%s: Error, ret = %d\n\r", __func__, ret);
    }
    return status;
}

static TESTerrorType_e eXblVerifyOnDemandLoading( void )
{
    TESTerrorType_e status = MODULE_TEST_PASSED;
    int ret = XBL_OK_NOT_DONE;
    uint32_t ulEntryPoint = 0UL;
    xbl_mem_Loadlist_area_t area[3];
    xbl_boot_params_t boot_param;
    xbl_mem_loadlist_param_t loadlist;

    memset ( &boot_param, 0, sizeof(boot_param) );
    memset ( &loadlist, 0, sizeof(loadlist) );
    
        
    loadlist.count = 3;
    loadlist.area = &area[0];
    area[0].start = 0x20000000U; /* DDR low addr */
    area[0].end   = 0x2FC00000U; /* DDR high addr. So all DDR are fall in my load list */
    area[1].start = 0x2000000U;  /* TCM low addr */
    area[1].end   = 0x3700000U;  /* TCM high addr. So all TCM are fall in my load list */
    area[2].start = 0x08000000U; /* SRAM low addr */
    area[2].end   = 0x08300000U; /* SRAM high addr. So all SRAM are fall in my load list */

    boot_param.image_id = XBL_IMAGE_ID_SW1;
    boot_param.loadlist = &loadlist;   

    ret = sailEl1XblLoaderOpen(&boot_param);

    if (ret !=  XBL_OK_NOT_DONE)
    {
        status = MODULE_TEST_FAILED;
        DEBUG_LOG(SAIL_ERROR, "%s: Error in sailEl1XblLoaderOpen, ret = %d\n\r", __func__, ret);
    }
    else
    {       
        
        while( ret == XBL_OK_NOT_DONE)
        {
            ret = sailEl1XblLoaderPollState(&ulEntryPoint);
        }

        if (ret ==  XBL_SUCCESS)
        {
            DEBUG_LOG(SAIL_ERROR, "%s PASSED : entrypoint = 0x%x \n\r", __func__, ulEntryPoint);
        }

        else
        {
            status = MODULE_TEST_FAILED;
            DEBUG_LOG(SAIL_ERROR, "%s: Error in sailEl1XblLoaderOpen, ret = %d\n\r", __func__, ret);
        }
    }
    return status;
}

/* Verify El1 hvc call to GetBootInfo trap  */
static TESTerrorType_e eXblVerifyxBootInfo( void )
{
    TESTerrorType_e status = MODULE_TEST_PASSED;
    int ret;
    XBLBootInfoType xBootInfo[XBL_IMAGE_ID_MAX]={0};
    ret = sailEl1XblGetBootInfo(xBootInfo,XBL_IMAGE_ID_MAX);

    if (ret != XBL_SUCCESS)
    {
        status = MODULE_TEST_FAILED;
        DEBUG_LOG(SAIL_ERROR, "%s: Error, ret = %d\n\r", __func__, ret);
    }
    
    else
    {
        DEBUG_LOG(SAIL_ERROR, "%s: PASSED\n\r", __func__);
    }
    return status;
}


static TESTerrorType_e eXblVerifyxImgGuid( void )
{
    TESTerrorType_e status = MODULE_TEST_PASSED;
    char imgGuid[36+1] = "" ;      // dummy GUID
    uint32_t flashgpt_id = XBL_GPT_TABLE_PRIMARY ;
    uint32_t partition = XBL_PARTITION_A ;
    const char * ptr  = "SAIL_SW1" ;

    int ret = sailEl1XblGetImgGUID(ptr, partition, flashgpt_id, imgGuid);

    if (ret != XBL_SUCCESS)
    {
        status = MODULE_TEST_FAILED;
        DEBUG_LOG(SAIL_ERROR, "%s: Error, ret = %d\n\r", __func__, ret);
    }
    
    else
    {
        DEBUG_LOG(SAIL_ERROR, "%s: PASSED\n\r", __func__);
    }
    return status;
}

TESTerrorType_e eXBLTestWrapper( void )
{
    TESTerrorType_e status = MODULE_TEST_FAILED;
    uint8* find = APPL_SAIL_Shell_gettoken(NULL);

    if (APPL_SAIL_Shell_stricmp("invalid_event",(char*)find)) 
    {
        status = eXblVerifyInvalidEvent( );
    }
    else if (APPL_SAIL_Shell_stricmp("boot_info",(char*)find)) 
    {
        status = eXblVerifyxBootInfo();
    }
    else if (APPL_SAIL_Shell_stricmp("img_guid",(char*)find)) 
    {
        status = eXblVerifyxImgGuid();
    }
    else if (APPL_SAIL_Shell_stricmp("on_demand",(char*)find)) 
    {
        status = eXblVerifyOnDemandLoading();
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR, "XBL INVALID TEST COMMAND \n\r");
    }
    return status;
}

