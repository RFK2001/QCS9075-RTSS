/* ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    =========================================================================== */

/*=================================================================================================
    File Name          : swiv.h
    Description        : SWIV and Elf/Program header common data structure.
=================================================================================================*/

#ifndef SWIV_H
#define SWIV_H

#include "safetylibs_types.h"

#ifdef SWIV_DEBUG_ENABLED
#include "xbl_diag.h"
#define SWIV_DEBUG_LOG XBL_LOG_INFO
#else
#define SWIV_DEBUG_LOG(...)
#endif

#define SWIV_MAGIC_NUM (0x56495753U)

#define SEG_MAX_NR    (14U)
#define ELF_TYPE_MASK  (3U)
#define LOAD_TYPE_MASK (3U << 2)

typedef sl_u16_t  sl_Elf32_Half;
typedef sl_u16_t  sl_Elf64_Half;

typedef sl_u32_t  sl_Elf32_Word;
typedef sl_s32_t  sl_Elf32_Sword;
typedef sl_u32_t  sl_Elf64_Word;
typedef sl_s32_t  sl_Elf64_Sword;

typedef sl_u64_t  sl_Elf32_Xword;
typedef sl_s64_t  sl_Elf32_Sxword;
typedef sl_u64_t  sl_Elf64_Xword;
typedef sl_s64_t  sl_Elf64_Sxword;

typedef sl_u32_t  sl_Elf32_Addr;
typedef sl_u64_t  sl_Elf64_Addr;

typedef sl_u32_t  sl_Elf32_Off;
typedef sl_u64_t  sl_Elf64_Off;

#define SL_ELFINFO_MAGIC_SIZE (16U)

#define SL_PT_NULL 0U
#define SL_PT_LOAD 1U
#define SL_PT_DYNAMIC 2U
#define SL_PT_INTERP 3U
#define SL_PT_NOTE 4U
#define SL_PT_SHLIB 5U
#define SL_PT_PHDR 6U
#define SL_PT_TLS 7U

#define SWIV_SUCCESS (0)
#define PARAMETER_INVALID (-11)
#define SWIV_NOT_FOUND (-22)
#define CRC_MISMATCH (-33)

typedef enum {
  ELF32_TYPE = 1U,
  ELF64_TYPE = 2U
} sl_elf_type;

typedef enum {
  SEG_UNLOAD = 4U,
  SEG_LOAD = 8U
} sl_load_type;

/**
 * 
 * @brief Elf header structure for ELF32 type image
 *
*/
typedef struct {
  sl_u8_t         e_ident[SL_ELFINFO_MAGIC_SIZE]; /**< Magic number and other info   */
  sl_Elf32_Half      e_type;               /**< Object file type                    */
  sl_Elf32_Half      e_machine;            /**< Architecture                        */
  sl_Elf32_Word      e_version;            /**< Object file version                 */
  sl_Elf32_Addr      e_entry;              /**< Entry point virtual address         */
  sl_Elf32_Off       e_phoff;              /**< Program header table file offset    */
  sl_Elf32_Off       e_shoff;              /**< Section header table file offset    */
  sl_Elf32_Word      e_flags;              /**< Processor-specific flags            */
  sl_Elf32_Half      e_ehsize;             /**< ELF header size in bytes            */
  sl_Elf32_Half      e_phentsize;          /**< Program header table entry size     */
  sl_Elf32_Half      e_phnum;              /**< Program header table entry count    */
  sl_Elf32_Half      e_shentsize;          /**< Section header table entry size     */
  sl_Elf32_Half      e_shnum;              /**< Section header table entry count    */
  sl_Elf32_Half      e_shstrndx;           /**< Section header string table index   */
} sl_Elf32_Ehdr;

/**
 * 
 * @brief Elf header structure for ELF64 type image
 *
*/
typedef struct {
  sl_u8_t         e_ident[SL_ELFINFO_MAGIC_SIZE]; /**< Magic number and other info   */
  sl_Elf64_Half      e_type;               /**< Object file type                    */
  sl_Elf64_Half      e_machine;            /**< Architecture                        */
  sl_Elf64_Word      e_version;            /**< Object file version                 */
  sl_Elf64_Addr      e_entry;              /**< Entry point virtual address         */
  sl_Elf64_Off       e_phoff;              /**< Program header table file offset    */
  sl_Elf64_Off       e_shoff;              /**< Section header table file offset    */
  sl_Elf64_Word      e_flags;              /**< Processor-specific flags            */
  sl_Elf64_Half      e_ehsize;             /**< ELF header size in bytes            */
  sl_Elf64_Half      e_phentsize;          /**< Program header table entry size     */
  sl_Elf64_Half      e_phnum;              /**< Program header table entry count    */
  sl_Elf64_Half      e_shentsize;          /**< Section header table entry size     */
  sl_Elf64_Half      e_shnum;              /**< Section header table entry count    */
  sl_Elf64_Half      e_shstrndx;           /**< Section header string table index   */
} sl_Elf64_Ehdr;

