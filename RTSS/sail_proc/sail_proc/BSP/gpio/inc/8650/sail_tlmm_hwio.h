#ifndef SAIL_TLMM_HWIO_H
#define SAIL_TLMM_HWIO_H
/**
    @file sail_tlmm_hwio.h

*/
/*
    ===========================================================================

    Copyright (c) 2025 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/gpio/inc/8650/sail_tlmm_hwio.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

#include "msmhwiobase.h"

#ifdef monaco
#include <../monaco/sail_tlmm_hwio_monaco.h>

#else
#include <./sail_tlmm_hwio_8650.h>
#endif

#endif /*SAIL_TLMM_HWIO_H */
