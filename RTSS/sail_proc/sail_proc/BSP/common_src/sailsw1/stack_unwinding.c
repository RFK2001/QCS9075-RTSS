/*
@file stack_unwinding.c

*/
 /*        Copyright (c) 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 */
 
 
/*===========================================================================
                              Include files
=============================================================================*/

#include "stack_unwinding.h"
#include "debug_log.h"
#include <stdio.h>
#include "logcode.h"
#include "freertos_init.h"
#include "target.h"        
#include "busywait.h"																																																																																																																																																																										
#include "target_linker_map.h"

extern volatile uint32_t Current_Lr; //Stores the address(r14) for the error API ,before it gets corrupt ,as we switch to different stack
uint32_t stack_end_address_data = 0xA5A5A5A5;
volatile uint32_t Current_fp; // Stores the FP(r7) ,before it gets corrupt ,as we switch to different stack
/*===========================================================================
**  Function :  stack_unwind
** ==========================================================================
*/
/*!
*
* @brief
*   This unwinds the call stack and prints the function address
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
void stack_unwind( void )
{
	uint32_t ulFramePointer      = Current_fp;
    uint32_t ulPrevFramePointer  = 0;
    uint32_t ulLinkRegister      = 0;
    uint32_t ulModeMask          = 0;
    uint32_t ulStackPointerStart = 0;
    uint32_t ulStackPointer      = 0;
    uint32_t Prev_Mode_Mask      = 0;
    uint32_t Curr_Mode_Mask      = 0;

/*
 * Reading previous mode and making it current mode
*/	

   __asm__ volatile( "mrs %0, CPSR\n" : "=r"(Curr_Mode_Mask) :);//Reading CPSR

   Curr_Mode_Mask = (Curr_Mode_Mask & CONST_31); //Mode computation

   switch(Curr_Mode_Mask){

   	   case CPSR_MODE_IRQ:
   		   __asm__ volatile( "mrs %0, SPSR_irq\n" : "=r"(ulModeMask) :);//Read prev mode status register
   		   break;
   	   case CPSR_MODE_FIQ:
   		   __asm__ volatile( "mrs %0, SPSR_fiq\n" : "=r"(ulModeMask) :);//Read prev mode status register
   		   break;
   	   case CPSR_MODE_SVC:
   		   __asm__ volatile( "mrs %0, SPSR_svc\n" : "=r"(ulModeMask) :);//Read prev mode status register
   		   break;
   	   case CPSR_MODE_ABT :
   		   __asm__ volatile( "mrs %0, SPSR_abt\n" : "=r"(ulModeMask) :);//Read prev mode status register
   		   break;
   	   case CPSR_MODE_UND:
   		   __asm__ volatile( "mrs %0, SPSR_und\n" : "=r"(ulModeMask) :);//Read prev mode status register
   		   break;
   	   case CPSR_MODE_SYS :
   		   ulModeMask = CPSR_MODE_SYS;
   		   __asm__ volatile( "mov %0, r7\n" : "=r" (ulFramePointer) :);

   	   	   break;
   	   default:
   		   while(1);
   }

   	Prev_Mode_Mask = (ulModeMask & CONST_31); //Mode computation

   	__asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulModeMask) :);//Read curr mode status register

	if( Prev_Mode_Mask == CPSR_MODE_USR) //if previous mode is user mode
	{
		ulModeMask = (( ulModeMask & ( ~ CPSR_MODE_MASK )) | CPSR_MODE_SYS);

		__asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) ); // Make current mode as system mode
	}
	else{

		ulModeMask = (( ulModeMask & ( ~ CPSR_MODE_MASK )) | Prev_Mode_Mask);

		__asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) ); //Make current mode as previous mode
	}


/*
 * Computing stack pointer start for current mode 
*/
     switch( Prev_Mode_Mask ){

		 case CPSR_MODE_SYS :
		 case CPSR_MODE_USR:

			 __asm__ volatile( "mov %0, r13\n" : "=r" (ulStackPointerStart) :);//Reading SP
			 while((*(uint32_t *)ulStackPointerStart) != 0xA5A5A5A5) //Tracking back the SP to get its start,the start SP has default value of 0xA5A5A5A5
			 {
				 ulStackPointerStart = ulStackPointerStart+4;
			 }
			 break;

		 case CPSR_MODE_IRQ :
		 case CPSR_MODE_FIQ:
			 ulStackPointerStart = ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE );//subtracting sys mode stack size to get SP start for IRQ OR FIQ
			 break;

		 case CPSR_MODE_SVC:
			 ulStackPointerStart = ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE );
			 break;

		 case CPSR_MODE_ABT :
		 case CPSR_MODE_UND:
			 ulStackPointerStart = ( SAILBSP_STACK_END - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE );
			 break;

		 default:
			 while(1);
     }

/*
 * Stack Unwind begins ..
*/

    DEBUG_LOG(SAIL_INFO,"\n\rStack unwind begins.. ");

    if(Curr_Mode_Mask != CPSR_MODE_SYS)// if current mode is not abort mode,means its a driver init failure
    	DEBUG_LOG(SAIL_INFO,"\n\rApi causes runtime error, ProgramCounter =%p ",Current_Lr);

	//Tracing back till the bottom of call stack
	while((ulPrevFramePointer <ulFramePointer) && (ulFramePointer <= ulStackPointerStart ) ){

		if(ulPrevFramePointer != 0)
			DEBUG_LOG(SAIL_INFO,"\n\rProgramCounter =%p ",ulLinkRegister);


		ulPrevFramePointer = ulFramePointer;

		ulLinkRegister = *(uint32_t *)(ulFramePointer+4);
		ulFramePointer = *(uint32_t *)(ulFramePointer);
		
	}	
	DEBUG_LOG(SAIL_INFO,"\n\rStack unwind ends.. \n\r");

	ulModeMask = (( ulModeMask & ( ~ CPSR_MODE_MASK )) | Curr_Mode_Mask);
	__asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) ); //Switch back to current mode i.e. error mode
}
