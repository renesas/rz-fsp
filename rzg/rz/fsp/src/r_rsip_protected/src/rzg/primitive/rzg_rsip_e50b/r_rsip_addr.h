/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_RSIP_ADDR_H
#define R_RSIP_ADDR_H

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#if RSIP_POLLING_LOOP_LIMIT
 #include <setjmp.h>
#endif

#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

#if BSP_MCU_GROUP_RZG3E
 #define RSIP_PRV_ADDR_BASE      (0x404b0000UL)
#else
 #define RSIP_PRV_ADDR_BASE      (0x41850000UL)
#endif

#define RSIP_PRV_ADDR_TYPE       (5U)
#define RSIP_PRV_HASH_IP_TYPE    (5U)

#if RSIP_POLLING_LOOP_LIMIT
 #define RSIP_PRV_PRIMITIVE_ENTRY       \
    if (setjmp(g_rsip_jmp_buf))         \
    {                                   \
        r_rsip_critical_section_exit(); \
        return RSIP_RET_UNKNOWN;        \
    }
 #define RSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL \
    if (setjmp(g_rsip_jmp_buf))             \
    {                                       \
        r_rsip_critical_section_exit();     \
        return;                             \
    }
 #define WAIT_STS(reg, bitPos, value)    r_rsip_wait_sts(&(reg), (bitPos), (value))
#else
 #define RSIP_PRV_PRIMITIVE_ENTRY
 #define RSIP_PRV_PRIMITIVE_ENTRY_NO_RETVAL

/* WAIT_STS is defined in r_rsip_reg.h */
#endif

/**********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

#if RSIP_POLLING_LOOP_LIMIT
extern jmp_buf g_rsip_jmp_buf;
#endif

/**********************************************************************************************************************
 * Public Function Prototypes
 **********************************************************************************************************************/

#if RSIP_POLLING_LOOP_LIMIT
void r_rsip_wait_sts(volatile uint32_t * reg, uint8_t bitPos, uint8_t value);
void r_rsip_critical_section_exit(void);

#endif

#endif                                 /* R_RSIP_ADDR_H */
