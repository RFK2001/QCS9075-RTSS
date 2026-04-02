/*===========================================================================
 Copyright (c) 2014-2015  Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef UTIL_H
#define UTIL_H
#include "types.h"

#ifndef TRUE  
   #define TRUE  ((BOOLEAN)(1==1))
#endif

#ifndef FALSE 
   #define FALSE  ((BOOLEAN)(1==0))
#endif

#ifndef MAX
   #define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#endif

#ifndef MIN
   #define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
#endif

#ifndef ARR_SIZE
#define  ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )
#endif

#define OVERFLOWS(type, ptr, len)  ((type) (ptr) > ((type) (ptr)+len))
#define UNDERFLOWS(type, ptr, len) ((type) (ptr) < ((type) (ptr)-len))

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(array)                \
  ((void const*) &(array) == (void const *) (array)   \
  ? sizeof (array) / sizeof *(array)     \
  : 0)
#endif

#define RETCHK(xx)            if ((xx) != E_SUCCESS) {return (xx);}

/* Align val down to be a multiple of size, size needs to be a power of two */
#define ALIGN_DOWN(val, size) ((val) & ~((size) - 1))

/* Align val up to be a multiple of size, size needs to be a power of two */
#define ALIGN_UP(val, size)   (((val) + (size) - 1) & ~((size) - 1))

//#define IS_ALIGNED(ptr, aln) (0 == ((uintptr_t) (ptr) & (aln - 1)))

#define FLOOR_4K(xx)          ALIGN_DOWN((xx), TZ_4KB)

#define ROUNDUP(value, round) (0 == value % round ?     \
                               value :                  \
                               value + (round - (value % round)))

#define TYPE_ROUNDUP(type, val, multiple)   (((val) + (multiple)-1) & \
                                             ~(type)((multiple)-1))
#define TYPE_ROUNDDOWN(type, val, multiple) ((val) & \
                                             ~(type)((multiple)-1))
#define DIFF(a,b) ((a)>(b)?(a)-(b):(b)-(a))

#if !defined(OFFTARGET)
#define INIT_FARCALL_FP(x) asm("str %2, [%1]\n": "=m" (x##_fp) :"r"(&x##_fp), "r"(&x) :"memory");
#else
#define INIT_FARCALL_FP(x) (x##_fp = x);
#endif
#define FARCALL(x) (x ## _fp)

/* MIN definition conflicting with comdef.h. */
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define SAIL_SEC_1TB                       0x10000000000
#define SAIL_SEC_8GB                       0x00200000000
#define SAIL_SEC_4GB                       0x00100000000
#define SAIL_SEC_2GB                       0x00080000000
#define SAIL_SEC_1GB                       0x00040000000
#define SAIL_SEC_512MB                     0x00020000000
#define SAIL_SEC_256MB                     0x00010000000
#define SAIL_SEC_128MB                     0x00008000000
#define SAIL_SEC_64MB                      0x00004000000
#define SAIL_SEC_32MB                      0x00002000000
#define SAIL_SEC_16MB                      0x00001000000
#define SAIL_SEC_2MB                       0x00000200000
#define SAIL_SEC_1MB                       0x00000100000
#define SAIL_SEC_4KB                       0x00000001000

uint64 read_vbar_el1(void);
void write_vbar_el1(uint64 vbar);
uint32 read_isr_el1(void);
void write_pmcr(uint64 val);
uint64 read_pmcr(void);
void write_pmuserenr(uint64 val);
uint64 read_ns_el1_cpsr(void);
uint64 read_id_aa64pfr1_el1(void);

int jtag_put_char(uint8 ch, uint32 timeout);

void dmb(void);
void dsb(void);
void isb(void);
void sev(void);
void wfe(void);

void pimem_memzi(uintnt *ptr, uint32 size);

void enable_cntps_ctl(void);
void disable_cntps_ctl(void);
uint64 read_cntps_val(void);
void write_cntps_val(uint64 val);

uint32  memscpy(
          void        *dst,
          uint32      dst_size,
          const void  *src,
          uint32      src_size );

void* secure_memset(
            void* ptr, 
            int32 value, 
            size_t len);

#endif /* UTIL_H */
