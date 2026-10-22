/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_TSIP_ADDR_H
#define R_TSIP_ADDR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#if TSIP_POLLING_LOOP_LIMIT
 #include <setjmp.h>
 #include "bsp_api.h"
#endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#define TSIP_PRV_ADDR_BASE       (0x40440000UL)

#define TSIP_PRV_ADDR_TYPE       (1U)
#define TSIP_PRV_HASH_IP_TYPE    (1U)

#if TSIP_POLLING_LOOP_LIMIT
 #define TSIP_PRV_PRIMITIVE_ENTRY       \
    if (setjmp(g_tsip_jmp_buf))         \
    {                                   \
        r_tsip_critical_section_exit(); \
        return TSIP_RET_UNKNOWN;        \
    }
 #define TSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL \
    if (setjmp(g_tsip_jmp_buf))             \
    {                                       \
        r_tsip_critical_section_exit();     \
        return;                             \
    }
 #define WAIT_STS(reg, bitPos, value)    r_tsip_wait_sts(&(reg), (bitPos), (value))
#else
 #define TSIP_PRV_PRIMITIVE_ENTRY
 #define TSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL

/* WAIT_STS is defined in r_tsip_reg.h */
#endif

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

#if TSIP_POLLING_LOOP_LIMIT
extern jmp_buf g_tsip_jmp_buf;
#endif

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

#if TSIP_POLLING_LOOP_LIMIT
void r_tsip_wait_sts(volatile uint32_t * reg, uint8_t bitPos, uint8_t value);
void r_tsip_critical_section_exit(void);

#endif

#endif                                 /* R_TSIP_ADDR_H */
