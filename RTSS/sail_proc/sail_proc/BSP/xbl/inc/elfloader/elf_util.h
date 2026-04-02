/*
===========================================================================
*/
/**
    @file  elf_util.h
    @brief Header of ELF utility sub-module

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/elfloader/elf_util.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/* Include header file guard */
#ifndef __ELF_UTIL_H__
#define __ELF_UTIL_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "elf_header.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/


/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**********************************************************
 * Verify ELF header
 *
 *
 * @param ehdr [IN]
 *   Pointer to ELF 32 bits header
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean elfUtilVerifyElfHeader(Elf32_Ehdr *ehdr);
/**********************************************************
 * Get entry address
 *
 *
 * @param ehdr [IN]
 *   Pointer to ELF 32 bits header
 *
 * @return uint32 [OUT]
 *   image's entry address
 *
 **********************************************************/
uint32 elfUtilGetEntryPointVaddr(Elf32_Ehdr *ehdr);
/**********************************************************
 * Get phdr number
 *
 *
 * @param ehdr [IN]
 *   Pointer to ELF 32 bits header
 *
 * @return uint26 [OUT]
 *   phdr number
 *
 **********************************************************/
uint16 elfUtilGetphnum(Elf32_Ehdr *ehdr);
/**********************************************************
 * Get program header struct size in bytes
 *
 *
 * @param ehdr [IN]
 *   Pointer to ELF 32 bits header
 *
 * @return uint16 [OUT]
 *   phdr struct size
 *
 **********************************************************/
uint16 elfUtilGetphentsize(Elf32_Ehdr *ehdr);
/**********************************************************
 * Gte program header flags
 *
 *
 * @param phdr [IN]
 *   Pointer to phdr pointer
 *
 * @return uint32 [OUT]
 *   program header's flags.
 *
 **********************************************************/
uint32 elfUtilGetProgramHeaderFlags(Elf32_Phdr *phdr);
/**********************************************************
 * Is this program header loadable?
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return boolean [OUT]
 *   TRUE: bootable segment.
 *
 **********************************************************/
boolean elfUtilIsLoadableSegment(Elf32_Phdr *phdr);
/**********************************************************
 * Is this segment zero segment?
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return boolean [OUT]
 *   TRUE: zero segment.
 *
 **********************************************************/
boolean elfUtilIsZeroSegment(Elf32_Phdr *phdr);
/**********************************************************
 * Get segment mem size
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return uint32 [OUT]
 *   segment's mem size.
 *
 **********************************************************/
uint32 elfUtilGetSegmentMemsz(Elf32_Phdr *phdr);
/**********************************************************
 * Get segment's file size
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return uint32 [OUT]
 *   Segment's file size.
 *
 **********************************************************/
uint32 elfUtilGetSegmentFilesz(Elf32_Phdr *phdr);
/**********************************************************
 * Gte segment's offset
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return uint32 [OUT]
 *   Segment offset.
 *
 **********************************************************/
uint32 elfUtilGetSegmentOffset(Elf32_Phdr *phdr);
/**********************************************************
 * Get segment's vaddr
 *
 *
 * @param ehdr [IN]
 *   Pointer to program header
 *
 * @return boolean [OUT]
 *   Destination virual address.
 *
 **********************************************************/
uint32 elfUtilGetSegmentDestVaddr(Elf32_Phdr *phdr);

#endif /*__ELF_UTIL_H__*/

/**********************************************************************************************************
**                                  End of file                                                          **
**********************************************************************************************************/
