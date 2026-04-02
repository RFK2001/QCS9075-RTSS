/**
 * @file mailbox_driver.h
 *
 * @brief Mailbox API and data structure
 *
 * This contains the prototypes for the mailbox driver
 * and any macros and variables type you will need.
 *
 * Copyright (c) 2020-2021 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */


#ifndef MAILBOX_H
#define MAILBOX_H

#include "types.h"

#define MAGIC_NUMBER            0x12345678u //The magic number of mailbox.
#define NAME_SIZE               16u //The buffer size which used to store mailbox name.
#define MAX_SUB_REGION_NUM      6u  //The maximum number of mailbox sub-region.
#define MAX_ITEM_NUM            512u //The maximum number of items in a mailbox sub-region.
#define SUB_REGION_HEADER_SIZE  sizeof(sub_region_desc) //The size of sub-region header.
#define MAILBOX_HEADER_SIZE     sizeof(mailbox_desc)    //The size of mailbox header.

#define SUCCESS             0  //create or validate the mailbox successfully.
#define NULL_INPUT         -11 //Some input pointer(s) is(are) NULL.
#define INVALID_CFG        -22 //Input parameters used to create mailbox are unreasonable.
#define INVALID_INDEX      -33 //Sub-region index is invalid.
#define INVALID_MAILBOX    -44 //Mailbox is invalid which has not been created.
#define NO_ENOUGH_BUF      -55 //Mailbox sub-region has no enough buffer to store input items.
#define CORRUPT_MAILBOX    -66 //Mailbox is corrupt.


/**
 * @brief structure which used to define the location of a sub-region by its start address offset and end address offset
 *
 */
typedef struct
{
	uint32 sub_region_start_offset; //offset of mailbox sub-region start address.
	uint32 sub_region_end_offset;   //offset of mailbox sub-region end address.
} sub_region_area;

/**
 * @brief mailbox descriptor
 *
 * The structure defines the mailbox layout inside the share memory, which is shared betwwen the receiver and sender.
 * It is better to add pad manually instead of depending on the compiler if necessary.
 */
typedef struct 
{
	int8          name[NAME_SIZE];   //Store mailbox name
	uint32         magic;             //Used to mark if mailbox has been created
	uint32         mb_size;           //The total size of the mailbox
	uint32         num_of_sub_region; //The number of sub-region in the mailbox
	sub_region_area  sub_region[MAX_SUB_REGION_NUM]; //The sub_region array is used to store the offset of each sub-region.
} mailbox_desc;

/**
 * @brief mailbox sub-region descriptor which used to define a ring-buffer which used to store items.
 *
 * The structure defines the mailbox layout inside the share memory, which is shared betwwen the receiver and sender.
 * It is better to add pad manually instead of depending on the compiler if necessary.
 */
typedef struct 
{
	int8	 name[NAME_SIZE];  //Store mailbox sub-region name
	uint32   max_item_num;     //The maximum item number of the mailbox sub-region
	uint32   max_item_size;    //The maximum item size of the mailbox sub-region
	uint32   item_in_index;    //write index
	uint32   item_out_index;   //read index
} sub_region_desc;

/**
 * @brief It is the type of input parameter which used to create a mailbox.
 *
 */
typedef struct
{
	int8	   name[NAME_SIZE];  //Store mailbox name
	uint32   mb_size;          //The total size of the mailbox
	uint32   num_sub_regions;  //The number of sub-region in the mailbox
} mailbox_config;

/**
 * @brief It is the type of input parameter which used to create a mailbox.
 *
 */
typedef struct
{
	int8   name[NAME_SIZE];   //Store mailbox sub-region name
	uint32  start_addr_offset; //offset of sub-region start address.
	uint32  end_addr_offset;   //offset of sub-region end address.
	uint32  item_max_num;      //Sub-region maximum item number
	uint32  item_max_size;     //Sub-region maximum item size
} sub_region_config;


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
int32 MB_Create(mailbox_desc *mb, const mailbox_config *mb_cfg, const sub_region_config subregion_cfg[]);


/**
 * @brief Check if mailbox has been created
 *  
 * It is non-blocking and both the sender and receiver of mailbox can call it to
 * check if mailbox has been created and if mailbox versions are matched between users.
 *
 * @param[in] mb The pointer to a mailbox
 *
 * @return If validate success return 0 else return negative error code.
 * @retval -11 Some input pointer(s) is(are) NULL.
 * @retval -44 Mailbox has not been created.
 * @retval -77 Mailbox versions are not matched.
 * 
 */
int32 MB_Validate(const mailbox_desc *mb);


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
int32 MB_Write(mailbox_desc *mb, const void *source_item_buf, uint32 item_num, uint32 sub_region_index);


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
int32 MB_Read(mailbox_desc *mb, void *destination_item_buf, uint32 item_num, uint32 sub_region_index);


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
int32 MB_Get_FreeItemNum(const mailbox_desc *mb, uint32 sub_region_index);


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
int32 MB_Get_ValidItemNum(const mailbox_desc *mb, uint32 sub_region_index);


#endif /* MAILBOX_H */

