/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright 2017 The Fuchsia Authors
 * Portions Copyright (c) 2017, Google Inc. All rights reserved.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 *
 * Portions Copyright (c) 2012-2015 Travis Geiselbrecht
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
#include <assert.h>
#include <bits.h>
#include <err.h>
#include <types.h>
#include <arm_gic.h>
#include <reg.h>
#include <interrupts.h>
#include <ops.h>
#include <spinlock.h>
#include <debug_log.h>
#include "gic_config.h"
#include "target.h"
#include "ipcc_gic.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "interrupt_info.h"
#include "sail_csr_hwio.h"
#include <arm_gicv3_regs.h>
#include "el2_cpu.h"
//#if ARCH_ARM64
#include <arm64.h>
#define iframe arm64_iframe_short
#define IFRAME_PC(frame) ((frame)->elr)
//#endif

#define MAX_INT   992

#define LOCAL_TRACE 0
#define GIC_ROUTER_MPIDR_AFFINITY_MASK ((0xFFULL << 32) | (0xFFFFFFULL))

#define GICD_LOCK_FLAGS SPIN_LOCK_FLAG_INTERRUPTS
#define SMP_MAX_CPUS            2
#define SMP_MAX_CLUSTERS        2
#define GIC_MAX_PER_CPU_INT     32
#define GIC_MAX_SHARED_INT      MAX_INT
#define GIC_MAX_REG_TABLE_SIZE  32U
#define IRM_AFFINITY_BASED         (0 << 31)
#define IRM_ANY_PARTICIPATING      (1 << 31)

#define SAVE_FPU_REGISTERS_FROM_IRQ()    \
    __asm volatile                                  \
    (                                               \
        "   vstmdb  sp!, {d16-d31}  \n"             \
        "   vstmdb  sp!, {d0-d15}   \n"             \
        "   vmrs    r1, fpscr       \n"             \
        "   stmdb   sp!, {r1}       \n"             \
        ::: "r1", "memory"                          \
    )

#define RESTORE_FPU_REGISTERS_FROM_IRQ() \
    __asm volatile                                  \
    (                                               \
        "   ldmia   sp!, {r1}       \n"             \
        "   vmsr    fpscr, r1       \n"             \
        "   vldmia  sp!, {d0-d15}   \n"             \
        "   vldmia  sp!, {d16-d31}  \n"             \
        ::: "r1", "memory"                          \
    )

/* Structure of Interrupt handler */
struct int_handler_struct {
    unsigned int vector;
    int_handler handler;
    void *arg;
};

static uint gic_max_int;
static spin_lock_t gicd_lock[SMP_MAX_CLUSTERS];
static uint32_t arm_gicv3_gic_base[SMP_MAX_CLUSTERS] = {0};
static uint32_t arm_gicv3_gicd_offset[SMP_MAX_CPUS] = {0};
static uint32_t arm_gicv3_gicr_offset[SMP_MAX_CPUS] = {0};
static uint32_t arm_gicv3_gicr_stride[SMP_MAX_CPUS] = {0};
static uint32_t gic_init_done[SMP_MAX_CLUSTERS] = {0};
static uint32_t gic_pre_init_csr_programming_done = 0;
static struct int_handler_struct int_handler_table_per_cpu[GIC_MAX_PER_CPU_INT][SMP_MAX_CPUS][SAILBSP_CLUSTER_COUNT]; 
static struct int_handler_struct int_handler_table_shared[GIC_MAX_REG_TABLE_SIZE][SAILBSP_CLUSTER_COUNT];
static volatile uint64_t recent_irq_timestamp[SMP_MAX_CPUS];
uint32_t spi_prev_mask[SAILBSP_CLUSTER_COUNT][SMP_MAX_CPUS][32] = {0};
uint32_t ppi_prev_mask[SAILBSP_CLUSTER_COUNT][SMP_MAX_CPUS] = {0};
uint32_t ipi_base = 0;
enum handler_return eIrqHandlerRet = INT_NO_RESCHEDULE;

static bool gic_is_valid_interrupt(unsigned int vector, uint32_t flags)
{
    return (vector < gic_max_int);
}

static void gic_wait_for_rwp(uint64_t reg)
{
    int count = 1000000;
    while (GICREG(0, reg) & (1 << 31)) {
        count -= 1;
        if (!count) {
            //TODO: once vlog_message() is made reentrant function we can add log prints 
			//LOG_INFO("arm_gicv3: rwp timeout 0x%x\n", GICREG(0, reg));
            return;
        }
    }
}

