/*
===========================================================================
*/
/**
    @file  spinor_el1_tests.c
    @brief Testing for the spinor EL1 driver functions

*/
/*
    ===========================================================================

    Copyright (c) 2021-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.TestFolderReStructure/tests/sailsw1/spinor_el1_tests.c#1 $
    $DateTime: 2024/01/25 22:37:00 $
    $Author: asuthar $

    ===========================================================================
*/
#include <string.h>
#include "tests.h"
#include "debug_log.h"
#include "common_functions.h"
#include "gpt_partition1.h"
#include "FreeRTOSOsal.h"
#include "err_fatal.h"
#include "spinor_tests.h"

#define WRITE_PATTERN      0x34

#define spinorEL1TOTALTESTCASES 22U

#define SPINOR_EL1_TEST
#ifndef SPINOR_EL1_TEST

TEST_FUNC TESTerrorType_e TestOSPINOR_El1_Wrapper(void)
{
  return MODULE_TEST_FAILED;
}

#else

#include "spinor_el1_api.h"

/* SAIL Updater Core Context */
typedef struct
{
    spinor_handle_t norHandle;      /** SPINOR device handle */
    spinorMemInfoType memInfo;      /** SPINOR device Info */
    uint8_t* pGPTWorkBuf;           /** Pointer to the workbuffer */
    gptHeader_t PrimaryGPTHdr;      /** Primary GPT Header */
    gptHeader_t SecondaryGPTHdr;    /** Secondary GPT Header */
    gptEntryRead gptReadCb;         /** Callback for the GPT read */
}sailUpdaterCoreCtx_t;

TEST_DATA spinorMemInfoType el1_nor_info={0};
TEST_DATA uint8 el1_buff[4096],el1_buff_copy[4096];
TEST_DATA spinorSectorMapInfoType el1_sectorMapInfo = {0};

/* Async tests */
#ifdef SPINOR_ASYNC_TEST
/* shared between the UART test task function to queue an item to the SPINOR test task */
typedef enum
{
    SPINOR_EL1_TEST_READ = 0,
    SPINOR_EL1_TEST_WRITE,
    SPINOR_EL1_TEST_ERASE,
}spinorEl1TestOpType;

/* SPINOR EL1 Operation Parameters */
typedef struct
{
    spinorEl1TestOpType opType;
    uint32 byte_offset;
    uint32 byte_count;
    void* buffer;
}spinorEl1TestOpParamType;

/* Item type to queue to the SPINOR test task from UART test function */
typedef struct
{
    spinor_handle_t handle;                         /* SPINOR client handle*/
    spinorEl1TestOpParamType opParam;               /* SPINOR client operation parameters */
}QItemforTestTaskType;

/* Notify Item type from the SPINOR test task to the UART  test function */
typedef struct
{
    SPINOR_STATUS status;                          /* Pointer to update the operation status */
}NotifyQItemfromTestTaskType;

/* The notify item from callback to SPINOR test task */
typedef struct
{
    SPINOR_STATUS status;                          /* Pointer to update the operation status */
    uint8 trans_ID;                                /* Variable to hold transaction ID */
}NotifyQItemfromTestCBType;


/* Task Init Macros */
#define SPINOR_TEST_TASK_STK_SZ            ( 4096 )

/* Queue Init Macros */
#define SPINOR_TEST_Q_LEN                  ( 1 )
#define SPINOR_TEST_Q_ITEM_SZ              ( sizeof(QItemforTestTaskType) )
#define SPINOR_TEST_Q_BUF_SZ               ( SPINOR_TEST_Q_LEN * SPINOR_TEST_Q_ITEM_SZ )

#define SPINOR_TEST_NOTIFY_Q_LEN           ( 1 )
#define SPINOR_TEST_NOTIFY_Q_ITEM_SZ       ( sizeof(NotifyQItemfromTestCBType) )
#define SPINOR_TEST_NOTIFY_Q_BUF_SZ        ( SPINOR_TEST_NOTIFY_Q_LEN * SPINOR_TEST_NOTIFY_Q_ITEM_SZ )

#define SPINOR_UART_NOTIFY_Q_LEN           ( 1 )
#define SPINOR_UART_NOTIFY_Q_ITEM_SZ       ( sizeof(NotifyQItemfromTestTaskType) )
#define SPINOR_UART_NOTIFY_Q_BUF_SZ        ( SPINOR_UART_NOTIFY_Q_LEN * SPINOR_UART_NOTIFY_Q_ITEM_SZ )

/* Task Init Definitions : Higher Priority than SPINOR task */
static StaticTask_t xSpinorTestTskHiTCB = { 0 };
static StackType_t xSpinorTestTskHiStk[SPINOR_TEST_TASK_STK_SZ] __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };

/* Queue Buffers and Handles definitions for Higher Priority Task: Between UART task and SPINOR test task */
uint8_t xQBufHiforTestTask[SPINOR_TEST_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xQHandleHiforTestTask = NULL;
StaticQueue_t xStaticQBufHiforTestTask;
/* Queue Buffers and Notify Handles definitions for Higher Priority Task: Between UART task and SPINOR test task */
uint8_t xNotifyQBufHifromTestTask[SPINOR_UART_NOTIFY_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xNotifyQHandleHifromTestTask = NULL;
StaticQueue_t xStaticNotifyQBufHifromTestTask;
/* Queue Buffers and Handles definitions for Higher Priority Task: Between SPINOR test task and callback */
uint8_t xNotifyQBufHiforTestTask[SPINOR_TEST_NOTIFY_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xNotifyQHandleHiforTestTask = NULL;
StaticQueue_t xStaticNotifyQBufHiforTestTask;
/* Task Init Definitions : Lower Priority than SPINOR task */
static StaticTask_t xSpinorTestTskLoTCB = { 0 };
static StackType_t xSpinorTestTskLoStk[SPINOR_TEST_TASK_STK_SZ] __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };

/* Queue Buffers and Handles definitions for Lower Priority Task: Between UART task and SPINOR test task */
uint8_t xQBufLoforTestTask[SPINOR_TEST_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xQHandleLoforTestTask = NULL;
StaticQueue_t xStaticQBufLoforTestTask;
/* Queue Buffers and Notify Handles definitions for Lower Priority Task: Between UART task and SPINOR test task */
uint8_t xNotifyQBufLofromTestTask[SPINOR_UART_NOTIFY_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xNotifyQHandleLofromTestTask = NULL;
StaticQueue_t xStaticNotifyQBufLofromTestTask;
/* Queue Buffers and Handles definitions for Lower Priority Task: Between SPINOR test task and callback */
uint8_t xNotifyQBufLoforTestTask[SPINOR_TEST_NOTIFY_Q_BUF_SZ] __attribute__((aligned(MEM_ALIGNMENT_4))) = { 0 };
SPINOR_UNPRIV_DATA QueueHandle_t xNotifyQHandleLoforTestTask = NULL;
StaticQueue_t xStaticNotifyQBufLoforTestTask;
#endif

/* Helper function to get the number of 4kblocks in the sectors for which the address belongs */
uint32 el1TestGetNum4kBlock(uint32_t addr, spinorSectorMapInfoType *el1_sectorMapInfo)
{
    uint32 num_blocks;

    for (int idx = 0; idx <= 4; idx++)
    {
        if ( (addr >= el1_sectorMapInfo->sectorMapInfo[idx].start_range) && (addr <= el1_sectorMapInfo->sectorMapInfo[idx].end_range))
        {
          num_blocks = el1_sectorMapInfo->sectorMapInfo[idx].er_size_KB/4;
          return num_blocks;
        }
    }

    return 0;
}

/* Erase followed by read testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_001(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_block;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
        el1_buff_copy[i] = i % ((sizeof(uint8))<<8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] Erase FAILED\r\n" );
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {
        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] Read FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff_copy[i]!=0xFF)
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_001]Erase data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_001] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_001] Erase followed by read test PASSED\r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if(el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_001] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_001] Erase followed by read test FAILED\r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Write followed by read testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_002(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_block;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Erase FAILED\r\n" );
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {
        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Read check for erase FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff_copy[i]!=0xFF)
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_002]Erase data inconsistent \n\r");
                goto Error_loop;
            }
        }

        result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Write FAILED\r\n" );
            goto Error_loop;
        }

        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Read check for write FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff[i]!=el1_buff_copy[i])
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_002] Write data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_002] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_002] Write followed by read test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if(el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_002] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_002] Write followed by read test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Test for handling SPINOR client open with different parameters */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_003(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t boot_loader_el1Handle = NULL, crashdump_el1Handle = NULL, el1Handle1 = NULL;

    result = spinorEl1Open ( &boot_loader_el1Handle, SPINOR_USER_TYPE_BOOT_LOADER );
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_003] Bootloader Open FAILED\r\n" );
        goto Error_loop;
    }

    /* Opening a crash dump hander in mission mode init should return failure */
    result = spinorEl1Open ( &crashdump_el1Handle, SPINOR_USER_TYPE_CRASH_DBG );
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_003] Crashdbg Open FAILED\r\n" );
        goto Error_loop;
    }

    /* Opening a EL2 hander in mission mode init should return invalid parameter */
    result = spinorEl1Open ( &el1Handle1, SPINOR_USER_TYPE_EL2 );
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_003] EL2 Open in mission mode FAILED\r\n" );
        goto Error_loop;
    }

    if (boot_loader_el1Handle != NULL)
    {
      result = spinorEl1Close( boot_loader_el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(crashdump_el1Handle != NULL)
    {
      result = spinorEl1Close( crashdump_el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_003] Invalid handle opening test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (boot_loader_el1Handle != NULL)
    {
      result = spinorEl1Close( boot_loader_el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(crashdump_el1Handle != NULL)
    {
      result = spinorEl1Close( crashdump_el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 5 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_003] Close 6 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_003] Invalid handle opening test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Get GPT partition info with invalid handle testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_004(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL, temp_handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_004] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_004] GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    temp_handle = el1Handle;
    el1Handle = (spinor_handle_t)12;

    /* Invalid handle */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_004] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    el1Handle = temp_handle;

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_004] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_004] Get GPT partition info with invalid handle test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_004] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_004] Get GPT partition info with invalid handle test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Invalid GUID string testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_005(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_005] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_005] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Corrupted GUID string vith valid hex characters */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-abcd-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_005] El1GetGptPartitionInfo with valid hex char FAILED\r\n" );
        goto Error_loop;
    }

    /* Invalid GUID string in non hex characters */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-gxti-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_005] El1GetGptPartitionInfo with invalid GUID FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_005] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_005] Invalid GUID string test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_005] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_005] Invalid GUID string test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Duplicate partition testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_006(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL, el1Handle_dupe = NULL;
    uint32 byte_offset, byte_count, byte_offset_temp, byte_count_temp;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Open ( &el1Handle_dupe, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Duplicate Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle_dupe, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Dupe handle El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1GetGptPartitionInfo( el1Handle_dupe, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset_temp, &byte_count_temp);
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Dupe handle El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_006] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle_dupe != NULL)
    {
      result = spinorEl1Close( el1Handle_dupe );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_006] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_006] Duplicate partition test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_006] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle_dupe != NULL)
    {
      result = spinorEl1Close( el1Handle_dupe );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_006] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_006] Duplicate partition test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Invalid partition read (not in whitelist) testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_007(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, partsize_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    partsize_count = byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1Read ( el1Handle, (byte_offset-byte_count), byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, (byte_offset-256), partsize_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 2 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, (byte_offset+partsize_count+256), byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 3 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset+partsize_count-4096, 2 * byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 4 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    result = spinorEl1Read ( el1Handle, byte_offset, 0, el1_buff_copy);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 5 FAILED\r\n" );
        goto Error_loop;
    }

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1Read ( el1Handle, (byte_offset-byte_count), partsize_count+256, el1_buff_copy); //check not greater than 4k
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Read 6 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_007] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_007] Invalid partition read (not in whitelist) test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_007] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_007] Invalid partition read (not in whitelist) test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Valid partition read (in whitelist range) testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_008(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Read ( el1Handle, (byte_offset+256), byte_count-256, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] Read 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] Read 2 FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_008] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_008] Valid partition read (in whitelist range) test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_008] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_008] Valid partition read (in whitelist range) test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Unaligned address and size for read testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_009(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Read ( el1Handle, byte_offset+12, byte_count-12, el1_buff_copy);
    if( result != SPINOR_ALIGNMENT )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] Read 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count-12, el1_buff_copy);
    if( result != SPINOR_ALIGNMENT )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] Read 2 FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_009] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_009] Unaligned address and size for read test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_009] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_009] Unaligned address and size for read test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Unaligned address and size for write testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_010(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Write ( el1Handle, byte_offset+12, byte_count-12, el1_buff );
    if (result != SPINOR_ALIGNMENT)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] Write 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count-12, el1_buff );
    if (result != SPINOR_ALIGNMENT)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] Write 2 FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_010] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_010] Unaligned address and size for write test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_010] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_010] Unaligned address and size for write test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Access to blacklisted GUID belonging to EL2 testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_011(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_011] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_011] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

