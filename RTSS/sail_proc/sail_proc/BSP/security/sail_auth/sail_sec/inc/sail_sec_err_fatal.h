/*===========================================================================
  Copyright (c) 2022 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential
===========================================================================*/
#ifndef SAIL_SEC_ERR_FATAL_H
#define SAIL_SEC_ERR_FATAL_H

#include <stdbool.h>

void sail_sec_err_fatal(uint32_t err_type) __attribute__((noreturn));

/* Handler to be called as a counter-measure when unexpected code-execution
 * is detected */
void sail_sec_fault_detected(void);

/* Random delay used as a counter-measure against glitching attacks */
void sail_sec_random_wait(void);

#endif /* SAIL_SEC_ERR_FATAL_H */
