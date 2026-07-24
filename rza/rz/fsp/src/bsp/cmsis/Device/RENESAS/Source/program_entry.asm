/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

///*******************************************************************************
//* File Name   : program_entry.asm
//* Description : Jump to Reset_Handler
//*******************************************************************************/

//==================================================================
// Entry point for the Reset handler
//==================================================================

    .section PROGRAM_ENTRY, "ax"
    .align 11

    .global Start
    .extern reset_handler

Start:

program_entry:
     B reset_handler

    .END
