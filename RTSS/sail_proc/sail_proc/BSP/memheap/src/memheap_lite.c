/* =========================================================================

DESCRIPTION
  Implementation of a simple sub-allocator to manage memory allocations
  and deallocations using a Next Fit strategy.

Copyright (c) 1997-2018, 2020 by QUALCOMM Technologies Incorporated.  All Rights Reserved.
============================================================================ */

/* =========================================================================

                             Edit History

$PVCSPath: O:/src/asw/COMMON/vcs/memheap.c_v   1.2   22 Mar 2002 16:54:42   rajeevg  $

when       who     what, where, why
--------   ---     ---------------------------------------------------------
07/12/17   nk      Added dynamic sections support to memheap
02/27/17   rks     Best fit 
01/05/17   nk      Added fix for input size validation
08/10/12   rks     Added XOR based guard byte for integrity checks
17/05/12   rks     fix for CR362308
013/04/12  rks     memheap2
09/03/12   rks     Use OSAL for OS abstraction and remove OS specific code/featurization
08/04/010  sri     Added checks for size variable overflow in mem_malloc()
08/04/009  sri     Added NULL checks where ever applicable
06/01/009  sri     Avoid compiler warnings based on MEMHEAP_ASSERT_NONE
04/14/009  sri     Replaced sprintf, strcat with snprintf, std_strlcat
                   respectively, memheap_write_data_to_file() is changed to
                   return void.
03/31/009  sri     qmutex attribute updated for qmutex_create()
09/01/004   gr     Deleted the context argument to the debug versions of
                   the memheap functions; the context is no longer used.
04/06/04    gr     Fixed a bug in the definition of the BEGIN_CRITICAL_SECTION
                   and END_CRITICAL_SECTION macros.
11/25/03    gr     Fixes for compiler warnings when FEATURE_MEM_DEBUG is
                   turned on.
11/18/03    rj     Added check for mem_malloc success before saving header
                   info.
11/07/03    gr     More debug support.
09/23/03    gr     Added functions to retrieve information about a heap.
09/19/03    gr     Added functionality to store information in flash when
                   an ASSERT fails.
09/17/03    gr     Mainlined FEATURE_HEAP_DEBUG. Added support for storing a
                   filename hash and a line number in the block header.
07/08/03    gr     Simplified mem_heap_task_lock and mem_heap_task_free.
06/26/03    gr     Renamed ASSERT to MEMHEAP_ASSERT. By default, MEMHEAP_ASSERT
                   throws a fatal error and prints out the task id.
06/25/03    gr     Added more ASSERTS. Changed the behavior of
                   FEATURE_MEM_DEBUG to keep just the last n stores and
                   frees. The id of the allocating task is now stored in
                   the info array. Set the block header pad to a non-zero
                   value to try and catch heap corruption.
06/21/03    gr     Added ASSERTS in mem_realloc and mem_free to catch bad
                   pointers passed in.
06/03/03   kjm     Fixed problem in realloc when block is actually grown.
                   If nextBlock is pointing to the free block merged onto
                   the end of the grown block, nextBlock was failing to
                   get updated to point to the following block.
03/11/03    gr     Added support for a heap-specific locking mechanism. This
                   allows some heaps to be restricted to task-context use,
                   and others to be usable from ISRs.
01/20/03   lad     Changed critical section macros to use INTLOCK() instead
                   of TASKLOCK().  Featurized ASSERT calls to optimize.
03/22/02    gr     Corrected a bug in mem_malloc.
10/10/01    gr     BEGIN_CRITICAL_SECTION and END_CRITICAL_SECTION now map
                   to TASKLOCK and TASKFREE, instead of to rex_enter_crit_sect
                   and rex_leave_crit_sect.
10/01/01    gr     Added support for some basic heap statistics.
11/09/00   jct     Revised for coding standard, integrate with REX critical
                   sections
09/09/99   kjm     Added even more ASSERTs to detect corrupt heaps.
04/22/99   kjm     mem_realloc now correctly updates used_bytes, max_used and
                     max_request.
02/17/99   kjm     Added realloc function.  Added support for two
                     variations of heap block headers.  Support backing up
                     and auto-reset when last block is freed to reduce
                     fragmentation.
11/24/98   kjm     Ported to C-only code for use in phone software from
                     original SubAllocator.cp file.
08/22/97   kjm     Original SubAllocator.cp file created.
============================================================================ */


/* ------------------------------------------------------------------------
** Includes
** ------------------------------------------------------------------------ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "memheap_lite.h"
#include "sailbsp_mutex.h"
//#include "stringl.h"

/* ------------------------------------------------------------------------
** Defines
** ------------------------------------------------------------------------ */

#define MEMHEAP2_BINSIZE0         (0x00000010)
#define MEMHEAP2_BINSIZE1         (0x00000020)
#define MEMHEAP2_BINSIZE2         (0x00000040)
#define MEMHEAP2_BINSIZE3         (0x00000060)
#define MEMHEAP2_BINSIZE4         (0x000000C0)
#define MEMHEAP2_BINSIZE5         (0x00000100)
#define MEMHEAP2_BINSIZE6         (0x00000150)
#define MEMHEAP2_BINSIZE7         (0x00000300)
#define MEMHEAP2_BINSIZE8         (0x00000600)
#define MEMHEAP2_BINSIZE9         (0x00000C00)
#define MEMHEAP2_BINSIZE10        (0x00002000)
#define MEMHEAP2_BINSIZE11        (0x00004000)
#define MEMHEAP2_BINSIZE12        (0x00008000)
#define MEMHEAP2_BINSIZE13        (0x00010000)
#define MEMHEAP2_BINSIZE14        (0x00020000)
#define MEMHEAP2_BINSIZE15        (0xFFFFFFFF)
#define MIN_HEAP_SIZE_FOR_BINS    (0x00019000)
#ifndef UINT32_MAX
#define UINT32_MAX 0xFFFFFFFFu
#endif

#define memscpy(dest,destsize,src,srcsize) memcpy(dest,src,srcsize)
#define BLOCK_SIZE(temp) ((mem_block_header_type*)(temp))->forw_offset

#define ADD_NEXT_TO_FREEBLOCK(freeBlock, next) \
      if((char*)(freeBlock)>(char*)(next)) \
      {\
         ((mem_block_header_type *)freeBlock)->next_freeBlk_forw_offset = (char*)freeBlock-(char*)(next);\
         ((mem_block_header_type*)freeBlock)->next_freeBlk_offset_sign=TRUE;\
      }\
      else{\
         ((mem_block_header_type *)freeBlock)->next_freeBlk_forw_offset = (char*)(next)-(char*)freeBlock;\
         ((mem_block_header_type*)freeBlock)->next_freeBlk_offset_sign=FALSE;\
      }\

#define NEXT_BLOCK_POINTER(temp) ((((mem_block_header_type*)(temp))->next_freeBlk_offset_sign == 0)?(mem_block_header_type*)(((char*)(temp)+((mem_block_header_type*)temp)->next_freeBlk_forw_offset)) : (mem_block_header_type*)(((char*)(temp)-((mem_block_header_type*)temp)->next_freeBlk_forw_offset)))

#define OVERFLOW_CHECK(elt_count, elt_size) (!(elt_count >= (1U<<10) || elt_size >= (1U<<22)) || ((((uint64)elt_count * (uint64)elt_size) >> 32) == 0))

#define BOUNDARY_CHECK_SECTIONS(theBlock, heap_ptr) ((theBlock >= ((mem_heap_type*)heap_ptr)->sections[((mem_block_header_type *)theBlock)->section_index].start_addr) && (theBlock < (mem_block_header_type *)((char*)(((mem_heap_type*)heap_ptr)->sections[((mem_block_header_type *)theBlock)->section_index].start_addr) + ((mem_heap_type*)heap_ptr)->sections[((mem_block_header_type *)theBlock)->section_index].size)))

#define FRD_OFFSET_CHECK_SECTIONS(block, heap_ptr) (((((mem_block_header_type *)block)->forw_offset + (char *)block) > (char *)block)\
   && ((((mem_block_header_type *)block)->forw_offset + (char *)block) <= ((((char*)((mem_heap_type*)heap_ptr)->sections[((mem_block_header_type *)block)->section_index].start_addr) + ((mem_heap_type*)heap_ptr)->sections[((mem_block_header_type *)block)->section_index].size))))


//#define MEMHEAP_VERIFY_HEADER(block, heap_ptr) (((mem_block_header_type *)block)->header_guard == ((mem_heap_type*)heap_ptr)->block_header_guard ? TRUE : FALSE)

/* XOR based Guard byte calculations and restore */
#define INTEGRITY_CHECK_ON_USED_HEADER(magic_num_used, block) \
            (block[0]^block[1]^block[2]^block[3]^block[4]^block[5]^magic_num_used)


#define INTEGRITY_CHECK_ON_FREE_HEADER(magic_num_free, block) \
            (block[0]^block[1]^block[2]^block[3]^block[4]^block[5]^block[6]^block[7]^magic_num_free)


#define ADD_GUARD_BYTES_TO_USED_HEADER(magic_num_used, block) \
            (block[0] = block[1]^block[2]^block[3]^block[4]^block[5]^magic_num_used)


#define ADD_GUARD_BYTES_TO_FREE_HEADER(magic_num_free, block) \
            (block[0] = block[1]^block[2]^block[3]^block[4]^block[5]^block[6]^block[7]^magic_num_free)



/*#define MAX_HEAP_INIT 5
uint32 magic_num[MAX_HEAP_INIT] = {(uint32)-1,(uint32)-1,(uint32)-1,(uint32)-1,(uint32)-1};
uint16 magic_num_index_array[MAX_HEAP_INIT] = {0,1,2,3,4};
uint16 magic_num_index = 0; */
#define OSAL_SUCCESS 0
#define OSAL_FAILURE 1

typedef struct frd_Offset_info_type{
  uint32 pad;
  uint32 freeBlock_frdOff;
}frd_Offset_info;

#define osal_crit_sect_t mutex_t

