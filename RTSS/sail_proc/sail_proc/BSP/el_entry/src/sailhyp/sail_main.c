/**
 * @file sail_main.c
 * @brief
 * Source file for sail main function
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
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
#include "timetick.h"
#include "errno.h"
#include "target.h"
#include "err_fatal.h"
#include "Clock.h"
#include "debug_log.h"
#include "sail_csr_hwio.h"
#include "HALhwio.h"
#include "logcode.h"
#include "sail_security_control_hwio.h"
#include "boot.h"
/*#include "can.h" CANSS init is disabled to reduce EL2 size */
#include "i2c.h"
#include "AccessControlAPI.h"
#include "hwkm_err.h"
#include "hwkm_initialize.h"
#include "el2_mpu.h"
//#include "wdt.h"
#include "uart.h"
//#include "tsens_boot_api.h"
#include "el2_mpu.h"
#include "boot_utils_config.h"

#if __has_include("ts_el2.h")
#include "ts_el2.h"
#endif

#include "spinor_el2_api.h"
#include "sailhyp_xbl_api.h"
#include "sail_updater_el2.h"
#include "pmicapi.h"
#include "pwr_controller_el2.h"
#include "sail_asild_noc_service_network.h"
#include "prng_fips_hybrid_entry.h"
#include "bist.h"
#include "libfdt.h"
#include "fdt_utils.h"
#include "Crashdbg_api.h"
#include "boot_logger.h"
#include "version.h"
#include "sleepEl2.h"
#include "g_SAIL_TO_MD_SECURITY_CONTROL_CORE_HWIO.h"
#include "common_functions.h"
#include "uclib_env.h"
#include "secure_storage_common_pub.h"
#include "secure_storage_el2_pub.h"
#define CLUSTER1_ENABLED
//#define TEST_SRC_ENABLED
#ifndef UNIT_TEST_EL2_DISABLED
//#include "tests.h"
#endif
#include "syscall.h"
#include "syscall_pub.h"
#ifdef NORPVL_ENB
#include "pvl_api.h"
#endif
#include "mailboxExt_api.h"
#ifdef lemans
  #include "sail_tcsr_hwio_8650.h"
#endif

#if defined (SAIL_CASAR)
#include "sail_cdt.h"
#endif

/* MD_PS_HOLD_MASK Status Register
*/
#define SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK       0xF1149420
#define POR_FSM_STATE_MASK_VAL                        0xFFFF
#define SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL             0xCFF8
#define MD_IN_EDL 0xFE111111U

//Boot success command code
//MD PBL boot
#define MD_PBL_COMMAND_CODE                           0xFE
//MD XBL to ABL boot
#define BOOT_SUCCESS_COMMAND_CODE                     0xCB
//MD s1 map and mailbox ready
#define MD_MBRDY_COMMAND_CODE                         0xD0

#define WAIT_100_MS                                   0x64
#define SAIL2MD_OSPI_MD_ACCESS_READY \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAA); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x08); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x0); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x0);

#define SAIL2MD_SAIL_ENTER_FASTBOOT \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAA); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x0A); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x0); \
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x0);

char QC_IMAGE_VERSION_STRING_AUTO_UPDATED [64]; //crm 

/* Define Image id to be dumped into SRAM for crashscope tool elf validation */
#if defined(SAIL_RTOS) || defined(NORPVL_ENB)
#if defined (lemans)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="SAIL_RTOS_LEMANSAU";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] = "SAIL_RTOS_LEMANSAU";
#elif defined (monaco)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="SAIL_RTOS_MONACOAU";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] = "SAIL_RTOS_MONACOAU";
#else
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] ="";
#endif
#elif defined(SAIL_CASAR)
#if defined (lemans)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]= "SAIL_CASAR_LEMANSAU";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] = "SAIL_CASAR_LEMANSAU";
#elif defined (monaco)
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="SAIL_CASAR_MONACOAU";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] = "SAIL_CASAR_MONACOAU";
#else
char OEM_IMAGE_UUID_STRING_AUTO_UPDATED[]="";
char IMAGE_VARIANT_STRING_AUTO_UPDATED[] ="";
#endif
#endif

/*===========================================================================
                               VARIABLES
============================================================================*/

uint8_t bootcfg_MDBIST_core = 0x0U;
static uint32_t BootPrimaryCoreOnly = 0x0U;
volatile uint8 waitfor_loadELF_ready = 0x0U; 
uint32_t is_initSMP_enabled = 0x0U;
uint32_t is_el2_wdt_enabled = 0x0U;
extern void icb_el2_noc_init(void);
uint32_t icb_el2_init_core = 0x0U;
/*============================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
============================================================================*/

/**
 * SAIL EL2 Cold Boot Flag
 */
bool  sailbsp_cold_boot_done = FALSE;

/*
 *===========================================================================
 *						        Functions
 *===========================================================================
 */
bool sailbsp_readClusterLockStepConfig(uint8_t cluster_num);
bool el_entry_read_dts(void);
void icb_early_noc_config(void);
/**
 * Called when stack protection fails, detecting a corrupt stack
 */
/*
void __stack_chk_fail(void) __attribute__ ((alias("sailbsp_stack_chk_fail")));
void sailbsp_stack_chk_fail(void)
{
  LOG_ERROR(ERR_FATAL_SAIL_STACK_CHK_FAILED);
}
*/


/* @ToDo tie this with WDOG and Download mode
 * This API is called when an error occured during pre mmu cold init
 * Log the error in tz image, sets dload cookie and trigger WDB
 */

/*
void sailbsp_cold_boot_assert(uint32_t err)
{
  #define COLD_BOOT_WDT_DELAY_MS 1000
  LOG_ERROR(err);
  sailbsp_dload_mode_set();
  sailbsp_wdt_set_timeout(COLD_BOOT_WDT_DELAY_MS * 2, COLD_BOOT_WDT_DELAY_MS);
}
*/

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
void sailbsp_set_cold_boot_done(void)
{
  sailbsp_cold_boot_done = TRUE;
}

bool sailbsp_is_cold_boot_done(void)
{
  return sailbsp_cold_boot_done;
}

