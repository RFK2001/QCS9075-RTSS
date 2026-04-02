/*===============================================================================
Copyright (c) 2018-2025 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
=============================================================================*/

#include "cache_ops.h"
#include "sail_memheap.h"
#include "common_functions.h"
#include <stdlib.h>

/* To be removed once PRNG support is available*/
static uint32 BSP_UNPRIV_DATA magic_num[MAX_HEAP_INIT] = {(uint32)-1,(uint32)-1,(uint32)-1,(uint32)-1,(uint32)-1};
static uint16 BSP_UNPRIV_DATA magic_num_index_array[MAX_HEAP_INIT] = {0,1,2,3,4};
static mem_magic_number_struct BSP_UNPRIV_DATA magic_mem_st =
{
  &magic_num[0],
  &magic_num_index_array[0],
  0
};

/* =========================================================================
**  Function : sail_heap_init
** =========================================================================*/
int sail_heap_init(eMemheaphandle *pHandler, void *pHeapStartAddress, uint32 nHeapSize)
{
    /* mem_malloc heap service api doesn't support size more than 32 bits */
    /* typecast dwSize to max supported size_t to accommodate all targets */
    if(((uint64)nHeapSize >> 32) & 0xFFFFFFFFULL)
    {
      //HYP_LOG_ERR("size requested more than 32 bits");
      return MEMHEAP_FAILURE;
    }

    /* check if the handle is not initialised already */
    if(pHandler == NULL)
    {
      return MEMHEAP_FAILURE;
    }
    
    if(!pHandler->nHeapHasInit)
    {

      pHandler->pMemMagicNumber = (mem_magic_number_struct *) &magic_mem_st;

      pHandler->pHeapStartAddress = pHeapStartAddress;
      pHandler->nHeapSize = nHeapSize;

      if(MEMHEAP_SUCCESS != mem_init_heap( &(pHandler->pHeapDesc), pHandler->pMemMagicNumber, pHandler->pHeapStartAddress, pHandler->nHeapSize)) 
      {
        return MEMHEAP_FAILURE;
      }
      pHandler->nHeapHasInit = 1;

    }


    return MEMHEAP_SUCCESS;
}

/* =========================================================================
**  Function : sail_heap_malloc
** =========================================================================*/
void* sail_heap_malloc(eMemheaphandle *pHandler, size_t dwSize)
{
  /* mem_malloc heap service api doesn't support size more than 32 bits */
  /* typecast dwSize to max supported size_t to accommodate all targets */
  if(((uint64)dwSize >> 32) & 0xFFFFFFFFULL)
  {
    //HYP_LOG_ERR("size requested more than 32 bits");
    return NULL;
  }

  if(pHandler != NULL && pHandler->nHeapHasInit )
  {
      return mem_malloc( &(pHandler->pHeapDesc), pHandler->pMemMagicNumber, dwSize );
  }

  return NULL;
}

/* =========================================================================
**  Function : sail_heap_free
** =========================================================================*/
void sail_heap_free(eMemheaphandle *pHandler, void *pMem)
{

  if(pHandler != NULL && pHandler->nHeapHasInit )
  {
      mem_free( &(pHandler->pHeapDesc), pHandler->pMemMagicNumber, pMem );
  }
}

/* =========================================================================
**  Function : sail_heap_deinit
** =========================================================================*/
int sail_heap_deinit(eMemheaphandle *pHandler)
{
  if(pHandler != NULL && pHandler->nHeapHasInit )
  {
    if(MEMHEAP_SUCCESS != mem_deinit_heap(&(pHandler->pHeapDesc), pHandler->pMemMagicNumber))
    {
        return MEMHEAP_FAILURE;
    }
    pHandler->nHeapHasInit = 0;
    
    return MEMHEAP_SUCCESS;
  }

  return MEMHEAP_FAILURE;
}

