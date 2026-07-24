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

/* BSP Common Includes. */
 #include "../../src/bsp/mcu/all/bsp_common.h"

/* BSP MPU Specific Includes. */
 #include "../../src/bsp/mcu/all/bsp_register_protection.h"
 #include "../../src/bsp/mcu/all/bsp_irq.h"
 #include "../../src/bsp/mcu/all/bsp_io.h"
 #include "../../src/bsp/mcu/all/bsp_clocks.h"
 #include "../../src/bsp/mcu/all/bsp_module_stop.h"
 #include "../../src/bsp/mcu/all/bsp_semaphore.h"
 #include "../../src/bsp/mcu/all/bsp_reset.h"
 #include "../../src/bsp/mcu/all/bsp_cache.h"
 #include "../../src/bsp/mcu/all/bsp_slave_stop.h"

/*BSP MPU Includes*/
 #ifdef BSP_CFG_CORE_CR52
  #include "../../src/bsp/mcu/all/cr/bsp_mpu_core.h"
 #endif

/*BSP MMU Includes*/
 #ifdef BSP_CFG_CORE_CA55
  #include "../../src/bsp/mcu/all/ca/bsp_mmu_core.h"
 #endif

/* Factory MPU information. */
 #include "../../inc/fsp_features.h"

/* BSP Common Includes (Other than bsp_common.h) */
 #include "../../src/bsp/mcu/all/bsp_delay.h"
 #include "../../src/bsp/mcu/all/bsp_mcu_api.h"

/* BSP TFU Includes. */
 #if BSP_FEATURE_TFU_SUPPORTED
  #include "../../src/bsp/mcu/all/bsp_tfu.h"
 #endif

 #if BSP_FEATURE_TZC400_SUPPORTED
  #include "../../src/bsp/mcu/all/bsp_tzc400.h"
 #endif

/* BSP DDR Includes. */
 #if BSP_FEATURE_DDR_SUPPORTED
  #include "../../src/bsp/mcu/rzt2n/bsp_ddr.h"
 #endif

 #if BSP_FEATURE_ADDRESS_EXPANDER_SUPPORTED
  #include "../../src/bsp/mcu/all/bsp_address_expander.h"
 #endif

 #if (BSP_CFG_OTFDE0_SUPPORT_ENABLE || BSP_CFG_OTFDE1_SUPPORT_ENABLE)
  #include "../../src/bsp/mcu/all/bsp_otfde.h"
 #endif

 #if (BSP_CFG_ESD_BOOT || BSP_CFG_EMMC_BOOT)
  #include "../../src/bsp/mcu/all/bsp_sdhi.h"
 #endif

/** Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Define overrides required for this MPU. */
 #define BSP_OVERRIDE_ADC_INFO_T
 #define BSP_OVERRIDE_ADC_CHANNEL_T
 #define BSP_OVERRIDE_CGC_CLOCK_T
 #define BSP_OVERRIDE_CGC_PLL_CFG_T
 #define BSP_OVERRIDE_CGC_DIVIDER_CFG_T
 #define BSP_OVERRIDE_CGC_CLOCK_CHANGE_T
 #define BSP_OVERRIDE_CGC_CLOCKS_CFG_T
 #define BSP_OVERRIDE_ELC_PERIPHERAL_T
 #define BSP_OVERRIDE_ERROR_EVENT_T
 #define BSP_OVERRIDE_ETHER_EVENT_T
 #define BSP_OVERRIDE_ETHER_CALLBACK_ARGS_T
 #define BSP_OVERRIDE_ETHER_PHY_LSI_TYPE_T
 #define BSP_OVERRIDE_ETHER_SWITCH_EVENT_T
 #define BSP_OVERRIDE_ETHER_SWITCH_CALLBACK_ARGS_T
 #define BSP_OVERRIDE_NAND_FLASH_TIMING_INFO_T
 #define BSP_OVERRIDE_POE3_STATE_T
 #define BSP_OVERRIDE_POE3_ACTIVE_LEVEL_T
 #define BSP_OVERRIDE_POEG_STATE_T
 #define BSP_OVERRIDE_POEG_TRIGGER_T
 #define BSP_OVERRIDE_TIMER_EVENT_T
 #define BSP_OVERRIDE_TRANSFER_MODE_T
 #define BSP_OVERRIDE_TRANSFER_SIZE_T
 #define BSP_OVERRIDE_TRANSFER_ADDR_MODE_T
 #define BSP_OVERRIDE_TRANSFER_CALLBACK_ARGS_T
 #define BSP_OVERRIDE_TRANSFER_INFO_T

/* Override definitions. */

 #define ELC_PERIPHERAL_NUM          (194U)

/* Private definition to set enumeration values. */
 #define IOPORT_P_OFFSET             (0U)
 #define IOPORT_PM_OFFSET            (1U)
 #define IOPORT_PMC_OFFSET           (3U)
 #define IOPORT_PFC_OFFSET           (4U)
 #define IOPORT_DRCTL_OFFSET         (10U)
 #define IOPORT_RSELP_OFFSET         (16U)
 #define IOPORT_IRQ_NUM_OFFSET       (17U)
 #define IOPORT_IRQ_ENABLE_OFFSET    (22U)

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
namespace RZT
{
  #endif
 #endif

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/*==============================================
 * ADC API Overrides
 *==============================================*/

/** ADC channels */
typedef enum e_adc_channel
{
    ADC_CHANNEL_0                 = 0,     ///< ADC channel 0
    ADC_CHANNEL_1                 = 1,     ///< ADC channel 1
    ADC_CHANNEL_2                 = 2,     ///< ADC channel 2
    ADC_CHANNEL_3                 = 3,     ///< ADC channel 3
    ADC_CHANNEL_4                 = 4,     ///< ADC channel 4
    ADC_CHANNEL_5                 = 5,     ///< ADC channel 5
    ADC_CHANNEL_6                 = 6,     ///< ADC channel 6
    ADC_CHANNEL_7                 = 7,     ///< ADC channel 7
    ADC_CHANNEL_8                 = 8,     ///< ADC channel 8
    ADC_CHANNEL_9                 = 9,     ///< ADC channel 9
    ADC_CHANNEL_10                = 10,    ///< ADC channel 10
    ADC_CHANNEL_11                = 11,    ///< ADC channel 11
    ADC_CHANNEL_12                = 12,    ///< ADC channel 12
    ADC_CHANNEL_13                = 13,    ///< ADC channel 13
    ADC_CHANNEL_14                = 14,    ///< ADC channel 14
    ADC_CHANNEL_15                = 15,    ///< ADC channel 15
    ADC_CHANNEL_16                = 16,    ///< ADC channel 16
    ADC_CHANNEL_17                = 17,    ///< ADC channel 17
    ADC_CHANNEL_18                = 18,    ///< ADC channel 18
    ADC_CHANNEL_19                = 19,    ///< ADC channel 19
    ADC_CHANNEL_20                = 20,    ///< ADC channel 20
    ADC_CHANNEL_21                = 21,    ///< ADC channel 21
    ADC_CHANNEL_22                = 22,    ///< ADC channel 22
    ADC_CHANNEL_23                = 23,    ///< ADC channel 23
    ADC_CHANNEL_24                = 24,    ///< ADC channel 24
    ADC_CHANNEL_25                = 25,    ///< ADC channel 25
    ADC_CHANNEL_26                = 26,    ///< ADC channel 26
    ADC_CHANNEL_27                = 27,    ///< ADC channel 27
    ADC_CHANNEL_28                = 28,    ///< ADC channel 28
    ADC_CHANNEL_DUPLEX_A          = 50,    ///< Data duplexing register A
    ADC_CHANNEL_DUPLEX_B          = 51,    ///< Data duplexing register B
    ADC_CHANNEL_DUPLEX            = -4,    ///< Data duplexing register
    ADC_CHANNEL_TEMPERATURE       = -3,    ///< Temperature sensor output
    ADC_CHANNEL_VOLT              = -2,    ///< Internal reference voltage
    ADC_CHANNEL_0_DSMIF_CAPTURE_A = 0x100, ///< ADC channel 0 Capture Current Data Register A
    ADC_CHANNEL_0_DSMIF_CAPTURE_B = 0x200, ///< ADC channel 0 Capture Current Data Register B
    ADC_CHANNEL_1_DSMIF_CAPTURE_A = 0x101, ///< ADC channel 1 Capture Current Data Register A
    ADC_CHANNEL_1_DSMIF_CAPTURE_B = 0x201, ///< ADC channel 1 Capture Current Data Register B
    ADC_CHANNEL_2_DSMIF_CAPTURE_A = 0x102, ///< ADC channel 2 Capture Current Data Register A
    ADC_CHANNEL_2_DSMIF_CAPTURE_B = 0x202, ///< ADC channel 2 Capture Current Data Register B
} adc_channel_t;

/*==============================================
 * CGC API Overrides
 *==============================================*/

/** Divider values of clock provided to xSPI */
typedef enum e_cgc_fsel_xspi_clock_div
{
    CGC_FSEL_XSPI_CLOCK_DIV_6  = 0x02, ///< XSPI_CLKn 133.3MHz (XSPI base clock divided by 3)
    CGC_FSEL_XSPI_CLOCK_DIV_8  = 0x03, ///< XSPI_CLKn 100.0MHz / 75.0MHz (XSPI base clock divided by 3 / divided by 4)
    CGC_FSEL_XSPI_CLOCK_DIV_16 = 0x04, ///< XSPI_CLKn 50.0MHz / 37.5MHz (XSPI base clock divided by 3 / divided by 4)
    CGC_FSEL_XSPI_CLOCK_DIV_32 = 0x05, ///< XSPI_CLKn 25.0MHz (XSPI base clock divided by 3)
    CGC_FSEL_XSPI_CLOCK_DIV_64 = 0x06, ///< XSPI_CLKn 12.5MHz (XSPI base clock divided by 3)
} cgc_fsel_xspi_clock_div_t;

/** Divider values of base clock generated for xSPI */
typedef enum e_cgc_divsel_xspi_clock_div
{
    CGC_DIVSEL_XSPI_CLOCK_DIV_3 = 0x00, ///< XSPI base clock divided by 3
    CGC_DIVSEL_XSPI_CLOCK_DIV_4 = 0x01, ///< XSPI base clock divided by 4
} cgc_divsel_xspi_clock_div_t;

/** Clock output divider values */
typedef enum e_cgc_clock_out_clock_div
{
    CGC_CLOCK_OUT_CLOCK_DIV_2 = 0,     ///< CKIO 100.0MHz
    CGC_CLOCK_OUT_CLOCK_DIV_3 = 1,     ///< CKIO 66.7MHz
    CGC_CLOCK_OUT_CLOCK_DIV_4 = 2,     ///< CKIO 50.0MHz
    CGC_CLOCK_OUT_CLOCK_DIV_5 = 3,     ///< CKIO 40.0MHz
    CGC_CLOCK_OUT_CLOCK_DIV_6 = 4,     ///< CKIO 33.3MHz
    CGC_CLOCK_OUT_CLOCK_DIV_7 = 5,     ///< CKIO 28.6MHz
    CGC_CLOCK_OUT_CLOCK_DIV_8 = 6,     ///< CKIO 25.0MHz
} cgc_clock_out_clock_div_t;

/** CANFD clock divider values */
typedef enum e_cgc_canfd_clock_div
{
    CGC_CANFD_CLOCK_DIV_10 = 0,        ///< CANFD clock 80.0MHz
    CGC_CANFD_CLOCK_DIV_20 = 1,        ///< CANFD clock 40.0MHz
} cgc_canfd_clock_div_t;

/** PHY clock source identifiers */
typedef enum e_cgc_phy_clock
{
    CGC_PHY_CLOCK_PLL3     = 0,        ///< PLL3 divider clock
    CGC_PHY_CLOCK_MAIN_OSC = 1,        ///< Main clock oscillator
} cgc_phy_clock_t;

/** SPI asynchronous serial clock frequency */
typedef enum e_cgc_spi_async_clock
{
    CGC_SPI_ASYNC_CLOCK_75MHZ = 0,     ///< SPI asynchronous serial clock 75MHz
    CGC_SPI_ASYNC_CLOCK_80MHZ = 1,     ///< SPI asynchronous serial clock 80MHz
    CGC_SPI_ASYNC_CLOCK_96MHZ = 2,     ///< SPI asynchronous serial clock 96MHz
} cgc_spi_async_clock_t;

/** SCI asynchronous serial clock frequency */
typedef enum e_cgc_sci_async_clock
{
    CGC_SCI_ASYNC_CLOCK_75MHZ    = 0,  ///< SCI asynchronous serial clock 75MHz
    CGC_SCI_ASYNC_CLOCK_80MHZ    = 1,  ///< SCI asynchronous serial clock 80MHz
    CGC_SCI_ASYNC_CLOCK_96MHZ    = 2,  ///< SCI asynchronous serial clock 96MHz
    CGC_SCI_ASYNC_CLOCK_EXTERNAL = 3,  ///< SCI asynchronous serial clock External (SCIEXTCLK) up to 20 MHz
} cgc_sci_async_clock_t;

/** SCIE asynchronous serial clock frequency */
typedef enum e_cgc_scie_async_clock
{
    CGC_SCIE_ASYNC_CLOCK_75MHZ    = 0, ///< SCIE asynchronous serial clock 75MHz
    CGC_SCIE_ASYNC_CLOCK_80MHZ    = 1, ///< SCIE asynchronous serial clock 80MHz
    CGC_SCIE_ASYNC_CLOCK_96MHZ    = 2, ///< SCIE asynchronous serial clock 96MHz
    CGC_SCIE_ASYNC_CLOCK_EXTERNAL = 3, ///< SCIE asynchronous serial clock External (SCIEXTCLK) up to 20 MHz
} cgc_scie_async_clock_t;

/** ENCOUT clock frequency */
typedef enum e_cgc_encout_clock
{
    CGC_ENCOUT_CLOCK_20MHZ = 0,        ///< ENCOUT provided clock 20MHz
    CGC_ENCOUT_CLOCK_80MHZ = 1,        ///< ENCOUT provided clock 80MHz
} cgc_encout_clock_t;

/** Divider values of clock generated for SDHI */
typedef enum e_cgc_sdhi_sel_clock_div
{
    CGC_SDHI_SEL_CLOCK_PLL4 = 0,       ///< PLL4 divider clock
    CGC_SDHI_SEL_CLOCK_PLL1 = 1,       ///< PLL1 divider clock
} cgc_sdhi_sel_clock_div_t;

/** Divider values of clock provided to NANDC */
typedef enum e_cgc_nandc_sel_clock_div
{
    CGC_NANDC_SEL_CLOCK_DIV_4   = 0,   ///< NANDC clock 400.0MHz (PLL1 divided by 4)
    CGC_NANDC_SEL_CLOCK_DIV_8   = 1,   ///< NANDC clock 200.0MHz (PLL1 divided by 8)
    CGC_NANDC_SEL_CLOCK_DIV_32  = 2,   ///< NANDC clock 50.0MHz (PLL1 divided by 32)
    CGC_NANDC_SEL_CLOCK_DIV_40  = 3,   ///< NANDC clock 40.0MHz (PLL1 divided by 40)
    CGC_NANDC_SEL_CLOCK_DIV_48  = 4,   ///< NANDC clock 33.3MHz (PLL1 divided by 48)
    CGC_NANDC_SEL_CLOCK_DIV_56  = 5,   ///< NANDC clock 28.6MHz (PLL1 divided by 56)
    CGC_NANDC_SEL_CLOCK_DIV_80  = 6,   ///< NANDC clock 20.0MHz (PLL1 divided by 80)
    CGC_NANDC_SEL_CLOCK_DIV_128 = 7,   ///< NANDC clock 12.5MHz (PLL1 divided by 128)
    CGC_NANDC_SEL_CLOCK_DIV_160 = 8,   ///< NANDC clock 10.0MHz (PLL1 divided by 160)
    CGC_NANDC_SEL_CLOCK_DIV_200 = 9,   ///< NANDC clock 8.0MHz (PLL1 divided by 200)
} cgc_nandc_sel_clock_div_t;

/** CPU clock divider values */
typedef enum e_cgc_cpu_clock_div
{
    CGC_CPU_CLOCK_DIV_4 = 0,           ///< CR52 400MHz, CA55 600MHz
    CGC_CPU_CLOCK_DIV_2 = 1,           ///< CR52 800MHz, CA55 1200MHz
} cgc_cpu_clock_div_t;

/** CPU clock divider values for CA55 DynamIQ Shared Unit (DSU). */
typedef enum e_cgc_cpu_clock_ca55_dsu_div
{
    CGC_CPU_CLOCK_CA55_DSU_DIV_2 = 0,  ///< DSU 500MHz
    CGC_CPU_CLOCK_CA55_DSU_DIV_1 = 1,  ///< DSU 1000MHz
} cgc_cpu_clock_ca55_dsu_div_t;

/** System clock source identifiers */
typedef enum e_cgc_clock
{
    CGC_CLOCK_LOCO = 0,                ///< The low speed on chip oscillator
    CGC_CLOCK_PLL0 = 1,                ///< The PLL0 oscillator
    CGC_CLOCK_PLL1 = 2,                ///< The PLL1 oscillator
    CGC_CLOCK_PLL2 = 3,                ///< The PLL2 oscillator
    CGC_CLOCK_PLL3 = 4,                ///< The PLL3 oscillator
    CGC_CLOCK_PLL4 = 5,                ///< The PLL4 oscillator
} cgc_clock_t;

struct st_cgc_pll_ssc_cfg
{
    uint8_t pll_ssc_enable : 1;               ///< SSC function enable
    uint8_t pll_ssc_modulation_freq_ctrl;     ///< Modulation frequency control parameter for SSC
    uint8_t pll_ssc_modulation_rate_ctrl : 6; ///< Modulation rate control parameter for SSC
};

/* Please refer to the struct st_cgc_pll_ssc_cfg. */
typedef struct st_cgc_pll_ssc_cfg cgc_pll_ssc_cfg_t;

/** Clock configuration structure - Used as an input parameter to the @ref RZT::cgc_api_t::clockStart function for the PLL clock. */
struct st_cgc_pll_cfg
{
    cgc_pll_ssc_cfg_t pll0_ssc_cfg;    ///< SSC settings of PLL0 (for RZ/T2H and RZ/T2N).
    cgc_pll_ssc_cfg_t pll2_ssc_cfg;    ///< SSC settings of PLL2 (for RZ/T2H and RZ/T2N).
};

/** Clock configuration structure - Dummy definition because it is not used in this MPU.
 * Set NULL as an input parameter to the cgc_api_t::clockStart function for the PLL clock. Please refer to the struct st_cgc_pll_cfg. */
typedef struct st_cgc_pll_cfg cgc_pll_cfg_t;

/** Clock configuration structure */
struct st_cgc_divider_cfg
{
    union
    {
        uint32_t sckcr_w;                                ///< System Clock Control Register

        struct
        {
            cgc_fsel_xspi_clock_div_t fselxspi0     : 3; ///< Divider value for XSPI_CLK0
            uint32_t                                : 3;
            cgc_divsel_xspi_clock_div_t divselxspi0 : 1; ///< Divider base value for XSPI_CLK0
            uint32_t                                : 1;
            cgc_fsel_xspi_clock_div_t fselxspi1     : 3; ///< Divider value for XSPI_CLK1
            uint32_t                                : 3;
            cgc_divsel_xspi_clock_div_t divselxspi1 : 1; ///< Divider base value for XSPI_CLK1
            uint32_t                                : 1;
            cgc_clock_out_clock_div_t ckio_div      : 3; ///< Divider value for CKIO
            uint32_t                                : 1;
            cgc_canfd_clock_div_t fselcanfd_div     : 1; ///< Divider value for CANFD clock
            uint32_t                                : 11;
        } sckcr_b;
    };

    union
    {
        uint32_t sckcr2_w;                             ///< System Clock Control Register 2

        struct
        {
            cgc_cpu_clock_div_t cr52cpu0          : 2; ///< Divider value for Cortex-R52 CPU0
            cgc_cpu_clock_div_t cr52cpu1          : 2; ///< Divider value for Cortex-R52 CPU1
            uint32_t                              : 4;
            cgc_cpu_clock_div_t ca55core0         : 1; ///< Divider value for Cortex-A55 Core0
            cgc_cpu_clock_div_t ca55core1         : 1; ///< Divider value for Cortex-A55 Core1
            uint32_t                              : 2;
            cgc_cpu_clock_ca55_dsu_div_t ca55sclk : 1; ///< Divider value for Cortex-A55 DSU
            uint32_t                              : 3;
            cgc_spi_async_clock_t spi3_async_sel  : 2; ///< SPI3 asynchronous serial clock
            cgc_sci_async_clock_t sci5_async_sel  : 2; ///< SCI5 asynchronous serial clock
            uint32_t                              : 12;
        } sckcr2_b;
    };

    union
    {
        uint32_t sckcr3_w;                            ///< System Clock Control Register 3

        struct
        {
            cgc_spi_async_clock_t spi0_async_sel : 2; ///< SPI0 asynchronous serial clock
            cgc_spi_async_clock_t spi1_async_sel : 2; ///< SPI1 asynchronous serial clock
            cgc_spi_async_clock_t spi2_async_sel : 2; ///< SPI2 asynchronous serial clock
            cgc_sci_async_clock_t sci0_async_sel : 2; ///< SCI0 asynchronous serial clock
            cgc_sci_async_clock_t sci1_async_sel : 2; ///< SCI1 asynchronous serial clock
            cgc_sci_async_clock_t sci2_async_sel : 2; ///< SCI2 asynchronous serial clock
            cgc_sci_async_clock_t sci3_async_sel : 2; ///< SCI3 asynchronous serial clock
            cgc_sci_async_clock_t sci4_async_sel : 2; ///< SCI4 asynchronous serial clock
            uint32_t                             : 8;
            cgc_phy_clock_t eth0_refclk_sel      : 1; ///< Reference clock to the external Ethernet0 PHY
            cgc_phy_clock_t eth1_refclk_sel      : 1; ///< Reference clock to the external Ethernet1 PHY
            cgc_phy_clock_t eth2_refclk_sel      : 1; ///< Reference clock to the external Ethernet2 PHY
            cgc_phy_clock_t eth3_refclk_sel      : 1; ///< Reference clock to the external Ethernet3 PHY
            cgc_phy_clock_t eth4_refclk_sel      : 1; ///< Reference clock to the external Ethernet4 PHY
            uint32_t                             : 3;
        } sckcr3_b;
    };

    union
    {
        uint32_t sckcr4_w;                              ///< System Clock Control Register 4

        struct
        {
            cgc_scie_async_clock_t scie0_async_sel : 2; ///< SCIE0 asynchronous serial clock
            cgc_scie_async_clock_t scie1_async_sel : 2; ///< SCIE1 asynchronous serial clock
            cgc_scie_async_clock_t scie2_async_sel : 2; ///< SCIE2 asynchronous serial clock
            cgc_scie_async_clock_t scie3_async_sel : 2; ///< SCIE3 asynchronous serial clock
            cgc_scie_async_clock_t scie4_async_sel : 2; ///< SCIE4 asynchronous serial clock
            cgc_scie_async_clock_t scie5_async_sel : 2; ///< SCIE5 asynchronous serial clock
            cgc_scie_async_clock_t scie6_async_sel : 2; ///< SCIE6 asynchronous serial clock
            cgc_scie_async_clock_t scie7_async_sel : 2; ///< SCIE7 asynchronous serial clock
            uint32_t                               : 8;
            cgc_encout_clock_t encoutclk           : 1; ///< ENCOUT provided clock
            uint32_t                               : 7;
        } sckcr4_b;
    };

    union
    {
        uint32_t sckcr5_w;                             ///< System Clock Control Register 5