/*===========================================================================
**  Function :  sailbsp_initsmp
** ==========================================================================
*/
/*!
*
* @brief
*   This function brings secondary cores out of reset
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
static void sailbsp_initsmp(void)
{
	uint32_t log_data = 0u;
  // it will not bring secondary cores out of reset, when initSMP_enable in sailhyp dts is set to be zero.
  if(is_initSMP_enabled == 0x0U)
  {
    return;
  }
    //skip core 1 if lockstep is enabled for cluster 0
    if(!sailbsp_readClusterLockStepConfig(0))
    {
      //Program Configuration control for Cluster-0 Core-1
      HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGHALT, 0x0);
      HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGENDIANESS, 0x0);
      HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGTHUMBEXCEPTIONS, 0x0);
      HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGL1CACHEINVDIS, 0x0);
      HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, CFGTCMBOOT, 0x0);
      //CFGVECTABLE gets latched at reset de-assertion of CPU into both registers RVBAR and HVBAR.
      //HVBAR/RVBAR bits 31:5
      HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER0_CPU1_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
      //De-Assert Core level resets for core 1
      (log_data) = CORE1_RELEASE;
      vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
      Clock_DeassertCoreReset(1);
    }


#ifdef CLUSTER1_ENABLED
  //Program Configuration control for Cluster-1
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CONFIG0, CFGMPIDRAFF1, 0x1);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CONFIG0, CFGMPIDRAFF2, 0x0);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CONFIG0, CFGINITREG, 0x1);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CONFIG0, CFGRAMPROTEN, 0x1);

  //Program Configuration control for Cluster-1 CPU-0
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGHALT, 0x0);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGENDIANESS, 0x0);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGTHUMBEXCEPTIONS, 0x0);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGL1CACHEINVDIS, 0x0);
  HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, CFGTCMBOOT, 0x0);
  //CFGVECTABLE gets latched at reset de-assertion of CPU into both registers RVBAR and HVBAR.
  //HVBAR/RVBAR bits 31:5
  HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER1_CPU0_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));

  //Enable Cluster Clock and De-Assert Cluster level resets for cluster 1
  busywait(100);
  Clock_DeassertClusterReset(1);

  //De-Assert Core level resets for core 2
  (log_data) = CORE2_RELEASE;
   vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
   
  busywait(100);
  Clock_DeassertCoreReset(2);
  
  if(!sailbsp_readClusterLockStepConfig(1))
  {
    //Program Configuration control for Cluster-1 CPU-1
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGHALT, 0x0);
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGENDIANESS, 0x0);
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGTHUMBEXCEPTIONS, 0x0);
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGL1CACHEINVDIS, 0x0);
    HWIO_OUTF(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, CFGTCMBOOT, 0x0);
    //CFGVECTABLE gets latched at reset de-assertion of CPU into both registers RVBAR and HVBAR.
    //HVBAR/RVBAR bits 31:5
    HWIO_OUT(SAILSS_CSR_RTCU_CLUSTER1_CPU1_CONFIG0, (SAILBSP_ENTRY_BASE >> 5));
    
    //De-Assert Core level resets for core 3
    (log_data) = CORE3_RELEASE;
    vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
    busywait(100);
    Clock_DeassertCoreReset(3);
  }
#endif
  return;
}

/*===========================================================================
**  Function :  sailbsp_readClusterConfig
** ==========================================================================
*/
/*!
*
* @brief
*   This function checks the cluster configuration
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
bool sailbsp_readClusterLockStepConfig(uint8_t cluster_num)
{
  if(cluster_num ==0 )
  {
    if(0x1 != (HWIO_INF(SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO,CLUSTER_CONFIG_GPIO) & 0x1))
    {
      return FALSE;
    }
    return TRUE;
  }
  else
  {
    if(0x2 != (HWIO_INF(SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO,CLUSTER_CONFIG_GPIO) & 0x2))
    {
      return FALSE;
    }
    return TRUE;
  }
}

/*===========================================================================
**  Function :  sailbsp_checkwarmboot
** ==========================================================================
*/
/*!
*
* @brief
*   This function checks whether the current SAIL boot is a warm boot or not.
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   TRUE - current boot is warm boot after PMIC warm reset to SAILSS.
*   FALSE - Not a warm boot.
*
*/
bool sailbsp_checkwarmboot( void )
{
  bool ret = FALSE;
  
  /* Temporary solution to use MD TCSR i.e MD PH1 BIST status TCSR, 
   which will be retained after warm reset of SAILSS and MD. Use cases - a)EDL entry, b)MD XBL crash */
  //ToDO - To use SAIL spare CSR's that can be retained after PMIC(Dependent or Independent) warm reset to SAILSS.

  //MD_BOOT_CHECK  will get set if any MD boot up failure happens,as below is  MD register read,so
  //the part of code will be skipped incase of MD boot up failure
  if(MD_OK == in_dword(MD_BOOT_CHECK))
  {
    if( HWIO_IN(SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG) == 0xFu )
    {
      /* SAIL_TO_MD_TCSR_SAIL2MAIN_MD_PH1_BIST_STATUS_REG: 
              bit 3 ->SAIL2MAIN_MD_PH1_BIST_PWR_ON_LBIST_PASS -> 1: pon_lbist_pass
              bit 2 ->SAIL2MAIN_MD_PH1_BIST_PWR_ON_MBIST_PASS -> 1: pon_mbist_pass	
              bit 1 ->SAIL2MAIN_MD_PH1_BIST_PWR_ON_LBIST_COMPLETE -> 1: pon_lbist_complete	
              bit 0 ->SAIL2MAIN_MD_PH1_BIST_PWR_ON_MBIST_COMPLETE -> 1: pon_mbist_complete				
      */
      ret = TRUE;  
      DEBUG_LOG(SAIL_INFO,"Skip MD BIST in warm boot \n\r");
    }
  }
  return(ret);
}

/*===========================================================================
**  Function :  sailbsp_waitfor_MDReady
** ==========================================================================
*/
/*!
*
* @brief
*   This function block till MD PS Hold Assert, means comes out of reset
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   TRUE - MD Access ready
*   FALSE - MD in EDL mode
*
*/
static bool sailbsp_waitfor_MDReady( void )
{
  /*there is a possibility in IVI with reduced BIST where
  * XBL_SEC would already complete by this time and update the
  * shadow register with command 0xCB
  */
  uint32_t MD_counter = 0;
  
	*(volatile uint32*) MD_BOOT_CHECK = 0;
   if(BOOT_SUCCESS_COMMAND_CODE == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG))
  {
    //MD access is ready at this point
    return MD_OK;
  }

  /* Wait for MD PS HOLD assertion to de-isolate SAIL and 
  shadow register value update from MD PBL or other boot stages.
  NOTE: During sys.up on SAIL, both SAIL and MD will go through reset via SRST signal from JTAG.
  SAIL will halt at reset vector but MD will continue to boot beyond PBL stage.
  1. When MD is in XBL loader stage(when we run "go" in SAIL JTAG"),
   a)status3_reg will be cleared, to pass any error code, just in case of any XBL crash/EDL request.
   b)status7_reg will have valid value of boot success/ddr ready OR  XBL crash/EDL request.
  2. When MD is in TZ or beyond(when we run "go" in SAIL JTAG"),
   a)status3_reg will stay cleared, to pass any error code, just in case of any crash in TZ or beyond.
   b)status7_reg will have valid value of boot success/MD mailbox ready OR  TZ crash/HLOS boot failure.
  Hence, checking non-zero value of both status3 and status7 shadow register is required */

  //Timeout implementation to avoid infinite looping incase of MD failure
  
  while( (0u == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG)) &&
         (0u == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG))
       )
  {	  
	  if(MD_counter >= WAIT_100_MS)
	  {
		  *(volatile uint32*) MD_BOOT_CHECK = 1;
		  return MD_NOT_OK;
	  }
    MD_counter++;
    busywait(1000);
  }

  //check if MD PBL allowed SAIL Access to MD or went to MD2SAIL_MD_EDL_ENTRY mode
  if(0xFE == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG) &&
     0x11 == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG) &&
     0x11 == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG))
  {
    return MD_OK;
  }
  //check if MD has already passed PBL boot stage  
  else if((HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG) >= BOOT_SUCCESS_COMMAND_CODE) &&
          (HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG) <= MD_MBRDY_COMMAND_CODE))
  {
    DEBUG_LOG(SAIL_INFO,"MD continued to boot,past PBL \n\r"); 
    return MD_OK;
  }
  else
  {
    return MD_BOOT_EDL;
  }
}


