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
        r_rsip_func100(bswap_32big(0x15def336U), bswap_32big(0xaf3f4230U), bswap_32big(0x771e8b35U),
                       bswap_32big(0x4f3c58a7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6f967508U), bswap_32big(0x1731c7b0U), bswap_32big(0x0d2d90b3U),
                           bswap_32big(0x84d99087U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xd53df29bU), bswap_32big(0x867f5e24U), bswap_32big(0xd01e3b2dU),
                           bswap_32big(0xfd14e66cU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0x4f6496ecU),
                   bswap_32big(0xc9f5b80fU),
                   bswap_32big(0xd2b87f4bU),
                   bswap_32big(0x8115bf82U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0x93d71efaU),
                   bswap_32big(0xf201e135U),
                   bswap_32big(0x91b389ebU),
                   bswap_32big(0x1628f324U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x34e07b12U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0xec7bfb4eU),
                   bswap_32big(0x845fbefdU),
                   bswap_32big(0xa705d37aU),
                   bswap_32big(0x1a81bb8bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0x282678d7U),
                   bswap_32big(0x4b4457deU),
                   bswap_32big(0xe11ca329U),
                   bswap_32big(0xd45fef5dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x15efddd1U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0x80823658U),
                   bswap_32big(0x6e68b3d7U),
                   bswap_32big(0x76ca065eU),
                   bswap_32big(0x39561fc8U));
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
        r_rsip_func100(bswap_32big(0x2278ee89U), bswap_32big(0x677aa8f3U), bswap_32big(0x00d2ede7U),
                       bswap_32big(0x248e478cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x825723c1U), bswap_32big(0x3da6c31aU), bswap_32big(0x74479594U),
                           bswap_32big(0x589bb26dU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x34e07b12U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x84d47893U), bswap_32big(0x5fc9d2ffU), bswap_32big(0x4c9fd19dU),
                           bswap_32big(0x5a33e210U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0xf8f82077U), bswap_32big(0x308a5b04U), bswap_32big(0xcb378df2U),
                           bswap_32big(0x53ff6dabU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0xa45e7859U), bswap_32big(0x4e14bbf2U), bswap_32big(0x9c656c78U),
                           bswap_32big(0x36b8d541U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x34e07b12U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0x475e25c9U), bswap_32big(0xfc86f6aaU), bswap_32big(0xe57acd07U),
                           bswap_32big(0x8f33959eU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0x264eb040U), bswap_32big(0xfbb87d91U), bswap_32big(0x687b45e4U),
                           bswap_32big(0x0a39331cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0xcc749786U), bswap_32big(0x4130d8a0U), bswap_32big(0x59206027U),
                           bswap_32big(0x259e7728U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0x64c7daebU), bswap_32big(0x0a47f53fU), bswap_32big(0x4bd94e79U),
                           bswap_32big(0x03e415edU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x93b30505U), bswap_32big(0xdd7f05ebU), bswap_32big(0xf4c8a381U),
                           bswap_32big(0x5290b517U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0x36bb8cb2U), bswap_32big(0x8e2de82bU), bswap_32big(0x594a9b28U),
                           bswap_32big(0x77910c70U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0xe24b4d38U), bswap_32big(0x49ec8032U), bswap_32big(0x8bb3e6b0U),
                           bswap_32big(0x4ea37200U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x197ed80eU), bswap_32big(0x2ab191d5U), bswap_32big(0xcef7e824U),
                           bswap_32big(0x7dd40523U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0x34e07b12U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0x8b02baefU),
                               bswap_32big(0xd47939f9U),
                               bswap_32big(0xc7a762e9U),
                               bswap_32big(0xce7eed86U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0x7428c98eU),
                               bswap_32big(0x1e2429aaU),
                               bswap_32big(0xbfe88b93U),
                               bswap_32big(0xd74890baU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0x8127850bU),
                               bswap_32big(0x509ca304U),
                               bswap_32big(0xd93e3fc2U),
                               bswap_32big(0x9e387e02U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x34e07b12U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0x66193115U),
                               bswap_32big(0x9a3243c7U),
                               bswap_32big(0x1b720f7cU),
                               bswap_32big(0x29c87a72U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0xb94a7b3bU),
                               bswap_32big(0x4a73a396U),
                               bswap_32big(0x11958072U),
                               bswap_32big(0x398e3b86U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0x6a0c55c2U),
                               bswap_32big(0xf9d2c21bU),
                               bswap_32big(0x07dbc52dU),
                               bswap_32big(0x8195ad2eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0x0f922381U),
                               bswap_32big(0xc75d55f6U),
                               bswap_32big(0x5b974634U),
                               bswap_32big(0x38ddc72dU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xcf86bbdbU),
                               bswap_32big(0x6bc3acf7U),
                               bswap_32big(0x720d2289U),
                               bswap_32big(0xd540d037U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x77046548U),
                               bswap_32big(0x052e4111U),
                               bswap_32big(0x9abf19a0U),
                               bswap_32big(0x660e80baU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xdccf6cd3U),
                               bswap_32big(0x490d31f7U),
                               bswap_32big(0x81caf591U),
                               bswap_32big(0x10a76f5dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x34e07b12U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0x286bed69U),
                               bswap_32big(0x3fcc0cc9U),
                               bswap_32big(0x7cbb1a41U),
                               bswap_32big(0x8c9bb699U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0x01928928U),
                               bswap_32big(0xb7fe9f3eU),
                               bswap_32big(0x56fa62e1U),
                               bswap_32big(0x0d33068eU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xff0a02d3U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x7bd29da2U),
                               bswap_32big(0x3b4fc4faU),
                               bswap_32big(0xe59c1fb1U),
                               bswap_32big(0xdb361ce2U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x70e3c523U),
                               bswap_32big(0x7c5f47bcU),
                               bswap_32big(0x52f8e868U),
                               bswap_32big(0x461483bcU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xaeb9e1c1U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0xf044bd89U),
                               bswap_32big(0xb1b66521U),
                               bswap_32big(0x25207171U),
                               bswap_32big(0xa0ce66e1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0xc14668eeU),
                               bswap_32big(0x00e060c8U),
                               bswap_32big(0x1b3cd0dcU),
                               bswap_32big(0x67e4997bU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0xe4bcc74cU),
                               bswap_32big(0xef9a70fbU),
                               bswap_32big(0x64a81fddU),
                               bswap_32big(0x6b3c802cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x82b6a405U),
                               bswap_32big(0x42aa8b48U),
                               bswap_32big(0xbccf4935U),
                               bswap_32big(0x0648d187U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x15efddd1U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0xcb68835cU),
                   bswap_32big(0x6fb49e59U),
                   bswap_32big(0x7cc5b4deU),
                   bswap_32big(0xbf139f71U));
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
        r_rsip_func100(bswap_32big(0xe23e377cU), bswap_32big(0x2fb5c721U), bswap_32big(0x7c215982U),
                       bswap_32big(0x029f55e1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x71003ce8U), bswap_32big(0x202968daU), bswap_32big(0x45880bceU),
                           bswap_32big(0x34a9fbf9U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc27823e7U), bswap_32big(0x65aa9c66U), bswap_32big(0xe001fed1U),
                           bswap_32big(0x77cac192U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xd5274ee8U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0x78b79c26U),
                   bswap_32big(0xd2be6e84U),
                   bswap_32big(0x1f697868U),
                   bswap_32big(0x70c30aaaU));
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
        r_rsip_func100(bswap_32big(0x5e9a00d4U), bswap_32big(0x57840241U), bswap_32big(0x02284c2fU),
                       bswap_32big(0x15483ae5U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0xb43ab434U), bswap_32big(0x96517a5aU), bswap_32big(0x5decfcbaU),
                           bswap_32big(0xb8d3d34eU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xde684f67U), bswap_32big(0x8b06e2a0U), bswap_32big(0xd777dec0U),
                           bswap_32big(0xca5724c4U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x8b0a1664U),
                   bswap_32big(0x7d26b2bbU),
                   bswap_32big(0xb65d8f3aU),
                   bswap_32big(0xdfb570c0U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0xa525ab05U), bswap_32big(0xfdf504cdU), bswap_32big(0xbbebe26eU),
                       bswap_32big(0xc26cee65U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x3c72ffeaU), bswap_32big(0xc38e761eU), bswap_32big(0x699c0f8fU),
                       bswap_32big(0x04f2f8f5U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
