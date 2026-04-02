/**********************************************************************************************************
** Copyright (c) 2021 Qualcomm Technologies, Inc.                                                        **
** All Rights Reserved.                                                                                  **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                            **
**********************************************************************************************************/

 /*========================================================================================================
    File Name          : Crashdbg_dcc_hal.c
    Component Name     : SAIL CRASH DEBUG DCC Target API
    Description        : This module defines all target specific interfaces exposed by the DCC driver.
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/src/sailhyp/Crashdbg_dcc_hal.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $
 ========================================================================================================*/
/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "HALhwio.h"
#include "hw_io.h"
#include "Crashdbg.h"
#include "Crashdbg_dcc_hal.h"
#include "saildbg_dcc_hwio.h"
#include "common_functions.h"

/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
/* Max number of linked lists supported by HW */
#define DCC_LL_COUNT      			(HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_BASEm_MAXm)

/* DCC SRAM size used for Linked Lists */
#define DCC_SRAM_SIZE               (0x10000)//ToDO- For now, 64KB. In APSS, it was 96KB but why?. This size will have impact on DCC SRAM zero init time.

/* DCC SRAM address mask */
#define DCC_SRAM_ADDRMASK           (0xFFFF) //Address mask value must be within the above DCC_SRAM_SIZE
/*=========================================================================================================
**                          Internal Functions												             **
==========================================================================================================*/

/*=========================================================================================================
**                          Function Definitions - Sail Crash Debug DCC Target API  		              **
==========================================================================================================*/
/*===========================================================================
**  HAL_DCC_GET_MAX_LISTS
** ==========================================================================
*/
/*!
*
* @brief
*   Return the max. number of lists supported by this version of DCC
*
* @param[in]
*   None
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
uint32 hal_dcc_get_max_lists(void)
{
  return DCC_LL_COUNT;
}



/*===========================================================================
**  HAL_DCC_CONFIG_LIST_BASE
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the list base address within a chosen sink
*
* @param[in]
*   List index and offset of the list within the sink
*
* @par Dependencies
*   Sink not chosen by this
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_config_list_base(uint32 list, uint32 base)
{
  /* Program the start address of the linked list */
  /* Allows SW to establish the Link List SRAM memory location where the first LL descriptor is located */
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_BASEm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_BASEm_ADDRESS_BMSK,
			 ((base+WORD_INDEX(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_RAM_REG_BASE)) <<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_BASEm_ADDRESS_SHFT));
}

/*===========================================================================
**  HAL_DCC_CONFIG_DATA_BASE
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the data base address within a chosen sink
*
* @param[in]
*   List index and offset of the data within the sink
*
* @par Dependencies
*   Sink not chosen by this
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*hal_dcc_config_data_base
*/
void hal_dcc_config_data_base(uint32 list, uint32 base)
{
  /* Program the address to put the fetched data in */
  /* Allows SW to establish the Link List SRAM memory location where the first LL fetched data is located */
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_FD_BASEm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_FD_BASEm_ADDRESS_BMSK,
			 ((base+WORD_INDEX(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_RAM_REG_BASE))<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_FD_BASEm_ADDRESS_SHFT));
}

/*===========================================================================
**  HAL_DCC_CONFIG_TIMEOUT
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the timeout for a given list execution
*
* @param[in]
*   List index and timeout value
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_config_timeout(uint32 list, uint32 timeout)
{
  /* Allows SW to establish a limit to the time that the associated Link List can execute.
	 Note: this timer runs on XO clock */	
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_TIMEOUTm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_TIMEOUTm_VALUE_BMSK,
			 (timeout<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_TIMEOUTm_VALUE_SHFT));
}

/*===========================================================================
**  HAL_DCC_CONFIG_TRANS_TIMEOUT
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the timeout for a given link execution
*
* @param[in]
*   List index and timeout value
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_config_trans_timeout(uint32 list, uint32 timeout)
{
  /* Allows SW to configure timeout for a Link transaction */
  /* If timeout occurs on a read operation , signature "A5A5A5A5" will be written into SRAM , where the actual fetched data to be written. 
  In case of timeout on write operation, signature won't be written but DMA controller will move to wait_ack state to accept the next link from the list */  
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_TRANS_TIMEOUTm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_TRANS_TIMEOUTm_VALUE_BMSK,
			 (timeout<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_TRANS_TIMEOUTm_VALUE_SHFT));
}