/*===========================================================================
**  Function :  vRGMIIVoltageConfig
** ==========================================================================
*/
/*!
*
* @brief
*   This function configures
*            L9C voltage on MD KOBRA of RGMII_PX8 Rail 2.5V based
*            on Dip Switch Setting
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/


static void vRGMIIVoltageConfig(void)
{
  //In Case of IVI Sail need to communicate to MD via shadow register to configure RGMII_PX8 (L9C) on MD_KOBRA side
  if (CHIPINFO_ID_SA_LEMANSAU_IVI == ChipInfo_GetChipId())
  {
      if ( !HWIO_INF(SAILSS_SECURITY_CONTROL_CAPT_SEC_GPIO,RGMII_VOL_SEL_GPIO) )
      {
        // In Case of RGMII_VOL_SEL_GPIO is 0 , L9C need to be configure to 2.5V
        // SAIL_RGMII_VOL_SEL_2P5 | 0xAA040001
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG, 0xAA);
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG, 0x04);
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG, 0x00);
        HWIO_OUT(SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG, 0x01);
        DEBUG_LOG(SAIL_INFO,"IVI MD RGMII_PX8 2.5V\n\r");
      }
  }
}


/*===========================================================================
**  Function :  vPSailPinConfig
** ==========================================================================
*/
/*!
*
* @brief
*   This function configures
*             1. psail_err_n(sail_gpio 63) as weak pull up
*             2. sail_slp_en(sail gpio 66) as output
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
static void vPSailPinConfig(void)
{

  #ifdef lemans
  const GPIOConfigType cfg[] = {
                                  {
                                    .func=   0u,
                                    .dir =   GPIO_IN,
                                    .pull =  GPIO_PU,
                                    .drive = GPIO_2MA
                                  },
                                  {
                                    .func=   1u,
                                    .dir =   GPIO_OUT,
                                    .pull =  GPIO_NP,
                                    .drive = GPIO_2MA
                                  }
                             };
  const uint32_t ngpio[] = {63u, 66u};

  #else

  const GPIOConfigType cfg[] = {
  {
                                    .func=   1u,
                                    .dir =   GPIO_OUT,
                                    .pull =  GPIO_NP,
                                    .drive = GPIO_2MA
  }
                             };
  const uint32_t ngpio[] = {55u};

  #endif


  (void) sail_gpio_config_group(&ngpio[0], &cfg[0], (sizeof(ngpio)/sizeof(ngpio[0])));

  
}

/*===========================================================================
**  Function :  Print_ChipID
** ==========================================================================
*/
/*!
*
* @brief
*   This function
*            Prints the ChipID details in Uart log
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/
static void vPrint_ChipID( void)
{
	ChipInfoIdType eChipID;

	eChipID = ChipInfo_GetChipId();

	switch( eChipID)
	{
		case CHIPINFO_ID_SA_LEMANSAU_ADAS:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_LEMANSAU_ADAS \n\r");
			break;

		case CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS \n\r");
			break;

		case CHIPINFO_ID_SA_LEMANSAU_ADAS_H:
			DEBUG_LOG(SAIL_WARNING,"SAIL CHIP VARIANT: CHIPINFO_ID_SA_LEMANSAU_ADAS_H \n\r");
			break;

		case CHIPINFO_ID_SA_LEMANSAU_IVI:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_LEMANSAU_IVI \n\r");
			break;

		case CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS_L:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_LEMANSAU_IVI_ADAS_L \n\r");
			break;
    case CHIPINFO_ID_QCS_MONACO_INDUSTRIAL:
      DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_QCS_MONACO_INDUSTRIAL \n\r");
      break;

     case CHIPINFO_ID_QCS_LEMANS_INDUSTRIAL:
      DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_QCS_LEMANS_INDUSTRIAL \n\r");
      break;

    case CHIPINFO_ID_SA_MONACOAU_SRV1L:
      DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_MONACOAU_SRV1L \n\r");
    break;

    case CHIPINFO_ID_SA_MONACOAU_IVI:
        DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_MONACOAU_IVI \n\r");
    break;

    case CHIPINFO_ID_SA_MONACOAU_ADAS:
      DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_MONACOAU_ADAS \n\r");
    break;

    case CHIPINFO_ID_SA_MONACOAU_FLEX:
      DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_SA_MONACOAU_FLEX \n\r");
    break;

		case CHIPINFO_ID_QRB_LEMANS:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_QRB_LEMANS \n\r");
			break;

		case CHIPINFO_ID_QCS_LEMANS:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_QCS_LEMANS \n\r");
			break;

		case CHIPINFO_ID_QCS_MONACO_INDUSTRIAL_SAFE:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: CHIPINFO_ID_QCS_MONACO_INDUSTRIAL_SAFE \n\r");
			break;

		default:
			DEBUG_LOG(SAIL_WARNING,"CHIP VARIANT: %d \n\r",eChipID);
			break;
	}
}

/*===========================================================================
**  Function :  Initiate SoC warm reset to EDL function
** ==========================================================================
*/
/*!
*
* @brief
*   To initiate SoC warm reset for any SAIL Image auth/load failure.
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
void sailbsp_wr_to_edl(void)
{
#ifndef SAILJTAGPROGRAMMER
    //Inform MD about SAIL Image auth/load failure.
    //Initiate SoC to warm reset to enter EDL mode.
    eISD_InitiateEDLentryFrmSail(SOC_EDL, XBL_IMAGE_ID_DBG_POLICY);
    //wait in loop for MD to warm reset, which will reset SAIL as well.
    //err_fatal() call is not necessary for this loop, as we need to allow SoC to warm reset and enter EDL mode.
#endif
    while(1);
}

/*===========================================================================
**  Function :  SAIL EDL mode entry function
** ==========================================================================
*/
/*!
*
* @brief
*   To prepare SAIL to enter EDL mode and open SAIL NOR flash access for Image flashing.
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
void sailbsp_sailedl_entry(void)
{
#ifndef SAILJTAGPROGRAMMER
    DEBUG_LOG(SAIL_WARNING,"SAIL detected MD in EDL mode \n\r");
    /* Disable SAIL WDOG if MD is in EDL mode that will eventually reset SAIL */
    //wdt_disable_el2();
    /* For ADAS independent pmic, re-program the pmic for hard reset
     * As crash debug init would have programmed it for crash reset
    */
    if(xPmicSetResetState(PMIC_POFF_PON)  != PMIC_ERR_FLAG_SUCCESS)
    {
      //pmic hard reset programming failed, log it.
      DEBUG_LOG(SAIL_ERROR,"pmic hard reset programming failed: \n\r");
    }
    //MD will hard reset once device programmer completes flashing.
    /* No impact with this change as SoC will go through hard reset.
       but disabling the debug feature in SW is considered safe	*/
    if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
    {
  	  DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
    }

    /* For SAIL_PS_HOLD to automatically follow MD_PS_HOLD de-assertion via SAIL PS_HOLD generation HW block: 
    a) Unmask fields - bit[2:0] i.e bit[NORMAL_RESET_ST:POR_ST] in SAILSS_CC_MD_PS_HOLD_MASK register,
    b) Unmask field - bit[0] i.e bit[MD_PS_HOLD_EN_MASK] in SAIL_FATAL_ERR_PS_HOLD_EN_MASK register (OR) PwrSeq_busy = 1,
    c) MD_PS_HOLD from padring must be de-asserted i.e transition from high to low.
    Reference: SAIL Power Controller HDD - SAIL PS_HOLD generation HW block */
    //Write 0xCFF8 for SAIL to follow MD
    out_dword(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL);
    (void)eISDCfgFatalErrSailPsHoldMask(MD_PS_HOLD_EN, ISD_FATAL_ERR_ACTIVE);

    //DeInit SPINOR
    spinorEl2DeInit(0);
    //MD in EDL mode, reprogram OSPI NOR flash mux for MD access, device programmer can flash SAIL images
    //reconfigure_mux(QSPI_CONTROL_MD);
    SPINOR_STATUS status = spinorEl2ReconfigureMUX();
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "spinorEl2ReconfigureMUX failed \r\n");
    }
    //update shadow register value to notify MD of OSPI ready
    SAIL2MD_OSPI_MD_ACCESS_READY
    DEBUG_LOG(SAIL_WARNING,"SAIL2MD_OSPI_MD_ACCESS_READY set\n\r");
    uint32_t err_code = MD_IN_EDL;
    (void)vLcWriteLogCode(MD_BOOT_MILESTONES,FAIL,&err_code,1u);
    //wait in loop for MD to reset, which will reset SAIL as well.
    //MD in EDL mode is considered as non-fatal.
    //Hence SAIL must be in a loop below, until device programmer completes flashing and hard reset SAIL.
    //err_fatal() call is not necessary for this loop, as we need to allow device programmer flashing in parallel.
    vLogSetUartState(LOG_UART_STOP);
	xUartDeInit(uartDEBUG_HW);