#ifdef SPINOR_EL2_DEFAULT_BLACKLIST
    /* Using SAIL_NOR_TEST_EL2 */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "503e59a3-66c6-4386-9999-00a44a94c039", &byte_offset, &byte_count);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_011] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_EL2_DEFAULT_BLACKLIST */

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_011] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_011] Access to blacklisted GUID belonging to EL2 test PASSED \r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_011] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_011] Access to blacklisted GUID belonging to EL2 test FAILED \r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Check buffer corruption test */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_012(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_block;
    uint32 byte_offset_temp, byte_count_temp;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes; /* Must be 4k */

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Erase FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Read FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff_copy[i]!=0xFF)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012]Erase data inconsistent \n\r");
            goto Error_loop;
        }
    }

    /* Write pattern to 512 bytes starting at offset + 1024 */

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    memset(el1_buff, WRITE_PATTERN, sizeof(el1_buff));
    byte_count_temp = 512;
    byte_offset_temp = byte_offset + 1024;

    result = spinorEl1Write ( el1Handle, byte_offset_temp, byte_count_temp, el1_buff );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Write FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset_temp, byte_count_temp, el1_buff_copy + 1024);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Read check for write FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<1024;i++)
    {
        if (el1_buff_copy[i] != 0)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012]Buffer before start of Read buffer corrupted \n\r");
            goto Error_loop;
        }
    }

    for (i=1024;i<(1024 + 512);i++)
    {
        if (el1_buff_copy[i] != WRITE_PATTERN)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012]Write data inconsistent: Read check 2 \n\r");
            goto Error_loop;
        }
    }

    for (i=(1024+512);i<byte_count;i++)
    {
        if (el1_buff_copy[i] != 0)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012]Buffers after read buffer corrupted \n\r");
            goto Error_loop;
        }
    }

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_012] Test buffer corruption PASSED\r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_012] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_012] Test buffer corruption FAILED\r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Writing to an invalid partition (not in whitelist) testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_013(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, partsize_count;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] el1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    partsize_count = byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1Write ( el1Handle, (byte_offset-byte_count), byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, (byte_offset-256), partsize_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 2 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, (byte_offset+partsize_count+256), byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 3 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset+partsize_count-4096, 2 * byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 4 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    result = spinorEl1Write ( el1Handle, byte_offset, 0, el1_buff_copy);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 5 FAILED\r\n" );
        goto Error_loop;
    }

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1Write ( el1Handle, (byte_offset-byte_count), partsize_count+256, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_013] Write 6 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_013] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_013] Writing to an invalid partition (not in whitelist) test PASSED \r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_013] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_013] Writing to an invalid partition (not in whitelist) test FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Erasing an invalid partition (not in whitelist) testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_014(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, partsize_count, num_block;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] el1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    partsize_count = byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

#ifdef SPINOR_FD_WHITELIST_CHECK
    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    result = spinorEl1Erase (el1Handle, (byte_offset - 4096)/byte_count , num_block);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Erase 1 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Erase (el1Handle, (byte_offset + partsize_count)/byte_count , num_block);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Erase 2 FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Erase (el1Handle, (byte_offset + 4096)/byte_count , num_block);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Erase 3 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* SPINOR_FD_WHITELIST_CHECK */

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count , 0);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_014] Erase 4 FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_014] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_014] Erasing an invalid partition (not in whitelist) test PASSED \r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_014] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_014] Erasing an invalid partition (not in whitelist) test FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Checking lowpower vote DPD exit test */
/*  1. Open handles, should exit DPD
    2. Vote for low power on all handles, should enter DPD
    3. Vote for low power exit on 1st handle , should exit DPD
    4. Vote for low power exit on 2nd handle , should do nothing
    5. Close both handles, should enter dpd here
    6. Open another handle, should exit dpd
    7. Close the handle, should enter dpd
*/
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_015(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL, el1Handle_dupe = NULL;
    uint32 byte_offset, byte_count;
    uint32 byte_offset_dupe, byte_count_dupe, i, num_block;
    int counter = 0, max_matches = 0;

    /* 1. Open handles, should exit DPD */
    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_015] Checking lowpower vote DPD exit test SKIPPED \r\n");
        goto spinor_el1_test_skip;
    }

    result = spinorEl1Open ( &el1Handle_dupe, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
      DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Dupe handle Open FAILED\r\n" );
      goto Error_loop;
    }
    result = spinorEl1GetMemInfo ( el1Handle_dupe, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Dupe handle El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
        el1_buff_copy[i] = i % ((sizeof(uint8))<<8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    /* We use SAIL_SW2 partition ("e96d074b-6921-49f2-bd7c-c6a0a4bb72e1") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle_dupe, "e96d074b-6921-49f2-bd7c-c6a0a4bb72e1", &byte_offset_dupe, &byte_count_dupe);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Dupe handle El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count_dupe < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Dupe Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count_dupe = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    /* Perform erase and write a pattern */
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Erase FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Read check for erase FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff_copy[i]!=0xFF)
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_015]Erase data inconsistent \n\r");
            goto Error_loop;
        }
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Write FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Read check for write FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_015] Write data inconsistent \n\r");
            goto Error_loop;
        }
    }

    /* 2. Vote for low power on all handles, should enter DPD */
    result =  spinorEl1LowPower( el1Handle, TRUE); //does not enter dpd here
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Low power el1_handle TRUE FAILED\r\n" );
        goto Error_loop;
    }

    result =  spinorEl1LowPower( el1Handle_dupe, TRUE); //enters dpd here
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Low power el1_handle_dupe TRUE FAILED\r\n" );
        goto Error_loop;
    }

    //In DPD mode, read API should read all incorrect values
    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] DPD entered Read FAILED\r\n" );
        goto Error_loop;
    }

    /* In DPD mode, the read API will read all incorrect values.
       As el1_buff is populated with values from 0 to 256 repeated until its size, the incorrect value will occur arrary_size/256 times */
    counter = 0;
    for (i=0;i<byte_count;i++)
    {
        if (el1_buff_copy[i] == el1_buff[i])
        {
            counter++;
        }
    }

    max_matches = ((sizeof(el1_buff)/sizeof(el1_buff[0]))/256);
    if(counter > max_matches)
    {
        DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015]Read API in DPD Mode data inconsistent, low power mode not entered \n\r");
        goto Error_loop;
    }

    /* 3. Vote for low power exit on 1st handle , should exit DPD */
    result =  spinorEl1LowPower( el1Handle, FALSE); //should exit dpd, without performing close
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Low power el1_handle FALSE FAILED\r\n" );
        goto Error_loop;
    }

    //Exited DPD mode, read API should read all valid values
    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] DPD Exit Read FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015]Read API after exiting DPD Mode data inconsistent \n\r");
            goto Error_loop;
        }
    }

    /* 4. Vote for low power exit on 2nd handle , should do nothing */
    result =  spinorEl1LowPower( el1Handle_dupe, FALSE); //does not exit DPD again
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Low power el1Handle_dupe FALSE FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* Read API should still read all valid values */
    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] DPD Exit Read 2 FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_015]Read API after exiting DPD Mode data inconsistent \n\r");
            goto Error_loop;
        }
    }

    /* 5. Close both handles, should enter dpd here */
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle_dupe != NULL)
    {
      result = spinorEl1Close( el1Handle_dupe );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    /* 6. Open another handle, should exit dpd */
    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] El1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* Exit DPD, Read API should read all valid values */
    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_015] DPD Exit Read 2 FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_015]Read API after exiting DPD Mode data inconsistent \n\r");
            goto Error_loop;
        }
    }

