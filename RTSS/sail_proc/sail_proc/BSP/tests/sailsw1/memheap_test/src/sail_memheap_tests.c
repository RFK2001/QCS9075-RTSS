/*******************************************************************************
**                                                                            **
** Copyright (C)  2021 Qualcomm Technologies, Inc. (2021)                     **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Qualcomm       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : sail_memheap_tests.c                                                 **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2020-12-06                                                  **
**                                                                            **
**  PLATFORM     : Qualcomm SMSS                                              **
**                                                                            **
**  AUTHOR       : SMSS SW DEV                                                **
**                                                                            **
**  VENDOR       : Qualcomm Technologies, Inc.                                **
**                                                                            **
**  DESCRIPTION  : sail_memheap test file                                              **
**                                                                            **
**  SPECIFICATION(S) : Unit test specification                                **
**                                                                            **
**                                                                            **
*******************************************************************************/

#include "tests.h"
#include "sail_memheap.h"
#include "IPCC.h"
#include "debug_log.h"
#include "common_functions.h"
#include <stdlib.h>

#define MAX_TEST_BLOCKS         10

TEST_DATA static eMemheaphandle heapHandle;
TEST_DATA volatile uint8 *arrayOfPtrs[MAX_TEST_BLOCKS] = {0};

TEST_FUNC static uint8 findFree( void )
{
    for(int i = 0; i < MAX_TEST_BLOCKS; i++)
    {
        if(NULL == arrayOfPtrs[i])
        {
            return i;
        }
    }

    return 0xFF;
}

TEST_FUNC static uint64 chatToInt(char *str)
{
    uint64 ullresult = 0x0u;
    uint8 ucIndex = 0x0u;

    for( ucIndex = 0x0u ; str[ucIndex]!= '\0' ; ucIndex++)
    {
        ullresult = ullresult*10u + (str[ucIndex]-'0');
    }

    return ullresult;
}

TEST_FUNC void xSailMemheapTestShell(uint8 *find)
{
    volatile uint8 signal = 0;
    uint64 heapStartAddress = 0;
    uint32 heapSize = 0;
    uint32 memSize = 0;
    uint32 usedBytes = 0;
    uint8 blockId = 0;
    volatile uint8 arrayIdx = 0;   

    find = APPL_SAIL_Shell_gettoken(NULL);

    // test command: memheap init <start_adddress_of_heap> <heap_size>
    if(APPL_SAIL_Shell_stricmp("init",(char*)find))
    {

        find = APPL_SAIL_Shell_gettoken(NULL);
        heapStartAddress = chatToInt((char *)find);
        
        find = APPL_SAIL_Shell_gettoken(NULL);
        heapSize = chatToInt((char *)find);

        if( 0 != sail_heap_init(&heapHandle, ((void *)(uintptr_t)heapStartAddress), heapSize))
        {
            DEBUG_LOG(SAIL_INFO,"[MEMHEAP_INIT] at start addr: 0x%X, heap size: %ld failed \n\r",heapStartAddress, heapSize);
        }
        DEBUG_LOG(SAIL_INFO,"[MEMHEAP_INIT] at start addr: 0x%X, heap size: %ld passed \n\r",heapStartAddress, heapSize);
    }
    // test command: memheap alloc <memory_size>
    else if(APPL_SAIL_Shell_stricmp("alloc",(char*)find))
    {

        find = APPL_SAIL_Shell_gettoken(NULL);
        memSize = chatToInt((char *)find);
        arrayIdx = findFree();

        if(arrayIdx >= MAX_TEST_BLOCKS)
        {
            DEBUG_LOG(SAIL_INFO,"[MEMHEAP_ALLOC] max number of blocks reached. Failed \n\r");
            return;
        }

        arrayOfPtrs[arrayIdx] = sail_heap_malloc(&heapHandle, memSize);
        if( 0 == arrayOfPtrs[arrayIdx])
        {
            DEBUG_LOG(SAIL_INFO,"[MEMHEAP_ALLOC] of size: %ld failed \n\r",memSize);
            return;
        }
        DEBUG_LOG(SAIL_INFO,"[MEMHEAP_ALLOC] Blk_id : %d of size: %ld at address 0x%X passed\n\r",arrayIdx, memSize, arrayOfPtrs[arrayIdx]);
        
    }
    // test command: memheap free <block_id>
    else if(APPL_SAIL_Shell_stricmp("free",(char*)find))
    {
        find = APPL_SAIL_Shell_gettoken(NULL);
        blockId = chatToInt((char *)find);

        if(blockId >= arrayIdx)
        {
            DEBUG_LOG(SAIL_INFO,"[MEMHEAP_FREE] of size: %ld failed \n\r",memSize);
            return;
        }

        sail_heap_free(&heapHandle, (void *)arrayOfPtrs[arrayIdx]);
        if( 0 != arrayOfPtrs[arrayIdx])
        {
            DEBUG_LOG(SAIL_INFO,"[MEMHEAP_FREE] of size: %ld failed \n\r",memSize);
        }
        DEBUG_LOG(SAIL_INFO,"[MEMHEAP_FREE] of size: %ld at address passed\n\r",memSize);   
    }

    if(heapHandle.nHeapHasInit)
    {
        usedBytes = heapHandle.pHeapDesc.used_bytes;
        DEBUG_LOG(SAIL_INFO,"[MEMHEAP] used heap %ld, available heap: %ld\n\r",usedBytes, (heapHandle.pHeapDesc.total_bytes - usedBytes));
    }

}
TEST_FUNC TESTerrorType_e xTestSAILMemHeapWrapper()
{
#if 0
    volatile uint8 *arrayOfPtrs[10] = {0};
    volatile uint8 arrayIdx = 0, heapIdx = 0;
    volatile size_t size = 0, heapSize = TEST_HEAP_SIZE;
    volatile uint8 doNotExit = 1;
    volatile uint8 value = 0xA;
    volatile uint8 nMemHeapTestState = 0xff;
    test_heap = 0x8210000;
    uint8  nCurrCPU = get_curr_phys_cpu_num();
    uint8 testCase = 0xff;

    switch(testCase)
    {
        case 0:
        
        break;

        case 1:
            sail_heap_init(&heapHandle, (void *)test_heap, heapSize);
            DEBUG_LOG(SAIL_INFO, "Heap Init done on core %d\n\r", nCurrCPU);
        break;

        case 2:
            arrayOfPtrs[arrayIdx++] = sail_heap_malloc(&heapHandle, size);
            DEBUG_LOG(SAIL_INFO, "Memalloc done at address: %X on core %d\n\r", arrayOfPtrs[(arrayIdx - 1)], nCurrCPU);
        break;

        case 3:
            sail_heap_free(&heapHandle, (void *)arrayOfPtrs[arrayIdx]);
            DEBUG_LOG(SAIL_INFO, "Memfree done on core %d\n\r", nCurrCPU);
        break;

        case 4:
            memset((void *)arrayOfPtrs[arrayIdx], value, size);
            DEBUG_LOG(SAIL_INFO, "Memset done on core %d\n\r", nCurrCPU);
        break;

        case 5:
        break;

    }
#endif
    return MODULE_TEST_PASSED;
}