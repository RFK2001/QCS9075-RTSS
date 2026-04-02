/*
  ===========================================================================
*/
/**
  @file mailboxLib.h
  @brief export mailboxLib APIs
*/
/*
  ===========================================================================
  
  Copyright (c) Qualcomm Technologies Incorporated.
  All Rights Reserved.
  Qualcomm Confidential and Proprietary
  
  Export of this technology or software is regulated by the U.S. Government.
  Diversion contrary to U.S. law prohibited.
  
  All ideas, data and information contained in or disclosed by
  this document are confidential and proprietary information of
  Qualcomm Technologies Incorporated and all rights therein are expressly 
  reserved.
  By accepting this material the recipient agrees that this material
  and the information contained therein are held in confidence and in
  trust and will not be used, copied, reproduced in whole or in part,
  nor its contents revealed in any manner to others without the express
  written permission of Qualcomm Technologies Incorporated.
  
  ===========================================================================

  $Header: 
  $DateTime: 
  $Author:

  ===========================================================================
*/
/*
  ===========================================================================

  EDIT HISTORY FOR MODULE

  when       who      what, where, why
  --------   -------  -------------------------------------------------------
  03/07/23   rsargar  subrgn reset and improvement
  11/06/22   rsargar  lib update for chan cfg support and improvements
  
  ===========================================================================
*/

#ifndef MAILBOXLIB_H
#define MAILBOXLIB_H

#include "types.h"

#define MB_MAGIC_NUMBER			0x4D4C3130u 				//The magic number i.e mailbox lib version encoding
#define MB_NAME_SZ				16u 						//The buffer size which used to store mailbox name.
// add checks inside driver 
#define MB_MAX_SUB_REGION_NUM	100u  						//The maximum number of mailbox sub-region.
#define MB_MAX_ITEM_NUM			0x8000u 					//The maximum number of items in a mailbox sub-region.
#define MB_SUB_REGION_HEADER_SZ	sizeof(mbsub_rgn_desc_t) 	//The size of sub-region header.
#define MB_HEADER_SIZE			sizeof(mb_desc_t)   		//The size of mailbox header.
#define MB_MAX_SIZE				(0x100000)   				//The mailbox max size sanity check.

/* Mailbox client subsytem use the following value to understand SAIL programmed chan mode */
#define MB_LIB_OWNER			(1)	// library onwer  proc domain.
#define MB_LIB_CLIENT			(2)	// library client proc domain.
#define MB_LIB_TYPE				MB_LIB_OWNER // library type configuration SAIL => ONWER , X domain : CLIENT.
#define MB_CHAN_MAX_TYPE		(2U)// chan type max
#define MB_CHAN_RD_MODE			(0U)// otherdomain treats RD as WR	
#define MB_CHAN_WR_MODE			(1U)// otherdomain treats WR as RD	
#define MB_CHAN_UNK_MODE		(2U)// update dyanamic selection of mode 	
#define MB_PORT_RECDECL_SZ		(1U) // The size of mailbox header.
#define MB_DEFAULT_CHAN_OFFSET	(0U) // The defualt offset initialiser.
#define MB_DEFAULT_PRIORITY		(0U) // The defualt PRIO initialiser.
/* Mailbox lib error codes */
#define MB_E_SUCCESS			 0  //create or validate the mailbox successfully.
#define MB_E_NULL_INPUT			-11 //Some input pointer(s) is(are) NULL.
#define MB_E_INVALID_CFG		-22 //Input parameters used to create mailbox are unreasonable.
#define MB_E_INVALID_INDEX		-33 //Sub-region index is invalid.
#define MB_E_INVALID_MAILBOX	-44 //Mailbox is invalid which has not been created.
#define MB_E_NO_ENOUGH_BUF		-55 //Mailbox sub-region has no enough buffer to store input items.
#define MB_E_CORRUPT_MAILBOX	-66 //Mailbox is corrupt.
#define MB_E_TRIG				-88 //Mailbox trig failed.
#define MB_E_NOT_READY			-99 //Mailbox comm not ready.

/**
 * @brief structure which used to define the location of a sub-region by its start address offset and end address offset
 *
 */
