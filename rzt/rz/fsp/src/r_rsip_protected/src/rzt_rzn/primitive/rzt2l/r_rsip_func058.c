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

void r_rsip_func058 (void)
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
        r_rsip_func100(bswap_32big(0x7454cba9U), bswap_32big(0xdedb078cU), bswap_32big(0x0dcbeb8cU),
                       bswap_32big(0xc34e3f4eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x7d7a2e66U), bswap_32big(0xa314e71bU), bswap_32big(0xd4aec9deU),
                           bswap_32big(0x179d672bU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xe958b440U), bswap_32big(0x4186492cU), bswap_32big(0xe652b504U),
                           bswap_32big(0x36b343a0U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0xb69d158bU));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0xdaaae8caU),
                   bswap_32big(0xab9200abU),
                   bswap_32big(0x0ce4ee56U),
                   bswap_32big(0xfaaee1a0U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x84654794U));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0xe61337d0U),
                   bswap_32big(0x0954f5ddU),
                   bswap_32big(0x8e839e9bU),
                   bswap_32big(0x4ffc076aU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0x45df49c4U),
                   bswap_32big(0xd8439fd4U),
                   bswap_32big(0xf4b4e4deU),
                   bswap_32big(0x9b9d0265U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xf310bd40U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0xfa080844U),
                   bswap_32big(0x532007d1U),
                   bswap_32big(0x31f61e4aU),
                   bswap_32big(0xfcab5541U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xbfabd333U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0x98791e2cU),
                   bswap_32big(0x67752bfdU),
                   bswap_32big(0x851acf41U),
                   bswap_32big(0x55e58873U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x14b00000U);
    WR1_PROG(REG_1600H, 0x00000b7bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x80e0001bU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x03430181U);
    while (1)
    {
        WR1_PROG(REG_1404H, 0x18c00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0017dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x00000220U, 0x00000a40U, 0x00000838U, 0x3030000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xb829837dU), bswap_32big(0x0a5ec490U), bswap_32big(0x9936d92cU),
                       bswap_32big(0x213f67dfU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x78071888U), bswap_32big(0xd0a05c6aU), bswap_32big(0xac608468U),
                           bswap_32big(0x0c22e1ccU));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x3c362187U), bswap_32big(0x42b4b070U), bswap_32big(0xd143b92dU),
                           bswap_32big(0xd62f1938U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb69d158bU));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xeced7f25U), bswap_32big(0x2fb674a8U), bswap_32big(0x4bb0103aU),
                           bswap_32big(0x58d499b1U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x5759088aU), bswap_32big(0xa04ede05U), bswap_32big(0xbd56d312U),
                           bswap_32big(0xee89813dU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0xf44ecf0bU), bswap_32big(0xcb9de670U), bswap_32big(0x086a1169U),
                           bswap_32big(0x65457c8cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb69d158bU));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0x320b0edeU), bswap_32big(0x3b24e8aaU), bswap_32big(0x25489e32U),
                           bswap_32big(0xc69f9456U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x84654794U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0x833b6b81U), bswap_32big(0xe2486d4cU), bswap_32big(0x3c4ccc5eU),
                           bswap_32big(0xfdb66f48U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf310bd40U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0x45630ecaU), bswap_32big(0x1bbb63b1U), bswap_32big(0x1dc5ce28U),
                           bswap_32big(0x08f5a71fU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xe8888a80U), bswap_32big(0x19fa156eU), bswap_32big(0x7b5d6836U),
                           bswap_32big(0xfdc66423U));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x84654794U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0x1b9dfed0U), bswap_32big(0x7ed8fba0U), bswap_32big(0xc0b74cd3U),
                           bswap_32big(0x44c257f4U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xf310bd40U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0x9b710a32U), bswap_32big(0x2dbd4fa4U), bswap_32big(0x1dad104aU),
                           bswap_32big(0x1e1af9eeU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x76bcbc65U), bswap_32big(0xec15b7a4U), bswap_32big(0x0e0e4907U),
                           bswap_32big(0x7a0d44e3U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0x58d603c5U),
                               bswap_32big(0xd1c09403U),
                               bswap_32big(0xd057e599U),
                               bswap_32big(0x85450d1fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x84654794U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0xb1db1427U),
                               bswap_32big(0xd41b4d92U),
                               bswap_32big(0x2fe632d3U),
                               bswap_32big(0xf36e62caU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0x0cff38a4U),
                               bswap_32big(0x7195d303U),
                               bswap_32big(0x198485f7U),
                               bswap_32big(0x2856d58bU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0xbaa7601fU),
                               bswap_32big(0x8653e310U),
                               bswap_32big(0xfe79a707U),
                               bswap_32big(0xb914c71cU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb69d158bU));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0x575d43c7U),
                               bswap_32big(0xee6ac078U),
                               bswap_32big(0x0cbdc9e6U),
                               bswap_32big(0x9b0ac41cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf310bd40U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0xce54a28dU),
                               bswap_32big(0x896e7483U),
                               bswap_32big(0x9c7505c1U),
                               bswap_32big(0xd598c603U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0x7994e923U),
                               bswap_32big(0x2cc7c97dU),
                               bswap_32big(0xc2fff528U),
                               bswap_32big(0x1e3d6fb3U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xb69d158bU));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x9f8a1ba2U),
                               bswap_32big(0x334818b1U),
                               bswap_32big(0xb89e51c2U),
                               bswap_32big(0xc70098a6U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xb8d7019aU),
                               bswap_32big(0x950eac81U),
                               bswap_32big(0x597e18c8U),
                               bswap_32big(0xf930f084U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0x84654794U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x30b03e45U),
                               bswap_32big(0xeb9178a8U),
                               bswap_32big(0xa7721fe0U),
                               bswap_32big(0x6b993ff1U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x4cd0ee07U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0xa6603c63U),
                               bswap_32big(0x22d74f10U),
                               bswap_32big(0x4886dbf3U),
                               bswap_32big(0x19cf43faU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0xd77ae3d3U),
                               bswap_32big(0x7a890a75U),
                               bswap_32big(0x908ff498U),
                               bswap_32big(0x79093ec5U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x84654794U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xf9e945e2U),
                               bswap_32big(0xf0a12fbcU),
                               bswap_32big(0x89b4ff06U),
                               bswap_32big(0x369889d7U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xf310bd40U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x630af722U),
                               bswap_32big(0xdef06045U),
                               bswap_32big(0x2a87bb7dU),
                               bswap_32big(0x4f23ec95U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb69d158bU));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xaae1bb9fU),
                               bswap_32big(0x0751297dU),
                               bswap_32big(0x9a266140U),
                               bswap_32big(0x500a4aebU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0x7da8f9feU),
                               bswap_32big(0xa56584e7U),
                               bswap_32big(0xc0e52e92U),
                               bswap_32big(0xbe0adb49U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xf310bd40U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xdaf58385U),
                               bswap_32big(0x597d1218U),
                               bswap_32big(0x6edca6ceU),
                               bswap_32big(0x42c2b0afU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x98525da3U),
                               bswap_32big(0xa0051dc9U),
                               bswap_32big(0x5967efecU),
                               bswap_32big(0x18199701U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xbfabd333U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0x1cd015cbU),
                   bswap_32big(0xcea24b3eU),
                   bswap_32big(0xf95893cfU),
                   bswap_32big(0xfc68ee32U));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    while (1)
    {
        WR1_PROG(REG_1600H, 0x38000fdeU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00A60000U);
        r_rsip_func100(bswap_32big(0x27484d03U), bswap_32big(0xaeafa5eeU), bswap_32big(0xa680abccU),
                       bswap_32big(0x18c499b8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2e8dc2f4U), bswap_32big(0x2768b22bU), bswap_32big(0xdee87c23U),
                           bswap_32big(0x0f211e5dU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x19b866d5U), bswap_32big(0x9b9d10e0U), bswap_32big(0x8cb86158U),
                           bswap_32big(0xf4ed3974U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xf310bd40U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0x6475feceU),
                   bswap_32big(0xbb94c7b0U),
                   bswap_32big(0x78290d88U),
                   bswap_32big(0xe7caff6dU));
    r_rsip_func017(OFS_ADR);
    WR1_PROG(REG_1404H, 0x16a80000U);
    WR1_PROG(REG_1608H, 0x80010360U);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc003(0x00030005U);
    r_rsip_subfunc003(0x03430005U);
    while (1)
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000a40U, 0x3131000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0xd229d89bU), bswap_32big(0xbdff527cU), bswap_32big(0xa890d551U),
                       bswap_32big(0xaa79fc09U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0xa1285823U), bswap_32big(0xe2124ebdU), bswap_32big(0x4bda0d10U),
                           bswap_32big(0x961d96beU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x212790ddU), bswap_32big(0x461d4c58U), bswap_32big(0xfcfce5d5U),
                           bswap_32big(0x810b2bb7U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x92caf92cU),
                   bswap_32big(0xc4910896U),
                   bswap_32big(0x163c2f17U),
                   bswap_32big(0x0d9661e7U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0x801625d4U), bswap_32big(0x1d64f428U), bswap_32big(0xe1882f2cU),
                       bswap_32big(0xd2764ebbU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x21939517U), bswap_32big(0x6829a110U), bswap_32big(0xd7462b40U),
                       bswap_32big(0x929b1417U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
