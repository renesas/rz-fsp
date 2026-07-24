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
        r_rsip_func100(bswap_32big(0x364078ceU), bswap_32big(0x435912ffU), bswap_32big(0x1b7298b1U),
                       bswap_32big(0x56c878c8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x862620c1U), bswap_32big(0xf4c287a5U), bswap_32big(0x739e077eU),
                           bswap_32big(0x533c56d6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc5a52431U), bswap_32big(0x56c1b276U), bswap_32big(0x5d8226b3U),
                           bswap_32big(0x4740e99fU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0x5126973fU));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0x0cf44dc9U),
                   bswap_32big(0x2bfdf58aU),
                   bswap_32big(0x186e6217U),
                   bswap_32big(0x1edd6c9dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0x342a1b97U),
                   bswap_32big(0x416a702cU),
                   bswap_32big(0x016522a1U),
                   bswap_32big(0xe4f5bb44U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0x1dcd1db9U),
                   bswap_32big(0xe2c81965U),
                   bswap_32big(0x08bd2d14U),
                   bswap_32big(0x093797aaU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0xee50b1bbU),
                   bswap_32big(0xf84d483eU),
                   bswap_32big(0x1325d5ebU),
                   bswap_32big(0x8d936c05U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xd5a25d78U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0x643522c7U),
                   bswap_32big(0x30a1df78U),
                   bswap_32big(0x48bf84deU),
                   bswap_32big(0x3868ae93U));
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
        r_rsip_func100(bswap_32big(0x33f6fc1eU), bswap_32big(0x95a19c23U), bswap_32big(0x6695fec0U),
                       bswap_32big(0x0644d080U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xfdff15e5U), bswap_32big(0xb02214bfU), bswap_32big(0x8b1a5836U),
                           bswap_32big(0x8986db18U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x614a3444U), bswap_32big(0x6b3ca20eU), bswap_32big(0x3a5807d9U),
                           bswap_32big(0x56a11371U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5126973fU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x22446fdcU), bswap_32big(0x094e157cU), bswap_32big(0xa82592c5U),
                           bswap_32big(0x40d42918U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x1284db5cU), bswap_32big(0x833b4180U), bswap_32big(0xf0b89a67U),
                           bswap_32big(0xc7b26925U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0x5cfb949fU), bswap_32big(0xbb8509d6U), bswap_32big(0xe7a621c2U),
                           bswap_32big(0x1d87d71dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x5126973fU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0x22b936e9U), bswap_32big(0xa474b928U), bswap_32big(0xf9af8f9dU),
                           bswap_32big(0xda2e0b9aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0x122879d8U), bswap_32big(0xbe5dc026U), bswap_32big(0x267160bfU),
                           bswap_32big(0x6d5c6097U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0x4e131f0eU), bswap_32big(0x73a639aeU), bswap_32big(0x8a42a8f7U),
                           bswap_32big(0x35164fb2U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x6c2e5884U), bswap_32big(0xcb4da9dcU), bswap_32big(0x6b75ec8eU),
                           bswap_32big(0x34d4ddb5U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0x6c9c5410U), bswap_32big(0xa4597459U), bswap_32big(0xbfe9ee88U),
                           bswap_32big(0xcad5c571U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0x477f30ceU), bswap_32big(0xc191d62cU), bswap_32big(0x2a392011U),
                           bswap_32big(0x0c8da488U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xfb8fcf5dU), bswap_32big(0x74de6a13U), bswap_32big(0x222f9b11U),
                           bswap_32big(0xe42158c1U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0xc53ea900U),
                               bswap_32big(0xeb238822U),
                               bswap_32big(0xa0f7c6f0U),
                               bswap_32big(0x21bc8ad7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0x02a15a59U),
                               bswap_32big(0xd48383eeU),
                               bswap_32big(0x431b0c2aU),
                               bswap_32big(0x4f023d25U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0x4ec2df7fU),
                               bswap_32big(0x813ae3b7U),
                               bswap_32big(0x05af3919U),
                               bswap_32big(0x4eb4e9c7U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0x06e2e5e3U),
                               bswap_32big(0x095f22e4U),
                               bswap_32big(0x8ab96f5aU),
                               bswap_32big(0x2c40b357U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5126973fU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0x623c4a7fU),
                               bswap_32big(0xbb622bdaU),
                               bswap_32big(0x9fa4c13eU),
                               bswap_32big(0x1f2bd9f9U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0x4d541231U),
                               bswap_32big(0xe7502f9dU),
                               bswap_32big(0x7d17be3bU),
                               bswap_32big(0x0cc7696dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0x76f856b2U),
                               bswap_32big(0x4e281ba2U),
                               bswap_32big(0x82f25638U),
                               bswap_32big(0xc4dca417U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x5126973fU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0x323131c6U),
                               bswap_32big(0x30bbc339U),
                               bswap_32big(0xb2416f02U),
                               bswap_32big(0xc5c74e1aU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x604c1840U),
                               bswap_32big(0xf6244fe2U),
                               bswap_32big(0x6c75b502U),
                               bswap_32big(0x328445efU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xe0a786e9U),
                               bswap_32big(0x89911a8fU),
                               bswap_32big(0xc2fd245cU),
                               bswap_32big(0x1a52958fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe7f100dcU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xa72964ebU),
                               bswap_32big(0xbdf8f9deU),
                               bswap_32big(0x4067a949U),
                               bswap_32big(0x27f13088U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0x8d0e2a5cU),
                               bswap_32big(0xd6340911U),
                               bswap_32big(0xda699f64U),
                               bswap_32big(0x72c28432U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xe5d9ef6bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0xb95b90a9U),
                               bswap_32big(0x9ff954b0U),
                               bswap_32big(0x77cee8a2U),
                               bswap_32big(0x3af0e7c6U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x8ca87266U),
                               bswap_32big(0xf33c25a2U),
                               bswap_32big(0xe7306ab5U),
                               bswap_32big(0x5ddd7943U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5126973fU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x67ce48c9U),
                               bswap_32big(0x80f2bf3eU),
                               bswap_32big(0x86e1cac7U),
                               bswap_32big(0xfc0f2501U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0xb15e7d45U),
                               bswap_32big(0xf46eac4aU),
                               bswap_32big(0x3d9f9942U),
                               bswap_32big(0x2e31f15bU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x1517fbc5U),
                               bswap_32big(0x64518e82U),
                               bswap_32big(0x84558ebeU),
                               bswap_32big(0x5df5f744U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xab5baadeU),
                               bswap_32big(0x0ec41bb0U),
                               bswap_32big(0xd5069bfbU),
                               bswap_32big(0x5ed9f17eU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xd5a25d78U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0x5aff155aU),
                   bswap_32big(0xd0bced2aU),
                   bswap_32big(0xdc41db7bU),
                   bswap_32big(0xe57bb1c7U));
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
        r_rsip_func100(bswap_32big(0x9dc5c112U), bswap_32big(0x2e024d8dU), bswap_32big(0x14d37c2dU),
                       bswap_32big(0x28264bb0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc074a1a7U), bswap_32big(0x17410d10U), bswap_32big(0x009a411eU),
                           bswap_32big(0x1dd7f2a2U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xe30e31aeU), bswap_32big(0xddbf0c25U), bswap_32big(0x3aaf1be4U),
                           bswap_32big(0x26b2f2daU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xbd001d4fU));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0x34c6b8beU),
                   bswap_32big(0x2a61499eU),
                   bswap_32big(0xe373b86dU),
                   bswap_32big(0x21a57712U));
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
        r_rsip_func100(bswap_32big(0x924e38e2U), bswap_32big(0xd95a801eU), bswap_32big(0x768ef134U),
                       bswap_32big(0xf1539604U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0x19571061U), bswap_32big(0xcd31d92fU), bswap_32big(0x9f3b93fbU),
                           bswap_32big(0xdbbca1d2U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc308fc65U), bswap_32big(0x3586ba70U), bswap_32big(0xa43fbab2U),
                           bswap_32big(0x94caff0fU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x8420caccU),
                   bswap_32big(0x09d967faU),
                   bswap_32big(0x5925fbb1U),
                   bswap_32big(0x719078cbU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0x494c2ed1U), bswap_32big(0xf36e841bU), bswap_32big(0x6a31f94eU),
                       bswap_32big(0x70d41f60U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xe41ddf3bU), bswap_32big(0x3865c5a9U), bswap_32big(0x4c149ad8U),
                       bswap_32big(0x7fcaba4aU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
