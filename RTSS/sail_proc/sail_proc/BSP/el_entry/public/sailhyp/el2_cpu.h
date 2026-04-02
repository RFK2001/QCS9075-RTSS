/**
 * @file types.h
 * @brief Types definitions
 * Header file for the definition of types used in sail
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.02.21   rrahul       Created
=============================================================================*/

#ifndef EL2_CPU_H
#define EL2_CPU_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "target.h"
#include "types.h"

/*===========================================================================
                           DEFINITION OF EL2 Control registers AArch32
===========================================================================*/

/*===========================================================================
                            MACROS
===========================================================================*/



/*===========================================================================
                            Functions 
===========================================================================*/

uint platform_cpu_num_to_cluster_id(uint cpu)
{ 
  if (cpu > SAILBSP_CPU_COUNT)
    while (1);

  cpu = (cpu >> SAILBSP_CPU_SIZE_SHFT);
  return ( cpu & SAILBSP_CLUSTER_FIELD_MASK);
}

uint platform_cpu_num_to_cpu_id(uint cpu)
{
  return (cpu & SAILBSP_CPU_FIELD_MASK);
}
#endif  