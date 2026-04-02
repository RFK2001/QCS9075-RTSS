/*=============================================================================
  File Name.............. : CanTrcv_184_Tcan1146_Drv.c
  Description............ : CAN Transceiver TCAN1146 driver internal source file
  Autosar Release Version : R22-11
  Platform............... :
  SW Release Version..... :

  =============================================================================*/

/*=============================================================================
  |                       REVISION HISTORY                                      |
  ===============================================================================
  | Revision  Date            Changed By        Description                     |
  ===============================================================================
 
  =============================================================================*/

/*=============================================================================
  |                       INCLUDE FILES                                         |
  =============================================================================*/
#include "CanTrcv_184_Tcan1146_Drv.h"
#include "CanTrcv_184_Tcan1146.h"
#include "SchM_CanTrcv_184_Tcan1146.h"        /* Scheduler Manager header file */
#include "CanTrcv_184_Tcan1146_Reg.h"
#include "debug_log.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if(CANTRCV_184_TCAN1146_1US16BIT_TIMER_SUPPORT == STD_ON)
#include "Tm.h"                         /* Time Service module header file */
#endif
#else
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
/*==============================================================================
  |                       VERSION CHECK                                        |
  ============================================================================*/
#ifndef CAN_PLT_SAFERTOS_ENABLE
/* [SWS_BSW_00036] Inter module version check. */
#if(CANTRCV_184_TCAN1146_1US16BIT_TIMER_SUPPORT == STD_ON)
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != TM_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != TM_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and Tm.h are different."
#endif
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define TCAN1146_SPI_XFER_LEN       2u
/*SPI_DATA*/ static uint8 txbuf[TCAN1146_SPI_XFER_LEN];
/*SPI_DATA*/ static uint8 rxbuf[TCAN1146_SPI_XFER_LEN];

#define TCAN1146_PN_REG_COUNT   19u
/*
 1. TCAN1146_SW_ID1_REG_ADDR
 2. TCAN1146_SW_ID2_REG_ADDR
 3. TCAN1146_SW_ID3_REG_ADDR
 4. TCAN1146_SW_ID4_REG_ADDR
 5. TCAN1146_SW_ID_MASK1_REG_ADDR
 6. TCAN1146_SW_ID_MASK2_REG_ADDR
 7. TCAN1146_SW_ID_MASK3_REG_ADDR
 8. TCAN1146_SW_ID_MASK4_REG_ADDR
 9. TCAN1146_SW_ID_MASK_DLC_REG_ADDR
10. TCAN1146_SW_DATA_0_REG_ADDR
11. TCAN1146_SW_DATA_1_REG_ADDR
12. TCAN1146_SW_DATA_2_REG_ADDR
13. TCAN1146_SW_DATA_3_REG_ADDR
14. TCAN1146_SW_DATA_4_REG_ADDR
15. TCAN1146_SW_DATA_5_REG_ADDR
16. TCAN1146_SW_DATA_6_REG_ADDR
17. TCAN1146_SW_DATA_7_REG_ADDR
18. TCAN1146_SW_CFG1_REG_ADDR
19. TCAN1146_SW_CFG3_REG_ADDR
*/

typedef struct {
    uint8 addr;
    uint8 val;
} Tcan1146_PnSpiReg;

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSPIInit(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_CFG_FAILURE;
    uint8 spiChId = CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].SpiChannelId;

    if (E_OK == Spi_SetupEB(spiChId, txbuf, rxbuf, TCAN1146_SPI_XFER_LEN))
    {
        returnValue = CANTRCV_E_OK;
    }

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : Tcan1146DrvSPIRead
  Parameters (IN)... : transceiver, regAddr
  Parameters (INOUT) : None
  Parameters (OUT).. : data
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API reads the register value at address regAddr into
  data, of the called transceiver
  Design IDs Covered :
 ******************************************************************************/
static CanTrcv_ReturnType Tcan1146DrvSPIRead(uint8 transceiver, uint8 regAddr,
        uint8 *data)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_CFG_FAILURE;
    uint8 noOfSpiCommRetry = (uint8)0;

    uint8 spiSeqId = CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].SpiSequenceId;
    uint8 spiCommRetries = CanTrcv_184_Tcan1146_Config.SpiCommRetries;

    txbuf[0] = regAddr << 1;
    txbuf[1] = 0;

    do
    {
        if (E_OK == Spi_SyncTransmit(spiSeqId))
        {
            *data = rxbuf[1];
            returnValue = CANTRCV_E_OK;
            break;
        }
        noOfSpiCommRetry++;
    } while (noOfSpiCommRetry <= spiCommRetries);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : Tcan1146DrvSPIWrite
  Parameters (IN)... : transceiver, regAddr, data
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API writes the value data into the register at address
  regAddr of the called transceiver
  Design IDs Covered :
 ******************************************************************************/
