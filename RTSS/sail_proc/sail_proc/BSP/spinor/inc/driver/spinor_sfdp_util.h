#ifndef __SPINOR_SFDP_UTILS_H__
#define __SPINOR_SFDP_UTILS_H__
/*
===========================================================================
*/
/**
    @file  spinor_sfdp_utils.h
    @brief Serial Flash Discoverable Parameters utility function defines

*/
/*
    ===========================================================================

    Copyright (c) 2020-2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_sfdp_util.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_erase_and_write_reg_mask

DESCRIPTION:
   This function gets the erase and write reg mask

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_erase_and_write_reg_mask(spinor_config_data *config, uint32_t device_id, spinor_sfdp_t *sfdp_data_read);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_4KB_uniform_sector

DESCRIPTION:
   This function gets the 4KB sector info

==================================================================================================*/
boolean spinor_sfdp_util_get_4KB_uniform_sector(spinor_sfdp_t *sfdp_data_read);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_bus_mode

DESCRIPTION:
   This function gets the bus mode

==================================================================================================*/
spinor_sfdp_bus_t spinor_sfdp_util_get_bus_mode(spinor_sfdp_t *sfdp_data_read);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_maxfreq

DESCRIPTION:
   Return the Max Frequency of operation of the param passed

==================================================================================================*/
uint32_t spinor_sfdp_util_get_maxfreq(uint32_t mhz);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_dqs_flag_ospi

DESCRIPTION:
   This function gets the DQS flag for OSPI

==================================================================================================*/
boolean spinor_sfdp_util_get_dqs_flag_ospi(spinor_sfdp_t *sfdp_data_read);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_str_bus_freq

DESCRIPTION:
   This function gets the STR bus frequency

==================================================================================================*/
uint32_t spinor_sfdp_util_get_str_bus_freq(spinor_sfdp_t *sfdp_data_read, uint32_t freq_mhz_at_least, boolean dqs, boolean is_ospi);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_dtr_bus_freq

DESCRIPTION:
   This function gets the DTR bus frequency

==================================================================================================*/
uint32_t spinor_sfdp_util_get_dtr_bus_freq(spinor_sfdp_t *sfdp_data_read, uint32_t freq_mhz_at_least, boolean dqs, boolean is_ospi);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_enter_4byte_mode

DESCRIPTION:
   This function gets the enter_4byte_mode

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_enter_4byte_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *enter_4byte_mode);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_octal_dtr_ext

DESCRIPTION:
   This function get octal dtr ext

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_octal_dtr_ext(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *octal_dtr_ext);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_access_param_perf

DESCRIPTION:
   This function gets the perf access parameters

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_access_param_perf(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                                                uint32_t bus_clk_khz, uint32 read_mode, uint32 write_mode, boolean dqs, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_access_param_perf_read_opcode_ospi

DESCRIPTION:
   This function gets the perf access param read opcode for OSPI

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_read_opcode_ospi(spinor_sfdp_t *sfdp_data_read, uint32_t bus_clk_khz, uint32 read_mode, spinor_config_data *config, uint8_t manufacturer);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_access_param_perf_read_opcode_qspi

DESCRIPTION:
   This function gets the perf access param read opcode for QSPI

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_read_opcode_qspi(spinor_sfdp_t *sfdp_data_read, uint32_t bus_clk_khz, uint32 read_mode, spinor_config_data *config, uint8_t manufacturer);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_access_param_perf_write_opcode_ospi

DESCRIPTION:
   This function gets the perf access param write opcode for OSPI

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_write_opcode_ospi(spinor_sfdp_t *sfdp_data_read, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_access_param_perf_write_opcode_qspi

DESCRIPTION:
   This function gets the perf access param write opcode for QSPI

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_write_opcode_qspi(spinor_sfdp_t *sfdp_data_read, uint32 write_mode, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_quad_enable_mode

DESCRIPTION:
   This function gets the quad_enable mode

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_quad_enable_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *quad_enable_mode);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_enable_444_seq

DESCRIPTION:
   This function gets the enable_444_seq

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_enable_444_seq(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *enable_444_seq);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_octal_enable_r

DESCRIPTION:
   This function gets the octal_enable_r

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_octal_enable_r(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *octal_enable_r, uint8 *octal_sdr_num_bytes);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_spi_io_mode

DESCRIPTION:
   This function gets the spi_io_mode

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_spi_io_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *spi_io_mode, uint32_t read_mode);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_device_transfer_rate

DESCRIPTION:
   This function gets the device transfer rate

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_device_transfer_rate(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                                              uint32_t read_mode, uint8 *device_transfer_rate);
															  
/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_power_on_delay_in_100us

DESCRIPTION:
   This function gets the power on delay

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_power_on_delay_in_100us(spinor_sfdp_t *sfdp_data_read, uint32_t device_id,
                                                                   spinor_sfdp_bus_t bus, uint8 *power_on_delay_in_100us);
																   
/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_dqs_sync_qspi_clk

DESCRIPTION:
   This function gets the dqs sync qspi clk flag

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_dqs_sync_qspi_clk(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, boolean *dqs_sync_qspi_clk);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_ecc_info

DESCRIPTION:
   This function gets the ECC info

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_ecc_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_crc_info

DESCRIPTION:
   This function gets the CRC info

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_crc_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_read_dummy_cycle

DESCRIPTION:
   This function gets the dummy cycles required for read

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_read_dummy_cycle(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint32_t bus_clk_khz,
                                                               uint32_t read_mode, spinor_config_data *config);
															   
/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_dummy_cycle_info

DESCRIPTION:
   This function gets the dummy cycle info

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_dummy_cycle_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                                               uint32_t bus_clk_khz, uint32_t read_mode, spinor_config_data *config);
															   
/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_manufacturer

DESCRIPTION:
   This function gets the manufacturer

==================================================================================================*/
uint8_t spinor_sfdp_util_get_manufacturer(uint32_t device_id);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_default_reg_read_and_reg_read_addr_dummy_cycles

DESCRIPTION:
   This function gets the default reg read and reg read addr dummy cycle

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_default_reg_read_and_reg_read_addr_dummy_cycles(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_config_data *config);

/*==================================================================================================

FUNCTION: spinor_sfdp_util_get_perf_reg_read_and_reg_read_addr_dummy_cycles

DESCRIPTION:
   This function gets the perf reg read and reg read addr dummy cycle

==================================================================================================*/
SPINOR_STATUS spinor_sfdp_util_get_perf_reg_read_and_reg_read_addr_dummy_cycles(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, spinor_config_data *config, uint32 read_mode);


#endif /* __SPINOR_SFDP_UTILS_H__ */
