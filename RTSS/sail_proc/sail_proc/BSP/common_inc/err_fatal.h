#ifndef ERR_FATAL_H
#define ERR_FATAL_H
/**
 * @file  err_fatal.h
 * @brief Provide BSP error fatal enumarations
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
*/

/*===========================================================================
                              Include files
=============================================================================*/
#include "types.h"

/*===========================================================================
                              TYPEDEF
===========================================================================*/
typedef uint32_t sailbsp_err_fatal_e;
typedef enum{
EL_ENTRY                 = 1,
SECURITY_MPU             = 2,
SECURITY_AC              = 3,
SECURITY_SEC_BOOT        = 4,
SECURITY_HWKM            = 5,
R52_DIAGNOSTIC           = 6,
NOC_DIAGNOSTIC           = 7,
XBL                      = 8,
CLOCK                    = 9,
PMIC                     = 10,
TSENS                    = 11,
CPR                      = 12,
CRASHDBG                 = 13,
PC                       = 14,
SPINOR                   = 15,
BIST                     = 16,
IPCC_DIAGNOSTICS         = 17,
HBCU                     = 18,
SLEEP                    = 19,
ACMU_FATAL               = 20,
NORPVL                   = 21,
SAFERTOS                 = 22,
EL1                      = 23,
TGBMON                   = 24,
ISD                      = 25,
CLIB                     = 26,
VSENSE                   = 27,
FUSA_DRV                 = 28,
SAIL_UPDATER             = 29,
MAILBOX                  = 30,
IPCC_GIC_DIAGNOSTICS     = 31,
CHIPINFO                 = 32,
COMMON_SRC               = 33,
ICB                      = 34,
GPIO_INIT                = 35,
MCAL_GPT                 = 36,
SECURITY_PRNG_FIPS       = 37,
SECURE_STORAGE           = 38,
UART                     = 39,
FREERTOS                 = 40,
SPI_DEINIT               = 41,
FAULT_HANDLER            = 42,
ARM_STL                  = 43,
I2CEL1                   = 44
}MODULE_ID;

/*===========================================================================
                              DEFINES
===========================================================================*/
/** Possible reasons for the ERR_FATAL call
 *  NOTE: New entries should be added to the end of the block of error codes,
          and old entries never removed. 
 */


#define ERR_FATAL_NON_SECURE_WDT                  1
#define ERR_FATAL_AHB_TIMEOUT                     2 
#define ERR_FATAL_NOC_ERROR                       3
#define ERR_FATAL_UNHANDLED_EXCEPTION             4
#define ERR_FATAL_UNKNOWN_EXCEPTION               5
#define ERR_FATAL_ASSERT_FAILED                   6
#define ERR_FATAL_PREFETCH_ABORT_EXCEPTION        7
#define ERR_FATAL_ABORT_EXCEPTION                 8
#define ERR_FATAL_UNDEF_EXCEPTION                 9
#define ERR_FATAL_CLIB_INIT_FAILED                10
#define ERR_FATAL_FORCED_REBOOT                   11


#define ERR_FATAL_EL2_SP_EL1_SYNCH                32
#define ERR_FATAL_EL2_SP_EL1_IRQ                  33
#define ERR_FATAL_EL2_SP_EL1_FIQ                  34
#define ERR_FATAL_EL2_SP_EL1_ERR                  35
#define ERR_FATAL_EL2_SP_EL2_SYNCH                36
#define ERR_FATAL_EL2_SP_EL2_IRQ                  37
#define ERR_FATAL_EL2_SP_EL2_FIQ                  38
#define ERR_FATAL_EL2_SP_EL2_ERR                  39
#define ERR_FATAL_EL2_LEL64_SYNCH                 40
#define ERR_FATAL_EL2_LEL64_IRQ                   41
#define ERR_FATAL_EL2_LEL64_FIQ                   42
#define ERR_FATAL_EL2_LEL64_ERR                   43
#define ERR_FATAL_EL2_LEL32_SYNCH                 44
#define ERR_FATAL_EL2_LEL32_IRQ                   45
#define ERR_FATAL_EL2_LEL32_FIQ                   46
#define ERR_FATAL_EL2_LEL32_ERR                   47
 
 
#define ERR_FATAL_FAULT_DETECTED                  64
#define ERR_FATAL_EL2_PREFETCH_ABT                65
#define ERR_FATAL_EL2_DATA_ABT                    66
#define ERR_FATAL_EL2_UNDEF_ABT                   67
#define ERR_FATAL_EL2_STACK_CHK_FAILED            68
#define ERR_FATAL_SVC_CALL_FAILED                 69
#define ERR_FATAL_HVC_CALL_FAILED                 70
 
 


/**
  This function is invoked to signal a fatal error requiring a reset. 
  Also logs the Fatal Error code and call stack.

  @param[in]  err   The category of error requiring the reset

  @sideeffects  This function does not return since it resets the
                processor.  
*/
void err_fatal(MODULE_ID mid,int32_t Error_ID);


/**
  This function is invoked to signal a warning. Logs the warning and callstack.

  @param[in]  err   The category of error requiring the reset

  @sideeffects  This function does not return since it resets the
                processor.  
*/
void sailbsp_err_warning(sailbsp_err_fatal_e err);

#endif /*  ERR_FATAL_H */
