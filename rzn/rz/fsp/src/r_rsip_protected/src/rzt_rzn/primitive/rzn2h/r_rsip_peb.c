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

rsip_ret_t r_rsip_peb (const uint32_t InData_KeyIndex[],
                       const uint32_t InData_EncPreMasterSecret[],
                       uint32_t       OutData_EncPreMasterSecret[])
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

    WR1_PROG(REG_1B00H, 0x00eb0002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x00000e50U);
    WR1_PROG(REG_1444H, 0x000003c7U);
    WR1_PROG(REG_1608H, 0x80040000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000eb01U));
    r_rsip_func101(bswap_32big(0x0817fcfbU),
                   bswap_32big(0x493d41e4U),
                   bswap_32big(0x7d542e6eU),
                   bswap_32big(0x60b6035aU));
    r_rsip_func045();
    WR1_PROG(REG_1600H, 0x0000b4e0U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x01e09ffdU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x0000eb01U));
    r_rsip_func101(bswap_32big(0x22da51dfU),
                   bswap_32big(0x0c711798U),
                   bswap_32big(0x7151c066U),
                   bswap_32big(0xf7278aa0U));
    r_rsip_func046();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000044U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x00003fc2U);
    WR1_PROG(REG_1A2CH, 0x40000f00U);
    WR1_PROG(REG_1A24H, 0xe8009107U);
    WR1_PROG(REG_1404H, 0x15300000U);
    for (iLoop = 0; iLoop < 64; iLoop = iLoop + 8)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 11]);
        r_rsip_subfunc003(0x00c20021U);
    }

    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0x49108054U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A2CH, 0x40000000U);
    WR1_PROG(REG_1A24H, 0xe8008105U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[68]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[69]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[70]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[71]);
    WR1_PROG(REG_1404H, 0x14200000U);
    r_rsip_subfunc003(0x00c00005U);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    WR1_PROG(REG_1444H, 0x000003c2U);
    WR1_PROG(REG_1A24H, 0x9c100005U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[72]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[73]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[74]);
    WR1_ADDR(REG_1420H, &InData_KeyIndex[75]);
    r_rsip_func100(bswap_32big(0xe6cae4beU),
                   bswap_32big(0x5e83328cU),
                   bswap_32big(0x78d7eedeU),
                   bswap_32big(0xd5d70a87U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x1a4d9a5fU), bswap_32big(0x7b861f62U), bswap_32big(0xa285b831U),
                       bswap_32big(0xb0b588c1U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_KEY_FAIL;
    }
    else
    {
        r_rsip_subfunc006(0x00000018U, 0x00000630U, 0x20200010U);
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000eb02U));
        r_rsip_func101(bswap_32big(0x8f0f778fU), bswap_32big(0x01a75183U), bswap_32big(0xb40f2cc8U),
                       bswap_32big(0x745760f4U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01a5a796U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000eb02U));
        r_rsip_func101(bswap_32big(0x8f315368U), bswap_32big(0xfe58c556U), bswap_32big(0x2c93e1ddU),
                       bswap_32big(0x2bd74df2U));
        r_rsip_func046();
        WR1_PROG(REG_1444H, 0x00000fc2U);
        WR1_PROG(REG_1A2CH, 0x40000300U);
        WR1_PROG(REG_1A24H, 0xf7009d07U);
        WR1_PROG(REG_1404H, 0x11f00000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[4]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[5]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[6]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[7]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[8]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[9]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[10]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[11]);
        r_rsip_subfunc003(0x00c20021U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[12]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[13]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[14]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[15]);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[16]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[17]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[18]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[19]);
        r_rsip_subfunc003(0x00c20011U);
        r_rsip_subfunc003(0x00020011U);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[20]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[21]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[22]);
        WR1_ADDR(REG_1420H, &InData_EncPreMasterSecret[23]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x34726b0aU), bswap_32big(0x7d398209U), bswap_32big(0xb730f867U),
                       bswap_32big(0x609ee13dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x51b8c12bU), bswap_32big(0xc8112a85U), bswap_32big(0x6537b74bU),
                           bswap_32big(0x1ded01f6U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0xa6ee7b34U), bswap_32big(0xc816c3f6U), bswap_32big(0x73c95b88U),
                           bswap_32big(0xfbc1b3fdU));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x03420005U);
            r_rsip_subfunc003(0x0002000dU);
            WR1_PROG(REG_1600H, 0x00008c00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000ffffU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00009000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00028080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1404H, 0x11200000U);
            WR1_PROG(REG_1608H, 0x81010000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c90005U);
            WR1_PROG(REG_1600H, 0x0000b480U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01020408U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4a0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x10204080U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x80200802U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x40100401U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 1)
            {
                r_rsip_func100(bswap_32big(0x5955dccfU),
                               bswap_32big(0x227858d6U),
                               bswap_32big(0x08da3606U),
                               bswap_32big(0xe5f9b9b3U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                WR1_PROG(REG_1600H, 0x00001004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001025U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001046U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00001067U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00c90011U);
                WR1_PROG(REG_1600H, 0x00002fc0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x5ab3beb2U),
                               bswap_32big(0xfba98cf2U),
                               bswap_32big(0x187c1190U),
                               bswap_32big(0x25277806U));
            }

            WR1_PROG(REG_1600H, 0x38008bc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x0fda038eU), bswap_32big(0x5dfca9fbU), bswap_32big(0x8063b64cU),
                           bswap_32big(0xb8f939a1U));
            r_rsip_func103();
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x0c200104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1608H, 0x80030000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x0342000dU);
            r_rsip_subfunc003(0x00020005U);
            WR1_PROG(REG_1600H, 0x00001004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00001025U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00001046U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00008c40U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xffffff00U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81030000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00c9000dU);
            WR1_PROG(REG_1404H, 0x16280000U);
            WR1_PROG(REG_1608H, 0x800103e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc003(0x00030005U);
            r_rsip_subfunc003(0x03430005U);
            WR1_PROG(REG_1600H, 0x3800dbe0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_1404H, 0x19400000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c000fdU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x00000630U, 0x00000a40U, 0x00000838U, 0x2020000aU);
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000a40U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00210000U);
            r_rsip_func100(bswap_32big(0xd47306f3U), bswap_32big(0x35ff8149U), bswap_32big(0x3696ece2U),
                           bswap_32big(0xedb6fbcdU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x3fbf26c9U),
                               bswap_32big(0xd15f5e02U),
                               bswap_32big(0x5f90f5e4U),
                               bswap_32big(0xaf3616f5U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xf55a659dU),
                               bswap_32big(0x66eee8e5U),
                               bswap_32big(0xbc27f9e1U),
                               bswap_32big(0xb61b7bc7U));
                r_rsip_subfunc005(0x00000220U, 0x00000428U, 0x00000630U, 0x00000838U, 0x0120000fU, 0x00020000U);
                WR1_PROG(REG_143CH, 0x00000d00U);
                WR1_PROG(REG_1600H, 0x00000bffU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b400U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000040U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1404H, 0x17380000U);
                for (iLoop = 0; iLoop < 64; iLoop = iLoop + 8)
                {
                    WR1_PROG(REG_1600H, 0x00000bdeU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x34202be0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d3c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c1eU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xad97f613U),
                                   bswap_32big(0x44b49a42U),
                                   bswap_32big(0x4400d162U),
                                   bswap_32big(0xe9bcf57cU));
                    WR1_PROG(REG_1A2CH, 0x00000100U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830021U);
                    WR1_PROG(REG_1408H, 0x00002022U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 1]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 2]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 3]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_EncPreMasterSecret[iLoop + 7]);
                    WR1_PROG(REG_1600H, 0x0000a7e0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00000008U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0xba548e81U),
                                   bswap_32big(0xb2fd1910U),
                                   bswap_32big(0xaa93a710U),
                                   bswap_32big(0x30a74e7bU));
                }

                WR1_PROG(REG_1600H, 0x38000be0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0xacfff961U),
                               bswap_32big(0x5f34e0dfU),
                               bswap_32big(0x811b194aU),
                               bswap_32big(0xd2c32e62U));
                WR1_PROG(REG_1408H, 0x00020000U);
                r_rsip_func102(bswap_32big(0xaab3ae07U),
                               bswap_32big(0x7e08f371U),
                               bswap_32big(0xd2960a71U),
                               bswap_32big(0x796c13a9U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
