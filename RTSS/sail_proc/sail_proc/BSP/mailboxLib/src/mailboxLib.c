/*
  ===========================================================================
*/
/**
  @file mailboxLib.c
  @brief implements mailboxLib routines
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

#include "mailboxLib.h"
#include <stdbool.h>

#include <stdlib.h>

/**
 * @brief An internal function whcih used to get the
 *        number of valid items from a mailbox sub-region.
 *
 * @param base The pointer to a mailbox sub-region.
 *
 * @return The number of valid items.
 * 
 */
static uint32 LibMB_Valid_Item(const mbsub_rgn_desc_t *base)
{
	uint32 valid_num = 0;
	uint32 write_index = base->item_in_index;
	uint32 read_index = base->item_out_index;
	if(write_index >= read_index)
	{
		valid_num = write_index - read_index;
	}
	else
	{
		valid_num = base->max_item_num - read_index + write_index;
	}

	return valid_num;
}

/**
 * @brief An internal function which used to get the number
 *        of free items from a mailbox sub-region.
 *
 * @param base The pointer to a mailbox sub-region.
 *
 * @return The number of free items.
 * 
 */
static uint32 LibMB_Free_Item(const mbsub_rgn_desc_t *base)
{
	uint32 free_num = 0;
	uint32 write_index = base->item_in_index;
	uint32 read_index = base->item_out_index;
	if(write_index >= read_index)
	{
		free_num = base->max_item_num - write_index + read_index;
	}
	else
	{
		free_num = read_index - write_index;
	}
	/* 
	 when the write index equals to the read index, there exist two cases, the ring-buffer is 
	 full or the ring-buffer is empty.Here reserve an item, then the write index won't catch 
	 the read index when write a mailbox,but read index can catch the write index when read a 
	 mailbox. so if the write index equals to the read index, there exist only one case that 
	 the sub-region ring buffer is empty.
	 */
	free_num = free_num - 1u;
	return free_num;
}

/**
 * @brief An internal function which used to copy data from source buffer
 *        to destination buffer.
 *
 * @param dest The pointer to a destination .
 * @param src The pointer to a source.
 * @param byte_num The number of bytes need copy.
 *
 * @return Void
 *
 */
void libmbcopy_bytes(void *dest, const void *src, uint32 byte_num)
{
	uint8 *dest_byte = dest;
	const uint8 *src_byte = src;
	//copy data by word when dest and src addresses are word aligned ,and byte num isn't too small
	if((NULL == dest) || (NULL == src) || (0U == byte_num)) {
		;
	}
	else if(byte_num >= sizeof(long) * 4u && (((uint64)(uintptr_t)dest_byte) % sizeof(long)) == 0u && (((uint64)(uintptr_t)src_byte) % sizeof(long)) == 0u)
	{
		uint32 word_count = byte_num / sizeof(long);
		uint32 byte_count = byte_num % sizeof(long);

		//firstly copy data word by word 
		long *dest_word = (long *)(void *)dest_byte;
		const long *src_word = (const long *)(const void *)src_byte;
		uint32 word_4_count = word_count / 4u;
		uint32 word_1_count = word_count % 4u;
		while(word_4_count > 0u)
		{
			*dest_word++ = *src_word++;
			*dest_word++ = *src_word++;
			*dest_word++ = *src_word++;
			*dest_word++ = *src_word++;
			word_4_count--;
		}
		while(word_1_count > 0u)
		{
			*dest_word++ = *src_word++;
			word_1_count--;
		}
		
		//then copy the rest of data byte by byte 
		dest_byte = (uint8 *)(void *)dest_word;
		src_byte = (const uint8 *)(const void *)src_word;
		while(byte_count > 0u)
		{
			*dest_byte++ = *src_byte++;
			byte_count--;
		}
	}
	else
	{
		while(byte_num > 0u)
		{
			*dest_byte++ = *src_byte++;
			byte_num--;
		}
	}
}

/**
 * @brief An internal function which used to initialize the mailbox.
 *
 * @param mb The pointer to a mailbox.
 * @param mb_cfg The pointers to the configuration of a mailbox.
 * @param subregion_cfg The configuration array which is used to store.
 *        the configuration of all sub-regions.
 *
 * @retval true Initialzie Mailbox success.
 * @retval false Initialzie Mailbox fail.
 *
 */
