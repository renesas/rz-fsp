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
    r_rsip_func100(bswap_32big(0xdb05bab0U),
                   bswap_32big(0x38d5e9e1U),
                   bswap_32big(0xc81a69d4U),
                   bswap_32big(0xae88949aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x28bc0137U), bswap_32big(0x021d0608U), bswap_32big(0x4eee7373U),
                       bswap_32big(0xabc63825U));
        WR1_PROG(REG_14B8H, 0x00000040U);
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
        r_rsip_func101(bswap_32big(0x6a475257U), bswap_32big(0xf3f88efdU), bswap_32big(0x9903788cU),
                       bswap_32big(0xa8b11d58U));
        r_rsip_func086(InData_DomainParam);
        r_rsip_func100(bswap_32big(0xb0076695U), bswap_32big(0x1b3dd7ccU), bswap_32big(0x3cd173cfU),
                       bswap_32big(0x3709e467U));
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
        WR1_PROG(REG_1404H, 0x12c80000U);
        WR1_PROG(REG_1600H, 0x00007c1cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x8be2d532U), bswap_32big(0x474cbb89U), bswap_32big(0x7f851123U),
                           bswap_32big(0x3ba5db54U));
            r_rsip_subfunc003(0x00c00009U);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20009U);
            r_rsip_subfunc003(0x00020009U);
            r_rsip_func101(bswap_32big(0x56b1bf90U), bswap_32big(0xa055eb71U), bswap_32big(0x46bb95dcU),
                           bswap_32big(0x047617e0U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xb6825c6bU), bswap_32big(0x2821d7b6U), bswap_32big(0xd84dd215U),
                           bswap_32big(0x4968e8f9U));
            r_rsip_subfunc003(0x00c0000dU);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_func101(bswap_32big(0x2e1127a9U), bswap_32big(0x71f330edU), bswap_32big(0xbb14d725U),
                           bswap_32big(0xe27bd8b9U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc003(0x00c00011U);
            r_rsip_func101(bswap_32big(0xdcb0d9afU), bswap_32big(0x1c550ceaU), bswap_32big(0x02e123acU),
                           bswap_32big(0x05d32b2eU));
        }

        r_rsip_func100(bswap_32big(0x063b247cU), bswap_32big(0x5613f5e9U), bswap_32big(0xa3e130beU),
                       bswap_32big(0xafcb3843U));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0xdfaec132U), bswap_32big(0x64c50729U), bswap_32big(0xa058ea31U),
                       bswap_32big(0x459c24e7U));
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
        r_rsip_func100(bswap_32big(0x758023ecU), bswap_32big(0x140cd420U), bswap_32big(0x98fa66beU),
                       bswap_32big(0x58f51925U));
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
            r_rsip_func101(bswap_32big(0xaddde587U), bswap_32big(0xa73ebe9eU), bswap_32big(0x58428f2cU),
                           bswap_32big(0x1e4f1bcdU));
        }

        WR1_PROG(REG_1600H, 0x00007c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_subfunc003(0x00c00029U);
        r_rsip_func100(bswap_32big(0x5f5357b5U), bswap_32big(0x9905bf61U), bswap_32big(0x8d673f91U),
                       bswap_32big(0x95fd45bbU));
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
            r_rsip_func100(bswap_32big(0x718cde40U), bswap_32big(0xb97ca5e1U), bswap_32big(0x64198059U),
                           bswap_32big(0x3c8a148eU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x05050009U);
                r_rsip_func101(bswap_32big(0x0aed88f0U),
                               bswap_32big(0x98a2f73aU),
                               bswap_32big(0x300515f0U),
                               bswap_32big(0x99ce1994U));
            }

            r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0505000cU);
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2e73258aU), bswap_32big(0x6c424ab6U), bswap_32big(0x4b016805U),
                           bswap_32big(0xc0ead896U));
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
        r_rsip_func101(bswap_32big(0x05e3efacU), bswap_32big(0x186a6499U), bswap_32big(0x6cfb663aU),
                       bswap_32big(0x072f7385U));
        r_rsip_func087(InData_DomainParam);
        r_rsip_subfunc009(bswap_32big(0x000000f4U));
        r_rsip_func101(bswap_32big(0xa7657a17U), bswap_32big(0x647372ccU), bswap_32big(0xcdb76bffU),
                       bswap_32big(0x2bbae605U));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0xeed974bcU), bswap_32big(0xa3e8d692U), bswap_32big(0xda99dd34U),
                       bswap_32big(0xb16c1c9aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x9a4a7224U), bswap_32big(0x50e562b3U), bswap_32big(0xaa0d193fU),
                           bswap_32big(0xd5fced88U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xde5b487aU), bswap_32big(0x732e32c0U), bswap_32big(0x6d3e1ddfU),
                           bswap_32big(0x8cbe2aeeU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0x05f3977eU), bswap_32big(0xe860d836U), bswap_32big(0xe1a4a538U),
                           bswap_32big(0x5506ddc3U));
            r_rsip_func045();
            r_rsip_func022();
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0x29d02ef9U), bswap_32big(0x46e301bbU), bswap_32big(0x992de74cU),
                           bswap_32big(0x1cf8acb2U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xab93b059U), bswap_32big(0x91c45c56U), bswap_32big(0x7b1408fbU),
                           bswap_32big(0x7545586eU));
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
            r_rsip_func100(bswap_32big(0xbe2fcf2aU), bswap_32big(0x172d6132U), bswap_32big(0x57c313fbU),
                           bswap_32big(0x113ac985U));
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
            r_rsip_func100(bswap_32big(0x80d67777U), bswap_32big(0x9937dc91U), bswap_32big(0x533cb877U),
                           bswap_32big(0x079f3bdbU));
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
            r_rsip_func100(bswap_32big(0x0bc6474bU), bswap_32big(0x3dc5d64eU), bswap_32big(0xb6cfc755U),
                           bswap_32big(0x25ce5d95U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0xdba78beaU), bswap_32big(0x08a0a6afU), bswap_32big(0x8d75e0e2U),
                           bswap_32big(0x6d6a8b09U));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0x555da7b3U), bswap_32big(0xb01391c3U), bswap_32big(0x59179a14U),
                           bswap_32big(0x0ff2e63bU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xc02695a9U), bswap_32big(0x8b639126U), bswap_32big(0xb863aac9U),
                           bswap_32big(0xc134a455U));
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
            r_rsip_func100(bswap_32big(0xe7db64b6U), bswap_32big(0xfaf8bb9eU), bswap_32big(0x88d4d99dU),
                           bswap_32big(0x01e3fe3fU));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_subfunc003(0x00830011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[16]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[18]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[19]);
            r_rsip_func100(bswap_32big(0x4d2639eeU), bswap_32big(0x55eb7ad4U), bswap_32big(0x32900112U),
                           bswap_32big(0xd2dd0e95U));
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
            r_rsip_func100(bswap_32big(0x05dca8a5U), bswap_32big(0x3378f6a5U), bswap_32big(0xc077a703U),
                           bswap_32big(0x03fc1d40U));
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
            r_rsip_func102(bswap_32big(0xb1677136U), bswap_32big(0x4ae0667dU), bswap_32big(0x2462eb68U),
                           bswap_32big(0x4e76755eU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
