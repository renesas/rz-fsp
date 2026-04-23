/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : gpio_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for gpio.
 *********************************************************************************************************************/

/* =========================================================================================================================== */
/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef GPIO_IODEFINE_H
#define GPIO_IODEFINE_H

typedef struct
{
    __IM uint8_t RESERVED[34];
    union
    {
        __IOM uint8_t P_22;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P_22_b;
    };
    union
    {
        __IOM uint8_t P_23;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            uint8_t          : 1;
        } P_23_b;
    };
    __IM uint8_t RESERVED1[1];
    union
    {
        __IOM uint8_t P_25;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            uint8_t          : 1;
        } P_25_b;
    };
    union
    {
        __IOM uint8_t P_26;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            uint8_t          : 1;
        } P_26_b;
    };
    union
    {
        __IOM uint8_t P_27;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_27_b;
    };
    union
    {
        __IOM uint8_t P_28;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P_28_b;
    };
    __IM uint8_t RESERVED2[1];
    union
    {
        __IOM uint8_t P_2A;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_2A_b;
    };
    union
    {
        __IOM uint8_t P_2B;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_2B_b;
    };
    union
    {
        __IOM uint8_t P_2C;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            uint8_t          : 5;
        } P_2C_b;
    };
    union
    {
        __IOM uint8_t P_2D;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_2D_b;
    };
    union
    {
        __IOM uint8_t P_2E;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_2E_b;
    };
    union
    {
        __IOM uint8_t P_2F;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            uint8_t          : 5;
        } P_2F_b;
    };
    union
    {
        __IOM uint8_t P_30;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_30_b;
    };
    union
    {
        __IOM uint8_t P_31;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            uint8_t          : 2;
        } P_31_b;
    };
    __IM uint8_t RESERVED3[1];
    union
    {
        __IOM uint8_t P_33;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_33_b;
    };
    union
    {
        __IOM uint8_t P_34;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            uint8_t          : 4;
        } P_34_b;
    };
    union
    {
        __IOM uint8_t P_35;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            uint8_t          : 3;
        } P_35_b;
    };
    union
    {
        __IOM uint8_t P_36;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            __IOM uint8_t P2 : 1;
            __IOM uint8_t P3 : 1;
            __IOM uint8_t P4 : 1;
            __IOM uint8_t P5 : 1;
            __IOM uint8_t P6 : 1;
            __IOM uint8_t P7 : 1;
        } P_36_b;
    };
    __IM uint8_t RESERVED4[5];
    union
    {
        __IOM uint8_t P_3C;
        struct
        {
            __IOM uint8_t P0 : 1;
            __IOM uint8_t P1 : 1;
            uint8_t          : 6;
        } P_3C_b;
    };
    __IM uint8_t RESERVED5[263];
    union
    {
        __IOM uint16_t PM_22;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_22_byte;
        struct
        {
            __IOM uint8_t PM22_0 : 2;
            __IOM uint8_t PM22_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM_22_b;
    };
    union
    {
        __IOM uint16_t PM_23;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_23_byte;
        struct
        {
            __IOM uint8_t PM23_0 : 2;
            __IOM uint8_t PM23_1 : 2;
            __IOM uint8_t PM23_2 : 2;
            __IOM uint8_t PM23_3 : 2;
            __IOM uint8_t PM23_4 : 2;
            __IOM uint8_t PM23_5 : 2;
            __IOM uint8_t PM23_6 : 2;
            uint8_t              : 2;
        } PM_23_b;
    };
    __IM uint8_t RESERVED6[2];
    union
    {
        __IOM uint16_t PM_25;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_25_byte;
        struct
        {
            __IOM uint8_t PM25_0 : 2;
            __IOM uint8_t PM25_1 : 2;
            __IOM uint8_t PM25_2 : 2;
            __IOM uint8_t PM25_3 : 2;
            __IOM uint8_t PM25_4 : 2;
            __IOM uint8_t PM25_5 : 2;
            __IOM uint8_t PM25_6 : 2;
            uint8_t              : 2;
        } PM_25_b;
    };
    union
    {
        __IOM uint16_t PM_26;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_26_byte;
        struct
        {
            __IOM uint8_t PM26_0 : 2;
            __IOM uint8_t PM26_1 : 2;
            __IOM uint8_t PM26_2 : 2;
            __IOM uint8_t PM26_3 : 2;
            __IOM uint8_t PM26_4 : 2;
            __IOM uint8_t PM26_5 : 2;
            __IOM uint8_t PM26_6 : 2;
            uint8_t              : 2;
        } PM_26_b;
    };
    union
    {
        __IOM uint16_t PM_27;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_27_byte;
        struct
        {
            __IOM uint8_t PM27_0 : 2;
            __IOM uint8_t PM27_1 : 2;
            __IOM uint8_t PM27_2 : 2;
            __IOM uint8_t PM27_3 : 2;
            __IOM uint8_t PM27_4 : 2;
            __IOM uint8_t PM27_5 : 2;
            __IOM uint8_t PM27_6 : 2;
            __IOM uint8_t PM27_7 : 2;
        } PM_27_b;
    };
    union
    {
        __IOM uint16_t PM_28;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_28_byte;
        struct
        {
            __IOM uint8_t PM28_0 : 2;
            __IOM uint8_t PM28_1 : 2;
            __IOM uint8_t PM28_2 : 2;
            __IOM uint8_t PM28_3 : 2;
            __IOM uint8_t PM28_4 : 2;
            __IOM uint8_t PM28_5 : 2;
            uint8_t              : 4;
        } PM_28_b;
    };
    __IM uint8_t RESERVED7[2];
    union
    {
        __IOM uint16_t PM_2A;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2A_byte;
        struct
        {
            __IOM uint8_t PM2A_0 : 2;
            __IOM uint8_t PM2A_1 : 2;
            __IOM uint8_t PM2A_2 : 2;
            __IOM uint8_t PM2A_3 : 2;
            __IOM uint8_t PM2A_4 : 2;
            __IOM uint8_t PM2A_5 : 2;
            __IOM uint8_t PM2A_6 : 2;
            __IOM uint8_t PM2A_7 : 2;
        } PM_2A_b;
    };
    union
    {
        __IOM uint16_t PM_2B;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2B_byte;
        struct
        {
            __IOM uint8_t PM2B_0 : 2;
            __IOM uint8_t PM2B_1 : 2;
            __IOM uint8_t PM2B_2 : 2;
            __IOM uint8_t PM2B_3 : 2;
            __IOM uint8_t PM2B_4 : 2;
            __IOM uint8_t PM2B_5 : 2;
            __IOM uint8_t PM2B_6 : 2;
            __IOM uint8_t PM2B_7 : 2;
        } PM_2B_b;
    };
    union
    {
        __IOM uint16_t PM_2C;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2C_byte;
        struct
        {
            __IOM uint8_t PM2C_0 : 2;
            __IOM uint8_t PM2C_1 : 2;
            __IOM uint8_t PM2C_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_2C_b;
    };
    union
    {
        __IOM uint16_t PM_2D;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2D_byte;
        struct
        {
            __IOM uint8_t PM2D_0 : 2;
            __IOM uint8_t PM2D_1 : 2;
            __IOM uint8_t PM2D_2 : 2;
            __IOM uint8_t PM2D_3 : 2;
            __IOM uint8_t PM2D_4 : 2;
            __IOM uint8_t PM2D_5 : 2;
            __IOM uint8_t PM2D_6 : 2;
            __IOM uint8_t PM2D_7 : 2;
        } PM_2D_b;
    };
    union
    {
        __IOM uint16_t PM_2E;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2E_byte;
        struct
        {
            __IOM uint8_t PM2E_0 : 2;
            __IOM uint8_t PM2E_1 : 2;
            __IOM uint8_t PM2E_2 : 2;
            __IOM uint8_t PM2E_3 : 2;
            __IOM uint8_t PM2E_4 : 2;
            __IOM uint8_t PM2E_5 : 2;
            __IOM uint8_t PM2E_6 : 2;
            __IOM uint8_t PM2E_7 : 2;
        } PM_2E_b;
    };
    union
    {
        __IOM uint16_t PM_2F;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_2F_byte;
        struct
        {
            __IOM uint8_t PM2F_0 : 2;
            __IOM uint8_t PM2F_1 : 2;
            __IOM uint8_t PM2F_2 : 2;
            uint8_t              : 2;
            uint8_t              : 8;
        } PM_2F_b;
    };
    union
    {
        __IOM uint16_t PM_30;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_30_byte;
        struct
        {
            __IOM uint8_t PM30_0 : 2;
            __IOM uint8_t PM30_1 : 2;
            __IOM uint8_t PM30_2 : 2;
            __IOM uint8_t PM30_3 : 2;
            __IOM uint8_t PM30_4 : 2;
            __IOM uint8_t PM30_5 : 2;
            __IOM uint8_t PM30_6 : 2;
            __IOM uint8_t PM30_7 : 2;
        } PM_30_b;
    };
    union
    {
        __IOM uint16_t PM_31;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_31_byte;
        struct
        {
            __IOM uint8_t PM31_0 : 2;
            __IOM uint8_t PM31_1 : 2;
            __IOM uint8_t PM31_2 : 2;
            __IOM uint8_t PM31_3 : 2;
            __IOM uint8_t PM31_4 : 2;
            __IOM uint8_t PM31_5 : 2;
            uint8_t              : 4;
        } PM_31_b;
    };
    __IM uint8_t RESERVED8[2];
    union
    {
        __IOM uint16_t PM_33;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_33_byte;
        struct
        {
            __IOM uint8_t PM33_0 : 2;
            __IOM uint8_t PM33_1 : 2;
            __IOM uint8_t PM33_2 : 2;
            __IOM uint8_t PM33_3 : 2;
            __IOM uint8_t PM33_4 : 2;
            uint8_t              : 6;
        } PM_33_b;
    };
    union
    {
        __IOM uint16_t PM_34;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_34_byte;
        struct
        {
            __IOM uint8_t PM34_0 : 2;
            __IOM uint8_t PM34_1 : 2;
            __IOM uint8_t PM34_2 : 2;
            __IOM uint8_t PM34_3 : 2;
            uint8_t              : 8;
        } PM_34_b;
    };
    union
    {
        __IOM uint16_t PM_35;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_35_byte;
        struct
        {
            __IOM uint8_t PM35_0 : 2;
            __IOM uint8_t PM35_1 : 2;
            __IOM uint8_t PM35_2 : 2;
            __IOM uint8_t PM35_3 : 2;
            __IOM uint8_t PM35_4 : 2;
            uint8_t              : 6;
        } PM_35_b;
    };
    union
    {
        __IOM uint16_t PM_36;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_36_byte;
        struct
        {
            __IOM uint8_t PM36_0 : 2;
            __IOM uint8_t PM36_1 : 2;
            __IOM uint8_t PM36_2 : 2;
            __IOM uint8_t PM36_3 : 2;
            __IOM uint8_t PM36_4 : 2;
            __IOM uint8_t PM36_5 : 2;
            __IOM uint8_t PM36_6 : 2;
            __IOM uint8_t PM36_7 : 2;
        } PM_36_b;
    };
    __IM uint8_t RESERVED9[10];
    union
    {
        __IOM uint16_t PM_3C;
        struct
        {
            __IOM uint8_t L;
            __IOM uint8_t H;
        } PM_3C_byte;
        struct
        {
            __IOM uint8_t PM3C_0 : 2;
            __IOM uint8_t PM3C_1 : 2;
            uint8_t              : 4;
            uint8_t              : 8;
        } PM_3C_b;
    };
    __IM uint8_t RESERVED10[168];
    union
    {
        __IOM uint8_t PMC_22;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC_22_b;
    };
    union
    {
        __IOM uint8_t PMC_23;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            uint8_t            : 1;
        } PMC_23_b;
    };
    __IM uint8_t RESERVED11[1];
    union
    {
        __IOM uint8_t PMC_25;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            uint8_t            : 1;
        } PMC_25_b;
    };
    union
    {
        __IOM uint8_t PMC_26;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            uint8_t            : 1;
        } PMC_26_b;
    };
    union
    {
        __IOM uint8_t PMC_27;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_27_b;
    };
    union
    {
        __IOM uint8_t PMC_28;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC_28_b;
    };
    __IM uint8_t RESERVED12[1];
    union
    {
        __IOM uint8_t PMC_2A;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_2A_b;
    };
    union
    {
        __IOM uint8_t PMC_2B;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_2B_b;
    };
    union
    {
        __IOM uint8_t PMC_2C;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            uint8_t            : 5;
        } PMC_2C_b;
    };
    union
    {
        __IOM uint8_t PMC_2D;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_2D_b;
    };
    union
    {
        __IOM uint8_t PMC_2E;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_2E_b;
    };
    union
    {
        __IOM uint8_t PMC_2F;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            uint8_t            : 5;
        } PMC_2F_b;
    };
    union
    {
        __IOM uint8_t PMC_30;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_30_b;
    };
    union
    {
        __IOM uint8_t PMC_31;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            uint8_t            : 2;
        } PMC_31_b;
    };
    __IM uint8_t RESERVED13[1];
    union
    {
        __IOM uint8_t PMC_33;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_33_b;
    };
    union
    {
        __IOM uint8_t PMC_34;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            uint8_t            : 4;
        } PMC_34_b;
    };
    union
    {
        __IOM uint8_t PMC_35;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            uint8_t            : 3;
        } PMC_35_b;
    };
    union
    {
        __IOM uint8_t PMC_36;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            __IOM uint8_t PMC2 : 1;
            __IOM uint8_t PMC3 : 1;
            __IOM uint8_t PMC4 : 1;
            __IOM uint8_t PMC5 : 1;
            __IOM uint8_t PMC6 : 1;
            __IOM uint8_t PMC7 : 1;
        } PMC_36_b;
    };
    __IM uint8_t RESERVED14[5];
    union
    {
        __IOM uint8_t PMC_3C;
        struct
        {
            __IOM uint8_t PMC0 : 1;
            __IOM uint8_t PMC1 : 1;
            uint8_t            : 6;
        } PMC_3C_b;
    };
    __IM uint8_t RESERVED15[587];
    union
    {
        __IOM uint32_t PFC_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_22_byte;
        struct
        {
            __IOM uint8_t PFC22_0 : 4;
            __IOM uint8_t PFC22_1 : 4;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_22_b;
    };
    union
    {
        __IOM uint32_t PFC_23;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_23_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_23_byte;
        struct
        {
            __IOM uint8_t PFC23_0 : 4;
            __IOM uint8_t PFC23_1 : 4;
            __IOM uint8_t PFC23_2 : 4;
            __IOM uint8_t PFC23_3 : 4;
            __IOM uint8_t PFC23_4 : 4;
            __IOM uint8_t PFC23_5 : 4;
            __IOM uint8_t PFC23_6 : 4;
            uint8_t               : 4;
        } PFC_23_b;
    };
    __IM uint8_t RESERVED16[4];
    union
    {
        __IOM uint32_t PFC_25;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_25_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_25_byte;
        struct
        {
            __IOM uint8_t PFC25_0 : 4;
            __IOM uint8_t PFC25_1 : 4;
            __IOM uint8_t PFC25_2 : 4;
            __IOM uint8_t PFC25_3 : 4;
            __IOM uint8_t PFC25_4 : 4;
            __IOM uint8_t PFC25_5 : 4;
            __IOM uint8_t PFC25_6 : 4;
            uint8_t               : 4;
        } PFC_25_b;
    };
    union
    {
        __IOM uint32_t PFC_26;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_26_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_26_byte;
        struct
        {
            __IOM uint8_t PFC26_0 : 4;
            __IOM uint8_t PFC26_1 : 4;
            __IOM uint8_t PFC26_2 : 4;
            __IOM uint8_t PFC26_3 : 4;
            __IOM uint8_t PFC26_4 : 4;
            __IOM uint8_t PFC26_5 : 4;
            __IOM uint8_t PFC26_6 : 4;
            uint8_t               : 4;
        } PFC_26_b;
    };
    union
    {
        __IOM uint32_t PFC_27;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_27_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_27_byte;
        struct
        {
            __IOM uint8_t PFC27_0 : 4;
            __IOM uint8_t PFC27_1 : 4;
            __IOM uint8_t PFC27_2 : 4;
            __IOM uint8_t PFC27_3 : 4;
            __IOM uint8_t PFC27_4 : 4;
            __IOM uint8_t PFC27_5 : 4;
            __IOM uint8_t PFC27_6 : 4;
            __IOM uint8_t PFC27_7 : 4;
        } PFC_27_b;
    };
    union
    {
        __IOM uint32_t PFC_28;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_28_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_28_byte;
        struct
        {
            __IOM uint8_t PFC28_0 : 4;
            __IOM uint8_t PFC28_1 : 4;
            __IOM uint8_t PFC28_2 : 4;
            __IOM uint8_t PFC28_3 : 4;
            __IOM uint8_t PFC28_4 : 4;
            __IOM uint8_t PFC28_5 : 4;
            uint8_t               : 8;
        } PFC_28_b;
    };
    __IM uint8_t RESERVED17[4];
    union
    {
        __IOM uint32_t PFC_2A;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2A_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2A_byte;
        struct
        {
            __IOM uint8_t PFC2A_0 : 4;
            __IOM uint8_t PFC2A_1 : 4;
            __IOM uint8_t PFC2A_2 : 4;
            __IOM uint8_t PFC2A_3 : 4;
            __IOM uint8_t PFC2A_4 : 4;
            __IOM uint8_t PFC2A_5 : 4;
            __IOM uint8_t PFC2A_6 : 4;
            __IOM uint8_t PFC2A_7 : 4;
        } PFC_2A_b;
    };
    union
    {
        __IOM uint32_t PFC_2B;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2B_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2B_byte;
        struct
        {
            __IOM uint8_t PFC2B_0 : 4;
            __IOM uint8_t PFC2B_1 : 4;
            __IOM uint8_t PFC2B_2 : 4;
            __IOM uint8_t PFC2B_3 : 4;
            __IOM uint8_t PFC2B_4 : 4;
            __IOM uint8_t PFC2B_5 : 4;
            __IOM uint8_t PFC2B_6 : 4;
            __IOM uint8_t PFC2B_7 : 4;
        } PFC_2B_b;
    };
    union
    {
        __IOM uint32_t PFC_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2C_byte;
        struct
        {
            __IOM uint8_t PFC2C_0 : 4;
            __IOM uint8_t PFC2C_1 : 4;
            __IOM uint8_t PFC2C_2 : 4;
            uint8_t               : 4;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_2C_b;
    };
    union
    {
        __IOM uint32_t PFC_2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2D_byte;
        struct
        {
            __IOM uint8_t PFC2D_0 : 4;
            __IOM uint8_t PFC2D_1 : 4;
            __IOM uint8_t PFC2D_2 : 4;
            __IOM uint8_t PFC2D_3 : 4;
            __IOM uint8_t PFC2D_4 : 4;
            __IOM uint8_t PFC2D_5 : 4;
            __IOM uint8_t PFC2D_6 : 4;
            __IOM uint8_t PFC2D_7 : 4;
        } PFC_2D_b;
    };
    union
    {
        __IOM uint32_t PFC_2E;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2E_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2E_byte;
        struct
        {
            __IOM uint8_t PFC2E_0 : 4;
            __IOM uint8_t PFC2E_1 : 4;
            __IOM uint8_t PFC2E_2 : 4;
            __IOM uint8_t PFC2E_3 : 4;
            __IOM uint8_t PFC2E_4 : 4;
            __IOM uint8_t PFC2E_5 : 4;
            __IOM uint8_t PFC2E_6 : 4;
            __IOM uint8_t PFC2E_7 : 4;
        } PFC_2E_b;
    };
    union
    {
        __IOM uint32_t PFC_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_2F_byte;
        struct
        {
            __IOM uint8_t PFC2F_0 : 4;
            __IOM uint8_t PFC2F_1 : 4;
            __IOM uint8_t PFC2F_2 : 4;
            uint8_t               : 4;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_2F_b;
    };
    union
    {
        __IOM uint32_t PFC_30;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_30_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_30_byte;
        struct
        {
            __IOM uint8_t PFC30_0 : 4;
            __IOM uint8_t PFC30_1 : 4;
            __IOM uint8_t PFC30_2 : 4;
            __IOM uint8_t PFC30_3 : 4;
            __IOM uint8_t PFC30_4 : 4;
            __IOM uint8_t PFC30_5 : 4;
            __IOM uint8_t PFC30_6 : 4;
            __IOM uint8_t PFC30_7 : 4;
        } PFC_30_b;
    };
    union
    {
        __IOM uint32_t PFC_31;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_31_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_31_byte;
        struct
        {
            __IOM uint8_t PFC31_0 : 4;
            __IOM uint8_t PFC31_1 : 4;
            __IOM uint8_t PFC31_2 : 4;
            __IOM uint8_t PFC31_3 : 4;
            __IOM uint8_t PFC31_4 : 4;
            __IOM uint8_t PFC31_5 : 4;
            uint8_t               : 8;
        } PFC_31_b;
    };
    __IM uint8_t RESERVED18[4];
    union
    {
        __IOM uint32_t PFC_33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_33_byte;
        struct
        {
            __IOM uint8_t PFC33_0 : 4;
            __IOM uint8_t PFC33_1 : 4;
            __IOM uint8_t PFC33_2 : 4;
            __IOM uint8_t PFC33_3 : 4;
            __IOM uint8_t PFC33_4 : 4;
            uint8_t               : 4;
            uint8_t               : 8;
        } PFC_33_b;
    };
    union
    {
        __IOM uint32_t PFC_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_34_byte;
        struct
        {
            __IOM uint8_t PFC34_0 : 4;
            __IOM uint8_t PFC34_1 : 4;
            __IOM uint8_t PFC34_2 : 4;
            __IOM uint8_t PFC34_3 : 4;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_34_b;
    };
    union
    {
        __IOM uint32_t PFC_35;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_35_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_35_byte;
        struct
        {
            __IOM uint8_t PFC35_0 : 4;
            __IOM uint8_t PFC35_1 : 4;
            __IOM uint8_t PFC35_2 : 4;
            __IOM uint8_t PFC35_3 : 4;
            __IOM uint8_t PFC35_4 : 4;
            uint8_t               : 4;
            uint8_t               : 8;
        } PFC_35_b;
    };
    union
    {
        __IOM uint32_t PFC_36;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_36_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_36_byte;
        struct
        {
            __IOM uint8_t PFC36_0 : 4;
            __IOM uint8_t PFC36_1 : 4;
            __IOM uint8_t PFC36_2 : 4;
            __IOM uint8_t PFC36_3 : 4;
            __IOM uint8_t PFC36_4 : 4;
            __IOM uint8_t PFC36_5 : 4;
            __IOM uint8_t PFC36_6 : 4;
            __IOM uint8_t PFC36_7 : 4;
        } PFC_36_b;
    };
    __IM uint8_t RESERVED19[20];
    union
    {
        __IOM uint32_t PFC_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PFC_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PFC_3C_byte;
        struct
        {
            __IOM uint8_t PFC3C_0 : 4;
            __IOM uint8_t PFC3C_1 : 4;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } PFC_3C_b;
    };
    __IM uint8_t RESERVED20[814];
    union
    {
        __IM uint8_t PIN_22;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN_22_b;
    };
    union
    {
        __IM uint8_t PIN_23;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            uint8_t           : 1;
        } PIN_23_b;
    };
    __IM uint8_t RESERVED21[1];
    union
    {
        __IM uint8_t PIN_25;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            uint8_t           : 1;
        } PIN_25_b;
    };
    union
    {
        __IM uint8_t PIN_26;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            uint8_t           : 1;
        } PIN_26_b;
    };
    union
    {
        __IM uint8_t PIN_27;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_27_b;
    };
    union
    {
        __IM uint8_t PIN_28;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN_28_b;
    };
    __IM uint8_t RESERVED22[1];
    union
    {
        __IM uint8_t PIN_2A;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_2A_b;
    };
    union
    {
        __IM uint8_t PIN_2B;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_2B_b;
    };
    union
    {
        __IM uint8_t PIN_2C;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            uint8_t           : 5;
        } PIN_2C_b;
    };
    union
    {
        __IM uint8_t PIN_2D;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_2D_b;
    };
    union
    {
        __IM uint8_t PIN_2E;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_2E_b;
    };
    union
    {
        __IM uint8_t PIN_2F;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            uint8_t           : 5;
        } PIN_2F_b;
    };
    union
    {
        __IM uint8_t PIN_30;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_30_b;
    };
    union
    {
        __IM uint8_t PIN_31;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            uint8_t           : 2;
        } PIN_31_b;
    };
    __IM uint8_t RESERVED23[1];
    union
    {
        __IM uint8_t PIN_33;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_33_b;
    };
    union
    {
        __IM uint8_t PIN_34;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            uint8_t           : 4;
        } PIN_34_b;
    };
    union
    {
        __IM uint8_t PIN_35;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            uint8_t           : 3;
        } PIN_35_b;
    };
    union
    {
        __IM uint8_t PIN_36;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            __IM uint8_t PIN2 : 1;
            __IM uint8_t PIN3 : 1;
            __IM uint8_t PIN4 : 1;
            __IM uint8_t PIN5 : 1;
            __IM uint8_t PIN6 : 1;
            __IM uint8_t PIN7 : 1;
        } PIN_36_b;
    };
    __IM uint8_t RESERVED24[5];
    union
    {
        __IM uint8_t PIN_3C;
        struct
        {
            __IM uint8_t PIN0 : 1;
            __IM uint8_t PIN1 : 1;
            uint8_t           : 6;
        } PIN_3C_b;
    };
    __IM uint8_t RESERVED25[2027];
    union
    {
        __IOM uint32_t IOLH_05;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_05_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_05_byte;
        struct
        {
            __IOM uint8_t WDTOVF_N : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH_05_b;
    };
    __IM uint8_t RESERVED26[4];
    union
    {
        __IOM uint32_t IOLH_06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_06_byte;
        struct
        {
            __IOM uint8_t SCIF_RXD : 2;
            uint8_t                : 6;
            __IOM uint8_t SCIF_TXD : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH_06_b;
    };
    __IM uint8_t RESERVED27[20];
    union
    {
        __IOM uint32_t IOLH_09_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_09_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_09_L_byte;
        struct
        {
            __IOM uint8_t SD0_CLK   : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_CMD   : 2;
            uint8_t                 : 6;
            __IOM uint8_t SD0_RST_N : 2;
            uint8_t                 : 6;
            uint8_t                 : 8;
        } IOLH_09_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_09_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_09_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_09_H_byte;
        struct
        {
            uint8_t              : 8;
            __IOM uint8_t SD0_DS : 2;
            uint8_t              : 6;
            uint8_t              : 8;
            uint8_t              : 8;
        } IOLH_09_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_0A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_0A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_0A_L_byte;
        struct
        {
            __IOM uint8_t SD0_D0 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D1 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D2 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D3 : 2;
            uint8_t              : 6;
        } IOLH_0A_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_0A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_0A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_0A_H_byte;
        struct
        {
            __IOM uint8_t SD0_D4 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D5 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D6 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D7 : 2;
            uint8_t              : 6;
        } IOLH_0A_H_b;
    };
    __IM uint8_t RESERVED28[192];
    union
    {
        __IOM uint32_t IOLH_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_23_L_byte;
        struct
        {
            __IOM uint8_t IOLH23_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH23_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH23_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH23_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_23_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_23_H_byte;
        struct
        {
            __IOM uint8_t IOLH23_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH23_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH23_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } IOLH_23_H_b;
    };
    __IM uint8_t RESERVED29[8];
    union
    {
        __IOM uint32_t IOLH_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_25_L_byte;
        struct
        {
            __IOM uint8_t IOLH25_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_25_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_25_H_byte;
        struct
        {
            __IOM uint8_t IOLH25_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH25_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } IOLH_25_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_26_L_byte;
        struct
        {
            __IOM uint8_t IOLH26_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH26_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH26_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH26_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_26_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_26_H_byte;
        struct
        {
            __IOM uint8_t IOLH26_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH26_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH26_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } IOLH_26_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_27_L_byte;
        struct
        {
            __IOM uint8_t IOLH27_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_27_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_27_H_byte;
        struct
        {
            __IOM uint8_t IOLH27_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH27_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_27_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_28_L_byte;
        struct
        {
            __IOM uint8_t IOLH28_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH28_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH28_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH28_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_28_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_28_H_byte;
        struct
        {
            __IOM uint8_t IOLH28_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH28_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_28_H_b;
    };
    __IM uint8_t RESERVED30[8];
    union
    {
        __IOM uint32_t IOLH_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2A_L_byte;
        struct
        {
            __IOM uint8_t IOLH2A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_2A_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2A_H_byte;
        struct
        {
            __IOM uint8_t IOLH2A_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2A_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_2A_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2B_L_byte;
        struct
        {
            __IOM uint8_t IOLH2B_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_2B_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2B_H_byte;
        struct
        {
            __IOM uint8_t IOLH2B_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2B_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_2B_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2C_byte;
        struct
        {
            __IOM uint8_t IOLH2C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH2C_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH2C_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH_2C_b;
    };
    __IM uint8_t RESERVED31[4];
    union
    {
        __IOM uint32_t IOLH_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2D_L_byte;
        struct
        {
            __IOM uint8_t IOLH2D_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_2D_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2D_H_byte;
        struct
        {
            __IOM uint8_t IOLH2D_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2D_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_2D_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2E_L_byte;
        struct
        {
            __IOM uint8_t IOLH2E_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_2E_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2E_H_byte;
        struct
        {
            __IOM uint8_t IOLH2E_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH2E_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_2E_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_2F_byte;
        struct
        {
            __IOM uint8_t IOLH2F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH2F_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH2F_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } IOLH_2F_b;
    };
    __IM uint8_t RESERVED32[4];
    union
    {
        __IOM uint32_t IOLH_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_30_L_byte;
        struct
        {
            __IOM uint8_t IOLH30_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_30_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_30_H_byte;
        struct
        {
            __IOM uint8_t IOLH30_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH30_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_30_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_31_L_byte;
        struct
        {
            __IOM uint8_t IOLH31_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH31_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH31_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH31_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_31_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_31_H_byte;
        struct
        {
            __IOM uint8_t IOLH31_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH31_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_31_H_b;
    };
    __IM uint8_t RESERVED33[8];
    union
    {
        __IOM uint32_t IOLH_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_33_L_byte;
        struct
        {
            __IOM uint8_t IOLH33_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH33_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_33_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_33_H_byte;
        struct
        {
            __IOM uint8_t IOLH33_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_33_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_34_byte;
        struct
        {
            __IOM uint8_t IOLH34_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH34_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH34_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH34_3 : 2;
            uint8_t                : 6;
        } IOLH_34_b;
    };
    __IM uint8_t RESERVED34[4];
    union
    {
        __IOM uint32_t IOLH_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_35_L_byte;
        struct
        {
            __IOM uint8_t IOLH35_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH35_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_35_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_35_H_byte;
        struct
        {
            __IOM uint8_t IOLH35_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } IOLH_35_H_b;
    };
    union
    {
        __IOM uint32_t IOLH_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_36_L_byte;
        struct
        {
            __IOM uint8_t IOLH36_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_L_3 : 2;
            uint8_t                  : 6;
        } IOLH_36_L_b;
    };
    union
    {
        __IOM uint32_t IOLH_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_36_H_byte;
        struct
        {
            __IOM uint8_t IOLH36_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t IOLH36_H_3 : 2;
            uint8_t                  : 6;
        } IOLH_36_H_b;
    };
    __IM uint8_t RESERVED35[40];
    union
    {
        __IOM uint32_t IOLH_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IOLH_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IOLH_3C_byte;
        struct
        {
            __IOM uint8_t IOLH3C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t IOLH3C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } IOLH_3C_b;
    };
    __IM uint8_t RESERVED36[1636];
    union
    {
        __IOM uint32_t IEN_09_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_09_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_09_L_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t SD0_CMD : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
        } IEN_09_L_b;
    };
    union
    {
        __IOM uint32_t IEN_09_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_09_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_09_H_byte;
        struct
        {
            uint8_t              : 8;
            __IOM uint8_t SD0_DS : 1;
            uint8_t              : 7;
            uint8_t              : 8;
            uint8_t              : 8;
        } IEN_09_H_b;
    };
    union
    {
        __IOM uint32_t IEN_0A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_0A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_0A_L_byte;
        struct
        {
            __IOM uint8_t SD0_D0 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D1 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D2 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D3 : 1;
            uint8_t              : 7;
        } IEN_0A_L_b;
    };
    union
    {
        __IOM uint32_t IEN_0A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_0A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_0A_H_byte;
        struct
        {
            __IOM uint8_t SD0_D4 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D5 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D6 : 1;
            uint8_t              : 7;
            __IOM uint8_t SD0_D7 : 1;
            uint8_t              : 7;
        } IEN_0A_H_b;
    };
    __IM uint8_t RESERVED37[184];
    union
    {
        __IOM uint32_t IEN_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_22_byte;
        struct
        {
            __IOM uint8_t P20 : 1;
            uint8_t           : 7;
            __IOM uint8_t P21 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_22_b;
    };
    __IM uint8_t RESERVED38[60];
    union
    {
        __IOM uint32_t IEN_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_2A_L_byte;
        struct
        {
            __IOM uint8_t PA0 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_2A_L_b;
    };
    union
    {
        __IOM uint32_t IEN_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_2A_H_byte;
        struct
        {
            uint8_t           : 8;
            uint8_t           : 8;
            __IOM uint8_t PA6 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
        } IEN_2A_H_b;
    };
    __IM uint8_t RESERVED39[16];
    union
    {
        __IOM uint32_t IEN_2D;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_2D_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_2D_byte;
        struct
        {
            __IOM uint8_t PD0 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_2D_b;
    };
    __IM uint8_t RESERVED40[20];
    union
    {
        __IOM uint32_t IEN_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_30_L_byte;
        struct
        {
            uint8_t           : 8;
            __IOM uint8_t PG1 : 1;
            uint8_t           : 7;
            __IOM uint8_t PG2 : 1;
            uint8_t           : 7;
            __IOM uint8_t PG3 : 1;
            uint8_t           : 7;
        } IEN_30_L_b;
    };
    union
    {
        __IOM uint32_t IEN_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_30_H_byte;
        struct
        {
            __IOM uint8_t PG4 : 1;
            uint8_t           : 7;
            __IOM uint8_t PG5 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_30_H_b;
    };
    union
    {
        __IOM uint32_t IEN_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_31_L_byte;
        struct
        {
            uint8_t           : 8;
            __IOM uint8_t PH1 : 1;
            uint8_t           : 7;
            __IOM uint8_t PH2 : 1;
            uint8_t           : 7;
            __IOM uint8_t PH3 : 1;
            uint8_t           : 7;
        } IEN_31_L_b;
    };
    union
    {
        __IOM uint32_t IEN_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_31_H_byte;
        struct
        {
            __IOM uint8_t PH4 : 1;
            uint8_t           : 7;
            __IOM uint8_t PH5 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_31_H_b;
    };
    __IM uint8_t RESERVED41[8];
    union
    {
        __IOM uint32_t IEN_33;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } IEN_33_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } IEN_33_byte;
        struct
        {
            __IOM uint8_t PJ0 : 1;
            uint8_t           : 7;
            uint8_t           : 8;
            uint8_t           : 8;
            uint8_t           : 8;
        } IEN_33_b;
    };
    __IM uint8_t RESERVED42[660];
    union
    {
        __IOM uint32_t PUPD_06;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_06_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_06_byte;
        struct
        {
            __IOM uint8_t SCIF_RXD : 2;
            uint8_t                : 6;
            __IOM uint8_t SCIF_TXD : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD_06_b;
    };
    __IM uint8_t RESERVED43[20];
    union
    {
        __IOM uint32_t PUPD_09_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_09_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_09_L_byte;
        struct
        {
            uint8_t               : 8;
            __IOM uint8_t SD0_CMD : 2;
            uint8_t               : 6;
            uint8_t               : 8;
            uint8_t               : 8;
        } PUPD_09_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_09_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_09_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_09_H_byte;
        struct
        {
            uint8_t              : 8;
            __IOM uint8_t SD0_DS : 2;
            uint8_t              : 6;
            uint8_t              : 8;
            uint8_t              : 8;
        } PUPD_09_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_0A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_0A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_0A_L_byte;
        struct
        {
            __IOM uint8_t SD0_D0 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D1 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D2 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D3 : 2;
            uint8_t              : 6;
        } PUPD_0A_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_0A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_0A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_0A_H_byte;
        struct
        {
            __IOM uint8_t SD0_D4 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D5 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D6 : 2;
            uint8_t              : 6;
            __IOM uint8_t SD0_D7 : 2;
            uint8_t              : 6;
        } PUPD_0A_H_b;
    };
    __IM uint8_t RESERVED44[192];
    union
    {
        __IOM uint32_t PUPD_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_23_L_byte;
        struct
        {
            __IOM uint8_t PUPD23_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD23_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD23_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD23_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_23_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_23_H_byte;
        struct
        {
            __IOM uint8_t PUPD23_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD23_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD23_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } PUPD_23_H_b;
    };
    __IM uint8_t RESERVED45[8];
    union
    {
        __IOM uint32_t PUPD_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_25_L_byte;
        struct
        {
            __IOM uint8_t PUPD25_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_25_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_25_H_byte;
        struct
        {
            __IOM uint8_t PUPD25_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD25_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } PUPD_25_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_26_L_byte;
        struct
        {
            __IOM uint8_t PUPD26_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD26_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD26_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD26_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_26_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_26_H_byte;
        struct
        {
            __IOM uint8_t PUPD26_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD26_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD26_H_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } PUPD_26_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_27_L_byte;
        struct
        {
            __IOM uint8_t PUPD27_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_27_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_27_H_byte;
        struct
        {
            __IOM uint8_t PUPD27_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD27_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_27_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_28_L_byte;
        struct
        {
            __IOM uint8_t PUPD28_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD28_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD28_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD28_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_28_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_28_H_byte;
        struct
        {
            __IOM uint8_t PUPD28_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD28_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_28_H_b;
    };
    __IM uint8_t RESERVED46[8];
    union
    {
        __IOM uint32_t PUPD_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2A_L_byte;
        struct
        {
            __IOM uint8_t PUPD2A_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_2A_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2A_H_byte;
        struct
        {
            __IOM uint8_t PUPD2A_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2A_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_2A_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2B_L_byte;
        struct
        {
            __IOM uint8_t PUPD2B_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_2B_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2B_H_byte;
        struct
        {
            __IOM uint8_t PUPD2B_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2B_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_2B_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2C_byte;
        struct
        {
            __IOM uint8_t PUPD2C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD2C_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD2C_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD_2C_b;
    };
    __IM uint8_t RESERVED47[4];
    union
    {
        __IOM uint32_t PUPD_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2D_L_byte;
        struct
        {
            __IOM uint8_t PUPD2D_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_2D_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2D_H_byte;
        struct
        {
            __IOM uint8_t PUPD2D_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2D_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_2D_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2E_L_byte;
        struct
        {
            __IOM uint8_t PUPD2E_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_2E_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2E_H_byte;
        struct
        {
            __IOM uint8_t PUPD2E_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD2E_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_2E_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_2F_byte;
        struct
        {
            __IOM uint8_t PUPD2F_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD2F_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD2F_2 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
        } PUPD_2F_b;
    };
    __IM uint8_t RESERVED48[4];
    union
    {
        __IOM uint32_t PUPD_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_30_L_byte;
        struct
        {
            __IOM uint8_t PUPD30_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_30_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_30_H_byte;
        struct
        {
            __IOM uint8_t PUPD30_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD30_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_30_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_31_L_byte;
        struct
        {
            __IOM uint8_t PUPD31_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD31_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD31_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD31_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_31_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_31_H_byte;
        struct
        {
            __IOM uint8_t PUPD31_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD31_H_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_31_H_b;
    };
    __IM uint8_t RESERVED49[8];
    union
    {
        __IOM uint32_t PUPD_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_33_L_byte;
        struct
        {
            __IOM uint8_t PUPD33_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD33_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_33_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_33_H_byte;
        struct
        {
            __IOM uint8_t PUPD33_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_33_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_34_byte;
        struct
        {
            __IOM uint8_t PUPD34_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD34_1 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD34_2 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD34_3 : 2;
            uint8_t                : 6;
        } PUPD_34_b;
    };
    __IM uint8_t RESERVED50[4];
    union
    {
        __IOM uint32_t PUPD_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_35_L_byte;
        struct
        {
            __IOM uint8_t PUPD35_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD35_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_35_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_35_H_byte;
        struct
        {
            __IOM uint8_t PUPD35_H_0 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } PUPD_35_H_b;
    };
    union
    {
        __IOM uint32_t PUPD_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_36_L_byte;
        struct
        {
            __IOM uint8_t PUPD36_L_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_L_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_L_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_L_3 : 2;
            uint8_t                  : 6;
        } PUPD_36_L_b;
    };
    union
    {
        __IOM uint32_t PUPD_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_36_H_byte;
        struct
        {
            __IOM uint8_t PUPD36_H_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_H_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_H_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t PUPD36_H_3 : 2;
            uint8_t                  : 6;
        } PUPD_36_H_b;
    };
    __IM uint8_t RESERVED51[40];
    union
    {
        __IOM uint32_t PUPD_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PUPD_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PUPD_3C_byte;
        struct
        {
            __IOM uint8_t PUPD3C_0 : 2;
            uint8_t                : 6;
            __IOM uint8_t PUPD3C_1 : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
        } PUPD_3C_b;
    };
    __IM uint8_t RESERVED52[812];
    union
    {
        __IOM uint32_t FILONOFF_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_22_byte;
        struct
        {
            __IOM uint8_t FILONOFF22_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF22_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF_22_b;
    };
    __IM uint8_t RESERVED53[4];
    union
    {
        __IOM uint32_t FILONOFF_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_23_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF23_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF23_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF23_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF23_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_23_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_23_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF23_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF23_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF23_H_2 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
        } FILONOFF_23_H_b;
    };
    __IM uint8_t RESERVED54[8];
    union
    {
        __IOM uint32_t FILONOFF_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_25_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF25_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_25_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_25_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF25_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF25_H_2 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
        } FILONOFF_25_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_26_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF26_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF26_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF26_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF26_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_26_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_26_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF26_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF26_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF26_H_2 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
        } FILONOFF_26_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_27_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF27_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_27_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_27_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF27_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF27_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_27_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_28_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF28_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF28_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF28_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF28_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_28_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_28_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF28_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF28_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_28_H_b;
    };
    __IM uint8_t RESERVED55[8];
    union
    {
        __IOM uint32_t FILONOFF_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2A_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF2A_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2A_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF2A_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2A_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2A_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2B_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF2B_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2B_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2B_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF2B_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2B_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2B_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2C_byte;
        struct
        {
            __IOM uint8_t FILONOFF2C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2C_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2C_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF_2C_b;
    };
    __IM uint8_t RESERVED56[4];
    union
    {
        __IOM uint32_t FILONOFF_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2D_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF2D_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2D_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2D_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF2D_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2D_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2D_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2E_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF2E_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2E_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2E_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF2E_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF2E_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_2E_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_2F_byte;
        struct
        {
            __IOM uint8_t FILONOFF2F_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2F_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF2F_2 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
        } FILONOFF_2F_b;
    };
    __IM uint8_t RESERVED57[4];
    union
    {
        __IOM uint32_t FILONOFF_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_30_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF30_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_30_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_30_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF30_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF30_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_30_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_31_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF31_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF31_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF31_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF31_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_31_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_31_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF31_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF31_H_1 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_31_H_b;
    };
    __IM uint8_t RESERVED58[8];
    union
    {
        __IOM uint32_t FILONOFF_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_33_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF33_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF33_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_33_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_33_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF33_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_33_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_34_byte;
        struct
        {
            __IOM uint8_t FILONOFF34_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF34_1 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF34_2 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF34_3 : 1;
            uint8_t                    : 7;
        } FILONOFF_34_b;
    };
    __IM uint8_t RESERVED59[4];
    union
    {
        __IOM uint32_t FILONOFF_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_35_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF35_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF35_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_35_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_35_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF35_H_0 : 1;
            uint8_t                      : 7;
            uint8_t                      : 8;
            uint8_t                      : 8;
            uint8_t                      : 8;
        } FILONOFF_35_H_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_36_L_byte;
        struct
        {
            __IOM uint8_t FILONOFF36_L_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_L_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_L_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_L_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_36_L_b;
    };
    union
    {
        __IOM uint32_t FILONOFF_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_36_H_byte;
        struct
        {
            __IOM uint8_t FILONOFF36_H_0 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_H_1 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_H_2 : 1;
            uint8_t                      : 7;
            __IOM uint8_t FILONOFF36_H_3 : 1;
            uint8_t                      : 7;
        } FILONOFF_36_H_b;
    };
    __IM uint8_t RESERVED60[40];
    union
    {
        __IOM uint32_t FILONOFF_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILONOFF_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILONOFF_3C_byte;
        struct
        {
            __IOM uint8_t FILONOFF3C_0 : 1;
            uint8_t                    : 7;
            __IOM uint8_t FILONOFF3C_1 : 1;
            uint8_t                    : 7;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILONOFF_3C_b;
    };
    __IM uint8_t RESERVED61[812];
    union
    {
        __IOM uint32_t FILNUM_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_22_byte;
        struct
        {
            __IOM uint8_t FILNUM22_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM22_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM_22_b;
    };
    __IM uint8_t RESERVED62[4];
    union
    {
        __IOM uint32_t FILNUM_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_23_L_byte;
        struct
        {
            __IOM uint8_t FILNUM23_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM23_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM23_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM23_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_23_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_23_H_byte;
        struct
        {
            __IOM uint8_t FILNUM23_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM23_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM23_H_2 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
        } FILNUM_23_H_b;
    };
    __IM uint8_t RESERVED63[8];
    union
    {
        __IOM uint32_t FILNUM_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_25_L_byte;
        struct
        {
            __IOM uint8_t FILNUM25_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_25_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_25_H_byte;
        struct
        {
            __IOM uint8_t FILNUM25_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM25_H_2 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
        } FILNUM_25_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_26_L_byte;
        struct
        {
            __IOM uint8_t FILNUM26_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM26_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM26_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM26_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_26_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_26_H_byte;
        struct
        {
            __IOM uint8_t FILNUM26_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM26_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM26_H_2 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
        } FILNUM_26_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_27_L_byte;
        struct
        {
            __IOM uint8_t FILNUM27_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_27_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_27_H_byte;
        struct
        {
            __IOM uint8_t FILNUM27_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM27_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_27_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_28_L_byte;
        struct
        {
            __IOM uint8_t FILNUM28_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM28_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM28_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM28_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_28_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_28_H_byte;
        struct
        {
            __IOM uint8_t FILNUM28_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM28_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_28_H_b;
    };
    __IM uint8_t RESERVED64[8];
    union
    {
        __IOM uint32_t FILNUM_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2A_L_byte;
        struct
        {
            __IOM uint8_t FILNUM2A_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2A_H_byte;
        struct
        {
            __IOM uint8_t FILNUM2A_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2A_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2A_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2B_L_byte;
        struct
        {
            __IOM uint8_t FILNUM2B_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2B_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2B_H_byte;
        struct
        {
            __IOM uint8_t FILNUM2B_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2B_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2B_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2C_byte;
        struct
        {
            __IOM uint8_t FILNUM2C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2C_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2C_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM_2C_b;
    };
    __IM uint8_t RESERVED65[4];
    union
    {
        __IOM uint32_t FILNUM_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2D_L_byte;
        struct
        {
            __IOM uint8_t FILNUM2D_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2D_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2D_H_byte;
        struct
        {
            __IOM uint8_t FILNUM2D_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2D_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2D_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2E_L_byte;
        struct
        {
            __IOM uint8_t FILNUM2E_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2E_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2E_H_byte;
        struct
        {
            __IOM uint8_t FILNUM2E_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM2E_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_2E_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_2F_byte;
        struct
        {
            __IOM uint8_t FILNUM2F_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2F_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM2F_2 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
        } FILNUM_2F_b;
    };
    __IM uint8_t RESERVED66[4];
    union
    {
        __IOM uint32_t FILNUM_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_30_L_byte;
        struct
        {
            __IOM uint8_t FILNUM30_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_30_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_30_H_byte;
        struct
        {
            __IOM uint8_t FILNUM30_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM30_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_30_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_31_L_byte;
        struct
        {
            __IOM uint8_t FILNUM31_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM31_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM31_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM31_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_31_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_31_H_byte;
        struct
        {
            __IOM uint8_t FILNUM31_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM31_H_1 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_31_H_b;
    };
    __IM uint8_t RESERVED67[8];
    union
    {
        __IOM uint32_t FILNUM_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_33_L_byte;
        struct
        {
            __IOM uint8_t FILNUM33_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM33_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_33_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_33_H_byte;
        struct
        {
            __IOM uint8_t FILNUM33_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_33_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_34_byte;
        struct
        {
            __IOM uint8_t FILNUM34_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM34_1 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM34_2 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM34_3 : 2;
            uint8_t                  : 6;
        } FILNUM_34_b;
    };
    __IM uint8_t RESERVED68[4];
    union
    {
        __IOM uint32_t FILNUM_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_35_L_byte;
        struct
        {
            __IOM uint8_t FILNUM35_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM35_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_35_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_35_H_byte;
        struct
        {
            __IOM uint8_t FILNUM35_H_0 : 2;
            uint8_t                    : 6;
            uint8_t                    : 8;
            uint8_t                    : 8;
            uint8_t                    : 8;
        } FILNUM_35_H_b;
    };
    union
    {
        __IOM uint32_t FILNUM_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_36_L_byte;
        struct
        {
            __IOM uint8_t FILNUM36_L_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_L_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_L_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_L_3 : 2;
            uint8_t                    : 6;
        } FILNUM_36_L_b;
    };
    union
    {
        __IOM uint32_t FILNUM_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_36_H_byte;
        struct
        {
            __IOM uint8_t FILNUM36_H_0 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_H_1 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_H_2 : 2;
            uint8_t                    : 6;
            __IOM uint8_t FILNUM36_H_3 : 2;
            uint8_t                    : 6;
        } FILNUM_36_H_b;
    };
    __IM uint8_t RESERVED69[40];
    union
    {
        __IOM uint32_t FILNUM_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILNUM_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILNUM_3C_byte;
        struct
        {
            __IOM uint8_t FILNUM3C_0 : 2;
            uint8_t                  : 6;
            __IOM uint8_t FILNUM3C_1 : 2;
            uint8_t                  : 6;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } FILNUM_3C_b;
    };
    __IM uint8_t RESERVED70[812];
    union
    {
        __IOM uint32_t FILCLKSEL_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_22_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL22_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL22_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL_22_b;
    };
    __IM uint8_t RESERVED71[4];
    union
    {
        __IOM uint32_t FILCLKSEL_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_23_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL23_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL23_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL23_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL23_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_23_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_23_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL23_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL23_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL23_H_2 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
        } FILCLKSEL_23_H_b;
    };
    __IM uint8_t RESERVED72[8];
    union
    {
        __IOM uint32_t FILCLKSEL_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_25_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL25_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_25_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_25_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL25_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL25_H_2 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
        } FILCLKSEL_25_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_26_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL26_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL26_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL26_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL26_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_26_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_26_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL26_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL26_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL26_H_2 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
        } FILCLKSEL_26_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_27_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL27_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_27_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_27_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL27_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL27_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_27_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_28_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL28_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL28_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL28_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL28_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_28_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_28_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL28_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL28_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_28_H_b;
    };
    __IM uint8_t RESERVED73[8];
    union
    {
        __IOM uint32_t FILCLKSEL_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2A_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2A_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2A_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2A_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2A_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2A_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2A_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2B_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2B_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2B_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2B_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2B_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2B_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2B_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2C_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2C_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2C_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL_2C_b;
    };
    __IM uint8_t RESERVED74[4];
    union
    {
        __IOM uint32_t FILCLKSEL_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2D_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2D_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2D_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2D_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2D_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2D_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2D_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2E_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2E_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2E_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2E_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2E_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL2E_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_2E_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_2F_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL2F_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2F_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL2F_2 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
        } FILCLKSEL_2F_b;
    };
    __IM uint8_t RESERVED75[4];
    union
    {
        __IOM uint32_t FILCLKSEL_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_30_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL30_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_30_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_30_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL30_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL30_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_30_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_31_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL31_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL31_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL31_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL31_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_31_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_31_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL31_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL31_H_1 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_31_H_b;
    };
    __IM uint8_t RESERVED76[8];
    union
    {
        __IOM uint32_t FILCLKSEL_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_33_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL33_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL33_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_33_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_33_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL33_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_33_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_34_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL34_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL34_1 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL34_2 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL34_3 : 2;
            uint8_t                     : 6;
        } FILCLKSEL_34_b;
    };
    __IM uint8_t RESERVED77[4];
    union
    {
        __IOM uint32_t FILCLKSEL_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_35_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL35_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL35_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_35_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_35_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL35_H_0 : 2;
            uint8_t                       : 6;
            uint8_t                       : 8;
            uint8_t                       : 8;
            uint8_t                       : 8;
        } FILCLKSEL_35_H_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_36_L_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL36_L_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_L_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_L_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_L_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_36_L_b;
    };
    union
    {
        __IOM uint32_t FILCLKSEL_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_36_H_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL36_H_0 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_H_1 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_H_2 : 2;
            uint8_t                       : 6;
            __IOM uint8_t FILCLKSEL36_H_3 : 2;
            uint8_t                       : 6;
        } FILCLKSEL_36_H_b;
    };
    __IM uint8_t RESERVED78[40];
    union
    {
        __IOM uint32_t FILCLKSEL_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } FILCLKSEL_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } FILCLKSEL_3C_byte;
        struct
        {
            __IOM uint8_t FILCLKSEL3C_0 : 2;
            uint8_t                     : 6;
            __IOM uint8_t FILCLKSEL3C_1 : 2;
            uint8_t                     : 6;
            uint8_t                     : 8;
            uint8_t                     : 8;
        } FILCLKSEL_3C_b;
    };
    __IM uint8_t RESERVED79[812];
    union
    {
        __IOM uint32_t ISEL_22;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_22_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_22_byte;
        struct
        {
            __IOM uint8_t ISEL22_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL22_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL_22_b;
    };
    __IM uint8_t RESERVED80[4];
    union
    {
        __IOM uint32_t ISEL_23_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_23_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_23_L_byte;
        struct
        {
            __IOM uint8_t ISEL23_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL23_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL23_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL23_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_23_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_23_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_23_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_23_H_byte;
        struct
        {
            __IOM uint8_t ISEL23_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL23_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL23_H_2 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
        } ISEL_23_H_b;
    };
    __IM uint8_t RESERVED81[8];
    union
    {
        __IOM uint32_t ISEL_25_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_25_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_25_L_byte;
        struct
        {
            __IOM uint8_t ISEL25_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_25_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_25_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_25_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_25_H_byte;
        struct
        {
            __IOM uint8_t ISEL25_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL25_H_2 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
        } ISEL_25_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_26_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_26_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_26_L_byte;
        struct
        {
            __IOM uint8_t ISEL26_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL26_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL26_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL26_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_26_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_26_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_26_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_26_H_byte;
        struct
        {
            __IOM uint8_t ISEL26_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL26_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL26_H_2 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
        } ISEL_26_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_27_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_27_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_27_L_byte;
        struct
        {
            __IOM uint8_t ISEL27_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_27_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_27_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_27_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_27_H_byte;
        struct
        {
            __IOM uint8_t ISEL27_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL27_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_27_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_28_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_28_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_28_L_byte;
        struct
        {
            __IOM uint8_t ISEL28_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL28_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL28_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL28_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_28_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_28_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_28_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_28_H_byte;
        struct
        {
            __IOM uint8_t ISEL28_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL28_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_28_H_b;
    };
    __IM uint8_t RESERVED82[8];
    union
    {
        __IOM uint32_t ISEL_2A_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2A_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2A_L_byte;
        struct
        {
            __IOM uint8_t ISEL2A_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_2A_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_2A_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2A_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2A_H_byte;
        struct
        {
            __IOM uint8_t ISEL2A_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2A_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_2A_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_2B_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2B_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2B_L_byte;
        struct
        {
            __IOM uint8_t ISEL2B_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_2B_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_2B_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2B_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2B_H_byte;
        struct
        {
            __IOM uint8_t ISEL2B_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2B_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_2B_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_2C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2C_byte;
        struct
        {
            __IOM uint8_t ISEL2C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2C_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2C_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL_2C_b;
    };
    __IM uint8_t RESERVED83[4];
    union
    {
        __IOM uint32_t ISEL_2D_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2D_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2D_L_byte;
        struct
        {
            __IOM uint8_t ISEL2D_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_2D_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_2D_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2D_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2D_H_byte;
        struct
        {
            __IOM uint8_t ISEL2D_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2D_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_2D_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_2E_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2E_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2E_L_byte;
        struct
        {
            __IOM uint8_t ISEL2E_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_2E_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_2E_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2E_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2E_H_byte;
        struct
        {
            __IOM uint8_t ISEL2E_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL2E_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_2E_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_2F;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_2F_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_2F_byte;
        struct
        {
            __IOM uint8_t ISEL2F_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2F_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL2F_2 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
        } ISEL_2F_b;
    };
    __IM uint8_t RESERVED84[4];
    union
    {
        __IOM uint32_t ISEL_30_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_30_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_30_L_byte;
        struct
        {
            __IOM uint8_t ISEL30_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_30_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_30_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_30_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_30_H_byte;
        struct
        {
            __IOM uint8_t ISEL30_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL30_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_30_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_31_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_31_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_31_L_byte;
        struct
        {
            __IOM uint8_t ISEL31_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL31_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL31_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL31_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_31_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_31_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_31_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_31_H_byte;
        struct
        {
            __IOM uint8_t ISEL31_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL31_H_1 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_31_H_b;
    };
    __IM uint8_t RESERVED85[8];
    union
    {
        __IOM uint32_t ISEL_33_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_33_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_33_L_byte;
        struct
        {
            __IOM uint8_t ISEL33_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL33_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_33_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_33_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_33_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_33_H_byte;
        struct
        {
            __IOM uint8_t ISEL33_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_33_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_34;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_34_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_34_byte;
        struct
        {
            __IOM uint8_t ISEL34_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL34_1 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL34_2 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL34_3 : 1;
            uint8_t                : 7;
        } ISEL_34_b;
    };
    __IM uint8_t RESERVED86[4];
    union
    {
        __IOM uint32_t ISEL_35_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_35_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_35_L_byte;
        struct
        {
            __IOM uint8_t ISEL35_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL35_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_35_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_35_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_35_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_35_H_byte;
        struct
        {
            __IOM uint8_t ISEL35_H_0 : 1;
            uint8_t                  : 7;
            uint8_t                  : 8;
            uint8_t                  : 8;
            uint8_t                  : 8;
        } ISEL_35_H_b;
    };
    union
    {
        __IOM uint32_t ISEL_36_L;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_36_L_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_36_L_byte;
        struct
        {
            __IOM uint8_t ISEL36_L_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_L_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_L_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_L_3 : 1;
            uint8_t                  : 7;
        } ISEL_36_L_b;
    };
    union
    {
        __IOM uint32_t ISEL_36_H;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_36_H_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_36_H_byte;
        struct
        {
            __IOM uint8_t ISEL36_H_0 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_H_1 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_H_2 : 1;
            uint8_t                  : 7;
            __IOM uint8_t ISEL36_H_3 : 1;
            uint8_t                  : 7;
        } ISEL_36_H_b;
    };
    __IM uint8_t RESERVED87[40];
    union
    {
        __IOM uint32_t ISEL_3C;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ISEL_3C_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ISEL_3C_byte;
        struct
        {
            __IOM uint8_t ISEL3C_0 : 1;
            uint8_t                : 7;
            __IOM uint8_t ISEL3C_1 : 1;
            uint8_t                : 7;
            uint8_t                : 8;
            uint8_t                : 8;
        } ISEL_3C_b;
    };
    __IM uint8_t RESERVED88[540];
    union
    {
        __IOM uint32_t PWPR;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } PWPR_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } PWPR_byte;
        struct
        {
            uint8_t             : 6;
            __IOM uint8_t PFCWE : 1;
            __IOM uint8_t B0WI  : 1;
            uint8_t             : 8;
            uint8_t             : 8;
            uint8_t             : 8;
        } PWPR_b;
    };
    union
    {
        __IOM uint32_t SD_CH0_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_CH0_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_CH0_POC_byte;
        struct
        {
            __IOM uint8_t SD0_POC : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SD_CH0_POC_b;
    };
    union
    {
        __IOM uint32_t SD_CH1_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_CH1_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_CH1_POC_byte;
        struct
        {
            __IOM uint8_t SD1_POC : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SD_CH1_POC_b;
    };
    union
    {
        __IOM uint32_t XSPI_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } XSPI_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } XSPI_POC_byte;
        struct
        {
            __IOM uint8_t XSPI_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } XSPI_POC_b;
    };
    union
    {
        __IOM uint32_t ETH0_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH0_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH0_POC_byte;
        struct
        {
            __IOM uint8_t ETH0_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } ETH0_POC_b;
    };
    union
    {
        __IOM uint32_t ETH1_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH1_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH1_POC_byte;
        struct
        {
            __IOM uint8_t ETH1_POC : 2;
            uint8_t                : 6;
            uint8_t                : 8;
            uint8_t                : 8;
            uint8_t                : 8;
        } ETH1_POC_b;
    };
    union
    {
        __IOM uint32_t ETH_MODE;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } ETH_MODE_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } ETH_MODE_byte;
        struct
        {
            __IOM uint8_t OEN0 : 1;
            __IOM uint8_t OEN1 : 1;
            uint8_t            : 6;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } ETH_MODE_b;
    };
    union
    {
        __IOM uint32_t I3C_SET;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } I3C_SET_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } I3C_SET_byte;
        struct
        {
            __IOM uint8_t STBN : 1;
            uint8_t            : 1;
            __IOM uint8_t POC  : 1;
            uint8_t            : 5;
            uint8_t            : 8;
            uint8_t            : 8;
            uint8_t            : 8;
        } I3C_SET_b;
    };
    union
    {
        __IOM uint32_t XSPI_HIZ;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } XSPI_HIZ_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } XSPI_HIZ_byte;
        struct
        {
            __IOM uint8_t SORST_N : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } XSPI_HIZ_b;
    };
    union
    {
        __IOM uint32_t SD_CH2_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } SD_CH2_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } SD_CH2_POC_byte;
        struct
        {
            __IOM uint8_t SD2_POC : 1;
            uint8_t               : 7;
            uint8_t               : 8;
            uint8_t               : 8;
            uint8_t               : 8;
        } SD_CH2_POC_b;
    };
    union
    {
        __IOM uint32_t OTHER_POC;
        struct
        {
            __IOM uint16_t L;
            __IOM uint16_t H;
        } OTHER_POC_hword;
        struct
        {
            __IOM uint8_t LL;
            __IOM uint8_t LH;
            __IOM uint8_t HL;
            __IOM uint8_t HH;
        } OTHER_POC_byte;
        struct
        {
            __IOM uint8_t PVDD1833_OTH_AWO_POC : 1;
            __IOM uint8_t PVDD1833_OTH_ISO_POC : 1;
            __IOM uint8_t WDTOVF_N_POC         : 1;
            uint8_t                            : 5;
            uint8_t                            : 8;
            uint8_t                            : 8;
            uint8_t                            : 8;
        } OTHER_POC_b;
    };
} R_GPIO_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_GPIO_BASE    0x41030000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_GPIO    ((R_GPIO_Type *) R_GPIO_BASE)

#endif
