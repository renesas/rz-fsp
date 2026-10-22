/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_FEATURE_H
#define BSP_FEATURE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/

/* ADC-Related Definitions */
#define BSP_FEATURE_ADC_C_UNIT_VALID_CONVERSION_RESULT_REGISTER_MASKS \
    BSP_FEATURE_ADC_C_UNIT_0_VALID_CONVERSION_RESULT_REGISTER_MASK,   \
    BSP_FEATURE_ADC_C_UNIT_1_VALID_CONVERSION_RESULT_REGISTER_MASK
#define BSP_FEATURE_ADC_C_UNIT_0_VALID_CONVERSION_RESULT_REGISTER_MASK    (0xFFU)
#define BSP_FEATURE_ADC_C_UNIT_1_VALID_CONVERSION_RESULT_REGISTER_MASK    (0xF00U)
#define BSP_FEATURE_ADC_C_VALID_UNIT_MASK                                 (0x3U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MIN                          (71U)
#define BSP_FEATURE_ADC_C_SAMPLE_STATE_COUNT_MAX                          (255U)
#define BSP_FEATURE_ADC_C_CONVERSION_TIME                                 (29U)
#define BSP_FEATURE_ADC_C_HAS_ADIVC                                       (0U)
#define BSP_FEATURE_ADC_C_TSU_CONTROL_AVAILABLE                           (1U)
#define BSP_FEATURE_ADC_C_TSU_ENABLE_STABILIZATION_TIME_US                (30U)
#define BSP_FEATURE_ADC_C_TSU_START_STABILIZATION_TIME_US                 (50U)
#define BSP_FEATURE_ADC_C_TSUMODE_TSUEN_SETTING                           (1U)

/* BSP Capabilities Definitions */
#define BSP_FEATURE_BSP_ACCESS_CONTROL_SET_SUPPORT                        (1U)
#define BSP_FEATURE_BSP_BOOTCPU_MASK                                      (R_SYSC_SYS_LSI_MODE_STAT_BOOTCPUSEL_Msk)
#define BSP_FEATURE_BSP_SYSTEM_CORE_CLOCK                                 (FSP_PRIV_CLOCK_P3CLK)
#define BSP_FEATURE_BSP_DELAY_LOOP_CYCLES                                 (30U)
#define BSP_FEATURE_BSP_INT_SIGNAL_VIA_DMAC                               (1U)
#define BSP_FEATURE_BSP_CLOCK_FREQ_INIT_CFG_SUPPORT                       (BSP_CFG_MCU_CLOCK_INIT)
#define BSP_FEATURE_BSP_HAS_ELC                                           (0U)
#define BSP_FEATURE_BSP_HAS_GPT_CLOCK                                     (0U)
#define BSP_FEATURE_BSP_SLAVE_ADDRESS_CONVERSION_SUPPORT                  (1U)
#define BSP_FEATURE_SYS_IPCONT_SEL_CLONECH_REG_BASE                       (&R_SYSC->SYS_IPCONT_SEL_CLONECH)
#define BSP_FEATURE_BSP_SUPPORT_SD_VOLT                                   (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_VOLT                                (1U)
#define BSP_FEATURE_BSP_SUPPORT_ETHER_MODE                                (1U)
#define BSP_FEATURE_BSP_SUPPORT_QSPI_VOLT                                 (0U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_VOLT                                 (1U)
#define BSP_FEATURE_BSP_SUPPORT_XSPI_OUTPUT                               (0U)
#define BSP_FEATURE_BSP_SUPPORT_I3C                                       (1U)
#define BSP_FEATURE_BSP_SUPPORT_BYPASS                                    (0U)
#define BSP_FEATURE_BSP_SUPPORT_PFCWE_PROTECT                             (1U)
#define BSP_FEATURE_BSP_SUPPORT_OEN_PROTECT                               (0U)
#define BSP_FEATURE_BSP_HAS_PFC_OEN_REG                                   (0U)
#define BSP_FEATURE_BSP_HAS_ETHER_MODE_REG                                (1U)
#define BSP_FEATURE_BSP_HAS_SD_CH0_POC_REG                                (1U)
#define BSP_FEATURE_BSP_HAS_SD_CH1_POC_REG                                (1U)
#define BSP_FEATURE_BSP_HAS_SD_CH2_POC_REG                                (1U)
#define BSP_FEATURE_BSP_HAS_ETH_POC_REG                                   (1U)
#define BSP_FEATURE_BSP_HAS_VBATT_MODULE                                  (1U)
#define BSP_FEATURE_BSP_SUPPORT_OTHER_POC_VOLT                            (1U)

