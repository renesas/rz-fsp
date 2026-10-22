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

rsip_ret_t r_rsip_pf5 (const uint32_t InData_CurveType[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_MsgDgst[],
                       const uint32_t InData_DomainParam[],
                       uint32_t       OutData_Signature[])
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
    if (0x0U != RD1_MASK(REG_14B8H, 0x1eU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00f50002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1000H, 0x00010000U);
    WR1_PROG(REG_1024H, 0x000007f0U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010340U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_CurveType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_subfunc009(bswap_32big(0x000000f5U));
    r_rsip_func101(bswap_32big(0x20813ce1U),
                   bswap_32big(0x99a7a193U),
                   bswap_32big(0x28fe002fU),
                   bswap_32big(0xb6cce78aU));
    r_rsip_func027(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x8e397fd7U),
                   bswap_32big(0x4247a690U),
                   bswap_32big(0x2138a3fcU),
                   bswap_32big(0x1365c7f0U));
    WR1_PROG(REG_1404H, 0x11300000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000410U, 0x0606000aU);
    r_rsip_subfunc006(0x00000020U, 0x00000410U, 0x06060010U);
    r_rsip_subfunc006(0x00000018U, 0x00000070U, 0x06060010U);
    WR1_PROG(REG_1404H, 0x10e00000U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xe2f4f981U),
                   bswap_32big(0xe3cc0743U),
                   bswap_32big(0xccf55464U),
                   bswap_32big(0x23d597efU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0x16035ddfU),
                   bswap_32big(0xccd639f2U),
                   bswap_32big(0x0317bf63U),
                   bswap_32big(0x97057e5fU));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    WR1_PROG(REG_1014H, 0x00000110U);
    WR1_PROG(REG_101CH, 0x00000410U);
    WR1_PROG(REG_1020H, 0x00000160U);
    WR1_PROG(REG_1010H, 0x00000020U);
    WR1_PROG(REG_1004H, 0x06060004U);
    WR1_PROG(REG_1000H, 0x00010001U);
    WAIT_STS(REG_1000H, 0U, 0U);
    WR1_PROG(REG_1404H, 0x14180000U);
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x08000104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
    r_rsip_subfunc003(0x00c0002dU);
    r_rsip_subfunc003(0x00c20005U);
    r_rsip_subfunc003(0x0002000dU);
    r_rsip_subfunc001(0x00000160U, 0x00000448U, 0x00000340U, 0x06060009U);
    r_rsip_subfunc006(0x00000020U, 0x000000c0U, 0x06060010U);
    r_rsip_subfunc009(bswap_32big(0x000000f5U));
    r_rsip_func101(bswap_32big(0x5638b6c2U),
                   bswap_32big(0x1e011530U),
                   bswap_32big(0x33351967U),
                   bswap_32big(0x2e7ec757U));
    r_rsip_func028(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x000000f5U));
    r_rsip_func101(bswap_32big(0x2d4b6d7fU),
                   bswap_32big(0xd7de6021U),
                   bswap_32big(0x4a7a856aU),
                   bswap_32big(0x8a165e8cU));
    r_rsip_func089();
    r_rsip_func100(bswap_32big(0x6ffd0a0fU),
                   bswap_32big(0x4d906bddU),
                   bswap_32big(0xa91bf0baU),
                   bswap_32big(0x5c9849c1U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xa53110d9U), bswap_32big(0x61732f13U), bswap_32big(0x43498fe9U),
                       bswap_32big(0x27e0a9b0U));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1014H, 0x000002a0U);
        WR1_PROG(REG_1018H, 0x00000840U);
        WR1_PROG(REG_101CH, 0x000000c0U);
        WR1_PROG(REG_1020H, 0x000002f0U);
        WR1_PROG(REG_1010H, 0x00000020U);
        WR1_PROG(REG_1004H, 0x06060002U);
        WR1_PROG(REG_1000H, 0x00010001U);
        WAIT_STS(REG_1000H, 0U, 0U);
        WR1_PROG(REG_1014H, 0x000002f0U);
        r_rsip_subfunc002(0x000000c0U, 0x000002a0U, 0x06060004U);
        WR1_PROG(REG_1404H, 0x10e00000U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
        r_rsip_subfunc003(0x00c0002dU);
        r_rsip_subfunc003(0x00c20005U);
        r_rsip_subfunc003(0x0002000dU);
        r_rsip_subfunc001(0x000002a0U, 0x00000110U, 0x00000140U, 0x0606000aU);
        WR1_PROG(REG_143CH, 0x00210000U);
        r_rsip_func100(bswap_32big(0x89a16171U), bswap_32big(0x2c499928U), bswap_32big(0xf73b6ef9U),
                       bswap_32big(0x7421c72fU));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x316d4bb4U), bswap_32big(0x0a0d0150U), bswap_32big(0x1a9364c1U),
                           bswap_32big(0xacdcaf19U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x1e2232cfU), bswap_32big(0x13782673U), bswap_32big(0xed6a3918U),
                           bswap_32big(0x7c185724U));
            WR1_PROG(REG_1404H, 0x11300000U);
            WR1_PROG(REG_1444H, 0x000000a2U);
            WR1_PROG(REG_1A24H, 0x08000104U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000002U));
            r_rsip_subfunc003(0x00c0002dU);
            r_rsip_subfunc003(0x00c20005U);
            r_rsip_subfunc003(0x0002000dU);
            r_rsip_subfunc001(0x000000c0U, 0x00000160U, 0x00000110U, 0x0606000aU);
            r_rsip_subfunc005(0x00000340U, 0x00000110U, 0x000000c0U, 0x00000160U, 0x0606000fU, 0x00020000U);
            WR1_PROG(REG_143CH, 0x00000d00U);
            WR1_PROG(REG_1014H, 0x00000160U);
            WR1_PROG(REG_1018H, 0x00000840U);
            r_rsip_subfunc002(0x000000c0U, 0x00000110U, 0x06060002U);
            WR1_PROG(REG_1444H, 0x00000bc2U);
            WR1_PROG(REG_1A2CH, 0x00000200U);
            WR1_PROG(REG_1A24H, 0x08008107U);
            WR1_PROG(REG_1404H, 0x11300000U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 0]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 1]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 2]);
                WR1_ADDR(REG_1420H, &InData_MsgDgst[iLoop + 3]);
                r_rsip_subfunc003(0x00c20011U);
            }

            WR1_PROG(REG_1444H, 0x000003c7U);
            WR1_PROG(REG_1608H, 0x80040000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[2]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[3]);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x000000f5U));
            r_rsip_func101(bswap_32big(0x4e862a38U), bswap_32big(0xcf4ff0fbU), bswap_32big(0xb158ba33U),
                           bswap_32big(0xe94b03d4U));
            r_rsip_func045();
            r_rsip_func076();
            r_rsip_subfunc009(bswap_32big(0x000000f5U));
            r_rsip_func101(bswap_32big(0xd614e0fdU), bswap_32big(0x04d6c670U), bswap_32big(0x4aa27908U),
                           bswap_32big(0x0a02cf59U));
            r_rsip_func046();
            WR1_PROG(REG_1444H, 0x00000bc2U);
            WR1_PROG(REG_1A2CH, 0x40000200U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            for (iLoop = 0; iLoop < 12; iLoop = iLoop + 4)
            {
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
                WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
            }

            WR1_PROG(REG_1404H, 0x11d00000U);
            r_rsip_subfunc003(0x00c20031U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[iLoop + 7]);
            WR1_PROG(REG_1A24H, 0x9c100005U);
            r_rsip_subfunc003(0x00820011U);
            r_rsip_func100(bswap_32big(0xf7cc5c82U), bswap_32big(0xd34663daU), bswap_32big(0xea459d25U),
                           bswap_32big(0x3b8beef7U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x99e67a5aU),
                               bswap_32big(0x00b609cbU),
                               bswap_32big(0x1f78e974U),
                               bswap_32big(0xc97f4ab2U));
                WR1_PROG(REG_14B8H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_KEY_FAIL;
            }
            else
            {
                WR1_PROG(REG_1014H, 0x00000200U);
                WR1_PROG(REG_1018H, 0x00000840U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x06060002U);
                WR1_PROG(REG_1014H, 0x000001b0U);
                WR1_PROG(REG_1018H, 0x000002a0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x06060002U);
                WR1_PROG(REG_1014H, 0x00000160U);
                WR1_PROG(REG_1018H, 0x00000200U);
                r_rsip_subfunc002(0x000000c0U, 0x000001b0U, 0x06060005U);
                WR1_PROG(REG_1014H, 0x00000110U);
                WR1_PROG(REG_1018H, 0x000001b0U);
                r_rsip_subfunc002(0x000000c0U, 0x00000200U, 0x06060002U);
                WR1_PROG(REG_1404H, 0x10e00000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000001U));
                r_rsip_subfunc003(0x00c0002dU);
                r_rsip_subfunc003(0x00c20005U);
                r_rsip_subfunc003(0x0002000dU);
                r_rsip_subfunc001(0x00000200U, 0x00000110U, 0x00000140U, 0x0606000aU);
                WR1_PROG(REG_143CH, 0x00210000U);
                r_rsip_func100(bswap_32big(0x400b8c52U),
                               bswap_32big(0xb8ccc507U),
                               bswap_32big(0xddf3e822U),
                               bswap_32big(0x5a7f752aU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0xc9cc303dU),
                                   bswap_32big(0xe9bda313U),
                                   bswap_32big(0x822cb804U),
                                   bswap_32big(0xd32b17f3U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xdd344686U),
                                   bswap_32big(0x3481b96aU),
                                   bswap_32big(0x2f3ecbebU),
                                   bswap_32big(0x8f137472U));
                    WR1_PROG(REG_1404H, 0x12700000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[0]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[1]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[2]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[3]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[4]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[5]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[6]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[7]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[8]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[9]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[10]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[11]);
                    r_rsip_func100(bswap_32big(0xd724d86cU),
                                   bswap_32big(0xe4a3edfbU),
                                   bswap_32big(0x848f94d6U),
                                   bswap_32big(0x22fef8e6U));
                    WR1_PROG(REG_1404H, 0x11d00000U);
                    WR1_PROG(REG_1A2CH, 0x00000200U);
                    WR1_PROG(REG_1A24H, 0x08008107U);
                    r_rsip_subfunc003(0x00830031U);
                    WR1_PROG(REG_1408H, 0x00002032U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[12]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[13]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[14]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[15]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[16]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[17]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[18]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[19]);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_Signature[20]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[21]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[22]);
                    RD1_ADDR(REG_1420H, &OutData_Signature[23]);
                    r_rsip_func102(bswap_32big(0xd50cefbeU),
                                   bswap_32big(0xbe20db9aU),
                                   bswap_32big(0x81da56ebU),
                                   bswap_32big(0x3309752cU));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
