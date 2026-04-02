LR_1 0x0801E000  0x1E2000   ; Define the load region name as LR_1
                            ; the region starts at 0x08000000.
                            ; the first 100kb is allocated to PBL image.
{
    ER_RO1 +0     ; First execution region is called ER_RO1, region starts at end of
                  ; previous region. Because there is no previous region, the
                  ; address is 0x000000.
    {
        vectors.o
    }
    syscall_table  +0 ;0x1000 0x1000       ;Execution region for the HVC calls.
    {   
        *(_sail_syscall)
    }
    ER_RO3 +0      ; Subsequent execution regions are called ER_ROn, region starts at end of
                  ; previous region. 
    {
        * (+RO)   ; All RO sections go into this region
    }
    ER_RW +0
    {
        * (+RW)   ; All RW sections go into this region, they are placed
                  ; consecutively.
    }
    ER_ZI +0
    {
        *(+ZI)
    }

}

; DTB  0x080C9000 -- 0x080CF000, Size 0x6000 (24KB)
; DTBO 0x080CF000 -- 0x080D1000, Size 0x2000 (8KB)
    
LR_2 0x81F0000 0x10000      ; Define the load region name as LR_3
{
    ; 32KB, Heap start = 0x080D1000, Heap end = 0x080D5000
    SAILHYP_HEAP 0x81F0000 EMPTY 0x4000  
    {
    }
    
    ; Stack defined at the bottom. We define headp right above this section.
    ; So both can grow towards each other
    ; 8KB each core, total 32KB, stack start =  0x080E1000 & Stack end = 0x080D5000
    ; IMPORTANT NOTE: EL2 stack size 0xC000 i.e 48KB needed to support RSA 2K and 4K crypto
    ARM_LIB_STACK 0x08200000 EMPTY -0xC000 
    {
    }
}

;LR_2 0x02000000     
;{
; Cortex-R52 optionally provides three Tightly-Coupled Memory (TCM) blocks (ATCM, BTCM and CTCM)
; Use these regions to place code and/or data in TCM:
;    ATCM 0x02000000 EMPTY 0x4000 
;    { 
;    }
;    BTCM 0x02004000 EMPTY 0x4000 
;    { 
;    }
;    CTCM 0x02008000 EMPTY 0x4000 
;    { 
;    }
; Scatterloading can be used to copy code and/or data into the TCMs
;}
