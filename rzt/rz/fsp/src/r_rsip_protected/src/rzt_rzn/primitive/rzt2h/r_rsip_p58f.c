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

rsip_ret_t r_rsip_p58f (const uint32_t InData_Cmd[],
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
    WAIT_STS(REG_2440H, 0U, 1U);
    WR1_PROG(REG_1444H, 0x00020065U);
    for (iLoop = 0; iLoop < (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop = iLoop + S_RAM[0])
    {
        WAIT_STS(REG_1444H, 31U, 1U);
        for (jLoop = 0; jLoop < S_RAM[0]; jLoop = jLoop + 2)
        {
            WR1_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop + 0]);
            WR1_ADDR(REG_1420H, &InData_Msg[iLoop + jLoop + 1]);
        }
    }

    WAIT_STS(REG_1444H, 31U, 1U);
    for (iLoop = (MAX_CNT - MAX_CNT % S_RAM[0]); iLoop < MAX_CNT; iLoop = iLoop + 1)
    {
        WR1_ADDR(REG_1420H, &InData_Msg[iLoop + 0]);
    }

    WR1_PROG(REG_1444H, 0x00000000U);
    WAIT_STS(REG_2440H, 8U, 0U);
    WR1_PROG(REG_143CH, 0x00001400U);
    WAIT_STS(REG_2440H, 4U, 1U);
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
    r_rsip_func100(bswap_32big(0x12e8d3cfU),
                   bswap_32big(0x57800ca2U),
                   bswap_32big(0x8b56e138U),
                   bswap_32big(0x350fa7d9U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0x4eba9d1dU), bswap_32big(0xc19cba87U), bswap_32big(0x74b236d9U),
                       bswap_32big(0x8b0f5362U));
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xdf3016fcU), bswap_32big(0xf385bb3bU), bswap_32big(0x4d54f17dU),
                           bswap_32big(0x16df493bU));
            WR1_PROG(REG_1408H, 0x0000601eU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            r_rsip_func102(bswap_32big(0xbe8a4d72U), bswap_32big(0x5264f27dU), bswap_32big(0xb32f0f24U),
                           bswap_32big(0x558e9a04U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0xddf33caaU), bswap_32big(0xf60ab605U), bswap_32big(0x66e92681U),
                           bswap_32big(0xa0a40578U));
            WR1_PROG(REG_1408H, 0x00006022U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            RD1_ADDR(REG_1420H, &OutData_MAC[7]);
            r_rsip_func102(bswap_32big(0xdd6b4172U), bswap_32big(0xea3fd710U), bswap_32big(0x21e92254U),
                           bswap_32big(0x183f0f5cU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x4853ddf8U), bswap_32big(0x1bfb454aU), bswap_32big(0x40556bccU),
                           bswap_32big(0x05d183aaU));
            WR1_PROG(REG_1408H, 0x00006032U);
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
            r_rsip_func102(bswap_32big(0xd9f4c9f0U), bswap_32big(0xf3e5b9edU), bswap_32big(0x23ef851bU),
                           bswap_32big(0xd41080a6U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x99024c11U), bswap_32big(0x335b01ddU), bswap_32big(0xe4335f9eU),
                           bswap_32big(0x16426a5fU));
            WR1_PROG(REG_1408H, 0x00006042U);
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
            r_rsip_func102(bswap_32big(0xbc51e246U), bswap_32big(0x91861118U), bswap_32big(0x647ef2bcU),
                           bswap_32big(0xd186c5aeU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func100(bswap_32big(0x443d87cbU), bswap_32big(0x203566afU), bswap_32big(0x91378553U),
                       bswap_32big(0xccf13c65U));
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
            WR1_PROG(REG_1600H, 0x0000001cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x0bc4c66fU), bswap_32big(0x8de8553eU), bswap_32big(0x997f9263U),
                           bswap_32big(0xbfd7844dU));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xc449dd06U), bswap_32big(0x12bb09b3U), bswap_32big(0xa09da518U),
                           bswap_32big(0x8a11223eU));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xd2408477U), bswap_32big(0x4142bb1aU), bswap_32big(0x25fab5a5U),
                           bswap_32big(0x5b7f8f82U));
        }
        else if (0x00000003U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x3d97fafbU), bswap_32big(0x9bae3ce3U), bswap_32big(0x80a4f6ebU),
                           bswap_32big(0x262dce4cU));
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
        r_rsip_func100(bswap_32big(0x99cd5283U), bswap_32big(0x3760c46cU), bswap_32big(0x2abc1262U),
                       bswap_32big(0x24734be0U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x4b8fa759U), bswap_32big(0x7b9fe1eaU), bswap_32big(0xec9a8e9cU),
                           bswap_32big(0xe2728f12U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x19415babU), bswap_32big(0x13b12f49U), bswap_32big(0xea6e8b43U),
                           bswap_32big(0x994688b0U));
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
                r_rsip_func100(bswap_32big(0xd1621188U),
                               bswap_32big(0xc76dff8fU),
                               bswap_32big(0x8aee6b00U),
                               bswap_32big(0x4af73d43U));
                WR1_PROG(REG_1600H, 0x000008e7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000863U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x380088c0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d060U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000c84U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x2000d060U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00007c03U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_143CH, 0x00600000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
                {
                    WR1_PROG(REG_1608H, 0x80830007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x0346000dU);
                    WR1_PROG(REG_1444H, 0x000002c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_PROG(REG_1444H, 0x000000a1U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                    r_rsip_func101(bswap_32big(0xadbfe51cU),
                                   bswap_32big(0x4207f13aU),
                                   bswap_32big(0x10184b2fU),
                                   bswap_32big(0xd9074ceeU));
                }
                else
                {
                    WR1_PROG(REG_1608H, 0x80840007U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03460011U);
                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0x08000045U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &InData_MAC[iLoop + 3]);
                    r_rsip_func101(bswap_32big(0xb0d46e3bU),
                                   bswap_32big(0x7ec07976U),
                                   bswap_32big(0x2a87aa91U),
                                   bswap_32big(0xaeb31b66U));
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
                r_rsip_func101(bswap_32big(0x7633a46bU),
                               bswap_32big(0xea9e7e2aU),
                               bswap_32big(0x239257d8U),
                               bswap_32big(0x83976f37U));
            }

            WR1_PROG(REG_1600H, 0x000008c2U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c06U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0xa18c5410U), bswap_32big(0x0770d812U), bswap_32big(0xdc8d730eU),
                           bswap_32big(0xa8153575U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xa02a34b0U),
                               bswap_32big(0xbceda8f4U),
                               bswap_32big(0xd9c38010U),
                               bswap_32big(0x6420b08fU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func102(bswap_32big(0xd8b01d8cU),
                               bswap_32big(0x56c11aa6U),
                               bswap_32big(0x824b697dU),
                               bswap_32big(0xfdc76e4dU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
