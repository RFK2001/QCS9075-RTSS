#ifndef __SPINOR_LEARNING_H__
#define __SPINOR_LEARNING_H__
/*
===========================================================================
*/
/**
    @file  spinor_learning.h
    @brief psinor learning pattern algorithms and utility functions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_learning.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/

#include "types.h"
#include "spinor_cm_defs.h"

/*==================================================================================================
                                               MACROS
==================================================================================================*/

/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/

/**********************************************************
 * Check if NOR flash card's pattern matches the defined pattern
 *
 * @param result [IN/OUT] Result of the pattern match check
 *
 * @return int [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_learning_check_nor_pattern(boolean* result);
/**********************************************************
 * Write NOR pattern to NOR flash card memory
 *
 * @param NA
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinor_learning_write_nor_pattern(void);
/**********************************************************
 * Performs DDR DLP training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_learning_DDR_DLP_training(void);
/**********************************************************
 * Performs SDR DLL training
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_learning_SDR_DLL_training(void);

#endif  // __SPINOR_HAL_H__
