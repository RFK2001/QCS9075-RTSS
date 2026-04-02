/*
===========================================================================
*/
/**
    @file  spinor_dma_pio.c
    @brief Implements functions related to the DMA and PIO transfers in the SPINOR driver

*/
/*
    ===========================================================================

    Copyright (c) 2015, 2017 - 2018, 2020-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_dma_pio.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*==================================================================================================
                                            DESCRIPTION
====================================================================================================

==================================================================================================*/
/*==================================================================================================
                                           INCLUDE FILES
==================================================================================================*/
#include "spinor_hal.h"
#include "debug_log.h"
#include "spinor_dma_pio.h"
#include "spinor_core.h"

/*==================================================================================================
                                             CONSTANTS
==================================================================================================*/
#define OSPI_DMA_CACHE_LN_ALIGNMENT 64
#define OSPI_PIO_ALIGNMENT          4

#define CRC_CHUNK_SIZE       16    /* CRC Chunk size in number of bytes */

//#define OCTALSPI_PRE_SIL          //Flag for pre-sil specific code

/*==================================================================================================
                                               MACROS
==================================================================================================*/
#undef ALIGN
#ifndef ALIGN
#define ALIGN(__value)  __attribute__((__aligned__(__value)))
#endif

#undef SECTION
#ifndef SECTION
#define SECTION(__name) __attribute__((section(__name)))
#endif

#define INT_TO_PTR(x) (void *)(uintptr_t)(x)

/*==================================================================================================
                                              TYPEDEFS
==================================================================================================*/

typedef enum
{
   MASTER_READ = 0,
   MASTER_WRITE = 1,
} BUS_XFER_DIRECTION;

#ifdef SPINOR_CRC_ENABLE
typedef struct
{
    uint8_t crc_data_buffer[PAGE_SIZE_IN_BYTES + CRC_CHUNK_SIZE + CRC_CHUNK_SIZE];  /* 256 + 16 crc bytes + 16 crc# bytes */
    uint8_t crc_address_buffer[6];  /* 4 bytes address + 1 byte crc + 1 byte crc# */
    uint32_t bytes_removed_or_added;
    uint32_t bytes_removed_or_added_addr;
    uint32_t extra_FFs_packed;
    uint32_t temp_data_bytes;
}OSPI_CRC_Params;
#endif
/*==================================================================================================
                                          LOCAL VARIABLES
==================================================================================================*/

// The DMA descriptors and DMA buffer could be cached but 32-byte aligned, and a multiple
// of 4-bytes in length.  They must also be accessible to external AHB masters.  OCIMEM
// and DDR are accessible but TCM is not (TCM is L2 cache that is repurposed as tightly
// coupled memory).  The stack and file scope variables use TCM in the XBL loader.

//DMA descriptor cannot cross 1KB boundary. The descriptor size is 64bytes now. So max descriptor cannot be more than 15.
// So this will not cross 1KB boundary for the next descriptors
static DESCRIPTOR dma_descriptors[DMA_MAX_DESCRIPTORS]          ALIGN(OSPI_DMA_DESCRIPTOR_ALIGNMENT);
static uint8_t    dma_buffer[OSPI_DMA_CACHE_LN_ALIGNMENT*6]     ALIGN(OSPI_DMA_CACHE_LN_ALIGNMENT);

static DESCRIPTOR *dma_chain = NULL;
static uint8_t *dma_free_ptr = dma_buffer;

static uint8_t *ospi_base = (void *)QSPI_REG_BASE;