/*===========================================================================
**  HAL_DCC_CONFIG_SINK
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the sink type
*
* @param[in]
*   List index and sink index
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/

void hal_dcc_config_sink(uint32 list, uint32 sink)
{
  /* Sink determines where the fetched data will be stored. 0 - SRAM, 1 -TPDM */	
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_SINK_BMSK,
			 (sink<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_SINK_SHFT));
}


/*===========================================================================
**  HAL_DCC_CONFIG_TRIGGER
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the trigger for Link list processing
*
* @param[in]
*   List index and trigger type
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/

void hal_dcc_config_trigger(uint32 list, hal_dcc_trig_type trigger)
{
  /* Enables the Hard-Wired trigger input to start LL processing */
  /* 0x1 - Enabled, 0x0 -Disabled */  
  if (HAL_DCC_HW_TRIGGER == trigger)
    HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm,
			   list,
			   HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_HW_TRIGGER_EN_BMSK,
			   (0x1<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_HW_TRIGGER_EN_SHFT));
}

/*===========================================================================
**  HAL_DCC_CONFIG_FUNC
** ==========================================================================
*/
/*!
*
* @brief
*   Configure the function to be performed by DCC i.e Data Capture or CRC
*
* @param[in]
*   List index and function
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/


void hal_dcc_config_func(uint32 list, uint32 func)
{
  /* Determines what type of function the DCC will perform.	1 = CRC will be performed on fetched data, 0 = Data will be stored in the specified sink */
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_FUNC_BMSK,
			 (func<<HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_FUNC_SHFT));
}

/*===========================================================================
**  HAL_DCC_LOCK_LIST
** ==========================================================================
*/
/*!
*
* @brief
*   Lock a list before configuration
*
* @param[in]
*   List index and sink index
*
* @par Dependencies
*   ONLY qualified hosts i.e TZ can set S bit when fuses are in proper state.
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_lock_list(uint32 list)
{
  HWIO_OUTI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm,
			list,
			(HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm_ACTIVE_BMSK | 
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm_S_BIT_BMSK));
}

/*===========================================================================
**  HAL_DCC_LOCK_LIST_NS
** ==========================================================================
*/
/*!
*
* @brief
*   Lock a list before configuration with NS attributes
*
* @param[in]
*   List index and sink index
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_lock_list_ns(uint32 list)
{
  /* To lock the ownership of the associated Linked List */
  /* ToDO- TBC- As of now, we do DCC Init as part of SAIL HYP and let it be NS */  
  HWIO_OUTI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm,
			list,
			HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm_ACTIVE_BMSK);
}

/*===========================================================================
**  HAL_DCC_UNLOCK_LIST
** ==========================================================================
*/
/*!
*
* @brief
*   Unlock a list before configuration
*
* @param[in]
*   List index and sink index
*
* @par Dependencies
*   None
*
* @retval
*   None
*
* @par Side Effects
*   None
*
*
*/
void hal_dcc_unlock_list(uint32 list)
{
  /* Field "ACTIVE" -> 0 = Linked List is open and new owner can use associated LL */	
  HWIO_OUTMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm,
			 list,
			 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm_ACTIVE_BMSK,
			 0);
}

/*===========================================================================
**  HAL_DCC_IS_LIST_LOCKED
** ==========================================================================
*/
/*!
*
* @brief
*   API to check if the list is locked
*
* @param[in]
*   List index
*
* @par Dependencies
*   None
*
* @retval
*   1 for locked, 0 for unlocked
*
* @par Side Effects
*   None
*
*
*/
boolean hal_dcc_is_list_locked(uint32 list)
{
  return HWIO_INMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm,
				   list,
				   HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_LOCKm_ACTIVE_BMSK);
}

/*===========================================================================
**  HAL_DCC_GET_SINK
** ==========================================================================
*/
/*!
*
* @brief
*   API to retrieve the sink for a list
*
* @param[in]
*   List index
*
* @par Dependencies
*   None
*
* @retval
*   hal_dcc_sink_type return value
*
* @par Side Effects
*   None
*
*
*/
hal_dcc_sink_type hal_dcc_get_sink(uint32 list)
{
  return ((hal_dcc_sink_type)HWIO_INMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm,
									   list,
									   HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_LL_CONFIGm_SINK_BMSK));
}

/*===========================================================================
**  HAL_DCC_GET_DATA_BASE
** ==========================================================================
*/
/*!
*
* @brief
*   API to retrieve the sink's base address within a sink
*
* @param[in]
*   List index
*
* @par Dependencies
*   None
*
* @retval
*   hex number return value
*
* @par Side Effects
*   None
*
*
*/
uint32 hal_dcc_get_database(uint32 list)
{
  return ((BYTE_INDEX((HWIO_INMI(SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_FD_BASEm,
								 list,
								 HWIO_SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_FD_BASEm_ADDRESS_BMSK))) + 
		   DCC_SRAM_SIZE) &
     	  (DCC_SRAM_ADDRMASK));
}

