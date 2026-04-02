/*
@file debug_err_fatal.c
@brief Misc. error handling routines

*/
 /*        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 */
 
 
/*===========================================================================
                              Include files
=============================================================================*/
#include "types.h"
#include "cache_ops.h"
#include "debug_log.h"
//#include "logcode.h"
#include "err_fatal.h"
#include "isd.h"
#include "isd_common_def.h"
#include "gpio.h"
#include "crc.h"
#include "crcconfig.h"
#include "Clock.h"
//#include "wdt.h"
#include "busywait.h"
#include "stack_unwinding.h"

#include "uart.h"

/*===========================================================================
                              Macros
=============================================================================*/
#define vipUART_BOOT_MSG_REQ_COMMAND_ID			  0xB0
#define vipUART_PING_COMMAND_ID					  0xB1
#define vipUART_BOOT_MSG_RESPONSE_COMMAND_ID	  0x30
#define socBOOT_MESSAGE_LENGTH					  0xC
#define uartCMD_ID_BYTE							  0x1
#define uartPACKET_HEADER_BYTE					  0x6
#define socBOOT_PACKET_LENGTH					  0x12

#define ERR_FATAL_SAIL  0UL
#define ERR_FATAL_EDL   1UL

//#define ComputeVIPUartWaitTime(DataLen)    ((((DataLen) * 1000000) / 115200) + 3000)

extern uartConnectionStatusType_e bUartConnectionStatus(uint8 ucChannelId);
/*=================================================================================================
**                                Local function prototypes                                       **
=================================================================================================*/
static void err_fatal_reset( void );
static void err_fatal_log(MODULE_ID mid,uint32_t Error_ID);
static uint32_t err_fatal_type(MODULE_ID mid,uint32_t Error_ID);
static void err_fatal_send_vip_message(MODULE_ID mid,uint32_t Error_ID);
static void err_fatal_SAIL(MODULE_ID mid,uint32_t Error_ID);

/*===========================================================================
                              Variables
=============================================================================*/
UART_DATA static uint8 ucSAILBootLogSeqId;
UART_DATA static uint8 ucMDBootLogSeqId;

uint8 in_error_fatal = 0;
static uint32  fatal_err_state = false;
uint8 UART_Init_Status = 0u;
uint8 *recieve_result;

/**
 * @   err_fatal  : API for Fatal error cases. This API will either
 wait for WDOG to bite if its enabled. If not it will deassert PS_HOLD.
 */
static void err_fatal_reset( void )
{
#ifndef SAILJTAGPROGRAMMER
#if 0
  //Check if WDOG has been enabled. 
  if(is_wdt_enabled_el2() == WDT_ENABLED )
  {
    //Wait for WDOG bite to pull SAIL_PS_HOLD. This will cause the system to restart, based on PMIC cfg.
    do{
        __asm__("wfi");
    }while(1);
  }
  else
#endif  
  {
    //pull SAIL_PS_HOLD. This will cause the system to restart, based on PMIC cfg.
    eISDSailPSHoldDeAssert();
  }
#endif
  while(1);
}

/**
 * @   err_fatal_log  : API for Fatal error and call stack logging on SAILSS console.
 In case of early err_fatal, initialize necessary drivers to enable UART logging.
 */ 
static void err_fatal_log(MODULE_ID mid,uint32_t Error_ID)
{
#ifndef SAILJTAGPROGRAMMER
  if ( UART_DISCONNECTED ==  bUartConnectionStatus(uartDEBUG_CHANNEL))
  {
    sail_gpio_init();
    busywait_init();
    vISDInit();
    if( CLOCK_SUCCESS != Clock_DriverInit())
    {
      err_fatal_reset();
    }
    vQupPlatformDriverInit();
    xUartInit(uartDEBUG_HW);
    vLogSetUartState(LOG_UART_WORKING);
  }
 
  LOG_ERROR("SAILBSP Fatal Error. Module_ID :%d  Error_ID : %d \n\r",mid,Error_ID);
  stack_unwind();
#endif
}

