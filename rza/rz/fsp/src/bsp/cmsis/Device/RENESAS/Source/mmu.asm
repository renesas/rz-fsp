/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

    .text
    .cfi_sections .debug_frame  // put stack frame info into .debug_frame instead of .eh_frame

    .global R_MMU_GetTranslationTableBaseAddress
    .global R_MMU_SetTranslationTableBaseAddress

//*******************************************************************************
// Read TTBR_EL3 register
//*******************************************************************************
    .type R_MMU_GetTranslationTableBaseAddress, "function"
    .cfi_startproc
R_MMU_GetTranslationTableBaseAddress:

    MRS x0, TTBR0_EL3

    RET
    .cfi_endproc

//*******************************************************************************
// Write TTBR_EL3 register
//*******************************************************************************
    .type R_MMU_SetTranslationTableBaseAddress, "function"
    .cfi_startproc
R_MMU_SetTranslationTableBaseAddress:

    MSR TTBR0_EL3, x1

    RET
    .cfi_endproc