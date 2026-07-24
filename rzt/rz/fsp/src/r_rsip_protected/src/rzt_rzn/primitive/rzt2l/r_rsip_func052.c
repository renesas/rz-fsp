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
        r_rsip_func100(bswap_32big(0x2174f525U), bswap_32big(0x502b5f8aU), bswap_32big(0xbd825014U),
                       bswap_32big(0x8bbee136U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc004(0x00000220U, 0x00000220U, 0x1010000cU);
            r_rsip_subfunc004(0x00000630U, 0x00000630U, 0x1010000cU);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8a1c090bU), bswap_32big(0xfc827027U), bswap_32big(0xbb787a71U),
                           bswap_32big(0x8bb44df5U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0xdbadfaf4U), bswap_32big(0x69d4865eU), bswap_32big(0x20d818aeU),
                           bswap_32big(0xb0c3dbbdU));
            break;
        }
    }

    WR1_PROG(REG_1404H, 0x19b00000U);
    r_rsip_subfunc003(0x00c00091U);
    r_rsip_subfunc007(bswap_32big(0x293ea72dU));
    OFS_ADR = 40;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000521U));
    r_rsip_func101(bswap_32big(0x6477f101U),
                   bswap_32big(0xc410ab44U),
                   bswap_32big(0x53777753U),
                   bswap_32big(0x0046c89bU));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xc2584badU));
    OFS_ADR = 80;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
    r_rsip_func101(bswap_32big(0x246c507fU),
                   bswap_32big(0x0482434cU),
                   bswap_32big(0x97ad822fU),
                   bswap_32big(0xcc4e25f3U));
    r_rsip_func016(OFS_ADR);
    WR1_PROG(REG_1404H, 0x19c00000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0007dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc007(bswap_32big(0xac2c887dU));
    OFS_ADR = 0;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000523U));
    r_rsip_func101(bswap_32big(0x294e21d2U),
                   bswap_32big(0x8dd5f501U),
                   bswap_32big(0xfe72bb7dU),
                   bswap_32big(0xf030e351U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xb60ea327U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
    r_rsip_func101(bswap_32big(0xc435e09cU),
                   bswap_32big(0x6635c28aU),
                   bswap_32big(0x97d12e34U),
                   bswap_32big(0xfb7f7f59U));
    r_rsip_func016(OFS_ADR);
    r_rsip_subfunc007(bswap_32big(0xe05c8defU));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x00000525U));
    r_rsip_func101(bswap_32big(0x2f82f0cdU),
                   bswap_32big(0xfef976a7U),
                   bswap_32big(0x9b2a1bf4U),
                   bswap_32big(0xb7f7f5a7U));
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
        r_rsip_func100(bswap_32big(0x65506dd4U), bswap_32big(0xeb2f96e7U), bswap_32big(0xd7a9a9bdU),
                       bswap_32big(0x2ab253b7U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0xf58ca6c3U), bswap_32big(0x115c1af9U), bswap_32big(0x9d38f932U),
                           bswap_32big(0x93bdb921U));
            break;
        }
        else
        {
            r_rsip_subfunc007(bswap_32big(0xac2c887dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x3803f466U), bswap_32big(0xd9c60de6U), bswap_32big(0x2c7f6c77U),
                           bswap_32big(0x7ac951ddU));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x293ea72dU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0x7cd82e7eU), bswap_32big(0xc8092630U), bswap_32big(0x264d8eebU),
                           bswap_32big(0x5c80b814U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc009(bswap_32big(0x00000521U));
            r_rsip_func101(bswap_32big(0x8a7c5f13U), bswap_32big(0xa8a3217aU), bswap_32big(0xc976e085U),
                           bswap_32big(0x7c843f59U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xac2c887dU));
            OFS_ADR = 0;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000526U));
            r_rsip_func101(bswap_32big(0x5cf3dcefU), bswap_32big(0x0f388bb8U), bswap_32big(0x85bcd532U),
                           bswap_32big(0xbb847f90U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0x293ea72dU));
            OFS_ADR = 40;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000527U));
            r_rsip_func101(bswap_32big(0x8e569b50U), bswap_32big(0xe367b20cU), bswap_32big(0xa9db3fbdU),
                           bswap_32big(0xfe82b104U));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xc2584badU));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000523U));
            r_rsip_func101(bswap_32big(0xd4e8ab0bU), bswap_32big(0x701d68f3U), bswap_32big(0x0203c718U),
                           bswap_32big(0x046b0863U));
            r_rsip_func017(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb60ea327U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000524U));
            r_rsip_func101(bswap_32big(0x5d5e98e8U), bswap_32big(0x12b22e2aU), bswap_32big(0x3e5fe0cbU),
                           bswap_32big(0x05fb6272U));
            r_rsip_func017(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc009(bswap_32big(0x00000522U));
            r_rsip_func101(bswap_32big(0xd5171693U), bswap_32big(0x32ced0efU), bswap_32big(0xaa46c39cU),
                           bswap_32big(0xce0c3789U));
            r_rsip_func053();
            r_rsip_subfunc007(bswap_32big(0xc2584badU));
            OFS_ADR = 80;
            r_rsip_subfunc008(0x13980000U, 0x00000024U, bswap_32big(0x00000528U));
            r_rsip_func101(bswap_32big(0x14e9bb5eU), bswap_32big(0x71f845f2U), bswap_32big(0xcc18fd63U),
                           bswap_32big(0x053dae9fU));
            r_rsip_func016(OFS_ADR);
            r_rsip_subfunc007(bswap_32big(0xb60ea327U));
            OFS_ADR = 120;
            r_rsip_subfunc008(0x19b00000U, 0x00000024U, bswap_32big(0x00000529U));
            r_rsip_func101(bswap_32big(0x65862541U), bswap_32big(0xb6dfe64dU), bswap_32big(0x7652be1cU),
                           bswap_32big(0xfc32d588U));
            r_rsip_func016(OFS_ADR);
            WR1_PROG(REG_1404H, 0x1f580000U);
            r_rsip_subfunc003(0x00c00081U);
            r_rsip_subfunc001(0x00000220U, 0x00000fd8U, 0x00000838U, 0x10100009U);
            r_rsip_subfunc001(0x00000630U, 0x00000fd8U, 0x00000220U, 0x10100009U);
            r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000630U, 0x10100009U);
            r_rsip_subfunc001(0x00000220U, 0x00000630U, 0x00000838U, 0x1010000aU);
            WR1_PROG(REG_143CH, 0x00a10000U);
            r_rsip_func100(bswap_32big(0xdd140c74U), bswap_32big(0x80ecaa6bU), bswap_32big(0x9a7ddfdfU),
                           bswap_32big(0x33e36b82U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_subfunc001(0x00000838U, 0x00000fd8U, 0x00000220U, 0x10100009U);
                r_rsip_subfunc007(bswap_32big(0xac2c887dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000525U));
                r_rsip_func101(bswap_32big(0x0ae4f0e6U),
                               bswap_32big(0x73d4d7c5U),
                               bswap_32big(0xf6958f11U),
                               bswap_32big(0x312212cbU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xc2584badU));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000526U));
                r_rsip_func101(bswap_32big(0x98f480e1U),
                               bswap_32big(0xbcdb948bU),
                               bswap_32big(0x578f075aU),
                               bswap_32big(0x612f595aU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000521U));
                r_rsip_func101(bswap_32big(0xd33cb312U),
                               bswap_32big(0xfb6d5e01U),
                               bswap_32big(0x57f1a3eeU),
                               bswap_32big(0xe0d720e5U));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xac2c887dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0x15c523c0U),
                               bswap_32big(0x73b7cfd4U),
                               bswap_32big(0x3cf2905cU),
                               bswap_32big(0x0bc334aaU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x293ea72dU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x00000527U));
                r_rsip_func101(bswap_32big(0x66cab5c5U),
                               bswap_32big(0x0a69ea12U),
                               bswap_32big(0x67080fa7U),
                               bswap_32big(0xbc917876U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb60ea327U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x00000528U));
                r_rsip_func101(bswap_32big(0x7f6f800aU),
                               bswap_32big(0x637eb82dU),
                               bswap_32big(0x4823a1b7U),
                               bswap_32big(0x83f4902cU));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000522U));
                r_rsip_func101(bswap_32big(0x6fbe07c4U),
                               bswap_32big(0x44c376fbU),
                               bswap_32big(0x87d94d0cU),
                               bswap_32big(0x72eb411bU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0x293ea72dU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x318c7411U),
                               bswap_32big(0xa1cdcdc7U),
                               bswap_32big(0x2b3fa5f6U),
                               bswap_32big(0x454488f6U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xe242c8b6U),
                               bswap_32big(0xb774bd93U),
                               bswap_32big(0x0ad92133U),
                               bswap_32big(0x654400cdU));
            }
            else
            {
                r_rsip_subfunc001(0x00000630U, 0x00000220U, 0x00000630U, 0x1010000aU);
                r_rsip_subfunc007(bswap_32big(0xc2584badU));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052aU));
                r_rsip_func101(bswap_32big(0xc0554b7eU),
                               bswap_32big(0xeb156451U),
                               bswap_32big(0xdcd6ba0eU),
                               bswap_32big(0xb050d3f8U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xac2c887dU));
                OFS_ADR = 0;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052bU));
                r_rsip_func101(bswap_32big(0x49ad2f0cU),
                               bswap_32big(0x38da0806U),
                               bswap_32big(0x351005a3U),
                               bswap_32big(0x5442b4b2U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000523U));
                r_rsip_func101(bswap_32big(0xadb22ca6U),
                               bswap_32big(0xb74a0392U),
                               bswap_32big(0xd9e4cbaeU),
                               bswap_32big(0xb0c0c45fU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xc2584badU));
                OFS_ADR = 80;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0xd1a8fe0dU),
                               bswap_32big(0x42bce2b7U),
                               bswap_32big(0xc5bcf680U),
                               bswap_32big(0x698d2aacU));
                r_rsip_func016(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0xb60ea327U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052cU));
                r_rsip_func101(bswap_32big(0x85c41feaU),
                               bswap_32big(0x1b1a0c25U),
                               bswap_32big(0xc2953832U),
                               bswap_32big(0x46307924U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc007(bswap_32big(0x293ea72dU));
                OFS_ADR = 40;
                r_rsip_subfunc008(0x1f480000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0x919f5f2eU),
                               bswap_32big(0x0cbcc626U),
                               bswap_32big(0xdc34422bU),
                               bswap_32big(0xd9686835U));
                r_rsip_func017(OFS_ADR);
                r_rsip_subfunc009(bswap_32big(0x00000524U));
                r_rsip_func101(bswap_32big(0x68f31af0U),
                               bswap_32big(0x0635dd98U),
                               bswap_32big(0xbe43203dU),
                               bswap_32big(0x9a581d4fU));
                r_rsip_func303();
                r_rsip_subfunc007(bswap_32big(0xb60ea327U));
                OFS_ADR = 120;
                r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052dU));
                r_rsip_func101(bswap_32big(0xc427d5d1U),
                               bswap_32big(0x3d8c1205U),
                               bswap_32big(0x20449da7U),
                               bswap_32big(0xf1489724U));
                r_rsip_func016(OFS_ADR);
                r_rsip_func101(bswap_32big(0xbd381474U),
                               bswap_32big(0xbbc4de0fU),
                               bswap_32big(0x6b07ed9eU),
                               bswap_32big(0x376f2f46U));
            }
        }
    }

    r_rsip_subfunc007(bswap_32big(0xe05c8defU));
    OFS_ADR = 160;
    r_rsip_subfunc008(0x11a00000U, 0x00000020U, bswap_32big(0x0000052eU));
    r_rsip_func101(bswap_32big(0x4a195aeeU),
                   bswap_32big(0x4d7034aeU),
                   bswap_32big(0x66e504c0U),
                   bswap_32big(0x2e28ecceU));
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
        r_rsip_func100(bswap_32big(0x28911abaU), bswap_32big(0xc42fdebbU), bswap_32big(0x91f177bdU),
                       bswap_32big(0xe67c706eU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000a40U, 0x00000630U, 0x00000630U, 0x10100008U);
            r_rsip_subfunc001(0x00000a40U, 0x00000220U, 0x00000220U, 0x10100008U);
            WR1_PROG(REG_1600H, 0x000033c0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xe5f129c8U), bswap_32big(0x24d0b0e3U), bswap_32big(0x8a535373U),
                           bswap_32big(0x505eeba6U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x2a93cc72U), bswap_32big(0x1fb80e91U), bswap_32big(0xf322d2e6U),
                           bswap_32big(0xd415b974U));
            break;
        }
    }

    r_rsip_subfunc007(bswap_32big(0xb60ea327U));
    OFS_ADR = 120;
    r_rsip_subfunc008(0x17a80000U, 0x00000024U, bswap_32big(0x0000052fU));
    r_rsip_func101(bswap_32big(0x61e3438cU),
                   bswap_32big(0xc23d139fU),
                   bswap_32big(0x426c7a70U),
                   bswap_32big(0xbf8baf7dU));
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
        r_rsip_func100(bswap_32big(0x5a58000cU), bswap_32big(0x951c9c18U), bswap_32big(0x82a3f0a2U),
                       bswap_32big(0xc8483238U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_subfunc001(0x00000838U, 0x00000220U, 0x00000838U, 0x1111000aU);
            r_rsip_func101(bswap_32big(0x34999bb3U), bswap_32big(0x078d1426U), bswap_32big(0x7a76f30aU),
                           bswap_32big(0x07d42290U));
        }
        else
        {
            r_rsip_func101(bswap_32big(0x95a274b4U), bswap_32big(0xd440a600U), bswap_32big(0x5fc31af8U),
                           bswap_32big(0xc32671c6U));
            break;
        }
    }

    WR1_PROG(REG_1600H, 0x3800db60U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x0649d0feU),
                   bswap_32big(0x6bd31133U),
                   bswap_32big(0xc261ef50U),
                   bswap_32big(0xfbca29a8U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_subfunc001(0x00000220U, 0x00000838U, 0x00000838U, 0x1111000aU);
        r_rsip_func101(bswap_32big(0x8e1057d3U), bswap_32big(0x1de37798U), bswap_32big(0x121bb126U),
                       bswap_32big(0x86db422bU));
    }
    else
    {
        r_rsip_func101(bswap_32big(0x38a16e4eU), bswap_32big(0x908cbae5U), bswap_32big(0x02e48c5fU),
                       bswap_32big(0x360ec2f2U));
    }

    WR1_PROG(REG_1600H, 0x000037b9U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c1dU);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00602000U);
    WR1_PROG(REG_1458H, 0x00000000U);
}