spinor_el1_test_skip:

    /* 7. Close the handle, should enter dpd */
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_015] Checking lowpower vote DPD exit test PASSED \r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    if(el1Handle_dupe != NULL)
    {
      result = spinorEl1Close( el1Handle_dupe );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_015] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_015] Checking lowpower vote DPD exit test FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* EL1 partition protection control tests  */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_016(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL, el1Handle1 = NULL, el1SuperHandle = NULL, el1SuperHandle1= NULL;
    uint32 byte_offset, byte_count, partsize_count, i, num_block, byte_offset_dupe, byte_count_dupe;
    eSpinorProtectType eAttrib;

    /***************** Test EL1 users cannot control partitions attibutes ****************************/
    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Open EL1 user FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] el1GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetPartitionAttrib( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_NOT_SUPPORTED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Restrict EL1 users to get partition attributes failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_RDWR;

    result = spinorEl1SetPartitionAttrib( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_NOT_SUPPORTED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Restrict EL1 users to Set partition attributes failed \r\n" );
        goto Error_loop;
    }

    /***************** Test EL1 Super user can control partitions attibutes ****************************/
    result = spinorEl1Open ( &el1SuperHandle, SPINOR_USER_TYPE_EL1_SUPER );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Opening EL1 Super user FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Open ( &el1SuperHandle1, SPINOR_USER_TYPE_EL1_SUPER );
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Opening multiple EL1 Super user test FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user get partition attributes failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_RDWR;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attributes to RDWR failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to RDWR \r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_RDWR)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to NONE \r\n" );
        goto Error_loop;
    }

    /***************** Protect El1 user from getting partition info after setting RDWR ****************************/
    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Failed to protect El1GetGptPartitionInfo for EL1 user after attribute set to RDWR \r\n" );
        goto Error_loop;
    }

    /***************** Check El1 user can get partition info after setting Attribute to NONE ****************************/
    eAttrib = SPINOR_PROTECT_NONE;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute  to NONE failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to NONE \r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_NONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to NONE \r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo FAILED after removing all protection for EL1 users \r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    partsize_count = byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    byte_offset_dupe = byte_offset;
    byte_count_dupe = byte_count;

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
    }

    for(int j = 0; j < num_block; j++)
    {
        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff_copy[i]!=0xFF)
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016]Erase data inconsistent \n\r");
                goto Error_loop;
            }
        }

        result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Write FAILED\r\n" );
            goto Error_loop;
        }

        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read check for write FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff[i]!=el1_buff_copy[i])
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016] Write data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    /* Restore byte offset and byte count values */
    byte_offset = byte_offset_dupe;
    byte_count = byte_count_dupe;

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase 1 FAILED\r\n" );
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {
        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 1 FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff_copy[i]!=0xFF)
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016]Erase 1 data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    /* Restore byte offset and byte count values */
    byte_offset = byte_offset_dupe;
    byte_count = byte_count_dupe;

    /***************** Check El1 user can get partition info after setting Attribute to RD ****************************/
    eAttrib = SPINOR_PROTECT_RD;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute  to RD failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to RD \r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_RD)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to RD \r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo FAILED after Read protection for EL1 users \r\n" );
        goto Error_loop;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Byte count validation FAILED\r\n" );
        goto Error_loop;
    }
    partsize_count = byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;


    /***************** Check El1 user can Erase and Write to partition after setting Attribute to RD ****************************/
    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    result = spinorEl1Erase (el1Handle, (byte_offset)/byte_count , num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase 2 FAILED after after Read protection for EL1 users \r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 2 protection failed for EL1 user after setting attribute \r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Write 2 FAILED\r\n" );
        goto Error_loop;
    }

    /***************** Check El1 user can read from partition info after setting Attribute to WR ****************************/
    eAttrib = SPINOR_PROTECT_WR;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute  to WR failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to WR \r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_WR)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to WR \r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 3 failed \r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016] Write 3 data inconsistent \n\r");
            goto Error_loop;
        }
    }

    result = spinorEl1Erase (el1Handle, (byte_offset)/byte_count , num_block);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase 4 protection failed after Write protection for EL1 users \r\n" );
        goto Error_loop;
    }


    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Write 4 protection failed after Write protection for EL1 users\r\n" );
        goto Error_loop;
    }


    /***************** Check El1 user cannot access partition even with the addresses after setting Attribute to RDWR ****************************/
    eAttrib = SPINOR_PROTECT_RDWR;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute  to RDWR 2 failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to RDWR 2\r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_RDWR)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to RDWR 2\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 5 protection failed after Read Write protection for EL1 users \r\n" );
        goto Error_loop;
    }

    result = spinorEl1Erase (el1Handle, (byte_offset)/byte_count , num_block);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase 5 protection failed after Write protection for EL1 users \r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Write 5 protection failed after Write protection for EL1 users\r\n" );
        goto Error_loop;
    }


    /***************** Check El1 user can access partition after setting Attribute to NONE ****************************/
    eAttrib = SPINOR_PROTECT_NONE;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute  to NONE 2 failed \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to NONE 2\r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_NONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to NONE 2\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 5 protection failed after Read Write protection for EL1 users \r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016] Write 4 data inconsistent \n\r");
            goto Error_loop;
        }
    }

    result = spinorEl1Erase (el1Handle, (byte_offset)/byte_count , num_block);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Erase 5 protection failed after Write protection for EL1 users \r\n" );
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {
        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 5 FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff_copy[i]!=0xFF)
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016]Erase 5 data inconsistent \n\r");
                goto Error_loop;
            }
        }

        result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Write 6 protection failed after Write protection for EL1 users\r\n" );
            goto Error_loop;
        }

        result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Read 6 FAILED\r\n" );
            goto Error_loop;
        }

        for (i=0;i<byte_count;i++)
        {
            if (el1_buff[i]!=el1_buff_copy[i])
            {
                DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_016] Write 6 data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    /* Restore byte offset and byte count values */
    byte_offset = byte_offset_dupe;
    byte_count = byte_count_dupe;

    /***************** Check El1 user can access same partition (whitelist disable) ****************************/
    result = spinorEl1Open ( &el1Handle1, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] Open EL1 2nd user FAILED\r\n" );
        goto Error_loop;
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test */
    result = spinorEl1GetGptPartitionInfo( el1Handle1, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo failed for 2nd EL1 users \r\n" );
        goto Error_loop;
    }

    /***************** Check El1 user can access EL2 partition (blacklist disable) ****************************/
    result = spinorEl1GetGptPartitionInfo( el1Handle1, "503e59a3-66c6-4386-9999-00a44a94c039", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo for EL2 partition failed for 2nd EL1 users \r\n" );
        goto Error_loop;
    }


    /***************** Check El1 Super user can change EL2 partition access ****************************/
    eAttrib = SPINOR_PROTECT_NONE;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute to NONE for EL2 partition failed \r\n" );
        goto Error_loop;
    }
    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to NONE for EL2 partition\r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_NONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to NONE for EL2 partition\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetGptPartitionInfo( el1Handle1, "503e59a3-66c6-4386-9999-00a44a94c039", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo for EL2 partition failed for 2nd EL1 users \r\n" );
        goto Error_loop;
    }


    /***************** Check El1 Super user can change EL2 partition access to RDWR protect ****************************/
    eAttrib = SPINOR_PROTECT_RDWR;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute to RDWR for EL2 partition failed \r\n" );
        goto Error_loop;
    }
    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to RDWR for EL2 partition\r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_RDWR)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to RDWR for EL2 partition\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetGptPartitionInfo( el1Handle, "503e59a3-66c6-4386-9999-00a44a94c039", &byte_offset, &byte_count);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] El1GetGptPartitionInfo protection for EL2 partition failed for 2nd EL1 user after setting RDWR protection \r\n" );
        goto Error_loop;
    }

    eAttrib = SPINOR_PROTECT_NONE;

    result = spinorEl1SetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to Set partition attribute to NONE 2 for EL2 partition failed \r\n" );
        goto Error_loop;
    }
    eAttrib = SPINOR_PROTECT_MAX;

    result = spinorEl1GetPartitionAttrib( el1SuperHandle, "503e59a3-66c6-4386-9999-00a44a94c039",  &eAttrib );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 Super user to get partition attributes failed after setting to NONE 2 for EL2 partition\r\n" );
        goto Error_loop;
    }

    if (eAttrib != SPINOR_PROTECT_NONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_016] get partition attribute did not return right value after setting to NONE 2 for EL2 partition\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle1 != NULL)
    {
      result = spinorEl1Close( el1SuperHandle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_016] EL1 partition protection control tests PASSED \r\n");
    xReturn = MODULE_TEST_PASSED;
    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle1 != NULL)
    {
      result = spinorEl1Close( el1SuperHandle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_016] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_016] EL1 partition protection control tests FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* EL1 Bin Cmd tests  */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_017(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL, el1Handle1 = NULL, el1SuperHandle = NULL, el1SuperHandle1= NULL;
    uint32 byte_offset, byte_count, partsize_count, i, num_block, opcode;
    spinorBincmdParams_t bincmdParams = {0};
    spinorBincmdParams_t *bincmdParamsPtr = NULL;
    uint32_t dev_id=0;

    /***************** Tests for Lock and Unlock for Bin Command ****************************/
    /* Check for NULL handle for spinorEl1AcquireSPIBus */
    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1Handle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1AcquireSPIBus NULL handle check FAILED\r\n" );
        goto Error_loop;
    }

    /* Check for NULL handle for spinorEl1ReleaseSPIBus */
    result = spinorEl1ReleaseSPIBus(el1Handle);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1ReleaseSPIBus NULL handle check FAILED\r\n" );
        goto Error_loop;
    }

    /* Open a EL1 user and acquire the lock. it should fail */
    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Open EL1 handle FAILED\r\n" );
        goto Error_loop;
    }

    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1Handle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_NOT_SUPPORTED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1AcquireSPIBus EL1 handle FAILED\r\n" );
        goto Error_loop;
    }

    /* Open a EL1 Super user and acquire the lock */
    result = spinorEl1Open ( &el1SuperHandle, SPINOR_USER_TYPE_EL1_SUPER );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Opening EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* Try to Open a multiple EL1 Super user */
    result = spinorEl1Open ( &el1SuperHandle1, SPINOR_USER_TYPE_EL1_SUPER );
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Opening multiple EL1 Super user test FAILED\r\n" );
        goto Error_loop;
    }

    /* Release a lock with EL1 Super user without acquiring the lock */
    result = spinorEl1ReleaseSPIBus(el1SuperHandle);
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Releasing spinorEl1ReleaseSPIBus without acquire for EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* EL1 Super user acquire the lock */
    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1SuperHandle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1AcquireSPIBus EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* EL1 Super user acquire the lock multiple times */
    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1SuperHandle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Multiple spinorEl1AcquireSPIBus EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* Release a lock with EL1 after acquiring lock should fail */
    result = spinorEl1ReleaseSPIBus(el1Handle);
    if( result != SPINOR_DEVICE_NOT_SUPPORTED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Releasing spinorEl1ReleaseSPIBus with EL1 user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* Release a lock with EL1 Super user after acquiring the lock should pass */
    result = spinorEl1ReleaseSPIBus(el1SuperHandle);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Releasing spinorEl1ReleaseSPIBus with EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }


    /***************** BIN Command API testing ****************************/
    /* Tests for BIN command API */
    result = spinorEl1Bincmd( el1SuperHandle1, &bincmdParams);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1Bincmd NULL handle check FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Bincmd( el1SuperHandle, bincmdParamsPtr);
    if( result != SPINOR_DEVICE_INVALID_PARAMETER )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1Bincmd NULL binCmdParamPtr check FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_FAIL )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1Bincmd without lock check FAILED\r\n" );
        goto Error_loop;
    }

   /* All other operations acquiring lock should be done before acquiring the lock explicitly*/

    result = spinorEl1GetMemInfo ( el1SuperHandle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] el1GetMemInfo FAILED\r\n" );
        goto Error_loop1;
    }


    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
        el1_buff_copy[i] = i % ((sizeof(uint8))<<8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop1;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Byte count validation FAILED\r\n" );
        goto Error_loop1;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1GetSectorMapInfo(el1SuperHandle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* EL1 Super user acquire the lock */
    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1SuperHandle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1AcquireSPIBus EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Bincmd( el1Handle, &bincmdParams);
    if( result != SPINOR_DEVICE_NOT_SUPPORTED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] spinorEl1Bincmd with EL1 handle check FAILED\r\n" );
        goto Error_loop1;
    }

    /* Write Enable Command */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Write Enable FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer =(uint8*) &dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    dev_id = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Read Status Register after write enable FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Write Enable Latch */
        if(dev_id & 0x02)
        {
            break;
        }
        dev_id = 0;
    }

    /* Erase */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {

        /* Get num 4k block */
        num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

        /* Choose the right opcode */
        if(num_block == 1)
        {
            opcode = 0x21;
        }
        else
        {
            /*  num_block = 64/48 */
            opcode = 0xDC;
        }

        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=opcode, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Erase operation FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    dev_id = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Read Status Register after erase FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Program erase busy */
        if (((uint8)dev_id & 0x01) == 0)
        {
            break;
        }
        dev_id = 0;
    }

    /* Read back */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x6C, .dummy_cycle = 8, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x0C, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Read operation after erase FAILED\r\n" );
        goto Error_loop1;
    }

    for (i=0;i<256;i++)
    {
        if (el1_buff_copy[i]!=0xFF)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017]Erase data inconsistent \n\r");
            goto Error_loop1;
        }
    }

    /* Write Enable Command */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for 2nd Write Enable FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&dev_id, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    dev_id = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Read Status Register after 2nd write enable FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Write Enable Latch */
        if(dev_id & 0x02)
        {
            break;
        }
        dev_id = 0;
    }

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* Write  */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x34, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id))  //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Write Operation FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read back */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x6C, .dummy_cycle = 8, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x0C, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Binary Command Operation for Read operation after write FAILED\r\n" );
        goto Error_loop1;
    }

    for (i=0;i<256;i++)
    {
        if (el1_buff_copy[i]!=el1_buff[i])
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017]Write data inconsistent \n\r");
            goto Error_loop1;
        }
    }

