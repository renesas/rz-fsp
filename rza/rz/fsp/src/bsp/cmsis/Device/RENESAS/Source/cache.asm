/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

    .text
    .cfi_sections .debug_frame  // put stack frame info into .debug_frame instead of .eh_frame

    .global R_BSP_CACHE_EnableInst
    .global R_BSP_CACHE_EnableData
    .global R_BSP_CACHE_DisableInst
    .global R_BSP_CACHE_DisableData
    .global R_BSP_CACHE_CleanAll
    .global R_BSP_CACHE_CleanInvalidateAll
    .global R_BSP_CACHE_InvalidateAll
    .global R_BSP_CACHE_CleanRange
    .global R_BSP_CACHE_InvalidateRange
    .global R_BSP_CACHE_CleanInvalidateRange

    .equ    SCTLR_ELX_BIT_I,        0x1000
    .equ    SCTLR_ELX_BIT_C,        0x04
    .equ    CLUSTERPWRCTLR_PREQ,    0xF0

//*******************************************************************************
// Enable instruction cache
//*******************************************************************************
    .type R_BSP_CACHE_EnableInst, "function"
    .cfi_startproc
R_BSP_CACHE_EnableInst:

    MRS x0, SCTLR_EL3
    ORR x0, x0, #SCTLR_ELX_BIT_I
    MSR SCTLR_EL3, x0

    ISB
    RET
    .cfi_endproc

//*******************************************************************************
// Enable data cache
//*******************************************************************************
    .type R_BSP_CACHE_EnableData, "function"
    .cfi_startproc
R_BSP_CACHE_EnableData:

    MRS x0, SCTLR_EL3
    ORR x0, x0, #SCTLR_ELX_BIT_C
    MSR SCTLR_EL3, x0

    ISB
    RET
    .cfi_endproc

//*******************************************************************************
// Disable instruction cache
//*******************************************************************************
    .type R_BSP_CACHE_DisableInst, "function"
    .cfi_startproc
R_BSP_CACHE_DisableInst:

    MRS x0, SCTLR_EL3
    BIC x0, x0, #SCTLR_ELX_BIT_I
    MSR SCTLR_EL3, x0

    ISB
    RET
    .cfi_endproc

//*******************************************************************************
// Disable data cache
//*******************************************************************************
    .type R_BSP_CACHE_DisableData, "function"
    .cfi_startproc
R_BSP_CACHE_DisableData:

    MRS x0, SCTLR_EL3
    BIC x0, x0, #SCTLR_ELX_BIT_C
    MSR SCTLR_EL3, x0

    ISB
    RET
    .cfi_endproc

// ------------------------------------------------------------

//*******************************************************************************
// Clean data and unified caches
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_CleanAll, "function"
    .cfi_startproc
R_BSP_CACHE_CleanAll:

    DMB  ISH                   // ensure all prior inner-shareable accesses have been observed

    MRS  x0, CLIDR_EL1
    AND  w3, w0, #0x07000000   // get 2 x level of coherence
    LSR  w3, w3, #23
    CBZ  w3, Cfinished
    MOV  w10, #0               // w10 = 2 x cache level
    MOV  w8, #1                // w8 = constant 0b1
Cloop1:                        // cache level
    ADD  w2, w10, w10, LSR #1  // calculate 3 x cache level
    LSR  w1, w0, w2            // extract 3-bit cache type for this level
    AND  w1, w1, #0x7
    CMP  w1, #2
    B.LT Cskip                 // no data or unified cache at this level
    MSR  CSSELR_EL1, x10       // select this cache level
    ISB                        // synchronize change of csselr
    MRS  x1, CCSIDR_EL1        // read ccsidr
    AND  w2, w1, #7            // w2 = log2(linelen)-4
    ADD  w2, w2, #4            // w2 = log2(linelen)
    UBFX w4, w1, #3, #10       // w4 = max way number, right aligned
    CLZ  w5, w4                // w5 = 32-log2(ways), bit position of way in dc operand
    LSL  w9, w4, w5            // w9 = max way number, aligned to position in dc operand
    LSL  w16, w8, w5           // w16 = amount to decrement way number per iteration
