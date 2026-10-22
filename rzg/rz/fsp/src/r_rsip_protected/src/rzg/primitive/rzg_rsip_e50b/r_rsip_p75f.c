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
    r_rsip_func100(bswap_32big(0x4da35a19U),
                   bswap_32big(0xcd507b0cU),
                   bswap_32big(0x8f4b0981U),
                   bswap_32big(0x911099e1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func100(bswap_32big(0xe02412caU), bswap_32big(0x1538083bU), bswap_32big(0xd8bc5dc0U),
                       bswap_32big(0x9ec4559aU));
        WR1_PROG(REG_1600H, 0x00007c04U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_143CH, 0x00600000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x06321632U), bswap_32big(0x0969fb32U), bswap_32big(0x0426a50aU),
                           bswap_32big(0xddeaeb8fU));
            WR1_PROG(REG_1408H, 0x00004016U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            r_rsip_func102(bswap_32big(0x835417b9U), bswap_32big(0xa230b6beU), bswap_32big(0x87e20ea2U),
                           bswap_32big(0xd41ae610U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x54a683e5U), bswap_32big(0x7869c986U), bswap_32big(0xd81b0218U),
                           bswap_32big(0xdc2070fbU));
            WR1_PROG(REG_1408H, 0x0000401eU);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &OutData_MAC[0]);
            RD1_ADDR(REG_1420H, &OutData_MAC[1]);
            RD1_ADDR(REG_1420H, &OutData_MAC[2]);
            RD1_ADDR(REG_1420H, &OutData_MAC[3]);
            RD1_ADDR(REG_1420H, &OutData_MAC[4]);
            RD1_ADDR(REG_1420H, &OutData_MAC[5]);
            RD1_ADDR(REG_1420H, &OutData_MAC[6]);
            r_rsip_func102(bswap_32big(0xfbfd61faU), bswap_32big(0x3650108fU), bswap_32big(0x055bb52cU),
                           bswap_32big(0x943cc4e7U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x7b646fbcU), bswap_32big(0x9b3d4e0eU), bswap_32big(0xfbe92c55U),
                           bswap_32big(0x80f9545bU));
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
            r_rsip_func102(bswap_32big(0x04d2a2ccU), bswap_32big(0xab1efd47U), bswap_32big(0x689719b1U),
                           bswap_32big(0x27b6e957U));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x8f4f9484U), bswap_32big(0xb5f09e30U), bswap_32big(0x6e0126fdU),
                           bswap_32big(0xc06adabbU));
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
            r_rsip_func102(bswap_32big(0xa4022e50U), bswap_32big(0xcc50a882U), bswap_32big(0x43a03814U),
                           bswap_32big(0x70f092bcU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            r_rsip_func100(bswap_32big(0x0d784ab0U), bswap_32big(0x7f28f42eU), bswap_32big(0xc1dadc81U),
                           bswap_32big(0x7078d8d1U));
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
            r_rsip_func102(bswap_32big(0x5e6c8ff4U), bswap_32big(0x216ade7eU), bswap_32big(0xac492b07U),
                           bswap_32big(0x470a3effU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);
        }

        return RSIP_RET_PASS;
    }
    else
    {
        r_rsip_func100(bswap_32big(0xe23c3f9bU), bswap_32big(0xd4e70a43U), bswap_32big(0x2f3e920bU),
                       bswap_32big(0xbca18a79U));
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
            r_rsip_func101(bswap_32big(0xb0c3879fU), bswap_32big(0x6d715f7cU), bswap_32big(0xf6f8ce8eU),
                           bswap_32big(0x2cb28596U));
        }
        else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000001cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x6b7735a5U), bswap_32big(0xe0306867U), bswap_32big(0x53be6774U),
                           bswap_32big(0x20ae970dU));
        }
        else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000020U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x938d46d1U), bswap_32big(0x992ae211U), bswap_32big(0x2115089eU),
                           bswap_32big(0x635da365U));
        }
        else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000030U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x843383d8U), bswap_32big(0x55927b16U), bswap_32big(0x8c156c74U),
                           bswap_32big(0x839ccdceU));
        }
        else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
        {
            WR1_PROG(REG_1600H, 0x0000b440U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000040U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0xf76d3261U), bswap_32big(0x3cbc96a8U), bswap_32big(0x74616e46U),
                           bswap_32big(0x1789681eU));
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
        r_rsip_func100(bswap_32big(0x4db2f572U), bswap_32big(0x57d3da58U), bswap_32big(0x8f572f99U),
                       bswap_32big(0x9cb72937U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x0d746197U), bswap_32big(0xd043ff1dU), bswap_32big(0xbf21fa49U),
                           bswap_32big(0xec604e6fU));
            WR1_PROG(REG_14BCH, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x76e90638U), bswap_32big(0x4650a432U), bswap_32big(0xfa8e9784U),
                           bswap_32big(0x6e7df658U));
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
                r_rsip_func100(bswap_32big(0x219942a3U),
                               bswap_32big(0x36e28d84U),
                               bswap_32big(0xf0ee1954U),
                               bswap_32big(0x12a24281U));
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
                    r_rsip_func101(bswap_32big(0x9f4df5dfU),
                                   bswap_32big(0xe6810bcdU),
                                   bswap_32big(0x04a2f739U),
                                   bswap_32big(0x86a16dcdU));
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
                    r_rsip_func101(bswap_32big(0xdd0e2aceU),
                                   bswap_32big(0x8fbaa636U),
                                   bswap_32big(0x49fb157aU),
                                   bswap_32big(0xb7fb817dU));
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
                    r_rsip_func101(bswap_32big(0x8a9dc93dU),
                                   bswap_32big(0xa1c25112U),
                                   bswap_32big(0x5413e122U),
                                   bswap_32big(0x7a04c9f7U));
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
                r_rsip_func101(bswap_32big(0x2f9db0b8U),
                               bswap_32big(0x42f8230fU),
                               bswap_32big(0xf7d75d97U),
                               bswap_32big(0xdada6054U));
            }

            WR1_PROG(REG_1600H, 0x000008c2U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00007c06U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_143CH, 0x00602000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func100(bswap_32big(0x0d5d46e6U), bswap_32big(0x3cebc60fU), bswap_32big(0x63571343U),
                           bswap_32big(0x32c7f671U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0xae1c1b09U),
                               bswap_32big(0xcab3bee4U),
                               bswap_32big(0xbfe98a97U),
                               bswap_32big(0x44cc4e9fU));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func102(bswap_32big(0x0c3d92a9U),
                               bswap_32big(0xe0d27ea0U),
                               bswap_32big(0x06260dbeU),
                               bswap_32big(0xb27e38c6U));
                WR1_PROG(REG_14BCH, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