typedef struct __attribute__((packed))
{
	uint32 sub_region_start_offset; //offset of mailbox sub-region start address.
	uint32 sub_region_end_offset;   //offset of mailbox sub-region end address.
} mbsub_rgn_area_t;

/**
 * @brief mailbox descriptor
 *
 * The structure defines the mailbox layout inside the share memory, which is shared betwwen the receiver and sender.
 * It is better to add pad manually instead of depending on the compiler if necessary.
 */
typedef struct __attribute__((packed))
{
	int8          		name[MB_NAME_SZ];   //Store mailbox name
	uint32         		magic;             	//Used to mark if mailbox has been created
	uint32         		mb_size;           	//The total size of the mailbox
	uint32         		mb_prio;           	//The main prio mailbox
	uint32         		num_of_sub_region; 	//The number of sub-region in the mailbox
	/* ptr portability and header sz memory adjust , OEM MAX support enabled bydefault */
	mbsub_rgn_area_t	sub_region[MB_PORT_RECDECL_SZ]; 	//The sub_region array is used to store the offset of each sub-region.
} mb_desc_t;

/**
 * @brief mailbox chan descriptor which used to get required info without affecting lib critical resources.
 *
 * The structure defines provides necessary chan info required in nonlib drv component, 
 * which is shared betwwen the receiver and sender.
 * It is better to add pad manually instead of depending on the compiler if necessary.
 */
typedef struct __attribute__((packed)) 
{
	int8   name[MB_NAME_SZ];    // Store mailbox sub-region node name
	uint32 sender; 			    //  sender IPCC cleint Id : genric across SoC : subsytem domain
	uint32 receiver; 			//  receiv IPCC cleint Id : genric across SoC : subsytem domain
	uint32 prot; 				//  mapped protocol instance 
	uint32 sig;   		        //  unique sig for Tx-Rx
	uint32 mode;   		   	    // 	This has specifc use at domain end SAIL treats mode = 1 =>WR; SAIL mode = 0 =>RD 
								// 	This has specifc use at domain end X domain treats mode = 1 =>RD; mode = 0 =>WR
								// 	This has specifc use within domain end
	uint32 prio;				//  channel priority 0: means default Max , 1 : Max -1 , 2: Max-2 so on upto max 65
	uint32 max_item_num;     	//  The maximum item number of the mailbox sub-region
	uint32 max_item_size;    	//  The maximum item size of the mailbox sub-region
} mbchan_desc_t;

/**
 * @brief mailbox sub-region descriptor which used to define a ring-buffer which used to store items.
 *
 * The structure defines the mailbox layout inside the share memory, which is shared betwwen the receiver and sender.
 * It is better to add pad manually instead of depending on the compiler if necessary.
 */
typedef struct __attribute__((packed)) 
{
	int8	 name[MB_NAME_SZ];  // Store mailbox sub-region node name
	uint32 	 sender; 			//  sender IPCC cleint Id : genric across SoC : subsytem domain
	uint32 	 receiver; 			//  receiv IPCC cleint Id : genric across SoC : subsytem domain
	uint32 	 prot; 				//  mapped protocol instance 
	uint32 	 sig;   		    //  unique sig for Tx-Rx
	uint32 	 mode;   			// 	This has specifc use at domain end SAIL treats mode = 1 =>WR; SAIL mode = 0 =>RD 
								// 	This has specifc use at domain end X domain treats mode = 1 =>RD; mode = 0 =>WR
								// 	This has specifc use within domain end
	uint32 	 prio;				//  channel priority 0: means default Max , 1 : Max -1 , 2: Max-2 so on upto max 65
	uint32   max_item_num;     	//  The maximum item number of the mailbox sub-region
	uint32   max_item_size;    	//  The maximum item size of the mailbox sub-region
	uint32   item_in_index;    	//  write index
	uint32   item_out_index;   	//  read index
} mbsub_rgn_desc_t;

/**
 * @brief It is the type of input parameter which used to create a mailbox.
 *
 */
typedef struct __attribute__((packed))
{
	int8	   	name[MB_NAME_SZ];  	// Store mailbox name
	uint32   	mb_size;          	// The total size of the mailbox
	uint32   	mb_prio;          	// The total size of the mailbox
	uint32   	num_sub_regions;  	// The number of sub-region in the mailbox
	uint32   	mblocator;  		// mb locator
} mbconfig_t;

