/*
===========================================================================
*/
/**
	@file  xbl_diag.h
	@brief xbl diag header file

*/
/*
	===========================================================================

	Copyright (c) 2022 Qualcomm Technologies, Inc.
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

	===========================================================================

	$Header: $
	$DateTime: $
	$Author: $

	===========================================================================
*/


#ifndef __XBL_DIAG_H__
#define __XBL_DIAG_H__

#include <debug_log.h>

#define XBL_LOG_FATAL(format_str, args...)      LOG_ERROR(format_str, ##args)
#define XBL_LOG_ERROR(format_str, args...)      LOG_ERROR(format_str, ##args)
#define XBL_LOG_WARNING(format_str, args...)    LOG_WARNING(format_str, ##args)
#define XBL_LOG_INFO(format_str, args...)       LOG_INFO(format_str, ##args)
#define XBL_LOG_VERBOSE(format_str, args...)    LOG_DEBUG(format_str, ##args)
#define XBL_LOG_TRACE(format_str, args...)      LOG_DEBUG(format_str, ##args)

#endif
