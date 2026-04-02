/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright 2017 The Fuchsia Authors
 * Portions Copyright (c) 2017, Google Inc. All rights reserved.
 *
 * Use of this source code is governed by a MIT-style
 * license that can be found in the LICENSE file or at
 * https://opensource.org/licenses/MIT
 *
 * Portions Copyright (c) 2012-2015 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "FreeRTOSOsal.h"
#include "reg.h"
#include "arch_ops.h"
#include "sailbsp_mutex.h"
#include "arm64.h"
#include "arm_acle.h"
#include "interrupts.h"
#include "types.h"
#include "sail_mem_map.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

#define GIC_MAX_INT                                 ( 992U )
#define GIC_NUM_SGI_PPI_INT                         ( 32U )
#define GICD_CTRL_GROUP1_MASK                       ( (uint32_t) 0x02U )
#define GIC_CLUSTER_FLAG_ADD(CLUSTER)               ( FreeRTOS_##CLUSTER##_GIC_FLAG_MEM_ADD )
#define GIC_CLUSTER_SPIN_LOCK_ADD(CLUSTER)          ( FreeRTOS_##CLUSTER##_SPIN_LOCK_MEM_ADD )
#define GICD_CTRL_ARE_EN                            ( (uint32_t) (0x1U << 4U) )
#define GIC_IRM_AFFINITY_BASED                      ( (uint64_t) (0x0ULL << 31U) )
#define GIC_IRM_ANY_PARTICIPATING                   ( (uint64_t) (0x1ULL << 31U) )
#define ICC_IAR_INTID_MASK                          ( (uint32_t) 0x3FFU )

/*=========================================================================================================
**                          Local typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/* Structure of Interrupt handler */
struct intHandlerStruct {
    uint32_t vector;
    InterruptHandle_t handler;
    void *arg;
};

typedef struct __gicHwConfig {
    //ToDO check if we need to add anything else here
    //ToDo we shoud have a better type for HWIO address to change it to uint64.
    uint32_t    gicDistributorOffset;
    uint32_t    gicRedistributorOffset;
    uint32_t    gicRedistributorStride;
}gicHwConfig_t;

/*=========================================================================================================
**                                             Local Variables                                          **
=========================================================================================================*/
gicHwConfig_t xGicInstances[configNUMBER_OF_CLUSTERS] = {
                                                            { 0xFD200000, 0xFD300000, 0x20000},
                                                            { 0xFD400000, 0xFD500000, 0x20000}
                                                        };

/* spin lock address for synchronization between cores in the same cluster . one lock for each cluster */
static mutex_t     *pxClusterLock[]          = { (mutex_t*)GIC_CLUSTER_SPIN_LOCK_ADD(0), (mutex_t*)GIC_CLUSTER_SPIN_LOCK_ADD(1) };
static uint32_t *pxGICDClusterInitFlag[]  = { (uint32_t *)GIC_CLUSTER_FLAG_ADD(0), (uint32_t *)GIC_CLUSTER_FLAG_ADD(1) };

static uint32_t ulArmGicv3GicBase[configNUMBER_OF_CLUSTERS] = {0};
static uint32_t ulArmGicv3GicdOffset[configNUMBER_OF_CLUSTERS] = {0};
static uint32_t ulArmGicv3GicrOffset[configNUMBER_OF_CLUSTERS] = {0};
static uint32_t ulArmGicv3GicrStride[configNUMBER_OF_CLUSTERS] = {0};


#if ( configNUMBER_OF_CORES > 1 )
static struct intHandlerStruct xIntHandlerTablePerCore[ configNUMBER_OF_CLUSTERS ][ configNUMBER_OF_CORES_PER_CLUSTER ][ GIC_NUM_SGI_PPI_INT ] = { 0 };
static struct intHandlerStruct xIntHandlerTableSharedPerCluster[ configNUMBER_OF_CLUSTERS ][ (GIC_MAX_INT - GIC_NUM_SGI_PPI_INT) ] = { 0 };
#else
static struct intHandlerStruct xIntHandlerTable[ GIC_MAX_INT ] = { 0 };
#endif/* #if ( configNUMBER_OF_CORES > 1 ) */

/*=========================================================================================================
**                                        Local function prototypes                                      **
=========================================================================================================*/
static void prvGicWaitForRwp(uint64_t reg);
static void prvGicSwitchOnGicr(uint64_t reg);
static void prvGicParamsInit(uint32_t cluster);
static void prvGicConfigureIntSGI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster, uint32_t cpu);
static void prvGicConfigureIntPPI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster, uint32_t cpu);
static void prvGicConfigureIntSPI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster);
static void prvGicUpdateIntRouting(uint32_t vector, uint64_t affinity);
static void prvGicSetIntGroup(uint32_t vector, uint32_t group);

