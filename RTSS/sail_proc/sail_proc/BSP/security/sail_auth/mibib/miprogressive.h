#ifndef MI_PROGRESSIVE_H
#define MI_PROGRESSIVE_H
/*===========================================================================

                Progressive Boot Definitions

DESCRIPTION
  This header file gives the external definition of the structures used
  by the Progressive Boot Loader to individually and selectively load
  ELF segments from NAND flash to memory as needed.
  
  Copyright 2022-2023 Qualcomm Technologies Incorporated. 
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
===========================================================================*/

#include "types.h"

#ifndef    SIZE4K
#define SIZE4K 4096
#endif

#ifndef    SIZE_4K_MINUS_1
#define SIZE_4K_MINUS_1 (SIZE4K - 1)
#endif

/*------------------------------------------------------------
 *
 *  Progressive Boot Table Definitions
 *
 * ---------------------------------------------------------*/
 
/* Magic numbers used in identifying valid progressive boot table (PBT) */
#define MI_PBT_MAGIC1     0xEFBEADDE
#define MI_PBT_MAGIC2     0x98765432

/* Must increment this version whenever structure of progressive header
 * changes.
 */
#define MI_PBT_VERSION   0x5


/* The latest ELF documentation is at http://www.caldera.com/developers/gabi/latest/ch5.pheader.html
 * and it talks about OS and PROCESSOR specific fields.
 * we use the bits (PF_MASKOS) in Elf32_PHdr.p_flags as recomended by ARM
 */

/* Definition for segment flags used in p_flag of program_segmen header
 *
 *                 Pool Indx    Segment type    Access type   Page/non page
 * bits in p_fag/-----27-----/----26-24-------/---- 23-21----/------20-------/
 */
/* Note: MI_PBT_MAX_SEGMENTS would impact OSBL memory usage */
#ifndef MI_PBT_MAX_SEGMENTS
#define MI_PBT_MAX_SEGMENTS 100U
#endif

#define MI_PBT_NON_PAGED_SEGMENT   0x0U
#define MI_PBT_PAGED_SEGMENT       0x1U

#define MI_PBT_RW_SEGMENT           0x0U
#define MI_PBT_RO_SEGMENT           0x1U
#define MI_PBT_ZI_SEGMENT           0x2U
#define MI_PBT_NOTUSED_SEGMENT      0x3U
#define MI_PBT_SHARED_SEGMENT       0x4U
#define MI_PBT_MONITOR_MODE_SEGMENT 0x1U

#define MI_PBT_L4_SEGMENT          0x0U
#define MI_PBT_AMSS_SEGMENT        0x1U
#define MI_PBT_HASH_SEGMENT        0x2U
#define MI_PBT_BOOT_SEGMENT        0x3U
#define MI_PBT_L4BSP_SEGMENT       0x4U
#define MI_PBT_SWAPPED_SEGMENT     0x5U
#define MI_PBT_SWAP_POOL_SEGMENT   0x6U
#define MI_PBT_PHDR_SEGMENT        0x7U

#define MI_PBT_POOL_INDEX          0x1U

#define MI_PBT_FLAG_PAGE_MODE_MASK        0x100000UL
#define MI_PBT_FLAG_ACCESS_TYPE_MASK      0xE00000UL
#define MI_PBT_FLAG_SEGMENT_TYPE_MASK     0x7000000UL
#define MI_PBT_FLAG_POOL_INDEX_MASK       0x8000000UL

#define MI_PBT_FLAG_PAGE_MODE_SHIFT       0x14U
#define MI_PBT_FLAG_ACCESS_TYPE_SHIFT     0x15U
#define MI_PBT_FLAG_SEGMENT_TYPE_SHIFT    0x18U
#define MI_PBT_FLAG_POOL_INDEX_SHIFT      0x1BU


#define MI_PBT_FLAGS_MASK                 0x0FF00000UL
#define MI_PBT_PHDR_FLAGS_SHIFT           0x14U


#define MI_PBT_ELF_AMSS_NON_PAGED_RW_SEGMENT \
          (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT)

#define MI_PBT_ELF_AMSS_NON_PAGED_RO_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )

#define MI_PBT_ELF_AMSS_NON_PAGED_ZI_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_ZI_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )

#define MI_PBT_ELF_AMSS_NON_PAGED_NOTUSED_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_NOTUSED_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )

#define MI_PBT_ELF_AMSS_NON_PAGED_SHARED_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_SHARED_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )


#define MI_PBT_ELF_AMSS_PAGED_RW_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_AMSS_PAGED_RO_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)    | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_AMSS_PAGED_ZI_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_ZI_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)    | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_AMSS_PAGED_NOTUSED_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT)   | \
            (MI_PBT_NOTUSED_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_AMSS_PAGED_SHARED_SEGMENT \
          ( (MI_PBT_AMSS_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT)   | \
            (MI_PBT_SHARED_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )


#define MI_PBT_ELF_HASH_SEGMENT \
          ( (MI_PBT_HASH_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )

#define MI_PBT_ELF_BOOT_SEGMENT \
           ( (MI_PBT_BOOT_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
             (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT) )

#define MI_PBT_ELF_NON_PAGED_L4BSP_SEGMENT \
          (MI_PBT_L4BSP_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT)

#define MI_PBT_ELF_PAGED_L4BSP_SEGMENT \
           ( (MI_PBT_L4BSP_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
             (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_SWAPPED_PAGED_RO_SEGMENT_INDEX0 \
          ( (MI_PBT_SWAPPED_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)       | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_SWAPPED_PAGED_RO_SEGMENT_INDEX1 \
          ( (MI_PBT_SWAPPED_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_RO_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)       | \
            (MI_PBT_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT)      | \
            (MI_PBT_POOL_INDEX << MI_PBT_FLAG_POOL_INDEX_SHIFT) )

#define MI_PBT_ELF_SWAP_POOL_NON_PAGED_ZI_SEGMENT_INDEX0 \
          ( (MI_PBT_SWAP_POOL_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_ZI_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)         | \
            (MI_PBT_NON_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT) )

#define MI_PBT_ELF_SWAP_POOL_NON_PAGED_ZI_SEGMENT_INDEX1 \
          ( (MI_PBT_SWAP_POOL_SEGMENT << MI_PBT_FLAG_SEGMENT_TYPE_SHIFT) | \
            (MI_PBT_ZI_SEGMENT << MI_PBT_FLAG_ACCESS_TYPE_SHIFT)         | \
            (MI_PBT_NON_PAGED_SEGMENT << MI_PBT_FLAG_PAGE_MODE_SHIFT)    | \
            (MI_PBT_POOL_INDEX << MI_PBT_FLAG_POOL_INDEX_SHIFT))


#define MI_PBT_PAGE_MODE_VALUE(x) \
         ( ((x) & MI_PBT_FLAG_PAGE_MODE_MASK) >> \
           MI_PBT_FLAG_PAGE_MODE_SHIFT )

#define MI_PBT_ACCESS_TYPE_VALUE(x) \
         ( ((x) & MI_PBT_FLAG_ACCESS_TYPE_MASK) >> \
           MI_PBT_FLAG_ACCESS_TYPE_SHIFT )

#define MI_PBT_SEGMENT_TYPE_VALUE(x) \
         ( ((x) & MI_PBT_FLAG_SEGMENT_TYPE_MASK) >> \
            MI_PBT_FLAG_SEGMENT_TYPE_SHIFT )

#define MI_PBT_POOL_INDEX_VALUE(x) \
          ( ((x) & MI_PBT_FLAG_POOL_INDEX_MASK) >> \
            MI_PBT_FLAG_POOL_INDEX_SHIFT )


/* Segment memory attributes */
#define MI_PBT_MEM_READ_WRITE 0U
#define MI_PBT_MEM_READ_ONLY  1U

/* Size of computed HASH values for progressive boot segments */
#define MI_PROG_BOOT_DIGEST_SIZE  20

/* Standard ELF segment type definitions */
#define MI_PBT_ELF_PT_NULL    0U
#define MI_PBT_ELF_PT_LOAD    1U
#define MI_PBT_ELF_PT_DYNAMIC 2U
#define MI_PBT_ELF_PT_INTERP  3U
#define MI_PBT_ELF_PT_NOTE    4U
#define MI_PBT_ELF_PT_SHLIB   5U
#define MI_PBT_ELF_PT_PHDR    6U
#define MI_PBT_ELF_TLS        7U

/* Definition of record for each loadable segment */
struct segment_record {
  uint32 type;
  uint32 segment_offset;    /* offset from first data block in NAND       */
  uint32 v_address;         /* Virtual execution address Address in RAM   */
  uint32 p_address;         /* Physical execution address Address in RAM  */
  uint32 size;              /* Size in bytes that needs to be copied      */
  uint32 mem_size;          /* Size in bytes that is actually used in RAM */
  uint32 memory_attribute;  /* Indicates if memory is RW or RO            */
  uint32 align;             /* Segment alignment */
};

/* Definition of Progressive Boot Table containing segment records */
struct progressive_boot_block {
  uint32          magic1;                   /* MAGIC1                 */
  uint32          magic2;                   /* MAGIC2                 */
  uint32          version;                  /* PBT version number     */
  uint32          numsegments;              /* Number of ELF segments */
  uint32          elf_image_entry_point;    /* ELF entry point addr   */

  struct segment_record segment[MI_PBT_MAX_SEGMENTS];
                               /* One record for each segment */
};

typedef struct progressive_boot_block progressive_boot_block_type;


#endif /* MI_PROGRESSIVE_H */
