/*==============================================================================

FILE:      NOC_error_target.c

DESCRIPTION: This file implements NOC Error handler target specific features.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
    Copyright (c) 2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.
==============================================================================*/
#include "NOC_error.h"
#include "debug_log.h"
#include "chipinfo.h"
#include "HALhwio.h"
//#include "fusa.h"
//#include "noc_report_hwio.h"
#include "Clock.h"
#include "busywait.h"


/*============================================================================
                          DEFINEs
============================================================================*/
#define OPC_SHFT 4
#define OPC_MASK 0x7
#define ERRCODE_SHFT 8
#define ERRCODE_MASK 0x7

#define BIST_AGGREGID_SHFT 8
#define BIST_AGGREGID_MASK 0x1F
#define BIST_START_SHFT 0
#define BIST_STOP_SHFT 1

#define BIST_STATUS_BISTFLT_SHFT 3
#define BIST_STATUS_DONE_SHFT 2
#define BIST_STATUS_UFLT_SHFT 1
#define BIST_STATUS_CFLT_SHFT 0

/*============================================================================
                          MACROs
============================================================================*/
#define inputdw(addr) (*((volatile uint32_t*)(addr)))

#define NOC_OUT8(addr, data)   (*((volatile uint8_t *) (addr)) = ((uint8_t) (data)))
#define NOC_OUT16(addr, data)  (*((volatile uint16_t *) (addr)) = ((uint16_t) (data)))
#define NOC_OUT32(addr, data)  (*((volatile uint32_t *) (addr)) = ((uint32_t) (data)))

#define NOC_IN8(addr)   ((uint8_t) (*((volatile uint8_t *) (addr))))
#define NOC_IN16(addr)  ((uin16) (*((volatile uint16_t *) (addr))))
#define NOC_IN32(addr)  ((uint32_t)(*((volatile uint32_t *) (addr))))

#define NOC_REG_ADDR(base,offset)   (((uint8_t*)(base)) + (offset))

#define REGISTER_VALID(offs) ((offs)!=REGISTER_NOT_APPLICABLE)

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

#define FAULTINSTATUS0_LOW_FILTER_MASK 		0x1U
#define FAULTINSTATUS0_HIGH_FILTER_MASK 	0x80U

/*============================================================================
                          STRUCTURE DECLARATIONS
============================================================================*/


/*============================================================================
                           DATA
============================================================================*/
static bool faulted = false;
static bool is_auto = false;


/*============================================================================
                           FUNCTION PROTOTYPES
============================================================================*/

/*============================================================================
                            EXTERNAL FUNCTIONS
============================================================================*/
#if 0
void NOC_Error_Init_Target
(
  NOCERR_info_type *    noc_info,
  uint32_t              noc_cnt,
  NOCERR_info_type_oem* noc_info_oem
)
{
	  (void)noc_info;
	  (void)noc_info_oem;
	  (void)noc_info_oem;

  bool BIST_fail = false;
  uint32_t BIST_countdown;
  uint32_t i = 0,j = 0,n = 0;

    is_auto = true;

  /* Spin for connect */
  //while(hang){}

  DEBUG_LOG(SAIL_INFO,"NOC BIST STARTED \n\r");

  /* Run the Built In Self Test (BIST) of the NOC saftey aggregators */
  for( n=0; (n < noc_cnt) && (BIST_fail == false); n++ )
  {
    for( i=0; (i < noc_info[n].num_sfty_ctl) && (BIST_fail == false); i++ )
    {
      /* Assert no interrupts for the BIST faults or done */
      NOC_OUT32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], 
                             noc_info[n].sfty_ctl_hw[i]->outen_low), 0x0);

      for( j=0; (j < noc_info[n].num_sfty_aggs[i]) && (BIST_fail == false); j++ )
      {
        uint32_t status;
        /* 3. Set aggregid, and stop the BIST */
        NOC_OUT32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], 
                               noc_info[n].sfty_ctl_hw[i]->bistctl_low), 
                               (1<<BIST_STOP_SHFT) | (noc_info[n].sfty_aggs[i][j].aggregid << BIST_AGGREGID_SHFT) );
        /* 4. Verify it is properly DONE */
        if( (1<<BIST_STATUS_DONE_SHFT) &  NOC_IN32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], 
                                                   noc_info[n].sfty_ctl_hw[i]->status_low)) )
        {
          /* Failure */
          BIST_fail = true;
          break;
        }
        /* 5. Start the BIST */
        NOC_OUT32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], 
                               noc_info[n].sfty_ctl_hw[i]->bistctl_low), 
                               (1<<BIST_START_SHFT) | (noc_info[n].sfty_aggs[i][j].aggregid << BIST_AGGREGID_SHFT) );

        /* 6. Wait for Done */
        for(BIST_countdown = 1000; 
            (BIST_countdown > 0 ) && 
            ( 0 == ((1<<BIST_STATUS_DONE_SHFT) &  NOC_IN32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], noc_info[n].sfty_ctl_hw[i]->status_low))));
            BIST_countdown--)
        {
          busywait(100);
        }
        if( BIST_countdown == 0)
        {
          BIST_fail = true;
          break;
        }
        
        status = NOC_IN32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], noc_info[n].sfty_ctl_hw[i]->status_low));
        if(status != ((1<<BIST_STATUS_DONE_SHFT) | (1<<BIST_STATUS_UFLT_SHFT) | (1<<BIST_STATUS_CFLT_SHFT)))
        {
          BIST_fail = true;
          break;
        }

        /* Turn BIST to off */
        NOC_OUT32(NOC_REG_ADDR(noc_info[n].sfty_ctl_addrs[i], 
                               noc_info[n].sfty_ctl_hw[i]->bistctl_low), 
                               (1<<BIST_STOP_SHFT) | (noc_info[n].sfty_aggs[i][j].aggregid << BIST_AGGREGID_SHFT) );

      }
    }
  }

  
  if((true == BIST_fail))
  {
    DEBUG_LOG(SAIL_ERROR,"NOC BIST failure noc %n, sfty_ctl %n, sfty_agg %n  \n\r", n,i,j);
  }
  else
  {
    DEBUG_LOG(SAIL_INFO,"NOC BIST SUCCESS \n\r");
  }



}

