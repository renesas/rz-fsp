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

rsip_ret_t r_rsip_pe5e (const uint32_t InData_EncMsg[], const uint32_t MAX_CNT2)
{
    RSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL;
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
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010100U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    uint32_t max_cnt2 = bswap_32big(MAX_CNT2);
    WR1_ADDR(REG_1420H, &max_cnt2);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x38000d08U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1608H, 0x00000080U);
    WR1_PROG(REG_143CH, 0x00A60000U);
    r_rsip_func100(bswap_32big(0x91c38990U),
                   bswap_32big(0xb549d9c4U),
                   bswap_32big(0x297cc9c4U),
                   bswap_32big(0x7e40e8f6U));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        WR1_PROG(REG_1444H, 0x000003c7U);
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[1]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[2]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[3]);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e503U));
        r_rsip_func101(bswap_32big(0x871a15f6U), bswap_32big(0xa75b6124U), bswap_32big(0xca34186eU),
                       bswap_32big(0xfd43d5f5U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x013f271aU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e503U));
        r_rsip_func101(bswap_32big(0x42c399b0U), bswap_32big(0x6c297bd4U), bswap_32big(0xb4c61a6eU),
                       bswap_32big(0xcbd70edeU));
        r_rsip_func046();
        WAIT_STS(REG_2030H, 0U, 1U);
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000044U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x08000054U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        r_rsip_func100(bswap_32big(0xb2e65b6aU), bswap_32big(0x4677edd4U), bswap_32big(0x65855df8U),
                       bswap_32big(0x32fc7717U));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0xa48ee7f9U), bswap_32big(0x38ec1206U), bswap_32big(0x812c2f06U),
                       bswap_32big(0x2d41e4a1U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c2000c4U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func100(bswap_32big(0x39a40fabU), bswap_32big(0xc48d9cddU), bswap_32big(0x5a3c2470U),
                       bswap_32big(0xa813f910U));
        WR1_PROG(REG_1608H, 0x81010100U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1408H, 0x00005006U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
        OFS_ADR = S_RAM[0];
        WR1_PROG(REG_1600H, 0x0000a900U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00026908U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000929U);
        WR1_PROG(REG_1458H, 0x00000000U);
        for (iLoop = 0; iLoop < S_RAM[0] - 8; iLoop = iLoop + 4)
        {
            WR1_PROG(REG_1444H, 0x000003c2U);
            WR1_PROG(REG_1A2CH, 0x40000000U);
            WR1_PROG(REG_1A24H, 0xf7008d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 4]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 5]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 6]);
            WR1_ADDR(REG_1420H, &InData_EncMsg[iLoop + 7]);
            r_rsip_func100(bswap_32big(0x5da4e859U), bswap_32big(0xe8156c1cU), bswap_32big(0xbb763815U),
                           bswap_32big(0xf88a7b92U));
            WR1_PROG(REG_1824H, 0xe7040d05U);
            r_rsip_subfunc003(0x00420011U);
            WR1_PROG(REG_1408H, 0x00001012U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
            RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
            WR1_PROG(REG_1600H, 0x00002d20U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x4a579a11U), bswap_32big(0x6d600460U), bswap_32big(0x7faabd9fU),
                           bswap_32big(0xae3d4b68U));
        }

        WR1_PROG(REG_1600H, 0x38000909U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0x54f2b0bfU), bswap_32big(0x80489d49U), bswap_32big(0x27f9d164U),
                       bswap_32big(0x217f23d9U));
        WR1_PROG(REG_1444H, 0x000000a1U);
        WR1_PROG(REG_1824H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1824H, 0x09140105U);
        r_rsip_subfunc003(0x00410011U);
        WR1_PROG(REG_1408H, 0x00001012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
        RD1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
        WR1_PROG(REG_1444H, 0x000003c2U);
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x07008d05U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 4]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 3]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 2]);
        WR1_ADDR(REG_1420H, &InData_EncMsg[OFS_ADR - 1]);
        WR1_PROG(REG_1A24H, 0x9c100005U);
        r_rsip_subfunc003(0x00820011U);
        r_rsip_func100(bswap_32big(0x39bdbb0aU), bswap_32big(0x9050967fU), bswap_32big(0x393e5ea9U),
                       bswap_32big(0xfc0b2808U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x8c7c3b62U), bswap_32big(0xe9c177b8U), bswap_32big(0x1ca21badU),
                           bswap_32big(0x3c714cd1U));

            return RSIP_RET_FAIL;
        }
        else
        {
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x08000044U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1444H, 0x000000a1U);
            WR1_PROG(REG_1824H, 0x08000054U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
            WR1_PROG(REG_1600H, 0x3800a900U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000005U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x4b21a654U), bswap_32big(0x59c06fe5U), bswap_32big(0xf461f6d1U),
                           bswap_32big(0xd8af48acU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_1600H, 0x00000929U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < S_RAM[0] - 12; iLoop = iLoop + 4)
                {
                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0xf7040d05U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
                    r_rsip_subfunc003(0x01410011U);
                    WR1_PROG(REG_1600H, 0x00002d20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x9030072bU),
                                   bswap_32big(0xfbdd24c5U),
                                   bswap_32big(0x88002bffU),
                                   bswap_32big(0xc518e763U));
                }

                WR1_PROG(REG_1600H, 0x000037e8U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x000033e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x38000be9U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1444H, 0x000003c1U);
                WR1_PROG(REG_1824H, 0xf7040d05U);
                WAIT_STS(REG_1444H, 31U, 1U);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
                WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
                r_rsip_subfunc003(0x01410005U);
                r_rsip_subfunc003(0x0001000dU);
                iLoop = iLoop + 4;
                r_rsip_func101(bswap_32big(0x8db28cb1U),
                               bswap_32big(0xdd94b179U),
                               bswap_32big(0x0bbb48efU),
                               bswap_32big(0xf1e46642U));
            }
            else
            {
                WR1_PROG(REG_1600H, 0x00000929U);
                WR1_PROG(REG_1458H, 0x00000000U);
                for (iLoop = 0; iLoop < S_RAM[0] - 8; iLoop = iLoop + 4)
                {
                    WR1_PROG(REG_1444H, 0x000003c1U);
                    WR1_PROG(REG_1824H, 0xf7040d05U);
                    WAIT_STS(REG_1444H, 31U, 1U);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
                    WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
                    r_rsip_subfunc003(0x01410011U);
                    WR1_PROG(REG_1600H, 0x00002d20U);
                    WR1_PROG(REG_1458H, 0x00000000U);
                    r_rsip_func101(bswap_32big(0x156946adU),
                                   bswap_32big(0x66ae7804U),
                                   bswap_32big(0x8e27b3b8U),
                                   bswap_32big(0x49015255U));
                }

                WR1_PROG(REG_1600H, 0x38000909U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x7d05bfe1U),
                               bswap_32big(0x14f3bb8cU),
                               bswap_32big(0x38c31bfdU),
                               bswap_32big(0x306b4ef4U));
            }

            WR1_PROG(REG_1444H, 0x000003c1U);
            WR1_PROG(REG_1824H, 0x07040d05U);
            WAIT_STS(REG_1444H, 31U, 1U);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 0]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 1]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 2]);
            WR1_ADDR(REG_1420H, &S_HEAP[iLoop + 3]);
            WR1_PROG(REG_1824H, 0x8c100005U);
            r_rsip_subfunc003(0x00410011U);
            r_rsip_func100(bswap_32big(0xc34d6170U), bswap_32big(0xd7927663U), bswap_32big(0xceca00deU),
                           bswap_32big(0x4518a20fU));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func101(bswap_32big(0xc6067fadU), bswap_32big(0x1fee34daU), bswap_32big(0x51f78151U),
                           bswap_32big(0xf25197b2U));

            return RSIP_RET_PASS;
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0xf702916aU), bswap_32big(0x8bc11af0U), bswap_32big(0x2e8ffba4U),
                       bswap_32big(0x588df12cU));

        return RSIP_RET_PASS;
    }
}