/**
 * @brief It is the type of input parameter which used to create a mailbox.
 *
 */
typedef struct __attribute__((packed))
{
	int8    name[MB_NAME_SZ];   // Store mailbox sub-region name
	uint32  sender; 			// sender IPCC cleint Id : genric across SoC : subsytem domain
	uint32  receiver; 			// receiv IPCC cleint Id : genric across SoC : subsytem domain
	uint32  prot; 				// mapped protocol instance 
	uint32  sig;   				// unique sig for Tx-Rx
	uint32  mode;   			// This has specifc use at domain end SAIL treats mode = 1 =>WR; SAIL mode = 0 =>RD 
								// This has specifc use at domain end X domain treats mode = 1 =>RD; mode = 0 =>WR
								// This has specifc use within domain end
	uint32  prio;				// channel priority 0: means default Max , 1 : Max -1 , 2: Max-2 so on upto max 65
	uint32  start_addr_offset; 	// offset of sub-region start address.
	uint32  end_addr_offset;   	// offset of sub-region end address.
	uint32  item_max_num;      	// Sub-region maximum item number
	uint32  item_max_size;     	// Sub-region maximum item size
} mbsub_rgn_config_t;


/**
 * @brief Mailbox chan map init
 * 
 * The function is non-blocking, which is used to init map of mb chan with subregion_cfg[] provided by the user
 * chan max and min sz of transfer unit.
 *
 * @param[in] mb The pointer to a mailbox.
 * @param[in] mb_cfg The pointers to the configuration of mailbox
 * @param[in] subregion_cfg Configuration array which is used to store the configuration of sub-regions,
 *        subregion_cfg[0] is for sub-region 0, subregion_cfg[1] is for sub-region 1,etc.
 * 
 * @return If Create success return 0 else return negative error code.
 * @retval 0 Create mailbox successfully.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -22 Input Mailbox configurations are unreasonable.
 *
 */
int32 LibMB_ChanMapInit(const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[]);

/**
 * @brief Create a mailbox
 * 
 * The function is non-blocking, which is used to create a mailbox with info provided by the user.
 * The interface shall be called by the allocator/controller of the share memory.
 * The interface shall be called when the share memory is ready.
 *
 * @param[in] mb The pointer to a mailbox.
 * @param[in] mb_cfg The pointers to the configuration of mailbox
 * @param[in] subregion_cfg Configuration array which is used to store the configuration of sub-regions,
 *        subregion_cfg[0] is for sub-region 0, subregion_cfg[1] is for sub-region 1,etc.
 * 
 * @return If Create success return 0 else return negative error code.
 * @retval 0 Create mailbox successfully.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -22 Input Mailbox configurations are unreasonable.
 * @retval -66 Mailbox is corrupt.
 *
 */
int32 LibMB_Create(mb_desc_t *mb, const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[]);

/**
 * @brief Check if mailbox has been created
 *  
 * It is non-blocking and both the sender and receiver of mailbox can call it to
 * check if mailbox has been created and if mailbox versions are matched between users.
 *
 * @param[in] mb The pointer to a mailbox
 *
 * @return If validate success return 0 else return negative error code.
 * @retval 0 The mailbox has been created.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -44 Mailbox has not been created.
 * @retval -77 Mailbox versions are not matched.
 * 
 */
int32 LibMB_Validate(const mb_desc_t *mb);

/**
 * @brief Write items into a mailbox sub-region.
 * 
 * The interface is non-blocking, which is used to write items into the region assigned
 * by caller.The interface won't write any items and return a negative error code when
 * the mailbox sub-region has not enough free buffer. The user should call it when the
 * mailbox has been created.
 *
 * If the interface is called by different threads, the caller shall be responsible 
 * for the sync mechanism.The mailbox user shall notify the receiver after writing
 * items into mailbox.
 * 
 * @param[in] mb The pointer to the mailbox.
 * @param[in] source_item_buf The pointers to the item source buffer.
 * @param[in] item_num The number of items written into the sub-region.
 * @param[in] sub_region_index The index of sub-region.
 * 
 * @return If write success return value is item_num else return negative error code.
 * @retval item_num Wite items into mailbox success.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -33 Invalid sub-region index.
 * @retval -44 Mailbox has not been created.
 * @retval -55 Mailbox has not enough free buffer.
 * @retval -66 Mailbox is corrupt.
 * 
 */