testdone:
    /* Release a lock with EL1 Super user after acquiring the lock should pass */
    result = spinorEl1ReleaseSPIBus(el1SuperHandle);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Releasing spinorEl1ReleaseSPIBus with EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle1 != NULL)
    {
      result = spinorEl1Close( el1SuperHandle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_017] EL1 Bin Cmd tests PASSED \r\n");
    xReturn = MODULE_TEST_PASSED;
    goto spinor_el1_test_end;

Error_loop1:
        /* Release a lock with EL1 Super user after acquiring the lock should pass */
        result = spinorEl1ReleaseSPIBus(el1SuperHandle);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_017] Releasing spinorEl1ReleaseSPIBus with EL1 Super user handle FAILED\r\n" );
            goto Error_loop;
        }

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1Handle1 != NULL)
    {
      result = spinorEl1Close( el1Handle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    if (el1SuperHandle1 != NULL)
    {
      result = spinorEl1Close( el1SuperHandle1 );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_017] Close 4 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_017] EL1 Bin Cmd tests FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* Invalid GPT table access testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_018(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, start_block;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* Accessing the primary GPT header region space */
    byte_offset = 0x5FF0;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, 1);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Erase FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Read FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Write FAILED\r\n" );
        goto Error_loop;
    }

    /* Accessing the secondary GPT header region space */
    start_block = (el1_nor_info.block_count - 5);

    result = spinorEl1Erase (el1Handle, start_block, 1);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Erase FAILED\r\n" );
        goto Error_loop;
    }

    byte_offset = ((el1_nor_info.block_count - 5) * (el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes)) - 256;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_ACCESS_DENIED )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Read FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_ACCESS_DENIED)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid address access Write FAILED\r\n" );
        goto Error_loop;
    }

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
    }

    /* Accessing near the primary GPT header region space */
    byte_offset = 0x6000;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Valid address access Erase FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Write ( el1Handle, byte_offset, byte_count, el1_buff );
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Valid address access Write FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Valid address access Read FAILED\r\n" );
        goto Error_loop;
    }

    for (i=0;i<byte_count;i++)
    {
        if (el1_buff[i]!=el1_buff_copy[i])
        {
            DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_018] Write data inconsistent \n\r");
            goto Error_loop;
        }
    }

    /* Accessing near the secondary GPT header region space */
    byte_offset = ((el1_nor_info.block_count - 5) * (el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes)) - byte_count;
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1Read ( el1Handle, byte_offset, byte_count, el1_buff_copy);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Valid address access Read FAILED\r\n" );
        goto Error_loop;
    }

    if (el1Handle != NULL )
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_018] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }
    DEBUG_LOG( SAIL_INFO, "[TC_SPINOR_EL1_018] Invalid GPT table access test PASSED\r\n" );

    goto spinor_el1_test_end;