/**
 * 
 * @brief Program header structure for ELF32 type image
 *
*/
typedef struct {
  sl_Elf32_Word      p_type;               /**< Segment type */
  sl_Elf32_Off       p_offset;             /**< Segment file offset */
  sl_Elf32_Addr      p_vaddr;              /**< Segment virtual address */
  sl_Elf32_Addr      p_paddr;              /**< Segment physical address */
  sl_Elf32_Word      p_filesz;             /**< Segment size in file */
  sl_Elf32_Word      p_memsz;              /**< Segment size in memory */
  sl_Elf32_Word      p_flags;              /**< Segment flags */
  sl_Elf32_Word      p_align;              /**< Segment alignment */
} sl_Elf32_Phdr;

/**
 * 
 * @brief Program header structure for ELF64 type image
 *
*/
typedef struct
{
  sl_Elf64_Word      p_type;               /**< Segment type */
  sl_Elf64_Word      p_flags;              /**< Segment attributes */
  sl_Elf64_Off       p_offset;             /**< Segment file offset */
  sl_Elf64_Addr      p_vaddr;              /**< Segment virtual address */
  sl_Elf64_Addr      p_paddr;              /**< Segment physical address */
  sl_Elf64_Xword     p_filesz;             /**< Segment size in file */
  sl_Elf64_Xword     p_memsz;              /**< Segment size in memory */
  sl_Elf64_Xword     p_align;              /**< Segment alignment */
} sl_Elf64_Phdr;

/**
 * 
 * @brief SWIV segment structure
 *
*/
struct swiv_segment
{
    sl_u32_t magic_num;   /**< Magic number used to identify SWIV segment */
    sl_u32_t crc;         /**< CRC checksum calculated by build utility */
    sl_u64_t padding;     /**< Padding bits to make sure the segment is 16 bytes (sectool limitation) */
};

/**
 * 
 * @brief SWIV segment infomation structure
 *
*/
struct swiv_segment_info
{
    sl_u64_t vaddr;       /**< Virtual address of the segment */
    sl_u64_t paddr;       /**< Physical address of the segment */
    sl_u64_t memsz;       /**< Memory size of the segment */
};

/**
 * 
 * @brief SWIV context recipe structure
 *
*/
struct swiv_context
{
    sl_u32_t crc;                                     /**< CRC checksum calculated by build utility */
    sl_load_type loadable;                            /**< The SWIV segment is loadable? SEG_LOAD-Yes, SEG_UNLOAD-No */
    sl_u32_t seg_num;                                 /**< The number of all the loadable segments including the SWIV segment if it's loadable */
    struct swiv_segment_info *seg_list;               /**< Segments info array */
    sl_u32_t seg_list_num;                            /**< Segments info number */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * swiv_parse() -  Parse the target image
 * 
 * @param[in] phdr:    Program header pointer
 * @param[in] phdr_num:    Number of the program headers
 * @param[out] recipe:    swiv_context pointer
 * @param[in] seg:    swiv segment pointer
 * @param[in] opt:    Options
 * 
 * Parse the target image, locate SWIV segment and generate a swiv_context recipe data structure
 * 
 * @return The parse result will be returned
 * @retval 0:   Successfully parsed.
 * @retval PARAMETER_INVALID:  parameter invalid.
 * @retval SWIV_NOT_FOUND:  SWIV segment not found.
 */
sl_s32_t swiv_parse(const void *phdr, sl_u32_t phdr_num, struct swiv_context *recipe, const struct swiv_segment *seg, sl_u32_t opt);

/**
 * swiv_verify() -  Verify the target image
 * 
 * @param[in] recipe:    swiv_context recipe pointer
 * 
 * Calculate the CRC checksum of all loadable segments and compare it with the CRC stored in the recipe.
 * The loadable SWIV segment is included when calculating the CRC checksum. The CRC value of the segment
 * is filled with zeros when calculating.
 * 
 * @return The verification result will be returned
 * @retval 0:   Successfully verified.
 * @retval PARAMETER_INVALID:  Parameter invalid.
 * @retval CRC_MISMATCH:  CRC mismatch.
 */
sl_s32_t swiv_verify(const struct swiv_context *recipe);

#ifdef __cplusplus
}
#endif

#endif /* SWIV_H */
