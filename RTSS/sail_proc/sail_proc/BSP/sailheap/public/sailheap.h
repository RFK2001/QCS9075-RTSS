/*
===========================================================================
*/
/**
    @file  sailheap.h
    @brief Types definitions
 *         Header file for the definition of types used in sail

*/
/*
    ===========================================================================

    Copyright (c) 2023-2025 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#ifndef SAILHEAP_H
#define SAILHEAP_H

#include "types.h"

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
int sailheap_init(void *pHeapSpinlockAddr, void *pHeapStartAddress, uint32 nHeapSize);

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
void* sailheap_malloc(size_t dwSize);

/* =========================================================================
**  Function : sail_heap_free
** =========================================================================*/
/**
  Allocates the memory on an already initialised heap.

  This function shall be called only after a heap is initialised sucessfully
  by calling api sail_heap_init(). 

  @param
  pMem:              Pointer to memory to be de-allocated
  @return
  None.

  @dependencies
  None.
*/
void sailheap_free(void *pMem);

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
int sailheap_deinit(void);

#endif