#ifdef SPINOR_CRC_ENABLE
static OSPI_CRC_Params crc_params    ALIGN(OSPI_DMA_CACHE_LN_ALIGNMENT);
static bool octalspi_crc_flag = FALSE;  /* Initialize to False always, will be set when needed */
static OSPI_OP_ID ospi_cmd_id;
#endif
/*==================================================================================================
                                     LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

static DESCRIPTOR        *allocate_descriptor(uint32_t bytes_needed, bool dma_mode);
static uint32_t           available_room(DESCRIPTOR *last);
static SPINOR_STATUS      flush_chain(bool dma_mode);
static DESCRIPTOR        *get_last_descriptor(void);
static SPINOR_STATUS      pio_transfer_chain(DESCRIPTOR *chain);
static SPINOR_STATUS      queue_addr(uint32_t addr, uint8_t addr_bytes,
                                     OSPI_MODE addr_mode, bool dma_mode);
static SPINOR_STATUS      queue_bounce_data(uint8_t *data, uint32_t data_bytes,
                                            OSPI_MODE data_mode, bool write, bool dma_mode);
static SPINOR_STATUS      queue_data(uint8_t *data, uint32_t data_bytes,
                                     OSPI_MODE data_mode, bool write, bool dma_mode);
static SPINOR_STATUS      queue_direct_data(uint8_t *data, uint32_t data_bytes,
                                            OSPI_MODE data_mode, bool write, bool dma_mode);
static SPINOR_STATUS      queue_dummy(uint8_t dummy_clocks, bool dma_mode, OSPI_MODE data_mode, OSPI_MODE addr_mode);
static SPINOR_STATUS      queue_opcode(uint16_t opcode, OSPI_MODE cmd_mode, bool dma_mode, uint8 sdr_opcode_bytes);

#ifdef SPINOR_CRC_ENABLE
static SPINOR_STATUS      crc_append_data_func(uint8_t *data, uint32_t data_bytes);
static SPINOR_STATUS      crc_unpack_data_func(uint8_t *data, uint32_t data_bytes);
static SPINOR_STATUS      crc_append_addr(uint32_t addr, uint8_t addr_bytes);
#endif
/*==================================================================================================
                                          LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================

FUNCTION: allocate_descriptor

DESCRIPTION:
   This function allocates a new descriptor, adds it to the chain, and returns a pointer to the
   new descriptor.  If no descriptors are available or there is not enough free space in the DMA
   buffer then the existing chain will be flushed to HW and a new chain will be created.

   We assume bytes_needed <= sizeof(dma_buffer).  We also assume that dma_buffer ends on a
   32-byte boundary (if not, the free_ptr calculation below can fail).

==================================================================================================*/
static DESCRIPTOR *allocate_descriptor(uint32_t bytes_needed, bool dma_mode)
{
   uint32_t alignment;
   uint8_t *free_ptr;
   uint32_t room;
   DESCRIPTOR *current;
   DESCRIPTOR *next;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;
   boolean dma_done =  FALSE;

   // get pointer to free space in DMA buffer and calculate room available

   alignment = dma_mode ? OSPI_DMA_CACHE_LN_ALIGNMENT : OSPI_PIO_ALIGNMENT;
   free_ptr = dma_free_ptr;
   free_ptr = (uint8_t *)(((uintptr_t)free_ptr + alignment - 1) & ~(alignment - 1));
   room = dma_buffer + sizeof(dma_buffer) - free_ptr;

   // get pointer to next free descriptor

   current = get_last_descriptor();
   if (current) { next = current + 1; }
   else         { next = &dma_descriptors[0]; }

   if ((uint8_t *)next >= (uint8_t *)dma_descriptors + sizeof(dma_descriptors)) { next = NULL; }

   // flush existing chain if necessary

   if (room < bytes_needed || next == NULL)
   {
      DEBUG_LOG(SAIL_ERROR,"%s: Error, Running out of descriptors. Split the tranactions \r\n", __func__);
      return NULL;
   }

   // populate descriptor

   next->data_address    = bytes_needed ? (uint32_t)free_ptr : 0;
   next->next_descriptor = 0;
   next->direction       = MASTER_READ;
   next->multi_io_mode   = 0;
   next->reserved1       = 0;
   next->fragment        = 1;
   next->reserved2       = 0;
   next->length          = 0;
   next->bounce_src      = 0;
   next->bounce_dst      = 0;
   next->bounce_length   = 0;

   // add descriptor to chain

   if (current) { current->next_descriptor = (uint32_t)next; }
   else         { dma_chain = next; }

   return(next);
}

/*==================================================================================================

FUNCTION: available_room

DESCRIPTION:
   This function calculates the room available in the last descriptor in the chain (the caller
   must pass in a pointer to the *last* descriptor).

==================================================================================================*/
static uint32_t available_room(DESCRIPTOR *last)
{
   uint8_t *end_of_buffer = dma_buffer + sizeof(dma_buffer);

   if (INT_TO_PTR(last->data_address) <  (void *)dma_buffer)    { return(0); }
   if (INT_TO_PTR(last->data_address) >= (void *)end_of_buffer) { return(0); }

   return (uint32_t)(end_of_buffer - (last->data_address + last->length));
}

/*==================================================================================================

FUNCTION: flush_chain

DESCRIPTION:
   This function flushes the existing DMA chain to hardware.

==================================================================================================*/
static SPINOR_STATUS flush_chain(bool dma_mode)
{
   DESCRIPTOR *desc = dma_chain;
   uint8_t *src;
   uint8_t *dst;
   uint32_t *src_dma;
   uint32_t *dst_dma;
   uint32_t i;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   status = spinor_hal_configure_dma_mode(dma_mode);
   if(status != SPINOR_DEVICE_DONE)
   {
      DEBUG_LOG(SAIL_ERROR,"%s: hal_config_dma_mode failed \r\n", __func__);
      goto flush_chain_end;
   }

   // Execute the transfers specified in the chain of descriptors.

   if (dma_mode) { spinor_hal_dma_transfer_chain((uint32_t)dma_chain); }
   else          { status = pio_transfer_chain(dma_chain); }

   if(status != SPINOR_DEVICE_DONE)
   {
      DEBUG_LOG(SAIL_ERROR,"%s: transfer chain (dma/pio) failed \r\n", __func__);
      goto flush_chain_end;
   }

flush_chain_end:
   return status;
}

/**********************************************************
 * Copy the data from bounce buffers
 *
 * @param dma_mode [IN]
 *   DMA mode
 *
 * @return int [OUT]
 *   Result of the operation. 0 for success, non zero for error
 *
 **********************************************************/
