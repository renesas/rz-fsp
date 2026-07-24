/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

    .extern R_BSP_GICR_Enable
    .extern R_BSP_GICD_AffinityRouteEnable
    .extern R_BSP_GICD_SetSpiSecurityAll
    .extern R_BSP_GICR_SetSgiPpiSecurityLine

    .equ DAIF_BIT_D,               (1 << 3)
    .equ DAIF_BIT_A,               (1 << 2)
    .equ DAIF_BIT_I,               (1 << 1)
    .equ DAIF_BIT_F,               (1 << 0)
    .equ DAIF_BIT_ALL_EXCEPTION,   (DAIF_BIT_D | DAIF_BIT_A | DAIF_BIT_I | DAIF_BIT_F)

    .equ ICC_SRE_EL3_BIT_Enable,   (1 << 3)
    .equ ICC_SRE_EL3_BIT_DIB,      (1 << 2)
    .equ ICC_SRE_EL3_BIT_DFB,      (1 << 1)
    .equ ICC_SRE_EL3_BIT_SRE,      (1 << 0)

    .equ ICC_SRE_EL1_BIT_SRE,      (1 << 0)

    .equ GICD_CTLR_BIT_ARE_NS,     (1 << 5)
    .equ GICD_CTLR_BIT_ARE_S,      (1 << 4)

    .equ ICC_IGRPEN1_EL3_BIT_EnableGrp1S,  (1 << 1)
    .equ ICC_IGRPEN1_EL3_BIT_EnableGrp1NS, (1 << 0)

//******************************************************************************
//* Function Name : __disable_irq
//* Description   : Disable IRQ
//******************************************************************************
    .section .text.__disable_irq
    .global __disable_irq
    .type   __disable_irq,%function
    .func   __disable_irq
__disable_irq:
    MSR     DAIFSET, DAIF_BIT_I
    RET

    .endfunc

//******************************************************************************
//* Function Name : __enable_irq
//* Description   : Enable IRQ
//******************************************************************************
    .section .text.__enable_irq
    .global __enable_irq
    .type   __enable_irq,%function
    .func   __enable_irq

__enable_irq:
    MSR     DAIFCLR, DAIF_BIT_I
    RET

    .endfunc

//******************************************************************************
//* Function Name : __disable_fiq
//* Description   : Disable FIQ
//******************************************************************************
    .section .text.__disable_fiq
    .global __disable_fiq
    .type   __disable_fiq,%function
    .func   __disable_fiq

__disable_fiq:
    MSR     DAIFSET, DAIF_BIT_F
    RET

    .endfunc

//******************************************************************************
//* Function Name : __enable_fiq
//* Description   : Enable FIQ
//******************************************************************************
    .section .text.__enable_fiq
    .global __enable_fiq
    .type   __enable_fiq,%function
    .func   __enable_fiq

__enable_fiq:
    MSR     DAIFCLR, DAIF_BIT_F
    RET


    .endfunc

//******************************************************************************
//* Function Name : __disable_all_exception
//* Description   : Disable all exception
//*                 Watchpoint, Breakpoint, and Software Step exceptions, SError
//*                 IRQ, FIQ
//******************************************************************************
    .section .text.__disable_all_exception
    .global __disable_all_exception
    .type   __disable_all_exception,%function
    .func   __disable_all_exception

__disable_all_exception:
    MSR     DAIFSET, DAIF_BIT_ALL_EXCEPTION
    RET

    .endfunc

//******************************************************************************
//* Function Name : __enable_all_exception
//* Description   : Enable all exception
//*                 Watchpoint, Breakpoint, and Software Step exceptions, SError
//*                 IRQ, FIQ
//******************************************************************************
    .section .text.__enable_all_exception
    .global __enable_all_exception
    .type   __enable_all_exception,%function
    .func   __enable_all_exception

__enable_all_exception:
    MSR     DAIFCLR, DAIF_BIT_ALL_EXCEPTION
    RET

    .endfunc

//******************************************************************************
//* Function Name : InitGicv3
//* Description   : Disable IRQ bypass and FIQ bypass
//*                 Enable system register
//*                 Set priority field to gggg.sss
//*                 Set secure access for EL1
//*                 SError, FIQ, IRQ route to EL3
//******************************************************************************
    .section .text.InitGicv3
    .global InitGicv3
    .type   InitGicv3,%function
    .func   InitGicv3
InitGicv3:

    STR  x30, [SP, #-0x08]!

    MOV  x0, #0
    ORR  x0, x0, ICC_SRE_EL3_BIT_Enable // Accessing of ICC_SRE_EL1, ICC_SRE_EL2 by EL1, EL2 isn't trap to EL3
    ORR  x0, x0, ICC_SRE_EL3_BIT_DIB    // Disable IRQ bypass
    ORR  x0, x0, ICC_SRE_EL3_BIT_DFB    // Disable FIQ bypass.
    ORR  x0, x0, ICC_SRE_EL3_BIT_SRE    // ICH_xxx, ICC_xxx register access is enabled for EL3
    MSR  S3_6_C12_C12_5, x0             // ICC_SRE_EL3
    ISB

    MOV  x0, #0
    ORR  x0, x0, ICC_SRE_EL1_BIT_SRE    // ICH_xxx, ICC_xxx register access is enabled for EL1
    MSR  S3_0_C12_C12_5, x0 // ICC_SRE_EL1

    //
    // Separate interrupt priority value fields in Group0, Group1
    //
    MOV  x0, #3             // Group priority [7: 4], Sub priority [3: 0]
    MSR  S3_0_C12_C8_3, x0  // ICC_BPR0_EL1
    MSR  S3_0_C12_C12_3, x0 // ICC_BPR1_EL1

    MOV  x0, (GICD_CTLR_BIT_ARE_NS | GICD_CTLR_BIT_ARE_S) // set None-secure and secure Affinity Routing Enable
    BL   R_BSP_GICD_AffinityRouteEnable

    BL   R_BSP_GICR_Enable

    MOV  w0, #1   // set Group1 None-Secure to argument for SPI, PPI
    BL   R_BSP_GICR_SetSgiPpiSecurityLine

    //
    // set interrupt priority mask, priority from 0 to 255 is valid
    //
    MOV  x0, #0xFF
    MSR  S3_0_C4_C6_0, x0 //ICC_PMR_EL1

    MOV  w0, #1  // set Group1 None-Secure to argument for SPI
    BL   R_BSP_GICD_SetSpiSecurityAll

    //
    // Group1 None-secure and Secure are enabled
    //
    MOV  x0, (ICC_IGRPEN1_EL3_BIT_EnableGrp1S | ICC_IGRPEN1_EL3_BIT_EnableGrp1NS)
    MSR  S3_6_C12_C12_7, x0 //ICC_IGRPEN1_EL3

    LDR  x30, [SP], #0x08

    RET

    .endfunc

    .END
