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
        r_rsip_func100(bswap_32big(0xfbbb6cd5U), bswap_32big(0xbcf54e97U), bswap_32big(0x5fe3c93aU),
                       bswap_32big(0xc8d028d1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x37445d4cU), bswap_32big(0x6620d7b2U), bswap_32big(0xc760f9f7U),
                           bswap_32big(0x304da757U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb3e222ddU), bswap_32big(0x9fdfe37cU), bswap_32big(0x1c357e2fU),
                           bswap_32big(0x30ba9375U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0xb4f25ecaU),
                   bswap_32big(0x2280f76dU),
                   bswap_32big(0x580a6889U),
                   bswap_32big(0x6b06af63U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0xec78e78aU),
                   bswap_32big(0xc7667daaU),
                   bswap_32big(0xaa512986U),
                   bswap_32big(0x306147a7U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0x65c77216U));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0x6b5709c5U),
                   bswap_32big(0x6b98ef7eU),
                   bswap_32big(0xc7a11f98U),
                   bswap_32big(0x6dd9c17dU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x73702829U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0x49f66361U),
                   bswap_32big(0x82c75f47U),
                   bswap_32big(0x418e9cdaU),
                   bswap_32big(0x12a01937U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x6636e075U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0xa35a32f2U),
                   bswap_32big(0x6cee82faU),
                   bswap_32big(0xcae40603U),
                   bswap_32big(0x9dadbccbU));
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
        r_rsip_func100(bswap_32big(0x19b43bbbU), bswap_32big(0xd60b5e4cU), bswap_32big(0x88766ba6U),
                       bswap_32big(0x02644b68U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x692bbe83U), bswap_32big(0xedcd0c2fU), bswap_32big(0x57dbd416U),
                           bswap_32big(0xab36d1e0U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0x65c77216U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0xa73172f2U), bswap_32big(0x2456f800U), bswap_32big(0x5022f01dU),
                           bswap_32big(0x43062defU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xe2b9d27cU), bswap_32big(0x72919714U), bswap_32big(0x619830a4U),
                           bswap_32big(0x67ac8e30U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0xea7674a6U), bswap_32big(0xda0fec98U), bswap_32big(0x8664e463U),
                           bswap_32big(0xb8c2100bU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x65c77216U));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0x208a853aU), bswap_32big(0xdf88a3bcU), bswap_32big(0x8eddcd8fU),
                           bswap_32big(0x3b76c503U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0x1e680fd6U), bswap_32big(0x7ccfab28U), bswap_32big(0xc97bb97aU),
                           bswap_32big(0xc45d7621U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0x8e9c16d6U), bswap_32big(0x4fb4b41eU), bswap_32big(0x5db7beccU),
                           bswap_32big(0x8bb0757fU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x73702829U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0x2b83f895U), bswap_32big(0x4f0a4c2eU), bswap_32big(0xca021afaU),
                           bswap_32big(0x92c1a7eaU));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xdab4096dU), bswap_32big(0xc077ad23U), bswap_32big(0x42fc87f8U),
                           bswap_32big(0x09a72d3cU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0x3d270c94U), bswap_32big(0xca6c7b18U), bswap_32big(0xbaef4aa2U),
                           bswap_32big(0x69057b5cU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x73702829U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0x7ddd37eeU), bswap_32big(0xe1fc122fU), bswap_32big(0x32c06cdeU),
                           bswap_32big(0x650d9af0U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x17d04ed5U), bswap_32big(0xbbd55dafU), bswap_32big(0xcb628c36U),
                           bswap_32big(0x50325cc0U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0x65c77216U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0xca37d361U),
                               bswap_32big(0x6c9e4d1cU),
                               bswap_32big(0x6c8e95a2U),
                               bswap_32big(0xf4cf9877U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0xf1593d93U),
                               bswap_32big(0xa02c3ba8U),
                               bswap_32big(0xe5cd959dU),
                               bswap_32big(0xfbd9e028U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0xc76df23aU),
                               bswap_32big(0xb9248175U),
                               bswap_32big(0xae697053U),
                               bswap_32big(0x3e70f351U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x65c77216U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0xdb367fd2U),
                               bswap_32big(0x6ea0df68U),
                               bswap_32big(0x6ccd4cb7U),
                               bswap_32big(0x0fc9b6e8U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0x76a5c58aU),
                               bswap_32big(0xd0caa4b1U),
                               bswap_32big(0x76500717U),
                               bswap_32big(0xfefe482aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x73702829U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0x48becdeaU),
                               bswap_32big(0x2ccbe106U),
                               bswap_32big(0x28169acbU),
                               bswap_32big(0xee2b1756U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0x4a527b0fU),
                               bswap_32big(0x07452906U),
                               bswap_32big(0x5d1d0053U),
                               bswap_32big(0x23e2bff6U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0xff010839U),
                               bswap_32big(0x987ed1abU),
                               bswap_32big(0x15fd275cU),
                               bswap_32big(0xd2b86100U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xdbd836b6U),
                               bswap_32big(0x92f93df6U),
                               bswap_32big(0x42198b17U),
                               bswap_32big(0x5960290cU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x087b80d4U),
                               bswap_32big(0x6046ce1bU),
                               bswap_32big(0x3a8cea37U),
                               bswap_32big(0xcbba9484U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x65c77216U));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x5ad8c1e7U),
                               bswap_32big(0x63b28011U),
                               bswap_32big(0x0d7b27baU),
                               bswap_32big(0x1ec92511U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0x63eb8e34U),
                               bswap_32big(0x5856d160U),
                               bswap_32big(0x9f857c02U),
                               bswap_32big(0x94191345U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xdeba65f4U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xa8ba7234U),
                               bswap_32big(0xcf94c357U),
                               bswap_32big(0xba4bcf2dU),
                               bswap_32big(0xedf385c5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x73702829U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x86dabd43U),
                               bswap_32big(0x397affb3U),
                               bswap_32big(0xc27b4475U),
                               bswap_32big(0xb3bd4c1fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb15e8d68U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0x4ec7b600U),
                               bswap_32big(0x2b28873eU),
                               bswap_32big(0x533f72b2U),
                               bswap_32big(0x614eaed5U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0xd04c0e91U),
                               bswap_32big(0x1e148f0aU),
                               bswap_32big(0xccfa4b4aU),
                               bswap_32big(0x19210df9U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x73702829U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xa310e622U),
                               bswap_32big(0x9aca30cbU),
                               bswap_32big(0xc866e023U),
                               bswap_32big(0xf6297582U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x1569b4ffU),
                               bswap_32big(0x0977a193U),
                               bswap_32big(0xdc160703U),
                               bswap_32big(0x59b639eaU));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x6636e075U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0x40eff8d3U),
                   bswap_32big(0xe46b42dcU),
                   bswap_32big(0x900a3e92U),
                   bswap_32big(0x2ec83129U));
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
        r_rsip_func100(bswap_32big(0x8fe1ff29U), bswap_32big(0x097710c1U), bswap_32big(0x99f3506bU),
                       bswap_32big(0x42e154c4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x5db39808U), bswap_32big(0x05fcf85dU), bswap_32big(0x3ef8b03eU),
                           bswap_32big(0x63ab5e41U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8d02efa9U), bswap_32big(0xd410c91fU), bswap_32big(0xb0d73d2fU),
                           bswap_32big(0xf4603de9U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x73702829U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0xac135de5U),
                   bswap_32big(0x8304b413U),
                   bswap_32big(0xbbb22b30U),
                   bswap_32big(0xef4c1600U));
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
        r_rsip_func100(bswap_32big(0xc7113980U), bswap_32big(0x1cc2c996U), bswap_32big(0x5c853447U),
                       bswap_32big(0x6270f7aeU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0x28f4aaa7U), bswap_32big(0xc12654e6U), bswap_32big(0xc9a4f865U),
                           bswap_32big(0xd138a692U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xc6f5ddf3U), bswap_32big(0xddd8928fU), bswap_32big(0x3952f3acU),
                           bswap_32big(0x767849c6U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xda6c51feU),
                   bswap_32big(0x29c12d62U),
                   bswap_32big(0xf8fe24e8U),
                   bswap_32big(0xa25e66b0U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0x2f997760U), bswap_32big(0x74bfda9dU), bswap_32big(0xd467f53eU),
                       bswap_32big(0x31d8a969U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x631bbb17U), bswap_32big(0xb18deb4aU), bswap_32big(0x698aa26aU),
                       bswap_32big(0xea7130feU));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
