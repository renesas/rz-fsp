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
    r_rsip_func100(bswap_32big(0xd81d352aU),
                   bswap_32big(0xad39f0cbU),
                   bswap_32big(0xd593746bU),
                   bswap_32big(0x8f62e29bU));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x68a64fd9U),
                   bswap_32big(0xeb44c4b9U),
                   bswap_32big(0xd48fc5dfU),
                   bswap_32big(0xa8a27829U));
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

    WR1_PROG(REG_1404H, 0x14300000U);
    r_rsip_subfunc003(0x00c000f1U);
    WR1_PROG(REG_1404H, 0x10200000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10700000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x11b00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10000000U);
    r_rsip_subfunc003(0x00c00011U);
    WR1_PROG(REG_1404H, 0x11600000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x10c00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x11100000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x1ac00000U);
    r_rsip_subfunc003(0x00c00051U);
    WR1_PROG(REG_1404H, 0x16100000U);
    r_rsip_subfunc003(0x00c000f1U);
    WR1_PROG(REG_1404H, 0x1b100000U);
    r_rsip_subfunc003(0x00c000f1U);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0xe18cd392U),
                   bswap_32big(0xc492caa4U),
                   bswap_32big(0xe2695eddU),
                   bswap_32big(0xfc5c4568U));
    r_rsip_func401(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0x0ffbf300U),
                   bswap_32big(0x30c58624U),
                   bswap_32big(0x43abbbe2U),
                   bswap_32big(0x9834359cU));
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
        r_rsip_func101(bswap_32big(0xf8077e44U), bswap_32big(0x3f90a107U), bswap_32big(0x3bf730f1U),
                       bswap_32big(0x7e7bc82fU));
        r_rsip_func402();
        r_rsip_func404();
        WR1_PROG(REG_1600H, 0x00002d00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xf5df49bbU), bswap_32big(0xac76d025U), bswap_32big(0x0fd63e3cU),
                       bswap_32big(0x6c5bb3a7U));
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
    WR1_PROG(REG_1000H, 0x00010201U);
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
    r_rsip_func100(bswap_32big(0xec8167feU),
                   bswap_32big(0xe83184bfU),
                   bswap_32big(0x2fb0826cU),
                   bswap_32big(0xc55b117aU));
    WR1_PROG(REG_1014H, 0x00000250U);
    WR1_PROG(REG_1018H, 0x000002a0U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1020H, 0x000002f0U);
    WR1_PROG(REG_1004H, 0x0404000fU);
    WR1_PROG(REG_1408H, 0x00020000U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1014H, 0x00000570U);
    WR1_PROG(REG_1018H, 0x000002f0U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1020H, 0x00000250U);
    WR1_PROG(REG_1004H, 0x04040002U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1014H, 0x000005c0U);
    WR1_PROG(REG_1018H, 0x000002f0U);
    WR1_PROG(REG_101CH, 0x00000070U);
    WR1_PROG(REG_1020H, 0x000002a0U);
    WR1_PROG(REG_1004H, 0x04040002U);
    WR1_PROG(REG_1000H, 0x00010201U);
    WAIT_STS(REG_1000H, 0U, 0U);
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
    r_rsip_func100(bswap_32big(0x2ddee487U),
                   bswap_32big(0x812d9b59U),
                   bswap_32big(0x413dbbd1U),
                   bswap_32big(0xda723b58U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0x698ff960U),
                   bswap_32big(0x908c7ed7U),
                   bswap_32big(0xb8f0b14aU),
                   bswap_32big(0xa155b734U));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01ebb717U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0x8e026ea2U),
                   bswap_32big(0xb1b33768U),
                   bswap_32big(0x7ba8a624U),
                   bswap_32big(0x93f7ff43U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x422e3879U),
                   bswap_32big(0x4a1e7f2cU),
                   bswap_32big(0x1548088eU),
                   bswap_32big(0x5d6c09e6U));
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
    r_rsip_func100(bswap_32big(0xb5f4ceddU),
                   bswap_32big(0x18b493d2U),
                   bswap_32big(0xbcdf70a9U),
                   bswap_32big(0x43e21222U));
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
    r_rsip_func100(bswap_32big(0x9f6a3fadU),
                   bswap_32big(0xfe11726fU),
                   bswap_32big(0xb7002730U),
                   bswap_32big(0x63be6df3U));
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
    r_rsip_func100(bswap_32big(0xd8880560U),
                   bswap_32big(0xaf751fe0U),
                   bswap_32big(0xff9d9006U),
                   bswap_32big(0xfffbd6c3U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0x8154c4efU),
                   bswap_32big(0xbfe9f795U),
                   bswap_32big(0xac82acd4U),
                   bswap_32big(0xce214debU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01fed3e5U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0xd198648cU),
                   bswap_32big(0x655e683dU),
                   bswap_32big(0x309038f4U),
                   bswap_32big(0x8036f9b7U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0xe4da16b1U),
                   bswap_32big(0x0b9bfc32U),
                   bswap_32big(0x6a5d4177U),
                   bswap_32big(0x23813ea6U));
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
    r_rsip_func100(bswap_32big(0x98b5103dU),
                   bswap_32big(0x3d13083aU),
                   bswap_32big(0x6a620110U),
                   bswap_32big(0xe750c778U));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
    r_rsip_func100(bswap_32big(0x91f816e4U),
                   bswap_32big(0x5a005ff8U),
                   bswap_32big(0x5822cb72U),
                   bswap_32big(0x1c19caf0U));
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
    r_rsip_func100(bswap_32big(0x16d818fbU),
                   bswap_32big(0x0b5b82f6U),
                   bswap_32big(0xee58c6cdU),
                   bswap_32big(0x7a40d45eU));
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
    r_rsip_func102(bswap_32big(0xea4da7a6U),
                   bswap_32big(0x7ae77a48U),
                   bswap_32big(0x1dfc657fU),
                   bswap_32big(0x5bdc0025U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
