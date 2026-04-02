/**
 * @file sail_main.c
 * @brief
 * Source file for sail main function
 *
 *        Copyright (c) 2021 -2024 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

/*============================================================================
 * Include Files
 *============================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "chipinfo.h"
#include "busywait.h"
#include "gpio.h"
#include "isd.h"
#include <stdbool.h>
#include "types.h"
#include "errno.h"
#include "target.h"
#include "Clock.h"
#include "debug_log.h"
#include "sail_csr_hwio.h"
#include "logcode.h"
#include "err_fatal.h"
#include "HALhwio.h"
#include "sail_security_control_hwio.h"
#include "boot.h"
#include "i2c_el1.h"
#include "Spi.h"
//#include "Spi_PBcfg.h"
//#include "fusa.h"
#include "timetick.h"
//#include "wdt_safertos.h"
#include "uart.h"
#include "freertos_init.h"
#include "common_functions.h"
#include "sailel1_xbl_api.h"
#include "pwr_controller_el1.h"
#include "xbl_def.h"
#include "IPCC.h"
//#include "slavesoc_monitor.h"
//#include "mailboxInt_api.h"
#include "mailboxExt_api.h"
#include "libfdt.h"
#include "fdt_utils.h"

#include "icb_error.h"

//#include "pmu.h"
#include "sleepEl1.h"
#define CLUSTER1_ENABLED
#include "spinor_el1_api.h"
#ifndef UNIT_TEST_EL1_DISABLED
#include "tests.h"
#endif
//#include "sail_fs_api.h"
#include "syscall_pub.h"
#include "syscall_svc.h"
#include "syscall_hvc.h"
#include "uart.h"
//#include "adsp_chime.h"
#include "Can.h"
#include "CanTrcv_184_Tcan1044.h"
#include "CanTrcv_184_Tcan1146.h"
/*===========================================================================
                               MACROS
============================================================================*/ 
#define EL1MAIN_FUNC  __attribute__ ( ( section ( "el1main_func" ) ) )

/*============================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
============================================================================*/

/**
 * SAIL EL2 Cold Boot Flag
 */
bool  sailbsp_cold_boot_done = FALSE;

/* Define Image id to be dumped into SRAM for crashscope tool elf validation */
#if defined(lemans)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="SAIL_RTOS_LEMANSAU";
#elif defined (monaco)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="SAIL_RTOS_MONACOAU";
#else
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="";
#endif

/*

 *===========================================================================
 *						        Functions
 *===========================================================================
 */


/*===========================================================================
**  Function :  sailbsp_ipcc_init
** ==========================================================================
*/
/*!
*
* @brief
*   This initilizes IPCC driver for MPROC protocols
*
* @param
*   cpu_num   cpu_num the driver is being initilized on
* @par Dependencies
*   None
* @retval
*   None
* @par .
*
*/
EL1MAIN_FUNC static void sailbsp_ipcc_init(uint32_t cpu_num)
{
  /*Inititalize IPCC Protocols*/
  IPCC_InitEx(IPCC_P_SAIL_MPROC, cpu_num);
}
/*===========================================================================
**  Function :  sailbsp_set_cold_boot_done
** ==========================================================================
*/
/*!
*
* @brief
*   This sets the Cold Boot init done flag. This flag used during bringing up
*   secondary cores and during warm boot sequence.
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
* @par .
*
*/
EL1MAIN_FUNC void sailbsp_set_cold_boot_done(void)
{
  sailbsp_cold_boot_done = TRUE;
}