static CanTrcv_ReturnType Tcan1146DrvSPIWrite(uint8 transceiver, uint8 regAddr,
        uint8 data)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_CFG_FAILURE;
    uint8 noOfSpiCommRetry = (uint8)0;

    uint8 spiSeqId = CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].SpiSequenceId;
    uint8 spiCommRetries = CanTrcv_184_Tcan1146_Config.SpiCommRetries;

    txbuf[0] = ((regAddr << 1) | 1u);
    txbuf[1] = data;

    rxbuf[0] = 0;
    rxbuf[1] = 0;

    do
    {
        if (E_OK == Spi_SyncTransmit(spiSeqId))
        {
            returnValue = CANTRCV_E_OK;
            break;
        }
        noOfSpiCommRetry++;
    } while (noOfSpiCommRetry <= spiCommRetries);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvInterruptDis(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = 0;

    do
    {
        /* Writing 0x00 to INT_ENABLE_1 reg */
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_1_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Writing 0x00 to INT_ENABLE_2 reg */
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_2_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Writing 0x00 to INT_ENABLE_3 reg */
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_3_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Writing 0x00 to INT_ENABLE_CANBUS reg */
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_CANBUS_REG_ADDR, buf);
    } while(0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvInterruptClr(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = 0;

    do
    {
        /* Clearing interrupts in INT_1 reg */
        buf = TCAN1146_INT_1_RSVD_MASK;
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_1_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Clearing interrupts in INT_2 reg */
        buf = TCAN1146_INT_2_RSVD_MASK;
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_2_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Clearing interrupts in INT_3 reg */
        buf = TCAN1146_INT_3_RSVD_MASK;
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_3_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Clearing interrupts in INT_CANBUS reg */
        buf = TCAN1146_INT_CANBUS_RSVD_MASK;
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_CANBUS_REG_ADDR, buf);
    } while(0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/* Function to enable required interrupts */
static CanTrcv_ReturnType Tcan1146DrvInterruptEn(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = 0;

    do
    {
#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
        /* Enabling Wakeup by bus, Wake Error and Frame error counter overflows
         * interrupts */
        buf = (1u << TCAN1146_CANINT_ENABLE_BIT_POS) |
              (1u << TCAN1146_WKERR_ENABLE_BIT_POS) |
              (1u << TCAN1146_FRAME_OVF_ENABLE_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_1_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Enabling SysERR interrupt */
        buf = (1u << TCAN1146_SWERR_ENABLE_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_ENABLE_3_REG_ADDR, buf);
#endif
    } while (0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON) && (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSetPnEnable(uint8 transceiver, boolean PNEnable)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;

    returnValue = Tcan1146DrvSPIRead(transceiver,
            TCAN1146_MODE_CONTROL_REG_ADDR, &buf);
    if (CANTRCV_E_OK == returnValue)
    {
        buf &= (uint8)(~(1u << TCAN1146_SW_EN_BIT_POS));
        if (TRUE == PNEnable)
        {
            buf |= (1u << TCAN1146_SW_EN_BIT_POS);
        }
        returnValue = Tcan1146DrvSPIWrite(transceiver,
                TCAN1146_MODE_CONTROL_REG_ADDR, buf);
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
static CanTrcv_ReturnType Tcan1146DrvSetupPnCfgRegData(uint8 transceiver, Tcan1146_PnSpiReg *reg)
{
    uint8 i = 0u;
    const CanTrcv_Tcan1146ChPnConfigType*
        PNCfgPtr = CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].PnCfg;
    uint32 canId = PNCfgPtr->PnFrameCanId;
    uint32 canIdMask = PNCfgPtr->PnFrameCanIdMask;
    const uint8* PNDataArr = NULL_PTR;

    if (PNCfgPtr->PnFrameDlc > 0u)
    {
        PNDataArr = CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].PnCfg->DataMask;
    }

    /* Initialize reg struct to zero */
    for(i = 0; i < TCAN1146_PN_REG_COUNT; i++)
    {
        reg[i].addr = 0u;
        reg[i].val = 0u;
    }

    if (TRUE == PNCfgPtr->PnCanIdIsExtended)
    {
        /* Setting Ext. ID[17:10] in SW_ID1 */
        reg[0].val = (uint8)(canId >> 10);
        reg[0].addr = TCAN1146_SW_ID1_REG_ADDR;

        /* Setting Ext. ID[9:2] in SW_ID2 */
        reg[1].val = (uint8)(canId >> 2);
        reg[1].addr = TCAN1146_SW_ID2_REG_ADDR;

        /* Setting Ext. ID[1:0], IDE bit and Ext. ID[28:24] in SW_ID3 */
        reg[2].val = (uint8)((canId << TCAN1146_SW_ID3_EXTID_1_0_BIT_POS) |
                (1u << TCAN1146_SW_ID3_IDE_BIT_POS) |
                ((canId >> 24) & TCAN1146_SW_ID3_EXTID_28_24_BIT_MASK));
        reg[2].addr = TCAN1146_SW_ID3_REG_ADDR;

        /* Setting Ext. ID[23:18] in SW_ID4 */
        reg[3].val = (uint8)(((canId >> 18) << TCAN1146_SW_ID4_EXTID_23_18_BIT_POS) & TCAN1146_SW_ID4_EXTID_23_18_BIT_MASK);
        reg[3].addr = TCAN1146_SW_ID4_REG_ADDR;

        /* Setting Ext. ID Mask[17:16] in SW_ID_MASK1 */
        reg[4].val = (uint8)((canIdMask >> 16) & TCAN1146_SW_ID_MASK1_EXTID_17_16_BIT_MASK);
        reg[4].addr = TCAN1146_SW_ID_MASK1_REG_ADDR;

        /* Setting Ext. ID Mask[15:8] in SW_ID_MASK2 */
        reg[5].val = (uint8)((canIdMask >> 8) & TCAN1146_SW_ID_MASK2_EXTID_15_8_BIT_MASK);
        reg[5].addr = TCAN1146_SW_ID_MASK2_REG_ADDR;

        /* Setting Ext. ID Mask[7:0] in SW_ID_MASK3 */
        reg[6].val = (uint8)(canIdMask & TCAN1146_SW_ID_MASK3_EXTID_7_0_BIT_MASK);
        reg[6].addr = TCAN1146_SW_ID_MASK3_REG_ADDR;

        /* Setting Ext. ID Mask[28:21] in SW_ID_MASK4 */
        reg[7].val = (uint8)((canIdMask >> 21) & TCAN1146_SW_ID_MASK4_EXTID_28_21_BIT_MASK);
        reg[7].addr = TCAN1146_SW_ID_MASK4_REG_ADDR;

        /* Setting Ext. ID Mask[20:18], DLC and Data Mask Enable in SW_ID_MASK_DLC */
        reg[8].val = (uint8)(((uint8)((canIdMask >> 18u) <<
                        TCAN1146_SW_ID_MASK_DLC_EXTID_20_18_BIT_POS) &
                    TCAN1146_SW_ID_MASK_DLC_EXTID_20_18_BIT_MASK) |
                ((PNCfgPtr->PnFrameDlc << TCAN1146_SW_ID_MASK_DLC_BIT_POS) &
                 TCAN1146_SW_ID_MASK_DLC_BIT_MASK) |
                ((PNCfgPtr->PnFrameDlc > 0u) ? 1u : 0u));
        reg[8].addr = TCAN1146_SW_ID_MASK_DLC_REG_ADDR;
    }
    else
    {
        /* Setting 0 in SW_ID1 */
        reg[0].val = 0u;
        reg[0].addr = TCAN1146_SW_ID1_REG_ADDR;

        /* Setting 0 in SW_ID2 */
        reg[1].val = 0u;
        reg[1].addr = TCAN1146_SW_ID2_REG_ADDR;

        /* Setting ID[10:6] in SW_ID3 */
        reg[2].val = (uint8)((canId >> 6) & TCAN1146_SW_ID3_ID_10_6_BIT_MASK);
        reg[2].addr = TCAN1146_SW_ID3_REG_ADDR;

        /* Setting ID[5:0] in SW_ID4 */
        reg[3].val = (uint8)((canId << TCAN1146_SW_ID4_ID_5_0_BIT_POS) & TCAN1146_SW_ID4_ID_5_0_BIT_MASK);
        reg[3].addr = TCAN1146_SW_ID4_REG_ADDR;

        /* Setting 0 in SW_ID_MASK1 */
        reg[4].val = 0u;
        reg[4].addr = TCAN1146_SW_ID_MASK1_REG_ADDR;

        /* Setting 0 in SW_ID_MASK2 */
        reg[5].val = 0u;
        reg[5].addr = TCAN1146_SW_ID_MASK2_REG_ADDR;

        /* Setting 0 in SW_ID_MASK3 */
        reg[6].val = 0u;
        reg[6].addr = TCAN1146_SW_ID_MASK3_REG_ADDR;

        /* Setting ID Mask[10:3] in SW_ID_MASK4 */
        reg[7].val = (uint8)(canIdMask >> 3);
        reg[7].addr = TCAN1146_SW_ID_MASK4_REG_ADDR;

        /* Setting ID Mask[2:0], DLC and Data Mask Enable in SW_ID_MASK_DLC */
        reg[8].val = (uint8)(((uint8)(canIdMask <<
                        TCAN1146_SW_ID_MASK_DLC_ID_2_0_BIT_POS) &
                    TCAN1146_SW_ID_MASK_DLC_ID_2_0_BIT_MASK) |
                ((PNCfgPtr->PnFrameDlc << TCAN1146_SW_ID_MASK_DLC_BIT_POS) &
                 TCAN1146_SW_ID_MASK_DLC_BIT_MASK) |
                ((PNCfgPtr->PnFrameDlc > 0u) ? 1u : 0u));
        reg[8].addr = TCAN1146_SW_ID_MASK_DLC_REG_ADDR;
    }
    for(i = 0; i < 8u; i++)
    {
        reg[9u + i].addr = TCAN1146_SW_DATA_0_REG_ADDR + i;
    }
    for(i = 0; i < PNCfgPtr->PnFrameDlc; i++)
    {
        reg[9u + i].val = PNDataArr[i];
    }

    /* Setting SW_FD_PASSIVE, CAN_DR and FD_DR */
    switch(PNCfgPtr->BaudRate)
    {
        case 50:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_50_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        case 100:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_100_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        case 125:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_125_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        case 250:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_250_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        case 500:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_500_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        case 1000:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_1_MBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
        default:
            reg[17].val = (TCAN1146_SW_CFG1_CANDR_500_KBPS << TCAN1146_SW_CFG1_CANDR_BIT_POS);
            break;
    }
    reg[17].val |= (1u << TCAN1146_SW_CFG1_FD_PASSIVE_BIT_POS) |
        ((((CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].MaxBaudrate
            / (PNCfgPtr->BaudRate * 1000u)) >= 5u) ? 1u : 0u) << TCAN1146_SW_CFG1_FD_DR_BIT_POS);
    reg[17].addr = TCAN1146_SW_CFG1_REG_ADDR;

    /* Setting Frame Error Counter Threshold to max(0xFF) */
    reg[18].val = 0xFF;
    reg[18].addr = TCAN1146_SW_CFG3_REG_ADDR;

    return CANTRCV_E_OK;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
static CanTrcv_ReturnType Tcan1146DrvSetPnCfg(uint8 transceiver)
{
    uint8 i = 0u;
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    CanTrcv_ReturnType readStatus = CANTRCV_E_OK;
    uint8 buf = 0u;
    Tcan1146_PnSpiReg reg[TCAN1146_PN_REG_COUNT] = {0};

    (void)Tcan1146DrvSetupPnCfgRegData(transceiver, reg);

    do
    {
        i = 0u;
        /* Writing SW registers */
        do
        {
            returnValue = Tcan1146DrvSPIWrite(transceiver, reg[i].addr, reg[i].val);
            i++;
        } while ((CANTRCV_E_OK == returnValue) && (i < TCAN1146_PN_REG_COUNT));

        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Reading SW registers, to verify correct values */
        i = 0u;
        do
        {
            returnValue = Tcan1146DrvSPIRead(transceiver, reg[i].addr, &buf);
            if (CANTRCV_E_OK != returnValue)
            {
                break;
            }
            readStatus = ((buf == reg[i].val) ? CANTRCV_E_OK : CANTRCV_E_PNCFG_FAILURE);
            i++;
        } while ((CANTRCV_E_OK == readStatus) && (i < TCAN1146_PN_REG_COUNT));

        if ((CANTRCV_E_OK != returnValue) || (CANTRCV_E_OK != readStatus))
        {
            break;
        }

        /* If all SPI transfers succeeded and all SW registers are configured
         * correctly, set SWCFG bit */
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_SW_CFG4_REG_ADDR,
                &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        buf |= (1u << TCAN1146_SW_CFG4_SWCFG_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_SW_CFG4_REG_ADDR,
                buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Read back SWCFG is set */
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_SW_CFG4_REG_ADDR,
                &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        if (0u == (buf & (1u << TCAN1146_SW_CFG4_SWCFG_BIT_POS)))
        {
            /* If readback value of SWCFG is 0 */
            returnValue = CANTRCV_E_NOT_OK;
        }
    } while(0);
    if (CANTRCV_E_PNCFG_FAILURE == readStatus)
    {
        returnValue = CANTRCV_E_PNCFG_FAILURE;
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_Set_Cfg
  Parameters (IN)... : transceiver, ApiId
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API writes the required configurations to the
  transceiver SPI registers.
  Design IDs Covered :
 ******************************************************************************/
static CanTrcv_ReturnType Tcan1146DrvSetCfg(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = 0;

    do
    {
        returnValue = Tcan1146DrvSPIRead(transceiver,
                TCAN1146_SWE_DIS_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Disable the sleep wake error timer */
        buf |= (1u << TCAN1146_CANSLNT_SWE_DIS_BIT_POS) |
            (1u << TCAN1146_SWE_DIS_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_SWE_DIS_REG_ADDR,
                buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver,
                TCAN1146_DEVICE_CONFIG1_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Disable LIMP and INH pins */
        buf |= (1u << TCAN1146_LIMP_DIS_BIT_POS) | (1u << TCAN1146_INH_DIS_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver,
                TCAN1146_DEVICE_CONFIG1_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver,
                TCAN1146_FSM_CONFIG_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Disable Fail safe and fail safe mode counter */
        buf |= (1u << TCAN1146_FS_DIS_BIT_POS);
        buf &= ~(1u << TCAN1146_FS_CNTR_EN_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_FSM_CONFIG_REG_ADDR,
                buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver,
                TCAN1146_SDO_CONFIG_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Set SDO/nINT pin as SDO and nINT */
        buf |= (1u << TCAN1146_SDO_CONFIG_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_SDO_CONFIG_REG_ADDR,
                buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver,
                TCAN1146_MODE_CONTROL_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Enabling bus fault detection and dominant timeout */
        buf |= (1u << TCAN1146_FD_EN_BIT_POS);
        buf &= ~(1u << TCAN1146_DTO_DIS_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver,
                TCAN1146_MODE_CONTROL_REG_ADDR, buf);
    } while(0);
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_Init_Hw
  Parameters (IN)... : transceiver
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API initiatizes each instance of transceiver.
  Design IDs Covered :
 ******************************************************************************/
CanTrcv_ReturnType Tcan1146DrvInit(uint8 transceiver,
        CanTrcv_TrcvModeType opMode,
        boolean* PNCfgWritten)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;

    do
    {
        /* Disable all interrupts */
        returnValue = Tcan1146DrvInterruptDis(transceiver);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Clear all pending interrupts */
        returnValue = Tcan1146DrvInterruptClr(transceiver);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        /* Perform required register configurations */
        returnValue = Tcan1146DrvSetCfg(transceiver);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
        if (TRUE == CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].HwPnSupport)
        {
            *PNCfgWritten = TRUE;
            /* Configure Selective wakeup */
            returnValue = Tcan1146DrvSetPnCfg(transceiver);
            if (CANTRCV_E_PNCFG_FAILURE == returnValue)
            {
                *PNCfgWritten = FALSE;
            }
            else if (CANTRCV_E_OK != returnValue)
            {
                break;
            }
            else
            {
                /* Do nothing */
            }
        }
#endif

        returnValue = Tcan1146DrvSetModeReg(transceiver, opMode);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
        if ((TRUE == CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].HwPnSupport) &&
            (TRUE == *PNCfgWritten))
        {
            /* Enable/Disable Selective wakeup according to configuration */
            returnValue = Tcan1146DrvSetPnEnable(transceiver,
                    CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver].PnCfg->PnEnabled);
            if (CANTRCV_E_OK != returnValue)
            {
                break;
            }
        }
#endif

        /* Enable monitored interrupts */
        returnValue = Tcan1146DrvInterruptEn(transceiver);
    } while(0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
static CanTrcv_ReturnType Tcan1146DrvGetModeReg(uint8 transceiver,
        CanTrcv_TrcvModeType *currentOpMode)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;

    returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_MODE_CONTROL_REG_ADDR, &buf);
    if (CANTRCV_E_OK == returnValue)
    {
        buf &= (uint8)(TCAN1146_MODE_SEL_BIT_MASK);
        if (TCAN1146_MODE_SEL_NORMAL == buf)
        {
            *currentOpMode = CANTRCV_TRCVMODE_NORMAL;
        }
        else if (TCAN1146_MODE_SEL_STANDBY == buf)
        {
            *currentOpMode = CANTRCV_TRCVMODE_STANDBY;
        }
        else if (TCAN1146_MODE_SEL_SLEEP == buf)
        {
            *currentOpMode = CANTRCV_TRCVMODE_SLEEP;
        }
        else
        {
            returnValue = CANTRCV_E_NOT_OK;
        }
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"


#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvSetOpMode(uint8 transceiver,
        CanTrcv_TrcvModeType opMode)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
    const CanTrcv_Tcan1146ChConfigType*
        ChannelConfigPtr = &CanTrcv_184_Tcan1146_Config.ChannelConfig[transceiver];
    boolean PNCfgWritten = FALSE;
    uint8 statusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif
    CanTrcv_TrcvModeType CurrentOpMode;
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    uint8 WakeupReason;
    uint8 currentStatusBits = (uint8)TCAN1146_NO_STATUS_SET;
#endif

    /* Invoke function to enable Data Protection */
    SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
    /* Get the operational mode of CAN transceiver Driver network */
    CurrentOpMode = CanTrcv_184_Tcan1146_ChannelState[transceiver].OperMode;
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    currentStatusBits = CanTrcv_184_Tcan1146_ChannelState[transceiver].StatusBits;
#endif
    /* Invoke function to disable Data Protection */
    SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();

    do
    {
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
        if ((TRUE == ChannelConfigPtr->HwPnSupport) &&
            (TRUE == ChannelConfigPtr->PnCfg->PnEnabled) &&
            (TRUE == ChannelConfigPtr->PnCfg->PowerOnFlag))
        {
            returnValue = Tcan1146DrvGetTrcvStatusBits(transceiver, &statusBits);
            if (CANTRCV_E_OK != returnValue)
            {
                break;
            }
            /* If the POR flag is set, transceiver shall be re-initialized */
            if (0u != (statusBits & (uint8)TCAN1146_POWER_ON))
            {
                /* If the POR flag is set, changing the operating mode in Init_Hw() */
                returnValue = Tcan1146DrvInit(transceiver, opMode, &PNCfgWritten);
                if (CANTRCV_E_OK != returnValue)
                {
                    break;
                }
                if (FALSE == PNCfgWritten)
                {
                    currentStatusBits |= (uint8)TCAN1146_PN_CFG_FAIL;
                }
                else
                {
                    currentStatusBits &= (~((uint8)TCAN1146_PN_CFG_FAIL));
                }
            }
            else
            {
                if (CurrentOpMode != opMode)
                {
                    /* If the POR flag is not set, changing the operating mode */
                    returnValue = Tcan1146DrvSetModeReg(transceiver, opMode);
                    if (CANTRCV_E_OK != returnValue)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
#endif
            if (CurrentOpMode != opMode)
            {
                /* If the POR flag is not set, changing the operating mode */
                returnValue = Tcan1146DrvSetModeReg(transceiver, opMode);
                if (CANTRCV_E_OK != returnValue)
                {
                    break;
                }
            }
#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
        }
#endif

        /* Busywait for Transceiver State Change wait time */
#if(CANTRCV_184_TCAN1146_1US16BIT_TIMER_SUPPORT == STD_ON)
#ifdef CAN_PLT_SAFERTOS_ENABLE
		(void)vFreeRTOSTaskDelay(pdMS_TO_TICKS(CANTRCV_184_TCAN1146_DELAY_IN_MS));
#else
        (void)Tm_BusyWait1us16bit(CANTRCV_184_TCAN1146_WAITTIME_IN_US);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#endif

        returnValue = Tcan1146DrvGetModeReg(transceiver, &CurrentOpMode);
        //If it is a SPI failure, returnValue will be CANTRCV_E_CFG_FAILURE
        //If mode is not set to Normal, Standby or Sleep, returnValue will be CANTRCV_E_NOT_OK
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        if (CurrentOpMode != opMode)
        {
            returnValue = CANTRCV_E_NOT_OK;
            break;
        }

        /* Invoke function to enable Data Protection */
        SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area();
        /* Set the Operational Mode of the requested network */
        CanTrcv_184_Tcan1146_ChannelState[transceiver].OperMode = opMode;
#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
        WakeupReason = CanTrcv_184_Tcan1146_ChannelState[transceiver].WakeupReason;
        if (CANTRCV_TRCVMODE_NORMAL == opMode)
        {
            /* For Normal mode, clearing the Wakeup pending status */
            CanTrcv_184_Tcan1146_ChannelState[transceiver].WakeupPending = FALSE;
            if (CANTRCV_184_TCAN1146_WU_NOT_FOUND == WakeupReason)
            {
                /* If the Opmode is Normal and WakeupReason is not found, set WakeupReason to Internal */
                WakeupReason = (uint8)CANTRCV_WU_INTERNALLY;
            }
        }
        else
        {
            /* If the Opmode is Standby or Sleep, set Wakeupreason to not found */
            WakeupReason = CANTRCV_184_TCAN1146_WU_NOT_FOUND;
        }
        CanTrcv_184_Tcan1146_ChannelState[transceiver].WakeupReason = WakeupReason;
        CanTrcv_184_Tcan1146_ChannelState[transceiver].StatusBits = currentStatusBits;
#endif
        /* Invoke function to disable Data Protection */
        SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area();
    } while(0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_SetOpMode_Hw
  Parameters (IN)... : transceiver, opMode, ApiId
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API sets the operating mode of the transceiver to
  Normal, Standby or Sleep.
  Design IDs Covered :
 ******************************************************************************/
CanTrcv_ReturnType Tcan1146DrvSetModeReg(uint8 transceiver,
        CanTrcv_TrcvModeType opMode)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;

    returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_MODE_CONTROL_REG_ADDR, &buf);
    if (CANTRCV_E_OK == returnValue)
    {
        buf &= (uint8)(~TCAN1146_MODE_SEL_BIT_MASK);
        /* Setting opmode */
        if (CANTRCV_TRCVMODE_NORMAL == opMode)
        {
            buf |= (TCAN1146_MODE_SEL_NORMAL << TCAN1146_MODE_SEL_BIT_POS);
        }
        else if (CANTRCV_TRCVMODE_STANDBY == opMode)
        {
            buf |= (TCAN1146_MODE_SEL_STANDBY << TCAN1146_MODE_SEL_BIT_POS);
        }
        else
        {
            buf |= (TCAN1146_MODE_SEL_SLEEP << TCAN1146_MODE_SEL_BIT_POS);
        }
        returnValue = Tcan1146DrvSPIWrite(transceiver,
                TCAN1146_MODE_CONTROL_REG_ADDR, buf);
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvCheckBusErrFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = 0u;

    *FlagState = CANTRCV_184_TCAN1146_FLAG_CLEARED;

    do
    {
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_CANBUS_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        *FlagState = (buf == 0u) ? CANTRCV_184_TCAN1146_FLAG_CLEARED : CANTRCV_184_TCAN1146_FLAG_SET;
        if (CANTRCV_184_TCAN1146_FLAG_SET == *FlagState)
        {
            break;
        }
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_1_REG_ADDR, &buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        buf &= (1u << TCAN1146_CANDOM_BIT_POS);
        *FlagState = (buf != 0u) ?
            CANTRCV_184_TCAN1146_FLAG_SET :
            CANTRCV_184_TCAN1146_FLAG_CLEARED;
    } while (0);
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearBusErrFlag(uint8 transceiver)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;


    do
    {
        /* Clearing BusErr interrupts in INT_CANBUS reg */
        buf = TCAN1146_INT_CANBUS_RSVD_MASK;
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_CANBUS_REG_ADDR, buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }
        /* Clearing CANDOM interrupt in INT_1 reg */
        buf = (1u << TCAN1146_CANDOM_BIT_POS);
        returnValue = Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_1_REG_ADDR, buf);
    } while(0);
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvGetTrcvStatusBits(uint8 transceiver,
        uint8* statusBits)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 int1_buf = (uint8)0, int2_buf = (uint8)0;

    *statusBits = (uint8)TCAN1146_NO_STATUS_SET;

    do
    {
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_1_REG_ADDR, &int1_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_2_REG_ADDR, &int2_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        if ((int2_buf & (1u << TCAN1146_PWRON_BIT_POS)) != 0u)
        {
            *statusBits |= (uint8)TCAN1146_POWER_ON;
        }
        if ((int1_buf & (1u << TCAN1146_FRAME_OVF_BIT_POS)) != 0u)
        {
            *statusBits |= (uint8)TCAN1146_FRAME_OVF;
        }
        if ((int1_buf & (1u << TCAN1146_CANINT_BIT_POS)) != 0u)
        {
            *statusBits |= (uint8)TCAN1146_WU_BY_BUS;
        }
        if ((int1_buf & (1u << TCAN1146_WKERR_BIT_POS)) != 0u)
        {
            *statusBits |= (uint8)TCAN1146_WKERR;
        }
    } while(0);

    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void Tcan1146DrvReportStatus(const CanTrcv_Tcan1146ChConfigType *channelPtr, uint8 statusBits)
{
#if(CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
    if (0u != (statusBits & (uint8)TCAN1146_POWER_ON))
    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
        EcuM_SetWakeupEvent(channelPtr->PorWakeupSourceId);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    }
    if ((0u != (statusBits & (uint8)TCAN1146_FRAME_OVF)) ||
        (0u != (statusBits & (uint8)TCAN1146_PN_CFG_FAIL)))
    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
        EcuM_SetWakeupEvent(channelPtr->SyserrWakeupSourceId);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    }
#endif
    if (0u != (statusBits & (uint8)TCAN1146_WU_BY_BUS))
    {
#ifndef CAN_PLT_SAFERTOS_ENABLE
        EcuM_SetWakeupEvent(channelPtr->WakeupSourceId);
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
    }
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvGetTrcvSystemData(uint8 transceiver,
        uint32* trcvSysData)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 int1_buf = (uint8)0, int2_buf = (uint8)0, int3_buf = (uint8)0, intcanbus_buf = (uint8)0;

    do {
        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_1_REG_ADDR, &int1_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_2_REG_ADDR, &int2_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_3_REG_ADDR, &int3_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_CANBUS_REG_ADDR, &intcanbus_buf);
        if (CANTRCV_E_OK != returnValue)
        {
            break;
        }

        *trcvSysData = ((uint32)int1_buf << 24u) | ((uint32)int2_buf << 16u) | ((uint32)int3_buf << 8u) | intcanbus_buf;
    } while(0);
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearTrcvWufFlag(uint8 transceiver)
{
    uint8 buf = (1u << TCAN1146_CANINT_BIT_POS) |
                (1u << TCAN1146_FRAME_OVF_BIT_POS);

    return Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_1_REG_ADDR, buf);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvReadTrcvTimeoutFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* flagState)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;

    returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_1_REG_ADDR, &buf);
    if (CANTRCV_E_OK == returnValue)
    {
        *flagState = ((buf & (1u << TCAN1146_CANTO_BIT_POS)) != 0u) ?
            CANTRCV_184_TCAN1146_FLAG_SET :
            CANTRCV_184_TCAN1146_FLAG_CLEARED;
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvClearTrcvTimeoutFlag(uint8 transceiver)
{
    uint8 buf = (1u << TCAN1146_CANTO_BIT_POS);

    return Tcan1146DrvSPIWrite(transceiver, TCAN1146_INT_1_REG_ADDR, buf);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
CanTrcv_ReturnType Tcan1146DrvReadTrcvSilenceFlag(uint8 transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* flagState)
{
    CanTrcv_ReturnType returnValue = CANTRCV_E_OK;
    uint8 buf = (uint8)0;

    returnValue = Tcan1146DrvSPIRead(transceiver, TCAN1146_INT_1_REG_ADDR, &buf);
    if (CANTRCV_E_OK == returnValue)
    {
        *flagState = ((buf & (1u << TCAN1146_CANSLNT_BIT_POS)) != 0u) ?
            CANTRCV_184_TCAN1146_FLAG_SET :
            CANTRCV_184_TCAN1146_FLAG_CLEARED;
    }
    return returnValue;
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
/******************************************************************************
  Service Name...... : CanTrcv_184_Tcan1146_SoftReset
  Parameters (IN)... : transceiver, ApiId
  Parameters (INOUT) : None
  Parameters (OUT).. : None
  Return Value...... : E_OK, E_NOT_OK
  Description....... : This API performs soft reset on the transceiver.
  Design IDs Covered :
 ******************************************************************************/
CanTrcv_ReturnType Tcan1146DrvSoftReset(uint8 transceiver)
{
    uint8 buf = (uint8)0;

    buf = (1u << TCAN1146_SF_RST_BIT_POS);

    return Tcan1146DrvSPIWrite(transceiver, TCAN1146_DEVICE_RESET_REG_ADDR, buf);
}
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

/*=============================================================================
  |                       END OF FILE                                           |
  =============================================================================*/
