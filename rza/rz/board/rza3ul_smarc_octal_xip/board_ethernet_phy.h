/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : board_ethernet_phy.h
 * Version      : 1.00
 * Description  : board_ethernet phy header
 *********************************************************************************************************************/

#ifdef __cplusplus
namespace RZA
{
#endif

/*******************************************************************************************************************//**
 * @ingroup RZA_BOARD_RZA3UL_SMARC_OCTAL
 * @defgroup RZA_BOARD_RZA3UL_SMARC_OCTAL_ETHERNET_PHY Board Ethernet Phy
 * @brief Ethernet Phy information for this board.
 *
 * This is code specific to the SMARC board.
 *
 * @{
 **********************************************************************************************************************/

#ifndef BSP_ETHERNET_PHY_H
#define BSP_ETHERNET_PHY_H

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
#define ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE    (1)
#define ETHER_PHY_LSI_TYPE_KIT_COMPONENT           ETHER_PHY_LSI_TYPE_KSZ9131RNXI
#define BOARD_PHY_REF_CLK                          (1)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Public Functions
 **********************************************************************************************************************/

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif

/** @} (end defgroup BOARD_RZA3UL_SMARC_OCTAL_ETHERNET_PHY) */

#ifdef __cplusplus
}
#endif