EL1MAIN_FUNC bool sailbsp_is_cold_boot_done(void)
{
  return sailbsp_cold_boot_done;
}
/*===========================================================================
**  Function :  main
** ==========================================================================
*/
/*!
*
* @brief
*   The Main performs performs early initialization
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   This function never returns.
*
*/
EL1MAIN_FUNC int sailbsp_main ()
{
  int retval;
  uint32_t hvcId = 0;
  uint32_t paramId = 0;
  uint32_t arg1 = 0;
  uint32_t arg2 = 0;
  uint32_t arg3 = 0;
  uint32_t arg4 = 0;
  uint32_t log_data = 0u;
  uint32_t cpu_num = get_curr_phys_cpu_num();
  uint64 warm_boot_status = in_dword(WARM_BOOT_STATUS);


  /* Image id variable used here,so that it is a part of safertos elf build to be used for crashscope tool elf validation */
 DEBUG_LOG(SAIL_INFO,"Image variant = %s\r\n",OEM_IMAGE_UUID_STRING_AUTO_UPDATED);

  retval = fdt_util_apply_overlay();
  if (0 != retval)
  {
      DEBUG_LOG(SAIL_INFO, "warning - fdt overlay failed and skipped\n\r");
  }

  vSleepInitEl1();
  if ( get_curr_phys_cpu_num() == 0){

    (log_data) = CORE0_EL1_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);

    vLCWriteTimeStamp( CORE0_EL1_STARTS ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
    DEBUG_LOG(SAIL_ERROR, "Entered EL1, Core:%u\n\r", cpu_num);
	


  }
  else if ( get_curr_phys_cpu_num() == 1){

    (log_data) = CORE1_EL1_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);

    vLCWriteTimeStamp( CORE1_EL1_STARTS ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

  }
  
  else if ( get_curr_phys_cpu_num() == 2){

    (log_data) = CORE2_EL1_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    vLCWriteTimeStamp( CORE2_EL1_STARTS ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }  
  else if ( get_curr_phys_cpu_num() == 3){

    (log_data) = CORE3_EL1_START;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    vLCWriteTimeStamp( CORE3_EL1_STARTS ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  
    if ( get_curr_phys_cpu_num() == 0){

     retval = sailEl1XblInit();
    if(XBL_SUCCESS != retval )
    {
      err_fatal(XBL ,retval);
    }
  
    /* Initialize PC EL1 */
    retval = xPCinitEL1();
    if (PC_STATUS_SUCCESS != retval)
    {
      err_fatal(PC ,retval);
    }
  }
  
  retval = xFreertosInitializeScheduler( cpu_num);
  if( pdPASS != retval )
  {
      DEBUG_LOG(SAIL_ERROR, "xfreertosInitializeScheduler() failed, Core:%u\n\r", cpu_num);
	  err_fatal(FREERTOS ,retval);
  }

  if ( get_curr_phys_cpu_num() == 0){
    retval = spinorEl1Init ( );
    if (retval != 0)
    {
	  err_fatal(SPINOR ,retval);
    }
 }

 if ( get_curr_phys_cpu_num() == 2){
    retval = spinorEl1Init ( );
    if (retval != 0)
    {
	  err_fatal(SPINOR ,retval);
    }
  }
 
  //gpio driver needs to be initialized early to reconfigure TLMM mux when MD is in EDL
  sail_gpio_init();
  
  busywait_init();
  sailbsp_ipcc_init(cpu_num);

  if ( get_curr_phys_cpu_num() == 0)
  {
     xUartInit(uartDEBUG_HW);
     /* this takes time to print memory buffer to UART console */
     #ifndef UNIT_TEST_EL1_DISABLED
        //vTestModuleInit ();
     #endif
  }

  vLogSetUartState(LOG_UART_WORKING);

  if ( get_curr_phys_cpu_num() == 2)
  {
     #ifdef SAILFS_INTERNAL_DRIVER_FLAG
     retval = nSAILFSInit();
     if(retval < 0)
     {
       DEBUG_LOG(SAIL_ERROR, "%s: error, SAILFSInit() failed, retval = %d\n\r", __func__, retval);
     }
    #endif  //  SAILFS_INTERNAL_DRIVER_FLAG
  }

  if ( get_curr_phys_cpu_num() == 2)
  {
    icb_el1_init();
  }
  
  if ( get_curr_phys_cpu_num() == 1)
 {
  /* Initialize the SPI driver*/
    Spi_Init(&Spi_Config);
    CanTrcv_184_Tcan1044_Init(NULL);
    CanTrcv_184_Tcan1146_Init(NULL);
    Can_Init(NULL);
 }

 #if 0 //TODO need to enable
  if( pdPASS != xFreertosChecker(cpu_num ) )
  {
      DEBUG_LOG(SAIL_ERROR, "xFreertosChecker() failed, Core:%u\n\r", cpu_num);
  }
 #endif

  /* End Driver API Inits */
  if( pdPASS != xFreertosTasksAndResourcesInit( ) )
  {
      DEBUG_LOG(SAIL_ERROR, "xFreertosTasksAndResourcesInit() failed, Core:%u\n\r", cpu_num);
  }
 
  if ( get_curr_phys_cpu_num() == 0){
  /* capture latest ISD event */
  /*In case of Rescue Image, dont call ISDUpdateEventStatus*/
  hvcId = SAIL_RESCUEIMG_HVC_ID;
  paramId = SAIL_RESCUEIMG_PARAM_ID;
    
  if( TRUE == xSyscallIsPrivilegedMode() )
  {
      if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
      {
          return pdFAIL;
      }
  }
  else
  {
      if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
      {
          return pdFAIL;
      }
  }
  if (paramId != 0xFFU)
  {
     vISDUpdatePendingEventStatus();
  }
}

  DEBUG_LOG(SAIL_WARNING,"FreeRTOS Initialized Successfully\r\n");

  if ( cpu_num == 0)
  {
    vLCWriteTimeStamp( CORE0_HLOS_KERNEL_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }

  else if ( cpu_num == 1)
  {
    vLCWriteTimeStamp( CORE1_HLOS_KERNEL_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  else if ( cpu_num == 2)
  {
    vLCWriteTimeStamp( CORE2_HLOS_KERNEL_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
  else if ( cpu_num == 3)
  {
    DEBUG_LOG(SAIL_WARNING, "CORE3 FreeRTOS Scheduler START \n\r");
  }
  /* Start SafeRTOS Kernel */
  xFreertosTaskStartScheduler(cpu_num);
  /* TODO: Will never return after starting the scheduler
   * Error Handling- SM_ERROR Assertion
   */
sailbsp_end:
  while(1);

  return 0;
}
