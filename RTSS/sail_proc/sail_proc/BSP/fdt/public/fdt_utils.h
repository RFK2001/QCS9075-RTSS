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

#ifndef _FDT_UTILS_H
#define _FDT_UTILS_H

#include <stdint.h>

FDT_FUNC void *fdt_get_dtb(void);
FDT_FUNC void *fdt_get_dtbo(void);
FDT_FUNC int32_t fdt_util_apply_overlay(void);

FDT_FUNC size_t strnlen(const char *s, size_t maxlen);

FDT_FUNC int32_t fdt_getprop_s32(const void *fdt, int nodeoffset, const char *name, int32_t *pval);
FDT_FUNC int32_t fdt_getprop_u32(const void *fdt, int nodeoffset, const char *name, uint32_t *pval);
FDT_FUNC void fdt_getprop_float(const void *fdt, int nodeoffset, const char *name,float *read_data);

FDT_FUNC int32_t fdt_getprop_s32_array(const void *fdt, int nodeoffset, const char *name, int32_t *pval, int *lenp);
FDT_FUNC int32_t fdt_getprop_u32_array(const void *fdt, int nodeoffset, const char *name, uint32_t *pval, int *lenp);

#endif  /* _FDT_UTILS_H */
