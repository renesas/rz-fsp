/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_OVERRIDE_H
 #define BSP_OVERRIDE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MCU. */
 #define BSP_OVERRIDE_ADC_INCLUDE
 #define BSP_OVERRIDE_ADC_INFO_T
 #define BSP_OVERRIDE_BSP_MST_ACC_CONTROL_IP_T
 #define BSP_OVERRIDE_BSP_ACC_CONTROL_IP_T
 #define BSP_OVERRIDE_BSP_SLV_ACC_CONTROL_IP_T
 #define BSP_OVERRIDE_BSP_MST_ACCESS_CONTROL
 #define BSP_OVERRIDE_BSP_ACCESS_CONTROL
 #define BSP_OVERRIDE_BSP_SLV_ACCESS_CONTROL
 #define BSP_OVERRIDE_BSP_PIN_T
 #define BSP_OVERRIDE_BSP_PORT_T
 #define BSP_OVERRIDE_CAN_INFO_T
 #define BSP_OVERRIDE_CANFD_ERROR_T
 #define BSP_OVERRIDE_CANFD_RX_BUFFER_T
 #define BSP_OVERRIDE_CANFD_RX_FIFO_T
 #define BSP_OVERRIDE_CANFD_RX_MB_T
 #define BSP_OVERRIDE_CANFD_TX_BUFFER_T
 #define BSP_OVERRIDE_CANFD_TX_MB_T
 #define BSP_OVERRIDE_DMAC_B_EXTERNAL_DETECTION_T
 #define BSP_OVERRIDE_DMAC_B_EXTETNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_T
 #define BSP_OVERRIDE_FSP_IP_T
 #define BSP_OVERRIDE_FSP_PRIV_CLOCK_T
 #define BSP_OVERRIDE_FSP_PRIV_CLOCK_DIVIDER_T
 #define BSP_OVERRIDE_FSP_PRIV_CLOCK_SELECTOR_T
 #define BSP_OVERRIDE_SPI_B_CLOCK_SOURCE_T
 #define BSP_OVERRIDE_SCI_B_SPI_CLOCK_SOURCE_T
 #define BSP_OVERRIDE_SCI_B_UART_CLOCK_SOURCE_T
 #define BSP_OVERRIDE_SCI_B_I2C_CLOCK_SOURCE_T
 #define BSP_OVERRIDE_TIMER_EVENT_T
 #define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
 #define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T
 #define BSP_OVERRIDE_TRANSFER_INFO_T
 #define BSP_OVERRIDE_TRANSFER_MODE_T
 #define BSP_OVERRIDE_TRANSFER_SIZE_T
 #define BSP_OVERRIDE_DISPLAY_IN_FORMAT_T
 #define BSP_OVERRIDE_DISPLAY_INPUT_CFG_T
 #define BSP_OVERRIDE_DISPLAY_DATA_SWAP_T

/* Override definitions. */

