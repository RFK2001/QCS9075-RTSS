/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __PLATFORM_INTERRUPTS_H
#define __PLATFORM_INTERRUPTS_H

/*=========================================================================
      Include Files
==========================================================================*/
#include "types.h"

/*=========================================================================
      Type Definitions
==========================================================================*/
/**
 * Interrupt handlers callback data type.
 */
typedef enum handler_return (*int_handler)(void *arg);

/**
 * Interrupt configuration enum.
 */
enum intr_config
{
   INT_CONFIG_LEVEL_TRIGGER    = 0,
   INT_CONFIG_EDGE_TRIGGER     = 1, /*EL2 : edge trigger is registered based on the case statement (1), EL1: edge trigger is registerd directly in GIC with value (2) for edge*/
   INT_CONFIG_MAX,
};
/*=========================================================================
      Interface Declarations
==========================================================================*/

/* =========================================================================
**  Function : gic_pre_init_csr_programming
** =========================================================================*/
/**
  Programs the RTCU CSR space for Edge Type SPI and PPI IRQs.

  This function must be called before the GIC is initialized for the first 
  for either cluster. This is called only once.

  @param level        [in].

  @return none

  @dependencies
  This is called only once. And called before the GIC Driver is initlaized.
*/

void gic_pre_init_csr_programming(void);
/* =========================================================================
**  Function : gic_init_percpu_early
** =========================================================================*/
/**
  Wakes up the GICR and ICC blocks in the GIC HW.

  This function must be called as for every core during cold boot and warm boot.

  @param level        [in].

  @return none

  @dependencies
  Driver must be initialized and CPU core must be up.
*/
void     gic_init_percpu_early(int level);

/* =========================================================================
**  Function : mask_interrupt
** =========================================================================*/
/**
  Masks the said interrupt in the GIC HW. 

  This function must be called before registering for any IRQ/FIQ. 

  @param vector        [in]. Interrupt id

  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t mask_interrupt(unsigned int vector);

/* =========================================================================
**  Function : register_int_handler
** =========================================================================*/
/**
  Registers a callback for the said interrupt. 

  This function must be called for any IRQ/FIQ that is being handled in the SW. 

  @param vector         [in].Interrupt id
  @param handler        [in].callback for the said interrupt.
  @param arg            [in].handler to the arguments to be passed with the callback function.
  
  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t register_int_handler(unsigned int vector, int_handler handler, void *arg);

/* =========================================================================
**  Function : set_int_priority
** =========================================================================*/
/**
  Assgins a priority for the said interrupt. 

  @param vector         [in].Interrupt id
  @param priority       [in].priority for the said interrupt.

  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t set_int_priority(unsigned int vector, unsigned int priority);

/* =========================================================================
**  Function : configure_interrupt
** =========================================================================*/
/**
  Configures the interrupt to be either level/edge triggered. 

  This function must be called for any IRQ/FIQ that is being registered in the SW. 

  @param vector         [in].Interrupt id
  @param handler        [in].configuration enum for the said interrupt.
  @param arg            [in].

  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t configure_interrupt(unsigned int vector, enum intr_config icfg, void* arg);

/* =========================================================================
**  Function : arm_gic_update_routing
** =========================================================================*/
/**
  Update the routing inforamtion for the said  

  This function must be called for any IRQ/FIQ that is being registered in the SW. 

  @param vector         [in].Interrupt id
  @param affinity       [in].Affinity programming of the core which is to handle the irq.

  @return none

  @dependencies
  Driver must be initialized.
*/
void     arm_gic_update_routing (unsigned int vector, uint64 affinity);

/* =========================================================================
**  Function : unregister_int_handler
** =========================================================================*/
/**
  UnRegisters a callback for the said interrupt. 

  

  @param vector         [in].Interrupt id
  @param flags          [in]. 
  
  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t unregister_int_handler(unsigned int vector, unsigned int flags);

/* =========================================================================
**  Function : unmask_interrupt
** =========================================================================*/
/**
  UnMasks the said interrupt in the GIC HW. 

  This function must be called for enabling the IRQ/FIQ. 

  @param vector        [in]. Interrupt id

  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t unmask_interrupt(unsigned int vector);

/* =========================================================================
**  Function : arm_gic_sgi
** =========================================================================*/
/**
  Triggers a SGI to the destination cores mentioned in the cpu_mask. 

  @param vector         [in].SGI id
  @param flags          [in].Flags sepcific to the SGI
  @param cpu_mask       [in].mask that will hold the destination inforamtion .
  
  @return error status 

  @dependencies
  Driver must be initialized.
*/
status_t arm_gic_sgi(u_int vector, u_int flags, u_int cpu_mask);

/* =========================================================================
**  Function : arm_gic_v3_init
** =========================================================================*/
/**
  Function to initilaize the GIC.
  This function must be called before using any interrupt driver APIs 

  @param cluster         [in].cluster id
  
  @return              None 

  @dependencies
*/
void arm_gic_v3_init(int cluster);

/* =========================================================================
**  Function : arm_gic_params_init
** =========================================================================*/
/**
  Function to initilaize base and offset addresses of GICD and GICR in instance 
  variables.
  This function must be called before arm_gic_v3_init 

  @param cluster         [in].cluster id
  
  @return              None 

  @dependencies
*/
void arm_gic_params_init(uint32_t cluster);
#endif
