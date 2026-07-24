/**************************************************************************//**
 * @file     cmsis_ca55.h
 * @brief    CMSIS Cortex-A55 Core Peripheral Access Layer Header File
 * @date     17. June 2024
 ******************************************************************************/

/*
 * Copyright [2020-2024] Renesas Electronics Corporation and/or its affiliates. All Rights Reserved.
 *
 * This file is based on the "\CMSIS\Core\Include\core_armv8mml.h"
 *
 * Changes:
 *    - Changed to be related to Cortex-A55 by
 * Renesas Electronics Corporation on 2024-06-17
 *    - Added address offsets for per-core GICR registers
 * Renesas Electronics Corporation on 2024-09-18
 */

/*
 * Copyright (c) 2009-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __CORE_CA55_H_GENERIC
#define __CORE_CA55_H_GENERIC

#ifdef __cplusplus
 #define   __I       volatile            /*!< Defines 'read only' permissions */
#else
 #define   __I       volatile const      /*!< Defines 'read only' permissions */
#endif
#define     __O      volatile            /*!< Defines 'write only' permissions */
#define     __IO     volatile            /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */

typedef struct
{
    __IOM uint32_t GICD_CTLR;            /*!< \brief Offset: 0x0000 (R/W) Distributor Control Register */
    __IM uint32_t  GICD_TYPER;           /*!< \brief Offset: 0x0004 (R/ ) Interrupt Controller Type Register */
    __IM uint32_t  GICD_IIDR;            /*!< \brief Offset: 0x0008 (R/ ) Distributor Implementer Identification Register */
    uint32_t       RESERVED1[5];
    __IOM uint32_t GICD_FCTLR;           /*!< \brief Offset: 0x0020 (R/W) Function Control Register */
    __IOM uint32_t GICD_SAC;             /*!< \brief Offset: 0x0024 (R/W) Secure Access Control */
    uint32_t       RESERVED2[6];
    __OM uint32_t  GICD_SETSPI_NSR;      /*!< \brief Offset: 0x0040 ( /W) Non-secure SPI Set Register */
    uint32_t       RESERVED3;
    __OM uint32_t  GICD_CLRSPI_NSR;      /*!< \brief Offset: 0x0048 ( /W) Non-secure SPI Clear Register */
    uint32_t       RESERVED4;
    __OM uint32_t  GICD_SETSPI_SR;       /*!< \brief Offset: 0x0050 ( /W) Secure SPI Set Register */
    uint32_t       RESERVED5;
    __OM uint32_t  GICD_CLRSPI_SR;       /*!< \brief Offset: 0x0058 ( /W) Secure SPI Clear Register */
    uint32_t       RESERVED6[9];
    __IOM uint32_t GICD_IGROUPR[32];     /*!< \brief Offset: 0x0080 (R/W) Interrupt Group Registers */
    __IOM uint32_t GICD_ISENABLER[32];   /*!< \brief Offset: 0x0100 (R/W) Interrupt Set-Enable Registers */
    __IOM uint32_t GICD_ICENABLER[32];   /*!< \brief Offset: 0x0180 (R/W) Interrupt Clear-Enable Registers */
    __IOM uint32_t GICD_ISPENDR[32];     /*!< \brief Offset: 0x0200 (R/W) Interrupt Set-Pending Registers */
    __IOM uint32_t GICD_ICPENDR[32];     /*!< \brief Offset: 0x0280 (R/W) Interrupt Clear-Pending Registers */
    __IOM uint32_t GICD_ISACTIVER[32];   /*!< \brief Offset: 0x0300 (R/W) Interrupt Set-Active Registers */
    __IOM uint32_t GICD_ICACTIVER[32];   /*!< \brief Offset: 0x0380 (R/W) Interrupt Clear-Active Registers */
    __IOM uint32_t GICD_IPRIORITYR[256]; /*!< \brief Offset: 0x0400 (R/W) Interrupt Priority Registers */
    uint32_t       RESERVED7[256];
    __IOM uint32_t GICD_ICFGR[64];       /*!< \brief Offset: 0x0C00 (R/W) Interrupt Configuration Registers */
    __IOM uint32_t GICD_IGRPMODR[32];    /*!< \brief Offset: 0x0D00 (R/W) Interrupt Group Modifier Registers */
    uint32_t       RESERVED8[32];
    __IOM uint32_t GICD_NSACR[64];       /*!< \brief Offset: 0x0E00 (R/W) Non-secure Access Control */
    uint32_t       RESERVED9[5248];
    __IOM uint64_t GICD_IROUTER[988];    /*!< \brief Offset: 0x6100 (R/W) Interrupt Routing Registers. */
    uint32_t       RESERVED10[4105];
    __IOM uint32_t GICD_CHIPSR;          /*!< \brief Offset: 0xC000 (R/W) Chip Status Register */
    __IOM uint32_t GICD_DCHIPR;          /*!< \brief Offset: 0xC004 (R/W) Default Chip Register */
    __IOM uint64_t GICD_CHIPR[16];       /*!< \brief Offset: 0xC008 (R/W) Chip Registers */
    uint32_t       RESERVED11[2016];
    __IOM uint32_t GICD_ICLAR[60];       /*!< \brief Offset: 0xE010 (R/W) The first register is GICD_ICLAR2 */
    __IOM uint32_t GICD_IERRR[30];       /*!< \brief Offset: 0xE108 (R/W) The first register is GICD_IERRR1 */
    uint32_t       RESERVED12[928];
    __IM uint64_t  GICD_CFGID;           /*!< \brief Offset: 0xF000 (R/ ) Configuration ID Register */
    uint32_t       RESERVED13[1010];
    __IM uint32_t  GICD_PIDR4;           /*!< \brief Offset: 0xFFD0 (R/ ) Peripheral ID4 register */
    __IM uint32_t  GICD_PIDR5;           /*!< \brief Offset: 0xFFD4 (R/ ) Peripheral ID 5 Register */
    __IM uint32_t  GICD_PIDR6;           /*!< \brief Offset: 0xFFD8 (R/ ) Peripheral ID 6 Register */
    __IM uint32_t  GICD_PIDR7;           /*!< \brief Offset: 0xFFDC (R/ ) Peripheral ID 7 Register */
    __IM uint32_t  GICD_PIDR0;           /*!< \brief Offset: 0xFFE0 (R/ ) Peripheral ID0 register */
    __IM uint32_t  GICD_PIDR1;           /*!< \brief Offset: 0xFFE4 (R/ ) Peripheral ID1 register */
    __IM uint32_t  GICD_PIDR2;           /*!< \brief Offset: 0xFFE8 (R/ ) Peripheral ID2 register */
    __IM uint32_t  GICD_PIDR3;           /*!< \brief Offset: 0xFFEC (R/ ) Peripheral ID3 register */
    __IM uint32_t  GICD_CIDR0;           /*!< \brief Offset: 0xFFF0 (R/ ) Component ID 0 Register */
    __IM uint32_t  GICD_CIDR1;           /*!< \brief Offset: 0xFFF4 (R/ ) Component ID 1 Register */
    __IM uint32_t  GICD_CIDR2;           /*!< \brief Offset: 0xFFF8 (R/ ) Component ID 2 Register */
    __IM uint32_t  GICD_CIDR3;           /*!< \brief Offset: 0xFFFC (R/ ) Component ID 3 Register */
} GICD_Type;

