/*
===========================================================================
*/
/**
    @file  types.h
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/common_inc/types.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

#ifndef TYPES_H
#define TYPES_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdatomic.h>
#include <stdbool.h>
 
/*===========================================================================
                           DEFINES
===========================================================================*/
#define _BOOLEAN_DEFINED
#define _INT8_DEFINED
#define _UINT8_DEFINED
#define _INT16_DEFINED
#define _UINT16_DEFINED
#define _INT32_DEFINED
#define _UINT32_DEFINED
#define _INT64_DEFINED
#define _UINT64_DEFINED
#define _UINTNT_DEFINED

/*===========================================================================
                           TYPEDEFS
===========================================================================*/
//TODO: change base type across bsp to use compiler types or platform types to maintain portability, avoid using mix types. 
//For now, allowing the platform types to match compiler types.
#if defined(__ARM_GNU__) 
typedef uint32_t                 uint32;
typedef uint32_t                 uint;
typedef uint32_t                 u_int;
typedef int32_t                  int32;
typedef uint32_t                 dword;
#elif defined(__ARM_FUSA__)
typedef unsigned int             uint32;
typedef unsigned int             uint;
typedef unsigned int             u_int;
typedef int                      int32;
typedef unsigned int             dword;        /* Unsigned 32 bit value type. */
#else
typedef unsigned int             uint32;
typedef unsigned int             uint;
typedef unsigned int             u_int;
typedef int                      int32;
typedef unsigned int             dword;        /* Unsigned 32 bit value type. */
#endif

typedef unsigned short           uint16;
typedef short                    int16;
typedef unsigned long long       uint64;
typedef long long                int64;
typedef unsigned char            uint8;
typedef signed char              int8;
typedef unsigned short           word;         /* Unsigned 16 bit value type. */
typedef unsigned long            uintnt;
typedef unsigned char            boolean;

typedef int                      status_t;
typedef uintptr_t                addr_t;
typedef uintptr_t                vaddr_t;
typedef uintptr_t                paddr_t;
typedef uint32                   register_t;//ToDo Check if uint64 is apt here [i am using 32 as this is a 32bit system]

typedef uint32_t                 u32;

enum handler_return {
    INT_NO_RESCHEDULE = 0,
    INT_RESCHEDULE,
};
/*===========================================================================
                            MACROS
===========================================================================*/
 #ifndef MAX
   #define  MAX( x, y ) ( ((x) > (y)) ? (x) : (y) )
#endif 

#ifndef MIN
   #define  MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )
#endif 

#define TRUE 1
#define FALSE 0

#ifndef NULL
  #define NULL  0
#endif

//Macros for Common Sizes


//Macros for Alignment and Alignment Checking Operations
//#define __ALIGN_MASK(x,mask)  (((x)+(mask)) & ~(mask))
//#define __ALIGN(x,a)          __ALIGN_MASK((x), (typeof(x))(a)-1)
//#define ALIGN(x,a)            __ALIGN((x),(a))
#define IS_ALIGNED(x,a)       (((x) & ((typeof(x))(a)-1)) == 0)

//Macros for Common Sizes
#define SIZE_256			(1 << 8)
#define SIZE_4K			    (1 << 12)
#define SIZE_8K			    (1 << 13)
#define SIZE_16K			(1 << 14)
#define SIZE_64K			(1 << 16)
#define SIZE_1M			    (1 << 20)
#define SIZE_2M			    (1 << 21)
#define SIZE_1G			    (1 << 30)

#define SIZEOF_ARRAY(a) (sizeof((a))/sizeof((a)[0]))

int32_t ffs(int32_t num);

typedef enum : uint32_t {
    DISABLE = 0,
    ENABLE = 1,
} enable_disable;






#endif  
