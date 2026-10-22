/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ICU_ERROR_H
 #define R_ICU_ERROR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
 #include "bsp_api.h"
 #include "r_error_api.h"
 #include "r_icu_error_cfg.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/**********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
 #define PERIPHERAL_ERROR_TABLE_MAX_ENTRIES    (96)
 #define DSMIF_ERROR_TABLE_MAX_ENTRIES         (384)
 #define ENCIF_ERROR_TABLE_MAX_ENTRIES         (160)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
typedef void (* error_table_t)(uint32_t id);

/** ICU_ERROR CPU0 Error Code */
typedef enum e_icu_error_cpu0_error
{
    ICU_ERROR_CPU0_ERROR_EVENT0  = (1UL << 0),
    ICU_ERROR_CPU0_ERROR_EVENT1  = (1UL << 1),
    ICU_ERROR_CPU0_ERROR_EVENT2  = (1UL << 2),
    ICU_ERROR_CPU0_ERROR_EVENT3  = (1UL << 3),
    ICU_ERROR_CPU0_ERROR_EVENT4  = (1UL << 4),
    ICU_ERROR_CPU0_ERROR_EVENT5  = (1UL << 5),
    ICU_ERROR_CPU0_ERROR_EVENT6  = (1UL << 6),
    ICU_ERROR_CPU0_ERROR_EVENT7  = (1UL << 7),
    ICU_ERROR_CPU0_ERROR_EVENT8  = (1UL << 8),
    ICU_ERROR_CPU0_ERROR_EVENT9  = (1UL << 9),
    ICU_ERROR_CPU0_ERROR_EVENT10 = (1UL << 10),
    ICU_ERROR_CPU0_ERROR_EVENT11 = (1UL << 11),
    ICU_ERROR_CPU0_ERROR_EVENT12 = (1UL << 12),
    ICU_ERROR_CPU0_ERROR_EVENT13 = (1UL << 13),
    ICU_ERROR_CPU0_ERROR_EVENT14 = (1UL << 14),
    ICU_ERROR_CPU0_ERROR_EVENT15 = (1UL << 15),
    ICU_ERROR_CPU0_ERROR_EVENT16 = (1UL << 16),
    ICU_ERROR_CPU0_ERROR_EVENT17 = (1UL << 17),
    ICU_ERROR_CPU0_ERROR_EVENT18 = (1UL << 18),
    ICU_ERROR_CPU0_ERROR_EVENT19 = (1UL << 19),
    ICU_ERROR_CPU0_ERROR_EVENT20 = (1UL << 20),
    ICU_ERROR_CPU0_ERROR_EVENT21 = (1UL << 21),
    ICU_ERROR_CPU0_ERROR_EVENT22 = (1UL << 22),
    ICU_ERROR_CPU0_ERROR_EVENT23 = (1UL << 23),
    ICU_ERROR_CPU0_ERROR_EVENT24 = (1UL << 24),
    ICU_ERROR_CPU0_ERROR_EVENT25 = (1UL << 25)
} icu_error_cpu0_error_t;

 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED

/** ICU_ERROR CPU1 Error Code */
typedef enum e_icu_error_cpu1_error
{
    ICU_ERROR_CPU1_ERROR_EVENT0  = (1UL << 0),
    ICU_ERROR_CPU1_ERROR_EVENT1  = (1UL << 1),
    ICU_ERROR_CPU1_ERROR_EVENT2  = (1UL << 2),
    ICU_ERROR_CPU1_ERROR_EVENT3  = (1UL << 3),
    ICU_ERROR_CPU1_ERROR_EVENT4  = (1UL << 4),
    ICU_ERROR_CPU1_ERROR_EVENT5  = (1UL << 5),
    ICU_ERROR_CPU1_ERROR_EVENT6  = (1UL << 6),
    ICU_ERROR_CPU1_ERROR_EVENT7  = (1UL << 7),
    ICU_ERROR_CPU1_ERROR_EVENT8  = (1UL << 8),
    ICU_ERROR_CPU1_ERROR_EVENT9  = (1UL << 9),
    ICU_ERROR_CPU1_ERROR_EVENT10 = (1UL << 10),
    ICU_ERROR_CPU1_ERROR_EVENT11 = (1UL << 11),
    ICU_ERROR_CPU1_ERROR_EVENT12 = (1UL << 12),
    ICU_ERROR_CPU1_ERROR_EVENT13 = (1UL << 13),
    ICU_ERROR_CPU1_ERROR_EVENT14 = (1UL << 14),
    ICU_ERROR_CPU1_ERROR_EVENT15 = (1UL << 15),
    ICU_ERROR_CPU1_ERROR_EVENT16 = (1UL << 16),
    ICU_ERROR_CPU1_ERROR_EVENT17 = (1UL << 17),
    ICU_ERROR_CPU1_ERROR_EVENT18 = (1UL << 18),
    ICU_ERROR_CPU1_ERROR_EVENT19 = (1UL << 19),
    ICU_ERROR_CPU1_ERROR_EVENT20 = (1UL << 20),
    ICU_ERROR_CPU1_ERROR_EVENT21 = (1UL << 21),
    ICU_ERROR_CPU1_ERROR_EVENT22 = (1UL << 22),
    ICU_ERROR_CPU1_ERROR_EVENT23 = (1UL << 23),
    ICU_ERROR_CPU1_ERROR_EVENT24 = (1UL << 24),
    ICU_ERROR_CPU1_ERROR_EVENT25 = (1UL << 25)
} icu_error_cpu1_error_t;
 #endif

 #if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
typedef enum e_icu_error_ca55_error
{
    ICU_ERROR_CR55_ERROR_0_NFAULTIRQ1        = (1UL << 0),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_1_NFAULTIRQ2        = (1UL << 1),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_2_NFAULTIRQ3        = (1UL << 2),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_3_NFAULTIRQ4        = (1UL << 3),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_4_NFAULTIRQ0        = (1UL << 4),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_5_NERRIRQ1          = (1UL << 5),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_6_NERRIRQ2          = (1UL << 6),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_7_NERRIRQ3          = (1UL << 7),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_8_NERRIRQ4          = (1UL << 8),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_9_NERRIRQ0          = (1UL << 9),  // DEPRECATED
    ICU_ERROR_CR55_ERROR_10_GIC600_FAULT_INT = (1UL << 10), // DEPRECATED
    ICU_ERROR_CR55_ERROR_11_GIC600_ERR_INT   = (1UL << 11), // DEPRECATED
    ICU_ERROR_CR55_ERROR_12_GIC600_PMU_INT   = (1UL << 12), // DEPRECATED
    ICU_ERROR_CA55_ERROR_0_NFAULTIRQ1        = (1UL << 0),
    ICU_ERROR_CA55_ERROR_1_NFAULTIRQ2        = (1UL << 1),
    ICU_ERROR_CA55_ERROR_2_NFAULTIRQ3        = (1UL << 2),
    ICU_ERROR_CA55_ERROR_3_NFAULTIRQ4        = (1UL << 3),
    ICU_ERROR_CA55_ERROR_4_NFAULTIRQ0        = (1UL << 4),
    ICU_ERROR_CA55_ERROR_5_NERRIRQ1          = (1UL << 5),
    ICU_ERROR_CA55_ERROR_6_NERRIRQ2          = (1UL << 6),
    ICU_ERROR_CA55_ERROR_7_NERRIRQ3          = (1UL << 7),
    ICU_ERROR_CA55_ERROR_8_NERRIRQ4          = (1UL << 8),
    ICU_ERROR_CA55_ERROR_9_NERRIRQ0          = (1UL << 9),
    ICU_ERROR_CA55_ERROR_10_GIC600_FAULT_INT = (1UL << 10),
    ICU_ERROR_CA55_ERROR_11_GIC600_ERR_INT   = (1UL << 11),
    ICU_ERROR_CA55_ERROR_12_GIC600_PMU_INT   = (1UL << 12),
} icu_error_ca55_error_t;
 #endif

 #if BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE == 1

