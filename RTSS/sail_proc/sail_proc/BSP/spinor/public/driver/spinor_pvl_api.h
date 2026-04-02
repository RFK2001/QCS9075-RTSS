#ifndef __SPINOR_PVL_API_H__
#define __SPINOR_PVL_API_H__

/*
===========================================================================
*/
/**
    @file  spinor_pvl_api.h
    @brief Public interface declaration for the Spinor PVL test.
           This file describes the spinor external interface.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/driver/spinor_pvl_api.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
#include "types.h"

#include "spinor_cm_defs.h"
SPINOR_STATUS spinor_pvl_enter_powder_down(void);
SPINOR_STATUS spinor_pvl_exit_powder_down(void);
SPINOR_STATUS spinor_pvl_sfdp_dump(void);
SPINOR_STATUS spinor_pvl_get_bus_type(boolean *bOSPI);
boolean spinor_pvl_check_dtr(void);
boolean spinor_pvl_check_read_114S(void);
boolean spinor_pvl_check_read_144S(void);
boolean spinor_pvl_check_read_118S(void);
boolean spinor_pvl_check_read_188S(void);
boolean spinor_pvl_check_888S(void);
uint32_t spinor_pvl_get_444_str_max_freq(void);
//uint32_t spinor_pvl_get_444_dtr_max_freq(void);
uint32_t spinor_pvl_get_888_dtr_max_freq(void);
//uint32_t spinor_pvl_get_888_str_max_freq(void);
uint32_t spinor_pvl_get_device_id(void);
#endif /* __SPINOR_PVL_API_H__ */