Cloop2:                        // cache way
    UBFX w7, w1, #13, #15      // w7 = max set number, right aligned
    LSL  w7, w7, w2            // w7 = max set number, aligned to position in dc operand
    LSL  w17, w8, w2           // w17 = amount to decrement set number per iteration
Cloop3:                        // cache set
    ORR  w11, w10, w9          // w11 = combine way number and cache number ...
    ORR  w11, w11, w7          // ... and set number for dc operand
    DC   csw, x11              // do data cache clean by set and way
    SUBS w7, w7, w17           // decrement set number
    B.GE Cloop3
    SUBS x9, x9, x16           // decrement way number
    B.GE Cloop2
Cskip:
    ADD  w10, w10, #2          // increment 2 x cache level
    CMP  w3, w10
    B.GT Cloop1
    DSB  SY                    // ensure completion of previous cache maintenance operation
    ISB
Cfinished:
    RET
    .cfi_endproc

//*******************************************************************************
// Clean&Invalidate data and unified caches
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_CleanInvalidateAll, "function"
    .cfi_startproc
R_BSP_CACHE_CleanInvalidateAll:

    DMB  ISH                   // ensure all prior inner-shareable accesses have been observed

    MRS  x0, CLIDR_EL1
    AND  w3, w0, #0x07000000   // get 2 x level of coherence
    LSR  w3, w3, #23
    CBZ  w3, CIfinished
    MOV  w10, #0               // w10 = 2 x cache level
    MOV  w8, #1                // w8 = constant 0b1
CIloop1:                       // cache level
    ADD  w2, w10, w10, LSR #1  // calculate 3 x cache level
    LSR  w1, w0, w2            // extract 3-bit cache type for this level
    AND  w1, w1, #0x7
    CMP  w1, #2
    B.LT CIskip                // no data or unified cache at this level
    MSR  CSSELR_EL1, x10       // select this cache level
    ISB                        // synchronize change of csselr
    MRS  x1, CCSIDR_EL1        // read ccsidr
    AND  w2, w1, #7            // w2 = log2(linelen)-4
    ADD  w2, w2, #4            // w2 = log2(linelen)
    UBFX w4, w1, #3, #10       // w4 = max way number, right aligned
    CLZ  w5, w4                // w5 = 32-log2(ways), bit position of way in dc operand
    LSL  w9, w4, w5            // w9 = max way number, aligned to position in dc operand
    LSL  w16, w8, w5           // w16 = amount to decrement way number per iteration
CIloop2:                       // cache way
    UBFX w7, w1, #13, #15      // w7 = max set number, right aligned
    LSL  w7, w7, w2            // w7 = max set number, aligned to position in dc operand
    LSL  w17, w8, w2           // w17 = amount to decrement set number per iteration
CIloop3:                       // cache set
    ORR  w11, w10, w9          // w11 = combine way number and cache number ...
    ORR  w11, w11, w7          // ... and set number for dc operand
    DC   cisw, x11             // do data cache clean&invalidate by set and way
    SUBS w7, w7, w17           // decrement set number
    B.GE CIloop3
    SUBS x9, x9, x16           // decrement way number
    B.GE CIloop2
CIskip:
    ADD  w10, w10, #2          // increment 2 x cache level
    CMP  w3, w10
    B.GT CIloop1
    DSB  SY                    // ensure completion of previous cache maintenance operation
    ISB
CIfinished:
    RET
    .cfi_endproc

//*******************************************************************************
// Invalidate data and unified caches
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_InvalidateAll, "function"
    .cfi_startproc
R_BSP_CACHE_InvalidateAll:

    DMB  ISH                   // ensure all prior inner-shareable accesses have been observed

    MRS  x0, CLIDR_EL1
    AND  w3, w0, #0x07000000   // get 2 x level of coherence
    LSR  w3, w3, #23
    CBZ  w3, Ifinished
    MOV  w10, #0               // w10 = 2 x cache level
    MOV  w8, #1                // w8 = constant 0b1
