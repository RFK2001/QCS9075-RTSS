/** 
    @file  hw_io.h
    @brief HW io macros
 */
/*=============================================================================
            Copyright (c) 2021-2025 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

#ifndef __HW_IO_H__
#define __HW_IO_H__


#define FLD_BMSK(reg, field) HWIO_##reg##_##field##_BMSK
#define FLD_SHFT(reg, field) HWIO_##reg##_##field##_SHFT

#define REG_IN(base, reg) \
    (*(volatile uint32 *)((uint32)base + (uint32)HWIO_##reg##_OFFS) & (uint32)HWIO_##reg##_RMSK)

#define REG_INI(base, reg, idx) \
    (*(volatile uint32 *)((uint32)base +(uint32) HWIO_##reg##_OFFS(idx)) & (uint32)HWIO_##reg##_RMSK)

#define REG_INII(base, reg, n, k) \
    (*(volatile uint32 *)((uint32)base +(uint32) HWIO_##reg##_OFFS(n,k)) & (uint32)HWIO_##reg##_RMSK)

#define REG_OUT(base, reg, data) \
    (*(volatile uint32 *)((uint32)base + (uint32)HWIO_##reg##_OFFS)) = (uint32)data

#define REG_OUTI(base, reg, idx, data) \
    (*(volatile uint32 *)((uint32)base + (uint32)HWIO_##reg##_OFFS(idx))) = (uint32)data

#define REG_OUTII(base, reg, n, k, data) \
    (*(volatile uint32 *)((uint32)base + (uint32)HWIO_##reg##_OFFS(n,k))) = (uint32)data

#define REG_INF(base, reg, field) \
    ((REG_IN(base, reg) & (uint32)FLD_BMSK(reg, field)) >> (uint32)FLD_SHFT(reg, field))

#define REG_OUTF(base, reg, field, data) \
    REG_OUT(base, reg, (( (uint32) REG_IN(base, reg) & ~( (uint32) FLD_BMSK(reg, field))) | (((uint32)data << (uint32) FLD_SHFT(reg, field)) & (uint32)FLD_BMSK(reg, field))))

#define FLD_SET(reg, field, data) \
    (((uint32) data << (uint32) FLD_SHFT(reg, field)) & (uint32) FLD_BMSK(reg, field))

#define FLD_GET(data, reg, field) \
    (((uint32)data & (uint32)FLD_BMSK(reg, field)) >> (uint32)FLD_SHFT(reg, field))


#endif