#ifdef AUTOSAR_ETH_BUILD
static int osal_enter_crit_sect(osal_crit_sect_t* critical_section){ return OSAL_SUCCESS;}
static int osal_exit_crit_sect(osal_crit_sect_t* critical_section){ return OSAL_SUCCESS;}
static int osal_init_crit_sect(osal_crit_sect_t* critical_section){ return OSAL_SUCCESS;}
static int osal_delete_crit_sect(osal_crit_sect_t* critical_section){ memset(critical_section, 0, sizeof(osal_crit_sect_t)); return OSAL_SUCCESS;}
#else
static int osal_enter_crit_sect(osal_crit_sect_t* critical_section){ mutex_lock(critical_section); return OSAL_SUCCESS;}
static int osal_exit_crit_sect(osal_crit_sect_t* critical_section){ mutex_unlock(critical_section) ; return OSAL_SUCCESS;}
static int osal_init_crit_sect(osal_crit_sect_t* critical_section){ return (mutex_init(critical_section) != (uint64_t)0ULL) ? OSAL_FAILURE : OSAL_SUCCESS;}
static int osal_delete_crit_sect(osal_crit_sect_t* critical_section){ memset(critical_section, 0, sizeof(osal_crit_sect_t)); return OSAL_SUCCESS;}    
#endif

#define MEMHEAP_ASSERT( xx_exp, ret ) \
    if( !(xx_exp) ) \
    { \
       return ret; \
    } \


static mem_block_header_type *mem_find_free_block(
   mem_heap_type *heap_ptr,
     /*  The heap to search for a free block
     */
   uint32  size_needed
     /*  The minimum size in bytes of the block needed (this size
         INCLUDES the size of the memory block header itself)
     */
);


typedef struct mem_heap_block_iterator_struct {
  const mem_heap_type   *mAllocator;
  mem_block_header_type *mBlock;
} mem_heap_block_iterator_type;



/* Code to enter and exit critical sections.
*/
   #define BEGIN_CRITICAL_SECTION(heap) \
     do { \
       if ((heap)->lock_fnc_ptr) \
         (heap)->lock_fnc_ptr(heap); \
     } while (0)
   #define END_CRITICAL_SECTION(heap) \
     do { \
       if ((heap)->free_fnc_ptr) \
         (heap)->free_fnc_ptr(heap); \
     } while (0)

static int mem_init_block_header(mem_block_header_type *, uint32, mem_heap_type *hep_ptr);

/*API to get caller ptr at different level*/
static inline uint32 memheap_get_return_address(uint32 level)
{
	register uint64 result;

  	 level-- ;
	__asm("MOV %0, FP\n" : "=r" (result));

    while(level--){
	result = *((uint64 *)(uintptr_t)result);
	}

    /*Calculating LR by adding 8 bytes to FP*/
	result = *((uint64 *)(uintptr_t)(result + 8));
	return (uint32)result;
}

#ifdef FEATURE_MEM_DEBUG
#ifndef MEM_HEAP_CALLER_ADDRESS_LEVEL
#define MEM_HEAP_CALLER_ADDRESS_LEVEL 3
#endif
#if defined(FEATURE_QDSP6)
 #define  MEM_HEAP_CALLER_ADDRESS(level) ((void *)__builtin_return_address(level));
#else
 #define MEM_HEAP_CALLER_ADDRESS(level) (memheap_get_return_address(level))
#endif
#endif

 /*static void MEMHEAP_ASSERT_FUNC(const char* format)
 {
        TCB_TYPE  self = TCB_SELF();
    ERR_FATAL( "In task 0x%x, Assertion " + format + " failed",, (uint32) self, 0, 0 );
 }*/

//#define MEMHEAP_ASSERT( xx_exp )

//static void mem_heap_handle_failure()
//{
  /* Never return. It is no longer safe for normal execution */
    //while (1);
  //  qsee_err_fatal();
//}

/* Lock function for Memheap.
*/
static int
mem_heap_enter_crit_sect( void * ptr)
{
  int ret_value;
  ret_value = osal_enter_crit_sect((osal_crit_sect_t*) (((mem_heap_type *)ptr)->memheap_crit_sect));
  MEMHEAP_ASSERT( ret_value == OSAL_SUCCESS, MEMHEAP_FAILURE );
  return MEMHEAP_SUCCESS;
} /* END mem_heap_enter_crit_sect */

/* Matching free function for mem_heap_lock_mutex().
*/
static int
mem_heap_leave_crit_sect( void * ptr)
{
  int ret_value;
  ret_value = osal_exit_crit_sect((osal_crit_sect_t*) (((mem_heap_type *)ptr)->memheap_crit_sect));
  MEMHEAP_ASSERT( ret_value == OSAL_SUCCESS, MEMHEAP_FAILURE );
  return MEMHEAP_SUCCESS;
} /* END mem_heap_leave_crit_sect */


/*===========================================================================
FUNCTION mem_heap_get_random_num
DESCRIPTION

===========================================================================*/
int mem_heap_get_random_num(void*  random_ptr, int random_len)
{

#ifdef FEATURE_MEMHEAP2_USE_PRNG
  /*if(memheap_prng_getdata(((uint8*)random_ptr), random_len)!= random_len)
  {
    MEMHEAP_ASSERT( 0, MEMHEAP_FAILURE );
  }*/
#else
 if(random_len == 4)
  {
    uint32 *ran_num = (uint32 *)random_ptr;
    *ran_num = 0xabcddcba;
  }
  else if(random_len == 2)
  {
    uint16 *ran_num = (uint16 *)random_ptr;
    *ran_num = 0xabcd;
  }
#endif
  return MEMHEAP_SUCCESS;

}

/*===========================================================================
FUNCTION MEM_GET_NEXT_BLOCK

DESCRIPTION
  Return the next block header in the heap for the block following the
  given one.  If the given block is the last block in the heap, return
  the first block in the heap.  Never returns NULL.

  Returns a pointer the the memory block header of the block following the given
  block (or the first block of the heap if the given block was the last
  block of the heap).

===========================================================================*/
static mem_block_header_type *mem_get_next_block
(
   const mem_heap_type         *heap_ptr,
     /*  The heap the given block belongs to -- may NOT be NULL!
     */
   const mem_block_header_type *block_ptr,
     /*  The block in the heap for which to return the following heap
         block
     */
   const unsigned int          check_next_section
)
{
   uint16 *pblk = NULL;
   mem_block_header_type *nextBlkPtr = NULL;
   MEMHEAP_ASSERT(block_ptr != NULL, NULL);
   MEMHEAP_ASSERT(heap_ptr != NULL, NULL); //this may be redundent since , it a static function re-visit this for possible optimisation
   MEMHEAP_ASSERT(block_ptr->forw_offset != 0, NULL);
   MEMHEAP_ASSERT(FRD_OFFSET_CHECK_SECTIONS(block_ptr, heap_ptr), NULL);
   MEMHEAP_ASSERT(!((block_ptr->forw_offset)%kMinChunkSize), NULL);

   
   if(heap_ptr->number_of_sections > 1)
   {
	   if(block_ptr->last_flag == 1)
      {
		   uint16 section_number=block_ptr->section_index;
         if((check_next_section == 1) && (section_number + 1 < MEM_HEAP_SECTIONS_MAX)&&(heap_ptr->sections[section_number + 1].start_addr != NULL))
         {
            nextBlkPtr =heap_ptr->sections[section_number + 1].start_addr;
         }else{
            nextBlkPtr =heap_ptr->sections[section_number].start_addr;
         }
      }
      else
      {
         nextBlkPtr = (mem_block_header_type *) ((char *) block_ptr + block_ptr->forw_offset);
      }
      
   }
   else
   {
	nextBlkPtr =  block_ptr->last_flag? heap_ptr->first_block
           : (mem_block_header_type *) ((char *) block_ptr + block_ptr->forw_offset);
   }
   pblk = (uint16*)nextBlkPtr;
   if(nextBlkPtr->free_flag == kBlockFree){
      MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk), NULL);
   }
   else{
      MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk), NULL);
   }
   return nextBlkPtr;
} /* END mem_get_next_block */


/*===========================================================================
FUNCTION memheap_copy_InBlk_frd_offset_in_nextBlk

DESCRIPTION
      This function will copy the forward offset of passed memory block to its 
      next memory block's header and update its guard bytes
===========================================================================*/

static void* memheap_copy_InBlk_frd_offset_in_nextBlk(mem_block_header_type *mem_block, mem_heap_type *heap_ptr)
{
   mem_block_header_type *temp = NULL;
   uint16 *pblk =NULL;

   if(mem_block->last_flag== kLastBlock)
   {
      return NULL;
   }
   // store the frd_offset in the next block for a free block
   temp = (mem_block_header_type *)((char*)mem_block + mem_block->forw_offset);
   temp->prev_block_forw_offset= mem_block->forw_offset;
   pblk = (uint16*)temp;

   if(temp->free_flag == kBlockUsed){
      ADD_GUARD_BYTES_TO_USED_HEADER(heap_ptr->magic_num_used, pblk);
   }
   else if(temp->free_flag == kBlockFree){
      ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
   }
   return NULL;
}



