/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : mhu_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for mhu.
 *********************************************************************************************************************/

/* ================================================================================================================= */
/* ================                              Device Specific Cluster Section                              ====== */
/* ================================================================================================================= */

/* ================================================================================================================= */
/* ================                            Device Specific Peripheral Section                             ====== */
/* ================================================================================================================= */

#ifndef MHU_IODEFINE_H
#define MHU_IODEFINE_H

typedef struct
{
    union
    {
        __IM uint32_t MSG_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } MSG_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t MSG_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } MSG_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t MSG_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } MSG_INT_CLRn_b;
    };

    __IM uint8_t RESERVED[4];
    union
    {
        __IM uint32_t RSP_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } RSP_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t RSP_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } RSP_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t RSP_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } RSP_INT_CLRn_b;
    };
} R_MHU0_Type;

typedef struct
{
    union
    {
        __IM uint32_t SW_INT_STSn;
        struct
        {
            __IM uint32_t STAT : 1;
            uint32_t           : 31;
        } SW_INT_STSn_b;
    };

    union
    {
        __IOM uint32_t SW_INT_SETn;
        struct
        {
            __IOM uint32_t SET : 1;
            uint32_t           : 31;
        } SW_INT_SETn_b;
    };

    union
    {
        __IOM uint32_t SW_INT_CLRn;
        struct
        {
            __IOM uint32_t CLEAR : 1;
            uint32_t             : 31;
        } SW_INT_CLRn_b;
    };
} R_MHU_SWINT0_Type;

/* ================================================================================================================= */
/* ================                          Device Specific Peripheral Address Map                           ====== */
/* ================================================================================================================= */

#define R_MHU_NS0_BASE       0x50400000
#define R_MHU_NS1_BASE       0x50400020
#define R_MHU_NS2_BASE       0x50400040
#define R_MHU_NS3_BASE       0x50400060
#define R_MHU_NS4_BASE       0x50400080
#define R_MHU_NS5_BASE       0x504000A0
#define R_MHU_NS6_BASE       0x504000C0
#define R_MHU_NS7_BASE       0x504000E0
#define R_MHU_NS8_BASE       0x50400100
#define R_MHU_NS9_BASE       0x50400120
#define R_MHU_NS10_BASE      0x50400140
#define R_MHU_NS11_BASE      0x50400160
#define R_MHU_NS12_BASE      0x50400180
#define R_MHU_NS13_BASE      0x504001A0
#define R_MHU_NS14_BASE      0x504001C0
#define R_MHU_NS15_BASE      0x504001E0
#define R_MHU_NS16_BASE      0x50400200
#define R_MHU_NS17_BASE      0x50400220
#define R_MHU_NS18_BASE      0x50400240
#define R_MHU_NS19_BASE      0x50400260

#define R_MHU_SWINT0_BASE    0x50400800
#define R_MHU_SWINT1_BASE    0x50400810
#define R_MHU_SWINT2_BASE    0x50400820
#define R_MHU_SWINT3_BASE    0x50400830
#define R_MHU_SWINT4_BASE    0x50480840
#define R_MHU_SWINT5_BASE    0x50480850
#define R_MHU_SWINT6_BASE    0x50480860
#define R_MHU_SWINT7_BASE    0x50480870

#define R_MHU_S0_BASE        0x40401000
#define R_MHU_S1_BASE        0x40401020
#define R_MHU_S2_BASE        0x40401040
#define R_MHU_S3_BASE        0x40401060
#define R_MHU_S4_BASE        0x40401080
#define R_MHU_S5_BASE        0x404010A0
#define R_MHU_S6_BASE        0x404010C0
#define R_MHU_S7_BASE        0x404010E0
#define R_MHU_S8_BASE        0x40401100
#define R_MHU_S9_BASE        0x40401120
#define R_MHU_S10_BASE       0x40401140
#define R_MHU_S11_BASE       0x40401160
#define R_MHU_S12_BASE       0x40401180
#define R_MHU_S13_BASE       0x404011A0
#define R_MHU_S14_BASE       0x404011C0
#define R_MHU_S15_BASE       0x404011E0
#define R_MHU_S16_BASE       0x40401200
#define R_MHU_S17_BASE       0x40401220
#define R_MHU_S18_BASE       0x40401240
#define R_MHU_S19_BASE       0x40401260

/* ================================================================================================================= */
/* ================                                  Peripheral declaration                                   ====== */
/* ================================================================================================================= */