/** ICU_ERROR Peripheral 0 Error Code */
typedef enum e_icu_error_peripheral_error_0
{
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA_INT      = (1UL << 0),  // Main OSC stop detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA0_INT     = (1UL << 1),  // CLMA0 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA1_INT     = (1UL << 2),  // CLMA1 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA2_INT     = (1UL << 3),  // CLMA2 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_BSC_WTO       = (1UL << 4),  // External wait timeout detection interrupt
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC0_ERR     = (1UL << 5),  // DMAC0 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC1_ERR     = (1UL << 6),  // DMAC1 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDF0  = (1UL << 7),  // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_USB_FDMAERR   = (1UL << 9),  // USB (Function) DMA error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTCSE  = (1UL << 10), // DSMIF0 lower threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTCSE  = (1UL << 11), // DSMIF0 upper threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE0 = (1UL << 12), // DSMIF0 lower threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE1 = (1UL << 13), // DSMIF0 lower threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_LTODE2 = (1UL << 14), // DSMIF0 lower threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE0 = (1UL << 15), // DSMIF0 upper threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE1 = (1UL << 16), // DSMIF0 upper threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_UTODE2 = (1UL << 17), // DSMIF0 upper threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE0  = (1UL << 18), // DSMIF0 Short-circuit detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE1  = (1UL << 19), // DSMIF0 Short-circuit detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF0_SCDE2  = (1UL << 20), // DSMIF0 Short-circuit detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTCSE  = (1UL << 21), // DSMIF1 lower threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTCSE  = (1UL << 22), // DSMIF1 upper threshold current sum error
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE0 = (1UL << 23), // DSMIF1 lower threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE1 = (1UL << 24), // DSMIF1 lower threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_LTODE2 = (1UL << 25), // DSMIF1 lower threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE0 = (1UL << 26), // DSMIF1 upper threshold overcurrent detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE1 = (1UL << 27), // DSMIF1 upper threshold overcurrent detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_UTODE2 = (1UL << 28), // DSMIF1 upper threshold overcurrent detection 2
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE0  = (1UL << 29), // DSMIF1 Short-circuit detection 0
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE1  = (1UL << 30), // DSMIF1 Short-circuit detection 1
    ICU_ERROR_PERIPHERAL_ERROR_0_DSMIF1_SCDE2  = (1UL << 31), // DSMIF1 Short-circuit detection 2
} icu_error_peripheral_error_0_t;

/** ICU_ERROR Peripheral 1 Error Code */
typedef enum e_icu_error_peripheral_error_1
{
    ICU_ERROR_PERIPHERAL_ERROR_1_DOC_DOPCI  = (1UL << 0),  // DOC interrupt
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_IE1  = (1UL << 1),  // System SRAM0 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_IE2  = (1UL << 2),  // System SRAM0 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM0_OVF  = (1UL << 3),  // System SRAM0 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_IE1  = (1UL << 4),  // System SRAM1 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_IE2  = (1UL << 5),  // System SRAM1 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM1_OVF  = (1UL << 6),  // System SRAM1 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_IE1  = (1UL << 7),  // System SRAM2 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_IE2  = (1UL << 8),  // System SRAM2 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_1_SRAM2_OVF  = (1UL << 9),  // System SRAM2 ECC error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_1_BUSERR     = (1UL << 13), // Bus error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SHOST  = (1UL << 15), // Master MPU for Serial Host I/F error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PHOST  = (1UL << 16), // Master MPU for Parallel Host I/F error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR0 = (1UL << 17), // Master MPU Read channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW0 = (1UL << 18), // Master MPU Write channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR1 = (1UL << 19), // Master MPU Read channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW1 = (1UL << 20), // Master MPU Write channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACR  = (1UL << 21), // Master MPU Read channel for GMAC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACW  = (1UL << 22), // Master MPU Write channel for GMAC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBH   = (1UL << 23), // Master MPU for USB Host error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBF   = (1UL << 24), // Master MPU for USB Function error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGR   = (1UL << 27), // Master MPU Read channel for Debug error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGW   = (1UL << 28), // Master MPU Write channel for Debug error
} icu_error_peripheral_error_1_t;
 #endif

 #if BSP_FEATURE_ICU_ERROR_PERIPHERAL_TYPE == 3

/** ICU_ERROR Peripheral 0 Error Code */
typedef enum e_icu_error_peripheral_error_0
{
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA0_INT     = (1UL << 0),  // CLMA0 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA1_INT     = (1UL << 1),  // CLMA1 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA2_INT     = (1UL << 2),  // CLMA2 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA3_INT     = (1UL << 3),  // CLMA3 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA4_INT     = (1UL << 4),  // CLMA4 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA5_INT     = (1UL << 5),  // CLMA5 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_CLMA6_INT     = (1UL << 6),  // CLMA6 error detection
    ICU_ERROR_PERIPHERAL_ERROR_0_BSC_WTO       = (1UL << 7),  // External wait timeout detection interrupt
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC0_ERR     = (1UL << 8),  // DMAC0 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC1_ERR     = (1UL << 9),  // DMAC1 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_DMAC2_ERR     = (1UL << 10), // DMAC1 transfer error
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFR0 = (1UL << 11), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFR1 = (1UL << 12), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFA0 = (1UL << 13), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFA1 = (1UL << 14), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFA2 = (1UL << 15), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_WDT_NMIUNDFA3 = (1UL << 16), // Down-counter underflow/refresh error for CPU0
    ICU_ERROR_PERIPHERAL_ERROR_0_USB_FDMAERR   = (1UL << 17), // USB (Function) DMA error
    ICU_ERROR_PERIPHERAL_ERROR_0_DOC_DOPCI     = (1UL << 18), // DOC interrupt
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM0_IE1     = (1UL << 19), // System SRAM0 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM0_IE2     = (1UL << 20), // System SRAM0 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM0_OVF     = (1UL << 21), // System SRAM0 error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM1_IE1     = (1UL << 22), // System SRAM1 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM1_IE2     = (1UL << 23), // System SRAM1 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM1_OVF     = (1UL << 24), // System SRAM1 error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM2_IE1     = (1UL << 25), // System SRAM2 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM2_IE2     = (1UL << 26), // System SRAM2 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM2_OVF     = (1UL << 27), // System SRAM2 error address capture overflow
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM3_IE1     = (1UL << 28), // System SRAM3 ECC 1 bit error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM3_IE2     = (1UL << 29), // System SRAM3 ECC 2 bits error
    ICU_ERROR_PERIPHERAL_ERROR_0_SRAM3_OVF     = (1UL << 30), // System SRAM3 error address capture overflow
} icu_error_peripheral_error_0_t;