/* CANFD-Related Definitions */
#define BSP_FEATURE_CANFD_NUM_CHANNELS                                    (3)
#define BSP_FEATURE_CANFD_FD_SUPPORT                                      (1)
#define BSP_FEATURE_CANFD_LITE                                            (0U)
#define BSP_FEATURE_CANFD_NUM_INSTANCES                                   (1U)
#define BSP_FEATURE_CANFD_HAS_RSCANFD                                     (0U)
#define BSP_FEATURE_CANFD_TXMB_OFFSET                                     (32U)
#define BSP_FEATURE_CANFD_TXMB_CHANNEL_OFFSET                             (64U)
#define BSP_FEATURE_CANFD_RXMB_MAX                                        (48U)
#define BSP_FEATURE_CANFD_ERROR_GLOBAL_CH0_ECC_REG_POS                    (28U)
#define BSP_FEATURE_CANFD_NUM_COMMON_FIFOS                                (9U)
#define BSP_FEATURE_CANFD_64BIT_SYSTEM                                    (0U)

/* Cortex-M33 Feature Definitions */
#define BSP_FEATURE_MCORE_HAS_DSP                                         (0U)
#define BSP_FEATURE_MCORE_HAS_FPU                                         (0U)
#define BSP_FEATURE_CURRENT_CORE_IS_CM33_FPU                              (0U)

/* DMAC-Related Definitions */
#define BSP_FEATURE_DMAC_MAX_CHANNEL                                      (16U)
#define BSP_FEATURE_DMAC_MAX_UNIT                                         (2U)
#define BSP_FEATURE_DMAC_B_64BIT_SYSTEM                                   (0U)
#define BSP_FEATURE_DMAC_VALID_UNIT_MASK                                  (0x1U) // Mask of valid units for DMAC.

/* GPT-Related Definitions */
#define BSP_FEATURE_GPT_VALID_CHANNEL_MASK                                (0xFFU)
#define BSP_FEATURE_GPT_MAX_CHANNEL                                       (8U)
#define BSP_FEATURE_GPT_EVENT_COUNT_CHANNEL_MASK                          (BSP_FEATURE_GPT_VALID_CHANNEL_MASK)
#define BSP_FEATURE_GPT_TPCS_SHIFT                                        (1U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_STEP_SIZE                           (4U)
#define BSP_FEATURE_GPT_CLOCK_DIVIDER_VALUE_7_9_VALID                     (0U)
#define BSP_FEATURE_GPT_ODC_VALID_CHANNEL_MASK                            (0U)
#define BSP_FEATURE_GPT_32BIT_CHANNEL_MASK                                (0xFFU)
#define BSP_FEATURE_GPT_CLOCK_SOURCE                                      (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_GPT_STATUS_REGISTER                                   GTST
#define BSP_FEATURE_GPT_OUTPUT_DISABLE_REQUEST_STATUS_MASK                (R_GPT0_GTST_OABLF_Msk | \
                                                                           R_GPT0_GTST_OABHF_Msk | \
                                                                           R_GPT0_GTST_DTEF_Msk)
#define BSP_FEATURE_GPT_SUPPORT_EXTENDED_INTERRUPT_SKIP                   (0U)
#define BSP_FEATURE_GPT_SHARED_OVFUNF_INTERRUPT                           (1U)
#define BSP_FEATURE_GPT_OVF_STATUS_MASK                                   (R_INTC_IM33_PEISR_PEVSTAT0_Msk)
#define BSP_FEATURE_GPT_UNF_STATUS_MASK                                   (R_INTC_IM33_PEISR_PEUSTAT0_Msk)

/* GTM-Related Definitions */
#define BSP_FEATURE_GTM_MAX_CHANNEL                                       (3U)
#define BSP_FEATURE_GTM_VALID_CHANNEL_MASK                                (0x07U)
#define BSP_FEATURE_GTM_SOURCE_CLOCK                                      (FSP_PRIV_CLOCK_P0CLK)

/* I3C-Related Definitions */
#define BSP_FEATURE_I3C_B_MAX_DEV_COUNT                                   (8U)
#define BSP_FEATURE_I3C_B_NTDTBP0_DEPTH                                   (16U)
#define BSP_FEATURE_I3C_B_IBI_DATA_DEPTH                                  (8U)
#define BSP_FEATURE_I3C_B_NUM_CHANNELS                                    (1U)
#define BSP_FEATURE_I3C_B_MSTP_OFFSET                                     (9U)

/* ICU-Related Definitions */
#define BSP_FEATURE_ICU_HAS_INTPMSEL_REG                                  (1)
#define BSP_FEATURE_ICU_HAS_INTTSEL_REG                                   (1)
#define BSP_FEATURE_ICU_HAS_MISR4_REG                                     (1)
#define BSP_FEATURE_ICU_HAS_SWISR_REG                                     (1)
#define BSP_FEATURE_ICU_HAS_PEISR_REG                                     (1)

/* IIC-Related Definitions */
#define BSP_FEATURE_IIC_SOURCE_CLOCK(channel)    (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_IIC_MAX_CHANNEL                                       (4U)
#define BSP_FEATURE_IIC_VALID_CHANNEL_MASK                                (0x0F)
#define BSP_FEATURE_IIC_REGISTER_SIZE_BY_BIT                              (8U)

/* INTC-Related Definitions */
#define BSP_FEATURE_INTC_IRQ_VALID_CHANNEL_MASK                           (0xFFFFU)
#define BSP_FEATURE_INTC_TINT_VALID_CHANNEL_MASK                          (0xFFFFFFFFU)
#define BSP_FEATURE_INTC_BASE_ADDR                                        (R_INTC_IM33)
#define BSP_FEATURE_INTC_IRQ_INTTSEL_MAX_CHANNEL                          (15U)
#define BSP_FEATURE_INTC_IRQ_INTTSEL_MIN_CHANNEL                          (8U)
#define BSP_FEATURE_INTC_TINT_INTTSEL_MAX_CHANNEL                         (31U)
#define BSP_FEATURE_INTC_TINT_INTTSEL_MIN_CHANNEL                         (4U)
#define BSP_FEATURE_INTTSEL_REG_LENGTH                                    (32)
#define BSP_FEATURE_INTC_TINT_INTTSEL_SET_VALUE                           (0)
#define BSP_FEATURE_INTC_IRQ_INTTSEL_SET_VALUE                            (1)
#define BSP_FEATURE_INTC_TINT_INTTSEL_INVALID_CHANNEL_MASK                (0xFU)
#define BSP_FEATURE_INTC_IRQ_INTTSEL_INVALID_CHANNEL_MASK                 (0xFFU)
#define BSP_FEATURE_INTC_IRQ_INTTSEL_POS_OFFSET                           (16)
#define BSP_FEATURE_INTC_TINT_TSSR_TSSEL_NUMBER                           (4U)
#define BSP_FEATURE_INTC_TINT_TSSR_TSSEL_TIEN_MASK                        (0x7FU)
#define BSP_FEATURE_INTC_TINT_TSSR_TSSEL_TIEN_WIDTH                       (8U)
#define BSP_FEATURE_INTC_TINT_TSSR_TIEN_MASK                              (1U)
#define BSP_FEATURE_INTC_TINT_TSSR_TIEN_WIDTH                             (7U)

