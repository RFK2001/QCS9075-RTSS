/* Linker script to configure memory regions. 
 *   EL1_SRAM.ORIGIN: starting address of EL1_SRAM
 *   EL1_SRAM.LENGTH: length of EL1_SRAM
 *   EL1_STACK.ORIGIN: starting address of EL1_STACK
 *   EL1_STACK.LENGTH: length of EL1_STACK
 *   NOINIT_MBOSH.ORIGIN: starting address of NOINIT_MBOSH
 *   NOINIT_MBOSH.LENGTH: length of NOINIT_MBOSH
 *   EL_SHARED_REGION.ORIGIN: starting address of EL_SHARED_REGION
 *   EL_SHARED_REGION.LENGTH: length of EL_SHARED_REGION
 */
MEMORY
{
  EL1_SRAM (rwx) : ORIGIN = 0x080FA000, LENGTH = 0x196800 /* 1.6MB */
  EL1_STACK (rwx) : ORIGIN = 0x08290800, LENGTH = 0xC000 /* 48KB */
  NOINIT_MBOSH (rwx) : ORIGIN = 0x082E0C00, LENGTH = 0x14400 /* 81KB */
  EL_SHARED_REGION (rwx) : ORIGIN = 0x082FB000, LENGTH = 0x1000 /* 4KB */
}

/* Entry Point: Vector Table */
ENTRY(EL1_Vectors)

