/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_rsip_primitive.h"
#include "r_rsip_reg.h"
#include "r_rsip_util.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

RSIP_PRV_PRIMITIVE_FUNC

rsip_ret_t r_rsip_pf9 (uint32_t const InData_CurveType[],
                       uint32_t const InData_DomainParam[],
                       uint32_t       OutData_PubKeyIndex[],
                       uint32_t       OutData_PrivKeyIndex[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00f90002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0xb67598e3U),
                   bswap_32big(0x1209ce75U),
                   bswap_32big(0x087343d9U),
                   bswap_32big(0x09cbc7daU));
    r_rsip_func027(InData_DomainParam);
    r_rsip_func100(bswap_32big(0xf9e68ebdU),
                   bswap_32big(0x3f57bd37U),
                   bswap_32big(0xcd1df2a8U),
                   bswap_32big(0xf2ce6525U));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x06060010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x06060010U);
    WR1_PROG(REG_1404H, 0x12b80000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x1e7c71edU),
                   bswap_32big(0xa1892276U),
                   bswap_32big(0xe4e090f5U),
                   bswap_32big(0x53a800f2U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa42ff46dU),
                   bswap_32big(0x7d663708U),
                   bswap_32big(0x5327c4f5U),
                   bswap_32big(0xf409e4aeU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x80c0880fU),
                   bswap_32big(0x6666ceacU),
                   bswap_32big(0xfe3b7dd2U),
                   bswap_32big(0x06620392U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20009U);
    r_rsip_subfunc003(0x00020009U);
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0606000aU);
    WR1_PROG(REG_1404H, 0x11280000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc003(0x00c00009U);
    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000250U, 0x06060007U);
    r_rsip_func100(bswap_32big(0x1a45ab91U),
                   bswap_32big(0xf10ed537U),
                   bswap_32big(0x6ab78db3U),
                   bswap_32big(0x6aeeea9dU));
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000863U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12180000U);
    WR1_PROG(REG_1608H, 0x808e0001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430039U);
    for (iLoop = 0; iLoop < 14; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1600H, 0x38000c63U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x20000842U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x10003841U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b7c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000001fU);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (jLoop = 0; jLoop < 32; jLoop = jLoop + 1)
        {
            WR1_PROG(REG_1600H, 0x3800585eU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x20003460U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x20002c60U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x10002c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x100033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
        }

        WR1_PROG(REG_1600H, 0x0000a420U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1404H, 0x14480000U);
    r_rsip_subfunc003(0x00c00039U);
    r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);
    WR1_PROG(REG_1404H, 0x10d80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c00035U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1600H, 0x00003403U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000250U, 0x07070007U);
        r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x265b7dc9U), bswap_32big(0x92a79882U), bswap_32big(0xd3762707U),
                       bswap_32big(0xac611e9dU));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10d80000U);
    r_rsip_subfunc003(0x00c00039U);
    r_rsip_func100(bswap_32big(0xdae4e654U),
                   bswap_32big(0x7b8438c8U),
                   bswap_32big(0xa4d59b02U),
                   bswap_32big(0x8420b743U));
    WR1_PROG(REG_1600H, 0x0000a400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1408H, 0x00005006U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
    for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 1)
    {
        r_rsip_subfunc001(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0707000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        r_rsip_func100(bswap_32big(0x4d2c8672U), bswap_32big(0xe70d8c43U), bswap_32big(0x131543ccU),
                       bswap_32big(0xb0cb794cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x07070009U);
            r_rsip_func101(bswap_32big(0x8ad91bb9U), bswap_32big(0x664f83bcU), bswap_32big(0x72072102U),
                           bswap_32big(0xfe49cb2aU));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0707000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x07070009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x63891c16U), bswap_32big(0xc15c73e3U), bswap_32big(0x73738e96U),
                       bswap_32big(0xcedcf429U));
    }

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000340U, 0x06060009U);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0x57211b4cU),
                   bswap_32big(0xac210838U),
                   bswap_32big(0x38adcad3U),
                   bswap_32big(0x0e61c12aU));
    r_rsip_func028(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x000000f9U));
    r_rsip_func101(bswap_32big(0x3dc6e4b5U),
                   bswap_32big(0x40cfc58bU),
                   bswap_32big(0xe703ebf7U),
                   bswap_32big(0x046c311aU));
    r_rsip_func089();
    r_rsip_func100(bswap_32big(0x3086144dU),
                   bswap_32big(0xbfb67a90U),
                   bswap_32big(0x9254c1c9U),
                   bswap_32big(0x5db27e37U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x08e1275aU), bswap_32big(0xb61b8921U), bswap_32big(0x2ef6fb06U),
                       bswap_32big(0x10e0f900U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x660378c4U), bswap_32big(0xfd348d1cU), bswap_32big(0xb1da54edU),
                       bswap_32big(0x90ba83e4U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x0000f901U));
        r_rsip_func101(bswap_32big(0x382e2fb0U), bswap_32big(0xd7c61205U), bswap_32big(0xd9ea13cdU),
                       bswap_32big(0x769c79bfU));
        r_rsip_func045();
        r_rsip_func076();
        r_rsip_subfunc009(bswap_32big(0x0000f901U));
        r_rsip_func101(bswap_32big(0x1e8fa6a5U), bswap_32big(0x2393c5f6U), bswap_32big(0x17d0c189U),
                       bswap_32big(0x5951963fU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x75a342a6U), bswap_32big(0x871cd635U), bswap_32big(0x14298382U),
                       bswap_32big(0x377ff174U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x13100000U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[8]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[9]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[10]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[11]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[12]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[14]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[15]);
        r_rsip_func100(bswap_32big(0xfa6e6e7fU), bswap_32big(0x74b6b2d2U), bswap_32big(0x5fc48a70U),
                       bswap_32big(0x8fdb8434U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[16]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[17]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[18]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[19]);
        r_rsip_func100(bswap_32big(0x479b8623U), bswap_32big(0x39f9301bU), bswap_32big(0x6496bceaU),
                       bswap_32big(0x554a7d1eU));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[3]);
        r_rsip_func100(bswap_32big(0x67792df2U), bswap_32big(0x1c643b17U), bswap_32big(0x7a0c44b2U),
                       bswap_32big(0xb087efa9U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x0000f902U));
        r_rsip_func101(bswap_32big(0xb4cd4b1dU), bswap_32big(0x2b8bdfe0U), bswap_32big(0xb86f60a5U),
                       bswap_32big(0xc4e70de0U));
        r_rsip_func045();
        r_rsip_func077();
        r_rsip_subfunc009(bswap_32big(0x0000f902U));
        r_rsip_func101(bswap_32big(0x8edaed65U), bswap_32big(0x29d0d7d2U), bswap_32big(0x702c384fU),
                       bswap_32big(0x624233d6U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xe2fe09f9U), bswap_32big(0xb0d3f96fU), bswap_32big(0x86f36580U),
                       bswap_32big(0xc6d33889U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12700000U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0xcdc8a6f8U), bswap_32big(0x256d621fU), bswap_32big(0x2efa2af0U),
                       bswap_32big(0x7097fdb9U));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        WR1_PROG(REG_1404H, 0x12c00000U);
        r_rsip_subfunc003(0x00830021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        for (iLoop = 12; iLoop < 20; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x49108054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func100(bswap_32big(0xa30e83b4U), bswap_32big(0x42624f85U), bswap_32big(0xd10f3b60U),
                       bswap_32big(0x00f0f39fU));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[24]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[25]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[26]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[27]);
        r_rsip_func100(bswap_32big(0xb0acc9f3U), bswap_32big(0x3161946aU), bswap_32big(0xa0debb9dU),
                       bswap_32big(0xd7c376efU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[28]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[29]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[30]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[31]);
        r_rsip_func100(bswap_32big(0x0f2d8ee3U), bswap_32big(0x6fac63a5U), bswap_32big(0xcb8d1d9fU),
                       bswap_32big(0x83275d01U));
        WR1_PROG(REG_1608H, 0x81040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[0]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[1]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[2]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[3]);
        r_rsip_func102(bswap_32big(0xac7424d8U), bswap_32big(0x80912317U), bswap_32big(0xc1a7d834U),
                       bswap_32big(0x68eaee71U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