/**
 * @   err_fatal_type  : API to check whether SAIL fatal error is due to a)MD boot failure, 
 b)SAIL EL2/EL1 boot failure, c)SAIL EDL entry i.e EL1 boot failure due to Image loading error, OR d)Any error after system boot completion.
 In case of SAIL EDL entry, SAIL shall follow MD_PS_HOLD to reset SAILSS. 
 Otherwise, SAIL shall de-assert SAIL_PS_HOLD directly or via R52 WDOG bite.
 */ 
static uint32_t err_fatal_type(MODULE_ID mid,uint32_t Error_ID)
{
  uint32_t ret = ERR_FATAL_SAIL;

  if (mid != ISD)
    ret = ERR_FATAL_SAIL; //SAIL EL2/EL1 boot failure OR Any error after system boot completion.
  else if ((mid == ISD) && (Error_ID <= ISD_FATAL_ERR_SAILDP_LOAD_FAIL))
    ret = ERR_FATAL_EDL; //SAIL EDL entry i.e EL1 boot failure due to Image loading error

  return(ret);
}

/**
 * @   err_fatal_send_vip_message  : API to update fatal error info to VIP via UART.
 NOTE - Direct Communication to VIP from other cores are allowed only if Core2(DCLS) is not up.
 */
static void err_fatal_send_vip_message(MODULE_ID mid,uint32_t Error_ID)
{
#if 0  
#ifndef SAILJTAGPROGRAMMER

  static uint8 BOOT_Status[CONST_256];
  uint32_t timer= 0u;
  uint8 pxdata = 0x0U;
  bool is_dcls_core_up = 0;
  

  //Write Error Code/Error ID into shared memory between cores.
  vLCWriteErrorCode( mid ,get_curr_phys_cpu_num() ,Error_ID);

  //Reading SAIL boot logcode Status from shared memory to check whether dcls core is up(core2).
  recieve_result = LcReadLogCode(SAIL_BOOT_MILESTONES);

  if(recieve_result != NULL)
  {
	is_dcls_core_up = ( recieve_result[2] & ( 1 << CONST_6));
  }

  /* When err_fatal is called from cluster 0 i.e either core 0 or core 1,
  error code communication to VIP is allowed only if core2(DCLS) is not up */
  if( get_curr_cluster_num() == 0){
    //If dcls not up ,wait for a sec in a poll manner
    //PLEASE CHECK.... During this polling of 1sec, ACK to MD will be missed for core2 EL1 Image loading failure use case.. how to handle it?
    while( (!is_dcls_core_up) && (timer != CONST_1000) ){
      busywait(CONST_1000);
      recieve_result = LcReadLogCode(SAIL_BOOT_MILESTONES);

      if(recieve_result != NULL)
      {
    	  is_dcls_core_up = ( recieve_result[2] & ( 1 << CONST_6));
      }
      timer++;
    }
    //After wait of 1 sec,if dcls is up,core will go in infinite loop
	if( is_dcls_core_up )
    {

      if(err_fatal_type(mid, Error_ID) == ERR_FATAL_SAIL)
      {
        if (mid == BIST)
        {
            ;
        }
        else
        {
          err_fatal_reset();
        }
      }
    }
  }
  //NOTE - Necessary drives for UART communication to VIP must be complete via err_fatal_log()
  //Init UART for VIP communication.
  xUartInit(uartVIP_HW);

  //UART message format for SAIL.
  BOOT_Status[1] = vipUART_BOOT_MSG_RESPONSE_COMMAND_ID; /* SoC Boot message command ID to VIP*/
  BOOT_Status[2] = 0x10;
  BOOT_Status[3] = socBOOT_PACKET_LENGTH;
  if( ucSAILBootLogSeqId == 0xffU)
  {
    ucSAILBootLogSeqId = 0x0U;
  }
  BOOT_Status[4] = ucSAILBootLogSeqId;
  BOOT_Status[5] = 0xF0;

  ucSAILBootLogSeqId++;

  if(recieve_result != NULL)
  {
    for(uint8 count = 0U ;count < socBOOT_MESSAGE_LENGTH; count++)
    {
	  BOOT_Status[count + uartPACKET_HEADER_BYTE] = recieve_result[count];

    }
  }
  if ( CRC_SUCCESS == xCrc8Generate( crcUARTVIP_CHANNEL_CRC8 , &BOOT_Status[1] , (socBOOT_PACKET_LENGTH-1) , &pxdata ) )
  {
    BOOT_Status[0] = pxdata;
  }

  //UART message format for MD.
  BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH + 1] = vipUART_BOOT_MSG_RESPONSE_COMMAND_ID;
  BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH + 2] = 0x10;
  BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH + 3] = socBOOT_PACKET_LENGTH;
  if( ucMDBootLogSeqId == 0xffU)
  {
      ucMDBootLogSeqId = 0x0U;
  }
  BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH + 4] = ucMDBootLogSeqId;
  BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH + 5] = 0xF0;
  ucMDBootLogSeqId++;
  //Packing MD Boot status and Error code(if any)
  recieve_result = LcReadLogCode(MD_BOOT_MILESTONES);

  if(recieve_result != NULL)
  {
    for(uint8_t count = 0U ;count < socBOOT_MESSAGE_LENGTH; count++)
    {
      BOOT_Status[count + socBOOT_PACKET_LENGTH + uartPACKET_HEADER_BYTE] = recieve_result[count];
    }
  }
  if ( CRC_SUCCESS == xCrc8Generate( crcUARTVIP_CHANNEL_CRC8 , &BOOT_Status[socBOOT_PACKET_LENGTH+1] , (socBOOT_PACKET_LENGTH-1) , &pxdata ) )
  {
    /* Adding the CRC field*/
    BOOT_Status[uartPACKET_HEADER_BYTE + socBOOT_MESSAGE_LENGTH ] = pxdata;
  }

  ulUartWrite(uartVIP_CHANNEL ,(const char*) &BOOT_Status[0], CONST_256);//Sending to VIP
  if (mid == BIST)
  {
    uint32_t ulUartWaitTime = 0;

    ulUartWaitTime = (uint32_t)ComputeVIPUartWaitTime(CONST_256);
    busywait(ulUartWaitTime); /* Add delay to push log going out of UART Tx FIFO */
    xUartDeInit(uartVIP_CHANNEL);
  }