bool NOC_Error_Handle_Target
(
  NOCERR_info_type *    noc_info,
  NOCERR_info_type_oem* noc_info_oem,
  bool                 *delay_crash
)

{

  (void)noc_info;
  (void)noc_info_oem;
  (void)delay_crash;
#if 0
  if(NULL != delay_crash)
  {
    *delay_crash = false;
  }


  /* Report errors to SMSS, but only if we're an auto SKU */
  if( is_auto )
  {
    /* Fault severity is dictated by whether or not we consider the error fatal. */
    safety_fault_severity severity;
    if( noc_info_oem->error_fatal )
    {
      severity = SAFETY_SOC_FATAL_ERROR;
    }
    /* Don't notify on non fatal errors. */
    else
    {
      return true;
    }

    /* Detect which NoC we are reporting for.
     * If we don't detect one, set to max and report anyways.
     * Better to send something than to send nothing. */
    safety_fault_noc_source source = NOC_SOURCE_MAX;
    switch( (uintptr_t)noc_info->base_addr )
    {
      case (uintptr_t)HWIO_ADDR(AGGRE_NOC_AGGRE_NOC_MAIN_A1NOC_ERRORLOGGER_ERL_SWID_LOW):
        source = NOC_SOURCE_AGGRE1_NOC;
        break;
      case (uintptr_t)HWIO_ADDR(AGGRE_NOC_AGGRE_NOC_MAIN_A2NOC_ERRORLOGGER_ERL_SWID_LOW):
        source = NOC_SOURCE_AGGRE2_NOC;
        break;
      default:
        break;
    }
    
    /* Set the other fields based on the recorded error.
     * Error code, address(36 bits), path, and opcode. */
    safety_fault_noc_code code;
    if( 0 != noc_info->syndrome.ERRLOG0_LOW )
    {
      code = (noc_info->syndrome.ERRLOG0_LOW >> ERRCODE_SHFT) & ERRCODE_MASK;
    }
    /* Check for Safety faults. */
    else
    {
      bool found = false;
      for( int32_t i = 0; i < noc_info->num_sfty_ctl; i++ )
      {
        if( noc_info->syndrome.sfty_ctl->STATUS_LOW & 0x2 )
        {
          found = true;
        }
      }

      /* Report safety fault. */
      if( found )
      {
        code = ECC_UNCORRECTABLE_FAULT;
      }
      /* Must be something else. */
      else
      {
        code = OTHER_FAULT;
      }
    }
#endif 

  return true;
}
#endif
/* vim: set ts=2 sts=2 sw=2 et :*/ 