#define GIC_CLUSTER_SPIN_LOCK_TAKE(clusterID)                mutex_lock(pxClusterLock[clusterID])
#define GIC_CLUSTER_SPIN_LOCK_GIVE(clusterID)                mutex_unlock(pxClusterLock[clusterID])

/*=========================================================================================================
**                                     GIC Register Mapping                                             **
=========================================================================================================*/
#define GICREG(gic, reg)         (*REG32(reg))
#define GICREG64(gic, reg)       (*REG64(reg))
#define GICD_OFFSET(cid)         ulArmGicv3GicdOffset[cid]
#define GICR_OFFSET(cid)         ulArmGicv3GicrOffset[cid]
#define GICR_STRIDE(cid)         ulArmGicv3GicrStride[cid]

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

/*=========================================================================================================
**                                        Inline ASM Funcation                                          **
=========================================================================================================*/
static inline void vIccWriteCtlr(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 4);
    ISB;
    DSB;
}

static inline void vIccWritePmr(uint32_t val)
{
    __arm_mcr(15, 0, val, 4, 6, 0);
    ISB;
    DSB;
}

static inline void vIccWriteIgrpen0(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 6);
    ISB;
    DSB;
}

static inline void vIccWriteIgrpen1(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 7);
    ISB;
    DSB;
}

static inline uint32_t ulIccReadSre(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 12, 5);
    ISB;
    DSB;
    return val;
}

static inline void vIccWriteSre(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 5);
    ISB;
    DSB;
}

static inline void vIccWriteEoir0(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 8, 1);
    ISB;
    DSB;
}

static inline void vIccWriteEoir1(uint32_t val)
{
    __arm_mcr(15, 0, val, 12, 12, 1);
    ISB;
    DSB;
}

static inline uint32_t ulIccReadIar0(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 8, 0);
    ISB;
    DSB;
    return val;
}

static inline uint32_t ulIccReadIar1(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 12, 12, 0);
    ISB;
    DSB;
    return val;
}

static inline void vIccWriteSgi1r(uint64 val)
{
    __arm_mcrr(15, 0, val, 12);
    ISB;
    DSB;
}


/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/
intEl1Status_t xGicInitEl1( void )
{
    intEl1Status_t xRet = INT_EL1_ERR_GENERIC;
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    uint32_t interruptIdx = 0x0U;
    uint32_t ulSreVal = 0x0U;

    /* Initialise EL1 Interrupt table for IRQs */
    #if ( configNUMBER_OF_CORES > 1 )
        for(interruptIdx = 0U; interruptIdx < (uint32_t)GIC_NUM_SGI_PPI_INT; interruptIdx++)
        {
            xIntHandlerTablePerCore[cluster][cpu][interruptIdx].vector = (uint32_t) 0x0U;
            xIntHandlerTablePerCore[cluster][cpu][interruptIdx].handler = NULL;
            xIntHandlerTablePerCore[cluster][cpu][interruptIdx].arg = NULL;
        }
    #else
        for(interruptIdx = 0U; interruptIdx < (uint32_t)GIC_MAX_INT; interruptIdx++)
        {
            xIntHandlerTable[interruptIdx].vector = (uint32_t) 0x0U;
            xIntHandlerTable[interruptIdx].handler = NULL;
            xIntHandlerTable[interruptIdx].arg = NULL; 
        }
    #endif

    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);
	
    /* Initalise GIC one time per cluster */
    if( *pxGICDClusterInitFlag[cluster] != (uint32_t)TRUE )
	{
		*pxGICDClusterInitFlag[cluster] = (uint32_t)TRUE;
        prvGicParamsInit(cluster);

        #if ( configNUMBER_OF_CORES > 1 )
            for(interruptIdx = 0U; interruptIdx < (uint32_t)(GIC_MAX_INT - GIC_NUM_SGI_PPI_INT); interruptIdx++)
            {
                xIntHandlerTableSharedPerCluster[cluster][interruptIdx].vector = (uint32_t) 0x0U;
                xIntHandlerTableSharedPerCluster[cluster][interruptIdx].handler = NULL;
                xIntHandlerTableSharedPerCluster[cluster][interruptIdx].arg = NULL;
            }
        #endif
	}
	else
	{
        GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);
		return INT_EL1_SUCCESS;
	}
	
	GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    /* Read ICC_SRE to check if system registers can access the GIC CPU interface. */
    ulSreVal = ulIccReadSre();
    if ( !(ulSreVal & ((uint32_t)0x1U)) ) {
        vIccWriteSre( ulSreVal | ((uint32_t)0x1U) );
        ulSreVal = ulIccReadSre();
        configASSERT(ulSreVal & ((uint32_t)0x1U));
    }

    /* when switch on a GICR need to write 0 to GICR_WAKER and then read it back,
    polling until the value you read is 0. To ensure processor is Awake and in predictable state.*/
    GICREG(0x0U, GICR_WAKER(cluster,cpu)) = 0x0U;
    prvGicSwitchOnGicr(GICR_WAKER(cluster,cpu));

    /* Disable Group 1 Interrupts */
    GICREG(0x0U, GICD_CTLR(cluster)) &= ~GICD_CTRL_GROUP1_MASK;
    vIccWriteIgrpen1(0);

    /* Clear sgi/ppi */
    GICREG(0x0U, GICR_ICPENDR0(cluster,cpu)) = 0xFFFFFFFF;
    prvGicWaitForRwp(GICR_CTLR(cluster,cpu));

    GICREG(0x0U, GICR_ICENABLER0(cluster,cpu)) = 0xFFFFFFFF;
    prvGicWaitForRwp(GICR_CTLR(cluster,cpu));

    /* Clear all spi */
    //TODO: read TYPER to check max supported interrupts (IRQs). 
    for (interruptIdx = 32U; interruptIdx < (uint32_t)GIC_MAX_INT; interruptIdx += 32U) {
        GICREG(0x0U, GICD_ICENABLER(cluster, interruptIdx / 32U)) = ~0U;
        GICREG(0x0U, GICD_ICPENDR(cluster, interruptIdx / 32U)) = ~0U;
    }
    prvGicWaitForRwp(GICD_CTLR(cluster));

    // set priority threshold to max
    vIccWritePmr((uint32_t)0xFFU);

    /* Enable distributor with ARE, group 1 enable */
    GICREG(0, GICD_CTLR(cluster)) |= (GICD_CTRL_ARE_EN | GICD_CTRL_GROUP1_MASK);
    vIccWriteIgrpen1(1U);

    return INT_EL1_SUCCESS;
}

