/**
 * @file log_code.c
 * @brief
 * Source file for common functions
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

 /*===========================================================================
          Include files
*===========================================================================*/
#include "logcode.h"
#include "libfdt.h"
#include "fdt_utils.h"

/*===========================================================================
          Helper functions
*===========================================================================*/
#define SAIL_BOOT_STATUS 0xB1
#define MD_BOOT_STATUS   0xA1
 /*===========================================================================
          Helper functions
*===========================================================================*/

void prvHelperWriteLogCode ( uint8_t library[] ,enum Module_Id_e mid ,uint32_t *pudata ,uint8_t uclength )
{
	uint8_t count               = 0;
	
	while (uclength--){
		
		library[mid * CONST_8 + (4 + count)] = (((*pudata) >> (count * CONST_8)) & CONST_255);
		count++;
	}
		
}


void ErrFatal_Readdtb( void )
{
	void *pDTB = NULL;
	int32_t root_offset = 0;
	uint32_t *err_fatal_codes = (uint32_t*)LOGCODE_ERR_FATAL_READ_DTB_ADDR;
	int retval = 0;
	memset(err_fatal_codes, 0, CONST_2);
	
	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/BootStatus");
		if(root_offset > 0)
		{
			/* if any of the DTB entries are missing, skip entering fastboot/devprgm mode */
			retval = fdt_getprop_u32(pDTB, root_offset, "module_id", &err_fatal_codes[0]);
			retval |= fdt_getprop_u32(pDTB, root_offset, "error_id", &err_fatal_codes[1]);
		}
	}
	if (retval == -1)
	{
		err_fatal_codes[0] = 0;
		err_fatal_codes[1] = 0;
	}
	return;
	
 }
 /*===========================================================================
           Write API for LogCodes
		   Arguments : Module Id 
		   			   Loglevel of module(pass /fail)
					   Pointer to the data for the module
					   The Length of data to be read
			
			Return : 1 (Successfully written the data)
					-1 (Failure occured)
 *===========================================================================*/
