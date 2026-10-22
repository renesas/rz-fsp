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

rsip_ret_t r_rsip_pf4 (uint32_t const InData_CurveType[],
                       uint32_t const InData_Cmd[],
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

    WR1_PROG(REG_1B00H, 0x00f40002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010380U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3020ab80U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00060020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b780U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x30000f5aU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00030020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000060U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000f9cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000d3e1U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008be0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x30fa7155U),
                   bswap_32big(0x45b5eef5U),
                   bswap_32big(0xdf98e31fU),
                   bswap_32big(0xf00841b4U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x2e8232b3U), bswap_32big(0x6a2a20deU), bswap_32big(0x08707ef6U),
                       bswap_32big(0xb4fc048dU));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
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
        r_rsip_subfunc009(bswap_32big(0x000000f4U));
        r_rsip_func101(bswap_32big(0xe8bf046fU), bswap_32big(0x73d6d013U), bswap_32big(0xcd18525cU),
                       bswap_32big(0x1c5a569cU));
        r_rsip_func086(InData_DomainParam);
        r_rsip_func100(bswap_32big(0x4a09893bU), bswap_32big(0xb53e9299U), bswap_32big(0x5956782dU),
                       bswap_32big(0xbc88223fU));
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
        WR1_PROG(REG_1404H, 0x12c80000U);
        WR1_PROG(REG_1600H, 0x00007c1cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x15ca488cU), bswap_32big(0x5fd3aa5aU), bswap_32big(0xea606fdeU),
                           bswap_32big(0xe0dc8b94U));
            r_rsip_subfunc003(0x00c00009U);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20009U);
            r_rsip_subfunc003(0x00020009U);
            r_rsip_func101(bswap_32big(0xb05e7ea3U), bswap_32big(0xd4ff44b2U), bswap_32big(0xf9df510eU),
                           bswap_32big(0xe7100a18U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x12d1b596U), bswap_32big(0x627b646eU), bswap_32big(0x861c2937U),
                           bswap_32big(0xae70b41cU));
            r_rsip_subfunc003(0x00c0000dU);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_func101(bswap_32big(0x75ff0adeU), bswap_32big(0x0c63be5fU), bswap_32big(0x9c2f17cbU),
                           bswap_32big(0x71cf5bedU));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc003(0x00c00011U);
            r_rsip_func101(bswap_32big(0xffc9ab8bU), bswap_32big(0xb2d76d18U), bswap_32big(0x9812d0e8U),
                           bswap_32big(0x6b56bedbU));
        }

        r_rsip_func100(bswap_32big(0xd9112dc1U), bswap_32big(0x3227ea00U), bswap_32big(0x0e3975c9U),
                       bswap_32big(0x02923e0cU));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x46f86af9U), bswap_32big(0x7629d2acU), bswap_32big(0xea269743U),
                       bswap_32big(0x7c21a54dU));
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
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0001dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000000c0U, 0x00000110U, 0x000001b0U, 0x0404000aU);
        WR1_PROG(REG_1444H, 0x000009b0U);
        WR1_PROG(REG_0138H, bswap_32big(0x00000000U));
        WR1_PROG(REG_013CH, bswap_32big(0x00000000U));
        WR1_PROG(REG_0140H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0144H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0148H, bswap_32big(0x00000000U));
        WR1_PROG(REG_014CH, bswap_32big(0x00000000U));
        WR1_PROG(REG_0150H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0154H, bswap_32big(0x00000001U));
        WR1_PROG(REG_0158H, bswap_32big(0x00000000U));
        WR1_PROG(REG_015CH, bswap_32big(0x00000000U));
        r_rsip_subfunc001(0x000001b0U, 0x00000160U, 0x00000250U, 0x04040007U);
        r_rsip_func100(bswap_32big(0xe24fb667U), bswap_32big(0x560820e0U), bswap_32big(0xd8fbeedbU),
                       bswap_32big(0x5fa3a9caU));
        WR1_PROG(REG_1600H, 0x00000800U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000821U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000863U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x12280000U);
        WR1_PROG(REG_1608H, 0x808a0001U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03430029U);
        for (iLoop = 0; iLoop < 10; iLoop = iLoop + 1)
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

        WR1_PROG(REG_1404H, 0x14580000U);
        r_rsip_subfunc003(0x00c00029U);
        r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
        r_rsip_subfunc003(0x00c00025U);
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
            r_rsip_subfunc001(0x000001b0U, 0x00000110U, 0x00000250U, 0x05050007U);
            r_rsip_subfunc001(0x00000250U, 0x00000480U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003060U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9511750dU), bswap_32big(0xd9866371U), bswap_32big(0x52705632U),
                           bswap_32big(0xa8ffca3cU));
        }

        WR1_PROG(REG_1600H, 0x00007c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_subfunc003(0x00c00029U);
        r_rsip_func100(bswap_32big(0xcb491b62U), bswap_32big(0x3fca8ee0U), bswap_32big(0x9f1113f2U),
                       bswap_32big(0x7a689dcdU));
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
            r_rsip_subfunc001(0x000002f0U, 0x000001b0U, 0x00000250U, 0x0505000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x11d2bbd1U), bswap_32big(0x36ccc460U), bswap_32big(0x9f5d77b1U),
                           bswap_32big(0x96591ec7U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x05050009U);
                r_rsip_func101(bswap_32big(0x5ca7b017U),
                               bswap_32big(0x1a7861b0U),
                               bswap_32big(0xd23ba8d7U),
                               bswap_32big(0xe2ddf5c8U));
            }

            r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0505000cU);
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc1ab4bb9U), bswap_32big(0x7033f059U), bswap_32big(0x1dcc9a5dU),
                           bswap_32big(0xa0ba7222U));
        }

        WR1_PROG(REG_1600H, 0x00007c00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10f00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0001dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000002f0U, 0x00000110U, 0x00000340U, 0x04040009U);
        WR1_PROG(REG_1404H, 0x11600000U);
        r_rsip_subfunc003(0x00c000f1U);
        r_rsip_subfunc009(bswap_32big(0x000000f4U));
        r_rsip_func101(bswap_32big(0xa9b69929U), bswap_32big(0x0dddd943U), bswap_32big(0x57be627dU),
                       bswap_32big(0xee23f5faU));
        r_rsip_func087(InData_DomainParam);
        r_rsip_subfunc009(bswap_32big(0x000000f4U));
        r_rsip_func101(bswap_32big(0x824927abU), bswap_32big(0xe50dc3aeU), bswap_32big(0xbff4633eU),
                       bswap_32big(0x888cfa46U));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0xd2d9a4f3U), bswap_32big(0xab36c344U), bswap_32big(0x5474615fU),
                       bswap_32big(0x66b39a2fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x7d077149U), bswap_32big(0xee1af4afU), bswap_32big(0x403ad45bU),
                           bswap_32big(0x8ddae8a4U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xbf1d4c0eU), bswap_32big(0xb3cbdffbU), bswap_32big(0xb8fa6600U),
                           bswap_32big(0x42df261bU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0x33be964dU), bswap_32big(0x6edfe3f2U), bswap_32big(0x8f959e7eU),
                           bswap_32big(0xdb9e407dU));
            r_rsip_func045();
            r_rsip_func022();
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0x57bc01efU), bswap_32big(0x5450f12eU), bswap_32big(0x7ba7f2ecU),
                           bswap_32big(0x399aa5efU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xd21ca818U), bswap_32big(0x09b53439U), bswap_32big(0xca4f5517U),
                           bswap_32big(0xf83939a6U));
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xe7009d07U);
            WR1_PROG(REG_1404H, 0x13200000U);
            r_rsip_subfunc003(0x00830021U);
            WR1_PROG(REG_1408H, 0x00002022U);
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
            r_rsip_func100(bswap_32big(0x554a3cf0U), bswap_32big(0xfb56077bU), bswap_32big(0xc514388cU),
                           bswap_32big(0xdaf53b41U));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x09108105U);
            r_rsip_subfunc003(0x00820011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[12]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[13]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[14]);
            RD1_ADDR(REG_1420H, &OutData_PrivKeyIndex[15]);
            r_rsip_func100(bswap_32big(0x8adbf1c3U), bswap_32big(0x07396eaaU), bswap_32big(0x9f4a597bU),
                           bswap_32big(0x4bd1371aU));
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
            r_rsip_func100(bswap_32big(0x5e7e3b61U), bswap_32big(0x2a32370dU), bswap_32big(0xd49c7744U),
                           bswap_32big(0x02c996b6U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0x7d956d8bU), bswap_32big(0x9fd9a269U), bswap_32big(0x16e01b3eU),
                           bswap_32big(0x83c28a18U));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0x0f7655aeU), bswap_32big(0x4cca4145U), bswap_32big(0x54f5ccb6U),
                           bswap_32big(0xcfe72f14U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x78afeb2bU), bswap_32big(0x7d490dddU), bswap_32big(0x80e50bb9U),
                           bswap_32big(0xe2bfe040U));
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xe8009107U);
            WR1_PROG(REG_1404H, 0x12800000U);
            r_rsip_subfunc003(0x00830021U);
            WR1_PROG(REG_1404H, 0x12d00000U);
            r_rsip_subfunc003(0x00830011U);
            WR1_PROG(REG_1408H, 0x00002032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[4]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[6]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[7]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[12]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[14]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[15]);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x49108054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_func100(bswap_32big(0xddeb63d6U), bswap_32big(0x6eff7c9cU), bswap_32big(0xad9035b6U),
                           bswap_32big(0x53e95729U));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_subfunc003(0x00830011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[16]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[18]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[19]);
            r_rsip_func100(bswap_32big(0xd86693eaU), bswap_32big(0x86402ae3U), bswap_32big(0x524e04abU),
                           bswap_32big(0x5257ba7dU));
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c100104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[20]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[21]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[22]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[23]);
            r_rsip_func100(bswap_32big(0xca08a37fU), bswap_32big(0x253da87cU), bswap_32big(0xa842aa27U),
                           bswap_32big(0xe4a73550U));
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
            r_rsip_func102(bswap_32big(0x80881e9fU), bswap_32big(0xab7bf728U), bswap_32big(0x26762d33U),
                           bswap_32big(0xbd8cc6e6U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
