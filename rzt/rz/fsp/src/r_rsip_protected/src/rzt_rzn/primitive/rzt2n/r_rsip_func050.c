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
        r_rsip_func100(bswap_32big(0x259029e7U), bswap_32big(0x89824b0cU), bswap_32big(0x98c3637cU),
                       bswap_32big(0xa145926dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xdc89a39dU), bswap_32big(0xae082f5cU), bswap_32big(0x981e22ccU),
                           bswap_32big(0x3a1677eeU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb208a652U), bswap_32big(0xa0b0974fU), bswap_32big(0x34e3cc62U),
                           bswap_32big(0x656b27c2U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0xa9cf23baU),
                   bswap_32big(0x7a631f0aU),
                   bswap_32big(0x57ebc9f5U),
                   bswap_32big(0x38758ee8U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0x448ab4abU),
                   bswap_32big(0xc6ec2eceU),
                   bswap_32big(0xf090ec22U),
                   bswap_32big(0xd7701509U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x884aee22U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0x9d998963U),
                   bswap_32big(0x21f62d5aU),
                   bswap_32big(0xd5d2501cU),
                   bswap_32big(0xe03ed2b9U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0xac980532U),
                   bswap_32big(0xf5efdb79U),
                   bswap_32big(0x430112c0U),
                   bswap_32big(0x68d43e52U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xde9d8f77U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0xba2c4f84U),
                   bswap_32big(0x90fc63edU),
                   bswap_32big(0x8d3d9a0aU),
                   bswap_32big(0x6b09eb1bU));
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
        r_rsip_func100(bswap_32big(0x65ee07dfU), bswap_32big(0xff228b1aU), bswap_32big(0xbb4aa1edU),
                       bswap_32big(0xc1883e13U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xa1470526U), bswap_32big(0xf961cab2U), bswap_32big(0x640a83aaU),
                           bswap_32big(0x54a83d9dU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x884aee22U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0xafb2ce93U), bswap_32big(0x02a09355U), bswap_32big(0xb1a1c96eU),
                           bswap_32big(0x596b03adU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0xba896477U), bswap_32big(0xf6e51aa5U), bswap_32big(0xe8df088cU),
                           bswap_32big(0xe25b92d1U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x0fd6ec94U), bswap_32big(0xe086a416U), bswap_32big(0xe3fd83fcU),
                           bswap_32big(0xabe5e9baU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x884aee22U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0x6326802aU), bswap_32big(0x78b33d08U), bswap_32big(0x406d5c73U),
                           bswap_32big(0x74ba9a1dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x60be6783U), bswap_32big(0xa8ffc2cdU), bswap_32big(0x0cc9113cU),
                           bswap_32big(0x76036902U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0xedd1df85U), bswap_32big(0x00ada77fU), bswap_32big(0x590bea42U),
                           bswap_32big(0x9c432167U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0xe191d57eU), bswap_32big(0x56e732e6U), bswap_32big(0x1c3847f0U),
                           bswap_32big(0xb04d5ba0U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x03424e48U), bswap_32big(0xc5853922U), bswap_32big(0x00908116U),
                           bswap_32big(0xdf6eab6cU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0xfdb374e2U), bswap_32big(0xc43d2a43U), bswap_32big(0xc4287ee1U),
                           bswap_32big(0x4e09aa51U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0x95c14437U), bswap_32big(0x5eda6969U), bswap_32big(0xb7b06f37U),
                           bswap_32big(0xb85e936fU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x4c7b48c2U), bswap_32big(0x20cf331bU), bswap_32big(0x9ab7f4ebU),
                           bswap_32big(0x5a0aad25U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0x884aee22U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0x2669426eU),
                               bswap_32big(0x9ab2cde8U),
                               bswap_32big(0x86e825caU),
                               bswap_32big(0x58cc1d15U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0x15f9223fU),
                               bswap_32big(0xcb23e051U),
                               bswap_32big(0xcf6785d5U),
                               bswap_32big(0xddc45d10U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0xc7c6ffd0U),
                               bswap_32big(0x4e98327dU),
                               bswap_32big(0x3a139f6eU),
                               bswap_32big(0xa2d0937cU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x884aee22U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x6636eaf4U),
                               bswap_32big(0x99e03ba1U),
                               bswap_32big(0x71cc6b89U),
                               bswap_32big(0x7a29bbe1U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0x53e01baaU),
                               bswap_32big(0x55b9b64eU),
                               bswap_32big(0x988188a3U),
                               bswap_32big(0xacf447f6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0x9c351d70U),
                               bswap_32big(0x5d77fe46U),
                               bswap_32big(0x27fe7753U),
                               bswap_32big(0xd3708685U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0x505be1b1U),
                               bswap_32big(0x0d417c60U),
                               bswap_32big(0xf04865f3U),
                               bswap_32big(0x92b13d50U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0x383641c2U),
                               bswap_32big(0xa5ea063aU),
                               bswap_32big(0xb661c08bU),
                               bswap_32big(0xaa90621dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xec5ed0ebU),
                               bswap_32big(0x3cf6c205U),
                               bswap_32big(0xfd562fcbU),
                               bswap_32big(0x816def43U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0x7da0763eU),
                               bswap_32big(0x665fed08U),
                               bswap_32big(0x5affd5f2U),
                               bswap_32big(0x53a66d32U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x884aee22U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xb3a0d67eU),
                               bswap_32big(0x403e52ddU),
                               bswap_32big(0x0804e2e0U),
                               bswap_32big(0xdf188ed7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0xb0b13582U),
                               bswap_32big(0x0b13b67bU),
                               bswap_32big(0x5d293d4bU),
                               bswap_32big(0x1cb40a72U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xb4ef45caU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x6c6805abU),
                               bswap_32big(0x1ae45803U),
                               bswap_32big(0x2616d1f4U),
                               bswap_32big(0xbb4c45a5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0x9abeec91U),
                               bswap_32big(0xaffa5434U),
                               bswap_32big(0x5a80944bU),
                               bswap_32big(0xa49ae755U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5d2dc4bcU));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0xa91f5d2cU),
                               bswap_32big(0x0d930c9dU),
                               bswap_32big(0xc797203bU),
                               bswap_32big(0x30e48d6cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0x038ed850U),
                               bswap_32big(0xa1d390a5U),
                               bswap_32big(0x30714f69U),
                               bswap_32big(0x1c6ca375U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0xc62db23aU),
                               bswap_32big(0x6f407d8fU),
                               bswap_32big(0xdd9c2896U),
                               bswap_32big(0xf6e778caU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xd4854899U),
                               bswap_32big(0x2542157eU),
                               bswap_32big(0x7594462fU),
                               bswap_32big(0x44c979d9U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xde9d8f77U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0x19f049eeU),
                   bswap_32big(0xf2ec05dfU),
                   bswap_32big(0x3184c0c4U),
                   bswap_32big(0x22e3c961U));
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
        r_rsip_func100(bswap_32big(0xa294302dU), bswap_32big(0x7e7c105bU), bswap_32big(0x4be32e9eU),
                       bswap_32big(0x5ff08a88U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8baa8b50U), bswap_32big(0xe51b5c44U), bswap_32big(0x70481fc5U),
                           bswap_32big(0xec969247U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x77d36754U), bswap_32big(0x9efbace0U), bswap_32big(0x8e857eb2U),
                           bswap_32big(0x98fef9aaU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xeb6476b4U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0x4cc2e24fU),
                   bswap_32big(0x6d748170U),
                   bswap_32big(0x140551c6U),
                   bswap_32big(0x8d044f7eU));
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
        r_rsip_func100(bswap_32big(0xd8a08018U), bswap_32big(0xba4a95cbU), bswap_32big(0x607e4cf0U),
                       bswap_32big(0x011796c1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0xe457521dU), bswap_32big(0x5db15742U), bswap_32big(0x0f27c452U),
                           bswap_32big(0x3ef244daU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x3ec3bb00U), bswap_32big(0x79782435U), bswap_32big(0x3d2e9129U),
                           bswap_32big(0xb7e44370U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xa1612a1bU),
                   bswap_32big(0xe1066fe1U),
                   bswap_32big(0xcb87931dU),
                   bswap_32big(0x03779b90U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0xd3324e9cU), bswap_32big(0xcd8a10ceU), bswap_32big(0xb6fa88e9U),
                       bswap_32big(0x29df27b0U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x038d8720U), bswap_32big(0x103f174dU), bswap_32big(0x5dc38c29U),
                       bswap_32big(0x9549824bU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