intEl1Status_t xGicConfigureInt(uint32_t vector, enum InterruptConfig_t icfg, void* arg)
{
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();  
    
    if (vector >= (uint32_t)GIC_MAX_INT)
        return INT_EL1_ERR_OUT_OF_RANGE;

    if (icfg >= EL1_INT_CONFIG_MAX)
        return INT_EL1_ERR_OUT_OF_RANGE;

    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);

    if(vector < (uint32_t)16U)
    { 
        prvGicConfigureIntSGI(vector,icfg,cluster,cpu);
    }
    else if(vector >= ( (uint32_t)16U ) && vector < ( (uint32_t)32U ) )
    {
        prvGicConfigureIntPPI(vector,icfg,cluster,cpu);
    }
    else 
    {
        prvGicConfigureIntSPI(vector,icfg,cluster);
        
        //Currently, SPI interrupt routing/affinity is applied to the Core, which call the interrupt configuration.
        prvGicUpdateIntRouting(vector, (uint64_t)cpu);
    }

    prvGicSetIntGroup(vector, 0x1U);

    GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    return INT_EL1_SUCCESS;
}

intEl1Status_t xGicSetIntPriority(uint32_t vector, uint32_t priority)
{
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    uint32_t priorityRegisterAddress;
    uint32_t priorityValue;
    uint32_t priorityShiftValue;
    
    if (vector >= (uint32_t)GIC_MAX_INT)
    {
        return INT_EL1_ERR_OUT_OF_RANGE;
    }

    if(vector < (uint32_t)32U)
    {
        priorityRegisterAddress = GICR_IPRIORITYR0(cluster,cpu) + ((vector/0x4U) * 4U);
    }
    else
    {
        priorityRegisterAddress = GICD_IPRIORITYR(cluster,(vector/0x4U));
    }

    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);

    priorityShiftValue = (vector % 0x4U) * 0x8U;
    priorityValue = GICREG(0, priorityRegisterAddress);
    priorityValue &= ~( 0xFFU << priorityShiftValue );
    priorityValue |= ( priority << priorityShiftValue );
    GICREG(0, priorityRegisterAddress) = priorityValue;

    GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    return INT_EL1_SUCCESS;
}

