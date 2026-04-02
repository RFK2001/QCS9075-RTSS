/* ============================================================================
 * @file  elfutils.h
 * @brief ELF utility macros
 * This header file provides helper macros to interpret flags/attributes present
 * in ELF headers
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef ELFUTILS_H
#define ELFUTILS_H

#include <stdint.h> 
#include "elf.h"

/* Definition for segment flags used in p_flag of program_segmen header
 *
 *                 Pool Indx    Segment type    Access type   Page/non page
 * bits in p_fag/-----27-----/----26-24-------/---- 23-21----/------20-------/
 */

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

/* Standard ELF segment type definitions */
#define MI_PBT_ELF_PT_NULL    0U
#define MI_PBT_ELF_PT_LOAD    1U
#define MI_PBT_ELF_PT_DYNAMIC 2U
#define MI_PBT_ELF_PT_INTERP  3U
#define MI_PBT_ELF_PT_NOTE    4U
#define MI_PBT_ELF_PT_SHLIB   5U
#define MI_PBT_ELF_PT_PHDR    6U
#define MI_PBT_ELF_TLS        7U

/*----------------------------------------------------------------------------
 * ELF Declarations
 * -------------------------------------------------------------------------*/
typedef uint32_t Elf_Class;

/* Compilation environments which add the compiler's include path might end
 * up using the compiler's elf.h rather than the one present in the TZ build.
 * In such a case define the ELF class types that would otherwise have come
 * from TZ's elf.h
 */
#ifndef ELF_CLASS_32
#define ELF_CLASS_32 ELFCLASS32
#endif
#ifndef ELF_CLASS_64
#define ELF_CLASS_64 ELFCLASS64
#endif

#endif // ELFUTILS_H