#endif
	/* stay in a loop until MD pulls MD_PS_HOLD */
	while(1);
}

/*===========================================================================
**  Function :  Warm Boot function
** ==========================================================================
*/
/*!
*
* @brief
*   To perform driver initialization necessary for warm boot
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
int sailbsp_warmInit (boot_pbl_shared_data_type* pbl_shared_info)
{
#ifndef SAILJTAGPROGRAMMER
  int retval;
  pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
  uint8 ucPMICSleepExit = 0u;
  
  xUartInit(uartDEBUG_HW);
  
  xI2cInit(i2cPMIC_PSAIL_HW);

  DEBUG_LOG(SAIL_WARNING, "Device woken up from sleep\n\r");

  if ( bSailPmicPresent() )
  {
     xErrFlag = xPmicSleepWakeConfiguration(ucPMICSleepExit);
    if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag)
    {
      DEBUG_LOG(SAIL_ERROR,"[PMIC]: PMIC Wakeup Config Failed ret (0x%x)\n\r",xErrFlag);
      err_fatal(PMIC ,xErrFlag);
    }

  }

  /* this takes time to print memory buffer to UART console */
  vLogSetUartState(LOG_UART_WORKING);

  retval = SAILbspACSleepExit(); // ASILB NOC XPU Re-Configuration on warm boot path
  if ( E_SUCCESS != retval)
  {
     err_fatal(SECURITY_AC ,retval );
  }

  retval = spinorEl2ControllerReInit();
  if (retval != 0)
  {
    if( retval <0)
    {
    	retval = retval *(-1) + 1;
    }
    err_fatal(SPINOR ,retval);
  }

if(bUartConnectionStatus(uartDEBUG_CHANNEL) == UART_CONNECTED)
  {
     xUartDeInit(uartDEBUG_HW);
  }

  sailbsp_initsmp();

#endif
  return 0;
}

/*===========================================================================
**  Function :  Crash debug PASS2 function
** ==========================================================================
*/
/*!
*
* @brief
*   To perform driver initialization necessary for PASS2-RAMDUMP Phase
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
int sailbsp_pass2 (void)
{
#ifndef SAILJTAGPROGRAMMER
  int retval;
  uint32_t ulPlatformType = 0;
  uint64 startTime = 0;
  pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

  DEBUG_LOG(SAIL_INFO,"SAILSS pass2 entry \n\r");

  ChipInfo_Init();
  ulPlatformType = PlatformInfo_Platform();

  busywait_init();
  sail_gpio_init();
  vPSailPinConfig();
  vISDInit();

  retval = Clock_DriverInit();
  if( 0 != retval )
  {
    while(1);
  }

  icb_early_noc_config();

  /* DeInit and Init I2C during crashdbg pass2 */
  if(I2cInitStatusCheck(i2cPMIC_PSAIL_HW) == I2C_SUCCESS)
  {
    if (xI2cDeInit(i2cPMIC_PSAIL_HW) != I2C_SUCCESS)
    {
      DEBUG_LOG(SAIL_ERROR,"SAILSS pass2 i2c deinit failed \n\r");
    }
  }
  /* Initialize all serial engines firmware, gpio and clock*/
  vQupPlatformDriverInit();

  xUartInit(uartDEBUG_HW);
  /* this takes time to print memory buffer to UART console */
  vLogSetUartState(LOG_UART_WORKING);
 
  xI2cInit(i2cPMIC_PSAIL_HW);

  /* DeInit and Init PMIC during crashdbg pass2 */
  vPmicDeInit();
  xErrFlag = xPmicInit();
  if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag)
  {
	  err_fatal(PMIC ,xErrFlag);
  }
  
   /* Sail Crash debug PASS2 Entry */
  Crashdbg_pass2_ramdump_entry();
  /* During Crash debug, SAIL hard reset will happen after ram dump
   and execution will not proceed after this ramdump function */
