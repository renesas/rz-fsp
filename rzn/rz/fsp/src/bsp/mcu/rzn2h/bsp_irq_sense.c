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

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
namespace RZN
{
#endif
#endif

/***********************************************************************************************************************
 * @addtogroup RZN_BSP_MCU_RZN2H
 * @{
 **********************************************************************************************************************/

/** Array of GICD_ICFGR initialization value. */

#if (1 == BSP_FEATURE_BSP_IRQ_CR52_SEL_SUPPORTED)

/* Interrupt types except for CR52 selected interrupt. */
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
    0xAAAAAAAAUL,                      /* event No. 240 to 255 */
    0xAAAAAAAAUL,                      /* event No. 256 to 271 */
    0xAAAAAAAAUL,                      /* event No. 272 to 287 */
    0xAAAAAAAAUL,                      /* event No. 288 to 303 */
    0xAAAAAAAAUL,                      /* event No. 304 to 319 */
    0xAAAAAAAAUL,                      /* event No. 320 to 335 */
    0xAAAAAAAAUL,                      /* event No. 336 to 351 */
    0xAAAAAAAAUL,                      /* event No. 352 to 367 */
    0x0002AAAAUL,                      /* event No. 368 to 383 */
    0x00000000UL,                      /* event No. 384 to 399 */
    0xAAAAA000UL,                      /* event No. 400 to 415 */
    0xAAAAAA2AUL,                      /* event No. 416 to 431 */
    0xAAAAAAAAUL,                      /* event No. 432 to 447 */
    0x2AAAAAAAUL,                      /* event No. 448 to 463 */
    0x80000000UL,                      /* event No. 464 to 479 */
    0xAAAAAAAAUL,                      /* event No. 480 to 495 */
    0xAAAAA80AUL,                      /* event No. 496 to 511 */
    0xAAAA02AAUL,                      /* event No. 512 to 527 */
    0xAA80AAAAUL,                      /* event No. 528 to 543 */
    0x002AAAAAUL,                      /* event No. 544 to 559 */
    0xAA800000UL,                      /* event No. 560 to 575 */
    0x8A82A2AAUL,                      /* event No. 576 to 591 */
    0x82828282UL,                      /* event No. 592 to 607 */
    0x82828282UL,                      /* event No. 608 to 623 */
    0xA0A00002UL,                      /* event No. 624 to 639 */
    0x082A0A82UL,                      /* event No. 640 to 655 */
    0xAAAAAAA0UL,                      /* event No. 656 to 671 */
    0xAAAAAAAAUL,                      /* event No. 672 to 687 */
    0x82AAAAAAUL,                      /* event No. 688 to 703 */
    0x00082A0AUL,                      /* event No. 704 to 719 */
    0x00000000UL,                      /* event No. 720 to 735 */
    0x00000000UL,                      /* event No. 736 to 751 */
    0x00000000UL,                      /* event No. 752 to 767 */
    0x00000000UL,                      /* event No. 768 to 783 */
    0x00000000UL,                      /* event No. 784 to 799 */
    0x00000000UL,                      /* event No. 800 to 815 */
    0x00000000UL,                      /* event No. 816 to 831 */
    0xAAAA0000UL,                      /* event No. 832 to 847 */
    0xAAAAAAAAUL,                      /* event No. 848 to 863 */
    0xAAAAAAAAUL,                      /* event No. 864 to 879 */
    0xAAAAAAAAUL,                      /* event No. 880 to 895 */
    0xAAAAAAAAUL,                      /* event No. 896 to 911 */
    0xAAAAAAAAUL,                      /* event No. 912 to 927 */
    0xAAAAAAAAUL,                      /* event No. 928 to 943 */
    0xAAAAAAAAUL,                      /* event No. 944 to 959 */
    0x002AAAAAUL,                      /* event No. 960 to 975 */
};

const uint32_t BSP_GICR_SGI_PPI_ICFGR_INIT[BSP_EVENT_SGI_PPI_ARRAY_NUM] =
{
    0xAAAAAAAAUL,                      /* event SGI */
    0x00020000UL,                      /* event PPI */
};

#endif

/** @} (end addtogroup BSP_MCU_RZN2H) */

#ifdef __FOR_FSP_DOCUMENT__
#ifdef __cplusplus
}
#endif
#endif

/*******************************************************************************************************************//**
 * Private global variables and functions
 **********************************************************************************************************************/