/*===========================================================================*/
/*!
    @brief
    Determines a bin number for the given value.

    @detail
    This function is effectivly an opened up binary search algorithm hard
    coded for 32 values, with the exception that it looks for the
    closest match without going over instead of the exact match.  This
    function is large but extremely fast, speed is much more important here
    than size.
    With the given value, it finds a bin number that this value
    should fall into. It does that by:
    (1) compare the value with the BIN in the center, therefore BIN15
        out of BIN0 to BIN31,
    (2) if the value is less than (or equal to) BIN15, it compares the value
        with the center bin with lower half of the bins, therefore, BIN7
        out of BIN0 to BIN15.
    (3) if the value is greater than BIN15 in the step (1), it compares
        the value with the center bin with higher half of the bins,
        therefore, BIN23 outof BIN16 to BIN31.
    (4) this process of binary search continues until it determines the
        bin number.

    @return
    bin number (0 - 31)
*/
/*=========================================================================*/
static uint32 memheap_find_bin
(
  uint32 value   /*!< value to be determined for bin assignment */
)
{
  /*! @brief bin number to return
  */
  uint32 bin=0;

  /*-----------------------------------------------------------------------*/


    if (value <= MEMHEAP2_BINSIZE7)
    {
      if (value <= MEMHEAP2_BINSIZE3)
      {
        if (value <= MEMHEAP2_BINSIZE1)
        {
          if (value <= MEMHEAP2_BINSIZE0)
          {
            bin = 0;
          }
          else /* value > MEMHEAP2_BINSIZE0 */
          {
            bin = 1;
          }
        }
        else   /* value > MEMHEAP2_BINSIZE1 */
        {
          if (value <= MEMHEAP2_BINSIZE2)
          {
            bin = 2;
          }
          else /* value > MEMHEAP2_BINSIZE2 */
          {
            bin = 3;
          }
        }
      }
      else     /* value > MEMHEAP2_BINSIZE3 */
      {
        if (value <= MEMHEAP2_BINSIZE5)
        {
          if (value <= MEMHEAP2_BINSIZE4)
          {
            bin = 4;
          }
          else /* value > MEMHEAP2_BINSIZE4 */
          {
            bin = 5;
          }
        }
        else   /* value > MEMHEAP2_BINSIZE5 */
        {
          if (value <= MEMHEAP2_BINSIZE6)
          {
            bin = 6;
          }
          else /* value > MEMHEAP2_BINSIZE6 */
          {
            bin = 7;
          }
        }
      }
    }
    else       /* value > MEMHEAP2_BINSIZE7 */
    {
      if (value <= MEMHEAP2_BINSIZE11)
      {
        if (value <= MEMHEAP2_BINSIZE9)
        {
          if (value <= MEMHEAP2_BINSIZE8)
          {
            bin = 8;
          }
          else /* value > MEMHEAP2_BINSIZE8 */
          {
            bin = 9;
          }
        }
        else   /* value > MEMHEAP2_BINSIZE9 */
        {
          if (value <= MEMHEAP2_BINSIZE10)
          {
            bin = 10;
          }
          else /* value > MEMHEAP2_BINSIZE10 */
          {
            bin = 11;
          }
        }
      }
      else     /* value > MEMHEAP2_BINSIZE11 */
      {
        if (value <= MEMHEAP2_BINSIZE13)
        {
          if (value <= MEMHEAP2_BINSIZE12)
          {
            bin = 12;
          }
          else /* value > MEMHEAP2_BINSIZE12 */
          {
            bin = 13;
          }
        }
        else   /* value > MEMHEAP2_BINSIZE13 */
        {
          if (value <= MEMHEAP2_BINSIZE14)
          {
            bin = 14;
          }
          else /* value > MEMHEAP2_BINSIZE14 */
          {
            bin = 15;
          }
        }
      }
    }

  return bin;
} /* memheap_find_bin() */


/*===========================================================================
FUNCTION bin_active

DESCRIPTION
   this function will update the binToUseForMalloc of each applicable BIN of the heap,
   whenever new bin is active

===========================================================================*/
static void bin_active(
  mem_heap_type             *heap_ptr,
  uint32             binNo
)
{
  int i = binNo;
  /*do the first iteration for the newly active BIN as it has freeBlock (firstNode is not NULL)*/
  heap_ptr->BIN[i].binToUseForMalloc = binNo;
  i--;
  while( i >= 0)
  {
    if( !(heap_ptr->BIN[i].firstNode) )
    {
      heap_ptr->BIN[i].binToUseForMalloc = binNo;
    }
    else{
      break;
    }
    i--;
  }
}

/*===========================================================================
FUNCTION bin_deactive

DESCRIPTION
   this function will update the binToUseForMalloc of each applicable BIN of the heap,
   whenever new bin is deactivate , means there is no free block that the bin holds
   and hence we cannot use the bin to allocate memory.

===========================================================================*/
static void bin_deactive(
  mem_heap_type             *heap_ptr,
  uint32             binNo
)
{
  int i = binNo;
  if((binNo+1) < MEMHEAP2_BIN_COUNT)
  {
    while((i >= 0)&&(heap_ptr->BIN[i].binToUseForMalloc == binNo)){
      heap_ptr->BIN[i].binToUseForMalloc = heap_ptr->BIN[binNo+1].binToUseForMalloc;
      i--;
    }
  }
}

/*===========================================================================
FUNCTION init_binToUseForMalloc

DESCRIPTION
   this function will initialize all of the BINs in a heap to the default bin no.
   with the highest bin available in the heap at the time of mem_init_heap.
   So initially for malloc this is the bin its going to use.

===========================================================================*/
static void init_binToUseForMalloc(
  mem_heap_type             *heap_ptr,
  mem_block_header_type     *mem_block
)
{
  uint32 bin = memheap_find_bin(mem_block->forw_offset);
  int i;
  for( i = bin; i >= 0 ; i-- )
  {
     heap_ptr->BIN[i].binToUseForMalloc = bin;
  }
}

/*===========================================================================
FUNCTION memheap_addNodeToBin

DESCRIPTION:
     This function adds the free memory block into the appropriate bin

===========================================================================*/
static int memheap_addNodeToBin(mem_heap_type *heap_ptr, void *freeBlock)
{

  uint32  binNo = memheap_find_bin(((mem_block_header_type*)freeBlock)->forw_offset);
  uint16 * pblk = NULL;
  uint32 freeBlock_size = ((mem_block_header_type*)freeBlock)->forw_offset;
  
  binStruct *binToUpdate = &heap_ptr->BIN[binNo];

  if(binToUpdate->firstNode){
    mem_block_header_type *temp, *tempPrev = NULL;

    temp = binToUpdate->firstNode;

    // search the linked list for the right location
    while((temp!=NEXT_BLOCK_POINTER(temp))
       && (BLOCK_SIZE(temp) < freeBlock_size)){
      /*sanity check for the free block in the list*/
       MEMHEAP_ASSERT(BOUNDARY_CHECK_SECTIONS((mem_block_header_type*)(temp), heap_ptr), MEMHEAP_FAILURE);
       tempPrev = temp;
       temp = NEXT_BLOCK_POINTER(temp);
    }

    /*sanity check before adding new block*/
    pblk =  (uint16*)temp;
    MEMHEAP_ASSERT(!(INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk)), MEMHEAP_FAILURE);

    /*firstNode in the bin*/
    if(temp == binToUpdate->firstNode)
    {
      if(freeBlock_size <=(BLOCK_SIZE(temp)))
      {
        //its the firstNode in the BIN to be updated
        binToUpdate->firstNode = (mem_block_header_type *)freeBlock;
        ADD_NEXT_TO_FREEBLOCK(freeBlock,temp);
      }
      else{ /*it will be added next to the firstNode*/
         mem_block_header_type *tempNext = NEXT_BLOCK_POINTER(temp);
        if (temp == tempNext) /*its lastNode as well hence only one block in the list*/
        {
          ADD_NEXT_TO_FREEBLOCK(temp, freeBlock);
          binToUpdate->lastNode = freeBlock;
          ((mem_block_header_type *)freeBlock)->next_freeBlk_forw_offset = 0;
          ((mem_block_header_type*)freeBlock)->next_freeBlk_offset_sign=0;
          /*since the last node's meta data changed so  update the guard bytes*/
          pblk = (uint16*) temp;
          ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
          }
        else{ /*this is going to be added after firstNode where list has more than 2 blocks
             so niether lastNode or firstNode will be updated*/
            
           /*get the next block to the temp */
           mem_block_header_type *tempNext = NEXT_BLOCK_POINTER(temp);
           /*the freeBlock will be pointing to tempNext*/
           ADD_NEXT_TO_FREEBLOCK(freeBlock, tempNext);

           /*Now temp should point to the freeBlock*/
           ADD_NEXT_TO_FREEBLOCK(temp, freeBlock);

           /*temp's metadata is changed so update the guard bytes*/
           pblk = (uint16*) temp;
           ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
        }
      }
    }
    /*lastNode in the bin*/
    else if(!temp->next_freeBlk_forw_offset)
    {
       if(BLOCK_SIZE(temp) < freeBlock_size) /*lastNode will be updated*/
       {
         // update the lastNode
         binToUpdate->lastNode = (mem_block_header_type *)freeBlock;
         ((mem_block_header_type *)freeBlock)->next_freeBlk_forw_offset = 0;
         ((mem_block_header_type*)freeBlock)->next_freeBlk_offset_sign=0;

         ADD_NEXT_TO_FREEBLOCK(temp, freeBlock);

         /*since the last node's meta data changed so  update the guard bytes*/
         pblk = (uint16*) temp;
         ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
       }
       else{ /*its one block before the lastNode*/
         if (NULL != tempPrev){
           ADD_NEXT_TO_FREEBLOCK(tempPrev, freeBlock);
           ADD_NEXT_TO_FREEBLOCK(freeBlock, temp);
           
           /*since the last node's meta data changed so  update the guard bytes*/
           pblk = (uint16*)tempPrev;
           ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
         }
         else{
            MEMHEAP_ASSERT(0, MEMHEAP_FAILURE); /*since it must have atlease 2 memory block in the list to come in this case*/
         }
      }
    }
     /*add the new block in the middle after temp*/
    else {
      /*get the next block to the temp */
      mem_block_header_type *tempNext = NEXT_BLOCK_POINTER(temp);
      /*the freeBlock will be pointing to tempNext*/
      ADD_NEXT_TO_FREEBLOCK(freeBlock, tempNext);
      
      /*Now temp should point to the freeBlock*/
      ADD_NEXT_TO_FREEBLOCK(temp, freeBlock);

      /*temp's metadata is changed so update the guard bytes*/
      pblk = (uint16*) temp;
      ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
    }

    binToUpdate->totalNodes = binToUpdate->totalNodes + 1;
  }else{
  
    binToUpdate->firstNode = (mem_block_header_type *)freeBlock;
    binToUpdate->lastNode = (mem_block_header_type *)freeBlock;

    ((mem_block_header_type *)freeBlock)->next_freeBlk_forw_offset = 0;
    ((mem_block_header_type*)freeBlock)->next_freeBlk_offset_sign=0;

    binToUpdate->totalNodes = 1;
    bin_active(heap_ptr, binNo);
  }

  return MEMHEAP_SUCCESS;
}