#endif
  return 0;
}

/*===========================================================================
**  Function :  sailbsp_readdtb_updatebootmode
** ==========================================================================
*/
/*!
*
* @brief
*   Gets the sailUpdater device tree for fastboot/devprgm GPIO configuration and update boot mode
*
* @param
*   boot_mode_type* - boot mode regular/fastboot to be updated to this pointer based on the gpio config/values
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sailbsp_readdtb_updatebootmode (boot_mode_type* bootmode)
{
	int retval;
	void *pDTB = NULL;
	int32_t root_offset = 0;
	uint32_t fastboot_enable,fastboot_gpio_num,fastboot_gpio_drv,fastboot_gpio_func,fastboot_gpio_pull,fastboot_gpio_dir,fastboot_gpio_val=0;
	uint32_t devprgm_enable,devprgm_gpio_num,devprgm_gpio_drv,devprgm_gpio_func,devprgm_gpio_pull,devprgm_gpio_dir,devprgm_gpio_val=0;
	/* Get the DTB entries for fastboot/devprgm GPIO configuration */
	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/sailUpdater");
		if(root_offset > 0)
		{
			/* if any of the DTB entries are missing, skip entering fastboot/devprgm mode */
			retval = fdt_getprop_u32(pDTB, root_offset, "fastboot_enable", &fastboot_enable);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_num", &fastboot_gpio_num);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_drv", &fastboot_gpio_drv);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_func", &fastboot_gpio_func);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_pull", &fastboot_gpio_pull);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_dir", &fastboot_gpio_dir);
			retval |= fdt_getprop_u32(pDTB, root_offset, "fastboot_gpio_val", &fastboot_gpio_val);

			/* If no errors in the DTB configuration, configure and check for the GPIO value */
			if(0 == retval)
			{
				/*To enter to fast boot mode below gpio pin conditions needs to be satisfied*/
				if(1 == fastboot_enable)
				{
					/* Configure based on the parameters */
					sail_gpio_config_pin(fastboot_gpio_num, (GPIOConfigType){fastboot_gpio_func, fastboot_gpio_dir, fastboot_gpio_pull, fastboot_gpio_drv});
					/* Check for regular boot vs fastboot */
					if(fastboot_gpio_val == sail_gpio_ReadPin(fastboot_gpio_num))
					{
						*bootmode = BOOT_MODE_FASTBOOT_ENTER;
						return;
					}
					else
					{
						/*Regular boot up, if fast boot gpio is HIGH*/
						*bootmode = BOOT_MODE_REGULAR;
					}
				}
				else
				{
					/*Regular bootup, if fast boot is disabled in device tree*/
					*bootmode = BOOT_MODE_REGULAR;
				}
			}
			else
			{
				/* Regular boot up if Error in parameters or missing parameters in the config */
				*bootmode = BOOT_MODE_REGULAR;
			}

                         /*In case of Monaco, Dev programmer read is not needed
                           Dev Programmer Pin GPIO_62 Read for Entering Fastboot is a BMW Requirement on Lemans*/
			ChipInfoFamilyType eChipFamily = ChipInfo_GetChipFamily();
			if (CHIPINFO_FAMILY_LEMANSAU == eChipFamily)
			{			
			    retval = fdt_getprop_u32(pDTB, root_offset, "devprgm_enable", &devprgm_enable);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_num", &devprgm_gpio_num);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_drv", &devprgm_gpio_drv);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_func", &devprgm_gpio_func);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_pull", &devprgm_gpio_pull);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_dir", &devprgm_gpio_dir);
			    retval |= fdt_getprop_u32(pDTB, root_offset, "devprgm_gpio_val", &devprgm_gpio_val);

			    /* If no errors in the DTB configuration, configure and check for the GPIO value */
			    if(0 == retval)
			    {
				    /*To enter to fast boot mode below gpio pin conditions needs to be satisfied*/
				    if(1 == devprgm_enable)
				    {
					    /* Configure based on the parameters */
					    sail_gpio_config_pin(devprgm_gpio_num, (GPIOConfigType){devprgm_gpio_func, devprgm_gpio_dir, devprgm_gpio_pull, devprgm_gpio_drv});
					    /* Check for regular boot vs fastboot */
					    if(devprgm_gpio_val == sail_gpio_ReadPin(devprgm_gpio_num))
					    {
						    *bootmode = BOOT_MODE_FASTBOOT_ENTER;
					    }
					    else
					    {
						    /*Regular boot up, if dev program gpio is LOW*/
						    *bootmode = BOOT_MODE_REGULAR;
					    }
				    }
				    else
				    {
					    /*Regular bootup, if dev program is disabled in device tree*/
					    *bootmode = BOOT_MODE_REGULAR;
				    }
			    }
			    else
			    {
				    /* Regular boot up if Error in parameters or missing parameters in the config */
				    *bootmode = BOOT_MODE_REGULAR;
			    }
			}
		}
		else
		{
			/* Regular boot up, If the path if not found,  */
			*bootmode = BOOT_MODE_REGULAR;
		}
	}
	else
	{
		/* Regular boot up if the DTB entry is null */
		*bootmode = BOOT_MODE_REGULAR;
	}
}
#ifdef SAILJTAGPROGRAMMER
int sailjtagprogrammer_main (boot_pbl_shared_data_type* pbl_shared_info)
{
  int retval;
  uint32_t ulPlatformType = 0;

  ChipInfo_Init();
  ulPlatformType = PlatformInfo_Platform();
  busywait_init();
  sail_gpio_init();
  sailbsp_set_cold_boot_done();
#if 0 //mzhu
  if( CLOCK_SUCCESS != Clock_DriverInit() )
  {
    while(1);
  }
#endif //mzhu
  extern int spinor_init (int type,spinor_hardcode_data_mode *hardcoded_data_mode);
  retval = spinor_init ( 0, NULL );
  if (retval != 0)
  {
    while(1);
  }
  extern void jsdcc_init(void);
  jsdcc_init();
  return 0;
}
#endif
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
int sailbsp_main (boot_pbl_shared_data_type* pbl_shared_info, boot_mode_type* bootmode)
{
#ifdef SAILJTAGPROGRAMMER
  return sailjtagprogrammer_main (pbl_shared_info);
#else
  int retval;
  uint32_t ulPlatformType = 0;
  pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
  uint32_t log_data = 0u;
  ChipInfoIdType eChipID;
  uint32_t *err_fatal_codes = (uint32_t*)LOGCODE_ERR_FATAL_READ_DTB_ADDR;
  uint32_t MD_Status = 0;
  
DEBUG_LOG(SAIL_WARNING,"SAIL image id: %s \n\r", SAIL_IMAGE_VERSION);
  DEBUG_LOG(SAIL_WARNING,"SAIL workspace name: %s \n\r", SAIL_WSPACE_INFO);
  DEBUG_LOG(SAIL_WARNING,"hostname: %s \n\r", HOSTNAME);
  DEBUG_LOG(SAIL_WARNING,"SAIL build env timestamp: %s \n\r", DATE);

  /* Image id variable used here,so that it is a part of hyp elf build to be used for crashscope tool elf validation */
  sailbsp_strlcpy(QC_IMAGE_VERSION_STRING_AUTO_UPDATED,SAIL_IMAGE_VERSION,sizeof(QC_IMAGE_VERSION_STRING_AUTO_UPDATED));
  DEBUG_LOG(SAIL_INFO,"Image variant =  %s \n\r", IMAGE_VARIANT_STRING_AUTO_UPDATED);
  DEBUG_LOG(SAIL_INFO,"Image variant UUID= %s\r\n",OEM_IMAGE_UUID_STRING_AUTO_UPDATED);

  ChipInfo_Init();

  vSleepInit();

  retval = fdt_util_apply_overlay();
  if (0 != retval)
  {
      DEBUG_LOG(SAIL_WARNING, "warning - fdt overlay failed and skipped\n\r");
  }

  //gpio driver needs to be initialized early to reconfigure TLMM mux when MD is in EDL
  sail_gpio_init();
  
  /*read device tree and update boot mode*/
  sailbsp_readdtb_updatebootmode(bootmode);
  

  ChipInfoFamilyType eChipFamily = ChipInfo_GetChipFamily();
  
  vPSailPinConfig();
  busywait_init();
  MD_Status = sailbsp_waitfor_MDReady();

  //MD_BOOT_CHECK  will get set if any MD boot up failure happens,below part of code will be skipped incase of MD boot up failure
  if(in_dword(MD_BOOT_CHECK) == MD_OK)
  {
	  while( 0x11 != HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG) && 0x13 != HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG)){
		  busywait(1000000);

	  }
	  if(HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG) == 0x11){
		  MD_Status = MD_BOOT_EDL;
	  }
	  if(MD_Status == MD_BOOT_EDL)
	  {
		  DEBUG_LOG(SAIL_WARNING,"MD2SAIL_MD_ACCESS_READY was not set by MD \n\r");
		  //MD will reset once device programmer completes flashing.
		  //Write 0xCFF8 for SAIL to follow MD
		  out_dword(SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK, SAIL_FOLLOW_MD_FSM_STATE_MASK_VAL);
		  //MD in EDL mode, reprogram OSPI NOR flash mux for MD access, device programmer can flash SAIL images
		  SPINOR_STATUS status = spinorEl2ReconfigureMUX();
		  if(status != SPINOR_DEVICE_DONE)
		  {
			  DEBUG_LOG(SAIL_ERROR, "spinorEl2ReconfigureMUX failed \r\n");
		  }
		  //update shadow register value to notify MD of OSPI ready
		  SAIL2MD_OSPI_MD_ACCESS_READY
			  DEBUG_LOG(SAIL_WARNING,"SAIL2MD_OSPI_MD_ACCESS_READY set\n\r");
		  //wait in loop for MD to reset, which will reset SAIL as well.
		  //MD in EDL mode is considered as non-fatal.
		  //Hence SAIL must be in a loop below, until device programmer completes flashing and hard reset SAIL.
		  //err_fatal() call is not necessary for this loop, as we need to allow device programmer flashing in parallel.
		  while(1);
	  }
	  if(MD_Status == MD_OK)
	  {
		 
		  pre_BIST_init();
	  }
  }
  
  /* If the boot mode is not regular then update the shadow register early if the MD BIST is skipped */ 
  if(BOOT_MODE_REGULAR != *bootmode)
  {
      if(TRUE == getSkipMDBISTConfig())
      {
          DEBUG_LOG(SAIL_WARNING,"Updating shadow reg SAIL ENTER FASTBOOT \n\r");
          /* Update the shadow register for SAIL enter fastboot to notify MD */
          SAIL2MD_SAIL_ENTER_FASTBOOT
          el2_mpu_enable_ddr_region();
      }
 }
  
  /* Print Chip Variant Information*/
  vPrint_ChipID();

  // Read out Dip Switch Setting then Configure MD KOBRA L9C
  vRGMIIVoltageConfig();

  ulPlatformType = PlatformInfo_Platform();
  

  vISDInit();

  sailbsp_set_cold_boot_done();
 
  retval = Clock_DriverInit();
  if( CLOCK_SUCCESS != retval)
  {
	  err_fatal(CLOCK ,retval);
  }
