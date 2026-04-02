/*
 * Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

#ifndef SAIL_BIST_INTERNAL_H_
#define SAIL_BIST_INTERNAL_H_

#include <stdint.h>

#define MD_BIST_DATA  __attribute__ ( ( section ("md_bist_data" ) ) )

#define SKU_DIFF 1UL

#define PHASE1_MBIST_ERR 1U
#define PHASE1_LBIST_ERR 2U
#define	PHASE2_MBIST_ERR 3U
#define PHASE2_LBIST_ERR 4U

#define INJ_SAIL_MBIST_ERR 0b1UL
#define INJ_SAIL_LBIST_ERR 0b10UL
#define INJ_MD_PH1_MBIST_ERR 0b100UL
#define INJ_MD_PH1_LBIST_ERR 0b1000UL
#define INJ_MD_PH2_MBIST_ERR 0b10000UL
#define INJ_MD_PH2_LBIST_ERR 0b100000UL

#endif //SAIL_BIST_INTERNAL_H_
