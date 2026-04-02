#ifndef SEC_IMG_ENV_H
#define SEC_IMG_ENV_H

/**
* @file sec_img_env.h
* @brief contain environment/image related configuration and definition
*/

/*===========================================================================
   Copyright (c) 2017 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header: //components/dev/ssg.tz/1.14/sunkum.ssg.tz.1.14.test_sep15/securemsm/secimgauth/inc/env/xbl_sec/sec_img_env.h#1 $
  $DateTime: 2021/09/15 00:43:50 $
  $Author: sunkum $

when       who      what, where, why
--------   ---      ------------------------------------
09/20/17   hw       Initial version.

===========================================================================*/
/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
//#include <stdint.h>
//#include "elfutils.h"
#include "types.h"

struct secboot_pbl_shared_info_type;
typedef struct secboot_pbl_shared_info_type pbl_secboot_shared_info_type;

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#ifndef _UINT64_DEFINED
#define _UINT64_DEFINED
  typedef  uint64_t     uint64;      /* Unsigned 64 bit value */
#endif

#ifndef _UINT32_DEFINED
#define _UINT32_DEFINED
  typedef  uint32_t     uint32;      /* Unsigned 32 bit value */
#endif

#ifndef _UINT8_DEFINED
#define _UINT8_DEFINED
  typedef  uint8_t       uint8;       /* Unsigned 8  bit value */
#endif

#ifndef _UINTNT_DEFINED
 #define _UINTNT_DEFINED
 //typedef  uintptr_t    uintnt;      //Unsigned Native Integer (Aarch32: 32 bits, Aarch64: 64 bits)  
 #endif

#ifndef _BOOLEAN_DEFINED
typedef  unsigned char      boolean;     /* Boolean value type. */
#define _BOOLEAN_DEFINED
#endif

#endif /* SEC_IMG_ENV_H */
