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
        r_rsip_func100(bswap_32big(0xcaa67d1fU), bswap_32big(0xe2b3b494U), bswap_32big(0xf3eb97feU),
                       bswap_32big(0xba9ca229U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x02d11425U), bswap_32big(0xce937f0fU), bswap_32big(0x823aac75U),
                           bswap_32big(0xaa6070b3U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xb8d6f5adU), bswap_32big(0x4c36624eU), bswap_32big(0x46779b00U),
                           bswap_32big(0xbfc08c28U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0x794158a3U));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0x04424ab2U),
                   bswap_32big(0x7a2f48e8U),
                   bswap_32big(0xe6d9c1a6U),
                   bswap_32big(0x89904588U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0x9729dbaaU),
                   bswap_32big(0x55704af2U),
                   bswap_32big(0x0470c243U),
                   bswap_32big(0xa82d8f3eU));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0xe4c7348eU),
                   bswap_32big(0x3f5be157U),
                   bswap_32big(0xaa09f0f0U),
                   bswap_32big(0xeac5e5efU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x781457c5U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0x605adcadU),
                   bswap_32big(0xfc154524U),
                   bswap_32big(0xa0342617U),
                   bswap_32big(0x5a305d76U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x9a3b9f44U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0x26df6b5dU),
                   bswap_32big(0x6d385533U),
                   bswap_32big(0x572fd2a7U),
                   bswap_32big(0x9273be8fU));
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
        r_rsip_func100(bswap_32big(0x3cdba578U), bswap_32big(0xfa68f049U), bswap_32big(0xb25e3c98U),
                       bswap_32big(0x8fa8173aU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xaa4a1e59U), bswap_32big(0x7d7e534eU), bswap_32big(0xfb82d281U),
                           bswap_32big(0x36642493U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x6d962864U), bswap_32big(0x811a9c9fU), bswap_32big(0x7474fb70U),
                           bswap_32big(0x47118996U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x794158a3U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0x529ef194U), bswap_32big(0x1dc3b915U), bswap_32big(0x1c2c5eeaU),
                           bswap_32big(0x54fd8654U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x5f1e393aU), bswap_32big(0xf3ebd8f8U), bswap_32big(0xd6b4c1e1U),
                           bswap_32big(0x79ded8daU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0x7760f138U), bswap_32big(0xabe3baccU), bswap_32big(0x334d26a4U),
                           bswap_32big(0xa8ecde9fU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x794158a3U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0xa0455be3U), bswap_32big(0xfc18be54U), bswap_32big(0x5090a738U),
                           bswap_32big(0xe95f703bU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0xa4f981f3U), bswap_32big(0xf242146cU), bswap_32big(0x65021c18U),
                           bswap_32big(0xca1f3b01U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x781457c5U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0x6d23e728U), bswap_32big(0x38aef2c7U), bswap_32big(0x11938ef0U),
                           bswap_32big(0xeadb5111U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xa76c5703U), bswap_32big(0x69296c95U), bswap_32big(0xcf882cb3U),
                           bswap_32big(0xcce1160bU));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0x572de636U), bswap_32big(0x84e913ffU), bswap_32big(0x9cba6847U),
                           bswap_32big(0xe6af589aU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x781457c5U));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0xe33e44f9U), bswap_32big(0xf8ddfdc2U), bswap_32big(0xd7f3f6d2U),
                           bswap_32big(0x9590eaabU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x008c3d76U), bswap_32big(0xe44792bfU), bswap_32big(0xd203a3dcU),
                           bswap_32big(0xc63b8653U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0x76baf410U),
                               bswap_32big(0x8613fad9U),
                               bswap_32big(0x8d4496a0U),
                               bswap_32big(0x3f7968c6U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0xb5d2a142U),
                               bswap_32big(0x6813ec23U),
                               bswap_32big(0xa911296cU),
                               bswap_32big(0x944086feU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0xf7e55de7U),
                               bswap_32big(0x27c6b621U),
                               bswap_32big(0x3414d0b1U),
                               bswap_32big(0x45b25b9aU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x1aa48b4bU),
                               bswap_32big(0x5f5c4f19U),
                               bswap_32big(0x23d298c9U),
                               bswap_32big(0xd9d7bc6fU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x794158a3U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0x893ccc3dU),
                               bswap_32big(0x7735c8c3U),
                               bswap_32big(0x8c1b7feeU),
                               bswap_32big(0x405f8affU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x781457c5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0x718e870bU),
                               bswap_32big(0x93a80711U),
                               bswap_32big(0x177167fcU),
                               bswap_32big(0x71de06f8U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0xb4520d76U),
                               bswap_32big(0xe7ff25f1U),
                               bswap_32big(0x69fa1057U),
                               bswap_32big(0x59416adeU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x794158a3U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0xdcbb2913U),
                               bswap_32big(0xbbd08348U),
                               bswap_32big(0x1fbe3340U),
                               bswap_32big(0xa58e6fecU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x6f47a592U),
                               bswap_32big(0xe0a1893fU),
                               bswap_32big(0xa106b03cU),
                               bswap_32big(0x034f9489U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x41a7b23eU),
                               bswap_32big(0x0ef35f22U),
                               bswap_32big(0xd0a9f7f0U),
                               bswap_32big(0x4c827512U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc0fb930dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x5184e368U),
                               bswap_32big(0x08515047U),
                               bswap_32big(0xda595ceaU),
                               bswap_32big(0x5ae4fe3fU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0xa20e71a1U),
                               bswap_32big(0x06246ed3U),
                               bswap_32big(0xb441f088U),
                               bswap_32big(0xd04596c1U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x9b1c4bcfU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xf2890426U),
                               bswap_32big(0x2386f4b8U),
                               bswap_32big(0xe63883e7U),
                               bswap_32big(0xd229b331U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x781457c5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x6f3f6b3fU),
                               bswap_32big(0x5fbe05adU),
                               bswap_32big(0xc04dd5e5U),
                               bswap_32big(0x68b7cf6dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x794158a3U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xeb217809U),
                               bswap_32big(0x42670ab6U),
                               bswap_32big(0x76f7afe5U),
                               bswap_32big(0xef557cd0U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0x920349d6U),
                               bswap_32big(0xb135b983U),
                               bswap_32big(0xe52cd424U),
                               bswap_32big(0xdcb9dfcfU));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x781457c5U));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0xb3f6afa3U),
                               bswap_32big(0xb96a2bd4U),
                               bswap_32big(0x5f0690ffU),
                               bswap_32big(0x59f00f17U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x7305621eU),
                               bswap_32big(0xaa8f309eU),
                               bswap_32big(0x54d8cc97U),
                               bswap_32big(0xf6c6c0a0U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x9a3b9f44U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0xc911c808U),
                   bswap_32big(0xcbf2cd59U),
                   bswap_32big(0xc2ad53f1U),
                   bswap_32big(0xefc5f602U));
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
        r_rsip_func100(bswap_32big(0x815a6d57U), bswap_32big(0x7e1dbb4cU), bswap_32big(0x81eb8304U),
                       bswap_32big(0xcd6ac6d8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0f5eb0a1U), bswap_32big(0x6504f5b4U), bswap_32big(0xf8bcc7bcU),
                           bswap_32big(0x9819d8f8U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x8c53bcf4U), bswap_32big(0x46d0862bU), bswap_32big(0xc0d7b456U),
                           bswap_32big(0xb80b7b77U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0x781457c5U));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0x02fab043U),
                   bswap_32big(0x34fdae6cU),
                   bswap_32big(0x39471095U),
                   bswap_32big(0xa4c1af65U));
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
        r_rsip_func100(bswap_32big(0x665298ecU), bswap_32big(0xe4d83eaaU), bswap_32big(0x80fade43U),
                       bswap_32big(0x5ff00970U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0xf4abcf22U), bswap_32big(0x93b7d1b0U), bswap_32big(0x72801291U),
                           bswap_32big(0x0da581f4U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x64edd25eU), bswap_32big(0x17ebdad1U), bswap_32big(0x23f96241U),
                           bswap_32big(0x6ad0ed24U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xeae48f4cU),
                   bswap_32big(0xa71cf890U),
                   bswap_32big(0x3d456889U),
                   bswap_32big(0x3f54854eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0x192a2fc0U), bswap_32big(0xb30b329fU), bswap_32big(0xb54f9d06U),
                       bswap_32big(0x7ff99871U));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x058def6aU), bswap_32big(0xb75b6450U), bswap_32big(0x4cbfca84U),
                       bswap_32big(0x238d59f6U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
