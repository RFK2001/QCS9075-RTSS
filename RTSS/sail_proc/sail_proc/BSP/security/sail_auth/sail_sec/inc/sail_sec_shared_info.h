/*===========================================================================
 Copyright (c) 2022 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifndef PBL_SEC_SHARED_INFO_H
#define PBL_SEC_SHARED_INFO_H

#include "pbl_sail_tee_shared.h"

pbl_secboot_shared_info_type *sail_sec_get_secboot_shared_data(void);

int sail_sec_copy_pbl_shared_info(void * pbl_shared_data);

sec_img_auth_elf_info_type *sail_sec_get_elf_meta_info(void);

boot_flash_type sail_sec_get_flash_type(void);

//boot_sbl_qsee_interface* xbl_sec_get_shared_info_ptr(void);

#endif /* PBL_SEC_SHARED_INFO_H */