static bool LibMB_Init_Mailbox(mb_desc_t *mb, const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[])
{
	bool ret = false;
	if ( mb != NULL )
	{
		ret = true;
		/*Initialize the name, sun-region number and total size of mailbox*/
		libmbcopy_bytes(mb->name, mb_cfg->name, MB_NAME_SZ);
		mb->num_of_sub_region = mb_cfg->num_sub_regions;
		mb->mb_size = mb_cfg->mb_size;
		mb->mb_prio = mb_cfg->mb_prio;
		/*Initialzie the mailbox sub-region one by one */
		for(uint32 i = 0u; i < mb->num_of_sub_region; i++)
		{
			mb->sub_region[i].sub_region_start_offset = subregion_cfg[i].start_addr_offset;
			mb->sub_region[i].sub_region_end_offset = subregion_cfg[i].end_addr_offset;
			void *sub_region_base = (uint8 *)mb + mb->sub_region[i].sub_region_start_offset;
			mbsub_rgn_desc_t *base = (mbsub_rgn_desc_t *)sub_region_base;
			if(base != NULL)
			{
				libmbcopy_bytes(base->name, subregion_cfg[i].name, MB_NAME_SZ);
				base->max_item_num = subregion_cfg[i].item_max_num;
				base->max_item_size = subregion_cfg[i].item_max_size;
				base->item_in_index = 0;
				base->item_out_index = 0;
				/* update chan hsz with hw deps */
				base->sender   = subregion_cfg[i].sender;
				base->receiver = subregion_cfg[i].receiver;
				base->prot     = subregion_cfg[i].prot;
				base->sig      = subregion_cfg[i].sig;
				base->mode     = subregion_cfg[i].mode;
				base->prio     = subregion_cfg[i].prio;
			}
			else
			{
				ret = false;
				break;
			}
		}
	}
	return ret;
}

/**
 * @brief An internal function which used to check the configurations 
 *        of mailbox provided by user.
 * 
 * It will check if the number of sub-region are valid
 * It will check if each sub-region can cover its all items.
 * It will check if exist overlapping areas between regions of mailbox, 
 * the regions include the sub-regions and mailbox header.
 *
 * @param mb The pointer to a mailbox.
 * @param mb_cfg The pointers to the configuration of a mailbox
 * @param subregion_cfg The configuration array which is used to store 
 * 	   the configuration of all sub-regions.
 *
 * @retval true Mailbox configurations are valid.
 * @retval false Mailbox configurations are invalid.
 *
 */
static bool LibMB_Boundary_Check(const mb_desc_t *mb, const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[])
{
	bool ret = true;
	uint32 current_region_end_offset = 0u;
	uint32 current_region_end_limit = 0u;
	uint32 hsz = 0u;

	if((mb_cfg->num_sub_regions <= MB_MAX_SUB_REGION_NUM) && (mb_cfg->num_sub_regions > 0u))
	{
		hsz = ( MB_SUB_REGION_HEADER_SZ - 1U );
		/*check if sub-region can cover its all items one by one*/
		for(uint32 i = 0u; i < mb_cfg->num_sub_regions; i++)
		{
			uint32 start_addr_offset = subregion_cfg[i].start_addr_offset;
			uint32 end_addr_offset = subregion_cfg[i].end_addr_offset;
			uint32 valid_size = subregion_cfg[i].item_max_num * subregion_cfg[i].item_max_size;
			uint32 max_item_num = subregion_cfg[i].item_max_num;

			/* check overflow of valid_size */
			bool valid_range = ((subregion_cfg[i].item_max_num != 0u) && ((valid_size / subregion_cfg[i].item_max_num ) != subregion_cfg[i].item_max_size));

			if((max_item_num > MB_MAX_ITEM_NUM) || (start_addr_offset >= end_addr_offset) || \
				(valid_range != 0u) || ((start_addr_offset + hsz + valid_size) <= start_addr_offset) || \
				((start_addr_offset + hsz + valid_size) > end_addr_offset))
			{
				ret = false;
				break;
			}
		}

		/* check if exist overlapping areas in mailbox, the areas include mailbox header and sub-regions.
		   Firstly check the mailbox header and sub-region0, then check sub-region1 and sub-region2,etc.
		   Finally check if last sub-region inside the mailbox
		*/
		/* next RW alignment offset adjust */
		uint32 chan = ( mb_cfg->num_sub_regions - 1U );
		hsz	 = (( sizeof( mb_desc_t ) + \
						( sizeof( mbsub_rgn_area_t ) * chan ) + 3U ) & ~0x3U);
		if(ret)
		{
			for(uint32 i = 0; i < (mb_cfg->num_sub_regions + 1u); i++)
			{
				if(i == 0u) /*current region is the header of mailbox*/
				{
					current_region_end_offset = hsz;
					current_region_end_limit  = subregion_cfg[0].start_addr_offset;
				}
				else if(i == (mb_cfg->num_sub_regions)) /*current region is the last sub-region*/
				{
					current_region_end_offset = subregion_cfg[i-1u].end_addr_offset;
					current_region_end_limit = mb_cfg->mb_size;
				}
				else /*current region is between mailbox header and the last sub-region*/
				{
					current_region_end_offset = subregion_cfg[i-1u].end_addr_offset;
					current_region_end_limit = subregion_cfg[i].start_addr_offset;
				}

				/*Check if exists overlapping areas between each regions in mailbox*/
				if((current_region_end_offset >= current_region_end_limit) || ((current_region_end_limit > mb_cfg->mb_size)))
				{
					ret = false;
					break;
				}
			}
		}
	}
	else
	{
		ret = false;
	}
	
	return ret;
}

