#ifndef SECBOOT_CHIPSET_H
#define SECBOOT_CHIPSET_H

/**
@file secboot_chipset.h
@brief Define functions or parameters for particular chipset
*/

/*===========================================================================
   Copyright (c) 2023 by QUALCOMM Technologies, Incorporated.  All Rights Reserved.
===========================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header: //components/dev/ssg.tz/1.0/sunkum.ssg.tz.1.0.TzXbl_dev_Jan13/securemsm/secboot/chipset/lahaina/xbl_sec/secboot_chipset.h#1 $
  $DateTime: 2022/01/13 01:04:30 $
  $Author: sunkum $

when       who      what, where, why
--------   ---      ------------------------------------
04/13/17   hw       Init Version 

===========================================================================*/
#include "CeML.h"
/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants (Used by callers to
 * implement CounterMeasure)
 * -------------------------------------------------------------------------*/
#define SECBOOT_OTP_ROOT_OF_TRUST_BYTE_SIZE CEML_HASH_DIGEST_SIZE_SHA384
#define SECBOOT_ROOT_OF_TRUST_ALGO          CEML_HASH_ALGO_SHA384

#define BITS_IN_BYTE (8) // the number of bits in one byte
#define WORD_LEN (sizeof(uint32_t)) // byte size of one word

// The word size of context handle required to run
// secboot. The size is different for targets.
#define SECBOOT_HANDLE_WORD_SIZE_ENV (0x500/WORD_LEN)

#endif /* SECBOOT_CHIPSET_H */
