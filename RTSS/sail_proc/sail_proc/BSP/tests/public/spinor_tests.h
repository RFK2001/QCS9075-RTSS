#ifndef __SPINOR_TESTS_H__
#define __SPINOR_TESTS_H__

/*
===========================================================================
*/
/**
    @file  spinor_tests.h
    @brief Common defines shared between SPINOR EL2 and EL1 testcases.

*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/tests/public/spinor_tests.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_cm_defs.h"

/* Event IDs for SPINOR Tests trap calls */
typedef enum
{
    SPINOR_TEST_TRAP_FUNC_ERASERD = 1,
    SPINOR_TEST_TRAP_FUNC_WRITERD,
    SPINOR_TEST_TRAP_FUNC_INVPARAMS,
    SPINOR_TEST_TRAP_FUNC_VALREAD,
    SPINOR_TEST_TRAP_FUNC_UNALIGNLP,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_1,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_2,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_3,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_4,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_5,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_6,
    SPINOR_TEST_TRAP_FUNC_SUPUSER_7,
    SPINOR_TEST_TRAP_FUNC_LOWPWR,
    SPINOR_TEST_TRAP_FUNC_ERASE_STARTEND,
    SPINOR_TEST_TRAP_FUNC_MAX
}spinorTrapTestEventID_t;

#endif /* __SPINOR_TESTS_H__ */