intEl1Status_t xGicSetIntEnable(uint vector, bool enable)
{
    int reg = vector / 32;
    uint32_t mask = 1ULL << (vector % 32);
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();

    if (vector >= (uint32_t)GIC_MAX_INT)
    {
        return INT_EL1_ERR_OUT_OF_RANGE;
    }

    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);

    if (vector < 32) {
        if (enable)
            GICREG(0, GICR_ISENABLER0(cluster,cpu)) = mask;
        else
            GICREG(0, GICR_ICENABLER0(cluster,cpu)) = mask;

        prvGicWaitForRwp(GICR_CTLR(cluster,cpu));
    }else{        
        if (enable)
            GICREG(0, GICD_ISENABLER(cluster,reg)) = mask;
        else
            GICREG(0, GICD_ICENABLER(cluster,reg)) = mask;
        
        prvGicWaitForRwp(GICD_CTLR(cluster));

    }

    GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    return INT_EL1_SUCCESS;
}

intEl1Status_t xGicRegisterIntHandler(uint32_t vector, InterruptHandle_t handler, void *arg)
{
    struct intHandlerStruct *h;
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    intEl1Status_t xRet = INT_EL1_ERR_GENERIC;

    if (vector >= (uint32_t)GIC_MAX_INT)
        return INT_EL1_ERR_OUT_OF_RANGE;

    if (handler == NULL)
        return INT_EL1_ERR_BAD_HANDLE;

    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);
    
    //TOOD: block multiple cores registering for same SPI in case of non-SMP by using shared memory location.
    #if ( configNUMBER_OF_CORES > 1 )
        if( vector < (uint32_t)GIC_NUM_SGI_PPI_INT )
        {
            h = &xIntHandlerTablePerCore[cluster][cpu][vector];
        }else
        {
            h = &xIntHandlerTableSharedPerCluster[cluster][ (vector - (uint32_t)GIC_NUM_SGI_PPI_INT) ];
        }
    #else
        h = &xIntHandlerTable[vector];
    #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

    if(h == NULL)
    {
        GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);
        return INT_EL1_ERR_BAD_HANDLE;
    }

    //If no one has registered for the interrupt we go ahead with the registration
    if ( h->vector == 0 )
    {
        h->vector = vector;
        h->handler = handler;
        h->arg = arg;

        xRet = INT_EL1_SUCCESS;
    }
    else {
        /* interrupt handler already exists. */
        xRet = INT_EL1_ERR_ALREADY_EXISTS;
    }

    GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    return xRet;
}

intEl1Status_t xGicUnRegisterIntHandler(uint32_t vector, uint32_t flags)
{
    struct intHandlerStruct *h;
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    intEl1Status_t xRet = INT_EL1_ERR_GENERIC;

     if (vector >= (uint32_t)GIC_MAX_INT)
        return INT_EL1_ERR_OUT_OF_RANGE;
    
    GIC_CLUSTER_SPIN_LOCK_TAKE(cluster);
    
    #if ( configNUMBER_OF_CORES > 1 )
        if( vector < (uint32_t)GIC_NUM_SGI_PPI_INT )
        {
            h = &xIntHandlerTablePerCore[cluster][cpu][vector];
        }else
        {
            h = &xIntHandlerTableSharedPerCluster[cluster][ (vector - (uint32_t)GIC_NUM_SGI_PPI_INT) ];
        }
    #else
        h = &xIntHandlerTable[vector];
    #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

    if(h == NULL)
    {
        GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);
        return INT_EL1_ERR_BAD_HANDLE;
    }
    //If no one has registered for the interrupt we go ahead with the registration
    if (h->vector == vector )
    {
        h->vector = 0x0;
        h->handler = NULL;
        h->arg = NULL;
        
        xRet = INT_EL1_SUCCESS;      
    }
    else {
        xRet = INT_EL1_ERR_ALREADY_EXISTS;
    }

    GIC_CLUSTER_SPIN_LOCK_GIVE(cluster);

    return xRet;
}

void vApplicationFPUSafeIRQHandler(uint32_t ulIccIar1 )
{
    struct intHandlerStruct *h;
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();

    uint32_t vector = ulIccIar1 & ICC_IAR_INTID_MASK;

    if( vector < GIC_MAX_INT )
    {
        #if ( configNUMBER_OF_CORES > 1 )
        if( vector < (uint32_t)GIC_NUM_SGI_PPI_INT )
        {
            h = &xIntHandlerTablePerCore[cluster][cpu][vector];
        }else
        {
            h = &xIntHandlerTableSharedPerCluster[cluster][ (vector - (uint32_t)GIC_NUM_SGI_PPI_INT) ];
        }
        #else
            h = &xIntHandlerTable[vector];
        #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

        if( h && (h->handler) )
        {
            h->handler(h->arg);
        }
        else
        {
            //TODO: add Error Hook to return Errors.
        }
    }
    else
    {
        //TODO: add Error Hook to return Errors.
    }
}