static void memheap_remove_block(
         mem_heap_type *heap_ptr, 
         mem_block_header_type *temp, 
         mem_block_header_type *prevTemp,
         uint32 bin)
{
   /* Output sanitization */
   uint16 *pblk;
   binStruct *binToSearch= &heap_ptr->BIN[bin];


   if(temp == binToSearch->firstNode)
   {
     /*check if it was the only free block in the bin*/
     if(temp == binToSearch->lastNode )
     {
       binToSearch->firstNode = NULL;
       binToSearch->lastNode = NULL;
     }
     else{
         binToSearch->firstNode = NEXT_BLOCK_POINTER(temp);
     }
   }
   /*check if it is the last block to be removed from the list*/
   else if(!temp->next_freeBlk_forw_offset)
   {
     if(!prevTemp) return;
     binToSearch->lastNode = prevTemp;
     prevTemp->next_freeBlk_forw_offset = 0;
     prevTemp->next_freeBlk_offset_sign=0;
     pblk = (uint16*) prevTemp;
     ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
   }
   else/*this is a middle block*/
   {
     temp=NEXT_BLOCK_POINTER(temp);
     if(!prevTemp) return;
     ADD_NEXT_TO_FREEBLOCK(prevTemp, temp);/*here temp is updated with temp next in above line , and temp is backed up in answer*/
     pblk = (uint16*) prevTemp;
     ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
   }

   binToSearch->totalNodes = binToSearch->totalNodes - 1;
   if(!(binToSearch->totalNodes))
   {
     bin_deactive(heap_ptr, bin);
   }

}

/*===========================================================================
FUNCTION findNRemoveFreeBlockInBINs

DESCRIPTION:
     This function find a free memory block of requested size in case if
     size_needed is not NULL else if mem_ptr is not NULL then will search for the
     memory block in the bins list ,remove it from the list and return it

===========================================================================*/
static mem_block_header_type * findNRemoveFreeBlockInBINs(
  mem_heap_type *heap_ptr,
  void *mem_ptr,
  size_t size_needed
)
{
  mem_block_header_type *answer = NULL;
  uint16 *pblk = NULL;
  mem_block_header_type *temp, *prevTemp=NULL;

  if(size_needed){
    uint32 bin = memheap_find_bin(size_needed);
    binStruct *binToSearch;

    bin = heap_ptr->BIN[bin].binToUseForMalloc;
    binToSearch = &heap_ptr->BIN[bin];

    if(binToSearch->firstNode == NULL)
    {
       return NULL;
    }

    pblk = (uint16 *)(binToSearch->lastNode);
    MEMHEAP_ASSERT(!(INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk)), NULL);

    if((binToSearch->lastNode)->forw_offset < size_needed){
      if(bin < MEMHEAP2_BIN_COUNT - 1)
      {
        bin = heap_ptr->BIN[bin + 1].binToUseForMalloc;
        binToSearch = &heap_ptr->BIN[bin];
        if(binToSearch->firstNode == NULL)
        {
          return NULL;
        }
      }
    }

    temp = binToSearch->firstNode;

    while((temp!=NEXT_BLOCK_POINTER(temp)) && (BLOCK_SIZE(temp) < size_needed)){
      prevTemp = temp;
      temp = NEXT_BLOCK_POINTER(temp);
     /*sanity check for the free block in the list*/
      MEMHEAP_ASSERT(BOUNDARY_CHECK_SECTIONS((mem_block_header_type*)(temp), heap_ptr), NULL);
    }

    if(BLOCK_SIZE(temp) >= size_needed)
    {
      answer = (mem_block_header_type*)(temp);
	  /* Output sanitization */
      pblk = (uint16 *)temp;
      MEMHEAP_ASSERT(!(INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk)), NULL);
      memheap_remove_block(heap_ptr, temp, prevTemp, bin);
      /*for safe-unlinking and Output sanitization  */
      answer->next_freeBlk_forw_offset = 0;
      return answer;
    }
    else{
      return NULL;/*reqiuested size memory block not found*/
    }

  }
  else if(mem_ptr){

    uint32 bin = memheap_find_bin(((mem_block_header_type*)mem_ptr)->forw_offset);
    binStruct *binToSearch = &heap_ptr->BIN[bin];
    mem_block_header_type *temp= NULL;

    temp = binToSearch->firstNode;
    
    if(temp == NULL)
    {
       /*If the freeblock is not found then it must assert*/
       MEMHEAP_ASSERT(0, NULL);
    }

    while((temp!=NEXT_BLOCK_POINTER(temp)) && ((void *)temp != mem_ptr)){
     /*sanity check for the free block in the list*/
       MEMHEAP_ASSERT(BOUNDARY_CHECK_SECTIONS((mem_block_header_type*)(temp), heap_ptr), NULL);
       prevTemp = temp;
       temp = NEXT_BLOCK_POINTER(temp);
    }

    if(temp == mem_ptr){
		   /* Output sanitization */
      pblk = (uint16 *)temp;
      MEMHEAP_ASSERT(!(INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk)), NULL);
      memheap_remove_block(heap_ptr, temp, prevTemp, bin);
      /*for safe-unlinking and Output sanitization  */
      ((mem_block_header_type*)mem_ptr)->next_freeBlk_forw_offset = 0;
      return mem_ptr;
    }
    else{
       /* If the freeblock is not found then it must assert*/
       MEMHEAP_ASSERT(0, NULL);
    }
  }
  return NULL;
}


/*===========================================================================
FUNCTION MEM_INIT_HEAP

DESCRIPTION
  Initializes the heap_ptr object and sets up inMemoryChunk for use with the
  heap_ptr object.  inMemoryChunk may be aligned on any boundary.  Beginning
  bytes will be skipped until a paragraph boundary is reached.  Do NOT pass
  in NULL pointers.  infail_fnc_ptr may be NULL in which case no function will
  be called if mem_malloc or mem_calloc is about to fail.  If infail_fnc_ptr
  is provided, it will be called once and then the allocation will be
  attempted again.  See description of my_allocator_failed_proc for details.
  There is no protection for initializing a heap more than once.  If a heap
  is re-initialized, all pointers previously allocated from the heap are
  immediately invalidated and their contents possibly destroyed.  If that's
  the desired behavior, a heap may be initialized more than once.
===========================================================================*/
/*lint -sem(mem_init_heap,1p,2p,2P>=3n) */
int mem_init_heap(
   mem_heap_type                 *heap_ptr,
      /* Statically allocated heap structure
      */
   mem_magic_number_struct       *mem_magic_number,
   void                          *heap_mem_ptr,
      /* Pointer to contiguous block of memory used for this heap
      */
   uint32                  heap_mem_size
      /* The size in bytes of the memory pointed to by heap_mem_ptr
      */
)
{
  char *memory_end_ptr;
    /* 1 beyond computed end of memory passed in to use as heap.
    */
  char *memory_start_ptr;
    /* The computed beginning of the memory passed in to use as heap.  This
       computed value guarantees the heap actually starts on a paragraph
       boundary.
    */
  uint32 chunks;
    /* How many whole blocks of size kMinChunkSize fit in the area of
       memory starting at memory_start_ptr and ending at (memory_end_ptr-1)
    */
  uint16 * pblk = NULL;
  uint32 ret_value =0;

  MEMHEAP_ASSERT(heap_ptr, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num_index_array, MEMHEAP_FAILURE);

  MEMHEAP_ASSERT(mem_magic_number->magic_num_index < MAX_HEAP_INIT, MEMHEAP_FAILURE); /* support at the most 30 heaps*/

  if( (heap_ptr->magic_num) &&
      (heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index])){
    /* heap is already initialized so just return */
    return MEMHEAP_SUCCESS;
  }

  memset(heap_ptr, 0, sizeof(mem_heap_type));

  MEMHEAP_ASSERT(heap_mem_ptr, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(heap_mem_size, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(heap_mem_size >= (2*kMinChunkSize-1), MEMHEAP_FAILURE);

  memory_start_ptr = (char *)heap_mem_ptr;
  memory_end_ptr   = memory_start_ptr + heap_mem_size;

  //use the memory required for memheap_crit_sect from the heap getting initialized */
 while( (((uint32)memory_start_ptr) & 0x000FUL) )
  {
     ++memory_start_ptr;
  }




  heap_ptr->memheap_crit_sect = memory_start_ptr;
  ret_value = osal_init_crit_sect((osal_crit_sect_t*)heap_ptr->memheap_crit_sect);
  MEMHEAP_ASSERT(ret_value == OSAL_SUCCESS, MEMHEAP_FAILURE);
  /* by default it is critical section */
  heap_ptr->lock_fnc_ptr = mem_heap_enter_crit_sect;
  heap_ptr->free_fnc_ptr = mem_heap_leave_crit_sect;
  /*move the memory start pointer by sizeof(osal_crit_sect_t) as we have used that much out of the heap;*/
  #ifndef CMNLIB
  memory_start_ptr = (char *)memory_start_ptr + sizeof(osal_crit_sect_t);
  #else
  memory_start_ptr = (char *)memory_start_ptr;
  #endif // CMNLIB check ends

  /* Advance to the nearest paragraph boundary. This while loop should work
  ** regardless of how many bits are required for address pointers near or
  ** far, etc.
  **
  ** Turn off lint "size incompatibility" warning because cast from pointer
  ** to uint32 will lose bits, but we don't care because we're only
  ** interested in the least significant bits and we never cast back into a
  ** pointer, so the warning can be safely ignored
  */
  /*lint --e(507)*/
  while( (((uint32)memory_start_ptr) & 0x000FUL) )
  {
     ++memory_start_ptr;
  }

  chunks = (uint32) ((memory_end_ptr - memory_start_ptr) / kMinChunkSize);
  heap_ptr->first_block            = (mem_block_header_type *) memory_start_ptr;
  heap_ptr->next_block             = heap_ptr->first_block;
  heap_ptr->sections[heap_ptr->number_of_sections].last_block = heap_ptr->first_block;

  /*MIN_HEAP_SIZE_FOR_BINS macro definition moved to scons file*/
  if( heap_mem_size < MIN_HEAP_SIZE_FOR_BINS){
     heap_ptr->legacy_check = kUseLegacyImpl;
  }else{
     heap_ptr->legacy_check = kUseBINsImpl;
  }
  mem_heap_get_random_num((&(mem_magic_number->magic_num[mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]])), 4);
  heap_ptr->magic_num = mem_magic_number->magic_num[mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]];
  heap_ptr->magic_num_index = mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index];
  mem_heap_get_random_num(&(heap_ptr->magic_num_free), 2);
  mem_heap_get_random_num(&(heap_ptr->magic_num_used), 2);
  mem_magic_number->magic_num_index++;
  mem_init_block_header(heap_ptr->first_block, chunks * kMinChunkSize, heap_ptr);
  heap_ptr->first_block->last_flag = (char) kLastBlock;
  heap_ptr->first_block->start_flag = (char) kStartBlock;
  heap_ptr->first_block->prev_block_forw_offset=0;
  heap_ptr->first_block->next_freeBlk_forw_offset=0;
  heap_ptr->first_block->next_freeBlk_offset_sign=0;
  heap_ptr->total_blocks           = 1;
  heap_ptr->max_used               = 0;
  heap_ptr->max_request            = 0;
  heap_ptr->used_bytes             = 0;
  heap_ptr->total_bytes            = chunks * kMinChunkSize;

  heap_ptr->sections[heap_ptr->number_of_sections].size= chunks * kMinChunkSize;
  heap_ptr->sections[heap_ptr->number_of_sections].start_addr=(void *)memory_start_ptr;
  if(heap_ptr->legacy_check & kUseBINsImpl){
    init_binToUseForMalloc(heap_ptr, heap_ptr->first_block);
    memheap_addNodeToBin(heap_ptr, heap_ptr->first_block);
  }

  ((mem_block_header_type *) memory_start_ptr)->section_index = (char) heap_ptr->number_of_sections;
  heap_ptr->number_of_sections++;

  pblk = (uint16*)(heap_ptr->first_block);
  ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
  return MEMHEAP_SUCCESS;
} /* END mem_init_heap */


