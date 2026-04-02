/**
 * @file common_functions.c
 * @brief
 * Source file for common functions
 *
 *        Copyright (c) 2020-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include "types.h"
#include <limits.h>
#include "debug_log.h"
#include "arm_acle.h"
#include "target.h"
#include "gpio.h"
#include "msmhwiobase.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "sail_csr_hwio.h"
#include "common_functions.h"
#include "arch_defs.h"
#include "commonClient.h"
#ifndef SAILEL2
#include "freertos_init.h"
#endif


#ifndef SAILEL2
#include "syscall_svc.h"
#include "arch_defs.h"
BSP_GLOBAL_DATA static volatile uint32_t ulMPDIRValCached = 0; /* NOTE this variable must compile to all the EL1 image */
#endif
#define INT32_MIN_VALUE  (0x80000000U)



/*===========================================================================
**  Function :  read_mpidr
** ==========================================================================
*/
/*!
*
* @brief
*   helper function to read mpidr register
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   cuurent value of mpidr register
* @par Side Effects
*   None
*
*/

uint32 read_mpidr(void)
{
    uint32_t val;
#ifndef SAILEL2
        if( FALSE == xSyscallIsPrivilegedMode() )
        {
            val = ulMPDIRValCached;
        }
        else
        {
            val = __arm_mrc(15, 0, 0, 0, 5);
            ulMPDIRValCached = val;
        }
#else
        val = __arm_mrc(15, 0, 0, 0, 5);
#endif
    __asm__ volatile("isb" ::: "memory");
    __asm__ volatile("dsb sy" ::: "memory");
    return val;
}
/*=========================================================================
 **  Function : bIsCurrentModeHyp
 ** =========================================================================*/
/**
  This function will check if current task mode is CPSR_MODE_HYP and returns TRUE

  @param
  [in]None

  @return
  TRUE or FALSE

  @dependencies
  None.
 */
boolean bIsCurrentModeHyp(void)
{
	bool  bHypMode   = TRUE;
	uint32_t      ulCPSR_reg   = 0;

	__asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulCPSR_reg) : );

	if(  CPSR_MODE_HYP == ( ulCPSR_reg & CPSR_MODE_MASK ) ) /* Is the current CPSR mode Hyp? */
	{   
		bHypMode = TRUE;
	}   
	else
	{   
		bHypMode = FALSE;
	}   
	return bHypMode ;
}

#ifndef SAILEL2
/*===========================================================================
**  Function :  xSyscallIsIrqMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function will check the irq mode.
*
* @param
*  None
* @par Dependencies
*   None
* @retval
*   boolean- TRUE/FALSE
* @par Side Effects
*   None
*
*/
 boolean xSyscallIsIrqMode( void )
 {
    return xFreertosIsIRQMode();
 }

#endif
/*===========================================================================
**  Function :  get_curr_cpu_num
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the current cpu number
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   current cpu number
* @par Side Effects
*   None
*
*/
uint get_curr_cpu_num(void)
{
  uint cpu_num;
  uint64_t mpidr = read_mpidr();
  cpu_num = (mpidr & 0xFF);

  if (cpu_num >= 2)
    while (1);

  return cpu_num;
}
/*===========================================================================
**  Function :  get_curr_cluster_num
** ==========================================================================
*/
/*!
*
* @brief
*   Function to get the current cluster number
*
* @param
    None
* @par Dependencies
*   None
* @retval
*   current cluster number
* @par Side Effects
*   None
*
*/
uint get_curr_cluster_num(void)
{
  uint cluster_num;
  uint64_t mpidr = read_mpidr();
  cluster_num = (mpidr & 0xFF00) >> 8;

  if (cluster_num >= 2)
    while (1);

  return cluster_num;
}

uint get_curr_phys_cpu_num(void)
{
  uint64_t mpidr = read_mpidr();
  uint phys_cpu_num = ((mpidr & SAILBSP_MPIDR_CLUSTER_MASK) >> SAILBSP_MPIDR_CLUSTER_SHFT) * SAILBSP_CPUS_PER_CLUSTER + 
                      ((mpidr & SAILBSP_MPIDR_CPU_MASK) >> SAILBSP_MPIDR_CPU_SHFT);
  if (phys_cpu_num >= SAILBSP_CPU_COUNT) {
    while (1);
  }
  return phys_cpu_num;
}