#if 0
/* Tsense init before PMIC driver Init */
  retval = xTsensInit();
  if(err_fatal_codes[0] == TSENS) //Corrupting return value.Added for the purpose of err_fatal testing,generally diasbled
  {
      retval = err_fatal_codes[1];
  }
  if( TSENS_SUCCESS != retval )
  {
	  err_fatal(TSENS ,retval);
  }
  (log_data) = TSENS_INIT;
  vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);

  /* SAIL Boot time temp check before PMIC initializes */
  retval = xSAILBootTimeTempCheck();
  if( TSENS_SAIL_SOC_OVERHEATING == retval )
  {
	  err_fatal(TSENS ,retval);
  }
#endif
#ifndef NORPVL_ENB
  bootcfg_el2_setMDBIST_core(bootmode);
  el_entry_read_dts();
  
  /* Frame the SMP OS Image core configuration mask based on core LS configuration */
  boot_util_frame_smp_os_core_cfg();

  if (FALSE == sailbsp_checkmdedl())
  {
    if (BOOT_MODE_REGULAR == *bootmode)
    {
      sailbsp_initsmp();
    }
  }
  if (bootcfg_MDBIST_core == 0x0U)
  {
    vLCWriteTimeStamp( BIST_PH1_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ));
    if(is_el2_wdt_enabled == 0x1U)
    {
      if (BOOT_MODE_REGULAR == *bootmode)
      {
        //wdt_init_el2();
      }
    }
    retval = slRunMDBIST();
    if(err_fatal_codes[0] == BIST)
    {
        retval = err_fatal_codes[1];
    }
    if (E_SUCCESS != retval)
    {
      if(TRUE == sailbsp_checkmdedl())
      {
        DEBUG_LOG(SAIL_WARNING,"MD BIST failed due to MD in EDL \n\r");
		/*when MD requests EDL mode, SAIL will fail to setup SPINOR correctly for flashing. 
		We cannot call sailbsp_sailedl_entry this early.*/
      }
      else
      {
        /* MD BIST failure for other reasons */				
        err_fatal(BIST ,retval);
      }
    }
    vLCWriteTimeStamp( BIST_PH2_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  }