SECTIONS
{
    .PRIV_CODE :
    {
        KEEP( *vectors.o( .text.vectors ) )
        *( privileged_functions )
    } > EL1_SRAM

    /* All RO sections go into this region */
    .UNPRIV_CODE :
    {
        . = ALIGN(256);
        KEEP( *bootcode.o( .text.boot ) )
        *( clock_func )
        *( syscall_func )
        *( exception_func )
        *( el1main_func )
        *( cpu_runtimestats_func )
        *( cpu_custom_utilization_func )
        *( boot_func )
        *( ipcc_func )
        *( isd_func )
        *( chipinfo_func )
        *( pmic_func )
        *( spinor_func )
        *( pwr_controller_func )
        *( crashdbg_func )
        *( noc_func )
        *( tsens_func )
        *( trusens_func )
        *( vsens_func )
        *( crc_func )
        *( crc_ro )
        *( fdt_func )
        *( mailbox_int_func )
        *( mailbox_ext_func )
        *( wdt_func )
        *( spi_func )
        *( spi_ro )
        *( mailbox_int_func )
        *( mailbox_ext_func )
        *( spinor_func )
        *( freertos_system_calls )
        *( gpttimer_api )
    } > EL1_SRAM

    /* Syscall table for SVC framework. */
    .syscall_table :
    {
        . = ALIGN(256);
        lnk_syscall_table_start_addr = .;
        KEEP( *( _sail_syscall ) )
        lnk_syscall_table_end_addr = .;

        lnk_syscall_table_length = lnk_syscall_table_end_addr - lnk_syscall_table_start_addr;
    } > EL1_SRAM

    /* FreeRTOS Privileged DATA */
    .PRIV_RAM :
	{
        . = ALIGN(256);
        *( privileged_data )
    } > EL1_SRAM

    /* ICB data*/
    .ICB_DATA :
    {
        . = ALIGN(64);
        * ( icb_data )
    } > EL1_SRAM

    /* ISD driver data section */
    .ISD_DATA :
    {
        . = ALIGN(64);
        lnk_isd_data_start_addr = .;
        
        * ( isd_data )
        
        . = ALIGN(64);
        lnk_isd_data_end_addr = .;

        lnk_isd_data_length = lnk_isd_data_end_addr - lnk_isd_data_start_addr;
    } > EL1_SRAM

    /* PMIC driver data section */
    .PMIC_DATA :
    {
        . = ALIGN(64);
        * ( pmic_data )
    } > EL1_SRAM

    /* PSAIL driver data section */
    .PSAIL_DATA :
    {
        . = ALIGN(64);
        * ( psail_data )
    } > EL1_SRAM

    /* Mailbox internal and external */
    .MBCOREDATA :
    {
        . = ALIGN(64);
        lnk_mb_core_data_start_addr = .;

        * ( ebr )   /* mailbox r+ section */
		* ( ibr )   /* mailbox r+ section */
		* ( ebrw )  /* mailbox w+ section */
		* ( ibrw )  /* mailbox w+ section */

        . = ALIGN(64);
        lnk_mb_core_data_end_addr = .;
    } > EL1_SRAM

    /* GPIO time sync app data section */
    .GPIO_TS_DATA :
    {
        . = ALIGN(64);
        * ( gpio_ts_data )
    } > EL1_SRAM

    /* GPT Timer Code/Data Section */
    .GPTTIMER :
    {
        . = ALIGN(64);
        lnk_gpt_timer_code_data_start_addr = .;

        * ( gpttimer_ro )
        * ( gpttimer_rw )

        . = ALIGN(64);
        lnk_gpt_timer_code_data_end_addr = .;
    } > EL1_SRAM

    /* UART Data*/
    .UART_DATA :
    {
        . = ALIGN(64);
        lnk_uart_data_start_addr = .;

        * ( uart_data )

        . = ALIGN(64);
        lnk_uart_data_end_addr = .;
    } > EL1_SRAM

    /* SPI data*/
    .SPI_DATA :
    {
        . = ALIGN(64);
        * ( spi_data )
    } > EL1_SRAM

    /* CAN data*/
    .CAN_DATA :
    {
        . = ALIGN(64);
        * ( can_data )
    } > EL1_SRAM

    /* SM App Data section */
    .SM_APP_DATA :
    {
        . = ALIGN(64);
        * ( sm_app_data )
    } > EL1_SRAM

    /* BSP global data section */
    .BSP_GLOBAL_DATA :
    {
        . = ALIGN(64);
        lnk_bsp_global_data_start_addr = .;
        
        * ( bsp_global_data )
        
        . = ALIGN(64);
        lnk_bsp_global_data_end_addr = .;
        
        lnk_bsp_global_data_length = lnk_bsp_global_data_end_addr - lnk_bsp_global_data_start_addr;
    } > EL1_SRAM

    /* BSP priv data section */
    BSP_PRIV_DATA :
    {
        . = ALIGN(64);
        * ( bsp_priv_data )
    } > EL1_SRAM

    /* Test Code */
    .USER_TEST_CODE :
    {
        . = ALIGN(256);
        *( test_func )
    } > EL1_SRAM

    /* Test Data */
    .USER_TEST_DATA :
    {
        . = ALIGN(64);
        *( test_data )
        *( test_bss )
    } > EL1_SRAM

    /* Untagged RO Region */
    .RO :
    {
        . = ALIGN(64);
        *( .text* )
        *( .rodata* )
    } > EL1_SRAM

    /* Untagged RW Region */
    .RW :
    {
        . = ALIGN(64);
        *( .data* )
    } > EL1_SRAM

    /* ZI/BSS Region */
    .bss :
    {
        . = ALIGN(64);
        *( .bss* )
        *( COMMON )
    } > EL1_SRAM

    /* sailbsp_heap_region */
    .SAILBSP_HEAP_DATA :
    {
        . = ALIGN(64);
        lnk_sailbsp_heap_start = .;
        
        * ( sailbsp_heap_data )

        . = ALIGN(64);
        lnk_sailbsp_heap_end = .;

        lnk_sailbsp_heap_length = lnk_sailbsp_heap_end - lnk_sailbsp_heap_start;
        PROVIDE(end = .);
    } > EL1_SRAM

    /* EL1 Stack */
    .ARM_LIB_STACK (NOLOAD):
    {
        lnk_stack_bottom = .;
        . = . + LENGTH(EL1_STACK);
        lnk_stack_top = .;

        lnk_stack_length = lnk_stack_top - lnk_stack_bottom;
    } > EL1_STACK

    /* Shared Memory Region 
     * reserved for EB , UART usecase
     * segment attribute must be No load for SW-N images
     */
    .NOINIT_MBOSH (NOLOAD) :
    {
        . = ALIGN(64);
        lnk_noinit_mbosh_start_addr = .;

        . = ALIGN(8);
        lnk_shr_eb_map_vect = .;
        . = . + 0x100;

        . = ALIGN(8);
        lnk_shr_eb_status = .;
        . = . + 0x100;
        
        . = ALIGN(8);
        lnk_shr_eb_bck_status = .;
        . = . + 0x200;

        . = ALIGN(8);
        lnk_shr_isd_context = .;
        . = . + 0x1000;

        . = ALIGN(8);
        lnk_shr_cdbg_status = .;
        . = . + 0x4;

        . = ALIGN(8);
        lnk_shr_sailsw1_task_history = .;
        . = . + 0x1000;

        . = ALIGN(8);
        lnk_shr_sail_gic_init_stat = .;
        . = . + 0x1000;

        lnk_noinit_mbosh_end_addr = .;
    } > NOINIT_MBOSH

    /* EL shared Region */
    .EL_SHARED_REGION (NOLOAD) :
    {
        . = ALIGN(64);
        lnk_el_shared_region_start_addr = .;
    } > EL_SHARED_REGION
}