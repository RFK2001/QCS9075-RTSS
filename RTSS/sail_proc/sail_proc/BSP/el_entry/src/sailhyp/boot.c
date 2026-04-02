/**
 * @file boot.c
 * @brief
 * Source file for Sail boot up routines
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
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
#include "timetick.h"
#include "debug_log.h"
#include "target.h"
#include "IPCC.h"
#include "err_fatal.h"
#include "interrupts.h"
#include "logcode.h"
#include "sail_csr_hwio.h"
#include "HALhwio.h"
#include "sail_security_control_hwio.h"
#include "hw_io.h"
//#include "wdt.h"
#include "arm_acle.h"
#include "el2_mpu.h"
#include "Crashdbg_api.h"
#include "common_functions.h"
#include "uart.h"
#include "cache_ops.h"
#include "boot_utils_config.h"
#include "common_functions.h"
#include "boot_logger.h"
//#include "r52_diagnostics.h"
//#include "noc_diagnostics.h"
#include "sleepEl2.h"
#include "busywait.h"
#include "spinor_el2_api.h"
#include "sailhyp_xbl_api.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "i2c.h"
#include "bist.h"
#include "locale.h"
#include "g_SAIL_PWR_CTRL.h"
#include "chipinfo.h"
#include "isd.h" 
#include "libfdt.h"
#include "fdt_utils.h"
#include "AccessControlAPI.h"

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

#define R2_BOARD_VERSION        0x20000U
extern uint32_t icb_el2_init_core;

/*===========================================================================
                               VARIABLES
============================================================================*/
uint8 boot_cluster_init_state[SAILBSP_CLUSTER_COUNT] = {0};
extern volatile uint8 waitfor_loadELF_ready;
extern uint32_t is_el2_wdt_enabled;
uint32_t is_secondarycore_wfi_enabled = 0x0U;
uint32_t is_warminit_loadelf_enabled = 0x0U;
extern void icb_el2_noc_init(void);
static volatile uint8_t SAILPowerControllerControlBits = 0;
extern uint32_t smp_os_image_cfg;
extern uint32_t smp_os_core_cfg_image1;
extern uint32_t smp_os_core_cfg_image2;
volatile uint8_t smp_image1_cores_stop_flag = 1;
volatile uint8_t smp_image2_cores_stop_flag = 1;

/*===========================================================================
                               EXTERN
============================================================================*/
extern int  sailbsp_main (boot_pbl_shared_data_type* pbl_shared_info, boot_mode_type* bootmode);
extern int sailbsp_pass2(void);
extern void ipcc_gic_register_cpu(uint32_t cpu_id);
extern int sailbsp_warmInit (boot_pbl_shared_data_type* pbl_shared_info);
extern bool sailbsp_checkwarmboot(void);
/*===========================================================================
                               Helper FUNCTIONS
 *===========================================================================*/
static void boot_cluster_init(int cluster_idx) {
   //add assert statement that cluster_idx is <= SAILBSP_CLUSTER_COUNT
  if(cluster_idx >= SAILBSP_CLUSTER_COUNT)
    LOG_ERROR("boot_cluster_init : Cluster index is invalid %d", cluster_idx);
  if(boot_cluster_init_state[cluster_idx])
    return;

  // Enable this once GIC HW support prsent in RUMI
  arm_gic_params_init(cluster_idx);
  arm_gic_v3_init(cluster_idx);

  //Update cluster init state.We do this once for each cluster.
  boot_cluster_init_state[cluster_idx] = 1;

 }
static void boot_cold_init(int boot_cpu_idx) {
  //API#1-Commom Cold Boot routine to be placed in withing this.Called only on the boot core.
  heap_init();
  qup_mem_init();
  gic_pre_init_csr_programming();
  boot_cluster_init(0);
}

static void boot_cpu_cold_init(int cpu_index) {
  //API#2-Any per cpu cold boot touines to be places here. Called for all the cores.

  /*Inititalize IPCC Protocols*/
  IPCC_InitEx(IPCC_P_MPROC, cpu_index);
  IPCC_InitEx(IPCC_P_COMPUTEL0, cpu_index);
  IPCC_InitEx(IPCC_P_COMPUTEL1, cpu_index);
  IPCC_InitEx(IPCC_P_SAIL_MPROC, cpu_index);
}

