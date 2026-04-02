/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright 2017 The Fuchsia Authors
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 */
#pragma once


#include "reg.h"
#include "arm64.h"
#include "el2_cpu.h"
#include "arm_acle.h"

#define GICREG(gic, reg)         (*REG32(reg))
#define GICREG64(gic, reg)       (*REG64(reg))
#define GICD_OFFSET(cid)         arm_gicv3_gicd_offset[cid]
#define GICR_OFFSET(cid)         arm_gicv3_gicr_offset[cid]
#define GICR_STRIDE(cid)         arm_gicv3_gicr_stride[cid]


static inline void gic_write_ctlr(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 4);
    ISB;
    DSB;
}

static inline void gic_write_pmr(uint32_t val)
{
    __arm_mcr(15, 0, val, 4, 6, 0);
    ISB;
    DSB;
}

static inline void gic_write_igrpen0(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 6);
    ISB;
    DSB;
}

static inline void gic_write_igrpen(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 7);
    ISB;
    DSB;
}

static inline uint32_t gic_read_sre(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 12, 5);
    ISB;
    DSB;
    return val;
}

static inline void gic_write_sre(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 5);
    ISB;
    DSB;
}

static inline void gic_write_eoir0(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 8, 1);
    ISB;
    DSB;
}

static inline void gic_write_eoir(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 1);
    ISB;
    DSB;
}

static inline uint32_t gic_read_iar0(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 8, 0);
    ISB;
    DSB;
    return val;
}

static inline uint32_t gic_read_iar(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 12, 0);
    ISB;
    DSB;
    return val;
}

static inline void gic_write_sgi1r(uint64 val)
{
    __arm_mcrr(15, 0, val, 12);
    ISB;
    DSB;
}

/* distributor registers */

#define GICD_CTLR(cid)               ((GICD_OFFSET(cid)) + 0x0000)
#define GICD_TYPER(cid)              ((GICD_OFFSET(cid)) + 0x0004)
#define GICD_IIDR(cid)               ((GICD_OFFSET(cid)) + 0x0008)
#define GICD_IGROUPR(cid,n)          ((GICD_OFFSET(cid)) + 0x0080 + (n) * 4)
#define GICD_ISENABLER(cid,n)        ((GICD_OFFSET(cid)) + 0x0100 + (n) * 4)
#define GICD_ICENABLER(cid,n)        ((GICD_OFFSET(cid)) + 0x0180 + (n) * 4)
#define GICD_ISPENDR(cid,n)          ((GICD_OFFSET(cid)) + 0x0200 + (n) * 4)
#define GICD_ICPENDR(cid,n)          ((GICD_OFFSET(cid)) + 0x0280 + (n) * 4)
#define GICD_ISACTIVER(cid,n)        ((GICD_OFFSET(cid)) + 0x0300 + (n) * 4)
#define GICD_ICACTIVER(cid,n)        ((GICD_OFFSET(cid)) + 0x0380 + (n) * 4)
#define GICD_IPRIORITYR(cid,n)       ((GICD_OFFSET(cid)) + 0x0400 + (n) * 4)
#define GICD_ITARGETSR(cid,n)        ((GICD_OFFSET(cid)) + 0x0800 + (n) * 4)
#define GICD_ICFGR(cid,n)            ((GICD_OFFSET(cid)) + 0x0c00 + (n) * 4)
//#define GICD_NSACR(cid,n)          ((GICD_OFFSET(cid)) + 0x0e00 + (n) * 4)
//#define GICD_SGIR(cid)             ((GICD_OFFSET(cid)) + 0x0f00)
//#define GICD_CPENDSGIR(cid,n)      ((GICD_OFFSET(cid)) + 0x0f10 + (n) * 4)
//#define GICD_SPENDSGIR(cid,n)      ((GICD_OFFSET(cid)) + 0x0f20 + (n) * 4)
#define GICD_IROUTER(cid, n)         ((GICD_OFFSET(cid)) + 0x6000 + (n) * 8)

/* redistributor registers */

#define GICR_SGI_OFFSET(cid)         ((GICR_OFFSET(cid)) + 0x10000)
                                    
#define GICR_CTLR(cid,i)             ((GICR_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0000)
#define GICR_IIDR(cid,i)             ((GICR_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0004)
#define GICR_TYPER(cid,i,n)          ((GICR_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0008 + (n) * 4)
#define GICR_STATUSR(cid,i)          ((GICR_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0010)
#define GICR_WAKER(cid,i)            ((GICR_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0014)
#define GICR_IGROUPR0(cid,i)         ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0080)
#define GICR_IGRPMOD0(cid,i)         ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0d00)
#define GICR_ISENABLER0(cid,i)       ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0100)
#define GICR_ICENABLER0(cid,i)       ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0180)
#define GICR_ISPENDR0(cid,i)         ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0200)
#define GICR_ICPENDR0(cid,i)         ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0280)
#define GICR_ISACTIVER0(cid,i)       ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0300)
#define GICR_ICACTIVER0(cid,i)       ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0380)
#define GICR_IPRIORITYR0(cid,i)      ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0400)
#define GICR_ICFGR0(cid,i)           ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0c00)
#define GICR_ICFGR1(cid,i)           ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0c04)
//#define GICR_NSACR(cid,i)          ((GICR_SGI_OFFSET(cid)) + GICR_STRIDE(cid) * (i) + 0x0e00)

/* peripheral identification registers */

#define GICD_PIDR0(cid)              ((GICD_OFFSET(cid)) + 0xffe0)
#define GICD_PIDR1(cid)              ((GICD_OFFSET(cid)) + 0xffe4)
#define GICD_PIDR2(cid)              ((GICD_OFFSET(cid)) + 0xffe8)
#define GICD_PIDR3(cid)              ((GICD_OFFSET(cid)) + 0xffec)
#define GICD_CIDR0(cid)              ((GICD_OFFSET(cid)) + 0xfff0)
#define GICD_CIDR1(cid)              ((GICD_OFFSET(cid)) + 0xfff4)
#define GICD_CIDR2(cid)              ((GICD_OFFSET(cid)) + 0xfff8)
#define GICD_CIDR3(cid)              ((GICD_OFFSET(cid)) + 0xfffc)

