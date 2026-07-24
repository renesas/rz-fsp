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
        r_rsip_func100(bswap_32big(0x074f6edaU), bswap_32big(0xabcfd827U), bswap_32big(0x43b6c990U),
                       bswap_32big(0x5e517ff1U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x54afe891U), bswap_32big(0x830b6e47U), bswap_32big(0x9cc593e0U),
                           bswap_32big(0x8dc1f4e1U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x6b14a7dcU), bswap_32big(0x105f93b0U), bswap_32big(0xee3e3f1bU),
                           bswap_32big(0xebeaffbdU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0x4236fc16U),
                   bswap_32big(0x36c78425U),
                   bswap_32big(0xafe5141eU),
                   bswap_32big(0x74aa2866U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x3cc10901U));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0x6c4a454fU),
                   bswap_32big(0x8c0fe784U),
                   bswap_32big(0x6fe247faU),
                   bswap_32big(0x1a782476U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0x087a9d14U),
                   bswap_32big(0x3a813d64U),
                   bswap_32big(0x2abcd079U),
                   bswap_32big(0xef001b92U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0xebbca1e3U),
                   bswap_32big(0x6a9edd53U),
                   bswap_32big(0x776b2f52U),
                   bswap_32big(0x0ce3ef93U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe4f152fdU));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0xca95d8feU),
                   bswap_32big(0xe6eb8986U),
                   bswap_32big(0x8fc12216U),
                   bswap_32big(0x74500ad9U));
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
        r_rsip_func100(bswap_32big(0xec240776U), bswap_32big(0xa03eba5aU), bswap_32big(0x6af89ecbU),
                       bswap_32big(0x201e8dccU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x0191d098U), bswap_32big(0xb7cb67a2U), bswap_32big(0xef2af996U),
                           bswap_32big(0x4375df72U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0xf4645d21U), bswap_32big(0x51d6321bU), bswap_32big(0x422d390aU),
                           bswap_32big(0x16940f5eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0x1bb05e3bU), bswap_32big(0x22e0d2d2U), bswap_32big(0xc070b7d2U),
                           bswap_32big(0x321c7f0eU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0xee865219U), bswap_32big(0x1625f138U), bswap_32big(0xbd06c2f9U),
                           bswap_32big(0x70b65575U));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0x017731e9U), bswap_32big(0x5a346f3fU), bswap_32big(0xaf9abd5bU),
                           bswap_32big(0x48b5a5f5U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0x7c91089eU), bswap_32big(0xa46fecb0U), bswap_32big(0x59529fc9U),
                           bswap_32big(0x11c326a7U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x3cc10901U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0xea1dd30eU), bswap_32big(0xc0a80ebaU), bswap_32big(0xdf0785d7U),
                           bswap_32big(0x824d9df8U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0xb53edb90U), bswap_32big(0x9ffecda0U), bswap_32big(0xdc0a5487U),
                           bswap_32big(0xdee05416U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xd1cd4039U), bswap_32big(0x9ebc05ebU), bswap_32big(0x0670b5bcU),
                           bswap_32big(0x99b26e0eU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x3cc10901U));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0xe461a2fdU), bswap_32big(0x75c4af8bU), bswap_32big(0x057b0cafU),
                           bswap_32big(0xba6fc777U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0x12baa836U), bswap_32big(0x8d224c22U), bswap_32big(0x5c560779U),
                           bswap_32big(0x9209be1aU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x48d8d893U), bswap_32big(0x64a01bfdU), bswap_32big(0x33351974U),
                           bswap_32big(0x96b536e8U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0x2a4d0362U),
                               bswap_32big(0xdf81c92fU),
                               bswap_32big(0x4689c43eU),
                               bswap_32big(0x7f827ef0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x3cc10901U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0x6b4f525cU),
                               bswap_32big(0xff672132U),
                               bswap_32big(0x08b3eeeeU),
                               bswap_32big(0x28ce5e60U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0x4f90f82cU),
                               bswap_32big(0x87833d5fU),
                               bswap_32big(0x568751dcU),
                               bswap_32big(0x24e19ee8U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x4d453c66U),
                               bswap_32big(0x31f6ca5dU),
                               bswap_32big(0x782837a0U),
                               bswap_32big(0x8a7338bcU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0xffbb543cU),
                               bswap_32big(0x3d1e935aU),
                               bswap_32big(0xeec4cf42U),
                               bswap_32big(0x809bcbe6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0xf7ebf9b9U),
                               bswap_32big(0x9ab0095cU),
                               bswap_32big(0xbcacd276U),
                               bswap_32big(0xa1088c59U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0x11fb639dU),
                               bswap_32big(0x6101a3d0U),
                               bswap_32big(0x568766eeU),
                               bswap_32big(0x7e5935d5U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0xba18c206U),
                               bswap_32big(0x66a62760U),
                               bswap_32big(0x39ded749U),
                               bswap_32big(0x9bfb5ff5U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x25e8a7c2U),
                               bswap_32big(0x909079c0U),
                               bswap_32big(0xfca27944U),
                               bswap_32big(0xab894085U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0x3cc10901U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0xd7436e8aU),
                               bswap_32big(0x8dec54bfU),
                               bswap_32big(0x6256b0a0U),
                               bswap_32big(0x5a2c3f67U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xabf7a97eU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x5dc27e84U),
                               bswap_32big(0x232fe590U),
                               bswap_32big(0x418e7123U),
                               bswap_32big(0xf6139618U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0x6b06aab7U),
                               bswap_32big(0x5fe274ffU),
                               bswap_32big(0xe1fb1309U),
                               bswap_32big(0xc4f4ceceU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x3cc10901U));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xa353a656U),
                               bswap_32big(0xe5846cc0U),
                               bswap_32big(0x22b18180U),
                               bswap_32big(0x8f17a0d0U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x38aba92eU),
                               bswap_32big(0xdfbc4667U),
                               bswap_32big(0x739a9311U),
                               bswap_32big(0x336194c4U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x2517e7b7U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xfc533492U),
                               bswap_32big(0x1f0de6fdU),
                               bswap_32big(0xb61e0029U),
                               bswap_32big(0x2e8bb03eU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0xbde12d7fU),
                               bswap_32big(0xa5a83925U),
                               bswap_32big(0x10157678U),
                               bswap_32big(0x8f28e1aeU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xe100cca0U),
                               bswap_32big(0x41f8ae15U),
                               bswap_32big(0xdb4dc83eU),
                               bswap_32big(0x6e7e7352U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x32ca1e5cU),
                               bswap_32big(0xbad17a32U),
                               bswap_32big(0xc51262ceU),
                               bswap_32big(0xafa9e521U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xe4f152fdU));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0x9e740d9fU),
                   bswap_32big(0x06ad5d82U),
                   bswap_32big(0xef41c8e5U),
                   bswap_32big(0x22860cb5U));
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
        r_rsip_func100(bswap_32big(0xcf378f4aU), bswap_32big(0x8d5511c1U), bswap_32big(0xcc13eb77U),
                       bswap_32big(0xfd6648c4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9f2abba0U), bswap_32big(0x132f39ddU), bswap_32big(0xde604643U),
                           bswap_32big(0xc8870803U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x0e2fb333U), bswap_32big(0x4b1c913aU), bswap_32big(0x087a7993U),
                           bswap_32big(0xa5fbb2bbU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x0b097e1fU));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0x042116cdU),
                   bswap_32big(0x1672790aU),
                   bswap_32big(0xd3d73da8U),
                   bswap_32big(0x107362fcU));
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
        r_rsip_func100(bswap_32big(0xf286abe5U), bswap_32big(0xbe40467cU), bswap_32big(0xdff27cd2U),
                       bswap_32big(0xa0d1cc09U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0x76832832U), bswap_32big(0x984e106dU), bswap_32big(0xc7d15632U),
                           bswap_32big(0x6688d4d4U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xd80cd344U), bswap_32big(0x7d694c05U), bswap_32big(0xddc14dc2U),
                           bswap_32big(0x71026617U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x2b0aeed2U),
                   bswap_32big(0xf65564fdU),
                   bswap_32big(0x7381aca4U),
                   bswap_32big(0x543d1135U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0x82e585d8U), bswap_32big(0x7d9d587bU), bswap_32big(0x74b8e970U),
                       bswap_32big(0x139ac794U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x8afd88cbU), bswap_32big(0x8a205916U), bswap_32big(0x50c23523U),
                       bswap_32big(0x7c5b71c0U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