static void boot_cpu_warm_init(int cpu) {
#ifndef SAILJTAGPROGRAMMER
  //API#3- Warm (second or later) power-on routines of any CPU.
  gic_init_percpu_early(cpu);
  uint32_t *err_fatal_codes = (uint32_t*)LOGCODE_ERR_FATAL_READ_DTB_ADDR;
  
  int retval = el2_mpu_init();
  if(err_fatal_codes[0] == SECURITY_MPU)
  {
    retval = err_fatal_codes[1];
  }
  if (retval!= 0) {
    err_fatal(SECURITY_MPU ,retval);
  }
#endif
}

boot_pbl_shared_data_type g_pbl_shared_info = {0};

static void boot_sail_main(boot_pbl_shared_data_type* pbl_shared_info, boot_mode_type* bootmode) {
  //API#4-Item#1 Anything beyond the basic functionalities can be tagged and added in sailbsp_main
  //At cold boot, SAIL RESET_CTRL FSM will be in IDLE state.
  /* Possible states PASS2 -  0xC: SP_PRE_DDR_INIT_ST, 0xD: SP_POST_DDR_INIT_ST,
                    0xE: DDR_SELF_RFRSH_CHK_ST and 0xF: ALLOW_PRE_ARES_PCIE_LINK_CHK_ST
  PASS2 entry state - 0xC:SP_PRE_DDR_INIT_ST */

  /*NOTE:
  * locale-dependent functions are activated. This enables you to
  * use the atoi family, sprintf(), sscanf(), and the functions in ctype.h
  */
  if(NULL == setlocale( LC_ALL, "C" ) )
  {
      err_fatal(CLIB , ERR_FATAL_CLIB_INIT_FAILED);
  }

  memcpy(&g_pbl_shared_info,pbl_shared_info,sizeof(boot_pbl_shared_data_type));

#ifndef SAILJTAGPROGRAMMER
  if (Crashdbg_GetSailResetCtrlFSMState() < SP_PRE_DDR_INIT_ST)
  {
#endif

    sailbsp_main(&g_pbl_shared_info, bootmode);
#ifndef SAILJTAGPROGRAMMER
  }
  else
  {
    sailbsp_pass2();
  }
#endif
}
/*===========================================================================
**  Function :  sailbsp_get_imageLoadToDDR_config
** ==========================================================================
*/
/*!
*
* @brief
*   Gets the sailbsp_get_imageLoadToDDR_config from device tree
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   uint32_t Selected config
* @par Side Effects
*   None
*
*/
uint32_t sailbsp_get_imageLoadToDDR_config(void) {
	int retval;
	uint32_t waitForDDR = 0; /*default*/
	void *pDTB = NULL;
	int32_t root_offset = 0;

	/* Get the DTB entries for imageLoadToDDR configuration */
	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/imageLoadToDDR");
		if(root_offset > 0)
		{
			retval = fdt_getprop_u32(pDTB, root_offset, "wait-for-DDR", &waitForDDR);

			/* If no errors in the DTB configuration, otherwise default config */
			if(0 == retval)
			{
			}
			else
			{
				 waitForDDR = 0; /*default*/
			}
		}
	}
	return waitForDDR;
}

static void sailbsp_imageLoadToDDR_wait(void) {
  if(sailbsp_get_imageLoadToDDR_config() == 1U)
  {
      /*check for DDR Status before proceeding with ELF load which could be from DDR*/
      while(1)
	  {
		if(S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS))
		{
          ;
		}
		else
		{
			el2_mpu_enable_ddr_region();
			DEBUG_LOG(SAIL_WARNING,"DDR READY BEFORE LOAD ELFS, S1_READY_SUCCESS \n\r");
			break;
		}
	  }
  }
}

