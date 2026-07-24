/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef __BSP_DDR_H__
 #define __BSP_DDR_H__

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/*******************************************************************************************************************//**
 * @addtogroup RZT_BSP_MCU
 * @{
 **********************************************************************************************************************/

/** @} (end addtogroup RZT_BSP_MCU) */
 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

/***********************************************************************************************************************
 * Includes <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Result of function */
 #define BSP_PRV_DDRTOP_OK            (uint32_t) (0)
 #define BSP_PRV_DDRTOP_ERR           (uint32_t) (-1)

 #define BSP_DDRTOP_PRIMARY_RANK      (0)
 #define BSP_DDRTOP_SCL_LANES         (3)

/* Setting paramater */
 #define BSP_DDRTOP_SCL_ROW_ADDR      (0b00000000000000000) /* 17bits */
 #define BSP_DDRTOP_SCL_COL_ADDR      (0b0000000000)        /* 10bits */
 #define BSP_DDRTOP_SCL_BA_ADDR       (0b000)               /* 3bits */

 #define BSP_DDRTOP_ECC_START_ADDR    (0x00000040ULL)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/
extern void bsp_ddr_init(void);

/*******************************************************************************************************************//**
 * Write an 32-bit value to a memory-mapped address.
 *
 * @param[in] addr
 * @param[in] value
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_mmio_write_32 (uintptr_t addr, uint32_t value)
{
    *(volatile uint32_t *) addr = value;
}

/*******************************************************************************************************************//**
 * Write an value to specific memory-mapped address.
 *
 * @param[in] addr
 * @param[in] data
 **********************************************************************************************************************/
__STATIC_INLINE void bsp_ddrtop_mc_apb_wr (uint32_t addr, uint32_t data)
{
    bsp_mmio_write_32(R_DDRSS_BASE + (addr << 2), data);
}

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/
 #if ((BSP_CLOCKS_PLL2_NORMAL != BSP_CFG_PLL2) && (1 == BSP_CFG_DDR_INIT_ENABLE))
  #error "When using DDR, please set to 'PLL2 is released from standby state'"
 #endif

#endif                                 /*__BSP_DDR_H__*/
