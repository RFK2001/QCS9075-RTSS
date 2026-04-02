/**
 * @file boot.c
 * @brief
 * Source file for Sail boot up routines
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
07.08.21   rrahul       Created
=============================================================================*/


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "errno.h"
#include "boot.h"
#include "debug_log.h"
#include "target.h"
//#include "IPCC.h"
//#include "interrupts.h"
//#include "sail_csr_hwio.h"
//#include "HALhwio.h"
//#include "sail_security_control_hwio.h"
//#include "hw_io.h"
//#include "wdt.h"
#include "arm_acle.h"
#include "locale.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "sailheap.h"
#include "sailbsp_mutex.h"

/*===========================================================================
                           MACROS
===========================================================================*/
#define BOOT_FUNC __attribute__( ( section ( "boot_func" ) ) )
/*===========================================================================
                               VARIABLES
============================================================================*/
uint8 boot_cluster_init_state[SAILBSP_CLUSTER_COUNT] = {0};

/*===========================================================================
                               SYS CALL DECLARATION
============================================================================*/

/*===========================================================================
                               EXTERN
============================================================================*/
extern int  sailbsp_main (void);
/*
 *===========================================================================
                               Helper FUNCTIONS
 *===========================================================================*/
#define SAILBSP_HEAP_DATA __attribute__ ( ( section ( "sailbsp_heap_data" ) ) )

SAILBSP_HEAP_DATA uint8_t ucSailHeapEL1[SAILBSP_CPU_COUNT][SAILHEAP_EL1_SIZE] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE)));
SAILBSP_HEAP_DATA static mutex_t xSailHeapEL1Mutex[SAILBSP_CPU_COUNT];
static void vSailHeapEL1Init(int cpu)
{
    int slRet = 0;
    memset(&ucSailHeapEL1[cpu], 0, SAILHEAP_EL1_SIZE);
    slRet = sailheap_init(&xSailHeapEL1Mutex[cpu], (void *)&ucSailHeapEL1[cpu], SAILHEAP_EL1_SIZE);
    if (slRet != 0)
    {
        err_fatal(EL_ENTRY, slRet);
    }
}
 /*===========================================================================
**  Function :  heap_init
** ==========================================================================
*/

/*
*
* @brief
*   Routine which initalizes the ARMLIBs heap allocator.
*
* @param
*   Heap Start  address and Heap End address.
* @par Dependencies
*   Earmark the Heap and Stack paritions. Update the Stack section in Linker script
* @retval
*   None
* @par Side Effects
*   None
*
*/
BOOT_FUNC void heap_init(int cpu) {
    /*We are not providing "__rt_heap_extend" implementation. If the system runs of heap
     * we prefer to crash and know about the use case. Update the heap size as needed.
     * If at a later point it is decided that he  means of dynamic heap extension is required
     * then have a memory allocator in palce. Update "__rt_heap_extend" after using that allocator.
     */

    //Invoke the armlib _init_alloc function with the heap descriptors as arguments.
    //_init_alloc(SAILBSP_HEAP_BASE,SAILBSP_HEAP_END);
	vSailHeapEL1Init(cpu);
}

 static void boot_cluster_init(int cluster_idx) {
   //add assert statement that cluster_idx is <= SAILBSP_CLUSTER_COUNT
  if(cluster_idx >= SAILBSP_CLUSTER_COUNT)
  {
	  //TODO Currently commented the below line since the linking is required for sailsw1 image.
      //LOG_ERROR("boot_cluster_init : Cluster index is invalid %d", cluster_idx);
  }
  if(boot_cluster_init_state[cluster_idx])
    return;

  // Enable this once GIC HW support prsent in RUMI
  //arm_gic_params_init(cluster_idx);
  //arm_gic_v3_init(cluster_idx);

  //Update cluster init state.We do this once for each cluster.
  boot_cluster_init_state[cluster_idx] = 1;

 }
 BOOT_FUNC static void boot_cold_init(int boot_cpu_idx) {
  //API#1-Commom Cold Boot routine to be placed in withing this.Called only on the boot core.
  //gic_pre_init_csr_programming();
  boot_cluster_init(0);
}

 BOOT_FUNC static void boot_cpu_cold_init(int cpu_index) {
  //API#2-Any per cpu cold boot touines to be places here. Called for all the cores.
  /*Inititalize IPCC Protocols*/
  //IPCC_InitEx(IPCC_P_SAIL_MPROC, cpu_index);

  /*IPCC Client Registration */
  //ipcc_gic_register_cpu(cpu_index);

}

BOOT_FUNC static void boot_cpu_warm_init(int cpu) {
  //API#3- Warm (second boot or later) routines that are common to cold boot and warm boot path of any CPU.
  //gic_init_percpu_early(cpu);\
  //ToDo -- invoke get_logical_cpu_id() and pass that here.
  heap_init(cpu);
}

static void boot_sail_main(void) {
  //API#4-Item#1 Anything beyond the basic functionalities can be tagged and added in sailbsp_main
  /*NOTE:
   * locale-dependent functions are activated. This enables you to
   * use the atoi family, sprintf(), sscanf(), and the functions in ctype.h
   */
  if(NULL == setlocale( LC_ALL, "C" ) )
  {
      err_fatal(CLIB , ERR_FATAL_CLIB_INIT_FAILED);
  }
  sailbsp_main();
}

/*
 *===========================================================================
                               FUNCTIONS
 *===========================================================================*/



//Assuming Cluster#0 cores to be the boot core
BOOT_FUNC uint32_t  sailbsp_boot_cold_init(int cpu) {
	//LOG_INFO("Sail Hyp cold boot, version: {:s} ({:s})",sailbsp_version, sailbsp_build_date);
	//LOG_INFO("Sail Hyp cold boot on boot Core:%d", cpu );
	//Common Cold Boot routine to be placed in within this.Called only on the boot core.
	boot_cold_init(cpu);
	//Any per cpu cold boot routines to be places here. Called for all the cores.
	boot_cpu_cold_init(cpu);
	//LOG_INFO("boot_cpu_warm_init");
	boot_cpu_warm_init(cpu);

	boot_sail_main();
    while (1);
	//Should never reach here.
	return 0;
	//TODO Currently commented the below line since the linking is required for sailsw1 image.
    //	LOG_ERROR("sailbsp_boot_cold_init : Should never reach here on Core:%d", cpu);
}

BOOT_FUNC void sailbsp_boot_secondary_init(int cpu, int cluster_id) {
	//LOG_INFO("secondary cpu :%d cluster:%d cold boot", cpu,cluster_id);
	//Any per cpu cold boot routines to be places here. Called for all the cores.
  boot_cluster_init(cluster_id);
	boot_cpu_cold_init(cpu);
	//LOG_INFO("boot_cpu_warm_init");
	boot_cpu_warm_init(cpu);

	boot_sail_main();
	while(1);//TODO Remove this once support for bringing up secondary cores is in place.
}
// Warm (second or later) power-on of any CPU.
BOOT_FUNC void sailbsp_boot_warm_init(int cpu,int cluster_id) {
	//LOG_INFO("Cpu :%d cluster:%d warm boot", cpu,cluster_id);
	//LOG_INFO("boot_cpu_warm_init");
	boot_cpu_warm_init(cpu);

	while(1);//TODO Remove this once support for warm boot is in place.
}
