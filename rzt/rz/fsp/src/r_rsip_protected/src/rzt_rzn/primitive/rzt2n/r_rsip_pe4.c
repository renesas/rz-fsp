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

rsip_ret_t r_rsip_pe4 (const uint32_t InData_HashType[],
                       const uint32_t InData_CurveType[],
                       const uint32_t InData_EncSecret[],
                       uint32_t       OutData_KeyIndex[])
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

    WR1_PROG(REG_1B00H, 0x00e40002U);
    WR1_PROG(REG_144CH, 0x00000000U);
    WR1_PROG(REG_1444H, 0x000000c7U);
    WR1_PROG(REG_1608H, 0x80010080U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WAIT_STS(REG_1444H, 31U, 1U);
    WR1_ADDR(REG_1420H, &InData_HashType[0]);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x3420a880U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000003U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x2000b480U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x00000002U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_1600H, 0x000009ceU);
    WR1_PROG(REG_1458H, 0x00000000U);
    r_rsip_func100(bswap_32big(0x779f6457U),
                   bswap_32big(0x41bf1f15U),
                   bswap_32big(0x85b41815U),
                   bswap_32big(0xf255d3e6U));
    WR1_PROG(REG_1600H, 0x00007c04U);
    WR1_PROG(REG_1458H, 0x00000000U);
    WR1_PROG(REG_143CH, 0x00600000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (0x00000000U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x011ec161U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0113edb0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000008U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x456813c8U), bswap_32big(0x72c3a678U), bswap_32big(0xe065c858U),
                       bswap_32big(0xf2a87012U));
    }
    else if (0x00000001U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1600H, 0x0000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01a2597cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x019ff0beU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b520U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000000cU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0xdcaeb243U), bswap_32big(0x033b4d25U), bswap_32big(0xbb4091a1U),
                       bswap_32big(0x19d8269eU));
    }
    else if (0x00000002U == RD1_MASK(REG_1440H, 0xffffffffU))
    {
        WR1_PROG(REG_1444H, 0x000000c7U);
        WR1_PROG(REG_1608H, 0x800101c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_ADDR(REG_1420H, &InData_CurveType[0]);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x38000dceU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x017d11fdU);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x1000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000014U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000b4a0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01f00452U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x2000b4c0U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000010U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x0000b500U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x01d373eaU);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_func101(bswap_32big(0x14bab864U), bswap_32big(0x2b5007fbU), bswap_32big(0x8d10ecacU),
                       bswap_32big(0xad4ac2fbU));
    }

    r_rsip_subfunc009(bswap_32big(0x000000e4U));
    r_rsip_func101(bswap_32big(0x4c10cbd4U),
                   bswap_32big(0xe271e712U),
                   bswap_32big(0xc004d628U),
                   bswap_32big(0x002f193fU));
    r_rsip_func407(InData_EncSecret);
    r_rsip_func100(bswap_32big(0xd8222852U),
                   bswap_32big(0x953d4c7bU),
                   bswap_32big(0x7cbff405U),
                   bswap_32big(0x55cffe0cU));
    WR1_PROG(REG_143CH, 0x00400000U);
    WR1_PROG(REG_1458H, 0x00000000U);
    if (CHCK_STS(REG_143CH, 22U, 1U))
    {
        r_rsip_func102(bswap_32big(0xca833e22U), bswap_32big(0x0caba372U), bswap_32big(0x3866c962U),
                       bswap_32big(0xe004f31eU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_FAIL;
    }
    else
    {
        WR1_PROG(REG_1600H, 0x38008880U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1600H, 0x00000002U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1608H, 0x00000080U);
        WR1_PROG(REG_143CH, 0x00260000U);
        r_rsip_func100(bswap_32big(0x425257b6U), bswap_32big(0x6dfe84acU), bswap_32big(0x2edf4168U),
                       bswap_32big(0x9c5b9ba6U));
        WR1_PROG(REG_143CH, 0x00400000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        if (CHCK_STS(REG_143CH, 22U, 1U))
        {
            WR1_PROG(REG_1600H, 0x38000dceU);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            r_rsip_func100(bswap_32big(0x041508c8U), bswap_32big(0xb9fdccc7U), bswap_32big(0xaa8a3affU),
                           bswap_32big(0x018f40afU));
            WR1_PROG(REG_143CH, 0x00400000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            if (CHCK_STS(REG_143CH, 22U, 1U))
            {
                WR1_PROG(REG_2000H, 0x00000001U);
                WR1_PROG(REG_2004H, 0x000000b0U);
                WR1_PROG(REG_2014H, 0x00000000U);
                WR1_PROG(REG_2010H, 0x00000210U);
                r_rsip_func408();
                WR1_PROG(REG_1600H, 0x000008a5U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1608H, 0x81910005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x01490045U);
                WAIT_STS(REG_2030H, 8U, 0U);
                WR1_PROG(REG_143CH, 0x00001600U);
                WR1_PROG(REG_1608H, 0x80900005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03450041U);
                r_rsip_func101(bswap_32big(0x579b29f6U),
                               bswap_32big(0x90119d99U),
                               bswap_32big(0x9eac53f5U),
                               bswap_32big(0x3c4d1e03U));
            }
            else
            {
                r_rsip_func101(bswap_32big(0x929a5efbU),
                               bswap_32big(0xbaea5917U),
                               bswap_32big(0xd9016a39U),
                               bswap_32big(0x1dbb30a4U));
            }
        }
        else
        {
            r_rsip_func100(bswap_32big(0x9277d648U), bswap_32big(0xc13cca49U), bswap_32big(0xb8841a94U),
                           bswap_32big(0x44d04303U));
            WR1_PROG(REG_1608H, 0x81010120U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1408H, 0x00005006U);
            WAIT_STS(REG_1408H, 30U, 1U);
            RD1_ADDR(bswap_32big(REG_1420H), &S_RAM[0]);
            for (iLoop = S_RAM[0]; iLoop < 16; iLoop = iLoop + 4)
            {
                WR1_PROG(REG_1608H, 0x80840005U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_subfunc003(0x03400011U);
                WR1_PROG(REG_1600H, 0x0000a4e0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000004U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x0000a4a0U);
                WR1_PROG(REG_1458H, 0x00000000U);
                WR1_PROG(REG_1600H, 0x00000010U);
                WR1_PROG(REG_1458H, 0x00000000U);
                r_rsip_func101(bswap_32big(0x47710ce5U),
                               bswap_32big(0x1a9a917eU),
                               bswap_32big(0x607a67ffU),
                               bswap_32big(0x1d2759e4U));
            }

            WR1_PROG(REG_1600H, 0x380088e0U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1600H, 0x00000010U);
            WR1_PROG(REG_1458H, 0x00000000U);
            WR1_PROG(REG_1608H, 0x00000080U);
            WR1_PROG(REG_143CH, 0x00260000U);
            WR1_PROG(REG_143CH, 0x00402000U);
            WR1_PROG(REG_1458H, 0x00000000U);
            r_rsip_func101(bswap_32big(0x991b312eU), bswap_32big(0xc49b2393U), bswap_32big(0x1fe77a19U),
                           bswap_32big(0xc627fd7fU));
        }

        r_rsip_func100(bswap_32big(0xd36c0557U), bswap_32big(0x414d36f3U), bswap_32big(0x3209fa65U),
                       bswap_32big(0xb0cc389bU));
        r_rsip_func103();
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c200104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1608H, 0x80040000U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x03420011U);
        r_rsip_subfunc009(bswap_32big(0x000000e4U));
        r_rsip_func101(bswap_32big(0x67fc5315U), bswap_32big(0x5168c88dU), bswap_32big(0xf09eebb5U),
                       bswap_32big(0x92244a72U));
        r_rsip_func045();
        WR1_PROG(REG_1600H, 0x000034e8U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc009(bswap_32big(0x000000e4U));
        r_rsip_func101(bswap_32big(0xde150eb5U), bswap_32big(0x058fe2ffU), bswap_32big(0xb3adbb94U),
                       bswap_32big(0x9d1e077dU));
        r_rsip_func046();
        r_rsip_func100(bswap_32big(0xd9fdd9caU), bswap_32big(0x73ff15efU), bswap_32big(0xb7a85c0dU),
                       bswap_32big(0x345c7065U));
        WR1_PROG(REG_1600H, 0x000008a5U);
        WR1_PROG(REG_1458H, 0x00000000U);
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7009d07U);
        WR1_PROG(REG_1608H, 0x81900005U);
        WR1_PROG(REG_1458H, 0x00000000U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[4]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[5]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[6]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[7]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[8]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[9]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[10]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[11]);
        r_rsip_func100(bswap_32big(0xca03172cU), bswap_32big(0xf28e6f73U), bswap_32big(0x9d0c09cbU),
                       bswap_32big(0xabed4cdfU));
        WR1_PROG(REG_1A2CH, 0x40000100U);
        WR1_PROG(REG_1A24H, 0xe7008d07U);
        r_rsip_subfunc003(0x00890021U);
        WR1_PROG(REG_1408H, 0x00002022U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[12]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[13]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[14]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[15]);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[16]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[17]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[18]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[19]);
        r_rsip_func100(bswap_32big(0x74633fc2U), bswap_32big(0xf15677ffU), bswap_32big(0xfa67fc87U),
                       bswap_32big(0x1d607946U));
        WR1_PROG(REG_1444H, 0x000000a2U);
        WR1_PROG(REG_1A24H, 0x0c000104U);
        WAIT_STS(REG_1444H, 31U, 1U);
        WR1_PROG(REG_1420H, bswap_32big(0x00000000U));
        WR1_PROG(REG_1A2CH, 0x40000000U);
        WR1_PROG(REG_1A24H, 0x09108105U);
        r_rsip_subfunc003(0x00820011U);
        WR1_PROG(REG_1408H, 0x00002012U);
        WAIT_STS(REG_1408H, 30U, 1U);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[20]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[21]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[22]);
        RD1_ADDR(REG_1420H, &OutData_KeyIndex[23]);
        r_rsip_func100(bswap_32big(0x588af6b5U), bswap_32big(0x206efa77U), bswap_32big(0xc4abb6e5U),
                       bswap_32big(0x4bc0bccfU));
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
        r_rsip_func102(bswap_32big(0xf8157a34U), bswap_32big(0x771bf53fU), bswap_32big(0x15109815U),
                       bswap_32big(0x83cd5cadU));
        WR1_PROG(REG_14B8H, 0x00000040U);
        WAIT_STS(REG_142CH, 12U, 0U);

        return RSIP_RET_PASS;
    }
}
