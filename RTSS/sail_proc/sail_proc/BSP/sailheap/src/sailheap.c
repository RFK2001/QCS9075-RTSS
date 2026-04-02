/*===============================================================================
Copyright (c) 2018-2019 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#include "cache_ops.h"
#include "sail_memheap.h"
#include "sailheap.h"
#include "sailbsp_mutex.h"
#include <stdlib.h>
#include "debug_log.h"

#define SIZE_1K 0x400
#define SIZE_7K 0x1C00

#ifdef SAILEL2

static eMemheaphandle gSailHeapLBinHandler;
static eMemheaphandle gSailHeapSBinHandler;
static mutex_t *pHeapMutex = NULL;
/* =========================================================================
**  Function : sailheap_init
** =========================================================================*/
int sailheap_init(void *pHeapSpinlockAddr, void *pHeapStartAddress, uint32 nHeapSize)
{
    int slRet = MEMHEAP_FAILURE;
    eMemheaphandle *pHandler = NULL;
 
    if(nHeapSize ==  SIZE_7K)
    {
        pHandler = &gSailHeapSBinHandler;
    }
    else
    {
        pHandler = &gSailHeapLBinHandler;
    }    
 
    pHeapMutex = pHeapSpinlockAddr;
    
    /* check if the global spin lock address is valid */
    if(pHeapMutex == NULL)
    {
      return MEMHEAP_FAILURE;
    }
    slRet= sail_heap_init(pHandler, pHeapStartAddress, nHeapSize);
    if (slRet == MEMHEAP_SUCCESS)
    {
        mutex_init(pHeapMutex);
    }
    return slRet;
}
/* =========================================================================
**  Function : sail_heap_malloc
** =========================================================================*/
void* sailheap_malloc(size_t dwSize)
{
    eMemheaphandle *pHandler;
    void *tmp = NULL;
    
    if(dwSize <=  32 )
    {
        pHandler = &gSailHeapSBinHandler;
    }
    else
    {
        pHandler = &gSailHeapLBinHandler;
    }
    
    mutex_lock(pHeapMutex);
    tmp = sail_heap_malloc(pHandler, dwSize);
    mutex_unlock(pHeapMutex);
    return tmp;
}
/* =========================================================================
**  Function : sail_heap_free
** =========================================================================*/
void sailheap_free(void *pMem)
{
    eMemheaphandle *pHandler;  
    if(pMem == NULL)
        return;
    
    if(pMem >= gSailHeapSBinHandler.pHeapStartAddress && 
       pMem < (gSailHeapSBinHandler.pHeapStartAddress + gSailHeapSBinHandler.nHeapSize) )
    {
        pHandler = &gSailHeapSBinHandler;
    }
    else if(pMem >= gSailHeapLBinHandler.pHeapStartAddress && 
            pMem < (gSailHeapLBinHandler.pHeapStartAddress + gSailHeapLBinHandler.nHeapSize) )
    {
        pHandler = &gSailHeapLBinHandler;
    }
    else
    {
        return;
    }
    
    mutex_lock(pHeapMutex);
    sail_heap_free(pHandler, pMem);
    mutex_unlock(pHeapMutex);
}
/* =========================================================================
**  Function : sail_heap_deinit
** =========================================================================*/
int sailheap_deinit(void)
{
    int slRet = MEMHEAP_FAILURE;
    eMemheaphandle *pHandler;  
    
    pHandler = &gSailHeapSBinHandler;
    slRet = sail_heap_deinit(pHandler);
        
    pHandler = &gSailHeapLBinHandler;
    //Its either sucecss or failure so we can "or" the return values.
    slRet |= sail_heap_deinit(pHandler);
    
    return slRet;
}

#else
#define SAILBSP_HEAP_DATA __attribute__ ( ( section ( "sailbsp_heap_data" ) ) )
SAILBSP_HEAP_DATA static eMemheaphandle gSailHeapHandler[4];
SAILBSP_HEAP_DATA static mutex_t *pHeapMutex[4] = {NULL, NULL, NULL, NULL};
uint get_curr_phys_cpu_num(void);
/* =========================================================================
**  Function : sailheap_init
** =========================================================================*/
int sailheap_init(void *pHeapSpinlockAddr, void *pHeapStartAddress, uint32 nHeapSize)
{
    int slRet = MEMHEAP_FAILURE;
    uint32_t cpu = get_curr_phys_cpu_num();
    eMemheaphandle *pHandler = &gSailHeapHandler[cpu];
    pHeapMutex[cpu] = pHeapSpinlockAddr;
    
    /* check if the global spin lock address is valid */
    if(pHeapMutex[cpu] == NULL)
    {
      return MEMHEAP_FAILURE;
    }
    slRet= sail_heap_init(pHandler, pHeapStartAddress, nHeapSize);
    if (slRet == MEMHEAP_SUCCESS)
    {
        mutex_init(pHeapMutex[cpu]);
    }
    return slRet;
}
/* =========================================================================
**  Function : sail_heap_malloc
** =========================================================================*/
void* sailheap_malloc(size_t dwSize)
{
    uint32_t cpu = get_curr_phys_cpu_num();
    eMemheaphandle *pHandler = &gSailHeapHandler[cpu];
    void *tmp = NULL;
    
    mutex_lock(pHeapMutex[cpu]);
    tmp = sail_heap_malloc(pHandler, dwSize);
    mutex_unlock(pHeapMutex[cpu]);
    return tmp;
}
/* =========================================================================
**  Function : sail_heap_free
** =========================================================================*/
void sailheap_free(void *pMem)
{
    uint32_t cpu = get_curr_phys_cpu_num();
    eMemheaphandle *pHandler = &gSailHeapHandler[cpu];
    
    mutex_lock(pHeapMutex[cpu]);
    mem_block_header_type *theBlock;
    theBlock = (mem_block_header_type *) ((char *) pMem - sizeof(mem_block_header_type));
    if(!theBlock->free_flag){
        sail_heap_free(pHandler, pMem);
    }else{
        /*The memory block is free already*/
    }
    mutex_unlock(pHeapMutex[cpu]);
}
/* =========================================================================
**  Function : sail_heap_deinit
** =========================================================================*/
int sailheap_deinit(void)
{
    int slRet = MEMHEAP_FAILURE;
    uint32_t cpu = get_curr_phys_cpu_num();
    eMemheaphandle *pHandler = &gSailHeapHandler[cpu];
    
    slRet = sail_heap_deinit(pHandler);
    
    return slRet;
}
#endif