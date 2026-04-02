/*
 *  * Copyright (c) Qualcomm Technologies, Inc.
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

#ifndef _DDRMILESTONE_H_
#define _DDRMILESTONE_H_

#include <stdint.h>
#include "freertos_init.h"

#define DDRMilestone_DDR_SUSPEND	( 0xD0030000U )

void vDDRMilestoneTask(void* pvParameters);

BaseType_t xDDRMilestoneTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior );
									 
extern QueueHandle_t xDDRMilestoneQHandle;

#endif /* _DDRMILESTONE_H_ */