Error_loop:
    if(el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"\n[TC_SPINOR_EL1_018] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_018] Invalid GPT table access test FAILED\r\n" );
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

/* erase start block and block count validation for non uniform 4k testcase */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_019(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_blocks;

    result = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Open FAILED\r\n" );
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo ( el1Handle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] GetMemInfo FAILED\r\n" );
        goto Error_loop;
    }

    if((0x195A34 != el1_nor_info.device_id) && (0x195B34 != el1_nor_info.device_id)) //Infineon
    {
        DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_019] Erase start and end block validation test SKIPPED \r\n");
        goto spinor_el1_test_skip;
    }


    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    /* Address A 0xa000 - falling in 4k range */
    /* Address B 0x10000 - falling in 192k/256k range*/
    /* Address C 0x1f00000 - falling in 256/192k range */
    /* Address D 0x1ff0000 - falling in 4k range */

#if 0 // invasive tests
    /* 1. erase from A+20K 1 block  pass */
    byte_offset = 0xF000; // 0xa000+ 0x5000
    num_blocks = 1;
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] valid address Erase 1 FAILED\r\n" );
        goto Error_loop;
    }

    /* 2. erase from A+20K 49blocks pass  */

    byte_offset = 0xF000; // 0xa000+ 0x5000
    num_blocks = 49;
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 2 FAILED\r\n" );
        goto Error_loop;
    }


    /* 3. erase from A+20K 49+64 blocks pass */
    byte_offset = 0xF000; // 0xa000+ 0x5000
    num_blocks = 113; // 49+64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 3 FAILED\r\n" );
        goto Error_loop;
    }

    /* 4. erase from B 48blocks pass */
    byte_offset = 0x10000; // 0x10000
    num_blocks = 48; // 48
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 4 FAILED\r\n" );
        goto Error_loop;
    }

    /* 5. erase from B 48+64 blocks pass */
    byte_offset = 0x10000; // 0x10000
    num_blocks = 112; // 48+64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 5 FAILED\r\n" );
        goto Error_loop;
    }

    /* 6. erase from B+192K 64 blocks pass */
    byte_offset = 0x40000; // 0x10000 + 0x30000
    num_blocks = 64; // 64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 6 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* invasive tests */

    /* 7. erase from B+4k 1block fail */
    byte_offset = 0x11000; // 0x10000 + 0x1000
    num_blocks = 1; // 1
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 7 FAILED\r\n" );
        goto Error_loop;
    }
    /* 8. erase from B+8k 1 block fail */
    byte_offset = 0x12000; // 0x10000 + 0x2000
    num_blocks = 1; // 1
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 8 FAILED\r\n" );
        goto Error_loop;
    }

    /* 9. erase from B  46block fail */
    byte_offset = 0x10000; // 0x10000
    num_blocks = 46; // 46
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 9 FAILED\r\n" );
        goto Error_loop;
    }

    /* 10. erase from B 48+4 blocks fail */
    byte_offset = 0x10000; // 0x10000
    num_blocks = 52; // 48+4
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 10 FAILED\r\n" );
        goto Error_loop;
    }

    /* 11. erase from B+4k 47 blocks fail */
    byte_offset = 0x11000; // 0x10000 + 0x1000
    num_blocks = 47; // 47
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 11 FAILED\r\n" );
        goto Error_loop;
    }

    /* 12. erase from B+4k 44 blocks fail */
    byte_offset = 0x11000; // 0x10000 + 0x1000
    num_blocks = 44; // 44
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 12 FAILED\r\n" );
        goto Error_loop;
    }

    /* 13. erase from B+4k 50 blocks fail */
    byte_offset = 0x11000; // 0x10000 + 0x1000
    num_blocks = 50; // 50
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 13 FAILED\r\n" );
        goto Error_loop;
    }

#if 0
    /* 14. erase from D+20K 1 block  pass */
    byte_offset = 0x1FF5000; // 0x1ff0000 + 0x5000
    num_blocks = 1; // 1
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 14 FAILED\r\n" );
        goto Error_loop;
    }
    /* 15. erase from C+768K 49blocks pass */
    byte_offset = 0x1FC0000; // 0x1F00000 + 0xC0000
    num_blocks = 49; // 49
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 15 FAILED\r\n" );
        goto Error_loop;
    }

    /* 16. erase from C+768K 48blocks pass */
    byte_offset = 0x1FC0000; // 0x1F00000 + 0xC0000
    num_blocks = 48; // 48
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 16 FAILED\r\n" );
        goto Error_loop;
    }

    /* 17. erase from C+512K 49+64 blocks pass */
    byte_offset = 0x1F80000; // 0x1F00000 + 0x80000
    num_blocks = 113; // 49+64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 17 FAILED\r\n" );
        goto Error_loop;
    }

    /* 18. erase from C+512K 48+64 blocks pass */
    byte_offset = 0x1F80000; // 0x1F00000 + 0x80000
    num_blocks = 112; // 48+64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 18 FAILED\r\n" );
        goto Error_loop;
    }

    /* 19. erase from C+512K 64 blocks pass */
    byte_offset = 0x1F80000; // 0x1F00000 + 0x80000
    num_blocks = 64; // 64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 19 FAILED\r\n" );
        goto Error_loop;
    }
    /* 20. erase from C 64 blocks pass  */
    byte_offset = 0x1F00000; // 0x1F00000
    num_blocks = 64; // 64
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Valid address Erase 20 FAILED\r\n" );
        goto Error_loop;
    }
#endif /* invasive tests */

    /* 21. erase from C  46block fail */
    byte_offset = 0x1F00000; // 0x1F00000
    num_blocks = 46; // 46
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 21 FAILED\r\n" );
        goto Error_loop;
    }

    /* 22. erase from C 64+4 blocks fail */
    byte_offset = 0x1F00000; // 0x1F00000
    num_blocks = 68; // 68
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 22 FAILED\r\n" );
        goto Error_loop;
    }

    /* 23. erase from C+4k 1block fail */
    byte_offset = 0x1F01000; // 0x1F00000 + 0x1000
    num_blocks = 1; // 1
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 23 FAILED\r\n" );
        goto Error_loop;
    }


    /* 24. erase from C+8k 1 block fail */
    byte_offset = 0x1F02000; // 0x1F00000 + 0x2000
    num_blocks = 1; // 1
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 24 FAILED\r\n" );
        goto Error_loop;
    }

    /* 25. erase from C+768K  46block fail */
    byte_offset = 0x1FC0000; // 0x1F00000 + 0xC0000
    num_blocks = 46; // 46
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 25 FAILED\r\n" );
        goto Error_loop;
    }

    /* 26. erase from C+768K+4k 47 blocks fail */
    byte_offset = 0x1FC1000; // 0x1F00000 + 0xC0000 + 0x1000
    num_blocks = 47; // 47
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 26 FAILED\r\n" );
        goto Error_loop;
    }

    /* 27. erase from C+768K+4k 44 blocks fail */
    byte_offset = 0x1FC1000; // 0x1F00000 + 0xC0000 + 0x1000
    num_blocks = 44; // 44
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 27 FAILED\r\n" );
        goto Error_loop;
    }

    /* 28. erase from C+768K+4k 50 blocks fail */
    byte_offset = 0x1FC1000; // 0x1F00000 + 0xC0000 + 0x1000
    num_blocks = 50; // 50
    result = spinorEl1Erase (el1Handle, byte_offset/byte_count, num_blocks);
    if( result != SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_019] Invalid address Erase 28 FAILED\r\n" );
        goto Error_loop;
    }


spinor_el1_test_skip:

    /* Close the handle */
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_019] Close 1 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_019] Erase start and end block validation test PASSED \r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
      result = spinorEl1Close( el1Handle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_019] Close 2 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_019] Erase start and end block validation test FAILED \r\n");
        xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;

}