/*===========================================================================
FUNCTION MEM_DEINIT_HEAP

DESCRIPTION
  De-Initializes the heap_ptr object only if the heap is in reset state.
  User is responsible for freeing all the allocated pointers before  calling
  into this function.
===========================================================================*/
int mem_deinit_heap(
   mem_heap_type                 *heap_ptr,
      /* Statically allocated heap structure
      */
   mem_magic_number_struct       *mem_magic_number
)
{
  int ret_value;
  MEMHEAP_ASSERT(mem_magic_number, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num_index_array, MEMHEAP_FAILURE);
  // return the magic number
  mem_magic_number->magic_num_index--;
  if(mem_magic_number->magic_num_index < MAX_HEAP_INIT)
  {
    mem_magic_number->magic_num_index_array[mem_magic_number->magic_num_index]=heap_ptr->magic_num_index;
  }
 /* De-initialize heap only if all the allocated blocks are freed */
 if(heap_ptr->used_bytes == 0)
 {
   ret_value = osal_delete_crit_sect((osal_crit_sect_t*)heap_ptr->memheap_crit_sect);
   MEMHEAP_ASSERT(ret_value == OSAL_SUCCESS, MEMHEAP_FAILURE);
   memset(heap_ptr, 0, sizeof(mem_heap_type));
 }
 else
 {
  MEMHEAP_ASSERT(heap_ptr->used_bytes == 0, MEMHEAP_FAILURE);
 }
 return MEMHEAP_SUCCESS;
}
/*===========================================================================
FUNCTION MEM_INIT_BLOCK_HEADER

DESCRIPTION
  Initializes a memory block header to control a block of memory in the
  heap.  The header may still need to some of its fields adjusted after
  this call if it will be a used block or the last block in the heap.
===========================================================================*/
int mem_init_block_header(
   mem_block_header_type *block_ptr,
     /* Memory header block to be initialized
     */
   uint32          size,
     /* The size of the block of memory controlled by this
        memory header block INCLUDING the size of the
        header block itself
     */
     mem_heap_type *heap_ptr
)
{
  char *p_temp;
  MEMHEAP_ASSERT(block_ptr, MEMHEAP_FAILURE);
  p_temp = ((char*)block_ptr);
  memset(p_temp, 0 , sizeof(mem_block_header_type));
  block_ptr->free_flag   = (char) kBlockFree;
  block_ptr->forw_offset = size;

  return MEMHEAP_SUCCESS;
} /* END mem_init_block_header */



/*===========================================================================
FUNCTION mem_heap_add_section

DESCRIPTION
  Add a section to an existing heap. 
  The section added is either merged with the existing heap if the heap is contigous and a new section
  is not create, Or the section is added as an additional section in the heap.
===========================================================================*/

int mem_heap_add_section(
   /* Statically allocated heap structure   */
   mem_heap_type                 *heap_ptr,
   /* Pointer to contiguous block of memory used for this section  */
   void                          *section_start,
   /* Size of the section  */
   uint32                 section_size)
{
   char *memory_end_ptr;
   char *memory_start_ptr;
   mem_block_header_type *theBlock;
   uint16 section_prev = 0xFFFF;
   uint16 section_next = 0xFFFF;
   char *section_end_ptr = 0;
   unsigned long chunks;
   uint16 * pblk = NULL;
   int i;
   uint16 sect_index =0 ;

   MEMHEAP_ASSERT(heap_ptr, MEMHEAP_FAILURE);
   MEMHEAP_ASSERT(heap_ptr->number_of_sections < MEM_HEAP_SECTIONS_MAX, MEMHEAP_FAILURE);

   memory_start_ptr = (char *)section_start;

   /*Asserting in case of overflow*/
   MEMHEAP_ASSERT((UINT32_MAX - (uint32)memory_start_ptr) >= section_size, MEMHEAP_FAILURE);

   memory_end_ptr   = memory_start_ptr + section_size;

   BEGIN_CRITICAL_SECTION(heap_ptr);

   /* Check if this section can be merged with another section in the heap */

   for(i=0; i<heap_ptr->number_of_sections; i++)
   {
      section_end_ptr = (char *)heap_ptr->sections[i].start_addr + heap_ptr->sections[i].size;
      /* Check if section added can be merged at the end of any of the sections */
      if((char *)section_end_ptr ==((char *)section_start))
      {
         section_prev = i;
         continue;
      }    
    
      /* Check if section added can be merged at the begining of any of the sections */
      if(((((char *)heap_ptr->sections[i].start_addr)-16) < memory_end_ptr)
		  &&(((char *)heap_ptr->sections[i].start_addr) >= memory_end_ptr) 
          && (section_end_ptr > memory_end_ptr))
      {
         section_next = i;
         continue;
      }
   }

   /* Check if the new section is contiguous with another section and merge it */
   if(section_prev < MEM_HEAP_SECTIONS_MAX)
   {
      /* The heap has a section that is before  the new section in memory and can be merged. */
      //     |                                   |
      //     |     Heap  section           |
      //     |                                   |
      //     |                                   |
      // __|____________________|_
      //     |                                   |
      //     |                                   |
      //     |      new  section           |
      //     |                                   |
      //     |                                   |
      theBlock = heap_ptr->sections[section_prev].last_block;
      chunks = (unsigned long) ((memory_end_ptr - memory_start_ptr) / kMinChunkSize);
      /* If block is free, increase the size and update fields of the block */
      if (theBlock->free_flag)
      {
         (void)findNRemoveFreeBlockInBINs(heap_ptr, theBlock, 0);
         theBlock->forw_offset += (chunks * kMinChunkSize);
         memheap_addNodeToBin(heap_ptr, (void*)theBlock);
         pblk = (uint16*)(theBlock);
         ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);

      }
      else
      {
         /*Since last block is in use, create a new block in the existing section */ 
         mem_init_block_header((mem_block_header_type *) memory_start_ptr, chunks * kMinChunkSize, heap_ptr);
        ((mem_block_header_type *) memory_start_ptr)->last_flag = (char) kLastBlock;
        ((mem_block_header_type *) memory_start_ptr)->next_freeBlk_forw_offset = 0;
         /* Reset the last flag in the block that was previously the last block in the section */
         theBlock->last_flag = 0;
         pblk = (uint16 *)theBlock;
         ADD_GUARD_BYTES_TO_USED_HEADER(heap_ptr->magic_num_used,pblk);
         ((mem_block_header_type *) memory_start_ptr)->section_index = (char)section_prev;
         memheap_addNodeToBin(heap_ptr, (mem_block_header_type *) memory_start_ptr);
         heap_ptr->sections[section_prev].last_block = (mem_block_header_type *) memory_start_ptr;

         memheap_copy_InBlk_frd_offset_in_nextBlk(theBlock, heap_ptr); /*the new section should be updated 
         with thblock's offset i.e. prev_block_forw_offset in the incoming section mem block header*/

         pblk = (uint16*)(memory_start_ptr);
         ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free,pblk);

         heap_ptr->total_blocks++;
      }
      heap_ptr->sections[section_prev].size += (chunks * kMinChunkSize);
      heap_ptr->total_bytes += (chunks * kMinChunkSize);
   }
   else if(section_next < MEM_HEAP_SECTIONS_MAX)
   {
      /* The heap has a section that is after  the new section in memory and can be merged. */
      //     |                                   |
      //     | New section                 |
      //     |                                   |
      //     |                                   |
      // __|____________________|_
      //     |                                   |
      //     |                                   |
      //     |      heap section           |
      //     |                                   |
      //     |                                   |
      while( (((unsigned long)memory_start_ptr) & 0x000FUL) )
      {
         ++memory_start_ptr;
      }
      theBlock = heap_ptr->sections[section_next].start_addr;
      if (theBlock->free_flag)
      {
         (void)findNRemoveFreeBlockInBINs(heap_ptr, theBlock, 0);

         chunks = (unsigned long) ((memory_end_ptr  - memory_start_ptr) / kMinChunkSize);
         mem_init_block_header((mem_block_header_type *) memory_start_ptr, (theBlock->forw_offset + (chunks * kMinChunkSize)), heap_ptr);
         ((mem_block_header_type *) memory_start_ptr)->start_flag = (char) kStartBlock;
         ((mem_block_header_type *) memory_start_ptr)->section_index = (char)section_next;
         memheap_addNodeToBin(heap_ptr, (mem_block_header_type *) memory_start_ptr);
         pblk = (uint16*)(memory_start_ptr);
         ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free,pblk);

         memheap_copy_InBlk_frd_offset_in_nextBlk( (mem_block_header_type *) memory_start_ptr, heap_ptr); /*the new section's frd offset 
         to be updated in its next block*/

         if(heap_ptr->sections[section_next].start_addr == heap_ptr->sections[section_next].last_block)
         {
            heap_ptr->sections[section_next].last_block = (mem_block_header_type *)memory_start_ptr;
         }
         heap_ptr->sections[section_next].start_addr = (mem_block_header_type *)memory_start_ptr;
         /* now set the theBlock's header info. to NULL */
         {
           uint32 *temp = (uint32*)theBlock; /*did it like this for optimization purpose*/
           temp[0] = 0;
           temp[1] = 0;
         }
      }
      else
      {
         chunks = (unsigned long) (((char *)theBlock - memory_start_ptr) / kMinChunkSize);
         mem_init_block_header((mem_block_header_type *) memory_start_ptr, chunks * kMinChunkSize, heap_ptr);
         ((mem_block_header_type *) memory_start_ptr)->start_flag = (char) kStartBlock;
         ((mem_block_header_type *) memory_start_ptr)->section_index = (char)section_next;
         memheap_addNodeToBin(heap_ptr, (mem_block_header_type *) memory_start_ptr);
         pblk = (uint16 *)memory_start_ptr;
         ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free,pblk);

         heap_ptr->sections[section_next].start_addr = (mem_block_header_type *)memory_start_ptr;

         /*Clear the start flag of the following block. */
         theBlock->start_flag = 0;
         pblk = (uint16*)(theBlock);
         ADD_GUARD_BYTES_TO_USED_HEADER(heap_ptr->magic_num_used,pblk);

         memheap_copy_InBlk_frd_offset_in_nextBlk((mem_block_header_type *)memory_start_ptr, heap_ptr); /*the new section's frd offset 
         to be updated in its next block*/

         heap_ptr->total_blocks++;
      }
 
      if (heap_ptr->first_block > (mem_block_header_type *)memory_start_ptr)
      {
        heap_ptr->first_block = (mem_block_header_type *)memory_start_ptr;
      }
      heap_ptr->sections[section_next].size += section_size;
      heap_ptr->total_bytes += (chunks * kMinChunkSize);
   }
   else
   {
      /* The added section cannot be merged with an existing one, just add an additional section in the heap */
      /* Advance to the nearest paragraph boundary */
      /*lint --e(507)*/
      while( (((unsigned long)memory_start_ptr) & 0x000FUL) )
      {
         ++memory_start_ptr;
      }


      //find the next available section
   	  for(i = 1; i< MEM_HEAP_SECTIONS_MAX-1 ; i++)
      {
         if(heap_ptr->sections[i].start_addr == NULL)
         {
            sect_index = i;
            break;
         }
      }
      MEMHEAP_ASSERT(sect_index, MEMHEAP_FAILURE);

      /* number_of_sections will contain total number of sections and is also the index in the sections array
            of the heap_ptr where the next section will be added. 
          */
      chunks = (unsigned long) ((memory_end_ptr - memory_start_ptr) / kMinChunkSize);

      MEMHEAP_ASSERT((chunks*kMinChunkSize) >= (2*kMinChunkSize-1), MEMHEAP_FAILURE);

      heap_ptr->sections[sect_index].size= chunks * kMinChunkSize;
      heap_ptr->sections[sect_index].start_addr=(void *)memory_start_ptr;

      heap_ptr->total_blocks++;
      heap_ptr->total_bytes = heap_ptr->total_bytes + (chunks * kMinChunkSize);

      mem_init_block_header((mem_block_header_type *) memory_start_ptr, chunks * kMinChunkSize, heap_ptr);
      theBlock = (mem_block_header_type *)memory_start_ptr;
      theBlock->last_flag = kLastBlock;
      theBlock->start_flag = kStartBlock;
      theBlock->section_index= sect_index;

      theBlock->prev_block_forw_offset=0;
      theBlock->next_freeBlk_forw_offset=0;
      theBlock->next_freeBlk_offset_sign=0;
      heap_ptr->sections[sect_index].last_block = theBlock;

      memheap_addNodeToBin(heap_ptr, theBlock);

      pblk = (uint16*)(theBlock);
      ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free,pblk);
      /* Done adding a section, increment the count of sections */
      heap_ptr->number_of_sections++;
	}
   END_CRITICAL_SECTION(heap_ptr);
   return MEMHEAP_SUCCESS;
} /* END mem_heap_add_section */