SPINOR_STATUS dma_pio_copy_bounce_data(bool dma_mode)
{
   DESCRIPTOR *desc = dma_chain;
   uint8_t *src;
   uint8_t *dst;
   uint32_t *src_dma;
   uint32_t *dst_dma;
   uint32_t i;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   // Copy any bounce data from the descriptors to the client buffer (for reads only).

   while (desc)
   {
      if (desc->direction == MASTER_READ) {
         if (dma_mode && desc->bounce_length == 0) {
            spinor_cache_inval(INT_TO_PTR(desc->data_address),desc->length);
         }
         else {
            src = INT_TO_PTR(desc->bounce_src);
            dst = INT_TO_PTR(desc->bounce_dst);

            //Do word copy if destination and length is word aligned in DMA mode.
            if ((dma_mode) && !(desc->bounce_length & 0x3) && !(desc->bounce_dst & 0x3)) {
               spinor_cache_inval(src, desc->bounce_length);
               src_dma = (uint32_t*)src;
               dst_dma = (uint32_t*)dst;

               for (i = 0; i < desc->bounce_length>>2; i++) {
                  dst_dma[i] = src_dma[i];
               }
            }
            else {
              for (i = 0; i < desc->bounce_length; i++) {
                    dst[i] = src[i];
                }
            }
         }
      }
      desc = INT_TO_PTR(desc->next_descriptor);
   }

   SPINOR_DSB;

   dma_free_ptr = dma_buffer;
   dma_chain = NULL;

   return status;
}

/*==================================================================================================

FUNCTION: get_last_descriptor

DESCRIPTION:
   This function returns a pointer to the last descriptor in the chain.  If no chain exists
   then NULL is returned.

==================================================================================================*/
static DESCRIPTOR *get_last_descriptor(void)
{
   DESCRIPTOR *desc = dma_chain;

   if (desc)
   {
      while (desc->next_descriptor) { desc = INT_TO_PTR(desc->next_descriptor); }
   }

   return(desc);
}

/*==================================================================================================

FUNCTION: pio_transfer_chain

DESCRIPTION:
   This function transfers a chain of descriptors over the bus using PIO mode.

==================================================================================================*/
static SPINOR_STATUS pio_transfer_chain(DESCRIPTOR *chain)
{
   DESCRIPTOR *desc = chain;
   bool write;
   uint8_t *buffer;
   uint32_t num_bytes;
   uint32_t pio_transfer_config;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   while (desc)
   {
      write = (desc->direction == MASTER_WRITE);
      buffer = INT_TO_PTR(desc->data_address);
      num_bytes = desc->length;
      pio_transfer_config = (desc->fragment ? HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_FRAGMENT_BMSK : 0) |
                            (desc->multi_io_mode << HWIO_QSPI_PIO_TRANSFER_CONFIG_MULTI_IO_MODE_SHFT) |
                            (write ? HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_DIRECTION_BMSK : 0);

      if (write)
      {
        status = spinor_hal_pio_write(buffer, num_bytes, pio_transfer_config);
      }
      else
      {
        status = spinor_hal_pio_read (buffer, num_bytes, pio_transfer_config);
      }

      if(status == SPINOR_DEVICE_FAIL)
      {
          DEBUG_LOG(SAIL_ERROR,"%s: pio read/write failed \r\n", __func__);
          goto pio_transfer_chain_end;
      }

      desc = INT_TO_PTR(desc->next_descriptor);
   }

pio_transfer_chain_end:
    return status;
}

/*==================================================================================================

FUNCTION: queue_addr

DESCRIPTION:
   Queue the 3-byte or 4-byte address (cmd-ADDR-dummy-data).

==================================================================================================*/
static SPINOR_STATUS queue_addr(uint32_t addr, uint8_t addr_bytes, OSPI_MODE addr_mode, bool dma_mode)
{
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;
   DESCRIPTOR *desc;
   uint8_t *ptr, *ptr_org;
   uint32_t i;

   if (addr_bytes == 0)
   {
      goto queue_addr_end;
   }

   desc = get_last_descriptor();

#ifdef SPINOR_CRC_ENABLE
   if(octalspi_crc_flag == TRUE && addr_bytes == 4)
   {
      status = crc_append_addr (addr, addr_bytes);
      if(status != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG(SAIL_ERROR,"%s: crc_append_addr failed \r\n", __func__);
          goto queue_addr_end;
      }
      addr_bytes += crc_params.bytes_removed_or_added_addr;
   }
#endif

   // Check if we can add to the last descriptor else allocate a new one.

   if (desc &&
       desc->direction == MASTER_WRITE &&
       desc->multi_io_mode == addr_mode &&
       available_room(desc) >= addr_bytes)
   {
      ptr = INT_TO_PTR(desc->data_address + desc->length);
   }
   else
   {
      desc = allocate_descriptor(addr_bytes, dma_mode);
      if(desc == NULL)
      {
          status = SPINOR_DEVICE_FAIL;
          DEBUG_LOG(SAIL_ERROR,"%s: allocate desc failed \r\n", __func__);
          goto queue_addr_end;
      }
      desc->direction = MASTER_WRITE;
      desc->multi_io_mode = addr_mode;
      ptr = INT_TO_PTR(desc->data_address);
   }

   // Write the address to the descriptor.
   ptr_org = ptr;
   for (i = addr_bytes; i > 0; i--)
   {
#ifdef SPINOR_CRC_ENABLE
      if(octalspi_crc_flag == TRUE)
          *ptr++ = crc_params.crc_address_buffer[addr_bytes-i];
      else
#endif
          *ptr++ = (uint8_t)(addr >> (i - 1) * 8);
   }
   if (dma_mode) { spinor_cache_flush_inval(ptr_org, addr_bytes); }
   desc->length += addr_bytes;
   dma_free_ptr = INT_TO_PTR(desc->data_address + desc->length);

queue_addr_end:
   return status;
}