/*  We need to write to GICR_WAKER as a workaround for UEFI not doing that, the
    hypervisor acts as if it had already been done the first time a VCPU is
    powered on, but that only applies the first time.
    So for the hotplug scenario we need to do the following:
    1. when switch on a GICR need to write 0 to GICR_WAKER and then read it back,
    polling until the value you read is 0. 
*/

static void gic_switch_on_gicr(uint64_t reg)
{
    int count = 1000000;
    while (GICREG(0, reg) !=0) {
        count -= 1;
        if (!count) {
		    //TODO: once vlog_message() is made reentrant function we can add log prints
            //LOG_INFO("arm_gicv3: waker timeout 0x%x\n", GICREG(0, reg));
            return;
        }
    }
}

/*  During unplug scenario: need to write 0x2 to GICR_WAKER
    (ProcessorSleep bit = 0x1)and then poll until it reads as 0x6 ie
    ProcessSleep bit and ChildrenAsleep bit both 0x1.*/
static void gic_switch_off_gicr(uint cpu)
{
   int count = 1000000;
   uint cluster = arch_curr_cluster_num(); 
   
   GICREG(0, GICR_WAKER(cluster,cpu)) = 0x2;   
   while (GICREG(0, GICR_WAKER(cluster,cpu)) !=0x6) {
        count -= 1;
        if (!count) {
		    //TODO: once vlog_message() is made reentrant function we can add log prints
            //LOG_INFO("arm_gicv3: waker timeout 0x%x\n", GICREG(0, GICR_WAKER(cluster,cpu)));
            return;
        }
    }
}
/* get installed vector handler */
static struct int_handler_struct *get_int_handler(unsigned int vector, uint cpu, uint cluster)
{
    struct int_handler_struct *slot = NULL;
    if (vector >= GIC_MAX_SHARED_INT)
    {
        return NULL;
    }
    
    if (vector < GIC_MAX_PER_CPU_INT)
    {
        slot =  &int_handler_table_per_cpu[vector][cpu][cluster];
    }
    else
    {
        for (int i = 0; i < GIC_MAX_REG_TABLE_SIZE; ++i)
        {
            if (int_handler_table_shared[i][cluster].vector == vector)
            {
                slot = &int_handler_table_shared[i][cluster];
                break;
            }
        }
    }
    return slot;
}
/* get free vector handler */
static struct int_handler_struct *get_int_handler_ex(unsigned int vector, uint cpu, uint cluster)
{
    struct int_handler_struct *slot = NULL;
    if (vector >= GIC_MAX_SHARED_INT)
    {
        return NULL;
    }

    if (vector < GIC_MAX_PER_CPU_INT)
    {
        slot =  &int_handler_table_per_cpu[vector][cpu][cluster];
    }
    else
    {
        for (int i = 0; i < GIC_MAX_REG_TABLE_SIZE; ++i)
        {
            if ( ( slot == NULL ) && ( int_handler_table_shared[i][cluster].vector == 0 ) )
            {
                slot = &int_handler_table_shared[i][cluster];
                break;
            }
        }
    }
    return slot;
}

static void set_csr_edge_sensitive_spi(uint32_t vector)
{
	uint32_t ridx = (vector-32)/32;
	uint32_t bitpos = vector%32;
	uint32_t rtcu_csr_spi_cfgn_val = 0;

	rtcu_csr_spi_cfgn_val = HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_INI(ridx);
	rtcu_csr_spi_cfgn_val &= ~(1<<bitpos);
	HWIO_SAILSS_CSR_RTCU_SPI_CONFIG_n_OUTI(ridx,rtcu_csr_spi_cfgn_val);

}

static void set_csr_edge_sensitive_ppi(uint32_t vector, uint32_t cpu_id)
{
    uint32_t bitpos = (vector-16) % 8; // This is tentative , rule may be subject to change in the future
	uint32_t rtcu_csr_ppi_cfg_val = 0;

	rtcu_csr_ppi_cfg_val = HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_INI(cpu_id);
	//Clear the bit to mark the PPI as edge triggered.
	rtcu_csr_ppi_cfg_val &= ~(1<<bitpos);
	HWIO_SAILSS_CSR_RTCU_CORE_n_PPI_CONFIG_OUTI(cpu_id,rtcu_csr_ppi_cfg_val);
}