/* EL1 Bin Cmd Sample tests  */
TEST_FUNC TESTerrorType_e TC_SPINOR_EL1_binCmdTest(void)
{
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t  el1SuperHandle = NULL;
    uint32 byte_offset, byte_count, partsize_count, i, num_block, opcode;
    spinorBincmdParams_t bincmdParams = {0};
    uint32_t read_val=0;

    /* Open a EL1 Super user and acquire the lock */
    result = spinorEl1Open ( &el1SuperHandle, SPINOR_USER_TYPE_EL1_SUPER );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Opening EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

   /* All other operations acquiring lock should be done before acquiring the lock explicitly*/

    result = spinorEl1GetMemInfo ( el1SuperHandle, &el1_nor_info );
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] el1GetMemInfo FAILED\r\n" );
        goto Error_loop1;
    }


    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for(i=0;i<(sizeof(el1_buff)/sizeof(el1_buff[0]));i++)
    {
        el1_buff[i] = i % ((sizeof(uint8))<<8);
        el1_buff_copy[i] = i % ((sizeof(uint8))<<8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo( el1SuperHandle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] El1GetGptPartitionInfo FAILED\r\n" );
        goto Error_loop1;
    }

    if ( byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Byte count validation FAILED\r\n" );
        goto Error_loop1;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1GetSectorMapInfo(el1SuperHandle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }


    /* EL1 Super user acquire the lock */
    while (1)
    {
        result = spinorEl1AcquireSPIBus(el1SuperHandle);
        if (SPINOR_ACCESS_NO_BUS == result)
        {
            vFreeRTOSTaskDelay(1);
            continue;
        }
        break;
    }
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] spinorEl1AcquireSPIBus EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    /* Write Enable Command */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Write Enable FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer =(uint8*) &read_val, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    read_val = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Read Status Register after write enable FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Write Enable Latch */
        if(read_val & 0x02)
        {
            break;
        }
        read_val = 0;
    }

    /* Erase */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=0x21, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        /* Get num 4k block */
        num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

        /* Choose the right opcode */
        if(num_block == 1)
        {
            opcode = 0x21;
        }
        else
        {
            /*  num_block = 64/48 */
            opcode = 0xDC;
        }

        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = 0, .len = 0, .opcode=opcode, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Erase operation FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    read_val = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Read Status Register after erase FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Program erase busy */
        if (((uint8)read_val & 0x01) == 0)
        {
            break;
        }
        read_val = 0;
    }

    /* Read back */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x6C, .dummy_cycle = 8, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x0C, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Read operation after erase FAILED\r\n" );
        goto Error_loop1;
    }

    for (i=0;i<256;i++)
    {
        if (el1_buff_copy[i]!=0xFF)
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_binCmdTest]Erase data inconsistent \n\r");
            goto Error_loop1;
        }
    }

    /* Write Enable Command */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 0, .opcode=0x06, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for 2nd Write Enable FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read Status Register */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 4, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 1, .opcode=0x05, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 8, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = 0, .buffer = (uint8*)&read_val, .len = 2, .opcode=0x05, .dummy_cycle = 5, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    }
    else
    {
        goto testdone;
    }

    read_val = 0;

    while (1)
    {
        result = spinorEl1Bincmd(el1SuperHandle, &bincmdParams);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Read Status Register after 2nd write enable FAILED\r\n" );
            goto Error_loop1;
        }
        /* Check for Write Enable Latch */
        if(read_val & 0x02)
        {
            break;
        }
        read_val = 0;
    }

    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    /* Write  */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x34, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff, .len = 256, .opcode=0x12, .dummy_cycle = 0, .num_addr_bytes = 4, .is_write_operation = TRUE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Write Operation FAILED\r\n" );
        goto Error_loop1;
    }

    /* Read back */
    /* Macronix */
    if ((0x003C84C2 == el1_nor_info.device_id) || (0x003984C2 == el1_nor_info.device_id))
    {
         bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x0019BB20 == el1_nor_info.device_id) // Micron QSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x6C, .dummy_cycle = 8, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if(0x001C5B2C == el1_nor_info.device_id) //Micron OSPI
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0x0C, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else if((0x195A34 == el1_nor_info.device_id) || (0x195B34 == el1_nor_info.device_id)) //Infineon
    {
        bincmdParams = (spinorBincmdParams_t){.addr = byte_offset, .buffer = el1_buff_copy, .len = 256, .opcode=0xEE, .dummy_cycle = 20, .num_addr_bytes = 4, .is_write_operation = FALSE, .use_dma = TRUE};
    }
    else
    {
        goto testdone;
    }

    result = spinorEl1Bincmd( el1SuperHandle, &bincmdParams);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Binary Command Operation for Read operation after write FAILED\r\n" );
        goto Error_loop1;
    }

    for (i=0;i<256;i++)
    {
        if (el1_buff_copy[i]!=el1_buff[i])
        {
            DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_binCmdTest]Write data inconsistent \n\r");
            goto Error_loop1;
        }
    }

testdone:
    /* Release a lock with EL1 Super user after acquiring the lock should pass */
    result = spinorEl1ReleaseSPIBus(el1SuperHandle);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Releasing spinorEl1ReleaseSPIBus with EL1 Super user handle FAILED\r\n" );
        goto Error_loop;
    }

    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_binCmdTest] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_EL1_binCmdTest] EL1 TC_SPINOR_EL1_binCmdTest tests PASSED \r\n");
    xReturn = MODULE_TEST_PASSED;
    goto spinor_el1_test_end;

Error_loop1:
        /* Release a lock with EL1 Super user after acquiring the lock should pass */
        result = spinorEl1ReleaseSPIBus(el1SuperHandle);
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] Releasing spinorEl1ReleaseSPIBus with EL1 Super user handle FAILED\r\n" );
            goto Error_loop;
        }

Error_loop:
    if (el1SuperHandle != NULL)
    {
      result = spinorEl1Close( el1SuperHandle );
      if(result != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"[TC_SPINOR_EL1_binCmdTest] Close 3 FAILED\n\r");
          xReturn = MODULE_TEST_FAILED;
          return xReturn;
      }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_EL1_binCmdTest] EL1 TC_SPINOR_EL1_binCmdTest tests FAILED \r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
}

#ifdef SPINOR_ASYNC_TEST
/**********************************************************
 * Implementing the callback function for High Priority Task
 *
 * @param type void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void spinorEl1TestHiCb(SPINOR_STATUS status, uint8 transaction_ID)
{
    NotifyQItemfromTestCBType CallbackNotifyQEle = { 0 };
    SPINOR_STATUS res = SPINOR_DEVICE_FAIL;
    BaseType_t xResult;

    /* Callback is done, send in notify queue */
    CallbackNotifyQEle.status = status;
    CallbackNotifyQEle.trans_ID = transaction_ID;

    /* Queue to the SPINOR test task */
    xResult = xFreeRTOSQueueSend(xNotifyQHandleHiforTestTask, &CallbackNotifyQEle, pdMS_TO_TICKS(freertosMAX_DELAY));
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Error,in Queuing to SPINOR test task queue block \r\n", __func__);
        vFreeRTOSTaskDelay(5);
        err_fatal(SAFERTOS, xResult);
    }
}

/**********************************************************
 * Implementing the callback function for Low Priority Task
 *
 * @param type void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void spinorEl1TestLoCb(SPINOR_STATUS status, uint8 transaction_ID)
{
    NotifyQItemfromTestCBType CallbackNotifyQEle = { 0 };
    SPINOR_STATUS res = SPINOR_DEVICE_FAIL;
    BaseType_t xResult;

    /* Callback is done, send in notify queue */
    CallbackNotifyQEle.status = status;
    CallbackNotifyQEle.trans_ID = transaction_ID;

    /* Queue to the SPINOR test task */
    xResult = xFreeRTOSQueueSend(xNotifyQHandleLoforTestTask, &CallbackNotifyQEle, pdMS_TO_TICKS(freertosMAX_DELAY));
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Error,in Queuing to SPINOR test task queue block \r\n", __func__);
        vFreeRTOSTaskDelay(5);
        err_fatal(SAFERTOS, xResult);
    }
}

/**********************************************************
 * SPINOR EL1 High Priority Test Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void xSpinorEL1TestHiTask(void* pvParameters)
{
    NotifyQItemfromTestCBType callbackNotify = { 0 };
    QItemforTestTaskType SpinorTestQEle = { 0 };
    NotifyQItemfromTestTaskType uartNotify = { 0 };
    BaseType_t xResult;
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinorEl1CallbackType callback = &spinorEl1TestHiCb;
    spinorEl1userdata userdata = { 0 };

    for (;;)
    {
        /* Queue is not full, receive item */
        xResult = xFreeRTOSQueueReceive(xQHandleHiforTestTask, &SpinorTestQEle, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestHiTask: Receive from Queue failed \n\r");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }

        switch (SpinorTestQEle.opParam.opType)
        {
        case SPINOR_EL1_TEST_ERASE:
            status = spinorEl1Erase_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, callback, &userdata);
            break;

        case SPINOR_EL1_TEST_READ:
            status = spinorEl1Read_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, SpinorTestQEle.opParam.buffer, callback, &userdata);
            break;

        case SPINOR_EL1_TEST_WRITE:
            status = spinorEl1Write_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, SpinorTestQEle.opParam.buffer, callback, &userdata);
            break;

        default:
            status = SPINOR_DEVICE_FAIL;
            break;
        }

        xResult = xFreeRTOSQueueReceive(xNotifyQHandleHiforTestTask, &callbackNotify, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestHiTask: Receive from Queue failed \n\r");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }
        if (userdata.transaction_ID != callbackNotify.trans_ID)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestHiTask: Error,in obtaining correct callback receive message \r\n");
            err_fatal(SPINOR, SPINOR_DEVICE_FAIL);
        }

        /* Callback is done, send in notify queue */
        uartNotify.status = callbackNotify.status;

        /* Queue to the UART test task */
        xResult = xFreeRTOSQueueSend(xNotifyQHandleHifromTestTask, &uartNotify, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestHiTask: Error,in Queuing to UART test task queue block \r\n");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }
    }
}