/*==================================================================================================

FUNCTION: queue_bounce_data

DESCRIPTION:
   Queue bounce data.  This is data that will use a bounce buffer that sits between the
   client buffer and hardware.  The bounce buffer is used to accommodate misaligned data.

==================================================================================================*/
static SPINOR_STATUS queue_bounce_data(uint8_t *data, uint32_t data_bytes,
                              OSPI_MODE data_mode, bool write, bool dma_mode)
{
   DESCRIPTOR *desc;
   uint8_t *ptr;
   uint32_t i;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   desc = allocate_descriptor(data_bytes, dma_mode);
   if(desc == NULL)
   {
       status = SPINOR_DEVICE_FAIL;
       DEBUG_LOG(SAIL_ERROR,"%s: allocate desc failed \r\n", __func__);
       goto queue_bounce_data_end;
   }
   desc->direction = write;
   desc->multi_io_mode = data_mode;
   ptr = INT_TO_PTR(desc->data_address);

   // Write the bounce data to the descriptor now or save the parameters
   // needed to read the bounce data from the descriptor later.
   if (write)
   {
      for (i = 0; i < data_bytes; i++) { ptr[i] = data[i]; }
      if (dma_mode) { spinor_cache_flush_inval(ptr, data_bytes); }
   }
   else
   {
      desc->bounce_src = (uint32_t)ptr;
      desc->bounce_dst = (uint32_t)data;
      desc->bounce_length = data_bytes;
      if (dma_mode) { spinor_cache_flush_inval(ptr, data_bytes); }
   }

   desc->length += data_bytes;
   dma_free_ptr = INT_TO_PTR(desc->data_address + desc->length);

queue_bounce_data_end:
   return status;
}

/*==================================================================================================

FUNCTION: queue_data

DESCRIPTION:
   Queue the data from the client buffer.  The data may be split into multiple parts to
   ensure the following:

   1) the buffer starts on a 32-byte boundary (for DMA) or a 4-byte boundary (for PIO)
   2) the buffer ends on a 4-byte boundary (only required for DMA reads)
   3) the buffer is no larger than 65535 (0xFFFF) bytes

   It is straightforward to handle (3) by splitting the buffer across multiple descriptors.
   Bounce buffers are used to handle (1) and (2).

==================================================================================================*/
static SPINOR_STATUS queue_data(uint8_t *data, uint32_t data_bytes,
                       OSPI_MODE data_mode, bool write, bool dma_mode)
{
   uint32_t alignment;
   uint8_t *aligned_ptr;
   uint8_t *epilog_ptr;
   uint32_t prolog_bytes, aligned_bytes, epilog_bytes;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   if (data_bytes == 0)
   {
      goto queue_data_end;
   }

   alignment = dma_mode ? OSPI_DMA_CACHE_LN_ALIGNMENT : OSPI_PIO_ALIGNMENT;
   aligned_ptr = (uint8_t *)(((uintptr_t)data + alignment - 1) & ~(alignment - 1));
   prolog_bytes = ((aligned_ptr - data) > data_bytes) ? (data_bytes) : (aligned_ptr - data);
   epilog_bytes = (dma_mode && !write) ? ((data_bytes - prolog_bytes) & 0x03) : (0);
   aligned_bytes = data_bytes - prolog_bytes - epilog_bytes;
   epilog_ptr = data + prolog_bytes + aligned_bytes;

   if (aligned_bytes == 0)
   {
      // Combine prolog and epilog if there is nothing between them.  This avoids
      // the need to have two bounce buffers in the same descriptor.

      prolog_bytes += epilog_bytes;
      epilog_bytes = 0;
   }

   if (prolog_bytes)  { status = queue_bounce_data(data, prolog_bytes,  data_mode, write, dma_mode); }
   if (aligned_bytes) { status = queue_direct_data(aligned_ptr, aligned_bytes, data_mode, write, dma_mode); }
   if (epilog_bytes)  { status = queue_bounce_data(epilog_ptr,  epilog_bytes,  data_mode, write, dma_mode); }

queue_data_end:
    return status;
}

/*==================================================================================================

FUNCTION: queue_direct_data

DESCRIPTION:
   Queue direct data.  This is data that will be copied directly between the client buffer
   and the hardware (and must be properly aligned).

==================================================================================================*/
static SPINOR_STATUS queue_direct_data(uint8_t *data, uint32_t data_bytes,
                              OSPI_MODE data_mode, bool write, bool dma_mode)
{
   DESCRIPTOR *desc;
   uint32_t chunk_size;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   while (data_bytes)
   {
      // Maximum transfer size is 0xFFFF bytes but 0xFFC0 is the largest size that
      // maintains 32-byte alignment between chunks.

      chunk_size = (data_bytes > DMA_MAX_TRSFR_LEN_PER_DESCRIPTOR) ? (DMA_MAX_TRSFR_LEN_PER_DESCRIPTOR) : (data_bytes);

      // Allocate a new descriptor and point it to the client buffer.

      desc = allocate_descriptor(0, dma_mode);
      if(desc == NULL)
      {
          status = SPINOR_DEVICE_FAIL;
          DEBUG_LOG(SAIL_ERROR,"%s: allocate desc failed \r\n", __func__);
          goto queue_direct_data_end;
      }
      desc->direction = write;
      desc->multi_io_mode = data_mode;
      desc->data_address = (uint32_t)data;
      desc->length = chunk_size;

      data += chunk_size;
      data_bytes -= chunk_size;

      if (dma_mode) {
         if (write) {
            spinor_cache_flush_inval(INT_TO_PTR(desc->data_address), desc->length);
         } else {
            spinor_cache_inval(INT_TO_PTR(desc->data_address), desc->length);
         }
      }
   }

queue_direct_data_end:
   return status;
}