static void gic_pre_init_percpu_csr_programming(uint32_t cpu)
{
	uint32_t ninterrupts = 0;
    uint32_t index = 0;

    //Program SAILSS_CSR_RTCU_PPI_CONFIG_n[n=0-29] for all external PPI interrupts
    ninterrupts = SIZEOF_ARRAY(edge_interrupts_ext_ppi);
    for (index = 0; index < ninterrupts; index++) {
    	set_csr_edge_sensitive_ppi( edge_interrupts_ext_ppi[index] ,cpu);
    }
}

static uint arch_max_num_cpus(void)
{
  return SMP_MAX_CPUS;
}

static uint arch_max_num_clusters(void)
{
  return SMP_MAX_CLUSTERS;
}

static void gic_set_igroup0(uint vector) 
{
    uint32_t reg = vector/32;
    uint32_t mask = ~(1ULL << (vector%32));
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    uint32_t igroup_val = 0x0;

    
    igroup_val = GICREG(0, GICD_IGROUPR(cluster,reg));
    GICREG(0, GICD_IGROUPR(cluster,reg)) = igroup_val & mask;
    gic_wait_for_rwp(GICD_CTLR(cluster));
    
}

static void gic_set_enable(uint vector, bool enable)
{
    int reg = vector / 32;
    uint32_t mask = 1ULL << (vector % 32);
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num(); 
    spin_lock_saved_state_t state;

    if (vector < 32) {
        if (enable)
            GICREG(0, GICR_ISENABLER0(cluster,cpu)) = mask;
        else
            GICREG(0, GICR_ICENABLER0(cluster,cpu)) = mask;

        gic_wait_for_rwp(GICR_CTLR(cluster,cpu));
    }else{
        spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);
        
        if (enable)
            GICREG(0, GICD_ISENABLER(cluster,reg)) = mask;
        else
            GICREG(0, GICD_ICENABLER(cluster,reg)) = mask;
        
        spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
        gic_wait_for_rwp(GICD_CTLR(cluster));

    }
}

static void  configure_interrupt_sgi(unsigned int vector, enum intr_config icfg, uint cluster, uint cpu){
    switch (icfg)
    {
       case INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR0(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICR_ICFGR0(cluster,cpu)) = cfg_val;
         }
       break;

       case INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR0(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICR_ICFGR0(cluster,cpu)) = cfg_val;
         }
       break;

     default:
       break;
    }
}

static void  configure_interrupt_spi(unsigned int vector, enum intr_config icfg,uint cluster){
    
    spin_lock_saved_state_t state;
    
    spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);
    switch (icfg)
    {
       case INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset, reg;

           reg = vector / 16;

           cfg_val = GICREG(0, GICD_ICFGR(cluster,reg));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICD_ICFGR(cluster,reg)) = cfg_val;
         }
       break;

       case INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset, reg;

           reg = vector / 16;

           cfg_val = GICREG(0, GICD_ICFGR(cluster,reg));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICD_ICFGR(cluster,reg)) = cfg_val;
         }
       break;

     default:
       break;
    }
    //Settng the group of the interrupt. Any interrpt in EL2 is FIQ
    gic_set_igroup0(vector);
    spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
}

static void  configure_interrupt_ppi(unsigned int vector, enum intr_config icfg, uint cluster, uint cpu){
    switch (icfg)
    {
       case INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR1(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICR_ICFGR1(cluster,cpu)) = cfg_val;
         }
       break;

       case INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR1(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICR_ICFGR1(cluster,cpu)) = cfg_val;
         }
       break;

     default:
       break;
    }
    
}

static
enum handler_return __platform_irq(struct iframe *frame)
{
    // get the current vector
    uint32_t iar;
    unsigned vector;
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();

    recent_irq_timestamp[cpu] = get_timer_cnt ();

    iar = gic_read_iar();

    vector = iar & 0x3ff;

    if (vector >= gic_max_int) {
        // spurious
        // TODO check this
        return INT_NO_RESCHEDULE;
    }


    //LOG_INFO("iar 0x%x cpu %u currthread %p vector %d pc 0x%lx\n", iar, cpu,
    //              get_current_thread(), vector, (uintptr_t)IFRAME_PC(frame));

    // deliver the interrupt
    enum handler_return ret;

    ret = INT_NO_RESCHEDULE;
    struct int_handler_struct *handler = get_int_handler(vector, cpu,cluster);
    if (handler && (handler->handler))
    {
      ret = handler->handler(handler->arg);
    }

