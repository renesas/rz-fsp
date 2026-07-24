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
        r_rsip_func100(bswap_32big(0x435f4c59U), bswap_32big(0xfe555e54U), bswap_32big(0xf91d7fd3U),
                       bswap_32big(0x00992016U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x0808000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x0808000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x52fd6f0fU), bswap_32big(0x4f740e53U), bswap_32big(0x1aaee1e9U),
                           bswap_32big(0x8cab8993U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xa31f177dU), bswap_32big(0x9aa74049U), bswap_32big(0xbac69f92U),
                           bswap_32big(0xe4d3133eU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19f00000U);
    r_rsip_subfunc003(0x00c00051U);
    r_rsip_subfunc007(bswap_32big(0x52846a81U));
    OFS_ADR = 24;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000501U));
    r_rsip_func101(bswap_32big(0x19615fecU),
                   bswap_32big(0x02ac6fe8U),
                   bswap_32big(0x0a7d153fU),
                   bswap_32big(0x71295373U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x32b3435aU));
    OFS_ADR = 48;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
    r_rsip_func101(bswap_32big(0x31729a17U),
                   bswap_32big(0x4b68f33fU),
                   bswap_32big(0xb76ea8ebU),
                   bswap_32big(0xc030c89dU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x1a000000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0003dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000503U));
    r_rsip_func101(bswap_32big(0x461624aeU),
                   bswap_32big(0x3b387421U),
                   bswap_32big(0xe8236bf3U),
                   bswap_32big(0xfe84c61cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
    r_rsip_func101(bswap_32big(0x22d97f48U),
                   bswap_32big(0x8a953437U),
                   bswap_32big(0x7927e017U),
                   bswap_32big(0xb0ccd49aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x71574de3U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x00000505U));
    r_rsip_func101(bswap_32big(0x9b747844U),
                   bswap_32big(0x9a32fd9fU),
                   bswap_32big(0x2a2ff813U),
                   bswap_32big(0x13f1770fU));
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
        r_rsip_func100(bswap_32big(0x05a6de07U), bswap_32big(0x1ba95402U), bswap_32big(0xb75d09f3U),
                       bswap_32big(0x0a1ccccbU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xf7c12b9aU), bswap_32big(0xb5a04377U), bswap_32big(0x02cb78cfU),
                           bswap_32big(0x25bb40ebU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x825fe5b3U), bswap_32big(0x9cb1df1aU), bswap_32big(0x3aecf5d4U),
                           bswap_32big(0x30e1fc40U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x52846a81U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x3b4d6e86U), bswap_32big(0x1392a793U), bswap_32big(0x5b3eb9c8U),
                           bswap_32big(0xe6da7983U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000501U));
            r_rsip_func101(bswap_32big(0x7467776aU), bswap_32big(0xd2f08bf6U), bswap_32big(0xd2a27204U),
                           bswap_32big(0xd354778fU));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000506U));
            r_rsip_func101(bswap_32big(0x347f5fccU), bswap_32big(0xa27ea819U), bswap_32big(0xfdd5bb76U),
                           bswap_32big(0xff066d77U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x52846a81U));
            OFS_ADR = 24;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000507U));
            r_rsip_func101(bswap_32big(0x58c89111U), bswap_32big(0x53197ac9U), bswap_32big(0x5c11abecU),
                           bswap_32big(0xa50128d5U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x32b3435aU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000503U));
            r_rsip_func101(bswap_32big(0x4eeaffc7U), bswap_32big(0x56cef173U), bswap_32big(0xa3d7b671U),
                           bswap_32big(0x5162a9d2U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000504U));
            r_rsip_func101(bswap_32big(0x9e2509abU), bswap_32big(0x5a325880U), bswap_32big(0x2bb2d66cU),
                           bswap_32big(0x3791c380U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc009(bswap_32big(0x00000502U));
            r_rsip_func101(bswap_32big(0x1128dda3U), bswap_32big(0xe2905cb8U), bswap_32big(0x16cbe672U),
                           bswap_32big(0x71a3c040U));
            r_rsip_func051();
            r_rsip_subfunc007(bswap_32big(0x32b3435aU));
            OFS_ADR = 48;
            r_rsip_subfunc008(0x13d80000U, 0x00000014U, bswap_32big(0x00000508U));
            r_rsip_func101(bswap_32big(0x47c535b5U), bswap_32big(0xa0071574U), bswap_32big(0x984f2e4aU),
                           bswap_32big(0x89f7f585U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19f00000U, 0x00000014U, bswap_32big(0x00000509U));
            r_rsip_func101(bswap_32big(0x199b1441U), bswap_32big(0x5cfd451eU), bswap_32big(0xdae3db77U),
                           bswap_32big(0x8832a983U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f980000U);
            r_rsip_subfunc003(0x00c00041U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x08080009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x08080009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x08080009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x0808000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x8f625e32U), bswap_32big(0x53a9396fU), bswap_32big(0xaca45790U),
                           bswap_32big(0x761d7e81U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x08080009U);
                r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000505U));
                r_rsip_func101(bswap_32big(0x6855d97bU),
                               bswap_32big(0xbb96f2d6U),
                               bswap_32big(0x98fa18beU),
                               bswap_32big(0xfbc93a82U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x32b3435aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000506U));
                r_rsip_func101(bswap_32big(0x5d830426U),
                               bswap_32big(0xfaf656aeU),
                               bswap_32big(0x636dbecbU),
                               bswap_32big(0x0cd4a5acU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000501U));
                r_rsip_func101(bswap_32big(0xb32d6dc4U),
                               bswap_32big(0xe02cf78fU),
                               bswap_32big(0x1d2ca34dU),
                               bswap_32big(0xd59f683bU));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0xf31f02bfU),
                               bswap_32big(0x4ba6e09dU),
                               bswap_32big(0xc908ff75U),
                               bswap_32big(0xff4179aaU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x52846a81U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x00000507U));
                r_rsip_func101(bswap_32big(0x2eac9e3eU),
                               bswap_32big(0x207bb16aU),
                               bswap_32big(0x615ff93bU),
                               bswap_32big(0x43e9c10dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x00000508U));
                r_rsip_func101(bswap_32big(0x3988c265U),
                               bswap_32big(0x4fb1c7d4U),
                               bswap_32big(0xb9424bb3U),
                               bswap_32big(0x15272f8aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000502U));
                r_rsip_func101(bswap_32big(0x8b43a491U),
                               bswap_32big(0xc9f537d4U),
                               bswap_32big(0x6ac16913U),
                               bswap_32big(0x6fdcffb0U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x52846a81U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0x52a935caU),
                               bswap_32big(0xe05bafbeU),
                               bswap_32big(0xcb2fd7a5U),
                               bswap_32big(0x362c86a9U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xc3891dcaU),
                               bswap_32big(0x945dfac9U),
                               bswap_32big(0xa0de9d6aU),
                               bswap_32big(0xf008e0aaU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x0808000aU);
                r_rsip_subfunc007(bswap_32big(0x32b3435aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050aU));
                r_rsip_func101(bswap_32big(0xe27f9606U),
                               bswap_32big(0xf4b5f017U),
                               bswap_32big(0x6fd1fa8bU),
                               bswap_32big(0xdeabd64bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x57cd6e70U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050bU));
                r_rsip_func101(bswap_32big(0xa520dbe1U),
                               bswap_32big(0x12e24b7cU),
                               bswap_32big(0x60e2f27bU),
                               bswap_32big(0x35abcec1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000503U));
                r_rsip_func101(bswap_32big(0x7f4ba3bfU),
                               bswap_32big(0x1fb7dbf1U),
                               bswap_32big(0x5f2d5428U),
                               bswap_32big(0xa4d7f4a1U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0x32b3435aU));
                OFS_ADR = 48;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0xdd6a26e1U),
                               bswap_32big(0x6aae0af4U),
                               bswap_32big(0x4d39615aU),
                               bswap_32big(0x1d2ce88fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050cU));
                r_rsip_func101(bswap_32big(0xcaf07124U),
                               bswap_32big(0x5c7a3fffU),
                               bswap_32big(0xea7b3422U),
                               bswap_32big(0x0d43d3efU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x52846a81U));
                OFS_ADR = 24;
                r_rsip_subfunc008(0x1f880000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x35d6e19fU),
                               bswap_32big(0x07b0bb1eU),
                               bswap_32big(0x51d9503bU),
                               bswap_32big(0x87ed9435U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000504U));
                r_rsip_func101(bswap_32big(0xef2960dbU),
                               bswap_32big(0xbaabb568U),
                               bswap_32big(0x2e80eaebU),
                               bswap_32big(0x66c7a6d3U));
                r_rsip_func301();
                r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050dU));
                r_rsip_func101(bswap_32big(0x2ef93783U),
                               bswap_32big(0xa25e4a27U),
                               bswap_32big(0x1ad61ec2U),
                               bswap_32big(0xca1d1569U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x3e914fbaU),
                               bswap_32big(0x59ce4b87U),
                               bswap_32big(0x7f27ee70U),
                               bswap_32big(0xe9ff183fU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x71574de3U));
    OFS_ADR = 96;
    r_rsip_subfunc008(0x11e00000U, 0x00000010U, bswap_32big(0x0000050eU));
    r_rsip_func101(bswap_32big(0x58b6158fU),
                   bswap_32big(0xd15475dcU),
                   bswap_32big(0x6afa03f9U),
                   bswap_32big(0x3c249a36U));
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
        r_rsip_func100(bswap_32big(0xa1fd9af6U), bswap_32big(0x311a530eU), bswap_32big(0xa9d1513bU),
                       bswap_32big(0xc3d92df3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x08080008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x08080008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x61cafb16U), bswap_32big(0xd89e5affU), bswap_32big(0xf8198757U),
                           bswap_32big(0xec5a24bbU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x4cd6c571U), bswap_32big(0x5dca5e27U), bswap_32big(0x0236c419U),
                           bswap_32big(0xa58b3ac2U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xa9b08b1aU));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x17e80000U, 0x00000014U, bswap_32big(0x0000050fU));
    r_rsip_func101(bswap_32big(0x75063d77U),
                   bswap_32big(0xfff2c25bU),
                   bswap_32big(0xd6a56c03U),
                   bswap_32big(0xb5c180dfU));
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
        r_rsip_func100(bswap_32big(0x41cbb7aeU), bswap_32big(0xc28b3e1cU), bswap_32big(0xe14844a7U),
                       bswap_32big(0x05fc1046U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x0909000aU);
            r_rsip_func101(bswap_32big(0x16640780U), bswap_32big(0x21e00f84U), bswap_32big(0xe043d42eU),
                           bswap_32big(0x00d0cb64U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xeb794030U), bswap_32big(0xb70d2636U), bswap_32big(0xcc7ac6ccU),
                           bswap_32big(0xb8b87472U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x2541a363U),
                   bswap_32big(0xc1b7f2bcU),
                   bswap_32big(0x3e5e617cU),
                   bswap_32big(0xbc7296eaU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x0909000aU);
        r_rsip_func101(bswap_32big(0x88c92c1aU), bswap_32big(0x437cfe8dU), bswap_32big(0x1d19a7ecU),
                       bswap_32big(0x4a99b9f5U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x21cd4758U), bswap_32big(0x8ae30ff3U), bswap_32big(0x1b3c667fU),
                       bswap_32big(0xa7dc3449U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
