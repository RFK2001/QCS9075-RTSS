/**
 * @file boot_utils.c
 * @brief
 * Source file for Utilitu functions for Sail boot up routines
 *
 *        Copyright (c) 2021 - 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.23.22   rrahul       Created
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
#include "target.h"
#include "logcode.h"
#include "sail_csr_hwio.h"
#include "HALhwio.h"
#include "sail_security_control_hwio.h"
#include "err_fatal.h"
#include "hw_io.h"

#include "common_functions.h"
#include "test1_hwio.h"
#include "boot_utils_config.h"
#include "target.h"
#include "sailhyp_xbl_api.h"

#include "isd.h"
#include "debug_log.h"
#include "el2_mpu.h"
#include "sailheap.h"
#include "sailbsp_mutex.h"
#include "sleepEl2.h"
#include "pmicapi.h"

/*===========================================================================
                           MACROS
===========================================================================*/
/*
  0 : Core to TOP comparator enable
  1:  Core to Governor comparator enable
  2:  Core to RAM comparator enable
  3:  Core-Governor to TOP comparator enable
  4:  Core-Governor to CORE comparator enable
  5:  Activity check on core signals comparator enable
  6:  Activity check on debug signals comparator enable
  28: Global-Governor to TOP comparator enable
  30: Global-Governor to CORE comparator enable
*/
#define COMPARATOR_ENABLE_BITS 0x5000007F
#define MEM_PROFILER_ENABLE_BIT 0x00000040
#define SAIL_SW1_ENTRY          0x08200000

#define LOAD_ELF_RET_OK          0
#define LOAD_ELF_RET_ERR_OPEN    (-100)
#define LOAD_ELF_RET_ERR_SW1     (-101)
#define LOAD_ELF_RET_ERR_SW2     (-102)

#define SAILHEAP_SIZE_LARGE_BIN        (0x2800)   /* 10KB */
#define SAILHEAP_SIZE_SMALL_BIN        (0x1C00)   /* 7KB */

uint32_t smp_os_image_cfg = 0x0U;
uint32_t smp_os_core_cfg_image1 = 0x0U;
uint32_t smp_os_core_cfg_image2 = 0x0U;
uint32_t TimerKConfig = 0x0U;
extern volatile uint8_t smp_image1_cores_stop_flag;
extern volatile uint8_t smp_image2_cores_stop_flag;

static uint8_t ucSailHeapLargeBin[SAILHEAP_SIZE_LARGE_BIN] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE)));
static uint8_t ucSailHeapSmallBin[SAILHEAP_SIZE_SMALL_BIN] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE)));
static mutex_t xSailHeapMutexLBin;
static mutex_t xSailHeapMutexSBin;
static void vSailHeapInit(void)
{
    int slRet = 0;
    
    memset(ucSailHeapLargeBin, 0, sizeof(ucSailHeapLargeBin)); 
    slRet = sailheap_init(&xSailHeapMutexLBin, (void *)ucSailHeapLargeBin, sizeof(ucSailHeapLargeBin));
    if (slRet != 0)
    {
        err_fatal(EL_ENTRY, slRet);
    }
    
    memset(ucSailHeapSmallBin, 0, sizeof(ucSailHeapSmallBin));
    slRet = sailheap_init(&xSailHeapMutexSBin, (void *)ucSailHeapSmallBin, sizeof(ucSailHeapSmallBin));
    if (slRet != 0)
    {
        err_fatal(EL_ENTRY, slRet);
    }
}
/*===========================================================================
                               VARIABLES
============================================================================*/

/*===========================================================================
                               SYS CALL DECLARATION
============================================================================*/

/*===========================================================================
                               EXTERN
============================================================================*/

/*
 *===========================================================================
                               Helper FUNCTIONS
 *===========================================================================*/

