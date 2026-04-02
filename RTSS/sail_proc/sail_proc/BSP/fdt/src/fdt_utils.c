/*
 * Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Export of this technology or software is regulated by the U.S. Government.
 * Diversion contrary to U.S. law prohibited.
 *
 * All ideas, data and information contained in or disclosed by
 * this document are confidential and proprietary information of
 * Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
 * By accepting this material the recipient agrees that this material
 * and the information contained therein are held in confidence and in
 * trust and will not be used, copied, reproduced in whole or in part,
 * nor its contents revealed in any manner to others without the express
 * written permission of Qualcomm Technologies, Inc.
 */

/*===========================================================================
 Copyright (c) 2018 by QUALCOMM Technologies.
 All rights reserved.
 ===========================================================================*/

/*===========================================================================

 EDIT HISTORY FOR FILE

 $Header: //components/rel/plt_utilities.qxa_qa/3.0/fdt_utils/fdt_utils.c#2 $
 $DateTime: 2018/06/04 16:54:33 $
 $Author: rohitn $

 when       who      what, where, why
 --------   ---      ------------------------------------
 02/26/18   guo      Initial version.

 ===========================================================================*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include <debug_log.h>
#include <common_functions.h>
#include <timetick.h>

#include <libfdt.h>
#include "fdt_utils.h"

FDT_FUNC void *fdt_get_dtb(void)
{
    void *ret_address = NULL;
    
/* Currently using commong DTB for both EL1 and EL2 */
#ifdef SAILEL2
    ret_address = (void *)EL2_DTB_STARTADDRESS;
#else
   ret_address = (void *)SW1_DTB_STARTADDRESS;

#endif	/* SAILEL2 */
    if (NULL == ret_address)
    {
        return NULL;
    }
    if (0 == fdt_check_header(ret_address))
    {
        return ret_address;
    }
    else
    {
        return NULL;
    }
}

FDT_FUNC void *fdt_get_dtbo(void)
{
    void *ret_address = NULL;

#ifdef SAILEL2
    ret_address = (void *)EL2_DTBO_STARTADDRESS;
#else
   ret_address = (void *)SW1_DTBO_STARTADDRESS;

#endif	/* SAILEL2 */
    if (NULL == ret_address)
    {
        return NULL;
    }
    if (0 == fdt_check_header(ret_address))
    {
        return ret_address;
    }
    else
    {
        return NULL;
    }
}

FDT_FUNC int32_t fdt_util_apply_overlay(void)
{
    void *dtb = fdt_get_dtb();
    void *dtbo = fdt_get_dtbo();
    int32_t ret = 0;

    if ((NULL != dtb) && (NULL != dtbo))
    {
        ret = fdt_overlay_apply(dtb, dtbo);
    }

    return ret;
}

FDT_FUNC size_t strnlen(const char *s, size_t maxlen)
{
	size_t cur = 0;

	for (cur = 0; cur < maxlen; cur++)
	{
		if ('\0' == s[cur])
		{
			break;
		}
	}

	return cur;
}

FDT_FUNC int32_t fdt_getprop_s32(const void *fdt, int nodeoffset, const char *name, int32_t *pval)
{
    int len = 0;
    int32_t *pprop = NULL;
    int32_t retval = 0;

    pprop = (int32_t *)fdt_getprop(fdt, nodeoffset, name, &len);
    if ( (len < 4) || (pprop == NULL) )
    {
        retval = -1;
    }
    else
    {
        *pval = fdt32_to_cpu(*pprop);
    }

    return retval;
}

FDT_FUNC void fdt_getprop_float(const void *fdt, int nodeoffset, const char *name,float *read_data)
{
	
	int offset_val = 5;	
	char *getval = (char*) fdt_getprop(fdt,nodeoffset,name,&offset_val);
	*read_data = (float)atof(getval);

}
FDT_FUNC int32_t fdt_getprop_u32(const void *fdt, int nodeoffset, const char *name, uint32_t *pval)
{
    int len = 0;
    uint32_t *pprop = NULL;
    int32_t retval = 0;

    pprop = (uint32_t *)fdt_getprop(fdt, nodeoffset, name, &len);
    if ( (len < 4) || (pprop == NULL) )
    {
        retval = -1;
    }
    else
    {
        *pval = fdt32_to_cpu(*pprop);
    }

    return retval;
}

FDT_FUNC int32_t fdt_getprop_s32_array(const void *fdt, int nodeoffset, const char *name, int32_t *pvals, int *lenp)
{
    int len = 0;
    int32_t *pprop = NULL;
    int32_t i = 0;
    int32_t retval = 0;

    pprop = (int32_t *)fdt_getprop(fdt, nodeoffset, name, &len);
    if ((len % 4 != 0) || (*lenp < (len / 4)) || (pprop == NULL))
    {
        *lenp = 0;
        retval = -1;
    }
    else
    {
        len /= 4;
        *lenp = len;
        for (i = 0; i < len; i++)
        {
            pvals[i] = fdt32_to_cpu(pprop[i]);
        }
    }

    return retval;
}

FDT_FUNC int32_t fdt_getprop_u32_array(const void *fdt, int nodeoffset, const char *name, uint32_t *pvals,  int *lenp)
{
    int len = 0;
    uint32_t *pprop = NULL;
    int32_t i = 0;
    int32_t retval = 0;

    pprop = (uint32_t *)fdt_getprop(fdt, nodeoffset, name, &len);
    /*removing the check (*lenp) < (len / 4) so that api will return exact number of elements
     even it is passed with less number of elements */
  //  if ((len % 4 != 0) || (*lenp) < (len / 4) || (pprop == NULL))
    if ((len % 4 != 0) || (pprop == NULL))
    {
        *lenp = 0;
        retval = -1;
    }
    else
    {
        len /= 4;
        *lenp = len;
        for (i = 0; i < len; i++)
        {
            pvals[i] = fdt32_to_cpu(pprop[i]);
        }
    }

    return retval;
}

FDT_FUNC void __attribute__((used)) test_get_hyp_prop(void)
{
    int32_t offset = 0;
    uint32_t val_array[10];
    int32_t valSize = 10;
    void *pDTB = NULL;
    void *pDTBO = NULL;
    int i = 0;
    int j = 0;
    timetick_type_64 start = 0;
    timetick_type_64 end = 0;
    uint64_t time_us = 0;

    pDTB = fdt_get_dtb();
    if (NULL == pDTB)
    {
        while (1);
    }

    sail_timetick_init();
    start = timetick_get64();

    for (i = 0; i < 10000; i++)
    {
        offset = fdt_path_offset(pDTB, "/test_entry");
        for (j = 0; j < 20; j++)
        {
            fdt_getprop_u32(pDTB, offset, "test_value1", &val_array[0]);
        }
    }
    end = timetick_get64();

    time_us = elapsedtime_us(end, start);
    LOG_ERROR("%llu\n", time_us);

    start = timetick_get64();

    for (i = 0; i < 10000; i++)
    {
        offset = fdt_path_offset(pDTB, "/test_entry");
        for (j = 0; j < 20; j++)
        {
            fdt_getprop_u32(pDTB, offset, "test_value2", &val_array[0]);
        }
    }
    end = timetick_get64();

    time_us = elapsedtime_us(end, start);
    LOG_ERROR("%llu\n", time_us);

}