/* IOPORT-Related Definitions */
#define BSP_FEATURE_IOPORT_PORT_GROUP_NUM                                 (0U)
#define BSP_FEATURE_IOPORT_SINGLE_PORT_NUM                                (0U)
#define BSP_FEATURE_IOPORT_HAS_DEDICATED_NMI                              (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_PERIPHERAL_FIL                         (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_PERIPHERAL_FIL_NMI                     (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_CLONE_CHANNEL                          (1U)
#define BSP_FEATURE_IOPORT_SUPPORT_SR_REG                                 (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_NOD_REG                                (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_SMT_REG                                (0U)
#define BSP_FEATURE_IOPORT_SUPPORT_PUPD_SP                                (1U)
#define BSP_FEATURE_IOPORT_SUPPORT_IEN_GP                                 (1U)
#define BSP_FEATURE_IOPORT_PFC_REG_BITFIELD                               (0xFU)
#define BSP_FEATURE_IOPORT_GP_REG_BASE_NUM                                _22
#define BSP_FEATURE_IOPORT_REG_POSTFIX_L
#define BSP_FEATURE_IOPORT_SP_REG_BASE_NUM                                (5U)
#define BSP_FEATURE_IOPORT_FIL_SP_REG_BASE_NUM                            _22
#define BSP_FEATURE_IOPORT_IEN_SP_REG_POSTFIX_L                           _L
#define BSP_FEATURE_IOPORT_IEN_GP_REG_POSTFIX_L
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM                            9
#define BSP_FEATURE_IOPORT_IEN_SP_REG_BASE_NUM_SYM                        _09
#define BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM                            (0U)
#define BSP_FEATURE_IOPORT_IEN_GP_REG_BASE_NUM_SYM                        _22
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_POSTFIX_L
#define BSP_FEATURE_IOPORT_IOLH_GP_REG_POSTFIX_L                          _L
#define BSP_FEATURE_IOPORT_IOLH_GP_REG_BASE_NUM                           (1U)
#define BSP_FEATURE_IOPORT_IOLH_GP_REG_BASE_NUM_SYM                       _23
#define BSP_FEATURE_IOPORT_IOLH_SP_REG_BASE_NUM                           _05
#define BSP_FEATURE_IOPORT_SR_SP_REG_BASE_NUM                             (0U)
#define BSP_FEATURE_IOPORT_NOD_SP_REG_BASE_NUM                            (0U)
#define BSP_FEATURE_IOPORT_PUPD_SP_REG_POSTFIX_L
#define BSP_FEATURE_IOPORT_PUPD_GP_REG_POSTFIX_L                          _L
#define BSP_FEATURE_IOPORT_PUPD_GP_REG_BASE_NUM                           (1U)
#define BSP_FEATURE_IOPORT_PUPD_GP_REG_BASE_NUM_SYM                       _23
#define BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM                           6
#define BSP_FEATURE_IOPORT_PUPD_SP_REG_BASE_NUM_SYM                       _06
#define BSP_FEATURE_IOPORT_GROUP1_PORT                                    (0U)
#define BSP_FEATURE_IOPORT_GROUP2_PORT                                    (0U)
#define BSP_FEATURE_IOPORT_FIL_IRQ_FUNC                                   (0U)
#define BSP_FEATURE_IOPORT_FIL_DMAC_FUNC                                  (0U)
#define BSP_FEATURE_IOPORT_NMI_FUNC                                       (0U)
#define BSP_FEATURE_IOPORT_NMI_PIN                                        (0U)
#define BSP_FEATURE_IOPORT_PWPR_PFCWE_OFFSET                              (6U)
#define BSP_FEATURE_IOPORT_PWPR_B0WI_OFFSET                               (7U)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_PORT_OFFSET                      (2U)
#define BSP_FEATURE_IOPORT_ClONE_CHANNEL_RIIC_FUNC                        (IOPORT_PERIPHERAL_MODE4)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RIIC_BASE_NUM                    (2U)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RIIC_BASE_BIT                    (0U)
#define BSP_FEATURE_IOPORT_ClONE_CHANNEL_RSCI_FUNC                        (IOPORT_PERIPHERAL_MODE5)
#define BSP_FEATURE_IOPORT_ClONE_CHANNEL_RSCI_FUNC_EXT                    (IOPORT_PERIPHERAL_MODE6)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RSCI_BASE_NUM                    (1U)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RSCI_BASE_BIT                    (0xCU)
#define BSP_FEATURE_IOPORT_ClONE_CHANNEL_RSPI_FUNC                        (IOPORT_PERIPHERAL_MODE2)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RSPI_BASE_NUM                    (1U)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_RSPI_BASE_BIT                    (8U)
#define BSP_FEATURE_IOPORT_ClONE_CHANNEL_SCIF_FUNC                        (IOPORT_PERIPHERAL_MODE7)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_SCIF_BASE_NUM                    (3U)
#define BSP_FEATURE_IOPORT_CLONE_CHANNEL_SCIF_BASE_BIT                    (4U)

/* MHU-Related Definitions */
#define BSP_FEATURE_MHU_FOR_CM33_MAX_CHANNELS                             (19)
#define BSP_FEATURE_MHU_NS_VALID_CHANNEL_MASK                             (0xF8888U)
#define BSP_FEATURE_MHU_NS_SEND_TYPE_RSP_VALID_CHANNEL_MASK               (0x8888U)
#define BSP_FEATURE_MHU_NS_SWINT_GET_VALID_CHANNEL_MASK                   (0x0FU)
#define BSP_FEATURE_MHU_NS_SWINT_SET_VALID_CHANNEL_MASK                   (0xF0U)
#define BSP_FEATURE_MHU_S_VALID_CHANNEL_MASK                              (0xF8888U)
#define BSP_FEATURE_MHU_S_SEND_TYPE_RSP_VALID_CHANNEL_MASK                (0x8888U)
#define BSP_FEATURE_MHU_IRQ_BUNDLE                                        (1)