Iloop1:                        // cache level
    ADD  w2, w10, w10, LSR #1  // calculate 3 x cache level
    LSR  w1, w0, w2            // extract 3-bit cache type for this level
    AND  w1, w1, #0x7
    CMP  w1, #2
    B.LT Iskip                 // no data or unified cache at this level
    MSR  CSSELR_EL1, x10       // select this cache level
    ISB                        // synchronize change of csselr
    MRS  x1, CCSIDR_EL1        // read ccsidr
    AND  w2, w1, #7            // w2 = log2(linelen)-4
    ADD  w2, w2, #4            // w2 = log2(linelen)
    UBFX w4, w1, #3, #10       // w4 = max way number, right aligned
    CLZ  w5, w4                // w5 = 32-log2(ways), bit position of way in dc operand
    LSL  w9, w4, w5            // w9 = max way number, aligned to position in dc operand
    LSL  w16, w8, w5           // w16 = amount to decrement way number per iteration
Iloop2:                        // cache way
    UBFX w7, w1, #13, #15      // w7 = max set number, right aligned
    LSL  w7, w7, w2            // w7 = max set number, aligned to position in dc operand
    LSL  w17, w8, w2           // w17 = amount to decrement set number per iteration
Iloop3:                        // cache set
    ORR  w11, w10, w9          // w11 = combine way number and cache number ...
    ORR  w11, w11, w7          // ... and set number for dc operand
    DC   isw, x11              // do data cache invalidate by set and way
    SUBS w7, w7, w17           // decrement set number
    B.GE Iloop3
    SUBS x9, x9, x16           // decrement way number
    B.GE Iloop2
Iskip:
    ADD  w10, w10, #2          // increment 2 x cache level
    CMP  w3, w10
    B.GT Iloop1
    DSB  SY                    // ensure completion of previous cache maintenance operation
    ISB
Ifinished:
    RET
    .cfi_endproc

//*******************************************************************************
// Cache Clean by MVA functions
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_CleanRange, "function"
    .cfi_startproc
R_BSP_CACHE_CleanRange:
    //
    // X0 = base address
    // X1 = length (we assume the length is not 0)
    //
    // Calculate end of the region
    ADD x1, x1, x0                  // Base Address + Length
    //
    // Clean the data cache by MVA
    //
    MRS X2, CTR_EL0                 // Read Cache Type Register
    // Get the minimun data cache line
    //
    UBFX X4, X2, #16, #4            // Extract DminLine (log2 of the cache line)
    MOV X3, #4                      // Dminline iss the number of words (4 bytes)
    LSL X3, X3, X4                  // X3 should contain the cache line
    SUB X4, X3, #1                  // get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
clean_data_cache:
    DC CVAC, X4                     // Clean data cache line by VA to PoC
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT clean_data_cache           // while (address < end_address)
    DSB ISH                         // Ensure visibility of the data cleaned from cache
    //
    //Clean the instruction cache by VA
    //
    // Get the minimum instruction cache line (X2 contains ctr_el0)
    AND X2, X2, #0xF                // Extract IminLine (log2 of the cache line)
    MOV X3, #4                      // IminLine is the number of words (4 bytes)
    LSL X3, X3, X2                  // X3 should contain the cache line
    SUB x4, x3, #1                  // Get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
clean_instruction_cache:
    IC IVAU, X4                     // Clean instruction cache line by VA to PoU
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT clean_instruction_cache    // while (address < end_address)
    DSB ISH                         // Ensure completion of the invalidations
    ISB                             // Synchronize the fetched instruction stream

    RET
    .cfi_endproc

//*******************************************************************************
// Cache Invalidate by MVA functions
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_InvalidateRange, "function"
    .cfi_startproc
R_BSP_CACHE_InvalidateRange:
    //
    // X0 = base address
    // X1 = length (we assume the length is not 0)
    //
    // Calculate end of the region
    ADD x1, x1, x0                  // Base Address + Length
    //
    // Invalidate the data cache by MVA
    //
    MRS X2, CTR_EL0                 // Read Cache Type Register
    // Get the minimun data cache line
    //
    UBFX X4, X2, #16, #4            // Extract DminLine (log2 of the cache line)
    MOV X3, #4                      // Dminline iss the number of words (4 bytes)
    LSL X3, X3, X4                  // X3 should contain the cache line
    SUB X4, X3, #1                  // get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