/**********************************************************
 * SPINOR EL1 Low Priority Test Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void xSpinorEL1TestLoTask(void* pvParameters)
{
    NotifyQItemfromTestCBType callbackNotify = { 0 };
    QItemforTestTaskType SpinorTestQEle = { 0 };
    NotifyQItemfromTestTaskType uartNotify = { 0 };
    BaseType_t xResult;
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinorEl1CallbackType callback = &spinorEl1TestLoCb;
    spinorEl1userdata userdata = { 0 };

    for (;;)
    {
        /* Queue is not full, receive item */
        xResult = xFreeRTOSQueueReceive(xQHandleLoforTestTask, &SpinorTestQEle, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestLoTask: Receive from Queue failed \n\r");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }

        switch (SpinorTestQEle.opParam.opType)
        {
        case SPINOR_EL1_TEST_ERASE:
            status = spinorEl1Erase_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, callback, &userdata);
            break;

        case SPINOR_EL1_TEST_READ:
            status = spinorEl1Read_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, SpinorTestQEle.opParam.buffer, callback, &userdata);
            break;

        case SPINOR_EL1_TEST_WRITE:
            status = spinorEl1Write_Async(SpinorTestQEle.handle, SpinorTestQEle.opParam.byte_offset, SpinorTestQEle.opParam.byte_count, SpinorTestQEle.opParam.buffer, callback, &userdata);
            break;

        default:
            status = SPINOR_DEVICE_FAIL;
            break;
        }

        xResult = xFreeRTOSQueueReceive(xNotifyQHandleLoforTestTask, &callbackNotify, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestHiTask: Receive from Queue failed \n\r");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }
        if (userdata.transaction_ID != callbackNotify.trans_ID)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestLoTask: Error,in obtaining correct callback receive message \r\n");
            err_fatal(SPINOR, SPINOR_DEVICE_FAIL);
        }

        /* Callback is done, send in notify queue */
        uartNotify.status = callbackNotify.status;

        /* Queue to the UART test task */
        xResult = xFreeRTOSQueueSend(xNotifyQHandleLofromTestTask, &uartNotify, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "xSpinorEL1TestLoTask: Error,in Queuing to UART test task queue block \r\n");
            vFreeRTOSTaskDelay(5);
            err_fatal(SAFERTOS, xResult);
        }
    }
}

/**********************************************************
 * Spinor EL1 High Priority Test Task Resouce Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return BaseType_t [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSpinorEl1TestTaskHiResourceInit(CPUIdType_e xSchdCore)
{
    BaseType_t xCreateResult = pdPASS;

    /* Queue for Queuing item */
    if (pdPASS != xFreeRTOSQueueCreate(xQBufHiforTestTask, SPINOR_TEST_Q_LEN, SPINOR_TEST_Q_ITEM_SZ, &xQHandleHiforTestTask,&xStaticQBufHiforTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

    /* Queue for Test Status Notification */
    if (pdPASS != xFreeRTOSQueueCreate(xNotifyQBufHifromTestTask, SPINOR_UART_NOTIFY_Q_LEN, SPINOR_UART_NOTIFY_Q_ITEM_SZ, &xNotifyQHandleHifromTestTask,&xStaticNotifyQBufHifromTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

    /* Queue for Callback Test Status Notification */
    if (pdPASS != xFreeRTOSQueueCreate(xNotifyQBufHiforTestTask, SPINOR_TEST_NOTIFY_Q_LEN, SPINOR_TEST_NOTIFY_Q_ITEM_SZ, &xNotifyQHandleHiforTestTask,&xStaticNotifyQBufHiforTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

xSpinorTestTaskResourceInit_end:
    return xCreateResult;
}

/**********************************************************
 * SPINOR EL1 High Priority Test Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return BaseType_t [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSpinorEL1TestHiTaskInit(CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior)
{
    BaseType_t xResult;
    UBaseType_t uxCoreAffinityMask;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode =xSpinorEL1TestHiTask,                        /* The function that implements the task being created. */
        .pcName ="SPINOR EL1 TEST HIGH",                      /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer =&xSpinorTestTskHiTCB,                        /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer =xSpinorTestTskHiStk,                         /* The buffer allocated for use as the task stack. */
        .usStackDepth =SPINOR_TEST_TASK_STK_SZ,                     /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                                        /* The task parameter, not used in this case. */
        .uxPriority =xTaskPrior,                                  /* The priority assigned to the task being created. */
		.xRegions = {				   /* The MPU task parameters. */
			{NULL, 0UL, 0UL}, /* No additional region definitions are required. */
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL}},

    };

    /* Create the check task. */
   	uxCoreAffinityMask = (1 << xSchdCore);  //Mapped to core 2 from core 0 for testing
	xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
			NULL );
    return xResult;
}

/**********************************************************
 * Spinor EL1 Low Priority Test Task Resouce Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return BaseType_t [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSpinorEl1TestTaskLoResourceInit(CPUIdType_e xSchdCore)
{
    BaseType_t xCreateResult = pdPASS;

    /* Queue for Queuing item */
    if (pdPASS != xFreeRTOSQueueCreate(xQBufLoforTestTask, SPINOR_TEST_Q_LEN, SPINOR_TEST_Q_ITEM_SZ, &xQHandleLoforTestTask,&xStaticQBufLoforTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

    /* Queue for Test Status Notification */
    if (pdPASS != xFreeRTOSQueueCreate(xNotifyQBufLofromTestTask, SPINOR_TEST_NOTIFY_Q_LEN, SPINOR_TEST_NOTIFY_Q_ITEM_SZ, &xNotifyQHandleLofromTestTask,&xStaticNotifyQBufLofromTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

    /* Queue for Callback Test Status Notification */
    if (pdPASS != xFreeRTOSQueueCreate(xNotifyQBufLoforTestTask, SPINOR_TEST_NOTIFY_Q_LEN, SPINOR_TEST_NOTIFY_Q_ITEM_SZ, &xNotifyQHandleLoforTestTask,&xStaticNotifyQBufLoforTestTask))
    {
        xCreateResult = pdFAIL;
        goto xSpinorTestTaskResourceInit_end;
    }

xSpinorTestTaskResourceInit_end:
    return xCreateResult;
}

/**********************************************************
 * SPINOR EL1 Low Priority Test Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return BaseType_t [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSpinorEL1TestLoTaskInit(CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior)
{
    BaseType_t xResult;
    UBaseType_t uxCoreAffinityMask;
	
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode =xSpinorEL1TestLoTask,                        /* The function that implements the task being created. */
        .pcName ="SPINOR EL1 TEST LOW",                       /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer =&xSpinorTestTskLoTCB,                        /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer=xSpinorTestTskLoStk,                         /* The buffer allocated for use as the task stack. */
        .usStackDepth =SPINOR_TEST_TASK_STK_SZ,                     /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                                        /* The task parameter, not used in this case. */
        .uxPriority =xTaskPrior,                                  /* The priority assigned to the task being created. */
		.xRegions = {				   /* The MPU task parameters. */
			{NULL, 0UL, 0UL}, /* No additional region definitions are required. */
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL}},
        
    };


    /* Create the check task. */
	uxCoreAffinityMask = (1 << xSchdCore);  //Mapped to core 2 from core 0 for testing
	xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
			NULL);


    return xResult;
}

#endif
/**********************************************************
 * SPINOR EL1 async testcase 1: Write followed by read testcase
 *
 * @return status [OUT]
 *   status of the testcase
 *
 **********************************************************/
TEST_FUNC TESTerrorType_e TC_SPINOR_ASYNC_EL1_001(void)
{
#ifdef SPINOR_ASYNC_TEST
    TESTerrorType_e xReturn = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_block;
    QItemforTestTaskType spinorEl1TestQueueItem = { 0 };
    NotifyQItemfromTestTaskType spinorEl1TeststatusQueueItem = { 0 };
    BaseType_t xResult;

    result = spinorEl1Open(&el1Handle, SPINOR_USER_TYPE_EL1);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Open FAILED\r\n");
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo(el1Handle, &el1_nor_info);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] GetMemInfo FAILED\r\n");
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for (i = 0; i < (sizeof(el1_buff) / sizeof(el1_buff[0])); i++)
    {
        el1_buff[i] = i % ((sizeof(uint8)) << 8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo(el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] El1GetGptPartitionInfo FAILED\r\n");
        goto Error_loop;
    }

    if (byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Byte count validation FAILED\r\n");
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;

    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    /* Make erase message */
    spinorEl1TestQueueItem.handle = el1Handle;
    spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_ERASE;
    spinorEl1TestQueueItem.opParam.buffer = NULL;
    spinorEl1TestQueueItem.opParam.byte_offset = (byte_offset / byte_count);
    spinorEl1TestQueueItem.opParam.byte_count = num_block;

    /* Queue to the SPINOR test task */
    xResult = xFreeRTOSQueueSend(xQHandleHiforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error,in Queuing Erase message to SPINOR test task queue block \r\n");
        result = SPINOR_DEVICE_FAIL;
        goto Error_loop;
    }

    /* Receive from SPINOR test task*/
    xResult = xFreeRTOSQueueReceive(xNotifyQHandleHifromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Receive Erase notify from Notify Queue failed \n\r");
        result = SPINOR_DEVICE_FAIL;
        goto Error_loop;
    }

    result = spinorEl1TeststatusQueueItem.status;
    if (SPINOR_DEVICE_DONE != result)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error, el1 erase failed at 0x%x start block and 0x%x block count \r\n", (byte_offset / byte_count), 1);
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {
        /* Make read after erase message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_READ;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff_copy;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleHiforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error,in Queuing Read message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleHifromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Receive Read notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error, el1 read failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Erase consistency check */
        for (i = 0; i < byte_count; i++)
        {
            if (el1_buff_copy[i] != 0xFF)
            {
                DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_001]Erase data inconsistent \n\r");
                goto Error_loop;
            }
        }

        /* Make write message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_WRITE;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleHiforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error,in Queuing Write message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleHifromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Receive Write notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error, el1 write failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Make read after write message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_READ;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff_copy;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleHiforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error,in Queuing Read message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleHifromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Receive Read notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Error, el1 read failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Write consistency check */
        for (i = 0; i < byte_count; i++)
        {
            if (el1_buff[i] != el1_buff_copy[i])
            {
                DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_001] Write data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }
    if (el1Handle != NULL)
    {
        result = spinorEl1Close(el1Handle);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_001] Close 1 FAILED\n\r");
            xReturn = MODULE_TEST_FAILED;
            return xReturn;
        }
    }
    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_ASYNC_EL1_001] Erase async, Write Async followed by Read Async (Higher priority) test PASSED\r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
        result = spinorEl1Close(el1Handle);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_001] Close 2 FAILED\n\r");
            xReturn = MODULE_TEST_FAILED;
            return xReturn;
        }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_001] Erase async, Write Async followed by Read Async (Higher priority) test FAILED\r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
