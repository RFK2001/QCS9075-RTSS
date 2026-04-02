/*
===========================================================================
*/
/**
	@file  pvl_api.h
	@brief pvl api definitions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pvl/public/pvl_api.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

	===========================================================================
*/

#ifndef __PVL_API_H__
#define __PVL_API_H__

#include "types.h"

//#define NORPVL_ENB
#define PVL_OK     0
#define PVL_ERROR  -1

void vPvlInit(void);
void vPvlTest(char* cmd, char* param0, char* param1, char* param2);

#endif /* __PVL_API_H__ */