/*==================================================================================================

FUNCTION: queue_dummy

DESCRIPTION:
   Queue dummy bytes to generate dummy clock cycles (cmd-addr-DUMMY-data).

   Note that we must use a write to drive DQ3 (HOLD_N) high when generating dummy clock cycles
   in 4-wire mode.  If we use a read then we will release DQ2 (WP_N) and DQ3 (HOLD_N) which will
   cause them to go low (assert).  This will cause the slave to ignore all but one of the dummy
   clock cycles (the first one gets through because it takes some time for HOLD_N to go low).

==================================================================================================*/
static SPINOR_STATUS queue_dummy(uint8_t dummy_clocks, bool dma_mode, OSPI_MODE data_mode, OSPI_MODE addr_mode )
{
   DESCRIPTOR *desc;
   uint8_t *ptr = NULL;
   uint32_t dummy_bytes;
   uint32_t clocks_per_byte;
   uint32_t remainder;
   uint32_t i;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;
   OSPI_MODE mode_to_use = SDR_8BIT;

   if (dummy_clocks == 0)
   {
      return status;
   }

   /* For this logic to work at lower frequencies, the number of dummy_clock cycles should be a multiple of the clocks_per_byte.
    Otherwise at lower frequencies, it might try to send the dummy_cycles in SDR_8BIT mode (for non SDR_8BIT data mode).
    This might cause issues. */

   switch (data_mode)
   {
      case SDR_1BIT: clocks_per_byte = 8; break;
      case SDR_2BIT: clocks_per_byte = 4; break;
      case SDR_4BIT: clocks_per_byte = 2; break;
      case SDR_8BIT: clocks_per_byte = 1; break;
      case DDR_1BIT: clocks_per_byte = 4; break;
      case DDR_2BIT: clocks_per_byte = 2; break;
      case DDR_4BIT: clocks_per_byte = 1; break;
      case DDR_8BIT: clocks_per_byte = 0; break;   // set clocks_per_byte and handle it below
      default: status = SPINOR_DEVICE_FAIL; return status;  // fatal error
   }


   if(clocks_per_byte)
   {
      remainder   = dummy_clocks % clocks_per_byte;
      if(remainder)
      {
          dummy_bytes = dummy_clocks;
          mode_to_use = SDR_8BIT;
      }
      else
      {
          dummy_bytes = dummy_clocks / clocks_per_byte;
          mode_to_use = data_mode;
      }
   }
   else
   {
      dummy_bytes = dummy_clocks;
      mode_to_use = DDR_8BIT;
   }

   desc = allocate_descriptor(dummy_bytes, dma_mode);
   if(desc == NULL)
   {
      status = SPINOR_DEVICE_FAIL;
      DEBUG_LOG(SAIL_ERROR,"%s: allocate desc failed \r\n", __func__);
      goto queue_dummy_end;
   }

   desc->direction = MASTER_READ;
   desc->multi_io_mode = mode_to_use;
   ptr = INT_TO_PTR(desc->data_address);
   desc->length += dummy_bytes;
   dma_free_ptr = INT_TO_PTR(desc->data_address + desc->length);

queue_dummy_end:
   return status;
}

/*==================================================================================================

FUNCTION: queue_opcode

DESCRIPTION:
   Queue the 2-byte/1-byte command opcode (CMD-addr-dummy-data).

==================================================================================================*/
static SPINOR_STATUS queue_opcode(uint16_t opcode, OSPI_MODE cmd_mode, bool dma_mode, uint8 sdr_opcode_bytes)
{
   DESCRIPTOR *desc;
   uint8_t *ptr;
   uint32_t opcode_bytes = 0;
   if(cmd_mode == SDR_8BIT)
       opcode_bytes = sdr_opcode_bytes;
   else if(cmd_mode == DDR_8BIT)
       opcode_bytes = 2;
   else
       opcode_bytes = 1;
   uint32_t i;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;

   desc = get_last_descriptor();

   // Check if we can add to the last descriptor else allocate a new one.

   if (desc &&
       desc->direction == MASTER_WRITE &&
       desc->multi_io_mode == cmd_mode &&
       available_room(desc) >= opcode_bytes)
   {
      ptr = INT_TO_PTR(desc->data_address + desc->length);
   }
   else
   {
      desc = allocate_descriptor(opcode_bytes, dma_mode);
      if(desc == NULL)
      {
          status = SPINOR_DEVICE_FAIL;
          DEBUG_LOG(SAIL_ERROR,"%s: allocate desc failed \r\n", __func__);
          goto queue_opcode_end;
      }
      desc->direction = MASTER_WRITE;
      desc->multi_io_mode = cmd_mode;
      ptr = INT_TO_PTR(desc->data_address);
   }

   // Write the opcode to the descriptor.
   for (i = 0; i < opcode_bytes; i++)
   {
      ptr[i] = (uint8)(opcode>>i*8);
   }

   if (dma_mode) { spinor_cache_flush_inval(ptr, opcode_bytes); }
   desc->length += opcode_bytes;
   dma_free_ptr = INT_TO_PTR(desc->data_address + desc->length);

queue_opcode_end:
   return status;
}