    gic_write_eoir(vector);

    //LOG_INFO( "cpu %u exit %d\n", cpu, ret);

    return ret;
}



static
enum handler_return __platform_fiq(struct iframe *frame)
{
    // get the current vector
    uint32_t iar0;
    unsigned vector;
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();

    recent_irq_timestamp[cpu] = get_timer_cnt ();

    iar0 = gic_read_iar0();

    vector = iar0 & 0x3ff;

    if (vector >= gic_max_int) {
        // spurious
        // TODO check this
        return INT_NO_RESCHEDULE;
    }

    //LOG_INFO("iar 0x%x cpu %u currthread %p vector %d pc 0x%lx\n", iar, cpu,
    //              get_current_thread(), vector, (uintptr_t)IFRAME_PC(frame));

    // deliver the interrupt
    enum handler_return ret;

    ret = INT_NO_RESCHEDULE;
    struct int_handler_struct *handler = get_int_handler(vector, cpu,cluster);
    if (handler && (handler->handler))
    {
      ret = handler->handler(handler->arg);
    }

    gic_write_eoir0(vector);

    //LOG_INFO( "cpu %u exit %d\n", cpu, ret);

    return ret;
}

status_t register_int_handler(unsigned int vector, int_handler handler, void *arg)
{
    struct int_handler_struct *h;
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();
    status_t  ret = ERR_GENERIC;
    spin_lock_saved_state_t state;

    if (vector >= MAX_INT)
        LOG_ERROR("register_int_handler: vector out of range %d\n", vector);

    spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);
    
    //ToDo : Add a hook function here to enforce IRQs to certain Clusters instance of GIC. 
    // This should be based on a static list made available during compile time.
    //We can add this once we have multi cluster env with GICs enabled.
    
    h = get_int_handler_ex(vector, cpu,cluster);
    
    if(h == NULL)
    {
        spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
        return ERR_NOT_VALID;
    }
    //If no one has registered for the interrupt we go ahead with the registration
    if (h->vector == 0 )
    {
        h->vector = vector;
        h->handler = handler;
        h->arg = arg;

        ret = NO_ERROR;      
    }
    else {
        ret = ERR_ALREADY_EXISTS;
    }

    spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);

    return ret;
}

status_t set_int_priority(unsigned int vector, unsigned int priority)
{
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();
    status_t  ret = ERR_GENERIC;
    spin_lock_saved_state_t state;
    uint32_t priorityRegisterAddress;
    uint32_t priorityValue;
    uint32_t priorityShiftValue;
    
    if (vector >= MAX_INT)
        LOG_ERROR("register_int_handler: vector out of range %d\n", vector);

    if(vector < GIC_MAX_PER_CPU_INT)
    {
        priorityRegisterAddress = GICR_IPRIORITYR0(cluster,cpu) + ((vector/0x4U) * 4U);
    }
    else
    {
        priorityRegisterAddress = GICD_IPRIORITYR(cluster,(vector/0x4U));
    }

    spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);

    priorityShiftValue = (vector % 0x4U) * 0x8U;
    priorityValue = GICREG(0, priorityRegisterAddress);
    priorityValue &= ~( 0xFFU << priorityShiftValue );
    priorityValue |= ( priority << priorityShiftValue );
    GICREG(0, priorityRegisterAddress) = priorityValue;

    spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);

    ret = NO_ERROR; 
    return ret;
}

status_t unregister_int_handler(unsigned int vector, unsigned int flags)
{
    struct int_handler_struct *h;
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();
    status_t  ret = ERR_GENERIC;
    spin_lock_saved_state_t state;

    if (vector >= MAX_INT)
        LOG_ERROR("register_int_handler: vector out of range %d\n", vector);

    spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);
    
    //ToDo : Add a hook function here to enforce IRQs to certain Clusters instance of GIC. 
    // This should be based on a static list made available during compile time.
    //We can add this once we have multi cluster env with GICs enabled.
    
    h = get_int_handler(vector, cpu,cluster);
    if(h == NULL)
    {
        spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
        return ERR_NOT_VALID;
    }
    //If no one has registered for the interrupt we go ahead with the registration
    if (h->vector == vector )
    {
        h->vector = 0x0;
        h->handler = NULL;
        h->arg = NULL;
        
        ret = NO_ERROR;      
    }
    else {
        ret = ERR_NOT_ALLOWED;
    }

    spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
    return ret;
}

