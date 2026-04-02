/**
 * @file el2_asm.h
 * @brief EL2 Hypervisor definitions
 * Header file for the definition of hypervisor register info used in sail
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

#ifndef TARGET_H
#define TARGET_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <types.h>
#include "target_linker_map.h"

/*===========================================================================
                           TYPEDEFS
===========================================================================*/
typedef struct _physical_memory_layout{
	uint32_t memory_addr_start;
	uint32_t memory_addr_end;
	uint32_t memory_size;
}physical_memory_layout;




/*===========================================================================
                            MACROS
===========================================================================*/
//#define SAILBSP_MEMORY_SIZE        0x100000

#ifdef XBL_USE_WHITELIST
#define SAILBSP_ENTRY_ADDR(image_id)         image_sram_memory[image_id].memory_addr_start /* SAIL Entry point. */
#define SAILBSP_END_ADDR(image_id)           image_sram_memory[image_id].memory_addr_end
#define SAILBSP_MEMORY_SIZE(image_id)        image_sram_memory[image_id].memory_size
#endif

#define SYS_MODE_STACK_SIZE                 2048U
#define IRQ_MODE_STACK_SIZE                 1024U
#define SVC_MODE_STACK_SIZE                 4096U
#define ABT_MODE_STACK_SIZE                 1024U


#define SAILBSP_CPU_COUNT           0x4
#define SAILBSP_CLUSTER_COUNT       0x2
#define SAILBSP_CPUS_PER_CLUSTER    0x2
#define SAILBSP_CLUSTER_SIZE_SHFT   0x1
#define SAILBSP_CLUSTER_FIELD_MASK  0x1
#define SAILBSP_CPU_SIZE_SHFT       0x1
#define SAILBSP_CPU_FIELD_MASK      0x1

//#define SAILBSP_NUM_DDR_REGIONS     4

#define SAILBSP_MPIDR_CLUSTER_MASK  0xFF00
#define SAILBSP_MPIDR_CLUSTER_SHFT  8
#define SAILBSP_MPIDR_CPU_MASK      0xFF
#define SAILBSP_MPIDR_CPU_SHFT      0


/* How many bits to Consider for masking in order to get the core# from MPIDR
 * register value Check MPIDR registers for 2 aux cores to determine this
 * Usually affinity0 or affinity 1 */
#define MPIDR_TO_CPU_NUM_BITS  16

/* How many bits to shift in order to get the core# from MPIDR register value
 * Check MPIDR registers for 2 aux cores to determine this */
#define MPIDR_TO_CPU_NUM_SHIFT  8

/* How many bits to shift to get the cluster number from MPIDR register */
#define MPIDR_TO_CLUSTER_NUM_SHIFT  8

#define WITH_SMP 1

/* For OSPI Control */
#define OCTAL_SPI_CS_0       67
#define OCTAL_SPI_DQS        68
#define OCTAL_SPI_WR_N       69
#define OCTAL_SPI_CLK        70
#define OCTAL_SPI_DATA_0     71
#define OCTAL_SPI_DATA_1     72
/*===========================================================================
                            VARIABLES
===========================================================================*/

#ifdef XBL_USE_WHITELIST
static physical_memory_layout image_sram_memory[SAILBSP_CPU_COUNT]=
										{	{MANDATORY_SW1_LR1_START,(MANDATORY_SW1_LR1_START+MANDATORY_SW1_LR1_SIZE),MANDATORY_SW1_LR1_SIZE},
											{MANDATORY_SW2_LR1_START,(MANDATORY_SW2_LR1_START+MANDATORY_SW2_LR1_SIZE),MANDATORY_SW2_LR1_SIZE},
											{MANDATORY_SW3_LR1_START,(MANDATORY_SW3_LR1_START+MANDATORY_SW3_LR1_SIZE),MANDATORY_SW3_LR1_SIZE},
											{0,0,0},
										};
#endif
#endif  