/*===========================================================================
FUNCTION MEM_MALLOC

DESCRIPTION
  Allocates a block of size bytes from the heap.  If heap_ptr is NULL
  or size is 0, the NULL pointer will be silently returned.

  Returns a pointer to the newly allocated block, or NULL if the block
  could not be allocated.
===========================================================================*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */
void* mem_malloc(
  mem_heap_type *heap_ptr,
     /* Heap from which to allocate
     */
  mem_magic_number_struct       *mem_magic_number,
  unsigned int         size
     /* Number of bytes to allocate
     */
)
{

  uint32 chunks;
    /* the computed minimum size of the memory block in chunks needed
       to satisfy the request */

  uint32 actualSize;
    /* the computed minimum size of the memory block in bytes needed
       to satisfy the request */

  unsigned char bonusBytes;
    /* the computed number of unused bytes at the end of the allocated
       memory block.  Will always be < kMinChunkSize */

  mem_block_header_type *freeBlock = NULL;
    /* the free block found of size >= actualSize */

  void *answer = NULL;
    /* the address of memory to be returned to the caller */

  uint16 * pblk = NULL;
  uint32 blockHeaderSize=sizeof(mem_block_header_type);

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/


  MEMHEAP_ASSERT(heap_ptr != NULL, NULL);

  MEMHEAP_ASSERT(mem_magic_number, NULL);
  MEMHEAP_ASSERT(mem_magic_number->magic_num, NULL);
  MEMHEAP_ASSERT(mem_magic_number->magic_num_index_array, NULL);
  if (!size) return NULL;



  /* quick check if requested size of memory is available */
  if( (uint32) size > heap_ptr->total_bytes ) return NULL;

  /* chunks overflow check : check max memory that can be malloc'd at a time */
  if( (0xFFFFFFFF - ( kMinChunkSize + sizeof(mem_block_header_type)) ) 
        < ((uint32) size)) return NULL;


  chunks = ((uint32) size + blockHeaderSize
            + kMinChunkSize - 1) / kMinChunkSize;
  actualSize = chunks * kMinChunkSize;
  bonusBytes = (unsigned char)
                (actualSize - size - blockHeaderSize);

    BEGIN_CRITICAL_SECTION(heap_ptr);


    MEMHEAP_ASSERT(heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index], NULL);
    if(heap_ptr->legacy_check & kUseBINsImpl){
      freeBlock = findNRemoveFreeBlockInBINs(heap_ptr,NULL, actualSize);
    }
    else{
      freeBlock = mem_find_free_block(heap_ptr, actualSize);
    }


    if (freeBlock)
    {
      /* split the block (if necessary) and return the new block */

      MEMHEAP_ASSERT(freeBlock->forw_offset > 0, NULL);
      // frd offset and actual size are chunk aligned
      if (freeBlock->forw_offset > actualSize)
      {
        /* must split into two free blocks */


        mem_block_header_type *newBlock = (mem_block_header_type *)
                                          ((char *) freeBlock + actualSize);
        mem_init_block_header(newBlock, freeBlock->forw_offset - actualSize, heap_ptr);
        newBlock->section_index =  freeBlock->section_index;
        newBlock->last_flag = freeBlock->last_flag;
        newBlock->prev_block_forw_offset=actualSize;
        freeBlock->forw_offset = actualSize;        
        if(freeBlock->last_flag ==kLastBlock)
             heap_ptr->sections[newBlock->section_index].last_block = newBlock;
        freeBlock->last_flag = 0;


        ++heap_ptr->total_blocks;
        /*Add this new remaining free block after spliting into the free Block list*/
        if(heap_ptr->legacy_check & kUseBINsImpl){
          memheap_addNodeToBin(heap_ptr, newBlock);
        }

        memheap_copy_InBlk_frd_offset_in_nextBlk(newBlock, heap_ptr);

        pblk = (uint16*)newBlock;
        ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
      }


      /* mark the block as used and return it */

      freeBlock->free_flag = kBlockUsed;
      freeBlock->extra = bonusBytes;
      /*  set up next block to search for
          next allocation request */
      if(heap_ptr->legacy_check != kUseBINsImpl){
        //Assuming legacy does not have sections
        heap_ptr->next_block = mem_get_next_block(heap_ptr, freeBlock,0);
       }

      heap_ptr->used_bytes += size;
      MEMHEAP_ASSERT(heap_ptr->total_bytes >= heap_ptr->used_bytes, NULL);

      if (heap_ptr->used_bytes > heap_ptr->max_used) {
        heap_ptr->max_used = heap_ptr->used_bytes;
      }
      if (size > heap_ptr->max_request) {
        heap_ptr->max_request = size;
      }

    pblk = (uint16*)freeBlock;
      ADD_GUARD_BYTES_TO_USED_HEADER(heap_ptr->magic_num_used, pblk);
      answer = (char *) freeBlock + blockHeaderSize;
    }

#ifdef FEATURE_MEM_DEBUG
    if(answer != NULL)
    {

      freeBlock->caller_ptr=MEM_HEAP_CALLER_ADDRESS(MEM_HEAP_CALLER_ADDRESS_LEVEL);
    }
#endif

    END_CRITICAL_SECTION(heap_ptr);

  return answer;
} /* END mem_malloc */