/*=========================================================================
**  Function : ffs
** =========================================================================*/
/**
* function to find the rightmost set bit pos
* @param
* [in] num
* @return
* [out] res
* NOTE:
* no bit set (num = 0) : return  -1
* pos 0 bit set        : return  0
* pos 1 bit set        : return  1
* pos 2 bit set        : return  2
* ....
* pos 31 bit set       : return  31
*
* @dependencies
* None
*/
int32_t ffs(int32_t num)
{
    int32_t res            = 0;
    int32_t word_size_bits = sizeof(int32_t) * 8;

    int32_t temp      = num & (-num);

    __asm("CLZ %[result], %[input]"
        : [result] "=r" (res)
        : [input] "r" (temp)
    );
    res =  word_size_bits - res - 1;
    return res;
}

/*===========================================================================
**  Function :  sailbsp_memscpy
** ==========================================================================
*/
/*!
*
* @brief
*   secure API memscpy - Size bounded memory copy.
*
* @param
*   [in/out] dst : pointer to destination array
*   [in] dst_size : size to copy to the destination
*   [in/out] src : pointer to source array
*   [in] src_size : size to copy from the source
*
* @par Dependencies
*   None
* @retval
*   size of items copied from source to destination
* @par Side Effects
*   None
*
*/
size_t sailbsp_memscpy(void *dst, size_t dst_size, const void *src, size_t src_size)
{
  size_t copy_size = (dst_size <= src_size) ? dst_size : src_size;
  size_t result = 0;

  if (copy_size && dst && src) 
  {
    memcpy(dst, src, copy_size);
	result = copy_size;
  }

  return result;
}

/*===========================================================================
**  Function :  sailbsp_checkmdedl
** ==========================================================================
*/
/*!
*
* @brief
*   Checks MD2SAIL shadow registers if MD is in EDL.
*
* @param
*   none
* @par Dependencies
*   None
* @retval
*   TRUE: MD went into EDL mode
*   FALSE: MD not in EDL mode
* @par Side Effects
*   None
*
*/
bool sailbsp_checkmdedl(void)
{
  //check if MD PBL ent to EDL mode
  if( 0xFE == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS3_REG) &&
    0x11 == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS2_REG) &&
    0x11 == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS1_REG) &&
    0x11 == HWIO_IN(SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS0_REG))
  {
    return TRUE;
  }
  else
  {
    return FALSE;
  }
}

bool isNumeric(const char *str) 
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

/*===========================================================================
**  Function :  silbsp_atoi
** ==========================================================================
*/
int32_t silbsp_atoi(const char* str)
{
    int32_t sign = 1, base = 0, i = 0;

    // if whitespaces then ignore.
    while (str[i] == ' ')
    {
        i++;
    }
    // sign of number
    if (str[i] == '-' || str[i] == '+')
    {
        boolean value = (str[i++] == '-');
        sign = (int)1 - (int)2 * (int)value;
    }

    // checking for valid input
    while (str[i] >= '0' && str[i] <= '9')
    {
        // handling overflow test case
        if (base > INT_MAX / 10
                || (base == INT_MAX / 10
                    && str[i] - '0' > 7))
        {
            if (sign == 1)
            {
                return INT_MAX;
            }
            else
            {
                return (int)INT32_MIN_VALUE;
            }
        }
        base = 10 * base + (str[i++] - '0');
    }
    return base * sign;
}

/*******************************************************************************
** Syntax           : uint8 sailbsp_stricmp                                   **
**                    (    	char const *str1, char const *str2                **
**                    )                                                       **
**                                                                            **
** Description      :  string compare            							  **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : *str1 - ptr to string in small caps ended with \0       **
** Parameters(in)   : *str2 - ptr to string needs to be compare               **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  1 - compare success                                    **
** Return value     :  0 - compare fail                                       **
**                                                                            **
*******************************************************************************/
uint8 sailbsp_stricmp(char const *str1, char const *str2)
{
	uint32 retval = 0U;
	uint32 temp = 0U;
	int res = 0;

	if((str1 != NULL) && (str2 != NULL))
	{
		/* loop limit is not req. as str1 is hard coded string test cmd */
		while(*str1!='\0')
		{
			temp = *str2;

			if((temp >= 'A') && (temp <= 'Z'))
			temp = temp + 32;

			res = *str1 - temp;

			if(res != 0U)
			{
				retval = 0U;
				break;
			}
			str1++;
			str2++;
		}

		if(*str2 == '\0' && *str1 == '\0')
		{
			retval = 1U;
		}
	}
    /* compare success ret 1 else 0 */
    return (uint8)retval;
}