int vLcWriteLogCode ( enum Module_Id_e mid ,enum LOG_LEVEL_e status ,uint32_t *pudata ,uint8_t uclength ){
	
	uint8_t *Sail_BaseAddress		   = (uint8_t*)LOGCODE_LIB_MEM ;
	uint8_t *is_updated 		   = (uint8_t*)LOGCODE_UPDATE_MEM  ;
	uint8_t *temp_sensor_row    = (uint8_t*)LOGCODE_TEMP_SENSOR;
	uint8_t *Md_BaseAddress		   = (uint8_t*)LOGIC_MD_BOOT_STATUS_ADDR ;
	is_updated[mid]            = 1;
	bool is_default            = 0;
	Md_BaseAddress[0] = MD_BOOT_STATUS;
	Sail_BaseAddress[mid * CONST_8 +0] = SAIL_BOOT_STATUS;
	uint32_t MD_err_code = 0;
	int cell = 0;
	
	switch(mid){

		case SAIL_BOOT_MILESTONES: 

			cell  = (*pudata )/ 8;

			if( status == PASS )
				Sail_BaseAddress[mid *  CONST_8 + (CONST_2 + cell)] |= (1 << ((*pudata )%8));

			is_default = 1;

			break;
			
		case CPU_LOAD:
			
			Sail_BaseAddress[mid * CONST_8 +0] = 0xB;
			Sail_BaseAddress[mid * CONST_8 +CONST_1] = 0x3;
			
			break;
		
		case RGMI_LINK_UP_TEST:
			
			Sail_BaseAddress[mid * CONST_8 +0] = 0xB;
			Sail_BaseAddress[mid * CONST_8 +CONST_1] = 0x5;
			
			break;
			
		case OSPI_READ_RESULTS:
			
			Sail_BaseAddress[mid * CONST_8 +0] = 0xB;
			Sail_BaseAddress[mid * CONST_8 +CONST_1] = 0x6;
			
			break;
		
		case SM_ERR_DIAGNOSTICS:
			
			Sail_BaseAddress[mid * CONST_8 +0] = 0xB;
			Sail_BaseAddress[mid * CONST_8 +CONST_1] = 0x7;

			break;
		
		case TEMP_SENSOR:
			
			;
			//uint8_t sid 	= ((*pudata) & CONST_255);
			uint8_t rid 	= mid + (*temp_sensor_row);
			(*temp_sensor_row) += 1;
			Sail_BaseAddress[rid * CONST_8 +0] = 0xB;
			Sail_BaseAddress[rid * CONST_8 + CONST_1] = 0x4;

			Sail_BaseAddress[rid * CONST_8 + CONST_4] = ((*pudata) & CONST_255);
			Sail_BaseAddress[rid * CONST_8 + CONST_5]= ( ((*pudata) >> CONST_8) & CONST_255);
			Sail_BaseAddress[rid * CONST_8 + CONST_6] = ( ((*pudata) >> CONST_16) & CONST_255);
			
			is_default = 1;
			Sail_BaseAddress[rid * CONST_8 + CONST_2] = status;
			
			break;

		case MD_BOOT_MILESTONES:
		{

			if( status == PASS )
			{
				if (LC_MD_XBLSEC_BOOT == (*pudata) )
				{
					Md_BaseAddress[2] |= 1;
				}
				else if (LC_MD_XBLLDR_BOOT == (*pudata))
				{

					Md_BaseAddress[2] |= (1 << 1);
				}
				else if (LC_MD_TZ_BOOT == (*pudata))
				{

					Md_BaseAddress[2] |= (1 << 2);
				}
				
			
				else if (LC_MD_QHEE_BOOT == (*pudata))
				{

					Md_BaseAddress[2] |= (1 << 3);
				}
				else if (LC_MD_QCPE_BOOT == (*pudata))
				{

					Md_BaseAddress[2] |= (1 << 4);
				}
				
				else if (LC_MD_UEFI_BOOT == (*pudata))
				{

					Md_BaseAddress[2] |= (1 << 5);
				}
				
				
				else if (LC_MD_ABL_BOOT == (*pudata))
				{
					Md_BaseAddress[2] |= (1 << 6);

				}
				
				
				else if (LC_MD_DDR_READY == (*pudata))
				{

					Md_BaseAddress[3] |= 1;
				}

				else if (LC_MD_ADSP_BOOT == (*pudata))
				{

					Md_BaseAddress[3] |= (1 << 1);
				}
				
				else if (LC_MD_HLOS_RDY == (*pudata))
				{

					Md_BaseAddress[3] |= (1 << 2);
				}

				else
				{
					// do nothing
				}
			}
			else
			{
				Md_BaseAddress[1] = 0xE; // DATA1 = NonZero value means Error in MD boot.
				//DATA8 to 11 shall be updated with MD boot error code, which was read from shadow registers.
				MD_err_code = (uint32_t)(*pudata);
				Md_BaseAddress[11] = (MD_err_code & CONST_255);
				Md_BaseAddress[10] = ((MD_err_code >> CONST_8 ) & CONST_255);
				Md_BaseAddress[9] = ((MD_err_code >> CONST_16 ) & CONST_255);
				Md_BaseAddress[8] = ((MD_err_code >> CONST_24) & CONST_255);				
			}
				
			is_default = 1;
		}
			break;
			
		default:
			
			is_default = 1;
			return -1;


				
	}
	
	if (!is_default){
		
		Sail_BaseAddress[mid * CONST_8 + CONST_2] = status;
		prvHelperWriteLogCode(Sail_BaseAddress, mid ,pudata ,uclength );
	}
	
	return 1;
}

 /*===========================================================================
           Read API for LogCodes
		   Arguments : Module Id 
			Return : On Success ,return the array containg the requested data.
					 On failure ,return NULL

 *===========================================================================*/

