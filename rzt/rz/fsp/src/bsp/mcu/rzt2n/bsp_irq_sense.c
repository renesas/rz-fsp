/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/** Array of GICD_ICFGR initialization value. */
const uint32_t BSP_GICD_ICFGR_INIT[BSP_EVENT_ARRAY_NUM] =
{
    0xAAAAAAAAUL,                      /* event No. 0 to 15    */
    0xAAAAAAAAUL,                      /* event No. 16 to 31   */
    0xAAAAAAAAUL,                      /* event No. 32 to 47   */
    0xAAAAAAAAUL,                      /* event No. 48 to 63   */
    0xAAAAAAAAUL,                      /* event No. 64 to 79   */
    0x00000000UL,                      /* event No. 80 to 95   */
    0xAAAAAAA8UL,                      /* event No. 96 to 111  */
    0xAAAAAAAAUL,                      /* event No. 112 to 127 */
    0xAAAAAAAAUL,                      /* event No. 128 to 143 */
    0xAAAAAAAAUL,                      /* event No. 144 to 159 */
    0xAAAAAAAAUL,                      /* event No. 160 to 175 */
    0xAAAAAAAAUL,                      /* event No. 176 to 191 */
    0xAAAAAAAAUL,                      /* event No. 192 to 207 */
    0xAAAAAAAAUL,                      /* event No. 208 to 223 */
    0xAAAAAAAAUL,                      /* event No. 224 to 239 */
    0x00AAAAAAUL,                      /* event No. 240 to 255 */
    0x00000000UL,                      /* event No. 256 to 271 */
    0xAA8AAA80UL,                      /* event No. 272 to 287 */
    0xAAAAAAA2UL,                      /* event No. 288 to 303 */
    0xAAAAAAAAUL,                      /* event No. 304 to 319 */
    0x02AAAAAAUL,                      /* event No. 320 to 335 */
    0xA8000000UL,                      /* event No. 336 to 351 */
    0xAAAAAAAAUL,                      /* event No. 352 to 367 */
    0xAAAAAA80UL,                      /* event No. 368 to 383 */
    0xAAAAA02AUL,                      /* event No. 384 to 399 */
    0xAAA80AAAUL,                      /* event No. 400 to 415 */
    0x0002AAAAUL,                      /* event No. 416 to 431 */
    0xAAA80000UL,                      /* event No. 432 to 447 */
    0xA0002A2AUL,                      /* event No. 448 to 463 */
    0xA0A0A0A2UL,                      /* event No. 464 to 479 */
    0xA0A0A0A0UL,                      /* event No. 480 to 495 */
    0x280000A0UL,                      /* event No. 496 to 511 */
    0x0A82A0A8UL,                      /* event No. 512 to 527 */
    0xAAAAA802UL,                      /* event No. 528 to 543 */
    0xA0AAAAAAUL,                      /* event No. 544 to 559 */
    0x00020A82UL,                      /* event No. 560 to 575 */
    0x00000000UL,                      /* event No. 576 to 591 */
    0x00000000UL,                      /* event No. 592 to 607 */
    0x00000000UL,                      /* event No. 608 to 623 */
    0x00000000UL,                      /* event No. 624 to 639 */
    0xAAA00000UL,                      /* event No. 640 to 655 */
    0xAAAAAAAAUL,                      /* event No. 656 to 671 */
    0xAAAAAAAAUL,                      /* event No. 672 to 687 */
    0xAAAAAAAAUL,                      /* event No. 688 to 703 */
    0xAAAAAAAAUL,                      /* event No. 704 to 719 */
    0x002AAAAAUL,                      /* event No. 720 to 735 */
};

const uint32_t BSP_GICR_SGI_PPI_ICFGR_INIT[BSP_EVENT_SGI_PPI_ARRAY_NUM] =
{
    0xAAAAAAAAUL,                      /* event SGI */
    0x00020000UL,                      /* event PPI */
};

#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
namespace RZT
{
 #endif
#endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU_RZT2N
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup RZT_BSP_MCU_RZT2N) */
#ifdef __FOR_FSP_DOCUMENT__
 #ifdef __cplusplus
}
 #endif
#endif

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
