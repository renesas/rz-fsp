/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : vbattb_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for adc_c.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef VBATTB_IODEFINE_H
#define VBATTB_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t BKR;
        struct
        {
            __IOM uint32_t BKDAT : 32;
        } BKR_b;
    };
} R_VBATTB_BKR_Type;

typedef struct
{
    union
    {
        __IOM uint32_t BKPSR;
        struct
        {
            __IOM uint32_t VBTRSTF : 1;
            uint32_t               : 31;
        } BKPSR_b;
    };
    union
    {
        __IOM uint32_t TAMPSR;
        struct
        {
            __IOM uint32_t TAMP0F : 1;
            uint32_t              : 31;
        } TAMPSR_b;
    };
    union
    {
        __IOM uint32_t TAMPCR;
        struct
        {
            __IOM uint32_t TAMP0IE  : 1;
            uint32_t                : 3;
            __IOM uint32_t TAMP0EE  : 1;
            uint32_t                : 2;
            __IOM uint32_t TAMPCRWP : 1;
            uint32_t                : 24;
        } TAMPCR_b;
    };
    union
    {
        __IOM uint32_t TCECR;
        struct
        {
            __IOM uint32_t TCE0S : 1;
            uint32_t             : 31;
        } TCECR_b;
    };
    union
    {
        __IOM uint32_t TAMPICR1;
        struct
        {
            __IOM uint32_t CH0EN : 1;
            uint32_t             : 31;
        } TAMPICR1_b;
    };
    union
    {
        __IOM uint32_t TAMPICR2;
        struct
        {
            __IOM uint32_t CH0NFE : 1;
            uint32_t              : 3;
            __IOM uint32_t CH0TRG : 1;
            uint32_t              : 27;
        } TAMPICR2_b;
    };
    union
    {
        __IM uint32_t TAMPIMR;
        struct
        {
            __IM uint32_t CH0LV : 1;
            uint32_t            : 31;
        } TAMPIMR_b;
    };
    union
    {
        __IOM uint32_t BKSCCR;
        struct
        {
            uint32_t             : 6;
            __IOM uint32_t SOSEL : 1;
            uint32_t             : 25;
        } BKSCCR_b;
    };
    __IM uint8_t RESERVED[4];
    union
    {
        __IOM uint32_t SOSCCR2;
        struct
        {
            __IOM uint32_t SOSTP2 : 1;
            uint32_t              : 31;
        } SOSCCR2_b;
    };
    union
    {
        __IOM uint32_t ISOEN;
        struct
        {
            __IOM uint32_t ISOEN : 1;
            uint32_t             : 31;
        } ISOEN_b;
    };
    union
    {
        __IOM uint32_t ISOENPROT;
        struct
        {
            __IOM uint32_t WRPOT : 32;
        } ISOENPROT_b;
    };
    union
    {
        __IOM uint32_t XOSCCR;
        struct
        {
            __IOM uint32_t XSEL  : 2;
            uint32_t             : 14;
            __IOM uint32_t OUTEN : 1;
            uint32_t             : 15;
        } XOSCCR_b;
    };
    __IM uint8_t RESERVED1[12];
    union
    {
        __IOM uint32_t EXTINTCR;
        struct
        {
            __IOM uint32_t OUTENABLE   : 1;
            __IOM uint32_t EXTINTREGWP : 1;
            uint32_t                   : 6;
            __IOM uint32_t DRVLVL      : 2;
            uint32_t                   : 22;
        } EXTINTCR_b;
    };
    union
    {
        __IOM uint32_t EXTINTATR;
        struct
        {
            __IOM uint32_t SIGTYPE    : 1;
            __IOM uint32_t ACTVLVL    : 1;
            uint32_t                  : 6;
            __IOM uint32_t PULSEWIDTH : 8;
            uint32_t                  : 16;
        } EXTINTATR_b;
    };
    union
    {
        __IOM uint32_t EXTINTSEL1;
        struct
        {
            __IOM uint32_t RTCINTSEL : 7;
            uint32_t                 : 25;
        } EXTINTSEL1_b;
    };
    union
    {
        __IOM uint32_t EXTINTSEL2;
        struct
        {
            __IOM uint32_t TAMPINTSEL : 1;
            uint32_t                  : 31;
        } EXTINTSEL2_b;
    };
    union
    {
        __IOM uint32_t EXTINTSR1;
        struct
        {
            __IOM uint32_t RTCINTSR : 7;
            uint32_t                : 25;
        } EXTINTSR1_b;
    };
    union
    {
        __IM uint32_t EXTINTSR2;
        struct
        {
            __IM uint32_t TAMPINTSR : 1;
            uint32_t                : 31;
        } EXTINTSR2_b;
    };
    __IM uint8_t RESERVED2[32];
    union
    {
        __IOM uint32_t ZEROIZCR;
        struct
        {
            __IOM uint32_t ZEROIZCR : 1;
            uint32_t                : 31;
        } ZEROIZCR_b;
    };
    union
    {
        __IM uint32_t ZEROIZSR;
        struct
        {
            __IM uint32_t ZEROIZSR : 16;
            uint32_t               : 16;
        } ZEROIZSR_b;
    };

    __IOM R_VBATTB_BKR_Type BKR[32];
} R_VBATTB_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_VBATTB_BASE    0x4005C000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_VBATTB    ((R_VBATTB_Type *) R_VBATTB_BASE)

#endif