#endif
#endif
}

/**
 * @   err_fatal_SAIL  : API for SAIL fatal error handling due to SAIL EL2/EL1 boot failure(other than EDL entry) and
 for any error after system boot completion.
 */
static void err_fatal_SAIL(MODULE_ID mid,uint32_t Error_ID)
{
  //Disable interrupts on this core.
  __asm__ volatile("cpsid  aif");
  ISB;
  //PLEASE CHECK.... clock driver doesnt call err_fatal for driver init failure.
  if ( mid == CLOCK)
  {
    err_fatal_reset();
  }
  else if ( mid == BIST)
  {
    err_fatal_log(mid,Error_ID);
    err_fatal_send_vip_message(mid,Error_ID);
    return;
  }
  //Enable UART(if needed). Log fatal error and call stack info into log buffer/console.
  err_fatal_log(mid,Error_ID); 
  //Communicate to VIP about fatal error code, before resetting the system.
  err_fatal_send_vip_message(mid,Error_ID); 
  //Wait for 50ms to flush the log buffer into console, before resetting the system.
  //NOTE - Does this delay also helps to ensure that VIP communication will be complete from core2?
  busywait(50000);
  //Wait for R52 WDOG to bite if it's enabled. If not, deassert SAIL_PS_HOLD directly to reset SAILSS. 
  err_fatal_reset();
}

/**
 * @   err_fatal_EDL : API for SAIL fatal error handling due to
 SAIL EDL entry for EL1 Image loading failure.
 */