void gic_pre_init_csr_programming()
{
	uint32_t ninterrupts = 0;
    uint32_t index = 0;
    uint32_t rtcu_csr_ctrl_val = 0;

    if(gic_pre_init_csr_programming_done) {
    	 LOG_ERROR( "GIC RTCU CSR Init already done: Should not be called again!\n");
         return; 
    }
	//Turn OFF dynamic clock power-mgmt for interrupts
    rtcu_csr_ctrl_val = HWIO_SAILSS_CSR_RTCU_CONTROL_IN;
    //Set bit 8 and 9 toTurn OFF dynamic clock power-mgmt for interrupts
    rtcu_csr_ctrl_val |= (3<<8);
    HWIO_SAILSS_CSR_RTCU_CONTROL_OUT(rtcu_csr_ctrl_val);

	//Program SAILSS_CSR_RTCU_SPI_CONFIG_n[n=0-29] for all SPI interrupts
    ninterrupts = SIZEOF_ARRAY(edge_interrupts_spi);
    for (index = 0; index < ninterrupts; index++) {
    	set_csr_edge_sensitive_spi( edge_interrupts_spi[index] );
    }

    //Program SAILSS_CSR_RTCU for all PPI interrupts for each cpu core
    for(index = 0;index < SAILBSP_CPU_COUNT;index++){
    	gic_pre_init_percpu_csr_programming(index);
    }

#if 0  //ToDo : rrahul Renable this once all hw issues are resolved for dynamic clock pwr-mgmt
    //Turn ON dynamic clock power-mgmt for interrupt
    rtcu_csr_ctrl_val = HWIO_SAILSS_CSR_RTCU_CONTROL_IN;
    //Clear bit 8 and 9 toTurn OFF dynamic clock power-mgmt for interrupts
    rtcu_csr_ctrl_val &= ~(3<<8);
    HWIO_SAILSS_CSR_RTCU_CONTROL_OUT(rtcu_csr_ctrl_val);
#endif //#if 0

    gic_pre_init_csr_programming_done = 1;
}

void gic_init_percpu_early(int level)
{
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num(); 
    
    if (gic_init_done[cluster] == 0)
      arm_gic_v3_init (cluster);

    // configure sgi/ppi as non-secure group 1
    GICREG(0, GICR_IGROUPR0(cluster,cpu)) = ~0;
    gic_wait_for_rwp(GICR_CTLR(cluster,cpu));

    // clear and mask sgi/ppi
    GICREG(0, GICR_ICENABLER0(cluster,cpu)) = 0xffffffff;
    GICREG(0, GICR_ICPENDR0(cluster,cpu)) = ~0;
    gic_wait_for_rwp(GICR_CTLR(cluster,cpu));

    GICREG(0, GICR_WAKER(cluster,cpu)) = 0x0;
    gic_switch_on_gicr(GICR_WAKER(cluster,cpu));

    // TODO lpi init

    uint32_t sre = gic_read_sre();
    if (!(sre & 0x1)) {
        gic_write_sre(sre | 0x1);
        sre = gic_read_sre();
        assert(sre & 0x1);
    }

    // set priority threshold to max
    gic_write_pmr(0xff);

    // TODO EOI deactivates interrupt - revisit
    gic_write_ctlr(0);

    // enable group 0 and group 1 interrupts ToDO --- Once SafeRTOS is fully enabled disable enabling group 1 interrupts here
    gic_write_igrpen0(1);
    gic_write_igrpen(1);

    // Enabling aborts and FIQs
    arch_enable_aborts();
    arch_enable_fiqs();
}

void arm_gic_suspend (void)
{
 //   uint32_t typer;
 //   uint rev, idbits;
    uint i;
    uint cluster = arch_curr_cluster_num(); 
    /* Clear/disable all remaining interrupt sources */
    for (i = 0; i < gic_max_int; i++)
      mask_interrupt(i);

    // disable the distributor
    GICREG(0, GICD_CTLR(cluster)) = 0;
    gic_wait_for_rwp(GICD_CTLR(cluster));
    ISB;
}