void boot_trampoline(uint32_t sw1_reset_vector_addr,uint32_t sw1_vbar_addr){
     uint32_t val=0x7f81,mode=0x200001D3;
     uint32_t ulSLAVEPCTLR = 0U;
     uint32_t ulHCRval = 0;
     /*  PL0/1 SW timerKernel config */
     __asm__ volatile("mcr p15, 0, %0, c14, c1, 0" : : "r" (TimerKConfig));
	 //Set Boot Address and VBAR for EL1
	 __asm__ volatile (" msr elr_hyp, %0":  :"r" (sw1_reset_vector_addr));
     __arm_mcr(15, 0,sw1_vbar_addr, 12, 0, 0);   // Write to VBAR.
     // Configure HACTLR
     __arm_mcr(15, 4,val, 1, 0, 1); // Write Rt to HACTLR

     /* Disable TCM AXIS access */
     __arm_mcr(15, 0,ulSLAVEPCTLR, 11, 0, 0); // Write ulSLAVEPCTLR to IMP_SLAVEPCTLR

     /* Update HCR to route IRQS/Asyncs to EL1  */
     ulHCRval = __arm_mrc(15, 4, 1, 1, 0);   // Read HCR
     ulHCRval = ( ulHCRval & (~0x30) );
     __arm_mcr( 15, 4,ulHCRval, 1, 1, 0 ); // Write to HCR

     ulHCRval = __arm_mrc(15, 4, 12, 11, 0);   // Read ICH_HCR --> trap enable for common register
     ulHCRval = ( ulHCRval | (1 << 10U) );
     __arm_mcr( 15, 4,ulHCRval, 12, 11, 0 ); // Write to ICH_HCR
     
	 //Configure SPSR_hyp to set the mode to SVC
	 __asm__ volatile (" msr spsr_hyp, %0":  :"r" (mode));

     //------------------------------------------------------------
	 //Clear out all working registers (except x0)
	 //before jump to another exception level
	 //------------------------------------------------------------
	 //CLEAN_REGS_BEFORE_RETURN_TO_SVC
	 //mov    r0, #0x0 ; @ToDo --Also clear r0 until we have to provide something meaningful

     //------------------------------------------------------------
     //Jump to SVC mode
     //------------------------------------------------------------
	 __asm__ volatile("isb" ::: "memory");
	 __asm__ volatile("dsb sy" ::: "memory");
	 __asm__ volatile ("eret");
}

/*===========================================================================
                               FUNCTIONS
 *===========================================================================*/
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
void heap_init(void) {
    /*We are not providing "__rt_heap_extend" implementation. If the system runs of heap
     * we prefer to crash and know about the use case. Update the heap size as needed.
     * If at a later point it is decided that he  means of dynamic heap extension is required
     * then have a memory allocator in palce. Update "__rt_heap_extend" after using that allocator.
     */

    //Invoke the armlib _init_alloc function with the heap descriptors as arguments.
    //_init_alloc(SAILBSP_HEAP_BASE,SAILBSP_HEAP_END);
    vSailHeapInit();
}

/*The QUP MEM is not cleared and rest to 0 on power reset . this routine does the same
  by memsetting the region to 0x0 . Invoke this api as early as posbile before any one
  uses log apis*/