/*===========================================================================
**  Function :  sailbsp_strlcpy
** ==========================================================================
*/
/*!
*
* @brief
*   sailbsp_strlcpy - string copy.
*
* @param
*   [in/out] dstBuffer : pointer to destination buffer.
*   [in] srcStr : pointer to string which needed to be copied.
*   [in] dstBuffSize : Total size to destination buffer which can hold the string, including null terminator.
*
* @par Dependencies
*   Input strings needs to have proper null-termination.
* @retval
*   returns length of Source string.
* @par Side Effects
*   None
*
*/
//TODO: need to check if further optimization is needed for strlcpy, strlcat
// if BSD extension can be supported for GNU/GCC, bsp - strlcat, strlcpy can be removed.
size_t sailbsp_strlcpy(char *dstBuffer, char const *srcStr, size_t dstBuffSize )
{
  size_t srcStrLen = 0U;

  if (dstBuffSize == 0U)
  {
    return ((size_t) strlen(srcStr));
  }

  for(size_t cnt = 0; cnt < (dstBuffSize - 1U); cnt++)
  {
    if( *srcStr != '\0' )
    {
      *dstBuffer++ = *srcStr++;
    }
    else
    {
      break;
    }

    srcStrLen++;  
  }
  *dstBuffer = '\0';

  while( *srcStr != '\0')
  {
    srcStr++;
    srcStrLen++;
  }

  return srcStrLen;
}

#if 0
/*******************************************************************************
** Syntax           : boolean bSailTsensGetPerSensorTempWrappper              **
**                    (    	uint32 ulSensorID , int8_t *suSensorTemp         **
**                    )                                                       **
**                                                                            **
** Description      :  Get Sail sensor Temperature in DegC                    **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : ulSensorID - Sensor ID <0-3>                   \0       **
**                                                                            **
** Parameters (out) : *suSensorTemp - ptr to variable which holds temp        **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Temp Read Success                              **
** Return value     :  FALSE - Temp Read Failure                              **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetPerSensorTempWrappper( uint32 ulSensorID , int8_t *suSensorTemp)
{
	boolean bRet = FALSE;
	int32_t slSensorTemp = 0;
	
	if( ( suSensorTemp == NULL ) || ( ulSensorID < 0U ) || ( ulSensorID > 3U ) )
	{
		return bRet;
	}
	
	slSensorTemp = slGetSensorTemp(ulSensorID);
    
	if(slSensorTemp != 0xFFFFFFF )
	{
		*suSensorTemp = (int8_t)( slSensorTemp / (int32_t)10 );
		bRet = TRUE;
	}
	else
	{
		bRet = FALSE;
	}
	return bRet;
}

/*******************************************************************************
** Syntax           : boolean bSailTsensGetMaskSensorTempWrappper             **
**                    (    	uint32_t ulSensorMask , int8_t *suSensorTemp        **
**                    )                                                       **
**                                                                            **
** Description      :  Get Sail sensor Temperature in DegC for the sensor     **
**                     mask provided                                          **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : ulSensorMask - Mask of sensors whose temperatures are   **
**                    to be fetched                                           **
**                                                                            **
** Parameters (out) : *suSensorTemp - ptr to variable which holds temp        **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Temp Read Success                              **
** Return value     :  FALSE - Temp Read Failure                              **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetMaskSensorTempWrappper( uint32_t ulSensorMask , int8_t *suSensorTemp)
{
	boolean bRet = FALSE;
	uint32_t ulSensorId = 0U;
	
	if( ( suSensorTemp == NULL ) || ( ( ulSensorMask & 0xF0U )  != 0U ) )
	{
		return bRet;
	}
    
	while(ulSensorMask != 0U)
	{
		if( ( ulSensorMask & 1U ) != 0U )
		{
	        if( bSailTsensGetPerSensorTempWrappper( ulSensorId , &suSensorTemp[ulSensorId]) != TRUE )
			{
				return bRet;
			}
   		}
		ulSensorMask >>= 1U;
		ulSensorId++;
	}
	
	return TRUE;
}

/*******************************************************************************
** Syntax           : boolean bSailTsensGetNumOfSensorWrappper                **
**                    (    	uint8_t *pulTsensNumSensor                       **
**                    )                                                       **
**                                                                            **
** Description      :  Get Number of Sensors in SAIL TSENS Controller         **
**					               		      								  **
**                           					  							  **
**                                      									  **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : pulTsensNumSensor - Pointer to variable to keep         **
**                                        Number of Sensors                   **
**                                                                            **
** Parameters (in-out): None                                                  **
**                                                                            **
** Return value     :  TRUE  - Success                                        **
** Return value     :  FALSE - Failure                                        **
**                                                                            **
*******************************************************************************/
boolean bSailTsensGetNumOfSensorWrappper( uint8_t *pulTsensNumSensor)
{
	return bTsensGetNumberOfSensors((uint32_t *)pulTsensNumSensor);
}
#endif

