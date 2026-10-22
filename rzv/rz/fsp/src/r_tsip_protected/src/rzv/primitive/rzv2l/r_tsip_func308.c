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

void r_tsip_func308 (void)
{
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
    r_tsip_func100(0xf942fe84U, 0x8621e434U, 0xbf28b19fU, 0x8fab867eU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000024U);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x00000b5aU);
    WR1_PROG(REG_00ECH, 0x0000d77cU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x3800db7aU);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x0000d37cU);
    WR1_PROG(REG_00ECH, 0x00003bbeU);
    WR1_PROG(REG_00ECH, 0x00002b5dU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x00003b5eU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0161d833U));
    r_tsip_func080();
    r_tsip_func100(0x358a244aU, 0xd116a70bU, 0xbac97cd1U, 0xbf36da1bU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(1020);
    r_tsip_func100(0x77206516U, 0x85e58762U, 0xc0f91008U, 0xdf4c40f5U);
    r_tsip_func314(1020 + 64);
    r_tsip_func100(0x113f45f4U, 0xb1e5c2e4U, 0x2a675221U, 0xa388921fU);
    WR1_PROG(REG_00ECH, 0x00000b39U);
    WR1_PROG(REG_00ECH, 0x0000d77dU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x3800db7bU);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x0000d37dU);
    WR1_PROG(REG_00ECH, 0x00003bbeU);
    WR1_PROG(REG_00ECH, 0x00002b3dU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x00003b3eU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013fd1d7U));
    r_tsip_func080();
    r_tsip_func100(0x791cb5c9U, 0xe528a27bU, 0xad49ca9fU, 0xf800f399U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    r_tsip_func313(1088);
    r_tsip_func100(0xced6fb69U, 0xbb417caaU, 0x82b01a8bU, 0x4ff9543fU);
    r_tsip_func314(1088 + 64);
    r_tsip_func100(0x805f8c4cU, 0x0a5a1bc3U, 0x68913176U, 0x15f49451U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x80c0001eU);
    WR1_PROG(REG_0000H, 0x00018303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x0000c0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_00E0H, 0x81010320U);
    WR1_PROG(REG_0000H, 0x00003807U);
    WR1_PROG(REG_002CH, 0x00000010U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00E0H, 0x81010340U);
    WR1_PROG(REG_0000H, 0x00003807U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00E0H, 0x80010300U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000d77eU);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_00ECH, 0x3000db7cU);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x00002fc0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x3000db7dU);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x00002fc0U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x3000dbc0U);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d77eU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d37eU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000400U);
    WR1_PROG(REG_0024H, 0x800080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000058d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013fd1d7U));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1088);
    WR1_PROG(REG_00ECH, 0x3000db7cU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d76bU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d36bU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x000037daU);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000097U);
    r_tsip_func101(0x95b29da5U, 0x71dbde9eU, 0xa725ee67U, 0xb81172bdU);
    r_tsip_func310();
    r_tsip_func100(0xf3bc3e48U, 0x84a537eaU, 0x93560c9aU, 0x7ce4693fU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x0161d833U));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1020);
    WR1_PROG(REG_00ECH, 0x3000db7dU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d76bU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d36bU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x000037d9U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000098U);
    r_tsip_func101(0xce3ba939U, 0xc2e2aa41U, 0xe2b62d5bU, 0x07eb7cb0U);
    r_tsip_func310();
    WR1_PROG(REG_00ECH, 0x3800db7eU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x2ff7d97cU, 0x0c08057dU, 0xff033674U, 0x8ce741b7U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00E0H, 0x81010300U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000090U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x80001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        r_tsip_func101(0x9844ab56U, 0x903d2222U, 0x613d7497U, 0x9c26674fU);
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00E0H, 0x81010300U);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000090U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x80001181U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        r_tsip_func101(0x5a819725U, 0xc3120e50U, 0x38385894U, 0x8610a207U);
    }

    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_00ECH, 0x02816fdeU);
    WR1_PROG(REG_00ECH, 0x30008bc0U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x0000d372U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d772U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000018U);
    WR1_PROG(REG_00E0H, 0x8081001eU);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x0000001cU);
    WR1_PROG(REG_00E0H, 0x8081001eU);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x0000d768U);
    WR1_PROG(REG_0024H, 0x000088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x81c0001eU);
    WR1_PROG(REG_0000H, 0x00013803U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000024U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_001CH, 0x00602000U);
}
