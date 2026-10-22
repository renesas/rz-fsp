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
        r_rsip_func100(bswap_32big(0x41dfa44aU), bswap_32big(0x5d5b83eaU), bswap_32big(0x2138db5dU),
                       bswap_32big(0x4d29b292U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x3030000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x3030000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc1a06affU), bswap_32big(0x4c7d47d4U), bswap_32big(0xca65e7d6U),
                           bswap_32big(0x5134ff7cU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xf2abf796U), bswap_32big(0x438441a7U), bswap_32big(0x08e7b710U),
                           bswap_32big(0x36a31ac7U));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x18b00000U);
    r_rsip_subfunc003(0x00c00191U);
    r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
    OFS_ADR = 104;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000581U));
    r_rsip_func101(bswap_32big(0xfcb47b06U),
                   bswap_32big(0x8b30eba3U),
                   bswap_32big(0x0a72c8a7U),
                   bswap_32big(0x69f63291U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
    OFS_ADR = 208;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
    r_rsip_func101(bswap_32big(0x01f265e6U),
                   bswap_32big(0x9d97b54eU),
                   bswap_32big(0xc9a6e42cU),
                   bswap_32big(0x0e53eab9U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x18c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0017dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000583U));
    r_rsip_func101(bswap_32big(0x42d81565U),
                   bswap_32big(0x43839796U),
                   bswap_32big(0x73a71acfU),
                   bswap_32big(0x7dadb6c3U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
    r_rsip_func101(bswap_32big(0x1593c645U),
                   bswap_32big(0x0710b913U),
                   bswap_32big(0xcdbb6860U),
                   bswap_32big(0xb626067eU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0x4918c3e5U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x00000585U));
    r_rsip_func101(bswap_32big(0xa0d664a6U),
                   bswap_32big(0x6a81928fU),
                   bswap_32big(0x7c3d826cU),
                   bswap_32big(0xd28eaa31U));
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
        r_rsip_func100(bswap_32big(0x6f37b0cbU), bswap_32big(0x53786e6cU), bswap_32big(0x7fe715f6U),
                       bswap_32big(0x87dcb68cU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xdfae20c4U), bswap_32big(0xdaa24ad2U), bswap_32big(0x4727527cU),
                           bswap_32big(0xeebc4953U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x3ed091ecU), bswap_32big(0x85bb6ceeU), bswap_32big(0x1412aa11U),
                           bswap_32big(0x5a564e77U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0xb1c4b1d9U), bswap_32big(0x5b913b51U), bswap_32big(0x7149c1c7U),
                           bswap_32big(0xdb429776U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000581U));
            r_rsip_func101(bswap_32big(0x2f9b860fU), bswap_32big(0xfa8b655bU), bswap_32big(0x6437f1d1U),
                           bswap_32big(0xf0705286U));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000586U));
            r_rsip_func101(bswap_32big(0x36fc11daU), bswap_32big(0x30b20102U), bswap_32big(0xadda95deU),
                           bswap_32big(0xf8becce6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
            OFS_ADR = 104;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000587U));
            r_rsip_func101(bswap_32big(0x9f7b9c5dU), bswap_32big(0xe0bd85bfU), bswap_32big(0x9fd189ceU),
                           bswap_32big(0xb98fcb5bU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000583U));
            r_rsip_func101(bswap_32big(0x809c25a4U), bswap_32big(0x3ce35d1fU), bswap_32big(0x22a0fc58U),
                           bswap_32big(0x072737c6U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000584U));
            r_rsip_func101(bswap_32big(0x1404b487U), bswap_32big(0x70ce0c5aU), bswap_32big(0xa7e116beU),
                           bswap_32big(0x091ccce5U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc009(bswap_32big(0x00000582U));
            r_rsip_func101(bswap_32big(0x7cfa68ceU), bswap_32big(0x67583f3aU), bswap_32big(0x105c46c1U),
                           bswap_32big(0xeecc7a82U));
            r_rsip_func059();
            r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
            OFS_ADR = 208;
            r_rsip_subfunc008(0x12980000U, 0x00000064U, bswap_32big(0x00000588U));
            r_rsip_func101(bswap_32big(0x688479c2U), bswap_32big(0xf1adf035U), bswap_32big(0x831575ebU),
                           bswap_32big(0x03f570d6U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
            OFS_ADR = 312;
            r_rsip_subfunc008(0x18b00000U, 0x00000064U, bswap_32big(0x00000589U));
            r_rsip_func101(bswap_32big(0x0eea07d4U), bswap_32big(0x22a678f4U), bswap_32big(0x1fb1dd7dU),
                           bswap_32big(0x080c2a2fU));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1e580000U);
            r_rsip_subfunc003(0x00c00181U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x30300009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x30300009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x30300009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x3030000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0x5429381cU), bswap_32big(0x41450ba7U), bswap_32big(0x08e14cf7U),
                           bswap_32big(0x2d9d3a08U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x30300009U);
                r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000585U));
                r_rsip_func101(bswap_32big(0x497fab8bU),
                               bswap_32big(0x2af17353U),
                               bswap_32big(0xbe1b1447U),
                               bswap_32big(0x76655d6cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000586U));
                r_rsip_func101(bswap_32big(0x087c881dU),
                               bswap_32big(0x3948501dU),
                               bswap_32big(0x3f2b276eU),
                               bswap_32big(0x231a1e18U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000581U));
                r_rsip_func101(bswap_32big(0x1aa8e6dfU),
                               bswap_32big(0x9661c098U),
                               bswap_32big(0x7f5497c1U),
                               bswap_32big(0xc8a7bbe2U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x8708c0acU),
                               bswap_32big(0xc102c4b6U),
                               bswap_32big(0xe7bbb950U),
                               bswap_32big(0x5fd8a3ddU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x00000587U));
                r_rsip_func101(bswap_32big(0x5749c3bdU),
                               bswap_32big(0x3a3f4944U),
                               bswap_32big(0xc85ee41aU),
                               bswap_32big(0xc6e12546U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x00000588U));
                r_rsip_func101(bswap_32big(0xc8e6a5bfU),
                               bswap_32big(0xbaab7ceaU),
                               bswap_32big(0x3c1e0a61U),
                               bswap_32big(0x73e2d547U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000582U));
                r_rsip_func101(bswap_32big(0x86a4997fU),
                               bswap_32big(0x783c9b6aU),
                               bswap_32big(0x499b415eU),
                               bswap_32big(0xd5c2df47U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x01b51e45U),
                               bswap_32big(0x1309cc2eU),
                               bswap_32big(0xa6658c59U),
                               bswap_32big(0xbcc5de7bU));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x4faa2f63U),
                               bswap_32big(0xf0efa0c2U),
                               bswap_32big(0x83150ba2U),
                               bswap_32big(0x742807f7U));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x3030000aU);
                r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058aU));
                r_rsip_func101(bswap_32big(0x80962e84U),
                               bswap_32big(0x87ae1635U),
                               bswap_32big(0xe5856010U),
                               bswap_32big(0x605689a8U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xd5447f3fU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058bU));
                r_rsip_func101(bswap_32big(0x809ea074U),
                               bswap_32big(0x85746d33U),
                               bswap_32big(0x238a6f9fU),
                               bswap_32big(0x53eb453cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000583U));
                r_rsip_func101(bswap_32big(0x87418d25U),
                               bswap_32big(0x72f3f695U),
                               bswap_32big(0x37659064U),
                               bswap_32big(0xc7ec1414U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0x75d7af9dU));
                OFS_ADR = 208;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0xf9742904U),
                               bswap_32big(0xa4785a85U),
                               bswap_32big(0x66c14d64U),
                               bswap_32big(0x3962d6c2U));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058cU));
                r_rsip_func101(bswap_32big(0x62807a87U),
                               bswap_32big(0xbf7e68adU),
                               bswap_32big(0x782eec89U),
                               bswap_32big(0x2af5372dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x9087a8d9U));
                OFS_ADR = 104;
                r_rsip_subfunc008(0x1e480000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0x4d1db174U),
                               bswap_32big(0x6d30220dU),
                               bswap_32big(0xc66081d1U),
                               bswap_32big(0x49d7725dU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000584U));
                r_rsip_func101(bswap_32big(0xdefe14f2U),
                               bswap_32big(0xd74d87cdU),
                               bswap_32big(0x0b44dec6U),
                               bswap_32big(0xee662695U));
                r_rsip_func309();
                r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
                OFS_ADR = 312;
                r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058dU));
                r_rsip_func101(bswap_32big(0x105052f5U),
                               bswap_32big(0x9f451fc5U),
                               bswap_32big(0xda64c15cU),
                               bswap_32big(0xe83cc712U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0x83f75db6U),
                               bswap_32big(0xf4ed9b85U),
                               bswap_32big(0x4c5cc020U),
                               bswap_32big(0xde8cdf76U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0x4918c3e5U));
    OFS_ADR = 416;
    r_rsip_subfunc008(0x10a00000U, 0x00000060U, bswap_32big(0x0000058eU));
    r_rsip_func101(bswap_32big(0xf8f1e614U),
                   bswap_32big(0xf4e1def1U),
                   bswap_32big(0xa4b65fccU),
                   bswap_32big(0x3b768461U));
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
        r_rsip_func100(bswap_32big(0x327c1df7U), bswap_32big(0xdff6e7b6U), bswap_32big(0x5dcdcd4eU),
                       bswap_32big(0xd3b0ae45U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x30300008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x30300008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xa14e3d01U), bswap_32big(0xc415be76U), bswap_32big(0x36d4026dU),
                           bswap_32big(0x1fcaf5bfU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xfb5cdcdcU), bswap_32big(0x505431d6U), bswap_32big(0xbad89432U),
                           bswap_32big(0x8aaf4dbfU));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xbd74f7dfU));
    OFS_ADR = 312;
    r_rsip_subfunc008(0x16a80000U, 0x00000064U, bswap_32big(0x0000058fU));
    r_rsip_func101(bswap_32big(0xa59187d4U),
                   bswap_32big(0xcb2880f3U),
                   bswap_32big(0x06d4f482U),
                   bswap_32big(0xe0a82925U));
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
        r_rsip_func100(bswap_32big(0x80676006U), bswap_32big(0x526cf128U), bswap_32big(0xc94896a1U),
                       bswap_32big(0xcfd1cdb7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x3131000aU);
            r_rsip_func101(bswap_32big(0xe0505f58U), bswap_32big(0x0af0330bU), bswap_32big(0x7644198dU),
                           bswap_32big(0xa8bc566cU));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x761c81b4U), bswap_32big(0x8b3f57bbU), bswap_32big(0xb392da47U),
                           bswap_32big(0xb7d60a6bU));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x073b14a3U),
                   bswap_32big(0x446110b6U),
                   bswap_32big(0x17ed6a8dU),
                   bswap_32big(0xee066a4eU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x3131000aU);
        r_rsip_func101(bswap_32big(0xd0b8dd75U), bswap_32big(0x92ff8d3dU), bswap_32big(0xa128a86aU),
                       bswap_32big(0xd729488eU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0xcdf47746U), bswap_32big(0xb7670d30U), bswap_32big(0x0f0a07e3U),
                       bswap_32big(0x5807c8f0U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
