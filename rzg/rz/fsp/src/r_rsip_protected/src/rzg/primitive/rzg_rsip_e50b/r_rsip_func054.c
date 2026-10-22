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

void r_rsip_func054 (void)
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
        r_rsip_func100(bswap_32big(0x1a4b7fedU), bswap_32big(0xb956118fU), bswap_32big(0xff4a4255U),
                       bswap_32big(0xb6fe247eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xdcaf17c0U), bswap_32big(0xd18d8a8cU), bswap_32big(0x869d8501U),
                           bswap_32big(0x8ea33867U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc3640205U), bswap_32big(0xf7b4e418U), bswap_32big(0x31147727U),
                           bswap_32big(0x3c79cc42U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0x869062adU),
                   bswap_32big(0x987d1498U),
                   bswap_32big(0x0bcebffaU),
                   bswap_32big(0x6d4ee1e1U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0983e362U));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0xe0fa9eb2U),
                   bswap_32big(0x46180d2bU),
                   bswap_32big(0xab1b2940U),
                   bswap_32big(0x786d760cU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0x9cc8bdbaU),
                   bswap_32big(0x9460edf5U),
                   bswap_32big(0xb740ccdeU),
                   bswap_32big(0x58aa8137U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0xf40ee750U),
                   bswap_32big(0x1b5a2af8U),
                   bswap_32big(0x10ae1732U),
                   bswap_32big(0xe71daa3cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x8008fd7fU));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0x7583ed9dU),
                   bswap_32big(0xa91b0e8cU),
                   bswap_32big(0x1a382a2aU),
                   bswap_32big(0x3f64d8e4U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15300000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80c0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430101U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19400000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c000fdU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x2020000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xde867492U), bswap_32big(0xecb4cd9dU), bswap_32big(0xa213f80bU),
                       bswap_32big(0xa1398fe3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x7e00271bU), bswap_32big(0x8be16122U), bswap_32big(0xcf495832U),
                           bswap_32big(0x79579c51U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0xc59c5e11U), bswap_32big(0x8fb1f609U), bswap_32big(0x2f0be3d4U),
                           bswap_32big(0x67160360U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0xba0a5b77U), bswap_32big(0xcab99351U), bswap_32big(0x9bb5d22bU),
                           bswap_32big(0x1928034bU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x5a6fd521U), bswap_32big(0x4330ae25U), bswap_32big(0xe26e9e28U),
                           bswap_32big(0x91fcad00U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0x6e64d62cU), bswap_32big(0xd8a68b51U), bswap_32big(0xe67e8ffaU),
                           bswap_32big(0x8fdbe6f8U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0xb71b544dU), bswap_32big(0x2dab5011U), bswap_32big(0x4cf8ffaeU),
                           bswap_32big(0x06cc899cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0983e362U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0x1101c4d0U), bswap_32big(0x00ea3213U), bswap_32big(0x161b2f50U),
                           bswap_32big(0x4e8b5c84U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0x92bd623dU), bswap_32big(0x054b46ceU), bswap_32big(0x82d63e06U),
                           bswap_32big(0x8336f207U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x2f4b7ddbU), bswap_32big(0x6ceeef6bU), bswap_32big(0x203a21bfU),
                           bswap_32big(0xaa990f40U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x0983e362U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0x639ce739U), bswap_32big(0x2a8b6d7fU), bswap_32big(0xc9342a49U),
                           bswap_32big(0x520bc615U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0x0a0aa65bU), bswap_32big(0x2dc9816dU), bswap_32big(0xe5f9682aU),
                           bswap_32big(0x7d969ca7U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x8dd94613U), bswap_32big(0x385f9f8bU), bswap_32big(0x70bca6fbU),
                           bswap_32big(0x8699d780U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0x8cb4f3abU),
                               bswap_32big(0x114be179U),
                               bswap_32big(0xa7979d97U),
                               bswap_32big(0x95d61cc7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0983e362U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0x5993a1dfU),
                               bswap_32big(0x50ea7c8aU),
                               bswap_32big(0xd6cd06b5U),
                               bswap_32big(0x2914e011U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0x8fa4b053U),
                               bswap_32big(0x61130a6eU),
                               bswap_32big(0x657e89d5U),
                               bswap_32big(0x354af347U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xfb44ba81U),
                               bswap_32big(0x6cfcd19cU),
                               bswap_32big(0x2d9ad301U),
                               bswap_32big(0xab2c53eaU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0x667998a4U),
                               bswap_32big(0xff9f77e1U),
                               bswap_32big(0x3f564d37U),
                               bswap_32big(0xfd29bff4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0x3a44fbd0U),
                               bswap_32big(0x170a3726U),
                               bswap_32big(0xbefbf987U),
                               bswap_32big(0x277277a1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0xc4ac69e7U),
                               bswap_32big(0x2e45c402U),
                               bswap_32big(0xa11a3b79U),
                               bswap_32big(0x033b3874U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xf1dda1b3U),
                               bswap_32big(0x3f24af4bU),
                               bswap_32big(0xd9f76460U),
                               bswap_32big(0x4e742747U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xbc68bce4U),
                               bswap_32big(0xe2c858e7U),
                               bswap_32big(0xf092c806U),
                               bswap_32big(0xee85abb3U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0x0983e362U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xe868402dU),
                               bswap_32big(0x41450402U),
                               bswap_32big(0xe455929cU),
                               bswap_32big(0x2a0a3961U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xeef9c3e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xbbe40b7aU),
                               bswap_32big(0x15a0f8ffU),
                               bswap_32big(0xd80a2db3U),
                               bswap_32big(0x563e4e41U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0xe69e16deU),
                               bswap_32big(0x4bd4698aU),
                               bswap_32big(0xa9cba079U),
                               bswap_32big(0x07b182a0U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x0983e362U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0xcb4269c4U),
                               bswap_32big(0xf9e688f7U),
                               bswap_32big(0x6e86ef3dU),
                               bswap_32big(0x05bb06c2U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0xcb3ebfa8U),
                               bswap_32big(0xac98b216U),
                               bswap_32big(0x3b3ed57fU),
                               bswap_32big(0xd52b9cf7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xaa2893c8U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x3d52122aU),
                               bswap_32big(0x5e1c92b3U),
                               bswap_32big(0x64826c3bU),
                               bswap_32big(0x72561b32U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0x273a8f71U),
                               bswap_32big(0xe7f2ac61U),
                               bswap_32big(0xeec63eaeU),
                               bswap_32big(0xd5d6d2d7U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x83637b7cU),
                               bswap_32big(0xd82291eeU),
                               bswap_32big(0xe69099fbU),
                               bswap_32big(0x9bb527ebU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x02744746U),
                               bswap_32big(0x175347d7U),
                               bswap_32big(0x4ede5fafU),
                               bswap_32big(0xca7cda59U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x8008fd7fU));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0x80fc5b4dU),
                   bswap_32big(0xb5f6f4edU),
                   bswap_32big(0xa68cbda6U),
                   bswap_32big(0xa8eb3da3U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0xa16d93d2U), bswap_32big(0x462dc6a4U), bswap_32big(0xe0f72464U),
                       bswap_32big(0x3a185972U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x35d9e6d4U), bswap_32big(0x9f2af3a9U), bswap_32big(0xef79fb86U),
                           bswap_32big(0x49a657f3U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x9656644bU), bswap_32big(0xc6b9ecb1U), bswap_32big(0xad915af4U),
                           bswap_32big(0x5419f656U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xf18c28f0U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0xc89ee149U),
                   bswap_32big(0xef3b4159U),
                   bswap_32big(0xcb4f1d15U),
                   bswap_32big(0x2ea5b059U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17280000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x2121000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x288bf427U), bswap_32big(0x98a2548aU), bswap_32big(0x9f64c5b8U),
                       bswap_32big(0x1eed47c9U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0xdb5a22b6U), bswap_32big(0x23edb306U), bswap_32big(0xc67ac1ceU),
                           bswap_32big(0x350dfef5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xa3267b12U), bswap_32big(0xeef93c45U), bswap_32big(0x53a8ddc8U),
                           bswap_32big(0x1c1c515aU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x4d7523d2U),
                   bswap_32big(0x377f4fcbU),
                   bswap_32big(0x61200b57U),
                   bswap_32big(0xe25c797fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0x44d491eeU), bswap_32big(0x7c9abf0bU), bswap_32big(0x29eaaad7U),
                       bswap_32big(0x452bf944U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xca3c2776U), bswap_32big(0x77c93de5U), bswap_32big(0xa9933552U),
                       bswap_32big(0x26fb5d65U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