/*==============================================
 * Access Control Level Configuration Macros Overrides
 *==============================================*/

 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM0            (R_SYSC->SYS_SLVACCCTL0)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM0            (R_SYSC_SYS_SLVACCCTL0_SRAM0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SRAM1            (R_SYSC->SYS_SLVACCCTL0)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SRAM1            (R_SYSC_SYS_SLVACCCTL0_SRAM1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC0             (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC0             (R_SYSC_SYS_SLVACCCTL2_TZC0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC1             (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC1             (R_SYSC_SYS_SLVACCCTL2_TZC1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC5             (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC5             (R_SYSC_SYS_SLVACCCTL2_TZC5_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_TZC6             (R_SYSC->SYS_SLVACCCTL2)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_TZC6             (R_SYSC_SYS_SLVACCCTL2_TZC6_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CST              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CST              (R_SYSC_SYS_SLVACCCTL3_CST_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CPG              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CPG              (R_SYSC_SYS_SLVACCCTL3_CPG_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SYSC             (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SYSC             (R_SYSC_SYS_SLVACCCTL3_SYSC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SYC              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SYC              (R_SYSC_SYS_SLVACCCTL3_SYC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GIC              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GIC              (R_SYSC_SYS_SLVACCCTL3_GIC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_IA55_IM33        (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_IA55_IM33        (R_SYSC_SYS_SLVACCCTL3_IA55_IM33_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPIO             (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPIO             (R_SYSC_SYS_SLVACCCTL3_GPIO_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_MHU              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_MHU              (R_SYSC_SYS_SLVACCCTL3_MHU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPU              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPU              (R_SYSC_SYS_SLVACCCTL3_GPU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_H264             (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_H264             (R_SYSC_SYS_SLVACCCTL3_H264_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CRU              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CRU              (R_SYSC_SYS_SLVACCCTL3_CRU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_ISU              (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_ISU              (R_SYSC_SYS_SLVACCCTL3_ISU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DSIPHY           (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DSIPHY           (R_SYSC_SYS_SLVACCCTL3_DSIPHY_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DSILINK          (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DSILINK          (R_SYSC_SYS_SLVACCCTL3_DSILINK_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_LCDC             (R_SYSC->SYS_SLVACCCTL3)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_LCDC             (R_SYSC_SYS_SLVACCCTL3_LCDC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC0            (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC0            (R_SYSC_SYS_SLVACCCTL4_DMAC0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DMAC1            (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DMAC1            (R_SYSC_SYS_SLVACCCTL4_DMAC1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM0            (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM0            (R_SYSC_SYS_SLVACCCTL4_OSTM0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM1            (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM1            (R_SYSC_SYS_SLVACCCTL4_OSTM1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_OSTM2            (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_OSTM2            (R_SYSC_SYS_SLVACCCTL4_OSTM2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT0             (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT0             (R_SYSC_SYS_SLVACCCTL4_WDT0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT1             (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT1             (R_SYSC_SYS_SLVACCCTL4_WDT1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_WDT2             (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_WDT2             (R_SYSC_SYS_SLVACCCTL4_WDT2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RTC              (R_SYSC->SYS_SLVACCCTL4)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RTC              (R_SYSC_SYS_SLVACCCTL4_RTC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_MTU3A            (R_SYSC->SYS_SLVACCCTL5)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_MTU3A            (R_SYSC_SYS_SLVACCCTL5_MTU3A_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_POE3             (R_SYSC->SYS_SLVACCCTL5)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_POE3             (R_SYSC_SYS_SLVACCCTL5_POE3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPT              (R_SYSC->SYS_SLVACCCTL5)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPT              (R_SYSC_SYS_SLVACCCTL5_GPT_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_POEG             (R_SYSC->SYS_SLVACCCTL5)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_POEG             (R_SYSC_SYS_SLVACCCTL5_POEG_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_DDR              (R_SYSC->SYS_SLVACCCTL5)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_DDR              (R_SYSC_SYS_SLVACCCTL5_DDR_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_USBT             (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_USBT             (R_SYSC_SYS_SLVACCCTL6_USBT_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_USB20            (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_USB20            (R_SYSC_SYS_SLVACCCTL6_USB20_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_USB21            (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_USB21            (R_SYSC_SYS_SLVACCCTL6_USB21_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI0            (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI0            (R_SYSC_SYS_SLVACCCTL6_SDHI0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI1            (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI1            (R_SYSC_SYS_SLVACCCTL6_SDHI1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SDHI2            (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SDHI2            (R_SYSC_SYS_SLVACCCTL6_SDHI2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH0             (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH0             (R_SYSC_SYS_SLVACCCTL6_ETH0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_ETH1             (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_ETH1             (R_SYSC_SYS_SLVACCCTL6_ETH1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_PCIE             (R_SYSC->SYS_SLVACCCTL6)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_PCIE             (R_SYSC_SYS_SLVACCCTL6_PCIE_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C0             (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C0             (R_SYSC_SYS_SLVACCCTL7_I2C0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C1             (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C1             (R_SYSC_SYS_SLVACCCTL7_I2C1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C2             (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C2             (R_SYSC_SYS_SLVACCCTL7_I2C2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_I2C3             (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_I2C3             (R_SYSC_SYS_SLVACCCTL7_I2C3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_I3C              (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_I3C              (R_SYSC_SYS_SLVACCCTL7_I3C_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CANFD            (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CANFD            (R_SYSC_SYS_SLVACCCTL7_CANFD_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI0            (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI0            (R_SYSC_SYS_SLVACCCTL7_RSPI0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI1            (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI1            (R_SYSC_SYS_SLVACCCTL7_RSPI1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSPI2            (R_SYSC->SYS_SLVACCCTL7)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSPI2            (R_SYSC_SYS_SLVACCCTL7_RSPI2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF0            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF0            (R_SYSC_SYS_SLVACCCTL8_SCIF0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF1            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF1            (R_SYSC_SYS_SLVACCCTL8_SCIF1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF2            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF2            (R_SYSC_SYS_SLVACCCTL8_SCIF2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF3            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF3            (R_SYSC_SYS_SLVACCCTL8_SCIF3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF4            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF4            (R_SYSC_SYS_SLVACCCTL8_SCIF4_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SCIF5            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SCIF5            (R_SYSC_SYS_SLVACCCTL8_SCIF5_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSCI0            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSCI0            (R_SYSC_SYS_SLVACCCTL8_RSCI0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSCI1            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSCI1            (R_SYSC_SYS_SLVACCCTL8_RSCI1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSCI2            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSCI2            (R_SYSC_SYS_SLVACCCTL8_RSCI2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_RSCI3            (R_SYSC->SYS_SLVACCCTL8)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_RSCI3            (R_SYSC_SYS_SLVACCCTL8_RSCI3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF0            (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF0            (R_SYSC_SYS_SLVACCCTL9_SSIF0_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF1            (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF1            (R_SYSC_SYS_SLVACCCTL9_SSIF1_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF2            (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF2            (R_SYSC_SYS_SLVACCCTL9_SSIF2_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SSIF3            (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SSIF3            (R_SYSC_SYS_SLVACCCTL9_SSIF3_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_SPDIF            (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_SPDIF            (R_SYSC_SYS_SLVACCCTL9_SPDIF_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_PDM              (R_SYSC->SYS_SLVACCCTL9)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_PDM              (R_SYSC_SYS_SLVACCCTL9_PDM_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_ADC              (R_SYSC->SYS_SLVACCCTL10)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_ADC              (R_SYSC_SYS_SLVACCCTL10_ADC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_TSU              (R_SYSC->SYS_SLVACCCTL10)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_TSU              (R_SYSC_SYS_SLVACCCTL10_TSU_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_OTP              (R_SYSC->SYS_SLVACCCTL11)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_OTP              (R_SYSC_SYS_SLVACCCTL11_OTP_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_VBATT            (R_SYSC->SYS_SLVACCCTL11)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_VBATT            (R_SYSC_SYS_SLVACCCTL11_VBATT_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_BSC              (R_SYSC->SYS_SLVACCCTL11)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_BSC              (R_SYSC_SYS_SLVACCCTL11_BSC_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CA55             (R_SYSC->SYS_SLVACCCTL12)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CA55             (R_SYSC_SYS_SLVACCCTL12_CA55_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_CM33             (R_SYSC->SYS_SLVACCCTL12)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_CM33             (R_SYSC_SYS_SLVACCCTL12_CM33_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_LSI              (R_SYSC->SYS_SLVACCCTL14)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_LSI              (R_SYSC_SYS_SLVACCCTL14_LSI_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_AOF              (R_SYSC->SYS_SLVACCCTL16)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_AOF              (R_SYSC_SYS_SLVACCCTL16_AOF_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_LP               (R_SYSC->SYS_SLVACCCTL17)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_LP               (R_SYSC_SYS_SLVACCCTL17_LP_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_GPREG            (R_SYSC->SYS_SLVACCCTL18)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_GPREG            (R_SYSC_SYS_SLVACCCTL18_GPREG_SL_Pos)
 #define BSP_ACCESS_CONTROL_REG_ACCCNT_IPCONT           (R_SYSC->SYS_SLVACCCTL20)
 #define BSP_ACCESS_CONTROL_POS_ACCCNT_IPCONT           (R_SYSC_SYS_SLVACCCTL20_IPCONT_SL_Pos)

/***********************************************************************************************************************
 * Definition of macros to set value to TZC Registers
 **********************************************************************************************************************/

 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_SRAM_ACPU    (R_TZC_SRAM_ACPU->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_SRAM_MCPU    (R_TZC_SRAM_MCPU->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_XSPI         (R_TZC_XSPI->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_DDR_ACPU     (R_TZC_DDR_ACPU->REGION_ID_ACCESS_0)
 #define BSP_SLV_ACCCNT_REG_BSP_SLV_ACCCNT_DDR_VIDEO    (R_TZC_DDR_VIDEO->REGION_ID_ACCESS_0)

/***********************************************************************************************************************
 * Definition of macros to set value to Master Access Control Registers
 **********************************************************************************************************************/

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC0(level)         {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL0                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_AWPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_DMAC0_AWSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL0_DMAC0_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC0(level)          {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL0                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_ARPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC0_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_DMAC0_ARSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL0_DMAC0_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DMAC1(level)         {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL0                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_AWPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_DMAC1_AWSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL0_DMAC1_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DMAC1(level)          {R_SYSC->SYS_MSTACCCTL0 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL0                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_ARPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL0_DMAC1_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_DMAC1_ARSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL0_DMAC1_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GPU(level)           {R_SYSC->SYS_MSTACCCTL0 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL0                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL0_GPU_AWPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL0_GPU_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_GPU_AWSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL0_GPU_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GPU(level)            {R_SYSC->SYS_MSTACCCTL0 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL0                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL0_GPU_ARPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL0_GPU_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL0_GPU_ARSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL0_GPU_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SDHI0(level)         {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL1                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_AWPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_SDHI0_AWSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL1_SDHI0_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SDHI0(level)          {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL1                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_ARPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI0_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_SDHI0_ARSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL1_SDHI0_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SDHI1(level)         {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL1                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_AWPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_SDHI1_AWSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL1_SDHI1_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SDHI1(level)          {R_SYSC->SYS_MSTACCCTL1 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL1                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_ARPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL1_SDHI1_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_SDHI1_ARSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL1_SDHI1_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETHER0(level)      {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL1                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_GEther0_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL1_GEther0_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETHER0(level)       {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL1                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther0_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_GEther0_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL1_GEther0_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_GBETHER1(level)      {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL1                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_GEther1_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL1_GEther1_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_GBETHER1(level)       {R_SYSC->SYS_MSTACCCTL1 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL1                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL1_GEther1_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL1_GEther1_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL1_GEther1_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_HOST(level)    {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0H_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0H_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_0H_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_0H_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_HOST(level)     {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0H_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0H_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_0H_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_0H_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB20_FUNC(level)    {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0D_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0D_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_0D_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_0D_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB20_FUNC(level)     {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0D_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_0D_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_0D_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_0D_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB21_HOST(level)    {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1H_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1H_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_1H_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_1H_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB21_HOST(level)     {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1H_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1H_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_1H_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_1H_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_USB21_FUNC(level)    {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1D_AWPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1D_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_1D_AWSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_1D_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_USB21_FUNC(level)     {R_SYSC->SYS_MSTACCCTL2 =                          \
                                                                       (R_SYSC->SYS_MSTACCCTL2                       \
                                                                        & ~(uint32_t) (                              \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1D_ARPU_Msk   \
                                                                            |                                        \
                                                                            R_SYSC_SYS_MSTACCCTL2_USB2_1D_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL2_USB2_1D_ARSEL_Msk     \
                                                                       | (level <<                                   \
                                                                           R_SYSC_SYS_MSTACCCTL2_USB2_1D_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_H264(level)          {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL3                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_AWPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_H264_AWSEL_Msk     \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL3_H264_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_H264(level)           {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL3                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_ARPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL3_H264_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_H2642_ARSEL_Msk    \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL3_H264_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_LCDC(level)          {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL3                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL3_LCDC_AWPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL3_LCDC_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_LCDC_AWSEL_Msk     \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL3_LCDC_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_LCDC(level)           {R_SYSC->SYS_MSTACCCTL3 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL3                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL3_LCDC_ARPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL3_LCDC_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_LCDC_ARSEL_Msk     \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL3_LCDC_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_DSI(level)           {R_SYSC->SYS_MSTACCCTL3 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL3                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL3_DSI_AWPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL3_DSI_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_DSI_AWSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL3_DSI_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_DSI(level)            {R_SYSC->SYS_MSTACCCTL3 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL3                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL3_DSI_ARPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL3_DSI_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL3_DSI_ARSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL3_DSI_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_ISU(level)           {R_SYSC->SYS_MSTACCCTL4 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL4                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL4_ISU_AWPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL4_ISU_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL4_ISU_AWSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL4_ISU_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_ISU(level)            {R_SYSC->SYS_MSTACCCTL4 =                      \
                                                                       (R_SYSC->SYS_MSTACCCTL4                   \
                                                                        & ~(uint32_t) (                          \
                                                                            R_SYSC_SYS_MSTACCCTL4_ISU_ARPU_Msk   \
                                                                            |                                    \
                                                                            R_SYSC_SYS_MSTACCCTL4_ISU_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL4_ISU_ARSEL_Msk     \
                                                                       | (level <<                               \
                                                                           R_SYSC_SYS_MSTACCCTL4_ISU_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_CRU(level)           {R_SYSC->SYS_MSTACCCTL4 =                         \
                                                                       (R_SYSC->SYS_MSTACCCTL4                      \
                                                                        & ~(uint32_t) (                             \
                                                                            R_SYSC_SYS_MSTACCCTL4_CRU_VD_AWPU_Msk   \
                                                                            |                                       \
                                                                            R_SYSC_SYS_MSTACCCTL4_CRU_VD_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL4_CRU_VD_AWSEL_Msk     \
                                                                       | (level <<                                  \
                                                                           R_SYSC_SYS_MSTACCCTL4_CRU_VD_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_SDHI2(level)         {R_SYSC->SYS_MSTACCCTL6 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL6                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL6_SDHI2_AWPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL6_SDHI2_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL6_SDHI2_AWSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL6_SDHI2_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_SDHI2(level)          {R_SYSC->SYS_MSTACCCTL6 =                        \
                                                                       (R_SYSC->SYS_MSTACCCTL6                     \
                                                                        & ~(uint32_t) (                            \
                                                                            R_SYSC_SYS_MSTACCCTL6_SDHI2_ARPU_Msk   \
                                                                            |                                      \
                                                                            R_SYSC_SYS_MSTACCCTL6_SDHI2_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL6_SDHI2_ARSEL_Msk     \
                                                                       | (level <<                                 \
                                                                           R_SYSC_SYS_MSTACCCTL6_SDHI2_ARPU_Pos);}

 #define BSP_ACCESS_CONTROL_WRITE_MST_ACCCNT_PCIE(level)          {R_SYSC->SYS_MSTACCCTL6 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL6                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL6_PCIE_AWPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL6_PCIE_AWNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL6_PCIE_AWSEL_Msk     \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL6_PCIE_AWPU_Pos);}

 #define BSP_ACCESS_CONTROL_READ_MST_ACCCNT_PCIE(level)           {R_SYSC->SYS_MSTACCCTL6 =                       \
                                                                       (R_SYSC->SYS_MSTACCCTL6                    \
                                                                        & ~(uint32_t) (                           \
                                                                            R_SYSC_SYS_MSTACCCTL6_PCIE_ARPU_Msk   \
                                                                            |                                     \
                                                                            R_SYSC_SYS_MSTACCCTL6_PCIE_ARNS_Msk)) \
                                                                       | R_SYSC_SYS_MSTACCCTL6_PCIE_ARSEL_Msk     \
                                                                       | (level <<                                \
                                                                           R_SYSC_SYS_MSTACCCTL6_PCIE_ARPU_Pos);}

/*==============================================
 * CPG control macros Overrides
 *==============================================*/

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_LCDC(ip, ch)        {R_BSP_MODULE_CLKON(ip, ch); \
                                                        R_BSP_MSTP_START(ip, ch);   \
                                                        R_BSP_MODULE_RSTON(ip, ch); \
                                                        R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_LCDC(ip, ch)         {R_BSP_MSTP_STOP(ip, ch); \
                                                        R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_MIPI_DSI(ip, ch)    {R_BSP_MODULE_CLKON(ip, ch); \
                                                        R_BSP_MSTP_START(ip, ch);   \
                                                        R_BSP_MODULE_RSTON(ip, ch); \
                                                        R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_MIPI_DSI(ip, ch)     {R_BSP_MSTP_STOP(ip, ch); \
                                                        R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_RTC(ip, ch)         {R_BSP_MSTP_START(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_RTC(ip, ch)          {R_BSP_MSTP_STOP(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_PDM(ip, ch)         {R_BSP_MODULE_CLKON(ip, ch); \
                                                        R_BSP_MSTP_START(ip, ch)    \
                                                        R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_PDM(ip, ch)          {R_BSP_MSTP_STOP(ip, ch); \
                                                        R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_VBATT(ip, ch)       {R_BSP_MODULE_CLKON(ip, ch); \
                                                        R_BSP_MSTP_START(ip, ch);   \
                                                        R_BSP_MODULE_RSTON(ip, ch); \
                                                        R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_VBATT(ip, ch)        {R_BSP_MSTP_STOP(ip, ch); \
                                                        R_BSP_MODULE_CLKOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Cancel the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_START_FSP_IP_I3C(ip, ch)         {R_BSP_MODULE_CLKON(ip, ch); \
                                                        R_BSP_MSTP_START(ip, ch);   \
                                                        R_BSP_MODULE_RSTON(ip, ch); \
                                                        R_BSP_MODULE_RSTOFF(ip, ch);}

/*******************************************************************************************************************//**
 * Enables the module stop state.
 *
 * @param      ip       fsp_ip_t enum value for the module to be stopped
 * @param      ch       The channel. Use channel 0 for modules without channels.
 **********************************************************************************************************************/

 #define R_BSP_MODULE_STOP_FSP_IP_I3C(ip, ch)          {R_BSP_MSTP_STOP(ip, ch); \
                                                        R_BSP_MODULE_CLKOFF(ip, ch);}

/***********************************************************************************************************************
 * Definition of macros to control LCDC clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_LCDC(channel)            (R_CPG->CPG_CLKON_LCDC)
 #define BSP_CLKON_BIT_FSP_IP_LCDC(channel)            (7U << (R_CPG_CPG_CLKON_LCDC_CLK0_ON_Pos))

 #define BSP_CLKMON_REG_FSP_IP_LCDC(channel)           (R_CPG->CPG_CLKMON_LCDC)
 #define BSP_CLKMON_BIT_FSP_IP_LCDC(channel)           (7U << (R_CPG_CPG_CLKMON_LCDC_CLK0_MON_Pos))

 #define BSP_RST_REG_FSP_IP_LCDC(channel)              (R_CPG->CPG_RST_LCDC)
 #define BSP_RST_BIT_FSP_IP_LCDC(channel)              (1U << (R_CPG_CPG_RST_LCDC_UNIT0_RSTB_Pos))

 #define BSP_RSTMON_REG_FSP_IP_LCDC(channel)           (R_CPG->CPG_RSTMON_LCDC)
 #define BSP_RSTMON_BIT_FSP_IP_LCDC(channel)           (1U << (R_CPG_CPG_RSTMON_LCDC_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control MIPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_MIPI_DSI(channel)        (R_CPG->CPG_CLKON_MIPI_DSI)
 #define BSP_CLKON_BIT_FSP_IP_MIPI_DSI(channel)        (0x1FU << (R_CPG_CPG_CLKON_MIPI_DSI_CLK1_ON_Pos))

 #define BSP_CLKMON_REG_FSP_IP_MIPI_DSI(channel)       (R_CPG->CPG_CLKMON_MIPI_DSI)
 #define BSP_CLKMON_BIT_FSP_IP_MIPI_DSI(channel)       (0x1FU << (R_CPG_CPG_CLKMON_MIPI_DSI_CLK1_MON_Pos))

 #define BSP_RST_REG_FSP_IP_MIPI_DSI(channel)          (R_CPG->CPG_RST_MIPI_DSI)
 #define BSP_RST_BIT_FSP_IP_MIPI_DSI(channel)          (0x7U << (R_CPG_CPG_RST_MIPI_DSI_UNIT0_RSTB_Pos))

 #define BSP_RSTMON_REG_FSP_IP_MIPI_DSI(channel)       (R_CPG->CPG_RSTMON_MIPI_DSI)
 #define BSP_RSTMON_BIT_FSP_IP_MIPI_DSI(channel)       (0x7U << (R_CPG_CPG_RSTMON_MIPI_DSI_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control PDM clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_PDM(channel)             (R_CPG->CPG_CLKON_PDM)
 #define BSP_CLKON_BIT_FSP_IP_PDM(channel)             (3U << ((R_CPG_CPG_CLKON_PDM_CLK0_ON_Pos)))

 #define BSP_CLKMON_REG_FSP_IP_PDM(channel)            (R_CPG->CPG_CLKMON_PDM)
 #define BSP_CLKMON_BIT_FSP_IP_PDM(channel)            (3U << ((R_CPG_CPG_CLKMON_PDM_CLK0_MON_Pos)))

 #define BSP_RST_REG_FSP_IP_PDM(channel)               (R_CPG->CPG_RST_PDM)
 #define BSP_RST_BIT_FSP_IP_PDM(channel)               (0x1U << ((R_CPG_CPG_RST_PDM_UNIT0_RSTB_Pos)))

 #define BSP_RSTMON_REG_FSP_IP_PDM(channel)            (R_CPG->CPG_RSTMON_PDM)
 #define BSP_RSTMON_BIT_FSP_IP_PDM(channel)            (0x1U << ((R_CPG_CPG_RSTMON_PDM_RST0_MON_Pos)))

/***********************************************************************************************************************
 * Definition of macros to control SCI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_SCI(channel)             (R_CPG->CPG_CLKON_RSCI)
 #define BSP_CLKON_BIT_FSP_IP_SCI(channel)             (0x101U << (R_CPG_CPG_CLKON_RSCI_CLK0_ON_Pos + (channel)))

 #define BSP_CLKMON_REG_FSP_IP_SCI(channel)            (R_CPG->CPG_CLKMON_RSCI)
 #define BSP_CLKMON_BIT_FSP_IP_SCI(channel)            (0x101U << (R_CPG_CPG_CLKMON_RSCI_CLK0_MON_Pos + (channel)))

 #define BSP_RST_REG_FSP_IP_SCI(channel)               (R_CPG->CPG_RST_RSCI)
 #define BSP_RST_BIT_FSP_IP_SCI(channel)               (0x101U << (R_CPG_CPG_RST_RSCI_UNIT0_RSTB_Pos + (channel)))

 #define BSP_RSTMON_REG_FSP_IP_SCI(channel)            (R_CPG->CPG_RSTMON_RSCI)
 #define BSP_RSTMON_BIT_FSP_IP_SCI(channel)            (0x101U << (R_CPG_CPG_RSTMON_RSCI_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control RSPI clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_RSPI(channel)            (R_CPG->CPG_CLKON_RSPI)
 #define BSP_CLKON_BIT_FSP_IP_RSPI(channel)            (0x101U << (R_CPG_CPG_CLKON_RSPI_CLK0_ON_Pos + (channel)))

 #define BSP_CLKMON_REG_FSP_IP_RSPI(channel)           (R_CPG->CPG_CLKMON_RSPI)
 #define BSP_CLKMON_BIT_FSP_IP_RSPI(channel)           (0x101U << (R_CPG_CPG_CLKMON_RSPI_CLK0_MON_Pos + (channel)))

 #define BSP_RST_REG_FSP_IP_RSPI(channel)              (R_CPG->CPG_RST_RSPI)
 #define BSP_RST_BIT_FSP_IP_RSPI(channel)              (0x101U << (R_CPG_CPG_RST_RSPI_UNIT0_RSTB_Pos + (channel)))

 #define BSP_RSTMON_REG_FSP_IP_RSPI(channel)           (R_CPG->CPG_RSTMON_RSPI)
 #define BSP_RSTMON_BIT_FSP_IP_RSPI(channel)           (0x101U << (R_CPG_CPG_RSTMON_RSPI_RST0_MON_Pos + (channel)))

/***********************************************************************************************************************
 * Definition of macros to control VBATT clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_VBATT(channel)           (R_CPG->CPG_CLKON_VBAT)
 #define BSP_CLKON_BIT_FSP_IP_VBATT(channel)           (0x1U << (R_CPG_CPG_CLKON_VBAT_CLK0_ON_Pos))

 #define BSP_CLKMON_REG_FSP_IP_VBATT(channel)          (R_CPG->CPG_CLKMON_VBAT)
 #define BSP_CLKMON_BIT_FSP_IP_VBATT(channel)          (0x1U << (R_CPG_CPG_CLKMON_VBAT_CLK0_MON_Pos))

 #define BSP_RST_REG_FSP_IP_VBATT(channel)             (R_CPG->CPG_RST_VBAT)
 #define BSP_RST_BIT_FSP_IP_VBATT(channel)             (0x1U << (R_CPG_CPG_RST_VBAT_UNIT0_RSTB_Pos))

 #define BSP_RSTMON_REG_FSP_IP_VBATT(channel)          (R_CPG->CPG_RSTMON_VBAT)
 #define BSP_RSTMON_BIT_FSP_IP_VBATT(channel)          (0x1U << (R_CPG_CPG_RSTMON_VBAT_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control LCDC module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_LCDC(channel)             (R_CPG->CPG_BUS_PERI_VIDEO1_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_LCDC(channel)             (7U << (R_CPG_CPG_BUS_PERI_VIDEO1_MSTOP_MSTOP7_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control MIPI module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_MIPI_DSI(channel)         (R_CPG->CPG_BUS_PERI_VIDEO1_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_MIPI_DSI(channel)         (3U << R_CPG_CPG_BUS_PERI_VIDEO1_MSTOP_MSTOP5_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control PDM module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_PDM(channel)              (R_CPG->CPG_BUS_MCPU3_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_PDM(channel)              (1U << (R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP9_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control RTC module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_RTC(channel)              R_CPG->CPG_BUS_MCPU3_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_RTC(channel)              (1U << (R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP7_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control VBATT module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_VBATT(channel)            R_CPG->CPG_BUS_MCPU3_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_VBATT(channel)            (1U << (R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP8_ON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control I3C clock ON/OFF and reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_CLKON_REG_FSP_IP_I3C(channel)             (R_CPG->CPG_CLKON_I3C)
 #define BSP_CLKON_BIT_FSP_IP_I3C(channel)             (3U << (R_CPG_CPG_CLKON_I3C_CLK0_ON_Pos))

 #define BSP_CLKMON_REG_FSP_IP_I3C(channel)            (R_CPG->CPG_CLKMON_I3C)
 #define BSP_CLKMON_BIT_FSP_IP_I3C(channel)            (3U << (R_CPG_CPG_CLKMON_I3C_CLK0_MON_Pos))

 #define BSP_RST_REG_FSP_IP_I3C(channel)               (R_CPG->CPG_RST_I3C)
 #define BSP_RST_BIT_FSP_IP_I3C(channel)               (3U << (R_CPG_CPG_RST_I3C_UNIT0_RSTB_Pos))

 #define BSP_RSTMON_REG_FSP_IP_I3C(channel)            (R_CPG->CPG_RSTMON_I3C)
 #define BSP_RSTMON_BIT_FSP_IP_I3C(channel)            (3U << (R_CPG_CPG_RSTMON_I3C_RST0_MON_Pos))

/***********************************************************************************************************************
 * Definition of macros to control SCI module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_SCI(channel)              *((2U >                                              \
                                                          channel) ? &R_CPG->CPG_BUS_MCPU2_MSTOP : &R_CPG-> \
                                                         CPG_BUS_MCPU3_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_SCI(channel)              ((2U >                                                                   \
                                                         channel) ? (1U <<                                                      \
                                                                     (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP7_ON_Pos +                 \
                                                                      channel)) : (1U <<                                        \
                                                                                   (                                            \
                                                                                       R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP11_ON_Pos \
                                                                                       + channel)))

/***********************************************************************************************************************
 * Definition of macros to control ADC module START/STOP and clock ON/OFF, reset ON/OFF
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_ADC(channel)              *((channel ==                                  \
                                                          0) ? &R_CPG->CPG_BUS_MCPU2_MSTOP : &R_CPG-> \
                                                         CPG_BUS_PERI_VIDEO1_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_ADC(channel)              (1U << R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP14_ON_Pos)

 #define BSP_CLKON_REG_FSP_IP_ADC(channel)             (R_CPG->CPG_CLKON_ADC)
 #define BSP_CLKON_BIT_FSP_IP_ADC(channel)             (0x3U << (R_CPG_CPG_CLKON_ADC_CLK2_ON_Pos * channel))
 #define BSP_CLKMON_REG_FSP_IP_ADC(channel)            (R_CPG->CPG_CLKMON_ADC)
 #define BSP_CLKMON_BIT_FSP_IP_ADC(channel)            (0x3U << R_CPG_CPG_CLKMON_ADC_CLK2_MON_Pos * channel)
 #define BSP_RST_REG_FSP_IP_ADC(channel)               (R_CPG->CPG_RST_ADC)
 #define BSP_RST_BIT_FSP_IP_ADC(channel)               (0x3U << R_CPG_CPG_RST_ADC_UNIT2_RSTB_Pos * channel)
 #define BSP_RSTMON_REG_FSP_IP_ADC(channel)            (R_CPG->CPG_RSTMON_ADC)
 #define BSP_RSTMON_BIT_FSP_IP_ADC(channel)            (0x3U << R_CPG_CPG_RSTMON_ADC_RST2_MON_Pos * channel)

/***********************************************************************************************************************
 * Definition of macros to control TSU module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_TSU(channel)              R_CPG->CPG_BUS_PERI_VIDEO1_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_TSU(channel)              (1U << R_CPG_CPG_BUS_PERI_VIDEO1_MSTOP_MSTOP15_ON_Pos)

/***********************************************************************************************************************
 * Definition of macros to control WDT module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_WDT(channel)              R_CPG->CPG_BUS_REG0_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_WDT(channel)              (1U << (R_CPG_CPG_BUS_REG0_MSTOP_MSTOP0_ON_Pos + channel))

/***********************************************************************************************************************
 * Definition of macros to control I3C module START/STOP
 **********************************************************************************************************************/
 #define BSP_MSTP_REG_FSP_IP_I3C(channel)              R_CPG->CPG_BUS_MCPU3_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_I3C(channel)              (1U << (R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP10_ON_Pos))

 #define BSP_CLKON_REG_FSP_IP_XSPI(channel)            (R_CPG->CPG_CLKON_XSPI)
 #define BSP_CLKON_BIT_FSP_IP_XSPI(channel)            (0xFU << (R_CPG_CPG_CLKON_XSPI_CLK0_ON_Pos))
 #define BSP_CLKMON_REG_FSP_IP_XSPI(channel)           (R_CPG->CPG_CLKMON_XSPI)
 #define BSP_CLKMON_BIT_FSP_IP_XSPI(channel)           (0xFU << (R_CPG_CPG_CLKMON_XSPI_CLK0_MON_Pos))
 #define BSP_RST_REG_FSP_IP_XSPI(channel)              (R_CPG->CPG_RST_XSPI)
 #define BSP_RST_BIT_FSP_IP_XSPI(channel)              (3U << (R_CPG_CPG_RST_XSPI_UNIT0_RSTB_Pos))
 #define BSP_RSTMON_REG_FSP_IP_XSPI(channel)           (R_CPG->CPG_RSTMON_XSPI)
 #define BSP_RSTMON_BIT_FSP_IP_XSPI(channel)           (3U << (R_CPG_CPG_RSTMON_XSPI_RST0_MON_Pos))

 #define BSP_MSTP_REG_FSP_IP_SCIF(channel)             *((4U >=                                             \
                                                          channel) ? &R_CPG->CPG_BUS_MCPU2_MSTOP : &R_CPG-> \
                                                         CPG_BUS_MCPU3_MSTOP)
 #define BSP_MSTP_BIT_FSP_IP_SCIF(channel)             ((4U >=                                                \
                                                         channel) ? (1U <<                                    \
                                                                     (R_CPG_CPG_BUS_MCPU2_MSTOP_MSTOP1_ON_Pos \
                                                                      + channel))                             \
                                                        : (1U << R_CPG_CPG_BUS_MCPU3_MSTOP_MSTOP4_ON_Pos))
 #define BSP_MSTP_REG_FSP_IP_XSPI(channel)             R_CPG->CPG_BUS_MCPU1_MSTOP
 #define BSP_MSTP_BIT_FSP_IP_XSPI(channel)             (1U << R_CPG_CPG_BUS_MCPU1_MSTOP_MSTOP1_ON_Pos)

/*==============================================
 * IOPORT-Related Macros Overrides
 *==============================================*/

 #define OVERRIDE_IOPORT_PRV_PFS_PSEL_OFFSET    (24)

/*==============================================
 * SYSC-Related Macros Overrides
 *==============================================*/

 #define R_BSP_IM33_DISABLE()    {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 | \
                                                        R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}
 #define R_BSP_IM33_ENABLE()     {R_SYSC->SYS_LP_CTL7 = R_SYSC->SYS_LP_CTL7 & \
                                                        ~R_SYSC_SYS_LP_CTL7_IM33_MASK_Msk;}

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC IRQ
 **********************************************************************************************************************/
 #define BSP_INTC_IRQ_CLR_STATE_FLAG(channel)                                   \
    do                                                                          \
    {                                                                           \
        /* Dummy read the ISCR before clearing the ISTAT bit. */                \
        volatile uint32_t iscr = BSP_FEATURE_INTC_BASE_ADDR->ISCR;              \
        FSP_PARAMETER_NOT_USED(iscr);                                           \
        /* Clear the ISTAT bit. */                                              \
        BSP_FEATURE_INTC_BASE_ADDR->ISCR = ~(INTC_IRQ_CLR_REG_MASK << channel); \
        /* Dummy read the ISCR to prevent the interrupt cause that have been cleared from being accidentally accepted. \
         * Reference section "Clear Timing of Interrupt Cause" of the hardware manual. */ \
        iscr = BSP_FEATURE_INTC_BASE_ADDR->ISCR;                                          \
        FSP_PARAMETER_NOT_USED(iscr);                                                     \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC NMI
 **********************************************************************************************************************/
 #define BSP_INTC_NMI_CLR_STATE_FLAG()                             \
    do                                                             \
    {                                                              \
        /* Dummy read the NSCR before clearing the NSTAT bit. */   \
        volatile uint32_t nscr = BSP_FEATURE_INTC_BASE_ADDR->NSCR; \
        FSP_PARAMETER_NOT_USED(nscr);                              \
        /* Clear the NSTAT bit. */                                 \
        BSP_FEATURE_INTC_BASE_ADDR->NSCR_b.NSTAT = 0;              \
        /* Dummy read the NSCR to prevent the interrupt cause that have been cleared from being accidentally accepted. \
         * Reference section "Clear Timing of Interrupt Cause" of the hardware manual. */ \
        nscr = BSP_FEATURE_INTC_BASE_ADDR->NSCR;                                          \
        FSP_PARAMETER_NOT_USED(nscr);                                                     \
    } while (0);

/***********************************************************************************************************************
 * Definition of macros to clear state flag of INTC TINT
 **********************************************************************************************************************/
 #define BSP_INTC_TINT_CLR_STATE_FLAG(channel)                                   \
    do                                                                           \
    {                                                                            \
        /* Dummy read the TSCR before clearing the TSTAT bit. */                 \
        volatile uint32_t tscr = BSP_FEATURE_INTC_BASE_ADDR->TSCR;               \
        FSP_PARAMETER_NOT_USED(tscr);                                            \
        /* Clear the TSTAT bit. */                                               \
        BSP_FEATURE_INTC_BASE_ADDR->TSCR = ~(INTC_TINT_CLR_REG_MASK << channel); \
        /* Dummy read the TSCR to prevent the interrupt cause that should have been cleared from being accidentally \
         * accepted again. Reference section "Clear Timing of Interrupt Cause" of the hardware manual. */ \
        tscr = BSP_FEATURE_INTC_BASE_ADDR->TSCR;                                                          \
        FSP_PARAMETER_NOT_USED(tscr);                                                                     \
    } while (0);

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZG
{
  #endif
 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

 #define FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0_SEL    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0
 #define FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1_SEL    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1
 #define FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2_SEL    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2

/*==============================================
 * BSP-Related Definitions Overrides
 *==============================================*/

/** Superset list of all possible IO ports. */
typedef enum e_bsp_io_port
{
    BSP_IO_PORT_02 = 0x0000,           /* IO port 2 */
    BSP_IO_PORT_03 = 0x0100,           /* IO port 3 */
    BSP_IO_PORT_05 = 0x0300,           /* IO port 5 */
    BSP_IO_PORT_06 = 0x0400,           /* IO port 6 */
    BSP_IO_PORT_07 = 0x0500,           /* IO port 7 */
    BSP_IO_PORT_08 = 0x0600,           /* IO port 8 */
    BSP_IO_PORT_10 = 0x0800,           /* IO port 10 */
    BSP_IO_PORT_11 = 0x0900,           /* IO port 11 */
    BSP_IO_PORT_12 = 0x0A00,           /* IO port 12 */
    BSP_IO_PORT_13 = 0x0B00,           /* IO port 13 */
    BSP_IO_PORT_14 = 0x0C00,           /* IO port 14 */
    BSP_IO_PORT_15 = 0x0D00,           /* IO port 15 */
    BSP_IO_PORT_16 = 0x0E00,           /* IO port 16 */
    BSP_IO_PORT_17 = 0x0F00,           /* IO port 17 */
    BSP_IO_PORT_19 = 0x1100,           /* IO port 19 */
    BSP_IO_PORT_20 = 0x1200,           /* IO port 20 */
    BSP_IO_PORT_21 = 0x1300,           /* IO port 21 */
    BSP_IO_PORT_22 = 0x1400,           /* IO port 22 */
    BSP_IO_PORT_28 = 0x1A00            /* IO port 28 */
} bsp_io_port_t;

/** Superset list of all possible IO port pins. */
typedef enum e_bsp_io_port_pin_t
{
    BSP_IO_PORT_02_PIN_00 = 0x0000,        /* IO port 2 pin 0 */
    BSP_IO_PORT_02_PIN_01 = 0x0001,        /* IO port 2 pin 1 */

    BSP_IO_PORT_03_PIN_00 = 0x0100,        /* IO port 3 pin 0 */
    BSP_IO_PORT_03_PIN_01 = 0x0101,        /* IO port 3 pin 1 */
    BSP_IO_PORT_03_PIN_02 = 0x0102,        /* IO port 3 pin 2 */
    BSP_IO_PORT_03_PIN_03 = 0x0103,        /* IO port 3 pin 3 */
    BSP_IO_PORT_03_PIN_04 = 0x0104,        /* IO port 3 pin 4 */
    BSP_IO_PORT_03_PIN_05 = 0x0105,        /* IO port 3 pin 5 */
    BSP_IO_PORT_03_PIN_06 = 0x0106,        /* IO port 3 pin 6 */

    BSP_IO_PORT_05_PIN_00 = 0x0300,        /* IO port 5 pin 0 */
    BSP_IO_PORT_05_PIN_01 = 0x0301,        /* IO port 5 pin 1 */
    BSP_IO_PORT_05_PIN_02 = 0x0302,        /* IO port 5 pin 2 */
    BSP_IO_PORT_05_PIN_03 = 0x0303,        /* IO port 5 pin 3 */
    BSP_IO_PORT_05_PIN_04 = 0x0304,        /* IO port 5 pin 4 */
    BSP_IO_PORT_05_PIN_05 = 0x0305,        /* IO port 5 pin 5 */
    BSP_IO_PORT_05_PIN_06 = 0x0306,        /* IO port 5 pin 6 */

    BSP_IO_PORT_06_PIN_00 = 0x0400,        /* IO port 6 pin 0 */
    BSP_IO_PORT_06_PIN_01 = 0x0401,        /* IO port 6 pin 1 */
    BSP_IO_PORT_06_PIN_02 = 0x0402,        /* IO port 6 pin 2 */
    BSP_IO_PORT_06_PIN_03 = 0x0403,        /* IO port 6 pin 3 */
    BSP_IO_PORT_06_PIN_04 = 0x0404,        /* IO port 6 pin 4 */
    BSP_IO_PORT_06_PIN_05 = 0x0405,        /* IO port 6 pin 5 */
    BSP_IO_PORT_06_PIN_06 = 0x0406,        /* IO port 6 pin 6 */

    BSP_IO_PORT_07_PIN_00 = 0x0500,        /* IO port 7 pin 0 */
    BSP_IO_PORT_07_PIN_01 = 0x0501,        /* IO port 7 pin 1 */
    BSP_IO_PORT_07_PIN_02 = 0x0502,        /* IO port 7 pin 2 */
    BSP_IO_PORT_07_PIN_03 = 0x0503,        /* IO port 7 pin 3 */
    BSP_IO_PORT_07_PIN_04 = 0x0504,        /* IO port 7 pin 4 */
    BSP_IO_PORT_07_PIN_05 = 0x0505,        /* IO port 7 pin 5 */
    BSP_IO_PORT_07_PIN_06 = 0x0506,        /* IO port 7 pin 6 */
    BSP_IO_PORT_07_PIN_07 = 0x0507,        /* IO port 7 pin 7 */

    BSP_IO_PORT_08_PIN_00 = 0x0600,        /* IO port 8 pin 0 */
    BSP_IO_PORT_08_PIN_01 = 0x0601,        /* IO port 8 pin 1 */
    BSP_IO_PORT_08_PIN_02 = 0x0602,        /* IO port 8 pin 2 */
    BSP_IO_PORT_08_PIN_03 = 0x0603,        /* IO port 8 pin 3 */
    BSP_IO_PORT_08_PIN_04 = 0x0604,        /* IO port 8 pin 4 */
    BSP_IO_PORT_08_PIN_05 = 0x0605,        /* IO port 8 pin 5 */

    BSP_IO_PORT_10_PIN_00 = 0x0800,        /* IO port 10 pin 0 */
    BSP_IO_PORT_10_PIN_01 = 0x0801,        /* IO port 10 pin 1 */
    BSP_IO_PORT_10_PIN_02 = 0x0802,        /* IO port 10 pin 2 */
    BSP_IO_PORT_10_PIN_03 = 0x0803,        /* IO port 10 pin 3 */
    BSP_IO_PORT_10_PIN_04 = 0x0804,        /* IO port 10 pin 4 */
    BSP_IO_PORT_10_PIN_05 = 0x0805,        /* IO port 10 pin 5 */
    BSP_IO_PORT_10_PIN_06 = 0x0806,        /* IO port 10 pin 6 */
    BSP_IO_PORT_10_PIN_07 = 0x0807,        /* IO port 10 pin 7 */

    BSP_IO_PORT_11_PIN_00 = 0x0900,        /* IO port 11 pin 0 */
    BSP_IO_PORT_11_PIN_01 = 0x0901,        /* IO port 11 pin 1 */
    BSP_IO_PORT_11_PIN_02 = 0x0902,        /* IO port 11 pin 2 */
    BSP_IO_PORT_11_PIN_03 = 0x0903,        /* IO port 11 pin 3 */
    BSP_IO_PORT_11_PIN_04 = 0x0904,        /* IO port 11 pin 4 */
    BSP_IO_PORT_11_PIN_05 = 0x0905,        /* IO port 11 pin 5 */
    BSP_IO_PORT_11_PIN_06 = 0x0906,        /* IO port 11 pin 6 */
    BSP_IO_PORT_11_PIN_07 = 0x0907,        /* IO port 11 pin 7 */

    BSP_IO_PORT_12_PIN_00 = 0x0A00,        /* IO port 12 pin 0 */
    BSP_IO_PORT_12_PIN_01 = 0x0A01,        /* IO port 12 pin 1 */
    BSP_IO_PORT_12_PIN_02 = 0x0A02,        /* IO port 12 pin 2 */

    BSP_IO_PORT_13_PIN_00 = 0x0B00,        /* IO port 13 pin 0 */
    BSP_IO_PORT_13_PIN_01 = 0x0B01,        /* IO port 13 pin 1 */
    BSP_IO_PORT_13_PIN_02 = 0x0B02,        /* IO port 13 pin 2 */
    BSP_IO_PORT_13_PIN_03 = 0x0B03,        /* IO port 13 pin 3 */
    BSP_IO_PORT_13_PIN_04 = 0x0B04,        /* IO port 13 pin 4 */
    BSP_IO_PORT_13_PIN_05 = 0x0B05,        /* IO port 13 pin 5 */
    BSP_IO_PORT_13_PIN_06 = 0x0B06,        /* IO port 13 pin 6 */
    BSP_IO_PORT_13_PIN_07 = 0x0B07,        /* IO port 13 pin 7 */

    BSP_IO_PORT_14_PIN_00 = 0x0C00,        /* IO port 14 pin 0 */
    BSP_IO_PORT_14_PIN_01 = 0x0C01,        /* IO port 14 pin 1 */
    BSP_IO_PORT_14_PIN_02 = 0x0C02,        /* IO port 14 pin 2 */
    BSP_IO_PORT_14_PIN_03 = 0x0C03,        /* IO port 14 pin 3 */
    BSP_IO_PORT_14_PIN_04 = 0x0C04,        /* IO port 14 pin 4 */
    BSP_IO_PORT_14_PIN_05 = 0x0C05,        /* IO port 14 pin 5 */
    BSP_IO_PORT_14_PIN_06 = 0x0C06,        /* IO port 14 pin 6 */
    BSP_IO_PORT_14_PIN_07 = 0x0C07,        /* IO port 14 pin 7 */

    BSP_IO_PORT_15_PIN_00 = 0x0D00,        /* IO port 15 pin 0 */
    BSP_IO_PORT_15_PIN_01 = 0x0D01,        /* IO port 15 pin 1 */
    BSP_IO_PORT_15_PIN_02 = 0x0D02,        /* IO port 15 pin 2 */

    BSP_IO_PORT_16_PIN_00 = 0x0E00,        /* IO port 16 pin 0 */
    BSP_IO_PORT_16_PIN_01 = 0x0E01,        /* IO port 16 pin 1 */
    BSP_IO_PORT_16_PIN_02 = 0x0E02,        /* IO port 16 pin 2 */
    BSP_IO_PORT_16_PIN_03 = 0x0E03,        /* IO port 16 pin 3 */
    BSP_IO_PORT_16_PIN_04 = 0x0E04,        /* IO port 16 pin 4 */
    BSP_IO_PORT_16_PIN_05 = 0x0E05,        /* IO port 16 pin 5 */
    BSP_IO_PORT_16_PIN_06 = 0x0E06,        /* IO port 16 pin 6 */
    BSP_IO_PORT_16_PIN_07 = 0x0E07,        /* IO port 16 pin 7 */

    BSP_IO_PORT_17_PIN_00 = 0x0F00,        /* IO port 17 pin 0 */
    BSP_IO_PORT_17_PIN_01 = 0x0F01,        /* IO port 17 pin 1 */
    BSP_IO_PORT_17_PIN_02 = 0x0F02,        /* IO port 17 pin 2 */
    BSP_IO_PORT_17_PIN_03 = 0x0F03,        /* IO port 17 pin 3 */
    BSP_IO_PORT_17_PIN_04 = 0x0F04,        /* IO port 17 pin 4 */
    BSP_IO_PORT_17_PIN_05 = 0x0F05,        /* IO port 17 pin 5 */

    BSP_IO_PORT_19_PIN_00 = 0x1100,        /* IO port 19 pin 0 */
    BSP_IO_PORT_19_PIN_01 = 0x1101,        /* IO port 19 pin 1 */
    BSP_IO_PORT_19_PIN_02 = 0x1102,        /* IO port 19 pin 2 */
    BSP_IO_PORT_19_PIN_03 = 0x1103,        /* IO port 19 pin 3 */
    BSP_IO_PORT_19_PIN_04 = 0x1104,        /* IO port 19 pin 4 */

    BSP_IO_PORT_20_PIN_00 = 0x1200,        /* IO port 20 pin 0 */
    BSP_IO_PORT_20_PIN_01 = 0x1201,        /* IO port 20 pin 1 */
    BSP_IO_PORT_20_PIN_02 = 0x1202,        /* IO port 20 pin 2 */
    BSP_IO_PORT_20_PIN_03 = 0x1203,        /* IO port 20 pin 3 */

    BSP_IO_PORT_21_PIN_00 = 0x1300,        /* IO port 21 pin 0 */
    BSP_IO_PORT_21_PIN_01 = 0x1301,        /* IO port 21 pin 1 */
    BSP_IO_PORT_21_PIN_02 = 0x1302,        /* IO port 21 pin 2 */
    BSP_IO_PORT_21_PIN_03 = 0x1303,        /* IO port 21 pin 3 */
    BSP_IO_PORT_21_PIN_04 = 0x1304,        /* IO port 21 pin 4 */

    BSP_IO_PORT_22_PIN_00 = 0x1400,        /* IO port 22 pin 0 */
    BSP_IO_PORT_22_PIN_01 = 0x1401,        /* IO port 22 pin 1 */
    BSP_IO_PORT_22_PIN_02 = 0x1402,        /* IO port 22 pin 2 */
    BSP_IO_PORT_22_PIN_03 = 0x1403,        /* IO port 22 pin 3 */
    BSP_IO_PORT_22_PIN_04 = 0x1404,        /* IO port 22 pin 4 */
    BSP_IO_PORT_22_PIN_05 = 0x1405,        /* IO port 22 pin 5 */
    BSP_IO_PORT_22_PIN_06 = 0x1406,        /* IO port 22 pin 6 */
    BSP_IO_PORT_22_PIN_07 = 0x1407,        /* IO port 22 pin 7 */

    BSP_IO_PORT_28_PIN_00 = 0x1A00,        /* IO port 28 pin 0 */

    /* Special purpose port */
    BSP_IO_WDT_OVF_PERROUT_N = 0xFFFF0500, /* WDT_OVF_PERROUT# */

    BSP_IO_SCIF0_RXD = 0xFFFF0600,         /* SCIF0_RXD */
    BSP_IO_SCIF0_TXD = 0xFFFF0601,         /* SCIF0_TXD */

    BSP_IO_SD0_CLK   = 0xFFFF0900,         /* SD0_CLK  */
    BSP_IO_SD0_CMD   = 0xFFFF0901,         /* SD0_CMD  */
    BSP_IO_SD0_RST_N = 0xFFFF0902,         /* SD0_RST# */
    BSP_IO_SD0_DS    = 0xFFFF0905,         /* SD0_DS   */

    BSP_IO_SD0_DAT0 = 0xFFFF0A00,          /* SD0_DAT0 */
    BSP_IO_SD0_DAT1 = 0xFFFF0A01,          /* SD0_DAT1 */
    BSP_IO_SD0_DAT2 = 0xFFFF0A02,          /* SD0_DAT2 */
    BSP_IO_SD0_DAT3 = 0xFFFF0A03,          /* SD0_DAT3 */
    BSP_IO_SD0_DAT4 = 0xFFFF0A04,          /* SD0_DAT4 */
    BSP_IO_SD0_DAT5 = 0xFFFF0A05,          /* SD0_DAT5 */
    BSP_IO_SD0_DAT6 = 0xFFFF0A06,          /* SD0_DAT6 */
    BSP_IO_SD0_DAT7 = 0xFFFF0A07,          /* SD0_DAT7 */
} bsp_io_port_pin_t;

/*==============================================
 * CAN API Overrides
 *==============================================*/

/** CAN status info */
struct st_can_info
{
    uint32_t status;                   ///< Useful information from the CAN status register.
    uint32_t rx_mb_status[2];          ///< RX Message Buffer New Data flags.
    uint32_t rx_fifo_status;           ///< RX FIFO Empty flags.
    uint8_t  error_count_transmit;     ///< Transmit error count.
    uint8_t  error_count_receive;      ///< Receive error count.
    uint32_t error_code;               ///< Error code, cleared after reading.
};

/** This structure specifies the properties of the transfer. Please refer to the struct st_can_info. */
typedef struct st_can_info can_info_t;

/*==============================================
 * CANFD Overrides
 *==============================================*/

/** CANFD Error Code */
typedef enum e_canfd_error
{
    CANFD_ERROR_CHANNEL_BUS              = 0x00000001, ///< Bus Error
    CANFD_ERROR_CHANNEL_WARNING          = 0x00000002, ///< Error Warning (TX/RX error count over 0x5F)
    CANFD_ERROR_CHANNEL_PASSIVE          = 0x00000004, ///< Error Passive (TX/RX error count over 0x7F)
    CANFD_ERROR_CHANNEL_BUS_OFF_ENTRY    = 0x00000008, ///< Bus-Off State Entry
    CANFD_ERROR_CHANNEL_BUS_OFF_RECOVERY = 0x00000010, ///< Recovery from Bus-Off State
    CANFD_ERROR_CHANNEL_OVERLOAD         = 0x00000020, ///< Overload
    CANFD_ERROR_CHANNEL_BUS_LOCK         = 0x00000040, ///< Bus Locked
    CANFD_ERROR_CHANNEL_ARBITRATION_LOSS = 0x00000080, ///< Arbitration Lost
    CANFD_ERROR_CHANNEL_STUFF            = 0x00000100, ///< Stuff Error
    CANFD_ERROR_CHANNEL_FORM             = 0x00000200, ///< Form Error
    CANFD_ERROR_CHANNEL_ACK              = 0x00000400, ///< ACK Error
    CANFD_ERROR_CHANNEL_CRC              = 0x00000800, ///< CRC Error
    CANFD_ERROR_CHANNEL_BIT_RECESSIVE    = 0x00001000, ///< Bit Error (recessive) Error
    CANFD_ERROR_CHANNEL_BIT_DOMINANT     = 0x00002000, ///< Bit Error (dominant) Error
    CANFD_ERROR_CHANNEL_ACK_DELIMITER    = 0x00004000, ///< ACK Delimiter Error
    CANFD_ERROR_GLOBAL_DLC               = 0x00010000, ///< DLC Error
    CANFD_ERROR_GLOBAL_MESSAGE_LOST      = 0x00020000, ///< Message Lost
    CANFD_ERROR_GLOBAL_PAYLOAD_OVERFLOW  = 0x00080000, ///< FD Payload Overflow
    CANFD_ERROR_GLOBAL_TXQ_OVERWRITE     = 0x00100000, ///< TX Queue Message Overwrite
    CANFD_ERROR_GLOBAL_TXQ_MESSAGE_LOST  = 0x00400000, ///< TX Queue Message Lost
    CANFD_ERROR_GLOBAL_CH0_SCAN_FAIL     = 0x01000000, ///< Channel 0 RX Scan Failure
    CANFD_ERROR_GLOBAL_CH1_SCAN_FAIL     = 0x02000000, ///< Channel 1 RX Scan Failure
    CANFD_ERROR_GLOBAL_CH0_ECC           = 0x10000000, ///< Channel 0 ECC Error
    CANFD_ERROR_GLOBAL_CH1_ECC           = 0x20000000, ///< Channel 1 ECC Error
    CANFD_ERROR_GLOBAL_CH2_ECC           = 0x40000000, ///< Channel 2 ECC Error
} canfd_error_t;

/** CANFD Receive Buffer (MB + FIFO) */
typedef enum e_canfd_rx_buffer
{
    CANFD_RX_BUFFER_MB_0   = 0,
    CANFD_RX_BUFFER_MB_1   = 1,
    CANFD_RX_BUFFER_MB_2   = 2,
    CANFD_RX_BUFFER_MB_3   = 3,
    CANFD_RX_BUFFER_MB_4   = 4,
    CANFD_RX_BUFFER_MB_5   = 5,
    CANFD_RX_BUFFER_MB_6   = 6,
    CANFD_RX_BUFFER_MB_7   = 7,
    CANFD_RX_BUFFER_MB_8   = 8,
    CANFD_RX_BUFFER_MB_9   = 9,
    CANFD_RX_BUFFER_MB_10  = 10,
    CANFD_RX_BUFFER_MB_11  = 11,
    CANFD_RX_BUFFER_MB_12  = 12,
    CANFD_RX_BUFFER_MB_13  = 13,
    CANFD_RX_BUFFER_MB_14  = 14,
    CANFD_RX_BUFFER_MB_15  = 15,
    CANFD_RX_BUFFER_MB_16  = 16,
    CANFD_RX_BUFFER_MB_17  = 17,
    CANFD_RX_BUFFER_MB_18  = 18,
    CANFD_RX_BUFFER_MB_19  = 19,
    CANFD_RX_BUFFER_MB_20  = 20,
    CANFD_RX_BUFFER_MB_21  = 21,
    CANFD_RX_BUFFER_MB_22  = 22,
    CANFD_RX_BUFFER_MB_23  = 23,
    CANFD_RX_BUFFER_MB_24  = 24,
    CANFD_RX_BUFFER_MB_25  = 25,
    CANFD_RX_BUFFER_MB_26  = 26,
    CANFD_RX_BUFFER_MB_27  = 27,
    CANFD_RX_BUFFER_MB_28  = 28,
    CANFD_RX_BUFFER_MB_29  = 29,
    CANFD_RX_BUFFER_MB_30  = 30,
    CANFD_RX_BUFFER_MB_31  = 31,
    CANFD_RX_BUFFER_MB_32  = 32,
    CANFD_RX_BUFFER_MB_33  = 33,
    CANFD_RX_BUFFER_MB_34  = 34,
    CANFD_RX_BUFFER_MB_35  = 35,
    CANFD_RX_BUFFER_MB_36  = 36,
    CANFD_RX_BUFFER_MB_37  = 37,
    CANFD_RX_BUFFER_MB_38  = 38,
    CANFD_RX_BUFFER_MB_39  = 39,
    CANFD_RX_BUFFER_MB_40  = 40,
    CANFD_RX_BUFFER_MB_41  = 41,
    CANFD_RX_BUFFER_MB_42  = 42,
    CANFD_RX_BUFFER_MB_43  = 43,
    CANFD_RX_BUFFER_MB_44  = 44,
    CANFD_RX_BUFFER_MB_45  = 45,
    CANFD_RX_BUFFER_MB_46  = 46,
    CANFD_RX_BUFFER_MB_47  = 47,
    CANFD_RX_BUFFER_FIFO_0 = 48,
    CANFD_RX_BUFFER_FIFO_1 = 49,
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_BUFFER_FIFO_2 = 50,
    CANFD_RX_BUFFER_FIFO_3 = 51,
    CANFD_RX_BUFFER_FIFO_4 = 52,
    CANFD_RX_BUFFER_FIFO_5 = 53,
    CANFD_RX_BUFFER_FIFO_6 = 54,
    CANFD_RX_BUFFER_FIFO_7 = 55,
 #endif
    CANFD_RX_BUFFER_FIFO_COMMON_0 = 56,
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_BUFFER_FIFO_COMMON_1 = 57,
    CANFD_RX_BUFFER_FIFO_COMMON_2 = 58,
 #endif
} canfd_rx_buffer_t;

/** CANFD Receive FIFO (RX FIFO) */
typedef enum e_canfd_rx_fifo
{
    CANFD_RX_FIFO_0 = (1U),
    CANFD_RX_FIFO_1 = (1U << 1),
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_FIFO_2 = (1U << 2),
    CANFD_RX_FIFO_3 = (1U << 3),
    CANFD_RX_FIFO_4 = (1U << 4),
    CANFD_RX_FIFO_5 = (1U << 5),
    CANFD_RX_FIFO_6 = (1U << 6),
    CANFD_RX_FIFO_7 = (1U << 7),
 #endif
    CANFD_RX_FIFO_COMMON_0 = (1U << 8),
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_RX_FIFO_COMMON_1 = (1U << 9),
    CANFD_RX_FIFO_COMMON_2 = (1U << 10),
    CANFD_RX_FIFO_COMMON_3 = (1U << 11),
    CANFD_RX_FIFO_COMMON_4 = (1U << 12),
    CANFD_RX_FIFO_COMMON_5 = (1U << 13),
    CANFD_RX_FIFO_COMMON_6 = (1U << 14),
    CANFD_RX_FIFO_COMMON_7 = (1U << 15),
    CANFD_RX_FIFO_COMMON_8 = (1U << 16),
 #endif
} canfd_rx_fifo_t;

/** CANFD Receive Message Buffer (RX MB) */
typedef enum e_canfd_rx_mb
{
    CANFD_RX_MB_NONE = 0,
    CANFD_RX_MB_0    = 0x80,
    CANFD_RX_MB_1    = 0x80 + 1,
    CANFD_RX_MB_2    = 0x80 + 2,
    CANFD_RX_MB_3    = 0x80 + 3,
    CANFD_RX_MB_4    = 0x80 + 4,
    CANFD_RX_MB_5    = 0x80 + 5,
    CANFD_RX_MB_6    = 0x80 + 6,
    CANFD_RX_MB_7    = 0x80 + 7,
    CANFD_RX_MB_8    = 0x80 + 8,
    CANFD_RX_MB_9    = 0x80 + 9,
    CANFD_RX_MB_10   = 0x80 + 10,
    CANFD_RX_MB_11   = 0x80 + 11,
    CANFD_RX_MB_12   = 0x80 + 12,
    CANFD_RX_MB_13   = 0x80 + 13,
    CANFD_RX_MB_14   = 0x80 + 14,
    CANFD_RX_MB_15   = 0x80 + 15,
    CANFD_RX_MB_16   = 0x80 + 16,
    CANFD_RX_MB_17   = 0x80 + 17,
    CANFD_RX_MB_18   = 0x80 + 18,
    CANFD_RX_MB_19   = 0x80 + 19,
    CANFD_RX_MB_20   = 0x80 + 20,
    CANFD_RX_MB_21   = 0x80 + 21,
    CANFD_RX_MB_22   = 0x80 + 22,
    CANFD_RX_MB_23   = 0x80 + 23,
    CANFD_RX_MB_24   = 0x80 + 24,
    CANFD_RX_MB_25   = 0x80 + 25,
    CANFD_RX_MB_26   = 0x80 + 26,
    CANFD_RX_MB_27   = 0x80 + 27,
    CANFD_RX_MB_28   = 0x80 + 28,
    CANFD_RX_MB_29   = 0x80 + 29,
    CANFD_RX_MB_30   = 0x80 + 30,
    CANFD_RX_MB_31   = 0x80 + 31,
    CANFD_RX_MB_32   = 0x80 + 32,
    CANFD_RX_MB_33   = 0x80 + 33,
    CANFD_RX_MB_34   = 0x80 + 34,
    CANFD_RX_MB_35   = 0x80 + 35,
    CANFD_RX_MB_36   = 0x80 + 36,
    CANFD_RX_MB_37   = 0x80 + 37,
    CANFD_RX_MB_38   = 0x80 + 38,
    CANFD_RX_MB_39   = 0x80 + 39,
    CANFD_RX_MB_40   = 0x80 + 40,
    CANFD_RX_MB_41   = 0x80 + 41,
    CANFD_RX_MB_42   = 0x80 + 42,
    CANFD_RX_MB_43   = 0x80 + 43,
    CANFD_RX_MB_44   = 0x80 + 44,
    CANFD_RX_MB_45   = 0x80 + 45,
    CANFD_RX_MB_46   = 0x80 + 46,
    CANFD_RX_MB_47   = 0x80 + 47
} canfd_rx_mb_t;

/** CANFD Transmit Buffer (MB + CFIFO) */
typedef enum e_canfd_tx_buffer
{
    CANFD_TX_BUFFER_0 = 0,
    CANFD_TX_BUFFER_1 = 1,
    CANFD_TX_BUFFER_2 = 2,
    CANFD_TX_BUFFER_3 = 3,
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_4  = 4,
    CANFD_TX_BUFFER_5  = 5,
    CANFD_TX_BUFFER_6  = 6,
    CANFD_TX_BUFFER_7  = 7,
    CANFD_TX_BUFFER_8  = 8,
    CANFD_TX_BUFFER_9  = 9,
    CANFD_TX_BUFFER_10 = 10,
    CANFD_TX_BUFFER_11 = 11,
    CANFD_TX_BUFFER_12 = 12,
    CANFD_TX_BUFFER_13 = 13,
    CANFD_TX_BUFFER_14 = 14,
    CANFD_TX_BUFFER_15 = 15,
    CANFD_TX_BUFFER_32 = 32,
    CANFD_TX_BUFFER_33 = 33,
    CANFD_TX_BUFFER_34 = 34,
    CANFD_TX_BUFFER_35 = 35,
    CANFD_TX_BUFFER_36 = 36,
    CANFD_TX_BUFFER_37 = 37,
    CANFD_TX_BUFFER_38 = 38,
    CANFD_TX_BUFFER_39 = 39,
    CANFD_TX_BUFFER_40 = 40,
    CANFD_TX_BUFFER_41 = 41,
    CANFD_TX_BUFFER_42 = 42,
    CANFD_TX_BUFFER_43 = 43,
    CANFD_TX_BUFFER_44 = 44,
    CANFD_TX_BUFFER_45 = 45,
    CANFD_TX_BUFFER_46 = 46,
    CANFD_TX_BUFFER_47 = 47,
 #endif
    CANFD_TX_BUFFER_FIFO_COMMON_0 = 48,
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_BUFFER_FIFO_COMMON_1 = 49,
    CANFD_TX_BUFFER_FIFO_COMMON_2 = 50,
 #endif
} canfd_tx_buffer_t;

/** CANFD Transmit Message Buffer (TX MB) */
typedef enum e_canfd_tx_mb
{
    CANFD_TX_MB_0 = 0,
    CANFD_TX_MB_1 = 1,
    CANFD_TX_MB_2 = 2,
    CANFD_TX_MB_3 = 3,
 #if !BSP_FEATURE_CANFD_LITE
    CANFD_TX_MB_4  = 4,
    CANFD_TX_MB_5  = 5,
    CANFD_TX_MB_6  = 6,
    CANFD_TX_MB_7  = 7,
    CANFD_TX_MB_8  = 8,
    CANFD_TX_MB_9  = 9,
    CANFD_TX_MB_10 = 10,
    CANFD_TX_MB_11 = 11,
    CANFD_TX_MB_12 = 12,
    CANFD_TX_MB_13 = 13,
    CANFD_TX_MB_14 = 14,
    CANFD_TX_MB_15 = 15,
    CANFD_TX_MB_32 = 32,
    CANFD_TX_MB_33 = 33,
    CANFD_TX_MB_34 = 34,
    CANFD_TX_MB_35 = 35,
    CANFD_TX_MB_36 = 36,
    CANFD_TX_MB_37 = 37,
    CANFD_TX_MB_38 = 38,
    CANFD_TX_MB_39 = 39,
    CANFD_TX_MB_40 = 40,
    CANFD_TX_MB_41 = 41,
    CANFD_TX_MB_42 = 42,
    CANFD_TX_MB_43 = 43,
    CANFD_TX_MB_44 = 44,
    CANFD_TX_MB_45 = 45,
    CANFD_TX_MB_46 = 46,
    CANFD_TX_MB_47 = 47,
 #endif
} canfd_tx_mb_t;

/*==============================================
 * DMAC_B Overrides
 *==============================================*/

/** Detection method of the external DMA request signal. */
typedef enum e_dmac_b_external_detection
{
    DMAC_B_EXTERNAL_DETECTION_FALLING_EDGE = 1, ///< Falling edge detection.
    DMAC_B_EXTERNAL_DETECTION_RISING_EDGE  = 2, ///< Rising edge detection.
    DMAC_B_EXTERNAL_DETECTION_LOW_LEVEL    = 5, ///< Low level detection.
    DMAC_B_EXTERNAL_DETECTION_HIGH_LEVEL   = 6, ///< High level detection.
} dmac_b_external_detection_t;

/** Active level of the external DMA ACK signal. */
typedef enum e_dmac_b_external_output_signal_active_level
{
    DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_HIGH_ACTIVE = 0,
    DMAC_B_EXTERNAL_OUTPUT_SIGNAL_ACTIVE_LEVEL_LOW_ACTIVE  = 1,
} dmac_b_external_output_signal_active_level_t;

/** access control. */
typedef enum e_acc_control_ip
{
    ACCCNT_SRAM0 = 0,
    ACCCNT_SRAM1,
    ACCCNT_TZC0,
    ACCCNT_TZC1,
    ACCCNT_TZC5,
    ACCCNT_TZC6,
    ACCCNT_CST,
    ACCCNT_CPG,
    ACCCNT_SYSC,
    ACCCNT_SYC,
    ACCCNT_GIC,
    ACCCNT_IA55_IM33,
    ACCCNT_GPIO,
    ACCCNT_MHU,
    ACCCNT_GPU,
    ACCCNT_H264,
    ACCCNT_CRU,
    ACCCNT_ISU,
    ACCCNT_DSIPHY,
    ACCCNT_DSILINK,
    ACCCNT_LCDC,
    ACCCNT_DMAC0,
    ACCCNT_DMAC1,
    ACCCNT_OSTM0,
    ACCCNT_OSTM1,
    ACCCNT_OSTM2,
    ACCCNT_WDT0,
    ACCCNT_WDT1,
    ACCCNT_WDT2,
    ACCCNT_RTC,
    ACCCNT_MTU3A,
    ACCCNT_POE3,
    ACCCNT_GPT,
    ACCCNT_POEG,
    ACCCNT_DDR,
    ACCCNT_USBT,
    ACCCNT_USB20,
    ACCCNT_USB21,
    ACCCNT_SDHI0,
    ACCCNT_SDHI1,
    ACCCNT_SDHI2,
    ACCCNT_ETH0,
    ACCCNT_ETH1,
    ACCCNT_PCIE,
    ACCCNT_I2C0,
    ACCCNT_I2C1,
    ACCCNT_I2C2,
    ACCCNT_I2C3,
    ACCCNT_I3C,
    ACCCNT_CANFD,
    ACCCNT_RSPI0,
    ACCCNT_RSPI1,
    ACCCNT_RSPI2,
    ACCCNT_SCIF0,
    ACCCNT_SCIF1,
    ACCCNT_SCIF2,
    ACCCNT_SCIF3,
    ACCCNT_SCIF4,
    ACCCNT_SCIF5,
    ACCCNT_RSCI0,
    ACCCNT_RSCI1,
    ACCCNT_RSCI2,
    ACCCNT_RSCI3,
    ACCCNT_SSIF0,
    ACCCNT_SSIF1,
    ACCCNT_SSIF2,
    ACCCNT_SSIF3,
    ACCCNT_SPDIF,
    ACCCNT_PDM,
    ACCCNT_ADC,
    ACCCNT_TSU,
    ACCCNT_OTP,
    ACCCNT_VBATT,
    ACCCNT_BSC,
    ACCCNT_CA55,
    ACCCNT_CM33,
    ACCCNT_LSI,
    ACCCNT_AOF,
    ACCCNT_LP,
    ACCCNT_GPREG,
    ACCCNT_IPCONT,
} fsp_acc_control_ip_t;

/** Available modules. */
typedef enum e_fsp_ip
{
    FSP_IP_GTM      = 0,               ///< General Timer
    FSP_IP_GPT      = 1,               ///< General PWM Timer
    FSP_IP_POEG     = 2,               ///< Port Output Enable for GPT
    FSP_IP_PORT     = 3,               ///< I/O Ports
    FSP_IP_IM33     = 4,               ///< IM33 (Interrupt controller)
    FSP_IP_SCIF     = 5,               ///< Serial Communications Interface with FIFO
    FSP_IP_RIIC     = 6,               ///< I2C Bus Interface
    FSP_IP_RSPI     = 7,               ///< Renesas Serial Peripheral Interface
    FSP_IP_MHU      = 8,               ///< Message Handling Unit
    FSP_IP_DMAC     = 9,               ///< Direct Memory Access Controller
    FSP_IP_DMAC_s   = 9,               ///< Direct Memory Access Controller
    FSP_IP_SSI      = 10,              ///< Serial Sound Interface
    FSP_IP_CANFD    = 11,              ///< CANFD Interface (RS-CANFD)
    FSP_IP_ADC      = 12,              ///< A/D Converter
    FSP_IP_TSU      = 13,              ///< Thermal Sensor Unit
    FSP_IP_WDT      = 14,              ///< Watchdog Timer
    FSP_IP_SCI      = 15,              ///< Serial Communications Interface
    FSP_IP_MTU3     = 16,              ///< Multi-Function Timer Pulse Unit 3
    FSP_IP_XSPI     = 17,              ///< Expanded Serial Peripheral Interface
    FSP_IP_IRQ      = 18,              ///< External interrupt from IRQ pin
    FSP_IP_TINT     = 19,              ///< External interrupt from GPIO pin
    FSP_IP_RTC      = 20,              ///< Realtime Clock
    FSP_IP_LCDC     = 21,              ///< LCD Controller
    FSP_IP_MIPI_DSI = 22,              ///< MIPI-DSI Tx module
    FSP_IP_VBATT    = 23,              ///< Battery Backup Function
    FSP_IP_I3C      = 24,              ///< I3C Bus Interface
} fsp_ip_t;

/** master access control. */
typedef enum e_mst_acc_control_ip
{
    MST_ACCCNT_DMAC0,
    MST_ACCCNT_DMAC1,
    MST_ACCCNT_GPU,
    MST_ACCCNT_SDHI0,
    MST_ACCCNT_SDHI1,
    MST_ACCCNT_GBETHER0,
    MST_ACCCNT_GBETHER1,
    MST_ACCCNT_USB20_HOST,
    MST_ACCCNT_USB21_HOST,
    MST_ACCCNT_USB20_FUNC,
    MST_ACCCNT_USB21_FUNC,
    MST_ACCCNT_H264,
    MST_ACCCNT_LCDC,
    MST_ACCCNT_DSI,
    MST_ACCCNT_ISU,
    MST_ACCCNT_CRU,
    MST_ACCCNT_SDHI2,
    MST_ACCCNT_PCIE
} fsp_mst_acc_control_ip_t;

typedef enum e_bsp_slv_acccnt
{
    BSP_SLV_ACCCNT_SRAM_ACPU,
    BSP_SLV_ACCCNT_SRAM_MCPU,
    BSP_SLV_ACCCNT_XSPI,
    BSP_SLV_ACCCNT_DDR_ACPU,
    BSP_SLV_ACCCNT_DDR_VIDEO
} bsp_slv_acccnt_t;

/* Private enum used in R_FSP_SystemClockHzGet. */
typedef enum e_fsp_priv_clock
{
    FSP_PRIV_CLOCK_ICLK,
    FSP_PRIV_CLOCK_IC0CLK,
    FSP_PRIV_CLOCK_IC1CLK,
    FSP_PRIV_CLOCK_IC2CLK,
    FSP_PRIV_CLOCK_IC3CLK,
    FSP_PRIV_CLOCK_P4CLK,
    FSP_PRIV_CLOCK_P6CLK,
    FSP_PRIV_CLOCK_P3CLK,
    FSP_PRIV_CLOCK_P5CLK,
    FSP_PRIV_CLOCK_P0CLK,
    FSP_PRIV_CLOCK_P20CLK,
    FSP_PRIV_CLOCK_P7CLK,
    FSP_PRIV_CLOCK_M1CLK,
    FSP_PRIV_CLOCK_ATCLK,
    FSP_PRIV_CLOCK_P1CLK,
    FSP_PRIV_CLOCK_M6CLK,
    FSP_PRIV_CLOCK_M0CLK,
    FSP_PRIV_CLOCK_P2CLK,
    FSP_PRIV_CLOCK_P8CLK,
    FSP_PRIV_CLOCK_P9CLK,
    FSP_PRIV_CLOCK_P10CLK,
    FSP_PRIV_CLOCK_M5CLK,
    FSP_PRIV_CLOCK_S0CLK,
    FSP_PRIV_CLOCK_HPCLK,
    FSP_PRIV_CLOCK_M4CLK,
    FSP_PRIV_CLOCK_M2CLK,
    FSP_PRIV_CLOCK_M3CLK,
    FSP_PRIV_CLOCK_OSCCLK,
    FSP_PRIV_CLOCK_OSCCLK2,
    FSP_PRIV_CLOCK_ETHTX01CLK,
    FSP_PRIV_CLOCK_ETHRX01CLK,
    FSP_PRIV_CLOCK_ETHRM0CLK,
    FSP_PRIV_CLOCK_ETHTX02CLK,
    FSP_PRIV_CLOCK_ETHRX02CLK,
    FSP_PRIV_CLOCK_ETHTX11CLK,
    FSP_PRIV_CLOCK_ETHRX11CLK,
    FSP_PRIV_CLOCK_ETHRM1CLK,
    FSP_PRIV_CLOCK_ETHTX12CLK,
    FSP_PRIV_CLOCK_ETHRX12CLK,
    FSP_PRIV_CLOCK_SD0CLK,
    FSP_PRIV_CLOCK_SD1CLK,
    FSP_PRIV_CLOCK_SD2CLK,
    FSP_PRIV_CLOCK_SPI0CLK,
    FSP_PRIV_CLOCK_SPI1CLK,
    FSP_PRIV_CLOCK_P13CLK,
    FSP_PRIV_CLOCK_P14CLK,
    FSP_PRIV_CLOCK_P15CLK,
    FSP_PRIV_CLOCK_P16CLK,
    FSP_PRIV_CLOCK_P17CLK,
    FSP_PRIV_CLOCK_P18CLK,
    FSP_PRIV_CLOCK_P19CLK,
    FSP_PRIV_CLOCK_GCLK,
    FSP_PRIV_CLOCK_BCLK,
    FSP_PRIV_CLOCK_NUM
} fsp_priv_clock_t;

/* Private enum used in R_BSP_ClockDividerSet. */
typedef enum e_fsp_priv_clock_divider
{
    FSP_PRIV_CLOCK_DIVIDER_DIV_CA55 = 0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_200,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_100,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL2_QSPI,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_200,
    FSP_PRIV_CLOCK_DIVIDER_DIV_PLL3_100,
    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI1,
    FSP_PRIV_CLOCK_DIVIDER_DIV_SDHI2,
    FSP_PRIV_CLOCK_DIVIDER_DIV_XSPI,
    FSP_PRIV_CLOCK_DIVIDER_DIV_GE3D,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CLK266FIXC_DIV16TO128,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CLK24_SEL,
    FSP_PRIV_CLOCK_DIVIDER_DIV_BSC,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE1,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE2,
    FSP_PRIV_CLOCK_DIVIDER_DIV_CA55_CORE3,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI1,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI2,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSCI3,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI0,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI1,
    FSP_PRIV_CLOCK_DIVIDER_DIV_RSPI2,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO32_VCLK,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO16_VCLK,
    FSP_PRIV_CLOCK_DIVIDER_DIV_DSI_DIV1TO2_LVDS,
    FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_TR,
    FSP_PRIV_CLOCK_DIVIDER_DIV_ETH0_RM,
    FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_TR,
    FSP_PRIV_CLOCK_DIVIDER_DIV_ETH1_RM,
    FSP_PRIV_CLOCK_DIVIDER_NUM,
} fsp_priv_clock_divider_t;

/* Private enum used in R_BSP_ClockSelectorSet. */
typedef enum e_fsp_priv_clock_selector
{
    FSP_PRIV_CLOCK_SELECTOR_SEL_PLL4 = 0,
    FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI0,
    FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI1,
    FSP_PRIV_CLOCK_SELECTOR_SEL_SDHI2,
    FSP_PRIV_CLOCK_SELECTOR_SEL_BSC,
    FSP_PRIV_CLOCK_SELECTOR_SEL_XSPI,
    FSP_PRIV_CLOCK_SELECTOR_SEL_DSI,
    FSP_PRIV_CLOCK_SELECTOR_SEL_GE3D,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_TX,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RX,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_RM,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_TX_I,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH0_CLK_RX_I,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_TX,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RX,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_RM,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_TX_I,
    FSP_PRIV_CLOCK_SELECTOR_SEL_ETH1_CLK_RX_I,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI0,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI1,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI2,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSCI3,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI0,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI1,
    FSP_PRIV_CLOCK_SELECTOR_SEL_RSPI2,
    FSP_PRIV_CLOCK_SELECTOR_NUM,
} fsp_priv_clock_selector_t;

/*==============================================
 * IOPORT Overrides
 *==============================================*/

/*==============================================
 * SPI_B Overrides
 *==============================================*/

/** SPI communication clock source. */
typedef enum e_spi_b_clock_source
{
    SPI_B_CLOCK_SOURCE_TCLK_CH0,
    SPI_B_CLOCK_SOURCE_TCLK_CH1,
    SPI_B_CLOCK_SOURCE_TCLK_CH2,
    SPI_B_CLOCK_SOURCE_PCLK
} spi_b_clock_source_t;

/*==============================================
 * SCI_B_SPI Overrides
 *==============================================*/
typedef enum e_sci_b_spi_clock_source
{
    SCI_B_SPI_SOURCE_CLOCK_TCLK_CH0,
    SCI_B_SPI_SOURCE_CLOCK_TCLK_CH1,
    SCI_B_SPI_SOURCE_CLOCK_TCLK_CH2,
    SCI_B_SPI_SOURCE_CLOCK_TCLK_CH3,
    SCI_B_SPI_SOURCE_CLOCK_PCLK
} sci_b_spi_clock_source_t;

/*==============================================
 * SCI_B_UART Overrides
 *==============================================*/
typedef enum e_sci_b_uart_clock_source
{
    SCI_B_UART_SOURCE_CLOCK_TCLK_CH0,
    SCI_B_UART_SOURCE_CLOCK_TCLK_CH1,
    SCI_B_UART_SOURCE_CLOCK_TCLK_CH2,
    SCI_B_UART_SOURCE_CLOCK_TCLK_CH3,
    SCI_B_UART_SOURCE_CLOCK_PCLK
} sci_b_uart_clock_source_t;

/*==============================================
 * SCI_B_I2C Overrides
 *==============================================*/
typedef enum e_sci_b_i2c_clock_source
{
    SCI_B_I2C_SOURCE_CLOCK_TCLK_CH0,
    SCI_B_I2C_SOURCE_CLOCK_TCLK_CH1,
    SCI_B_I2C_SOURCE_CLOCK_TCLK_CH2,
    SCI_B_I2C_SOURCE_CLOCK_TCLK_CH3,
    SCI_B_I2C_SOURCE_CLOCK_PCLK
} sci_b_i2c_clock_source_t;

/*==============================================
 * LCDC Overrides
 *==============================================*/
typedef enum e_display_in_format
{
    DISPLAY_IN_FORMAT_32BITS_ARGB8888 = 0,                         ///< ARGB8888, 32 bits
    DISPLAY_IN_FORMAT_32BITS_RGB888   = 1,                         ///< RGB888,   32 bits
    DISPLAY_IN_FORMAT_16BITS_RGB565   = 2,                         ///< RGB565,   16 bits
    DISPLAY_IN_FORMAT_16BITS_ARGB1555 = 3,                         ///< ARGB1555, 16 bits
    DISPLAY_IN_FORMAT_16BITS_ARGB4444 = 4,                         ///< ARGB4444, 16 bits

    DISPLAY_IN_FORMAT_CLUT8 = 5,                                   ///< CLUT8
    DISPLAY_IN_FORMAT_CLUT4 = 6,                                   ///< CLUT4
    DISPLAY_IN_FORMAT_CLUT1 = 7,                                   ///< CLUT1

    DISPLAY_IN_FORMAT_32BITS_RGBA8888                        = 8,  ///< RGBA8888,                        32 bits
    DISPLAY_IN_FORMAT_24BITS_BGR888                          = 9,  ///< BGR888,                          24 bits
    DISPLAY_IN_FORMAT_24BITS_RGB888                          = 10, ///< RGB888,                          24 bits
    DISPLAY_IN_FORMAT_32BITS_ABGR8888                        = 11, ///< ABGR8888,                        32 bits
    DISPLAY_IN_FORMAT_24BITS_YCBCR444_INTERLEAVED            = 12, ///< YCbCr444 interleaved,             24 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_UYVY = 13, ///< YCbCr422 interleaved type0 UYVY,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_YUY2 = 14, ///< YCbCr422 interleaved type0 YUY2,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE0_YVYU = 15, ///< YCbCr422 interleaved type0 YVYU,  16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR422_INTERLEAVED_TYPE1      = 16, ///< YCbCr420 interleaved type1,       16 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR420_INTERLEAVED            = 17, ///< YCbCr420 interleaved,             12 bits
    DISPLAY_IN_FORMAT_16BITS_YCBCR420_PLANAR                 = 18, ///< YCbCr420 planar,                  16bits

    /** All other options start at this value. */
    DISPLAY_IN_FORMAT_CUSTOM = 0x80,
} display_in_format_t;

typedef enum e_display_data_swap
{
    DISPLAY_DATA_SWAP_8BIT  = 1,
    DISPLAY_DATA_SWAP_16BIT = 2,
    DISPLAY_DATA_SWAP_32BIT = 4,
    DISPLAY_DATA_SWAP_64BIT = 8,
} display_data_swap_t;

typedef enum e_data_enable_output_mode
{
    DEMD_LOW_ACTIVE  = 1,
    DEMD_HIGH_ACTIVE = 3,
} data_enable_output_mode_t;

/** Graphics plane input configuration structure */
struct st_display_input_cfg
{
    uint32_t          * p_base;        ///< Base address to the frame buffer
    uint32_t          * p_base_cb;     ///< Base address to the frame buffer for Cb plane
    uint32_t          * p_base_cr;     ///< Base address to the frame buffer for Cr plane
    uint16_t            hsize;         ///< Horizontal pixels in a line
    uint16_t            vsize;         ///< Vertical pixels in a frame
    uint16_t            coordinate_x;  ///< Coordinate X
    uint16_t            coordinate_y;  ///< Coordinate Y
    uint16_t            hstride;       ///< Memory stride (bytes) in a line
    uint16_t            hstride_cbcr;  ///< Memory stride (bytes) in a line for Cb and Cr plane
    display_in_format_t format;        ///< Input format setting
    display_data_swap_t data_swap;     ///< Input data swap_Setting
};

/** This structure specifies the properties of the transfer. Please refer to the struct st_display_input_cfg. */
typedef struct st_display_input_cfg display_input_cfg_t;

/*==============================================
 * Timer API Overrides
 *==============================================*/

/** Events that can trigger a callback function */
typedef enum e_timer_event
{
    TIMER_EVENT_CYCLE_END,                     ///< Requested timer delay has expired or timer has wrapped around
    TIMER_EVENT_CREST = TIMER_EVENT_CYCLE_END, ///< Timer crest event (counter is at a maximum, triangle-wave PWM only)
    TIMER_EVENT_CAPTURE_A,                     ///< A capture has occurred on signal A
    TIMER_EVENT_CAPTURE_B,                     ///< A capture has occurred on signal B
    TIMER_EVENT_CAPTURE_C,                     ///< A capture has occurred on signal C
    TIMER_EVENT_CAPTURE_D,                     ///< A capture has occurred on signal D
    TIMER_EVENT_TROUGH,                        ///< Timer trough event (counter is 0, triangle-wave PWM only
    TIMER_EVENT_COMPARE_A,                     ///< A compare has occurred on signal A
    TIMER_EVENT_COMPARE_B,                     ///< A compare has occurred on signal B
    TIMER_EVENT_COMPARE_C,                     ///< A compare has occurred on signal C
    TIMER_EVENT_COMPARE_D,                     ///< A compare has occurred on signal D
    TIMER_EVENT_COMPARE_E,                     ///< A compare has occurred on signal E
    TIMER_EVENT_COMPARE_F,                     ///< A compare has occurred on signal F
    TIMER_EVENT_DEAD_TIME                      ///< Dead time event
} timer_event_t;

/*==============================================
 * Transfer API Overrides
 *==============================================*/

/** Events that can trigger a callback function. */
typedef enum e_transfer_event
{
    TRANSFER_EVENT_TRANSFER_END   = 0, ///< Transfer has completed.
    TRANSFER_EVENT_TRANSFER_ERROR = 1, ///< Transfer error has occurred.
} transfer_event_t;

/** Transfer mode describes what will happen when a transfer request occurs. */
typedef enum e_transfer_mode
{
    /** Normal mode. */
    TRANSFER_MODE_NORMAL = 0,

    /** Block mode. */
    TRANSFER_MODE_BLOCK = 1
} transfer_mode_t;

/** Transfer size specifies the size of each individual transfer. */
typedef enum e_transfer_size
{
    TRANSFER_SIZE_1_BYTE   = 0,        ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE   = 1,        ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE   = 2,        ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE   = 3,        ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE  = 4,        ///< Each transfer transfers a 128-bit value
    TRANSFER_SIZE_32_BYTE  = 5,        ///< Each transfer transfers a 256-bit value
    TRANSFER_SIZE_64_BYTE  = 6,        ///< Each transfer transfers a 512-bit value
    TRANSFER_SIZE_128_BYTE = 7         ///< Each transfer transfers a 1024-bit value
} transfer_size_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer is incremented by associated transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 0,

    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 1
} transfer_addr_mode_t;

/** Callback function parameter data. */
struct st_transfer_callback_args
{
    transfer_event_t event;            ///< Event code
    void           * p_context;        ///< Placeholder for user data. Set in transfer_api_t::open function in RZG::transfer_cfg_t.
};

/** Callback function parameter data. Please refer to the struct st_transfer_callback_args. */
typedef struct st_transfer_callback_args transfer_callback_args_t;

/** This structure specifies the properties of the transfer. */
struct st_transfer_info
{
    /** Select what happens to destination address after each transfer. */
    transfer_addr_mode_t dest_addr_mode;

    /** Select what happens to source address after each transfer. */
    transfer_addr_mode_t src_addr_mode;

    /** Select mode from @ref RZG::transfer_mode_t. */
    transfer_mode_t mode;

    /** Source address. */
    void const * volatile p_src;

    /** Destination address. */
    void * volatile p_dest;

    /** The total number of transfer bytes. */
    volatile uint32_t length;

    /** Select source data size to transfer at once. */
    transfer_size_t src_size;

    /** Select destination data size to transfer at once. */
    transfer_size_t dest_size;

    /** Next1 Register set settings */
    void const * p_next1_src;
    void       * p_next1_dest;
    uint32_t     next1_length;
};

/** This structure specifies the properties of the transfer. Please refer to the struct st_transfer_info. */
typedef struct st_transfer_info transfer_info_t;

/*==============================================
 * ADC API Overrides
 *==============================================*/

/** ADC Information Structure for Transfer Interface */
struct st_adc_info
{
    volatile const void * p_address;         ///< The address to start reading the data from
    uint32_t              length;            ///< The total number of transfers to read
    transfer_size_t       transfer_size;     ///< The size of each transfer
    uint32_t              calibration_data1; ///< Temperature sensor calibration data1
    uint32_t              calibration_data2; ///< Temperature sensor calibration data2
};

/** ADC Information Structure for Transfer Interface. Please refer to the struct st_adc_info. */
typedef struct st_adc_info adc_info_t;

/***********************************************************************************************************************
 * Exported global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 **********************************************************************************************************************/

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif
