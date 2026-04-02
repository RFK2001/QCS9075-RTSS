/********************************************************************************
    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
********************************************************************************/
/*===============================================================================
    File Name          : CDD_TestFramework.h
    Component Name     : AutoSAR based TestFramework
    Description        : Header file for testing modules
    $Header: $
    $DateTime: $
    $Author: $
================================================================================*/
#ifndef CDD_TESTFRAMEWORK_H__
#define CDD_TESTFRAMEWORK_H__

/*===============================================================================
 * Include Files
 *=============================================================================*/

#include <stdio.h>
#include "types.h"
#include "common_functions.h"


/*===============================================================================
**        Global typedefs : Enums, Structures Union and other typedefs         **
===============================================================================*/
typedef enum
{
    TEST_FRAMEWORK_UART = 0,
    TEST_FRAMEWORK_MB,
}TestFrameworkType;

typedef enum
{
    TEST_FRAMEWORK_STATUS_INACTIVE = 0,
    TEST_FRAMEWORK_STATUS_ACTIVE,
}TestFrameworkStatusType;


#define MAX_BUFF_LENG 58u
#define HAL_SAIL_TEST_RXBUFF_SIZE  	255U

extern TestFrameworkStatusType TestFrameworkStatus; 
/*===============================================================================
**                                    Global function prototypes               **
===============================================================================*/
extern uint8* APPL_Shell_gettoken(uint8* str);
extern uint8 APPL_Shell_stricmp(char const *str1, char const *str2);
void APPL_SAIL_Shell_start(TestFrameworkType eTFType, uint8* databuff);

#endif //__TESTFRAMEWORK_H__
