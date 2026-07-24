/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/* Access to peripherals and board defines. */
#include "bsp_api.h"
#include "r_gether_phy.h"
#include "r_ether_phy_api.h"
#if (ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE)

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/* Vendor Specific PHY Registers */
 #define GETHER_PHY_REG_MMD_ACCESS_CONTROL            (0x0D)
 #define GETHER_PHY_REG_MMD_ADDRESS_DATA              (0x0E)

 #define GETHER_PHY_REG_MMD_ACCESS_CONTROL_ADDRESS    (0x0000)
 #define GETHER_PHY_REG_MMD_ACCESS_CONTROL_DATA       (0x4000)

 #define GETHER_PHY_DEV_RX_DDL_CONTROL                (2)
 #define GETHER_PHY_REG_RX_DDL_CONTROL                (76)
 #define GETHER_PHY_DEV_TX_DDL_CONTROL                (2)
 #define GETHER_PHY_REG_TX_DDL_CONTROL                (77)

 #define GETHER_PHY_REG_RX_DDL_CONTROL_BYPASS         (0x1000UL)
 #define GETHER_PHY_REG_TX_DDL_CONTROL_BYPASS         (0x1000UL)

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global function
 ***********************************************************************************************************************/
void gether_phy_targets_ksz9131rnxi_initialize(ether_phy_instance_ctrl_t * p_instance_ctrl);
bool gether_phy_target_ksz9131rnxi_is_support_link_partner_ability(ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                                   uint32_t                    line_speed_duplex);

/***********************************************************************************************************************
 * Private global variables and functions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Name: gether_phy_mmd_read
 * Description  : Read MMD register
 * Arguments    : p_instance_ctrl - Instance of Ehter PHY
 *                device_address  - Device address of the register
 *                reg_addr        - Address of the register
 * Return Value : Read data of the resigster
 ***********************************************************************************************************************/
static uint32_t gether_phy_mmd_read (ether_phy_instance_ctrl_t * p_instance_ctrl,
                                     uint32_t                    device_address,
                                     uint32_t                    reg_addr)
{
    uint32_t data = 0;

    R_GETHER_PHY_Write(p_instance_ctrl,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL_ADDRESS | device_address);
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_MMD_ADDRESS_DATA, reg_addr);
    R_GETHER_PHY_Write(p_instance_ctrl,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL_DATA | device_address);

    R_GETHER_PHY_Read(p_instance_ctrl, GETHER_PHY_REG_MMD_ADDRESS_DATA, &data);

    return data;
}                                      /* End of gether_phy_mmd_read */

/***********************************************************************************************************************
 * Function Name: gether_phy_mmd_write
 * Description  : Write MMD register
 * Arguments    : p_instance_ctrl - Instance of Ehter PHY
 *                device_address  - Device address of the register
 *                reg_addr        - Address of the register
 *                data            - Data to write
 * Return Value : none
 ***********************************************************************************************************************/
static void gether_phy_mmd_write (ether_phy_instance_ctrl_t * p_instance_ctrl,
                                  uint32_t                    device_address,
                                  uint32_t                    reg_addr,
                                  uint32_t                    data)
{
    R_GETHER_PHY_Write(p_instance_ctrl,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL_ADDRESS | device_address);
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_MMD_ADDRESS_DATA, reg_addr);
    R_GETHER_PHY_Write(p_instance_ctrl,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL,
                       GETHER_PHY_REG_MMD_ACCESS_CONTROL_DATA | device_address);
    R_GETHER_PHY_Write(p_instance_ctrl, GETHER_PHY_REG_MMD_ADDRESS_DATA, data);
}                                      /* End of gether_phy_mmd_write */

/***********************************************************************************************************************
 * Function Name: gether_phy_targets_initialize
 * Description  : PHY-LSI specific initialization processing
 * Arguments    : p_instance_ctrl - instance of Ehter PHY
 * Return Value : none
 ***********************************************************************************************************************/
void gether_phy_targets_ksz9131rnxi_initialize (ether_phy_instance_ctrl_t * p_instance_ctrl)
{
    uint32_t reg;

    /* Enable RXC DLL delay */
    reg  = gether_phy_mmd_read(p_instance_ctrl, GETHER_PHY_DEV_RX_DDL_CONTROL, GETHER_PHY_REG_RX_DDL_CONTROL);
    reg &= (uint32_t) ~GETHER_PHY_REG_RX_DDL_CONTROL_BYPASS;
    gether_phy_mmd_write(p_instance_ctrl, GETHER_PHY_DEV_RX_DDL_CONTROL, GETHER_PHY_REG_RX_DDL_CONTROL, reg);

    /* Enable TXC DLL delay */
    reg  = gether_phy_mmd_read(p_instance_ctrl, GETHER_PHY_DEV_TX_DDL_CONTROL, GETHER_PHY_REG_TX_DDL_CONTROL);
    reg &= (uint32_t) ~GETHER_PHY_REG_TX_DDL_CONTROL_BYPASS;
    gether_phy_mmd_write(p_instance_ctrl, GETHER_PHY_DEV_TX_DDL_CONTROL, GETHER_PHY_REG_TX_DDL_CONTROL, reg);
}                                      /* End of function gether_phy_targets_initialize() */

/***********************************************************************************************************************
 * Function Name: gether_phy_targets_is_support_link_partner_ability
 * Description  : Check if the PHY-LSI connected Ethernet controller supports link ability
 * Arguments    : p_instance_ctrl -
 *                    Ethernet control block
 *                line_speed_duplex -
 *                    Line speed duplex of link partner PHY-LSI
 * Return Value : bool
 ***********************************************************************************************************************/
bool gether_phy_target_ksz9131rnxi_is_support_link_partner_ability (ether_phy_instance_ctrl_t * p_instance_ctrl,
                                                                    uint32_t                    line_speed_duplex)
{
    FSP_PARAMETER_NOT_USED(p_instance_ctrl);
    FSP_PARAMETER_NOT_USED(line_speed_duplex);

    /* This PHY-LSI supports half and full duplex mode. */
    return true;
}                                      /* End of function ether_phy_targets_is_support_link_partner_ability() */

#endif /* ETHER_PHY_CFG_TARGET_KSZ9131RNXI_ENABLE */
