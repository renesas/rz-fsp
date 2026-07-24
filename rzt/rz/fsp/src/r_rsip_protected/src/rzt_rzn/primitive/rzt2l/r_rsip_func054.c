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
        r_rsip_func100(bswap_32big(0xc441004fU), bswap_32big(0x9bc9fd2fU), bswap_32big(0x01a4dc28U),
                       bswap_32big(0x494976b3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x2020000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x2020000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8c4153c6U), bswap_32big(0x2f6446c3U), bswap_32big(0x2907a36fU),
                           bswap_32big(0x92b36af2U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x84d1119cU), bswap_32big(0xaa565443U), bswap_32big(0x1d5e64b9U),
                           bswap_32big(0x992c5696U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19300000U);
    r_rsip_subfunc003(0x00c00111U);
    r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
    OFS_ADR = 72;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000541U));
    r_rsip_func101(bswap_32big(0x9cd888b7U),
                   bswap_32big(0xaa90bcc7U),
                   bswap_32big(0xf1c2557aU),
                   bswap_32big(0x77095352U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
    OFS_ADR = 144;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
    r_rsip_func101(bswap_32big(0x54b7e2ecU),
                   bswap_32big(0x334dc36eU),
                   bswap_32big(0x3889a744U),
                   bswap_32big(0xb656549aU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19400000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c000fdU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000543U));
    r_rsip_func101(bswap_32big(0x9a523c1cU),
                   bswap_32big(0xe3d1a0cbU),
                   bswap_32big(0xe335ed72U),
                   bswap_32big(0x755a384fU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
    r_rsip_func101(bswap_32big(0xe10364b0U),
                   bswap_32big(0x5590da67U),
                   bswap_32big(0x10cb38e7U),
                   bswap_32big(0x295b925aU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3f505121U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x00000545U));
    r_rsip_func101(bswap_32big(0x1e979756U),
                   bswap_32big(0x79212460U),
                   bswap_32big(0xc735ceedU),
                   bswap_32big(0xf534aa88U));
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
        r_rsip_func100(bswap_32big(0x88498131U), bswap_32big(0x7ba60ef7U), bswap_32big(0xf0461f58U),
                       bswap_32big(0x48bd8809U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x86fa2adaU), bswap_32big(0xf7d2b861U), bswap_32big(0x837b2643U),
                           bswap_32big(0x6a33d1f3U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0xe967700eU), bswap_32big(0x1f2d5a4aU), bswap_32big(0x5d99d339U),
                           bswap_32big(0xbacc2dc8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0xf83de077U), bswap_32big(0x62b31b20U), bswap_32big(0xfe126fa1U),
                           bswap_32big(0x2e6615efU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000541U));
            r_rsip_func101(bswap_32big(0x0a273b88U), bswap_32big(0x020523f0U), bswap_32big(0x9faa9c16U),
                           bswap_32big(0x08c1d461U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000546U));
            r_rsip_func101(bswap_32big(0x46f874ebU), bswap_32big(0x0b54c8e5U), bswap_32big(0x2b58af3aU),
                           bswap_32big(0x40c1cd76U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
            OFS_ADR = 72;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000547U));
            r_rsip_func101(bswap_32big(0x5b09efb8U), bswap_32big(0x79f332cfU), bswap_32big(0x014c7ec9U),
                           bswap_32big(0xaf237dd7U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000543U));
            r_rsip_func101(bswap_32big(0x7a076496U), bswap_32big(0x468a227aU), bswap_32big(0x92dffbddU),
                           bswap_32big(0x9a088ae3U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000544U));
            r_rsip_func101(bswap_32big(0xf9c39d48U), bswap_32big(0x3f08e96fU), bswap_32big(0xc0b2cb6cU),
                           bswap_32big(0xc99c916cU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc009(bswap_32big(0x00000542U));
            r_rsip_func101(bswap_32big(0xe2e76204U), bswap_32big(0xb6713fd5U), bswap_32big(0xf9db4a19U),
                           bswap_32big(0x7a17d1d4U));
            r_rsip_func055();
            r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
            OFS_ADR = 144;
            r_rsip_subfunc008(0x13180000U, 0x00000044U, bswap_32big(0x00000548U));
            r_rsip_func101(bswap_32big(0x27cf9aefU), bswap_32big(0xec908ef4U), bswap_32big(0x5c7e4afbU),
                           bswap_32big(0xfee80ab7U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
            OFS_ADR = 216;
            r_rsip_subfunc008(0x19300000U, 0x00000044U, bswap_32big(0x00000549U));
            r_rsip_func101(bswap_32big(0x98e11aa5U), bswap_32big(0x77ed7cdcU), bswap_32big(0x4e9f7547U),
                           bswap_32big(0x9d96b962U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1ed80000U);
            r_rsip_subfunc003(0x00c00101U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x20200009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x20200009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x20200009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x2020000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xdad4825aU), bswap_32big(0xc55c7b46U), bswap_32big(0xc85a8618U),
                           bswap_32big(0xfda64026U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x20200009U);
                r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000545U));
                r_rsip_func101(bswap_32big(0x00fee502U),
                               bswap_32big(0xc3983ca0U),
                               bswap_32big(0xbefd4562U),
                               bswap_32big(0x859c0041U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000546U));
                r_rsip_func101(bswap_32big(0x15a29e01U),
                               bswap_32big(0x4598b9c7U),
                               bswap_32big(0xec38903dU),
                               bswap_32big(0x885c243fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000541U));
                r_rsip_func101(bswap_32big(0xf61f9216U),
                               bswap_32big(0xc5eed9aaU),
                               bswap_32big(0x5da26fceU),
                               bswap_32big(0xb29ab780U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xfcd14e3eU),
                               bswap_32big(0x4de31a74U),
                               bswap_32big(0xfb8bc37bU),
                               bswap_32big(0xd2d9e7e0U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x00000547U));
                r_rsip_func101(bswap_32big(0xe604afb0U),
                               bswap_32big(0xf110571cU),
                               bswap_32big(0x19e3d62eU),
                               bswap_32big(0x0881206bU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x00000548U));
                r_rsip_func101(bswap_32big(0xde64e0b8U),
                               bswap_32big(0x4ad02f01U),
                               bswap_32big(0x2de44d68U),
                               bswap_32big(0xc1d92978U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000542U));
                r_rsip_func101(bswap_32big(0x86c9524cU),
                               bswap_32big(0xaeac9c88U),
                               bswap_32big(0x749be70bU),
                               bswap_32big(0x60d71fb6U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xc0e7998aU),
                               bswap_32big(0xc55d4a6dU),
                               bswap_32big(0x8c96e8e5U),
                               bswap_32big(0x81ea0fc5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xf475fd00U),
                               bswap_32big(0xca7cab98U),
                               bswap_32big(0xa2961b93U),
                               bswap_32big(0x13239f03U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x2020000aU);
                r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054aU));
                r_rsip_func101(bswap_32big(0xc1a77e0dU),
                               bswap_32big(0xd3e86540U),
                               bswap_32big(0x941eb8f7U),
                               bswap_32big(0xef435571U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc3e2b751U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054bU));
                r_rsip_func101(bswap_32big(0xcd698ca2U),
                               bswap_32big(0xabedd661U),
                               bswap_32big(0x7da29a92U),
                               bswap_32big(0xee9a24d4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000543U));
                r_rsip_func101(bswap_32big(0x3984ba1fU),
                               bswap_32big(0x42a751a8U),
                               bswap_32big(0xd102ddedU),
                               bswap_32big(0x00a51310U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xc0ced2d8U));
                OFS_ADR = 144;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0x8ba4a968U),
                               bswap_32big(0x003baa79U),
                               bswap_32big(0xc3de81d5U),
                               bswap_32big(0xe4a7a73fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054cU));
                r_rsip_func101(bswap_32big(0xa08d0488U),
                               bswap_32big(0xd3a398fdU),
                               bswap_32big(0xe2ef3678U),
                               bswap_32big(0x5dda9b61U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd06abe0aU));
                OFS_ADR = 72;
                r_rsip_subfunc008(0x1ec80000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0xc5c0a328U),
                               bswap_32big(0xcbbdac8dU),
                               bswap_32big(0xe5821bd2U),
                               bswap_32big(0x85e915f7U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000544U));
                r_rsip_func101(bswap_32big(0x5c930b21U),
                               bswap_32big(0x6dd2f483U),
                               bswap_32big(0x3a457f64U),
                               bswap_32big(0x665d9150U));
                r_rsip_func305();
                r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
                OFS_ADR = 216;
                r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054dU));
                r_rsip_func101(bswap_32big(0x5494931eU),
                               bswap_32big(0x110a87a9U),
                               bswap_32big(0xb1d5a2d2U),
                               bswap_32big(0xaaa38b11U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x8761eef5U),
                               bswap_32big(0x054b1a85U),
                               bswap_32big(0x9ff40187U),
                               bswap_32big(0x41e8ed06U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x3f505121U));
    OFS_ADR = 288;
    r_rsip_subfunc008(0x11200000U, 0x00000040U, bswap_32big(0x0000054eU));
    r_rsip_func101(bswap_32big(0x8d04a21aU),
                   bswap_32big(0x6f1b2c5aU),
                   bswap_32big(0x31e0bf65U),
                   bswap_32big(0xc03c2171U));
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
        r_rsip_func100(bswap_32big(0x8464fb4fU), bswap_32big(0xb360f8dbU), bswap_32big(0x5fe06051U),
                       bswap_32big(0x36777bf0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x20200008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x20200008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x68829fc2U), bswap_32big(0x272990fdU), bswap_32big(0xbfc2b2b0U),
                           bswap_32big(0xd6bcfff6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xad36e2c7U), bswap_32big(0x8a021c18U), bswap_32big(0xc8b87c05U),
                           bswap_32big(0xe1bfb622U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xb1a61e19U));
    OFS_ADR = 216;
    r_rsip_subfunc008(0x17280000U, 0x00000044U, bswap_32big(0x0000054fU));
    r_rsip_func101(bswap_32big(0x9d2ec3e2U),
                   bswap_32big(0x98b711bfU),
                   bswap_32big(0xfe1ca532U),
                   bswap_32big(0x5f8fdcf7U));
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
        r_rsip_func100(bswap_32big(0x3d38ab9dU), bswap_32big(0x232fa5fbU), bswap_32big(0x86e5c77bU),
                       bswap_32big(0x65e9c69aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x2121000aU);
            r_rsip_func101(bswap_32big(0x4989a805U), bswap_32big(0x1717615bU), bswap_32big(0xab139198U),
                           bswap_32big(0x535c7ea6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x1cec9f14U), bswap_32big(0xeefe1122U), bswap_32big(0x7b8d5523U),
                           bswap_32big(0x39f9dbc4U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xa711718fU),
                   bswap_32big(0x6e586975U),
                   bswap_32big(0x99726f3bU),
                   bswap_32big(0xdaca095cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x2121000aU);
        r_rsip_func101(bswap_32big(0xc0dd03c4U), bswap_32big(0x9d4f1551U), bswap_32big(0x0ecc2d1cU),
                       bswap_32big(0x18a3ab0cU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x50c08a3fU), bswap_32big(0x671baad0U), bswap_32big(0x4fe460f7U),
                       bswap_32big(0x08a7b44aU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
