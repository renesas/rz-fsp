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
        r_rsip_func100(bswap_32big(0x40641a43U), bswap_32big(0x77dfcb0cU), bswap_32big(0x1f531cfaU),
                       bswap_32big(0x76ab2e8eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6611f983U), bswap_32big(0xd7e3d7a0U), bswap_32big(0x96f819a6U),
                           bswap_32big(0x4a5588ccU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x67e17b4dU), bswap_32big(0x7c3279eeU), bswap_32big(0x02e775a7U),
                           bswap_32big(0x7eac2ad1U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0x79e41893U));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0x346fab15U),
                   bswap_32big(0xcf429dbbU),
                   bswap_32big(0x70b8b9ceU),
                   bswap_32big(0x8fb6577bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xf70bd375U));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0xbb7114a1U),
                   bswap_32big(0xab728570U),
                   bswap_32big(0xff25a3c8U),
                   bswap_32big(0xf394ea31U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0xe32a6999U),
                   bswap_32big(0xba45f7a1U),
                   bswap_32big(0x85acf9e1U),
                   bswap_32big(0x717f32f8U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xfc76e800U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0x22301fadU),
                   bswap_32big(0xdea2c1d5U),
                   bswap_32big(0x3a0b2d47U),
                   bswap_32big(0x622fc4d9U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3aefe239U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0xbc67a1ebU),
                   bswap_32big(0x028f8805U),
                   bswap_32big(0x23c7abf8U),
                   bswap_32big(0x030ec807U));
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
        r_rsip_func100(bswap_32big(0x198d6533U), bswap_32big(0xf1d11119U), bswap_32big(0x412bf26eU),
                       bswap_32big(0x83df5ceeU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xe1648ddcU), bswap_32big(0x6a840accU), bswap_32big(0xd6d93a19U),
                           bswap_32big(0x14e16f98U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0xf816fc8fU), bswap_32big(0x02f744abU), bswap_32big(0xb542de70U),
                           bswap_32big(0x293fd0e8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x79e41893U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x3fb3781aU), bswap_32big(0x1cd873fbU), bswap_32big(0x1599d334U),
                           bswap_32big(0xbda6f095U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x74742213U), bswap_32big(0xede09c07U), bswap_32big(0x2935ecbfU),
                           bswap_32big(0xff1f5a1dU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0x6f99098cU), bswap_32big(0xccdde78dU), bswap_32big(0x913d4ad5U),
                           bswap_32big(0x6d330e51U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x79e41893U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x66ee597cU), bswap_32big(0xbcad4196U), bswap_32big(0xa03d43b1U),
                           bswap_32big(0x8e641933U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf70bd375U));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0x71522e01U), bswap_32big(0xe68a5d70U), bswap_32big(0x58e18810U),
                           bswap_32big(0x03d10fcdU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xfc76e800U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0x1bc54f91U), bswap_32big(0xac39c090U), bswap_32big(0x435ac76dU),
                           bswap_32big(0xea16af93U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0xc83d2a6cU), bswap_32big(0x54f71bacU), bswap_32big(0x3cde30adU),
                           bswap_32big(0x9f03f9efU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0xf70bd375U));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0x91c3acefU), bswap_32big(0xb11a643fU), bswap_32big(0x5745d406U),
                           bswap_32big(0xbec668bbU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xfc76e800U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0xc2180662U), bswap_32big(0x1a528f41U), bswap_32big(0x6db336fcU),
                           bswap_32big(0xd2727427U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x39a3fca3U), bswap_32big(0x2fbfe95eU), bswap_32big(0xf50c4e72U),
                           bswap_32big(0x526da72cU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0x08046de8U),
                               bswap_32big(0x9a2594e9U),
                               bswap_32big(0x0c725298U),
                               bswap_32big(0x06fe6605U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf70bd375U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0xf13c5aecU),
                               bswap_32big(0x59bfeb72U),
                               bswap_32big(0xe1f6d371U),
                               bswap_32big(0x17a8b00bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0x2da534aaU),
                               bswap_32big(0x4ebfbcaeU),
                               bswap_32big(0xec11a63cU),
                               bswap_32big(0x80e68fccU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x21af5b81U),
                               bswap_32big(0x88fea69eU),
                               bswap_32big(0x036b63beU),
                               bswap_32big(0x4d8066f5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x79e41893U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0x46f2419bU),
                               bswap_32big(0x18bd7f80U),
                               bswap_32big(0x1979b914U),
                               bswap_32big(0xb80ec222U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xfc76e800U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0x2a224809U),
                               bswap_32big(0x19db8631U),
                               bswap_32big(0x6b76e25dU),
                               bswap_32big(0x6f9113f0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0xe339c0d1U),
                               bswap_32big(0x9072cf5fU),
                               bswap_32big(0xbcf34317U),
                               bswap_32big(0xd1df6f69U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x79e41893U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xb0b7660fU),
                               bswap_32big(0x4fd4b5dfU),
                               bswap_32big(0x25faf6abU),
                               bswap_32big(0x4e8fb298U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x98c1b340U),
                               bswap_32big(0x62de7384U),
                               bswap_32big(0x97ba97b1U),
                               bswap_32big(0xb02fe807U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0xf70bd375U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0xd21d9e98U),
                               bswap_32big(0x7b4378d0U),
                               bswap_32big(0xe9c32d5aU),
                               bswap_32big(0x30c281caU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9b9b8182U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xb355d02bU),
                               bswap_32big(0x6cda28f3U),
                               bswap_32big(0x41b3c69dU),
                               bswap_32big(0x24a26c9cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0x27d35b2aU),
                               bswap_32big(0x28423500U),
                               bswap_32big(0xb12482ebU),
                               bswap_32big(0x1e93ff09U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xf70bd375U));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x35c81b57U),
                               bswap_32big(0xacbf4518U),
                               bswap_32big(0x4796517dU),
                               bswap_32big(0x2c09c0c0U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xfc76e800U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x666c0e4dU),
                               bswap_32big(0x9e0562e9U),
                               bswap_32big(0x94f64988U),
                               bswap_32big(0xe3c2cf9eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x79e41893U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x8ffd696fU),
                               bswap_32big(0xc4c2ae16U),
                               bswap_32big(0xccde833fU),
                               bswap_32big(0x63c87bc2U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0xac16fa4fU),
                               bswap_32big(0x8fb33b57U),
                               bswap_32big(0x75288893U),
                               bswap_32big(0x68630319U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xfc76e800U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0xeeeadc14U),
                               bswap_32big(0x75375c98U),
                               bswap_32big(0xbd74dbf8U),
                               bswap_32big(0x66c37bd9U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x405818faU),
                               bswap_32big(0x5682eb73U),
                               bswap_32big(0x9c1e0309U),
                               bswap_32big(0xfd2faa0fU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x3aefe239U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0xda9e42bfU),
                   bswap_32big(0xa3154944U),
                   bswap_32big(0x23392c47U),
                   bswap_32big(0xb8461239U));
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
        r_rsip_func100(bswap_32big(0xb7e23662U), bswap_32big(0xbd84dddcU), bswap_32big(0x44bcac30U),
                       bswap_32big(0xe852954eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x915128afU), bswap_32big(0x1f488c1eU), bswap_32big(0x72d6ca40U),
                           bswap_32big(0x5dcca3d0U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8ba96eb6U), bswap_32big(0xe694547aU), bswap_32big(0xf99a9a13U),
                           bswap_32big(0xaeba3490U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xfc76e800U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0x310ed1deU),
                   bswap_32big(0x99c02995U),
                   bswap_32big(0x45bfb62cU),
                   bswap_32big(0xab342ab7U));
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
        r_rsip_func100(bswap_32big(0x53d64a25U), bswap_32big(0xb9d07a2dU), bswap_32big(0x1a757af4U),
                       bswap_32big(0x89e7dd46U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0x887b981bU), bswap_32big(0xefa91e9cU), bswap_32big(0x4c593bbaU),
                           bswap_32big(0xc6788ce3U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1e01da60U), bswap_32big(0x33fbfb05U), bswap_32big(0x9787b9d1U),
                           bswap_32big(0x51d60af5U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xac11ef0eU),
                   bswap_32big(0x82378912U),
                   bswap_32big(0x8900e9d8U),
                   bswap_32big(0x2526c707U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0xb2ed15ecU), bswap_32big(0x834caedaU), bswap_32big(0x156570e1U),
                       bswap_32big(0x26c989d9U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x8bedae97U), bswap_32big(0x6a575d0eU), bswap_32big(0x30a46782U),
                       bswap_32big(0x24b0847aU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