/*===========================================================================
**  HAL_DCC_CONFIG_LIST
** ==========================================================================
*/
/*!
*
* @brief
*   API to program the parameters of a list in one shot
*
* @param[in]
*   List index and pointer to hal params
*
* @par Dependencies
*   None
*
* @retval
*   hal_dcc_sink_type return value
*
* @par Side Effects
*   None
*
*
*/

boolean hal_dcc_config_list(uint32 idx, hal_dcc_list_params_type *params)
{

  boolean success = FALSE;

  if (params)
  {
    /* ToDO - TBC - SAIL HYP Security requirement, as we do DCC Init as part of SAIL HYP */
	/* Lock the list */
    hal_dcc_lock_list_ns(idx);

    /* Check for lock status */
	/* ToDo - add log if possible */
    if (!hal_dcc_is_list_locked(idx))
      return success;

    /* Configure all parameters of the list */
    hal_dcc_config_sink(idx, params->esink);

    hal_dcc_config_timeout(idx, params->ntimeout);

    hal_dcc_config_trans_timeout(idx, params->ntranstimeout);

    hal_dcc_config_data_base(idx, WORD_INDEX(ALIGN_ADDR(params->noffset, 16)));

    hal_dcc_config_func(idx, params->efunc);

    hal_dcc_config_trigger(idx, params->etrigger);

    success = TRUE;
  }

  return success;
}


/*===========================================================================
**  HAL_DCC_GET_SINKBASE
** ==========================================================================
*/
/*!
*
* @brief
*   Return the sink's base address as per system memorymap
*
* @param[in]
*   Sink type
*
* @par Dependencies
*   None
*
* @retval
*
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
uint64 hal_dcc_get_sinkbase(hal_dcc_sink_type sink)
{

  switch (sink)
  {
    case HAL_DCC_SINK_SRAM:
      return SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_RAM_REG_BASE;
      break;

    default:
      return (uint64)0ULL;

   }
}

/*===========================================================================
**  HAL_DCC_INIT_SINK
** ==========================================================================
*/
/*!
*
* @brief
*   Initialize a given sink for use by DCC driver
*
* @param[in]
*   Sink type
*
* @par Dependencies
*   None
*
* @retval
*  Success or Fail
*
* @par Side Effects
*   Mainly used to check against this value
*
*
*/
boolean hal_dcc_init_sink(hal_dcc_sink_type sink)
{
  /* Get the base address for this sink */
  static boolean init = FALSE;

  if (!init)
  {
    volatile uint64 *base = (uint64 *)((uintptr_t)(hal_dcc_get_sinkbase(sink)));

    if (base)
    {
      for (uint32 count = DCC_SRAM_SIZE; count > 0; count-=sizeof(uint64))
        *(base++) = 0L;
    }

    init = TRUE;
  }

  return init;
}

/*===========================================================================
**  HAL_DCC_PROGRAM_LIST
** ==========================================================================
*/
/*!
*
* @brief
*   API to program the actual list into a DCC sink
*
* @param[in]
*   List data, list index, offset within sink and size
*
* @par Dependencies
*   None
*
* @retval
*   hal_dcc_sink_type return value
*
* @par Side Effects
*   None
*
*
*/

boolean hal_dcc_program_list(void *list, uint32 list_idx, uint32 offset, uint32 size)
{

  boolean success = FALSE;

  if (offset & DCC_SRAM_SIZE)
     return success;

  uint32 aligned_offset = ALIGN_ADDR(offset, 16);

  /* Program the actual linked list based on the sink */
  hal_dcc_sink_type sink = hal_dcc_get_sink(list_idx);
  if (sink == HAL_DCC_SINK_SRAM)
  {
    if (offset & DCC_SRAM_SIZE)
      return success;
    else
      sailbsp_memscpy((void *)(uintptr_t)(aligned_offset + SAILSS_DBG_SAILSS_DBG_QDSS_DCC_DCC_RAM_REG_BASE), size, list, size);
  }
  
  /* Now point the memory to the list */
  hal_dcc_config_list_base(list_idx, WORD_INDEX(ALIGN_ADDR(offset, 16)));

  success = TRUE;

  return success;

}
/**********************************************************************************************************
**                                  End of file Crashdbg_dcc_hal                                         **
**********************************************************************************************************/



