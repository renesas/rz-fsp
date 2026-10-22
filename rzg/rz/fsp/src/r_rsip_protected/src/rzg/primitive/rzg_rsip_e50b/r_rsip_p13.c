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
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0x7ea73cedU),
                   bswap_32big(0x16c17983U),
                   bswap_32big(0xe8747232U),
                   bswap_32big(0x108f5d77U));
    r_rsip_func074(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x79658ceaU),
                   bswap_32big(0xa259f98aU),
                   bswap_32big(0xb29480d3U),
                   bswap_32big(0x34dc959aU));
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x09090010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x09090010U);
    WR1_PROG(REG_1404H, 0x12a00000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa7eb1812U),
                   bswap_32big(0xf574804aU),
                   bswap_32big(0xa365909aU),
                   bswap_32big(0x48247954U));
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
    r_rsip_func100(bswap_32big(0x030025b4U),
                   bswap_32big(0x2fb8ed72U),
                   bswap_32big(0x4edb15d1U),
                   bswap_32big(0xeeba5bc1U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xb16f7386U),
                   bswap_32big(0xaa4e373fU),
                   bswap_32big(0xfba2dba8U),
                   bswap_32big(0x86f5c0b3U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x974f2fd0U),
                   bswap_32big(0x8e2337a3U),
                   bswap_32big(0x110132a4U),
                   bswap_32big(0x50a88a8eU));
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
    r_rsip_func100(bswap_32big(0xf5462621U),
                   bswap_32big(0x5b0a5b5fU),
                   bswap_32big(0x5c3f2847U),
                   bswap_32big(0xcc4c13feU));
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
        r_rsip_func101(bswap_32big(0xaae33723U), bswap_32big(0x4a94416bU), bswap_32big(0xb0eccf00U),
                       bswap_32big(0xd284dfcdU));
    }

    WR1_PROG(REG_1600H, 0x00007c03U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_func100(bswap_32big(0x164561d2U),
                   bswap_32big(0x1f98107dU),
                   bswap_32big(0xc24d4dfdU),
                   bswap_32big(0x798280feU));
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
        r_rsip_func100(bswap_32big(0xef7c1636U), bswap_32big(0x21f97ea6U), bswap_32big(0xf7586b93U),
                       bswap_32big(0x942d419bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000002f0U, 0x0a0a0009U);
            r_rsip_func101(bswap_32big(0xf23b5ea0U), bswap_32big(0x6965c169U), bswap_32big(0x11ea0513U),
                           bswap_32big(0xc036394cU));
        }

        r_rsip_subfunc004(0x000001b0U, 0x00000250U, 0x0a0a000cU);
        r_rsip_subfunc001(0x00000250U, 0x00000110U, 0x000001b0U, 0x0a0a0009U);
        WR1_PROG(REG_1600H, 0x00003000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x13d44f89U), bswap_32big(0xa79af47bU), bswap_32big(0x9082ed3fU),
                       bswap_32big(0xd854f24cU));
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
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0xd6a38c4bU),
                   bswap_32big(0x2ddc17e3U),
                   bswap_32big(0x6269c99fU),
                   bswap_32big(0x4c958ce7U));
    r_rsip_func075(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x00000013U));
    r_rsip_func101(bswap_32big(0xe58e4646U),
                   bswap_32big(0x2233edf0U),
                   bswap_32big(0x72f1f8dbU),
                   bswap_32big(0x1365fa4dU));
    r_rsip_func072();
    r_rsip_func100(bswap_32big(0x86d1e5abU),
                   bswap_32big(0x02d3e2cbU),
                   bswap_32big(0xa2289e48U),
                   bswap_32big(0x868af990U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x2820abf2U), bswap_32big(0x350a9adcU), bswap_32big(0x1e83fa66U),
                       bswap_32big(0x31ff4e5bU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xc8346e7cU), bswap_32big(0x64862e4bU), bswap_32big(0xb2b6b579U),
                       bswap_32big(0x7c327cbdU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00001301U));
        r_rsip_func101(bswap_32big(0x2c6e234dU), bswap_32big(0xfb27fa05U), bswap_32big(0xc9f82856U),
                       bswap_32big(0x7a273cb1U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x013e60bcU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00001301U));
        r_rsip_func101(bswap_32big(0x4b9f23d5U), bswap_32big(0x5b62806eU), bswap_32big(0xef6a870cU),
                       bswap_32big(0xb62e59c3U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0x89d5e5b2U), bswap_32big(0x00617f41U), bswap_32big(0x52f106ffU),
                       bswap_32big(0x28375fa0U));
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

        r_rsip_func100(bswap_32big(0xc8b165cdU), bswap_32big(0xa6be9e8fU), bswap_32big(0x4cc4ba7eU),
                       bswap_32big(0x3b5a3593U));
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
        r_rsip_func100(bswap_32big(0xe85921c5U), bswap_32big(0x1e59f0a3U), bswap_32big(0xaf5e614aU),
                       bswap_32big(0x09b3d576U));
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
        r_rsip_func100(bswap_32big(0x7ffbf281U), bswap_32big(0xdb819f93U), bswap_32big(0xffe103f2U),
                       bswap_32big(0x9b06ba82U));
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
        r_rsip_func100(bswap_32big(0xec4477edU), bswap_32big(0x4292259aU), bswap_32big(0x01324507U),
                       bswap_32big(0x08ec0df2U));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x00001302U));
        r_rsip_func101(bswap_32big(0x6cf1abc9U), bswap_32big(0xb6834d5cU), bswap_32big(0x95a96c59U),
                       bswap_32big(0xf2ddfb0bU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01ee6fdbU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x00001302U));
        r_rsip_func101(bswap_32big(0x6c6a6dbcU), bswap_32big(0x0499a999U), bswap_32big(0x88ca73c4U),
                       bswap_32big(0x3d765c80U));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xaedd413dU), bswap_32big(0xf41477dbU), bswap_32big(0xc2e0e9d6U),
                       bswap_32big(0xe8a6afbdU));
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

        r_rsip_func100(bswap_32big(0x55bfb54bU), bswap_32big(0x77ffa7dcU), bswap_32big(0xb535d4c3U),
                       bswap_32big(0x7c2c8608U));
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

        r_rsip_func100(bswap_32big(0x3a1e408aU), bswap_32big(0xcce31d53U), bswap_32big(0x2ca19ec1U),
                       bswap_32big(0x22d2d440U));
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
        r_rsip_func100(bswap_32big(0x527d044bU), bswap_32big(0xd7e242ccU), bswap_32big(0xb308f286U),
                       bswap_32big(0x128a1199U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0xe8008105U);
        r_rsip_subfunc003(0x00830011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[40]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[41]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[42]);
        RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[43]);
        r_rsip_func100(bswap_32big(0x37e04df3U), bswap_32big(0x41e6c674U), bswap_32big(0x353095cfU),
                       bswap_32big(0xe8eb1889U));
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
        r_rsip_func100(bswap_32big(0x3fd85ba4U), bswap_32big(0x1bb70c2bU), bswap_32big(0x789b4d53U),
                       bswap_32big(0x549ee175U));
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
        r_rsip_func102(bswap_32big(0x42fc6ff6U), bswap_32big(0x548a006fU), bswap_32big(0x76037757U),
                       bswap_32big(0xce48cf73U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
