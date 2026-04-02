/*
===========================================================================
*/
/**
    @file  elf_util.c
    @brief Implementation of elf loader's elf utilities

*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/elfloader/elf_util.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*===========================================================================
                     INCLUDE FILES FOR MODULE
===========================================================================*/
#include <stdint.h>
#include <string.h>
#include "types.h"
#include "elf_util.h"
#include "miprogressive.h"


/*===========================================================================
                    VARIABLE DECLARATIONS FOR MODULE
===========================================================================*/


//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
//    ELF Driver Internals
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------

// ---------------------------------------------
// Since these staticv functions are internal, we assume the parameters are valid
// ---------------------------------------------


uint32 elfUtilGetProgramHeaderFlags(Elf32_Phdr *phdr)
{
      return phdr->p_flags;
}

boolean elfUtilIsLoadableSegment(Elf32_Phdr *phdr)
{
    uint32 phdr_type;
    uint32 phdr_flags;
    boolean bLoadable = FALSE;

    phdr_type =  phdr->p_type;
    phdr_flags = phdr->p_flags;

    bLoadable = (phdr_type == MI_PBT_ELF_PT_LOAD  &&
                MI_PBT_PAGE_MODE_VALUE(phdr_flags) == MI_PBT_NON_PAGED_SEGMENT  &&
                MI_PBT_ACCESS_TYPE_VALUE(phdr_flags) != MI_PBT_NOTUSED_SEGMENT  &&
                /* hash segment to be loaded explicitly to fixed buffer */
                MI_PBT_SEGMENT_TYPE_VALUE(phdr_flags) != MI_PBT_HASH_SEGMENT   &&
                MI_PBT_ACCESS_TYPE_VALUE(phdr_flags) != MI_PBT_SHARED_SEGMENT);

     return bLoadable;
}

boolean elfUtilIsZeroSegment(Elf32_Phdr *phdr)
{
    uint32 memsz = 0;
    uint32 filesz = 0;
    boolean bZeroSegment = FALSE;
    
    memsz = phdr->p_memsz;
    filesz = phdr->p_filesz;

    if (memsz == 0U && filesz == 0U)
    {
        bZeroSegment = TRUE;
    }
  return bZeroSegment;
}

boolean elfUtilVerifyElfHeader(Elf32_Ehdr *ehdr)
{
    boolean bValid;
    
    if (ehdr == NULL)
    {
        return FALSE;
    }

    bValid = ((uint8)((Elf32_Ehdr *)ehdr)->e_ident[ELFINFO_MAG0_INDEX] == ELFINFO_MAG0 && 
           ((Elf32_Ehdr *)ehdr)->e_ident[ELFINFO_MAG1_INDEX] == (unsigned char)ELFINFO_MAG1 &&
           ((Elf32_Ehdr *)ehdr)->e_ident[ELFINFO_MAG2_INDEX] == (unsigned char)ELFINFO_MAG2 &&
           ((Elf32_Ehdr *)ehdr)->e_ident[ELFINFO_MAG3_INDEX] == (unsigned char)ELFINFO_MAG3 &&
           (uint8)((Elf32_Ehdr *)ehdr)->e_ident[ELFINFO_VERSION_INDEX] == ELF_VERSION_CURRENT &&
           ((Elf32_Ehdr *)ehdr)->e_ehsize == sizeof(Elf32_Ehdr) &&
           ((Elf32_Ehdr *)ehdr)->e_phentsize == sizeof(Elf32_Phdr) &&
           ((Elf32_Ehdr *)ehdr)->e_phnum != 0U &&
           (uint8)((Elf32_Ehdr *)ehdr)->e_phnum <= MI_PBT_MAX_SEGMENTS);
  return bValid;
}
uint32 elfUtilGetEntryPointVaddr(Elf32_Ehdr *ehdr)
{
    return (ehdr != NULL) ? ehdr->e_entry : 0U;
}
uint16 elfUtilGetphnum(Elf32_Ehdr *ehdr)
{
    return (ehdr != NULL) ? ehdr->e_phnum : 0U;
}
uint16 elfUtilGetphentsize(Elf32_Ehdr *ehdr)
{
    return (ehdr != NULL) ? ehdr->e_phentsize : 0U;
}

uint32 elfUtilGetSegmentMemsz(Elf32_Phdr *phdr)
{
    return (phdr != NULL) ? phdr->p_memsz : 0U;
}
uint32 elfUtilGetSegmentFilesz(Elf32_Phdr *phdr)
{
    return (phdr != NULL) ? phdr->p_filesz : 0U;
}
uint32 elfUtilGetSegmentOffset(Elf32_Phdr *phdr)
{
    return (phdr != NULL) ? phdr->p_offset : 0U;
}

uint32 elfUtilGetSegmentDestVaddr(Elf32_Phdr *phdr)
{
    return (phdr != NULL) ? phdr->p_vaddr : 0U;
}