#else
    return MODULE_TEST_PASSED;
#endif
}

/**********************************************************
 * SPINOR EL1 async testcase 2: Write followed by read testcase
 *
 * @return status [OUT]
 *   status of the testcase
 *
 **********************************************************/
TEST_FUNC TESTerrorType_e TC_SPINOR_ASYNC_EL1_002(void)
{
#ifdef SPINOR_ASYNC_TEST
    TESTerrorType_e xReturn = MODULE_TEST_PASSED;
    SPINOR_STATUS result;
    spinor_handle_t el1Handle = NULL;
    uint32 byte_offset, byte_count, i, num_block;
    QItemforTestTaskType spinorEl1TestQueueItem = { 0 };
    NotifyQItemfromTestTaskType spinorEl1TeststatusQueueItem = { 0 };
    BaseType_t xResult;

    result = spinorEl1Open(&el1Handle, SPINOR_USER_TYPE_EL1);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Open FAILED\r\n");
        goto Error_loop;
    }

    result = spinorEl1GetMemInfo(el1Handle, &el1_nor_info);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] GetMemInfo FAILED\r\n");
        goto Error_loop;
    }

    memset(el1_buff, 0, sizeof(el1_buff));
    memset(el1_buff_copy, 0, sizeof(el1_buff_copy));

    for (i = 0; i < (sizeof(el1_buff) / sizeof(el1_buff[0])); i++)
    {
        el1_buff[i] = i % ((sizeof(uint8)) << 8);
    }

    /* We use SAIL_NOR_TEST_EL1 partition ("c4a1da4a-190a-4b9a-b02d-055dd1b717ed") to do spinor el1 test for now */
    result = spinorEl1GetGptPartitionInfo(el1Handle, "c4a1da4a-190a-4b9a-b02d-055dd1b717ed", &byte_offset, &byte_count);
    if (result != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] El1GetGptPartitionInfo FAILED\r\n");
        goto Error_loop;
    }

    if (byte_count < el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Byte count validation FAILED\r\n");
        goto Error_loop;
    }
    byte_count = el1_nor_info.pages_per_block * el1_nor_info.page_size_bytes;


    result = spinorEl1GetSectorMapInfo(el1Handle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] El1GetSectorMapInfo FAILED\r\n" );
        goto Error_loop;
    }

    /* Get num 4k block */
    num_block = el1TestGetNum4kBlock(byte_offset, &el1_sectorMapInfo);

    /* Make erase message */
    spinorEl1TestQueueItem.handle = el1Handle;
    spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_ERASE;
    spinorEl1TestQueueItem.opParam.buffer = NULL;
    spinorEl1TestQueueItem.opParam.byte_offset = (byte_offset / byte_count);
    spinorEl1TestQueueItem.opParam.byte_count = num_block;

    /* Queue to the SPINOR test task */
    xResult = xFreeRTOSQueueSend(xQHandleLoforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error,in Queuing Erase message to SPINOR test task queue block \r\n");
        result = SPINOR_DEVICE_FAIL;
        goto Error_loop;
    }

    /* Receive from SPINOR test task */
    xResult = xFreeRTOSQueueReceive(xNotifyQHandleLofromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
    if (pdPASS != xResult)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Receive Erase notify from Notify Queue failed \n\r");
        result = SPINOR_DEVICE_FAIL;
        goto Error_loop;
    }

    result = spinorEl1TeststatusQueueItem.status;
    if (SPINOR_DEVICE_DONE != result)
    {
        DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error, el1 erase failed at 0x%x start block and 0x%x block count \r\n", (byte_offset / byte_count), 1);
        goto Error_loop;
    }

    for(int j = 0; j < num_block; j++)
    {

        /* Make read after erase message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_READ;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff_copy;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleLoforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error,in Queuing Read message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleLofromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Receive Read notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error, el1 read failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Erase consistency check */
        for (i = 0; i < byte_count; i++)
        {
            if (el1_buff_copy[i] != 0xFF)
            {
                DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_002]Erase data inconsistent \n\r");
                goto Error_loop;
            }
        }

        /* Make write message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_WRITE;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleLoforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error,in Queuing Write message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleLofromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Receive Write notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error, el1 write failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Make read after write message */
        spinorEl1TestQueueItem.handle = el1Handle;
        spinorEl1TestQueueItem.opParam.opType = SPINOR_EL1_TEST_READ;
        spinorEl1TestQueueItem.opParam.buffer = el1_buff_copy;
        spinorEl1TestQueueItem.opParam.byte_offset = byte_offset;
        spinorEl1TestQueueItem.opParam.byte_count = byte_count;

        /* Queue to the SPINOR test task */
        xResult = xFreeRTOSQueueSend(xQHandleLoforTestTask, &spinorEl1TestQueueItem, pdMS_TO_TICKS(freertosMAX_DELAY));
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error,in Queuing Read message to SPINOR test task queue block \r\n");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        /* Receive from SPINOR test task */
        xResult = xFreeRTOSQueueReceive(xNotifyQHandleLofromTestTask, &spinorEl1TeststatusQueueItem, freertosMAX_DELAY);
        if (pdPASS != xResult)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Receive Read notify from Notify Queue failed \n\r");
            result = SPINOR_DEVICE_FAIL;
            goto Error_loop;
        }

        result = spinorEl1TeststatusQueueItem.status;
        if (SPINOR_DEVICE_DONE != result)
        {
            DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Error, el1 read failed at 0x%x byte offset and 0x%x byte count \r\n", byte_offset, byte_count);
            goto Error_loop;
        }

        /* Write consistency check */
        for (i = 0; i < byte_count; i++)
        {
            if (el1_buff[i] != el1_buff_copy[i])
            {
                DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_002] Write data inconsistent \n\r");
                goto Error_loop;
            }
        }

        byte_offset += byte_count;
        memset(el1_buff_copy, 0, sizeof(el1_buff_copy));
    }

    if (el1Handle != NULL)
    {
        result = spinorEl1Close(el1Handle);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_002] Close 1 FAILED\n\r");
            xReturn = MODULE_TEST_FAILED;
            return xReturn;
        }
    }
    DEBUG_LOG(SAIL_INFO, "[TC_SPINOR_ASYNC_EL1_002] Erase async, Write Async followed by Read Async (Lower priority) test PASSED\r\n");

    goto spinor_el1_test_end;

Error_loop:
    if (el1Handle != NULL)
    {
        result = spinorEl1Close(el1Handle);
        if (result != SPINOR_DEVICE_DONE)
        {
            DEBUG_LOG(SAIL_ERROR, "\n[TC_SPINOR_ASYNC_EL1_002] Close 2 FAILED\n\r");
            xReturn = MODULE_TEST_FAILED;
            return xReturn;
        }
    }

    DEBUG_LOG(SAIL_ERROR, "[TC_SPINOR_ASYNC_EL1_002] Erase async, Write Async followed by Read Async (Lower priority) test FAILED\r\n");
    xReturn = MODULE_TEST_FAILED;

spinor_el1_test_end:
    return xReturn;
#else
    return MODULE_TEST_PASSED;
#endif
}

TEST_FUNC TESTerrorType_e TestOSPINOR_El1_Wrapper( void )
{
    uint8 uspinorEL1TestsCount =  spinorEL1TOTALTESTCASES;

    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_001())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_002())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_003())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_004())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_005())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_006())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_007())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_008())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_009())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_010())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_011())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_012())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_013())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_014())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_015())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_016())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_017())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_018())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_019())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_EL1_binCmdTest())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_ASYNC_EL1_001())
    {
        uspinorEL1TestsCount--;
    }
    if (MODULE_TEST_PASSED != TC_SPINOR_ASYNC_EL1_002())
    {
        uspinorEL1TestsCount--;
    }
    if (spinorEL1TOTALTESTCASES == uspinorEL1TestsCount)
    {
        DEBUG_LOG(SAIL_WARNING, ">>>>> SPINOR EL1 all test cases passed <<<<<\n\r");
        return MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR, ">>>>> SPINOR EL1 all test cases not passed <<<<<\n\r");
        return MODULE_TEST_FAILED;
    }
}


TEST_FUNC TESTerrorType_e xOSPINORDVTestWrapper(void)
{
    //uint8 ulcpu_ID = get_curr_phys_cpu_num();
    TESTerrorType_e xReturn  = MODULE_TEST_PASSED;
    SPINOR_STATUS result_el1;

    result_el1 = spinorEl1IsDeviceAlive();
    if( result_el1 != SPINOR_DEVICE_DONE )
    {
        //DebugPrint_DVTask(DVTASK_FAILED,1);
        xReturn = MODULE_TEST_FAILED;
    }

    return xReturn;
 }


#endif