/**
 * @brief An internal function which used to write items into mailbox sub-region.
 *
 * @param base The pointer to a mailbox sub-region.
 * @param source_item_buf The pointers to the item source buffer.
 * @param item_num The number of items written into the sub-region.
 *
 * @return void
 *
 */
static void LibMB_Write_Item(mbsub_rgn_desc_t *base, const void *source_item_buf, uint32 item_num)
{
	uint32 item_size = base->max_item_size;
	uint32 item_write_index = base->item_in_index;
	uint32 item_ring_buffer_size = base->max_item_num;
	uint8 *ring_buffer_base = (uint8 *) base + MB_SUB_REGION_HEADER_SZ;
	const uint8 *source_data_base = (const uint8 *) source_item_buf;
	uint8 *dest_addr = NULL;
	const uint8 *src_addr = NULL;
	uint32 write_item_num = 0;

	/* if loopback happens in the item ring buffer, devide the write process into two step.
	   1. write items from the write index to the end of the sub-region ring-buffer
	   2. write the rest items from the start of sub-region ring-buffer
	 */
	if(item_write_index + item_num > item_ring_buffer_size)
	{
		dest_addr = ring_buffer_base + (item_write_index * item_size);
		src_addr = source_data_base;
		write_item_num = item_ring_buffer_size - item_write_index;
		libmbcopy_bytes(dest_addr, src_addr, write_item_num * item_size);
		
		dest_addr = ring_buffer_base;
		src_addr = source_data_base + (write_item_num * item_size);
		write_item_num = (item_write_index + item_num) - item_ring_buffer_size;
		libmbcopy_bytes(dest_addr, src_addr, write_item_num * item_size);
	}
	else
	{
		/*loopback not happen, write all items into sub-region ring-buffer from the write index*/
		dest_addr = ring_buffer_base + (item_write_index * item_size);
		src_addr = source_data_base;
		write_item_num = item_num;
		libmbcopy_bytes(dest_addr, src_addr, write_item_num * item_size);
	}
	
	/*update the item write index after items have been written into mailbox*/
	base->item_in_index = (item_write_index + item_num) % item_ring_buffer_size;
}

/**
 * @brief An internal function which used to read items from a sub-region 
 *
 * @param base The pointer to a mailbox sub-region.
 * @param destination_item_buf The pointers to the item destination buffer.
 * @param item_num The number of items read from the sub-region.
 *
 * @return void
 *
 */
