/**
 * @file el2_sys_fields.h
 * @brief EL2 Hypervisor System Field definitions
 * Header file for the definition of hypervisor system fields info used in sail
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
07.02.21   rrahul       Created
=============================================================================*/

#ifndef EL2_SYS_FIELDS_H
#define EL2_SYS_FIELDS_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/


/*===========================================================================
                           DEFINITION OF EL2 Control registers AArch32
===========================================================================*/


/**
 * Constants for CPSR mode bits.
 */
#define CPSR_MODE_USR           0x10
#define CPSR_MODE_FIQ           0x11
#define CPSR_MODE_IRQ           0x12
#define CPSR_MODE_SVC           0x13
#define CPSR_MODE_ABT           0x17
#define CPSR_MODE_HYP           0x1a
#define CPSR_MODE_UND           0x1b
#define CPSR_MODE_SYS           0x1f

#define CPSR_MODE_MASK          0x1f  /* CPSR mask for CPU mode.*/

#define CPSR_A_BIT              0x100
#define CPSR_I_BIT              0x80
#define CPSR_F_BIT              0x40
#define CPSR_T_BIT              0x20
#define CPSR_M_BIT              0x10

#define DAIFSET_D_BIT           0x08    /* Debug exception mask bit */
#define DAIFSET_A_BIT           0x04    /* SError mask bit */
#define DAIFSET_I_BIT           0x02    /* IRQ mask bit */
#define DAIFSET_F_BIT           0x01    /* FIQ mask bit */

/*===========================================================================
                            MACROS
===========================================================================*/


#endif  //EL2_SYS_FIELDS_H