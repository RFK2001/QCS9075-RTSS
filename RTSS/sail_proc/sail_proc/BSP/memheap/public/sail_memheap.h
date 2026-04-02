/*
===========================================================================
*/
/**
    @file  sail_memheap.h
    @brief Types definitions
 *         Header file for the definition of types used in sail

*/
/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/yyesodha.bsp.sail.1.0.ipcc_el1_refactor/memheap/inc/sail_memheap.h#1 $
    $DateTime: 2022/03/14 00:32:37 $
    $Author: yyesodha $

    ===========================================================================
*/

#ifndef SAIL_MEMHEAP_H
#define SAIL_MEMHEAP_H

#include "types.h"
#include "memheap_lite.h"

/*handle type for heap allocator*/
typedef struct
{
    mem_heap_type               pHeapDesc;
    mem_magic_number_struct*    pMemMagicNumber;
    void*                       pHeapStartAddress;
    uint32                      nHeapSize;
    uint8                       nHeapHasInit;                    
}eMemheaphandle;

/* =========================================================================
**  Function : sail_heap_init
** =========================================================================*/
/**
  Initialize sail heap.

  This function initializes heap start from pHeapStartAddress with size of 
  nHeapSize. 

  @param
  pAllocatorHandle:  Pointer to hold the heap_handle. Caller can cast a uintptr_t 
                     to void *.
  pHeapStartAddress: Start address of the heap
  nHeapSize:         Size fo the heap
  @return
  MEMHEAP_FAILURE:   Heap initialisation Failed
  MEMHEAP_SUCCESS:   Heap initialised successfully

  @dependencies
  None.
*/
int sail_heap_init(eMemheaphandle *pHandler, void *pHeapStartAddress, uint32 nHeapSize);

/* =========================================================================
**  Function : sail_heap_malloc
** =========================================================================*/
/**
  Allocates the memory on an already initialised heap.

  This function shall be called only after a heap is initialised sucessfully
  by calling api sail_heap_init(). 

  @param
  pAllocatorHandle:  Pointer to the heap_handle which was earlier passed to
                     sail_heap_init() for initialising heap
  dwSize:            Size of memory to be allocated
  @return
  NULL:              Memory Allocation failed
  void *:            Memory Allocated successfully

  @dependencies
  None.
*/
void* sail_heap_malloc(eMemheaphandle *pHandler, size_t dwSize);

/* =========================================================================
**  Function : sail_heap_free
** =========================================================================*/
/**
  Allocates the memory on an already initialised heap.

  This function shall be called only after a heap is initialised sucessfully
  by calling api sail_heap_init(). 

  @param
  pAllocatorHandle:  Pointer to the heap_handle which was earlier passed to
                     sail_heap_init() for initialising heap
  pMem:              Pointer to memory to be de-allocated
  @return
  None.

  @dependencies
  None.
*/
void sail_heap_free(eMemheaphandle *pHandler, void *pMem);

/* =========================================================================
**  Function : sail_heap_deinit
** =========================================================================*/
/**
  Allocates the memory on an already initialised heap.

  This function shall be called only after a heap is initialised sucessfully
  by calling api sail_heap_init(). 

  @param
  pAllocatorHandle:  Pointer to the heap_handle which was earlier passed to
                     sail_heap_init() for initialising heap
  @return
  MEMHEAP_FAILURE:   Heap initialisation Failed
  MEMHEAP_SUCCESS:   Heap initialised successfully

  @dependencies
  None.
*/
int sail_heap_deinit(eMemheaphandle *pHandler);

#endif