void qup_mem_init(void) {
    memset((void *)SAILBSP_QUP_MEM_START,0,SAILBSP_QUP_MEM_SIZE);
}
/*
*
* @brief
*   Load sailsw1 and sailsw2 elfs into RAM
*
* @param
*   NULL
* @par Dependencies
*   spinor EL2 driver
* @retval
*   XBL_SUCCESS or error
* @par Side Effects
*   None
*
*/
uint32_t boot_utils_load_elfs(uint32_t phys_core_id)
{
#ifndef SAILJTAGPROGRAMMER
  uint32_t ret;
  uint32_t image_count = 1;
  uint32_t image_id = boot_config_get_core_image_id(phys_core_id);
  xbl_boot_params_t boot_params[1] = {{.image_id = image_id, .boot_option = XBL_BOOT_OPTION_MANDATORY}};
  
  if (image_id >= BOOT_IMAGE_ID_MAX)
  {
	  DEBUG_LOG(SAIL_ERROR, "Board provision error(core 2 and 3 are not in DCLS). Invalid Imageid %d \r\n", image_id);
    if (phys_core_id == 3)
    {
      low_power();
    	while(1);
    }
	else{

		err_fatal(EL_ENTRY ,BOARD_PROVISION_ERROR);
	}
  }
  
  /* Check if the current core is included in SMP OS configuration and is not a master core */
  if( ( smp_os_core_cfg_image1 & (1U << phys_core_id) ) && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image1) != phys_core_id ) )
  {
	  uint32_t image_entry = 0U;
      uint32_t master_core = boot_util_smp_os_get_master_core(smp_os_core_cfg_image1);
       
	  image_entry = boot_config_get_image_entry ( master_core, master_core );
	  while(smp_image1_cores_stop_flag == 1U || image_entry == 0U)
	  {
		  image_entry = boot_config_get_image_entry ( master_core, master_core );
	  }
	  
	  DEBUG_LOG(SAIL_ERROR, "image_entry for core%d:%d \r\n", phys_core_id, image_entry);
	  boot_config_update_boot_image_info ( image_id, image_entry, BOOT_IMAGE_STATUS_SUCCESS );
	  return (uint32_t)XBL_SUCCESS;
  }
  else if( ( smp_os_core_cfg_image2 & (1U << phys_core_id) ) && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image2) != phys_core_id ) )
  {
	  uint32_t image_entry = 0U;
      uint32_t master_core = boot_util_smp_os_get_master_core(smp_os_core_cfg_image2);
	  
	  image_entry = boot_config_get_image_entry ( master_core, master_core );
	  while(smp_image1_cores_stop_flag == 1U || image_entry == 0U)
	  {
		  image_entry = boot_config_get_image_entry ( master_core, master_core );
	  }
	  
	  DEBUG_LOG(SAIL_ERROR, "image_entry for core%d:%d \r\n", phys_core_id, image_entry);
	  boot_config_update_boot_image_info ( image_id, image_entry, BOOT_IMAGE_STATUS_SUCCESS );
	  return (uint32_t)XBL_SUCCESS;
  }
  
  //TBD: We only boot SW1 now. Need to get direction when we need to boot SW2 and SW3
  ret = sailhyp_xbl_boot_elfs(boot_params, image_count);
  if (ret == XBL_SUCCESS)
  {
    uint32_t image_entry;
    if (XBL_SUCCESS == (ret = sailhyp_xbl_get_image_entry_point((eXblImageIdType) image_id, &image_entry)))
    {
      boot_config_update_boot_image_info ( image_id, image_entry, BOOT_IMAGE_STATUS_SUCCESS );
    }
    else
    {
      boot_config_update_boot_image_info ( image_id, 0, BOOT_IMAGE_STATUS_ERROR );
      goto done;
    }
  }
done:
  if (ret != XBL_SUCCESS)
  {
    //SAIL SW/2/3 Auth failure from both primary and backup partitions. 
    //Communicate MD to warm reset and enter EDL mode.
    eISD_InitiateEDLentryFrmSail(SOC_EDL, image_id);
    DEBUG_LOG(SAIL_ERROR, "Imageid %d load error\r\n", image_id);
    //SAIL has communicated to MD about SAIL EL1 Image auth/load failure from backup parition.
    //Upon receiving this failure info, MD will set "SAIL force EDL entry". 
    //Hence SAIL must be in a loop below, until MD pull MD_PS_HOLD low to warm reset MD followed by SAIL to enter EDL mode.
    //below loop is considered non-fatal and err_fatal() call is not necessary here, to avoid SAIL_PS_HOLD low, before MD receives SAIL EL1 Image auth failure info.
    while(1);
  }
  return ret;
#else
   return 0;