invalidate_data_cache:
    DC IVAC, X4                     // Invalidate data cache line by VA to PoC
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT invalidate_data_cache      // while (address < end_address)
    DSB ISH                         // Ensure visibility of the data cleaned from cache
    //
    //Clean the instruction cache by VA
    //
    // Get the minimum instruction cache line (X2 contains ctr_el0)
    AND X2, X2, #0xF                // Extract IminLine (log2 of the cache line)
    MOV X3, #4                      // IminLine is the number of words (4 bytes)
    LSL X3, X3, X2                  // X3 should contain the cache line
    SUB x4, x3, #1                  // Get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
invalidate_instruction_cache:
    IC IVAU, X4                     // Invalidate instruction cache line by VA to PoU
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT invalidate_instruction_cache    // while (address < end_address)
    DSB ISH                         // Ensure completion of the invalidations
    ISB                             // Synchronize the fetched instruction stream

    RET
    .cfi_endproc


//*******************************************************************************
// Cache Clean&Invalidate by MVA functions
// Refer to Programmer’s Guide for ARMv8-A
//*******************************************************************************
    .type R_BSP_CACHE_CleanInvalidateRange, "function"
    .cfi_startproc
R_BSP_CACHE_CleanInvalidateRange:
    //
    // X0 = base address
    // X1 = length (we assume the length is not 0)
    //
    // Calculate end of the region
    ADD x1, x1, x0                  // Base Address + Length
    //
    // Invalidate the data cache by MVA
    //
    MRS X2, CTR_EL0                 // Read Cache Type Register
    // Get the minimun data cache line
    //
    UBFX X4, X2, #16, #4            // Extract DminLine (log2 of the cache line)
    MOV X3, #4                      // Dminline iss the number of words (4 bytes)
    LSL X3, X3, X4                  // X3 should contain the cache line
    SUB X4, X3, #1                  // get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
cleaninvalidate_data_cache:
    DC CIVAC, X4                    // Clean&Invalidate data cache line by VA to PoC
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT cleaninvalidate_data_cache // while (address < end_address)
    DSB ISH                         // Ensure visibility of the data cleaned from cache
    //
    //Clean the instruction cache by VA
    //
    // Get the minimum instruction cache line (X2 contains ctr_el0)
    AND X2, X2, #0xF                // Extract IminLine (log2 of the cache line)
    MOV X3, #4                      // IminLine is the number of words (4 bytes)
    LSL X3, X3, X2                  // X3 should contain the cache line
    SUB x4, x3, #1                  // Get the mask for the cache line
    BIC X4, X0, X4                  // Aligned the base address of the region
cleaninvalidate_instruction_cache:
    IC IVAU, X4                     // Invalidate instruction cache line by VA to PoU
    ADD X4, X4, X3                  // Next cache line
    CMP X4, X1                      // Is X4 (current cache line) smaller than the end
                                    // of the region
    B.LT cleaninvalidate_instruction_cache    // while (address < end_address)
    DSB ISH                         // Ensure completion of the invalidations
    ISB                             // Synchronize the fetched instruction stream

    RET
    .cfi_endproc


//*******************************************************************************
// Control power of Level 3 cache.
//*******************************************************************************
    .type R_BSP_CACHE_L3_PowerCtrl, "function"
    .cfi_startproc
R_BSP_CACHE_L3_PowerCtrl:
    // X0 = power (0:OFF, other:ON)

    MRS x1, S3_0_C15_C3_5   // Read CLUSTERPWRCTLR_EL1 into X1

    CMP x0, #0

    B.EQ l3_powerctrl_off

    ORR x1, x1, #CLUSTERPWRCTLR_PREQ

    B l3_powerctrl_end

l3_powerctrl_off:
    BIC x1, x1, #CLUSTERPWRCTLR_PREQ

l3_powerctrl_end:
    MSR S3_0_C15_C3_5, x1   // Write X1 into CLUSTERPWRCTLR_EL1
    ISB

    RET
    .cfi_endproc
