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
        r_rsip_func100(bswap_32big(0xf9c3b859U), bswap_32big(0x567daa92U), bswap_32big(0x3f6545a0U),
                       bswap_32big(0x0740ec7dU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x16eb0d83U), bswap_32big(0x1c73e33eU), bswap_32big(0x5a133943U),
                           bswap_32big(0x491e5a42U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x285f94edU), bswap_32big(0x027aa38fU), bswap_32big(0x8385c4b1U),
                           bswap_32big(0x2c1c848aU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0x09b52876U),
                   bswap_32big(0x0f6efb76U),
                   bswap_32big(0x925355b6U),
                   bswap_32big(0x1c61145cU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3326b67bU));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0x94d6a5c8U),
                   bswap_32big(0x7226a297U),
                   bswap_32big(0xa1d13cd6U),
                   bswap_32big(0x23a82362U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x5a444838U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0xedc74c65U),
                   bswap_32big(0x7841a1a6U),
                   bswap_32big(0x82c30eefU),
                   bswap_32big(0x1120b186U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0xf83095aaU),
                   bswap_32big(0xb9909438U),
                   bswap_32big(0x0d0b0f63U),
                   bswap_32big(0x50814bb3U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x48492f5dU));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0xc17aaa99U),
                   bswap_32big(0x4580a3caU),
                   bswap_32big(0x22814465U),
                   bswap_32big(0x9dd5ad5aU));
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
        r_rsip_func100(bswap_32big(0x60359593U), bswap_32big(0xcfc2e732U), bswap_32big(0xe13cdf40U),
                       bswap_32big(0x936895b6U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x5c69ae02U), bswap_32big(0x317219d4U), bswap_32big(0xdd9dd087U),
                           bswap_32big(0x491846f0U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x5a444838U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x254430acU), bswap_32big(0x0875dff1U), bswap_32big(0x85dbaa1dU),
                           bswap_32big(0x8291218cU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0xa82fcf3eU), bswap_32big(0xfb1a5afaU), bswap_32big(0xb25faaf0U),
                           bswap_32big(0x3a8d1a61U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0xe099444dU), bswap_32big(0x361cce62U), bswap_32big(0xd21e4078U),
                           bswap_32big(0x5800f37dU));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x5a444838U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0x845c1bd2U), bswap_32big(0x31e0b083U), bswap_32big(0x43b7873dU),
                           bswap_32big(0xf78a84fbU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0x44a36cf1U), bswap_32big(0xcca9dc9fU), bswap_32big(0x98979293U),
                           bswap_32big(0x33d110d4U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x3326b67bU));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0x4c26cab7U), bswap_32big(0x576bcb52U), bswap_32big(0xfd2029a8U),
                           bswap_32big(0xb34708ebU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0xffca50bfU), bswap_32big(0x020c28feU), bswap_32big(0x70dcbdddU),
                           bswap_32big(0x13bd5558U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x96995cc2U), bswap_32big(0xf8bbcf40U), bswap_32big(0x07b5f422U),
                           bswap_32big(0xef505a20U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x3326b67bU));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0xcaf34474U), bswap_32big(0x68d9ca69U), bswap_32big(0xebb02af1U),
                           bswap_32big(0x7c97786dU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0x41513844U), bswap_32big(0x01f7f453U), bswap_32big(0xfdd606e1U),
                           bswap_32big(0xd74c3d54U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x9b81127fU), bswap_32big(0xc5e7dd63U), bswap_32big(0xe8456c93U),
                           bswap_32big(0xa35dd00fU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0x5a444838U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0xd3723aecU),
                               bswap_32big(0x9bdb61b0U),
                               bswap_32big(0xd422909cU),
                               bswap_32big(0x734f78dcU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x3326b67bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0x3c03c0a0U),
                               bswap_32big(0xe58600ebU),
                               bswap_32big(0xce9196fdU),
                               bswap_32big(0x9b48a50bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0x3f70562dU),
                               bswap_32big(0xd43cac63U),
                               bswap_32big(0xd558eb8aU),
                               bswap_32big(0x942a6d21U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x5a444838U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0x51f61b9eU),
                               bswap_32big(0x041bdb16U),
                               bswap_32big(0xbb3387feU),
                               bswap_32big(0xa15a868fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0x32872045U),
                               bswap_32big(0xb1aa0db5U),
                               bswap_32big(0xbdc9e4e4U),
                               bswap_32big(0x74de5762U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0xb8270f24U),
                               bswap_32big(0x6043aaebU),
                               bswap_32big(0x49fe6fdbU),
                               bswap_32big(0x296a7d69U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0xe21b4993U),
                               bswap_32big(0xe77bc653U),
                               bswap_32big(0xe73ce7bdU),
                               bswap_32big(0x0577307dU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xe56927c9U),
                               bswap_32big(0x3caa9272U),
                               bswap_32big(0x821cbc4aU),
                               bswap_32big(0x840ca2a8U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xf5380cddU),
                               bswap_32big(0x76c15983U),
                               bswap_32big(0x62a8d248U),
                               bswap_32big(0x7cd32746U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0x3326b67bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0x7e2e6038U),
                               bswap_32big(0x47495fb1U),
                               bswap_32big(0xc392f4e9U),
                               bswap_32big(0xf3a714e5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x5a444838U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0x7335348aU),
                               bswap_32big(0x8e145cb1U),
                               bswap_32big(0x919d059aU),
                               bswap_32big(0x6f54c0fcU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0x28f7976dU),
                               bswap_32big(0x56a30465U),
                               bswap_32big(0x72272405U),
                               bswap_32big(0x9156ae4fU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x3326b67bU));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x8f71e647U),
                               bswap_32big(0x188caf1cU),
                               bswap_32big(0x5d5003d0U),
                               bswap_32big(0x4490129eU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x5036c812U),
                               bswap_32big(0x56f7c0e9U),
                               bswap_32big(0x71624008U),
                               bswap_32big(0xee143b8bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0b1c2202U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0xd972a340U),
                               bswap_32big(0x7d7d61c7U),
                               bswap_32big(0x669c2c94U),
                               bswap_32big(0xe54acd15U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0x729f2961U),
                               bswap_32big(0x256967dcU),
                               bswap_32big(0xcbd67128U),
                               bswap_32big(0x18bbeccbU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0xebdf8150U),
                               bswap_32big(0xf46ba48dU),
                               bswap_32big(0xf53f81c8U),
                               bswap_32big(0xa43d30b4U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xe4cfec9aU),
                               bswap_32big(0x073fc119U),
                               bswap_32big(0x55e94632U),
                               bswap_32big(0xfcb6508bU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x48492f5dU));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0x3074506bU),
                   bswap_32big(0x99cd8dbdU),
                   bswap_32big(0x95e8a541U),
                   bswap_32big(0x98ea1d66U));
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
        r_rsip_func100(bswap_32big(0x1e08af97U), bswap_32big(0xa86c55c7U), bswap_32big(0x6849e0edU),
                       bswap_32big(0x02eacab6U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5260b842U), bswap_32big(0x055942eaU), bswap_32big(0xc198b9a7U),
                           bswap_32big(0x3bde7c25U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5181f3fdU), bswap_32big(0xd5d6abe1U), bswap_32big(0x86752772U),
                           bswap_32big(0x2d84c94dU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xff3fb3d7U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0x9d4c3aa6U),
                   bswap_32big(0x73e46787U),
                   bswap_32big(0x1d82ef9fU),
                   bswap_32big(0x4180df21U));
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
        r_rsip_func100(bswap_32big(0x297c5adbU), bswap_32big(0x00717da1U), bswap_32big(0xf96cb135U),
                       bswap_32big(0xd974c2efU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0xd78b2d5cU), bswap_32big(0x2f82b680U), bswap_32big(0x53c495d1U),
                           bswap_32big(0x307956e9U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xf880bf18U), bswap_32big(0x0bcde320U), bswap_32big(0x78b8d8e3U),
                           bswap_32big(0x10a9e144U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xf41b1ef5U),
                   bswap_32big(0xc1f8cb13U),
                   bswap_32big(0xb1f747e4U),
                   bswap_32big(0x6677740fU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0xffdc8076U), bswap_32big(0xe5e05fe3U), bswap_32big(0xe0009ef7U),
                       bswap_32big(0x5ee42b96U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xa58e6284U), bswap_32big(0xd82b1b03U), bswap_32big(0x6f476461U),
                       bswap_32big(0x13637ee1U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
