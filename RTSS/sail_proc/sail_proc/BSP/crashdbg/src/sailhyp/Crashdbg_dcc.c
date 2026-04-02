/**********************************************************************************************************
** Copyright (c) 2021 Qualcomm Technologies, Inc.                                                        **
** All Rights Reserved.                                                                                  **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                            **
**********************************************************************************************************/

 /*========================================================================================================
    File Name          : Crashdbg_dcc.c
    Component Name     : SAIL CRASH DEBUG DCC driver API
    Description        : This module defines all interfaces exposed by the DCC driver.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/src/sailhyp/Crashdbg_dcc.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
 ========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "Crashdbg.h"
#include "Crashdbg_dcc.h"
#include "Crashdbg_dcc_hal.h"
#include "common_functions.h"

/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/

/*=========================================================================================================
**                          Internal Functions												              **
==========================================================================================================*/

/*=========================================================================================================
**                          External Functions												              **
==========================================================================================================*/
extern const dcc_config_type *dcc_get_config(void);
extern const dcc_ll_config_type *dcc_get_ll_config(uint32);
extern const uint32 dcc_get_ll_cnt(void);

/*=========================================================================================================
**                          Function Definitions                 						                  **
==========================================================================================================*/
/*===========================================================================
**  Function :  CrashdbgDCCTargetInit
** ==========================================================================
*/
/*!
*
* @brief : DCC Target Init to program the linked list based on DCC configuration
* @param : None
* @Dependencies :
* @retval : boolean [out] - 0:Init Failed, 1:Init Success
* @Side Effects : None
*
*/
static boolean CrashdbgDCCTargetInit(void)
{
   uint32 index = 0;
   hal_dcc_list_params_type params = {0};
   boolean success = FALSE;
   uint8 tmp_initsts = 0; //ToDo- For debug only. This shall be removed after adding logs

   /* ToDO - TBC - All clocks and necessary init at the system level is done already at the top level */
   const dcc_config_type *dcc_config = dcc_get_config();
   
   /* Get the size */
   const uint32 count = dcc_get_ll_cnt();

   if (dcc_config->dcc_en)
   {

     for (index = 0 ; index < count; index++)
     {         
          /* Get all the linked list configuration */
          const dcc_ll_config_type *dcc_ll_config = dcc_get_ll_config(index);
		  
          /* DCC enabled but null data is a failure scenario */
          if (!dcc_ll_config)
             return FALSE;
          else
          {
             /* Linked list index obtain */
             uint32 idx = dcc_ll_config->ll_idx;

             /* Check the index */
             if (idx > hal_dcc_get_max_lists())
			 {
				tmp_initsts = 1;			  
                //ToDO - SYSDBG_ERR_FATAL("DCC List index invalid", idx, 0, 0);
             }

             /* Configure the LL to be active. If already active, that's a failure. */
             if (hal_dcc_is_list_locked(idx))
			 {
				tmp_initsts = 2;
				//ToDO - SYSDBG_ERR_FATAL("DCC List Locked", idx, 0, 0);
             }

             /* Enable timeout */
             if (dcc_ll_config->ll_timeout_en)
               params.ntimeout = dcc_ll_config->ll_timeout;

             /* Enable per-transaction timeout */
             if (dcc_ll_config->llt_timeout_en)
               params.ntranstimeout = dcc_ll_config->llt_timeout;
             
             /* Configure the sink type */
             if (dcc_config->sink == DCC_SINK_SRAM)
               params.esink = HAL_DCC_SINK_SRAM;
             //else
             //  params.esink = HAL_DCC_SINK_ETB; //ETB config is not supported yet

             /* Initialize the memory */
             if (!hal_dcc_init_sink(params.esink))
               return success;

             /* Choose the trigger */
             switch (dcc_ll_config->ll_trigger)
             {
               case DCC_TRIGGER_SCANDUMP:
               case DCC_TRIGGER_WINDDOWN:
                  params.etrigger = HAL_DCC_HW_TRIGGER;
                  break;
               
               default:
                  break;
             }

             /* Program the address to put the fetched data in */
             params.noffset = dcc_ll_config->ll_fd_offset;
             params.efunc = HAL_DCC_FUNC_REG_CAPTURE;

             /* Configure all the list params */
             if (!hal_dcc_config_list(idx, &params))
                return success;

             /* Program the actual linked list */
             if (!hal_dcc_program_list((void *)dcc_ll_config->ll, idx, dcc_ll_config->ll_offset, dcc_ll_config->ll_size))
                return success;


          }
      }
    /* Done. Init */
    success = TRUE;
   }
   else {
      /* Not fatal at the moment if DCC is disabled for boot processor. Add log here */
      success = TRUE;
   }
   
   return success;
}

