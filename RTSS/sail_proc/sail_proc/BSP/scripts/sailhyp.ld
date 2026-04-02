/* Linker script to configure memory regions. 
 *   SDI_STACK.ORIGIN: starting address of SDI_STACK
 *   SDI_STACK.LENGTH: length of SDI_STACK
 *   EL2_SRAM.ORIGIN: starting address of EL2_SRAM
 *   EL2_SRAM.LENGTH: length of EL2_SRAM
 *   EL2_STACK.ORIGIN: starting address of EL2_STACK
 *   EL2_STACK.LENGTH: length of EL2_STACK
 *   NOINIT_MBOSH.ORIGIN: starting address of NOINIT_MBOSH
 *   NOINIT_MBOSH.LENGTH: length of NOINIT_MBOSH
 *   EL_SHARED_REGION.ORIGIN: starting address of EL_SHARED_REGION
 *   EL_SHARED_REGION.LENGTH: length of EL_SHARED_REGION
 */
MEMORY
{
  SDI_STACK (rwx) : ORIGIN = 0x0801D000, LENGTH = 0x400 /* 1KB */
  EL2_SRAM (rwx) : ORIGIN = 0x0801D400, LENGTH = 0xCFC00 /* 831KB */
  /* due to memory limitation had to extend the sram region with GCC. Currently reclaim and sbit regions have been used. TODO: need to check the memory usage */
  EL2_STACK (rwx) : ORIGIN = 0x080ED000, LENGTH = 0xC000 /* 48KB */
  NOINIT_MBOSH (rwx) : ORIGIN = 0x082E0C00, LENGTH = 0x14400 /* 81KB */
  EL_SHARED_REGION (rwx) : ORIGIN = 0x082FB000, LENGTH = 0x1000 /* 4KB */
}

/* Entry Point: Vector Table */
ENTRY(EL2_Vectors)

SECTIONS
{
    /* SDI Stack */
    /* Stack grows downwards, Stack start =  0x080213F0 & Stack end = 0x08021000
     * SDI is System Debug Interface, data here is used for crashdump purposes
     * Refer & update Crashdbg_sdientry.s file for exact stack pointer location
     */
    .SDI_STACK (NOLOAD):
    {
        lnk_sdi_stack_bottom = .;
        . = . + LENGTH( SDI_STACK );
        lnk_sdi_stack_top = .;

        lnk_sdi_stack_length = lnk_sdi_stack_top - lnk_sdi_stack_bottom;
    } > SDI_STACK

    .STARTUP :
    {
        KEEP( *vectors.o( .text.vectors ) )
        . = ALIGN(64);
        KEEP( *bootcode.o( .text.boot ) )
    } > EL2_SRAM

    /* Execution region for the HVC calls. */
    .syscall_table :
    {
        . = ALIGN(256);
        lnk_syscall_table_start_addr = .;
        KEEP( *( _sail_syscall ) )
        lnk_syscall_table_end_addr = .;

        lnk_syscall_table_length = lnk_syscall_table_end_addr - lnk_syscall_table_start_addr;
    } > EL2_SRAM

    /* PRNG FIPS Hybrid Module TEXT */
    /* Need keep at the top of this section to avoid the code location changes */
    /* Function names are explicitly listed here to avoid the chance of re-ordering by the linker */
    .PRNG_INTEGRITY_TEXT_MARKER :
    {
        lnk_prng_intg_txt_mrk_saddr = .;

        *prngFipsHybridModule.o(.text.prng_fips.prngFipsHybridModule)
        *prngFipsHybridModule.o(.text.prng_fips.prngFips_integrity_check)
        *prngFipsHybridModule.o(.text.prng_fips.prngFips_hash_kat)
        *prngFipsHybridModule.o(.text.prng_fips.prngFips_init)
        *prngFipsHybridModule.o(.text.prng_fips.prngFipsHybridGetVersionHash)
        *prngFipsHybridModule.o(.text.prng_fips.prng_fips_memcmp)
        *prngFipsHybridModule.o(.text.prng_fips.prng_fips_memcpy)
        *prngFipsHybridModule.o(.text.prng_fips.prng_fips_memscpy)
        *prngFipsHybridModule.o(.text.prng_fips.prng_fips_memset)
        *prngFipsHybridModule.o(.text.prng_fips.prngFips_busywait)
        *sha256.o(.text.prng_fips.sha256)

        lnk_prng_intg_txt_mrk_eaddr = .;

    } > EL2_SRAM

    /* PRNG FIPS Hybrid Module RODATA */
    /* The rodata variable names are explicitly listed here to avoid the possibility of re-ordering by the linker */
    .PRNG_INTEGRITY_RODATA_MARKER :
    {
        lnk_prng_intg_rodata_mrk_saddr = .;

        KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.K256) )
        KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.sha256_digest) )
        KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.sha256_iv) )
		KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.sha256_msg) )

        lnk_prng_intg_rodata_mrk_eaddr = .;
    } > EL2_SRAM

    .PRNG_INTEGRITY_TEXT_HASH :
	{
        lnk_prng_intg_txt_hash_saddr = .;

		KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.text_hash) )

        lnk_prng_intg_txt_hash_eaddr = .;
	} > EL2_SRAM

    .PRNG_INTEGRITY_RODATA_HASH :
	{
        lnk_prng_intg_rodata_hash_saddr = .;

		KEEP( *prngFipsHybridModule.o(.rodata.prng_fips.rodata_hash) )

        lnk_prng_intg_rodata_hash_eaddr = .;
	} > EL2_SRAM

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
    } > EL2_SRAM

    /* GPT Timer Code/Data Section */
    .GPTTIMER :
    {
        . = ALIGN(64);
        lnk_gpt_timer_code_data_start_addr = .;
        
        * ( gpttimer_ro )
        * ( gpttimer_rw )
        
        . = ALIGN(64);
        lnk_gpt_timer_code_data_end_addr = .;
    } > EL2_SRAM

    /* UART Data*/
    .UART_DATA :
    {
        . = ALIGN(64);
        lnk_uart_data_start_addr = .;
        
        * ( uart_data )
        
        . = ALIGN(64);
        lnk_uart_data_end_addr = .;
    } > EL2_SRAM

    /* Untagged RO Region */
    .RO :
    {
        . = ALIGN(64);
        *( .text* )
        *( .rodata* )
    } > EL2_SRAM

    /* Untagged RW Region */
    .RW :
    {
        . = ALIGN(64);
        *( .data* )
    } > EL2_SRAM

    /* ZI/BSS Region */
    .bss :
    {
        . = ALIGN(64);
        *( .bss* )
        *( COMMON )
    } > EL2_SRAM

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
    } > EL2_SRAM

    /* RESERVED 0x080AD000, size: 0x3000 */

    /* EL2 Stack */
    /* IMPORTANT NOTE: EL2 stack size 0xC000 i.e 48KB needed to support RSA 2K and 4K crypto */
    .ARM_LIB_STACK (NOLOAD):
    {
        lnk_stack_bottom = .;
        . = . + LENGTH(EL2_STACK);
        lnk_stack_top = .;

        lnk_stack_length = lnk_stack_top - lnk_stack_bottom;
    } > EL2_STACK

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