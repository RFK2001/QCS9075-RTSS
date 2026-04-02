/**
 * @file ipcc_gic.c
 * @brief
 * Source file for API GIC SGI functionality between Clusters using IPCC.
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

/*============================================================================
 *                              Include Files
 *============================================================================*/

#include "ipcc_gic.h"
#include "arch_ops.h"
#include "target.h"
#include "debug_log.h"
#include "err_fatal.h"

 /*===========================================================================
                                DEFINES
============================================================================*/ 
#define GIC_MAX_SGI         16
 /*===========================================================================
                                VARIABLES
============================================================================*/ 
static IPCC_Handle gic_sgi_intr_handle[SAILBSP_CPU_COUNT] = {};   

 /*===========================================================================
                                FUNCTIONS
============================================================================*/ 
extern void gic_handle_ipcc_sgi(uint32 vector);
/*============================================================================
            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE
============================================================================*/

/** This is the global structure which holds information about IPCC interrupts
 *  available on the sail subsystem. */
ipcc_gic_sgi_intr_info_type gic_sgi_interrupt_table[SAILBSP_CPU_COUNT] = { 
                                                            {
                                                                IPCC_C_SAIL0,
                                                                {IPCC_C_SAIL2,IPCC_C_SAIL3},
                                                                0,
                                                                31
                                                            },
                                                            {
                                                                IPCC_C_SAIL1,
                                                                {IPCC_C_SAIL2,IPCC_C_SAIL3},
                                                                0,
                                                                31
                                                            },
                                                            {
                                                                IPCC_C_SAIL2,
                                                                {IPCC_C_SAIL0,IPCC_C_SAIL1},
                                                                1,                                                                
                                                                31
                                                            },
                                                            {
                                                                IPCC_C_SAIL3,
                                                                {IPCC_C_SAIL0,IPCC_C_SAIL1},
                                                                1,
                                                                31
                                                            },                    
                                                         };
/*
 *===========================================================================
 *						        Functions
 *===========================================================================
 */

void ipcc_gic_sgi_isr( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal ){
   //add checks if the sender is from the other cluster. 
   
   //for now assuming we only handle SGIs meaning signals 0-15
   if(nSignal < GIC_MAX_SGI) {       
    gic_handle_ipcc_sgi(nSignal); 
   }
   else 
	   err_fatal(IPCC_GIC_DIAGNOSTICS ,IPCC_GIC_SGI_ERROR);
}

/*===========================================================================
  FUNCTION  ipcc_gic_register_interrupt
===========================================================================*/
/**
  This function registers for R52 Cores IPCC interrupts.

  @return
  None
*/
/*=========================================================================*/
void ipcc_gic_register_cpu(uint32 cpu_id)
{
  ipcc_gic_sgi_intr_info_type * intr;
  uint32 i;
  //uint32 cpu_id = arch_curr_cpu_id();
  IPCC_Client client;
  /* Register to signals from  Cores of the other cluster */
  intr = (ipcc_gic_sgi_intr_info_type *)(&gic_sgi_interrupt_table[cpu_id]);
  /* Create Incoming Interrupt Controller Handle */
  if( ( IPCC_EOK != IPCC_AttachEx( &gic_sgi_intr_handle[cpu_id], IPCC_P_SAIL_MPROC, intr->client ,cpu_id ) )
                                     || (gic_sgi_intr_handle[cpu_id] == NULL) )
  {
    LOG_ERROR("ipcc_gic_register_interrupt: IPCC Handle creation failed!");
    err_fatal(IPCC_GIC_DIAGNOSTICS ,IPCC_GIC_REGISTER_ERROR);;
  }
  
  for(i = 0; i < 2;i++) 
  {
    client = intr->to[i];
    if( IPCC_RegisterInterrupt(
        gic_sgi_intr_handle[cpu_id],
        client,
        intr->low,
        intr->high,
        (IPCC_CB)ipcc_gic_sgi_isr,  //ToDo Check if we need per core SGI handler
        0) != IPCC_EOK )  //ToDo Check if we need to send any data
    {
      LOG_ERROR("ipcc_gic_register_interrupt: GIC IPCC ISR for core %d failed to "
                "register.", cpu_id);
      err_fatal(IPCC_GIC_DIAGNOSTICS ,IPCC_INTR_REGISTRATION_ERROR);;
    }
  } 
}

/*===========================================================================
  FUNCTION  ipcc_gic_send_interrupt
===========================================================================*/
/**
  This function sends out the interprocessor interrupts.

  @param[in] dest Destination processor to interrupt

  @return
  None
*/
/*=========================================================================*/
void ipcc_gic_send_interrupt(uint8 vector, uint32 dest_cluster,uint32 cpu_mask, uint8 cpu_id)
{
 
  ipcc_gic_sgi_intr_info_type * intr;
  uint32 cpu = 0;
  uint32 dest = 0;
  
  if(dest_cluster >=2 )
      return;
  while(cpu_mask && (cpu < 2) && (dest_cluster < 2)){
     if (cpu_mask & (1u << cpu)) {
        dest = cpu + (dest_cluster * 2);
         
        cpu_mask &= ~(1u << cpu);
        intr = (ipcc_gic_sgi_intr_info_type *)&gic_sgi_interrupt_table[dest];
        IPCC_Trigger(gic_sgi_intr_handle[cpu_id],intr->client,vector, vector);
      }
      cpu++;
  }
}

#ifdef TEST_SRC_ENABLED
IPCC_Handle *IPCC_GetHandle(uint8_t cpu_id){
  if(cpu_id >= 4) 
    while (1);
  
  return &gic_sgi_intr_handle[cpu_id];
}
#endif
