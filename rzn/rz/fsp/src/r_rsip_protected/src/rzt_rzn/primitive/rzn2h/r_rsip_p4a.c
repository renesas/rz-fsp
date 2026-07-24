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
    r_rsip_func100(bswap_32big(0xaa7d60bbU),
                   bswap_32big(0x24f9114eU),
                   bswap_32big(0x6a8d0df4U),
                   bswap_32big(0x8002e785U));
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xa7d9d0aeU),
                   bswap_32big(0x7a2fb6caU),
                   bswap_32big(0xde011aa3U),
                   bswap_32big(0x02d1f5bdU));
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
    r_rsip_func101(bswap_32big(0x3b316f0aU),
                   bswap_32big(0x473774ffU),
                   bswap_32big(0x822642bdU),
                   bswap_32big(0x4708d0d1U));
    r_rsip_func401(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x0000004aU));
    r_rsip_func101(bswap_32big(0x73a5aef9U),
                   bswap_32big(0x328ce9d1U),
                   bswap_32big(0x3e4098dcU),
                   bswap_32big(0xb170ca64U));
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
        r_rsip_func101(bswap_32big(0xbc507048U), bswap_32big(0x71ba564eU), bswap_32big(0xee767aa7U),
                       bswap_32big(0x7b103fb2U));
        r_rsip_func402();
        r_rsip_func404();
        WR1_PROG(REG_1600H, 0x00002d00U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xa3075353U), bswap_32big(0x60f2c65bU), bswap_32big(0xc8364a86U),
                       bswap_32big(0xd5410708U));
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
    r_rsip_func100(bswap_32big(0x3d7b6e1aU),
                   bswap_32big(0x902269f2U),
                   bswap_32big(0x7305acbaU),
                   bswap_32big(0x3530240cU));
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
    r_rsip_func100(bswap_32big(0xe4a3bafeU),
                   bswap_32big(0x67218fcbU),
                   bswap_32big(0x7f41de3dU),
                   bswap_32big(0xfa92949dU));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0xb3490a53U),
                   bswap_32big(0xb94000a4U),
                   bswap_32big(0x638ebc52U),
                   bswap_32big(0x76701a6fU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x017a6afbU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a01U));
    r_rsip_func101(bswap_32big(0x217d0557U),
                   bswap_32big(0xeb275f78U),
                   bswap_32big(0x22ba29d8U),
                   bswap_32big(0x7c16ccb5U));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x80ffd6b4U),
                   bswap_32big(0x5125b1adU),
                   bswap_32big(0x803d7924U),
                   bswap_32big(0x1a573cdbU));
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
    r_rsip_func100(bswap_32big(0x37601f16U),
                   bswap_32big(0xef04fce2U),
                   bswap_32big(0x583f3693U),
                   bswap_32big(0x058b090fU));
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
    r_rsip_func100(bswap_32big(0x3c95f9d5U),
                   bswap_32big(0x084a313cU),
                   bswap_32big(0xd0910674U),
                   bswap_32big(0xe56cd9a7U));
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
    r_rsip_func100(bswap_32big(0xc40f6c6fU),
                   bswap_32big(0xde5475caU),
                   bswap_32big(0x3b91eea8U),
                   bswap_32big(0xe08d53a9U));
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03420011U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0xd6298224U),
                   bswap_32big(0xd0c89d90U),
                   bswap_32big(0xb2af73adU),
                   bswap_32big(0x3d1349bfU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01750f23U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x00004a02U));
    r_rsip_func101(bswap_32big(0xd0d727d0U),
                   bswap_32big(0xc8e7c3a1U),
                   bswap_32big(0xbded25a2U),
                   bswap_32big(0x067cd8faU));
    r_rsip_func046();
    r_rsip_func100(bswap_32big(0x173cff03U),
                   bswap_32big(0x4d8535eaU),
                   bswap_32big(0xa79d4f02U),
                   bswap_32big(0xb1ab64dcU));
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
    r_rsip_func100(bswap_32big(0x6606f1e4U),
                   bswap_32big(0xcbc32549U),
                   bswap_32big(0xd7a8dcedU),
                   bswap_32big(0x3db5d7cfU));
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    r_rsip_subfunc003(0x00890011U);
    WR1_PROG(REG_1408H, 0x00002012U);
    WAIT_STS(REG_1408H, 30U, 1U);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[8]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[9]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[10]);
    RD1_ADDR(REG_1420H, &OutData_PubKeyIndex[11]);
    r_rsip_func100(bswap_32big(0x8026722cU),
                   bswap_32big(0x48c3af1bU),
                   bswap_32big(0x4aaf7267U),
                   bswap_32big(0x2ab1a9c5U));
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
    r_rsip_func100(bswap_32big(0x7c3f044fU),
                   bswap_32big(0xcec85615U),
                   bswap_32big(0x8d97c10dU),
                   bswap_32big(0xbc997b6fU));
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
    r_rsip_func102(bswap_32big(0x9eff0f09U),
                   bswap_32big(0xf99e4a88U),
                   bswap_32big(0x9996f16fU),
                   bswap_32big(0xe92827b5U));
    WR1_PROG(REG_14B8H, 0x00000040U);
    WAIT_STS(REG_142CH, 12U, 0U);

    return RSIP_RET_PASS;
}