uint8_t* LcReadLogCode ( enum Module_Id_e mid ){
	
	uint8_t *Sail_BaseAddress	   = (uint8_t*)LOGCODE_LIB_MEM ;
	uint8_t *is_updated 		   = (uint8_t*)LOGCODE_UPDATE_MEM  ;
	uint8_t *Md_BaseAddress	   = (uint8_t*)LOGIC_MD_BOOT_STATUS_ADDR ;

	switch(mid){

		case SAIL_BOOT_MILESTONES: 
			
			return Sail_BaseAddress;

		case MD_BOOT_MILESTONES: 

			return Md_BaseAddress; 
			
		case CPU_LOAD:
			
			break;
	
		case RGMI_LINK_UP_TEST:
			
			break;
			
		case OSPI_READ_RESULTS:
			
			break;
		
		case SM_ERR_DIAGNOSTICS:
			
			break;

		case TEMP_SENSOR:
			
			if(is_updated[mid]){
				
				static uint8_t result[32];
				int strt_row = 5;
				int end_row  = 8;

				for(int i = strt_row;i <= end_row;i++)
					for(int j =0;j<= 11;j++)
					
						result[(i - strt_row) * CONST_8 + j] = Sail_BaseAddress[i * 8 + j];
				
				return result;
			}
			
			else
				return NULL;
		

		case DV_TEST:
			
			if (is_updated[CPU_LOAD] && is_updated[TEMP_SENSOR] && is_updated[RGMI_LINK_UP_TEST] && 
				is_updated[OSPI_READ_RESULTS] && is_updated[SM_ERR_DIAGNOSTICS])
			{	
				static uint8_t result[64];
				int strt_row = 1;
				int end_row  = 8;

				for(int i = strt_row;i <= end_row;i++)
					for(int j =0;j<= 11;j++)
					
						result[(i - strt_row) * CONST_8 + j] = Sail_BaseAddress[i * 8 + j];
				
				return result;
			}
			else
				return NULL;

		default:
			return NULL;
		
	}
	
	return NULL;
	
}

 /*===========================================================================
           Write API for Timestamp
		   Arguments : None
		   Return : None

 *===========================================================================*/
void vLCWriteTimeStamp(BOOT_STAGE_e boot_id ,uint64_t ultime_stamp){

  
	uint64_t *Tstamp = (uint64_t*)LOGCODE_TIMESTAMP_ADDR ;
	uint8_t *Tstamp_core = (uint8_t*)LOGCODE_TIMESTAMP_CORE_ADDR;
	uint8_t core_id = get_curr_phys_cpu_num();

	Tstamp[boot_id] = ultime_stamp;
	Tstamp_core[boot_id] = core_id;
    return;
}
/*===========================================================================
          Write API for Handling fatal errors
		   Arguments : 1) Module Code
		   	   	   	   2) Core Id
		   	   	   	   3) Error info
		   Return : None

*===========================================================================*/
void vLCWriteErrorCode(MODULE_ID mod_id ,uint8_t core_id , uint32_t error_code){

	uint8_t *Sail_BaseAddress     = (uint8_t*)LOGCODE_LIB_MEM ;
	enum Module_Id_e mid = SAIL_BOOT_MILESTONES;
	uint8_t *is_updated 	 = (uint8_t*)LOGCODE_UPDATE_MEM  ;

	if( Sail_BaseAddress[mid * CONST_8 + 1] != 0)// Some fatal error has already been reported
		return;

	Sail_BaseAddress[mid * CONST_8 +0] = SAIL_BOOT_STATUS;
	is_updated[mid]            = 1;

	Sail_BaseAddress[mid * CONST_8 + 1] = mod_id;
	Sail_BaseAddress[mid * CONST_8 + 1] = (Sail_BaseAddress[mid * CONST_8 + 1] | (core_id << CONST_6));

	Sail_BaseAddress[mid * CONST_8 + CONST_8] = (error_code & CONST_255);
	Sail_BaseAddress[mid * CONST_8 + CONST_9] = ((error_code >> CONST_8 ) & CONST_255);

	Sail_BaseAddress[mid * CONST_8 + CONST_10] = ((error_code >> CONST_16 ) & CONST_255);
	Sail_BaseAddress[mid * CONST_8 + CONST_11] = ((error_code >> CONST_24) & CONST_255);
}