#endif  
  /* Initialize all serial engines firmware, gpio and clock*/
  vQupPlatformDriverInit();
  
  /* Initialize debug uart */
  retval = xUartInit(uartDEBUG_HW);

  if(retval == UART_SUCCESS)
  {
	  (log_data) = DBG_UART;
	  vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
  }

  /* this takes time to print memory buffer to UART console */
  vLogSetUartState(LOG_UART_WORKING);


  /* capture HBCU (SAIL BIST) result. if failure, inform VIP and go err_fatal */
  vCaptureDisableHBCU();

  retval = xI2cInit(i2cPMIC_PSAIL_HW);
  if(retval == I2C_SUCCESS)
  {
	  (log_data) = I2C;
	  vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);
  }

  vLCWriteTimeStamp( PMIC_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ));

  xErrFlag = xPmicInit();
  if(err_fatal_codes[0] == PMIC)
  {
	  xErrFlag = err_fatal_codes[1];
  }
  if ( PMIC_ERR_FLAG_SUCCESS != xErrFlag )
  {
      err_fatal(PMIC ,xErrFlag);

  }
  vLCWriteTimeStamp( PMIC_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

  (log_data) = ASILD_PMIC;
   vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 1);

   /* In case of independent PMIC Initialize CPR */
   busywait(3000);

  if ( TRUE == bSailPmicPresent() )
  {
    // Clock_LateInitClocks need to be called after xPmicInit to set CPU clock to Turbo Freq
    Clock_LateInitClocks();
  }

  /* Based on independent PMIC Detection Initialize Power Controlller Init */
  if ( FALSE == bSailPmicPresent() )
  {
    retval = xPCinitEL2(PC_PMIC_MERGED);
    if(err_fatal_codes[0] == PC)
	{
	  retval = err_fatal_codes[1];
	}
    if (PC_STATUS_SUCCESS != retval)
    {
    	err_fatal(PC ,retval);

    }else
    {
      DEBUG_LOG(SAIL_INFO,"PCInit Success for Merged Pmic\n\r");
    }
  }
  else
  {
	retval = xPCinitEL2(PC_PMIC_INDEPENDENT);
	if(err_fatal_codes[0] == PC)
	{
	    retval = err_fatal_codes[1];
	}
    if (PC_STATUS_SUCCESS != retval)
    {
    	err_fatal(PC ,retval);

    }else
    {
      DEBUG_LOG(SAIL_INFO,"PCInit Success for independent Pmic\n\r");
    }
  }
  
  icb_early_noc_config();

  /* For Autosar perform ICB EL2 init in core0 */
  if(icb_el2_init_core == 0x0U)
  {
    icb_el2_noc_init();
  }
  
/* Flag SAIL_CC should be enabled in tests.h - sailhyp*/

#ifdef SAIL_CC
  //wdt_disable_el2 ();
  vTestModuleInit ();
  #ifdef SAIL_CC_XBL
  extern void xXblSetPblSharedData(void *data);
  xXblSetPblSharedData((pbl_shared_info));
  #endif /* SAIL_CC_XBL */
  extern void vTestsCcMainLoop(void); /* This is forever while loop */
  vTestsCcMainLoop ( );
#endif

#ifndef OCTALSPI_PRE_SIL
  /* Note: Since not all RUMIs has OSPI support, we disable OSPI driver.
   * If you need to test OSPI please enable it
   */

#ifdef NORPVL_ENB
  //wdt_disable_el2();
  vTestModuleInit ();
  extern void vPvlTestLoop(void);
  vPvlInit();
  vPvlTestLoop( );