/*===========================================================================
FUNCTION MEM_FREE

DESCRIPTION
  Deallocates the ptr block of memory.  If ptr is NULL, heap_ptr is NULL or
  ptr is outside the range of memory managed by heap_ptr, then this function
  call does nothing (and is guaranteed to be harmless).  This function will
  ASSERT if it can detect an attempt to free an already freed block.  (This
  is not always reliable though, so it might not catch it.)
===========================================================================*/
/*lint -sem(mem_free,1p) */
int mem_free(
  mem_heap_type *heap_ptr,
     /* Heap in which to free memory
     */
  mem_magic_number_struct       *mem_magic_number,
  void          *ptr
     /* Memory to free
     */
)
{
  mem_block_header_type *theBlock;
    /* The computed address of the memory header block in the heap that
       controls the memory referenced by ptr */

  uint32          sizeBlockHeader=sizeof(mem_block_header_type);

  uint16 *pblk = NULL;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/


  MEMHEAP_ASSERT(heap_ptr != NULL, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(mem_magic_number->magic_num_index_array, MEMHEAP_FAILURE);
  /*commented out the below assert since NULL free occurances are found and once
   corrsponding fixes are in its need to be uncomment*/
  MEMHEAP_ASSERT(heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index], MEMHEAP_FAILURE);



  /*commented out the below assert since NULL free occurances are found and once
   corrsponding fixes are in its need to be uncomment*/
  if(ptr == NULL)
  {
     //MEMHEAP_ERROR(" NULL ptr occurenaces in mem_free()",0,0,0);
    //MEMHEAP_ASSERT(0, MEMHEAP_FAILURE);

    return MEMHEAP_SUCCESS;
  }


  /* free the passed in block */

  MEMHEAP_ASSERT(heap_ptr->first_block, MEMHEAP_FAILURE);
  BEGIN_CRITICAL_SECTION(heap_ptr);


  theBlock = (mem_block_header_type *)
                          ((char *) ptr - sizeBlockHeader);

  //check for block alignment to 16
  MEMHEAP_ASSERT((((uint32)theBlock)%kMinChunkSize) == 0, MEMHEAP_FAILURE);


  /* boundry check for the ptr passed to free */
  MEMHEAP_ASSERT(BOUNDARY_CHECK_SECTIONS(theBlock, heap_ptr), MEMHEAP_FAILURE);




  /* Try to detect corruption. */


  MEMHEAP_ASSERT(!theBlock->free_flag, MEMHEAP_FAILURE);  /* Attempt to detect multiple
                                            frees of same block */
  /* Make sure forw_offset is reasonable */
  MEMHEAP_ASSERT(theBlock->forw_offset >= sizeBlockHeader, MEMHEAP_FAILURE);
  /* Make sure extra is reasonable */
  MEMHEAP_ASSERT(theBlock->extra < kMinChunkSize, MEMHEAP_FAILURE);

  /* Make sure forw_offset is not spiling over the heap boundry */
  MEMHEAP_ASSERT(FRD_OFFSET_CHECK_SECTIONS(theBlock, heap_ptr), MEMHEAP_FAILURE);

 //check for heap canary
  pblk = (uint16*)(theBlock);
  MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk), MEMHEAP_FAILURE);



  if (!theBlock->free_flag) /* Be intelligent about not munging the heap if
                              a multiple free of the same block is detected */
  {


    MEMHEAP_ASSERT((theBlock->forw_offset - sizeBlockHeader
                                  - theBlock->extra) <= heap_ptr->used_bytes, MEMHEAP_FAILURE);
    heap_ptr->used_bytes -= theBlock->forw_offset - sizeBlockHeader
                                  - theBlock->extra;
    MEMHEAP_ASSERT(heap_ptr->total_bytes >= heap_ptr->used_bytes, MEMHEAP_FAILURE);

    theBlock->free_flag = (char) kBlockFree;





  /* try to do defragmentation if possible*/
    /*check if it can concatenate the previous block of the theBlock*/
   if(theBlock->start_flag != kStartBlock)
   {
      mem_block_header_type *preFreeBlock;

         preFreeBlock =  (mem_block_header_type *)((char*)theBlock - theBlock->prev_block_forw_offset);
         pblk = (uint16*)preFreeBlock;
         if((preFreeBlock->free_flag == kBlockFree)
         && BOUNDARY_CHECK_SECTIONS(preFreeBlock, heap_ptr)
         && FRD_OFFSET_CHECK_SECTIONS(pblk, heap_ptr)
         &&(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk)) /*we don’t want to ASSERT if integrity check fails , just don’t concatenate the block*/
         &&(preFreeBlock->section_index == theBlock->section_index))
         {

            /* preFreeBlock is free and now we can join it with the new 
            free block theBlock so remove it from the list if apply*/
            if(heap_ptr->legacy_check & kUseBINsImpl)
            {
               (void)findNRemoveFreeBlockInBINs(heap_ptr, preFreeBlock, 0);
            }
            --heap_ptr->total_blocks;
            preFreeBlock->forw_offset += theBlock->forw_offset;
            preFreeBlock->last_flag = theBlock->last_flag;
            if(theBlock->last_flag ==kLastBlock)
                    heap_ptr->sections[preFreeBlock->section_index].last_block = preFreeBlock;

            /* now set the theBlock's header info. to NULL */
            {
               uint32 *temp = (uint32*)theBlock; /*did it like this for optimization purpose*/
               temp[0] = 0;
               temp[1] = 0;
            }
            theBlock = preFreeBlock;
         }

   }/*if(theBlock != heap_ptr->first_block)*/

   /*check if it can concatenate the next block of the theBlock*/
   if(theBlock->last_flag != kLastBlock)
   { 
      mem_block_header_type *nextFreeBlock =
      (mem_block_header_type *)((char *)theBlock + theBlock->forw_offset);
 
      if(nextFreeBlock->free_flag == kBlockFree)
      {
         pblk = (uint16*)nextFreeBlock;
         MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk), MEMHEAP_FAILURE);
         MEMHEAP_ASSERT(BOUNDARY_CHECK_SECTIONS(nextFreeBlock, heap_ptr), MEMHEAP_FAILURE);
         MEMHEAP_ASSERT(FRD_OFFSET_CHECK_SECTIONS(pblk,heap_ptr), MEMHEAP_FAILURE);
         if(heap_ptr->legacy_check & kUseBINsImpl){
           (void)findNRemoveFreeBlockInBINs(heap_ptr, nextFreeBlock, 0);
         }
         theBlock->forw_offset += nextFreeBlock->forw_offset;
         theBlock->last_flag = nextFreeBlock->last_flag;
         if(nextFreeBlock->last_flag ==kLastBlock)
              heap_ptr->sections[theBlock->section_index].last_block = theBlock;

         /* now set the nextFreeBlock's header info. to NULL */
         {
            uint32 *temp = (uint32*)nextFreeBlock; /*did it like this for optimization purpose*/
            temp[0] = 0;
            temp[1] = 0;
            temp[2] = 0;
         }
         --heap_ptr->total_blocks;
      }else{
         /* Assert if the next block is used but fails the integrity check
          It is highly likely that the owner of the current block
         corrupted the next block and we should try to catch early. */
         pblk = (uint16*)nextFreeBlock;
         MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk), MEMHEAP_FAILURE);
      }
   }

   if(heap_ptr->legacy_check & kUseBINsImpl){
      memheap_addNodeToBin(heap_ptr, (void*)theBlock);
   }
   else{
      /* Backup now to lessen possible fragmentation, useful for Legacy impl. */
      heap_ptr->next_block = theBlock;
   }
   pblk = (uint16*)theBlock;
   ADD_GUARD_BYTES_TO_FREE_HEADER(heap_ptr->magic_num_free, pblk);
   

   memheap_copy_InBlk_frd_offset_in_nextBlk(theBlock, heap_ptr);


   /* reset heap to initial state if everything is now freed */
   if (!heap_ptr->used_bytes) {
      /* reset heap now, but retain statistics */
      heap_ptr->next_block = heap_ptr->first_block;
   }
  }

     END_CRITICAL_SECTION(heap_ptr);
     return MEMHEAP_SUCCESS;
} /* END mem_free */

/*===========================================================================
FUNCTION MEM_FIND_FREE_BLOCK

DESCRIPTION
  Find a free block of at least inSizeNeeded total bytes.  Collapse
  adjacent free blocks along the way.

  Returns a pointer to a memory block header describing a free block
  of at least inSizeNeeded total bytes.  Returns NULL if no such free
  block exists or can be created by collapsing adjacent free blocks.
===========================================================================*/
static mem_block_header_type *mem_find_free_block(
   mem_heap_type *heap_ptr,
     /*  The heap to search for a free block
     */
   uint32  size_needed
     /*  The minimum size in bytes of the block needed (this size
         INCLUDES the size of the memory block header itself)
     */
)
{
  long searchBlocks;
    /* The maximum number of blocks to search.  After searching this
       many, we've been through the heap once and the allocation fails
       if we couldn't find/create a satisfactory free block */

  mem_block_header_type *followingBlock;
    /* a loop variable used to walk through the blocks of the heap */
  uint16 *pblk = NULL;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  MEMHEAP_ASSERT(heap_ptr, NULL);
  MEMHEAP_ASSERT(heap_ptr->first_block, NULL);
  /* sanity check for the  heap_ptr->next_block  */
  if((heap_ptr->next_block)->free_flag == kBlockFree){
      pblk = (uint16*)(heap_ptr->next_block);
      MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_FREE_HEADER(heap_ptr->magic_num_free, pblk), NULL);
   }
   else{
      pblk = (uint16*)(heap_ptr->next_block);
      MEMHEAP_ASSERT(!INTEGRITY_CHECK_ON_USED_HEADER(heap_ptr->magic_num_used, pblk), NULL);
   }

  searchBlocks = (long) heap_ptr->total_blocks;

  followingBlock = mem_get_next_block(heap_ptr, heap_ptr->next_block,0);

  for (; searchBlocks > 0; --searchBlocks, heap_ptr->next_block=followingBlock,
                  followingBlock=mem_get_next_block(heap_ptr, heap_ptr->next_block,0))
  {
    MEMHEAP_ASSERT(heap_ptr->next_block->forw_offset > 0, NULL);
    MEMHEAP_ASSERT(followingBlock->forw_offset > 0, NULL);

    if (heap_ptr->next_block->free_flag)
    {
      if (heap_ptr->next_block->forw_offset >= size_needed) {
        return heap_ptr->next_block;
      }
    }
  }
  return NULL;       /* didn't find anything */
} /* END mem_find_free_block */

