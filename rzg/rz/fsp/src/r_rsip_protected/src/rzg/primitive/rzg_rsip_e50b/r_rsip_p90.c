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

rsip_ret_t r_rsip_p90 (const uint32_t InData_Cmd[],
                       const uint32_t InData_KeyIndex[],
                       const uint32_t InData_WrappedKeyType[],
                       const uint32_t InData_Text[],
                       uint32_t       OutData_KeyIndex[],
                       uint32_t       WRAPPED_KEY_SIZE,
                       uint32_t       KEY_INDEX_SIZE)
{
    RSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    int32_t  jLoop;
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
    if (0x0U != RD1_MASK(REG_14B4H, 0x1dU))
    {
        return RSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_1B00H, 0x00900002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000001c7U);
    WR1_PROG(REG_1608H, 0x80020100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_Cmd[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_WrappedKeyType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00003409U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a900U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    WR1_PROG(REG_1600H, 0x38008800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000001U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00260000U);
    WR1_PROG(REG_1600H, 0x3420a800U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0xb2ff6cf3U),
                   bswap_32big(0x940fe7e4U),
                   bswap_32big(0xb9dd91f0U),
                   bswap_32big(0x9ff9e89aU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xd5f1bf16U), bswap_32big(0x9730ca29U), bswap_32big(0x624e7b5eU),
                       bswap_32big(0x2b9d19d5U));
        WR1_PROG(REG_14B4H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
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
        r_rsip_subfunc009(bswap_32big(0x00009001U));
        r_rsip_func101(bswap_32big(0xad748aa5U), bswap_32big(0xe9158724U), bswap_32big(0x6409271bU),
                       bswap_32big(0x53151f03U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x38000d08U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x1860ad35U), bswap_32big(0x681eea85U), bswap_32big(0x03f7889bU),
                       bswap_32big(0xfd610626U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x01379ba9U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00009001U));
            r_rsip_func101(bswap_32big(0x2ac310e5U), bswap_32big(0x75e67cfdU), bswap_32big(0xbde2f587U),
                           bswap_32big(0xf9b98b2fU));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x68c31242U), bswap_32big(0x3f62ff9dU), bswap_32big(0x4b6dde08U),
                           bswap_32big(0x94e4f5f4U));
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7009d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_subfunc003(0x00420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
            WR1_PROG(REG_182CH, 0x00000000U);
            r_rsip_func101(bswap_32big(0x04ed490fU), bswap_32big(0x24c77cc4U), bswap_32big(0x994c4b34U),
                           bswap_32big(0x690ce642U));
        }
        else
        {
            WR1_PROG(REG_1600H, 0x0000b4e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x014e8006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_subfunc009(bswap_32big(0x00009002U));
            r_rsip_func101(bswap_32big(0x04a2d407U), bswap_32big(0xac464b43U), bswap_32big(0x3ddf6f9aU),
                           bswap_32big(0x2ec60038U));
            r_rsip_func046();
            r_rsip_func100(bswap_32big(0x3239d759U), bswap_32big(0x51cd169bU), bswap_32big(0xaee61c64U),
                           bswap_32big(0x084f8f87U));
            WR1_PROG(REG_1444H, 0x000007c2U);
            WR1_PROG(REG_1A2CH, 0x40000100U);
            WR1_PROG(REG_1A24H, 0xf7009d07U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[4]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[5]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[6]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[7]);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[8]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[9]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[10]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[11]);
            WR1_PROG(REG_1824H, 0x08000085U);
            r_rsip_subfunc003(0x00420011U);
            r_rsip_func100(bswap_32big(0xf6392d75U), bswap_32big(0x79d0d5e1U), bswap_32big(0xbb96d4f4U),
                           bswap_32big(0x50444ee3U));
            WR1_PROG(REG_1824H, 0x08000095U);
            r_rsip_subfunc003(0x00420011U);
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0x07008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[12]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[13]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[14]);
            WR1_ADDR(REG_1420H, &InData_KeyIndex[15]);
            WR1_PROG(REG_182CH, 0x40000000U);
            r_rsip_func101(bswap_32big(0xe0dda83eU), bswap_32big(0x9c6c22f8U), bswap_32big(0xccd7229bU),
                           bswap_32big(0xa3fd097dU));
        }

        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0xcaeb286cU), bswap_32big(0xd70f9e98U), bswap_32big(0xb37ad1ffU),
                       bswap_32big(0x6f76edb4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func102(bswap_32big(0x58e8cd34U), bswap_32big(0x9fe23a17U), bswap_32big(0xdd2c9998U),
                           bswap_32big(0x73da89eaU));
            WR1_PROG(REG_14B4H, 0x00000040U);
            WAIT_STS(REG_142CH, 12U, 0U);

            return RSIP_RET_KEY_FAIL;
        }
        else
        {
            WR1_PROG(REG_1600H, 0x00003409U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func030();
            WR1_PROG(REG_1600H, 0x00002ca0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x000035c7U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1444H, 0x000001c7U);
            WR1_PROG(REG_1608H, 0x80020000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Text[0]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_Text[1]);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b7e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00002fc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b780U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (iLoop = 2; iLoop < WRAPPED_KEY_SIZE; iLoop = iLoop + 2)
            {
                WR1_PROG(REG_1444H, 0x000001c7U);
                WR1_PROG(REG_1608H, 0x8082001fU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 0]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &InData_Text[iLoop + 1]);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000027fcU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002fc0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0xbbab7908U),
                               bswap_32big(0x44ce7f2aU),
                               bswap_32big(0x33338c4eU),
                               bswap_32big(0xc97ec376U));
            }

            WR1_PROG(REG_1600H, 0x38000bc5U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000377fU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000ab60U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000008U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003785U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003380U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000349cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00026c84U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00016f9cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000249cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000bdeU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b720U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000004U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000b740U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x0000000cU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003785U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00003380U);
            WR1_PROG(REG_1458H, 0x00000000U);
            for (jLoop = 5; jLoop >= 0; jLoop = jLoop - 1)
            {
                WR1_PROG(REG_1600H, 0x000037fbU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000bbdU);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = (WRAPPED_KEY_SIZE / 2) - 1; iLoop >= 1; iLoop = iLoop - 1)
                {
                    WR1_PROG(REG_1600H, 0x00000824U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1824H, 0x0a00810dU);
                    WR1_PROG(REG_1608H, 0x81020000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00490009U);
                    WR1_PROG(REG_1608H, 0x8182001fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00490009U);
                    WR1_PROG(REG_1608H, 0x80040000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x03410011U);
                    WR1_PROG(REG_1600H, 0x00003c5fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000027f9U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003c7fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002bfaU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00003080U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00002fa0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x82ef41f3U),
                                   bswap_32big(0x96bd8cedU),
                                   bswap_32big(0x514093f0U),
                                   bswap_32big(0x145ac1ebU));
                }

                WR1_PROG(REG_1600H, 0x38000bbcU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00002fc0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x072283dfU),
                               bswap_32big(0x88d3096bU),
                               bswap_32big(0x0d646924U),
                               bswap_32big(0x1444d48fU));
            }

            WR1_PROG(REG_1600H, 0x38008bc0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000006U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x38008800U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xa6a6a6a6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            WR1_PROG(REG_1600H, 0x38008820U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0xa6a6a6a6U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00A60000U);
            r_rsip_func100(bswap_32big(0x55771f35U), bswap_32big(0x08393165U), bswap_32big(0x23ec4862U),
                           bswap_32big(0xa25b7567U));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                r_rsip_func102(bswap_32big(0x044bf4e8U),
                               bswap_32big(0xea4268c6U),
                               bswap_32big(0x03892265U),
                               bswap_32big(0x19582356U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_FAIL;
            }
            else
            {
                r_rsip_func100(bswap_32big(0xffe757a1U),
                               bswap_32big(0xc00207c7U),
                               bswap_32big(0x536c0811U),
                               bswap_32big(0x49309525U));
                r_rsip_func103();
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c200104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1608H, 0x80040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03420011U);
                r_rsip_subfunc009(bswap_32big(0x00009002U));
                r_rsip_func101(bswap_32big(0x0cf3db1fU),
                               bswap_32big(0xaebe75f5U),
                               bswap_32big(0x4ddf3161U),
                               bswap_32big(0xd13f0862U));
                r_rsip_func045();
                WR1_PROG(REG_1600H, 0x000034e6U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc009(bswap_32big(0x00009003U));
                r_rsip_func101(bswap_32big(0x175d4024U),
                               bswap_32big(0x2094d44bU),
                               bswap_32big(0xdbb61f24U),
                               bswap_32big(0x6a37326cU));
                r_rsip_func046();
                WR1_PROG(REG_1600H, 0x000034eeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b7e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000044U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x08000054U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1600H, 0x00000bdeU);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b760U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000b780U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a8e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000008U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < KEY_INDEX_SIZE - 8; iLoop = iLoop + 4)
                {
                    WR1_PROG(REG_1600H, 0x000008c6U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x34202bc7U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x2000d0c0U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x00007c06U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_143CH, 0x00602000U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func100(bswap_32big(0xe280eda4U),
                                   bswap_32big(0x9fe1f0e5U),
                                   bswap_32big(0xd4644725U),
                                   bswap_32big(0xedd7cb25U));
                    WR1_PROG(REG_1444H, 0x000003c2U);
                    WR1_PROG(REG_1A2CH, 0x40000000U);
                    WR1_PROG(REG_1A24H, 0xe7008d05U);
                    WR1_PROG(REG_1608H, 0x8184001fU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_subfunc003(0x00890011U);
                    WR1_PROG(REG_1408H, 0x00002012U);
                    WAIT_STS(REG_1408H, 30U, 1U);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                    RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                    WR1_PROG(REG_1600H, 0x000027fcU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    WR1_PROG(REG_1600H, 0x000027dbU);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9d090ad4U),
                                   bswap_32big(0x5c73578dU),
                                   bswap_32big(0x5a80fc02U),
                                   bswap_32big(0x4b82702fU));
                }

                WR1_PROG(REG_1600H, 0x38000bc7U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func100(bswap_32big(0x818922d0U),
                               bswap_32big(0xa494449aU),
                               bswap_32big(0x2d9c8faeU),
                               bswap_32big(0xea199febU));
                WR1_PROG(REG_1444H, 0x000000a2U);
                WR1_PROG(REG_1A24H, 0x0c000104U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
                WR1_PROG(REG_1A2CH, 0x40000000U);
                WR1_PROG(REG_1A24H, 0x09108105U);
                r_rsip_subfunc003(0x00820011U);
                WR1_PROG(REG_1408H, 0x00002012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 4]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 5]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 6]);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[iLoop + 7]);
                r_rsip_func100(bswap_32big(0x56152570U),
                               bswap_32big(0x51681b4dU),
                               bswap_32big(0x6d8fb354U),
                               bswap_32big(0x65e3628eU));
                WR1_PROG(REG_1608H, 0x81040000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1408H, 0x00005012U);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[0]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[1]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[2]);
                WAIT_STS(REG_1408H, 30U, 1U);
                RD1_ADDR(REG_1420H, &OutData_KeyIndex[3]);
                r_rsip_func102(bswap_32big(0x7ae572feU),
                               bswap_32big(0xac2ae5e1U),
                               bswap_32big(0x2e4f9af3U),
                               bswap_32big(0xc2da8b72U));
                WR1_PROG(REG_14B4H, 0x00000040U);
                WAIT_STS(REG_142CH, 12U, 0U);

                return RSIP_RET_PASS;
            }
        }
    }
}
