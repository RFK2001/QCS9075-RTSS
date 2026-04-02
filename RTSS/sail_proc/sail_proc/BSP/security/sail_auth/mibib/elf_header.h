#ifndef ELF_HEADER
#define ELF_HEADER

/*===========================================================================
 * ELF Header Definitions
 * This section contains definitions necessary to parse an ELF header and
 * find ELF Header and Segment Header and extract length and offsets.
 
  Copyright 2022-2023 Qualcomm Technologies Incorporated. 
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
===========================================================================*/


/* The first 52 bytes of the file is the ELF header  */

#define ELFINFO_MAGIC_SIZE (16)

typedef struct
{
  unsigned char e_ident[ELFINFO_MAGIC_SIZE]; /* Magic number and other info   */
  uint16_t        e_type;                /* Object file type                    */
  uint16_t        e_machine;             /* Architecture                        */
  uint32_t        e_version;             /* Object file version                 */
  uint32_t        e_entry;               /* Entry point virtual address         */
  uint32_t        e_phoff;               /* Program header table file offset    */
  uint32_t        e_shoff;               /* Section header table file offset    */
  uint32_t        e_flags;               /* Processor-specific flags            */
  uint16_t        e_ehsize;              /* ELF header size in bytes            */
  uint16_t        e_phentsize;           /* Program header table entry size     */
  uint16_t        e_phnum;               /* Program header table entry count    */
  uint16_t        e_shentsize;           /* Section header table entry size     */
  uint16_t        e_shnum;               /* Section header table entry count    */
  uint16_t        e_shstrndx;            /* Section header string table index   */
} Elf32_Ehdr;

typedef struct
{
  unsigned char e_ident[ELFINFO_MAGIC_SIZE]; /** Magic number and other info   */
  uint16_t        e_type;                /** Object file type                    */
  uint16_t        e_machine;             /** Architecture                        */
  uint32_t        e_version;             /** Object file version                 */
  uint64_t        e_entry;               /** Entry point virtual address         */
  uint64_t        e_phoff;               /** Program header table file offset    */
  uint64_t        e_shoff;               /** Section header table file offset    */
  uint32_t        e_flags;               /** Processor-specific flags            */
  uint16_t        e_ehsize;              /** ELF header size in bytes            */
  uint16_t        e_phentsize;           /** Program header table entry size     */
  uint16_t        e_phnum;               /** Program header table entry count    */
  uint16_t        e_shentsize;           /** Section header table entry size     */
  uint16_t        e_shnum;               /** Section header table entry count    */
  uint16_t        e_shstrndx;            /** Section header string table index   */
} Elf64_Ehdr;

/* Fields in the e_ident array.  The ELFINFO_*_INDEX macros are 
 * indices into the array.  The macros under each ELFINFO_* macro
 * is the values the byte may have.  
 */

#define ELFINFO_MAG0_INDEX    0U     /* File identification byte 0 index */
#define ELFINFO_MAG0          0x7fU  /* Magic number byte 0              */

#define ELFINFO_MAG1_INDEX    1     /* File identification byte 1 index */
#define ELFINFO_MAG1         'E'    /* Magic number byte 1              */

#define ELFINFO_MAG2_INDEX    2     /* File identification byte 2 index */
#define ELFINFO_MAG2         'L'    /* Magic number byte 2              */

#define ELFINFO_MAG3_INDEX    3     /* File identification byte 3 index */
#define ELFINFO_MAG3         'F'    /* Magic number byte 3              */

#define ELFINFO_CLASS_INDEX   4     /* File class byte index            */

/* Version information */
#define ELFINFO_VERSION_INDEX 6U    /* File version byte index          */
#define ELF_VERSION_CURRENT   1U    /* Current version                  */

/* ELF Object Type */
typedef enum
{
  ELF_CLASS_32 = 1,    /* 32-bit objects                   */
  ELF_CLASS_64 = 2,     /* 64-bit objects                   */
  ELF_CLASS_TYPE_FORCE32BITS = 0x7FFFFFFF /* force to 32 bits*/
} Elf_Class;

/* Program segment header.  */
typedef struct
{
  uint32 p_type;                   /* Segment type */
  uint32 p_offset;                 /* Segment file offset */
  uint32 p_vaddr;                  /* Segment virtual address */
  uint32 p_paddr;                  /* Segment physical address */
  uint32 p_filesz;                 /* Segment size in file */
  uint32 p_memsz;                  /* Segment size in memory */
  uint32 p_flags;                  /* Segment flags */
  uint32 p_align;                  /* Segment alignment */
} Elf32_Phdr;

/* Section header.  */
typedef struct
{
  uint32	sh_name;		/* Section name */
  uint32	sh_type;		/* Section type */
  uint32	sh_flags;		/* Section flags */
  uint32	sh_addr;		/* Section addr */
  uint32	sh_offset;		/* Section offset */
  uint32	sh_size;		/* Section size */
  uint32	sh_link;		/* Section link */
  uint32	sh_info;		/* Section info */
  uint32	sh_addralign;	/* Section align */
  uint32	sh_entsize;	    /* Section ent size */
} Elf32_Shdr;

/* Program segment header.  */
typedef struct
{
  uint32_t p_type;                   /** Segment type */
  uint32_t p_flags;                  /** Segment attributes */
  uint64_t p_offset;                 /** Segment file offset */
  uint64_t p_vaddr;                  /** Segment virtual address */
  uint64_t p_paddr;                  /** Segment physical address */
  uint64_t p_filesz;                 /** Segment size in file */
  uint64_t p_memsz;                  /** Segment size in memory */
  uint64_t p_align;                  /** Segment alignment */
} Elf64_Phdr;

/* Section header.  */
typedef struct
{
  uint32	sh_name;		/* Section name */
  uint32	sh_type;		/* Section type */
  uint64	sh_flags;		/* Section flags */
  uint64	sh_addr;		/* Section addr */
  uint64	sh_offset;		/* Section offset */
  uint64	sh_size;		/* Section size */
  uint32	sh_link;		/* Section link */
  uint32	sh_info;		/* Section info */
  uint64	sh_addralign;	/* Section align */
  uint64	sh_entsize;	    /* Section ent size */
} Elf64_Shdr;

#endif /* ELF_HEADER */
