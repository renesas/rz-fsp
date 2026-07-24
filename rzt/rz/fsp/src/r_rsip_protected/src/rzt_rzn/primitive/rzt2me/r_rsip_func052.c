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

void r_rsip_func052 (void)
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
        r_rsip_func100(bswap_32big(0x858cf5e9U), bswap_32big(0x29206b3eU), bswap_32big(0xc631c013U),
                       bswap_32big(0x2c879b3bU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x47044bc4U), bswap_32big(0x79c3c20dU), bswap_32big(0x09ac3246U),
                           bswap_32big(0x4da3fffaU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x5beddc0bU), bswap_32big(0xf3dc7b69U), bswap_32big(0x0b15fcc2U),
                           bswap_32big(0x82d619d8U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0xf22994b8U));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0xb0ba3422U),
                   bswap_32big(0xba9e86e6U),
                   bswap_32big(0xc30b55b9U),
                   bswap_32big(0xd2f724d4U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x725c8882U));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0x130e2bd3U),
                   bswap_32big(0x43ecc620U),
                   bswap_32big(0x78407a3dU),
                   bswap_32big(0x87cbbaf7U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0x2c29aa1dU),
                   bswap_32big(0x3384c100U),
                   bswap_32big(0x6c1b1c28U),
                   bswap_32big(0x37985a53U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0x0249c402U),
                   bswap_32big(0x5b45dedaU),
                   bswap_32big(0x454d454bU),
                   bswap_32big(0x20a3ea2eU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x093b7d04U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x0a8e1175U),
                   bswap_32big(0xef32f7a6U),
                   bswap_32big(0xfeebb0f6U),
                   bswap_32big(0x62a0b584U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x15b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80a0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430081U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x19c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0007dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x1010000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x07a08566U), bswap_32big(0xce5eab24U), bswap_32big(0xf6a17b15U),
                       bswap_32big(0x143d56a6U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xebde8f17U), bswap_32big(0x5a2a8bc8U), bswap_32big(0x3847eb07U),
                           bswap_32big(0x2b52658fU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x739e104fU), bswap_32big(0x8a628ee5U), bswap_32big(0x7a461643U),
                           bswap_32big(0xc3d02487U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf22994b8U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xba1d70bdU), bswap_32big(0x307f0163U), bswap_32big(0x0100e05bU),
                           bswap_32big(0x491d8211U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x6fe779b4U), bswap_32big(0x8489bf21U), bswap_32big(0xc39b83b7U),
                           bswap_32big(0x3e868d9bU));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0x666e9b8dU), bswap_32big(0x405913faU), bswap_32big(0xbee02214U),
                           bswap_32big(0x671ffe8aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf22994b8U));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0xdcf94214U), bswap_32big(0x3b217bedU), bswap_32big(0x2a6d8942U),
                           bswap_32big(0xe3efbd62U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x725c8882U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0x93cc4f41U), bswap_32big(0xd8de515bU), bswap_32big(0x997c9076U),
                           bswap_32big(0xabb05ff5U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0xbcc98025U), bswap_32big(0xbdcfa1bcU), bswap_32big(0x7d2bdc36U),
                           bswap_32big(0x29fde2b1U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xb812d804U), bswap_32big(0xe464ef12U), bswap_32big(0x25f116a7U),
                           bswap_32big(0x136faec9U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0x725c8882U));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0x3dfba19eU), bswap_32big(0xe7b3d866U), bswap_32big(0xc212ff80U),
                           bswap_32big(0x988a9268U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0xad164c03U), bswap_32big(0x0c105935U), bswap_32big(0x3db49432U),
                           bswap_32big(0x59ea9b32U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x2a603818U), bswap_32big(0x91b43e6aU), bswap_32big(0x75d2ea44U),
                           bswap_32big(0x7f3384daU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0xa962de76U),
                               bswap_32big(0xd793e499U),
                               bswap_32big(0x62e632faU),
                               bswap_32big(0x0429e5c1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x725c8882U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0xa9ecd647U),
                               bswap_32big(0xe4c216f2U),
                               bswap_32big(0x98f0718bU),
                               bswap_32big(0xae6d3e77U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0xb61db482U),
                               bswap_32big(0x5c46417fU),
                               bswap_32big(0xea7c03f8U),
                               bswap_32big(0x6d988f37U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x327878eeU),
                               bswap_32big(0x2f0f7d72U),
                               bswap_32big(0x3244472fU),
                               bswap_32big(0xb42f855fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf22994b8U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0x6e3e2f4cU),
                               bswap_32big(0xfaa7bf7eU),
                               bswap_32big(0x4329a0ceU),
                               bswap_32big(0x75932e3dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0x428bd480U),
                               bswap_32big(0x65c7218eU),
                               bswap_32big(0xc604ef63U),
                               bswap_32big(0x008bab4cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0x4b0bdebeU),
                               bswap_32big(0x1ae11144U),
                               bswap_32big(0xe32002e6U),
                               bswap_32big(0xe4d0b2eaU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xf22994b8U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x721c6fa8U),
                               bswap_32big(0x1051ff92U),
                               bswap_32big(0x71962b3aU),
                               bswap_32big(0xea11bcf7U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xffb9b610U),
                               bswap_32big(0xc9a97edaU),
                               bswap_32big(0xa708395eU),
                               bswap_32big(0xa501ea9aU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0x725c8882U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x2380deeaU),
                               bswap_32big(0xc9e8608dU),
                               bswap_32big(0xa3d146c5U),
                               bswap_32big(0x35f46cacU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x68d2ac6fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0xcfc9d775U),
                               bswap_32big(0x794bbe3bU),
                               bswap_32big(0xf299eaaaU),
                               bswap_32big(0xe8da0a74U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0xe20f00f7U),
                               bswap_32big(0x9b3a65d6U),
                               bswap_32big(0x72befce3U),
                               bswap_32big(0x11f1a478U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x725c8882U));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x4088f6aaU),
                               bswap_32big(0x0a9958e1U),
                               bswap_32big(0xa1c9a169U),
                               bswap_32big(0xe6906419U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x96e3b8baU),
                               bswap_32big(0x7530bb56U),
                               bswap_32big(0x0e8cee08U),
                               bswap_32big(0x2e153e1eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf22994b8U));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0xac670b16U),
                               bswap_32big(0x5f6a5da9U),
                               bswap_32big(0x18a0b658U),
                               bswap_32big(0x50c528aaU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0x843678b3U),
                               bswap_32big(0xca7723afU),
                               bswap_32big(0xa1e6daf3U),
                               bswap_32big(0x821bf6e3U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x81089c9bU),
                               bswap_32big(0xb65cd19dU),
                               bswap_32big(0x6f9daca9U),
                               bswap_32big(0x364ef6d1U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xb62286c1U),
                               bswap_32big(0x73d8a1a0U),
                               bswap_32big(0x6e21409fU),
                               bswap_32big(0xd7010733U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x093b7d04U));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0xa70c5d6dU),
                   bswap_32big(0x259cf7bfU),
                   bswap_32big(0x64469900U),
                   bswap_32big(0xe42f987dU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x81be3a2eU), bswap_32big(0x68c62882U), bswap_32big(0x6300c6f3U),
                       bswap_32big(0xc022a123U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xa3ef4e4cU), bswap_32big(0x4c1c36b1U), bswap_32big(0xe71218eeU),
                           bswap_32big(0xb1ee04e1U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb0451febU), bswap_32big(0xb3b43e6dU), bswap_32big(0xff306ce7U),
                           bswap_32big(0x60fa495eU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x6afa85bfU));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x7afa826bU),
                   bswap_32big(0x1247c907U),
                   bswap_32big(0xa840c725U),
                   bswap_32big(0x0a299c9fU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x17a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x1111000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xc4281f2aU), bswap_32big(0x9ba73d76U), bswap_32big(0xf1ea6460U),
                       bswap_32big(0x54abc3e3U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0x4f47c6f3U), bswap_32big(0x1da61080U), bswap_32big(0x2373c0a7U),
                           bswap_32big(0xdb914817U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x404d9645U), bswap_32big(0xe8c8cd73U), bswap_32big(0x7d73d808U),
                           bswap_32big(0x49c85288U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x7d3f97e5U),
                   bswap_32big(0xc2b71399U),
                   bswap_32big(0x90e4b355U),
                   bswap_32big(0x02ccbe1cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0xd8f424a8U), bswap_32big(0xf44287deU), bswap_32big(0x01e3df2bU),
                       bswap_32big(0xc3f94a6aU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xd39ffce9U), bswap_32big(0x10d82a8cU), bswap_32big(0x516c13edU),
                       bswap_32big(0x3a4451b3U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