#endif
}
/*
*
* @brief
*   Exit EL2 and jump to this core's EL1 executable
*
* @param
*   NULL
* @par Dependencies
*   boot_utils_load_elfs
* @retval
*   NULL
* @par Side Effects
*   None
*
*/
void boot_utils_cpu_exit_el2 ( uint32_t phys_core_id)
{
#ifndef SAILJTAGPROGRAMMER
  boot_image_id_enum_type id;
  uint32_t image_entry = 0;
  int retval ;
  pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

  if(0u == phys_core_id)
  {
	eISDDeInit();
  }

  for ( id = 0; id < BOOT_IMAGE_ID_MAX; id++ )
  {
    image_entry = boot_config_get_image_entry ( id, phys_core_id );

    if ( image_entry > 0 )
    {
       retval = el2_mpu_update();
       if ( retval != 0) 
       {
         err_fatal(SECURITY_MPU ,retval);
       }


       boot_trampoline ( image_entry, image_entry );
    }
    else
    {
      continue;
    }
  }
  err_fatal(EL_ENTRY ,IMAGE_NOT_FOUND);

#endif
}

bool sailbsp_iscluster_lockstep(uint8 cluster_num)
{
	uint8 cluster_config = 0;
	bool is_lockstep = FALSE;

	cluster_config = REG_INF(SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE,
		SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO, CLUSTER_CONFIG_GPIO);

	switch(cluster_num)
	{
		case 0:
			if(cluster_config & 0x1)
			{
				is_lockstep = TRUE;
			}
			break;
		case 1:
		if(0x2 == (cluster_config & 0x2))
		{
			is_lockstep = TRUE;
		}
		break;
	}
	return is_lockstep;
}

void sailbsp_enable_comparator(void)
{

	uint8 cluster_config = 0;

	//check if cluster 0, core 0 or cluster 1 core 0
	if(get_curr_cpu_num() > 0)
      return; //not in lockstep

	//check if lockstep is enabled
	cluster_config = REG_INF(SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE,
	SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO, CLUSTER_CONFIG_GPIO);

	if ((0x1 == (cluster_config & 0x1)) && (0x0 == get_curr_cluster_num()))
	{
      REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER0_DCLS_COMP_EN, COMPARATOR_ENABLE_BITS );
	}
	else if((0x2 == (cluster_config & 0x2)) && (0x1 == get_curr_cluster_num()))
	{
      REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CLUSTER1_DCLS_COMP_EN, COMPARATOR_ENABLE_BITS );
	}
	else
	{
      //current cluster is in split mode
	}
	return;
}

void sailbsp_enable_mem_profiler(void)
{
	/* Enable the memory error profiler bit in the SAILSS_CSR_RTCU_CONTROL register */
	REG_OUT(SAILSS_CSR_SAILSS_CSR_REG_BASE, SAILSS_CSR_RTCU_CONTROL, MEM_PROFILER_ENABLE_BIT );

	return;
}

uint32_t boot_util_smp_os_get_master_core(uint32_t ulSmpOSImage_CoreCfg)
{
	uint32_t core_id = 0;
    uint32_t bit_mask = 1;
 
    while (!(ulSmpOSImage_CoreCfg & bit_mask)) {
 
        // left shift
        bit_mask = bit_mask << 1;
        core_id++;
    }
	
	return core_id;
}

void boot_util_frame_smp_os_core_cfg( void )
{
	if(smp_os_image_cfg == 0x1)
	{
		if(sailbsp_iscluster_lockstep(0))
		{
			smp_os_core_cfg_image1 |= 0x1;
		}
		else
		{
			smp_os_core_cfg_image1 |= 0x3;
		}
		
		if(sailbsp_iscluster_lockstep(1))
		{
			smp_os_core_cfg_image1 |= 0x4;
		}
		else
		{
			smp_os_core_cfg_image1 |= 0xC;
		}
	}
	else if(smp_os_image_cfg == 0x3)
	{
		if(sailbsp_iscluster_lockstep(0))
		{
			smp_os_core_cfg_image1 |= 0x1;
		}
		else
		{
			smp_os_core_cfg_image1 |= 0x3;
		}
		
		if(sailbsp_iscluster_lockstep(1))
		{
			smp_os_core_cfg_image2 |= 0x4;
		}
		else
		{
			smp_os_core_cfg_image2 |= 0xC;
		}
	}
}
