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
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "common_functions.h"
#include "logcode.h"
#include "target.h"
#include "busywait.h"
#include "target_linker_map.h"

#define EL2_CORE_STACK_SIZE 12288 //size of core stack in el2
volatile uint32_t ulEl1FramePointer[4]; //stores the frame pointer for el1 stack for each core in case of el1 to el2 abort
volatile uint32_t ulabort_flag[4] ;

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
	uint32_t ulFramePointer      = 0;
    uint32_t ulPrevFramePointer  = 0;
    uint32_t ulLinkRegister      = 0;
	uint32_t ulELR_HYP           = 0;
	uint32_t ulELR_MODE          = 0;
	uint32_t ulStackPointer      = 0;
	uint32_t ulModeMask          = 0;
	uint32_t ulStackPointerStart = 0;
	uint32_t Prev_Mode_Mask      = 0;
	uint32_t Curr_Mode_Mask      = 0;
	uint32_t phys_core_id        = get_curr_phys_cpu_num();

	__asm__ volatile( "mrs %0, spsr_hyp\n" : "=r"(ulModeMask) :);//Reading previous SPSR

	ulModeMask = (ulModeMask & CONST_31); //Mode computation i.e. last 5 bits

	if ( ulModeMask == CPSR_MODE_HYP){

		__asm__ volatile( "mov %0, r7\n" : "=r" (ulFramePointer) :);

		if(phys_core_id == 0)
			ulStackPointerStart = SAILBSP_STACK_END;

		else if(phys_core_id == 1)
			ulStackPointerStart = SAILBSP_STACK_END - EL2_CORE_STACK_SIZE;

		else if(phys_core_id == 2)
			ulStackPointerStart = SAILBSP_STACK_END - (CONST_2 * EL2_CORE_STACK_SIZE);

		else if(phys_core_id == 3)
			ulStackPointerStart =  SAILBSP_STACK_END - (CONST_3 * EL2_CORE_STACK_SIZE);
	}
	else{//If its some el1 mode

		ulFramePointer = ulEl1FramePointer[phys_core_id];//retrieving FP for the respective core

		__asm__ volatile( "mrs %0, sp_usr\n" : "=r"(ulStackPointerStart) :); //SP for user mode
		
		if(ulStackPointerStart != 0U)
		{
			while((*(uint32_t *)ulStackPointerStart) != 0xA5A5A5A5)//Tracking back the SP to get start,the start SP has default value of 0xA5A5A5A5
			{
				ulStackPointerStart = ulStackPointerStart + 4;
			}
			switch( ulModeMask ){

				case CPSR_MODE_SYS ://user and system mode stack are same
				case CPSR_MODE_USR:

					break;

				case CPSR_MODE_IRQ :
				case CPSR_MODE_FIQ:
					ulStackPointerStart = ( ulStackPointerStart  - SYS_MODE_STACK_SIZE ); //subtracting sys mode stack size to get SP start for IRQ OR FIQ
					break;

				case CPSR_MODE_SVC:
					ulStackPointerStart = ( ulStackPointerStart  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE );
					break;

				case CPSR_MODE_ABT :
				case CPSR_MODE_UND:
					ulStackPointerStart = ( ulStackPointerStart - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE );
					break;

				default:
					while(1);
				}
		}

	}



	LOG_ERROR("\n\rStack unwind begins.. ");

	if( ulabort_flag[phys_core_id] == 1)
	{
		__asm__ volatile( "mrs %0, elr_hyp\n" : "=r"(ulELR_HYP) :);//elr_hyp gives the address of the api that causes abort
		LOG_ERROR("\n\rApi causes runtime error,  =%p ",ulELR_HYP);
	}

	//Tracing back till the bottom of call stack
	while((ulPrevFramePointer <ulFramePointer) && (ulFramePointer < ulStackPointerStart) ){

		if(ulPrevFramePointer != 0)
			LOG_ERROR("\n\rProgramCounter =%p ",ulLinkRegister);

		ulPrevFramePointer = ulFramePointer;
		ulLinkRegister = *(uint32_t *)(ulFramePointer+4);
		ulFramePointer = *(uint32_t *)(ulFramePointer);

	}
	LOG_ERROR("\n\rStack unwind ends.. \n\r");

}
