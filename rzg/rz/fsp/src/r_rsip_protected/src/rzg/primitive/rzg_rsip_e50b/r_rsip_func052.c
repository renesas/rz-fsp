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

void r_rsip_func052 (void)
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
        r_rsip_func100(bswap_32big(0xda6b18bbU), bswap_32big(0xcca30f9eU), bswap_32big(0xe31317cdU),
                       bswap_32big(0x0a432b37U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x02257984U), bswap_32big(0xed65290fU), bswap_32big(0xe70163e9U),
                           bswap_32big(0xb0f5fa3eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5dac6e0bU), bswap_32big(0x54dd1946U), bswap_32big(0xe396dab4U),
                           bswap_32big(0x7a62d4beU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0x987ad3a7U),
                   bswap_32big(0x1d068509U),
                   bswap_32big(0x655d4c8bU),
                   bswap_32big(0xde0dc089U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x517ad655U));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0x4d5c1f20U),
                   bswap_32big(0x88d3db5dU),
                   bswap_32big(0x9ce3f028U),
                   bswap_32big(0x68b39eedU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0x17c084fdU),
                   bswap_32big(0x37454be0U),
                   bswap_32big(0x7d9c2668U),
                   bswap_32big(0xe676e7b1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0xead17974U),
                   bswap_32big(0xda759951U),
                   bswap_32big(0x7cfd97e9U),
                   bswap_32big(0x55c1e636U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x313512c8U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x42e024c3U),
                   bswap_32big(0x9298ebd1U),
                   bswap_32big(0x7d37128bU),
                   bswap_32big(0xf699fc43U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430081U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x09300f02U), bswap_32big(0xf96a6feeU), bswap_32big(0x4b4951d5U),
                       bswap_32big(0x2cd52a40U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x45b24064U), bswap_32big(0x82bfe266U), bswap_32big(0x6dff7928U),
                           bswap_32big(0x80512c54U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x3e4ed52fU), bswap_32big(0x92a33c0dU), bswap_32big(0x5248e8adU),
                           bswap_32big(0x44b9f3daU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x96cbaab3U), bswap_32big(0xef0d0e19U), bswap_32big(0x58812b22U),
                           bswap_32big(0x2f9679acU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x2a6d8d78U), bswap_32big(0x59daeb74U), bswap_32big(0xfa559e28U),
                           bswap_32big(0xae24d9f5U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0xdee08466U), bswap_32big(0x4a5d1644U), bswap_32big(0x96ce8c1eU),
                           bswap_32big(0x0fa77c94U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0xceb43895U), bswap_32big(0x4d4ba8d1U), bswap_32big(0x468c727bU),
                           bswap_32big(0x65632cb1U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x517ad655U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0x76bc7576U), bswap_32big(0x223c1dbdU), bswap_32big(0x322ef5d9U),
                           bswap_32big(0x82be3fa1U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0xd1c83501U), bswap_32big(0xa2fe755aU), bswap_32big(0x620eefa6U),
                           bswap_32big(0x020314dfU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x73ce3943U), bswap_32big(0x0a6ea12eU), bswap_32big(0x39b8dd1eU),
                           bswap_32big(0xad2254d2U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0x517ad655U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0x9cf5548bU), bswap_32big(0x2533f409U), bswap_32big(0x43fd6147U),
                           bswap_32big(0xea04a5edU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0x7dc28c45U), bswap_32big(0x222a5fd7U), bswap_32big(0x8079a2b0U),
                           bswap_32big(0xea655188U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x0a011640U), bswap_32big(0xe82a7563U), bswap_32big(0xc68a2a43U),
                           bswap_32big(0x46364bf4U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0x9245fc51U),
                               bswap_32big(0xd2958e39U),
                               bswap_32big(0xc150d7a8U),
                               bswap_32big(0x7d3c37f9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x517ad655U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0x518839bcU),
                               bswap_32big(0x72fca223U),
                               bswap_32big(0xf083aa65U),
                               bswap_32big(0xde4eaeefU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0xd61abf4aU),
                               bswap_32big(0xd7c242d5U),
                               bswap_32big(0x90c8e0b9U),
                               bswap_32big(0x4969707cU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0xea795818U),
                               bswap_32big(0x4aef3a59U),
                               bswap_32big(0x53964f29U),
                               bswap_32big(0xe0e2bed3U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0xb11b7495U),
                               bswap_32big(0xb13470c5U),
                               bswap_32big(0x8175cf12U),
                               bswap_32big(0x6c612c40U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0x63e3d0b1U),
                               bswap_32big(0x935816bbU),
                               bswap_32big(0x660f7e45U),
                               bswap_32big(0x9bc07bf5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0x4557945dU),
                               bswap_32big(0x8c688995U),
                               bswap_32big(0xb7d50047U),
                               bswap_32big(0xaef14a24U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x79d54390U),
                               bswap_32big(0xbaaa2894U),
                               bswap_32big(0xb5adc2e0U),
                               bswap_32big(0x7297424eU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xc1c6c93fU),
                               bswap_32big(0x89f89353U),
                               bswap_32big(0xd875212aU),
                               bswap_32big(0xfddc2ce6U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0x517ad655U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x3590b66aU),
                               bswap_32big(0x6d2265a0U),
                               bswap_32big(0x9d7c17dcU),
                               bswap_32big(0x68721945U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xcb10d4dbU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x1a86cae7U),
                               bswap_32big(0x938e9dd5U),
                               bswap_32big(0x34588805U),
                               bswap_32big(0xf4c70692U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0xb34c75e1U),
                               bswap_32big(0x0c5227c2U),
                               bswap_32big(0x5afe700dU),
                               bswap_32big(0x471d052cU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x517ad655U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x8a493479U),
                               bswap_32big(0x4cf907a1U),
                               bswap_32big(0xc758bde4U),
                               bswap_32big(0x65e87065U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x4d219b54U),
                               bswap_32big(0x1ff75badU),
                               bswap_32big(0x2bdc82b3U),
                               bswap_32big(0xfd4dd730U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe010fe4bU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x8dddba72U),
                               bswap_32big(0x9d9639acU),
                               bswap_32big(0xb72113f7U),
                               bswap_32big(0x0904a5b8U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0x1304336cU),
                               bswap_32big(0x54b210b7U),
                               bswap_32big(0x99787ab4U),
                               bswap_32big(0x095a51d3U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0xbcd707d9U),
                               bswap_32big(0x5b2031c5U),
                               bswap_32big(0x0922d5e5U),
                               bswap_32big(0x44a56507U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x4d5c0da3U),
                               bswap_32big(0x130ec5afU),
                               bswap_32big(0xc3c34456U),
                               bswap_32big(0x45e8787eU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x313512c8U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0xcaaa2dfeU),
                   bswap_32big(0x378d3326U),
                   bswap_32big(0x2d960430U),
                   bswap_32big(0x8458b550U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x95f301a3U), bswap_32big(0x549c1a6cU), bswap_32big(0xbef8e709U),
                       bswap_32big(0x679a2692U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x52181263U), bswap_32big(0x5fab625cU), bswap_32big(0xff757404U),
                           bswap_32big(0x078eeecaU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x88400e11U), bswap_32big(0xc1f889b2U), bswap_32big(0xd5a96a6bU),
                           bswap_32big(0xafdb0312U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0eebbc1fU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x263a89aeU),
                   bswap_32big(0x5409a05fU),
                   bswap_32big(0x6ae4ac7dU),
                   bswap_32big(0x287011a7U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x1111000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x3c3ec3ffU), bswap_32big(0xd7949847U), bswap_32big(0xd8174acfU),
                       bswap_32big(0xc7053473U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0xa2bfc772U), bswap_32big(0x4889b334U), bswap_32big(0xc04d4726U),
                           bswap_32big(0xa3ed8e9eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1721a005U), bswap_32big(0x2c6cdd42U), bswap_32big(0x2d6a825cU),
                           bswap_32big(0x09b65c43U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x4457c0aaU),
                   bswap_32big(0x155abb73U),
                   bswap_32big(0xb5dced87U),
                   bswap_32big(0x8e260a7eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0xb527d564U), bswap_32big(0x39ecdc0cU), bswap_32big(0xc9126be6U),
                       bswap_32big(0x4883e369U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x033b7b7aU), bswap_32big(0xe55d300dU), bswap_32big(0xac7125c1U),
                       bswap_32big(0x74d026c9U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