static void LibMB_Read_Item(mbsub_rgn_desc_t *base, void *destination_item_buf, uint32 item_num)
{
	uint32 item_size = base->max_item_size;
	uint32 item_read_index = base->item_out_index;
	uint32 item_ring_buffer_size = base->max_item_num;
	const uint8 *ring_buffer_base = (uint8 *) base + MB_SUB_REGION_HEADER_SZ;
	uint8 *dest_data_base = (uint8 *) destination_item_buf;
	uint8 *dest_addr = NULL;
	const uint8 *src_addr = NULL;
	uint32 read_item_num = 0;
	
	/* if loopback happens in the item ring buffer, devide the write process into two step.
	   1. read items from the read index to the end of the sub-region ring-buffer
	   2. read the rest items from the start of sub-region ring-buffer
	 */
	if(item_read_index + item_num > item_ring_buffer_size)
	{
		dest_addr = dest_data_base;
		src_addr = ring_buffer_base + (item_read_index * item_size);
		read_item_num = item_ring_buffer_size - item_read_index;
		libmbcopy_bytes(dest_addr, src_addr, read_item_num * item_size);
		
		dest_addr = dest_data_base + (read_item_num * item_size);
		src_addr = ring_buffer_base;
		read_item_num = (item_read_index + item_num) - item_ring_buffer_size;
		libmbcopy_bytes(dest_addr, src_addr, read_item_num * item_size);
	}
	else
	{
		/*loopback not happen, read all items from the read index of sub-region ring-buffer*/
		dest_addr = dest_data_base;
		src_addr = ring_buffer_base + (item_read_index * item_size);
		read_item_num = item_num;
		libmbcopy_bytes(dest_addr, src_addr, read_item_num * item_size);
	}
	
	/*update the item read index after items have been read out */
	base->item_out_index = (item_read_index + item_num) % item_ring_buffer_size;
}

/**
 * @brief An internal function which used for sanity check of mailbox   
 *
 * The function will check if the read index, write index and 
 * valid items number of a sub-region ring-buffer are valid.
 *
 * @param base The pointer to a mailbox sub-region.
 *
 * @retval true mailbox sanity check pass
 * @retval false mailbox sanity check fail
 *
 */