/*==================================================================================================
                                          GLOBAL FUNCTIONS
==================================================================================================*/
/*==================================================================================================

FUNCTION: spinor_dma_pio_transfer

DESCRIPTION:
   This function executes a complete SPI NOR flash transaction including the command, address,
   dummy clock cycles, and data.  In most cases, this function should be used instead of the
   low level read/write APIs.

==================================================================================================*/
bool spinor_dma_pio_transfer(OSPI_CMD *cmd, uint32_t addr, uint8_t *data, uint32_t data_bytes, bool enable_dma, uint8 sdr_opcode_bytes)
{
   DESCRIPTOR *last;
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;
   uint8 *temp_buffer;
   uint32_t temp_data_bytes;
   int byte_rem, chunk_count, number_of_crc_chunks;

   if (cmd->addr_bytes   > 4)
   {
       DEBUG_LOG(SAIL_ERROR,"%s: address bytes > 4 \r\n", __func__);
       return false;
   }

   if(status != SPINOR_DEVICE_DONE)
   {
       return false;
   }

#ifdef SPINOR_CRC_ENABLE
   /* Appending data if CRC is enabled */
   if(octalspi_crc_flag == TRUE && (ospi_cmd_id == OSPI_WRITE_OP || ospi_cmd_id == REG_WRITE_OP) && (data_bytes != 0)) /* Write Operations */
   {
       status = crc_append_data_func(data, data_bytes);
       if(status != SPINOR_DEVICE_DONE)
       {
          DEBUG_LOG(SAIL_ERROR,"%s: crc_append_data failed \r\n", __func__);
          return false;
       }
       temp_buffer = crc_params.crc_data_buffer;
       temp_data_bytes = data_bytes + crc_params.bytes_removed_or_added;
   }
   else if(octalspi_crc_flag == TRUE && ospi_cmd_id == REG_READ_OP) /* Register Read Operations */
   {
       temp_buffer = crc_params.crc_data_buffer;
       temp_data_bytes = (data_bytes * 4);
       crc_params.bytes_removed_or_added = (data_bytes * 3);
   }
   else if(octalspi_crc_flag == TRUE && (ospi_cmd_id == OSPI_READ_OP || ospi_cmd_id == OSPI_SFDP_OP)) /* Memory Read Operations */
   {
       temp_buffer = crc_params.crc_data_buffer;
       byte_rem = data_bytes % CRC_CHUNK_SIZE;
       chunk_count = data_bytes / CRC_CHUNK_SIZE;
       number_of_crc_chunks = (byte_rem == 0) ? (chunk_count) : (chunk_count + 1);
       if(byte_rem != 0)
       {
           crc_params.extra_FFs_packed = CRC_CHUNK_SIZE - byte_rem;
       }
       crc_params.bytes_removed_or_added = (2 * number_of_crc_chunks) + crc_params.extra_FFs_packed;
       temp_data_bytes = data_bytes + crc_params.bytes_removed_or_added;
   }
   else /* Other Operations : No Appending needed */
#endif
   {
       temp_buffer = data;
       temp_data_bytes = data_bytes;
   }

#ifdef SPINOR_CRC_ENABLE
   crc_params.temp_data_bytes = temp_data_bytes;
#endif

   status = queue_opcode(cmd->opcode, cmd->cmd_mode, enable_dma, sdr_opcode_bytes);
   status = queue_addr(addr, cmd->addr_bytes, cmd->addr_mode, enable_dma);
   status = queue_dummy(cmd->dummy_clocks, enable_dma, cmd->data_mode, cmd->addr_mode);
   status = queue_data(temp_buffer, temp_data_bytes, cmd->data_mode, cmd->write, enable_dma);

   if(status != SPINOR_DEVICE_DONE)
   {
       DEBUG_LOG(SAIL_ERROR,"%s: queue opcode/addr/dummy/data failed \r\n", __func__);
       return false;
   }

   last = get_last_descriptor();
   last->fragment = 0;  // deassert chip select after completing the last 1

   if (enable_dma) {
      uint32_t len = (last - dma_chain + 1) * sizeof(DESCRIPTOR);
      spinor_cache_flush_inval((uint8_t *)dma_chain, len);
   }

   status = flush_chain(enable_dma);
   if(status != SPINOR_DEVICE_DONE)
   {
      DEBUG_LOG(SAIL_ERROR,"%s: flush chain failed \r\n", __func__);
      return false;
   }

   return true;
}

#ifdef SPINOR_CRC_ENABLE
/**********************************************************
 * Unpack the CRC data
 *
 * @param data [IN/OUT]
 *   Data buffer to unpack the data
 *
 * @param data_bytes [IN]
 *   Number of bytes in the orginal data
 *
 * @return boolean [OUT]
 *   Result of the operation. 0 for success, non zero for error
 *
 **********************************************************/
