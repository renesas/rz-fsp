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

rsip_ret_t r_rsip_p75f (const uint32_t InData_Cmd[],
                        const uint32_t InData_Msg[],
                        const uint32_t InData_MAC[],
                        const uint32_t InData_length[],
                        uint32_t       MAX_CNT,
                        uint32_t       OutData_MAC[])
{
    RSIP_PRV_PRIMITIVE_ENTRY;
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
    WAIT_STS(REG_2030H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020064U);
    for (iLoop = 0; iLoop < (MAX_CNT & 0xfffffff0U); iLoop = iLoop + 16)
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 1]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 2]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 3]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 4]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 5]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 6]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 7]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 8]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 9]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 10]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 11]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 12]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 13]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 14]);
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 15]);
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT & 0xfffffff0U); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2030H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001600U);
    WAIT_STS(REG_2030H, 4U, 1U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    r_rsip_func100(bswap_32big(0xebba5a62U),
                   bswap_32big(0xfa4e2c8aU),
                   bswap_32big(0x43ad8842U),
                   bswap_32big(0x78ef31feU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0x513bad6eU), bswap_32big(0x410b35f1U), bswap_32big(0xcb3b32eaU),
                       bswap_32big(0x003eea7dU));
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xc87c44d8U), bswap_32big(0x97764761U), bswap_32big(0x4cf0b290U),
                           bswap_32big(0x96f29bf9U));
            WR1_PROG(REG_1408H, 0x00004016U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            r_rsip_func102(bswap_32big(0x66a549d4U), bswap_32big(0xcfdbf9b4U), bswap_32big(0x28f75a4aU),
                           bswap_32big(0x0ffe6c3cU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x3575c150U), bswap_32big(0xe2e832b5U), bswap_32big(0x45cd3027U),
                           bswap_32big(0x5116bd1cU));
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            r_rsip_func102(bswap_32big(0x8d592225U), bswap_32big(0x04e25d71U), bswap_32big(0xd7a3fc7eU),
                           bswap_32big(0xef191a4bU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xa7afa05fU), bswap_32big(0x4d3a9117U), bswap_32big(0x9456a53eU),
                           bswap_32big(0x5bc9c6b3U));
            WR1_PROG(REG_1408H, 0x00004022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            r_rsip_func102(bswap_32big(0x6f48a01fU), bswap_32big(0x7e71a847U), bswap_32big(0xa787aabfU),
                           bswap_32big(0xbcd3b31dU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xc698e651U), bswap_32big(0x4d8e615bU), bswap_32big(0xb3c1a1bbU),
                           bswap_32big(0xd0b974d8U));
            WR1_PROG(REG_1408H, 0x00004032U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            RD1_ADDR(REG_1420H, &OutData_MAC[8]);
            RD1_ADDR(REG_1420H, &OutData_MAC[9]);
            RD1_ADDR(REG_1420H, &OutData_MAC[10]);
            RD1_ADDR(REG_1420H, &OutData_MAC[11]);
            r_rsip_func102(bswap_32big(0xb536e4cdU), bswap_32big(0xf7a36441U), bswap_32big(0xd74fe591U),
                           bswap_32big(0x8e0e410cU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xbe3b7251U), bswap_32big(0xd01de9a2U), bswap_32big(0x64af0e16U),
                           bswap_32big(0x3b2ef3f5U));
            WR1_PROG(REG_1408H, 0x00004042U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            RD1_ADDR(REG_1420H, &OutData_MAC[8]);
            RD1_ADDR(REG_1420H, &OutData_MAC[9]);
            RD1_ADDR(REG_1420H, &OutData_MAC[10]);
            RD1_ADDR(REG_1420H, &OutData_MAC[11]);
            RD1_ADDR(REG_1420H, &OutData_MAC[12]);
            RD1_ADDR(REG_1420H, &OutData_MAC[13]);
            RD1_ADDR(REG_1420H, &OutData_MAC[14]);
            RD1_ADDR(REG_1420H, &OutData_MAC[15]);
            r_rsip_func102(bswap_32big(0xe6059f9fU), bswap_32big(0x405b0e78U), bswap_32big(0x4ed130d1U),
                           bswap_32big(0xe27f4cbfU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xd833bf21U), bswap_32big(0xc5769df3U), bswap_32big(0x67ea36ebU),
                       bswap_32big(0x3819e9c0U));
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x80010020U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_length[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000014U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x9117e0a2U), bswap_32big(0xeba80d9eU), bswap_32big(0x88f69c48U),
                           bswap_32big(0xc6309c53U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xac583252U), bswap_32big(0x65c329ccU), bswap_32big(0x896cbd2fU),
                           bswap_32big(0xafb84d2eU));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x85235012U), bswap_32big(0xe42fe1feU), bswap_32big(0x706f76f2U),
                           bswap_32big(0x380a520bU));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x8462499eU), bswap_32big(0xf7b4c84dU), bswap_32big(0x45278611U),
                           bswap_32big(0x2aae1fefU));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x2320c36cU), bswap_32big(0x9f70304dU), bswap_32big(0x28dea8ebU),
                           bswap_32big(0xa749f5bcU));
        }

        WR1_PROG(REG_1600H, 0x3420a820U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000004U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_1600H, 0x34202841U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x81cf6321U), bswap_32big(0xb2d82237U), bswap_32big(0x07c93c43U),
                       bswap_32big(0xee35bf65U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xb598923cU), bswap_32big(0x5c388e2cU), bswap_32big(0x5aae6f06U),
                           bswap_32big(0xd72bdef5U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x8358a058U), bswap_32big(0x0f2c2756U), bswap_32big(0xaa37faaeU),
                           bswap_32big(0x941f0737U));
            WR1_PROG(REG_1600H, 0x000008c6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000008a5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000a440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00046842U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c42U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x81010040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = 0; iLoop < S_RAM[0]; iLoop = iLoop + 4)
            {
                r_rsip_func100(bswap_32big(0x7c267459U),
                               bswap_32big(0xaf8e9109U),
                               bswap_32big(0xb65e53f1U),
                               bswap_32big(0x65cc9e07U));
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00003464U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x3420a880U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000003U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x380088c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000b460U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000002U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c03U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80810007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03450005U);
                    WR1_PROG(REG_1444H, 0x000000c1U);
                    WR1_PROG(REG_1824H, 0x08000044U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    r_rsip_func101(bswap_32big(0x5a67baeeU),
                                   bswap_32big(0xe1365328U),
                                   bswap_32big(0xb77261b1U),
                                   bswap_32big(0x6c6fc75bU));
                }
                else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x0345000dU);
                    WR1_PROG(REG_1444H, 0x000002c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_func101(bswap_32big(0x62dd077cU),
                                   bswap_32big(0x1deaf5beU),
                                   bswap_32big(0xcd8ce2fdU),
                                   bswap_32big(0x39fd1b1eU));
                }
                else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03450011U);
                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 3]);
                    r_rsip_func101(bswap_32big(0x62950fb7U),
                                   bswap_32big(0x38cfc598U),
                                   bswap_32big(0x1902820cU),
                                   bswap_32big(0x62de5d39U));
                }

                WR1_PROG(REG_1600H, 0x00000800U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (jLoop = 0; jLoop < 16; jLoop = jLoop + 1)
                {
                    WR1_PROG(REG_1600H, 0x3c0028a1U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x12003c07U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ce0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002ca0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                }

                WR1_PROG(REG_1824H, 0x9c000005U);
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81840007U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x00490011U);
                WR1_PROG(REG_1600H, 0x0000a4c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x9d6384f8U),
                               bswap_32big(0xd72e6aa6U),
                               bswap_32big(0x1b7e3a65U),
                               bswap_32big(0xb71f4c14U));
            }

            WR1_PROG(REG_1600H, 0x000008c2U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c06U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x94428a98U), bswap_32big(0x2131fd15U), bswap_32big(0xa0f3949aU),
                           bswap_32big(0xeefb212bU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xa041350fU),
                               bswap_32big(0x8b6ac50aU),
                               bswap_32big(0x31318a11U),
                               bswap_32big(0xbf1eca0aU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func102(bswap_32big(0x9f00c12bU),
                               bswap_32big(0xdec4ba05U),
                               bswap_32big(0x82c3c926U),
                               bswap_32big(0xbd185bf6U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