static bool LibMB_Mailbox_sanity_check(const mbsub_rgn_desc_t *base)
{
	bool ret = true;
	if(base != NULL)
	{
		if((base->max_item_num > MB_MAX_ITEM_NUM) || (base->item_in_index >= base->max_item_num) \
			|| (base->item_out_index >= base->max_item_num))
		{
			ret = false;
		}
	}
	else
	{
		ret = false;
	}
	
	return ret;
}

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
int32 LibMB_ChanMapInit(const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[])
{
	int32 ret  = MB_E_SUCCESS;
	uint32 chan = 0U;
	uint32 hsz = 0U;
	mbsub_rgn_config_t *pcfgset = NULL;
	if((mb_cfg != NULL) && (subregion_cfg != NULL) && (mb_cfg->num_sub_regions <= MB_MAX_SUB_REGION_NUM) && (mb_cfg->num_sub_regions > 0U))
	{
		pcfgset = (void*)&subregion_cfg[0U];
		chan 	= ( mb_cfg->num_sub_regions - 1U );
		/* next RW alignment offset adjust */
		hsz	= (( sizeof( mb_desc_t ) + \
				( sizeof( mbsub_rgn_area_t ) * chan ) + 3U ) & ~0x3U);
		for(chan = 0; chan < mb_cfg->num_sub_regions; chan++)
		{
			if( 0U == chan )
			{
				/* start chan offset */
				pcfgset[chan].start_addr_offset = (hsz + 4U);
				pcfgset[chan].end_addr_offset	= ( pcfgset[chan].start_addr_offset + ( MB_SUB_REGION_HEADER_SZ - 1U ) + \
													( pcfgset[chan].item_max_num * pcfgset[chan].item_max_size ) );
				/* reuse for channel hsz */
				hsz = ( MB_SUB_REGION_HEADER_SZ - 1U );
			}
			else
			{
				pcfgset[chan].start_addr_offset = ( pcfgset[( chan - 1U )].end_addr_offset + 1U );
				pcfgset[chan].end_addr_offset	= ( pcfgset[chan].start_addr_offset + hsz + \
													( pcfgset[chan].item_max_num * pcfgset[chan].item_max_size ) );
			}
		}
		if( mb_cfg->mb_size < pcfgset[chan - 1U].end_addr_offset)
		{	/* chan map overflow abrt check */
			ret = MB_E_INVALID_CFG;
		}
		else if (chan != mb_cfg->num_sub_regions)
		{	/* all cfg chan init expected */
			ret = MB_E_INVALID_CFG;
		}
		else
		{
			; /* do nothing pick default */
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}


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
bool LibMB_ChanReset( mb_desc_t *mb, const mbsub_rgn_config_t subregion_cfg[], const uint32 schan)
{
	bool ret = true;
	if(MB_E_SUCCESS != LibMB_Validate( mb ))
	{
		ret = false;
	}
	else if((mb != NULL) && (schan < mb->num_of_sub_region))
	{
		/*Initialzie the mailbox sub-region one by one */
		mb->sub_region[schan].sub_region_start_offset = subregion_cfg[schan].start_addr_offset;
		mb->sub_region[schan].sub_region_end_offset = subregion_cfg[schan].end_addr_offset;
		void *sub_region_base = (uint8 *)mb + mb->sub_region[schan].sub_region_start_offset;
		mbsub_rgn_desc_t *base = (mbsub_rgn_desc_t *)sub_region_base;
		if(base != NULL)
		{
			libmbcopy_bytes(base->name, subregion_cfg[schan].name, MB_NAME_SZ);
			base->max_item_num = subregion_cfg[schan].item_max_num;
			base->max_item_size = subregion_cfg[schan].item_max_size;
			base->item_in_index = 0;
			base->item_out_index = 0;
			/* update chan hsz with hw deps */
			base->sender   = subregion_cfg[schan].sender;
			base->receiver = subregion_cfg[schan].receiver;
			base->prot     = subregion_cfg[schan].prot;
			base->sig      = subregion_cfg[schan].sig;
			base->mode     = subregion_cfg[schan].mode;
			base->prio     = subregion_cfg[schan].prio;
		}
		else
		{
			ret = false;
		}
	}
	else
	{
		ret = false;
	}
	return ret;
}

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
int32 LibMB_Create(mb_desc_t *mb, const mbconfig_t *mb_cfg, const mbsub_rgn_config_t subregion_cfg[])
{
	int32 ret = MB_E_SUCCESS;
	if((mb != NULL) && (mb_cfg != NULL) && (subregion_cfg != NULL))
	{
		if(LibMB_Boundary_Check((const mb_desc_t *)mb, mb_cfg, subregion_cfg))
		{
			if(LibMB_Init_Mailbox(mb, mb_cfg, subregion_cfg))
			{
				mb->magic = MB_MAGIC_NUMBER;
			}
			else
			{
				ret = MB_E_CORRUPT_MAILBOX;
			}
		}
		else
		{
			ret = MB_E_INVALID_CFG;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}

/**
 * @brief Check if mailbox has been created
 *  
 * It is non-blocking and both the sender and receiver of mailbox can  
 * call it to check if mailbox has been created.
 *
 * @param[in] mb The pointer to a mailbox
 *
 * @return If Create success return 0 else return negative error code.
 * @retval 0 The mailbox has been created.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -44 Mailbox has not been created.
 * 
 */
int32 LibMB_Validate(const mb_desc_t *mb)
{
	int32  ret = MB_E_SUCCESS;
	
	if(mb != NULL)
	{
		if(mb->magic != MB_MAGIC_NUMBER)
		{
			ret = MB_E_INVALID_MAILBOX;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	
	return ret;
}

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
int32 LibMB_Write(mb_desc_t *mb, const void *source_item_buf, uint32 item_num, uint32 sub_region_index)
{
	int32  ret = 0;
	if((mb != NULL) && (source_item_buf != NULL))
	{
		if(MB_MAGIC_NUMBER == mb->magic)
		{
			if(sub_region_index < mb->num_of_sub_region)
			{
				void *sub_region_base = (uint8 *)mb + mb->sub_region[sub_region_index].sub_region_start_offset;
				if(LibMB_Mailbox_sanity_check(sub_region_base) == true)
				{
					if(item_num <= LibMB_Free_Item(sub_region_base))
					{
						LibMB_Write_Item(sub_region_base, source_item_buf, item_num);
						ret = (int32)item_num;
					}
					else
					{
						ret = MB_E_NO_ENOUGH_BUF;
					}
				}
				else
				{
					ret = MB_E_CORRUPT_MAILBOX;
				}
			}
			else
			{
				ret = MB_E_INVALID_INDEX;
			}
		}
		else
		{
			ret = MB_E_INVALID_MAILBOX;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}

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
int32 LibMB_Read(mb_desc_t *mb, void *destination_item_buf, uint32 item_num, uint32 sub_region_index)
{
	int32  ret = 0;
	if((mb != NULL) && (destination_item_buf != NULL))
	{
		if(MB_MAGIC_NUMBER == mb->magic)
		{
			if(sub_region_index < mb->num_of_sub_region)
			{
				void *sub_region_base = (uint8 *)mb + mb->sub_region[sub_region_index].sub_region_start_offset;
				if(LibMB_Mailbox_sanity_check(sub_region_base) == true)
				{
					uint32 read_num = (LibMB_Valid_Item(sub_region_base) < item_num) ? LibMB_Valid_Item(sub_region_base) : item_num;
					if(read_num > 0u)
					{
						LibMB_Read_Item(sub_region_base, destination_item_buf, read_num);
						ret = (int32)read_num;
					}
				}
				else
				{
					ret = MB_E_CORRUPT_MAILBOX ;
				}
			}
			else
			{
				ret = MB_E_INVALID_INDEX;
			}
		}
		else
		{
			ret = MB_E_INVALID_MAILBOX ;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	
	return ret;

}

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
int32 LibMB_Get_FreeItemNum(const mb_desc_t *mb, uint32 sub_region_index)
{
	int32  ret = 0;
	if(mb != NULL)
	{
		if(MB_MAGIC_NUMBER == mb->magic)
		{
			if(sub_region_index < mb->num_of_sub_region)
			{
				const void *sub_region_base = (const uint8 *)mb + mb->sub_region[sub_region_index].sub_region_start_offset;
				if(LibMB_Mailbox_sanity_check(sub_region_base) == true)
				{
					ret = (int32)LibMB_Free_Item(sub_region_base);
				}
				else
				{
					ret = MB_E_CORRUPT_MAILBOX;
				}
			}
			else
			{
				ret = MB_E_INVALID_INDEX;
			}
		}
		else
		{
			ret = MB_E_INVALID_MAILBOX;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}

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
int32 LibMB_Get_ValidItemNum(const mb_desc_t *mb, uint32 sub_region_index)
{
	int32  ret = 0;
	if(mb != NULL) 
	{
		if(MB_MAGIC_NUMBER == mb->magic)
		{
			if(sub_region_index < mb->num_of_sub_region)
			{
				const void *sub_region_base = (const uint8 *)mb + mb->sub_region[sub_region_index].sub_region_start_offset;
				if(LibMB_Mailbox_sanity_check(sub_region_base) == true)
				{
					ret = (int32)LibMB_Valid_Item(sub_region_base);
				}
				else
				{
					ret = MB_E_CORRUPT_MAILBOX;
				}
			}
			else
			{
				ret = MB_E_INVALID_INDEX;
			}
		}
		else
		{
			ret = MB_E_INVALID_MAILBOX;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}

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

int32 LibMB_Get_ChanInfo(const mb_desc_t *mb, uint32_t sub_region_index, mbchan_desc_t* chaninfo)
{
	int32  ret = 0;
	if((mb != NULL) && (chaninfo != NULL))
	{
		if(MB_MAGIC_NUMBER == mb->magic)
		{
			if(sub_region_index < mb->num_of_sub_region)
			{
				const void *sub_region_base = (const uint8 *)mb + mb->sub_region[sub_region_index].sub_region_start_offset;
				if(LibMB_Mailbox_sanity_check(sub_region_base) == true)
				{
					const mbsub_rgn_desc_t* base = sub_region_base;
					chaninfo->mode = base->mode;  
					if(MB_LIB_TYPE != MB_LIB_OWNER)
					{
						if( MB_CHAN_RD_MODE == base->mode )
						{
							chaninfo->mode = MB_CHAN_WR_MODE;
					}
					else
					{
							chaninfo->mode = MB_CHAN_RD_MODE;
						}
					}
					libmbcopy_bytes(chaninfo->name, base->name, MB_NAME_SZ);
					chaninfo->sender   = base->sender;   
					chaninfo->receiver = base->receiver;
					chaninfo->prot     = base->prot;     
					chaninfo->sig      = base->sig;
					chaninfo->prio     = base->prio;    
					chaninfo->max_item_num   = base->max_item_num;  
					chaninfo->max_item_size  = base->max_item_size;
				}
				else
				{
					ret = MB_E_CORRUPT_MAILBOX;
				}
			}
			else
			{
				ret = MB_E_INVALID_INDEX;
			}
		}
		else
		{
			ret = MB_E_INVALID_MAILBOX;
		}
	}
	else
	{
		ret = MB_E_NULL_INPUT;
	}
	return ret;
}
/*============================================================================*/