void arm_gic_suspend_cpu(uint level)
{
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num(); 
    uint64_t mpidr;

    gic_write_igrpen(0);

    // clear and mask sgi/ppi
    GICREG(0, GICR_ICPENDR0(cluster,cpu)) = 0xFFFFFFFF;
    gic_wait_for_rwp(GICR_CTLR(cluster,cpu));
    GICREG(0, GICR_ICENABLER0(cluster,cpu)) = 0xFFFFFFFF;
    gic_wait_for_rwp(GICR_CTLR(cluster,cpu));

    /* Read MPIDR register */
    //mpidr = ARM64_READ_SYSREG(mpidr_el1);
    mpidr = arch_read_mpidr();

    // mask and clear spi
    uint vector;
    for (vector = 32; vector < gic_max_int; vector++)
    {
       /* Check if the vector is configured to route to this particular cpu/affinity. */
       if(( GICREG64(0, GICD_IROUTER(cluster, vector) )| IRM_AFFINITY_BASED ) == (mpidr & GIC_ROUTER_MPIDR_AFFINITY_MASK))
       {
          int reg = vector / 32;
          uint32_t mask = 1ULL << (vector % 32);
          /* Mask and clear SPI that are configured to route to this specific cpu. */
          GICREG(0, GICD_ICENABLER(cluster,reg)) = mask;
          GICREG(0, GICD_ICPENDR(cluster,reg)) = mask;
       }    
    }
    gic_wait_for_rwp(GICD_CTLR(cluster));

    gic_switch_off_gicr(cpu);

}

void arm_gic_resume_cpu(uint level)
{
    spin_lock_saved_state_t state;
    uint cluster = arch_curr_cluster_num(); 

    spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);
	#if 0
    if (!(GICREG(0, GICD_CTLR(cluster)) & 1)) {
        //dprintf(SPEW, "%s: distibutor is off, calling arm_gic_init instead\n", __func__);
        arm_gic_v3_init(0);
    } else {
        gic_init_percpu_early(0);
    }
    #endif
    uint cpu = arch_curr_cpu_num();
    GICREG(0, GICR_WAKER(cluster,cpu)) = 0x0;   
    gic_switch_on_gicr(GICR_WAKER(cluster,cpu));

    spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
}

void gic_init(void)
{
    uint32_t typer;
    uint cluster = arch_curr_cluster_num();  
    __UNUSED uint rev, idbits;

    if (gic_init_done[cluster] == 0)
      arm_gic_v3_init (cluster);
      
    rev = (GICREG(0, GICD_PIDR2(cluster)) >> 4) & 0xf;
    assert(rev == 3 || rev == 4);

    typer = GICREG(0, GICD_TYPER(cluster));
    idbits = typer & 0x1f;
    gic_max_int = (idbits + 1) * 32;
//    dprintf (SPEW, "gic_init max_irqs: %u\n", gic_max_int);

    if (gic_max_int < MAX_INT)
    {
      //dprintf (SPEW, "Max ints %d exceed Gic supported max ints %u\n", MAX_INT, gic_max_int);
      gic_max_int = MAX_INT;
    }

    // disable the distributor
    GICREG(0, GICD_CTLR(cluster)) = 0;
    gic_wait_for_rwp(GICD_CTLR(cluster));
    ISB;

    // mask and clear spi
    uint i;
    for (i = 32; i < gic_max_int; i += 32) {
        GICREG(0, GICD_ICENABLER(cluster, i / 32)) = ~0;
        GICREG(0, GICD_ICPENDR(cluster, i / 32)) = ~0;
    }
    gic_wait_for_rwp(GICD_CTLR(cluster));

    // enable distributor with ARE, group 1 enable
    GICREG(0, GICD_CTLR(cluster)) = (1 << 4) | (1 << 1) | (1 << 0);
    gic_wait_for_rwp(GICD_CTLR(cluster));

    uint64_t mpidr = 0;
	uint64_t gic_routing;
	#define MPIDR_AFFINITY_MASK  ((0xFFULL << 32) | (0xFFFFFFULL))
	
	//__asm__ __volatile__("mrs %0, MPIDR_EL1":"=r"(mpidr));
    __asm__ volatile("MRC p15,0,%0,c0,c0,5" : "=r"(mpidr) : );
	
	uint64_t affinity = mpidr & MPIDR_AFFINITY_MASK;
	
	gic_routing = affinity | IRM_AFFINITY_BASED;

	// set spi to route to boot core. must do this after ARE enable
    if (SMP_MAX_CPUS > 0) {
        for (i = 32; i < gic_max_int; i++) {
            GICREG64(0, GICD_IROUTER(cluster,i)) = gic_routing;
        }   
    }

    for (i = 32; i < gic_max_int; i += 16)
        GICREG(0, GICD_ICFGR(cluster, i / 16)) = 0;

    for (i = 32; i < gic_max_int; i += 32) 
        GICREG(0, GICD_IGROUPR(cluster, i / 32)) = ~0;

    /* Ticket locks need explicit initialization */
    for (i = 0; i < SMP_MAX_CLUSTERS; i++)
    {
        arch_spin_lock_init (&gicd_lock[i]);
    }
    
}

