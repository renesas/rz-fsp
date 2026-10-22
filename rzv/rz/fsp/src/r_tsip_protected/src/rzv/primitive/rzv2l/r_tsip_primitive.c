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

#if TSIP_POLLING_LOOP_LIMIT
 #include "bsp_api.h"
 #include "r_tsip_addr.h"
#endif

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

#if TSIP_POLLING_LOOP_LIMIT
static uintptr_t gs_tsip_old_mask_level = 0U;
#endif

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

#if TSIP_POLLING_LOOP_LIMIT
jmp_buf g_tsip_jmp_buf = {0};
#endif

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

#if TSIP_POLLING_LOOP_LIMIT

/*
 * To avoid rebuilding all primitive functions every time, they do not include bsp_api.h.
 * Instead, these functions are defined as global functions.
 */

void r_tsip_wait_sts (volatile uint32_t * reg, uint8_t bitPos, uint8_t value)
{
    uint32_t loop = TSIP_POLLING_LOOP_LIMIT;

    while (!CHCK_STS(*reg, bitPos, value) && --loop)
    {
        ;
    }

    if (!loop)
    {
        /* Critical section enter */
        gs_tsip_old_mask_level = FSP_CRITICAL_SECTION_GET_CURRENT_STATE();
        FSP_CRITICAL_SECTION_SET_STATE(FSP_CRITICAL_SECTION_IRQ_MASK_SET);

        /* Abort */
        longjmp(g_tsip_jmp_buf, 1);
    }
}

void r_tsip_critical_section_exit (void)
{
    FSP_CRITICAL_SECTION_SET_STATE(gs_tsip_old_mask_level);
}

#endif
