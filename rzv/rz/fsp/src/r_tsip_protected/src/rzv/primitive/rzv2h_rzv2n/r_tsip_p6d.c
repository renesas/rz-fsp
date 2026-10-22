/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "r_tsip_primitive.h"
#include "r_tsip_reg.h"
#include "r_tsip_util.h"

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

TSIP_PRV_PRIMITIVE_FUNC

tsip_ret_t r_tsip_p6d (uint32_t OutData_KeyIndex[])
{
    TSIP_PRV_PRIMITIVE_ENTRY;
    uint32_t iLoop;
    uint32_t iLoop2;
    uint32_t jLoop;
    uint32_t kLoop;
    uint32_t oLoop;
    uint32_t oLoop1;
    uint32_t oLoop2;
    uint32_t OFS_ADR;
    (void) iLoop;
    (void) iLoop2;
    (void) jLoop;
    (void) kLoop;
    (void) oLoop;
    (void) oLoop1;
    (void) oLoop2;
    (void) OFS_ADR;
    if (0x0U != RD1_MASK(REG_01B4H, 0x1dU))
    {
        return TSIP_RET_RESOURCE_CONFLICT;
    }

    WR1_PROG(REG_0084H, 0x00006d02U);
    WR1_PROG(REG_0108H, 0x00000000U);
    r_tsip_func100(0xdc6022cfU, 0xe3fe385dU, 0x62b92edaU, 0xc7940cd3U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008c00U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00ffffffU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00009000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x01000000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    r_tsip_func100(0x4c6045efU, 0x969cbdc8U, 0x97e7b5ebU, 0x32c85c3aU);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0004H, 0x00000613U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[0]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[1]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[2]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[3]);
    r_tsip_func100(0x76080438U, 0x0d81cb3cU, 0xb84386b4U, 0x20044466U);
    WR1_PROG(REG_00ECH, 0x0000b540U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x000001e0U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_00A4H, 0x00080805U);
    WR1_PROG(REG_00E0H, 0x8184000aU);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x5fc67242U, 0xc00c63c7U, 0xcb847edfU, 0x77103b3bU);
    WR1_PROG(REG_0104H, 0x00000051U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e15U);
    WR1_PROG(REG_00E0H, 0x81040000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001813U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x2ee93f85U, 0xdc981c76U, 0x65d4b650U, 0x88b54e18U);
    WR1_PROG(REG_0104H, 0x00000151U);
    WR1_PROG(REG_00A4H, 0x00440a04U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00A4H, 0x00080e14U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01294396U));
    r_tsip_func100(0x4f86247aU, 0x307c05b6U, 0x35bc13f7U, 0xf5650adeU);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_00E0H, 0x80080000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0x26869deeU, 0xe9547b71U, 0x773d0ea3U, 0x8e803da4U);
    r_tsip_func103();
    WR1_PROG(REG_0104H, 0x00000052U);
    WR1_PROG(REG_00C4H, 0x01000c84U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0000H, 0x00008213U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    r_tsip_func100(0xe054058fU, 0xf1dad30eU, 0xa9d55cd2U, 0xcf6b506aU);
    WR1_PROG(REG_00B0H, 0x00000100U);
    WR1_PROG(REG_00A4H, 0x02e487b7U);
    WR1_PROG(REG_00E0H, 0x81050000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    WR1_PROG(REG_0000H, 0x00001817U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000100fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0104H, 0x00000351U);
    WR1_PROG(REG_00A4H, 0x000009c5U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000002U));
    WR1_PROG(REG_0004H, 0x00000133U);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[4]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[5]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[6]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[7]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[8]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[9]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[10]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[11]);
    WAIT_STS(REG_0004H, 30U, 1U);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[12]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[13]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[14]);
    RD1_ADDR(REG_0100H, &OutData_KeyIndex[15]);
    r_tsip_func102(0x36461819U, 0x5e81606fU, 0xf445f1afU, 0xa1a1aab8U);
    WR1_PROG(REG_01B4H, 0x00000040U);
    WAIT_STS(REG_0018H, 12U, 0U);

    return TSIP_RET_PASS;
}