void arm_gic_update_routing (unsigned int vector, uint64_t affinity)
{
  uint64_t gic_routing;
  uint cluster = arch_curr_cluster_num();  
  
  gic_routing = affinity | IRM_AFFINITY_BASED;

  GICREG64(0, GICD_IROUTER(cluster,vector)) = gic_routing;
}

void arm_gic_v3_init(int cluster)
{
  gic_init_done[cluster]++;
  gic_init();
}

void arm_gic_params_init(uint32_t cluster)
{
  arm_gicv3_gic_base[cluster] = 0x00U;
  arm_gicv3_gicd_offset[cluster] = sailbsp_gic_instances[cluster].gic_distributor_offset;
  arm_gicv3_gicr_offset[cluster] = sailbsp_gic_instances[cluster].gic_redistributor_offset;
  arm_gicv3_gicr_stride[cluster] = sailbsp_gic_instances[cluster].gic_redistributor_stride;
  //ipi_base = targ_ipi_base; //ToDo check the use of this and renable later.
}

//ToDo need to vet this API in more detail.
status_t arm_gic_sgi(u_int irq, u_int flags, u_int cpu_mask)
{
    uint cp = arch_curr_cpu_num();//ToDo check if this API is supposed to give a cummulative CPU_ID instead of core id in the gven cluster
    //TODO: once vlog_message() is made reentrant function we can add log prints
	//LOG_INFO("sgi to %d : %x  %x %x\n", cp, irq, flags, cpu_mask);

    if (flags != ARM_GIC_SGI_FLAG_NS) {
        return ERR_INVALID_ARGS;
    }

    if (irq >= 16) {
        return ERR_INVALID_ARGS;
    }

    smp_wmb();

    uint cpu = 0;
    uint curr_cpu_id = arch_curr_cpu_id();
    uint cluster = 0; 
    uint curr_cluster = arch_curr_cluster_num();  
    uint64_t val = 0;
    while (cpu_mask && (cpu < SAILBSP_CPU_COUNT) && (cluster < arch_max_num_clusters())) {
        u_int mask = 0;
        while (platform_cpu_num_to_cluster_id(cpu) == cluster) {
            if (cpu_mask & (1u << cpu)) {
                mask |= 1u << platform_cpu_num_to_cpu_id(cpu);
                cpu_mask &= ~(1u << cpu);
            }
            cpu += 1;
        }
        if(cluster == curr_cluster){
#if 0
#define IRM_ALL_PE_EXCEPT_SELF   (1 << 40)

            val = ((irq & 0xf) << 24) |
                  IRM_ALL_PE_EXCEPT_SELF
#else
            val = ((irq & 0xf) << 24) |
                  ((cluster & 0xff) << 16) |
                (mask & 0xff);
#endif
            gic_write_sgi1r(val);
        }
        else{
            //ToDo enable the below send interrupts to the cores in the other cluser.
            ipcc_gic_send_interrupt(irq,cluster,mask, curr_cpu_id);
        }
        cluster += 1;

    }


    return NO_ERROR;
}

status_t mask_interrupt(unsigned int vector)
{
    if (vector >= gic_max_int)
        return ERR_INVALID_ARGS;

    gic_set_enable(vector, false);

    return NO_ERROR;
}

status_t unmask_interrupt(unsigned int vector)
{
    uint cpu = arch_curr_cpu_num();
    if (vector >= gic_max_int)
        return ERR_INVALID_ARGS;

    //TODO: once vlog_message() is made reentrant function we can add log prints
	//LOG_INFO( "umask cpu %u vect %d\n", cpu, vector);
    gic_set_enable(vector, true);

    return NO_ERROR;
}

status_t configure_interrupt(unsigned int vector, enum intr_config icfg, void* arg)
{
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();   
    
    if (vector >= gic_max_int)
        return ERR_INVALID_ARGS;

    if (icfg >= INT_CONFIG_MAX)
        return ERR_INVALID_ARGS;

    //TODO: once vlog_message() is made reentrant function we can add log prints
	//LOG_INFO("config cpu %u vect %d cfg %d val %lx\n", cpu, vector, icfg, (unsigned long)arg);

    if(vector < 16) 
        configure_interrupt_sgi(vector,icfg,cluster,cpu);
    else if(vector >= 16 && vector < 32)
        configure_interrupt_ppi(vector,icfg,cluster,cpu);
    else 
        configure_interrupt_spi(vector,icfg,cluster);
    
    return NO_ERROR;
}

enum handler_return platform_irq(struct iframe *frame)
{
	SAVE_FPU_REGISTERS_FROM_IRQ();
    eIrqHandlerRet = __platform_irq(frame);
	RESTORE_FPU_REGISTERS_FROM_IRQ();
	
	return eIrqHandlerRet;
}

enum handler_return platform_fiq(struct iframe *frame)
{
    //@TODO : Recheck if we have to do anything different for FIQs.
    //for now using the  IRQ stack. 
	SAVE_FPU_REGISTERS_FROM_IRQ();
    eIrqHandlerRet = __platform_fiq(frame);    
	RESTORE_FPU_REGISTERS_FROM_IRQ();
	
	return eIrqHandlerRet;
}

void arm_gic_mask_spi(void)
{  
   uint cpu = arch_curr_cpu_num();
   uint cluster = arch_curr_cluster_num();
   spin_lock_saved_state_t state;
   
   spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);

   for (uint i = 32; i < gic_max_int; i += 32)
   {
      spi_prev_mask[cluster][cpu][(i/32)-1] = GICREG(0, GICD_ISENABLER(cluster, i / 32)) ;
      //mask++;

      GICREG(0, GICD_ICENABLER(cluster, i / 32)) = ~0;
       // GICREG(0, GICD_ICPENDR(i / 32)) = ~0;
   }

   spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
   gic_wait_for_rwp(GICD_CTLR(cluster)); 

}

void arm_gic_mask_ppi(void)
{
   //uint32_t prev_val_ppi;
   uint cpu = arch_curr_cpu_num();
   uint cluster = arch_curr_cluster_num();
   /* PPI INTID: 16 to 31 */ 
   ppi_prev_mask[cluster][cpu] = GICREG(0, GICR_ISENABLER0(cluster,cpu));

   uint32_t set_mask = 0xFFFF0000;
   GICREG(0, GICR_ICENABLER0(cluster,cpu)) = set_mask;
   //GICREG(0, GICR_ICPENDR0(cpu)) = mask;
   gic_wait_for_rwp(GICR_CTLR(cluster,cpu));

}

void arm_gic_unmask_spi(void)
{
   uint cpu = arch_curr_cpu_num();
   uint cluster = arch_curr_cluster_num();
   spin_lock_saved_state_t state;

   spin_lock_save(&gicd_lock[cluster], &state, GICD_LOCK_FLAGS);

   for (uint i = 32; i < gic_max_int; i += 32)
   {
        GICREG(0, GICD_ISENABLER(cluster, i / 32)) = spi_prev_mask[cluster][cpu][(i/32)-1];
        //mask++;
       // GICREG(0, GICD_ICPENDR(i / 32)) = ~0;
    }
   spin_unlock_restore(&gicd_lock[cluster], state, GICD_LOCK_FLAGS);
   gic_wait_for_rwp(GICD_CTLR(cluster));
}

void arm_gic_unmask_ppi(void)
{
   uint cpu = arch_curr_cpu_num();
   uint cluster = arch_curr_cluster_num();
   /* PPI INTID: 16 to 31 */ 
   //uint32_t mask = 0xFFFF0000;
   GICREG(0, GICR_ISENABLER0(cluster, cpu)) = ppi_prev_mask[cluster][cpu];
   //GICREG(0, GICR_ICPENDR0(cpu)) = mask;
   gic_wait_for_rwp(GICR_CTLR(cluster, cpu));
}

void gic_handle_ipcc_sgi(uint32 vector){
    
    uint cpu = arch_curr_cpu_num();
    uint cluster = arch_curr_cluster_num();
    enum handler_return ret;
    
    recent_irq_timestamp[cpu] = get_timer_cnt ();

    struct int_handler_struct *handler = get_int_handler(vector, cpu,cluster);
    if (handler && (handler->handler))
    {
      ret = handler->handler(handler->arg);
    }

    //TODO: once vlog_message() is made reentrant function we can add log prints
	//LOG_INFO( "cpu %u exit %d\n", cpu,ret);   
}