#endif

  vLCWriteTimeStamp( SPI_NOR_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ));
  retval = spinorEl2Init ( 0, NULL );
  if(err_fatal_codes[0] == SPINOR)
  {
      retval = err_fatal_codes[1];
  }
  if (retval != 0)
  {
    err_fatal(SPINOR ,retval);
  }
  vLCWriteTimeStamp( SPI_NOR_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
  
#ifdef SAIL_CC_SPINOR
  TESTerrorType_e result = TestOSPINOR_El2_Wrapper();
#endif
	vLCWriteTimeStamp(SBL_START ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

	retval = sailhyp_xbl_init(pbl_shared_info);
  if (XBL_SUCCESS != retval )
  {
    /* When MD is already in EDL mode, SAIL enters EDL mode.
    wait for SAIL Image flashing(Sec and DP) to complete */
    if (TRUE == sailbsp_checkmdedl())
    {
      sailbsp_sailedl_entry();
    }
    else
    {
      /* For both DP Image and Sec Image auth failure,
      allow SoC warm reset to enter EDL mode */  
      sailbsp_wr_to_edl();
    }
  }
  vLCWriteTimeStamp( SBL_END ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );

  //retval = spinorEl1Init ( );
  //if (retval != 0)
  //{
  //  while(1);
  //}

#endif
#ifndef NORPVL_ENB

      /* Only when SAIL/MD is not in EDL,SAIL XBL driver init done flag "waitfor_loadELF_ready" shall be set;
      to allow SAIL EL1 Image auth/hash/load of all SAIL cores */ 
      //waitfor_loadELF_ready = 0x1U;
  if (BOOT_MODE_REGULAR == *bootmode)
  {
      /* Sail Crash debug Init at cold boot. To be done after sailhyp_xbl_init(),
      because security image gets loaded in sailhyp_xbl_init() and crash debug uses security debug policy flags. */
      retval = Crashdbg_Init();
      if(err_fatal_codes[0] == CRASHDBG)
      {
          retval = err_fatal_codes[1];
      }
      if (DBG_FAILED == retval)
      {
          err_fatal(CRASHDBG, retval);
      }
	  (log_data) = CRASH_DBG;
      vLcWriteLogCode( SAIL_BOOT_MILESTONES ,PASS ,&log_data , 0x1);
  }

  /* ACInit should happen indepedent of MD state */
	retval = SAILbspACInit();
	if(err_fatal_codes[0] == SECURITY_AC)
	{
	  retval = err_fatal_codes[1];
	}
	if(retval != 0)
	{
	  err_fatal(SECURITY_AC ,retval );
	}

  retval = crypto_sail_init();
  if(retval != 0){
    DEBUG_LOG(SAIL_WARNING,"\n Crypto BAM init Failed \n\n\r");  
  }

#if defined (SAIL_CASAR)
  CDT_Enable_Module_Init(0);
#endif

  /* When SOC EDL is either initiated by SAIL or MD in current or previous boot(after SOC warm reset to enter EDL),
  SAIL shall open up SPINOR access to MD and stays in EDL loop for flashing to complete */  
  /*check again if MD PBL went into EDL mode
   * In case of IVI there might be a possibility of
   * MD entering EDL post warm reset via TCSR cookie
  */
  if(TRUE == sailbsp_checkmdedl())
  {
    sailbsp_sailedl_entry();
  }
  /* Only when SAIL/MD is not in EDL,SAIL XBL driver init done flag "waitfor_loadELF_ready" shall be set;
  to allow SAIL EL1 Image auth/hash/load of all SAIL cores */ 
  waitfor_loadELF_ready = 0x1U;
   
  /*Can_Init(); CANSS init is disabled to reduce EL2 size */

  /* Initialize HWKM */
  retval = hwkm_initialize_out_of_reset();
  if(err_fatal_codes[0] == SECURITY_HWKM)
  {
     retval = err_fatal_codes[1];
  }
  if (0 != retval )
  {
    err_fatal(SECURITY_HWKM ,retval);
    
  }
  #if defined(__ARM_FUSA__)
  retval = prng_fips_hybrid_entry();
  if(retval != 0)
  {
    err_fatal(SECURITY_PRNG_FIPS , retval);
  }
  #endif
  SECURE_STORAGE_STATUS secure_storage_ret = secureStorageEL2Init();
  if(secure_storage_ret != E_SECURE_STORAGE_SUCCESS)
  {
    err_fatal(SECURE_STORAGE , secure_storage_ret);
  } 

  if (BOOT_MODE_FASTBOOT_ENTER == *bootmode)
  {
      DEBUG_LOG(SAIL_WARNING,"\nEntering fastboot mode \n\n\r");
      /* Update the shadow register for SAIL enter fastboot to notify MD */
      SAIL2MD_SAIL_ENTER_FASTBOOT
      
      /* TODO: need to remove the while(1) condition once ISD/Sailupdate are enabled */
      /*check for TZ Status before proceeding with El2 Init and Mailbox Enable*/
      while(TZ_SUCCESS != eISDGetStatus(ISD_GET_TZ_STATUS))
      {
          ;
      }

      el2_mpu_enable_ddr_region();
      
      if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterEl2Init())
      {
          DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterEl2Init() failed\n\r");
          while (1);
      }
  
      vSailUpdaterTask((void*)bootmode);
  
      if ((*bootmode != BOOT_MODE_FASTBOOT_BOOT) && (*bootmode != BOOT_MODE_FASTBOOT_CONT) )
      {
          DEBUG_LOG(SAIL_ERROR,"Unexpected boot mode from SAIL Updater exit\n\r");
          while (1);
      }
      
      if (*bootmode == BOOT_MODE_FASTBOOT_BOOT)
      {
           BootPrimaryCoreOnly = 0xFFU;
       	   isdStatusType_e isdStatus = eISDSetCustomMDEvStatus(XBL_SEC_BOOT_SECCESS);
       	   if(isdStatus != XBL_SEC_BOOT_SECCESS)
       	   {
       	       DEBUG_LOG(SAIL_WARNING,"ISD status Roll back failed, isdStatus: %d \n\r", isdStatus);
       	   }
       	   DEBUG_LOG(SAIL_INFO,"set BootPrimaryCoreOnly for fastboot boot \n\r");
      }
      
      xSAILUpdaterDeinit();
  
             //workaround for UEFI DRAM clear
             (void)memset((void*)mailboxEB_QCMI_ADDR,0,0x1F);	      
      DEBUG_LOG(SAIL_WARNING,"\nExiting fastboot mode \n\n\r");
  }

  /* stop UART logging from EL2 here because BIST takes much time */
  vLogSetUartState(LOG_UART_STOP);


  /* Bring other cores out of reset only for regular boot */
  if (*bootmode == BOOT_MODE_FASTBOOT_CONT)
  {
      /* After confirming that MD is not in EDL mode at the end of EL2(as per above logic)
      bring secondary cores out of reset */
      sailbsp_initsmp();
  }
  #endif 

/* To enter in EL1 use option 1/2
 *  1. comment the xTestModule() functionality
 *  2. Enter 'Exit' command from the sail debug console
 * */
#ifndef UNIT_TEST_EL2_DISABLED
 // vTestModuleInit ();
//#endif
  //xTestModule();
#endif

  if(bUartConnectionStatus(uartDEBUG_CHANNEL) == UART_CONNECTED)
  {
      /* TODO: Remove busywait and implement UART GetStatus */
      busywait(50000);
      xUartDeInit(uartDEBUG_HW);
  }

  return 0;
#endif /* SAILJTAGPROGRAMMER */
}

/**********************************************************
 * Process the SAIL Updater RSCUE IMAGE HVC Call
 *
 *
 * @param rsp [OUT]
 *   Pointer to the Response Message sailbsp_hvc_rsp_t
 *
 * @return HVC_SUCCESS [OUT]
 *   Status of the operation.
 *
 **********************************************************/
uint32 xSailUpdaterRescueImageCheck(sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = BootPrimaryCoreOnly;
    return HVC_SUCCESS;
}


/*===========================================================================
**  Function :  HVCCall_IsClusterInLockStepMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function check if a particular cluster is in lockstep mode
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   None
*
*/


uint32 HVCCall_IsClusterInLockStepMode(uint32 cluster_num , sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32) sailbsp_readClusterLockStepConfig( (uint8) cluster_num);

    return (uint32) HVC_SUCCESS;
}

SAIL_DEFINE_SYSCALL(  (uint32_t)GET_CLUSTER_CONFIG,
                      (uint32_t)GET_CLUSTER_CONFIG_PARM_ID,
                      0u,
                      HVCCall_IsClusterInLockStepMode
                    );

SAIL_DEFINE_SYSCALL(SAIL_RESCUEIMG_HVC_ID,
                    SAIL_RESCUEIMG_PARAM_ID,
                    0,
                    xSailUpdaterRescueImageCheck
                    );