/* MTU3-Related Definitions */
#define BSP_FEATURE_MTU3_VALID_CHANNEL_MASK                               (0x01FF)
#define BSP_FEATURE_MTU3_MAX_CHANNELS                                     (9U)
#define BSP_FEATURE_MTU3_CLOCK_DIVIDER_STEP_SIZE                          (2U)
#define BSP_FEATURE_MTU3_CLOCK_DIVIDER_VALUE_7_9_VALID                    (0U)
#define BSP_FEATURE_MTU3_CLOCK_SOURCE                                     (FSP_PRIV_CLOCK_P0CLK)

/* PDM-Related Definitions */
#define BSP_FEATURE_PDM_UNITS                                             (1)
#define BSP_FEATURE_PDM_CHANNELS_PER_UNIT                                 (3)

/* POEG-Related Definitions */
#define BSP_FEATURE_POEG_CHANNEL_MASK                                     (0xFU)

/* RTC-Related Definitions */
#define BSP_FEATURE_RTC_PES_256_HZ_UNSELECTABLE                           (1)
#define BSP_FEATURE_RTC_INTERRUPT_TYPE_IS_LEVEL                           (1)
#define BSP_FEATURE_RTC_HAS_RCR3                                          (1)
#define BSP_FEATURE_RTC_HAS_TCEN                                          (1)
#define BSP_FEATURE_RTC_TCNF_WIDTH_3BITS                                  (0)
#define BSP_FEATURE_RTC_RTCCR_CHANNELS                                    (1)
#define BSP_FEATURE_RTC_COUNT_SOURCE_CLOCK_FREQ_HZ                        (32768U)
#define BSP_FEATURE_RTC_HAS_RCR4                                          (0)
#define BSP_FEATURE_RTC_HAS_FREQUENCY_REG                                 (0)

/* SCI-Related Definitions */
#define BSP_FEATURE_SCI_MAX_CHANNELS                                      (4U)
#define BSP_FEATURE_SCI_CHANNELS_MASK                                     (0xFU)
#define BSP_FEATURE_SCI_UART_FIFO_CHANNELS                                (0xFU)
#define BSP_FEATURE_SCI_UART_FIFO_DEPTH                                   (32U)
#define BSP_FEATURE_SCI_UART_SUPPORT_HALF_DATA_FUNCTION                   (1)
#define BSP_FEATURE_SCI_HAS_SEPARATE_CLOCK_FOR_CHANNEL                    (1)
#define BSP_FEATURE_SCI_B_PCLK                                            (FSP_PRIV_CLOCK_P0CLK)
#define BSP_FEATURE_SCI_B_TCLK(source)    (FSP_PRIV_CLOCK_P13CLK + source)
#define BSP_FEATURE_SCI_B_DIFFERENT_TCLK_PATH_EACH_CHANNEL                (1)

/* SCIF-Related Definitions */
#define BSP_FEATURE_SCIF_MAX_CHANNEL                                      (6U)
#define BSP_FEATURE_SCIF_CHANNELS_MASK                                    (0x3FU)
#define BSP_FEATURE_SCIF_RTSCTS_SUPPORT                                   (0)
#define BSP_FEATURE_SCIF_CKS2_LIMITATION                                  (1)
#define BSP_FEATURE_SCIF_CLOCK                                            (FSP_PRIV_CLOCK_P0CLK)

/* SPI-Related Definitions */
#define BSP_FEATURE_SPI_MAX_CHANNEL                                       (3U)
#define BSP_FEATURE_SPI_PCLK                                              (FSP_PRIV_CLOCK_P3CLK)
#define BSP_FEATURE_SPI_TCLK(source)    (FSP_PRIV_CLOCK_P17CLK + source)
#define BSP_FEATURE_SPI_B_DIFFERENT_TCLK_PATH_EACH_CHANNEL                (1)

/* TrustZone-Related Definitions */
#define BSP_FEATURE_TZ_HAS_TRUSTZONE                                      (1U)

/* WDT-Related Definitions */
#define BSP_FEATURE_WDT_TYPE                                              (0U)
#define BSP_FEATURE_WDT_MAX_CHANNEL                                       (3U)

/* XSPI-Related Definitions */
#define BSP_FEATURE_XSPI_CHANNELS                                         (0x01U)
#define BSP_FEATURE_XSPI_NUM_CHIP_SELECT                                  (2U)
#define BSP_FEATURE_XSPI_NUM_UNITS                                        (1U)
#define BSP_FEATURE_XSPI_DO_NOT_HAS_CSSCTL                                (1U)
#define BSP_FEATURE_XSPI_START_ADDRESS                                    (0x80000000)
#define BSP_FEATURE_XSPI_DEVICE_CS0_1_ADDRESS_DELTA                       (0x08000000)

#endif                                 /* BSP_FEATURE_H */
