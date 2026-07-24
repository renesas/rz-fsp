/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_RIIC_H
 #define BSP_RIIC_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
 #define R_BSP_RIIC_7BIT_SLAVE_ADDRESS_SHIFT_POS           (1U)
 #define R_BSP_RIIC_10BIT_SLAVE_ADDRESS_UPPER_SHIFT_POS    (7U)
 #define R_BSP_RIIC_10BIT_SLAVE_ADDRESS_FLAG               (0x01U)
 #define R_BSP_RIIC_10BIT_SLAVE_ADDRESS_UPPER_MASK         (0x07U)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZG
{
  #endif
 #endif

/**********************************************************************************************************************
 * @addtogroup RZG_BSP_MPU_RZG3L
 * @{
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 *********************************************************************************************************************/
 #define R_BSP_RIIC_SET_SLAVE_ADDRESS(p_ctrl)                                                                 \
    /*7 bit mode selected, clear SAR. */                                                                      \
    if (I2C_SLAVE_ADDR_MODE_7BIT == p_ctrl->p_cfg->addr_mode)                                                 \
    {                                                                                                         \
        p_ctrl->p_reg->ICSARU0 = 0U;                                                                          \
        p_ctrl->p_reg->ICSARL0 = (uint8_t) (p_ctrl->p_cfg->slave << R_BSP_RIIC_7BIT_SLAVE_ADDRESS_SHIFT_POS); \
    }                                                                                                         \
    /* 10 bit mode selected, set SARx. */                                                                     \
    else                                                                                                      \
    {                                                                                                         \
        p_ctrl->p_reg->ICSARU0 =                                                                              \
            (uint8_t) (((p_ctrl->p_cfg->slave >> R_BSP_RIIC_10BIT_SLAVE_ADDRESS_UPPER_SHIFT_POS) |            \
                        R_BSP_RIIC_10BIT_SLAVE_ADDRESS_FLAG) & R_BSP_RIIC_10BIT_SLAVE_ADDRESS_UPPER_MASK);    \
        p_ctrl->p_reg->ICSARL0 = (uint8_t) (p_ctrl->p_cfg->slave);                                            \
    }

 #define R_BSP_RIIC_ENABLE_SLAVE_ADDRESS(p_ctrl)                                             \
    p_ctrl->p_reg->ICSER =                                                                   \
        (uint8_t) ((uint8_t) IIC_SLAVE_ICSER_SLAVE_ADDRESS_ENABLE_REGISTER_0 |               \
                   ((uint8_t) p_ctrl->p_cfg->general_call_enable << R_RIIC0_ICSER_GCE_Pos)); \


/** @} (end addtogroup RZG_BSP_MPU_RZG3L) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif                                 /* BSP_RIIC_H */
