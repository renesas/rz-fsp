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
    r_rsip_func100(bswap_32big(0x3be45994U),
                   bswap_32big(0xf4d1c71dU),
                   bswap_32big(0x70490bc7U),
                   bswap_32big(0x4b6036faU));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x25460850U),
                   bswap_32big(0xb2d99d54U),
                   bswap_32big(0x5aa7f937U),
                   bswap_32big(0x4ffcd1beU));
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
    r_rsip_func101(bswap_32big(0xb2d0129aU),
                   bswap_32big(0xbad44be5U),
                   bswap_32big(0xe3cfb915U),
                   bswap_32big(0x2c420e10U));
    r_rsip_func401(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0x89560a56U),
                   bswap_32big(0xcaae86b8U),
                   bswap_32big(0xc09e15e9U),
                   bswap_32big(0x8459e609U));
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
        r_rsip_func101(bswap_32big(0x43d47bb7U), bswap_32big(0xf11252acU), bswap_32big(0x0635b075U),
                       bswap_32big(0x6ba177d5U));
        r_rsip_func402();
        r_rsip_func404();
        WR1_PROG(REG_1600H, 0x00002d00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa7e26b59U), bswap_32big(0xe7aa9a54U), bswap_32big(0x17ac4f35U),
                       bswap_32big(0x025895ebU));
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
    r_rsip_func100(bswap_32big(0x9746bcf2U),
                   bswap_32big(0x974284a0U),
                   bswap_32big(0xb523c668U),
                   bswap_32big(0xc669821aU));
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
    r_rsip_func100(bswap_32big(0x82b00af6U),
                   bswap_32big(0x9cc0693eU),
                   bswap_32big(0x41008c03U),
                   bswap_32big(0x02947d31U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0xb49181e1U),
                   bswap_32big(0x7b7f1d3eU),
                   bswap_32big(0x57a49542U),
                   bswap_32big(0xfde714f8U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01793385U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0x171b5d77U),
                   bswap_32big(0xeb75dc57U),
                   bswap_32big(0xf1b3da89U),
                   bswap_32big(0xc1cb5606U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x177d29bcU),
                   bswap_32big(0x39fab93bU),
                   bswap_32big(0x4d8e2ddbU),
                   bswap_32big(0xeaeb91a6U));
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
    r_rsip_func100(bswap_32big(0xcdb997b8U),
                   bswap_32big(0x18e96877U),
                   bswap_32big(0x0b866efaU),
                   bswap_32big(0x2a425a7bU));
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
    r_rsip_func100(bswap_32big(0xdbe36ce4U),
                   bswap_32big(0xbf33a138U),
                   bswap_32big(0xe7a90a1eU),
                   bswap_32big(0x24817b19U));
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
    r_rsip_func100(bswap_32big(0xf69004fcU),
                   bswap_32big(0x72e77b24U),
                   bswap_32big(0xf73f55bfU),
                   bswap_32big(0x047d0be0U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0x8ce07decU),
                   bswap_32big(0x883e139eU),
                   bswap_32big(0xe6849d58U),
                   bswap_32big(0x188c37a8U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01f7b873U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0x1a0801e5U),
                   bswap_32big(0x40c4ce34U),
                   bswap_32big(0x8037d169U),
                   bswap_32big(0xd05897c8U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x5f5d2caeU),
                   bswap_32big(0xee326803U),
                   bswap_32big(0x049dd8f0U),
                   bswap_32big(0x35876bceU));
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
    r_rsip_func100(bswap_32big(0xdbcab895U),
                   bswap_32big(0x0d48c25fU),
                   bswap_32big(0x093cd060U),
                   bswap_32big(0x8079d5c2U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
    r_rsip_func100(bswap_32big(0x1b215d0fU),
                   bswap_32big(0x829c83f2U),
                   bswap_32big(0x7ed0e0c7U),
                   bswap_32big(0x58aca2a0U));
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
    r_rsip_func100(bswap_32big(0xcc86173cU),
                   bswap_32big(0xb97511c2U),
                   bswap_32big(0x2aff8d1bU),
                   bswap_32big(0x54e20779U));
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
    r_rsip_func102(bswap_32big(0xd20ed0e8U),
                   bswap_32big(0x349ca637U),
                   bswap_32big(0x749b2771U),
                   bswap_32big(0x30c327d4U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
