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
    r_rsip_func100(bswap_32big(0x4604810cU),
                   bswap_32big(0x5177189fU),
                   bswap_32big(0xbb53a71dU),
                   bswap_32big(0xe5a13d3dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1e2f2baaU), bswap_32big(0x7b348e36U), bswap_32big(0x0162f7e5U),
                       bswap_32big(0x07536775U));
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
        r_rsip_func101(bswap_32big(0x777c27bcU), bswap_32big(0xefb61470U), bswap_32big(0x8a2de518U),
                       bswap_32big(0xab26d9daU));
        r_rsip_func086(InData_DomainParam);
        r_rsip_func100(bswap_32big(0xcbdcfd08U), bswap_32big(0xa6af4fc0U), bswap_32big(0xdd0623f8U),
                       bswap_32big(0xb814b927U));
        r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x04040010U);
        r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x04040010U);
        WR1_PROG(REG_1404H, 0x12c80000U);
        WR1_PROG(REG_1600H, 0x00007c1cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xbbf5a927U), bswap_32big(0x8eacfbc1U), bswap_32big(0x60f2003dU),
                           bswap_32big(0xf8c3ac40U));
            r_rsip_subfunc003(0x00c00009U);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20009U);
            r_rsip_subfunc003(0x00020009U);
            r_rsip_func101(bswap_32big(0x7e341566U), bswap_32big(0x92871107U), bswap_32big(0xc109dc03U),
                           bswap_32big(0xb40ac795U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x0dea61feU), bswap_32big(0x0e93a51eU), bswap_32big(0x4f6e2c14U),
                           bswap_32big(0x9982f5dcU));
            r_rsip_subfunc003(0x00c0000dU);
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_func101(bswap_32big(0xb3fcf5f1U), bswap_32big(0x1734b7cbU), bswap_32big(0x859e218dU),
                           bswap_32big(0xc707d4f4U));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_subfunc003(0x00c00011U);
            r_rsip_func101(bswap_32big(0x4459f669U), bswap_32big(0xe107abbeU), bswap_32big(0x7e17176bU),
                           bswap_32big(0x5a1ca781U));
        }

        r_rsip_func100(bswap_32big(0x8ba44c36U), bswap_32big(0xa4163b74U), bswap_32big(0xed3668feU),
                       bswap_32big(0xdc40035cU));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0x441e0f2eU), bswap_32big(0x651592ceU), bswap_32big(0x0731d1c4U),
                       bswap_32big(0x769d01f3U));
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
        r_rsip_func100(bswap_32big(0xa4a61593U), bswap_32big(0x9a6ba34eU), bswap_32big(0x0126d050U),
                       bswap_32big(0x5b714510U));
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
            r_rsip_func101(bswap_32big(0x123b9437U), bswap_32big(0x32dde10dU), bswap_32big(0x34ab2ed2U),
                           bswap_32big(0xb6a95c78U));
        }

        WR1_PROG(REG_1600H, 0x00007c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00602000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1404H, 0x10e80000U);
        r_rsip_subfunc003(0x00c00029U);
        r_rsip_func100(bswap_32big(0xd7ef46dbU), bswap_32big(0x3f09db2dU), bswap_32big(0xbe043c44U),
                       bswap_32big(0xccd099c1U));
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
            r_rsip_func100(bswap_32big(0x340375efU), bswap_32big(0x89e43376U), bswap_32big(0x19e43b45U),
                           bswap_32big(0xef5556ebU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x05050009U);
                r_rsip_func101(bswap_32big(0x30f64351U),
                               bswap_32big(0x344f51e0U),
                               bswap_32big(0x5ba5cf98U),
                               bswap_32big(0x6206ad43U));
            }

            r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0505000cU);
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x05050009U);
            WR1_PROG(REG_1600H, 0x00003000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xbc12b4a1U), bswap_32big(0x739670d9U), bswap_32big(0x991626daU),
                           bswap_32big(0xa1ff2cd8U));
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
        r_rsip_func101(bswap_32big(0x7af5ee81U), bswap_32big(0xc1e2464eU), bswap_32big(0x111040d8U),
                       bswap_32big(0xe85432b5U));
        r_rsip_func087(InData_DomainParam);
        r_rsip_subfunc009(bswap_32big(0x000000f4U));
        r_rsip_func101(bswap_32big(0x346b928dU), bswap_32big(0x3bf74d07U), bswap_32big(0x679dcfdaU),
                       bswap_32big(0xd976ebcfU));
        r_rsip_func088();
        r_rsip_func100(bswap_32big(0xcf8357c8U), bswap_32big(0xfc1d0de6U), bswap_32big(0xc9c0fdbbU),
                       bswap_32big(0xec2decadU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xa9f91bd4U), bswap_32big(0x50ceefd0U), bswap_32big(0xe54252d5U),
                           bswap_32big(0x5bb283fbU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x2890b51aU), bswap_32big(0xd94d3f61U), bswap_32big(0x3cb31762U),
                           bswap_32big(0x3948e8f0U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0xc91d6c13U), bswap_32big(0xdd3c4569U), bswap_32big(0xa97ffeedU),
                           bswap_32big(0xc930ffc8U));
            r_rsip_func045();
            r_rsip_func022();
            r_rsip_subfunc009(bswap_32big(0x0000f401U));
            r_rsip_func101(bswap_32big(0xe9463e60U), bswap_32big(0x871ec064U), bswap_32big(0x6e08efefU),
                           bswap_32big(0xe7e404ebU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0xb7091103U), bswap_32big(0xf9bf5f0cU), bswap_32big(0x27792eafU),
                           bswap_32big(0x800da733U));
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
            r_rsip_func100(bswap_32big(0x615a505eU), bswap_32big(0xe69ae5bbU), bswap_32big(0xa33bec68U),
                           bswap_32big(0x53d1bda7U));
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
            r_rsip_func100(bswap_32big(0xd1d7a1aeU), bswap_32big(0x33d137e8U), bswap_32big(0xe7c00876U),
                           bswap_32big(0xcef2f77aU));
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
            r_rsip_func100(bswap_32big(0xb0a0f23cU), bswap_32big(0x68d6c60fU), bswap_32big(0xdc09dd78U),
                           bswap_32big(0x8a85ec92U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420011U);
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0x7582afa7U), bswap_32big(0x72104c45U), bswap_32big(0x1597e7cfU),
                           bswap_32big(0xa992ab7aU));
            r_rsip_func045();
            r_rsip_func023();
            r_rsip_subfunc009(bswap_32big(0x0000f402U));
            r_rsip_func101(bswap_32big(0xe9419b19U), bswap_32big(0xa18ec57aU), bswap_32big(0x33499c0dU),
                           bswap_32big(0x52d35035U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x29035142U), bswap_32big(0x1e93e1b6U), bswap_32big(0x83a8690cU),
                           bswap_32big(0xa7b35e1bU));
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
            r_rsip_func100(bswap_32big(0x16f63c6bU), bswap_32big(0x6319ad89U), bswap_32big(0xc804f350U),
                           bswap_32big(0x90e049c1U));
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xe8008105U);
            r_rsip_subfunc003(0x00830011U);
            WR1_PROG(REG_1408H, 0x00002012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[16]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[17]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[18]);
            RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[19]);
            r_rsip_func100(bswap_32big(0x40fb7947U), bswap_32big(0xf66246caU), bswap_32big(0x323d7110U),
                           bswap_32big(0xb0515ccfU));
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
            r_rsip_func100(bswap_32big(0xe8a029adU), bswap_32big(0xe5b6d5fdU), bswap_32big(0xed0ebf8dU),
                           bswap_32big(0x682a0f11U));
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
            r_rsip_func102(bswap_32big(0xea8ac739U), bswap_32big(0x9f67a64cU), bswap_32big(0xbb7f43d5U),
                           bswap_32big(0xe1d092eaU));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_PASS;
        }
    }
}
