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
    r_rsip_func100(bswap_32big(0x0d10f17bU),
                   bswap_32big(0x989e3cfaU),
                   bswap_32big(0xb501e197U),
                   bswap_32big(0x56c1a62fU));
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
        r_rsip_func101(bswap_32big(0x96708310U), bswap_32big(0x05669e7bU), bswap_32big(0x5bec45aeU),
                       bswap_32big(0x292cc4ceU));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x0000b4e0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x018f1cdcU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x0000e503U));
        r_rsip_func101(bswap_32big(0x82d16bdcU), bswap_32big(0x4c80c2c4U), bswap_32big(0xb2f72894U),
                       bswap_32big(0x1247d3b1U));
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
        r_rsip_func100(bswap_32big(0xd93ab801U), bswap_32big(0x83df13c8U), bswap_32big(0xc632ba16U),
                       bswap_32big(0x7ac9cfa7U));
        r_rsip_func103();
        r_rsip_func100(bswap_32big(0xab9e5737U), bswap_32big(0x7cf419a5U), bswap_32big(0x2b3e7d2bU),
                       bswap_32big(0xb4d618b7U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c2000c4U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WAIT_STS(REG_1A28H, 6U, 0U);
        WR1_PROG(REG_143CH, 0x00000900U);
        r_rsip_func100(bswap_32big(0x84332b8cU), bswap_32big(0x15445042U), bswap_32big(0xa01bb70bU),
                       bswap_32big(0x8571df20U));
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
            r_rsip_func100(bswap_32big(0xf00ed068U), bswap_32big(0xd53c3846U), bswap_32big(0x27cb9464U),
                           bswap_32big(0x9f2d5f90U));
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
            r_rsip_func101(bswap_32big(0x9647a899U), bswap_32big(0x776c9898U), bswap_32big(0x3cf18636U),
                           bswap_32big(0x45a9060dU));
        }

        WR1_PROG(REG_1600H, 0x38000909U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        WR1_PROG(REG_143CH, 0x00402000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func100(bswap_32big(0xba457a02U), bswap_32big(0x27501f0bU), bswap_32big(0x851815e2U),
                       bswap_32big(0xa1050265U));
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
        r_rsip_func100(bswap_32big(0xb5602facU), bswap_32big(0x6bfaa6cfU), bswap_32big(0x8c4b18e1U),
                       bswap_32big(0x0b95ced4U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            r_rsip_func101(bswap_32big(0x9acdd53eU), bswap_32big(0x4db3edbeU), bswap_32big(0x076e6585U),
                           bswap_32big(0x4aa60a7dU));

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
            r_rsip_func100(bswap_32big(0x27fe4779U), bswap_32big(0x12795beeU), bswap_32big(0x53ca22a4U),
                           bswap_32big(0xd405877dU));
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
                    r_rsip_func101(bswap_32big(0x24647459U),
                                   bswap_32big(0x6ae29076U),
                                   bswap_32big(0x4ff9f267U),
                                   bswap_32big(0x6f1c44bbU));
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
                r_rsip_func101(bswap_32big(0x3233aa89U),
                               bswap_32big(0xc6926cfeU),
                               bswap_32big(0x5399ff9fU),
                               bswap_32big(0xd7fa427eU));
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
                    r_rsip_func101(bswap_32big(0x166c1c70U),
                                   bswap_32big(0x28c0f7d8U),
                                   bswap_32big(0x8efad6a9U),
                                   bswap_32big(0x8f8c26f7U));
                }

                WR1_PROG(REG_1600H, 0x38000909U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x00000080U);
                WR1_PROG(REG_143CH, 0x00260000U);
                WR1_PROG(REG_143CH, 0x00402000U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x87e0ab55U),
                               bswap_32big(0xaf65e7c2U),
                               bswap_32big(0x4db73768U),
                               bswap_32big(0xfdda0638U));
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
            r_rsip_func100(bswap_32big(0xb316fc6fU), bswap_32big(0xf2dcc713U), bswap_32big(0x145d73b2U),
                           bswap_32big(0x3111ec49U));
            WR1_PROG(REG_1408H, 0x00020000U);
            r_rsip_func101(bswap_32big(0xa788a73aU), bswap_32big(0x8ea8ae46U), bswap_32big(0x59f55000U),
                           bswap_32big(0x6181bc66U));

            return RSIP_RET_PASS;
        }
    }
    else
    {
        r_rsip_func101(bswap_32big(0x7c69e01fU), bswap_32big(0x9dcbda7cU), bswap_32big(0x3b9180cdU),
                       bswap_32big(0xe1336690U));

        return RSIP_RET_PASS;
    }
}