/**
 * \brief  Structure type to access the Generic Interrupt Controller (GIC) for GICR for Control target.
 */
typedef struct
{
    __IOM uint32_t GICR_CTLR;          /*!< \brief Offset: 0x0x0000 (R/W) Redistributor Control Register */
    __IM uint32_t  GICR_IIDR;          /*!< \brief Offset: 0x0x0004 (R/ ) Redistributor Implementation Identification Register */
    __IM uint64_t  GICR_TYPER;         /*!< \brief Offset: 0x0x0008 (R/ ) Interrupt Controller Type Register */
    uint32_t       RESERVED1;
    __IOM uint32_t GICR_WAKER;         /*!< \brief Offset: 0x0x0014 (R/W) Power Management Control Register */
    uint32_t       RESERVED2[2];
    __IOM uint32_t GICR_FCTLR;         /*!< \brief Offset: 0x0x0020 (R/W) Function Control Register */
    __IOM uint32_t GICR_PWRR;          /*!< \brief Offset: 0x0x0024 (R/W) Power Register */
    __IOM uint32_t GICR_CLASS;         /*!< \brief Offset: 0x0x0028 (R/W) Secure-only register */
    uint32_t       RESERVED3[17];
    __IOM uint64_t GICR_PROPBASER;     /*!< \brief Offset: 0x0x0070 (R/W) Redistributor Properties Base Address Register */
    __IOM uint64_t GICR_PENDBASER;     /*!< \brief Offset: 0x0x0078 (R/W) Redistributor LPI Pending Table Base Address Register */
    uint32_t       RESERVED4[16340];
    __IM uint32_t  GICR_PIDR4;         /*!< \brief Offset: 0x0xFFD0 (R/ ) Peripheral ID 4 Register */
    __IM uint32_t  GICR_PIDR5;         /*!< \brief Offset: 0x0xFFD4 (R/ ) Peripheral ID 5 Register */
    __IM uint32_t  GICR_PIDR6;         /*!< \brief Offset: 0x0xFFD8 (R/ ) Peripheral ID 6 Register */
    __IM uint32_t  GICR_PIDR7;         /*!< \brief Offset: 0x0xFFDC (R/ ) Peripheral ID 7 Register */
    __IM uint32_t  GICR_PIDR0;         /*!< \brief Offset: 0x0xFFE0 (R/ ) Peripheral ID 0 Register */
    __IM uint32_t  GICR_PIDR1;         /*!< \brief Offset: 0x0xFFE4 (R/ ) Peripheral ID 1 Register */
    __IM uint32_t  GICR_PIDR2;         /*!< \brief Offset: 0x0xFFE8 (R/ ) Peripheral ID 2 Register */
    __IM uint32_t  GICR_PIDR3;         /*!< \brief Offset: 0x0xFFEC (R/ ) Peripheral ID 3 Register */
    __IM uint32_t  GICR_CIDR0;         /*!< \brief Offset: 0x0xFFF0 (R/ ) Peripheral ID 0 Register */
    __IM uint32_t  GICR_CIDR1;         /*!< \brief Offset: 0x0xFFF4 (R/ ) Peripheral ID 1 Register */
    __IM uint32_t  GICR_CIDR2;         /*!< \brief Offset: 0x0xFFF8 (R/ ) Peripheral ID 2 Register */
    __IM uint32_t  GICR_CIDR3;         /*!< \brief Offset: 0x0xFFFC (R/ ) Peripheral ID 3 Register */
} GICR_CONTROL_TARGET_Type;

/**
 * \brief  Structure type to access the Generic Interrupt Controller (GIC) for GICR for SGI and PPI.
 */
typedef struct
{
    uint32_t       RESERVED1[32];
    __IOM uint32_t GICR_IGROUPR0;                                                                    /*!< \brief Offset: 0x0x0080 (R/W) Interrupt Group Register */
    uint32_t       RESERVED2[31];
    __IOM uint32_t GICR_ISENABLER0;                                                                  /*!< \brief Offset: 0x0x0100 (R/W) Interrupt Set-Enable Register */
    uint32_t       RESERVED3[31];
    __IOM uint32_t GICR_ICENABLER0;                                                                  /*!< \brief Offset: 0x0x0180 (R/W) Interrupt Clear-Enable Register */
    uint32_t       RESERVED4[31];
    __IOM uint32_t GICR_ISPENDR0;                                                                    /*!< \brief Offset: 0x0x0200 (R/W) Interrupt Set-Pending Register */
    uint32_t       RESERVED5[31];
    __IOM uint32_t GICR_ICPENDR0;                                                                    /*!< \brief Offset: 0x0x0280 (R/W) Peripheral Clear Pending Register */
    uint32_t       RESERVED6[31];
    __IOM uint32_t GICR_ISACTIVER0;                                                                  /*!< \brief Offset: 0x0x0300 (R/W) Interrupt Set-Active Register */
    uint32_t       RESERVED7[31];
    __IOM uint32_t GICR_ICACTIVER0;                                                                  /*!< \brief Offset: 0x0x0380 (R/W) Interrupt Clear-Active Register */
    uint32_t       RESERVED8[31];
    __IOM uint32_t GICR_IPRIORITYR[8];                                                               /*!< \brief Offset: 0x0x0400 (R/W) Interrupt Priority Registers */
    uint32_t       RESERVED9[504];
    __IOM uint32_t GICR_ICFGR[2];                                                                    /*!< \brief Offset: 0x0x0C00 (R/W) Interrupt Configuration Register */
    uint32_t       RESERVED10[62];
    __IOM uint32_t GICR_IGRPMODR0;                                                                   /*!< \brief Offset: 0x0x0D00 (R/W) Interrupt Group Modifier Register */
    uint32_t       RESERVED11[63];
    __IOM uint32_t GICR_NSACR;                                                                       /*!< \brief Offset: 0x0x0E00 (R/W) Non-secure Access Control Register */
    uint32_t       RESERVED12[11391];
    __IM uint32_t  GICR_MISCSTATUSR;                                                                 /*!< \brief Offset: 0x0xC000 (R/ ) Miscellaneous Status Register */
    uint32_t       RESERVED13;
    __IM uint32_t  GICR_IERRVR;                                                                      /*!< \brief Offset: 0x0xC008 (R/ ) Interrupt Error Valid Register */
    uint32_t       RESERVED14;
    __IOM uint64_t GICR_SGIDR;                                                                       /*!< \brief Offset: 0x0xC010 (R/W) SGI Default Register */
    uint32_t       RESERVED15[3066];
    __IM uint32_t  GICR_CFGID0;                                                                      /*!< \brief Offset: 0x0xF000 (R/ ) Configuration ID0 Register */
    __IM uint32_t  GICR_CFGID1;                                                                      /*!< \brief Offset: 0x0xF004 (R/ ) Configuration ID1 Register */
} GICR_SGI_PPI_Type;

