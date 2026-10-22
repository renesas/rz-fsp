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

rsip_ret_t r_rsip_p4a (uint32_t const InData_DomainParam[],
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

    WR1_PROG(REG_1B00H, 0x0004a002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000008c8U);
    r_rsip_func100(bswap_32big(0xfb3bfb3eU),
                   bswap_32big(0x94ac49c1U),
                   bswap_32big(0x5c50f194U),
                   bswap_32big(0xe3d1c0d2U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xe19d3290U),
                   bswap_32big(0xbfaa0027U),
                   bswap_32big(0xb150e8f9U),
                   bswap_32big(0xfddd2dc2U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000050U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80840000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80840000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    WR1_PROG(REG_2000H, 0x00000001U);
    WR1_PROG(REG_2004H, 0x000000b0U);
    WR1_PROG(REG_1444H, 0x00000020U);
    WR1_PROG(REG_2014H, 0x00000000U);
    WR1_PROG(REG_1444H, 0x00000020U);
    WR1_PROG(REG_2010H, 0x00000100U);
    WR1_PROG(REG_1608H, 0x81880000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x01490021U);
    WAIT_STS(REG_2030H, 4U, 1U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80880000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03450021U);
    r_rsip_subfunc003(0x00050021U);
    WR1_PROG(REG_1600H, 0x00003820U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00008c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xf8ffffffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003820U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00008c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0xffffff3fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00009020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003c20U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000842U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b460U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1600H, 0x02003801U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003843U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003c41U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0x4d69e49dU),
                   bswap_32big(0x142fa118U),
                   bswap_32big(0x408db59fU),
                   bswap_32big(0x17c8546eU));
    r_rsip_func401(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0x3eb061aaU),
                   bswap_32big(0xece2c921U),
                   bswap_32big(0x5cb053aeU),
                   bswap_32big(0x1d03c2a7U));
    r_rsip_func406(InData_DomainParam);
    WR1_PROG(REG_1404H, 0x15000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    r_rsip_subfunc003(0x00c00015U);
    r_rsip_subfunc003(0x00c2000dU);
    r_rsip_subfunc003(0x00020005U);
    WR1_PROG(REG_1404H, 0x16400000U);
    r_rsip_subfunc003(0x00c00021U);
    WR1_PROG(REG_1404H, 0x16900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    r_rsip_subfunc003(0x00c00015U);
    r_rsip_subfunc003(0x00c2000dU);
    r_rsip_subfunc003(0x00020005U);
    WR1_PROG(REG_1404H, 0x16e00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    r_rsip_subfunc003(0x00c00015U);
    r_rsip_subfunc003(0x00c2000dU);
    r_rsip_subfunc003(0x00020005U);
    WR1_PROG(REG_1404H, 0x1b400000U);
    r_rsip_subfunc003(0x00c00021U);
    WR1_PROG(REG_1404H, 0x1b900000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    r_rsip_subfunc003(0x00c00015U);
    r_rsip_subfunc003(0x00c2000dU);
    r_rsip_subfunc003(0x00020005U);
    WR1_PROG(REG_1404H, 0x1be00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000026U));
    r_rsip_subfunc003(0x00c00015U);
    r_rsip_subfunc003(0x00c2000dU);
    r_rsip_subfunc003(0x00020005U);
    WR1_PROG(REG_1600H, 0x00000908U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b660U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b520U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    for (iLoop = 0; iLoop < 256; iLoop = iLoop + 1)
    {
        r_rsip_func405();
        r_rsip_func403();
        r_rsip_func101(bswap_32big(0x301eadbeU), bswap_32big(0x6f8ca065U), bswap_32big(0x026db9afU),
                       bswap_32big(0x12e5237fU));
        r_rsip_func402();
        r_rsip_func404();
        WR1_PROG(REG_1600H, 0x00002d00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xb5147d72U), bswap_32big(0xc5b80cd4U), bswap_32big(0x201cf968U),
                       bswap_32big(0x6d671be1U));
    }

    WR1_PROG(REG_1600H, 0x08000909U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_143CH, 0x00402000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc001(0x00000660U, 0x00000b10U, 0x00000570U, 0x0404000aU);
    r_rsip_subfunc001(0x000006b0U, 0x00000b10U, 0x000005c0U, 0x0404000aU);
    r_rsip_subfunc001(0x00000700U, 0x00000b10U, 0x00000610U, 0x0404000aU);
    WR1_PROG(REG_1014H, 0x00000610U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1020H, 0x00000250U);
    WR1_PROG(REG_1010H, 0x00000008U);
    WR1_PROG(REG_1004H, 0x04040004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x12d00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0001dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000070U, 0x000002f0U, 0x000002a0U, 0x0404000aU);
    r_rsip_func100(bswap_32big(0xbb968840U),
                   bswap_32big(0xa0fb2cadU),
                   bswap_32big(0x3b9de0f8U),
                   bswap_32big(0xd38360b4U));
    r_rsip_subfunc005(0x00000250U, 0x000002a0U, 0x00000070U, 0x000002f0U, 0x0404000fU, 0x00020000U);
    WR1_PROG(REG_1014H, 0x00000570U);
    WR1_PROG(REG_1018H, 0x000002f0U);
    r_rsip_subfunc002(0x00000070U, 0x00000250U, 0x04040002U);
    WR1_PROG(REG_1014H, 0x000005c0U);
    WR1_PROG(REG_1018H, 0x000002f0U);
    r_rsip_subfunc002(0x00000070U, 0x000002a0U, 0x04040002U);
    WR1_PROG(REG_1404H, 0x12800000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80880001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430021U);
    WR1_PROG(REG_1600H, 0x00003801U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00008c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x7fffffffU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1404H, 0x12300000U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000020U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80880001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430021U);
    WR1_PROG(REG_1600H, 0x0000b420U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000003cU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003841U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x001f6c42U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00001002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003c01U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000821U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000842U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000b460U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x0000001fU);
    WR1_PROG(REG_1458H, 0x00000000U);
    for (iLoop = 0; iLoop < 16; iLoop = iLoop + 1)
    {
        WR1_PROG(REG_1600H, 0x02003801U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003843U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003c41U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x02003c03U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00002c20U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00003060U);
        WR1_PROG(REG_1458H, 0x00000000U);
    }

    WR1_PROG(REG_1600H, 0x0000b7c0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000040U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x947b8578U),
                   bswap_32big(0x90d65c7dU),
                   bswap_32big(0x05f59286U),
                   bswap_32big(0x2ec4b44dU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0xf78e49a3U),
                   bswap_32big(0xa42934b7U),
                   bswap_32big(0xe215708cU),
                   bswap_32big(0xd7d9c737U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x017e9b25U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0xeb3f25cfU),
                   bswap_32big(0x64a273f9U),
                   bswap_32big(0x02a10bfaU),
                   bswap_32big(0x32dfbd89U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x82958e75U),
                   bswap_32big(0x12bcb1aaU),
                   bswap_32big(0xa0489b6eU),
                   bswap_32big(0xf8ee2d0aU));
    WR1_PROG(REG_1A2CH, 0x40000100U);
    WR1_PROG(REG_1A24H, 0xe7009d07U);
    WR1_PROG(REG_1608H, 0x8188001eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890021U);
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
    r_rsip_func100(bswap_32big(0xc6c0b800U),
                   bswap_32big(0x7cebbc93U),
                   bswap_32big(0x88782220U),
                   bswap_32big(0xf50fa83bU));
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
    r_rsip_func100(bswap_32big(0x3321367fU),
                   bswap_32big(0x239c514aU),
                   bswap_32big(0x2489f10fU),
                   bswap_32big(0x0497a4f8U));
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
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0xb212f20eU),
                   bswap_32big(0x06cd9859U),
                   bswap_32big(0x73dc9d09U),
                   bswap_32big(0x3547049fU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0x9100c137U),
                   bswap_32big(0x3e8676d8U),
                   bswap_32big(0x013881cbU),
                   bswap_32big(0xce46db76U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f49b81U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0x768769fdU),
                   bswap_32big(0xb4ccf86dU),
                   bswap_32big(0x7daefffeU),
                   bswap_32big(0xc90c5235U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x4f14313dU),
                   bswap_32big(0x7054fa99U),
                   bswap_32big(0x56aa2e17U),
                   bswap_32big(0xd82bd5eaU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8009105U);
    WR1_PROG(REG_1608H, 0x8188001eU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[4]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[5]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[6]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[7]);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_func100(bswap_32big(0x947ab3d8U),
                   bswap_32big(0x38a98949U),
                   bswap_32big(0x20f19adcU),
                   bswap_32big(0x5e93a00eU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
    r_rsip_func100(bswap_32big(0x55d05586U),
                   bswap_32big(0x97098e68U),
                   bswap_32big(0xbd22f9bcU),
                   bswap_32big(0xb7d1b73cU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c100104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[12]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[13]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[14]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[15]);
    r_rsip_func100(bswap_32big(0x53787969U),
                   bswap_32big(0xec3ca4b2U),
                   bswap_32big(0x558e8654U),
                   bswap_32big(0x57637e64U));
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
    r_rsip_func102(bswap_32big(0xfa2f2d57U),
                   bswap_32big(0xfa719f1bU),
                   bswap_32big(0xd83f5879U),
                   bswap_32big(0x3f1f4753U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
