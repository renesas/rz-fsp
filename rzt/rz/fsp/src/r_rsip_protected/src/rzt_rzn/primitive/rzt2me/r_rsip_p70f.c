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

rsip_ret_t r_rsip_p70f (const uint32_t InData_Msg[], uint32_t MAX_CNT, uint32_t OutData_MsgDigest[])
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
    r_rsip_func100(bswap_32big(0x1b7a61b3U),
                   bswap_32big(0x1b72cd95U),
                   bswap_32big(0xe271635aU),
                   bswap_32big(0xacf8e89bU));
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000004U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x1000b400U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00007c00U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x29b146b0U), bswap_32big(0xedfa798aU), bswap_32big(0x606ef203U),
                       bswap_32big(0x303cca8eU));
        WR1_PROG(REG_1408H, 0x00004016U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        r_rsip_func102(bswap_32big(0x14133f81U), bswap_32big(0x06755983U), bswap_32big(0x9092d322U),
                       bswap_32big(0xd265bf56U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x6fcc0c7bU), bswap_32big(0x3d15327bU), bswap_32big(0x71591fbaU),
                       bswap_32big(0xa2180e8fU));
        WR1_PROG(REG_1408H, 0x0000401eU);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        r_rsip_func102(bswap_32big(0xfb5b375dU), bswap_32big(0x856dbd41U), bswap_32big(0x7a0b2d64U),
                       bswap_32big(0x66882265U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x6c4e2069U), bswap_32big(0xace71faeU), bswap_32big(0x70f89c71U),
                       bswap_32big(0x6ff038eeU));
        WR1_PROG(REG_1408H, 0x00004022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        r_rsip_func102(bswap_32big(0x1828ad6eU), bswap_32big(0xaf055b3dU), bswap_32big(0x7f161f9aU),
                       bswap_32big(0xd18347d0U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000005U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0xb2f09a78U), bswap_32big(0x1b0ea3a5U), bswap_32big(0xb5475806U),
                       bswap_32big(0x8a0fff49U));
        WR1_PROG(REG_1408H, 0x00004032U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        r_rsip_func102(bswap_32big(0x0a4806a7U), bswap_32big(0xe9648003U), bswap_32big(0x2f4eee34U),
                       bswap_32big(0xb507172bU));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }
    else if (0x00000006U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        r_rsip_func100(bswap_32big(0x97f29707U), bswap_32big(0x2810399fU), bswap_32big(0x538e0701U),
                       bswap_32big(0x63b1501fU));
        WR1_PROG(REG_1408H, 0x00004042U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[0]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[1]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[2]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[3]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[4]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[5]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[6]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[7]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[8]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[9]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[10]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[11]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[12]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[13]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[14]);
        RD1_ADDR(REG_1420H, &OutData_MsgDigest[15]);
        r_rsip_func102(bswap_32big(0x92d2357fU), bswap_32big(0x559bdcb3U), bswap_32big(0xa82736bbU),
                       bswap_32big(0x66990959U));
        WR1_PROG(REG_14BCH, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);
    }

    return RSIP_RET_PASS;
}