typedef enum e_icu_error_peripheral_error_1
{
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR0  = (1UL << 0),  // Master MPU Read channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW0  = (1UL << 1),  // Master MPU Write channel for DMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR1  = (1UL << 2),  // Master MPU Read channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW1  = (1UL << 3),  // Master MPU Write channel for DMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACR2  = (1UL << 4),  // Master MPU Read channel for DMAC2 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DMACW2  = (1UL << 5),  // Master MPU Write channel for DMAC2 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACR0  = (1UL << 6),  // Master MPU Read channel for GMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GRAMW0  = (1UL << 7),  // Master MPU Write channel for GMAC0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACR1  = (1UL << 8),  // Master MPU Read channel for GMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACW1  = (1UL << 9),  // Master MPU Write channel for GMAC1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACR2  = (1UL << 10), // Master MPU Read channel for GMAC2 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_GMACW2  = (1UL << 11), // Master MPU Write channel for GMAC2 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBH    = (1UL << 12), // Master MPU for USB Host error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_USBF    = (1UL << 13), // Master MPU for USB Function error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGR    = (1UL << 14), // Master MPU Read channel for AXI-AP error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_DBGW    = (1UL << 15), // Master MPU Write channel for AXI-AP error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_ETRR    = (1UL << 16), // Master MPU Read channel for ETR error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_ETRW    = (1UL << 17), // Master MPU Read channel for ETR error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SHOSTIF = (1UL << 18), // Master MPU for Serial Host I/F error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_LCDCR   = (1UL << 19), // Master MPU Read channel for LCDC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_LCDCW   = (1UL << 20), // Master MPU Write channel for LCDC error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SDHIR0  = (1UL << 21), // Master MPU Read channel for SDHI0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SDHIW0  = (1UL << 22), // Master MPU Write channel for SDHI0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SDHIR1  = (1UL << 23), // Master MPU Read channel for SDHI1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_SDHIW1  = (1UL << 24), // Master MPU Write channel for SDHI1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PCIER0  = (1UL << 25), // Master MPU Read channel for PCIE0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PCIEW0  = (1UL << 26), // Master MPU Write channel for PCIE0 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PCIER1  = (1UL << 27), // Master MPU Read channel for PCIE1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_PCIEW1  = (1UL << 28), // Master MPU Write channel for PCIE1 error
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_CA55R   = (1UL << 29), // Cortex-A55 read error to Master MPU registers
    ICU_ERROR_PERIPHERAL_ERROR_1_MPU_CA55W   = (1UL << 30), // Cortex-A55 write error to Master MPU registers
} icu_error_peripheral_error_1_t;

typedef enum e_icu_error_peripheral_error_2
{
    ICU_ERROR_PERIPHERAL_ERROR_2_MPU_CR521R             = (1UL << 0),  // Cortex-R52 CPU1 read error to Master MPU registers
    ICU_ERROR_PERIPHERAL_ERROR_2_MPU_CR521W             = (1UL << 1),  // Cortex-R52 CPU1 read error to Master MPU registers
    ICU_ERROR_PERIPHERAL_ERROR_2_MAINBUSA_ERRINT        = (1UL << 2),  // Internal main bus A error
    ICU_ERROR_PERIPHERAL_ERROR_2_MAINBUSR_ERRINT        = (1UL << 3),  // Internal main bus R error
    ICU_ERROR_PERIPHERAL_ERROR_2_LLPPBUS_ERRINT         = (1UL << 4),  // LLPP bus error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_DDR_A1             = (1UL << 5),  // TZC-400-0 for DDR A0 and A1 I/F error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_DDR_A2             = (1UL << 6),  // TZC-400-1 for DDR A4 I/F error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_PCIE               = (1UL << 7),  // TZC-400 for PCIE error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_DDR_R1             = (1UL << 8),  // TZC-400-3 for DDR R2 I/F error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_DDR_R2             = (1UL << 9),  // TZC-400-4 for DDR R3 I/F error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_SYSRAM             = (1UL << 10), // TZC-400 for SYSRAM error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_BSC                = (1UL << 11), // TZC-400 for BSC error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_XSPI               = (1UL << 12), // TZC-400 for XSPI error
    ICU_ERROR_PERIPHERAL_ERROR_2_TZC_TCM                = (1UL << 13), // TZC-400 for TCM error
    ICU_ERROR_PERIPHERAL_ERROR_2_MAINBUSA_SEC_ERRINT    = (1UL << 14), // Internal main bus A error (TZM and TZS)
    ICU_ERROR_PERIPHERAL_ERROR_2_MAINBUSR_SEC_ERRINT    = (1UL << 15), // Internal main bus R error (TZM and TZS)
    ICU_ERROR_PERIPHERAL_ERROR_2_PERI_SEC_ERRINT        = (1UL << 16), // Pericore error (TZS)
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE0_INT_SERR_RC      = (1UL << 17), // PCIE0 Error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE0_INT_SERR_COR_RC  = (1UL << 18), // PCIE0 Correctable error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE0_INT_NON_FATAL_RC = (1UL << 19), // PCIE0 Non fatal error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE0_INT_SERR_FATL_RC = (1UL << 20), // PCIE0 Fatal error detect for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE0_INT_AXI_ERR      = (1UL << 21), // PCIE0 Error detect interrupt of AXI
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE1_INT_SERR_RC      = (1UL << 22), // PCIE0 Error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE1_INT_SERR_COR_RC  = (1UL << 23), // PCIE0 Correctable error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE1_INT_NON_FATAL_RC = (1UL << 24), // PCIE0 Non fatal error detect interrupt for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE1_INT_SERR_FATL_RC = (1UL << 25), // PCIE0 Fatal error detect for Root complex
    ICU_ERROR_PERIPHERAL_ERROR_2_PCIE1_INT_AXI_ERR      = (1UL << 26), // PCIE0 Error detect interrupt of AXI
    ICU_ERROR_PERIPHERAL_ERROR_2_PERF_MON_DATA_STATUS0  = (1UL << 27), // Performance monitor signal 0
    ICU_ERROR_PERIPHERAL_ERROR_2_PERF_MON_DATA_STATUS1  = (1UL << 28), // Performance monitor signal 1
} icu_error_peripheral_error_2_t;

 #endif

 #if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
