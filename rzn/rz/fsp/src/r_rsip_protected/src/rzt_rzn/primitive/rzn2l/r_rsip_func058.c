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

void r_rsip_func058 (void)
{
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
    WR1_PROG(REG_1600H, 0x0000373dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000bdeU);
    WR1_PROG(REG_1458H, 0x00000000U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x12180000U);
        WR1_PROG(REG_1608H, 0x80010340U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1404H, 0x16280000U);
        WR1_PROG(REG_1608H, 0x80010360U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00030005U);
        r_rsip_subfunc003(0x03430005U);
        WR1_PROG(REG_1600H, 0x0000135bU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x3800db40U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x3a9ad9b6U), bswap_32big(0x023985f7U), bswap_32big(0x1b45cf60U),
                       bswap_32big(0xf248293aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xcc1e0a66U), bswap_32big(0x26914453U), bswap_32big(0x513cc461U),
                           bswap_32big(0x273a35dbU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xbbd76c07U), bswap_32big(0x0929a763U), bswap_32big(0xc1b342caU),
                           bswap_32big(0x38a294fdU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0xef69ad07U),
                   bswap_32big(0xf39e0a34U),
                   bswap_32big(0x6d8644c9U),
                   bswap_32big(0xe9453ca1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x188ebc71U));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0x321e7521U),
                   bswap_32big(0x44b9861dU),
                   bswap_32big(0xd6a6be13U),
                   bswap_32big(0xec3103b5U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0x99708e48U),
                   bswap_32big(0xf6758022U),
                   bswap_32big(0x1e7029d5U),
                   bswap_32big(0x13c8fc8cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x49f151b5U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0xc891c139U),
                   bswap_32big(0x86a055baU),
                   bswap_32big(0x9d82503bU),
                   bswap_32big(0x34be25e1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x663700e4U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0x610240baU),
                   bswap_32big(0x80c5addaU),
                   bswap_32big(0xd6cb11efU),
                   bswap_32big(0x5e63578fU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80e0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430181U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x777ccc41U), bswap_32big(0x1818b165U), bswap_32big(0x77cba35dU),
                       bswap_32big(0xe1ab8860U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x65b1d135U), bswap_32big(0xb7641973U), bswap_32big(0xaa962ea4U),
                           bswap_32big(0x2ec98579U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0xb56ca2f0U), bswap_32big(0x33c84e74U), bswap_32big(0x2c3132bcU),
                           bswap_32big(0x4a690c3fU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xf46add5bU), bswap_32big(0x35dde675U), bswap_32big(0xd99957a6U),
                           bswap_32big(0x78a3ddeaU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x149a8f2fU), bswap_32big(0xb9e6ce3cU), bswap_32big(0xec8cd02fU),
                           bswap_32big(0x752ebaceU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0x9299a1e9U), bswap_32big(0x9efe8b10U), bswap_32big(0x81227456U),
                           bswap_32big(0xe5ba2f9aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0x156cf8c5U), bswap_32big(0xac13d421U), bswap_32big(0x8a0eb813U),
                           bswap_32big(0xe8dd6c1fU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x188ebc71U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0x402d7f83U), bswap_32big(0x5892b683U), bswap_32big(0x5f225df5U),
                           bswap_32big(0xdbc898f3U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x49f151b5U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0x6d41bdeaU), bswap_32big(0x60ed2dfcU), bswap_32big(0xf51cab00U),
                           bswap_32big(0xfbd81634U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xf1017e71U), bswap_32big(0xcc2d4363U), bswap_32big(0xa2d376f9U),
                           bswap_32big(0xa3307fa8U));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x188ebc71U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0x5132993bU), bswap_32big(0x6a2771f5U), bswap_32big(0xa53836eaU),
                           bswap_32big(0x232001d4U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x49f151b5U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0x164dda78U), bswap_32big(0x2ff72caeU), bswap_32big(0x7b50ec37U),
                           bswap_32big(0x0dd80541U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x7b68b1daU), bswap_32big(0x8de75df7U), bswap_32big(0xfc0d7589U),
                           bswap_32big(0xbbb688ddU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0xcb48635eU),
                               bswap_32big(0xed19f1a1U),
                               bswap_32big(0x8bd9edbdU),
                               bswap_32big(0x51c3dd05U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x188ebc71U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0xc659a698U),
                               bswap_32big(0x4752b1fdU),
                               bswap_32big(0x9aba954dU),
                               bswap_32big(0xc3aa9e56U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0x43d91f79U),
                               bswap_32big(0x0eec9a97U),
                               bswap_32big(0xa76fae64U),
                               bswap_32big(0x2b1e0154U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0xde356afeU),
                               bswap_32big(0xa2f03977U),
                               bswap_32big(0x9e16151fU),
                               bswap_32big(0x80762e81U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0xe229cd8eU),
                               bswap_32big(0x96d1c6d2U),
                               bswap_32big(0x1b71f593U),
                               bswap_32big(0x3c1e3a65U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x49f151b5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0x3085ededU),
                               bswap_32big(0x79d1bee5U),
                               bswap_32big(0x7f0093adU),
                               bswap_32big(0x5b53f9a1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0xef37f89aU),
                               bswap_32big(0xe1a4b80aU),
                               bswap_32big(0xf4c9d8a6U),
                               bswap_32big(0x17720b57U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x59792063U),
                               bswap_32big(0x23fc8abcU),
                               bswap_32big(0xbb6ff2daU),
                               bswap_32big(0x8a38d904U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x37fd256fU),
                               bswap_32big(0x35afe214U),
                               bswap_32big(0x648194bbU),
                               bswap_32big(0xec9d87e2U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0x188ebc71U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0xe9d02818U),
                               bswap_32big(0x901ae5bfU),
                               bswap_32big(0xc3537ec0U),
                               bswap_32big(0x1779cc35U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb0f572e0U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x87e8da16U),
                               bswap_32big(0xed3ca85cU),
                               bswap_32big(0x2e08ef4eU),
                               bswap_32big(0x4edae14cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0x013868f9U),
                               bswap_32big(0x8ad5f88fU),
                               bswap_32big(0x8f92b66fU),
                               bswap_32big(0xfde454e9U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x188ebc71U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x96b3d8d4U),
                               bswap_32big(0x0a3b98ecU),
                               bswap_32big(0xf3504ba4U),
                               bswap_32big(0xbd5d211cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x49f151b5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xa4b2e8e6U),
                               bswap_32big(0xb1135df1U),
                               bswap_32big(0xb82ee651U),
                               bswap_32big(0x450e0d51U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa33fb8f4U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xfbe3c215U),
                               bswap_32big(0x0f8f83d0U),
                               bswap_32big(0xc7f86169U),
                               bswap_32big(0x337d41ceU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0xcf51e1bcU),
                               bswap_32big(0x35997ba2U),
                               bswap_32big(0xde1b0c66U),
                               bswap_32big(0x78fbcc8fU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x49f151b5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0x5af2d529U),
                               bswap_32big(0x2a79c2f0U),
                               bswap_32big(0x430ce4dbU),
                               bswap_32big(0xf46fc684U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x98a66dd3U),
                               bswap_32big(0x9f817068U),
                               bswap_32big(0xea96dbe9U),
                               bswap_32big(0xbc055d4fU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x663700e4U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0xfef145b9U),
                   bswap_32big(0x24e634aaU),
                   bswap_32big(0xea55a092U),
                   bswap_32big(0xf5b77a62U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xa187e142U), bswap_32big(0xf337581dU), bswap_32big(0x3b3c7956U),
                       bswap_32big(0xe1a82a51U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xf1775207U), bswap_32big(0xdd6368b6U), bswap_32big(0x4513cf20U),
                           bswap_32big(0x4914ca37U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x0b88d221U), bswap_32big(0x1e170325U), bswap_32big(0xa7838ef2U),
                           bswap_32big(0x94ed7f31U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x49f151b5U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0x96859c41U),
                   bswap_32big(0x8fc924b4U),
                   bswap_32big(0x639ae538U),
                   bswap_32big(0xcfcdd32eU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x3131000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x496babffU), bswap_32big(0xc7251893U), bswap_32big(0xb31bd923U),
                       bswap_32big(0x1a641b46U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0x66673cdeU), bswap_32big(0xcf6d243eU), bswap_32big(0xed1a46e2U),
                           bswap_32big(0x5cfe25a6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xd23ded9aU), bswap_32big(0xf7b4a2ecU), bswap_32big(0x2a3b1022U),
                           bswap_32big(0x119c244cU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x2e000d2fU),
                   bswap_32big(0x98719334U),
                   bswap_32big(0x7e441b01U),
                   bswap_32big(0x1453bb64U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0x36d7a146U), bswap_32big(0x41262bf5U), bswap_32big(0x8fa58b2aU),
                       bswap_32big(0x77175718U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x899a6d7eU), bswap_32big(0xa97a8145U), bswap_32big(0x336407c3U),
                       bswap_32big(0x45c837ecU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
