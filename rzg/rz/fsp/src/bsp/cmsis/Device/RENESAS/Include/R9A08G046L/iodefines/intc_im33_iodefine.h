/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : intc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for intc.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef INTC_IM33_IODEFINE_H
#define INTC_IM33_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t NSCR;
        struct
        {
            __IOM uint32_t NSTAT : 1;
            uint32_t             : 15;
            __IM uint32_t NSMON  : 1;
            uint32_t             : 15;
        } NSCR_b;
    };
    union
    {
        __IOM uint32_t NITSR;
        struct
        {
            __IOM uint32_t NTSEL : 1;
            uint32_t             : 31;
        } NITSR_b;
    };
    __IM uint8_t RESERVED[8];
    union
    {
        __IOM uint32_t ISCR;
        struct
        {
            __IOM uint32_t ISTAT0  : 1;
            __IOM uint32_t ISTAT1  : 1;
            __IOM uint32_t ISTAT2  : 1;
            __IOM uint32_t ISTAT3  : 1;
            __IOM uint32_t ISTAT4  : 1;
            __IOM uint32_t ISTAT5  : 1;
            __IOM uint32_t ISTAT6  : 1;
            __IOM uint32_t ISTAT7  : 1;
            __IOM uint32_t ISTAT8  : 1;
            __IOM uint32_t ISTAT9  : 1;
            __IOM uint32_t ISTAT10 : 1;
            __IOM uint32_t ISTAT11 : 1;
            __IOM uint32_t ISTAT12 : 1;
            __IOM uint32_t ISTAT13 : 1;
            __IOM uint32_t ISTAT14 : 1;
            __IOM uint32_t ISTAT15 : 1;
            uint32_t               : 16;
        } ISCR_b;
    };
    union
    {
        __IOM uint32_t IITSR;
        struct
        {
            __IOM uint32_t IITSEL0  : 2;
            __IOM uint32_t IITSEL1  : 2;
            __IOM uint32_t IITSEL2  : 2;
            __IOM uint32_t IITSEL3  : 2;
            __IOM uint32_t IITSEL4  : 2;
            __IOM uint32_t IITSEL5  : 2;
            __IOM uint32_t IITSEL6  : 2;
            __IOM uint32_t IITSEL7  : 2;
            __IOM uint32_t IITSEL8  : 2;
            __IOM uint32_t IITSEL9  : 2;
            __IOM uint32_t IITSEL10 : 2;
            __IOM uint32_t IITSEL11 : 2;
            __IOM uint32_t IITSEL12 : 2;
            __IOM uint32_t IITSEL13 : 2;
            __IOM uint32_t IITSEL14 : 2;
            __IOM uint32_t IITSEL15 : 2;
        } IITSR_b;
    };
    __IM uint8_t RESERVED1[8];
    union
    {
        __IOM uint32_t TSCR;
        struct
        {
            __IOM uint32_t TSTAT0  : 1;
            __IOM uint32_t TSTAT1  : 1;
            __IOM uint32_t TSTAT2  : 1;
            __IOM uint32_t TSTAT3  : 1;
            __IOM uint32_t TSTAT4  : 1;
            __IOM uint32_t TSTAT5  : 1;
            __IOM uint32_t TSTAT6  : 1;
            __IOM uint32_t TSTAT7  : 1;
            __IOM uint32_t TSTAT8  : 1;
            __IOM uint32_t TSTAT9  : 1;
            __IOM uint32_t TSTAT10 : 1;
            __IOM uint32_t TSTAT11 : 1;
            __IOM uint32_t TSTAT12 : 1;
            __IOM uint32_t TSTAT13 : 1;
            __IOM uint32_t TSTAT14 : 1;
            __IOM uint32_t TSTAT15 : 1;
            __IOM uint32_t TSTAT16 : 1;
            __IOM uint32_t TSTAT17 : 1;
            __IOM uint32_t TSTAT18 : 1;
            __IOM uint32_t TSTAT19 : 1;
            __IOM uint32_t TSTAT20 : 1;
            __IOM uint32_t TSTAT21 : 1;
            __IOM uint32_t TSTAT22 : 1;
            __IOM uint32_t TSTAT23 : 1;
            __IOM uint32_t TSTAT24 : 1;
            __IOM uint32_t TSTAT25 : 1;
            __IOM uint32_t TSTAT26 : 1;
            __IOM uint32_t TSTAT27 : 1;
            __IOM uint32_t TSTAT28 : 1;
            __IOM uint32_t TSTAT29 : 1;
            __IOM uint32_t TSTAT30 : 1;
            __IOM uint32_t TSTAT31 : 1;
        } TSCR_b;
    };
    union
    {
        __IOM uint32_t TITSR0;
        struct
        {
            __IOM uint32_t TITSEL0  : 2;
            __IOM uint32_t TITSEL1  : 2;
            __IOM uint32_t TITSEL2  : 2;
            __IOM uint32_t TITSEL3  : 2;
            __IOM uint32_t TITSEL4  : 2;
            __IOM uint32_t TITSEL5  : 2;
            __IOM uint32_t TITSEL6  : 2;
            __IOM uint32_t TITSEL7  : 2;
            __IOM uint32_t TITSEL8  : 2;
            __IOM uint32_t TITSEL9  : 2;
            __IOM uint32_t TITSEL10 : 2;
            __IOM uint32_t TITSEL11 : 2;
            __IOM uint32_t TITSEL12 : 2;
            __IOM uint32_t TITSEL13 : 2;
            __IOM uint32_t TITSEL14 : 2;
            __IOM uint32_t TITSEL15 : 2;
        } TITSR0_b;
    };
    union
    {
        __IOM uint32_t TITSR1;
        struct
        {
            __IOM uint32_t TITSEL16 : 2;
            __IOM uint32_t TITSEL17 : 2;
            __IOM uint32_t TITSEL18 : 2;
            __IOM uint32_t TITSEL19 : 2;
            __IOM uint32_t TITSEL20 : 2;
            __IOM uint32_t TITSEL21 : 2;
            __IOM uint32_t TITSEL22 : 2;
            __IOM uint32_t TITSEL23 : 2;
            __IOM uint32_t TITSEL24 : 2;
            __IOM uint32_t TITSEL25 : 2;
            __IOM uint32_t TITSEL26 : 2;
            __IOM uint32_t TITSEL27 : 2;
            __IOM uint32_t TITSEL28 : 2;
            __IOM uint32_t TITSEL29 : 2;
            __IOM uint32_t TITSEL30 : 2;
            __IOM uint32_t TITSEL31 : 2;
        } TITSR1_b;
    };
    union
    {
        __IOM uint32_t INTTSEL;
        struct
        {
            uint32_t                 : 4;
            __IOM uint32_t TINTSEL4  : 1;
            __IOM uint32_t TINTSEL5  : 1;
            __IOM uint32_t TINTSEL6  : 1;
            __IOM uint32_t TINTSEL7  : 1;
            __IOM uint32_t TINTSEL8  : 1;
            __IOM uint32_t TINTSEL9  : 1;
            __IOM uint32_t TINTSEL10 : 1;
            __IOM uint32_t TINTSEL11 : 1;
            __IOM uint32_t TINTSEL12 : 1;
            __IOM uint32_t TINTSEL13 : 1;
            __IOM uint32_t TINTSEL14 : 1;
            __IOM uint32_t TINTSEL15 : 1;
            __IOM uint32_t TINTSEL16 : 1;
            __IOM uint32_t TINTSEL17 : 1;
            __IOM uint32_t TINTSEL18 : 1;
            __IOM uint32_t TINTSEL19 : 1;
            __IOM uint32_t TINTSEL20 : 1;
            __IOM uint32_t TINTSEL21 : 1;
            __IOM uint32_t TINTSEL22 : 1;
            __IOM uint32_t TINTSEL23 : 1;
            __IOM uint32_t TINTSEL24 : 1;
            __IOM uint32_t TINTSEL25 : 1;
            __IOM uint32_t TINTSEL26 : 1;
            __IOM uint32_t TINTSEL27 : 1;
            __IOM uint32_t TINTSEL28 : 1;
            __IOM uint32_t TINTSEL29 : 1;
            __IOM uint32_t TINTSEL30 : 1;
            __IOM uint32_t TINTSEL31 : 1;
        } INTTSEL_b;
    };
    union
    {
        __IOM uint32_t TSSR0;
        struct
        {
            __IOM uint32_t TSSEL0 : 7;
            __IOM uint32_t TIEN0  : 1;
            __IOM uint32_t TSSEL1 : 7;
            __IOM uint32_t TIEN1  : 1;
            __IOM uint32_t TSSEL2 : 7;
            __IOM uint32_t TIEN2  : 1;
            __IOM uint32_t TSSEL3 : 7;
            __IOM uint32_t TIEN3  : 1;
        } TSSR0_b;
    };
    union
    {
        __IOM uint32_t TSSR1;
        struct
        {
            __IOM uint32_t TSSEL4 : 7;
            __IOM uint32_t TIEN4  : 1;
            __IOM uint32_t TSSEL5 : 7;
            __IOM uint32_t TIEN5  : 1;
            __IOM uint32_t TSSEL6 : 7;
            __IOM uint32_t TIEN6  : 1;
            __IOM uint32_t TSSEL7 : 7;
            __IOM uint32_t TIEN7  : 1;
        } TSSR1_b;
    };
    union
    {
        __IOM uint32_t TSSR2;
        struct
        {
            __IOM uint32_t TSSEL8  : 7;
            __IOM uint32_t TIEN8   : 1;
            __IOM uint32_t TSSEL9  : 7;
            __IOM uint32_t TIEN9   : 1;
            __IOM uint32_t TSSEL10 : 7;
            __IOM uint32_t TIEN10  : 1;
            __IOM uint32_t TSSEL11 : 7;
            __IOM uint32_t TIEN11  : 1;
        } TSSR2_b;
    };
    union
    {
        __IOM uint32_t TSSR3;
        struct
        {
            __IOM uint32_t TSSEL12 : 7;
            __IOM uint32_t TIEN12  : 1;
            __IOM uint32_t TSSEL13 : 7;
            __IOM uint32_t TIEN13  : 1;
            __IOM uint32_t TSSEL14 : 7;
            __IOM uint32_t TIEN14  : 1;
            __IOM uint32_t TSSEL15 : 7;
            __IOM uint32_t TIEN15  : 1;
        } TSSR3_b;
    };
    union
    {
        __IOM uint32_t TSSR4;
        struct
        {
            __IOM uint32_t TSSEL16 : 7;
            __IOM uint32_t TIEN16  : 1;
            __IOM uint32_t TSSEL17 : 7;
            __IOM uint32_t TIEN17  : 1;
            __IOM uint32_t TSSEL18 : 7;
            __IOM uint32_t TIEN18  : 1;
            __IOM uint32_t TSSEL19 : 7;
            __IOM uint32_t TIEN19  : 1;
        } TSSR4_b;
    };
    union
    {
        __IOM uint32_t TSSR5;
        struct
        {
            __IOM uint32_t TSSEL20 : 7;
            __IOM uint32_t TIEN20  : 1;
            __IOM uint32_t TSSEL21 : 7;
            __IOM uint32_t TIEN21  : 1;
            __IOM uint32_t TSSEL22 : 7;
            __IOM uint32_t TIEN22  : 1;
            __IOM uint32_t TSSEL23 : 7;
            __IOM uint32_t TIEN23  : 1;
        } TSSR5_b;
    };
    union
    {
        __IOM uint32_t TSSR6;
        struct
        {
            __IOM uint32_t TSSEL24 : 7;
            __IOM uint32_t TIEN24  : 1;
            __IOM uint32_t TSSEL25 : 7;
            __IOM uint32_t TIEN25  : 1;
            __IOM uint32_t TSSEL26 : 7;
            __IOM uint32_t TIEN26  : 1;
            __IOM uint32_t TSSEL27 : 7;
            __IOM uint32_t TIEN27  : 1;
        } TSSR6_b;
    };
    union
    {
        __IOM uint32_t TSSR7;
        struct
        {
            __IOM uint32_t TSSEL28 : 7;
            __IOM uint32_t TIEN28  : 1;
            __IOM uint32_t TSSEL29 : 7;
            __IOM uint32_t TIEN29  : 1;
            __IOM uint32_t TSSEL30 : 7;
            __IOM uint32_t TIEN30  : 1;
            __IOM uint32_t TSSEL31 : 7;
            __IOM uint32_t TIEN31  : 1;
        } TSSR7_b;
    };
    union
    {
        __IOM uint32_t BEISR0;
        struct
        {
            __IOM uint32_t BESTAT0  : 1;
            __IOM uint32_t BESTAT1  : 1;
            __IOM uint32_t BESTAT2  : 1;
            __IOM uint32_t BESTAT3  : 1;
            __IOM uint32_t BESTAT4  : 1;
            __IOM uint32_t BESTAT5  : 1;
            __IOM uint32_t BESTAT6  : 1;
            __IOM uint32_t BESTAT7  : 1;
            __IOM uint32_t BESTAT8  : 1;
            __IOM uint32_t BESTAT9  : 1;
            __IOM uint32_t BESTAT10 : 1;
            __IOM uint32_t BESTAT11 : 1;
            __IOM uint32_t BESTAT12 : 1;
            __IOM uint32_t BESTAT13 : 1;
            __IOM uint32_t BESTAT14 : 1;
            __IOM uint32_t BESTAT15 : 1;
            __IOM uint32_t BESTAT16 : 1;
            __IOM uint32_t BESTAT17 : 1;
            __IOM uint32_t BESTAT18 : 1;
            __IOM uint32_t BESTAT19 : 1;
            __IOM uint32_t BESTAT20 : 1;
            __IOM uint32_t BESTAT21 : 1;
            __IOM uint32_t BESTAT22 : 1;
            __IOM uint32_t BESTAT23 : 1;
            __IOM uint32_t BESTAT24 : 1;
            __IOM uint32_t BESTAT25 : 1;
            __IOM uint32_t BESTAT26 : 1;
            __IOM uint32_t BESTAT27 : 1;
            __IOM uint32_t BESTAT28 : 1;
            __IOM uint32_t BESTAT29 : 1;
            __IOM uint32_t BESTAT30 : 1;
            __IOM uint32_t BESTAT31 : 1;
        } BEISR0_b;
    };
    union
    {
        __IOM uint32_t BEISR1;
        struct
        {
            __IOM uint32_t BESTAT32 : 1;
            __IOM uint32_t BESTAT33 : 1;
            __IOM uint32_t BESTAT34 : 1;
            __IOM uint32_t BESTAT35 : 1;
            __IOM uint32_t BESTAT36 : 1;
            __IOM uint32_t BESTAT37 : 1;
            __IOM uint32_t BESTAT38 : 1;
            __IOM uint32_t BESTAT39 : 1;
            __IOM uint32_t BESTAT40 : 1;
            __IOM uint32_t BESTAT41 : 1;
            __IOM uint32_t BESTAT42 : 1;
            __IOM uint32_t BESTAT43 : 1;
            __IOM uint32_t BESTAT44 : 1;
            __IOM uint32_t BESTAT45 : 1;
            __IOM uint32_t BESTAT46 : 1;
            __IOM uint32_t BESTAT47 : 1;
            __IOM uint32_t BESTAT48 : 1;
            __IOM uint32_t BESTAT49 : 1;
            __IOM uint32_t BESTAT50 : 1;
            __IOM uint32_t BESTAT51 : 1;
            __IOM uint32_t BESTAT52 : 1;
            __IOM uint32_t BESTAT53 : 1;
            __IOM uint32_t BESTAT54 : 1;
            __IOM uint32_t BESTAT55 : 1;
            __IOM uint32_t BESTAT56 : 1;
            __IOM uint32_t BESTAT57 : 1;
            uint32_t                : 6;
        } BEISR1_b;
    };
    __IM uint8_t RESERVED2[8];
    union
    {
        __IOM uint32_t EREISR0;
        struct
        {
            __IOM uint32_t A01ESTAT0 : 1;
            __IOM uint32_t A01ESTAT1 : 1;
            __IOM uint32_t A01ESTAT2 : 1;
            __IOM uint32_t A01ESTAT3 : 1;
            __IOM uint32_t A01ESTAT4 : 1;
            __IOM uint32_t A01ESTAT5 : 1;
            __IOM uint32_t A01ESTAT6 : 1;
            __IOM uint32_t A01ESTAT7 : 1;
            uint32_t                 : 24;
        } EREISR0_b;
    };
    union
    {
        __IOM uint32_t EREISR1;
        struct
        {
            __IOM uint32_t M01ESTAT0 : 1;
            __IOM uint32_t M01ESTAT1 : 1;
            __IOM uint32_t M01ESTAT2 : 1;
            __IOM uint32_t M01ESTAT3 : 1;
            __IOM uint32_t M01ESTAT4 : 1;
            __IOM uint32_t M01ESTAT5 : 1;
            __IOM uint32_t M01ESTAT6 : 1;
            __IOM uint32_t M01ESTAT7 : 1;
            uint32_t                 : 24;
        } EREISR1_b;
    };
    union
    {
        __IOM uint32_t EREISR2;
        struct
        {
            __IOM uint32_t A02ESTAT0 : 1;
            __IOM uint32_t A02ESTAT1 : 1;
            __IOM uint32_t A02ESTAT2 : 1;
            __IOM uint32_t A02ESTAT3 : 1;
            __IOM uint32_t A02ESTAT4 : 1;
            __IOM uint32_t A02ESTAT5 : 1;
            __IOM uint32_t A02ESTAT6 : 1;
            __IOM uint32_t A02ESTAT7 : 1;
            uint32_t                 : 24;
        } EREISR2_b;
    };
    union
    {
        __IOM uint32_t EREISR3;
        struct
        {
            __IOM uint32_t M02ESTAT0 : 1;
            __IOM uint32_t M02ESTAT1 : 1;
            __IOM uint32_t M02ESTAT2 : 1;
            __IOM uint32_t M02ESTAT3 : 1;
            __IOM uint32_t M02ESTAT4 : 1;
            __IOM uint32_t M02ESTAT5 : 1;
            __IOM uint32_t M02ESTAT6 : 1;
            __IOM uint32_t M02ESTAT7 : 1;
            uint32_t                 : 24;
        } EREISR3_b;
    };
    union
    {
        __IOM uint32_t EREISR4;
        struct
        {
            __IOM uint32_t A0OFSTAT0 : 1;
            __IOM uint32_t A0OFSTAT1 : 1;
            __IOM uint32_t A0OFSTAT2 : 1;
            __IOM uint32_t A0OFSTAT3 : 1;
            __IOM uint32_t A0OFSTAT4 : 1;
            __IOM uint32_t A0OFSTAT5 : 1;
            __IOM uint32_t A0OFSTAT6 : 1;
            __IOM uint32_t A0OFSTAT7 : 1;
            uint32_t                 : 24;
        } EREISR4_b;
    };
    union
    {
        __IOM uint32_t EREISR5;
        struct
        {
            __IOM uint32_t M0OFSTAT0 : 1;
            __IOM uint32_t M0OFSTAT1 : 1;
            __IOM uint32_t M0OFSTAT2 : 1;
            __IOM uint32_t M0OFSTAT3 : 1;
            __IOM uint32_t M0OFSTAT4 : 1;
            __IOM uint32_t M0OFSTAT5 : 1;
            __IOM uint32_t M0OFSTAT6 : 1;
            __IOM uint32_t M0OFSTAT7 : 1;
            uint32_t                 : 24;
        } EREISR5_b;
    };
    __IM uint8_t RESERVED3[8];
    union
    {
        __IOM uint32_t INTPMSEL0;
        struct
        {
            __IOM uint32_t PMINTSEL0  : 1;
            __IOM uint32_t PMINTSEL1  : 1;
            __IOM uint32_t PMINTSEL2  : 1;
            __IOM uint32_t PMINTSEL3  : 1;
            __IOM uint32_t PMINTSEL4  : 1;
            __IOM uint32_t PMINTSEL5  : 1;
            __IOM uint32_t PMINTSEL6  : 1;
            __IOM uint32_t PMINTSEL7  : 1;
            __IOM uint32_t PMINTSEL8  : 1;
            __IOM uint32_t PMINTSEL9  : 1;
            __IOM uint32_t PMINTSEL10 : 1;
            __IOM uint32_t PMINTSEL11 : 1;
            __IOM uint32_t PMINTSEL12 : 1;
            __IOM uint32_t PMINTSEL13 : 1;
            __IOM uint32_t PMINTSEL14 : 1;
            __IOM uint32_t PMINTSEL15 : 1;
            __IOM uint32_t PMINTSEL16 : 1;
            __IOM uint32_t PMINTSEL17 : 1;
            __IOM uint32_t PMINTSEL18 : 1;
            __IOM uint32_t PMINTSEL19 : 1;
            __IOM uint32_t PMINTSEL20 : 1;
            __IOM uint32_t PMINTSEL21 : 1;
            __IOM uint32_t PMINTSEL22 : 1;
            __IOM uint32_t PMINTSEL23 : 1;
            __IOM uint32_t PMINTSEL24 : 1;
            __IOM uint32_t PMINTSEL25 : 1;
            __IOM uint32_t PMINTSEL26 : 1;
            __IOM uint32_t PMINTSEL27 : 1;
            __IOM uint32_t PMINTSEL28 : 1;
            __IOM uint32_t PMINTSEL29 : 1;
            __IOM uint32_t PMINTSEL30 : 1;
            __IOM uint32_t PMINTSEL31 : 1;
        } INTPMSEL0_b;
    };
    union
    {
        __IOM uint32_t INTPMSEL1;
        struct
        {
            __IOM uint32_t PMINTSEL32 : 1;
            __IOM uint32_t PMINTSEL33 : 1;
            __IOM uint32_t PMINTSEL34 : 1;
            __IOM uint32_t PMINTSEL35 : 1;
            __IOM uint32_t PMINTSEL36 : 1;
            __IOM uint32_t PMINTSEL37 : 1;
            __IOM uint32_t PMINTSEL38 : 1;
            __IOM uint32_t PMINTSEL39 : 1;
            __IOM uint32_t PMINTSEL40 : 1;
            __IOM uint32_t PMINTSEL41 : 1;
            __IOM uint32_t PMINTSEL42 : 1;
            __IOM uint32_t PMINTSEL43 : 1;
            uint32_t                  : 20;
        } INTPMSEL1_b;
    };
    union
    {
        __IOM uint32_t PEISR;
        struct
        {
            __IOM uint32_t PEVSTAT0 : 1;
            __IOM uint32_t PEVSTAT1 : 1;
            __IOM uint32_t PEVSTAT2 : 1;
            __IOM uint32_t PEVSTAT3 : 1;
            __IOM uint32_t PEVSTAT4 : 1;
            __IOM uint32_t PEVSTAT5 : 1;
            __IOM uint32_t PEVSTAT6 : 1;
            __IOM uint32_t PEVSTAT7 : 1;
            uint32_t                : 8;
            __IOM uint32_t PEUSTAT0 : 1;
            __IOM uint32_t PEUSTAT1 : 1;
            __IOM uint32_t PEUSTAT2 : 1;
            __IOM uint32_t PEUSTAT3 : 1;
            __IOM uint32_t PEUSTAT4 : 1;
            __IOM uint32_t PEUSTAT5 : 1;
            __IOM uint32_t PEUSTAT6 : 1;
            __IOM uint32_t PEUSTAT7 : 1;
            uint32_t                : 8;
        } PEISR_b;
    };
    __IM uint8_t RESERVED4[20];
    union
    {
        __IOM uint32_t MISR4;
        struct
        {
            __IOM uint32_t MMNSSTAT3  : 1;
            __IOM uint32_t MMNSSTAT7  : 1;
            __IOM uint32_t MMNSSTAT11 : 1;
            __IOM uint32_t MMNSSTAT15 : 1;
            uint32_t                  : 4;
            __IOM uint32_t MRNSSTAT16 : 1;
            __IOM uint32_t MRNSSTAT17 : 1;
            __IOM uint32_t MRNSSTAT18 : 1;
            __IOM uint32_t MRNSSTAT19 : 1;
            uint32_t                  : 4;
            __IOM uint32_t MMSSTAT3   : 1;
            __IOM uint32_t MMSSTAT7   : 1;
            __IOM uint32_t MMSSTAT11  : 1;
            __IOM uint32_t MMSSTAT15  : 1;
            uint32_t                  : 4;
            __IOM uint32_t MRSSTAT16  : 1;
            __IOM uint32_t MRSSTAT17  : 1;
            __IOM uint32_t MRSSTAT18  : 1;
            __IOM uint32_t MRSSTAT19  : 1;
            uint32_t                  : 4;
        } MISR4_b;
    };
    __IM uint8_t RESERVED5[12];
    union
    {
        __IOM uint32_t SWISR;
        struct
        {
            __IOM uint32_t SWSTAT0 : 1;
            __IOM uint32_t SWSTAT1 : 1;
            __IOM uint32_t SWSTAT2 : 1;
            __IOM uint32_t SWSTAT3 : 1;
            uint32_t               : 28;
        } SWISR_b;
    };
} R_INTC_IM33_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_INTC_IM33_BASE    0x41060000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_INTC_IM33    ((R_INTC_IM33_Type *) R_INTC_IM33_BASE)

#endif