boolean dma_pio_unpack_crc_data(uint8_t *data,uint32 data_bytes)
{
   SPINOR_STATUS status = SPINOR_DEVICE_DONE;
   /* Unpacking the data if CRC is enabled */
   status = crc_unpack_data_func(data, crc_params.temp_data_bytes);
   if(status != SPINOR_DEVICE_DONE)
   {
     DEBUG_LOG(SAIL_ERROR,"%s: crc_unpack_data failed \r\n", __func__);
     return false;
   }
   crc_params.temp_data_bytes -= crc_params.bytes_removed_or_added;

   if(crc_params.temp_data_bytes != data_bytes)
   {
     DEBUG_LOG(SAIL_ERROR,"%s: CRC number of bytes mismatch \r\n", __func__);
     return false;
   }

   crc_params.bytes_removed_or_added = 0;
   crc_params.bytes_removed_or_added_addr = 0;
   crc_params.extra_FFs_packed = 0;
   crc_params.temp_data_bytes = 0;

   return true;
}

/*==================================================================================================

FUNCTION: crc_append_data_func

DESCRIPTION:
   This function appends the data buffer with the CRC related bytes and tranfers the same
   Source buffer : data
   Destination appended buffer : crc_data_buffer

==================================================================================================*/
static SPINOR_STATUS crc_append_data_func(uint8_t *data, uint32_t data_bytes )
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp_crc_val = 0;
    int byte_rem, chunk_count, number_of_crc_chunks;
    crc_params.bytes_removed_or_added = 0;
    crc_params.extra_FFs_packed = 0;

    memset(crc_params.crc_data_buffer, 0, sizeof(crc_params.crc_data_buffer)/sizeof(crc_params.crc_data_buffer[0]));

    /* Follows the same logic for appending the data for both OSPI memory writes and OSPI register writes with data_bytes > 1 */
    if((ospi_cmd_id == OSPI_WRITE_OP) || ((ospi_cmd_id == REG_WRITE_OP) && (data_bytes > 1)))
    {
        byte_rem = data_bytes % CRC_CHUNK_SIZE;
        chunk_count = data_bytes / CRC_CHUNK_SIZE;
        number_of_crc_chunks = (byte_rem == 0) ? (chunk_count) : (chunk_count + 1);
        if(byte_rem != 0)
        {
            crc_params.extra_FFs_packed = CRC_CHUNK_SIZE - byte_rem;
        }

        /* Appending for the defined data_bytes */
        for(int i = 0; i< number_of_crc_chunks - 1 ; i++) // 0,1,2,3...14
        {
          int t = i+1; //1,2,3,4...16
          temp_crc_val = 0;
          for(int j = i*CRC_CHUNK_SIZE ; j < t * CRC_CHUNK_SIZE ; j++) //0 to 15, 16 to 31, ..., 224 to 239 -> buffer values
          {
            crc_params.crc_data_buffer[2*i+j] = data[j];
            temp_crc_val ^= data[j];
          }
          crc_params.crc_data_buffer[18*t - 2] = temp_crc_val;
          crc_params.crc_data_buffer[18*t - 1] = ~(temp_crc_val); /* Check if needed for reg_write operation */
        }

        /* Last Iteration where the remaining data_bytes (which is not a multiple of 16 byte chunk) is written and the remaining space
           (to fill it up unil the 16byte chunk boundary, if any) is packed with 0xFFs */
        int i = number_of_crc_chunks - 1; //15
        int t = number_of_crc_chunks;
        temp_crc_val = 0;
        for(int j = i*CRC_CHUNK_SIZE ; j < data_bytes ; j++) //240 to 255 -> buffer values
        {
          crc_params.crc_data_buffer[2*i+j] = data[j];
          temp_crc_val ^= data[j];
        }
        if(crc_params.extra_FFs_packed != 0)
        {
          for(int j = data_bytes ; j < data_bytes + crc_params.extra_FFs_packed ; j++)
          {
            crc_params.crc_data_buffer[2*i+j] = 0xFF;
          }
          if(crc_params.extra_FFs_packed % 2 != 0)
          {
            temp_crc_val = ~(temp_crc_val);
          }
        }
        crc_params.crc_data_buffer[18*t - 2] = temp_crc_val;
        crc_params.crc_data_buffer[18*t - 1] = ~(temp_crc_val);
        crc_params.bytes_removed_or_added += (number_of_crc_chunks * 2) + crc_params.extra_FFs_packed;
        goto crc_append_data_func_end;
    }
    else /* data_bytes == 1 and ospi_cmd_id == REG_WRITE_OP */
    {
      crc_params.crc_data_buffer[0] = data[0];
      crc_params.crc_data_buffer[1] = data[0];
      crc_params.crc_data_buffer[2] = ~(data[0]);
      crc_params.crc_data_buffer[3] = ~(data[0]);
      crc_params.bytes_removed_or_added += 3;
      goto crc_append_data_func_end;
    }

crc_append_data_func_end:
    return status;
}

