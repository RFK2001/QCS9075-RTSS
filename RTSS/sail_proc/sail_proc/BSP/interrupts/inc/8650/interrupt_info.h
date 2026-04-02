

/**
 * @file interrupt_info.h
 * @brief
 * Header file for storing information about the Edge Interrupts in
 * the target for Sail Subsystem.
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
01.14.21   rrahul       Created
=============================================================================*/
/* Include header file guard */
#ifndef INTERRUPT_INFO_H
#define INTERRUPT_INFO_H
/*===========================================================================
                               INCLUDE FILES
===========================================================================*/

/*===========================================================================
                               MACROS/DEFINES
===========================================================================*/




static const int edge_interrupts_spi[] =
{
    //List of divergent irqs  (manually added here)

//vector number not present in the ipcat
    /* destination_vector=, //sailss_emac0_phy_intr_n
    destination_vector=, //cpr_fusa_agg_err_out
    destination_vector=, //cpr_fusa_agg_warn_out
    destination_vector=, //cpr_fusa_agg_err_out
    destination_vector=, //cpr_fusa_agg_warn_out
    destination_vector=, //cpr_fusa_agg_err_out
    destination_vector=, //cpr_fusa_agg_warn_out
    destination_vector=, //cpr_fusa_agg_err_out
    destination_vector=, //cpr_fusa_agg_warn_out
    destination_vector=, //tlmm_csr_aggregated_irq
    destination_vector=, //cpr_fusa_agg_err_out
    destination_vector=, //cpr_fusa_agg_warn_out */
    //List Based on IPCat SAIL Subsystem Interrupts Only
    //grep -i edge interrupts.xml | sed  's/"/ /g'  | awk '{print $(NF-1) ", //" $5}'  -- used this for Lemans
    37, //APSS_spareIPCInterrupt_3_
    38, //APSS_spareTzIPCInterrupt_0_
    256, //ptp_pps_irq[0]
    257, //ptp_pps_irq[1]
    312, //qdss_etrbytecnt_etr1_irq
    383, //crypto_core_irq_0_
    384, //crypto_core_irq_1_
    385, //crypto_core_irq_2
    596, //ts0_tsens_0C_int
    601, //ts1_tsens_0C_int
    752, //isd_rtcu_md_ps_hold_posedge_irq
    753, //isd_rtcu_md_ps_hold_negedge_irq
    754, //isd_rtcu_md_psail_err_n_posedge_irq
    755, //isd_rtcu_md_psail_err_n_negedge_irq
    756, //isd_rtcu_deglitch_cntr_saftey_reset_irq
    762, //#define ceINTR_MISC_HOST_P         762
    771, //#define ceINTR_MISC_TARGET_P       771
    780, //#define ceINTR_LINE_HOST_P_0       780
    781, //#define ceINTR_LINE_HOST_P_1       781
    782, //#define ceINTR_LINE_HOST_P_2       782
    789, //#define ceINTR_LINE_HOST_P_3       789    
    783, //#define ceINTR_LINE_TARGET_P_0     783
    784, //#define ceINTR_LINE_TARGET_P_1     784
    785, //#define ceINTR_LINE_TARGET_P_2     785
    790, //#define ceINTR_LINE_TARGET_P_3     790
};

static const int edge_interrupts_ext_ppi[2] =
{
    16, // Watchdog BARK
    17, // Watchdog Window-error (min/max)
};

#endif //INTERRUPT_INFO_H
