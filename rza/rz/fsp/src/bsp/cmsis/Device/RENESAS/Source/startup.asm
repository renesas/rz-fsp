/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

//==================================================================
// Entry point for the Reset handler
//==================================================================
    .section RESET_HANDLER, "ax"
    .balign  8
    .cfi_sections .debug_frame

    .extern  __stack_end     // Linker symbol from scatter file

    .weak    DTBL_F
    .weak    BTBL_F
    .weak    DTBL
    .weak    BTBL

    .extern  vector_table
    .extern  R_MMU_Init
    .extern  INITSCT

    .extern R_BSP_CACHE_InvalidateL1Data

    .global reset_handler

    .equ    counter_freq,  24000000

    .equ  SCR_EL3_BIT_ST,   (1 << 11)
    .equ  SCR_EL3_BIT_RW,   (1 << 10)
    .equ  SCR_EL3_BIT_EA,   (1 << 3)
    .equ  SCR_EL3_BIT_FIQ,  (1 << 2)
    .equ  SCR_EL3_BIT_IRQ,  (1 << 1)

    .equ  HCR_EL2_BIT_RW,   (1 << 31)

    .equ  SCTLR_EL3_BIT_M,  (1 << 0)

//******************************************************************************
// Function Name : reset_handler
// Description   : This function is the assembler function executed after reset
//               : cancellation. After initial setting for the stack pointer or
//               : the MMU and reset cancellation, executes initial setting for
//               : the minimum required peripheral functions. Calls the main
//               : function to execute.
//******************************************************************************
reset_handler:

//===================================================================
// Set Vector Base Address Register (VBAR) to point to initializer routine
//===================================================================
    LDR  x0, =vector_table
    MSR  VBAR_EL3, x0
    MSR  VBAR_EL2, x0
    MSR  VBAR_EL1, x0

//==================================================================
// Top of level system control init at each EL level
// Stop the following systems
// MMU, cache, and some memory control system, Tag check fault, pointer authentication
//==================================================================
    MOV  x0, #0
    MSR  SCTLR_EL3, x0
    MSR  SCTLR_EL2, x0
    MSR  SCTLR_EL1, x0

//==================================================================
// Setting up Stack Area (EL3)
//==================================================================
    LDR  x1, =__stack_end
    MOV  sp, x1

//==================================================================
// Stop trapping to EL3 or EL2 for low EL level tracing,
// activity monitoring, SVE, and access to SIMD and floating point features
//==================================================================
    MOV  x0, #0
    MSR  CPTR_EL3, x0
    MSR  CPTR_EL2, x0

//==================================================================
// Secure configuration
//==================================================================

    MSR  SCR_EL3, xzr       //;; Set 0 to SCR_EL3
    ISB

    MOV  w1, #0
    ORR  w1, w1, SCR_EL3_BIT_ST   //;; Set EL3 not to trap access to low EL secure counter registers
    ORR  w1, w1, SCR_EL3_BIT_RW   //;; Set EL2 to AArch64 mode, Allow EL1 and EL0 control settings in EL2
    ORR  w1, w1, SCR_EL3_BIT_EA   //;; Trap External aborts and SError exceptions at all EL levels with EL3
    ORR  w1, w1, SCR_EL3_BIT_FIQ  //;; Trap FIQ at all EL levels with EL3
    ORR  w1, w1, SCR_EL3_BIT_IRQ  //;; Trap IRQ at all EL levels with EL3
    MSR  SCR_EL3, x1

    ISB

//==================================================================
// Set EL1 to execute with Aarch64
//==================================================================
    MOV  x2, HCR_EL2_BIT_RW     //;; EL1 execute with AArch64
    MSR  HCR_EL2, x2

//==================================================================
// Copy the multiprocessor ID information to the virtual multiprocessor ID register
//==================================================================
    MRS  x0, MPIDR_EL1
    MSR  VMPIDR_EL2, x0

//==================================================================
// Copy processing element information to the virtual processor ID register
//==================================================================
    MRS  x0, MIDR_EL1
    MSR  VPIDR_EL2, x0

//==================================================================
// Set 0 to Virtual Translation Table Address
//==================================================================
    MSR  VTTBR_EL2, xzr

//==================================================================
// set system counter frequency
//==================================================================
    LDR  x0, =counter_freq
    MSR  CNTFRQ_EL0, x0

//==================================================================
// TLB maintenance, Invalidate Data and Instruction TLBs
//==================================================================
    TLBI ALLE3      //;; Cortex-A55 I-TLB and D-TLB invalidation (TLBIALL)

//===================================================================
// Invalidate instruction cache, also flushes BTAC
//===================================================================
    IC IALLUIS      //;; ICIALLUIS - Instruction Cache Invalidate All to PoU

//==================================================================
// Cache Invalidation code for Cortex-A55
//==================================================================
    BL  R_BSP_CACHE_InvalidateAll

//==================================================================
// Section initialize for R_SC_HardwareSetup
//==================================================================
    LDR  x0, =DTBL_F                //;; ROM to RAM table for R_SC_HardwareSetup
    LDR  x1, =BTBL_F                //;; RAM zero fill table for R_SC_HardwareSetup
    BL   INITSCT                    //;; Call

    IC IALLUIS      //;; ICIALLUIS - Instruction Cache Invalidate All to PoU

//==================================================================
// Initialize hardware hook
//==================================================================
    BL   R_BSP_HardwareInit         //;; Initialize hook

    MOV  x0, #0                     //;; BSP_WARM_START_RESET
    BL   R_BSP_WarmStart            //;; Initialize hook

//===================================================================
// Enable MMU
// Leaving the caches disabled until (main).
//===================================================================
    MRS  x0, SCTLR_EL3              //;; Read System Control Register (EL3)
    ORR  x0, x0, SCTLR_EL3_BIT_M      //;; Set M bit 1 to enable MMU before section initialization processing
    MSR  SCTLR_EL3, x0              //;; Write value back to System Control Register (EL3)
    ISB

//===================================================================
// copy and clear the sections
//===================================================================
    LDR  x0, =DTBL                  //;; ROM to RAM table
    LDR  x1, =BTBL                  //;; RAM zero fill table
    BL   INITSCT                    //;; Call to copy and to clear the sections

    IC IALLUIS      //;; ICIALLUIS - Instruction Cache Invalidate All to PoU

// =========================================================================
// Branch to C library entry point
// =========================================================================
    BL   SystemInit                 //;; Branch to SytemInit */

    BL   main                       //;; Branch to C library entry point */

    B    .


Literals2:
    .LTORG

r_rza3_startup_verison :
    .align 2
    .ascii "1.00"

    .END