/*==================================================================================================

FUNCTION: crc_unpack_data_func

DESCRIPTION:
   This function unpacks the appended CRC buffer and transfers only the data bytes to the data buffer. It removes the CRC bytes.
   Source buffer : crc_data_buffer
   Destination appended buffer : data

==================================================================================================*/
static SPINOR_STATUS crc_unpack_data_func(uint8_t *data, uint32_t data_bytes)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp_crc_val = 0;
    int byte_rem, chunk_count, number_of_crc_chunks;
    crc_params.bytes_removed_or_added = 0;
    int j, bytes_retained = 0;
    int last_relevant_data = 0, start_index = 0;

    /* data unpacking: Follows the same logic for unpacking the data for both OSPI memory reads and OSPI register reads with data_bytes > 1
       (Read SFDP cmd) */
    if(ospi_cmd_id == OSPI_READ_OP || ospi_cmd_id == OSPI_SFDP_OP)
    {
        chunk_count = data_bytes/(CRC_CHUNK_SIZE+2);
        number_of_crc_chunks = (ospi_cmd_id == OSPI_SFDP_OP) ? (chunk_count) : (chunk_count - 1);

        /* SFDP case : ?
           READ_OP case : process all upto last chunk; last chunk need to remove FFs if applicable */

        for(int i = 0; i < number_of_crc_chunks; i++)
        {
            int t = i+1;
            temp_crc_val = 0;
            for(j = i * CRC_CHUNK_SIZE; j < t * CRC_CHUNK_SIZE ; j++)
            {
                data[j] = crc_params.crc_data_buffer[2*i+j];
                temp_crc_val ^= crc_params.crc_data_buffer[2*i+j];
            }

            if(crc_params.crc_data_buffer[18*t - 2] != temp_crc_val)
            {
                DEBUG_LOG(SAIL_ERROR," data crc check for chunk number %d failed", t);
                status = SPINOR_DEVICE_FAIL;
                goto crc_unpack_data_func_end;
            }
        }

        /* Only for READ_OP: removing the FFs (if any) and processing the last chunk */
        j = 0;
        temp_crc_val = 0;
        if(crc_params.extra_FFs_packed != 0)
        {
            last_relevant_data = (CRC_CHUNK_SIZE - crc_params.extra_FFs_packed);
            start_index = number_of_crc_chunks * CRC_CHUNK_SIZE;
        }
        else
        {
            last_relevant_data = CRC_CHUNK_SIZE;
            start_index = number_of_crc_chunks * CRC_CHUNK_SIZE;
        }
        for(j = start_index ; j < start_index + last_relevant_data; j++)
        {
            data[j] = crc_params.crc_data_buffer[2*number_of_crc_chunks + j];
            temp_crc_val ^= crc_params.crc_data_buffer[2*number_of_crc_chunks + j];
        }

        if(crc_params.crc_data_buffer[2*number_of_crc_chunks + j] != temp_crc_val)
        {
            DEBUG_LOG(SAIL_ERROR," data crc check for chunk number %d failed", chunk_count);
            status = SPINOR_DEVICE_FAIL;
            goto crc_unpack_data_func_end;
        }

        crc_params.bytes_removed_or_added += (chunk_count * 2) + crc_params.extra_FFs_packed;
        goto crc_unpack_data_func_end;
    }
    else if(ospi_cmd_id == REG_READ_OP)
    {
        int n = 0;
        bytes_retained = 0;
        for(int i = 0 ; i < data_bytes ; i++)
        {
            if( i % 4 == 0)
            {
                data[n++] = crc_params.crc_data_buffer[i];
                bytes_retained++;
            }
        }
        crc_params.bytes_removed_or_added += (data_bytes - bytes_retained);
        goto crc_unpack_data_func_end;
    }

crc_unpack_data_func_end:
    return status;
}

/*==================================================================================================

FUNCTION: crc_append_addr

DESCRIPTION:
   This function appends the address bytes with the CRC related bytes and tranfers the same
   Source address : addr
   Destination appended address : crc_address_buffer

==================================================================================================*/
static SPINOR_STATUS crc_append_addr(uint32_t addr, uint8_t addr_bytes)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    crc_params.bytes_removed_or_added_addr = 0;

    if(addr_bytes > 4)
    {
        status = SPINOR_DEVICE_FAIL;
        return status;
    }

    for(int i = addr_bytes; i > 0; i--)
    {
        crc_params.crc_address_buffer[4-i] = addr >> (i - 1) * 8;
    }
    crc_params.crc_address_buffer[4] = (crc_params.crc_address_buffer[0] ^ crc_params.crc_address_buffer[1] ^ crc_params.crc_address_buffer[2] ^ crc_params.crc_address_buffer[3]);
    crc_params.crc_address_buffer[5] = ~(crc_params.crc_address_buffer[4]);
    crc_params.bytes_removed_or_added_addr += 2;

    status = SPINOR_DEVICE_DONE;
    return status;
}

/**********************************************************
 * Set the OSPI command flag for the operation ID.
 *
 * @return operation_id [IN]
 *   Operation ID.
 *
 **********************************************************/
void SetOSPICmdFlag(OSPI_OP_ID operation_id)
{
    ospi_cmd_id = operation_id;
}

/**********************************************************
 * Get the OSPI command flag.
 *
 * @return int [OUT]
 *   Operation ID.
 *
 **********************************************************/
OSPI_OP_ID GetOSPICmdFlag(void)
{
    return ospi_cmd_id;
}

/**********************************************************
 * Set the CRC flag.
 *
 * @return value [IN]
 *   value to set.
 *
 **********************************************************/
void SetCRCFlag(bool value)
{
    octalspi_crc_flag = value;
}

/**********************************************************
 * Get the CRC flag.
 *
 * @return bool [OUT]
 *   value to CRC flag.
 *
 **********************************************************/
bool GetCRCFlag(void)
{
    return octalspi_crc_flag;
}
#endif