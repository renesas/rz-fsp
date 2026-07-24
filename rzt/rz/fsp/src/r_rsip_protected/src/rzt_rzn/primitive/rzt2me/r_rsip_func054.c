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
        r_rsip_func100(bswap_32big(0x1f7347e5U), bswap_32big(0x6768873dU), bswap_32big(0x4a5ab5a2U),
                       bswap_32big(0x7349b496U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x27704210U), bswap_32big(0xa0f14ea3U), bswap_32big(0x6843109eU),
                           bswap_32big(0x8522d664U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xf4d87edfU), bswap_32big(0xaae01186U), bswap_32big(0x933b1511U),
                           bswap_32big(0x04408039U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0xd9634da2U));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0xc34f203cU),
                   bswap_32big(0x3f6510acU),
                   bswap_32big(0xa4c51397U),
                   bswap_32big(0xcf645695U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x94174653U));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0xd2869032U),
                   bswap_32big(0x52fe1095U),
                   bswap_32big(0x23ee0519U),
                   bswap_32big(0xe04f8d2fU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x933f58e2U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0x792a5e27U),
                   bswap_32big(0x202f1d0aU),
                   bswap_32big(0x5359f91cU),
                   bswap_32big(0x578eb00aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0x0c975ceaU),
                   bswap_32big(0xa1220743U),
                   bswap_32big(0x5e514acdU),
                   bswap_32big(0x50139973U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x9bee78e8U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0xe4e9ec81U),
                   bswap_32big(0xcf475d5dU),
                   bswap_32big(0x12518ec3U),
                   bswap_32big(0x7fd02b41U));
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
        r_rsip_func100(bswap_32big(0x2e197d49U), bswap_32big(0x3b06a92aU), bswap_32big(0x4d959e91U),
                       bswap_32big(0x70371cffU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x013b89a5U), bswap_32big(0x7cb8138aU), bswap_32big(0x797581bdU),
                           bswap_32big(0x415699f0U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x933f58e2U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x04545e08U), bswap_32big(0x62d357aaU), bswap_32big(0x4e50a23cU),
                           bswap_32big(0x79306956U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd9634da2U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x28eb78c8U), bswap_32big(0x7e6fc192U), bswap_32big(0xb5581493U),
                           bswap_32big(0xf08cdcbeU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x514d5048U), bswap_32big(0x7861ebb2U), bswap_32big(0x5c9551c0U),
                           bswap_32big(0x9ab9a10cU));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x933f58e2U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0xf0773fd2U), bswap_32big(0xce345faaU), bswap_32big(0x75f822baU),
                           bswap_32big(0x4d110611U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd9634da2U));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0x5f99236cU), bswap_32big(0x69a8c88aU), bswap_32big(0x8a81dc4bU),
                           bswap_32big(0x489b5e70U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x94174653U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0xb2ee1a02U), bswap_32big(0x67b15f22U), bswap_32big(0x63168facU),
                           bswap_32big(0x58f544ddU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0x4a54705cU), bswap_32big(0xee1609a5U), bswap_32big(0x86996892U),
                           bswap_32big(0xb6b0f9f4U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0x8276dbb0U), bswap_32big(0xa3718d49U), bswap_32big(0x35a24f1eU),
                           bswap_32big(0xb05c298bU));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0x94174653U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0x8f501fd9U), bswap_32big(0xa9834589U), bswap_32big(0x95b32d98U),
                           bswap_32big(0x407decb4U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0x4cfb8502U), bswap_32big(0xad7dd171U), bswap_32big(0x494cae7bU),
                           bswap_32big(0x55b53ec6U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x06b8a7edU), bswap_32big(0x4cf72e96U), bswap_32big(0x5e057fdbU),
                           bswap_32big(0x902e3d72U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0x933f58e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0x18b18656U),
                               bswap_32big(0x1f87b5c2U),
                               bswap_32big(0x994b5871U),
                               bswap_32big(0x91d8256dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x94174653U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0xb754761eU),
                               bswap_32big(0x7264844cU),
                               bswap_32big(0x45d5aa4dU),
                               bswap_32big(0x46cec530U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0xd5f1ce5cU),
                               bswap_32big(0x93f7ce06U),
                               bswap_32big(0x46a50efdU),
                               bswap_32big(0x8e6fffceU));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x933f58e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xae645701U),
                               bswap_32big(0x31d8bda8U),
                               bswap_32big(0x7b019b0bU),
                               bswap_32big(0x84eb851dU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd9634da2U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0x88817d81U),
                               bswap_32big(0xf957526bU),
                               bswap_32big(0xc8b9caebU),
                               bswap_32big(0x3f94103aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0x0325fcd9U),
                               bswap_32big(0x90096e20U),
                               bswap_32big(0xd9159bbdU),
                               bswap_32big(0xdeae027fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0x22c560deU),
                               bswap_32big(0xaafb88ddU),
                               bswap_32big(0x079e945bU),
                               bswap_32big(0x49ed0f92U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xd9634da2U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xf4cfcf62U),
                               bswap_32big(0x06b2d51bU),
                               bswap_32big(0x718c93a7U),
                               bswap_32big(0x076e8f49U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x6a880512U),
                               bswap_32big(0xd0e802a3U),
                               bswap_32big(0xa45cf362U),
                               bswap_32big(0xece6e3d3U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0x94174653U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xe8f050b8U),
                               bswap_32big(0xd7872adbU),
                               bswap_32big(0x3b903883U),
                               bswap_32big(0xfb5c9d19U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x933f58e2U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0x68d09cd8U),
                               bswap_32big(0x8c202aa9U),
                               bswap_32big(0x80721e73U),
                               bswap_32big(0x7059a0ecU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0xf20a13c1U),
                               bswap_32big(0x4f5c90c7U),
                               bswap_32big(0x9684be9eU),
                               bswap_32big(0x13b6a545U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0x94174653U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x2d6bd4c8U),
                               bswap_32big(0x499f6c03U),
                               bswap_32big(0xecd4fa16U),
                               bswap_32big(0x2042fb16U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0xccfc3096U),
                               bswap_32big(0x5df32d7bU),
                               bswap_32big(0xb6569f00U),
                               bswap_32big(0x4923f3aaU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd9634da2U));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x40098784U),
                               bswap_32big(0x37ab7997U),
                               bswap_32big(0xcc02cc75U),
                               bswap_32big(0x4f2d2740U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0xa703b471U),
                               bswap_32big(0xbd9e2bf6U),
                               bswap_32big(0xba5c87cbU),
                               bswap_32big(0x98f213a4U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x77d777bdU),
                               bswap_32big(0x50f685e5U),
                               bswap_32big(0x7a3e3e4cU),
                               bswap_32big(0x7fcae053U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xf31b9a2dU),
                               bswap_32big(0x9a0f4980U),
                               bswap_32big(0x41d6571bU),
                               bswap_32big(0xda5d40f3U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x9bee78e8U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0x7eeef0c1U),
                   bswap_32big(0x1c9ae9a9U),
                   bswap_32big(0x676f8c5fU),
                   bswap_32big(0x4600e318U));
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
        r_rsip_func100(bswap_32big(0xeba95ca1U), bswap_32big(0xe9061db3U), bswap_32big(0x93c87743U),
                       bswap_32big(0xb37b9ca0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x22ab8c00U), bswap_32big(0x9ae6dbeaU), bswap_32big(0x7f40ea95U),
                           bswap_32big(0x61409f17U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x57c265b6U), bswap_32big(0xaf70b500U), bswap_32big(0xa8c2ee8cU),
                           bswap_32big(0x050d2cd5U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xe14d5c93U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0xde9285daU),
                   bswap_32big(0xc562b5daU),
                   bswap_32big(0xedab5d3bU),
                   bswap_32big(0x5a758522U));
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
        r_rsip_func100(bswap_32big(0x0241f743U), bswap_32big(0x22b90a00U), bswap_32big(0x555b12d8U),
                       bswap_32big(0xc4e64cacU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0x6b896e4dU), bswap_32big(0xa85dc47bU), bswap_32big(0x531b8be4U),
                           bswap_32big(0xd3cd8375U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xeea0fca8U), bswap_32big(0x353a074dU), bswap_32big(0x896f1396U),
                           bswap_32big(0x092ba344U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x23a3b955U),
                   bswap_32big(0x2a64d8e1U),
                   bswap_32big(0xd71492c8U),
                   bswap_32big(0x78976aedU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0x104fe1f1U), bswap_32big(0x828a16b6U), bswap_32big(0x30841e1eU),
                       bswap_32big(0x8806a8b9U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x7cba6600U), bswap_32big(0xdf78afa2U), bswap_32big(0xe2321a6cU),
                       bswap_32big(0x9ea169f2U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
