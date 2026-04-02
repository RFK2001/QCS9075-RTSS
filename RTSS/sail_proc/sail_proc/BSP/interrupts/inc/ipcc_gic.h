/**
 * @file ipcc_gic.h
 * @brief Types definitions
 * Header file for the definition of types used in sail
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/

#ifndef IPCC_GIC_H
#define IPCC_GIC_H

/*============================================================================
 *                              Include Files
 *============================================================================*/
#include "types.h"
#include "IPCC.h"

 /*============================================================================
                                Types
============================================================================*/
typedef struct
{
  IPCC_Client client;
  IPCC_Client to[2];
  IPCC_Signal  low;
  IPCC_Signal  high;  
  //uint32 mask; //Do we need this?
} ipcc_gic_sgi_intr_info_type;

/*===========================================================================
 *						        Functions
 *===========================================================================*/
 
void ipcc_gic_send_interrupt(uint8 vector, uint32 dest_cluster,uint32 cpu_mask, uint8 cpu);

#endif