/*===========================================================================
**  Function :  CrashdbgDCCRetrievePC
** ==========================================================================
*/
/*!
*
* @brief : Top Level function to retrieve PC information when entering debug flow
* @param : core [in] Active core info
* @Dependencies : None
* @retval : boolean [out] - 0:Init Failed, 1:Init Success
* @Side Effects : Depends on static information being configured correctly.
*
*/ 
//ToDo - fFunction Not used -  Can be added for SAIL if needed?
uint64 CrashdbgDCCRetrievePC(uint32 core)
{
  #define PC_BMSK  (((uint64)1<<56) - 1) 

  uint64 pc = 0; void *pc_addr;

  const dcc_config_type *dcc_config = dcc_get_config();

  dcc_sram_cfg_type sram_cfg = {0};

  if ((core < dcc_config->pc_count) && (CrashdbgDCCRetrieveCfg(dcc_config->pc_trigger, &sram_cfg)))
  {
    pc_addr = ((void *)(uintptr_t)(sram_cfg.start_addr + dcc_config->pc_offset + (core * dcc_config->pc_size)));
    sailbsp_memscpy((void *)&pc, dcc_config->pc_size, pc_addr, dcc_config->pc_size);
    /* Don't mask any bits as top level software needs 
       to make use of the other bits in the captured values */
  }
  return pc;
}

/*===========================================================================
**  Function: CrashdbgDCCRetrieveCfg
** ==========================================================================
*/
/*!
* 
* @brief
* Top Level function to retrieve DCC SRAM start address and size for a particular
* list based on trigger
*
* @param[in] 
* Trigger used for the DCC linked list. 
*  
* @par Dependencies
* None
* 
* @retval
*   None
* 
* @par Side Effects
* Must be called only after global struct is initialized
*/

boolean CrashdbgDCCRetrieveCfg(dcc_trigger_type trigger, dcc_sram_cfg_type *cfg)
{
   boolean success = FALSE;
   /* Sanity checks */
   if (!cfg)
      return success;
   else 
   {

      /* ToDo All clocks and necessary init at the system level is done already at the top level */
      const dcc_config_type *dcc_config = dcc_get_config();

      /* If not enabled, the config is not used. */
      if (!dcc_config->dcc_en)
          return success;

      /* Get the size */
      const uint32 count = dcc_get_ll_cnt();

      for (uint32 index = 0 ; index < count; index++)
      {
          const dcc_ll_config_type *dcc_ll_config = dcc_get_ll_config(index);

          if (dcc_ll_config->ll_trigger == trigger)
          {
              cfg->start_addr = hal_dcc_get_sinkbase(hal_dcc_get_sink(index)) + hal_dcc_get_database(dcc_ll_config->ll_idx);
              cfg->size       = dcc_ll_config->ll_fd_size;
              success = TRUE;
              break;
          }
      }

      return success;
   }
        
}


/*===========================================================================
**  Function: CrashdbgDCCInit
** ==========================================================================
*/
/*!
* 
* @brief
* Top Level Function which performs DCC initialization
*
* @param[in] 
* None
*  
* @par Dependencies
* None
* 
* @retval
*   None
* 
* @par Side Effects
* Must be called only after global struct is initialized
*/
boolean CrashdbgDCCInit(void)
{
  boolean status = FALSE;
  /* ToDo -  Grab OS Lock here if needed */

  /* Perform DCC Target HW Init */
  status = CrashdbgDCCTargetInit();

  /* ToDo - Relinquish Lock */

  return status;
}
/**********************************************************************************************************
**                                  End of file Crashdbg_dcc                                             **
**********************************************************************************************************/