/*===========================================================================
**  Function :  sailbsp_get_UARTloglevel_config
** ==========================================================================
*/
/*!
*
* @brief
*   Gets the desired UART log level from device tree
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sailbsp_get_UARTloglevel_config(void) {
	
	int retval_dtb = -1;
	uint32_t UARTloglevel = 0; /*default*/
	void *pDTB = NULL;
	int32_t root_offset = 0;

	/* Get the DTB entries for setUARTloglevel configuration */
	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/setUARTloglevel");
		if(root_offset > 0)
		{
			retval_dtb = fdt_getprop_u32(pDTB, root_offset, "newUARTloglevel", &UARTloglevel);

			/* If no errors in the DTB configuration, otherwise default config */
			if(0 == retval_dtb)
			{
				if((vLogGetLevel() ) != UARTloglevel){
					vLogSetLevel(UARTloglevel);
				}
			}
			else
			{
				 UARTloglevel = 2; /*default*/
			}
		}
	}
	
}
/*
 *===========================================================================
                               FUNCTIONS
 *===========================================================================*/
uint32_t  boot_cpu_get_loaded_image_id(uint32_t *image_id) {
    return boot_config_get_loaded_image_id(image_id);

}
//Assuming Cluster#0 cores to be the boot core
void  sailbsp_boot_cold_init(int cpu, boot_pbl_shared_data_type* pbl_shared_info) {

  uint64 startTime = 0;
  boot_mode_type bootmode= BOOT_MODE_UNKNOWN;
  uint32_t log_data;
  int retval = 0;
  
  uint32_t *err_fatal_codes = (uint32_t*)LOGCODE_ERR_FATAL_READ_DTB_ADDR;
  uint32_t phys_core_id = get_curr_phys_cpu_num();
  if (phys_core_id == 0)
  {
      vDebugLogInit();
  }
#ifndef SAILJTAGPROGRAMMER
  ErrFatal_Readdtb();
  sailbsp_get_UARTloglevel_config();
  vLCWriteTimeStamp( CORE0_EL2_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  /* DeInit UART Driver during crashdbg pass2 */
  if (IDLE_ST != Crashdbg_GetSailResetCtrlFSMState())
  {
    if(xUartDeInit(uartDEBUG_HW) != UART_SUCCESS)
    {
        //ToDO - Add log in DDR - "SAIL Crash Debug PASS2 - UART DeInit Failed");
    }
    /* This functions aligns UART log pointers before start of PASS2 logs */
    vLogUartLogBufferDeinit();
  }
#endif
  //Common Cold Boot routine to be placed in within this.Called only on the boot core.
  boot_cold_init(cpu);

#ifndef SAILJTAGPROGRAMMER
  /* Init cpu cold boot routines only at cold boot, but not during crashdbg pass2 */
  if (IDLE_ST == Crashdbg_GetSailResetCtrlFSMState())
  {
    vSleepInit();

    //Any per cpu cold boot routines to be places here. Called for all the cores.
    boot_cpu_cold_init(cpu);

    boot_cpu_warm_init(cpu);
	
    DEBUG_LOG_NOTIMESTAMP(SAIL_WARNING,"%s",(char*)(pbl_shared_info-> pbl_ts_buffer));
	
    startTime = uBootLogger_LogStartTime("SAIL EL2 entry on core", cpu);

    /* Perform R52 diagnostics */
#if 0	
    retval = r52_diagnostics();

    if(err_fatal_codes[0] == R52_DIAGNOSTIC)
    {
       retval = err_fatal_codes[1];
    }
    if (retval != 0)
    {
      err_fatal(R52_DIAGNOSTIC ,retval);
    }
    (log_data) = R52_DIAGNOSTICS;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data, 1);
#endif	
  /* Perform IPCC diagnostics */
  IPCC_Status_t returnVal;

  returnVal = IPCC_diagnostics();
  if(err_fatal_codes[0] == IPCC_DIAGNOSTICS)
  {
  	returnVal = err_fatal_codes[1];
  }
  
  if (IPCC_EOK != returnVal)
  {
    err_fatal(IPCC_DIAGNOSTICS ,returnVal);

  }

  DEBUG_LOG( SAIL_ERROR, "SAIL BSP EL2 : IPCC Diagnostics passed from core %d  \n\r", cpu);
  }
#endif

  boot_sail_main(pbl_shared_info, &bootmode);
#ifndef SAILJTAGPROGRAMMER
  vLCWriteTimeStamp( CORE0_EL1_LOAD_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

  sailbsp_imageLoadToDDR_wait();

  boot_utils_load_elfs(phys_core_id);
  
  /* Signal to other SMP cores to unblock as image has already been loaded */
  if( ( ( smp_os_image_cfg & 0x1 ) != 0U ) && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image1) == phys_core_id ) )
  {
	  smp_image1_cores_stop_flag = 0;
  }

  if( ( ( smp_os_image_cfg & 0x2 ) != 0U ) && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image2) == phys_core_id ) )
  {
	  smp_image2_cores_stop_flag = 0;
  }
  
  if(err_fatal_codes[0] == EL_ENTRY)
  {
	 err_fatal(EL_ENTRY ,err_fatal_codes[1]);
  }
  (log_data) = CORE0_EL1_LOAD;
  vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data, 1);

  vLCWriteTimeStamp( CORE0_EL1_LOAD_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  
  vBootLogger_LogDeltaTime(startTime, "SAIL EL2 Exit on core", cpu);

  vLCWriteTimeStamp( CORE0_EL2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

  boot_utils_cpu_exit_el2(phys_core_id);
  
#endif

  //Should never reach here.
  LOG_ERROR("sailbsp_boot_cold_init : Should never reach here on Core:%d", cpu);
}

void sailbsp_boot_secondary_init(int cpu, int cluster_id) {
  uint64 startTime = 0;
  int retval = 0;
  uint32_t phys_core_id = get_curr_phys_cpu_num();
  uint32_t log_data;
  
  uint32_t *err_fatal_codes = (uint32_t*)LOGCODE_ERR_FATAL_READ_DTB_ADDR;
  
  sailbsp_get_UARTloglevel_config();
#ifndef SAILJTAGPROGRAMMER
  
  if ( phys_core_id == 1)
  {
    
    (log_data) = CORE1_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    vLCWriteTimeStamp( CORE1_EL2_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  else if ( phys_core_id == 2){

    (log_data) = CORE2_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    vLCWriteTimeStamp( CORE2_EL2_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }else if ( phys_core_id == 3){
    (log_data) = CORE3_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    vLCWriteTimeStamp( CORE3_EL2_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  startTime = uBootLogger_LogStartTime("SAIL EL2 entry on core", cpu);
  //Any per cpu cold boot routines to be places here. Called for all the cores.
  boot_cluster_init(cluster_id);
  boot_cpu_cold_init(cpu);
  //LOG_INFO("boot_cpu_warm_init");
  boot_cpu_warm_init(cpu);
 #if 0
  /* Perform R52 diagnostics */
  retval = r52_diagnostics();
  
  if(err_fatal_codes[0] == R52_DIAGNOSTIC)
  {
    retval = err_fatal_codes[1];
  }
  if (retval != 0)
  {
    err_fatal(R52_DIAGNOSTIC ,retval );
  }
 
  if(phys_core_id == 2)
  {
      retval = NOC_tests_ASIL_D();
      if(retval != 0)
      {
          err_fatal(NOC_DIAGNOSTIC ,retval);
      }
      
      retval = NOC_tests_ASIL_B();
      if(retval != 0)
      {
          err_fatal(NOC_DIAGNOSTIC ,retval);
      }
  }
  #endif

  /* Perform IPCC diagnostics */
  IPCC_Status_t returnVal;
  returnVal = IPCC_diagnostics();
  
  if(err_fatal_codes[0] == IPCC_DIAGNOSTICS)
  {
  	returnVal = err_fatal_codes[1];
  }

  if (IPCC_EOK != returnVal)
  {
    err_fatal(IPCC_DIAGNOSTICS ,returnVal);

  }
  DEBUG_LOG( SAIL_ERROR, "SAIL BSP EL2 : IPCC Diagnostics passed from core %d  \n\r", cpu);


 /* wdt_init_el2();    EL2 test for all core*/
/*  wdt_disable(); */
  vISDInitSMP();

  // For FreeRTOS we need to put the secondary cores in WFI (This is needed for STR functionality)
  if(is_secondarycore_wfi_enabled == 0x1u)
  {
    low_power();
  }
  
 #if 0 
 //Updating the status for the starting of cores
 /* If BIST is not skipped */
  if (bootcfg_el2_getMDBIST_core() != 0xFFU){
    /* If we are running from the BIST core */
    if (bootcfg_el2_getMDBIST_core() == phys_core_id)
    {
          if(is_el2_wdt_enabled == 0x1U)
          {
            wdt_init_el2(); // Watchdog initialized in core 1 or 2

          }
          //MD_BOOT_CHECK  will get set if any MD boot up failure happens,so
          //MDBIST  will be skipped incase of MD boot up failure
          if(MD_OK == in_dword(MD_BOOT_CHECK))
          {
            vLCWriteTimeStamp( BIST_PH1_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ));
            retval = slRunMDBIST();
            if (E_SUCCESS != retval)
            {
              if(TRUE == sailbsp_checkmdedl())
              {
                /*Use case - MD XBL Image loading failure - EDL entry.
                  When MD PBL detects MD XBL Image loading failure from current BOOT_LUN,
                  MD will enter EDL. MD EDL communication to SAIL is delayed.
                  In parallel, SAIL core1 started performing MD BIST, at early EL2 boot.
                  But SAIL core 0 detects MD EDL, in its EL2 boot sequence and open up SPINOR access for EDL. 
                  Eventually, core1- MD BIST timeout and calls error fatal to reset SAIL, which has an impact on EDL USB enumeration */
                DEBUG_LOG(SAIL_ERROR,"MD BIST failed due to MD in EDL \n\r");	
                /* To avoid loss of EDL USB enumeration, if MD BIST fails due to MD in EDL,
                  Skip error fatal call, disable wdog on core1 and stay in tight loop until SOC hard resets after EDL flashing completion */
                /* NOTE - This workaround is needed mainly to avoid SAIL reset due to MD stays in PBL for EDL and PH2 BIST timeout,
                  as MD_PBL flow does PH1 BIST first, then detects XBL image loading failure and enter EDL */
                wdt_disable_el2();
                while(1); //loop waiting for EDL flashing completion.
              }
              else
              {
                /* MD BIST failure for other reasons */				
                err_fatal(BIST ,retval);
              }
            } 
            vLCWriteTimeStamp( BIST_PH2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
          }
    }
  }
  
  /* ASILB_ISO_NOC_XPU Configuration and  Enable MSA Interrupts to SAIL in HYP/EL2 once MD BIST is completed */
  if (bootcfg_el2_getMDBIST_core() == phys_core_id)
  {
	retval = ACInitPostBIST();
	if(retval != E_SUCCESS)
	{
		DEBUG_LOG(SAIL_ERROR,"[SAIL AC] AC Config POST BIST Failure");
		err_fatal(SECURITY_AC ,retval);
	}
  }
 #endif 
  //Updating the status for loading the el1 images
  if ( phys_core_id == 1)
  {
     while(waitfor_loadELF_ready == 0){
      invalidate_dcache_by_addr((uint32)&waitfor_loadELF_ready);
      // core 1 would continue to load its ELF after waitfor_loadELF_ready is set
     }
     vLCWriteTimeStamp( CORE1_EL1_LOAD_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  else if ( phys_core_id == 2)
  {
    while(waitfor_loadELF_ready == 0){
      invalidate_dcache_by_addr((uint32)&waitfor_loadELF_ready);
      // core 2 would continue to load its ELF after waitfor_loadELF_ready is set
    }
    if(icb_el2_init_core == 0x2U)
    {
      icb_el2_noc_init();
    }
    vLCWriteTimeStamp( CORE2_EL1_LOAD_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }else if ( phys_core_id == 3)
  {
      while(waitfor_loadELF_ready == 0){
      invalidate_dcache_by_addr((uint32)&waitfor_loadELF_ready);
      // core 3 would continue to load its ELF after waitfor_loadELF_ready is set
      }
      vLCWriteTimeStamp( CORE3_EL1_LOAD_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }

  sailbsp_imageLoadToDDR_wait();

  boot_utils_load_elfs(phys_core_id);
  if(err_fatal_codes[0] == EL_ENTRY)
  {
	 err_fatal(EL_ENTRY ,err_fatal_codes[1]);
  }
  
  /* Signal to other SMP cores to unblock as image has already been loaded */
  if( ( smp_os_image_cfg & 0x1 ) != 0U && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image1) == phys_core_id ) )
  {
	  smp_image1_cores_stop_flag = 0;
  }

  if( ( smp_os_image_cfg & 0x2 ) != 0U && ( boot_util_smp_os_get_master_core(smp_os_core_cfg_image2) == phys_core_id ) )
  {
	  smp_image2_cores_stop_flag = 0;
  }
  
  if ( phys_core_id == 1)
  {
    (log_data) = CORE1_EL1_LOAD;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data, 1);
    vLCWriteTimeStamp( CORE1_EL1_LOAD_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
   }
  else if ( phys_core_id == 2)
  {
     (log_data) = CORE2_EL1_LOAD;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data, 1);
    vLCWriteTimeStamp( CORE2_EL1_LOAD_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }else  if ( phys_core_id == 3)
  {
    (log_data) = CORE3_EL1_LOAD;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data, 1);
    vLCWriteTimeStamp( CORE3_EL1_LOAD_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }

  vBootLogger_LogDeltaTime(startTime, "SAIL EL2 Exit on core", cpu);

  if ( phys_core_id == 1)
  {
    vLCWriteTimeStamp( CORE1_EL2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  else if ( phys_core_id == 2)
  {
    vLCWriteTimeStamp( CORE2_EL2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }else if ( phys_core_id == 3)
  {
    vLCWriteTimeStamp( CORE3_EL2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  boot_utils_cpu_exit_el2(phys_core_id);
#endif


  while(1);//TODO Remove this once support for bringing up secondary cores is in place.
}
// Warm (second or later) power-on of any CPU.

void sailbsp_boot_warm_init(int cpu,int cluster_id) {
#ifndef SAILJTAGPROGRAMMER

  uint32_t phys_core_id = get_curr_phys_cpu_num();

  // For Autosar we need to put the secondary cores in WFI (This is needed for STR functionality)
  if ( 0x0 != phys_core_id )
  {
    if(is_secondarycore_wfi_enabled == 0x1u)
    {
      low_power();
    }
  }

  //LOG_INFO("Cpu :%d cluster:%d warm boot", cpu,cluster_id);
  //LOG_INFO("boot_cpu_warm_init");

  if ( cpu ==0 )
  {
    SAILPowerControllerControlBits = (REG_IN(SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE,SAILSS_PWR_CTRL_PWR_CTRL_CONTROL)&0x1U);
  }
  if(SAILPowerControllerControlBits==0x1U)
  {
	    // sleep exit path
    if ( 0x0 == phys_core_id )
    {
      if ( SLEEP_ERR_FLAG_SUCCESS != xSleepEl2Exit()) // Sleep Restore is needed for Core0 Only
      {
        while(1);
      }
      *(volatile uint32*) WARM_BOOT_STATUS = DEVICE_IS_IN_WARM_BOOT; // Setting warm boot status in register 
    }

    boot_cpu_warm_init(cpu); // Warm Init is needed for all the core

    if ( 0x0 == phys_core_id )
    {
      sailbsp_warmInit(&g_pbl_shared_info);
    }

    
    SAILPowerControllerControlBits = 0u;

  }else{
	  // core reset path
    el2_mpu_mark_deinit();
    boot_cpu_warm_init(cpu); // Warm Init is needed for all the core
    
    if ( 0x0 == phys_core_id )
    {
      // clearing DEBUGLOG_UART_READYSTATE_ADDR
      memset((void*)DEBUGLOG_UART_READYSTATE_ADDR, 0, 0x1);
    }

  }

  /*Load the elf then jump to EL1*/

  if(is_warminit_loadelf_enabled == 0x1u)
  {
    boot_utils_load_elfs(phys_core_id);
  }

  boot_utils_cpu_exit_el2(phys_core_id);
#endif
}