static void err_fatal_EDL(MODULE_ID mid,uint32_t Error_ID)
{
  //Enable UART(if needed). Log fatal error and call stack info into log buffer/console.
  err_fatal_log(mid,Error_ID);
  //Communicate to VIP about fatal error code, before resetting the system.  
  err_fatal_send_vip_message(mid,Error_ID);
  // Wait for 50ms to flush the log buffer into console, before resetting the system.
  //NOTE - Does this delay also helps to ensure that VIP communication will be complete from core2?
  busywait(50000);
  //Configure PMIC for reset and Send ACK to MD as SAIL_RESET_READY via ISD driver.
  //Wait for MD_PS_HOLD to de-assert(go low) first. Upon MD_PS_HOLD negative edge ISR, SAIL shall de-assert SAIL_PS_HOLD. 
  /* NOTE:
  a) As SAIL need MD_PS_HOLD negative edge ISR to follow MD, disabling interrupts on core is not allowed for SAIL EDL entry.
  b) PS_HOLD de-assertion(MD and SAIL) in above step , will be a warm reset to enter EDL for SAIL EL1 Image loading failure use case.
  */
}

/**
 * @   err_fatal  : API for SAIL fatal error handling.
 */
void err_fatal(MODULE_ID mid,int32_t Error_ID)
{

  if(Error_ID < 0)
  {
	  if(mid == SPINOR)
		  Error_ID = Error_ID *(-1) + 1;
	  else
		  Error_ID *= -1;

  }
  uint32_t switch_cond = err_fatal_type(mid, (uint32_t)Error_ID);

  /* Check whether SAIL fatal error is due to 
  a)SAIL EL2/EL1 boot failure, 
  b)SAIL EDL entry i.e EL1 boot failure due to SAIL EL1 Image loading error, OR 
  c)Any error after system boot completion.
  In case of SAIL EDL entry, SAIL shall follow MD_PS_HOLD to reset SAILSS. 
  Otherwise, SAIL shall de-assert SAIL_PS_HOLD directly or via R52 WDOG bite(if enabled).*/ 
  switch(switch_cond){
    case ERR_FATAL_EDL:
        //Log call stack, SAIL EDL entry and error code update to VIP via UART.
        err_fatal_EDL(mid ,(uint32_t)Error_ID);
        /* err_fatal_EDL() function should return to ISD driver to proceed with below steps.
        - Configure PMIC for reset and Send ACK to MD as SAIL_RESET_READY.
        - Wait for MD_PS_HOLD to de-assert(go low) first. Upon MD_PS_HOLD negative edge ISR, SAIL shall de-assert SAIL_PS_HOLD */ 
    break;
    case ERR_FATAL_SAIL:
    default:
        //Log call stack, SAIL fatal error and error code update to VIP via UART.
        err_fatal_SAIL(mid ,(uint32_t)Error_ID);
        //err_fatal_sail() function should never return.
        if ( mid == BIST )
        {
            return;
        }
        while(1)
        ;
    break;
  }
  
}

void err_warning(sailbsp_err_fatal_e err)
{
  //Disable interrupts on this core.
  uint32_t cpsr_state;
  __asm__ volatile (" mrs %0, cpsr" : "=r" (cpsr_state) :  );
  
  __asm__ volatile("cpsid  aif");
  ISB;
  //log the warning
  LOG_NOUART("SAILBSP Warning. Error Code :%d",err);
  //Capture the backtrace and log it.
  stack_unwind();
  //restore the aif bits to its orignal state
  __asm__ volatile (" msr cpsr, %0": : "r" (cpsr_state));
}

/**
 * @  salbbsp_set_err_fatal
 */
void  set_err_fatal_state(void)
{
  fatal_err_state = true;
}

/**
 * @   is_fatal_err_set
 */
bool  is_fatal_err_set(void)
{
  uint32_t addr = (uint32_t)(&fatal_err_state);
  clean_invalidate_cache_by_addr(addr);
  return fatal_err_state;
}