/* Memory mapping of Core Hardware */
#define GIC0_BASE                    (0x83000000UL)                                                  /*!< GIC0 Base Address */
#define GICR_TARGET0_BASE            (0x00040000UL)                                                  /*!< GICR Base Address (for Control target 0) */
#define GICR_TARGET0_SGI_PPI_BASE    (0x00050000UL)                                                  /*!< GICR Base Address (for SGI and PPI target 0) */
#define GICR_TARGET1_BASE            (0x00060000UL)                                                  /*!< GICR Base Address (for Control target 1) */
#define GICR_TARGET1_SGI_PPI_BASE    (0x00070000UL)                                                  /*!< GICR Base Address (for SGI and PPI target 1) */
#define GICR_TARGET2_BASE            (0x00080000UL)                                                  /*!< GICR Base Address (for Control target 2) */
#define GICR_TARGET2_SGI_PPI_BASE    (0x00090000UL)                                                  /*!< GICR Base Address (for SGI and PPI target 2) */
#define GICR_TARGET3_BASE            (0x000A0000UL)                                                  /*!< GICR Base Address (for Control target 3) */
#define GICR_TARGET3_SGI_PPI_BASE    (0x000B0000UL)                                                  /*!< GICR Base Address (for SGI and PPI target 3) */

#define GICD0                        ((GICD_Type *) GIC0_BASE)                                       /*!< GICD configuration struct */
#define GICR0_TARGET0_IFREG          ((GICR_CONTROL_TARGET_Type *) (GIC0_BASE + GICR_TARGET0_BASE))  /*!< GICR configuration struct for Control target 0 */
#define GICR0_TARGET0_INTREG         ((GICR_SGI_PPI_Type *) (GIC0_BASE + GICR_TARGET0_SGI_PPI_BASE)) /*!< GICR configuration struct for SGI and PPI target 0 */
#define GICR0_TARGET1_IFREG          ((GICR_CONTROL_TARGET_Type *) (GIC0_BASE + GICR_TARGET1_BASE))  /*!< GICR configuration struct for Control target 1 */
#define GICR0_TARGET1_INTREG         ((GICR_SGI_PPI_Type *) (GIC0_BASE + GICR_TARGET1_SGI_PPI_BASE)) /*!< GICR configuration struct for SGI and PPI target 1 */
#define GICR0_TARGET2_IFREG          ((GICR_CONTROL_TARGET_Type *) (GIC0_BASE + GICR_TARGET2_BASE))  /*!< GICR configuration struct for Control target 2 */
#define GICR0_TARGET2_INTREG         ((GICR_SGI_PPI_Type *) (GIC0_BASE + GICR_TARGET2_SGI_PPI_BASE)) /*!< GICR configuration struct for SGI and PPI target 2 */
#define GICR0_TARGET3_IFREG          ((GICR_CONTROL_TARGET_Type *) (GIC0_BASE + GICR_TARGET3_BASE))  /*!< GICR configuration struct for Control target 3 */
#define GICR0_TARGET3_INTREG         ((GICR_SGI_PPI_Type *) (GIC0_BASE + GICR_TARGET3_SGI_PPI_BASE)) /*!< GICR configuration struct for SGI and PPI target 3 */

#endif /* __CORE_CA55_H_GENERIC */