/*=========================================================================================================
**                                        Local functions definition                                     **
=========================================================================================================*/
static void prvGicWaitForRwp(uint64_t reg)
{
    uint32_t count = 1000000;
    while (GICREG(0, reg) & (1 << 31)) {
        count -= 1;
        if (!count) {
            //TODO return err incase of count execced.
            return;
        }
    }
}

static void prvGicSwitchOnGicr(uint64_t reg)
{
    uint32_t count = 1000000;
    while (GICREG(0, reg) !=0) {
        count -= 1;
        if (!count) {
            //TODO return err incase of count execced.
            return;
        }
    }
}

static void prvGicParamsInit(uint32_t cluster)
{
  ulArmGicv3GicBase[cluster] = 0x00U;
  ulArmGicv3GicdOffset[cluster] = xGicInstances[cluster].gicDistributorOffset;
  ulArmGicv3GicrOffset[cluster] = xGicInstances[cluster].gicRedistributorOffset;
  ulArmGicv3GicrStride[cluster] = xGicInstances[cluster].gicRedistributorStride;
  //ipi_base = targ_ipi_base; //ToDo check the use of this and renable later.
}

static void prvGicConfigureIntSGI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster, uint32_t cpu)
{
    switch (icfg)
    {
       case EL1_INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR0(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICR_ICFGR0(cluster,cpu)) = cfg_val;
         }
       break;

       case EL1_INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR0(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICR_ICFGR0(cluster,cpu)) = cfg_val;
         }
       break;

     default:
       break;
    }
}

static void prvGicConfigureIntPPI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster, uint32_t cpu)
{
    switch (icfg)
    {
       case EL1_INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR1(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICR_ICFGR1(cluster,cpu)) = cfg_val;
         }
       break;

       case EL1_INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset;

           cfg_val = GICREG(0, GICR_ICFGR1(cluster,cpu));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICR_ICFGR1(cluster,cpu)) = cfg_val;
         }
       break;

     default:
       break;
    }
    
}

static void prvGicConfigureIntSPI(uint32_t vector, enum InterruptConfig_t icfg, uint32_t cluster)
{
    switch (icfg)
    {
       case EL1_INT_CONFIG_LEVEL_TRIGGER:
         {
           uint32_t cfg_val, offset, reg;

           reg = vector / 16;

           cfg_val = GICREG(0, GICD_ICFGR(cluster,reg));

           offset = vector % 16;

           cfg_val = cfg_val & ~(2 << (offset * 2));

           GICREG(0, GICD_ICFGR(cluster,reg)) = cfg_val;
         }
       break;

       case EL1_INT_CONFIG_EDGE_TRIGGER:
         {
           uint32_t cfg_val, offset, reg;

           reg = vector / 16;

           cfg_val = GICREG(0, GICD_ICFGR(cluster,reg));

           offset = vector % 16;

           cfg_val = cfg_val | (2 << (offset * 2));

           GICREG(0, GICD_ICFGR(cluster,reg)) = cfg_val;
         }
       break;

     default:
       break;
    }
}

static void prvGicUpdateIntRouting(uint32_t vector, uint64_t affinity)
{
  uint64_t gic_routing;
  uint cluster = arch_curr_cluster_num();  
  
  gic_routing = affinity | GIC_IRM_AFFINITY_BASED;

  GICREG64(0, GICD_IROUTER(cluster,vector)) = gic_routing;
}

static void prvGicSetIntGroup(uint32_t vector, uint32_t group) 
{
    uint32_t reg = vector/32;
    uint32_t mask = ~(1ULL << (vector%32));
    uint32_t cpu = arch_curr_cpu_num();
    uint32_t cluster = arch_curr_cluster_num();
    uint32_t igroup_val = 0x0;

    if (vector < 32) {
        igroup_val = GICREG(0, GICR_IGROUPR0(cluster,cpu));
        igroup_val = igroup_val & mask;
        GICREG(0, GICR_IGROUPR0(cluster,cpu)) = igroup_val | (group << (vector%32));
        prvGicWaitForRwp(GICR_CTLR(cluster,cpu));
    }else
    {
        igroup_val = GICREG(0, GICD_IGROUPR(cluster,reg));
        igroup_val = igroup_val & mask;
        GICREG(0, GICD_IGROUPR(cluster,reg)) = igroup_val | (group << (vector%32));
        prvGicWaitForRwp(GICD_CTLR(cluster));
    }
}