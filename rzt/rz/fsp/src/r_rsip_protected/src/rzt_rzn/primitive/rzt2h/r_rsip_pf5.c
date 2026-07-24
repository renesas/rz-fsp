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
    r_rsip_func101(bswap_32big(0x05b8f05fU),
                   bswap_32big(0xaec98a82U),
                   bswap_32big(0x3d506087U),
                   bswap_32big(0x01898146U));
    r_rsip_func027(InData_DomainParam);
    r_rsip_func100(bswap_32big(0x646433b3U),
                   bswap_32big(0xa002f907U),
                   bswap_32big(0x7c44d684U),
                   bswap_32big(0x1952002aU));
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
    r_rsip_func100(bswap_32big(0xa8e0742aU),
                   bswap_32big(0x2354b5b7U),
                   bswap_32big(0xd2a8a4fcU),
                   bswap_32big(0x931e3361U));
    WR1_PROG(REG_1444H, 0x000000a2U);
    WR1_PROG(REG_1A24H, 0x0c200104U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
    r_rsip_subfunc003(0x00c20011U);
    r_rsip_func103();
    r_rsip_func100(bswap_32big(0xf3ce7666U),
                   bswap_32big(0x1dd6c360U),
                   bswap_32big(0xd8f147aaU),
                   bswap_32big(0xc74078e9U));
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
    r_rsip_func101(bswap_32big(0xd902416bU),
                   bswap_32big(0xc5494769U),
                   bswap_32big(0x1599c8cbU),
                   bswap_32big(0xeb2817baU));
    r_rsip_func028(InData_DomainParam);
    r_rsip_subfunc009(bswap_32big(0x000000f5U));
    r_rsip_func101(bswap_32big(0x32f884b5U),
                   bswap_32big(0x0b896b4aU),
                   bswap_32big(0x0a61e99cU),
                   bswap_32big(0xc2aa30b5U));
    r_rsip_func089();
    r_rsip_func100(bswap_32big(0x94d37aa2U),
                   bswap_32big(0x0444229eU),
                   bswap_32big(0x3daf9d60U),
                   bswap_32big(0x3ab205a2U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0x25a1d6e7U), bswap_32big(0x97635805U), bswap_32big(0xf8c53845U),
                       bswap_32big(0x1784a024U));
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
        r_rsip_func100(bswap_32big(0x335eb7c6U), bswap_32big(0x5c185428U), bswap_32big(0x34b8fd2dU),
                       bswap_32big(0x4c4e96d8U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0xd6062990U), bswap_32big(0xbb1c0a8aU), bswap_32big(0xc342e38eU),
                           bswap_32big(0x325c4d26U));
            WR1_PROG(REG_14B8H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_FAIL;
        }
        else
        {
            r_rsip_func100(bswap_32big(0x27f315a9U), bswap_32big(0x9bd10a03U), bswap_32big(0xd9ccc4dbU),
                           bswap_32big(0xfdd7b555U));
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
            r_rsip_func101(bswap_32big(0x87c47210U), bswap_32big(0xf46cbd49U), bswap_32big(0x2a4fa016U),
                           bswap_32big(0x4d55fb0aU));
            r_rsip_func045();
            r_rsip_func076();
            r_rsip_subfunc009(bswap_32big(0x000000f5U));
            r_rsip_func101(bswap_32big(0x929f3a26U), bswap_32big(0x39101306U), bswap_32big(0xb06d7a06U),
                           bswap_32big(0xed854145U));
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
            r_rsip_func100(bswap_32big(0xf81f0a8bU), bswap_32big(0x5571f2c1U), bswap_32big(0x82aaae6eU),
                           bswap_32big(0x1957599dU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x5e614c14U),
                               bswap_32big(0x073b14bcU),
                               bswap_32big(0x655d6e81U),
                               bswap_32big(0x08647201U));
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
                r_rsip_func100(bswap_32big(0x3ed81a85U),
                               bswap_32big(0x0b89bdf8U),
                               bswap_32big(0x320535beU),
                               bswap_32big(0x1b4ac32eU));
                WR1_PROG(REG_143CH, 0x00400000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                if (CHCK_STS(REG_143CH, 22U, 1U))
                {
                    r_rsip_func102(bswap_32big(0x90e0e20bU),
                                   bswap_32big(0x2a7b1b07U),
                                   bswap_32big(0x434e9876U),
                                   bswap_32big(0xe6f53243U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_FAIL;
                }
                else
                {
                    r_rsip_func100(bswap_32big(0xace0c2b9U),
                                   bswap_32big(0x3c867152U),
                                   bswap_32big(0xc03cb31dU),
                                   bswap_32big(0x33106cbbU));
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
                    r_rsip_func100(bswap_32big(0x3ccf71e1U),
                                   bswap_32big(0xb084ff90U),
                                   bswap_32big(0xebf8ed22U),
                                   bswap_32big(0xf266e333U));
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
                    r_rsip_func102(bswap_32big(0x856d6e85U),
                                   bswap_32big(0xd22ec476U),
                                   bswap_32big(0x28d89d0aU),
                                   bswap_32big(0xeb127ee3U));
                    WR1_PROG(REG_14B8H, 0x00000040U);
                    WAIT_STS(REG_142CH, 12U, 0U);

                    return RSIP_RET_PASS;
                }
            }
        }
    }
}
