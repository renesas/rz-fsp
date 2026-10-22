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

void r_tsip_func304 (void)
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
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000024U);
    WR1_PROG(REG_00ECH, 0x00003c1eU);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x0000d779U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_00ECH, 0x00000b18U);
    WR1_PROG(REG_00E0H, 0x80010300U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x000000adU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000031fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x3800db1fU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x9eb08ce8U, 0xd58025e7U, 0x00863677U, 0x5cbb6149U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func101(0x171fd38aU, 0x3152b898U, 0xaaa2b33fU, 0xdf5dd6f9U);
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000581U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x82001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_00ECH, 0x0000d379U);
        r_tsip_func101(0x17a1444fU, 0x66f65f35U, 0xb6c77202U, 0x51bb554cU);
    }

    r_tsip_func100(0x14e710b2U, 0xde4115dbU, 0x359f1635U, 0xb7462f1eU);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x017da167U));
    r_tsip_func080();
    r_tsip_func100(0x82314da4U, 0xacf4877eU, 0xa7b582d6U, 0x0f682394U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    r_tsip_func313(1156);
    r_tsip_func100(0x8427e062U, 0xd1be2cf3U, 0x710be803U, 0x1cd40af2U);
    r_tsip_func314(1156 + 64);
    WR1_PROG(REG_00ECH, 0x00000b5aU);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000d77cU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x3800db7aU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x1b29f73bU, 0x757e86beU, 0xc1f4982eU, 0x10dfb86fU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000157U);
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
        WR1_PROG(REG_00E0H, 0x8181001eU);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000110U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        oLoop1 = 1;
        while (oLoop1 == 1)
        {
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x5e910c64U, 0xb4204ddfU, 0x565fe6eeU, 0x9b102568U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001981U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001181U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                WR1_PROG(REG_00ECH, 0x00003340U);
                r_tsip_func101(0x02133974U, 0x7fb5732cU, 0x27a20bc5U, 0xd0057164U);
            }
            else
            {
                r_tsip_func101(0x48daee53U, 0x6b43c9d9U, 0xd3722d98U, 0xccd1c3ceU);
                oLoop1 = 0;
            }
        }

        WR1_PROG(REG_00ECH, 0x0000d37cU);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00ECH, 0x00002b9aU);
        WR1_PROG(REG_00ECH, 0x0000375cU);
        r_tsip_func101(0x1e8c0bc2U, 0x1f1cdf96U, 0x8a2e158dU, 0xe16a3814U);
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00E0H, 0x8181001eU);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x82001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        oLoop1 = 1;
        while (oLoop1 == 1)
        {
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0x1d14d8a2U, 0xb052d019U, 0x1d4c6a79U, 0x1af12510U);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001981U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001181U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                r_tsip_func101(0xd33141dfU, 0x727b9bc3U, 0xfb734ad8U, 0x6a8f17dbU);
                oLoop1 = 0;
            }
            else
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001991U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001191U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                WR1_PROG(REG_00ECH, 0x00002f40U);
                r_tsip_func101(0x91d61864U, 0x0034def1U, 0x6c4d6951U, 0x6fa8ae5fU);
            }
        }

        r_tsip_func101(0xbe92aa4eU, 0x7f4729d8U, 0xc86c1693U, 0x33617b61U);
    }

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
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x80c0001eU);
    WR1_PROG(REG_0000H, 0x00018303U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00000b39U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000d77dU);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000004U);
    WR1_PROG(REG_00ECH, 0x3800db7bU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x1ba243b4U, 0x36544936U, 0xab362a98U, 0x80e28890U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0104H, 0x00000157U);
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
        WR1_PROG(REG_00E0H, 0x8181001eU);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000110U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        oLoop1 = 1;
        while (oLoop1 == 1)
        {
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xa6e90de6U, 0x97dc12dcU, 0xdc564f50U, 0x6abd7faaU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001981U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001181U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                WR1_PROG(REG_00ECH, 0x00003320U);
                r_tsip_func101(0xccf44d68U, 0x6aab971aU, 0x43f2c09dU, 0x60c92e46U);
            }
            else
            {
                r_tsip_func101(0x90c352c7U, 0xf6c820cbU, 0x75ebfebaU, 0x378202baU);
                oLoop1 = 0;
            }
        }

        WR1_PROG(REG_00ECH, 0x0000d37dU);
        WR1_PROG(REG_00ECH, 0x00000b9cU);
        WR1_PROG(REG_00ECH, 0x00002b99U);
        WR1_PROG(REG_00ECH, 0x0000373cU);
        r_tsip_func101(0x32a66659U, 0x261f3c43U, 0xd6d7a8efU, 0x815c2204U);
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00E0H, 0x8181001eU);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000010U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x82001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        oLoop1 = 1;
        while (oLoop1 == 1)
        {
            WR1_PROG(REG_001CH, 0x00210000U);
            r_tsip_func100(0xba3df53eU, 0xc44641c5U, 0x6a6efee8U, 0x8d2357acU);
            WR1_PROG(REG_001CH, 0x00400000U);
            WR1_PROG(REG_01D0H, 0x00000000U);
            if (CHCK_STS(REG_001CH, 22U, 1U))
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001981U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001181U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                r_tsip_func101(0x34f9d27cU, 0x4bbe91d1U, 0x022bc457U, 0xc04c6155U);
                oLoop1 = 0;
            }
            else
            {
                WR1_PROG(REG_0024H, 0x000009c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x04001991U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000040c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00800001U);
                WR1_PROG(REG_0024H, 0x000011c0U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0034H, 0x00000004U);
                WR1_PROG(REG_0024H, 0x82001191U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0024H, 0x000080c1U);
                WAIT_STS(REG_0024H, 21U, 0U);
                WR1_PROG(REG_0028H, 0x00bf0001U);
                WR1_PROG(REG_00ECH, 0x00002f20U);
                r_tsip_func101(0x5477805fU, 0xbb55eab7U, 0xc2d3c673U, 0x94c0f925U);
            }
        }

        r_tsip_func101(0x6e39698dU, 0x3402d856U, 0xd7e557b8U, 0xbbfd28edU);
    }

    r_tsip_func100(0xad5e3bd0U, 0x5faaac4dU, 0x6cfce8deU, 0x7ec76f62U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013fd1d7U));
    r_tsip_func080();
    r_tsip_func100(0xae357750U, 0x42f5629cU, 0x6e14b9b7U, 0x76125487U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(1088);
    r_tsip_func100(0x307d308eU, 0x5cad3e6aU, 0x089c3a99U, 0xabf549aaU);
    r_tsip_func314(1088 + 64);
    r_tsip_func100(0x4298d509U, 0xb956e1f1U, 0xcb3b49b5U, 0xd132838dU);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000088d0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x81c0001eU);
    WR1_PROG(REG_0000H, 0x00013803U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000050U);
    WR1_PROG(REG_00E0H, 0x8088001eU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x00000022U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000070U);
    WR1_PROG(REG_00E0H, 0x8088001eU);
    WR1_PROG(REG_0000H, 0x00008323U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x0000480cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a2b89bU));
    r_tsip_func080();
    r_tsip_func100(0x43cdaadaU, 0x3f4ca063U, 0x70147f11U, 0x49a1e42cU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(1224);
    r_tsip_func100(0xa62f958aU, 0xeb69b1faU, 0x9e5b05e9U, 0xd80f5904U);
    r_tsip_func314(1224 + 64);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x81c0001eU);
    WR1_PROG(REG_0000H, 0x00013803U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_00E0H, 0x800103a0U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x000000adU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0000H, 0x0000031fU);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WR1_PROG(REG_0104H, 0x00000767U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x40000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
    WR1_PROG(REG_0034H, 0x00000030U);
    WR1_PROG(REG_0024H, 0x80001dc0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00ECH, 0x3800dbbeU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x501a6c42U, 0x940dd84bU, 0x6d6be67dU, 0xe9d6ee5dU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0024H, 0x00000991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000d375U);
        r_tsip_func101(0x913f1bedU, 0x680eab4fU, 0x7ac8eba4U, 0xee12db39U);
    }
    else
    {
        WR1_PROG(REG_0024H, 0x00000981U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00ECH, 0x0000d775U);
        r_tsip_func101(0x0619f006U, 0x60ab7f8cU, 0xab71023bU, 0x3aafae1fU);
    }

    r_tsip_func100(0x4fbacb14U, 0x1e656b45U, 0x9b4b0815U, 0x0f38a06bU);
    WR1_PROG(REG_0034H, 0x00000c00U);
    WR1_PROG(REG_0024H, 0x8000e0c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013d2cc1U));
    r_tsip_func080();
    r_tsip_func100(0xfc54977dU, 0xda3c64a6U, 0x89a10a79U, 0x18370282U);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000024U);
    r_tsip_func313(1428);
    r_tsip_func100(0x0c8f4ce7U, 0x630b67ffU, 0x2d4a3073U, 0x9a68e489U);
    r_tsip_func314(1428 + 64);
    r_tsip_func100(0xc88791acU, 0x488af16aU, 0xb8595b24U, 0xddf35a04U);
    WR1_PROG(REG_0028H, 0x00870001U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000050U);
    WR1_PROG(REG_00E0H, 0x8188001eU);
    WR1_PROG(REG_0000H, 0x00003823U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000070U);
    WR1_PROG(REG_00E0H, 0x8188001eU);
    WR1_PROG(REG_0000H, 0x00003823U);
    WR1_PROG(REG_002CH, 0x00000010U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000019a1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x0000c80cU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x01a2b89bU));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(1224);
    WR1_PROG(REG_00ECH, 0x0000d776U);
    WR1_PROG(REG_00ECH, 0x3800db75U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0xa17271f6U, 0x193570acU, 0xf81826cdU, 0x357a99c9U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00000991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x43fd02c3U, 0x9eb11a72U, 0x58bd47ecU, 0xda8b7160U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_00ECH, 0x0000d376U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_0104H, 0x00000257U);
            WR1_PROG(REG_002CH, 0x00000050U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
            WR1_PROG(REG_002CH, 0x00000110U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_002CH, 0x00000050U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0028H, 0x00bf0001U);
            r_tsip_func101(0x8032cb88U, 0x17743a3aU, 0x10a53a4dU, 0xdc4d0ec3U);
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x0000d776U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WR1_PROG(REG_0104H, 0x00000067U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0028H, 0x00bf0001U);
            r_tsip_func101(0xe19f5db1U, 0x9d3e82f8U, 0xf6ba907aU, 0x70d274fdU);
        }
    }
    else
    {
        WR1_PROG(REG_0024H, 0x000009c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x00001991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_001CH, 0x00210000U);
        r_tsip_func100(0x4391ea9bU, 0xd1aee7bdU, 0x39ec8f96U, 0xb01bfa11U);
        WR1_PROG(REG_001CH, 0x00400000U);
        WR1_PROG(REG_01D0H, 0x00000000U);
        if (CHCK_STS(REG_001CH, 22U, 1U))
        {
            WR1_PROG(REG_00ECH, 0x0000d376U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_0104H, 0x00000257U);
            WR1_PROG(REG_002CH, 0x00000050U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
            WR1_PROG(REG_002CH, 0x00000110U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0xFFFFFFFFU));
            WR1_PROG(REG_002CH, 0x00000050U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0028H, 0x00bf0001U);
            r_tsip_func101(0x6deb20b0U, 0x26047567U, 0xb8fd43bbU, 0x5cf60db0U);
        }
        else
        {
            WR1_PROG(REG_00ECH, 0x0000d776U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_002CH, 0x00000010U);
            WR1_PROG(REG_0104H, 0x00000067U);
            WAIT_STS(REG_0104H, 31U, 1U);
            WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
            WR1_PROG(REG_0028H, 0x00bf0001U);
            r_tsip_func101(0x736292ebU, 0x50e70cb3U, 0x7f42e7d6U, 0xd2b808d6U);
        }
    }

    r_tsip_func100(0xcc25c1cfU, 0xf0eea244U, 0x8818452aU, 0xea543442U);
    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04000189U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x02000189U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04000189U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x02000189U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016be062U));
    r_tsip_func080();
    r_tsip_func100(0xe7ecd477U, 0x05cd4aa5U, 0x73e05f30U, 0xad2ea67eU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(1360);
    r_tsip_func100(0x40f39c6eU, 0xf9a783c9U, 0x56c5df78U, 0xba4ec7a8U);
    r_tsip_func314(1360 + 64);
    r_tsip_func100(0xcb990d84U, 0x3c26b815U, 0x32624f57U, 0x1900c92eU);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000008U);
    WR1_PROG(REG_00E0H, 0x8081001eU);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_00ECH, 0x000037dcU);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016be062U));
    r_tsip_func080();
    r_tsip_func100(0xb7201b31U, 0xa8c0f4ddU, 0x2bbb8715U, 0x174cd1dfU);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000012U);
    r_tsip_func312(1360);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x017da167U));
    r_tsip_func080();
    r_tsip_func100(0xc6431c11U, 0x9f625c6cU, 0x3241f9edU, 0xd4320651U);
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000010U);
    r_tsip_func312(1156);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_00E0H, 0x80010380U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00E0H, 0x810103c0U);
    WR1_PROG(REG_0000H, 0x00003807U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x00001191U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00E0H, 0x81010380U);
    WR1_PROG(REG_0000H, 0x00003807U);
    WR1_PROG(REG_002CH, 0x00000012U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_002CH, 0x00000000U);
    WR1_PROG(REG_0024H, 0x0000080aU);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_00E0H, 0x800103c0U);
    WR1_PROG(REG_0000H, 0x00008307U);
    WR1_PROG(REG_002CH, 0x00000020U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x00008fc0U);
    WR1_PROG(REG_00ECH, 0x0000000fU);
    WR1_PROG(REG_00ECH, 0x0000d777U);
    WR1_PROG(REG_00ECH, 0x0000b7a0U);
    WR1_PROG(REG_00ECH, 0x00000010U);
    WR1_PROG(REG_00ECH, 0x3000dbc3U);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x00002bddU);
    WR1_PROG(REG_00ECH, 0x00070020U);
    WR1_PROG(REG_00ECH, 0x0000d377U);
    WR1_PROG(REG_00ECH, 0x00000b9cU);
    WR1_PROG(REG_00ECH, 0x00002b9eU);
    WR1_PROG(REG_00ECH, 0x000037dcU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x013d2cc1U));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1428);
    WR1_PROG(REG_00ECH, 0x00000bffU);
    WR1_PROG(REG_00ECH, 0x3800db77U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x17e1f625U, 0x727b2518U, 0x01846273U, 0xecf570a1U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0x8ed6a813U, 0x2aab6149U, 0x511d018aU, 0xcdde3342U);
        WR1_PROG(REG_00E0H, 0x810103c0U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (oLoop2 = 0; oLoop2 < S_RAM[0]; oLoop2 = oLoop2 + 1)
        {
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x04001991U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000004U);
            WR1_PROG(REG_0024H, 0x82001191U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0028H, 0x00bf0001U);
            WR1_PROG(REG_00ECH, 0x00002fe0U);
            r_tsip_func101(0xab95a5beU, 0xbd409b85U, 0x0eb7b056U, 0xf434a75bU);
        }

        r_tsip_func101(0xf0c5edadU, 0xc68a9ad8U, 0x9e2d4d72U, 0xbdd911f1U);
    }
    else
    {
        r_tsip_func100(0xde4810a6U, 0xb3766fb1U, 0x52a90656U, 0x7c40420fU);
        WR1_PROG(REG_00E0H, 0x810103c0U);
        WR1_PROG(REG_0004H, 0x00000607U);
        WAIT_STS(REG_0004H, 30U, 1U);
        RD1_ADDR(bswap_32big(REG_0100H), &S_RAM[0]);
        for (oLoop2 = 0; oLoop2 < S_RAM[0]; oLoop2 = oLoop2 + 1)
        {
            WR1_PROG(REG_0024H, 0x000009c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x04001981U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000040c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0028H, 0x00800001U);
            WR1_PROG(REG_0024H, 0x000011c0U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0034H, 0x00000004U);
            WR1_PROG(REG_0024H, 0x82001181U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0024H, 0x000080c1U);
            WAIT_STS(REG_0024H, 21U, 0U);
            WR1_PROG(REG_0028H, 0x00bf0001U);
            WR1_PROG(REG_00ECH, 0x00002fe0U);
            r_tsip_func101(0x6289918dU, 0x2750c0cfU, 0x550e780cU, 0xa3548d74U);
        }

        r_tsip_func101(0x2dabb5d0U, 0xaf193a8eU, 0xab3e9b01U, 0x4ce0fcd4U);
    }

    WR1_PROG(REG_00ECH, 0x38000bdfU);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00260000U);
    WR1_PROG(REG_001CH, 0x00402000U);
    r_tsip_func100(0x11d7bd17U, 0xb3f9543dU, 0x222df84aU, 0x58fe4bd4U);
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000008U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016be062U));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1360);
    WR1_PROG(REG_00ECH, 0x3800db76U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x9910041cU, 0xae7216d8U, 0xa2b90b21U, 0xdd851c24U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func315(0x00000190U);
        r_tsip_func101(0xc6b7f5e9U, 0xbf3e5c05U, 0x498cee14U, 0x1a639ed4U);
    }
    else
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00E0H, 0x8181001eU);
        WR1_PROG(REG_0000H, 0x00003807U);
        WR1_PROG(REG_002CH, 0x00000090U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        r_tsip_func101(0x20c1ab6eU, 0xa3d54792U, 0xe9797816U, 0x1f82fd47U);
    }

    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04001981U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x82001181U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x00000bdeU);
    WR1_PROG(REG_00ECH, 0x02816fdeU);
    WR1_PROG(REG_00ECH, 0x30008bc0U);
    WR1_PROG(REG_00ECH, 0x00000000U);
    WR1_PROG(REG_00ECH, 0x00020020U);
    WR1_PROG(REG_00ECH, 0x0000d378U);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d778U);
    WR1_PROG(REG_00ECH, 0x00000080U);
    r_tsip_func100(0x62aeb5c4U, 0xac68c432U, 0x45dae3edU, 0xfa18cd81U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016efbeaU));
    r_tsip_func080();
    r_tsip_func100(0xdbd28e3cU, 0xc5ce433eU, 0x5fc272d0U, 0x877810daU);
    WR1_PROG(REG_0000H, 0x00012303U);
    WR1_PROG(REG_002CH, 0x00000022U);
    r_tsip_func313(1292);
    r_tsip_func100(0x9da7ca2bU, 0x53c3dc78U, 0x94ec4c45U, 0xbcd2707eU);
    r_tsip_func314(1292 + 64);
    r_tsip_func100(0x8d53dc6eU, 0x7047688fU, 0x615db2adU, 0x1b0c200aU);
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
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_0024H, 0x000001c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
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
    r_tsip_func101(0xa9b91158U, 0x663c855cU, 0xb0aa45dbU, 0xcbf1a689U);
    r_tsip_func310();
    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x000000a0U);
    WR1_PROG(REG_00E0H, 0x81c0001eU);
    WR1_PROG(REG_0000H, 0x00013803U);
    WR1_PROG(REG_002CH, 0x00000014U);
    WAIT_STS(REG_0000H, 25U, 0U);
    WR1_PROG(REG_001CH, 0x00001800U);
    WR1_PROG(REG_00ECH, 0x3000db7dU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d76bU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d36bU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x000037d9U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000098U);
    r_tsip_func101(0xe182800aU, 0xee3a6557U, 0x9fb73eedU, 0xc681665dU);
    r_tsip_func310();
    r_tsip_func100(0x5645caedU, 0xc7a7d7afU, 0xe233be38U, 0x38a19217U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x017da167U));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1156);
    WR1_PROG(REG_00ECH, 0x3000db7eU);
    WR1_PROG(REG_00ECH, 0x00030020U);
    WR1_PROG(REG_00ECH, 0x0000d76bU);
    WR1_PROG(REG_00ECH, 0x00000060U);
    WR1_PROG(REG_00ECH, 0x0000d36bU);
    WR1_PROG(REG_00ECH, 0x00000080U);
    WR1_PROG(REG_00ECH, 0x000037d8U);
    WR1_PROG(REG_00ECH, 0x0000b400U);
    WR1_PROG(REG_00ECH, 0x00000099U);
    r_tsip_func101(0x7c73bf46U, 0x51f51d73U, 0x4b1cb3f0U, 0xe4d2e723U);
    r_tsip_func310();
    r_tsip_func100(0xb58e482dU, 0x44e39e1fU, 0xc5c24205U, 0x7be6d159U);
    WR1_PROG(REG_0104H, 0x00000058U);
    WR1_PROG(REG_00E0H, 0x80010020U);
    WAIT_STS(REG_0104H, 31U, 1U);
    WR1_PROG(REG_0100H, bswap_32big(0x016efbeaU));
    r_tsip_func080();
    WR1_PROG(REG_0000H, 0x00013203U);
    WR1_PROG(REG_002CH, 0x00000014U);
    r_tsip_func312(1292);
    WR1_PROG(REG_00ECH, 0x3800db78U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x742064dfU, 0x766df92bU, 0xdb9b61b3U, 0x00a8595fU);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0104H, 0x00000257U);
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000001U));
        WR1_PROG(REG_002CH, 0x00000190U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0xFFFFFFFFU));
        WR1_PROG(REG_002CH, 0x00000050U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x00000000U));
        WR1_PROG(REG_0028H, 0x00bf0001U);
        r_tsip_func101(0x1bc1315bU, 0x6171a6c4U, 0xb50763fcU, 0x25aa4da1U);
    }
    else
    {
        r_tsip_func101(0x2723ff77U, 0x173bd6c5U, 0x38cb8bc9U, 0xad933721U);
    }

    WR1_PROG(REG_0024H, 0x000009c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x04001981U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000040c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00800001U);
    WR1_PROG(REG_0024H, 0x000011c0U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0034H, 0x00000004U);
    WR1_PROG(REG_0024H, 0x82001181U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0024H, 0x000080c1U);
    WAIT_STS(REG_0024H, 21U, 0U);
    WR1_PROG(REG_0028H, 0x00bf0001U);
    WR1_PROG(REG_00ECH, 0x3800db79U);
    WR1_PROG(REG_00E0H, 0x00000080U);
    WR1_PROG(REG_001CH, 0x00A60000U);
    r_tsip_func100(0x12585f09U, 0xeabb7adaU, 0x87ebb395U, 0xa5583f07U);
    WR1_PROG(REG_001CH, 0x00400000U);
    WR1_PROG(REG_01D0H, 0x00000000U);
    if (CHCK_STS(REG_001CH, 22U, 1U))
    {
        r_tsip_func100(0x2ffddafbU, 0x727da666U, 0xaf66926cU, 0x3d6c5be8U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0034H, 0x00000400U);
        WR1_PROG(REG_0024H, 0x800080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04000991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000040c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x800011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x02816fdeU);
        WR1_PROG(REG_00ECH, 0x30008bc0U);
        WR1_PROG(REG_00ECH, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00020020U);
        WR1_PROG(REG_00ECH, 0x0000d368U);
        WR1_PROG(REG_00ECH, 0x00000060U);
        WR1_PROG(REG_00ECH, 0x0000d768U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_00ECH, 0x0000001cU);
        WR1_PROG(REG_00E0H, 0x8081001eU);
        WR1_PROG(REG_0000H, 0x00008307U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01a2b89bU));
        r_tsip_func080();
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000014U);
        r_tsip_func312(1224);
        WR1_PROG(REG_0024H, 0x000019c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x04000991U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x0000c0c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_0034H, 0x00000004U);
        WR1_PROG(REG_0024H, 0x800011c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x02001191U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
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
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0024H, 0x000098d0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        r_tsip_func101(0x38ef3aceU, 0xd1e94a3bU, 0x711aeb73U, 0x3d2fecacU);
    }
    else
    {
        r_tsip_func100(0x992be21fU, 0xe8007766U, 0x7fb7aa9dU, 0x58c86383U);
        WR1_PROG(REG_00ECH, 0x00000bdeU);
        WR1_PROG(REG_00ECH, 0x02816fdeU);
        WR1_PROG(REG_00ECH, 0x30008bc0U);
        WR1_PROG(REG_00ECH, 0x00000000U);
        WR1_PROG(REG_00ECH, 0x00020020U);
        WR1_PROG(REG_00ECH, 0x0000d368U);
        WR1_PROG(REG_00ECH, 0x00000060U);
        WR1_PROG(REG_00ECH, 0x0000d768U);
        WR1_PROG(REG_00ECH, 0x00000080U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_00ECH, 0x0000001cU);
        WR1_PROG(REG_00E0H, 0x8081001eU);
        WR1_PROG(REG_0000H, 0x00008307U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_0028H, 0x00800001U);
        WR1_PROG(REG_00ECH, 0x0000b7c0U);
        WR1_PROG(REG_00ECH, 0x00000018U);
        WR1_PROG(REG_0024H, 0x000001c0U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_0024H, 0x000080c1U);
        WAIT_STS(REG_0024H, 21U, 0U);
        WR1_PROG(REG_00E0H, 0x8081001eU);
        WR1_PROG(REG_0000H, 0x00008307U);
        WR1_PROG(REG_002CH, 0x00000020U);
        WAIT_STS(REG_0000H, 25U, 0U);
        WR1_PROG(REG_001CH, 0x00001800U);
        WR1_PROG(REG_0028H, 0x00bf0001U);
        WR1_PROG(REG_00ECH, 0x0000d772U);
        WR1_PROG(REG_0104H, 0x00000058U);
        WR1_PROG(REG_00E0H, 0x80010020U);
        WAIT_STS(REG_0104H, 31U, 1U);
        WR1_PROG(REG_0100H, bswap_32big(0x01a2b89bU));
        r_tsip_func080();
        WR1_PROG(REG_0000H, 0x00013203U);
        WR1_PROG(REG_002CH, 0x00000010U);
        r_tsip_func312(1224);
        r_tsip_func101(0x4e4f45f2U, 0x28ece73fU, 0x3f07bc29U, 0xe89bb461U);
    }

    WR1_PROG(REG_00ECH, 0x0000b7c0U);
    WR1_PROG(REG_00ECH, 0x00000024U);
    WR1_PROG(REG_00ECH, 0x0000381eU);
    WR1_PROG(REG_00ECH, 0x00007c00U);
    WR1_PROG(REG_001CH, 0x00602000U);
}