#define R_MHU_NS0       ((R_MHU0_Type *) R_MHU_NS0_BASE)
#define R_MHU_NS1       ((R_MHU0_Type *) R_MHU_NS1_BASE)
#define R_MHU_NS2       ((R_MHU0_Type *) R_MHU_NS2_BASE)
#define R_MHU_NS3       ((R_MHU0_Type *) R_MHU_NS3_BASE)
#define R_MHU_NS4       ((R_MHU0_Type *) R_MHU_NS4_BASE)
#define R_MHU_NS5       ((R_MHU0_Type *) R_MHU_NS5_BASE)
#define R_MHU_NS6       ((R_MHU0_Type *) R_MHU_NS6_BASE)
#define R_MHU_NS7       ((R_MHU0_Type *) R_MHU_NS7_BASE)
#define R_MHU_NS8       ((R_MHU0_Type *) R_MHU_NS8_BASE)
#define R_MHU_NS9       ((R_MHU0_Type *) R_MHU_NS9_BASE)
#define R_MHU_NS10      ((R_MHU0_Type *) R_MHU_NS10_BASE)
#define R_MHU_NS11      ((R_MHU0_Type *) R_MHU_NS11_BASE)
#define R_MHU_NS12      ((R_MHU0_Type *) R_MHU_NS12_BASE)
#define R_MHU_NS13      ((R_MHU0_Type *) R_MHU_NS13_BASE)
#define R_MHU_NS14      ((R_MHU0_Type *) R_MHU_NS14_BASE)
#define R_MHU_NS15      ((R_MHU0_Type *) R_MHU_NS15_BASE)
#define R_MHU_NS16      ((R_MHU0_Type *) R_MHU_NS16_BASE)
#define R_MHU_NS17      ((R_MHU0_Type *) R_MHU_NS17_BASE)
#define R_MHU_NS18      ((R_MHU0_Type *) R_MHU_NS18_BASE)
#define R_MHU_NS19      ((R_MHU0_Type *) R_MHU_NS19_BASE)
#define R_MHU_SWINT0    ((R_MHU_SWINT0_Type *) R_MHU_SWINT0_BASE)
#define R_MHU_SWINT1    ((R_MHU_SWINT0_Type *) R_MHU_SWINT1_BASE)
#define R_MHU_SWINT2    ((R_MHU_SWINT0_Type *) R_MHU_SWINT2_BASE)
#define R_MHU_SWINT3    ((R_MHU_SWINT0_Type *) R_MHU_SWINT3_BASE)
#define R_MHU_SWINT4    ((R_MHU_SWINT0_Type *) R_MHU_SWINT4_BASE)
#define R_MHU_SWINT5    ((R_MHU_SWINT0_Type *) R_MHU_SWINT5_BASE)
#define R_MHU_SWINT6    ((R_MHU_SWINT0_Type *) R_MHU_SWINT6_BASE)
#define R_MHU_SWINT7    ((R_MHU_SWINT0_Type *) R_MHU_SWINT7_BASE)
#define R_MHU_S0        ((R_MHU0_Type *) R_MHU_S0_BASE)
#define R_MHU_S1        ((R_MHU0_Type *) R_MHU_S1_BASE)
#define R_MHU_S2        ((R_MHU0_Type *) R_MHU_S2_BASE)
#define R_MHU_S3        ((R_MHU0_Type *) R_MHU_S3_BASE)
#define R_MHU_S4        ((R_MHU0_Type *) R_MHU_S4_BASE)
#define R_MHU_S5        ((R_MHU0_Type *) R_MHU_S5_BASE)
#define R_MHU_S6        ((R_MHU0_Type *) R_MHU_S6_BASE)
#define R_MHU_S7        ((R_MHU0_Type *) R_MHU_S7_BASE)
#define R_MHU_S8        ((R_MHU0_Type *) R_MHU_S8_BASE)
#define R_MHU_S9        ((R_MHU0_Type *) R_MHU_S9_BASE)
#define R_MHU_S10       ((R_MHU0_Type *) R_MHU_S10_BASE)
#define R_MHU_S11       ((R_MHU0_Type *) R_MHU_S11_BASE)
#define R_MHU_S12       ((R_MHU0_Type *) R_MHU_S12_BASE)
#define R_MHU_S13       ((R_MHU0_Type *) R_MHU_S13_BASE)
#define R_MHU_S14       ((R_MHU0_Type *) R_MHU_S14_BASE)
#define R_MHU_S15       ((R_MHU0_Type *) R_MHU_S15_BASE)
#define R_MHU_S16       ((R_MHU0_Type *) R_MHU_S16_BASE)
#define R_MHU_S17       ((R_MHU0_Type *) R_MHU_S17_BASE)
#define R_MHU_S18       ((R_MHU0_Type *) R_MHU_S18_BASE)
#define R_MHU_S19       ((R_MHU0_Type *) R_MHU_S19_BASE)

#endif                                 /* MHU_IODEFINE_H */