/*===========================================================================
FUNCTION MEM_BLOCK_SIZE

DESCRIPTION
  Returns the size of the memory pointer previously allocated using
  MEM_MALLOC() or MEM_REALLOC()
===========================================================================*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */
unsigned int mem_get_buffer_size(
  void* ptr)
{
  mem_block_header_type*  theBlock        = NULL;
  unsigned int            buffer_size     = 0;
  uint32                  sizeBlockHeader = sizeof(mem_block_header_type);

  if (NULL != ptr)
  {
    theBlock = (mem_block_header_type *)
                         ((char *) ptr - sizeBlockHeader);

    buffer_size = theBlock->forw_offset-sizeBlockHeader;
  }

  return buffer_size;
} /* END mem_get_buffer_size */


#ifndef HYP
/*===========================================================================
FUNCTION MEM_REALLOC

DESCRIPTION
  Resizes the ptr block of memory to be size bytes while preserving the
  block's contents.

  Returns a pointer to the beginning of the resized block of memory (which
  may be different than ptr) or NULL if the block cannot be resized.
===========================================================================*/
/*lint -sem(mem_malloc,1p,2n>=0&&(@p==0||@P==2n)) */
void* mem_realloc(
  mem_heap_type *heap_ptr,
     /* Heap from which to reallocate
     */
  mem_magic_number_struct       *mem_magic_number,

   void          *ptr,
    /* A block previously allocated from heap_ptr
     */

  unsigned int         size
  /* New size (in bytes) of the ptr block of memory
  */
)
{
  mem_block_header_type *theBlock;
    /* The computed address of the memory header block in the heap that
       controls the memory referenced by ptr */

  uint32          sizeBlockHeader=sizeof(mem_block_header_type);

  void *ptrRet = NULL;

  unsigned int origSize=0;

  MEMHEAP_ASSERT(heap_ptr != NULL, NULL);
  MEMHEAP_ASSERT(mem_magic_number, NULL);
  MEMHEAP_ASSERT(mem_magic_number->magic_num, NULL);
  MEMHEAP_ASSERT(mem_magic_number->magic_num_index_array, NULL);
  MEMHEAP_ASSERT(heap_ptr->magic_num == mem_magic_number->magic_num[heap_ptr->magic_num_index], NULL);

  if (!ptr)
  {
    return mem_malloc(heap_ptr, mem_magic_number,size);
  }
  if (!size)
  {
    mem_free(heap_ptr,mem_magic_number,ptr);
    return NULL;
  }

   // Do a memory allocation
   ptrRet=mem_malloc(heap_ptr, mem_magic_number,size);

   //check if the pointer return is NULL or not

   if(ptrRet != NULL)
   {
     theBlock = (mem_block_header_type *)
                          ((char *) ptr - sizeBlockHeader);

     origSize=theBlock->forw_offset-sizeBlockHeader;
     memscpy(ptrRet,size,ptr,origSize);

     // free the original pointer if allocation was successful.
     mem_free(heap_ptr,mem_magic_number,ptr);
   }

   return ptrRet;
} /* END mem_realloc */



/*===========================================================================
FUNCTION MEM_HEAP_BLOCK_ITERATOR_RESET

DESCRIPTION
  Reset a heap block iterator to begin the iteration of heap blocks from
  the beginning.
===========================================================================*/
int mem_heap_block_iterator_reset(
   mem_heap_block_iterator_type *block_iter_ptr
     /* The iterator structure to be reset
     */
)
{
  MEMHEAP_ASSERT(block_iter_ptr, MEMHEAP_FAILURE);
  block_iter_ptr->mBlock = NULL;
  return MEMHEAP_SUCCESS;
} /* mem_heap_block_iterator_reset */


/*===========================================================================
FUNCTION MEM_HEAP_BLOCK_ITERATOR_NEXT

DESCRIPTION
  Return a memory block header for the next block (or next virtual block)
  in the heap being iterated.  Description is only valid if the function
  returns a non-zero value.

  The heap being iterated should not be changed during the iteration as the
  iterator may get lost or return bogus values.  There is no protection
  against this however.

  Returns:
      zero      There are no more heap blocks to return
      non-zero  The next heap block was returned in outBlock successfully
===========================================================================*/
int mem_heap_block_iterator_next(
   mem_heap_block_iterator_type *block_iter_ptr,
     /* Iterator to return next iterated block from
     */
   mem_block_header_type        *out_block_ptr,
     /* Pointer to a location where a copy of a memory block header
        is placed describing the returned memory block.  Only
        valid if the function returns a non-zero value.
     */
   int                           fake_free_coalesced
     /* Input flag.  zero => return the next block header from the heap
        exactly as it is.  non-zero => return the next virtual block
        header from the heap.  Virtual block headers are created by
        collapsing all adjacent free blocks into one.
     */
)
{
  int ans;

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  MEMHEAP_ASSERT(block_iter_ptr, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(out_block_ptr, MEMHEAP_FAILURE);

  ans = 0;
  if (!block_iter_ptr->mBlock)
  {
    block_iter_ptr->mBlock = block_iter_ptr->mAllocator->first_block;

    if (block_iter_ptr->mBlock) {
      ans = 1;
    }
  }
  else if (!block_iter_ptr->mBlock->last_flag)
  {
    block_iter_ptr->mBlock = mem_get_next_block(block_iter_ptr->mAllocator, block_iter_ptr->mBlock,1);
    ans = 1;

  }else
  {
     if ( (block_iter_ptr->mBlock->section_index + 1) < block_iter_ptr->mAllocator->number_of_sections)
     {
         block_iter_ptr->mBlock = mem_get_next_block(block_iter_ptr->mAllocator, block_iter_ptr->mBlock,1);
         ans = 1;
     }
  }
  memset(out_block_ptr, 0, sizeof(mem_block_header_type));
  if (ans)
  {
    *out_block_ptr = *block_iter_ptr->mBlock;
    if (fake_free_coalesced && out_block_ptr->free_flag)
    {
      /* Pretend as though adjacent free blocks were coalesced */
      for (;;)
      {
        mem_block_header_type *next_block;
        if (block_iter_ptr->mBlock->last_flag) break;
        next_block = mem_get_next_block(block_iter_ptr->mAllocator, block_iter_ptr->mBlock,0);
        if (!(next_block->free_flag)) break;
        block_iter_ptr->mBlock = next_block;
        out_block_ptr->forw_offset += block_iter_ptr->mBlock->forw_offset;
      }
    }
  }
  return ans;
} /* mem_heap_block_iterator_next */
/*===========================================================================
FUNCTION MEM_HEAP_BLOCK_ITERATOR_INIT

DESCRIPTION
  Initializes an iterator structure to be used for walking the blocks
  in the specified heap.
===========================================================================*/
int mem_heap_block_iterator_init(
   mem_heap_block_iterator_type *block_iter_ptr,
     /*  The Iterator structure to be initialized
     */
   const mem_heap_type          *heap_ptr
     /*  The heap this iterator should iterate over
     */
)
{
  MEMHEAP_ASSERT(block_iter_ptr, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(heap_ptr, MEMHEAP_FAILURE);

  block_iter_ptr->mAllocator = heap_ptr;
  mem_heap_block_iterator_reset(block_iter_ptr);
  return MEMHEAP_SUCCESS;
} /* mem_heap_block_iterator_init */

/*===========================================================================
FUNCTION MEM_GET_BLOCK_LOGICAL_SIZE

DESCRIPTION
  Returns the logical block size of a memory block in the heap

  Returns the size (in bytes) of the block excluding block header overhead and
  unused bytes at the end of the block.
===========================================================================*/
/*lint -sem(mem_get_block_logical_size,1p) */
unsigned long mem_get_block_logical_size(
   const mem_block_header_type *block_hdr_ptr
     /*  A memory block to get the logical size of
     */
)
{
  MEMHEAP_ASSERT(block_hdr_ptr, MEMHEAP_FAILURE);
  return block_hdr_ptr->forw_offset - sizeof(mem_block_header_type)
            - (block_hdr_ptr->free_flag ? 0 : block_hdr_ptr->extra);
} /* mem_get_block_logical_size */

/*===========================================================================
FUNCTION MEM_HEAP_GET_TOTALS

DESCRIPTION
  Returns heap totals for the heap.  This function IS thread safe.
  Heap must already have been initialized.
  Return totals for the heap.
===========================================================================*/
int mem_heap_get_totals(
   mem_heap_type  *heap_ptr,
      /* The heap to return totals for
      */
   mem_heap_totals_type *totals
      /* A pointer to a totals structure to receive the various
         heap information
      */
)
{
  mem_heap_block_iterator_type heapIter;
    /* heap iterator used to collect heap statistics */

  mem_block_header_type theBlock;
    /* holds info returned by heap iterator */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

  MEMHEAP_ASSERT(heap_ptr, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(totals, MEMHEAP_FAILURE);

  BEGIN_CRITICAL_SECTION(heap_ptr);
  memset(totals, 0, sizeof(*totals));
  mem_heap_block_iterator_init(&heapIter, heap_ptr);
  totals->max_logical_used = heap_ptr->max_used;
  totals->max_logical_request = heap_ptr->max_request;
  while (mem_heap_block_iterator_next(&heapIter, &theBlock, 1))
  {
    unsigned long blkSize = mem_get_block_logical_size(&theBlock);
    ++totals->current_block_count;
    totals->header_bytes += sizeof(mem_block_header_type);
    if (theBlock.free_flag)
    {
      totals->free_bytes += blkSize;
      if (blkSize > totals->largest_free_block)
        totals->largest_free_block = blkSize;
    }
    else
    {
      ++totals->used_blocks;
      totals->used_bytes += blkSize;
      totals->wasted_bytes += theBlock.extra;
    }
  }
  totals->total_physical_bytes = totals->free_bytes
                                    + totals->used_bytes
                                    + totals->wasted_bytes
                                    + totals->header_bytes;
  MEMHEAP_ASSERT(totals->used_bytes == heap_ptr->used_bytes, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(totals->current_block_count >= 1, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(totals->current_block_count <= heap_ptr->total_blocks, MEMHEAP_FAILURE);
  MEMHEAP_ASSERT(totals->total_physical_bytes == heap_ptr->total_bytes, MEMHEAP_FAILURE);
  END_CRITICAL_SECTION(heap_ptr);
  return MEMHEAP_SUCCESS;
} /* mem_heap_get_totals */

#endif

