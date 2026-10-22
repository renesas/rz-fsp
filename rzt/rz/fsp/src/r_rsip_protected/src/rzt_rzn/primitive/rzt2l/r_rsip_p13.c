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

rsip_ret_t r_rsip_p13 (uint32_t const InData_DomainParam[],
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

    WR1_PROG(REG_1B00H, 0x00130002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10700000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x13400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x17f00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18400000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x18900000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0x981f3568U),
                   bswap_32big(0x6206c65aU),
                   bswap_32big(0xf89a11c4U),
                   bswap_32big(0x577853eaU));
    r_rsip_func074(InData_DomainParam);
    r_rsip_func100(bswap_32big(0xbda29d6bU),
                   bswap_32big(0x344b1448U),
                   bswap_32big(0xd86b1e8aU),
                   bswap_32big(0xc46eea9eU));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x09090010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x09090010U);
    WR1_PROG(REG_1404H, 0x12a00000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x5abc8a72U),
                   bswap_32big(0x4121d672U),
                   bswap_32big(0xab7c579eU),
                   bswap_32big(0xaa7f5211U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80020000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420009U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00008c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000001ffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x81020000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00c90009U);
    r_rsip_subfunc003(0x00c20009U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x824f768bU),
                   bswap_32big(0xa9eb1592U),
                   bswap_32big(0x76609e47U),
                   bswap_32big(0xbe0c4367U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x9f6a2c08U),
                   bswap_32big(0x02a03c5fU),
                   bswap_32big(0x2a5711eaU),
                   bswap_32big(0x6b7abc27U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xb27f4732U),
                   bswap_32big(0x22c8d80cU),
                   bswap_32big(0xe025e3bcU),
                   bswap_32big(0x30dbb930U));
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
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0909000aU);
    WR1_PROG(REG_1404H, 0x11180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc003(0x00c00009U);
    r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000250U, 0x09090007U);
    r_rsip_func100(bswap_32big(0x15c8e300U),
                   bswap_32big(0xd4172701U),
                   bswap_32big(0x8f6eeaa2U),
                   bswap_32big(0xb4ec151cU));
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000863U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12000000U);
    WR1_PROG(REG_1608H, 0x80940001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430051U);
    for (iLoop = 0; iLoop < 20; iLoop = iLoop + 1)
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

    WR1_PROG(REG_1404H, 0x14300000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0004dU);
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
        r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000250U, 0x0a0a0007U);
        r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x0a0a0009U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x37d231adU), bswap_32big(0x926114c9U), bswap_32big(0xf1f3a08bU),
                       bswap_32big(0xfccc2391U));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_func100(bswap_32big(0x471b5850U),
                   bswap_32big(0x990c45f2U),
                   bswap_32big(0xeb12d5e2U),
                   bswap_32big(0x8cf3bdf3U));
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
        r_rsip_subfunc001(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0a0a000aU);
        WR1_PROG(REG_143CH, 0x00a10000U);
        r_rsip_func100(bswap_32big(0xe6ed0786U), bswap_32big(0x23dff1ddU), bswap_32big(0x121aa4aeU),
                       bswap_32big(0x32ef6fd1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x0a0a0009U);
            r_rsip_func101(bswap_32big(0x9a9784fbU), bswap_32big(0x322a4033U), bswap_32big(0xfe8e3b52U),
                           bswap_32big(0x262ecb3dU));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0a0a000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x0a0a0009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x3607f284U), bswap_32big(0xc968d5bdU), bswap_32big(0xeea9cdc7U),
                       bswap_32big(0x7b7f2092U));
    }

    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10c80000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c00045U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000340U, 0x09090009U);
    WR1_PROG(REG_1404H, 0x11600000U);
    r_rsip_subfunc003(0x00c000f1U);
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0x499fe10fU),
                   bswap_32big(0x828101a5U),
                   bswap_32big(0x5419253eU),
                   bswap_32big(0x10d1247aU));
    r_rsip_func075(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0x39d1da87U),
                   bswap_32big(0x3b9d615bU),
                   bswap_32big(0xb4e365bdU),
                   bswap_32big(0x34b6bdabU));
    r_rsip_func072();
    r_rsip_func100(bswap_32big(0x882b6bf8U),
                   bswap_32big(0x0bb67ea1U),
                   bswap_32big(0xd010fda2U),
                   bswap_32big(0x2f819652U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x4090b859U), bswap_32big(0xa78c3d28U), bswap_32big(0x5ccd18d6U),
                       bswap_32big(0x7f266051U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x1d72236fU), bswap_32big(0xa5b08557U), bswap_32big(0x4c1c72d0U),
                       bswap_32big(0xed1e9e17U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00001301U));
        r_rsip_func101(bswap_32big(0x13a0514dU), bswap_32big(0x0f625ad1U), bswap_32big(0x9d2b0cb4U),
                       bswap_32big(0xa8ceed13U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01accfebU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00001301U));
        r_rsip_func101(bswap_32big(0x6255e7b0U), bswap_32big(0xf3e790a0U), bswap_32big(0x59bd39dbU),
                       bswap_32big(0x87564775U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xbbd7e84cU), bswap_32big(0x4164f376U), bswap_32big(0xe7f4144cU),
                       bswap_32big(0xc50ecccbU));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1404H, 0x12f80000U);
        r_rsip_subfunc003(0x00800009U);
        r_rsip_subfunc003(0x00830029U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0xcc2dbe1dU), bswap_32big(0x8b3f3788U), bswap_32big(0x69b2f13dU),
                       bswap_32big(0xf8c31aa2U));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_subfunc003(0x00830021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 4]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 5]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 6]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 8]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 9]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 10]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 11]);
        r_rsip_func100(bswap_32big(0xf1ef0f3aU), bswap_32big(0x32c2f6c3U), bswap_32big(0x56ac6a40U),
                       bswap_32big(0x8a3f1bcdU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 12]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 13]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 14]);
        RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[iLoop + 15]);
        r_rsip_func100(bswap_32big(0x744802b2U), bswap_32big(0x65c95907U), bswap_32big(0x19ac3206U),
                       bswap_32big(0xd0498d8dU));
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
        r_rsip_func100(bswap_32big(0x368557caU), bswap_32big(0xd3cc78caU), bswap_32big(0xecacd7c6U),
                       bswap_32big(0x111b116aU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00001302U));
        r_rsip_func101(bswap_32big(0xbd2dda42U), bswap_32big(0xcf12d8edU), bswap_32big(0x7defc4fdU),
                       bswap_32big(0x9e37cb44U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f7ab4bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00001302U));
        r_rsip_func101(bswap_32big(0xb2f66fafU), bswap_32big(0x2ad6b9c0U), bswap_32big(0xfadfced4U),
                       bswap_32big(0x7e598badU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xbaddc01bU), bswap_32big(0x1c8db05bU), bswap_32big(0x00e81dd9U),
                       bswap_32big(0xcdd5ba4eU));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8009107U);
        WR1_PROG(REG_1404H, 0x12580000U);
        r_rsip_subfunc003(0x00800009U);
        r_rsip_subfunc003(0x00830029U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0x1b57d5e5U), bswap_32big(0xae987ef4U), bswap_32big(0x9a1d2832U),
                       bswap_32big(0x3bec3355U));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_subfunc003(0x00830021U);
        WR1_PROG(REG_1404H, 0x12a80000U);
        r_rsip_subfunc003(0x00800009U);
        r_rsip_subfunc003(0x00830009U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 12; iLoop < 24; iLoop = iLoop + 4)
        {
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[iLoop + 7]);
        }

        r_rsip_func100(bswap_32big(0x4d8bd117U), bswap_32big(0xb9881542U), bswap_32big(0x2bc0250aU),
                       bswap_32big(0x034fd0bdU));
        WR1_PROG(REG_1A2CH, 0x40000200U);
        WR1_PROG(REG_1A24H, 0xe8008107U);
        r_rsip_subfunc003(0x00830031U);
        WR1_PROG(REG_1408H, 0x00002032U);
        for (iLoop = 24; iLoop < 36; iLoop = iLoop + 4)
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
        r_rsip_func100(bswap_32big(0x56db0608U), bswap_32big(0xde5730aaU), bswap_32big(0xe9475f21U),
                       bswap_32big(0xb971a551U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[40]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[41]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[42]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[43]);
        r_rsip_func100(bswap_32big(0xe73fca7aU), bswap_32big(0xd64b13ecU), bswap_32big(0xba9b762dU),
                       bswap_32big(0x2a0e6e9cU));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c100104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[44]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[45]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[46]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[47]);
        r_rsip_func100(bswap_32big(0x7a3b2a71U), bswap_32big(0x2c268e2fU), bswap_32big(0x77561a4aU),
                       bswap_32big(0xa255f4ceU));
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
        r_rsip_func102(bswap_32big(0x5c74c425U), bswap_32big(0xde7b71d8U), bswap_32big(0x4d9494f7U),
                       bswap_32big(0x15ec9125U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