typedef enum e_icu_error_dsmif_error_0
{
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0EH0 = (1UL << 0),  // DSMIF0 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EL0 = (1UL << 1),  // DSMIF0 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EH0 = (1UL << 2),  // DSMIF0 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EL0 = (1UL << 3),  // DSMIF0 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EH0 = (1UL << 4),  // DSMIF0 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0EL1 = (1UL << 5),  // DSMIF0 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0EH1 = (1UL << 6),  // DSMIF0 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EL1 = (1UL << 7),  // DSMIF0 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EH1 = (1UL << 8),  // DSMIF0 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EL1 = (1UL << 9),  // DSMIF0 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EH1 = (1UL << 10), // DSMIF0 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0EL2 = (1UL << 11), // DSMIF0 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0EH2 = (1UL << 12), // DSMIF0 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EL2 = (1UL << 13), // DSMIF0 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1EH2 = (1UL << 14), // DSMIF0 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EL2 = (1UL << 15), // DSMIF0 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2EH2 = (1UL << 16), // DSMIF0 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0WN0 = (1UL << 17), // DSMIF0 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1WN0 = (1UL << 18), // DSMIF0 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2WN0 = (1UL << 19), // DSMIF0 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC3WN0 = (1UL << 20), // DSMIF0 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0WN1 = (1UL << 21), // DSMIF0 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1WN1 = (1UL << 22), // DSMIF0 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2WN1 = (1UL << 23), // DSMIF0 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC3WN1 = (1UL << 24), // DSMIF0 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC0WN2 = (1UL << 25), // DSMIF0 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC1WN2 = (1UL << 26), // DSMIF0 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC2WN2 = (1UL << 27), // DSMIF0 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_0_DSMIF0_OVC3WN2 = (1UL << 28), // DSMIF0 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_0_t;

typedef enum e_icu_error_dsmif_error_1
{
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0EH0 = (1UL << 0),  // DSMIF1 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EL0 = (1UL << 1),  // DSMIF1 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EH0 = (1UL << 2),  // DSMIF1 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EL0 = (1UL << 3),  // DSMIF1 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EH0 = (1UL << 4),  // DSMIF1 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0EL1 = (1UL << 5),  // DSMIF1 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0EH1 = (1UL << 6),  // DSMIF1 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EL1 = (1UL << 7),  // DSMIF1 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EH1 = (1UL << 8),  // DSMIF1 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EL1 = (1UL << 9),  // DSMIF1 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EH1 = (1UL << 10), // DSMIF1 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0EL2 = (1UL << 11), // DSMIF1 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0EH2 = (1UL << 12), // DSMIF1 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EL2 = (1UL << 13), // DSMIF1 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1EH2 = (1UL << 14), // DSMIF1 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EL2 = (1UL << 15), // DSMIF1 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2EH2 = (1UL << 16), // DSMIF1 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0WN0 = (1UL << 17), // DSMIF1 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1WN0 = (1UL << 18), // DSMIF1 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2WN0 = (1UL << 19), // DSMIF1 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC3WN0 = (1UL << 20), // DSMIF1 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0WN1 = (1UL << 21), // DSMIF1 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1WN1 = (1UL << 22), // DSMIF1 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2WN1 = (1UL << 23), // DSMIF1 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC3WN1 = (1UL << 24), // DSMIF1 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC0WN2 = (1UL << 25), // DSMIF1 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC1WN2 = (1UL << 26), // DSMIF1 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC2WN2 = (1UL << 27), // DSMIF1 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_1_DSMIF1_OVC3WN2 = (1UL << 28), // DSMIF1 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_1_t;

typedef enum e_icu_error_dsmif_error_2
{
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0EH0 = (1UL << 0),  // DSMIF2 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EL0 = (1UL << 1),  // DSMIF2 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EH0 = (1UL << 2),  // DSMIF2 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EL0 = (1UL << 3),  // DSMIF2 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EH0 = (1UL << 4),  // DSMIF2 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0EL1 = (1UL << 5),  // DSMIF2 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0EH1 = (1UL << 6),  // DSMIF2 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EL1 = (1UL << 7),  // DSMIF2 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EH1 = (1UL << 8),  // DSMIF2 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EL1 = (1UL << 9),  // DSMIF2 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EH1 = (1UL << 10), // DSMIF2 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0EL2 = (1UL << 11), // DSMIF2 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0EH2 = (1UL << 12), // DSMIF2 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EL2 = (1UL << 13), // DSMIF2 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1EH2 = (1UL << 14), // DSMIF2 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EL2 = (1UL << 15), // DSMIF2 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2EH2 = (1UL << 16), // DSMIF2 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0WN0 = (1UL << 17), // DSMIF2 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1WN0 = (1UL << 18), // DSMIF2 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2WN0 = (1UL << 19), // DSMIF2 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC3WN0 = (1UL << 20), // DSMIF2 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0WN1 = (1UL << 21), // DSMIF2 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1WN1 = (1UL << 22), // DSMIF2 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2WN1 = (1UL << 23), // DSMIF2 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC3WN1 = (1UL << 24), // DSMIF2 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC0WN2 = (1UL << 25), // DSMIF2 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC1WN2 = (1UL << 26), // DSMIF2 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC2WN2 = (1UL << 27), // DSMIF2 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_2_DSMIF2_OVC3WN2 = (1UL << 28), // DSMIF2 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_2_t;

typedef enum e_icu_error_dsmif_error_3
{
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0EH0 = (1UL << 0),  // DSMIF3 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EL0 = (1UL << 1),  // DSMIF3 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EH0 = (1UL << 2),  // DSMIF3 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EL0 = (1UL << 3),  // DSMIF3 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EH0 = (1UL << 4),  // DSMIF3 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0EL1 = (1UL << 5),  // DSMIF3 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0EH1 = (1UL << 6),  // DSMIF3 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EL1 = (1UL << 7),  // DSMIF3 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EH1 = (1UL << 8),  // DSMIF3 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EL1 = (1UL << 9),  // DSMIF3 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EH1 = (1UL << 10), // DSMIF3 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0EL2 = (1UL << 11), // DSMIF3 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0EH2 = (1UL << 12), // DSMIF3 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EL2 = (1UL << 13), // DSMIF3 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1EH2 = (1UL << 14), // DSMIF3 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EL2 = (1UL << 15), // DSMIF3 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2EH2 = (1UL << 16), // DSMIF3 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0WN0 = (1UL << 17), // DSMIF3 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1WN0 = (1UL << 18), // DSMIF3 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2WN0 = (1UL << 19), // DSMIF3 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC3WN0 = (1UL << 20), // DSMIF3 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0WN1 = (1UL << 21), // DSMIF3 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1WN1 = (1UL << 22), // DSMIF3 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2WN1 = (1UL << 23), // DSMIF3 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC3WN1 = (1UL << 24), // DSMIF3 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC0WN2 = (1UL << 25), // DSMIF3 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC1WN2 = (1UL << 26), // DSMIF3 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC2WN2 = (1UL << 27), // DSMIF3 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_3_DSMIF3_OVC3WN2 = (1UL << 28), // DSMIF3 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_3_t;

typedef enum e_icu_error_dsmif_error_4
{
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0EH0 = (1UL << 0),  // DSMIF4 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EL0 = (1UL << 1),  // DSMIF4 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EH0 = (1UL << 2),  // DSMIF4 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EL0 = (1UL << 3),  // DSMIF4 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EH0 = (1UL << 4),  // DSMIF4 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0EL1 = (1UL << 5),  // DSMIF4 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0EH1 = (1UL << 6),  // DSMIF4 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EL1 = (1UL << 7),  // DSMIF4 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EH1 = (1UL << 8),  // DSMIF4 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EL1 = (1UL << 9),  // DSMIF4 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EH1 = (1UL << 10), // DSMIF4 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0EL2 = (1UL << 11), // DSMIF4 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0EH2 = (1UL << 12), // DSMIF4 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EL2 = (1UL << 13), // DSMIF4 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1EH2 = (1UL << 14), // DSMIF4 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EL2 = (1UL << 15), // DSMIF4 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2EH2 = (1UL << 16), // DSMIF4 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0WN0 = (1UL << 17), // DSMIF4 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1WN0 = (1UL << 18), // DSMIF4 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2WN0 = (1UL << 19), // DSMIF4 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC3WN0 = (1UL << 20), // DSMIF4 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0WN1 = (1UL << 21), // DSMIF4 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1WN1 = (1UL << 22), // DSMIF4 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2WN1 = (1UL << 23), // DSMIF4 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC3WN1 = (1UL << 24), // DSMIF4 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC0WN2 = (1UL << 25), // DSMIF4 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC1WN2 = (1UL << 26), // DSMIF4 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC2WN2 = (1UL << 27), // DSMIF4 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_4_DSMIF4_OVC3WN2 = (1UL << 28), // DSMIF4 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_4_t;

typedef enum e_icu_error_dsmif_error_5
{
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0EH0 = (1UL << 0),  // DSMIF5 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EL0 = (1UL << 1),  // DSMIF5 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EH0 = (1UL << 2),  // DSMIF5 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EL0 = (1UL << 3),  // DSMIF5 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EH0 = (1UL << 4),  // DSMIF5 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0EL1 = (1UL << 5),  // DSMIF5 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0EH1 = (1UL << 6),  // DSMIF5 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EL1 = (1UL << 7),  // DSMIF5 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EH1 = (1UL << 8),  // DSMIF5 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EL1 = (1UL << 9),  // DSMIF5 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EH1 = (1UL << 10), // DSMIF5 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0EL2 = (1UL << 11), // DSMIF5 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0EH2 = (1UL << 12), // DSMIF5 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EL2 = (1UL << 13), // DSMIF5 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1EH2 = (1UL << 14), // DSMIF5 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EL2 = (1UL << 15), // DSMIF5 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2EH2 = (1UL << 16), // DSMIF5 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0WN0 = (1UL << 17), // DSMIF5 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1WN0 = (1UL << 18), // DSMIF5 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2WN0 = (1UL << 19), // DSMIF5 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC3WN0 = (1UL << 20), // DSMIF5 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0WN1 = (1UL << 21), // DSMIF5 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1WN1 = (1UL << 22), // DSMIF5 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2WN1 = (1UL << 23), // DSMIF5 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC3WN1 = (1UL << 24), // DSMIF5 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC0WN2 = (1UL << 25), // DSMIF5 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC1WN2 = (1UL << 26), // DSMIF5 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC2WN2 = (1UL << 27), // DSMIF5 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_5_DSMIF5_OVC3WN2 = (1UL << 28), // DSMIF5 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_5_t;

typedef enum e_icu_error_dsmif_error_7
{
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0EH0 = (1UL << 0),  // DSMIF7 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EL0 = (1UL << 1),  // DSMIF7 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EH0 = (1UL << 2),  // DSMIF7 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EL0 = (1UL << 3),  // DSMIF7 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EH0 = (1UL << 4),  // DSMIF7 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0EL1 = (1UL << 5),  // DSMIF7 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0EH1 = (1UL << 6),  // DSMIF7 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EL1 = (1UL << 7),  // DSMIF7 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EH1 = (1UL << 8),  // DSMIF7 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EL1 = (1UL << 9),  // DSMIF7 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EH1 = (1UL << 10), // DSMIF7 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0EL2 = (1UL << 11), // DSMIF7 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0EH2 = (1UL << 12), // DSMIF7 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EL2 = (1UL << 13), // DSMIF7 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1EH2 = (1UL << 14), // DSMIF7 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EL2 = (1UL << 15), // DSMIF7 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2EH2 = (1UL << 16), // DSMIF7 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0WN0 = (1UL << 17), // DSMIF7 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1WN0 = (1UL << 18), // DSMIF7 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2WN0 = (1UL << 19), // DSMIF7 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC3WN0 = (1UL << 20), // DSMIF7 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0WN1 = (1UL << 21), // DSMIF7 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1WN1 = (1UL << 22), // DSMIF7 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2WN1 = (1UL << 23), // DSMIF7 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC3WN1 = (1UL << 24), // DSMIF7 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC0WN2 = (1UL << 25), // DSMIF7 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC1WN2 = (1UL << 26), // DSMIF7 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC2WN2 = (1UL << 27), // DSMIF7 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_7_DSMIF7_OVC3WN2 = (1UL << 28), // DSMIF7 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_7_t;

typedef enum e_icu_error_dsmif_error_8
{
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0EH0 = (1UL << 0),  // DSMIF8 Overcurrent Upper limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EL0 = (1UL << 1),  // DSMIF8 Overcurrent Lower limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EH0 = (1UL << 2),  // DSMIF8 Overcurrent Upper limit Detection 1 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EL0 = (1UL << 3),  // DSMIF8 Overcurrent Lower limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EH0 = (1UL << 4),  // DSMIF8 Overcurrent Upper limit Detection 2 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0EL1 = (1UL << 5),  // DSMIF8 Overcurrent Lower limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0EH1 = (1UL << 6),  // DSMIF8 Overcurrent Upper limit Detection 0 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EL1 = (1UL << 7),  // DSMIF8 Overcurrent Lower limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EH1 = (1UL << 8),  // DSMIF8 Overcurrent Upper limit Detection 1 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EL1 = (1UL << 9),  // DSMIF8 Overcurrent Lower limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EH1 = (1UL << 10), // DSMIF8 Overcurrent Upper limit Detection 2 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0EL2 = (1UL << 11), // DSMIF8 Overcurrent Lower limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0EH2 = (1UL << 12), // DSMIF8 Overcurrent Upper limit Detection 0 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EL2 = (1UL << 13), // DSMIF8 Overcurrent Lower limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1EH2 = (1UL << 14), // DSMIF8 Overcurrent Upper limit Detection 1 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EL2 = (1UL << 15), // DSMIF8 Overcurrent Lower limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2EH2 = (1UL << 16), // DSMIF8 Overcurrent Upper limit Detection 2 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0WN0 = (1UL << 17), // DSMIF8 Overcurrent Detection Window Notification 0 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1WN0 = (1UL << 18), // DSMIF8 Overcurrent Detection Window Notification 1 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2WN0 = (1UL << 19), // DSMIF8 Overcurrent Detection Window Notification 2 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC3WN0 = (1UL << 20), // DSMIF8 Overcurrent Detection Window Notification 3 CH 0
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0WN1 = (1UL << 21), // DSMIF8 Overcurrent Detection Window Notification 0 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1WN1 = (1UL << 22), // DSMIF8 Overcurrent Detection Window Notification 1 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2WN1 = (1UL << 23), // DSMIF8 Overcurrent Detection Window Notification 2 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC3WN1 = (1UL << 24), // DSMIF8 Overcurrent Detection Window Notification 3 CH 1
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC0WN2 = (1UL << 25), // DSMIF8 Overcurrent Detection Window Notification 0 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC1WN2 = (1UL << 26), // DSMIF8 Overcurrent Detection Window Notification 1 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC2WN2 = (1UL << 27), // DSMIF8 Overcurrent Detection Window Notification 2 CH 2
    ICU_ERROR_DSMIF_ERROR_8_DSMIF8_OVC3WN2 = (1UL << 28), // DSMIF8 Overcurrent Detection Window Notification 3 CH 2
} icu_error_dsmif_error_8_t;

typedef enum e_icu_error_dsmif_error_10
{
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_SUMERRL = (1UL << 0),  // DSMIF0 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_SUMERRH = (1UL << 1),  // DSMIF0 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_SCE0    = (1UL << 2),  // DSMIF0 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_SCE1    = (1UL << 3),  // DSMIF0 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_SCE2    = (1UL << 4),  // DSMIF0 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_10_DSMIF0_OVC0EL0 = (1UL << 5),  // DSMIF0 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_SUMERRL = (1UL << 6),  // DSMIF1 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_SUMERRH = (1UL << 7),  // DSMIF1 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_SCE0    = (1UL << 8),  // DSMIF1 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_SCE1    = (1UL << 9),  // DSMIF1 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_SCE2    = (1UL << 10), // DSMIF1 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_10_DSMIF1_OVC0EL0 = (1UL << 11), // DSMIF1 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_SUMERRL = (1UL << 12), // DSMIF2 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_SUMERRH = (1UL << 13), // DSMIF2 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_SCE0    = (1UL << 14), // DSMIF2 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_SCE1    = (1UL << 15), // DSMIF2 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_SCE2    = (1UL << 16), // DSMIF2 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_10_DSMIF2_OVC0EL0 = (1UL << 17), // DSMIF2 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_SUMERRL = (1UL << 18), // DSMIF3 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_SUMERRH = (1UL << 19), // DSMIF3 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_SCE0    = (1UL << 20), // DSMIF3 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_SCE1    = (1UL << 21), // DSMIF3 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_SCE2    = (1UL << 22), // DSMIF3 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_10_DSMIF3_OVC0EL0 = (1UL << 23), // DSMIF3 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_SUMERRL = (1UL << 24), // DSMIF4 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_SUMERRH = (1UL << 25), // DSMIF4 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_SCE0    = (1UL << 26), // DSMIF4 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_SCE1    = (1UL << 27), // DSMIF4 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_SCE2    = (1UL << 28), // DSMIF4 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_10_DSMIF4_OVC0EL0 = (1UL << 29), // DSMIF4 Overcurrent Lower limit Detection 0 CH 0
} icu_error_dsmif_error_10_t;

typedef enum e_icu_error_dsmif_error_11
{
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_SUMERRL = (1UL << 0),  // DSMIF5 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_SUMERRH = (1UL << 1),  // DSMIF5 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_SCE0    = (1UL << 2),  // DSMIF5 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_SCE1    = (1UL << 3),  // DSMIF5 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_SCE2    = (1UL << 4),  // DSMIF5 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_11_DSMIF5_OVC0EL0 = (1UL << 5),  // DSMIF5 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_SUMERRL = (1UL << 12), // DSMIF7 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_SUMERRH = (1UL << 13), // DSMIF7 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_SCE0    = (1UL << 14), // DSMIF7 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_SCE1    = (1UL << 15), // DSMIF7 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_SCE2    = (1UL << 16), // DSMIF7 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_11_DSMIF7_OVC0EL0 = (1UL << 17), // DSMIF7 Overcurrent Lower limit Detection 0 CH 0
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_SUMERRL = (1UL << 18), // DSMIF8 Overcurrent Sum Error Lower limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_SUMERRH = (1UL << 19), // DSMIF8 Overcurrent Sum Error Upper limit detection
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_SCE0    = (1UL << 20), // DSMIF8 Short Circuit Detection CH 0
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_SCE1    = (1UL << 21), // DSMIF8 Short Circuit Detection CH 1
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_SCE2    = (1UL << 22), // DSMIF8 Short Circuit Detection CH 2
    ICU_ERROR_DSMIF_ERROR_11_DSMIF8_OVC0EL0 = (1UL << 23), // DSMIF8 Overcurrent Lower limit Detection 0 CH 0
} icu_error_dsmif_error_11_t;
 #endif

 #if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
typedef enum e_icu_error_encif_error_0
{
    ICU_ERROR_ENCIF_ERROR_0_BISS00_NER   = (1UL << 0),  // BISS00 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS01_NER   = (1UL << 1),  // BISS01 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS02_NER   = (1UL << 2),  // BISS02 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS03_NER   = (1UL << 3),  // BISS03 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS04_NER   = (1UL << 4),  // BISS04 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS05_NER   = (1UL << 5),  // BISS05 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS06_NER   = (1UL << 6),  // BISS06 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS07_NER   = (1UL << 7),  // BISS07 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS09_NER   = (1UL << 9),  // BISS09 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS10_NER   = (1UL << 10), // BISS10 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS11_NER   = (1UL << 11), // BISS11 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS12_NER   = (1UL << 12), // BISS12 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS13_NER   = (1UL << 13), // BISS13 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_BISS14_NER   = (1UL << 14), // BISS14 Error interrupt
    ICU_ERROR_ENCIF_ERROR_0_AFMT00_TMOUT = (1UL << 16), // AFMT00 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT01_TMOUT = (1UL << 17), // AFMT01 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT02_TMOUT = (1UL << 18), // AFMT02 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT03_TMOUT = (1UL << 19), // AFMT03 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT04_TMOUT = (1UL << 20), // AFMT04 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT05_TMOUT = (1UL << 21), // AFMT05 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT06_TMOUT = (1UL << 22), // AFMT06 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT07_TMOUT = (1UL << 23), // AFMT07 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT09_TMOUT = (1UL << 25), // AFMT09 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT10_TMOUT = (1UL << 26), // AFMT10 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT11_TMOUT = (1UL << 27), // AFMT11 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT12_TMOUT = (1UL << 28), // AFMT12 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT13_TMOUT = (1UL << 29), // AFMT13 Time out error
    ICU_ERROR_ENCIF_ERROR_0_AFMT14_TMOUT = (1UL << 30), // AFMT14 Time out error
} icu_error_encif_error_0_t;

typedef enum e_icu_error_encif_error_1
{
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_ESTIMATOR_ON     = (1UL << 0),  // HDSL00 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_SAFE_CHANNEL_ERR = (1UL << 1),  // HDSL00 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_SAFE_POS_ERR     = (1UL << 2),  // HDSL00 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_ACCELERATION_ERR = (1UL << 3),  // HDSL00 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_ACC_THR_ERR      = (1UL << 4),  // HDSL00 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_ENCODING_ERR     = (1UL << 5),  // HDSL00 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_1_HDSL00_DEV_THR_ERR      = (1UL << 6),  // HDSL00 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_ESTIMATOR_ON     = (1UL << 8),  // HDSL01 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_SAFE_CHANNEL_ERR = (1UL << 9),  // HDSL01 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_SAFE_POS_ERR     = (1UL << 10), // HDSL01 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_ACCELERATION_ERR = (1UL << 11), // HDSL01 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_ACC_THR_ERR      = (1UL << 12), // HDSL01 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_ENCODING_ERR     = (1UL << 13), // HDSL01 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_1_HDSL01_DEV_THR_ERR      = (1UL << 14), // HDSL01 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_ESTIMATOR_ON     = (1UL << 16), // HDSL02 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_SAFE_CHANNEL_ERR = (1UL << 17), // HDSL02 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_SAFE_POS_ERR     = (1UL << 18), // HDSL02 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_ACCELERATION_ERR = (1UL << 19), // HDSL02 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_ACC_THR_ERR      = (1UL << 20), // HDSL02 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_ENCODING_ERR     = (1UL << 21), // HDSL02 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_1_HDSL02_DEV_THR_ERR      = (1UL << 22), // HDSL02 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_ESTIMATOR_ON     = (1UL << 24), // HDSL03 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_SAFE_CHANNEL_ERR = (1UL << 25), // HDSL03 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_SAFE_POS_ERR     = (1UL << 26), // HDSL03 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_ACCELERATION_ERR = (1UL << 27), // HDSL03 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_ACC_THR_ERR      = (1UL << 28), // HDSL03 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_ENCODING_ERR     = (1UL << 29), // HDSL03 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_1_HDSL03_DEV_THR_ERR      = (1UL << 30), // HDSL03 Estimator deviation threshold reached
} icu_error_encif_error_1_t;

typedef enum e_icu_error_encif_error_2
{
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_ESTIMATOR_ON     = (1UL << 0),  // HDSL04 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_SAFE_CHANNEL_ERR = (1UL << 1),  // HDSL04 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_SAFE_POS_ERR     = (1UL << 2),  // HDSL04 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_ACCELERATION_ERR = (1UL << 3),  // HDSL04 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_ACC_THR_ERR      = (1UL << 4),  // HDSL04 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_ENCODING_ERR     = (1UL << 5),  // HDSL04 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_2_HDSL04_DEV_THR_ERR      = (1UL << 6),  // HDSL04 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_ESTIMATOR_ON     = (1UL << 8),  // HDSL05 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_SAFE_CHANNEL_ERR = (1UL << 9),  // HDSL05 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_SAFE_POS_ERR     = (1UL << 10), // HDSL05 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_ACCELERATION_ERR = (1UL << 11), // HDSL05 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_ACC_THR_ERR      = (1UL << 12), // HDSL05 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_ENCODING_ERR     = (1UL << 13), // HDSL05 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_2_HDSL05_DEV_THR_ERR      = (1UL << 14), // HDSL05 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_ESTIMATOR_ON     = (1UL << 16), // HDSL06 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_SAFE_CHANNEL_ERR = (1UL << 17), // HDSL06 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_SAFE_POS_ERR     = (1UL << 18), // HDSL06 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_ACCELERATION_ERR = (1UL << 19), // HDSL06 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_ACC_THR_ERR      = (1UL << 20), // HDSL06 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_ENCODING_ERR     = (1UL << 21), // HDSL06 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_2_HDSL06_DEV_THR_ERR      = (1UL << 22), // HDSL06 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_ESTIMATOR_ON     = (1UL << 24), // HDSL07 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_SAFE_CHANNEL_ERR = (1UL << 25), // HDSL07 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_SAFE_POS_ERR     = (1UL << 26), // HDSL07 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_ACCELERATION_ERR = (1UL << 27), // HDSL07 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_ACC_THR_ERR      = (1UL << 28), // HDSL07 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_ENCODING_ERR     = (1UL << 29), // HDSL07 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_2_HDSL07_DEV_THR_ERR      = (1UL << 30), // HDSL07 Estimator deviation threshold reached
} icu_error_encif_error_2_t;

typedef enum e_icu_error_encif_error_3
{
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_ESTIMATOR_ON     = (1UL << 8),  // HDSL09 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_SAFE_CHANNEL_ERR = (1UL << 9),  // HDSL09 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_SAFE_POS_ERR     = (1UL << 10), // HDSL09 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_ACCELERATION_ERR = (1UL << 11), // HDSL09 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_ACC_THR_ERR      = (1UL << 12), // HDSL09 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_ENCODING_ERR     = (1UL << 13), // HDSL09 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_3_HDSL09_DEV_THR_ERR      = (1UL << 14), // HDSL09 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_ESTIMATOR_ON     = (1UL << 16), // HDSL10 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_SAFE_CHANNEL_ERR = (1UL << 17), // HDSL10 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_SAFE_POS_ERR     = (1UL << 18), // HDSL10 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_ACCELERATION_ERR = (1UL << 19), // HDSL10 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_ACC_THR_ERR      = (1UL << 20), // HDSL10 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_ENCODING_ERR     = (1UL << 21), // HDSL10 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_3_HDSL10_DEV_THR_ERR      = (1UL << 22), // HDSL10 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_ESTIMATOR_ON     = (1UL << 24), // HDSL11 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_SAFE_CHANNEL_ERR = (1UL << 25), // HDSL11 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_SAFE_POS_ERR     = (1UL << 26), // HDSL11 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_ACCELERATION_ERR = (1UL << 27), // HDSL11 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_ACC_THR_ERR      = (1UL << 28), // HDSL11 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_ENCODING_ERR     = (1UL << 29), // HDSL11 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_3_HDSL11_DEV_THR_ERR      = (1UL << 30), // HDSL11 Estimator deviation threshold reached
} icu_error_encif_error_3_t;

typedef enum e_icu_error_encif_error_4
{
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_ESTIMATOR_ON     = (1UL << 0),  // HDSL12 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_SAFE_CHANNEL_ERR = (1UL << 1),  // HDSL12 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_SAFE_POS_ERR     = (1UL << 2),  // HDSL12 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_ACCELERATION_ERR = (1UL << 3),  // HDSL12 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_ACC_THR_ERR      = (1UL << 4),  // HDSL12 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_ENCODING_ERR     = (1UL << 5),  // HDSL12 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_4_HDSL12_DEV_THR_ERR      = (1UL << 6),  // HDSL12 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_ESTIMATOR_ON     = (1UL << 8),  // HDSL13 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_SAFE_CHANNEL_ERR = (1UL << 9),  // HDSL13 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_SAFE_POS_ERR     = (1UL << 10), // HDSL13 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_ACCELERATION_ERR = (1UL << 11), // HDSL13 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_ACC_THR_ERR      = (1UL << 12), // HDSL13 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_ENCODING_ERR     = (1UL << 13), // HDSL13 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_4_HDSL13_DEV_THR_ERR      = (1UL << 14), // HDSL13 Estimator deviation threshold reached
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_ESTIMATOR_ON     = (1UL << 16), // HDSL14 Position Estimator activated
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_SAFE_CHANNEL_ERR = (1UL << 17), // HDSL14 Transmission error in safe channel 1
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_SAFE_POS_ERR     = (1UL << 18), // HDSL14 Safe position not valid
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_ACCELERATION_ERR = (1UL << 19), // HDSL14 Fast channel / position error
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_ACC_THR_ERR      = (1UL << 20), // HDSL14 Fast channel / position threshold error
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_ENCODING_ERR     = (1UL << 21), // HDSL14 DSL message encoding error
    ICU_ERROR_ENCIF_ERROR_4_HDSL14_DEV_THR_ERR      = (1UL << 22), // HDSL14 Estimator deviation threshold reached
} icu_error_encif_error_4_t;
 #endif

/** ERROR instance control block. Do not initialize. Initialization occurs when the @ref RZN::error_api_t::open function is called. */
struct st_icu_error_instance_ctrl
{
    error_cfg_t const * p_cfg;         // Pointer to the configuration structure
    uint32_t            open;          ///< Used by driver to check if the control structure is valid

    /* Pointer to callback and optional working memory */
    void (* p_callback)(error_callback_args_t *);
    error_callback_args_t * p_callback_memory;
    void * p_context;                  ///< User defined context passed into callback function
};

/** ERROR instance control block. Do not initialize. Initialization occurs when the @ref RZN::error_api_t::open function is called. Please refer to the struct st_icu_error_instance_ctrl. */
typedef struct st_icu_error_instance_ctrl icu_error_instance_ctrl_t;

/** ERROR event configuration extension. */
struct st_icu_error_extended_cfg
{
    uint8_t   cpu0_err0_ipl;                           ///< Cortex-R52 CPU0 error 0 interrupt priority
    IRQn_Type cpu0_err0_irq;                           ///< Cortex-R52 CPU0 error 0 interrupt IRQ number
    uint8_t   cpu0_err1_ipl;                           ///< Cortex-R52 CPU0 error 1 interrupt priority
    IRQn_Type cpu0_err1_irq;                           ///< Cortex-R52 CPU0 error 1 interrupt IRQ number
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    uint8_t   cpu1_err0_ipl;                           ///< Cortex-R52 CPU1 error 0 interrupt interrupt priority
    IRQn_Type cpu1_err0_irq;                           ///< Cortex-R52 CPU1 error 0 interrupt IRQ number
    uint8_t   cpu1_err1_ipl;                           ///< Cortex-R52 CPU1 error 1 interrupt interrupt priority
    IRQn_Type cpu1_err1_irq;                           ///< Cortex-R52 CPU1 error 1 interrupt IRQ number
 #endif
 #if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    uint8_t   ca55_err0_ipl;                           ///< Cortex-A55 error 0 interrupt interrupt priority
    IRQn_Type ca55_err0_irq;                           ///< Cortex-A55 error 0 interrupt IRQ number
    uint8_t   ca55_err1_ipl;                           ///< Cortex-A55 error 1 interrupt interrupt priority
    IRQn_Type ca55_err1_irq;                           ///< Cortex-A55 error 1 interrupt IRQ number
 #endif
    uint8_t   peri_err0_ipl;                           ///< Peripheral error 0 interrupt priority
    IRQn_Type peri_err0_irq;                           ///< Peripheral error 0 interrupt IRQ number
    uint8_t   peri_err1_ipl;                           ///< Peripheral error 1 interrupt priority
    IRQn_Type peri_err1_irq;                           ///< Peripheral error 1 interrupt IRQ number

 #if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    uint8_t   dsmif_err0_ipl;                          ///< DSMIF error 0 interrupt priority
    IRQn_Type dsmif_err0_irq;                          ///< DSMIF error 0 interrupt IRQ number
    uint8_t   dsmif_err1_ipl;                          ///< DSMIF error 1 interrupt priority
    IRQn_Type dsmif_err1_irq;                          ///< DSMIF error 1 interrupt IRQ number
 #endif

 #if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    uint8_t   encif_err0_ipl;                          ///< ENCIF error 0 interrupt priority
    IRQn_Type encif_err0_irq;                          ///< ENCIF error 0 interrupt IRQ number
    uint8_t   encif_err1_ipl;                          ///< ENCIF error 1 interrupt priority
    IRQn_Type encif_err1_irq;                          ///< ENCIF error 1 interrupt IRQ number
 #endif

    uint32_t cpu0_err_reset_mask;                      ///< Cortex-R52 CPU0 error reset mask
    uint32_t cpu0_err0_event_mask;                     ///< Cortex-R52 CPU0 error 0 event mask
    uint32_t cpu0_err1_event_mask;                     ///< Cortex-R52 CPU0 error 1 event mask
 #if BSP_FEATURE_ICU_ERROR_CR52_CPU1_SUPPORTED
    uint32_t cpu1_err_reset_mask;                      ///< Cortex-R52 CPU1 error reset mask
    uint32_t cpu1_err0_event_mask;                     ///< Cortex-R52 CPU1 error 0 event mask
    uint32_t cpu1_err1_event_mask;                     ///< Cortex-R52 CPU1 error 1 event mask
 #endif
 #if BSP_FEATURE_ICU_ERROR_CA55_SUPPORTED
    uint32_t ca55_err_reset_mask;                      ///< Cortex-R52 CA55 error reset mask
    uint32_t ca55_err0_event_mask;                     ///< Cortex-R52 CA55 error 0 event mask
    uint32_t ca55_err1_event_mask;                     ///< Cortex-R52 CA55 error 1 event mask
 #endif
    uint32_t peri_err_event_0_reset_mask;              ///< Peripheral error event 0 reset mask
    uint32_t peri_err0_event_0_mask;                   ///< Peripheral error 0 event 0 mask
    uint32_t peri_err1_event_0_mask;                   ///< Peripheral error 1 event 0 mask
    uint32_t peri_err_event_1_reset_mask;              ///< Peripheral error event 1 reset mask
    uint32_t peri_err0_event_1_mask;                   ///< Peripheral error 0 event 1 mask
    uint32_t peri_err1_event_1_mask;                   ///< Peripheral error 1 event 1 mask
 #if 2U < BSP_FEATURE_ICU_ERROR_PERI_ERR_REG_NUM
    uint32_t peri_err_event_2_reset_mask;              ///< Peripheral error event 2 reset mask
    uint32_t peri_err0_event_2_mask;                   ///< Peripheral error 0 event 2 mask
    uint32_t peri_err1_event_2_mask;                   ///< Peripheral error 1 event 2 mask
 #endif

 #if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    uint32_t dsmif_err_event_0_reset_mask;             ///< DSMIF error event 0 reset mask
    uint32_t dsmif_err0_event_0_mask;                  ///< DSMIF error 0 event 0 mask
    uint32_t dsmif_err1_event_0_mask;                  ///< DSMIF error 1 event 0 mask
    uint32_t dsmif_err_event_1_reset_mask;             ///< DSMIF error event 1 reset mask
    uint32_t dsmif_err0_event_1_mask;                  ///< DSMIF error 0 event 1 mask
    uint32_t dsmif_err1_event_1_mask;                  ///< DSMIF error 1 event 1 mask
    uint32_t dsmif_err_event_2_reset_mask;             ///< DSMIF error event 2 reset mask
    uint32_t dsmif_err0_event_2_mask;                  ///< DSMIF error 0 event 2 mask
    uint32_t dsmif_err1_event_2_mask;                  ///< DSMIF error 1 event 2 mask
    uint32_t dsmif_err_event_3_reset_mask;             ///< DSMIF error event 3 reset mask
    uint32_t dsmif_err0_event_3_mask;                  ///< DSMIF error 0 event 3 mask
    uint32_t dsmif_err1_event_3_mask;                  ///< DSMIF error 1 event 3 mask
    uint32_t dsmif_err_event_4_reset_mask;             ///< DSMIF error event 4 reset mask
    uint32_t dsmif_err0_event_4_mask;                  ///< DSMIF error 0 event 4 mask
    uint32_t dsmif_err1_event_4_mask;                  ///< DSMIF error 1 event 4 mask
    uint32_t dsmif_err_event_5_reset_mask;             ///< DSMIF error event 5 reset mask
    uint32_t dsmif_err0_event_5_mask;                  ///< DSMIF error 0 event 5 mask
    uint32_t dsmif_err1_event_5_mask;                  ///< DSMIF error 1 event 5 mask
    uint32_t dsmif_err_event_7_reset_mask;             ///< DSMIF error event 7 reset mask
    uint32_t dsmif_err0_event_7_mask;                  ///< DSMIF error 0 event 7 mask
    uint32_t dsmif_err1_event_7_mask;                  ///< DSMIF error 1 event 7 mask
    uint32_t dsmif_err_event_8_reset_mask;             ///< DSMIF error event 8 reset mask
    uint32_t dsmif_err0_event_8_mask;                  ///< DSMIF error 0 event 8 mask
    uint32_t dsmif_err1_event_8_mask;                  ///< DSMIF error 1 event 8 mask
    uint32_t dsmif_err_event_10_reset_mask;            ///< DSMIF error event 10 reset mask
    uint32_t dsmif_err0_event_10_mask;                 ///< DSMIF error 0 event 10 mask
    uint32_t dsmif_err1_event_10_mask;                 ///< DSMIF error 1 event 10 mask
    uint32_t dsmif_err_event_11_reset_mask;            ///< DSMIF error event 11 reset mask
    uint32_t dsmif_err0_event_11_mask;                 ///< DSMIF error 0 event 11 mask
    uint32_t dsmif_err1_event_11_mask;                 ///< DSMIF error 1 event 11 mask
 #endif
 #if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    uint32_t encif_err_event_0_reset_mask;             ///< ENCIF error event 0 reset mask
    uint32_t encif_err0_event_0_mask;                  ///< ENCIF error 0 event 0 mask
    uint32_t encif_err1_event_0_mask;                  ///< ENCIF error 1 event 0 mask
    uint32_t encif_err_event_1_reset_mask;             ///< ENCIF error event 1 reset mask
    uint32_t encif_err0_event_1_mask;                  ///< ENCIF error 0 event 1 mask
    uint32_t encif_err1_event_1_mask;                  ///< ENCIF error 1 event 1 mask
    uint32_t encif_err_event_2_reset_mask;             ///< ENCIF error event 2 reset mask
    uint32_t encif_err0_event_2_mask;                  ///< ENCIF error 0 event 2 mask
    uint32_t encif_err1_event_2_mask;                  ///< ENCIF error 1 event 2 mask
    uint32_t encif_err_event_3_reset_mask;             ///< ENCIF error event 3 reset mask
    uint32_t encif_err0_event_3_mask;                  ///< ENCIF error 0 event 3 mask
    uint32_t encif_err1_event_3_mask;                  ///< ENCIF error 1 event 3 mask
    uint32_t encif_err_event_4_reset_mask;             ///< ENCIF error event 4 reset mask
    uint32_t encif_err0_event_4_mask;                  ///< ENCIF error 0 event 4 mask
    uint32_t encif_err1_event_4_mask;                  ///< ENCIF error 1 event 4 mask
 #endif
    const error_table_t * p_error_handler_table;       ///< Peripheral error handler table

 #if BSP_FEATURE_ICU_ERROR_DSMIF_ERR_INTERRUPT_SUPPORTED
    const error_table_t * p_dsmif_error_handler_table; ///< DSMIF error handler table
 #endif

 #if BSP_FEATURE_ICU_ERROR_ENCIF_ERR_INTERRUPT_SUPPORTED
    const error_table_t * p_encif_error_handler_table; ///< ENCIF error handler table
 #endif
};

/** ERROR event configuration extension. Please refer to the struct st_icu_error_extended_cfg. */
typedef struct st_icu_error_extended_cfg icu_error_extended_cfg_t;

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/** @cond INC_HEADER_DEFS_SEC */
/** Filled in Interface API structure for this Instance. */
extern const error_api_t g_error_on_icu_error;

/** @endcond */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZN
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZN_ICU_ERROR
 * @{
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public APIs
 **********************************************************************************************************************/
fsp_err_t R_ICU_ERROR_Open(error_ctrl_t * const p_ctrl, error_cfg_t const * const p_cfg);
fsp_err_t R_ICU_ERROR_Close(error_ctrl_t * const p_ctrl);
fsp_err_t R_ICU_ERROR_StatusGet(error_ctrl_t * const p_ctrl, uint32_t source, uint32_t * p_status);
fsp_err_t R_ICU_ERROR_StatusClear(error_ctrl_t * const p_ctrl, uint32_t source, uint32_t event);
fsp_err_t R_ICU_ERROR_CallbackSet(error_ctrl_t * const          p_ctrl,
                                  void (                      * p_callback)(error_callback_args_t *),
                                  void * const                  p_context,
                                  error_callback_args_t * const p_callback_memory);

/*******************************************************************************************************************//**
 * @} (end defgroup ICU_ERROR)
 **********************************************************************************************************************/
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