int32 LibMB_Write(mb_desc_t *mb, const void *source_item_buf, uint32 item_num, uint32 sub_region_index);

/**
 * @brief Read items from a mailbox sub-region.
 * 
 * The interface is non-blocking, which is used to read items from the region 
 * assigned by caller.The user should use it when the mailbox has been created.
 *
 * If the interface is called by different threads, the caller shall be responsible 
 * for the sync mechanism.
 * 
 * @param[in] mb The pointer to the mailbox.
 * @param[out] destination_item_buf The pointers to the item destination buffer.
 * @param[in] item_num The number of items hope to read from the sub-region.
 * @param[in] sub_region_index The index of sub-region.
 * 
 * @return If read success return the actual item number read from mailbox else 
 *		  return negative error code.If the sub-region is empty return 0.
 * @retval actual_item_num Wite items into mailbox success.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -33 Invalid sub-region index.
 * @retval -44 Mailbox has not been created.
 * @retval -66 Mailbox is corrupt.
 * 
 */
int32 LibMB_Read(mb_desc_t *mb, void *destination_item_buf, uint32 item_num, uint32 sub_region_index);

/**
 * @brief Get the number of free items from a mailbox sub-region
 * 
 * The interface is non-blocking, which is used to get the number of free items from 
 * a mailbox sub-region assigned by the user. The user shall use the interface when
 * mailbox has been created.
 *
 * @param[in] mb The pointer to the mailbox.
 * @param[in] sub_region_index The index of sub-region.
 * 
 * @return if get the number of free items success return the item number, else 
 *         return negative error code.
 * @retval item_num Get the number of free items success
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -33 Invalid sub-region index.
 * @retval -44 Mailbox has not been created.
 * @retval -66 Mailbox is corrupt.
 * 
 */
int32 LibMB_Get_FreeItemNum(const mb_desc_t *mb, uint32 sub_region_index);


/**
 * @brief Get the number of valid items from a mailbox sub-region
 * 
 * The interface is non-blocking, which is used to get the number of valid items  
 * from a mailbox sub-region assigned by the user. The user shall use the interface 
 * when mailbox has been created.
 *
 * @param[in] mb The pointer to the mailbox.
 * @param[in] sub_region_index The index of sub-region.
 * @return if get the number of valid items success return the item number, else 
 *         return negative error code.
 * @retval item_num Get the number of valid items success
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -33 Invalid sub-region index.
 * @retval -44 Mailbox has not been created.
 * @retval -66 Mailbox is corrupt.
 * 
 */
int32 LibMB_Get_ValidItemNum(const mb_desc_t *mb, uint32 sub_region_index);

/**
 * @brief Get the chan info
 * 
 * The interface is non-blocking, which is used to get the chan info
 * from a mailbox sub-region assigned by the user. The user shall use the interface 
 * when mailbox has been created.
 *
 * @param[in] mb The pointer to the mailbox.
 * @param[in] sub_region_index The index of sub-region.
 * @param[out] chan info .
 * @retval 0 success
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -33 Invalid sub-region index.
 * @retval -44 Mailbox has not been created.
 * @retval -66 Mailbox is corrupt.
 */
int32 LibMB_Get_ChanInfo(const mb_desc_t *mb, uint32 sub_region_index, mbchan_desc_t* chaninfo);

/**
 * @brief An internal function which used to reset software mailbox subchannel of the mailbox
 *			used by entity has cfg onwership.
 *
 * @param mb The pointer to a mailbox.
 * @param subregion_cfg The configuration array which is used to store.
 *        the configuration of all sub-regions.
 * @param schan The configuration array subregion index.
 * 
 * @retval true reset subchannel.
 * @retval false reset subchannel fail.
 *
 */
bool LibMB_ChanReset( mb_desc_t *mb, const mbsub_rgn_config_t subregion_cfg[], const uint32 schan);

void libmbcopy_bytes(void *dest, const void *src, uint32 byte_num);

#endif /* MAILBOXLIB_H */
/*============================================================================*/

