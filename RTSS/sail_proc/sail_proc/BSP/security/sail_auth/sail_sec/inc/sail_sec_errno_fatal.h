
/*===========================================================================
 Copyright (c) 2017-2022 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifndef XBL_SEC_ERRNO_FATAL_H
#define XBL_SEC_ERRNO_FATAL_H

#define XBL_SEC_ERR_FATAL_NONE                         0x0

#define XBL_SEC_ERR_FATAL_EL3_SP_EL0_SYNCH             0x1
#define XBL_SEC_ERR_FATAL_EL3_SP_EL0_IRQ               0x2
#define XBL_SEC_ERR_FATAL_EL3_SP_EL0_FIQ               0x3
#define XBL_SEC_ERR_FATAL_EL3_SP_EL0_ERR               0x4
#define XBL_SEC_ERR_FATAL_EL3_SP_EL3_SYNCH             0x5
#define XBL_SEC_ERR_FATAL_EL3_SP_EL3_IRQ               0x6
#define XBL_SEC_ERR_FATAL_EL3_SP_EL3_FIQ               0x7
#define XBL_SEC_ERR_FATAL_EL3_SP_EL3_ERR               0x8
#define XBL_SEC_ERR_FATAL_EL3_LEL64_SYNCH              0x9
#define XBL_SEC_ERR_FATAL_EL3_LEL64_IRQ                0xA
#define XBL_SEC_ERR_FATAL_EL3_LEL64_FIQ                0xB
#define XBL_SEC_ERR_FATAL_EL3_LEL64_ERR                0xC
#define XBL_SEC_ERR_FATAL_EL3_LEL32_SYNCH              0xD
#define XBL_SEC_ERR_FATAL_EL3_LEL32_IRQ                0xE
#define XBL_SEC_ERR_FATAL_EL3_LEL32_FIQ                0xF
#define XBL_SEC_ERR_FATAL_EL3_LEL32_ERR                0x10

#define XBL_SEC_ERR_FATAL_EL1_SP_EL0_SYNCH             0x11
#define XBL_SEC_ERR_FATAL_EL1_SP_EL0_IRQ               0x12
#define XBL_SEC_ERR_FATAL_EL1_SP_EL0_FIQ               0x13
#define XBL_SEC_ERR_FATAL_EL1_SP_EL0_ERR               0x14
#define XBL_SEC_ERR_FATAL_EL1_SP_EL1_SYNCH             0x15
#define XBL_SEC_ERR_FATAL_EL1_SP_EL1_IRQ               0x16
#define XBL_SEC_ERR_FATAL_EL1_SP_EL1_FIQ               0x17
#define XBL_SEC_ERR_FATAL_EL1_SP_EL1_ERR               0x18
#define XBL_SEC_ERR_FATAL_EL1_LEL64_SYNCH              0x19
#define XBL_SEC_ERR_FATAL_EL1_LEL64_IRQ                0x1A
#define XBL_SEC_ERR_FATAL_EL1_LEL64_FIQ                0x1B
#define XBL_SEC_ERR_FATAL_EL1_LEL64_ERR                0x1C
#define XBL_SEC_ERR_FATAL_EL1_LEL32_SYNCH              0x1D
#define XBL_SEC_ERR_FATAL_EL1_LEL32_IRQ                0x1E
#define XBL_SEC_ERR_FATAL_EL1_LEL32_FIQ                0x1F
#define XBL_SEC_ERR_FATAL_EL1_LEL32_ERR                0x20

#define XBL_SEC_ERR_FATAL_INIT_FAILED                  0x21
#define XBL_SEC_ERR_FATAL_STACK_CHK_FAILED             0x22
#define XBL_SEC_ERR_FATAL_INVALID_TZ_ENTRY_ADDR        0x23

#define XBL_SEC_ERR_FATAL_AC_FAILURE                   0x24
#define XBL_SEC_ERR_FATAL_WLIST_UPDATE_FAILED          0x25
#define XBL_SEC_ERR_FATAL_MILESTONE_SET_FAILED         0x26
#define XBL_SEC_ERR_FATAL_AC_VMIDMT_SMMU_FAILURE       0x27

#define XBL_SEC_ERR_FATAL_MON_PREFETCH_ABT             0x28
#define XBL_SEC_ERR_FATAL_MON_DATA_ABT                 0x29
#define XBL_SEC_ERR_FATAL_MON_ASM_0                    0x2A
#define XBL_SEC_ERR_FATAL_MON_ASM_1                    0x2B
#define XBL_SEC_ERR_FATAL_MON_ASM_2                    0x2C
#define XBL_SEC_ERR_FATAL_MON_IRQ                      0x2D
#define XBL_SEC_ERR_FATAL_MON_FIQ                      0x2E

#define XBL_SEC_ERR_FATAL_FAULT_DETECTED               0x2F
#define XBL_SEC_ERR_FATAL_MAPPING_FAILURE              0x30
#define XBL_SEC_ERR_FATAL_INVALID_APPS_ENTRY_ADDR      0x31
#define XBL_SEC_ERR_FATAL_INTEGER_OVERFLOW             0x32

/** XPU id 0x%x, errFlags: %x, busFlags: %x, Addr: %x, MasterId: %x, VMID: %x, TID: %x, BID: %x, PID: %x, Len: %x, Size: %x, ReqPriority: %x, MemType: %x */
#define XBL_SEC_ERR_FATAL_XPU_ERROR                    0x33
#define XBL_SEC_ERR_FATAL_AC_CLEAR_MAP_FAILURE         0x34
#define XBL_SEC_ERR_FATAL_AC_CLEAR_UNMAP_FAILURE       0x35
#define XBL_SEC_ERR_FATAL_AC_CLEAR_FAILURE             0x36
#define XBL_SEC_ERR_FATAL_AC_LOCK_FAILURE              0x37
#define XBL_SEC_ERR_FATAL_AC_UNLOCK_FAILURE            0x38
#define XBL_SEC_ERR_FATAL_IMG_MAP_NOT_FOUND            0x39

#define XBL_SEC_ERR_FATAL_PIMEM_INIT_FAILURE           0x3A
#define XBL_SEC_ERR_FATAL_MILESTONE_INVALID_PARAM      0x3B
#define XBL_SEC_ERR_FATAL_IMG_SHARED_PTR_INIT_FAILED   0x3C

#define XBL_SEC_ERR_FATAL_SEC_MEM_RGN_INVALID_PARAM    0x3D
#define XBL_SEC_ERR_FATAL_MEASURED_BOOT_INVALID_PARAM  0X3E
#define XBL_SEC_ERR_FATAL_HASH_INIT_FAILURE            0x3F
#define XBL_SEC_ERR_FATAL_HASH_UPDATE_FAILURE          0x40
#define XBL_SEC_ERR_FATAL_HASH_FINAL_FAILURE           0x41
#define XBL_SEC_ERR_FATAL_HASH_DEINIT_FAILURE          0x42
#define XBL_SEC_ERR_FATAL_AC_IMG_ADDR_MAP_FAILURE      0x43

#define XBL_SEC_ERR_FATAL_WFI_FAILURE                  0x43

#define XBL_SEC_ERR_FATAL_PAUTH_REGS_INIT_FAILURE      0x44

#define XBL_SEC_ERR_FATAL_SWIV_VERIFICATION_FAILED	   0x45

#endif /* XBL_SEC_ERRNO_FATAL_H */
