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

void r_rsip_func050 (void)
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
        r_rsip_func100(bswap_32big(0x81563b92U), bswap_32big(0x61a28cfcU), bswap_32big(0x204be04aU),
                       bswap_32big(0xdc1d5553U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5d516675U), bswap_32big(0x2521d277U), bswap_32big(0x384f6f2bU),
                           bswap_32big(0x140a4ac7U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8923bc1fU), bswap_32big(0x44db9095U), bswap_32big(0x00c25359U),
                           bswap_32big(0xd295a6c7U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0xfd740063U),
                   bswap_32big(0x1f28a958U),
                   bswap_32big(0xf6dc2ff1U),
                   bswap_32big(0xa059350aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x056edd9bU));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0x6f2c912eU),
                   bswap_32big(0x118c6555U),
                   bswap_32big(0x7cd21251U),
                   bswap_32big(0x7ce01313U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x70e0c138U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0x54460d8aU),
                   bswap_32big(0x638f4092U),
                   bswap_32big(0xf429fb6cU),
                   bswap_32big(0xfe6962a6U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xbbe14194U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0xe5deafe3U),
                   bswap_32big(0xc43a823cU),
                   bswap_32big(0x0953464bU),
                   bswap_32big(0x0f964d4fU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x16ba58cdU));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0x5e66202eU),
                   bswap_32big(0xf01394feU),
                   bswap_32big(0xc5679d42U),
                   bswap_32big(0x0a334ac2U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15f00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x8090001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430041U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x1a000000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0003dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x0808000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x79b7f39eU), bswap_32big(0x3a712693U), bswap_32big(0x5921b678U),
                       bswap_32big(0xae0115daU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xe639a75bU), bswap_32big(0x0b4054d3U), bswap_32big(0x5c98ab5dU),
                           bswap_32big(0x64d437b8U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x70e0c138U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x0d308b5cU), bswap_32big(0x9a3dc035U), bswap_32big(0x24e775d3U),
                           bswap_32big(0x06be0bc8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0xc9621d97U), bswap_32big(0xb0360516U), bswap_32big(0xa33af338U),
                           bswap_32big(0xdcd7f032U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x54344d3dU), bswap_32big(0x415ea650U), bswap_32big(0x25f8a0c2U),
                           bswap_32big(0x4e165494U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x70e0c138U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0xcb0c13e6U), bswap_32big(0x32bdf7e2U), bswap_32big(0xd382bc0bU),
                           bswap_32big(0xf815d922U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x08d90cd1U), bswap_32big(0x00add4ccU), bswap_32big(0x3fe60b13U),
                           bswap_32big(0x5e0e8f33U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x056edd9bU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0xa759a1faU), bswap_32big(0xd16f4f76U), bswap_32big(0x4e392eccU),
                           bswap_32big(0xee4ea076U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbbe14194U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0x59430429U), bswap_32big(0x28e77c78U), bswap_32big(0x44ca287cU),
                           bswap_32big(0xb7ab272cU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x63500779U), bswap_32big(0x36f742cdU), bswap_32big(0x42ab296fU),
                           bswap_32big(0x43fcea78U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x056edd9bU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0x88b849faU), bswap_32big(0x35d0d639U), bswap_32big(0xe4b8dbd0U),
                           bswap_32big(0xf1598499U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbbe14194U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0xf4020ba0U), bswap_32big(0x857c0c33U), bswap_32big(0x2f19947bU),
                           bswap_32big(0x77efdf3dU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x669c0fa4U), bswap_32big(0x78a7243cU), bswap_32big(0x0df56a5fU),
                           bswap_32big(0x2af93e34U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0x70e0c138U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0x8436dd92U),
                               bswap_32big(0xa6424894U),
                               bswap_32big(0x5c025f60U),
                               bswap_32big(0xa7527784U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x056edd9bU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0xd429aa8cU),
                               bswap_32big(0x186eb78bU),
                               bswap_32big(0x9a101577U),
                               bswap_32big(0xa355aa6fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0x171f634cU),
                               bswap_32big(0x48bc595aU),
                               bswap_32big(0x0de6604dU),
                               bswap_32big(0x32c0a41aU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x70e0c138U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x3b3ca0dfU),
                               bswap_32big(0x13807a8dU),
                               bswap_32big(0x964bea27U),
                               bswap_32big(0x0549e797U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0x0bbbe9afU),
                               bswap_32big(0x76761adeU),
                               bswap_32big(0xec6a8132U),
                               bswap_32big(0x6d3c2af5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbbe14194U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0xd2580f7dU),
                               bswap_32big(0x7f2f269aU),
                               bswap_32big(0x4c234cfbU),
                               bswap_32big(0x22ead7e3U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0x85144119U),
                               bswap_32big(0x3e86596dU),
                               bswap_32big(0x3d474951U),
                               bswap_32big(0x3c664ad9U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xfb8880e8U),
                               bswap_32big(0x28ba7bf7U),
                               bswap_32big(0xeb03e67eU),
                               bswap_32big(0x1f64f6a3U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xbe45b773U),
                               bswap_32big(0x24c56068U),
                               bswap_32big(0x38887444U),
                               bswap_32big(0x9ecad3b3U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0x056edd9bU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0xc386bc67U),
                               bswap_32big(0xbca0feb9U),
                               bswap_32big(0x49cb7b56U),
                               bswap_32big(0xb763f46bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x70e0c138U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0x8c6f98cbU),
                               bswap_32big(0xf8ba1240U),
                               bswap_32big(0x25d4cbefU),
                               bswap_32big(0xe5cfe813U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0xfcff1200U),
                               bswap_32big(0x435071beU),
                               bswap_32big(0x1eb46c92U),
                               bswap_32big(0x849e8e3aU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x056edd9bU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0xc0047459U),
                               bswap_32big(0xfd7b1f16U),
                               bswap_32big(0xcc320c20U),
                               bswap_32big(0xcdd15902U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbbe14194U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x5c96d38fU),
                               bswap_32big(0xa55c8762U),
                               bswap_32big(0xe2e090caU),
                               bswap_32big(0x7ba4316aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc9f38ef5U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x0b702871U),
                               bswap_32big(0xb6392fd9U),
                               bswap_32big(0x0ed8416bU),
                               bswap_32big(0x793d6fa1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0x864465e7U),
                               bswap_32big(0xc0bb8904U),
                               bswap_32big(0x87f77da9U),
                               bswap_32big(0x5e228d27U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xbbe14194U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x25cd2b93U),
                               bswap_32big(0x14b181dbU),
                               bswap_32big(0xe4361991U),
                               bswap_32big(0x50af93efU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x62e16545U),
                               bswap_32big(0x9b222649U),
                               bswap_32big(0x1f473560U),
                               bswap_32big(0x511db81aU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x16ba58cdU));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0xa999509cU),
                   bswap_32big(0xb8ef7dd5U),
                   bswap_32big(0x629467d1U),
                   bswap_32big(0xb1835533U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x563ef099U), bswap_32big(0x7ac45c59U), bswap_32big(0x17dbebc9U),
                       bswap_32big(0x045693dcU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xebdb4891U), bswap_32big(0xa8fd9a5eU), bswap_32big(0x3ff45a72U),
                           bswap_32big(0x833c2c55U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x04c507fbU), bswap_32big(0x46cb04daU), bswap_32big(0xf759c0dcU),
                           bswap_32big(0x26609480U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xbbe14194U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0xc8e35315U),
                   bswap_32big(0xeb7cd071U),
                   bswap_32big(0x9fc98edfU),
                   bswap_32big(0x53ec9924U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17e80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x0909000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xe6ea168dU), bswap_32big(0xb1d930c2U), bswap_32big(0xdce25230U),
                       bswap_32big(0xe0b2a673U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0xfe8f7438U), bswap_32big(0x3b7cbc62U), bswap_32big(0x45f34739U),
                           bswap_32big(0xa748563eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc8fa7a4fU), bswap_32big(0xa61baac4U), bswap_32big(0x5679ad31U),
                           bswap_32big(0xaa46fb48U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x81ebf405U),
                   bswap_32big(0xc5f04f7eU),
                   bswap_32big(0x76396b69U),
                   bswap_32big(0xbc82ce0dU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0x66a67feeU), bswap_32big(0x290167f7U), bswap_32big(0xd36bae37U),
                       bswap_32big(0x3396b926U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x6b222eaaU), bswap_32big(0xa4a0d691U), bswap_32big(0xf05d7948U),
                       bswap_32big(0x50da4f1dU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