        struct
        {
            cgc_nandc_sel_clock_div_t nandcclksel : 4; ///< Divider value for NANDC
            uint32_t                              : 4;
            cgc_sdhi_sel_clock_div_t sdhi0clksel  : 1; ///< Divider value for SDHI0
            uint32_t                              : 1;
            cgc_sdhi_sel_clock_div_t sdhi1clksel  : 1; ///< Divider value for SDHI1
            uint32_t                              : 21;
        } sckcr5_b;
    };
};

/** Clock configuration structure Please refer to the struct st_cgc_divider_cfg. */
typedef struct st_cgc_divider_cfg cgc_divider_cfg_t;

/** Clock options */
typedef enum e_cgc_clock_change
{
    CGC_CLOCK_CHANGE_START = 0,        ///< Start the clock
    CGC_CLOCK_CHANGE_STOP  = 1,        ///< Stop the clock
    CGC_CLOCK_CHANGE_NONE  = 2,        ///< No change to the clock
} cgc_clock_change_t;

/** Clock configuration */
struct st_cgc_clocks_cfg
{
    cgc_divider_cfg_t  divider_cfg;    ///< Clock dividers structure
    cgc_pll_ssc_cfg_t  pll0_ssc_cfg;   ///< Configuration of PLL0 SSC function setting
    cgc_pll_ssc_cfg_t  pll2_ssc_cfg;   ///< Configuration of PLL2 SSC function setting
    cgc_clock_change_t loco_state;     ///< State of LOCO
    cgc_clock_change_t pll0_state;     ///< State of PLL0
    cgc_clock_change_t pll2_state;     ///< State of PLL2
};

/** Clock configuration Please refer to the struct st_cgc_clocks_cfg. */
typedef struct st_cgc_clocks_cfg cgc_clocks_cfg_t;

/*==============================================
 * ELC API Overrides
 *==============================================*/

/** Possible peripherals to be linked to event signals (not all available on all MPUs) */
typedef enum e_elc_peripheral
{
    ELC_PERIPHERAL_MTU0           = (0),
    ELC_PERIPHERAL_MTU3           = (1),
    ELC_PERIPHERAL_MTU4           = (2),
    ELC_PERIPHERAL_GPT0_A         = (3),
    ELC_PERIPHERAL_GPT0_B         = (4),
    ELC_PERIPHERAL_GPT0_C         = (5),
    ELC_PERIPHERAL_GPT0_D         = (6),
    ELC_PERIPHERAL_GPT0_E         = (7),
    ELC_PERIPHERAL_GPT0_F         = (8),
    ELC_PERIPHERAL_GPT1_A         = (9),
    ELC_PERIPHERAL_GPT1_B         = (10),
    ELC_PERIPHERAL_GPT1_C         = (11),
    ELC_PERIPHERAL_GPT1_D         = (12),
    ELC_PERIPHERAL_GPT1_E         = (13),
    ELC_PERIPHERAL_GPT1_F         = (14),
    ELC_PERIPHERAL_GPT2_A         = (15),
    ELC_PERIPHERAL_GPT2_B         = (16),
    ELC_PERIPHERAL_GPT2_C         = (17),
    ELC_PERIPHERAL_GPT2_D         = (18),
    ELC_PERIPHERAL_GPT2_E         = (19),
    ELC_PERIPHERAL_GPT2_F         = (20),
    ELC_PERIPHERAL_GPT3_A         = (21),
    ELC_PERIPHERAL_GPT3_B         = (22),
    ELC_PERIPHERAL_GPT3_C         = (23),
    ELC_PERIPHERAL_GPT3_D         = (24),
    ELC_PERIPHERAL_GPT3_E         = (25),
    ELC_PERIPHERAL_GPT3_F         = (26),
    ELC_PERIPHERAL_GPT4_A         = (27),
    ELC_PERIPHERAL_GPT4_B         = (28),
    ELC_PERIPHERAL_GPT4_C         = (29),
    ELC_PERIPHERAL_GPT4_D         = (30),
    ELC_PERIPHERAL_GPT4_E         = (31),
    ELC_PERIPHERAL_GPT4_F         = (32),
    ELC_PERIPHERAL_GPT4_G         = (33),
    ELC_PERIPHERAL_GPT4_H         = (34),
    ELC_PERIPHERAL_ADC0_A         = (35),
    ELC_PERIPHERAL_ADC0_B         = (36),
    ELC_PERIPHERAL_ADC1_A         = (37),
    ELC_PERIPHERAL_ADC1_B         = (38),
    ELC_PERIPHERAL_ADC2_A         = (39),
    ELC_PERIPHERAL_ADC2_B         = (40),
    ELC_PERIPHERAL_DSMIF0_CAP0    = (41),
    ELC_PERIPHERAL_DSMIF0_CAP1    = (42),
    ELC_PERIPHERAL_DSMIF0_CAP2    = (43),
    ELC_PERIPHERAL_DSMIF0_CAP3    = (44),
    ELC_PERIPHERAL_DSMIF0_CAP4    = (45),
    ELC_PERIPHERAL_DSMIF0_CAP5    = (46),
    ELC_PERIPHERAL_DSMIF0_CDCNT0  = (47),
    ELC_PERIPHERAL_DSMIF0_CDCNT1  = (48),
    ELC_PERIPHERAL_DSMIF0_CDCNT2  = (49),
    ELC_PERIPHERAL_DSMIF1_CAP0    = (50),
    ELC_PERIPHERAL_DSMIF1_CAP1    = (51),
    ELC_PERIPHERAL_DSMIF1_CAP2    = (52),
    ELC_PERIPHERAL_DSMIF1_CAP3    = (53),
    ELC_PERIPHERAL_DSMIF1_CAP4    = (54),
    ELC_PERIPHERAL_DSMIF1_CAP5    = (55),
    ELC_PERIPHERAL_DSMIF1_CDCNT0  = (56),
    ELC_PERIPHERAL_DSMIF1_CDCNT1  = (57),
    ELC_PERIPHERAL_DSMIF1_CDCNT2  = (58),
    ELC_PERIPHERAL_DSMIF2_CAP0    = (59),
    ELC_PERIPHERAL_DSMIF2_CAP1    = (60),
    ELC_PERIPHERAL_DSMIF2_CAP2    = (61),
    ELC_PERIPHERAL_DSMIF2_CAP3    = (62),
    ELC_PERIPHERAL_DSMIF2_CAP4    = (63),
    ELC_PERIPHERAL_DSMIF2_CAP5    = (64),
    ELC_PERIPHERAL_DSMIF2_CDCNT0  = (65),
    ELC_PERIPHERAL_DSMIF2_CDCNT1  = (66),
    ELC_PERIPHERAL_DSMIF2_CDCNT2  = (67),
    ELC_PERIPHERAL_DSMIF3_CAP0    = (68),
    ELC_PERIPHERAL_DSMIF3_CAP1    = (69),
    ELC_PERIPHERAL_DSMIF3_CAP2    = (70),
    ELC_PERIPHERAL_DSMIF3_CAP3    = (71),
    ELC_PERIPHERAL_DSMIF3_CAP4    = (72),
    ELC_PERIPHERAL_DSMIF3_CAP5    = (73),
    ELC_PERIPHERAL_DSMIF3_CDCNT0  = (74),
    ELC_PERIPHERAL_DSMIF3_CDCNT1  = (75),
    ELC_PERIPHERAL_DSMIF3_CDCNT2  = (76),
    ELC_PERIPHERAL_DSMIF4_CAP0    = (77),
    ELC_PERIPHERAL_DSMIF4_CAP1    = (78),
    ELC_PERIPHERAL_DSMIF4_CAP2    = (79),
    ELC_PERIPHERAL_DSMIF4_CAP3    = (80),
    ELC_PERIPHERAL_DSMIF4_CAP4    = (81),
    ELC_PERIPHERAL_DSMIF4_CAP5    = (82),
    ELC_PERIPHERAL_DSMIF4_CDCNT0  = (83),
    ELC_PERIPHERAL_DSMIF4_CDCNT1  = (84),
    ELC_PERIPHERAL_DSMIF4_CDCNT2  = (85),
    ELC_PERIPHERAL_ENCIF_SS_TRG0  = (86),
    ELC_PERIPHERAL_ENCIF_SS_TRG1  = (87),
    ELC_PERIPHERAL_ENCIF_SS_TRG2  = (88),
    ELC_PERIPHERAL_ENCIF_SS_TRG3  = (89),
    ELC_PERIPHERAL_ENCIF_SS_TRG4  = (90),
    ELC_PERIPHERAL_ENCIF_SS_TRG5  = (91),
    ELC_PERIPHERAL_ENCIF_SS_TRG6  = (92),
    ELC_PERIPHERAL_ENCIF_SS_TRG7  = (93),
    ELC_PERIPHERAL_ESC0           = (94),
    ELC_PERIPHERAL_ESC1           = (95),
    ELC_PERIPHERAL_GMAC0_CAP0     = (96),
    ELC_PERIPHERAL_GMAC0_CAP1     = (97),
    ELC_PERIPHERAL_GMAC1_CAP0     = (98),
    ELC_PERIPHERAL_GMAC1_CAP1     = (99),
    ELC_PERIPHERAL_GMAC2_CAP0     = (100),
    ELC_PERIPHERAL_GMAC2_CAP1     = (101),
    ELC_PERIPHERAL_OUTPORTGR1     = (102),
    ELC_PERIPHERAL_OUTPORTGR2     = (103),
    ELC_PERIPHERAL_INPORTGR1      = (104),
    ELC_PERIPHERAL_INPORTGR2      = (105),
    ELC_PERIPHERAL_SINGLEPORT0    = (106),
    ELC_PERIPHERAL_SINGLEPORT1    = (107),
    ELC_PERIPHERAL_SINGLEPORT2    = (108),
    ELC_PERIPHERAL_SINGLEPORT3    = (109),
    ELC_PERIPHERAL_ENCOUT_TRIGGER = (110)
} elc_peripheral_t;

/*==============================================
 * ERROR API Overrides
 *==============================================*/

/** Error event source. */
typedef enum e_error_event
{
    ERROR_EVENT_CPU0,                  ///< Error event from CR520
    ERROR_EVENT_CPU1,                  ///< Error event from CR521
    ERROR_EVENT_CA55,                  ///< Error event from CA55
    ERROR_EVENT_PERIPHERAL_0,          ///< Error event from Peripheral 0
    ERROR_EVENT_PERIPHERAL_1,          ///< Error event from Peripheral 1
    ERROR_EVENT_PERIPHERAL_2,          ///< Error event from Peripheral 2
    ERROR_EVENT_PERIPHERAL_3,          ///< Error event from Peripheral 3
    ERROR_EVENT_DSMIF_0,               ///< Error event from DSMIF 0
    ERROR_EVENT_DSMIF_1,               ///< Error event from DSMIF 1
    ERROR_EVENT_DSMIF_2,               ///< Error event from DSMIF 2
    ERROR_EVENT_DSMIF_3,               ///< Error event from DSMIF 3
    ERROR_EVENT_DSMIF_4,               ///< Error event from DSMIF 4
    ERROR_EVENT_DSMIF_10,              ///< Error event from DSMIF 10
    ERROR_EVENT_ENCIF_0,               ///< Error event from ENCIF 0
    ERROR_EVENT_ENCIF_1,               ///< Error event from ENCIF 1
    ERROR_EVENT_ENCIF_2,               ///< Error event from ENCIF 2
    ERROR_EVENT_ENCIF_5,               ///< Error event from ENCIF 4
} error_event_t;

/*==============================================
 * IOPORT API Overrides
 *==============================================*/

/** Superset of all peripheral functions.  */
typedef enum e_ioport_pin_pfc
{
    IOPORT_PIN_PFC_00_IRQ0  = (0x00U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ0
    IOPORT_PIN_PFC_00_IRQ1  = (0x01U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ1
    IOPORT_PIN_PFC_00_IRQ2  = (0x02U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ2
    IOPORT_PIN_PFC_00_IRQ3  = (0x03U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ3
    IOPORT_PIN_PFC_00_IRQ4  = (0x04U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ4
    IOPORT_PIN_PFC_00_IRQ5  = (0x05U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ5
    IOPORT_PIN_PFC_00_IRQ6  = (0x06U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ6
    IOPORT_PIN_PFC_00_IRQ7  = (0x07U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ7
    IOPORT_PIN_PFC_00_IRQ8  = (0x08U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ8
    IOPORT_PIN_PFC_00_IRQ9  = (0x09U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ9
    IOPORT_PIN_PFC_00_IRQ10 = (0x0AU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ10
    IOPORT_PIN_PFC_00_IRQ11 = (0x0BU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ11
    IOPORT_PIN_PFC_00_IRQ12 = (0x0CU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ12
    IOPORT_PIN_PFC_00_IRQ13 = (0x0DU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ13
    IOPORT_PIN_PFC_00_IRQ14 = (0x0EU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ14
    IOPORT_PIN_PFC_00_IRQ15 = (0x0FU << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< IRQ15
    IOPORT_PIN_PFC_00_SEI   = (0x10U << IOPORT_IRQ_NUM_OFFSET) | (0x01U << IOPORT_IRQ_ENABLE_OFFSET), ///< SEI

    IOPORT_PIN_P000_PFC_04_A16        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P00_0 / BSC / A16
    IOPORT_PIN_P000_PFC_06_MTIOC3B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P00_0 / MTU3n / MTIOC3B
    IOPORT_PIN_P000_PFC_09_GTIOC0_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P00_0 / GPTn / GTIOC0_0A
    IOPORT_PIN_P000_PFC_0A_GTADSM0_0  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P00_0 / GPTn / GTADSM0_0
    IOPORT_PIN_P000_PFC_0F_ETH3_TXCLK = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P00_0 / ETHER_ETHn / ETH3_TXCLK
    IOPORT_PIN_P000_PFC_1A_SCKE1      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P00_0 / SCIEn / SCKE1
    IOPORT_PIN_P000_PFC_1E_SPI_RSPCK2 = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P00_0 / SPIn / SPI_RSPCK2
    IOPORT_PIN_P000_PFC_26_ENCIFCK1   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P00_0 / ENCIFn / ENCIFCK1
    IOPORT_PIN_P000_PFC_29_HDSL0_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P00_0 / HDSLn / HDSL0_SEL1
    IOPORT_PIN_P000_PFC_2E_HA16       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P00_0 / PHOSTIF / HA16

    IOPORT_PIN_P001_PFC_04_A17         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P00_1 / BSC / A17
    IOPORT_PIN_P001_PFC_06_MTIOC3D     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P00_1 / MTU3n / MTIOC3D
    IOPORT_PIN_P001_PFC_09_GTIOC0_0B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P00_1 / GPTn / GTIOC0_0B
    IOPORT_PIN_P001_PFC_0A_GTADSM0_1   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P00_1 / GPTn / GTADSM0_1
    IOPORT_PIN_P001_PFC_0F_ETH3_TXD0   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P00_1 / ETHER_ETHn / ETH3_TXD0
    IOPORT_PIN_P001_PFC_1A_DEE1        = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P00_1 / SCIEn / DEE1
    IOPORT_PIN_P001_PFC_1C_IIC_SCL2    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P00_1 / IICn / IIC_SCL2
    IOPORT_PIN_P001_PFC_1D_CANRX0      = (0x1DU << IOPORT_PFC_OFFSET),                                ///< P00_1 / CANFDn / CANRX0
    IOPORT_PIN_P001_PFC_1E_SPI_MISO2   = (0x1EU << IOPORT_PFC_OFFSET),                                ///< P00_1 / SPIn / SPI_MISO2
    IOPORT_PIN_P001_PFC_26_ENCIFOE1    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P00_1 / ENCIFn / ENCIFOE1
    IOPORT_PIN_P001_PFC_29_HDSL0_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P00_1 / HDSLn / HDSL0_MISO1
    IOPORT_PIN_P001_PFC_2E_HA17        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P00_1 / PHOSTIF / HA17

    IOPORT_PIN_P002_PFC_04_A18         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P00_2 / BSC / A18
    IOPORT_PIN_P002_PFC_06_MTIOC4A     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P00_2 / MTU3n / MTIOC4A
    IOPORT_PIN_P002_PFC_09_GTIOC0_1B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P00_2 / GPTn / GTIOC0_1B
    IOPORT_PIN_P002_PFC_0A_GTADSM1_0   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P00_2 / GPTn / GTADSM1_0
    IOPORT_PIN_P002_PFC_0F_ETH3_TXD1   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P00_2 / ETHER_ETHn / ETH3_TXD1
    IOPORT_PIN_P002_PFC_1A_TXDE1       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P00_2 / SCIEn / TXDE1
    IOPORT_PIN_P002_PFC_1C_IIC_SDA2    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P00_2 / IICn / IIC_SDA2
    IOPORT_PIN_P002_PFC_1D_CANTX0      = (0x1DU << IOPORT_PFC_OFFSET),                                ///< P00_2 / CANFDn / CANTX0
    IOPORT_PIN_P002_PFC_1E_SPI_MOSI2   = (0x1EU << IOPORT_PFC_OFFSET),                                ///< P00_2 / SPIn / SPI_MOSI2
    IOPORT_PIN_P002_PFC_22_MCLK41      = (0x22U << IOPORT_PFC_OFFSET),                                ///< P00_2 / DSMIFn / MCLK41
    IOPORT_PIN_P002_PFC_26_ENCIFDO1    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P00_2 / ENCIFn / ENCIFDO1
    IOPORT_PIN_P002_PFC_29_HDSL0_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P00_2 / HDSLn / HDSL0_MOSI1
    IOPORT_PIN_P002_PFC_2E_HA18        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P00_2 / PHOSTIF / HA18

    IOPORT_PIN_P003_PFC_04_A19        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / BSC / A19
    IOPORT_PIN_P003_PFC_06_MTIOC4C    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / MTU3n / MTIOC4C
    IOPORT_PIN_P003_PFC_09_GTIOC0_1A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / GPTn / GTIOC0_1A
    IOPORT_PIN_P003_PFC_0A_GTADSM1_1  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / GPTn / GTADSM1_1
    IOPORT_PIN_P003_PFC_0F_ETH3_TXD2  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / ETHER_ETHn / ETH3_TXD2
    IOPORT_PIN_P003_PFC_1A_RXDE1      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / SCIEn / RXDE1
    IOPORT_PIN_P003_PFC_1D_CANRXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / CANFDn / CANRXDP0
    IOPORT_PIN_P003_PFC_1E_SPI_SSL20  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / SPIn / SPI_SSL20
    IOPORT_PIN_P003_PFC_22_MDAT41     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / DSMIFn / MDAT41
    IOPORT_PIN_P003_PFC_26_ENCIFDI1   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / ENCIFn / ENCIFDI1
    IOPORT_PIN_P003_PFC_29_HSDL0_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P00_3 / HDSLn / HSDL0_CLK2
    IOPORT_PIN_P003_PFC_2E_HA19       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P00_3 / PHOSTIF / HA19

    IOPORT_PIN_P004_PFC_04_A20        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / BSC / A20
    IOPORT_PIN_P004_PFC_06_MTIOC4B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / MTU3n / MTIOC4B
    IOPORT_PIN_P004_PFC_09_GTIOC0_2A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / GPTn / GTIOC0_2A
    IOPORT_PIN_P004_PFC_0A_GTADSM2_0  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / GPTn / GTADSM2_0
    IOPORT_PIN_P004_PFC_0F_ETH3_TXD3  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / ETHER_ETHn / ETH3_TXD3
    IOPORT_PIN_P004_PFC_1B_TXDE6      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / SCIEn / TXDE6
    IOPORT_PIN_P004_PFC_1D_CANTXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / CANFDn / CANTXDP0
    IOPORT_PIN_P004_PFC_1E_SPI_SSL21  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / SPIn / SPI_SSL21
    IOPORT_PIN_P004_PFC_21_MCLK20     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / DSMIFn / MCLK20
    IOPORT_PIN_P004_PFC_27_ENCIFDO6   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / ENCIFn / ENCIFDO6
    IOPORT_PIN_P004_PFC_29_HDSL0_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P00_4 / HDSLn / HDSL0_SEL2
    IOPORT_PIN_P004_PFC_2E_HA20       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P00_4 / PHOSTIF / HA20

    IOPORT_PIN_P005_PFC_04_A21         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P00_5 / BSC / A21
    IOPORT_PIN_P005_PFC_06_MTIOC4D     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P00_5 / MTU3n / MTIOC4D
    IOPORT_PIN_P005_PFC_07_MTIOC8C     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P00_5 / MTU3n / MTIOC8C
    IOPORT_PIN_P005_PFC_09_GTIOC0_2B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P00_5 / GPTn / GTIOC0_2B
    IOPORT_PIN_P005_PFC_0A_GTADSM2_1   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P00_5 / GPTn / GTADSM2_1
    IOPORT_PIN_P005_PFC_0F_ETH3_TXEN   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P00_5 / ETHER_ETHn / ETH3_TXEN
    IOPORT_PIN_P005_PFC_1B_RXDE6       = (0x1BU << IOPORT_PFC_OFFSET),                                ///< P00_5 / SCIEn / RXDE6
    IOPORT_PIN_P005_PFC_1E_SPI_SSL22   = (0x1EU << IOPORT_PFC_OFFSET),                                ///< P00_5 / SPIn / SPI_SSL22
    IOPORT_PIN_P005_PFC_21_MDAT20      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P00_5 / DSMIFn / MDAT20
    IOPORT_PIN_P005_PFC_27_ENCIFDI6    = (0x27U << IOPORT_PFC_OFFSET),                                ///< P00_5 / ENCIFn / ENCIFDI6
    IOPORT_PIN_P005_PFC_29_HDSL0_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P00_5 / HDSLn / HDSL0_MISO2
    IOPORT_PIN_P005_PFC_2E_HA21        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P00_5 / PHOSTIF / HA21

    IOPORT_PIN_P006_PFC_04_A22             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P00_6 / BSC / A22
    IOPORT_PIN_P006_PFC_06_MTCLKA          = (0x06U << IOPORT_PFC_OFFSET),                            ///< P00_6 / MTU3 / MTCLKA
    IOPORT_PIN_P006_PFC_07_MTIOC8D         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P00_6 / MTU3n / MTIOC8D
    IOPORT_PIN_P006_PFC_09_GTIOC0_3A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P00_6 / GPTn / GTIOC0_3A
    IOPORT_PIN_P006_PFC_0A_GTADSM3_0       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P00_6 / GPTn / GTADSM3_0
    IOPORT_PIN_P006_PFC_0F_ETH3_RXCLK      = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P00_6 / ETHER_ETHn / ETH3_RXCLK
    IOPORT_PIN_P006_PFC_18_RXD4_SCL4_MISO4 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P00_6 / SCIn / RXD4_SCL4_MISO4
    IOPORT_PIN_P006_PFC_1A_SCKE0           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P00_6 / SCIEn / SCKE0
    IOPORT_PIN_P006_PFC_1B_SCKE6           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P00_6 / SCIEn / SCKE6
    IOPORT_PIN_P006_PFC_1E_SPI_SSL23       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P00_6 / SPIn / SPI_SSL23
    IOPORT_PIN_P006_PFC_25_MBX_HINT        = (0x25U << IOPORT_PFC_OFFSET),                            ///< P00_6 / MBXSEM / MBX_HINT
    IOPORT_PIN_P006_PFC_26_ENCIFCK0        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P00_6 / ENCIFn / ENCIFCK0
    IOPORT_PIN_P006_PFC_27_ENCIFCK6        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P00_6 / ENCIFn / ENCIFCK6

    IOPORT_PIN_P007_PFC_04_A23             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P00_7 / BSC / A23
    IOPORT_PIN_P007_PFC_06_MTCLKB          = (0x06U << IOPORT_PFC_OFFSET),                            ///< P00_7 / MTU3 / MTCLKB
    IOPORT_PIN_P007_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P00_7 / MTU3n / MTIOC1B
    IOPORT_PIN_P007_PFC_09_GTIOC0_3B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P00_7 / GPTn / GTIOC0_3B
    IOPORT_PIN_P007_PFC_0A_GTADSM3_1       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P00_7 / GPTn / GTADSM3_1
    IOPORT_PIN_P007_PFC_0F_ETH3_RXD0       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P00_7 / ETHER_ETHn / ETH3_RXD0
    IOPORT_PIN_P007_PFC_18_TXD4_SDA4_MOSI4 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P00_7 / SCIn / TXD4_SDA4_MOSI4
    IOPORT_PIN_P007_PFC_1A_DEE0            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P00_7 / SCIEn / DEE0
    IOPORT_PIN_P007_PFC_1B_DEE6            = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P00_7 / SCIEn / DEE6
    IOPORT_PIN_P007_PFC_1E_SPI_SSL22       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P00_7 / SPIn / SPI_SSL22
    IOPORT_PIN_P007_PFC_25_MBX_HINT        = (0x25U << IOPORT_PFC_OFFSET),                            ///< P00_7 / MBXSEM / MBX_HINT
    IOPORT_PIN_P007_PFC_26_ENCIFOE0        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P00_7 / ENCIFn / ENCIFOE0
    IOPORT_PIN_P007_PFC_27_ENCIFOE6        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P00_7 / ENCIFn / ENCIFOE6
    IOPORT_PIN_P007_PFC_2E_HERROUT         = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P00_7 / PHOSTIF / HERROUT

    IOPORT_PIN_P010_PFC_04_A0        = (0x04U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / BSC / A0
    IOPORT_PIN_P010_PFC_06_MTIOC3A   = (0x06U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / MTU3n / MTIOC3A
    IOPORT_PIN_P010_PFC_07_MTIOC1A   = (0x07U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / MTU3n / MTIOC1A
    IOPORT_PIN_P010_PFC_09_GTIOC0_4A = (0x09U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / GPTn / GTIOC0_4A
    IOPORT_PIN_P010_PFC_0A_GTADSM4_0 = (0x0AU << IOPORT_PFC_OFFSET),                                  ///< P01_0 / GPTn / GTADSM4_0
    IOPORT_PIN_P010_PFC_0F_ETH3_RXD1 = (0x0FU << IOPORT_PFC_OFFSET),                                  ///< P01_0 / ETHER_ETHn / ETH3_RXD1
    IOPORT_PIN_P010_PFC_18_DE4       = (0x18U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / SCIn / DE4
    IOPORT_PIN_P010_PFC_1A_TXDE0     = (0x1AU << IOPORT_PFC_OFFSET),                                  ///< P01_0 / SCIEn / TXDE0
    IOPORT_PIN_P010_PFC_1E_SPI_SSL21 = (0x1EU << IOPORT_PFC_OFFSET),                                  ///< P01_0 / SPIn / SPI_SSL21
    IOPORT_PIN_P010_PFC_26_ENCIFDO0  = (0x26U << IOPORT_PFC_OFFSET),                                  ///< P01_0 / ENCIFn / ENCIFDO0
    IOPORT_PIN_P010_PFC_2E_HA0       = (0x2EU << IOPORT_PFC_OFFSET),                                  ///< P01_0 / PHOSTIF / HA0

    IOPORT_PIN_P011_PFC_04_RD_WR           = (0x04U << IOPORT_PFC_OFFSET),                            ///< P01_1 / BSC / RD_WR
    IOPORT_PIN_P011_PFC_06_MTIOC3C         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P01_1 / MTU3n / MTIOC3C
    IOPORT_PIN_P011_PFC_07_MTIOC8A         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P01_1 / MTU3n / MTIOC8A
    IOPORT_PIN_P011_PFC_09_GTIOC0_4B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P01_1 / GPTn / GTIOC0_4B
    IOPORT_PIN_P011_PFC_0A_GTADSM4_1       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P01_1 / GPTn / GTADSM4_1
    IOPORT_PIN_P011_PFC_0F_ETH3_RXD2       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P01_1 / ETHER_ETHn / ETH3_RXD2
    IOPORT_PIN_P011_PFC_17_USB_OVRCUR      = (0x17U << IOPORT_PFC_OFFSET),                            ///< P01_1 / USB / USB_OVRCUR
    IOPORT_PIN_P011_PFC_18_SCK5            = (0x18U << IOPORT_PFC_OFFSET),                            ///< P01_1 / SCIn / SCK5
    IOPORT_PIN_P011_PFC_19_RXD5_SCL5_MISO5 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P01_1 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P011_PFC_1A_RXDE0           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P01_1 / SCIEn / RXDE0
    IOPORT_PIN_P011_PFC_26_ENCIFDI0        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P01_1 / ENCIFn / ENCIFDI0
    IOPORT_PIN_P011_PFC_2C_SD1_PWEN        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P01_1 / SDHIn / SD1_PWEN
    IOPORT_PIN_P011_PFC_2E_HWRSTB          = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P01_1 / PHOSTIF / HWRSTB

    IOPORT_PIN_P012_PFC_04_BS              = (0x04U << IOPORT_PFC_OFFSET),                            ///< P01_2 / BSC / BS
    IOPORT_PIN_P012_PFC_05_DREQ            = (0x05U << IOPORT_PFC_OFFSET),                            ///< P01_2 / DMAC / DREQ
    IOPORT_PIN_P012_PFC_0F_ETH3_RXD3       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P01_2 / ETHER_ETHn / ETH3_RXD3
    IOPORT_PIN_P012_PFC_18_CTS5_RTS5_SS5   = (0x18U << IOPORT_PFC_OFFSET),                            ///< P01_2 / SCIn / CTS5_RTS5_SS5
    IOPORT_PIN_P012_PFC_19_TXD5_SDA5_MOSI5 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P01_2 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P012_PFC_1A_SCKE4           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P01_2 / SCIEn / SCKE4
    IOPORT_PIN_P012_PFC_1E_SPI_MOSI2       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P01_2 / SPIn / SPI_MOSI2
    IOPORT_PIN_P012_PFC_21_MCLK00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P01_2 / DSMIFn / MCLK00
    IOPORT_PIN_P012_PFC_23_ADTRG0          = (0x23U << IOPORT_PFC_OFFSET),                            ///< P01_2 / ADCn / ADTRG0
    IOPORT_PIN_P012_PFC_26_ENCIFCK4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P01_2 / ENCIFn / ENCIFCK4
    IOPORT_PIN_P012_PFC_2C_SD1_IOVS        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P01_2 / SDHIn / SD1_IOVS
    IOPORT_PIN_P012_PFC_2E_HBS             = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P01_2 / PHOSTIF / HBS

    IOPORT_PIN_P013_PFC_04_CS3             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P01_3 / BSC / CS3
    IOPORT_PIN_P013_PFC_05_DACK            = (0x05U << IOPORT_PFC_OFFSET),                            ///< P01_3 / DMAC / DACK
    IOPORT_PIN_P013_PFC_0F_ETH3_RXDV       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P01_3 / ETHER_ETHn / ETH3_RXDV
    IOPORT_PIN_P013_PFC_10_ETH1_TXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P01_3 / ETHER_ETHn / ETH1_TXER
    IOPORT_PIN_P013_PFC_15_ESC_I2CCLK      = (0x15U << IOPORT_PFC_OFFSET),                            ///< P01_3 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P013_PFC_18_CTS5            = (0x18U << IOPORT_PFC_OFFSET),                            ///< P01_3 / SCIn / CTS5
    IOPORT_PIN_P013_PFC_19_RXD1_SCL1_MISO1 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P01_3 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P013_PFC_1A_DEE4            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P01_3 / SCIEn / DEE4
    IOPORT_PIN_P013_PFC_1C_IIC_SCL1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P01_3 / IICn / IIC_SCL1
    IOPORT_PIN_P013_PFC_1E_SPI_MISO2       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P01_3 / SPIn / SPI_MISO2
    IOPORT_PIN_P013_PFC_21_MDAT00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P01_3 / DSMIFn / MDAT00
    IOPORT_PIN_P013_PFC_23_ADTRG1          = (0x23U << IOPORT_PFC_OFFSET),                            ///< P01_3 / ADCn / ADTRG1
    IOPORT_PIN_P013_PFC_25_MBX_HINT        = (0x25U << IOPORT_PFC_OFFSET),                            ///< P01_3 / MBXSEM / MBX_HINT
    IOPORT_PIN_P013_PFC_26_ENCIFOE4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P01_3 / ENCIFn / ENCIFOE4

    IOPORT_PIN_P014_PFC_04_CS5             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P01_4 / BSC / CS5
    IOPORT_PIN_P014_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET),                            ///< P01_4 / DMAC / TEND
    IOPORT_PIN_P014_PFC_02_ETH3_REFCLK     = (0x02U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ETHER_ETHn / ETH3_REFCLK
    IOPORT_PIN_P014_PFC_03_RMII3_REFCLK    = (0x03U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ETHER_ETHn / RMII3_REFCLK
    IOPORT_PIN_P014_PFC_0F_ETH1_RXER       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P01_4 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P014_PFC_10_ETH1_CRS        = (0x10U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P014_PFC_15_ESC_I2CDATA     = (0x15U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P014_PFC_17_USB_EXICEN      = (0x17U << IOPORT_PFC_OFFSET),                            ///< P01_4 / USB / USB_EXICEN
    IOPORT_PIN_P014_PFC_19_TXD1_SDA1_MOSI1 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P01_4 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P014_PFC_1A_RXDE4           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P01_4 / SCIEn / RXDE4
    IOPORT_PIN_P014_PFC_1C_IIC_SDA1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P01_4 / IICn / IIC_SDA1
    IOPORT_PIN_P014_PFC_1E_SPI_RSPCK2      = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P01_4 / SPIn / SPI_RSPCK2
    IOPORT_PIN_P014_PFC_21_MCLK01          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P01_4 / DSMIFn / MCLK01
    IOPORT_PIN_P014_PFC_23_ADTRG2          = (0x23U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ADCn / ADTRG2
    IOPORT_PIN_P014_PFC_26_ENCIFDI4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P01_4 / ENCIFn / ENCIFDI4

    IOPORT_PIN_P015_PFC_04_CS2           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P01_5 / BSC / CS2
    IOPORT_PIN_P015_PFC_05_DREQ          = (0x05U << IOPORT_PFC_OFFSET),                              ///< P01_5 / DMAC / DREQ
    IOPORT_PIN_P015_PFC_0F_ETH3_TXER     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P01_5 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P015_PFC_10_ETH1_COL      = (0x10U << IOPORT_PFC_OFFSET),                              ///< P01_5 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P015_PFC_15_ESC_RESETOUT  = (0x15U << IOPORT_PFC_OFFSET),                              ///< P01_5 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P015_PFC_17_USB_EXICEN    = (0x17U << IOPORT_PFC_OFFSET),                              ///< P01_5 / USB / USB_EXICEN
    IOPORT_PIN_P015_PFC_1A_TXDE4         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P01_5 / SCIEn / TXDE4
    IOPORT_PIN_P015_PFC_1E_SPI_SSL20     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P01_5 / SPIn / SPI_SSL20
    IOPORT_PIN_P015_PFC_21_MDAT01        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P01_5 / DSMIFn / MDAT01
    IOPORT_PIN_P015_PFC_26_ENCIFDO4      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P01_5 / ENCIFn / ENCIFDO4
    IOPORT_PIN_P015_PFC_2E_HCS1          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P01_5 / PHOSTIF / HCS1
    IOPORT_PIN_P015_PFC_2F_ESWM_PHYLINK0 = (0x2FU << IOPORT_PFC_OFFSET),                              ///< P01_5 / ETHER_ESWM / ESWM_PHYLINK0
    IOPORT_PIN_P015_PFC_30_HPSW_PHYLINK0 = (0x30U << IOPORT_PFC_OFFSET),                              ///< P01_5 / ETHER_HPSW / HPSW_PHYLINK0

    IOPORT_PIN_P016_PFC_04_D13        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / BSC / D13
    IOPORT_PIN_P016_PFC_06_MTIOC6B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / MTU3n / MTIOC6B
    IOPORT_PIN_P016_PFC_07_MTIOC8B    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / MTU3n / MTIOC8B
    IOPORT_PIN_P016_PFC_09_GTIOC1_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / GPTn / GTIOC1_0A
    IOPORT_PIN_P016_PFC_0A_GTADSM0_0  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / GPTn / GTADSM0_0
    IOPORT_PIN_P016_PFC_0C_GTETRGB    = (0x0CU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / GPT_POEG / GTETRGB
    IOPORT_PIN_P016_PFC_0D_CMTW1_TIC0 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / CMTWn / CMTW1_TIC0
    IOPORT_PIN_P016_PFC_0F_ETH4_TXCLK = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / ETHER_ETHn / ETH4_TXCLK
    IOPORT_PIN_P016_PFC_10_ETH0_RXER  = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / ETHER_ETHn / ETH0_RXER
    IOPORT_PIN_P016_PFC_18_SCK1       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / SCIn / SCK1
    IOPORT_PIN_P016_PFC_1E_SPI_RSPCK3 = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P016_PFC_21_MCLK02     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P01_6 / DSMIFn / MCLK02
    IOPORT_PIN_P016_PFC_2C_SD1_CD     = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / SDHIn / SD1_CD
    IOPORT_PIN_P016_PFC_2E_HD13       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P01_6 / PHOSTIF / HD13

    IOPORT_PIN_P017_PFC_04_D14             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P01_7 / BSC / D14
    IOPORT_PIN_P017_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P01_7 / MTU3n / MTIOC6D
    IOPORT_PIN_P017_PFC_07_MTIC5U          = (0x07U << IOPORT_PFC_OFFSET),                            ///< P01_7 / MTU3n / MTIC5U
    IOPORT_PIN_P017_PFC_09_GTIOC1_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P01_7 / GPTn / GTIOC1_0B
    IOPORT_PIN_P017_PFC_0A_GTADSM0_1       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P01_7 / GPTn / GTADSM0_1
    IOPORT_PIN_P017_PFC_0C_GTETRGC         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P01_7 / GPT_POEG / GTETRGC
    IOPORT_PIN_P017_PFC_0D_CMTW1_TOC0      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P01_7 / CMTWn / CMTW1_TOC0
    IOPORT_PIN_P017_PFC_0F_ETH4_TXD0       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P01_7 / ETHER_ETHn / ETH4_TXD0
    IOPORT_PIN_P017_PFC_10_ETH1_RXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P01_7 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P017_PFC_18_RXD1_SCL1_MISO1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P01_7 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P017_PFC_1E_SPI_MISO3       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P01_7 / SPIn / SPI_MISO3
    IOPORT_PIN_P017_PFC_21_MDAT02          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P01_7 / DSMIFn / MDAT02
    IOPORT_PIN_P017_PFC_2C_SD1_WP          = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P01_7 / SDHIn / SD1_WP
    IOPORT_PIN_P017_PFC_2E_HD14            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P01_7 / PHOSTIF / HD14

    IOPORT_PIN_P020_PFC_04_WE2             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P02_0 / BSC / WE2
    IOPORT_PIN_P020_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P02_0 / MTU3n / MTIOC7A
    IOPORT_PIN_P020_PFC_07_MTIC5V          = (0x07U << IOPORT_PFC_OFFSET),                            ///< P02_0 / MTU3n / MTIC5V
    IOPORT_PIN_P020_PFC_09_GTIOC1_1B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P02_0 / GPTn / GTIOC1_1B
    IOPORT_PIN_P020_PFC_0A_GTADSM1_0       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P02_0 / GPTn / GTADSM1_0
    IOPORT_PIN_P020_PFC_0C_GTETRGD         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P02_0 / GPT_POEG / GTETRGD
    IOPORT_PIN_P020_PFC_0F_ETH4_TXD1       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P02_0 / ETHER_ETHn / ETH4_TXD1
    IOPORT_PIN_P020_PFC_14_ETHSW_PTPOUT0   = (0x14U << IOPORT_PFC_OFFSET),                            ///< P02_0 / ETHER_ETHSW / ETHSW_PTPOUT0
    IOPORT_PIN_P020_PFC_15_ESC_SYNC0       = (0x15U << IOPORT_PFC_OFFSET),                            ///< P02_0 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P020_PFC_18_TXD1_SDA1_MOSI1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P02_0 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P020_PFC_1A_SCIEXTCLK       = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P02_0 / CGC / SCIEXTCLK
    IOPORT_PIN_P020_PFC_1E_SPI_MOSI3       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P02_0 / SPIn / SPI_MOSI3
    IOPORT_PIN_P020_PFC_2C_SD1_PWEN        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P02_0 / SDHIn / SD1_PWEN
    IOPORT_PIN_P020_PFC_2E_HWR2            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P02_0 / PHOSTIF / HWR2

    IOPORT_PIN_P021_PFC_04_WE3_AH          = (0x04U << IOPORT_PFC_OFFSET),                            ///< P02_1 / BSC / WE3_AH
    IOPORT_PIN_P021_PFC_06_MTIOC7C         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P02_1 / MTU3n / MTIOC7C
    IOPORT_PIN_P021_PFC_07_MTIC5W          = (0x07U << IOPORT_PFC_OFFSET),                            ///< P02_1 / MTU3n / MTIC5W
    IOPORT_PIN_P021_PFC_09_GTIOC1_1A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P02_1 / GPTn / GTIOC1_1A
    IOPORT_PIN_P021_PFC_0A_GTADSM1_1       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P02_1 / GPTn / GTADSM1_1
    IOPORT_PIN_P021_PFC_0F_ETH4_TXD2       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P02_1 / ETHER_ETHn / ETH4_TXD2
    IOPORT_PIN_P021_PFC_11_GMAC0_PTPTRG0   = (0x11U << IOPORT_PFC_OFFSET),                            ///< P02_1 / ETHER_GMACn / GMAC0_PTPTRG0
    IOPORT_PIN_P021_PFC_16_ESC_LATCH0      = (0x16U << IOPORT_PFC_OFFSET),                            ///< P02_1 / ETHER_ESC / ESC_LATCH0
    IOPORT_PIN_P021_PFC_18_CTS1_RTS1_SS1   = (0x18U << IOPORT_PFC_OFFSET),                            ///< P02_1 / SCIn / CTS1_RTS1_SS1
    IOPORT_PIN_P021_PFC_19_RXD3_SCL3_MISO3 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P02_1 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P021_PFC_1A_TXDE5           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P02_1 / SCIEn / TXDE5
    IOPORT_PIN_P021_PFC_1E_SPI_SSL30       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P02_1 / SPIn / SPI_SSL30
    IOPORT_PIN_P021_PFC_1F_SPI_SSL00       = (0x1FU << IOPORT_PFC_OFFSET),                            ///< P02_1 / SPIn / SPI_SSL00
    IOPORT_PIN_P021_PFC_26_ENCIFDO5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P02_1 / ENCIFn / ENCIFDO5
    IOPORT_PIN_P021_PFC_2E_HWR3            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P02_1 / PHOSTIF / HWR3

    IOPORT_PIN_P022_PFC_04_D15           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P02_2 / BSC / D15
    IOPORT_PIN_P022_PFC_06_MTIOC7B       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P02_2 / MTU3n / MTIOC7B
    IOPORT_PIN_P022_PFC_07_MTIOC0A       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P02_2 / MTU3n / MTIOC0A
    IOPORT_PIN_P022_PFC_09_GTIOC1_2A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P02_2 / GPTn / GTIOC1_2A
    IOPORT_PIN_P022_PFC_0A_GTADSM2_0     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P02_2 / GPTn / GTADSM2_0
    IOPORT_PIN_P022_PFC_0F_ETH4_TXD3     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P02_2 / ETHER_ETHn / ETH4_TXD3
    IOPORT_PIN_P022_PFC_11_GMAC0_PTPTRG1 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P02_2 / ETHER_GMACn / GMAC0_PTPTRG1
    IOPORT_PIN_P022_PFC_15_ESC_LEDRUN    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P02_2 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P022_PFC_16_ESC_LATCH1    = (0x16U << IOPORT_PFC_OFFSET),                              ///< P02_2 / ETHER_ESC / ESC_LATCH1
    IOPORT_PIN_P022_PFC_18_CTS1          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P02_2 / SCIn / CTS1
    IOPORT_PIN_P022_PFC_1E_SPI_SSL31     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P02_2 / SPIn / SPI_SSL31
    IOPORT_PIN_P022_PFC_1F_SPI_SSL01     = (0x1FU << IOPORT_PFC_OFFSET),                              ///< P02_2 / SPIn / SPI_SSL01
    IOPORT_PIN_P022_PFC_2C_SD1_PWEN      = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P02_2 / SDHIn / SD1_PWEN
    IOPORT_PIN_P022_PFC_2E_HD15          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P02_2 / PHOSTIF / HD15

    IOPORT_PIN_P023_PFC_04_A9            = (0x04U << IOPORT_PFC_OFFSET),                              ///< P02_3 / BSC / A9
    IOPORT_PIN_P023_PFC_06_MTIOC7D       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P02_3 / MTU3n / MTIOC7D
    IOPORT_PIN_P023_PFC_07_MTIOC0B       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P02_3 / MTU3n / MTIOC0B
    IOPORT_PIN_P023_PFC_09_GTIOC1_2B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P02_3 / GPTn / GTIOC1_2B
    IOPORT_PIN_P023_PFC_0A_GTADSM2_1     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P02_3 / GPTn / GTADSM2_1
    IOPORT_PIN_P023_PFC_0F_ETH4_TXEN     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P02_3 / ETHER_ETHn / ETH4_TXEN
    IOPORT_PIN_P023_PFC_11_GMAC1_PTPTRG0 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P02_3 / ETHER_GMACn / GMAC1_PTPTRG0
    IOPORT_PIN_P023_PFC_15_ESC_LEDERR    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P02_3 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P023_PFC_18_DE1           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P02_3 / SCIn / DE1
    IOPORT_PIN_P023_PFC_1E_SPI_SSL32     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P02_3 / SPIn / SPI_SSL32
    IOPORT_PIN_P023_PFC_1F_SPI_SSL02     = (0x1FU << IOPORT_PFC_OFFSET),                              ///< P02_3 / SPIn / SPI_SSL02
    IOPORT_PIN_P023_PFC_2C_SD1_IOVS      = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P02_3 / SDHIn / SD1_IOVS
    IOPORT_PIN_P023_PFC_2E_HA9           = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P02_3 / PHOSTIF / HA9

    IOPORT_PIN_P024_PFC_04_A10           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P02_4 / BSC / A10
    IOPORT_PIN_P024_PFC_06_MTCLKC        = (0x06U << IOPORT_PFC_OFFSET),                              ///< P02_4 / MTU3 / MTCLKC
    IOPORT_PIN_P024_PFC_07_MTIOC0C       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P02_4 / MTU3n / MTIOC0C
    IOPORT_PIN_P024_PFC_09_GTIOC1_3A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P02_4 / GPTn / GTIOC1_3A
    IOPORT_PIN_P024_PFC_0A_GTADSM3_0     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P02_4 / GPTn / GTADSM3_0
    IOPORT_PIN_P024_PFC_0F_ETH4_RXCLK    = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P02_4 / ETHER_ETHn / ETH4_RXCLK
    IOPORT_PIN_P024_PFC_11_GMAC1_PTPTRG1 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P02_4 / ETHER_GMACn / GMAC1_PTPTRG1
    IOPORT_PIN_P024_PFC_18_SCK2          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P02_4 / SCIn / SCK2
    IOPORT_PIN_P024_PFC_1A_SCKE1         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P02_4 / SCIEn / SCKE1
    IOPORT_PIN_P024_PFC_1E_SPI_SSL33     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P02_4 / SPIn / SPI_SSL33
    IOPORT_PIN_P024_PFC_1F_SPI_SSL03     = (0x1FU << IOPORT_PFC_OFFSET),                              ///< P02_4 / SPIn / SPI_SSL03
    IOPORT_PIN_P024_PFC_21_MCLK12        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P02_4 / DSMIFn / MCLK12
    IOPORT_PIN_P024_PFC_22_MCLK40        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P02_4 / DSMIFn / MCLK40
    IOPORT_PIN_P024_PFC_26_ENCIFCK1      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P02_4 / ENCIFn / ENCIFCK1
    IOPORT_PIN_P024_PFC_2E_HA10          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P02_4 / PHOSTIF / HA10

    IOPORT_PIN_P025_PFC_04_A11             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P02_5 / BSC / A11
    IOPORT_PIN_P025_PFC_06_MTCLKD          = (0x06U << IOPORT_PFC_OFFSET),                            ///< P02_5 / MTU3 / MTCLKD
    IOPORT_PIN_P025_PFC_07_MTIOC0D         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P02_5 / MTU3n / MTIOC0D
    IOPORT_PIN_P025_PFC_09_GTIOC1_3B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P02_5 / GPTn / GTIOC1_3B
    IOPORT_PIN_P025_PFC_0A_GTADSM3_1       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P02_5 / GPTn / GTADSM3_1
    IOPORT_PIN_P025_PFC_0F_ETH4_RXD0       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P02_5 / ETHER_ETHn / ETH4_RXD0
    IOPORT_PIN_P025_PFC_11_GMAC2_PTPTRG0   = (0x11U << IOPORT_PFC_OFFSET),                            ///< P02_5 / ETHER_GMACn / GMAC2_PTPTRG0
    IOPORT_PIN_P025_PFC_18_RXD2_SCL2_MISO2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P02_5 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P025_PFC_1A_DEE1            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P02_5 / SCIEn / DEE1
    IOPORT_PIN_P025_PFC_1E_SPI_SSL32       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P02_5 / SPIn / SPI_SSL32
    IOPORT_PIN_P025_PFC_21_MDAT12          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P02_5 / DSMIFn / MDAT12
    IOPORT_PIN_P025_PFC_22_MDAT40          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P02_5 / DSMIFn / MDAT40
    IOPORT_PIN_P025_PFC_26_ENCIFOE1        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P02_5 / ENCIFn / ENCIFOE1
    IOPORT_PIN_P025_PFC_2E_HA11            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P02_5 / PHOSTIF / HA11

    IOPORT_PIN_P026_PFC_04_A12             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P02_6 / BSC / A12
    IOPORT_PIN_P026_PFC_06_MTIOC6A         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P02_6 / MTU3n / MTIOC6A
    IOPORT_PIN_P026_PFC_07_MTIOC1A         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P02_6 / MTU3n / MTIOC1A
    IOPORT_PIN_P026_PFC_09_GTIOC1_4A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P02_6 / GPTn / GTIOC1_4A
    IOPORT_PIN_P026_PFC_0A_GTADSM4_0       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P02_6 / GPTn / GTADSM4_0
    IOPORT_PIN_P026_PFC_0F_ETH4_RXD1       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P02_6 / ETHER_ETHn / ETH4_RXD1
    IOPORT_PIN_P026_PFC_11_GMAC2_PTPTRG1   = (0x11U << IOPORT_PFC_OFFSET),                            ///< P02_6 / ETHER_GMACn / GMAC2_PTPTRG1
    IOPORT_PIN_P026_PFC_15_ESC_LEDSTER     = (0x15U << IOPORT_PFC_OFFSET),                            ///< P02_6 / ETHER_ESC / ESC_LEDSTER
    IOPORT_PIN_P026_PFC_18_TXD2_SDA2_MOSI2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P02_6 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P026_PFC_1A_TXDE1           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P02_6 / SCIEn / TXDE1
    IOPORT_PIN_P026_PFC_1E_SPI_SSL31       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P02_6 / SPIn / SPI_SSL31
    IOPORT_PIN_P026_PFC_21_MCLK11          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P02_6 / DSMIFn / MCLK11
    IOPORT_PIN_P026_PFC_22_MCLK42          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P02_6 / DSMIFn / MCLK42
    IOPORT_PIN_P026_PFC_26_ENCIFDO1        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P02_6 / ENCIFn / ENCIFDO1
    IOPORT_PIN_P026_PFC_2E_HA12            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P02_6 / PHOSTIF / HA12

    IOPORT_PIN_P027_PFC_04_A13           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P02_7 / BSC / A13
    IOPORT_PIN_P027_PFC_06_MTIOC6C       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P02_7 / MTU3n / MTIOC6C
    IOPORT_PIN_P027_PFC_07_MTIOC1B       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P02_7 / MTU3n / MTIOC1B
    IOPORT_PIN_P027_PFC_09_GTIOC1_4B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P02_7 / GPTn / GTIOC1_4B
    IOPORT_PIN_P027_PFC_0A_GTADSM4_1     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P02_7 / GPTn / GTADSM4_1
    IOPORT_PIN_P027_PFC_0F_ETH4_RXD2     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P02_7 / ETHER_ETHn / ETH4_RXD2
    IOPORT_PIN_P027_PFC_18_CTS2_RTS2_SS2 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P02_7 / SCIn / CTS2_RTS2_SS2
    IOPORT_PIN_P027_PFC_1A_RXDE1         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P02_7 / SCIEn / RXDE1
    IOPORT_PIN_P027_PFC_21_MDAT11        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P02_7 / DSMIFn / MDAT11
    IOPORT_PIN_P027_PFC_22_MDAT42        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P02_7 / DSMIFn / MDAT42
    IOPORT_PIN_P027_PFC_26_ENCIFDI1      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P02_7 / ENCIFn / ENCIFDI1
    IOPORT_PIN_P027_PFC_28_DUEI3         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P02_7 / ENDATn / DUEI3
    IOPORT_PIN_P027_PFC_2E_HA13          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P02_7 / PHOSTIF / HA13

    IOPORT_PIN_P030_PFC_04_A14         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P03_0 / BSC / A14
    IOPORT_PIN_P030_PFC_09_GTIOC3_3A   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P03_0 / GPTn / GTIOC3_3A
    IOPORT_PIN_P030_PFC_0F_ETH4_RXD3   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P03_0 / ETHER_ETHn / ETH4_RXD3
    IOPORT_PIN_P030_PFC_10_ETH0_COL    = (0x10U << IOPORT_PFC_OFFSET),                                ///< P03_0 / ETHER_ETHn / ETH0_COL
    IOPORT_PIN_P030_PFC_18_CTS2        = (0x18U << IOPORT_PFC_OFFSET),                                ///< P03_0 / SCIn / CTS2
    IOPORT_PIN_P030_PFC_1A_SCKE5       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P03_0 / SCIEn / SCKE5
    IOPORT_PIN_P030_PFC_1C_IIC_SCL2    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P03_0 / IICn / IIC_SCL2
    IOPORT_PIN_P030_PFC_1E_SPI_MOSI3   = (0x1EU << IOPORT_PFC_OFFSET),                                ///< P03_0 / SPIn / SPI_MOSI3
    IOPORT_PIN_P030_PFC_21_MCLK10      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P03_0 / DSMIFn / MCLK10
    IOPORT_PIN_P030_PFC_26_ENCIFCK5    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P03_0 / ENCIFn / ENCIFCK5
    IOPORT_PIN_P030_PFC_28_TST_OUT3    = (0x28U << IOPORT_PFC_OFFSET),                                ///< P03_0 / ENDATn / TST_OUT3
    IOPORT_PIN_P030_PFC_29_HDSL0_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P03_0 / HDSLn / HDSL0_MOSI2
    IOPORT_PIN_P030_PFC_2E_HA14        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P03_0 / PHOSTIF / HA14

    IOPORT_PIN_P031_PFC_04_A15           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P03_1 / BSC / A15
    IOPORT_PIN_P031_PFC_09_GTIOC3_3B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P03_1 / GPTn / GTIOC3_3B
    IOPORT_PIN_P031_PFC_0F_ETH4_RXDV     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P03_1 / ETHER_ETHn / ETH4_RXDV
    IOPORT_PIN_P031_PFC_10_ETH0_CRS      = (0x10U << IOPORT_PFC_OFFSET),                              ///< P03_1 / ETHER_ETHn / ETH0_CRS
    IOPORT_PIN_P031_PFC_14_ETHSW_PTPOUT3 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P03_1 / ETHER_ETHSW / ETHSW_PTPOUT3
    IOPORT_PIN_P031_PFC_15_ESC_SYNC1     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P03_1 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P031_PFC_18_DE2           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P03_1 / SCIn / DE2
    IOPORT_PIN_P031_PFC_1A_DEE5          = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P03_1 / SCIEn / DEE5
    IOPORT_PIN_P031_PFC_1C_IIC_SDA2      = (0x1CU << IOPORT_PFC_OFFSET),                              ///< P03_1 / IICn / IIC_SDA2
    IOPORT_PIN_P031_PFC_1E_SPI_MISO3     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P03_1 / SPIn / SPI_MISO3
    IOPORT_PIN_P031_PFC_21_MDAT10        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P03_1 / DSMIFn / MDAT10
    IOPORT_PIN_P031_PFC_26_ENCIFOE5      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P03_1 / ENCIFn / ENCIFOE5
    IOPORT_PIN_P031_PFC_28_SI3           = (0x28U << IOPORT_PFC_OFFSET),                              ///< P03_1 / ENDATn / SI3
    IOPORT_PIN_P031_PFC_29_HDSL1_LINK    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P03_1 / HDSLn / HDSL1_LINK
    IOPORT_PIN_P031_PFC_2E_HA15          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P03_1 / PHOSTIF / HA15

    IOPORT_PIN_P032_PFC_05_DACK       = (0x05U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / DMAC / DACK
    IOPORT_PIN_P032_PFC_0D_CMTW1_TOC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P03_2 / CMTWn / CMTW1_TOC1
    IOPORT_PIN_P032_PFC_0E_RTCAT1HZ   = (0x0EU << IOPORT_PFC_OFFSET),                                 ///< P03_2 / RTC / RTCAT1HZ
    IOPORT_PIN_P032_PFC_10_ETH0_TXER  = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_ETHn / ETH0_TXER
    IOPORT_PIN_P032_PFC_11_GMAC0_MDC  = (0x11U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_GMACn / GMAC0_MDC
    IOPORT_PIN_P032_PFC_12_GMAC1_MDC  = (0x12U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P032_PFC_13_GMAC2_MDC  = (0x13U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_GMACn / GMAC2_MDC
    IOPORT_PIN_P032_PFC_14_ETHSW_MDC  = (0x14U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P032_PFC_15_ESC_MDC    = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P032_PFC_18_DE2        = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / SCIn / DE2
    IOPORT_PIN_P032_PFC_1B_TXDE4      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P03_2 / SCIEn / TXDE4
    IOPORT_PIN_P032_PFC_27_ENCIFDO4   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ENCIFn / ENCIFDO4
    IOPORT_PIN_P032_PFC_2C_SD1_IOVS   = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P03_2 / SDHIn / SD1_IOVS
    IOPORT_PIN_P032_PFC_2F_ESWM_MDC   = (0x2FU << IOPORT_PFC_OFFSET),                                 ///< P03_2 / ETHER_ESWM / ESWM_MDC

    IOPORT_PIN_P033_PFC_05_TEND            = (0x05U << IOPORT_PFC_OFFSET),                            ///< P03_3 / DMAC / TEND
    IOPORT_PIN_P033_PFC_0D_CMTW1_TIC1      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P03_3 / CMTWn / CMTW1_TIC1
    IOPORT_PIN_P033_PFC_11_GMAC0_MDIO      = (0x11U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_GMACn / GMAC0_MDIO
    IOPORT_PIN_P033_PFC_12_GMAC1_MDIO      = (0x12U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P033_PFC_13_GMAC2_MDIO      = (0x13U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_GMACn / GMAC2_MDIO
    IOPORT_PIN_P033_PFC_14_ETHSW_MDIO      = (0x14U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P033_PFC_15_ESC_MDIO        = (0x15U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P033_PFC_16_ESC_LINKACT0    = (0x16U << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P033_PFC_18_TXD1_SDA1_MOSI1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P03_3 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P033_PFC_19_TXD3_SDA3_MOSI3 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P03_3 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P033_PFC_2C_SD1_PWEN        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P03_3 / SDHIn / SD1_PWEN
    IOPORT_PIN_P033_PFC_2F_ESWM_MDIO       = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P03_3 / ETHER_ESWM / ESWM_MDIO

    IOPORT_PIN_P034_PFC_02_ETH4_REFCLK  = (0x02U << IOPORT_PFC_OFFSET),                               ///< P03_4 / ETHER_ETHn / ETH4_REFCLK
    IOPORT_PIN_P034_PFC_03_RMII4_REFCLK = (0x03U << IOPORT_PFC_OFFSET),                               ///< P03_4 / ETHER_ETHn / RMII4_REFCLK
    IOPORT_PIN_P034_PFC_04_A24          = (0x04U << IOPORT_PFC_OFFSET),                               ///< P03_4 / BSC / A24
    IOPORT_PIN_P034_PFC_0C_GTETRGSA     = (0x0CU << IOPORT_PFC_OFFSET),                               ///< P03_4 / GPT_POEG / GTETRGSA
    IOPORT_PIN_P034_PFC_16_ESC_RESETOUT = (0x16U << IOPORT_PFC_OFFSET),                               ///< P03_4 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P034_PFC_1A_TXDE5        = (0x1AU << IOPORT_PFC_OFFSET),                               ///< P03_4 / SCIEn / TXDE5
    IOPORT_PIN_P034_PFC_1E_SPI_RSPCK3   = (0x1EU << IOPORT_PFC_OFFSET),                               ///< P03_4 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P034_PFC_1F_SPI_MOSI0    = (0x1FU << IOPORT_PFC_OFFSET),                               ///< P03_4 / SPIn / SPI_MOSI0
    IOPORT_PIN_P034_PFC_21_MCLK11       = (0x21U << IOPORT_PFC_OFFSET),                               ///< P03_4 / DSMIFn / MCLK11
    IOPORT_PIN_P034_PFC_26_ENCIFDO5     = (0x26U << IOPORT_PFC_OFFSET),                               ///< P03_4 / ENCIFn / ENCIFDO5
    IOPORT_PIN_P034_PFC_2C_SD1_CD       = (0x2CU << IOPORT_PFC_OFFSET),                               ///< P03_4 / SDHIn / SD1_CD

    IOPORT_PIN_P035_PFC_04_A25             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P03_5 / BSC / A25
    IOPORT_PIN_P035_PFC_0C_GTETRGSB        = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P03_5 / GPT_POEG / GTETRGSB
    IOPORT_PIN_P035_PFC_0F_ETH4_RXER       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P03_5 / ETHER_ETHn / ETH4_RXER
    IOPORT_PIN_P035_PFC_19_RXD3_SCL3_MISO3 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P03_5 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P035_PFC_1A_RXDE5           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P03_5 / SCIEn / RXDE5
    IOPORT_PIN_P035_PFC_1E_SPI_SSL30       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P03_5 / SPIn / SPI_SSL30
    IOPORT_PIN_P035_PFC_1F_SPI_MISO0       = (0x1FU << IOPORT_PFC_OFFSET),                            ///< P03_5 / SPIn / SPI_MISO0
    IOPORT_PIN_P035_PFC_21_MDAT11          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P03_5 / DSMIFn / MDAT11
    IOPORT_PIN_P035_PFC_22_MCLK30          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P03_5 / DSMIFn / MCLK30
    IOPORT_PIN_P035_PFC_26_ENCIFDI5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P03_5 / ENCIFn / ENCIFDI5
    IOPORT_PIN_P035_PFC_2C_SD1_WP          = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P03_5 / SDHIn / SD1_WP
    IOPORT_PIN_P035_PFC_2F_ESWM_PHYLINK1   = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P03_5 / ETHER_ESWM / ESWM_PHYLINK1
    IOPORT_PIN_P035_PFC_30_HPSW_PHYLINK1   = (0x30U << IOPORT_PFC_OFFSET),                            ///< P03_5 / ETHER_HPSW / HPSW_PHYLINK1

    IOPORT_PIN_P036_PFC_09_GTIOC1_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / GPTn / GTIOC1_0A
    IOPORT_PIN_P036_PFC_18_SCK0       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / SCIn / SCK0
    IOPORT_PIN_P036_PFC_1B_SCKE0      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P03_6 / SCIEn / SCKE0
    IOPORT_PIN_P036_PFC_21_MCLK02     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / DSMIFn / MCLK02
    IOPORT_PIN_P036_PFC_22_MCLK32     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / DSMIFn / MCLK32
    IOPORT_PIN_P036_PFC_27_ENCIFCK0   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / ENCIFn / ENCIFCK0
    IOPORT_PIN_P036_PFC_28_DUEI4      = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / ENDATn / DUEI4
    IOPORT_PIN_P036_PFC_29_HDSL1_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P03_6 / HDSLn / HDSL1_SMPL
    IOPORT_PIN_P036_PFC_2C_SD1_CLK    = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P03_6 / SDHIn / SD1_CLK

    IOPORT_PIN_P037_PFC_09_GTIOC1_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P03_7 / GPTn / GTIOC1_0B
    IOPORT_PIN_P037_PFC_18_RXD0_SCL0_MISO0 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P03_7 / SCIn / RXD0_SCL0_MISO0
    IOPORT_PIN_P037_PFC_1B_DEE0            = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P03_7 / SCIEn / DEE0
    IOPORT_PIN_P037_PFC_1C_IIC_SCL0        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P03_7 / IICn / IIC_SCL0
    IOPORT_PIN_P037_PFC_21_MDAT02          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P03_7 / DSMIFn / MDAT02
    IOPORT_PIN_P037_PFC_22_MDAT32          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P03_7 / DSMIFn / MDAT32
    IOPORT_PIN_P037_PFC_27_ENCIFOE0        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P03_7 / ENCIFn / ENCIFOE0
    IOPORT_PIN_P037_PFC_28_TST_OUT4        = (0x28U << IOPORT_PFC_OFFSET),                            ///< P03_7 / ENDATn / TST_OUT4
    IOPORT_PIN_P037_PFC_29_HDSL1_CLK1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P03_7 / HDSLn / HDSL1_CLK1
    IOPORT_PIN_P037_PFC_2C_SD1_CMD         = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P03_7 / SDHIn / SD1_CMD

    IOPORT_PIN_P040_PFC_09_GTIOC1_1B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P04_0 / GPTn / GTIOC1_1B
    IOPORT_PIN_P040_PFC_18_TXD0_SDA0_MOSI0 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P04_0 / SCIn / TXD0_SDA0_MOSI0
    IOPORT_PIN_P040_PFC_1B_SCKE1           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P04_0 / SCIEn / SCKE1
    IOPORT_PIN_P040_PFC_1C_IIC_SDA0        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P04_0 / IICn / IIC_SDA0
    IOPORT_PIN_P040_PFC_21_MCLK00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P04_0 / DSMIFn / MCLK00
    IOPORT_PIN_P040_PFC_22_MCLK30          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P04_0 / DSMIFn / MCLK30
    IOPORT_PIN_P040_PFC_27_ENCIFCK1        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P04_0 / ENCIFn / ENCIFCK1
    IOPORT_PIN_P040_PFC_28_SI4             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P04_0 / ENDATn / SI4
    IOPORT_PIN_P040_PFC_29_HDSL1_SEL1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P04_0 / HDSLn / HDSL1_SEL1
    IOPORT_PIN_P040_PFC_2C_SD1_DATA0       = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P04_0 / SDHIn / SD1_DATA0

    IOPORT_PIN_P041_PFC_09_GTIOC1_1A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P04_1 / GPTn / GTIOC1_1A
    IOPORT_PIN_P041_PFC_18_CTS0_RTS0_SS0 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P04_1 / SCIn / CTS0_RTS0_SS0
    IOPORT_PIN_P041_PFC_1B_DEE1          = (0x1BU << IOPORT_PFC_OFFSET),                              ///< P04_1 / SCIEn / DEE1
    IOPORT_PIN_P041_PFC_21_MDAT00        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P04_1 / DSMIFn / MDAT00
    IOPORT_PIN_P041_PFC_22_MDAT30        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P04_1 / DSMIFn / MDAT30
    IOPORT_PIN_P041_PFC_27_ENCIFOE1      = (0x27U << IOPORT_PFC_OFFSET),                              ///< P04_1 / ENCIFn / ENCIFOE1
    IOPORT_PIN_P041_PFC_28_DUEI5         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P04_1 / ENDATn / DUEI5
    IOPORT_PIN_P041_PFC_29_HDSL1_MISO1   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P04_1 / HDSLn / HDSL1_MISO1
    IOPORT_PIN_P041_PFC_2C_SD1_DATA1     = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P04_1 / SDHIn / SD1_DATA1

    IOPORT_PIN_P042_PFC_09_GTIOC1_2A   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P04_2 / GPTn / GTIOC1_2A
    IOPORT_PIN_P042_PFC_18_CTS0        = (0x18U << IOPORT_PFC_OFFSET),                                ///< P04_2 / SCIn / CTS0
    IOPORT_PIN_P042_PFC_1B_TXDE2       = (0x1BU << IOPORT_PFC_OFFSET),                                ///< P04_2 / SCIEn / TXDE2
    IOPORT_PIN_P042_PFC_21_MCLK01      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P04_2 / DSMIFn / MCLK01
    IOPORT_PIN_P042_PFC_22_MCLK31      = (0x22U << IOPORT_PFC_OFFSET),                                ///< P04_2 / DSMIFn / MCLK31
    IOPORT_PIN_P042_PFC_27_ENCIFDO2    = (0x27U << IOPORT_PFC_OFFSET),                                ///< P04_2 / ENCIFn / ENCIFDO2
    IOPORT_PIN_P042_PFC_28_TST_OUT5    = (0x28U << IOPORT_PFC_OFFSET),                                ///< P04_2 / ENDATn / TST_OUT5
    IOPORT_PIN_P042_PFC_29_HDSL1_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P04_2 / HDSLn / HDSL1_MOSI1
    IOPORT_PIN_P042_PFC_2C_SD1_DATA2   = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P04_2 / SDHIn / SD1_DATA2

    IOPORT_PIN_P043_PFC_09_GTIOC1_2B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / GPTn / GTIOC1_2B
    IOPORT_PIN_P043_PFC_18_DE0        = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / SCIn / DE0
    IOPORT_PIN_P043_PFC_1B_RXDE2      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P04_3 / SCIEn / RXDE2
    IOPORT_PIN_P043_PFC_21_MDAT01     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / DSMIFn / MDAT01
    IOPORT_PIN_P043_PFC_22_MDAT31     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / DSMIFn / MDAT31
    IOPORT_PIN_P043_PFC_27_ENCIFDI2   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / ENCIFn / ENCIFDI2
    IOPORT_PIN_P043_PFC_28_SI5        = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / ENDATn / SI5
    IOPORT_PIN_P043_PFC_29_HDSL1_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P04_3 / HDSLn / HDSL1_CLK2
    IOPORT_PIN_P043_PFC_2C_SD1_DATA3  = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P04_3 / SDHIn / SD1_DATA3

    IOPORT_PIN_P044_PFC_09_GTIOC5_1A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P04_4 / GPTn / GTIOC5_1A
    IOPORT_PIN_P044_PFC_0D_CMTW0_TIC0    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P04_4 / CMTWn / CMTW0_TIC0
    IOPORT_PIN_P044_PFC_11_GMAC0_PTPTRG0 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P04_4 / ETHER_GMACn / GMAC0_PTPTRG0
    IOPORT_PIN_P044_PFC_15_ESC_LATCH0    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P04_4 / ETHER_ESC / ESC_LATCH0
    IOPORT_PIN_P044_PFC_18_SCK1          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P04_4 / SCIn / SCK1
    IOPORT_PIN_P044_PFC_1E_SPI_RSPCK1    = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P04_4 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P044_PFC_24_HSPI_INT      = (0x24U << IOPORT_PFC_OFFSET),                              ///< P04_4 / SHOSTIF / HSPI_INT
    IOPORT_PIN_P044_PFC_28_DUEI6         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P04_4 / ENDATn / DUEI6
    IOPORT_PIN_P044_PFC_29_HDSL1_SEL2    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P04_4 / HDSLn / HDSL1_SEL2
    IOPORT_PIN_P044_PFC_2C_SD0_CLK       = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P04_4 / SDHIn / SD0_CLK
    IOPORT_PIN_P044_PFC_2D_NAND_WE       = (0x2DU << IOPORT_PFC_OFFSET),                              ///< P04_4 / NANDC / NAND_WE

    IOPORT_PIN_P045_PFC_09_GTIOC5_1B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P04_5 / GPTn / GTIOC5_1B
    IOPORT_PIN_P045_PFC_0D_CMTW0_TOC0      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P04_5 / CMTWn / CMTW0_TOC0
    IOPORT_PIN_P045_PFC_15_ESC_LINKACT0    = (0x15U << IOPORT_PFC_OFFSET),                            ///< P04_5 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P045_PFC_18_RXD1_SCL1_MISO1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P04_5 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P045_PFC_1D_CANRX0          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P04_5 / CANFDn / CANRX0
    IOPORT_PIN_P045_PFC_1E_SPI_MISO1       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P04_5 / SPIn / SPI_MISO1
    IOPORT_PIN_P045_PFC_24_HSPI_CS         = (0x24U << IOPORT_PFC_OFFSET),                            ///< P04_5 / SHOSTIF / HSPI_CS
    IOPORT_PIN_P045_PFC_28_TST_OUT6        = (0x28U << IOPORT_PFC_OFFSET),                            ///< P04_5 / ENDATn / TST_OUT6
    IOPORT_PIN_P045_PFC_29_HDSL1_MISO2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P04_5 / HDSLn / HDSL1_MISO2
    IOPORT_PIN_P045_PFC_2C_SD0_CMD         = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P04_5 / SDHIn / SD0_CMD
    IOPORT_PIN_P045_PFC_2D_NAND_RE         = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P04_5 / NANDC / NAND_RE

    IOPORT_PIN_P046_PFC_09_GTIOC5_2A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P04_6 / GPTn / GTIOC5_2A
    IOPORT_PIN_P046_PFC_0B_GTIOC2_4A       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P04_6 / GPTn / GTIOC2_4A
    IOPORT_PIN_P046_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P04_6 / CMTWn / CMTW0_TIC1
    IOPORT_PIN_P046_PFC_15_ESC_LINKACT1    = (0x15U << IOPORT_PFC_OFFSET),                            ///< P04_6 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P046_PFC_18_TXD1_SDA1_MOSI1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P04_6 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P046_PFC_1D_CANTX0          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P04_6 / CANFDn / CANTX0
    IOPORT_PIN_P046_PFC_1E_SPI_MOSI1       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P04_6 / SPIn / SPI_MOSI1
    IOPORT_PIN_P046_PFC_24_HSPI_IO0        = (0x24U << IOPORT_PFC_OFFSET),                            ///< P04_6 / SHOSTIF / HSPI_IO0
    IOPORT_PIN_P046_PFC_28_SI6             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P04_6 / ENDATn / SI6
    IOPORT_PIN_P046_PFC_29_HDSL1_MOSI2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P04_6 / HDSLn / HDSL1_MOSI2
    IOPORT_PIN_P046_PFC_2C_SD0_DATA0       = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P04_6 / SDHIn / SD0_DATA0
    IOPORT_PIN_P046_PFC_2D_NAND_IO0        = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P04_6 / NANDC / NAND_IO0

    IOPORT_PIN_P047_PFC_09_GTIOC5_2B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P04_7 / GPTn / GTIOC5_2B
    IOPORT_PIN_P047_PFC_0B_GTIOC2_4B     = (0x0BU << IOPORT_PFC_OFFSET),                              ///< P04_7 / GPTn / GTIOC2_4B
    IOPORT_PIN_P047_PFC_0D_CMTW0_TOC1    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P04_7 / CMTWn / CMTW0_TOC1
    IOPORT_PIN_P047_PFC_15_ESC_RESETOUT  = (0x15U << IOPORT_PFC_OFFSET),                              ///< P04_7 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P047_PFC_18_CTS1_RTS1_SS1 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P04_7 / SCIn / CTS1_RTS1_SS1
    IOPORT_PIN_P047_PFC_1D_CANRXDP0      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P04_7 / CANFDn / CANRXDP0
    IOPORT_PIN_P047_PFC_1E_SPI_SSL10     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P04_7 / SPIn / SPI_SSL10
    IOPORT_PIN_P047_PFC_24_HSPI_IO1      = (0x24U << IOPORT_PFC_OFFSET),                              ///< P04_7 / SHOSTIF / HSPI_IO1
    IOPORT_PIN_P047_PFC_28_DUEI7         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P04_7 / ENDATn / DUEI7
    IOPORT_PIN_P047_PFC_29_HDSL2_LINK    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P04_7 / HDSLn / HDSL2_LINK
    IOPORT_PIN_P047_PFC_2C_SD0_DATA1     = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P04_7 / SDHIn / SD0_DATA1
    IOPORT_PIN_P047_PFC_2D_NAND_IO1      = (0x2DU << IOPORT_PFC_OFFSET),                              ///< P04_7 / NANDC / NAND_IO1

    IOPORT_PIN_P050_PFC_09_GTIOC5_3A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / GPTn / GTIOC5_3A
    IOPORT_PIN_P050_PFC_0B_GTIOC3_4A  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / GPTn / GTIOC3_4A
    IOPORT_PIN_P050_PFC_0D_CMTW1_TIC0 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / CMTWn / CMTW1_TIC0
    IOPORT_PIN_P050_PFC_15_ESC_LEDERR = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P050_PFC_18_CTS1       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / SCIn / CTS1
    IOPORT_PIN_P050_PFC_1A_SCKE5      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / SCIEn / SCKE5
    IOPORT_PIN_P050_PFC_1D_CANTXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / CANFDn / CANTXDP0
    IOPORT_PIN_P050_PFC_1E_SPI_SSL11  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / SPIn / SPI_SSL11
    IOPORT_PIN_P050_PFC_24_HSPI_IO2   = (0x24U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / SHOSTIF / HSPI_IO2
    IOPORT_PIN_P050_PFC_26_ENCIFCK5   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / ENCIFn / ENCIFCK5
    IOPORT_PIN_P050_PFC_28_TST_OUT7   = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / ENDATn / TST_OUT7
    IOPORT_PIN_P050_PFC_29_HDSL2_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P05_0 / HDSLn / HDSL2_SMPL
    IOPORT_PIN_P050_PFC_2C_SD0_DATA2  = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / SDHIn / SD0_DATA2
    IOPORT_PIN_P050_PFC_2D_NAND_IO2   = (0x2DU << IOPORT_PFC_OFFSET),                                 ///< P05_0 / NANDC / NAND_IO2

    IOPORT_PIN_P051_PFC_09_GTIOC5_3B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P05_1 / GPTn / GTIOC5_3B
    IOPORT_PIN_P051_PFC_0B_GTIOC3_4B     = (0x0BU << IOPORT_PFC_OFFSET),                              ///< P05_1 / GPTn / GTIOC3_4B
    IOPORT_PIN_P051_PFC_0D_CMTW1_TOC0    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P05_1 / CMTWn / CMTW1_TOC0
    IOPORT_PIN_P051_PFC_14_ETHSW_PTPOUT0 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P05_1 / ETHER_ETHSW / ETHSW_PTPOUT0
    IOPORT_PIN_P051_PFC_15_ESC_SYNC0     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P05_1 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P051_PFC_18_DE1           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P05_1 / SCIn / DE1
    IOPORT_PIN_P051_PFC_1A_DEE5          = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P05_1 / SCIEn / DEE5
    IOPORT_PIN_P051_PFC_1E_SPI_SSL12     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P05_1 / SPIn / SPI_SSL12
    IOPORT_PIN_P051_PFC_1F_SPI_RSPCK0    = (0x1FU << IOPORT_PFC_OFFSET),                              ///< P05_1 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P051_PFC_24_HSPI_IO3      = (0x24U << IOPORT_PFC_OFFSET),                              ///< P05_1 / SHOSTIF / HSPI_IO3
    IOPORT_PIN_P051_PFC_26_ENCIFOE5      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P05_1 / ENCIFn / ENCIFOE5
    IOPORT_PIN_P051_PFC_28_SI7           = (0x28U << IOPORT_PFC_OFFSET),                              ///< P05_1 / ENDATn / SI7
    IOPORT_PIN_P051_PFC_2C_SD0_DATA3     = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P05_1 / SDHIn / SD0_DATA3
    IOPORT_PIN_P051_PFC_2D_NAND_IO3      = (0x2DU << IOPORT_PFC_OFFSET),                              ///< P05_1 / NANDC / NAND_IO3

    IOPORT_PIN_P052_PFC_09_GTIOC5_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / GPTn / GTIOC5_0A
    IOPORT_PIN_P052_PFC_0B_GTIOC1_3B  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / GPTn / GTIOC1_3B
    IOPORT_PIN_P052_PFC_0D_CMTW1_TIC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / CMTWn / CMTW1_TIC1
    IOPORT_PIN_P052_PFC_15_ESC_LEDRUN = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P052_PFC_18_SCK2       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / SCIn / SCK2
    IOPORT_PIN_P052_PFC_1A_TXDE5      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / SCIEn / TXDE5
    IOPORT_PIN_P052_PFC_1E_SPI_RSPCK2 = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / SPIn / SPI_RSPCK2
    IOPORT_PIN_P052_PFC_24_HSPI_CK    = (0x24U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / SHOSTIF / HSPI_CK
    IOPORT_PIN_P052_PFC_26_ENCIFDO5   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / ENCIFn / ENCIFDO5
    IOPORT_PIN_P052_PFC_29_HDSL2_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P05_2 / HDSLn / HDSL2_CLK1
    IOPORT_PIN_P052_PFC_2C_SD0_DATA4  = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / SDHIn / SD0_DATA4
    IOPORT_PIN_P052_PFC_2D_NAND_IO4   = (0x2DU << IOPORT_PFC_OFFSET),                                 ///< P05_2 / NANDC / NAND_IO4

    IOPORT_PIN_P053_PFC_09_GTIOC5_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P05_3 / GPTn / GTIOC5_0B
    IOPORT_PIN_P053_PFC_0D_CMTW1_TOC1      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P05_3 / CMTWn / CMTW1_TOC1
    IOPORT_PIN_P053_PFC_0F_ETH0_TXER       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P05_3 / ETHER_ETHn / ETH0_TXER
    IOPORT_PIN_P053_PFC_10_ETH1_RXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P05_3 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P053_PFC_18_RXD2_SCL2_MISO2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P05_3 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P053_PFC_1A_RXDE5           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P05_3 / SCIEn / RXDE5
    IOPORT_PIN_P053_PFC_1C_IIC_SCL2        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P05_3 / IICn / IIC_SCL2
    IOPORT_PIN_P053_PFC_1E_SPI_MISO2       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P05_3 / SPIn / SPI_MISO2
    IOPORT_PIN_P053_PFC_24_HSPI_IO4        = (0x24U << IOPORT_PFC_OFFSET),                            ///< P05_3 / SHOSTIF / HSPI_IO4
    IOPORT_PIN_P053_PFC_26_ENCIFDI5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P05_3 / ENCIFn / ENCIFDI5
    IOPORT_PIN_P053_PFC_29_HDSL2_SEL1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P05_3 / HDSLn / HDSL2_SEL1
    IOPORT_PIN_P053_PFC_2C_SD0_DATA5       = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P05_3 / SDHIn / SD0_DATA5
    IOPORT_PIN_P053_PFC_2D_NAND_IO5        = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P05_3 / NANDC / NAND_IO5

    IOPORT_PIN_P054_PFC_0B_GTIOC2_3A       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P05_4 / GPTn / GTIOC2_3A
    IOPORT_PIN_P054_PFC_0F_ETH0_RXER       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P05_4 / ETHER_ETHn / ETH0_RXER
    IOPORT_PIN_P054_PFC_18_TXD2_SDA2_MOSI2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P05_4 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P054_PFC_1C_IIC_SDA2        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P05_4 / IICn / IIC_SDA2
    IOPORT_PIN_P054_PFC_1E_SPI_MOSI2       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P05_4 / SPIn / SPI_MOSI2
    IOPORT_PIN_P054_PFC_21_MCLK00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P05_4 / DSMIFn / MCLK00
    IOPORT_PIN_P054_PFC_24_HSPI_IO5        = (0x24U << IOPORT_PFC_OFFSET),                            ///< P05_4 / SHOSTIF / HSPI_IO5
    IOPORT_PIN_P054_PFC_29_HDSL2_MISO1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P05_4 / HDSLn / HDSL2_MISO1
    IOPORT_PIN_P054_PFC_2C_SD0_DATA6       = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P05_4 / SDHIn / SD0_DATA6
    IOPORT_PIN_P054_PFC_2D_NAND_IO6        = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P05_4 / NANDC / NAND_IO6

    IOPORT_PIN_P055_PFC_0B_GTIOC2_3B       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P05_5 / GPTn / GTIOC2_3B
    IOPORT_PIN_P055_PFC_0F_ETH0_CRS        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P05_5 / ETHER_ETHn / ETH0_CRS
    IOPORT_PIN_P055_PFC_18_CTS2_RTS2_SS2   = (0x18U << IOPORT_PFC_OFFSET),                            ///< P05_5 / SCIn / CTS2_RTS2_SS2
    IOPORT_PIN_P055_PFC_19_RXD2_SCL2_MISO2 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P05_5 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P055_PFC_1E_SPI_SSL20       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P05_5 / SPIn / SPI_SSL20
    IOPORT_PIN_P055_PFC_21_MDAT00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P05_5 / DSMIFn / MDAT00
    IOPORT_PIN_P055_PFC_24_HSPI_IO6        = (0x24U << IOPORT_PFC_OFFSET),                            ///< P05_5 / SHOSTIF / HSPI_IO6
    IOPORT_PIN_P055_PFC_29_HDSL2_MOSI1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P05_5 / HDSLn / HDSL2_MOSI1
    IOPORT_PIN_P055_PFC_2C_SD0_DATA7       = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P05_5 / SDHIn / SD0_DATA7
    IOPORT_PIN_P055_PFC_2D_NAND_IO7        = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P05_5 / NANDC / NAND_IO7

    IOPORT_PIN_P056_PFC_0F_ETH0_COL        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P05_6 / ETHER_ETHn / ETH0_COL
    IOPORT_PIN_P056_PFC_18_CTS2            = (0x18U << IOPORT_PFC_OFFSET),                            ///< P05_6 / SCIn / CTS2
    IOPORT_PIN_P056_PFC_19_TXD2_SDA2_MOSI2 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P05_6 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P056_PFC_1E_SPI_SSL21       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P05_6 / SPIn / SPI_SSL21
    IOPORT_PIN_P056_PFC_21_MCLK01          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P05_6 / DSMIFn / MCLK01
    IOPORT_PIN_P056_PFC_24_HSPI_IO7        = (0x24U << IOPORT_PFC_OFFSET),                            ///< P05_6 / SHOSTIF / HSPI_IO7
    IOPORT_PIN_P056_PFC_29_HDSL2_CLK2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P05_6 / HDSLn / HDSL2_CLK2
    IOPORT_PIN_P056_PFC_2C_SD0_RST         = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P05_6 / SDHIn / SD0_RST
    IOPORT_PIN_P056_PFC_2D_NAND_WP         = (0x2DU << IOPORT_PFC_OFFSET),                            ///< P05_6 / NANDC / NAND_WP

    IOPORT_PIN_P057_PFC_04_CS2          = (0x04U << IOPORT_PFC_OFFSET),                               ///< P05_7 / BSC / CS2
    IOPORT_PIN_P057_PFC_09_GTIOC1_3A    = (0x09U << IOPORT_PFC_OFFSET),                               ///< P05_7 / GPTn / GTIOC1_3A
    IOPORT_PIN_P057_PFC_0F_ETH1_TXER    = (0x0FU << IOPORT_PFC_OFFSET),                               ///< P05_7 / ETHER_ETHn / ETH1_TXER
    IOPORT_PIN_P057_PFC_15_ESC_RESETOUT = (0x15U << IOPORT_PFC_OFFSET),                               ///< P05_7 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P057_PFC_18_SCK3         = (0x18U << IOPORT_PFC_OFFSET),                               ///< P05_7 / SCIn / SCK3
    IOPORT_PIN_P057_PFC_1A_SCKE5        = (0x1AU << IOPORT_PFC_OFFSET),                               ///< P05_7 / SCIEn / SCKE5
    IOPORT_PIN_P057_PFC_1E_SPI_RSPCK0   = (0x1EU << IOPORT_PFC_OFFSET),                               ///< P05_7 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P057_PFC_21_MDAT00       = (0x21U << IOPORT_PFC_OFFSET),                               ///< P05_7 / DSMIFn / MDAT00
    IOPORT_PIN_P057_PFC_26_ENCIFCK5     = (0x26U << IOPORT_PFC_OFFSET),                               ///< P05_7 / ENCIFn / ENCIFCK5
    IOPORT_PIN_P057_PFC_28_DUEI4        = (0x28U << IOPORT_PFC_OFFSET),                               ///< P05_7 / ENDATn / DUEI4
    IOPORT_PIN_P057_PFC_29_HDSL2_SEL2   = (0x29U << IOPORT_PFC_OFFSET),                               ///< P05_7 / HDSLn / HDSL2_SEL2

    IOPORT_PIN_P060_PFC_04_CS3           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P06_0 / BSC / CS3
    IOPORT_PIN_P060_PFC_09_GTIOC1_0A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P06_0 / GPTn / GTIOC1_0A
    IOPORT_PIN_P060_PFC_0F_ETH1_RXER     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P06_0 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P060_PFC_15_ESC_LEDSTER   = (0x15U << IOPORT_PFC_OFFSET),                              ///< P06_0 / ETHER_ESC / ESC_LEDSTER
    IOPORT_PIN_P060_PFC_18_CTS3_RTS3_SS3 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P06_0 / SCIn / CTS3_RTS3_SS3
    IOPORT_PIN_P060_PFC_1D_CANRXDP1      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P06_0 / CANFDn / CANRXDP1
    IOPORT_PIN_P060_PFC_1E_SPI_SSL00     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P06_0 / SPIn / SPI_SSL00
    IOPORT_PIN_P060_PFC_28_TST_OUT4      = (0x28U << IOPORT_PFC_OFFSET),                              ///< P06_0 / ENDATn / TST_OUT4
    IOPORT_PIN_P060_PFC_29_HDSL2_MISO2   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P06_0 / HDSLn / HDSL2_MISO2

    IOPORT_PIN_P061_PFC_04_CS5             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P06_1 / BSC / CS5
    IOPORT_PIN_P061_PFC_09_GTIOC1_3B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P06_1 / GPTn / GTIOC1_3B
    IOPORT_PIN_P061_PFC_0F_ETH1_CRS        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P06_1 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P061_PFC_18_TXD3_SDA3_MOSI3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P06_1 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P061_PFC_1A_DEE5            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P06_1 / SCIEn / DEE5
    IOPORT_PIN_P061_PFC_1D_CANTX1          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P06_1 / CANFDn / CANTX1
    IOPORT_PIN_P061_PFC_1E_SPI_MOSI0       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P06_1 / SPIn / SPI_MOSI0
    IOPORT_PIN_P061_PFC_21_MDAT00          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P06_1 / DSMIFn / MDAT00
    IOPORT_PIN_P061_PFC_26_ENCIFOE5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P06_1 / ENCIFn / ENCIFOE5
    IOPORT_PIN_P061_PFC_28_SI4             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P06_1 / ENDATn / SI4
    IOPORT_PIN_P061_PFC_29_HDSL2_MOSI2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P06_1 / HDSLn / HDSL2_MOSI2

    IOPORT_PIN_P062_PFC_04_D28             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P06_2 / BSC / D28
    IOPORT_PIN_P062_PFC_09_GTIOC1_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P06_2 / GPTn / GTIOC1_0B
    IOPORT_PIN_P062_PFC_0A_GTIOC2_0A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P06_2 / GPTn / GTIOC2_0A
    IOPORT_PIN_P062_PFC_0F_ETH1_COL        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P06_2 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P062_PFC_18_RXD3_SCL3_MISO3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P06_2 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P062_PFC_1D_CANRX1          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P06_2 / CANFDn / CANRX1
    IOPORT_PIN_P062_PFC_1E_SPI_MISO0       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P06_2 / SPIn / SPI_MISO0
    IOPORT_PIN_P062_PFC_21_MCLK01          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P06_2 / DSMIFn / MCLK01
    IOPORT_PIN_P062_PFC_28_DUEI5           = (0x28U << IOPORT_PFC_OFFSET),                            ///< P06_2 / ENDATn / DUEI5
    IOPORT_PIN_P062_PFC_29_HDSL3_LINK      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P06_2 / HDSLn / HDSL3_LINK
    IOPORT_PIN_P062_PFC_2E_HD28            = (0x2EU << IOPORT_PFC_OFFSET),                            ///< P06_2 / PHOSTIF / HD28

    IOPORT_PIN_P063_PFC_04_D29           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P06_3 / BSC / D29
    IOPORT_PIN_P063_PFC_09_GTIOC1_1B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P06_3 / GPTn / GTIOC1_1B
    IOPORT_PIN_P063_PFC_0A_GTIOC2_0B     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P06_3 / GPTn / GTIOC2_0B
    IOPORT_PIN_P063_PFC_11_GMAC1_PTPTRG0 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P06_3 / ETHER_GMACn / GMAC1_PTPTRG0
    IOPORT_PIN_P063_PFC_15_ESC_LEDERR    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P06_3 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P063_PFC_18_CTS3          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P06_3 / SCIn / CTS3
    IOPORT_PIN_P063_PFC_1D_CANTXDP1      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P06_3 / CANFDn / CANTXDP1
    IOPORT_PIN_P063_PFC_1E_SPI_SSL01     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P06_3 / SPIn / SPI_SSL01
    IOPORT_PIN_P063_PFC_28_TST_OUT5      = (0x28U << IOPORT_PFC_OFFSET),                              ///< P06_3 / ENDATn / TST_OUT5
    IOPORT_PIN_P063_PFC_29_HDSL3_SMPL    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P06_3 / HDSLn / HDSL3_SMPL
    IOPORT_PIN_P063_PFC_2E_HD29          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P06_3 / PHOSTIF / HD29

    IOPORT_PIN_P064_PFC_04_D30           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P06_4 / BSC / D30
    IOPORT_PIN_P064_PFC_06_MTIOC2A       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P06_4 / MTU3n / MTIOC2A
    IOPORT_PIN_P064_PFC_09_GTIOC1_1A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P06_4 / GPTn / GTIOC1_1A
    IOPORT_PIN_P064_PFC_0A_GTIOC2_1A     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P06_4 / GPTn / GTIOC2_1A
    IOPORT_PIN_P064_PFC_11_GMAC1_PTPTRG1 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P06_4 / ETHER_GMACn / GMAC1_PTPTRG1
    IOPORT_PIN_P064_PFC_18_DE3           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P06_4 / SCIn / DE3
    IOPORT_PIN_P064_PFC_1E_SPI_SSL02     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P06_4 / SPIn / SPI_SSL02
    IOPORT_PIN_P064_PFC_21_MDAT01        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P06_4 / DSMIFn / MDAT01
    IOPORT_PIN_P064_PFC_28_SI5           = (0x28U << IOPORT_PFC_OFFSET),                              ///< P06_4 / ENDATn / SI5
    IOPORT_PIN_P064_PFC_29_HDSL3_CLK1    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P06_4 / HDSLn / HDSL3_CLK1
    IOPORT_PIN_P064_PFC_2E_HD30          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P06_4 / PHOSTIF / HD30

    IOPORT_PIN_P065_PFC_04_D31        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / BSC / D31
    IOPORT_PIN_P065_PFC_06_MTIOC2B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / MTU3n / MTIOC2B
    IOPORT_PIN_P065_PFC_09_GTIOC1_2A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / GPTn / GTIOC1_2A
    IOPORT_PIN_P065_PFC_0A_GTIOC2_1B  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P06_5 / GPTn / GTIOC2_1B
    IOPORT_PIN_P065_PFC_18_SCK4       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / SCIn / SCK4
    IOPORT_PIN_P065_PFC_1E_SPI_SSL03  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P06_5 / SPIn / SPI_SSL03
    IOPORT_PIN_P065_PFC_21_MCLK30     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / DSMIFn / MCLK30
    IOPORT_PIN_P065_PFC_28_DUEI6      = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / ENDATn / DUEI6
    IOPORT_PIN_P065_PFC_29_HDSL3_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P06_5 / HDSLn / HDSL3_SEL1
    IOPORT_PIN_P065_PFC_2E_HD31       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P06_5 / PHOSTIF / HD31

    IOPORT_PIN_P066_PFC_09_GTIOC1_4A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P06_6 / GPTn / GTIOC1_4A
    IOPORT_PIN_P066_PFC_0A_GTIOC2_2A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P06_6 / GPTn / GTIOC2_2A
    IOPORT_PIN_P066_PFC_18_RXD4_SCL4_MISO4 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P06_6 / SCIn / RXD4_SCL4_MISO4
    IOPORT_PIN_P066_PFC_1A_TXDE5           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P06_6 / SCIEn / TXDE5
    IOPORT_PIN_P066_PFC_1D_CANRX0          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P06_6 / CANFDn / CANRX0
    IOPORT_PIN_P066_PFC_21_MCLK02          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P06_6 / DSMIFn / MCLK02
    IOPORT_PIN_P066_PFC_26_ENCIFDO5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P06_6 / ENCIFn / ENCIFDO5
    IOPORT_PIN_P066_PFC_28_TST_OUT6        = (0x28U << IOPORT_PFC_OFFSET),                            ///< P06_6 / ENDATn / TST_OUT6
    IOPORT_PIN_P066_PFC_29_HDSL3_MISO1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P06_6 / HDSLn / HDSL3_MISO1
    IOPORT_PIN_P066_PFC_2C_SD1_PWEN        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P06_6 / SDHIn / SD1_PWEN

    IOPORT_PIN_P067_PFC_09_GTIOC1_4B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P06_7 / GPTn / GTIOC1_4B
    IOPORT_PIN_P067_PFC_0A_GTIOC2_2B       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P06_7 / GPTn / GTIOC2_2B
    IOPORT_PIN_P067_PFC_18_TXD4_SDA4_MOSI4 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P06_7 / SCIn / TXD4_SDA4_MOSI4
    IOPORT_PIN_P067_PFC_1A_RXDE5           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P06_7 / SCIEn / RXDE5
    IOPORT_PIN_P067_PFC_1D_CANTX0          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P06_7 / CANFDn / CANTX0
    IOPORT_PIN_P067_PFC_21_MDAT02          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P06_7 / DSMIFn / MDAT02
    IOPORT_PIN_P067_PFC_26_ENCIFDI5        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P06_7 / ENCIFn / ENCIFDI5
    IOPORT_PIN_P067_PFC_28_SI6             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P06_7 / ENDATn / SI6
    IOPORT_PIN_P067_PFC_29_HDSL3_MOSI1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P06_7 / HDSLn / HDSL3_MOSI1
    IOPORT_PIN_P067_PFC_2C_SD1_IOVS        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P06_7 / SDHIn / SD1_IOVS

    IOPORT_PIN_P070_PFC_08_POE0          = (0x08U << IOPORT_PFC_OFFSET),                              ///< P07_0 / MTU_POE3 / POE0
    IOPORT_PIN_P070_PFC_09_GTIOC1_2B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P07_0 / GPTn / GTIOC1_2B
    IOPORT_PIN_P070_PFC_0F_ETH4_TXER     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P07_0 / ETHER_ETHn / ETH4_TXER
    IOPORT_PIN_P070_PFC_15_ESC_RESETOUT  = (0x15U << IOPORT_PFC_OFFSET),                              ///< P07_0 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P070_PFC_18_CTS4_RTS4_SS4 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P07_0 / SCIn / CTS4_RTS4_SS4
    IOPORT_PIN_P070_PFC_1C_IIC_SDA1      = (0x1CU << IOPORT_PFC_OFFSET),                              ///< P07_0 / IICn / IIC_SDA1
    IOPORT_PIN_P070_PFC_1E_SPI_SSL13     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P07_0 / SPIn / SPI_SSL13
    IOPORT_PIN_P070_PFC_21_MDAT30        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P07_0 / DSMIFn / MDAT30
    IOPORT_PIN_P070_PFC_23_ADTRG2        = (0x23U << IOPORT_PFC_OFFSET),                              ///< P07_0 / ADCn / ADTRG2
    IOPORT_PIN_P070_PFC_28_DUEI7         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P07_0 / ENDATn / DUEI7
    IOPORT_PIN_P070_PFC_29_HDSL3_CLK2    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P07_0 / HDSLn / HDSL3_CLK2
    IOPORT_PIN_P070_PFC_2A_POUTA         = (0x2AU << IOPORT_PFC_OFFSET),                              ///< P07_0 / ENCOUT / POUTA

    IOPORT_PIN_P071_PFC_08_POE4           = (0x08U << IOPORT_PFC_OFFSET),                             ///< P07_1 / MTU_POE3 / POE4
    IOPORT_PIN_P071_PFC_0F_ETH4_RXER      = (0x0FU << IOPORT_PFC_OFFSET),                             ///< P07_1 / ETHER_ETHn / ETH4_RXER
    IOPORT_PIN_P071_PFC_14_ETHSW_TDMAOUT1 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P07_1 / ETHER_ETHSW / ETHSW_TDMAOUT1
    IOPORT_PIN_P071_PFC_15_ESC_LEDERR     = (0x15U << IOPORT_PFC_OFFSET),                             ///< P07_1 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P071_PFC_18_CTS4           = (0x18U << IOPORT_PFC_OFFSET),                             ///< P07_1 / SCIn / CTS4
    IOPORT_PIN_P071_PFC_1A_DEE1           = (0x1AU << IOPORT_PFC_OFFSET),                             ///< P07_1 / SCIEn / DEE1
    IOPORT_PIN_P071_PFC_1D_CANRXDP0       = (0x1DU << IOPORT_PFC_OFFSET),                             ///< P07_1 / CANFDn / CANRXDP0
    IOPORT_PIN_P071_PFC_1E_SPI_SSL22      = (0x1EU << IOPORT_PFC_OFFSET),                             ///< P07_1 / SPIn / SPI_SSL22
    IOPORT_PIN_P071_PFC_21_MCLK31         = (0x21U << IOPORT_PFC_OFFSET),                             ///< P07_1 / DSMIFn / MCLK31
    IOPORT_PIN_P071_PFC_23_ADTRG0         = (0x23U << IOPORT_PFC_OFFSET),                             ///< P07_1 / ADCn / ADTRG0
    IOPORT_PIN_P071_PFC_26_ENCIFOE1       = (0x26U << IOPORT_PFC_OFFSET),                             ///< P07_1 / ENCIFn / ENCIFOE1
    IOPORT_PIN_P071_PFC_28_TST_OUT7       = (0x28U << IOPORT_PFC_OFFSET),                             ///< P07_1 / ENDATn / TST_OUT7
    IOPORT_PIN_P071_PFC_29_HDSL3_SEL2     = (0x29U << IOPORT_PFC_OFFSET),                             ///< P07_1 / HDSLn / HDSL3_SEL2

    IOPORT_PIN_P072_PFC_08_POE8          = (0x08U << IOPORT_PFC_OFFSET),                              ///< P07_2 / MTU_POE3 / POE8
    IOPORT_PIN_P072_PFC_0F_ETH4_CRS      = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P07_2 / ETHER_ETHn / ETH4_CRS
    IOPORT_PIN_P072_PFC_14_ETHSW_PTPOUT2 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P07_2 / ETHER_ETHSW / ETHSW_PTPOUT2
    IOPORT_PIN_P072_PFC_15_ESC_SYNC0     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P07_2 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P072_PFC_18_DE4           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P07_2 / SCIn / DE4
    IOPORT_PIN_P072_PFC_1A_TXDE1         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P07_2 / SCIEn / TXDE1
    IOPORT_PIN_P072_PFC_1D_CANTXDP0      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P07_2 / CANFDn / CANTXDP0
    IOPORT_PIN_P072_PFC_1E_SPI_SSL23     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P07_2 / SPIn / SPI_SSL23
    IOPORT_PIN_P072_PFC_21_MDAT31        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P07_2 / DSMIFn / MDAT31
    IOPORT_PIN_P072_PFC_23_ADTRG1        = (0x23U << IOPORT_PFC_OFFSET),                              ///< P07_2 / ADCn / ADTRG1
    IOPORT_PIN_P072_PFC_26_ENCIFDO1      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P07_2 / ENCIFn / ENCIFDO1
    IOPORT_PIN_P072_PFC_28_SI7           = (0x28U << IOPORT_PFC_OFFSET),                              ///< P07_2 / ENDATn / SI7
    IOPORT_PIN_P072_PFC_2A_POUTB         = (0x2AU << IOPORT_PFC_OFFSET),                              ///< P07_2 / ENCOUT / POUTB

    IOPORT_PIN_P073_PFC_08_POE10         = (0x08U << IOPORT_PFC_OFFSET),                              ///< P07_3 / MTU_POE3 / POE10
    IOPORT_PIN_P073_PFC_0A_GTIOC1_0A     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P07_3 / GPTn / GTIOC1_0A
    IOPORT_PIN_P073_PFC_0F_ETH4_COL      = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P07_3 / ETHER_ETHn / ETH4_COL
    IOPORT_PIN_P073_PFC_11_GMAC2_PTPTRG1 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P07_3 / ETHER_GMACn / GMAC2_PTPTRG1
    IOPORT_PIN_P073_PFC_14_ETHSW_PTPOUT3 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P07_3 / ETHER_ETHSW / ETHSW_PTPOUT3
    IOPORT_PIN_P073_PFC_15_ESC_SYNC1     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P07_3 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P073_PFC_1A_RXDE1         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P07_3 / SCIEn / RXDE1
    IOPORT_PIN_P073_PFC_1C_IIC_SCL1      = (0x1CU << IOPORT_PFC_OFFSET),                              ///< P07_3 / IICn / IIC_SCL1
    IOPORT_PIN_P073_PFC_21_MCLK22        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P07_3 / DSMIFn / MCLK22
    IOPORT_PIN_P073_PFC_26_ENCIFDI1      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P07_3 / ENCIFn / ENCIFDI1
    IOPORT_PIN_P073_PFC_29_HDSL3_MISO2   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P07_3 / HDSLn / HDSL3_MISO2
    IOPORT_PIN_P073_PFC_2A_POUTZ         = (0x2AU << IOPORT_PFC_OFFSET),                              ///< P07_3 / ENCOUT / POUTZ

    IOPORT_PIN_P074_PFC_04_A16            = (0x04U << IOPORT_PFC_OFFSET),                             ///< P07_4 / BSC / A16
    IOPORT_PIN_P074_PFC_08_POE11          = (0x08U << IOPORT_PFC_OFFSET),                             ///< P07_4 / MTU_POE3 / POE11
    IOPORT_PIN_P074_PFC_0A_GTIOC1_1B      = (0x0AU << IOPORT_PFC_OFFSET),                             ///< P07_4 / GPTn / GTIOC1_1B
    IOPORT_PIN_P074_PFC_11_GMAC2_PTPTRG0  = (0x11U << IOPORT_PFC_OFFSET),                             ///< P07_4 / ETHER_GMACn / GMAC2_PTPTRG0
    IOPORT_PIN_P074_PFC_14_ETHSW_TDMAOUT0 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P07_4 / ETHER_ETHSW / ETHSW_TDMAOUT0
    IOPORT_PIN_P074_PFC_15_ESC_LEDRUN     = (0x15U << IOPORT_PFC_OFFSET),                             ///< P07_4 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P074_PFC_1A_SCKE1          = (0x1AU << IOPORT_PFC_OFFSET),                             ///< P07_4 / SCIEn / SCKE1
    IOPORT_PIN_P074_PFC_21_MDAT22         = (0x21U << IOPORT_PFC_OFFSET),                             ///< P07_4 / DSMIFn / MDAT22
    IOPORT_PIN_P074_PFC_26_ENCIFCK1       = (0x26U << IOPORT_PFC_OFFSET),                             ///< P07_4 / ENCIFn / ENCIFCK1
    IOPORT_PIN_P074_PFC_29_HDSL3_MOSI2    = (0x29U << IOPORT_PFC_OFFSET),                             ///< P07_4 / HDSLn / HDSL3_MOSI2

    IOPORT_PIN_P075_PFC_06_MTCLKC     = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / MTU3 / MTCLKC
    IOPORT_PIN_P075_PFC_07_MTIOC0C    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / MTU3n / MTIOC0C
    IOPORT_PIN_P075_PFC_09_GTIOC4_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / GPTn / GTIOC4_0A
    IOPORT_PIN_P075_PFC_0A_GTIOC0_1A  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / GPTn / GTIOC0_1A
    IOPORT_PIN_P075_PFC_0C_GTETRGA    = (0x0CU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / GPT_POEG / GTETRGA
    IOPORT_PIN_P075_PFC_0F_ETH0_TXER  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / ETHER_ETHn / ETH0_TXER
    IOPORT_PIN_P075_PFC_1A_TXDE6      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / SCIEn / TXDE6
    IOPORT_PIN_P075_PFC_1C_IIC_SDA0   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / IICn / IIC_SDA0
    IOPORT_PIN_P075_PFC_1D_CANTX0     = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / CANFDn / CANTX0
    IOPORT_PIN_P075_PFC_1E_SPI_MOSI3  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P07_5 / SPIn / SPI_MOSI3
    IOPORT_PIN_P075_PFC_21_MCLK21     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / DSMIFn / MCLK21
    IOPORT_PIN_P075_PFC_26_ENCIFDO6   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / ENCIFn / ENCIFDO6
    IOPORT_PIN_P075_PFC_28_DUEI0      = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / ENDATn / DUEI0
    IOPORT_PIN_P075_PFC_29_HDSL6_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P07_5 / HDSLn / HDSL6_LINK

    IOPORT_PIN_P076_PFC_04_A23        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P07_6 / BSC / A23
    IOPORT_PIN_P076_PFC_0C_GTETRGB    = (0x0CU << IOPORT_PFC_OFFSET),                                 ///< P07_6 / GPT_POEG / GTETRGB
    IOPORT_PIN_P076_PFC_0F_ETH0_RXER  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P07_6 / ETHER_ETHn / ETH0_RXER
    IOPORT_PIN_P076_PFC_1D_CANRXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P07_6 / CANFDn / CANRXDP0
    IOPORT_PIN_P076_PFC_1E_SPI_SSL30  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P07_6 / SPIn / SPI_SSL30
    IOPORT_PIN_P076_PFC_28_TST_OUT0   = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P07_6 / ENDATn / TST_OUT0
    IOPORT_PIN_P076_PFC_29_HDSL6_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P07_6 / HDSLn / HDSL6_SMPL

    IOPORT_PIN_P077_PFC_04_A22       = (0x04U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / BSC / A22
    IOPORT_PIN_P077_PFC_06_MTCLKD    = (0x06U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / MTU3 / MTCLKD
    IOPORT_PIN_P077_PFC_07_MTIOC0D   = (0x07U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / MTU3n / MTIOC0D
    IOPORT_PIN_P077_PFC_09_GTIOC4_0B = (0x09U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / GPTn / GTIOC4_0B
    IOPORT_PIN_P077_PFC_0A_GTIOC0_1B = (0x0AU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / GPTn / GTIOC0_1B
    IOPORT_PIN_P077_PFC_0C_GTETRGC   = (0x0CU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / GPT_POEG / GTETRGC
    IOPORT_PIN_P077_PFC_0F_ETH0_CRS  = (0x0FU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / ETHER_ETHn / ETH0_CRS
    IOPORT_PIN_P077_PFC_18_SCK5      = (0x18U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / SCIn / SCK5
    IOPORT_PIN_P077_PFC_1A_DEE6      = (0x1AU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / SCIEn / DEE6
    IOPORT_PIN_P077_PFC_1C_IIC_SCL0  = (0x1CU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / IICn / IIC_SCL0
    IOPORT_PIN_P077_PFC_1D_CANRX0    = (0x1DU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / CANFDn / CANRX0
    IOPORT_PIN_P077_PFC_1E_SPI_MISO3 = (0x1EU << IOPORT_PFC_OFFSET),                                  ///< P07_7 / SPIn / SPI_MISO3
    IOPORT_PIN_P077_PFC_21_MCLK32    = (0x21U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / DSMIFn / MCLK32
    IOPORT_PIN_P077_PFC_26_ENCIFOE6  = (0x26U << IOPORT_PFC_OFFSET),                                  ///< P07_7 / ENCIFn / ENCIFOE6

    IOPORT_PIN_P080_PFC_04_A21           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P08_0 / BSC / A21
    IOPORT_PIN_P080_PFC_06_MTIOC6A       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P08_0 / MTU3n / MTIOC6A
    IOPORT_PIN_P080_PFC_07_MTIOC0A       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P08_0 / MTU3n / MTIOC0A
    IOPORT_PIN_P080_PFC_09_GTIOC4_1A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P08_0 / GPTn / GTIOC4_1A
    IOPORT_PIN_P080_PFC_0C_GTETRGD       = (0x0CU << IOPORT_PFC_OFFSET),                              ///< P08_0 / GPT_POEG / GTETRGD
    IOPORT_PIN_P080_PFC_0F_ETH0_COL      = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P08_0 / ETHER_ETHn / ETH0_COL
    IOPORT_PIN_P080_PFC_18_CTS5_RTS5_SS5 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P08_0 / SCIn / CTS5_RTS5_SS5
    IOPORT_PIN_P080_PFC_1A_SCKE6         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P08_0 / SCIEn / SCKE6
    IOPORT_PIN_P080_PFC_1D_CANRX1        = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P08_0 / CANFDn / CANRX1
    IOPORT_PIN_P080_PFC_1E_SPI_RSPCK3    = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P08_0 / SPIn / SPI_RSPCK3
    IOPORT_PIN_P080_PFC_21_MDAT32        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P08_0 / DSMIFn / MDAT32
    IOPORT_PIN_P080_PFC_26_ENCIFCK6      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P08_0 / ENCIFn / ENCIFCK6
    IOPORT_PIN_P080_PFC_28_DUEI1         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P08_0 / ENDATn / DUEI1
    IOPORT_PIN_P080_PFC_29_HDSL6_SEL1    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P08_0 / HDSLn / HDSL6_SEL1

    IOPORT_PIN_P081_PFC_04_A20           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P08_1 / BSC / A20
    IOPORT_PIN_P081_PFC_0C_GTETRGSA      = (0x0CU << IOPORT_PFC_OFFSET),                              ///< P08_1 / GPT_POEG / GTETRGSA
    IOPORT_PIN_P081_PFC_11_GMAC0_PTPTRG0 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P08_1 / ETHER_GMACn / GMAC0_PTPTRG0
    IOPORT_PIN_P081_PFC_15_ESC_LATCH0    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P08_1 / ETHER_ESC / ESC_LATCH0
    IOPORT_PIN_P081_PFC_18_CTS5          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P08_1 / SCIn / CTS5
    IOPORT_PIN_P081_PFC_1D_CANTXDP0      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P08_1 / CANFDn / CANTXDP0
    IOPORT_PIN_P081_PFC_1E_SPI_SSL31     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P08_1 / SPIn / SPI_SSL31
    IOPORT_PIN_P081_PFC_28_TST_OUT1      = (0x28U << IOPORT_PFC_OFFSET),                              ///< P08_1 / ENDATn / TST_OUT1
    IOPORT_PIN_P081_PFC_29_HDSL6_MISO1   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P08_1 / HDSLn / HDSL6_MISO1
    IOPORT_PIN_P081_PFC_2C_SD0_CD        = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P08_1 / SDHIn / SD0_CD

    IOPORT_PIN_P082_PFC_04_A19           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P08_2 / BSC / A19
    IOPORT_PIN_P082_PFC_06_MTIOC6C       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P08_2 / MTU3n / MTIOC6C
    IOPORT_PIN_P082_PFC_07_MTIOC0B       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P08_2 / MTU3n / MTIOC0B
    IOPORT_PIN_P082_PFC_0C_GTETRGSB      = (0x0CU << IOPORT_PFC_OFFSET),                              ///< P08_2 / GPT_POEG / GTETRGSB
    IOPORT_PIN_P082_PFC_11_GMAC0_PTPTRG1 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P08_2 / ETHER_GMACn / GMAC0_PTPTRG1
    IOPORT_PIN_P082_PFC_15_ESC_LATCH1    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P08_2 / ETHER_ESC / ESC_LATCH1
    IOPORT_PIN_P082_PFC_18_DE5           = (0x18U << IOPORT_PFC_OFFSET),                              ///< P08_2 / SCIn / DE5
    IOPORT_PIN_P082_PFC_1A_RXDE6         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P08_2 / SCIEn / RXDE6
    IOPORT_PIN_P082_PFC_1D_CANTX1        = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P08_2 / CANFDn / CANTX1
    IOPORT_PIN_P082_PFC_1E_SPI_SSL32     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P08_2 / SPIn / SPI_SSL32
    IOPORT_PIN_P082_PFC_21_MDAT21        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P08_2 / DSMIFn / MDAT21
    IOPORT_PIN_P082_PFC_26_ENCIFDI6      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P08_2 / ENCIFn / ENCIFDI6
    IOPORT_PIN_P082_PFC_2C_SD0_WP        = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P08_2 / SDHIn / SD0_WP

    IOPORT_PIN_P083_PFC_04_A18             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P08_3 / BSC / A18
    IOPORT_PIN_P083_PFC_0F_ETH1_CRS        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P08_3 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P083_PFC_14_ETHSW_TDMAOUT2  = (0x14U << IOPORT_PFC_OFFSET),                            ///< P08_3 / ETHER_ETHSW / ETHSW_TDMAOUT2
    IOPORT_PIN_P083_PFC_15_ESC_LINKACT0    = (0x15U << IOPORT_PFC_OFFSET),                            ///< P08_3 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P083_PFC_18_TXD5_SDA5_MOSI5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P08_3 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P083_PFC_1D_CANRXDP1        = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P08_3 / CANFDn / CANRXDP1
    IOPORT_PIN_P083_PFC_1E_SPI_SSL33       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P08_3 / SPIn / SPI_SSL33
    IOPORT_PIN_P083_PFC_28_SI0             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P08_3 / ENDATn / SI0
    IOPORT_PIN_P083_PFC_29_HDSL6_CLK2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P08_3 / HDSLn / HDSL6_CLK2

    IOPORT_PIN_P084_PFC_04_A17             = (0x04U << IOPORT_PFC_OFFSET),                            ///< P08_4 / BSC / A17
    IOPORT_PIN_P084_PFC_0F_ETH1_COL        = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P08_4 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P084_PFC_14_ETHSW_TDMAOUT3  = (0x14U << IOPORT_PFC_OFFSET),                            ///< P08_4 / ETHER_ETHSW / ETHSW_TDMAOUT3
    IOPORT_PIN_P084_PFC_15_ESC_LINKACT1    = (0x15U << IOPORT_PFC_OFFSET),                            ///< P08_4 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P084_PFC_18_RXD5_SCL5_MISO5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P08_4 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P084_PFC_1D_CANTXDP1        = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P08_4 / CANFDn / CANTXDP1
    IOPORT_PIN_P084_PFC_28_SI1             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P08_4 / ENDATn / SI1
    IOPORT_PIN_P084_PFC_29_HDSL6_SEL2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P08_4 / HDSLn / HDSL6_SEL2

    IOPORT_PIN_P085_PFC_04_A6       = (0x04U << IOPORT_PFC_OFFSET),                                   ///< P08_5 / BSC / A6
    IOPORT_PIN_P085_PFC_1A_SCKE3    = (0x1AU << IOPORT_PFC_OFFSET),                                   ///< P08_5 / SCIEn / SCKE3
    IOPORT_PIN_P085_PFC_26_ENCIFCK3 = (0x26U << IOPORT_PFC_OFFSET),                                   ///< P08_5 / ENCIFn / ENCIFCK3
    IOPORT_PIN_P085_PFC_28_DUEI0    = (0x28U << IOPORT_PFC_OFFSET),                                   ///< P08_5 / ENDATn / DUEI0
    IOPORT_PIN_P085_PFC_2C_SD1_PWEN = (0x2CU << IOPORT_PFC_OFFSET),                                   ///< P08_5 / SDHIn / SD1_PWEN
    IOPORT_PIN_P085_PFC_2D_NAND_ALE = (0x2DU << IOPORT_PFC_OFFSET),                                   ///< P08_5 / NANDC / NAND_ALE
    IOPORT_PIN_P085_PFC_2E_HA6      = (0x2EU << IOPORT_PFC_OFFSET),                                   ///< P08_5 / PHOSTIF / HA6

    IOPORT_PIN_P086_PFC_04_A7       = (0x04U << IOPORT_PFC_OFFSET),                                   ///< P08_6 / BSC / A7
    IOPORT_PIN_P086_PFC_1A_DEE3     = (0x1AU << IOPORT_PFC_OFFSET),                                   ///< P08_6 / SCIEn / DEE3
    IOPORT_PIN_P086_PFC_26_ENCIFOE3 = (0x26U << IOPORT_PFC_OFFSET),                                   ///< P08_6 / ENCIFn / ENCIFOE3
    IOPORT_PIN_P086_PFC_28_TST_OUT0 = (0x28U << IOPORT_PFC_OFFSET),                                   ///< P08_6 / ENDATn / TST_OUT0
    IOPORT_PIN_P086_PFC_2C_SD1_IOVS = (0x2CU << IOPORT_PFC_OFFSET),                                   ///< P08_6 / SDHIn / SD1_IOVS
    IOPORT_PIN_P086_PFC_2D_NAND_CLE = (0x2DU << IOPORT_PFC_OFFSET),                                   ///< P08_6 / NANDC / NAND_CLE
    IOPORT_PIN_P086_PFC_2E_HA7      = (0x2EU << IOPORT_PFC_OFFSET),                                   ///< P08_6 / PHOSTIF / HA7

    IOPORT_PIN_P087_PFC_04_A8       = (0x04U << IOPORT_PFC_OFFSET),                                   ///< P08_7 / BSC / A8
    IOPORT_PIN_P087_PFC_1A_DEE7     = (0x1AU << IOPORT_PFC_OFFSET),                                   ///< P08_7 / SCIEn / DEE7
    IOPORT_PIN_P087_PFC_26_ENCIFOE7 = (0x26U << IOPORT_PFC_OFFSET),                                   ///< P08_7 / ENCIFn / ENCIFOE7
    IOPORT_PIN_P087_PFC_28_SI0      = (0x28U << IOPORT_PFC_OFFSET),                                   ///< P08_7 / ENDATn / SI0
    IOPORT_PIN_P087_PFC_2C_SD0_PWEN = (0x2CU << IOPORT_PFC_OFFSET),                                   ///< P08_7 / SDHIn / SD0_PWEN
    IOPORT_PIN_P087_PFC_2D_NAND_CE0 = (0x2DU << IOPORT_PFC_OFFSET),                                   ///< P08_7 / NANDC / NAND_CE0
    IOPORT_PIN_P087_PFC_2E_HA8      = (0x2EU << IOPORT_PFC_OFFSET),                                   ///< P08_7 / PHOSTIF / HA8

    IOPORT_PIN_P090_PFC_04_WE0           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P09_0 / BSC / WE0
    IOPORT_PIN_P090_PFC_14_ETHSW_PTPOUT1 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P09_0 / ETHER_ETHSW / ETHSW_PTPOUT1
    IOPORT_PIN_P090_PFC_15_ESC_SYNC1     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P09_0 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P090_PFC_1A_TXDE7         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P09_0 / SCIEn / TXDE7
    IOPORT_PIN_P090_PFC_26_ENCIFDO7      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P09_0 / ENCIFn / ENCIFDO7
    IOPORT_PIN_P090_PFC_28_DUEI1         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P09_0 / ENDATn / DUEI1
    IOPORT_PIN_P090_PFC_2C_SD0_IOVS      = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P09_0 / SDHIn / SD0_IOVS
    IOPORT_PIN_P090_PFC_2E_HWR0          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P09_0 / PHOSTIF / HWR0

    IOPORT_PIN_P091_PFC_04_WE1      = (0x04U << IOPORT_PFC_OFFSET),                                   ///< P09_1 / BSC / WE1
    IOPORT_PIN_P091_PFC_1A_SCKE7    = (0x1AU << IOPORT_PFC_OFFSET),                                   ///< P09_1 / SCIEn / SCKE7
    IOPORT_PIN_P091_PFC_26_ENCIFCK7 = (0x26U << IOPORT_PFC_OFFSET),                                   ///< P09_1 / ENCIFn / ENCIFCK7
    IOPORT_PIN_P091_PFC_28_TST_OUT1 = (0x28U << IOPORT_PFC_OFFSET),                                   ///< P09_1 / ENDATn / TST_OUT1
    IOPORT_PIN_P091_PFC_2D_NAND_CE1 = (0x2DU << IOPORT_PFC_OFFSET),                                   ///< P09_1 / NANDC / NAND_CE1
    IOPORT_PIN_P091_PFC_2E_HWR1     = (0x2EU << IOPORT_PFC_OFFSET),                                   ///< P09_1 / PHOSTIF / HWR1

    IOPORT_PIN_P092_PFC_04_WAIT        = (0x04U << IOPORT_PFC_OFFSET),                                ///< P09_2 / BSC / WAIT
    IOPORT_PIN_P092_PFC_18_SCK0        = (0x18U << IOPORT_PFC_OFFSET),                                ///< P09_2 / SCIn / SCK0
    IOPORT_PIN_P092_PFC_1A_RXDE3       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P09_2 / SCIEn / RXDE3
    IOPORT_PIN_P092_PFC_1B_RXDE4       = (0x1BU << IOPORT_PFC_OFFSET),                                ///< P09_2 / SCIEn / RXDE4
    IOPORT_PIN_P092_PFC_26_ENCIFDI3    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P09_2 / ENCIFn / ENCIFDI3
    IOPORT_PIN_P092_PFC_27_ENCIFDI4    = (0x27U << IOPORT_PFC_OFFSET),                                ///< P09_2 / ENCIFn / ENCIFDI4
    IOPORT_PIN_P092_PFC_28_SI1         = (0x28U << IOPORT_PFC_OFFSET),                                ///< P09_2 / ENDATn / SI1
    IOPORT_PIN_P092_PFC_29_HDSL6_CLK1  = (0x29U << IOPORT_PFC_OFFSET),                                ///< P09_2 / HDSLn / HDSL6_CLK1
    IOPORT_PIN_P092_PFC_2D_NAND_RY_BY1 = (0x2DU << IOPORT_PFC_OFFSET),                                ///< P09_2 / NANDC / NAND_RY_BY1
    IOPORT_PIN_P092_PFC_2E_HWAIT       = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P09_2 / PHOSTIF / HWAIT

    IOPORT_PIN_P093_PFC_04_CS0           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P09_3 / BSC / CS0
    IOPORT_PIN_P093_PFC_07_MTIOC2A       = (0x07U << IOPORT_PFC_OFFSET),                              ///< P09_3 / MTU3n / MTIOC2A
    IOPORT_PIN_P093_PFC_09_GTIOC4_3A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P09_3 / GPTn / GTIOC4_3A
    IOPORT_PIN_P093_PFC_14_ETHSW_LPI0    = (0x14U << IOPORT_PFC_OFFSET),                              ///< P09_3 / ETHER_ETHSW / ETHSW_LPI0
    IOPORT_PIN_P093_PFC_18_CTS0_RTS0_SS0 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P09_3 / SCIn / CTS0_RTS0_SS0
    IOPORT_PIN_P093_PFC_1A_RXDE6         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P09_3 / SCIEn / RXDE6
    IOPORT_PIN_P093_PFC_1B_SCKE4         = (0x1BU << IOPORT_PFC_OFFSET),                              ///< P09_3 / SCIEn / SCKE4
    IOPORT_PIN_P093_PFC_21_MCLK31        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P09_3 / DSMIFn / MCLK31
    IOPORT_PIN_P093_PFC_26_ENCIFDI6      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P09_3 / ENCIFn / ENCIFDI6
    IOPORT_PIN_P093_PFC_27_ENCIFCK4      = (0x27U << IOPORT_PFC_OFFSET),                              ///< P09_3 / ENCIFn / ENCIFCK4
    IOPORT_PIN_P093_PFC_29_HDSL6_MOSI1   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P09_3 / HDSLn / HDSL6_MOSI1
    IOPORT_PIN_P093_PFC_2C_SD0_CD        = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P09_3 / SDHIn / SD0_CD
    IOPORT_PIN_P093_PFC_2D_NAND_RY_BY0   = (0x2DU << IOPORT_PFC_OFFSET),                              ///< P09_3 / NANDC / NAND_RY_BY0
    IOPORT_PIN_P093_PFC_2E_HCS0          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P09_3 / PHOSTIF / HCS0
    IOPORT_PIN_P093_PFC_2F_ESWM_MPINT0   = (0x2FU << IOPORT_PFC_OFFSET),                              ///< P09_3 / ETHER_ESWM / ESWM_MPINT0

    IOPORT_PIN_P094_PFC_04_RD          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P09_4 / BSC / RD
    IOPORT_PIN_P094_PFC_07_MTIOC2B     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P09_4 / MTU3n / MTIOC2B
    IOPORT_PIN_P094_PFC_09_GTIOC4_3B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P09_4 / GPTn / GTIOC4_3B
    IOPORT_PIN_P094_PFC_14_ETHSW_LPI1  = (0x14U << IOPORT_PFC_OFFSET),                                ///< P09_4 / ETHER_ETHSW / ETHSW_LPI1
    IOPORT_PIN_P094_PFC_18_CTS0        = (0x18U << IOPORT_PFC_OFFSET),                                ///< P09_4 / SCIn / CTS0
    IOPORT_PIN_P094_PFC_1A_RXDE7       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P09_4 / SCIEn / RXDE7
    IOPORT_PIN_P094_PFC_1B_DEE4        = (0x1BU << IOPORT_PFC_OFFSET),                                ///< P09_4 / SCIEn / DEE4
    IOPORT_PIN_P094_PFC_21_MDAT31      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P09_4 / DSMIFn / MDAT31
    IOPORT_PIN_P094_PFC_26_ENCIFDI7    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P09_4 / ENCIFn / ENCIFDI7
    IOPORT_PIN_P094_PFC_27_ENCIFOE4    = (0x27U << IOPORT_PFC_OFFSET),                                ///< P09_4 / ENCIFn / ENCIFOE4
    IOPORT_PIN_P094_PFC_2C_SD0_WP      = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P09_4 / SDHIn / SD0_WP
    IOPORT_PIN_P094_PFC_2D_NAND_RY_BY2 = (0x2DU << IOPORT_PFC_OFFSET),                                ///< P09_4 / NANDC / NAND_RY_BY2
    IOPORT_PIN_P094_PFC_2E_HRD         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P09_4 / PHOSTIF / HRD
    IOPORT_PIN_P094_PFC_2F_ESWM_MPINT1 = (0x2FU << IOPORT_PFC_OFFSET),                                ///< P09_4 / ETHER_ESWM / ESWM_MPINT1

    IOPORT_PIN_P095_PFC_04_A1         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P09_5 / BSC / A1
    IOPORT_PIN_P095_PFC_14_ETHSW_LPI2 = (0x14U << IOPORT_PFC_OFFSET),                                 ///< P09_5 / ETHER_ETHSW / ETHSW_LPI2
    IOPORT_PIN_P095_PFC_1A_TXDE3      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P09_5 / SCIEn / TXDE3
    IOPORT_PIN_P095_PFC_1B_TXDE4      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P09_5 / SCIEn / TXDE4
    IOPORT_PIN_P095_PFC_26_ENCIFDO3   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P09_5 / ENCIFn / ENCIFDO3
    IOPORT_PIN_P095_PFC_27_ENCIFDO4   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P09_5 / ENCIFn / ENCIFDO4
    IOPORT_PIN_P095_PFC_28_DUEI2      = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P09_5 / ENDATn / DUEI2
    IOPORT_PIN_P095_PFC_2E_HA1        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P09_5 / PHOSTIF / HA1

    IOPORT_PIN_P096_PFC_04_A2             = (0x04U << IOPORT_PFC_OFFSET),                             ///< P09_6 / BSC / A2
    IOPORT_PIN_P096_PFC_14_ETHSW_TDMAOUT0 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P09_6 / ETHER_ETHSW / ETHSW_TDMAOUT0
    IOPORT_PIN_P096_PFC_18_DE0            = (0x18U << IOPORT_PFC_OFFSET),                             ///< P09_6 / SCIn / DE0
    IOPORT_PIN_P096_PFC_1A_TXDE6          = (0x1AU << IOPORT_PFC_OFFSET),                             ///< P09_6 / SCIEn / TXDE6
    IOPORT_PIN_P096_PFC_26_ENCIFDO6       = (0x26U << IOPORT_PFC_OFFSET),                             ///< P09_6 / ENCIFn / ENCIFDO6
    IOPORT_PIN_P096_PFC_28_TST_OUT2       = (0x28U << IOPORT_PFC_OFFSET),                             ///< P09_6 / ENDATn / TST_OUT2
    IOPORT_PIN_P096_PFC_2D_NAND_CE2       = (0x2DU << IOPORT_PFC_OFFSET),                             ///< P09_6 / NANDC / NAND_CE2
    IOPORT_PIN_P096_PFC_2E_HA2            = (0x2EU << IOPORT_PFC_OFFSET),                             ///< P09_6 / PHOSTIF / HA2

    IOPORT_PIN_P097_PFC_04_A3             = (0x04U << IOPORT_PFC_OFFSET),                             ///< P09_7 / BSC / A3
    IOPORT_PIN_P097_PFC_14_ETHSW_TDMAOUT1 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P09_7 / ETHER_ETHSW / ETHSW_TDMAOUT1
    IOPORT_PIN_P097_PFC_15_ESC_LINKACT2   = (0x15U << IOPORT_PFC_OFFSET),                             ///< P09_7 / ETHER_ESC / ESC_LINKACT2
    IOPORT_PIN_P097_PFC_16_ESC_LINKACT1   = (0x16U << IOPORT_PFC_OFFSET),                             ///< P09_7 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P097_PFC_1A_SCKE6          = (0x1AU << IOPORT_PFC_OFFSET),                             ///< P09_7 / SCIEn / SCKE6
    IOPORT_PIN_P097_PFC_26_ENCIFCK6       = (0x26U << IOPORT_PFC_OFFSET),                             ///< P09_7 / ENCIFn / ENCIFCK6
    IOPORT_PIN_P097_PFC_28_SI2            = (0x28U << IOPORT_PFC_OFFSET),                             ///< P09_7 / ENDATn / SI2
    IOPORT_PIN_P097_PFC_2A_POUTA          = (0x2AU << IOPORT_PFC_OFFSET),                             ///< P09_7 / ENCOUT / POUTA
    IOPORT_PIN_P097_PFC_2E_HA3            = (0x2EU << IOPORT_PFC_OFFSET),                             ///< P09_7 / PHOSTIF / HA3

    IOPORT_PIN_P100_PFC_04_A4             = (0x04U << IOPORT_PFC_OFFSET),                             ///< P10_0 / BSC / A4
    IOPORT_PIN_P100_PFC_14_ETHSW_TDMAOUT2 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P10_0 / ETHER_ETHSW / ETHSW_TDMAOUT2
    IOPORT_PIN_P100_PFC_15_ESC_IRQ        = (0x15U << IOPORT_PFC_OFFSET),                             ///< P10_0 / ETHER_ESC / ESC_IRQ
    IOPORT_PIN_P100_PFC_1A_DEE6           = (0x1AU << IOPORT_PFC_OFFSET),                             ///< P10_0 / SCIEn / DEE6
    IOPORT_PIN_P100_PFC_26_ENCIFOE6       = (0x26U << IOPORT_PFC_OFFSET),                             ///< P10_0 / ENCIFn / ENCIFOE6
    IOPORT_PIN_P100_PFC_2A_POUTB          = (0x2AU << IOPORT_PFC_OFFSET),                             ///< P10_0 / ENCOUT / POUTB
    IOPORT_PIN_P100_PFC_2D_NAND_CE3       = (0x2DU << IOPORT_PFC_OFFSET),                             ///< P10_0 / NANDC / NAND_CE3
    IOPORT_PIN_P100_PFC_2E_HA4            = (0x2EU << IOPORT_PFC_OFFSET),                             ///< P10_0 / PHOSTIF / HA4

    IOPORT_PIN_P101_PFC_04_A5             = (0x04U << IOPORT_PFC_OFFSET),                             ///< P10_1 / BSC / A5
    IOPORT_PIN_P101_PFC_14_ETHSW_TDMAOUT3 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P10_1 / ETHER_ETHSW / ETHSW_TDMAOUT3
    IOPORT_PIN_P101_PFC_15_ESC_RESETOUT   = (0x15U << IOPORT_PFC_OFFSET),                             ///< P10_1 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P101_PFC_16_ESC_LEDRUN     = (0x16U << IOPORT_PFC_OFFSET),                             ///< P10_1 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P101_PFC_2A_POUTZ          = (0x2AU << IOPORT_PFC_OFFSET),                             ///< P10_1 / ENCOUT / POUTZ
    IOPORT_PIN_P101_PFC_2E_HA5            = (0x2EU << IOPORT_PFC_OFFSET),                             ///< P10_1 / PHOSTIF / HA5

    IOPORT_PIN_P102_PFC_06_MTIOC6B   = (0x06U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / MTU3n / MTIOC6B
    IOPORT_PIN_P102_PFC_07_MTIOC1B   = (0x07U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / MTU3n / MTIOC1B
    IOPORT_PIN_P102_PFC_09_GTIOC3_0A = (0x09U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / GPTn / GTIOC3_0A
    IOPORT_PIN_P102_PFC_0A_GTIOC4_1B = (0x0AU << IOPORT_PFC_OFFSET),                                  ///< P10_2 / GPTn / GTIOC4_1B
    IOPORT_PIN_P102_PFC_18_SCK2      = (0x18U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / SCIn / SCK2
    IOPORT_PIN_P102_PFC_1C_IIC_SCL2  = (0x1CU << IOPORT_PFC_OFFSET),                                  ///< P10_2 / IICn / IIC_SCL2
    IOPORT_PIN_P102_PFC_21_MCLK22    = (0x21U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / DSMIFn / MCLK22
    IOPORT_PIN_P102_PFC_28_DUEI2     = (0x28U << IOPORT_PFC_OFFSET),                                  ///< P10_2 / ENDATn / DUEI2

    IOPORT_PIN_P103_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P10_3 / MTU3n / MTIOC6D
    IOPORT_PIN_P103_PFC_09_GTIOC3_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P10_3 / GPTn / GTIOC3_0B
    IOPORT_PIN_P103_PFC_18_RXD2_SCL2_MISO2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P10_3 / SCIn / RXD2_SCL2_MISO2
    IOPORT_PIN_P103_PFC_21_MDAT22          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P10_3 / DSMIFn / MDAT22
    IOPORT_PIN_P103_PFC_28_TST_OUT2        = (0x28U << IOPORT_PFC_OFFSET),                            ///< P10_3 / ENDATn / TST_OUT2

    IOPORT_PIN_P104_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P10_4 / MTU3n / MTIOC7A
    IOPORT_PIN_P104_PFC_09_GTIOC3_1B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P10_4 / GPTn / GTIOC3_1B
    IOPORT_PIN_P104_PFC_0A_GTIOC4_2A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P10_4 / GPTn / GTIOC4_2A
    IOPORT_PIN_P104_PFC_0D_CMTW0_TIC0      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P10_4 / CMTWn / CMTW0_TIC0
    IOPORT_PIN_P104_PFC_18_TXD2_SDA2_MOSI2 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P10_4 / SCIn / TXD2_SDA2_MOSI2
    IOPORT_PIN_P104_PFC_28_SI2             = (0x28U << IOPORT_PFC_OFFSET),                            ///< P10_4 / ENDATn / SI2

    IOPORT_PIN_P105_PFC_06_MTIOC7C       = (0x06U << IOPORT_PFC_OFFSET),                              ///< P10_5 / MTU3n / MTIOC7C
    IOPORT_PIN_P105_PFC_09_GTIOC3_1A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P10_5 / GPTn / GTIOC3_1A
    IOPORT_PIN_P105_PFC_0A_GTIOC4_2B     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P10_5 / GPTn / GTIOC4_2B
    IOPORT_PIN_P105_PFC_0D_CMTW0_TOC0    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P10_5 / CMTWn / CMTW0_TOC0
    IOPORT_PIN_P105_PFC_18_CTS2_RTS2_SS2 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P10_5 / SCIn / CTS2_RTS2_SS2
    IOPORT_PIN_P105_PFC_1C_IIC_SDA2      = (0x1CU << IOPORT_PFC_OFFSET),                              ///< P10_5 / IICn / IIC_SDA2
    IOPORT_PIN_P105_PFC_28_DUEI3         = (0x28U << IOPORT_PFC_OFFSET),                              ///< P10_5 / ENDATn / DUEI3

    IOPORT_PIN_P106_PFC_06_MTIOC7B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P10_6 / MTU3n / MTIOC7B
    IOPORT_PIN_P106_PFC_09_GTIOC3_2A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P10_6 / GPTn / GTIOC3_2A
    IOPORT_PIN_P106_PFC_0D_CMTW0_TIC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P10_6 / CMTWn / CMTW0_TIC1
    IOPORT_PIN_P106_PFC_18_CTS2       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P10_6 / SCIn / CTS2
    IOPORT_PIN_P106_PFC_1B_SCKE2      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P10_6 / SCIEn / SCKE2
    IOPORT_PIN_P106_PFC_27_ENCIFCK2   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P10_6 / ENCIFn / ENCIFCK2
    IOPORT_PIN_P106_PFC_28_TST_OUT3   = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P10_6 / ENDATn / TST_OUT3

    IOPORT_PIN_P107_PFC_06_MTIOC7D    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P10_7 / MTU3n / MTIOC7D
    IOPORT_PIN_P107_PFC_09_GTIOC3_2B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P10_7 / GPTn / GTIOC3_2B
    IOPORT_PIN_P107_PFC_0D_CMTW0_TOC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P10_7 / CMTWn / CMTW0_TOC1
    IOPORT_PIN_P107_PFC_18_DE2        = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P10_7 / SCIn / DE2
    IOPORT_PIN_P107_PFC_1B_DEE2       = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P10_7 / SCIEn / DEE2
    IOPORT_PIN_P107_PFC_27_ENCIFOE2   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P10_7 / ENCIFn / ENCIFOE2
    IOPORT_PIN_P107_PFC_28_SI3        = (0x28U << IOPORT_PFC_OFFSET),                                 ///< P10_7 / ENDATn / SI3

    IOPORT_PIN_P110_PFC_17_USB_VBUSEN = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P11_0 / USB / USB_VBUSEN
    IOPORT_PIN_P110_PFC_1B_TXDE2      = (0x1BU << IOPORT_PFC_OFFSET),                                 ///< P11_0 / SCIEn / TXDE2
    IOPORT_PIN_P110_PFC_27_ENCIFDO2   = (0x27U << IOPORT_PFC_OFFSET),                                 ///< P11_0 / ENCIFn / ENCIFDO2

    IOPORT_PIN_P111_PFC_09_GTIOC0_3A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P11_1 / GPTn / GTIOC0_3A
    IOPORT_PIN_P111_PFC_15_ESC_I2CCLK      = (0x15U << IOPORT_PFC_OFFSET),                            ///< P11_1 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P111_PFC_17_USB_OVRCUR      = (0x17U << IOPORT_PFC_OFFSET),                            ///< P11_1 / USB / USB_OVRCUR
    IOPORT_PIN_P111_PFC_18_RXD1_SCL1_MISO1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P11_1 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P111_PFC_1B_RXDE2           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P11_1 / SCIEn / RXDE2
    IOPORT_PIN_P111_PFC_1C_IIC_SCL0        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P11_1 / IICn / IIC_SCL0
    IOPORT_PIN_P111_PFC_27_ENCIFDI2        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P11_1 / ENCIFn / ENCIFDI2

    IOPORT_PIN_P112_PFC_09_GTIOC0_3B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P11_2 / GPTn / GTIOC0_3B
    IOPORT_PIN_P112_PFC_15_ESC_I2CDATA     = (0x15U << IOPORT_PFC_OFFSET),                            ///< P11_2 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P112_PFC_17_USB_EXICEN      = (0x17U << IOPORT_PFC_OFFSET),                            ///< P11_2 / USB / USB_EXICEN
    IOPORT_PIN_P112_PFC_18_TXD1_SDA1_MOSI1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P11_2 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P112_PFC_1C_IIC_SDA0        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P11_2 / IICn / IIC_SDA0

    IOPORT_PIN_P113_PFC_08_POE4            = (0x08U << IOPORT_PFC_OFFSET),                            ///< P11_3 / MTU_POE3 / POE4
    IOPORT_PIN_P113_PFC_0C_GTETRGD         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P11_3 / GPT_POEG / GTETRGD
    IOPORT_PIN_P113_PFC_18_RXD0_SCL0_MISO0 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P11_3 / SCIn / RXD0_SCL0_MISO0
    IOPORT_PIN_P113_PFC_1C_IIC_SCL0        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P11_3 / IICn / IIC_SCL0

    IOPORT_PIN_P114_PFC_0C_GTETRGSA        = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P11_4 / GPT_POEG / GTETRGSA
    IOPORT_PIN_P114_PFC_18_TXD0_SDA0_MOSI0 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P11_4 / SCIn / TXD0_SDA0_MOSI0
    IOPORT_PIN_P114_PFC_1C_IIC_SDA1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P11_4 / IICn / IIC_SDA1

    IOPORT_PIN_P115_PFC_02_CKIO        = (0x02U << IOPORT_PFC_OFFSET),                                ///< P11_5 / BSC / CKIO
    IOPORT_PIN_P115_PFC_08_POE0        = (0x08U << IOPORT_PFC_OFFSET),                                ///< P11_5 / MTU_POE3 / POE0
    IOPORT_PIN_P115_PFC_09_GTIOC5_0A   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P11_5 / GPTn / GTIOC5_0A
    IOPORT_PIN_P115_PFC_0C_GTETRGA     = (0x0CU << IOPORT_PFC_OFFSET),                                ///< P11_5 / GPT_POEG / GTETRGA
    IOPORT_PIN_P115_PFC_1A_SCIEXTCLK   = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P11_5 / CGC / SCIEXTCLK
    IOPORT_PIN_P115_PFC_1C_IIC_SCL2    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P11_5 / IICn / IIC_SCL2
    IOPORT_PIN_P115_PFC_2D_NAND_RY_BY3 = (0x2DU << IOPORT_PFC_OFFSET),                                ///< P11_5 / NANDC / NAND_RY_BY3
    IOPORT_PIN_P115_PFC_2E_HCKIO       = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P11_5 / PHOSTIF / HCKIO

    IOPORT_PIN_P116_PFC_17_USB_OVRCUR = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P11_6 / USB / USB_OVRCUR
    IOPORT_PIN_P116_PFC_1C_IIC_SDA2   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P11_6 / IICn / IIC_SDA2

    IOPORT_PIN_P117_PFC_08_POE11      = (0x08U << IOPORT_PFC_OFFSET),                                 ///< P11_7 / MTU_POE3 / POE11
    IOPORT_PIN_P117_PFC_09_GTIOC5_2A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P11_7 / GPTn / GTIOC5_2A
    IOPORT_PIN_P117_PFC_0C_GTETRGB    = (0x0CU << IOPORT_PFC_OFFSET),                                 ///< P11_7 / GPT_POEG / GTETRGB
    IOPORT_PIN_P117_PFC_0E_RTCAT1HZ   = (0x0EU << IOPORT_PFC_OFFSET),                                 ///< P11_7 / RTC / RTCAT1HZ
    IOPORT_PIN_P117_PFC_17_USB_OTG_ID = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P11_7 / USB / USB_OTG_ID
    IOPORT_PIN_P117_PFC_25_MBX_HINT   = (0x25U << IOPORT_PFC_OFFSET),                                 ///< P11_7 / MBXSEM / MBX_HINT

    IOPORT_PIN_P120_PFC_01_TMS = (0x01U << IOPORT_PFC_OFFSET),                                        ///< P12_0 / JTAG/SWD / TMS
    IOPORT_PIN_P121_PFC_01_TDI = (0x01U << IOPORT_PFC_OFFSET),                                        ///< P12_1 / JTAG/SWD / TDI
    IOPORT_PIN_P122_PFC_01_TCK = (0x01U << IOPORT_PFC_OFFSET),                                        ///< P12_2 / JTAG/SWD / TCK
    IOPORT_PIN_P123_PFC_01_TDO = (0x01U << IOPORT_PFC_OFFSET),                                        ///< P12_3 / JTAG/SWD / TDO

    IOPORT_PIN_P124_PFC_17_USB_VBUSIN = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P12_4 / USB / USB_VBUSIN

    IOPORT_PIN_P125_PFC_04_D16         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P12_5 / BSC / D16
    IOPORT_PIN_P125_PFC_05_DREQ        = (0x05U << IOPORT_PFC_OFFSET),                                ///< P12_5 / DMAC / DREQ
    IOPORT_PIN_P125_PFC_0A_GTADSM0_0   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P12_5 / GPTn / GTADSM0_0
    IOPORT_PIN_P125_PFC_0C_GTETRGB     = (0x0CU << IOPORT_PFC_OFFSET),                                ///< P12_5 / GPT_POEG / GTETRGB
    IOPORT_PIN_P125_PFC_0D_CMTW1_TIC0  = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P12_5 / CMTWn / CMTW1_TIC0
    IOPORT_PIN_P125_PFC_21_MCLK40      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P12_5 / DSMIFn / MCLK40
    IOPORT_PIN_P125_PFC_29_HDSL6_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P12_5 / HDSLn / HDSL6_MISO2
    IOPORT_PIN_P125_PFC_2E_HD16        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P12_5 / PHOSTIF / HD16

    IOPORT_PIN_P126_PFC_04_D17         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P12_6 / BSC / D17
    IOPORT_PIN_P126_PFC_05_DACK        = (0x05U << IOPORT_PFC_OFFSET),                                ///< P12_6 / DMAC / DACK
    IOPORT_PIN_P126_PFC_0A_GTADSM0_1   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P12_6 / GPTn / GTADSM0_1
    IOPORT_PIN_P126_PFC_0C_GTETRGC     = (0x0CU << IOPORT_PFC_OFFSET),                                ///< P12_6 / GPT_POEG / GTETRGC
    IOPORT_PIN_P126_PFC_0D_CMTW1_TOC0  = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P12_6 / CMTWn / CMTW1_TOC0
    IOPORT_PIN_P126_PFC_21_MDAT40      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P12_6 / DSMIFn / MDAT40
    IOPORT_PIN_P126_PFC_29_HDSL6_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P12_6 / HDSLn / HDSL6_MOSI2
    IOPORT_PIN_P126_PFC_2E_HD17        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P12_6 / PHOSTIF / HD17

    IOPORT_PIN_P127_PFC_04_D18           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P12_7 / BSC / D18
    IOPORT_PIN_P127_PFC_0A_GTADSM1_0     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P12_7 / GPTn / GTADSM1_0
    IOPORT_PIN_P127_PFC_0C_GTETRGD       = (0x0CU << IOPORT_PFC_OFFSET),                              ///< P12_7 / GPT_POEG / GTETRGD
    IOPORT_PIN_P127_PFC_0D_CMTW1_TIC1    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P12_7 / CMTWn / CMTW1_TIC1
    IOPORT_PIN_P127_PFC_14_ETHSW_PTPOUT0 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P12_7 / ETHER_ETHSW / ETHSW_PTPOUT0
    IOPORT_PIN_P127_PFC_15_ESC_SYNC0     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P12_7 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P127_PFC_21_MCLK41        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P12_7 / DSMIFn / MCLK41
    IOPORT_PIN_P127_PFC_29_HDSL7_LINK    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P12_7 / HDSLn / HDSL7_LINK
    IOPORT_PIN_P127_PFC_2E_HD18          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P12_7 / PHOSTIF / HD18

    IOPORT_PIN_P130_PFC_04_D19           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P13_0 / BSC / D19
    IOPORT_PIN_P130_PFC_0A_GTADSM1_1     = (0x0AU << IOPORT_PFC_OFFSET),                              ///< P13_0 / GPTn / GTADSM1_1
    IOPORT_PIN_P130_PFC_0D_CMTW1_TOC1    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P13_0 / CMTWn / CMTW1_TOC1
    IOPORT_PIN_P130_PFC_14_ETHSW_PTPOUT1 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P13_0 / ETHER_ETHSW / ETHSW_PTPOUT1
    IOPORT_PIN_P130_PFC_15_ESC_SYNC1     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P13_0 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P130_PFC_21_MDAT41        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P13_0 / DSMIFn / MDAT41
    IOPORT_PIN_P130_PFC_29_HDSL7_SMPL    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P13_0 / HDSLn / HDSL7_SMPL
    IOPORT_PIN_P130_PFC_2E_HD19          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P13_0 / PHOSTIF / HD19

    IOPORT_PIN_P131_PFC_04_D20        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P13_1 / BSC / D20
    IOPORT_PIN_P131_PFC_05_TEND       = (0x05U << IOPORT_PFC_OFFSET),                                 ///< P13_1 / DMAC / TEND
    IOPORT_PIN_P131_PFC_0A_GTADSM2_0  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P13_1 / GPTn / GTADSM2_0
    IOPORT_PIN_P131_PFC_15_ESC_LEDRUN = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P13_1 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P131_PFC_21_MCLK10     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P13_1 / DSMIFn / MCLK10
    IOPORT_PIN_P131_PFC_29_HDSL7_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P13_1 / HDSLn / HDSL7_CLK1
    IOPORT_PIN_P131_PFC_2C_SD1_PWEN   = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P13_1 / SDHIn / SD1_PWEN
    IOPORT_PIN_P131_PFC_2E_HD20       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P13_1 / PHOSTIF / HD20

    IOPORT_PIN_P132_PFC_04_D21        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P13_2 / BSC / D21
    IOPORT_PIN_P132_PFC_0A_GTADSM2_1  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P13_2 / GPTn / GTADSM2_1
    IOPORT_PIN_P132_PFC_15_ESC_LEDERR = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P13_2 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P132_PFC_21_MDAT10     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P13_2 / DSMIFn / MDAT10
    IOPORT_PIN_P132_PFC_29_HDSL7_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P13_2 / HDSLn / HDSL7_SEL1
    IOPORT_PIN_P132_PFC_2C_SD1_IOVS   = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P13_2 / SDHIn / SD1_IOVS
    IOPORT_PIN_P132_PFC_2E_HD21       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P13_2 / PHOSTIF / HD21

    IOPORT_PIN_P133_PFC_04_D22         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P13_3 / BSC / D22
    IOPORT_PIN_P133_PFC_0A_GTADSM3_0   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P13_3 / GPTn / GTADSM3_0
    IOPORT_PIN_P133_PFC_0F_ETH1_CRS    = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_ETHn / ETH1_CRS
    IOPORT_PIN_P133_PFC_11_GMAC0_MDC   = (0x11U << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_GMACn / GMAC0_MDC
    IOPORT_PIN_P133_PFC_12_GMAC1_MDC   = (0x12U << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P133_PFC_13_GMAC2_MDC   = (0x13U << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_GMACn / GMAC2_MDC
    IOPORT_PIN_P133_PFC_14_ETHSW_MDC   = (0x14U << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P133_PFC_15_ESC_MDC     = (0x15U << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P133_PFC_21_MCLK42      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P13_3 / DSMIFn / MCLK42
    IOPORT_PIN_P133_PFC_29_HDSL7_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P13_3 / HDSLn / HDSL7_MISO1
    IOPORT_PIN_P133_PFC_2C_SD1_PWEN    = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P13_3 / SDHIn / SD1_PWEN
    IOPORT_PIN_P133_PFC_2E_HD22        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P13_3 / PHOSTIF / HD22
    IOPORT_PIN_P133_PFC_2F_ESWM_MDC    = (0x2FU << IOPORT_PFC_OFFSET),                                ///< P13_3 / ETHER_ESWM / ESWM_MDC

    IOPORT_PIN_P134_PFC_04_D23         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P13_4 / BSC / D23
    IOPORT_PIN_P134_PFC_0A_GTADSM3_1   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P13_4 / GPTn / GTADSM3_1
    IOPORT_PIN_P134_PFC_0E_RTCAT1HZ    = (0x0EU << IOPORT_PFC_OFFSET),                                ///< P13_4 / RTC / RTCAT1HZ
    IOPORT_PIN_P134_PFC_0F_ETH1_COL    = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_ETHn / ETH1_COL
    IOPORT_PIN_P134_PFC_11_GMAC0_MDIO  = (0x11U << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_GMACn / GMAC0_MDIO
    IOPORT_PIN_P134_PFC_12_GMAC1_MDIO  = (0x12U << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P134_PFC_13_GMAC2_MDIO  = (0x13U << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_GMACn / GMAC2_MDIO
    IOPORT_PIN_P134_PFC_14_ETHSW_MDIO  = (0x14U << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P134_PFC_15_ESC_MDIO    = (0x15U << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P134_PFC_21_MDAT42      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P13_4 / DSMIFn / MDAT42
    IOPORT_PIN_P134_PFC_29_HDSL7_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P13_4 / HDSLn / HDSL7_MOSI1
    IOPORT_PIN_P134_PFC_2C_SD1_IOVS    = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P13_4 / SDHIn / SD1_IOVS
    IOPORT_PIN_P134_PFC_2E_HD23        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P13_4 / PHOSTIF / HD23
    IOPORT_PIN_P134_PFC_2F_ESWM_MDIO   = (0x2FU << IOPORT_PFC_OFFSET),                                ///< P13_4 / ETHER_ESWM / ESWM_MDIO

    IOPORT_PIN_P135_PFC_04_D24         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P13_5 / BSC / D24
    IOPORT_PIN_P135_PFC_0A_GTADSM4_0   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P13_5 / GPTn / GTADSM4_0
    IOPORT_PIN_P135_PFC_15_ESC_LEDSTER = (0x15U << IOPORT_PFC_OFFSET),                                ///< P13_5 / ETHER_ESC / ESC_LEDSTER
    IOPORT_PIN_P135_PFC_1A_SCKE7       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P13_5 / SCIEn / SCKE7
    IOPORT_PIN_P135_PFC_21_MCLK11      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P13_5 / DSMIFn / MCLK11
    IOPORT_PIN_P135_PFC_26_ENCIFCK7    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P13_5 / ENCIFn / ENCIFCK7
    IOPORT_PIN_P135_PFC_29_HDSL7_CLK2  = (0x29U << IOPORT_PFC_OFFSET),                                ///< P13_5 / HDSLn / HDSL7_CLK2
    IOPORT_PIN_P135_PFC_2E_HD24        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P13_5 / PHOSTIF / HD24

    IOPORT_PIN_P136_PFC_04_D25        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P13_6 / BSC / D25
    IOPORT_PIN_P136_PFC_0A_GTADSM4_1  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P13_6 / GPTn / GTADSM4_1
    IOPORT_PIN_P136_PFC_1A_DEE7       = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P13_6 / SCIEn / DEE7
    IOPORT_PIN_P136_PFC_21_MDAT11     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P13_6 / DSMIFn / MDAT11
    IOPORT_PIN_P136_PFC_26_ENCIFOE7   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P13_6 / ENCIFn / ENCIFOE7
    IOPORT_PIN_P136_PFC_29_HDSL7_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P13_6 / HDSLn / HDSL7_SEL2
    IOPORT_PIN_P136_PFC_2E_HD25       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P13_6 / PHOSTIF / HD25

    IOPORT_PIN_P137_PFC_04_D26         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P13_7 / BSC / D26
    IOPORT_PIN_P137_PFC_1A_TXDE7       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P13_7 / SCIEn / TXDE7
    IOPORT_PIN_P137_PFC_21_MCLK12      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P13_7 / DSMIFn / MCLK12
    IOPORT_PIN_P137_PFC_26_ENCIFDO7    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P13_7 / ENCIFn / ENCIFDO7
    IOPORT_PIN_P137_PFC_29_HDSL7_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P13_7 / HDSLn / HDSL7_MISO2
    IOPORT_PIN_P137_PFC_2E_HD26        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P13_7 / PHOSTIF / HD26

    IOPORT_PIN_P140_PFC_04_D27           = (0x04U << IOPORT_PFC_OFFSET),                              ///< P14_0 / BSC / D27
    IOPORT_PIN_P140_PFC_14_ETHSW_PTPOUT3 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P14_0 / ETHER_ETHSW / ETHSW_PTPOUT3
    IOPORT_PIN_P140_PFC_15_ESC_SYNC1     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P14_0 / ETHER_ESC / ESC_SYNC1
    IOPORT_PIN_P140_PFC_1A_RXDE7         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P14_0 / SCIEn / RXDE7
    IOPORT_PIN_P140_PFC_21_MDAT12        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P14_0 / DSMIFn / MDAT12
    IOPORT_PIN_P140_PFC_26_ENCIFDI7      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P14_0 / ENCIFn / ENCIFDI7
    IOPORT_PIN_P140_PFC_29_HDSL7_MOSI2   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P14_0 / HDSLn / HDSL7_MOSI2
    IOPORT_PIN_P140_PFC_2E_HD27          = (0x2EU << IOPORT_PFC_OFFSET),                              ///< P14_0 / PHOSTIF / HD27

    IOPORT_PIN_P141_PFC_04_D0         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / BSC / D0
    IOPORT_PIN_P141_PFC_06_MTIOC3B    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / MTU3n / MTIOC3B
    IOPORT_PIN_P141_PFC_07_MTIOC8A    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / MTU3n / MTIOC8A
    IOPORT_PIN_P141_PFC_09_GTIOC2_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / GPTn / GTIOC2_0A
    IOPORT_PIN_P141_PFC_0A_GTIOC4_6A  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P14_1 / GPTn / GTIOC4_6A
    IOPORT_PIN_P141_PFC_0B_GTIOC0_0A  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P14_1 / GPTn / GTIOC0_0A
    IOPORT_PIN_P141_PFC_0F_ETH3_TXER  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P14_1 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P141_PFC_10_ETH2_TXER  = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / ETHER_ETHn / ETH2_TXER
    IOPORT_PIN_P141_PFC_17_USB_VBUSEN = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / USB / USB_VBUSEN
    IOPORT_PIN_P141_PFC_1A_SCKE6      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P14_1 / SCIEn / SCKE6
    IOPORT_PIN_P141_PFC_26_ENCIFCK6   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / ENCIFn / ENCIFCK6
    IOPORT_PIN_P141_PFC_29_HDSL0_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P14_1 / HDSLn / HDSL0_LINK
    IOPORT_PIN_P141_PFC_2E_HD0        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P14_1 / PHOSTIF / HD0

    IOPORT_PIN_P142_PFC_04_D1          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P14_2 / BSC / D1
    IOPORT_PIN_P142_PFC_06_MTIOC3D     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P14_2 / MTU3n / MTIOC3D
    IOPORT_PIN_P142_PFC_07_MTIOC8B     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P14_2 / MTU3n / MTIOC8B
    IOPORT_PIN_P142_PFC_09_GTIOC2_0B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P14_2 / GPTn / GTIOC2_0B
    IOPORT_PIN_P142_PFC_0A_GTIOC4_6B   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P14_2 / GPTn / GTIOC4_6B
    IOPORT_PIN_P142_PFC_0B_GTIOC0_0B   = (0x0BU << IOPORT_PFC_OFFSET),                                ///< P14_2 / GPTn / GTIOC0_0B
    IOPORT_PIN_P142_PFC_0F_ETH3_RXER   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P14_2 / ETHER_ETHn / ETH3_RXER
    IOPORT_PIN_P142_PFC_10_ETH2_RXER   = (0x10U << IOPORT_PFC_OFFSET),                                ///< P14_2 / ETHER_ETHn / ETH2_RXER
    IOPORT_PIN_P142_PFC_17_USB_OVERCUR = (0x17U << IOPORT_PFC_OFFSET),                                ///< P14_2 / USB / USB_OVERCUR
    IOPORT_PIN_P142_PFC_1A_DEE6        = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P14_2 / SCIEn / DEE6
    IOPORT_PIN_P142_PFC_26_ENCIFOE6    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P14_2 / ENCIFn / ENCIFOE6
    IOPORT_PIN_P142_PFC_29_HDSL0_SMPL  = (0x29U << IOPORT_PFC_OFFSET),                                ///< P14_2 / HDSLn / HDSL0_SMPL
    IOPORT_PIN_P142_PFC_2E_HD1         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P14_2 / PHOSTIF / HD1

    IOPORT_PIN_P143_PFC_04_D2         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / BSC / D2
    IOPORT_PIN_P143_PFC_08_POE0       = (0x08U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / MTU_POE3 / POE0
    IOPORT_PIN_P143_PFC_09_GTIOC5_1A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / GPTn / GTIOC5_1A
    IOPORT_PIN_P143_PFC_0B_GTIOC0_2A  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P14_3 / GPTn / GTIOC0_2A
    IOPORT_PIN_P143_PFC_0C_GTETRGA    = (0x0CU << IOPORT_PFC_OFFSET),                                 ///< P14_3 / GPT_POEG / GTETRGA
    IOPORT_PIN_P143_PFC_0E_RTCAT1HZ   = (0x0EU << IOPORT_PFC_OFFSET),                                 ///< P14_3 / RTC / RTCAT1HZ
    IOPORT_PIN_P143_PFC_17_USB_EXICEN = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / USB / USB_EXICEN
    IOPORT_PIN_P143_PFC_1A_SCIEXTCLK  = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P14_3 / CGC / SCIEXTCLK
    IOPORT_PIN_P143_PFC_23_ADTRG0     = (0x23U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / ADCn / ADTRG0
    IOPORT_PIN_P143_PFC_25_MBX_HINT   = (0x25U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / MBXSEM / MBX_HINT
    IOPORT_PIN_P143_PFC_29_HDSL0_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P14_3 / HDSLn / HDSL0_CLK1
    IOPORT_PIN_P143_PFC_2E_HD2        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P14_3 / PHOSTIF / HD2

    IOPORT_PIN_P144_PFC_04_D3         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / BSC / D3
    IOPORT_PIN_P144_PFC_06_MTIOC4A    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / MTU3n / MTIOC4A
    IOPORT_PIN_P144_PFC_07_MTIC5U     = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / MTU3n / MTIC5U
    IOPORT_PIN_P144_PFC_09_GTIOC2_1A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / GPTn / GTIOC2_1A
    IOPORT_PIN_P144_PFC_0B_GTIOC0_1B  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P14_4 / GPTn / GTIOC0_1B
    IOPORT_PIN_P144_PFC_0F_ETH3_CRS   = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P14_4 / ETHER_ETHn / ETH3_CRS
    IOPORT_PIN_P144_PFC_10_ETH2_CRS   = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / ETHER_ETHn / ETH2_CRS
    IOPORT_PIN_P144_PFC_1A_TXDE6      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P14_4 / SCIEn / TXDE6
    IOPORT_PIN_P144_PFC_23_ADTRG1     = (0x23U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / ADCn / ADTRG1
    IOPORT_PIN_P144_PFC_26_ENCIFDO6   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / ENCIFn / ENCIFDO6
    IOPORT_PIN_P144_PFC_29_HDSL0_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P14_4 / HDSLn / HDSL0_SEL1
    IOPORT_PIN_P144_PFC_2E_HD3        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P14_4 / PHOSTIF / HD3

    IOPORT_PIN_P145_PFC_04_D4          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P14_5 / BSC / D4
    IOPORT_PIN_P145_PFC_06_MTIOC4C     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P14_5 / MTU3n / MTIOC4C
    IOPORT_PIN_P145_PFC_07_MTIC5V      = (0x07U << IOPORT_PFC_OFFSET),                                ///< P14_5 / MTU3n / MTIC5V
    IOPORT_PIN_P145_PFC_09_GTIOC2_1B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P14_5 / GPTn / GTIOC2_1B
    IOPORT_PIN_P145_PFC_0B_GTIOC0_1A   = (0x0BU << IOPORT_PFC_OFFSET),                                ///< P14_5 / GPTn / GTIOC0_1A
    IOPORT_PIN_P145_PFC_0F_ETH3_COL    = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P14_5 / ETHER_ETHn / ETH3_COL
    IOPORT_PIN_P145_PFC_10_ETH2_COL    = (0x10U << IOPORT_PFC_OFFSET),                                ///< P14_5 / ETHER_ETHn / ETH2_COL
    IOPORT_PIN_P145_PFC_1A_RXDE6       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P14_5 / SCIEn / RXDE6
    IOPORT_PIN_P145_PFC_23_ADTRG2      = (0x23U << IOPORT_PFC_OFFSET),                                ///< P14_5 / ADCn / ADTRG2
    IOPORT_PIN_P145_PFC_26_ENCIFDI6    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P14_5 / ENCIFn / ENCIFDI6
    IOPORT_PIN_P145_PFC_29_HDSL0_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P14_5 / HDSLn / HDSL0_MISO1
    IOPORT_PIN_P145_PFC_2E_HD4         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P14_5 / PHOSTIF / HD4

    IOPORT_PIN_P146_PFC_04_D5          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P14_6 / BSC / D5
    IOPORT_PIN_P146_PFC_06_MTIOC4B     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P14_6 / MTU3n / MTIOC4B
    IOPORT_PIN_P146_PFC_07_MTIOC1B     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P14_6 / MTU3n / MTIOC1B
    IOPORT_PIN_P146_PFC_09_GTIOC2_2A   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P14_6 / GPTn / GTIOC2_2A
    IOPORT_PIN_P146_PFC_0D_CMTW0_TIC0  = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P14_6 / CMTWn / CMTW0_TIC0
    IOPORT_PIN_P146_PFC_29_HDSL0_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P14_6 / HDSLn / HDSL0_MOSI1
    IOPORT_PIN_P146_PFC_2A_POUTA       = (0x2AU << IOPORT_PFC_OFFSET),                                ///< P14_6 / ENCOUT / POUTA
    IOPORT_PIN_P146_PFC_2C_SD0_PWEN    = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P14_6 / SDHIn / SD0_PWEN
    IOPORT_PIN_P146_PFC_2E_HD5         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P14_6 / PHOSTIF / HD5

    IOPORT_PIN_P147_PFC_04_D6         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P14_7 / BSC / D6
    IOPORT_PIN_P147_PFC_06_MTIOC4D    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P14_7 / MTU3n / MTIOC4D
    IOPORT_PIN_P147_PFC_07_MTIOC1A    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P14_7 / MTU3n / MTIOC1A
    IOPORT_PIN_P147_PFC_09_GTIOC2_2B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P14_7 / GPTn / GTIOC2_2B
    IOPORT_PIN_P147_PFC_0D_CMTW0_TOC0 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P14_7 / CMTWn / CMTW0_TOC0
    IOPORT_PIN_P147_PFC_29_HDSL0_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P14_7 / HDSLn / HDSL0_CLK2
    IOPORT_PIN_P147_PFC_2A_POUTB      = (0x2AU << IOPORT_PFC_OFFSET),                                 ///< P14_7 / ENCOUT / POUTB
    IOPORT_PIN_P147_PFC_2C_SD0_IOVS   = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P14_7 / SDHIn / SD0_IOVS
    IOPORT_PIN_P147_PFC_2E_HD6        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P14_7 / PHOSTIF / HD6

    IOPORT_PIN_P150_PFC_04_D7         = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / BSC / D7
    IOPORT_PIN_P150_PFC_06_MTCLKA     = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / MTU3 / MTCLKA
    IOPORT_PIN_P150_PFC_07_MTIOC8C    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / MTU3n / MTIOC8C
    IOPORT_PIN_P150_PFC_09_GTIOC2_3A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / GPTn / GTIOC2_3A
    IOPORT_PIN_P150_PFC_0D_CMTW0_TIC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P15_0 / CMTWn / CMTW0_TIC1
    IOPORT_PIN_P150_PFC_1A_SCKE2      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P15_0 / SCIEn / SCKE2
    IOPORT_PIN_P150_PFC_26_ENCIFCK2   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / ENCIFn / ENCIFCK2
    IOPORT_PIN_P150_PFC_29_HDSL0_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P15_0 / HDSLn / HDSL0_SEL2
    IOPORT_PIN_P150_PFC_2A_POUTZ      = (0x2AU << IOPORT_PFC_OFFSET),                                 ///< P15_0 / ENCOUT / POUTZ
    IOPORT_PIN_P150_PFC_2C_SD1_CD     = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P15_0 / SDHIn / SD1_CD
    IOPORT_PIN_P150_PFC_2E_HD7        = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P15_0 / PHOSTIF / HD7

    IOPORT_PIN_P151_PFC_04_D8          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P15_1 / BSC / D8
    IOPORT_PIN_P151_PFC_06_MTCLKB      = (0x06U << IOPORT_PFC_OFFSET),                                ///< P15_1 / MTU3 / MTCLKB
    IOPORT_PIN_P151_PFC_07_MTIOC8D     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P15_1 / MTU3n / MTIOC8D
    IOPORT_PIN_P151_PFC_09_GTIOC2_3B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P15_1 / GPTn / GTIOC2_3B
    IOPORT_PIN_P151_PFC_0D_CMTW0_TOC1  = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P15_1 / CMTWn / CMTW0_TOC1
    IOPORT_PIN_P151_PFC_1A_DEE2        = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P15_1 / SCIEn / DEE2
    IOPORT_PIN_P151_PFC_26_ENCIFOE2    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P15_1 / ENCIFn / ENCIFOE2
    IOPORT_PIN_P151_PFC_29_HDSL0_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P15_1 / HDSLn / HDSL0_MISO2
    IOPORT_PIN_P151_PFC_2C_SD1_WP      = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P15_1 / SDHIn / SD1_WP
    IOPORT_PIN_P151_PFC_2E_HD8         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P15_1 / PHOSTIF / HD8

    IOPORT_PIN_P152_PFC_04_D9          = (0x04U << IOPORT_PFC_OFFSET),                                ///< P15_2 / BSC / D9
    IOPORT_PIN_P152_PFC_06_MTIOC3A     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P15_2 / MTU3n / MTIOC3A
    IOPORT_PIN_P152_PFC_07_MTIC5W      = (0x07U << IOPORT_PFC_OFFSET),                                ///< P15_2 / MTU3n / MTIC5W
    IOPORT_PIN_P152_PFC_09_GTIOC2_4A   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P15_2 / GPTn / GTIOC2_4A
    IOPORT_PIN_P152_PFC_0D_CMTW1_TIOC0 = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P15_2 / CMTWn / CMTW1_TIOC0
    IOPORT_PIN_P152_PFC_1A_TXDE2       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P15_2 / SCIEn / TXDE2
    IOPORT_PIN_P152_PFC_26_ENCIFDO2    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P15_2 / ENCIFn / ENCIFDO2
    IOPORT_PIN_P152_PFC_29_HDSL0_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P15_2 / HDSLn / HDSL0_MOSI2
    IOPORT_PIN_P152_PFC_2C_SD1_PWEN    = (0x2CU << IOPORT_PFC_OFFSET),                                ///< P15_2 / SDHIn / SD1_PWEN
    IOPORT_PIN_P152_PFC_2E_HD9         = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P15_2 / PHOSTIF / HD9

    IOPORT_PIN_P153_PFC_04_D10        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / BSC / D10
    IOPORT_PIN_P153_PFC_06_MTIOC3C    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / MTU3n / MTIOC3C
    IOPORT_PIN_P153_PFC_07_MTIOC1A    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / MTU3n / MTIOC1A
    IOPORT_PIN_P153_PFC_09_GTIOC2_4B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / GPTn / GTIOC2_4B
    IOPORT_PIN_P153_PFC_0D_CMTW1_TOC0 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P15_3 / CMTWn / CMTW1_TOC0
    IOPORT_PIN_P153_PFC_1A_RXDE2      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P15_3 / SCIEn / RXDE2
    IOPORT_PIN_P153_PFC_23_ADTRG0     = (0x23U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / ADCn / ADTRG0
    IOPORT_PIN_P153_PFC_26_ENCIFDI2   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / ENCIFn / ENCIFDI2
    IOPORT_PIN_P153_PFC_29_HDSL1_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P15_3 / HDSLn / HDSL1_LINK
    IOPORT_PIN_P153_PFC_2C_SD1_IOVS   = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P15_3 / SDHIn / SD1_IOVS
    IOPORT_PIN_P153_PFC_2E_HD10       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P15_3 / PHOSTIF / HD10

    IOPORT_PIN_P154_PFC_04_D11        = (0x04U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / BSC / D11
    IOPORT_PIN_P154_PFC_09_GTIOC2_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / GPTn / GTIOC2_0A
    IOPORT_PIN_P154_PFC_0D_CMTW1_TIC1 = (0x0DU << IOPORT_PFC_OFFSET),                                 ///< P15_4 / CMTWn / CMTW1_TIC1
    IOPORT_PIN_P154_PFC_15_ESC_I2CCLK = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P154_PFC_1A_SCKE6      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P15_4 / SCIEn / SCKE6
    IOPORT_PIN_P154_PFC_1C_IIC_SCL0   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P15_4 / IICn / IIC_SCL0
    IOPORT_PIN_P154_PFC_21_MCLK20     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / DSMIFn / MCLK20
    IOPORT_PIN_P154_PFC_23_ADTRG1     = (0x23U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / ADCn / ADTRG1
    IOPORT_PIN_P154_PFC_26_ENCIFCK6   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / ENCIFn / ENCIFCK6
    IOPORT_PIN_P154_PFC_29_HDSL1_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P15_4 / HDSLn / HDSL1_SMPL
    IOPORT_PIN_P154_PFC_2E_HD11       = (0x2EU << IOPORT_PFC_OFFSET),                                 ///< P15_4 / PHOSTIF / HD11

    IOPORT_PIN_P155_PFC_04_D12         = (0x04U << IOPORT_PFC_OFFSET),                                ///< P15_5 / BSC / D12
    IOPORT_PIN_P155_PFC_09_GTIOC2_0B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P15_5 / GPTn / GTIOC2_0B
    IOPORT_PIN_P155_PFC_0D_CMTW1_TOC1  = (0x0DU << IOPORT_PFC_OFFSET),                                ///< P15_5 / CMTWn / CMTW1_TOC1
    IOPORT_PIN_P155_PFC_0E_RTCAT1HZ    = (0x0EU << IOPORT_PFC_OFFSET),                                ///< P15_5 / RTC / RTCAT1HZ
    IOPORT_PIN_P155_PFC_15_ESC_I2CDATA = (0x15U << IOPORT_PFC_OFFSET),                                ///< P15_5 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P155_PFC_1A_DEE6        = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P15_5 / SCIEn / DEE6
    IOPORT_PIN_P155_PFC_1C_IIC_SDA0    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P15_5 / IICn / IIC_SDA0
    IOPORT_PIN_P155_PFC_21_MDAT20      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P15_5 / DSMIFn / MDAT20
    IOPORT_PIN_P155_PFC_23_ADTRG2      = (0x23U << IOPORT_PFC_OFFSET),                                ///< P15_5 / ADCn / ADTRG2
    IOPORT_PIN_P155_PFC_26_ENCIFOE6    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P15_5 / ENCIFn / ENCIFOE6
    IOPORT_PIN_P155_PFC_29_HDSL1_CLK1  = (0x29U << IOPORT_PFC_OFFSET),                                ///< P15_5 / HDSLn / HDSL1_CLK1
    IOPORT_PIN_P155_PFC_2E_HD12        = (0x2EU << IOPORT_PFC_OFFSET),                                ///< P15_5 / PHOSTIF / HD12

    IOPORT_PIN_P156_PFC_0B_GTIOC0_4A       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P15_6 / GPTn / GTIOC0_4A
    IOPORT_PIN_P156_PFC_18_DE1             = (0x18U << IOPORT_PFC_OFFSET),                            ///< P15_6 / SCIn / DE1
    IOPORT_PIN_P156_PFC_1A_TXDE6           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P15_6 / SCIEn / TXDE6
    IOPORT_PIN_P156_PFC_1B_TXDE7           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P15_6 / SCIEn / TXDE7
    IOPORT_PIN_P156_PFC_1C_IIC_SCL1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P15_6 / IICn / IIC_SCL1
    IOPORT_PIN_P156_PFC_20_XSPI1_CKP       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P15_6 / XSPIn / XSPI1_CKP
    IOPORT_PIN_P156_PFC_21_MCLK21          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P15_6 / DSMIFn / MCLK21
    IOPORT_PIN_P156_PFC_26_ENCIFDO6        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P15_6 / ENCIFn / ENCIFDO6
    IOPORT_PIN_P156_PFC_27_ENCIFDO7        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P15_6 / ENCIFn / ENCIFDO7
    IOPORT_PIN_P156_PFC_29_HDSL1_SEL1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P15_6 / HDSLn / HDSL1_SEL1
    IOPORT_PIN_P156_PFC_2F_ESWM_TASGATE0_0 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P15_6 / ETHER_ESWM / ESWM_TASGATE0_0

    IOPORT_PIN_P157_PFC_0B_GTIOC0_4B       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P15_7 / GPTn / GTIOC0_4B
    IOPORT_PIN_P157_PFC_18_DE3             = (0x18U << IOPORT_PFC_OFFSET),                            ///< P15_7 / SCIn / DE3
    IOPORT_PIN_P157_PFC_1A_RXDE6           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P15_7 / SCIEn / RXDE6
    IOPORT_PIN_P157_PFC_1B_RXDE7           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P15_7 / SCIEn / RXDE7
    IOPORT_PIN_P157_PFC_1C_IIC_SDA1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P15_7 / IICn / IIC_SDA1
    IOPORT_PIN_P157_PFC_20_XSPI1_CS0       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P15_7 / XSPIn / XSPI1_CS0
    IOPORT_PIN_P157_PFC_21_MDAT21          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P15_7 / DSMIFn / MDAT21
    IOPORT_PIN_P157_PFC_26_ENCIFDI6        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P15_7 / ENCIFn / ENCIFDI6
    IOPORT_PIN_P157_PFC_27_ENCIFDI7        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P15_7 / ENCIFn / ENCIFDI7
    IOPORT_PIN_P157_PFC_29_HDSL1_MISO1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P15_7 / HDSLn / HDSL1_MISO1
    IOPORT_PIN_P157_PFC_2F_ESWM_TASGATE0_1 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P15_7 / ETHER_ESWM / ESWM_TASGATE0_1

    IOPORT_PIN_P160_PFC_06_MTIOC6B         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_0 / MTU3n / MTIOC6B
    IOPORT_PIN_P160_PFC_07_MTIOC1B         = (0x07U << IOPORT_PFC_OFFSET),                            ///< P16_0 / MTU3n / MTIOC1B
    IOPORT_PIN_P160_PFC_09_GTIOC3_0A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_0 / GPTn / GTIOC3_0A
    IOPORT_PIN_P160_PFC_0A_GTIOC4_0A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_0 / GPTn / GTIOC4_0A
    IOPORT_PIN_P160_PFC_18_RXD1_SCL1_MISO1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_0 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P160_PFC_1B_TXDE1           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_0 / SCIEn / TXDE1
    IOPORT_PIN_P160_PFC_1C_IIC_SCL2        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P16_0 / IICn / IIC_SCL2
    IOPORT_PIN_P160_PFC_20_XSPI1_CS1       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_0 / XSPIn / XSPI1_CS1
    IOPORT_PIN_P160_PFC_21_MCLK22          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P16_0 / DSMIFn / MCLK22
    IOPORT_PIN_P160_PFC_27_ENCIFDO1        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_0 / ENCIFn / ENCIFDO1
    IOPORT_PIN_P160_PFC_29_HDSL1_MOSI1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_0 / HDSLn / HDSL1_MOSI1
    IOPORT_PIN_P160_PFC_2F_ESWM_TASGATE0_2 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P16_0 / ETHER_ESWM / ESWM_TASGATE0_2

    IOPORT_PIN_P161_PFC_06_MTIOC6D         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_1 / MTU3n / MTIOC6D
    IOPORT_PIN_P161_PFC_09_GTIOC3_0B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_1 / GPTn / GTIOC3_0B
    IOPORT_PIN_P161_PFC_0A_GTIOC4_0B       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_1 / GPTn / GTIOC4_0B
    IOPORT_PIN_P161_PFC_18_TXD1_SDA1_MOSI1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_1 / SCIn / TXD1_SDA1_MOSI1
    IOPORT_PIN_P161_PFC_1B_RXDE1           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_1 / SCIEn / RXDE1
    IOPORT_PIN_P161_PFC_1C_IIC_SDA2        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P16_1 / IICn / IIC_SDA2
    IOPORT_PIN_P161_PFC_20_XSPI1_DS        = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_1 / XSPIn / XSPI1_DS
    IOPORT_PIN_P161_PFC_21_MDAT22          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P16_1 / DSMIFn / MDAT22
    IOPORT_PIN_P161_PFC_27_ENCIFDI1        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_1 / ENCIFn / ENCIFDI1
    IOPORT_PIN_P161_PFC_29_HDSL1_CLK2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_1 / HDSLn / HDSL1_CLK2
    IOPORT_PIN_P161_PFC_2F_ESWM_TASGATE0_3 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P16_1 / ETHER_ESWM / ESWM_TASGATE0_3

    IOPORT_PIN_P162_PFC_06_MTIOC7A         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_2 / MTU3n / MTIOC7A
    IOPORT_PIN_P162_PFC_09_GTIOC3_1B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_2 / GPTn / GTIOC3_1B
    IOPORT_PIN_P162_PFC_0A_GTIOC4_1A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_2 / GPTn / GTIOC4_1A
    IOPORT_PIN_P162_PFC_10_ETH4_TXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P16_2 / ETHER_ETHn / ETH4_TXER
    IOPORT_PIN_P162_PFC_18_RXD5_SCL5_MISO5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_2 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P162_PFC_1B_RXDE4           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_2 / SCIEn / RXDE4
    IOPORT_PIN_P162_PFC_1E_SPI_SSL01       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P16_2 / SPIn / SPI_SSL01
    IOPORT_PIN_P162_PFC_20_XSPI1_IO0       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_2 / XSPIn / XSPI1_IO0
    IOPORT_PIN_P162_PFC_27_ENCIFDI4        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_2 / ENCIFn / ENCIFDI4
    IOPORT_PIN_P162_PFC_29_HDSL1_SEL2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_2 / HDSLn / HDSL1_SEL2

    IOPORT_PIN_P163_PFC_06_MTIOC7C         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_3 / MTU3n / MTIOC7C
    IOPORT_PIN_P163_PFC_09_GTIOC3_1A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_3 / GPTn / GTIOC3_1A
    IOPORT_PIN_P163_PFC_0A_GTIOC4_1B       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_3 / GPTn / GTIOC4_1B
    IOPORT_PIN_P163_PFC_10_ETH4_RXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P16_3 / ETHER_ETHn / ETH4_RXER
    IOPORT_PIN_P163_PFC_18_TXD5_SDA5_MOSI5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_3 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P163_PFC_1B_TXDE4           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_3 / SCIEn / TXDE4
    IOPORT_PIN_P163_PFC_1E_SPI_SSL02       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P16_3 / SPIn / SPI_SSL02
    IOPORT_PIN_P163_PFC_20_XSPI1_IO1       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_3 / XSPIn / XSPI1_IO1
    IOPORT_PIN_P163_PFC_27_ENCIFDO4        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_3 / ENCIFn / ENCIFDO4
    IOPORT_PIN_P163_PFC_29_HDSL1_MISO2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_3 / HDSLn / HDSL1_MISO2

    IOPORT_PIN_P164_PFC_06_MTIOC7B         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_4 / MTU3n / MTIOC7B
    IOPORT_PIN_P164_PFC_09_GTIOC3_2A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_4 / GPTn / GTIOC3_2A
    IOPORT_PIN_P164_PFC_0A_GTIOC4_2A       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_4 / GPTn / GTIOC4_2A
    IOPORT_PIN_P164_PFC_10_ETH4_CRS        = (0x10U << IOPORT_PFC_OFFSET),                            ///< P16_4 / ETHER_ETHn / ETH4_CRS
    IOPORT_PIN_P164_PFC_18_RXD3_SCL3_MISO3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_4 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P164_PFC_1B_SCKE7           = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_4 / SCIEn / SCKE7
    IOPORT_PIN_P164_PFC_1E_SPI_MISO0       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P16_4 / SPIn / SPI_MISO0
    IOPORT_PIN_P164_PFC_20_XSPI1_IO2       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_4 / XSPIn / XSPI1_IO2
    IOPORT_PIN_P164_PFC_21_MCLK01          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P16_4 / DSMIFn / MCLK01
    IOPORT_PIN_P164_PFC_27_ENCIFCK7        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_4 / ENCIFn / ENCIFCK7
    IOPORT_PIN_P164_PFC_29_HDSL1_MOSI2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_4 / HDSLn / HDSL1_MOSI2

    IOPORT_PIN_P165_PFC_06_MTIOC7D         = (0x06U << IOPORT_PFC_OFFSET),                            ///< P16_5 / MTU3n / MTIOC7D
    IOPORT_PIN_P165_PFC_09_GTIOC3_2B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P16_5 / GPTn / GTIOC3_2B
    IOPORT_PIN_P165_PFC_0A_GTIOC4_2B       = (0x0AU << IOPORT_PFC_OFFSET),                            ///< P16_5 / GPTn / GTIOC4_2B
    IOPORT_PIN_P165_PFC_10_ETH4_COL        = (0x10U << IOPORT_PFC_OFFSET),                            ///< P16_5 / ETHER_ETHn / ETH4_COL
    IOPORT_PIN_P165_PFC_18_TXD3_SDA3_MOSI3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P16_5 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P165_PFC_1B_DEE7            = (0x1BU << IOPORT_PFC_OFFSET),                            ///< P16_5 / SCIEn / DEE7
    IOPORT_PIN_P165_PFC_1E_SPI_MOSI0       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P16_5 / SPIn / SPI_MOSI0
    IOPORT_PIN_P165_PFC_20_XSPI1_IO3       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P16_5 / XSPIn / XSPI1_IO3
    IOPORT_PIN_P165_PFC_21_MDAT01          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P16_5 / DSMIFn / MDAT01
    IOPORT_PIN_P165_PFC_27_ENCIFDO7        = (0x27U << IOPORT_PFC_OFFSET),                            ///< P16_5 / ENCIFn / ENCIFDO7
    IOPORT_PIN_P165_PFC_29_HDSL2_LINK      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P16_5 / HDSLn / HDSL2_LINK

    IOPORT_PIN_P166_PFC_06_MTCLKC     = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / MTU3 / MTCLKC
    IOPORT_PIN_P166_PFC_07_MTIOC0C    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / MTU3n / MTIOC0C
    IOPORT_PIN_P166_PFC_09_GTIOC3_3A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / GPTn / GTIOC3_3A
    IOPORT_PIN_P166_PFC_0F_ETH3_TXER  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P16_6 / ETHER_ETHn / ETH3_TXER
    IOPORT_PIN_P166_PFC_10_ETH2_TXER  = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / ETHER_ETHn / ETH2_TXER
    IOPORT_PIN_P166_PFC_1A_SCKE3      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P16_6 / SCIEn / SCKE3
    IOPORT_PIN_P166_PFC_1C_IIC_SCL0   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P16_6 / IICn / IIC_SCL0
    IOPORT_PIN_P166_PFC_1D_CANRXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P16_6 / CANFDn / CANRXDP0
    IOPORT_PIN_P166_PFC_1E_SPI_RSPCK0 = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P16_6 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P166_PFC_20_XSPI1_IO4  = (0x20U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / XSPIn / XSPI1_IO4
    IOPORT_PIN_P166_PFC_22_MCLK30     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / DSMIFn / MCLK30
    IOPORT_PIN_P166_PFC_26_ENCIFCK3   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / ENCIFn / ENCIFCK3
    IOPORT_PIN_P166_PFC_29_HDSL2_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P16_6 / HDSLn / HDSL2_SMPL

    IOPORT_PIN_P167_PFC_06_MTCLKD     = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / MTU3 / MTCLKD
    IOPORT_PIN_P167_PFC_07_MTIOC0D    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / MTU3n / MTIOC0D
    IOPORT_PIN_P167_PFC_09_GTIOC3_3B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / GPTn / GTIOC3_3B
    IOPORT_PIN_P167_PFC_0F_ETH3_RXER  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P16_7 / ETHER_ETHn / ETH3_RXER
    IOPORT_PIN_P167_PFC_10_ETH2_RXER  = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / ETHER_ETHn / ETH2_RXER
    IOPORT_PIN_P167_PFC_1A_DEE3       = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P16_7 / SCIEn / DEE3
    IOPORT_PIN_P167_PFC_1C_IIC_SDA0   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P16_7 / IICn / IIC_SDA0
    IOPORT_PIN_P167_PFC_1D_CANTXDP0   = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P16_7 / CANFDn / CANTXDP0
    IOPORT_PIN_P167_PFC_1E_SPI_SSL00  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P16_7 / SPIn / SPI_SSL00
    IOPORT_PIN_P167_PFC_20_XSPI1_IO5  = (0x20U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / XSPIn / XSPI1_IO5
    IOPORT_PIN_P167_PFC_22_MDAT30     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / DSMIFn / MDAT30
    IOPORT_PIN_P167_PFC_26_ENCIFOE3   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / ENCIFn / ENCIFOE3
    IOPORT_PIN_P167_PFC_29_HDSL2_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P16_7 / HDSLn / HDSL2_CLK1

    IOPORT_PIN_P170_PFC_06_MTIOC6A    = (0x06U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / MTU3n / MTIOC6A
    IOPORT_PIN_P170_PFC_07_MTIOC0A    = (0x07U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / MTU3n / MTIOC0A
    IOPORT_PIN_P170_PFC_09_GTIOC3_4A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / GPTn / GTIOC3_4A
    IOPORT_PIN_P170_PFC_0F_ETH3_CRS   = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P17_0 / ETHER_ETHn / ETH3_CRS
    IOPORT_PIN_P170_PFC_10_ETH2_CRS   = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / ETHER_ETHn / ETH2_CRS
    IOPORT_PIN_P170_PFC_17_USB_VBUSEN = (0x17U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / USB / USB_VBUSEN
    IOPORT_PIN_P170_PFC_1A_TXDE3      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P17_0 / SCIEn / TXDE3
    IOPORT_PIN_P170_PFC_1C_IIC_SCL1   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P17_0 / IICn / IIC_SCL1
    IOPORT_PIN_P170_PFC_1D_CANRX0     = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P17_0 / CANFDn / CANRX0
    IOPORT_PIN_P170_PFC_20_XSPI1_IO6  = (0x20U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / XSPIn / XSPI1_IO6
    IOPORT_PIN_P170_PFC_22_MCLK31     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / DSMIFn / MCLK31
    IOPORT_PIN_P170_PFC_26_ENCIFDO3   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / ENCIFn / ENCIFDO3
    IOPORT_PIN_P170_PFC_29_HDSL2_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P17_0 / HDSLn / HDSL2_SEL1

    IOPORT_PIN_P171_PFC_06_MTIOC6C     = (0x06U << IOPORT_PFC_OFFSET),                                ///< P17_1 / MTU3n / MTIOC6C
    IOPORT_PIN_P171_PFC_07_MTIOC0B     = (0x07U << IOPORT_PFC_OFFSET),                                ///< P17_1 / MTU3n / MTIOC0B
    IOPORT_PIN_P171_PFC_09_GTIOC3_4B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P17_1 / GPTn / GTIOC3_4B
    IOPORT_PIN_P171_PFC_0F_ETH3_COL    = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P17_1 / ETHER_ETHn / ETH3_COL
    IOPORT_PIN_P171_PFC_10_ETH2_COL    = (0x10U << IOPORT_PFC_OFFSET),                                ///< P17_1 / ETHER_ETHn / ETH2_COL
    IOPORT_PIN_P171_PFC_1A_RXDE3       = (0x1AU << IOPORT_PFC_OFFSET),                                ///< P17_1 / SCIEn / RXDE3
    IOPORT_PIN_P171_PFC_1C_IIC_SDA1    = (0x1CU << IOPORT_PFC_OFFSET),                                ///< P17_1 / IICn / IIC_SDA1
    IOPORT_PIN_P171_PFC_1D_CANTX0      = (0x1DU << IOPORT_PFC_OFFSET),                                ///< P17_1 / CANFDn / CANTX0
    IOPORT_PIN_P171_PFC_20_XSPI1_IO7   = (0x20U << IOPORT_PFC_OFFSET),                                ///< P17_1 / XSPIn / XSPI1_IO7
    IOPORT_PIN_P171_PFC_22_MDAT31      = (0x22U << IOPORT_PFC_OFFSET),                                ///< P17_1 / DSMIFn / MDAT31
    IOPORT_PIN_P171_PFC_25_MBX_HINT    = (0x25U << IOPORT_PFC_OFFSET),                                ///< P17_1 / MBXSEM / MBX_HINT
    IOPORT_PIN_P171_PFC_26_ENCIFDI3    = (0x26U << IOPORT_PFC_OFFSET),                                ///< P17_1 / ENCIFn / ENCIFDI3
    IOPORT_PIN_P171_PFC_29_HDSL2_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P17_1 / HDSLn / HDSL2_MISO1

    IOPORT_PIN_P172_PFC_1A_SCKE7           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P17_2 / SCIEn / SCKE7
    IOPORT_PIN_P172_PFC_20_XSPI0_CKP       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_2 / XSPIn / XSPI0_CKP
    IOPORT_PIN_P172_PFC_21_MCLK30          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P17_2 / DSMIFn / MCLK30
    IOPORT_PIN_P172_PFC_26_ENCIFCK7        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P17_2 / ENCIFn / ENCIFCK7
    IOPORT_PIN_P172_PFC_29_HDSL2_MOSI1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_2 / HDSLn / HDSL2_MOSI1
    IOPORT_PIN_P172_PFC_2F_ESWM_TASGATE0_4 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_2 / ETHER_ESWM / ESWM_TASGATE0_4

    IOPORT_PIN_P173_PFC_1A_DEE7            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P17_3 / SCIEn / DEE7
    IOPORT_PIN_P173_PFC_20_XSPI0_CKN       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_3 / XSPIn / XSPI0_CKN
    IOPORT_PIN_P173_PFC_21_MDAT30          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P17_3 / DSMIFn / MDAT30
    IOPORT_PIN_P173_PFC_26_ENCIFOE7        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P17_3 / ENCIFn / ENCIFOE7
    IOPORT_PIN_P173_PFC_29_HDSL2_CLK2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_3 / HDSLn / HDSL2_CLK2
    IOPORT_PIN_P173_PFC_2F_ESWM_TASGATE0_5 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_3 / ETHER_ESWM / ESWM_TASGATE0_5

    IOPORT_PIN_P174_PFC_1A_TXDE7           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P17_4 / SCIEn / TXDE7
    IOPORT_PIN_P174_PFC_20_XSPI0_CS0       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_4 / XSPIn / XSPI0_CS0
    IOPORT_PIN_P174_PFC_21_MCLK31          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P17_4 / DSMIFn / MCLK31
    IOPORT_PIN_P174_PFC_26_ENCIFDO7        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P17_4 / ENCIFn / ENCIFDO7
    IOPORT_PIN_P174_PFC_29_HDSL2_SEL2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_4 / HDSLn / HDSL2_SEL2
    IOPORT_PIN_P174_PFC_2F_ESWM_TASGATE0_6 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_4 / ETHER_ESWM / ESWM_TASGATE0_6

    IOPORT_PIN_P175_PFC_1A_RXDE7           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P17_5 / SCIEn / RXDE7
    IOPORT_PIN_P175_PFC_20_XSPI0_CS1       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_5 / XSPIn / XSPI0_CS1
    IOPORT_PIN_P175_PFC_21_MDAT31          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P17_5 / DSMIFn / MDAT31
    IOPORT_PIN_P175_PFC_26_ENCIFDI7        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P17_5 / ENCIFn / ENCIFDI7
    IOPORT_PIN_P175_PFC_29_HDSL2_MISO2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_5 / HDSLn / HDSL2_MISO2
    IOPORT_PIN_P175_PFC_2F_ESWM_TASGATE0_7 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_5 / ETHER_ESWM / ESWM_TASGATE0_7

    IOPORT_PIN_P176_PFC_20_XSPI0_DS        = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_6 / XSPIn / XSPI0_DS
    IOPORT_PIN_P176_PFC_22_MCLK20          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P17_6 / DSMIFn / MCLK20
    IOPORT_PIN_P176_PFC_29_HDSL2_MOSI2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_6 / HDSLn / HDSL2_MOSI2
    IOPORT_PIN_P176_PFC_2F_ESWM_TASGATE0_8 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_6 / ETHER_ESWM / ESWM_TASGATE0_8

    IOPORT_PIN_P177_PFC_20_XSPI0_IO0       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P17_7 / XSPIn / XSPI0_IO0
    IOPORT_PIN_P177_PFC_22_MDAT20          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P17_7 / DSMIFn / MDAT20
    IOPORT_PIN_P177_PFC_29_HDSL3_LINK      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P17_7 / HDSLn / HDSL3_LINK
    IOPORT_PIN_P177_PFC_2F_ESWM_TASGATE1_0 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P17_7 / ETHER_ESWM / ESWM_TASGATE1_0

    IOPORT_PIN_P180_PFC_20_XSPI0_IO1       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_0 / XSPIn / XSPI0_IO1
    IOPORT_PIN_P180_PFC_22_MCLK02          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P18_0 / DSMIFn / MCLK02
    IOPORT_PIN_P180_PFC_29_HDSL3_SMPL      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_0 / HDSLn / HDSL3_SMPL
    IOPORT_PIN_P180_PFC_2F_ESWM_TASGATE1_1 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_0 / ETHER_ESWM / ESWM_TASGATE1_1

    IOPORT_PIN_P181_PFC_20_XSPI0_IO2       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_1 / XSPIn / XSPI0_IO2
    IOPORT_PIN_P181_PFC_21_MCLK32          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_1 / DSMIFn / MCLK32
    IOPORT_PIN_P181_PFC_29_HDSL3_CLK1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_1 / HDSLn / HDSL3_CLK1
    IOPORT_PIN_P181_PFC_2F_ESWM_TASGATE1_2 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_1 / ETHER_ESWM / ESWM_TASGATE1_2

    IOPORT_PIN_P182_PFC_20_XSPI0_IO3       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_2 / XSPIn / XSPI0_IO3
    IOPORT_PIN_P182_PFC_21_MDAT32          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_2 / DSMIFn / MDAT32
    IOPORT_PIN_P182_PFC_29_HDSL3_SEL1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_2 / HDSLn / HDSL3_SEL1
    IOPORT_PIN_P182_PFC_2F_ESWM_TASGATE1_3 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_2 / ETHER_ESWM / ESWM_TASGATE1_3

    IOPORT_PIN_P183_PFC_1A_SCKE4           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P18_3 / SCIEn / SCKE4
    IOPORT_PIN_P183_PFC_20_XSPI0_IO4       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_3 / XSPIn / XSPI0_IO4
    IOPORT_PIN_P183_PFC_21_MCLK21          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_3 / DSMIFn / MCLK21
    IOPORT_PIN_P183_PFC_26_ENCIFCK4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P18_3 / ENCIFn / ENCIFCK4
    IOPORT_PIN_P183_PFC_29_HDSL3_MISO1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_3 / HDSLn / HDSL3_MISO1
    IOPORT_PIN_P183_PFC_2F_ESWM_TASGATE1_4 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_3 / ETHER_ESWM / ESWM_TASGATE1_4

    IOPORT_PIN_P184_PFC_0C_GTETRGA         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P18_4 / GPT_POEG / GTETRGA
    IOPORT_PIN_P184_PFC_1A_DEE4            = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P18_4 / SCIEn / DEE4
    IOPORT_PIN_P184_PFC_20_XSPI0_IO5       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_4 / XSPIn / XSPI0_IO5
    IOPORT_PIN_P184_PFC_21_MDAT21          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_4 / DSMIFn / MDAT21
    IOPORT_PIN_P184_PFC_26_ENCIFOE4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P18_4 / ENCIFn / ENCIFOE4
    IOPORT_PIN_P184_PFC_29_HDSL3_MOSI1     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_4 / HDSLn / HDSL3_MOSI1
    IOPORT_PIN_P184_PFC_2F_ESWM_TASGATE1_5 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_4 / ETHER_ESWM / ESWM_TASGATE1_5

    IOPORT_PIN_P185_PFC_0C_GTETRGB         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P18_5 / GPT_POEG / GTETRGB
    IOPORT_PIN_P185_PFC_1A_RXDE4           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P18_5 / SCIEn / RXDE4
    IOPORT_PIN_P185_PFC_20_XSPI0_IO6       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_5 / XSPIn / XSPI0_IO6
    IOPORT_PIN_P185_PFC_21_MCLK20          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_5 / DSMIFn / MCLK20
    IOPORT_PIN_P185_PFC_26_ENCIFDI4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P18_5 / ENCIFn / ENCIFDI4
    IOPORT_PIN_P185_PFC_29_HDSL3_CLK2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_5 / HDSLn / HDSL3_CLK2
    IOPORT_PIN_P185_PFC_2F_ESWM_TASGATE1_6 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_5 / ETHER_ESWM / ESWM_TASGATE1_6

    IOPORT_PIN_P186_PFC_0C_GTETRGC         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P18_6 / GPT_POEG / GTETRGC
    IOPORT_PIN_P186_PFC_1A_TXDE4           = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P18_6 / SCIEn / TXDE4
    IOPORT_PIN_P186_PFC_20_XSPI0_IO7       = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_6 / XSPIn / XSPI0_IO7
    IOPORT_PIN_P186_PFC_21_MDAT20          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_6 / DSMIFn / MDAT20
    IOPORT_PIN_P186_PFC_26_ENCIFDO4        = (0x26U << IOPORT_PFC_OFFSET),                            ///< P18_6 / ENCIFn / ENCIFDO4
    IOPORT_PIN_P186_PFC_29_HDSL3_SEL2      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_6 / HDSLn / HDSL3_SEL2
    IOPORT_PIN_P186_PFC_2F_ESWM_TASGATE1_7 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_6 / ETHER_ESWM / ESWM_TASGATE1_7

    IOPORT_PIN_P187_PFC_20_XSPI0_RESET0    = (0x20U << IOPORT_PFC_OFFSET),                            ///< P18_7 / XSPIn / XSPI0_RESET0
    IOPORT_PIN_P187_PFC_21_MCLK30          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P18_7 / DSMIFn / MCLK30
    IOPORT_PIN_P187_PFC_22_MDAT02          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P18_7 / DSMIFn / MDAT02
    IOPORT_PIN_P187_PFC_29_HDSL3_MISO2     = (0x29U << IOPORT_PFC_OFFSET),                            ///< P18_7 / HDSLn / HDSL3_MISO2
    IOPORT_PIN_P187_PFC_2F_ESWM_TASGATE1_8 = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P18_7 / ETHER_ESWM / ESWM_TASGATE1_8

    IOPORT_PIN_P190_PFC_0F_ETH0_TXCLK  = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P19_0 / ETHER_ETHn / ETH0_TXCLK
    IOPORT_PIN_P190_PFC_29_HDSL3_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P19_0 / HDSLn / HDSL3_MOSI2

    IOPORT_PIN_P191_PFC_0F_ETH0_TXD0  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P19_1 / ETHER_ETHn / ETH0_TXD0
    IOPORT_PIN_P191_PFC_29_HDSL4_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P19_1 / HDSLn / HDSL4_LINK

    IOPORT_PIN_P192_PFC_0F_ETH0_TXD1  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P19_2 / ETHER_ETHn / ETH0_TXD1
    IOPORT_PIN_P192_PFC_29_HDSL4_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P19_2 / HDSLn / HDSL4_SMPL

    IOPORT_PIN_P193_PFC_0F_ETH0_TXD2  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P19_3 / ETHER_ETHn / ETH0_TXD2
    IOPORT_PIN_P193_PFC_29_HDSL4_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P19_3 / HDSLn / HDSL4_CLK1

    IOPORT_PIN_P194_PFC_0F_ETH0_TXD3  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P19_4 / ETHER_ETHn / ETH0_TXD3
    IOPORT_PIN_P194_PFC_29_HDSL4_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P19_4 / HDSLn / HDSL4_SEL1

    IOPORT_PIN_P195_PFC_0F_ETH0_TXEN   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P19_5 / ETHER_ETHn / ETH0_TXEN
    IOPORT_PIN_P195_PFC_29_HDSL4_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P19_5 / HDSLn / HDSL4_MISO1

    IOPORT_PIN_P196_PFC_0F_ETH0_RXCLK  = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P19_6 / ETHER_ETHn / ETH0_RXCLK
    IOPORT_PIN_P196_PFC_29_HDSL4_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P19_6 / HDSLn / HDSL4_MOSI1

    IOPORT_PIN_P197_PFC_0F_ETH0_RXD0  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P19_7 / ETHER_ETHn / ETH0_RXD0
    IOPORT_PIN_P197_PFC_1D_CANRX0     = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P19_7 / CANFDn / CANRX0
    IOPORT_PIN_P197_PFC_29_HDSL4_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P19_7 / HDSLn / HDSL4_CLK2

    IOPORT_PIN_P200_PFC_0F_ETH0_RXD1  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P20_0 / ETHER_ETHn / ETH0_RXD1
    IOPORT_PIN_P200_PFC_1D_CANTX0     = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P20_0 / CANFDn / CANTX0
    IOPORT_PIN_P200_PFC_29_HDSL4_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P20_0 / HDSLn / HDSL4_SEL2

    IOPORT_PIN_P201_PFC_0F_ETH0_RXD2   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P20_1 / ETHER_ETHn / ETH0_RXD2
    IOPORT_PIN_P201_PFC_1D_CANRXDP0    = (0x1DU << IOPORT_PFC_OFFSET),                                ///< P20_1 / CANFDn / CANRXDP0
    IOPORT_PIN_P201_PFC_29_HDSL4_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P20_1 / HDSLn / HDSL4_MISO2

    IOPORT_PIN_P202_PFC_0F_ETH0_RXD3   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P20_2 / ETHER_ETHn / ETH0_RXD3
    IOPORT_PIN_P202_PFC_1D_CANTXDP0    = (0x1DU << IOPORT_PFC_OFFSET),                                ///< P20_2 / CANFDn / CANTXDP0
    IOPORT_PIN_P202_PFC_29_HDSL4_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P20_2 / HDSLn / HDSL4_MOSI2

    IOPORT_PIN_P203_PFC_0F_ETH0_RXDV  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P20_3 / ETHER_ETHn / ETH0_RXDV
    IOPORT_PIN_P203_PFC_29_HDSL5_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P20_3 / HDSLn / HDSL5_LINK

    IOPORT_PIN_P204_PFC_11_GMAC0_MDC = (0x11U << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_GMACn / GMAC0_MDC
    IOPORT_PIN_P204_PFC_12_GMAC1_MDC = (0x12U << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P204_PFC_13_GMAC2_MDC = (0x13U << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_GMACn / GMAC2_MDC
    IOPORT_PIN_P204_PFC_14_ETHSW_MDC = (0x14U << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P204_PFC_15_ESC_MDC   = (0x15U << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P204_PFC_1D_CANTX1    = (0x1DU << IOPORT_PFC_OFFSET),                                  ///< P20_4 / CANFDn / CANTX1
    IOPORT_PIN_P204_PFC_2F_ESWM_MDC  = (0x2FU << IOPORT_PFC_OFFSET),                                  ///< P20_4 / ETHER_ESWM / ESWM_MDC

    IOPORT_PIN_P205_PFC_11_GMAC0_MDIO = (0x11U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_GMACn / GMAC0_MDIO
    IOPORT_PIN_P205_PFC_12_GMAC1_MDIO = (0x12U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P205_PFC_13_GMAC2_MDIO = (0x13U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_GMACn / GMAC2_MDIO
    IOPORT_PIN_P205_PFC_14_ETHSW_MDIO = (0x14U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P205_PFC_15_ESC_MDIO   = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P205_PFC_1D_CANRX1     = (0x1DU << IOPORT_PFC_OFFSET),                                 ///< P20_5 / CANFDn / CANRX1
    IOPORT_PIN_P205_PFC_29_HDSL5_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P20_5 / HDSLn / HDSL5_SMPL
    IOPORT_PIN_P205_PFC_2F_ESWM_MDIO  = (0x2FU << IOPORT_PFC_OFFSET),                                 ///< P20_5 / ETHER_ESWM / ESWM_MDIO

    IOPORT_PIN_P206_PFC_14_ETHSW_PHYLINK0 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P20_6 / ETHER_ETHSW / ETHSW_PHYLINK0
    IOPORT_PIN_P206_PFC_15_ESC_PHYLINK0   = (0x15U << IOPORT_PFC_OFFSET),                             ///< P20_6 / ETHER_ESC / ESC_PHYLINK0
    IOPORT_PIN_P206_PFC_1D_CANRXDP1       = (0x1DU << IOPORT_PFC_OFFSET),                             ///< P20_6 / CANFDn / CANRXDP1
    IOPORT_PIN_P206_PFC_29_HDSL5_CLK1     = (0x29U << IOPORT_PFC_OFFSET),                             ///< P20_6 / HDSLn / HDSL5_CLK1
    IOPORT_PIN_P206_PFC_2F_ESWM_PHYLINK0  = (0x2FU << IOPORT_PFC_OFFSET),                             ///< P20_6 / ETHER_ESWM / ESWM_PHYLINK0
    IOPORT_PIN_P206_PFC_30_HPSW_PHYLINK0  = (0x30U << IOPORT_PFC_OFFSET),                             ///< P20_6 / ETHER_HPSW / HPSW_PHYLINK0

    IOPORT_PIN_P207_PFC_02_ETH0_REFCLK  = (0x02U << IOPORT_PFC_OFFSET),                               ///< P20_7 / ETHER_ETHn / ETH0_REFCLK
    IOPORT_PIN_P207_PFC_03_RMII0_REFCLK = (0x03U << IOPORT_PFC_OFFSET),                               ///< P20_7 / ETHER_ETHn / RMII0_REFCLK
    IOPORT_PIN_P207_PFC_1D_CANTXDP1     = (0x1DU << IOPORT_PFC_OFFSET),                               ///< P20_7 / CANFDn / CANTXDP1
    IOPORT_PIN_P207_PFC_29_HDSL5_SEL1   = (0x29U << IOPORT_PFC_OFFSET),                               ///< P20_7 / HDSLn / HDSL5_SEL1

    IOPORT_PIN_P210_PFC_29_HDSL5_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P21_0 / HDSLn / HDSL5_MISO1

    IOPORT_PIN_P211_PFC_0F_ETH1_TXCLK  = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P21_1 / ETHER_ETHn / ETH1_TXCLK
    IOPORT_PIN_P211_PFC_29_HDSL5_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P21_1 / HDSLn / HDSL5_MOSI1

    IOPORT_PIN_P212_PFC_0F_ETH1_TXD0  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P21_2 / ETHER_ETHn / ETH1_TXD0
    IOPORT_PIN_P212_PFC_29_HDSL5_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P21_2 / HDSLn / HDSL5_CLK2

    IOPORT_PIN_P213_PFC_0F_ETH1_TXD1  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P21_3 / ETHER_ETHn / ETH1_TXD1
    IOPORT_PIN_P213_PFC_29_HDSL5_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P21_3 / HDSLn / HDSL5_SEL2

    IOPORT_PIN_P214_PFC_0F_ETH1_TXD2   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P21_4 / ETHER_ETHn / ETH1_TXD2
    IOPORT_PIN_P214_PFC_29_HDSL5_MISO2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P21_4 / HDSLn / HDSL5_MISO2

    IOPORT_PIN_P215_PFC_0F_ETH1_TXD3   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P21_5 / ETHER_ETHn / ETH1_TXD3
    IOPORT_PIN_P215_PFC_29_HDSL5_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P21_5 / HDSLn / HDSL5_MOSI2

    IOPORT_PIN_P216_PFC_0F_ETH1_TXEN  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P21_6 / ETHER_ETHn / ETH1_TXEN
    IOPORT_PIN_P216_PFC_29_HDSL6_LINK = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P21_6 / HDSLn / HDSL6_LINK

    IOPORT_PIN_P217_PFC_0A_GTOPC4_4A  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P21_7 / GPTn / GTOPC4_4A
    IOPORT_PIN_P217_PFC_0F_ETH1_RXCLK = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P21_7 / ETHER_ETHn / ETH1_RXCLK
    IOPORT_PIN_P217_PFC_29_HDSL6_SMPL = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P21_7 / HDSLn / HDSL6_SMPL

    IOPORT_PIN_P220_PFC_0A_GTIOC4_4B  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P22_0 / GPTn / GTIOC4_4B
    IOPORT_PIN_P220_PFC_0F_ETH1_RXD0  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P22_0 / ETHER_ETHn / ETH1_RXD0
    IOPORT_PIN_P220_PFC_29_HDSL6_CLK1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P22_0 / HDSLn / HDSL6_CLK1

    IOPORT_PIN_P221_PFC_09_GTIOC5_0A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P22_1 / GPTn / GTIOC5_0A
    IOPORT_PIN_P221_PFC_0A_GTIOC4_5A  = (0x0AU << IOPORT_PFC_OFFSET),                                 ///< P22_1 / GPTn / GTIOC4_5A
    IOPORT_PIN_P221_PFC_0F_ETH1_RXD1  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P22_1 / ETHER_ETHn / ETH1_RXD1
    IOPORT_PIN_P221_PFC_29_HDSL6_SEL1 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P22_1 / HDSLn / HDSL6_SEL1

    IOPORT_PIN_P222_PFC_09_GTIOC5_0B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P22_2 / GPTn / GTIOC5_0B
    IOPORT_PIN_P222_PFC_0A_GTIOC4_5B   = (0x0AU << IOPORT_PFC_OFFSET),                                ///< P22_2 / GPTn / GTIOC4_5B
    IOPORT_PIN_P222_PFC_0B_GTIOC0_3A   = (0x0BU << IOPORT_PFC_OFFSET),                                ///< P22_2 / GPTn / GTIOC0_3A
    IOPORT_PIN_P222_PFC_0F_ETH1_RXD2   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P22_2 / ETHER_ETHn / ETH1_RXD2
    IOPORT_PIN_P222_PFC_29_HDSL6_MISO1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P22_2 / HDSLn / HDSL6_MISO1

    IOPORT_PIN_P223_PFC_0B_GTIOC0_3B   = (0x0BU << IOPORT_PFC_OFFSET),                                ///< P22_3 / GPTn / GTIOC0_3B
    IOPORT_PIN_P223_PFC_0F_ETH1_RXD3   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P22_3 / ETHER_ETHn / ETH1_RXD3
    IOPORT_PIN_P223_PFC_29_HDSL6_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P22_3 / HDSLn / HDSL6_MOSI1

    IOPORT_PIN_P224_PFC_0B_GTIOC0_2B  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P22_4 / GPTn / GTIOC0_2B
    IOPORT_PIN_P224_PFC_0F_ETH1_RXDV  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P22_4 / ETHER_ETHn / ETH1_RXDV
    IOPORT_PIN_P224_PFC_29_HDSL6_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P22_4 / HDSLn / HDSL6_CLK2

    IOPORT_PIN_P225_PFC_14_ETHSW_PHYLINK1 = (0x14U << IOPORT_PFC_OFFSET),                             ///< P22_5 / ETHER_ETHSW / ETHSW_PHYLINK1
    IOPORT_PIN_P225_PFC_15_ESC_PHYLINK1   = (0x15U << IOPORT_PFC_OFFSET),                             ///< P22_5 / ETHER_ESC / ESC_PHYLINK1
    IOPORT_PIN_P225_PFC_29_HDSL6_SEL2     = (0x29U << IOPORT_PFC_OFFSET),                             ///< P22_5 / HDSLn / HDSL6_SEL2
    IOPORT_PIN_P225_PFC_2F_ESWM_PHYLINK1  = (0x2FU << IOPORT_PFC_OFFSET),                             ///< P22_5 / ETHER_ESWM / ESWM_PHYLINK1
    IOPORT_PIN_P225_PFC_30_HPSW_PHYLINK1  = (0x30U << IOPORT_PFC_OFFSET),                             ///< P22_5 / ETHER_HPSW / HPSW_PHYLINK1

    IOPORT_PIN_P226_PFC_02_ETH1_REFCLK  = (0x02U << IOPORT_PFC_OFFSET),                               ///< P22_6 / ETHER_ETHn / ETH1_REFCLK
    IOPORT_PIN_P226_PFC_03_RMII1_REFCLK = (0x03U << IOPORT_PFC_OFFSET),                               ///< P22_6 / ETHER_ETHn / RMII1_REFCLK
    IOPORT_PIN_P226_PFC_29_HDSL6_MISO2  = (0x29U << IOPORT_PFC_OFFSET),                               ///< P22_6 / HDSLn / HDSL6_MISO2

    IOPORT_PIN_P227_PFC_29_HDSL6_MOSI2 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P22_7 / HDSLn / HDSL6_MOSI2

    IOPORT_PIN_P230_PFC_09_GTIOC4_0A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P23_0 / GPTn / GTIOC4_0A
    IOPORT_PIN_P230_PFC_0B_GTIOC3_3A       = (0x0BU << IOPORT_PFC_OFFSET),                            ///< P23_0 / GPTn / GTIOC3_3A
    IOPORT_PIN_P230_PFC_0F_ETH2_TXCLK      = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P23_0 / ETHER_ETHn / ETH2_TXCLK
    IOPORT_PIN_P230_PFC_18_RXD3_SCL3_MISO3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P23_0 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P230_PFC_1E_SPI_RSPCK0      = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P23_0 / SPIn / SPI_RSPCK0
    IOPORT_PIN_P230_PFC_22_MDAT01          = (0x22U << IOPORT_PFC_OFFSET),                            ///< P23_0 / DSMIFn / MDAT01
    IOPORT_PIN_P230_PFC_29_HDSL7_LINK      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P23_0 / HDSLn / HDSL7_LINK

    IOPORT_PIN_P231_PFC_09_GTIOC4_0B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P23_1 / GPTn / GTIOC4_0B
    IOPORT_PIN_P231_PFC_0B_GTIOC3_3B     = (0x0BU << IOPORT_PFC_OFFSET),                              ///< P23_1 / GPTn / GTIOC3_3B
    IOPORT_PIN_P231_PFC_0F_ETH2_TXD0     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P23_1 / ETHER_ETHn / ETH2_TXD0
    IOPORT_PIN_P231_PFC_11_GMAC0_PTPTRG0 = (0x11U << IOPORT_PFC_OFFSET),                              ///< P23_1 / ETHER_GMACn / GMAC0_PTPTRG0
    IOPORT_PIN_P231_PFC_15_ESC_LATCH0    = (0x15U << IOPORT_PFC_OFFSET),                              ///< P23_1 / ETHER_ESC / ESC_LATCH0
    IOPORT_PIN_P231_PFC_18_SCK3          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P23_1 / SCIn / SCK3
    IOPORT_PIN_P231_PFC_1C_IIC_SCL0      = (0x1CU << IOPORT_PFC_OFFSET),                              ///< P23_1 / IICn / IIC_SCL0
    IOPORT_PIN_P231_PFC_1D_CANRXDP1      = (0x1DU << IOPORT_PFC_OFFSET),                              ///< P23_1 / CANFDn / CANRXDP1
    IOPORT_PIN_P231_PFC_1E_SPI_MISO0     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P23_1 / SPIn / SPI_MISO0
    IOPORT_PIN_P231_PFC_21_MCLK40        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P23_1 / DSMIFn / MCLK40
    IOPORT_PIN_P231_PFC_22_MCLK21        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P23_1 / DSMIFn / MCLK21
    IOPORT_PIN_P231_PFC_29_HDSL7_SMPL    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P23_1 / HDSLn / HDSL7_SMPL

    IOPORT_PIN_P232_PFC_09_GTIOC4_1A    = (0x09U << IOPORT_PFC_OFFSET),                               ///< P23_2 / GPTn / GTIOC4_1A
    IOPORT_PIN_P232_PFC_0F_ETH2_TXD1    = (0x0FU << IOPORT_PFC_OFFSET),                               ///< P23_2 / ETHER_ETHn / ETH2_TXD1
    IOPORT_PIN_P232_PFC_15_ESC_LINKACT0 = (0x15U << IOPORT_PFC_OFFSET),                               ///< P23_2 / ETHER_ESC / ESC_LINKACT0
    IOPORT_PIN_P232_PFC_1C_IIC_SDA0     = (0x1CU << IOPORT_PFC_OFFSET),                               ///< P23_2 / IICn / IIC_SDA0
    IOPORT_PIN_P232_PFC_1D_CANTXDP1     = (0x1DU << IOPORT_PFC_OFFSET),                               ///< P23_2 / CANFDn / CANTXDP1
    IOPORT_PIN_P232_PFC_1E_SPI_MOSI0    = (0x1EU << IOPORT_PFC_OFFSET),                               ///< P23_2 / SPIn / SPI_MOSI0
    IOPORT_PIN_P232_PFC_21_MDAT40       = (0x21U << IOPORT_PFC_OFFSET),                               ///< P23_2 / DSMIFn / MDAT40
    IOPORT_PIN_P232_PFC_22_MDAT21       = (0x22U << IOPORT_PFC_OFFSET),                               ///< P23_2 / DSMIFn / MDAT21
    IOPORT_PIN_P232_PFC_29_HDSL7_CLK1   = (0x29U << IOPORT_PFC_OFFSET),                               ///< P23_2 / HDSLn / HDSL7_CLK1

    IOPORT_PIN_P233_PFC_09_GTIOC4_1B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P23_3 / GPTn / GTIOC4_1B
    IOPORT_PIN_P233_PFC_0B_GTIOC4_3A     = (0x0BU << IOPORT_PFC_OFFSET),                              ///< P23_3 / GPTn / GTIOC4_3A
    IOPORT_PIN_P233_PFC_0F_ETH2_TXD2     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P23_3 / ETHER_ETHn / ETH2_TXD2
    IOPORT_PIN_P233_PFC_15_ESC_LINKACT1  = (0x15U << IOPORT_PFC_OFFSET),                              ///< P23_3 / ETHER_ESC / ESC_LINKACT1
    IOPORT_PIN_P233_PFC_18_CTS3_RTS3_SS3 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P23_3 / SCIn / CTS3_RTS3_SS3
    IOPORT_PIN_P233_PFC_1E_SPI_SSL00     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P23_3 / SPIn / SPI_SSL00
    IOPORT_PIN_P233_PFC_21_MCLK41        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P23_3 / DSMIFn / MCLK41
    IOPORT_PIN_P233_PFC_22_MCLK01        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P23_3 / DSMIFn / MCLK01
    IOPORT_PIN_P233_PFC_29_HDSL7_SEL1    = (0x29U << IOPORT_PFC_OFFSET),                              ///< P23_3 / HDSLn / HDSL7_SEL1

    IOPORT_PIN_P234_PFC_09_GTIOC4_2A     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P23_4 / GPTn / GTIOC4_2A
    IOPORT_PIN_P234_PFC_0B_GTIOC4_3B     = (0x0BU << IOPORT_PFC_OFFSET),                              ///< P23_4 / GPTn / GTIOC4_3B
    IOPORT_PIN_P234_PFC_0F_ETH2_TXD3     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P23_4 / ETHER_ETHn / ETH2_TXD3
    IOPORT_PIN_P234_PFC_14_ETHSW_PTPOUT2 = (0x14U << IOPORT_PFC_OFFSET),                              ///< P23_4 / ETHER_ETHSW / ETHSW_PTPOUT2
    IOPORT_PIN_P234_PFC_15_ESC_SYNC0     = (0x15U << IOPORT_PFC_OFFSET),                              ///< P23_4 / ETHER_ESC / ESC_SYNC0
    IOPORT_PIN_P234_PFC_18_CTS3          = (0x18U << IOPORT_PFC_OFFSET),                              ///< P23_4 / SCIn / CTS3
    IOPORT_PIN_P234_PFC_1E_SPI_SSL01     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P23_4 / SPIn / SPI_SSL01
    IOPORT_PIN_P234_PFC_21_MDAT41        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P23_4 / DSMIFn / MDAT41
    IOPORT_PIN_P234_PFC_22_MDAT01        = (0x22U << IOPORT_PFC_OFFSET),                              ///< P23_4 / DSMIFn / MDAT01
    IOPORT_PIN_P234_PFC_29_HDSL7_MISO1   = (0x29U << IOPORT_PFC_OFFSET),                              ///< P23_4 / HDSLn / HDSL7_MISO1

    IOPORT_PIN_P235_PFC_09_GTIOC4_2B   = (0x09U << IOPORT_PFC_OFFSET),                                ///< P23_5 / GPTn / GTIOC4_2B
    IOPORT_PIN_P235_PFC_0F_ETH2_TXEN   = (0x0FU << IOPORT_PFC_OFFSET),                                ///< P23_5 / ETHER_ETHn / ETH2_TXEN
    IOPORT_PIN_P235_PFC_15_ESC_LEDERR  = (0x15U << IOPORT_PFC_OFFSET),                                ///< P23_5 / ETHER_ESC / ESC_LEDERR
    IOPORT_PIN_P235_PFC_18_DE3         = (0x18U << IOPORT_PFC_OFFSET),                                ///< P23_5 / SCIn / DE3
    IOPORT_PIN_P235_PFC_1E_SPI_SSL02   = (0x1EU << IOPORT_PFC_OFFSET),                                ///< P23_5 / SPIn / SPI_SSL02
    IOPORT_PIN_P235_PFC_21_MCLK42      = (0x21U << IOPORT_PFC_OFFSET),                                ///< P23_5 / DSMIFn / MCLK42
    IOPORT_PIN_P235_PFC_22_MCLK30      = (0x22U << IOPORT_PFC_OFFSET),                                ///< P23_5 / DSMIFn / MCLK30
    IOPORT_PIN_P235_PFC_29_HDSL7_MOSI1 = (0x29U << IOPORT_PFC_OFFSET),                                ///< P23_5 / HDSLn / HDSL7_MOSI1

    IOPORT_PIN_P236_PFC_09_GTIOC4_3A  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / GPTn / GTIOC4_3A
    IOPORT_PIN_P236_PFC_0B_GTIOC5_3A  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P23_6 / GPTn / GTIOC5_3A
    IOPORT_PIN_P236_PFC_0E_RTCAT1HZ   = (0x0EU << IOPORT_PFC_OFFSET),                                 ///< P23_6 / RTC / RTCAT1HZ
    IOPORT_PIN_P236_PFC_0F_ETH2_RXCLK = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P23_6 / ETHER_ETHn / ETH2_RXCLK
    IOPORT_PIN_P236_PFC_15_ESC_LEDRUN = (0x15U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / ETHER_ESC / ESC_LEDRUN
    IOPORT_PIN_P236_PFC_18_SCK4       = (0x18U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / SCIn / SCK4
    IOPORT_PIN_P236_PFC_21_MDAT42     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / DSMIFn / MDAT42
    IOPORT_PIN_P236_PFC_22_MDAT30     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / DSMIFn / MDAT30
    IOPORT_PIN_P236_PFC_29_HDSL7_CLK2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P23_6 / HDSLn / HDSL7_CLK2
    IOPORT_PIN_P236_PFC_2C_SD0_CD     = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P23_6 / SDHIn / SD0_CD

    IOPORT_PIN_P237_PFC_09_GTIOC4_3B  = (0x09U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / GPTn / GTIOC4_3B
    IOPORT_PIN_P237_PFC_0B_GTIOC5_3B  = (0x0BU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / GPTn / GTIOC5_3B
    IOPORT_PIN_P237_PFC_0F_ETH2_RXD0  = (0x0FU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / ETHER_ETHn / ETH2_RXD0
    IOPORT_PIN_P237_PFC_10_ETH0_COL   = (0x10U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / ETHER_ETHn / ETH0_COL
    IOPORT_PIN_P237_PFC_1A_SCKE0      = (0x1AU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / SCIEn / SCKE0
    IOPORT_PIN_P237_PFC_1C_IIC_SCL1   = (0x1CU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / IICn / IIC_SCL1
    IOPORT_PIN_P237_PFC_1E_SPI_SSL12  = (0x1EU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / SPIn / SPI_SSL12
    IOPORT_PIN_P237_PFC_21_MCLK10     = (0x21U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / DSMIFn / MCLK10
    IOPORT_PIN_P237_PFC_22_MCLK32     = (0x22U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / DSMIFn / MCLK32
    IOPORT_PIN_P237_PFC_26_ENCIFCK0   = (0x26U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / ENCIFn / ENCIFCK0
    IOPORT_PIN_P237_PFC_29_HDSL7_SEL2 = (0x29U << IOPORT_PFC_OFFSET),                                 ///< P23_7 / HDSLn / HDSL7_SEL2
    IOPORT_PIN_P237_PFC_2C_SD0_WP     = (0x2CU << IOPORT_PFC_OFFSET),                                 ///< P23_7 / SDHIn / SD0_WP

    IOPORT_PIN_P240_PFC_05_DREQ         = (0x05U << IOPORT_PFC_OFFSET),                               ///< P24_0 / DMAC / DREQ
    IOPORT_PIN_P240_PFC_08_POE0         = (0x08U << IOPORT_PFC_OFFSET),                               ///< P24_0 / MTU_POE3 / POE0
    IOPORT_PIN_P240_PFC_09_GTIOC4_4A    = (0x09U << IOPORT_PFC_OFFSET),                               ///< P24_0 / GPTn / GTIOC4_4A
    IOPORT_PIN_P240_PFC_0F_ETH2_RXD1    = (0x0FU << IOPORT_PFC_OFFSET),                               ///< P24_0 / ETHER_ETHn / ETH2_RXD1
    IOPORT_PIN_P240_PFC_10_ETH0_CRS     = (0x10U << IOPORT_PFC_OFFSET),                               ///< P24_0 / ETHER_ETHn / ETH0_CRS
    IOPORT_PIN_P240_PFC_15_ESC_LINKACT2 = (0x15U << IOPORT_PFC_OFFSET),                               ///< P24_0 / ETHER_ESC / ESC_LINKACT2
    IOPORT_PIN_P240_PFC_1A_DEE0         = (0x1AU << IOPORT_PFC_OFFSET),                               ///< P24_0 / SCIEn / DEE0
    IOPORT_PIN_P240_PFC_1C_IIC_SDA1     = (0x1CU << IOPORT_PFC_OFFSET),                               ///< P24_0 / IICn / IIC_SDA1
    IOPORT_PIN_P240_PFC_1E_SPI_SSL13    = (0x1EU << IOPORT_PFC_OFFSET),                               ///< P24_0 / SPIn / SPI_SSL13
    IOPORT_PIN_P240_PFC_21_MDAT10       = (0x21U << IOPORT_PFC_OFFSET),                               ///< P24_0 / DSMIFn / MDAT10
    IOPORT_PIN_P240_PFC_22_MDAT32       = (0x22U << IOPORT_PFC_OFFSET),                               ///< P24_0 / DSMIFn / MDAT32
    IOPORT_PIN_P240_PFC_26_ENCIFOE0     = (0x26U << IOPORT_PFC_OFFSET),                               ///< P24_0 / ENCIFn / ENCIFOE0
    IOPORT_PIN_P240_PFC_29_HDSL7_MISO2  = (0x29U << IOPORT_PFC_OFFSET),                               ///< P24_0 / HDSLn / HDSL7_MISO2
    IOPORT_PIN_P240_PFC_2C_SD1_CD       = (0x2CU << IOPORT_PFC_OFFSET),                               ///< P24_0 / SDHIn / SD1_CD

    IOPORT_PIN_P241_PFC_05_DACK          = (0x05U << IOPORT_PFC_OFFSET),                              ///< P24_1 / DMAC / DACK
    IOPORT_PIN_P241_PFC_08_POE4          = (0x08U << IOPORT_PFC_OFFSET),                              ///< P24_1 / MTU_POE3 / POE4
    IOPORT_PIN_P241_PFC_09_GTIOC4_4B     = (0x09U << IOPORT_PFC_OFFSET),                              ///< P24_1 / GPTn / GTIOC4_4B
    IOPORT_PIN_P241_PFC_0D_CMTW0_TIC0    = (0x0DU << IOPORT_PFC_OFFSET),                              ///< P24_1 / CMTW / CMTW0_TIC0
    IOPORT_PIN_P241_PFC_0F_ETH2_RXD2     = (0x0FU << IOPORT_PFC_OFFSET),                              ///< P24_1 / ETHER_ETHn / ETH2_RXD2
    IOPORT_PIN_P241_PFC_10_ETH0_TXER     = (0x10U << IOPORT_PFC_OFFSET),                              ///< P24_1 / ETHER_ETHn / ETH0_TXER
    IOPORT_PIN_P241_PFC_15_ESC_IRQ       = (0x15U << IOPORT_PFC_OFFSET),                              ///< P24_1 / ETHER_ESC / ESC_IRQ
    IOPORT_PIN_P241_PFC_18_CTS4_RTS4_SS4 = (0x18U << IOPORT_PFC_OFFSET),                              ///< P24_1 / SCIn / CTS4_RTS4_SS4
    IOPORT_PIN_P241_PFC_1A_TXDE0         = (0x1AU << IOPORT_PFC_OFFSET),                              ///< P24_1 / SCIEn / TXDE0
    IOPORT_PIN_P241_PFC_1E_SPI_SSL10     = (0x1EU << IOPORT_PFC_OFFSET),                              ///< P24_1 / SPIn / SPI_SSL10
    IOPORT_PIN_P241_PFC_21_MCLK11        = (0x21U << IOPORT_PFC_OFFSET),                              ///< P24_1 / DSMIFn / MCLK11
    IOPORT_PIN_P241_PFC_25_MBX_HINT      = (0x25U << IOPORT_PFC_OFFSET),                              ///< P24_1 / MBXSEM / MBX_HINT
    IOPORT_PIN_P241_PFC_26_ENCIFDO0      = (0x26U << IOPORT_PFC_OFFSET),                              ///< P24_1 / ENCIFn / ENCIFDO0
    IOPORT_PIN_P241_PFC_2C_SD1_WP        = (0x2CU << IOPORT_PFC_OFFSET),                              ///< P24_1 / SDHIn / SD1_WP

    IOPORT_PIN_P242_PFC_05_TEND         = (0x05U << IOPORT_PFC_OFFSET),                               ///< P24_2 / DMAC / TEND
    IOPORT_PIN_P242_PFC_08_POE8         = (0x08U << IOPORT_PFC_OFFSET),                               ///< P24_2 / MTU_POE3 / POE8
    IOPORT_PIN_P242_PFC_09_GTIOC4_5A    = (0x09U << IOPORT_PFC_OFFSET),                               ///< P24_2 / GPTn / GTIOC4_5A
    IOPORT_PIN_P242_PFC_0D_CMTW0_TOC0   = (0x0DU << IOPORT_PFC_OFFSET),                               ///< P24_2 / CMTW / CMTW0_TOC0
    IOPORT_PIN_P242_PFC_0F_ETH2_RXD3    = (0x0FU << IOPORT_PFC_OFFSET),                               ///< P24_2 / ETHER_ETHn / ETH2_RXD3
    IOPORT_PIN_P242_PFC_15_ESC_RESETOUT = (0x15U << IOPORT_PFC_OFFSET),                               ///< P24_2 / ETHER_ESC / ESC_RESETOUT
    IOPORT_PIN_P242_PFC_18_CTS4         = (0x18U << IOPORT_PFC_OFFSET),                               ///< P24_2 / SCIn / CTS4
    IOPORT_PIN_P242_PFC_1A_RXDE0        = (0x1AU << IOPORT_PFC_OFFSET),                               ///< P24_2 / SCIEn / RXDE0
    IOPORT_PIN_P242_PFC_1E_SPI_SSL11    = (0x1EU << IOPORT_PFC_OFFSET),                               ///< P24_2 / SPIn / SPI_SSL11
    IOPORT_PIN_P242_PFC_21_MDAT11       = (0x21U << IOPORT_PFC_OFFSET),                               ///< P24_2 / DSMIFn / MDAT11
    IOPORT_PIN_P242_PFC_26_ENCIFDI0     = (0x26U << IOPORT_PFC_OFFSET),                               ///< P24_2 / ENCIFn / ENCIFDI0
    IOPORT_PIN_P242_PFC_29_HDSL7_MOSI2  = (0x29U << IOPORT_PFC_OFFSET),                               ///< P24_2 / HDSLn / HDSL7_MOSI2

    IOPORT_PIN_P243_PFC_09_GTIOC4_5B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P24_3 / GPTn / GTIOC4_5B
    IOPORT_PIN_P243_PFC_0D_CMTW0_TIC1      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P24_3 / CMTW / CMTW0_TIC1
    IOPORT_PIN_P243_PFC_0F_ETH2_RXDV       = (0x0FU << IOPORT_PFC_OFFSET),                            ///< P24_3 / ETHER_ETHn / ETH2_RXDV
    IOPORT_PIN_P243_PFC_10_ETH0_RXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P24_3 / ETHER_ETHn / ETH0_RXER
    IOPORT_PIN_P243_PFC_15_ESC_I2CCLK      = (0x15U << IOPORT_PFC_OFFSET),                            ///< P24_3 / ETHER_ESC / ESC_I2CCLK
    IOPORT_PIN_P243_PFC_18_TXD5_SDA5_MOSI5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P24_3 / SCIn / TXD5_SDA5_MOSI5
    IOPORT_PIN_P243_PFC_1C_IIC_SCL1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P24_3 / IICn / IIC_SCL1
    IOPORT_PIN_P243_PFC_1E_SPI_MOSI1       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P24_3 / SPIn / SPI_MOSI1
    IOPORT_PIN_P243_PFC_21_MDAT12          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P24_3 / DSMIFn / MDAT12
    IOPORT_PIN_P243_PFC_29_HDSL0_LINK      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P24_3 / HDSLn / HDSL0_LINK
    IOPORT_PIN_P243_PFC_2C_SD0_PWEN        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P24_3 / SDHIn / SD0_PWEN

    IOPORT_PIN_P244_PFC_02_ETH2_REFCLK     = (0x02U << IOPORT_PFC_OFFSET),                            ///< P24_4 / ETHER_ETHn / ETH2_REFCLK
    IOPORT_PIN_P244_PFC_03_RMII2_REFCLK    = (0x03U << IOPORT_PFC_OFFSET),                            ///< P24_4 / ETHER_ETHn / RMII2_REFCLK
    IOPORT_PIN_P244_PFC_08_POE11           = (0x08U << IOPORT_PFC_OFFSET),                            ///< P24_4 / MTU_POE3 / POE11
    IOPORT_PIN_P244_PFC_09_GTIOC4_6A       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P24_4 / GPTn / GTIOC4_6A
    IOPORT_PIN_P244_PFC_0D_CMTW0_TOC1      = (0x0DU << IOPORT_PFC_OFFSET),                            ///< P24_4 / CMTW / CMTW0_TOC1
    IOPORT_PIN_P244_PFC_10_ETH1_RXER       = (0x10U << IOPORT_PFC_OFFSET),                            ///< P24_4 / ETHER_ETHn / ETH1_RXER
    IOPORT_PIN_P244_PFC_15_ESC_I2CDATA     = (0x15U << IOPORT_PFC_OFFSET),                            ///< P24_4 / ETHER_ESC / ESC_I2CDATA
    IOPORT_PIN_P244_PFC_18_RXD5_SCL5_MISO5 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P24_4 / SCIn / RXD5_SCL5_MISO5
    IOPORT_PIN_P244_PFC_1C_IIC_SDA1        = (0x1CU << IOPORT_PFC_OFFSET),                            ///< P24_4 / IICn / IIC_SDA1
    IOPORT_PIN_P244_PFC_1E_SPI_MISO1       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P24_4 / SPIn / SPI_MISO1
    IOPORT_PIN_P244_PFC_21_MCLK12          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P24_4 / DSMIFn / MCLK12
    IOPORT_PIN_P244_PFC_29_HDSL0_SMPL      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P24_4 / HDSLn / HDSL0_SMPL
    IOPORT_PIN_P244_PFC_2C_SD0_IOVS        = (0x2CU << IOPORT_PFC_OFFSET),                            ///< P24_4 / SDHIn / SD0_IOVS

    IOPORT_PIN_P245_PFC_08_POE10           = (0x08U << IOPORT_PFC_OFFSET),                            ///< P24_5 / MTU_POE3 / POE10
    IOPORT_PIN_P245_PFC_09_GTIOC4_6B       = (0x09U << IOPORT_PFC_OFFSET),                            ///< P24_5 / GPTn / GTIOC4_6B
    IOPORT_PIN_P245_PFC_0C_GTETRGA         = (0x0CU << IOPORT_PFC_OFFSET),                            ///< P24_5 / GPT_POEG / GTETRGA
    IOPORT_PIN_P245_PFC_18_TXD4_SDA4_MOSI4 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P24_5 / SCIn / TXD4_SDA4_MOSI4
    IOPORT_PIN_P245_PFC_1A_SCIEXTCLK       = (0x1AU << IOPORT_PFC_OFFSET),                            ///< P24_5 / CGC / SCIEXTCLK
    IOPORT_PIN_P245_PFC_21_MDAT22          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P24_5 / DSMIFn / MDAT22
    IOPORT_PIN_P245_PFC_29_HDSL0_CLK1      = (0x29U << IOPORT_PFC_OFFSET),                            ///< P24_5 / HDSLn / HDSL0_CLK1
    IOPORT_PIN_P245_PFC_2B_PCIE_RSTOUTB    = (0x2BU << IOPORT_PFC_OFFSET),                            ///< P24_5 / PCIE / PCIE_RSTOUTB

    IOPORT_PIN_P246_PFC_11_GMAC0_MDC = (0x11U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_GMACn / GMAC0_MDC
    IOPORT_PIN_P246_PFC_12_GMAC1_MDC = (0x12U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_GMACn / GMAC1_MDC
    IOPORT_PIN_P246_PFC_13_GMAC2_MDC = (0x13U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_GMACn / GMAC2_MDC
    IOPORT_PIN_P246_PFC_14_ETHSW_MDC = (0x14U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_ETHSW / ETHSW_MDC
    IOPORT_PIN_P246_PFC_15_ESC_MDC   = (0x15U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_ESC / ESC_MDC
    IOPORT_PIN_P246_PFC_18_DE5       = (0x18U << IOPORT_PFC_OFFSET),                                  ///< P24_6 / SCIn / DE5
    IOPORT_PIN_P246_PFC_2F_ESWM_MDC  = (0x2FU << IOPORT_PFC_OFFSET),                                  ///< P24_6 / ETHER_ESWM / ESWM_MDC

    IOPORT_PIN_P247_PFC_11_GMAC0_MDIO      = (0x11U << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_GMACn / GMAC0_MDIO
    IOPORT_PIN_P247_PFC_12_GMAC1_MDIO      = (0x12U << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_GMACn / GMAC1_MDIO
    IOPORT_PIN_P247_PFC_13_GMAC2_MDIO      = (0x13U << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_GMACn / GMAC2_MDIO
    IOPORT_PIN_P247_PFC_14_ETHSW_MDIO      = (0x14U << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_ETHSW / ETHSW_MDIO
    IOPORT_PIN_P247_PFC_15_ESC_MDIO        = (0x15U << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_ESC / ESC_MDIO
    IOPORT_PIN_P247_PFC_18_TXD3_SDA3_MOSI3 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P24_7 / SCIn / TXD3_SDA3_MOSI3
    IOPORT_PIN_P247_PFC_1D_CANRX1          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P24_7 / CANFDn / CANRX1
    IOPORT_PIN_P247_PFC_1E_SPI_RSPCK1      = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P24_7 / SPIn / SPI_RSPCK1
    IOPORT_PIN_P247_PFC_2F_ESWM_MDIO       = (0x2FU << IOPORT_PFC_OFFSET),                            ///< P24_7 / ETHER_ESWM / ESWM_MDIO

    IOPORT_PIN_P250_PFC_14_ETHSW_PHYLINK2  = (0x14U << IOPORT_PFC_OFFSET),                            ///< P25_0 / ETHER_ETHSW / ETHSW_PHYLINK2
    IOPORT_PIN_P250_PFC_15_ESC_PHYLINK2    = (0x15U << IOPORT_PFC_OFFSET),                            ///< P25_0 / ETHER_ESC / ESC_PHYLINK2
    IOPORT_PIN_P250_PFC_18_RXD1_SCL1_MISO1 = (0x18U << IOPORT_PFC_OFFSET),                            ///< P25_0 / SCIn / RXD1_SCL1_MISO1
    IOPORT_PIN_P250_PFC_19_RXD3_SCL3_MISO3 = (0x19U << IOPORT_PFC_OFFSET),                            ///< P25_0 / SCIn / RXD3_SCL3_MISO3
    IOPORT_PIN_P250_PFC_1D_CANTX1          = (0x1DU << IOPORT_PFC_OFFSET),                            ///< P25_0 / CANFDn / CANTX1
    IOPORT_PIN_P250_PFC_1E_SPI_SSL03       = (0x1EU << IOPORT_PFC_OFFSET),                            ///< P25_0 / SPIn / SPI_SSL03
    IOPORT_PIN_P250_PFC_21_MCLK22          = (0x21U << IOPORT_PFC_OFFSET),                            ///< P25_0 / DSMIFn / MCLK22

    /** Marks end of enum - used by parameter checking */
    IOPORT_PERIPHERAL_END
} ioport_pin_pfc_t;

/** Options to configure pin functions  */
typedef enum e_ioport_cfg_options
{
    IOPORT_CFG_PORT_DIRECTION_HIZ          = 0x00000000 << IOPORT_PM_OFFSET, ///< Sets the pin direction to Hi-Z
    IOPORT_CFG_PORT_DIRECTION_INPUT        = 0x00000001 << IOPORT_PM_OFFSET, ///< Sets the pin direction to input (default)
    IOPORT_CFG_PORT_DIRECTION_OUTPUT       = 0x00000002 << IOPORT_PM_OFFSET, ///< Sets the pin direction to output
    IOPORT_CFG_PORT_DIRECTION_OUTPUT_INPUT = 0x00000003 << IOPORT_PM_OFFSET, ///< Sets the pin direction to output (data is input to input buffer)
    IOPORT_CFG_PORT_OUTPUT_LOW             = 0x00000000 << IOPORT_P_OFFSET,  ///< Sets the pin level to low
    IOPORT_CFG_PORT_OUTPUT_HIGH            = 0x00000001 << IOPORT_P_OFFSET,  ///< Sets the pin level to high
    IOPORT_CFG_PORT_GPIO               = 0x00000000 << IOPORT_PMC_OFFSET,    ///< Enables pin to operate as an GPIO pin
    IOPORT_CFG_PORT_PERI               = 0x00000001 << IOPORT_PMC_OFFSET,    ///< Enables pin to operate as a peripheral pin
    IOPORT_CFG_DRIVE_LOW               = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to low
    IOPORT_CFG_DRIVE_MID               = 0x00000001 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to medium
    IOPORT_CFG_DRIVE_HIGH              = 0x00000002 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to high
    IOPORT_CFG_DRIVE_UHIGH             = 0x00000003 << IOPORT_DRCTL_OFFSET,  ///< Sets pin drive output to ultra high
    IOPORT_CFG_PULLUP_DOWN_DISABLE     = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Disables the pin's pull-up / pull-down
    IOPORT_CFG_PULLUP_ENABLE           = 0x00000004 << IOPORT_DRCTL_OFFSET,  ///< Enables the pin's internal pull-up
    IOPORT_CFG_PULLDOWN_ENABLE         = 0x00000008 << IOPORT_DRCTL_OFFSET,  ///< Enables the pin's pull-down
    IOPORT_CFG_SCHMITT_TRIGGER_DISABLE = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Disables schmitt trigger input
    IOPORT_CFG_SCHMITT_TRIGGER_ENABLE  = 0x00000010 << IOPORT_DRCTL_OFFSET,  ///< Enables schmitt trigger input
    IOPORT_CFG_SLEW_RATE_SLOW          = 0x00000000 << IOPORT_DRCTL_OFFSET,  ///< Sets the slew rate to slow
    IOPORT_CFG_SLEW_RATE_FAST          = 0x00000020 << IOPORT_DRCTL_OFFSET,  ///< Sets the slew rate to fast
    IOPORT_CFG_REGION_SAFETY           = 0x00000000 << IOPORT_RSELP_OFFSET,  ///< Selects safety region
    IOPORT_CFG_REGION_NSAFETY          = 0x00000001 << IOPORT_RSELP_OFFSET,  ///< Selects non safety region
    IOPORT_CFG_PIM_TTL                 = 0x00000020,                         ///< This macro has been unsupported
    IOPORT_CFG_NMOS_ENABLE             = 0x00000040,                         ///< This macro has been unsupported
    IOPORT_CFG_PMOS_ENABLE             = 0x00000080,                         ///< This macro has been unsupported
    IOPORT_CFG_DRIVE_HS_HIGH           = 0x00000800,                         ///< This macro has been unsupported
    IOPORT_CFG_DRIVE_MID_IIC           = 0x00000C00,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_RISING_EDGE       = 0x00001000,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_FALLING_EDGE      = 0x00002000,                         ///< This macro has been unsupported
    IOPORT_CFG_EVENT_BOTH_EDGES        = 0x00003000,                         ///< This macro has been unsupported
    IOPORT_CFG_IRQ_ENABLE              = 0x00004000,                         ///< This macro has been unsupported
    IOPORT_CFG_ANALOG_ENABLE           = 0x00008000,                         ///< This macro has been unsupported
    IOPORT_CFG_PERIPHERAL_PIN          = 0x00010000                          ///< This macro has been unsupported
} ioport_cfg_options_t;

/*==============================================
 * ETHER API Overrides
 *==============================================*/

/** Event code of callback function */
typedef enum e_ether_event
{
    ETHER_EVENT_WAKEON_LAN,            ///< Magic packet detection event
    ETHER_EVENT_LINK_ON,               ///< Link up detection event
    ETHER_EVENT_LINK_OFF,              ///< Link down detection event
    ETHER_EVENT_SBD_INTERRUPT,         ///< SBD Interrupt event
    ETHER_EVENT_PMT_INTERRUPT,         ///< PMT Interrupt event

    ETHER_EVENT_RX_COMPLETE,           ///< ESWM: Receive complete event.
    ETHER_EVENT_RX_MESSAGE_LOST,       ///< ESWM: Receive FIFO overflow or Receive descriptor is full.
    ETHER_EVENT_TX_COMPLETE,           ///< ESWM: Transmit complete event.
} ether_event_t;

/** Ether Callback function parameter data */
struct st_ether_callback_args
{
    uint32_t      channel;             ///< Device channel number
    ether_event_t event;               ///< Event code

    uint32_t status_ether;             ///< Interrupt status of SDB or PMT
    uint32_t status_link;              ///< Link status

    void * p_context;                  ///< Placeholder for user data.
};

/** Ether Callback function parameter data Please refer to the struct st_ether_callback_args. */
typedef struct st_ether_callback_args ether_callback_args_t;

/*==============================================
 * ETHER SWITCH API Overrides
 *==============================================*/

/** Ether Switch Event code of callback function */
typedef enum e_ether_switch_event
{
    ETHER_SWITCH_EVENT_LINK_CHANGE,     ///< ETHSW: Change Link status

    ETHER_SWITCH_EVENT_RX_COMPLETE,     ///< ESWM: A descriptor complete to receive a flame.
    ETHER_SWITCH_EVENT_TX_COMPLETE,     ///< ESWM: A descriptor complete to transmit a flame.
    ETHER_SWITCH_EVENT_RX_QUEUE_FULL,   ///< ESWM: A RX descriptor queue is full.
    ETHER_SWITCH_EVENT_RX_MESSAGE_LOST, ///< ESWM: Receive a frame when a RX descriptor queue is full.
    ETHER_SWITCH_EVENT_TAS_ERROR,       ///< ESWM: TAS gate error.
} ether_switch_event_t;

/** Ether Switch Callback function parameter data */
struct st_ether_switch_callback_args
{
    uint32_t channel;                  ///< ETHSW/ESWM: Device channel number
    uint32_t ports;                    ///< ESWM:       Bitmap of ports on which the interrupt occurred.

    ether_switch_event_t event;        ///< ETHSW/ESWM: The event can be used to identify what caused the callback.

    uint32_t status_link;              ///< ETHSW:      Link status bit0:port0. bit1:port1. bit2:port2, bit3:port3
    uint32_t queue_index;              ///< ESWM:       Queue index where a interrupt occurs.
    void   * p_context;                ///< ETHSW/ESWM: Placeholder for user data.  Set in @ref RZT::ether_switch_api_t::open function in @ref RZT::ether_switch_cfg_t.
};

/** Ether Switch Callback function parameter data Please refer to the struct st_ether_switch_callback_args. */
typedef struct st_ether_switch_callback_args ether_switch_callback_args_t;

/*==============================================
 * ETHER PHY API Overrides
 *==============================================*/

/** Phy LSI */
typedef enum e_ether_phy_lsi_type
{
    ETHER_PHY_LSI_TYPE_DEFAULT = 0,     ///< Select default configuration. This type dose not change Phy LSI default setting by strapping option.
    ETHER_PHY_LSI_TYPE_VSC8541 = 1,     ///< Select configuration forVSC8541
    ETHER_PHY_LSI_TYPE_KSZ9131 = 2,     ///< Select configuration forKSZ9131
    ETHER_PHY_LSI_TYPE_KSZ9031 = 3,     ///< Select configuration forKSZ9031
    ETHER_PHY_LSI_TYPE_KSZ8081 = 4,     ///< Select configuration forKSZ8081
    ETHER_PHY_LSI_TYPE_KSZ8041 = 5,     ///< Select configuration forKSZ8041
    ETHER_PHY_LSI_TYPE_CUSTOM  = 0xFFU, ///< Select configuration for User custom.
} ether_phy_lsi_type_t;

/*==============================================
 * NAND FLASH API Overrides
 *==============================================*/

/** Timing information during communication with the NAND Flash */
struct st_nand_flash_timing_info
{
    uint32_t we_pulse_width;                        ///< WE_n pulse width cycles
    uint32_t we_high_hold_time;                     ///< WE_n high hold time cycles
    uint32_t re_pulse_width;                        ///< RE_n pulse width cycles
    uint32_t re_high_hold_time;                     ///< RE_n high hold time cycles
    uint32_t re_high_to_we_low_time;                ///< RE_n high to WE_n low time cycles
    uint32_t we_high_to_re_low_time;                ///< WE_n high to RE_n low time cycles
    uint32_t ale_to_data_loading_time;              ///< ALE to data loading time cycles
    uint32_t command_end_to_sr6_low;                ///< Command end timing to SR[6] low cycles
    uint32_t re_high_to_output_hiz;                 ///< RE_n high to output hi-Z cycles
    uint32_t ce_setup_time;                         ///< CE_n setup time cycles
    uint32_t ce_high_hold_time;                     ///< CE_n high hold time cycles
    uint32_t interface_and_timing_mode_change_time; ///< Interface and Timing Mode Change time cycles
};

/** Timing information during communication with the NAND Flash Please refer to the struct st_nand_flash_timing_info. */
typedef struct st_nand_flash_timing_info nand_flash_timing_info_t;

/*==============================================
 * POE3 API Overrides
 *==============================================*/

/** POE3 states. */
typedef enum e_poe3_state
{
    POE3_STATE_NO_DISABLE_REQUEST           = 0,                ///< Timer output is not disabled by POE3
    POE3_STATE_POE0_HIGH_IMPEDANCE_REQUEST  = 1U,               ///< Timer output disabled due to POE0# pin
    POE3_STATE_POE4_HIGH_IMPEDANCE_REQUEST  = 1U << 1,          ///< Timer output disabled due to POE4# pin
    POE3_STATE_POE8_HIGH_IMPEDANCE_REQUEST  = 1U << 2,          ///< Timer output disabled due to POE8# pin
    POE3_STATE_POE10_HIGH_IMPEDANCE_REQUEST = 1U << 3,          ///< Timer output disabled due to POE10# pin
    POE3_STATE_POE11_HIGH_IMPEDANCE_REQUEST = 1U << 4,          ///< Timer output disabled due to POE11# pin

    POE3_STATE_SOFTWARE_STOP_DISABLE_REQUEST = 1U << 5,         ///< Timer output disabled due to poe3_api_t::outputDisable()

    POE3_STATE_OSCILLATION_STOP_DISABLE_REQUEST = 1U << 6,      ///< Timer output disabled due to main oscillator stop

    POE3_STATE_OUTPUT_SHORT_CIRCUIT_1_ERROR_REQUEST = 1U << 9,  ///< Timer output disabled due to output short circuit 1
    POE3_STATE_OUTPUT_SHORT_CIRCUIT_2_ERROR_REQUEST = 1U << 10, ///< Timer output disabled due to output short circuit 2

    POE3_STATE_DSMIF0_ERROR_REQUEST   = 1U << 11,               ///< Timer output disabled due to DSMIF0 Error0
    POE3_STATE_DSMIF1_ERROR_REQUEST   = 1U << 12,               ///< Timer output disabled due to DSMIF1 Error0
    POE3_STATE_DSMIF2_ERROR_REQUEST   = 1U << 13,               ///< Timer output disabled due to DSMIF2 Error0
    POE3_STATE_DSMIF3_ERROR_REQUEST   = 1U << 14,               ///< Timer output disabled due to DSMIF3 Error0
    POE3_STATE_DSMIF4_ERROR_REQUEST   = 1U << 15,               ///< Timer output disabled due to DSMIF4 Error0
    POE3_STATE_DSMIF0_1_ERROR_REQUEST = 1U << 21,               ///< Timer output disabled due to DSMIF0 Error1
    POE3_STATE_DSMIF1_1_ERROR_REQUEST = 1U << 22,               ///< Timer output disabled due to DSMIF1 Error1
    POE3_STATE_DSMIF2_1_ERROR_REQUEST = 1U << 23,               ///< Timer output disabled due to DSMIF2 Error1
    POE3_STATE_DSMIF3_1_ERROR_REQUEST = 1U << 24,               ///< Timer output disabled due to DSMIF3 Error1
    POE3_STATE_DSMIF4_1_ERROR_REQUEST = 1U << 25,               ///< Timer output disabled due to DSMIF4 Error1
} poe3_state_t;

/** POE3 active level for short circuit detection. */
typedef enum e_poe3_active_level
{
    POE3_ACTIVE_LEVEL_HIGH         = 1U,    ///< High level is set as the active level to detect a short circuit.
    POE3_ACTIVE_LEVEL_LOW          = 0U,    ///< Low level is set as the active level to detect a short circuit.
    POE3_ACTIVE_LEVEL_SETTING_NONE = 0xFFU, ///< The active level of the pin is set by the timer peripheral side, not by POE3.
} poe3_active_level_t;

/*==============================================
 * POEG API Overrides
 *==============================================*/

/** POEG states. */
typedef enum e_poeg_state
{
    POEG_STATE_NO_DISABLE_REQUEST                = 0,       ///< GPT output is not disabled by POEG
    POEG_STATE_PIN_DISABLE_REQUEST               = 1U << 0, ///< GPT output disabled due to GTETRG pin level
    POEG_STATE_GPT_OR_COMPARATOR_DISABLE_REQUEST = 1U << 1, ///< GPT output disabled due to high speed analog comparator or GPT
    POEG_STATE_OSCILLATION_STOP_DISABLE_REQUEST  = 1U << 2, ///< GPT output disabled due to main oscillator stop
    POEG_STATE_SOFTWARE_STOP_DISABLE_REQUEST     = 1U << 3, ///< GPT output disabled due to poeg_api_t::outputDisable()

    POEG_STATE_DSMIF0_DISABLE_REQUEST = 1U << 4,            ///< GPT output disabled due to DSMIF0 error 0
    POEG_STATE_DSMIF1_DISABLE_REQUEST = 1U << 5,            ///< GPT output disabled due to DSMIF1 error 0
    POEG_STATE_DSMIF2_DISABLE_REQUEST = 1U << 6,            ///< GPT output disabled due to DSMIF2 error 0
    POEG_STATE_DSMIF3_DISABLE_REQUEST = 1U << 7,            ///< GPT output disabled due to DSMIF3 error 0
    POEG_STATE_DSMIF4_DISABLE_REQUEST = 1U << 8,            ///< GPT output disabled due to DSMIF4 error 0

    /** GPT output disable request active from the GTETRG pin. If a filter is used, this flag represents the state of
     * the filtered input. */
    POEG_STATE_PIN_DISABLE_REQUEST_ACTIVE = 1U << 16,

    POEG_STATE_DSMIF0_1_DISABLE_REQUEST = 1U << 20, ///< GPT output disabled due to DSMIF0 error 1
    POEG_STATE_DSMIF1_1_DISABLE_REQUEST = 1U << 21, ///< GPT output disabled due to DSMIF1 error 1
    POEG_STATE_DSMIF2_1_DISABLE_REQUEST = 1U << 22, ///< GPT output disabled due to DSMIF2 error 1
    POEG_STATE_DSMIF3_1_DISABLE_REQUEST = 1U << 23, ///< GPT output disabled due to DSMIF3 error 1
    POEG_STATE_DSMIF4_1_DISABLE_REQUEST = 1U << 24, ///< GPT output disabled due to DSMIF4 error 1
} poeg_state_t;

/** Triggers that will disable GPT output pins. */
typedef enum e_poeg_trigger
{
    /** Software disable is always supported with POEG. Select this option if no other triggers are used. */
    POEG_TRIGGER_SOFTWARE         = 0U,
    POEG_TRIGGER_PIN              = 1U << 0, ///< Disable GPT output based on GTETRG input level(PIDE)
    POEG_TRIGGER_GPT_OUTPUT_LEVEL = 1U << 1, ///< Disable GPT output based on GPT output pin levels(IOCE)
    POEG_TRIGGER_OSCILLATION_STOP = 1U << 2, ///< Disable GPT output based on main oscillator stop(OSPTE)
    POEG_TRIGGER_ACMPHS0          = 1U << 4, ///< Disable GPT output based on ACMPHS0 comparator result
    POEG_TRIGGER_ACMPHS1          = 1U << 5, ///< Disable GPT output based on ACMPHS1 comparator result
    POEG_TRIGGER_ACMPHS2          = 1U << 6, ///< Disable GPT output based on ACMPHS2 comparator result
    POEG_TRIGGER_ACMPHS3          = 1U << 7, ///< Disable GPT output based on ACMPHS3 comparator result
    POEG_TRIGGER_ACMPHS4          = 1U << 8, ///< Disable GPT output based on ACMPHS4 comparator result
    POEG_TRIGGER_ACMPHS5          = 1U << 9, ///< Disable GPT output based on ACMPHS5 comparator result

    /** The GPT output pins can be disabled when DSMIF error occurs (LLPP only). */
    POEG_TRIGGER_D0ERR0E = 1U << 10,         ///< Permit output disabled by DSMIF0 error detection
    POEG_TRIGGER_D1ERR0E = 1U << 11,         ///< Permit output disabled by DSMIF1 error detection
    POEG_TRIGGER_D2ERR0E = 1U << 12,         ///< Permit output disabled by DSMIF2 error detection
    POEG_TRIGGER_D3ERR0E = 1U << 13,         ///< Permit output disabled by DSMIF3 error detection
    POEG_TRIGGER_D4ERR0E = 1U << 14,         ///< Permit output disabled by DSMIF4 error detection
    POEG_TRIGGER_D0ERR1E = 1U << 20,         ///< Permit output disabled by DSMIF0 error 1 detection
    POEG_TRIGGER_D1ERR1E = 1U << 21,         ///< Permit output disabled by DSMIF1 error 1 detection
    POEG_TRIGGER_D2ERR1E = 1U << 22,         ///< Permit output disabled by DSMIF2 error 1 detection
    POEG_TRIGGER_D3ERR1E = 1U << 23,         ///< Permit output disabled by DSMIF3 error 1 detection
    POEG_TRIGGER_D4ERR1E = 1U << 24,         ///< Permit output disabled by DSMIF4 error 1 detection
} poeg_trigger_t;

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
    TIMER_EVENT_TROUGH,                        ///< Timer trough event (counter is 0, triangle-wave PWM only)
    TIMER_EVENT_COMPARE_A,                     ///< A compare has occurred on signal A
    TIMER_EVENT_COMPARE_B,                     ///< A compare has occurred on signal B
    TIMER_EVENT_COMPARE_C,                     ///< A compare has occurred on signal C
    TIMER_EVENT_COMPARE_D,                     ///< A compare has occurred on signal D
    TIMER_EVENT_COMPARE_E,                     ///< A compare has occurred on signal E
    TIMER_EVENT_COMPARE_F,                     ///< A compare has occurred on signal F
    TIMER_EVENT_DEAD_TIME,                     ///< Dead time event
    TIMER_EVENT_PERIOD_COUNT_END               ///< Period count finish event.
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
    TRANSFER_SIZE_1_BYTE  = 0,         ///< Each transfer transfers a 8-bit value
    TRANSFER_SIZE_2_BYTE  = 1,         ///< Each transfer transfers a 16-bit value
    TRANSFER_SIZE_4_BYTE  = 2,         ///< Each transfer transfers a 32-bit value
    TRANSFER_SIZE_8_BYTE  = 3,         ///< Each transfer transfers a 64-bit value
    TRANSFER_SIZE_16_BYTE = 4,         ///< Each transfer transfers a 128-bit value
    TRANSFER_SIZE_32_BYTE = 5,         ///< Each transfer transfers a 256-bit value
    TRANSFER_SIZE_64_BYTE = 6          ///< Each transfer transfers a 512-bit value
} transfer_size_t;

/** Address mode specifies whether to modify (increment or decrement) pointer after each transfer. */
typedef enum e_transfer_addr_mode
{
    /** Address pointer is incremented by associated @ref RZT::transfer_size_t after each transfer. */
    TRANSFER_ADDR_MODE_INCREMENTED = 0,

    /** Address pointer remains fixed after each transfer. */
    TRANSFER_ADDR_MODE_FIXED = 1
} transfer_addr_mode_t;

/** Callback function parameter data. */
struct st_transfer_callback_args_t
{
    transfer_event_t event;            ///< Event code
    void           * p_context;        ///< Placeholder for user data. Set in transfer_api_t::open function in ::transfer_cfg_t.
};

/** Callback function parameter data. Please refer to the struct st_transfer_callback_args_t. */
typedef struct st_transfer_callback_args_t transfer_callback_args_t;

/** This structure specifies the properties of the transfer. */
struct st_transfer_info
{
    /** Select what happens to destination pointer after each transfer. */
    transfer_addr_mode_t dest_addr_mode;

    /** Select what happens to source pointer after each transfer. */
    transfer_addr_mode_t src_addr_mode;

    /** Select mode from @ref RZT::transfer_mode_t. */
    transfer_mode_t mode;

    /** Source pointer. */
    void const * volatile p_src;

    /** Destination pointer. */
    void * volatile p_dest;

    /** Length of each transfer. */
    volatile uint32_t length;

    /** Select number of source bytes to transfer at once. */
    transfer_size_t src_size;

    /** Select number of destination bytes to transfer at once. */
    transfer_size_t dest_size;

    /** Next1 Register set settings */
    void const * p_next1_src;
    void       * p_next1_dest;
    uint32_t     next1_length;
};

/** This structure specifies the properties of the transfer. Please refer to the struct st_transfer_info. */
typedef struct st_transfer_info transfer_info_t;

/*=========================================================
 * ADC API Override using other override definitions
 *=========================================================*/

/** ADC Information Structure for Transfer Interface */
struct st_adc_info
{
    volatile const void * p_address;         ///< The address to start reading the data from
    uint32_t              length;            ///< The total number of transfers to read
    transfer_size_t       transfer_size;     ///< The size of each transfer
    elc_peripheral_t      elc_peripheral;    ///< Name of the peripheral in the ELC list
    elc_event_t           elc_event;         ///< Name of the ELC event for the peripheral
    uint32_t              calibration_data1; ///< Temperature sensor calibration data1
    uint32_t              calibration_data2; ///< Temperature sensor calibration data2
    int16_t               slope_microvolts;  ///< Temperature sensor slope in microvolts/degrees C
    bool calibration_ongoing;                ///< Calibration is in progress.
};

/** ADC Information Structure for Transfer Interface Please refer to the struct st_adc_info. */
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

/** Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif
