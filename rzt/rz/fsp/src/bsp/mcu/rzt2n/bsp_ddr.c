/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes <System Includes> , "Project Includes"
 **********************************************************************************************************************/
#include <stdio.h>
#include "bsp_api.h"

#if (BSP_FEATURE_DDR_SUPPORTED)
 #if (1 == BSP_CFG_DDR_INIT_ENABLE)
  #include "bsp_ddr.h"

  #if (1 == BSP_CFG_BOARD_RZT2N_EVB)
   #if defined(BOARD_RZT2N_489_EVB)
    #include "../../../../../board/rzt2n_489_evb/board_ddr_param.h"
   #endif
   #if defined(BOARD_RZT2N_EVB)
    #include "../../../../../board/rzt2n_evb/board_ddr_param.h"
   #endif
  #elif (1 == BSP_CFG_BOARD_CUSTOM)
   #include "../../../../../board/custom/board_ddr_param.h"
  #endif

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/
  #define BSP_DDR_PHY_PULL_UP_ODT        (0)  /* LPDDR4 uses pull down ODT on PHY side */
  #define BSP_DDR_DRAM_PULL_UP_ODT       (0)  /* LPDDR4 uses pull down ODT on DRAM side */

  #define BSP_DDR_MAX_VREF_TRIM_PHY      (64) /* Max VREF trim value supported by PHY selected based on pull down or pull up ODT */
                                              /* Because UVREF supports 2 trim ranges depending on pull down or pull up ODT */

  #define BSP_DDR_SWEEP_LIMIT            (80) /* Total number of unique VREF trim settings */
                                              /* supported by DRAM including both range 0 and range 1 */
  #define BSP_DDR_MAX_BEST_VREF_SAVED    (30) /* Maximum number of BEST VREF settings that we need to save */

  #define BSP_DDR_VREF_STEP_SIZE         (1U)

  #define BSP_DDR_PHY_MAX_VREF_TRIM      (BSP_DDR_PHY_PULL_UP_ODT ? 126 : 64)
  #define BSP_DDR_DRAM_MAX_VREF_TRIM     (BSP_DDR_DRAM_PULL_UP_ODT ? 126 : 64)
  #define BSP_DDR_DRAM_SWEEP_LIMIT       (80) /* Total number of unique VREF trim settings for LPDDR4 */

  #define BSP_DDRTOP_ECC_END_ADDR_DEF    (0x000000FFF)

  #define BSP_DDR_SW_DLY_100             (100)

  #define BSP_DDR_MAS_DLY_200            (200)

  #define BSP_DDR_DQ_VREF_CALC_40        (40)
  #define BSP_DDR_DQ_VREF_CALC_50        (50)
  #define BSP_DDR_DQ_VREF_CALC_66        (66)
  #define BSP_DDR_DQ_VREF_CALC_128       (128)
  #define BSP_DDR_DQ_VREF_CALC_512       (512)
  #define BSP_DDR_DQ_VREF_CALC_1000      (1000)
  #define BSP_DDR_DQ_VREF_CALC_4000      (4000)
  #define BSP_DDR_DQ_VREF_CALC_6600      (6600)

  #define BSP_DDR_CLK_CALC_1000          (1000)
  #define BSP_DDR_CLK_CALC_1736          (1736)
  #define BSP_DDR_CLK_CALC_2176          (2176)
  #define BSP_DDR_CLK_CALC_3840          (3840)
  #define BSP_DDR_CLK_CALC_18560         (18560)

  #define BSP_DDR_CLK_CHECK_1364         (1364)
  #define BSP_DDR_CLK_CHECK_1500         (1500)
  #define BSP_DDR_CLK_CHECK_2500         (2500)

  #define BSP_DDR_CAS_CALC_51            (51)
  #define BSP_DDR_CAS_CALC_62            (62)
  #define BSP_DDR_CAS_CALC_256           (0x100)
  #define BSP_DDR_CAS_CALC_2500          (2500)

  #define BSP_DDR_REGNO_0F               (0x0F)
  #define BSP_DDR_REGNO_14               (0x14)
  #define BSP_DDR_REGNO_20               (0x20)
  #define BSP_DDR_REGNO_28               (0x28)

  #define BSP_DDR_OPECODE_00             (0x00)
  #define BSP_DDR_OPECODE_AA             (0xAA)

  #define BSP_DDR_SET_100000D            (100000)
  #define BSP_DDR_SET_200000D            (200000)
  #define BSP_DDR_SET_250000D            (250000)

  #define BSP_DDR_SET_27                 (0x27)
  #define BSP_DDR_SET_28                 (0x28)
  #define BSP_DDR_SET_34                 (0x34)
  #define BSP_DDR_SET_7F                 (0x7F)
  #define BSP_DDR_SET_C0                 (0xC0)
  #define BSP_DDR_SET_C8                 (0xC8)
  #define BSP_DDR_SET_FF                 (0xFF)
  #define BSP_DDR_SET_00000100           (0x00000100)
  #define BSP_DDR_SET_00000123           (0x00000123)
  #define BSP_DDR_SET_000001CF           (0x000001CF)
  #define BSP_DDR_SET_000001FF           (0x000001FF)
  #define BSP_DDR_SET_00000200           (0x00000200)
  #define BSP_DDR_SET_00000400           (0x00000400)
  #define BSP_DDR_SET_00001801           (0x00001801)
  #define BSP_DDR_SET_00002028           (0x00002028)
  #define BSP_DDR_SET_00003E90           (0x00003E90)
  #define BSP_DDR_SET_00010000           (0x00010000)
  #define BSP_DDR_SET_00010001           (0x00010001)
  #define BSP_DDR_SET_0006010A           (0x0006010A)
  #define BSP_DDR_SET_00080108           (0x00080108)
  #define BSP_DDR_SET_000A0106           (0x000A0106)
  #define BSP_DDR_SET_000A5066           (0x000A5066)
  #define BSP_DDR_SET_000C0104           (0x000C0104)
  #define BSP_DDR_SET_01000000           (0x01000000)
  #define BSP_DDR_SET_05009000           (0x05009000)
  #define BSP_DDR_SET_05011000           (0x05011000)
  #define BSP_DDR_SET_0E71B1A9           (0x0E71B1A9)
  #define BSP_DDR_SET_10000000           (0x10000000)
  #define BSP_DDR_SET_1000C000           (0x1000C000)
  #define BSP_DDR_SET_140B002D           (0x140B002D)
  #define BSP_DDR_SET_710E4A56           (0x710E4A56)
  #define BSP_DDR_SET_789A3CE0           (0x789A3CE0)
  #define BSP_DDR_SET_8764C232           (0x8764C232)
  #define BSP_DDR_SET_90000000           (0x90000000)
  #define BSP_DDR_SET_9F000000           (0x9F000000)
  #define BSP_DDR_SET_AA00AA00           (0xAA00AA00)

  #define BSP_DDR_MASK_34                (0x34)
  #define BSP_DDR_MASK_3F                (0x3F)
  #define BSP_DDR_MASK_44                (0b01000100)
  #define BSP_DDR_MASK_7F                (0x7F)
  #define BSP_DDR_MASK_80                (0x80)
  #define BSP_DDR_MASK_C2                (0b11000010)
  #define BSP_DDR_MASK_F8                (0xF8)
  #define BSP_DDR_MASK_FF                (0xFF)
  #define BSP_DDR_MASK_0100              (0x0100)
  #define BSP_DDR_MASK_01FF              (0x01FF)
  #define BSP_DDR_MASK_03FF              (0x03FF)
  #define BSP_DDR_MASK_0000FFFF          (0x0000FFFF)
  #define BSP_DDR_MASK_0000FFFFULL       (0x0000FFFFULL)
  #define BSP_DDR_MASK_0003FFFF          (0x0003FFFF)
  #define BSP_DDR_MASK_007FFFFF          (0x007FFFFF)
  #define BSP_DDR_MASK_01000000          (0x01000000)
  #define BSP_DDR_MASK_01000001          (0x01000001)
  #define BSP_DDR_MASK_01FF0000          (0x01FF0000)
  #define BSP_DDR_MASK_07FFFFFF          (0x07FFFFFF)
  #define BSP_DDR_MASK_0FFFFFFF          (0x0FFFFFFF)
  #define BSP_DDR_MASK_7FFFFFFF          (0x7FFFFFFF)
  #define BSP_DDR_MASK_BF000000          (0xBF000000)
  #define BSP_DDR_MASK_FFFF0000          (0xFFFF0000)
  #define BSP_DDR_MASK_FFFFFFFF          (0xFFFFFFFF)

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables (to be accessed by other files)
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private global variables and functions
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_reg(void);

static void bsp_prv_ddr_mc_mrw(uint8_t mr, uint8_t op, uint8_t cs);
static void bsp_prv_ddr_freq_change_init_lp4(uint32_t target_fsp);
static void bsp_prv_ddr_proc_switch_fsp(unsigned int target_fsp);

static void bsp_prv_ddr_proc_prog0(uint64_t start_addr, uint8_t addr_space, uint8_t run_mode);
static void bsp_prv_ddr_proc_ecc_init0(const uint64_t range[][2], uint32_t num_of_ranges);

static void bsp_prv_ddr_init_reset_release(void);
static void bsp_prv_ddr_init_phy_update_after_training(void);
static void bsp_prv_ddr_init_mc_update_after_training(void);

static uint32_t bsp_prv_ddr_init_hwdfs_start(uint32_t target_fsp);
static void     bsp_prv_ddr_init_hwdfs_clock_change(void);
static uint32_t bsp_prv_ddr_init_hwdfs_finish(void);

/* Tasks for command bus training */
static void bsp_prv_ddr_init_phy_swizzle(void);
static void bsp_prv_ddr_init_mc_swizzle(void);
static void bsp_prv_ddr_init_mc_write_regmap(uint32_t proc_status);
static void bsp_prv_ddr_init_dram_sequence(uint32_t num_ranks);

static uint32_t bsp_prv_ddr_init_read_bit_leveling(uint32_t bit_lvl_from_saved);
static uint32_t bsp_prv_ddr_init_write_bit_leveling(uint32_t bit_lvl_from_saved);

static uint32_t bsp_prv_ddr_init_scl(uint32_t rank,
                                     uint32_t bit_lvl_from_saved,
                                     uint32_t scl_second_try,
                                     uint32_t run_WR_BIT_LEVELING,
                                     uint32_t scl_start_addr_X,
                                     uint32_t val_NATIVE_BURST8);
static void bsp_prv_ddr_init_vref_dq_training_wrapper(uint32_t rank, uint32_t num_ranks);
static void bsp_prv_ddr_init_vref_dq_training(uint32_t DQ_vref_mid_level,
                                              uint8_t  DQ_vref_mid_level_code,
                                              uint8_t  DQ_sweep_range,
                                              uint8_t  DQ_vref_step_size,
                                              uint8_t  DQ_max_vref_trim_phy,
                                              uint32_t DRAM_vref_mid_level,
                                              uint8_t  DRAM_vref_mid_level_code,
                                              uint8_t  DRAM_sweep_range,
                                              uint8_t  DRAM_vref_step_size,
                                              uint8_t  DRAM_max_vref_trim_phy,
                                              uint8_t  DRAM_sweep_limit,
                                              uint8_t  DRAM_mem_chip_selects,
                                              uint32_t RUN_PHY_VREF,
                                              uint32_t RUN_DRAM_VREF,
                                              uint32_t bit_lvl_sample_qty);
static void bsp_prv_ddr_init_phy_vref_dq_training(uint32_t vref_mid_level,
                                                  uint32_t vref_mid_level_code,
                                                  uint32_t sweep_range,
                                                  uint32_t vref_step_size,
                                                  uint32_t max_vref_trim_phy,
                                                  uint32_t best_vref_setting_lane[2]);
static void bsp_prv_ddr_init_find_vref_window(uint8_t window_diff[2], uint32_t current_vref);
static void bsp_prv_ddr_init_dram_vref_dq_training(uint32_t vref_mid_level,
                                                   uint8_t  vref_mid_level_code,
                                                   uint8_t  sweep_range,
                                                   uint8_t  vref_step_size,
                                                   uint8_t  max_vref_trim_phy,
                                                   uint8_t  sweep_limit,
                                                   uint8_t  mem_chip_selects,
                                                   uint32_t best_vref_setting_lane[2]);
static void bsp_prv_ddr_init_setup_vref_training_registers(uint8_t vref_value,
                                                           uint8_t mpr_mode,
                                                           uint8_t turn_on_off_training);
static uint32_t bsp_prv_ddr_init_write_leveling(uint32_t rank, uint32_t bit_lvl_from_saved);
static void     bsp_prv_ddr_init_phy_routine(uint32_t num_ranks);

static const uint32_t bsp_ddr_sweep_range_ratio = 15; /* 0.15 * 100 */

/*******************************************************************************************************************//**
 * External unswizzle CA setting.
 **********************************************************************************************************************/
static inline uint8_t bsp_ext_unswizzle_ca (uint32_t ca_bit)
{
    uint8_t ext_unswizzle_ca;

    ext_unswizzle_ca = param_ddr_swizzle_ca[ca_bit];

    return ext_unswizzle_ca;
}

/*******************************************************************************************************************//**
 * External unswizzle CS setting.
 **********************************************************************************************************************/
static inline uint8_t bsp_ext_unswizzle_cs (uint32_t cs_bit)
{
    uint8_t ext_unswizzle_cs;

    ext_unswizzle_cs = param_ddr_swizzle_cs[cs_bit];

    return ext_unswizzle_cs;
}

/*******************************************************************************************************************//**
 * External unswizzle bit setting.
 **********************************************************************************************************************/
static inline uint8_t bsp_ext_unswizzle_bit (uint8_t dq_bit, uint8_t lane)
{
    uint8_t ext_unswizzle_bit;

    ext_unswizzle_bit = param_ddr_swizzle_bit[(lane * 8) + dq_bit] % 8;

    return ext_unswizzle_bit;
}

/*******************************************************************************************************************//**
 * External swizzle CA setting.
 **********************************************************************************************************************/
static inline uint8_t bsp_ext_swizzle_ca (uint8_t ca_bit)
{
    uint8_t ext_swizzle_ca;

    ext_swizzle_ca = ca_bit;
    for (uint8_t i = 0; i < 6; i++)
    {
        ext_swizzle_ca = (bsp_ext_unswizzle_ca(i) == ca_bit ? i : ext_swizzle_ca);
    }

    return ext_swizzle_ca;
}

/*******************************************************************************************************************//**
 * External swizzle CS setting.
 **********************************************************************************************************************/
static inline uint8_t bsp_ext_swizzle_cs (uint8_t cs_bit)
{
    uint8_t ext_swizzle_cs;

    ext_swizzle_cs = cs_bit;
    for (uint8_t i = 0; i < 2; i++)
    {
        ext_swizzle_cs = (bsp_ext_unswizzle_cs(i) == cs_bit ? i : ext_swizzle_cs);
    }

    return ext_swizzle_cs;
}

/*******************************************************************************************************************//**
 * DDR related register initial settings.
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_reg (void)
{
    volatile uint32_t dummy;

    /* DDR Initialization: Start */

    /* SCKCR4 */
    /* b28     : DDRCLKSEL :   0:ddr_clk=12.5kHz,   1:(Refer DDRDIVSEL)         */
    /* b31-b29 : DDRDIVSEL : 0x0:ddr_clk= 800MHz, 0x4:ddr_clk=50MHz             */
    /* Initial setting here should be 50MHz.                                    */
    /* Subsequent DDR initialization code changes it to 800MHz as FSP operation */
    dummy = R_SYSC_NS->SCKCR4;

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);
    R_SYSC_NS->SCKCR4 = ((dummy & BSP_DDR_MASK_0FFFFFFF) | BSP_DDR_SET_90000000);

    /* Wait for 30 dummy reads of register for clock change */
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);

    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);

    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);

    /* Release MC and PHY reset */
    bsp_prv_ddr_init_reset_release();

    /* Initialize System Bus setting for DDR */
    /* NOTE: You can skip this operation if it's already done before */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_SYSTEM);

  #if (BSP_CFG_OTFDE0_SUPPORT_ENABLE || BSP_CFG_OTFDE1_SUPPORT_ENABLE)

    /* Enable OTFDE. */
    uint32_t otfde_enable = 0U;
   #if BSP_CFG_OTFDE0_SUPPORT_ENABLE
    otfde_enable |= R_OTFDE_MISC_OTFDE_ENABLE_EN_P0_Msk;
   #endif
   #if BSP_CFG_OTFDE1_SUPPORT_ENABLE
    otfde_enable |= R_OTFDE_MISC_OTFDE_ENABLE_EN_P1_Msk;
   #endif
    R_OTFDE_MISC->OTFDE_ENABLE = otfde_enable;
  #endif

    /* b0: DDR0R AXI */
    /* b8: DDR APB IF */
    R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_DDRSS_PORT0);
    R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_DDRAPB);

    /* Releasing AMBA bus stop */
    R_BSP_SlaveStopRelease(BSP_BUS_SLAVE_DDRSS_PORT1);

  #if (BSP_CFG_OTFDE0_SUPPORT_ENABLE || BSP_CFG_OTFDE1_SUPPORT_ENABLE)
    bsp_otfde_init();
  #endif

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_SYSTEM);
}

/*******************************************************************************************************************//**
 * @brief Issue MRW command to DRAM through Memory Controller
 * @param mr Mode Register Number
 * @param op Opecode for MR
 * @param cs Ranks for all rank MRW
 **********************************************************************************************************************/
static void bsp_prv_ddr_mc_mrw (uint8_t mr, uint8_t op, uint8_t cs)
{
    uint32_t wrdata;

    R_DDRSS->DDR_MEMC_DENALI_CTL_195_b.MRSINGLE_DATA_0 = op;
    R_DDRSS->DDR_MEMC_DENALI_CTL_195_b.MRSINGLE_DATA_1 = op;

    wrdata = mr << 0 |
             cs << 8 |
             1 << 23 |
             0 << 24 |
             1 << 25;
    R_DDRSS->DDR_MEMC_DENALI_CTL_176_b.WRITE_MODEREG = (wrdata & BSP_DDR_MASK_07FFFFFF);
}

/*******************************************************************************************************************//**
 * @brief Switch Frequency Set Point
 * @param target_fsp the target FSP number
 **********************************************************************************************************************/
static void bsp_prv_ddr_freq_change_init_lp4 (uint32_t target_fsp)
{
    R_DDR_PHY->DDR_PHY_CTRL0 = R_DDR_PHY->DDR_PHY_CTRL0 | (1 << 4);
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS); /* 50ns wait */

    bsp_prv_ddr_proc_switch_fsp(target_fsp);

    {
        /* re-calibrate master DLL after clock frequency change */
        R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE = ((0 << 0) | (1 << 8));
        FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE & ((1 << 8) | (BSP_DDRTOP_SCL_LANES << 12))),
                                   0);

        R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE = ((0 << 0) | (1 << 8));
        FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE & ((1 << 8) | (BSP_DDRTOP_SCL_LANES << 12))),
                                   0);

        R_DDR_PHY->DDR_PHY_DLL_FORCE_CALIB      = 1;
        R_DDR_PHY->DDR_PHY_DPHY_DLL_FORCE_CALIB = BSP_DDRTOP_SCL_LANES;

        FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DLL_FORCE_CALIB & 1), 0);
        FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DPHY_DLL_FORCE_CALIB & BSP_DDRTOP_SCL_LANES), 0);

        R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE = (4 << 0);
    }

    R_DDR_PHY->DDR_PHY_CTRL0 = R_DDR_PHY->DDR_PHY_CTRL0 & ~(uint32_t) (1 << 4);
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS); /* 7.5ns wait */
}

/*******************************************************************************************************************//**
 * @brief Change clock frequency from SYS
 * @param target_fsp the target FSP number
 **********************************************************************************************************************/
static void bsp_prv_ddr_proc_switch_fsp (unsigned int target_fsp)
{
    volatile uint32_t dummy;

    /*  Change clock frequency from SYS */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_CGC);

    /* SYS_CTRL SCKCR4 */
    /* b28 :        DDR_LOW_CLK_SEL : 0 25MHz, 1 initial 200MHz */
    /* b31-b29 : DDR_LOW_CLK_DIVSEL : 000 ddrclk 800MHz, half_rate_clk 400MHz */
    /*                              : 100 ddrclk  50MHz, half_rate_clk  25MHz */
    dummy = R_SYSC_NS->SCKCR4;
    if (1 == target_fsp)
    {
        R_SYSC_NS->SCKCR4 = ((dummy & BSP_DDR_MASK_0FFFFFFF) | BSP_DDR_SET_10000000);
    }
    else
    {
        R_SYSC_NS->SCKCR4 = ((dummy & BSP_DDR_MASK_0FFFFFFF) | BSP_DDR_SET_90000000);
    }

    /* Wait for 10 dummy reads of register for clock change */
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);
    FSP_REGISTER_READ(R_SYSC_NS->SCKCR4);

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_CGC);
}

/*******************************************************************************************************************//**
 * @brief Programming BIST logic to initialize memory area for Inline-ECC
 * @param start_addr 2 ^ addr_space
 * @param addr_space bit[0]:1=first run, bit[1]:1=independent mode (with setting ecc_disable_w_uc_err)
 * @param run_mode
 **********************************************************************************************************************/
static void bsp_prv_ddr_proc_prog0 (uint64_t start_addr, uint8_t addr_space, uint8_t run_mode)
{
    uint32_t lp_auto_entry_en;

    /* Memory initialization program */
    if (1 == ((run_mode >> 1) & 1))
    {
        /* This step should only be executed if the Inline-ECC feature is used. */
        R_DDRSS->DDR_MEMC_DENALI_CTL_221 = R_DDRSS->DDR_MEMC_DENALI_CTL_221 | BSP_DDR_SET_00010000;

        /* Before running a BIST function, the automatic low power modes should be disabled (lp_auto_entry_en=0) */
        /* and the memories should be removed from any low power state. */
        lp_auto_entry_en = R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN;
        R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN = 0;
    }

    if (0 != run_mode)
    {
        /* Write all-0 to Memory. */
        R_DDRSS->DDR_MEMC_DENALI_CTL_213_b.BIST_DATA_CHECK = 1;
        R_DDRSS->DDR_MEMC_DENALI_CTL_216_b.BIST_TEST_MODE  = 0b100;
        R_DDRSS->DDR_MEMC_DENALI_CTL_217 = 0x00000000;                                            /* bist_data_pattern[ 31:  0] */
        R_DDRSS->DDR_MEMC_DENALI_CTL_218 = 0x00000000;                                            /* bist_data_pattern[ 63: 32] */
    }

    /* Run BIST */
    R_DDRSS->DDR_MEMC_DENALI_CTL_214_b.BIST_START_ADDRESS = (start_addr & BSP_DDR_MASK_FFFFFFFF); /* bist_start_address[31:0] */
    /* 2**addr_space */
    R_DDRSS->DDR_MEMC_DENALI_CTL_212_b.ADDR_SPACE = (uint8_t) (addr_space & BSP_DDR_MASK_3F);
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    R_DDRSS->DDR_MEMC_DENALI_CTL_212_b.BIST_GO = 1;
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_DENALI_CTL_322_b.INT_STATUS_BIST & 0x01), 0x01);
    R_DDRSS->DDR_MEMC_DENALI_CTL_212_b.BIST_GO = 0;

    /* Clear int_status_bist */
    R_DDRSS->DDR_MEMC_DENALI_CTL_331_b.INT_ACK_BIST = R_DDRSS->DDR_MEMC_DENALI_CTL_331_b.INT_ACK_BIST | 0x01;
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_DENALI_CTL_322_b.INT_STATUS_BIST & 0x01), 0x00);

    if (1 == ((run_mode >> 1) & 1))
    {
        /* Clear int_status_ecc */
        R_DDRSS->DDR_MEMC_DENALI_CTL_325 = BSP_DDR_SET_000001CF;                                   /* int_ack_ecc[8,7:6,3:0]=All-1 */
        FSP_HARDWARE_REGISTER_WAIT(R_DDRSS->DDR_MEMC_DENALI_CTL_316_b.INT_STATUS_ECC, 0x00000000); /* Wait for int_status_ecc[31:0] != 0 */
        /* Revert lp_auto_entry_en */
        R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN = (lp_auto_entry_en & 0x0F);

        /* Revert ecc_disable_w_uc_err */
        R_DDRSS->DDR_MEMC_DENALI_CTL_221 = R_DDRSS->DDR_MEMC_DENALI_CTL_221 & ~(uint32_t) (BSP_DDR_SET_00010000);
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    }
}

/*******************************************************************************************************************//**
 * @brief Memory initialization programming for Inline-ECC
 * @param range
 * @param num_of_ranges
 **********************************************************************************************************************/
static void bsp_prv_ddr_proc_ecc_init0 (const uint64_t range[][2], uint32_t num_of_ranges)
{
    const uint32_t AW    = 34;
    const uint64_t ADDR1 = 1;
    uint8_t        lp_auto_entry_en;
    uint64_t       addr;
    uint64_t       prog_size;

    /* This step should only be executed if the Inline-ECC feature is used. */
    R_DDRSS->DDR_MEMC_DENALI_CTL_221 = R_DDRSS->DDR_MEMC_DENALI_CTL_221 | BSP_DDR_SET_00010000;

    /* Before running a BIST function, the automatic low power modes should be disabled (lp_auto_entry_en=0) */
    /* and the memories should be removed from any low power state. */
    lp_auto_entry_en = (R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN & 0x0F);
    R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN = 0;

    /* Write all-0 to Memory. */
    uint8_t prog0_run_mode = 0b01;
    for (uint32_t i = 0; i < num_of_ranges; i++)
    {
        prog_size = range[i][1] - range[i][0] + 1;
        addr      = range[i][0];
        for (uint8_t j = 0; j < AW; j++)
        {
            if (ADDR1 == ((prog_size >> j) & ADDR1))
            {
                bsp_prv_ddr_proc_prog0(addr, j, prog0_run_mode);
                addr           = (uint64_t) (addr + (1 << j));
                prog0_run_mode = 0b00;
            }
        }
    }

    /* Clear int_status_ecc */
    R_DDRSS->DDR_MEMC_DENALI_CTL_325 = BSP_DDR_SET_000001CF;                                   /* int_ack_ecc[8,7:6,3:0]=All-1 */
    FSP_HARDWARE_REGISTER_WAIT(R_DDRSS->DDR_MEMC_DENALI_CTL_316_b.INT_STATUS_ECC, 0x00000000); /* wait for int_status_ecc[31:0] != 0 */

    /* Revert lp_auto_entry_en */
    R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN = (uint8_t) (lp_auto_entry_en & 0x0F);

    /* Revert ecc_disable_w_uc_err */
    R_DDRSS->DDR_MEMC_DENALI_CTL_221 = R_DDRSS->DDR_MEMC_DENALI_CTL_221 & ~(uint32_t) (BSP_DDR_SET_00010000);

    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
}

/*******************************************************************************************************************//**
 * @brief Release DDR MC and PHY reset
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_reset_release (void)
{
    /* DDR Module Reset Release: SYS_CTRL MRCTLM */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);

    /* Releasing DDR module clock gating */
    R_BSP_MODULE_START(FSP_IP_DDRSS, 0);

    /* Releasing OTFDE module clock gating */
    R_BSP_MODULE_START(FSP_IP_OTFDE, 0);

    /* Assert all DDR reset */
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_RST_N);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_RESET);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_AXI0_ARESETN);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_AXI1_ARESETN);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_MC_PRESETN);
    R_BSP_ModuleResetEnable(BSP_MODULE_RESET_DDRSS_PHY_PRESETN);

    /* De-assert DDR reset in order */
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);          /* 5 half_rate_clk or more */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_RST_N);        /* rst_n */

    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);          /* 2 half_rate_clk or more */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_AXI0_ARESETN); /* axi0_ARESETn */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_AXI1_ARESETN); /* axi1_ARESETn */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_MC_PRESETN);   /* MC_PRESETn */

    R_BSP_SoftwareDelay(2, BSP_DELAY_UNITS_MICROSECONDS);          /* 40 half_rate_clk or more */
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_PHY_PRESETN);  /* PHY_PRESETn */

    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    R_DDR_PHY->DDR_PHY_CTRL0 = R_DDR_PHY->DDR_PHY_CTRL0 | 0x00000001;
    R_BSP_ModuleResetDisable(BSP_MODULE_RESET_DDRSS_RESET);        /* reset */
    R_DDR_PHY->DDR_PHY_CTRL0 = R_DDR_PHY->DDR_PHY_CTRL0 | (1 << 16);

    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
}

/*******************************************************************************************************************//**
 * @brief PHY register settings after training
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_phy_update_after_training (void)
{
    const uint32_t BSP_PRV_DDR_DSCL_SHORTEN         = 0;
    const uint32_t BSP_PRV_DDR_BIT_LVL_WR_DYNAMIC   = 1;
    const uint32_t BSP_PRV_DDR_BIT_LVL_DYNAMIC      = 1;
    const uint32_t BSP_PRV_DDR_DLL_RECALIB_CNT      = 0x3FFFF;
    const uint32_t BSP_PRV_DDR_AUTO_SCL_ENABLE      = 0;
    const uint32_t BSP_PRV_DDR_ALT_CTRLUPD_DLL_DSCL = 0;
    const uint32_t BSP_PRV_DDR_PHY_AUTO_SCL         = 1;
    const uint32_t BSP_PRV_DDR_DSCL_INTERVAL        = 0x3D09;

    uint32_t num_ranks;
    uint32_t rddata;

    rddata    = R_DDRSS->DDR_MEMC_DENALI_CTL_301_b.CS_MAP;
    num_ranks = (rddata == 3) ? 2 : 1;

    /* Enable xBTI countermeasure */
    R_DDR_PHY->DDR_PHY_WRIDLE1 = (3 << 16 | 3 << 8 | 3 << 0);
    if (2 == num_ranks)
    {
        /* only allow toggle in 2rank config */
        R_DDR_PHY->DDR_PHY_WRIDLE2 = (3 << 16 | 3 << 8 | 3 << 0);
    }

    R_DDR_PHY->DDR_PHY_WRIDLE0 = (7 << 16 | 1 << 0); /* write_idle_cnt = 7, write_idle_cnt_en = 1 */

    /* DABC step size modification */
    R_DDR_PHY->DDR_PHY_WRLVL_STEP_SIZE = (R_DDR_PHY->DDR_PHY_WRLVL_STEP_SIZE & ~((uint32_t) BSP_DDR_MASK_FF)) | 2;

    /* SCL setting */
    R_DDR_PHY->DDR_PHY_SCL_START = ((0 << 24) | (0 << 25) | (1 << 21));

    /* Dynamic read and write bit-leveling. */
    R_DDR_PHY->DDR_PHY_DYNAMIC_WRITE_BIT_LVL = (R_DDR_PHY->DDR_PHY_DYNAMIC_WRITE_BIT_LVL & ~((uint32_t) (1 << 0))) |
                                               (BSP_PRV_DDR_BIT_LVL_WR_DYNAMIC);
    R_DDR_PHY->DDR_PHY_DYNAMIC_BIT_LVL = (R_DDR_PHY->DDR_PHY_DYNAMIC_BIT_LVL & ~((uint32_t) (1 << 0))) |
                                         (BSP_PRV_DDR_BIT_LVL_DYNAMIC);

    /* Setup Multi-rank  Dynamic Calibration settings. */
    R_DDR_PHY->DDR_PHY_RANK_SEL = ((BSP_DDRTOP_PRIMARY_RANK << 8) |        /* dscl_rank - when dscl_num_ranks = 1, train only the programmed rank. */
                                   (((num_ranks - 1) != 0) ? 2 : 1) << 4 | /* dscl_num_ranks - number of ranks to be trained dynamically. */
                                   (0 << 0));                              /* rank_sel - NOTE: this will be overridden when dscl_en is set. */

    R_DDR_PHY->DDR_PHY_DLL_RECALIB = (R_DDR_PHY->DDR_PHY_DLL_RECALIB &
                                      ~((uint32_t) ((((1 << 18) - 1) << 8) | (1 << 26)))) |
                                     ((BSP_PRV_DDR_DLL_RECALIB_CNT << 8) |
                                      (uint32_t) ((BSP_PRV_DDR_AUTO_SCL_ENABLE &&
                                                   BSP_PRV_DDR_ALT_CTRLUPD_DLL_DSCL) << 26));

    /* Setup DSCL parameters after second rank has been calibrated.  */
    R_DDR_PHY->DDR_PHY_DSCL_CNT = ((BSP_PRV_DDR_DSCL_SHORTEN << 26) | /* dscl_shorten */
                                   (BSP_PRV_DDR_PHY_AUTO_SCL << 24) | /* dscl_en */
                                   (BSP_PRV_DDR_DSCL_INTERVAL << 0)); /* dscl_exp_cnt. Set this to BSP_PRV_DDR_DSCL_INTERVAL. */
}

/*******************************************************************************************************************//**
 * @brief MC register settings after training
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_mc_update_after_training (void)
{
    uint32_t rddata;
    uint32_t num_ranks;
    uint8_t  main_clk_dly;             /* [4:0] */
    uint8_t  main_clk_dly_pre;         /* [4:0] */
    uint8_t  tphy_rdlat;               /* [6:0] */

    rddata    = R_DDRSS->DDR_MEMC_DENALI_CTL_301_b.CS_MAP;
    num_ranks = (rddata == 3) ? 2 : 1;

    /* update DFI timing after SCL */
    R_DDR_PHY->DDR_PHY_LANE_SEL = 0;
    rddata       = R_DDR_PHY->DDR_PHY_SCL_LATENCY;
    main_clk_dly = (uint8_t) (rddata >> 16);

    if (2 == num_ranks)
    {
        /* use larger main_clk_dly value among ranks */
        R_DDR_PHY->DDR_PHY_LANE_SEL = (1 << 16);
        rddata           = R_DDR_PHY->DDR_PHY_SCL_LATENCY;
        main_clk_dly_pre = (uint8_t) (rddata >> 16);

        if (main_clk_dly_pre > main_clk_dly)
        {
            main_clk_dly = main_clk_dly_pre;
        }

        R_DDR_PHY->DDR_PHY_LANE_SEL = 0;
    }

    tphy_rdlat = (uint8_t) ((main_clk_dly + 2 + 2) * 2 + 2);

    R_DDRSS->DDR_MEMC_DENALI_CTL_515_b.TDFI_PHY_RDLAT_F1 = (uint8_t) (tphy_rdlat & BSP_DDR_MASK_7F);

    /* enable interrupts */
    R_DDRSS->DDR_MEMC_DENALI_CTL_314 = R_DDRSS->DDR_MEMC_DENALI_CTL_314 & BSP_DDR_MASK_7FFFFFFF;

    /* enable lp_auto */
    if (0 == R_DDRSS->DDR_MEMC_DENALI_CTL_161_b.PCPCS_PD_EN) /* pcpcs_pd_en */
    {
        R_DDRSS->DDR_MEMC_DENALI_CTL_155 |= ((BSP_DDR_MASK_0100 << 16 | 0x1 << 0));
        R_DDRSS->DDR_MEMC_DENALI_CTL_154_b.LP_AUTO_ENTRY_EN = 0x01;
    }
}

/*******************************************************************************************************************//**
 * Functions for Hardware Dynamic Frequency Scaling
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief Initialize HW-DFS parameter and start HW-DFS. Run until dfi_init_start=1
 * @param target_fsp
 * @return result of HWDFS start
 **********************************************************************************************************************/
static uint32_t bsp_prv_ddr_init_hwdfs_start (uint32_t target_fsp)
{
    uint32_t rddata;
    uint32_t rddata2;

    /* Check if mr3_data_f0_X is equal to mr3_data_f1_X, because HW-DFS sends f0 value for f1 */
    /* If the value does not match, send the value directly after HW-DFS sequence */
    rddata  = R_DDRSS->DDR_MEMC_DENALI_CTL_195_b.MR3_DATA_F0_0;
    rddata2 = R_DDRSS->DDR_MEMC_DENALI_CTL_195_b.MR3_DATA_F1_0;
    if (rddata != rddata2)
    {

        /* MR3 register mismatch in rank 0 */
        return BSP_PRV_DDRTOP_ERR;
    }

    rddata  = R_DDRSS->DDR_MEMC_DENALI_CTL_196_b.MR3_DATA_F0_1;
    rddata2 = R_DDRSS->DDR_MEMC_DENALI_CTL_196_b.MR3_DATA_F1_1;
    if (rddata != rddata2)
    {

        /* MR3 register mismatch in rank 1 */
        return BSP_PRV_DDRTOP_ERR;
    }

    R_DDR_PHY->DDR_PHY_MODE0 = R_DDR_PHY->DDR_PHY_MODE0 | BSP_DDR_SET_01000000; /* sel_dfi_phyupd_reqack_lb = 1 */

    /* set initial parameters for Hardware Frequency Dynamic Scaling function */
    /* -- ctl_lp_ext_fc_reg_copy=2'b01, ctl_lp_ext_cmd=0x04 */
    R_DDRSS->DDR_MEMC_MC_HWIF0 = (0x04 << 16 | target_fsp << 8);

    /* wait for CONTROLLER_BUSY=0 */
    FSP_HARDWARE_REGISTER_WAIT(R_DDRSS->DDR_MEMC_DENALI_CTL_308_b.CONTROLLER_BUSY, 0b0);

    R_DDRSS->DDR_MEMC_MC_HWIF0 = (R_DDRSS->DDR_MEMC_MC_HWIF0 | 0x00000001);            /* ctl_lp_ext_req = 1 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWIF1 & 0x00000001), 0x00000001); /* wait for mon_lp_ext_ack = 1 */

    /* MRW REF SRE execution */
    R_DDRSS->DDR_MEMC_MC_HWIF0 = (R_DDRSS->DDR_MEMC_MC_HWIF0 | BSP_DDR_SET_10000000);  /* pulse_lp_ext_cmd_strb = 1 */

    /* wait for mon_lp_ext_done = 0 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWIF1 & 0x00000010), 0x00000000);

    /* wait for dfi_init_start = 1 */
    FSP_HARDWARE_REGISTER_WAIT(R_DDRSS->DDR_MEMC_MCAR_MON_b.dfi_init_start, 1);

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * @brief Change clock frequency and handshaking via HWDFS logic. Run until new clock is on CK
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_hwdfs_clock_change (void)
{
    uint32_t rddata;
    uint32_t cntrl_freq_change_req_type;

    /* dfi_init_complete = 0 */
    R_DDRSS->DDR_MEMC_MCAR_CTL_b.sel_dfi_init_complete = 1;                             /* sel_dfi_init_complete = 1 */
    R_DDRSS->DDR_MEMC_MCAR_CTL_b.ctl_dfi_init_complete = 0;                             /* ctl_dfi_init_complete = 0 */

    /* clock frequency change */
    /* wait for mon_cntrl_freq_change_req = 1 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWDFS0 & 0x00000001), 0x00000001); /* mon_dfi_init_start = 1 */

    /* set mon_cntrl_freq_change_req_type for cntrl_freq_change_req_type */
    rddata = R_DDRSS->DDR_MEMC_MC_HWDFS0;
    cntrl_freq_change_req_type = (rddata >> 4) & 3;

    /* change clock frequency and re-calibrate master DLL */
    bsp_prv_ddr_freq_change_init_lp4(cntrl_freq_change_req_type);

    /* Delay of 200ns for tVRCG_ENABLE time */
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

    /* pulse_cntrl_freq_change_ack = 1 */
    R_DDRSS->DDR_MEMC_MC_HWDFS1 = (R_DDRSS->DDR_MEMC_MC_HWDFS1 | 0x00000001);

    /* wait for mon_cntrl_freq_change_req = 0 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWDFS0 & 0x00000001), 0x00000000);

    /* wait for dfi_init_start = 0 */
    /* wait for mon_dfi_init_start = 0 */
    FSP_HARDWARE_REGISTER_WAIT(R_DDRSS->DDR_MEMC_MCAR_MON_b.dfi_init_start, 0);
}

/*******************************************************************************************************************//**
 * @brief Finish HWDFS operation. Set dfi_init_complete=1. Run until lp_ext_ack=0
 * @return result of HWDFS finish
 **********************************************************************************************************************/
static uint32_t bsp_prv_ddr_init_hwdfs_finish (void)
{
    uint32_t rddata;
    uint32_t lp_ext_resp;
    uint32_t ctl_lp_ext_fc_reg_copy;

    /* dfi_init_complete = 1 */
    R_DDRSS->DDR_MEMC_MCAR_CTL = R_DDRSS->DDR_MEMC_MCAR_CTL | BSP_DDR_SET_10000000;               /* ctl_dfi_init_complete = 1 */
    R_DDRSS->DDR_MEMC_MCAR_CTL = R_DDRSS->DDR_MEMC_MCAR_CTL & ~((uint32_t) BSP_DDR_SET_01000000); /* sel_dfi_init_complete = 0 */

    /* SRX MRW REF execution */
    /* wait for lp_ext_done = 1 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWIF1 & 0x00000100), 0x00000100);

    /* check lp_ext_resp */
    rddata      = R_DDRSS->DDR_MEMC_MC_HWIF1;
    lp_ext_resp = (rddata >> 12) & 3;
    if (0b00 != lp_ext_resp)
    {

        /* Status error in HWDFS */
        return BSP_PRV_DDRTOP_ERR;
    }

    R_DDRSS->DDR_MEMC_MC_HWIF0 = (R_DDRSS->DDR_MEMC_MC_HWIF0 & ~((uint32_t) (BSP_DDR_MASK_01000001))); /* ctl_lp_ext_req = 0 */

    /* wait for mon_lp_ext_ack = 0 */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_MC_HWIF1 & 0x00000001), 0x00000000);

    /* store ctl_lp_ext_fc_reg_copy */
    rddata                 = R_DDRSS->DDR_MEMC_MC_HWIF0;
    ctl_lp_ext_fc_reg_copy = (rddata >> 8) & 3;

    /* check FSP_OP_CURRENT */
    rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_210_b.FSP_OP_CURRENT;
    if ((rddata & 0x00000001) != (ctl_lp_ext_fc_reg_copy & 0x00000001))
    {

        /* Status error in FSP_OP_CURRENT after HWDFS */
        return BSP_PRV_DDRTOP_ERR;
    }

    /* check CURRENT_REG_COPY */
    rddata = (R_DDRSS->DDR_MEMC_DENALI_CTL_165_b.CURRENT_REG_COPY & 0x00000001);
    if (rddata != (ctl_lp_ext_fc_reg_copy & 0x00000001))
    {

        /* Status error in CURRENT_REG_COPY after HWDFS */
        return BSP_PRV_DDRTOP_ERR;
    }

    R_DDR_PHY->DDR_PHY_MODE0 = R_DDR_PHY->DDR_PHY_MODE0 & ~(uint32_t) (BSP_DDR_MASK_01000000); /* sel_dfi_phyupd_reqack_lb = 0 */

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * Tasks for command bus training
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @brief PHY swizzle setting
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_phy_swizzle (void)
{
    uint32_t pval;

    /* set CA_SWIZZLE_POSITION */
    /* CA */
    /* pad_mem_address[3:0] */
    pval = bsp_ext_unswizzle_ca(0) << 0 |
           bsp_ext_unswizzle_ca(1) << 8 |
           bsp_ext_unswizzle_ca(2) << 16 |
           bsp_ext_unswizzle_ca(3) << 24;
    R_DDR_PHY->DDR_PHY_LANE_SEL            = 0;
    R_DDR_PHY->DDR_PHY_CA_SWIZZLE_POSITION = pval;

    /* pad_mem_address[5:4] */
    pval = bsp_ext_unswizzle_ca(4) << 0 |
           bsp_ext_unswizzle_ca(5) << 8;
    R_DDR_PHY->DDR_PHY_LANE_SEL            = 1;
    R_DDR_PHY->DDR_PHY_CA_SWIZZLE_POSITION =
        (R_DDR_PHY->DDR_PHY_CA_SWIZZLE_POSITION & ~((uint32_t) BSP_DDR_MASK_0000FFFF)) | pval;

    /* CS */
    /* pad_mem_cs_n[1:0] */
    pval = ((uint32_t) bsp_ext_unswizzle_cs(0) + 26) << 16 |
           ((uint32_t) bsp_ext_unswizzle_cs(1) + 26) << 24;
    R_DDR_PHY->DDR_PHY_LANE_SEL            = 6;
    R_DDR_PHY->DDR_PHY_CA_SWIZZLE_POSITION =
        (R_DDR_PHY->DDR_PHY_CA_SWIZZLE_POSITION & ~((uint32_t) BSP_DDR_MASK_FFFF0000)) | pval;

    R_DDR_PHY->DDR_PHY_LANE_SEL = 0;
}

/*******************************************************************************************************************//**
 * MC swizzle setting
 * set SWIZZLE_SEL_n
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_mc_swizzle (void)
{
    uint32_t pval;

    /* SWIZZLE_SEL_0 */
    pval = (bsp_ext_swizzle_cs(0) + 1) << 0 |
           (bsp_ext_swizzle_cs(1) + 1) << 8;
    R_DDRSS->DDR_MEMC_SWIZZLE_SEL_0 = (R_DDRSS->DDR_MEMC_SWIZZLE_SEL_0 &
                                       ~(uint32_t) (BSP_DDR_MASK_3F << 8 | BSP_DDR_MASK_3F)) | pval;

    /* SWIZZLE_SEL_1 */
    pval = (bsp_ext_swizzle_ca(0) + 18) << 0 |
           (bsp_ext_swizzle_ca(1) + 18) << 8 |
           (bsp_ext_swizzle_ca(2) + 18) << 16 |
           (bsp_ext_swizzle_ca(3) + 18) << 24;
    R_DDRSS->DDR_MEMC_SWIZZLE_SEL_1 =
        (R_DDRSS->DDR_MEMC_SWIZZLE_SEL_1 & ~(uint32_t) (BSP_DDR_MASK_3F << 24 | BSP_DDR_MASK_3F << 16 |
                                                        BSP_DDR_MASK_3F << 8 | BSP_DDR_MASK_3F)) | pval;

    /* SWIZZLE_SEL_2 */
    pval = (bsp_ext_swizzle_ca(4) + 18) << 0 |
           (bsp_ext_swizzle_ca(5) + 18) << 8;
    R_DDRSS->DDR_MEMC_SWIZZLE_SEL_2 = (R_DDRSS->DDR_MEMC_SWIZZLE_SEL_2 &
                                       ~(uint32_t) (BSP_DDR_MASK_3F << 8 | BSP_DDR_MASK_3F)) | pval;
}

/*******************************************************************************************************************//**
 * Intialize MC register setting
 * @param proc_status DDR process status
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_mc_write_regmap (uint32_t proc_status)
{
    size_t i;
    for (i = 0; i < param_setup_mc_size; i++)
    {
        bsp_ddrtop_mc_apb_wr(param_setup_mc[i][0], param_setup_mc[i][1]);
    }

    if (0 != proc_status)
    {
        R_DDRSS->DDR_MEMC_DENALI_CTL_22_b.PHY_INDEP_INIT_MODE = 1;
    }
}

/*******************************************************************************************************************//**
 * @brief Initialize DRAM MR setting
 * @param num_ranks  Number of Ranks
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_dram_sequence (uint32_t num_ranks)
{
    uint32_t rddata;

    FSP_PARAMETER_NOT_USED(num_ranks);

    /* This setting should be done after finishing all MC setting */
    rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_61_b.NO_MEMORY_DM;
    if (0 == rddata)
    {
        rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_311_b.WR_DBI_EN;
        if (1 == rddata)
        {
            /* Enable DM control and mask pattern on PHY_DMPAT and make the PHY DQ bits corresponding to DRAM DQ7-3 in each lane high */
            /* Enable DM control and mask patterns for PCB DQ swizzling */
            R_DDR_PHY->DDR_PHY_DMPAT = ((1 << 24) |
                                        (1 << (bsp_ext_unswizzle_bit(7, 1) + 8)) |
                                        (1 << (bsp_ext_unswizzle_bit(6, 1) + 8)) |
                                        (1 << (bsp_ext_unswizzle_bit(5, 1) + 8)) |
                                        (1 << (bsp_ext_unswizzle_bit(4, 1) + 8)) |
                                        (1 << (bsp_ext_unswizzle_bit(3, 1) + 8)) |
                                        (1 << (bsp_ext_unswizzle_bit(7, 0) + 0)) |
                                        (1 << (bsp_ext_unswizzle_bit(6, 0) + 0)) |
                                        (1 << (bsp_ext_unswizzle_bit(5, 0) + 0)) |
                                        (1 << (bsp_ext_unswizzle_bit(4, 0) + 0)) |
                                        (1 << (bsp_ext_unswizzle_bit(3, 0) + 0)));
        }
    }

    /* mask dfi_ctrlupd_req */
    R_DDRSS->DDR_MEMC_MCAR_CTL = R_DDRSS->DDR_MEMC_MCAR_CTL | BSP_DDR_SET_00010000; /* ctrlupd_mask_en = 1 */

    /* enable IO output */
    R_DDR_PHY->DDR_PHY_CTRL0 = R_DDR_PHY->DDR_PHY_CTRL0 & ~(uint32_t) (0x00000001);

    /* Wait for Analog DLL to lock */
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_UNQ_ANALOG_DLL_2 & 0x00000003), 0x00000003);

    /* Wait until PHY is ready to accept commands on the DFI interface */
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DLL_RISE_FALL & 0x00001000), 0x00001000);

    /* Manually update the UCAL I/O */
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | (1 << 4);
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | (0 << 4);

    /* Initiate command processing in the controller */
    R_DDRSS->DDR_MEMC_DENALI_CTL_00_b.START = 1; /* Controller */

    /* Wait for controller to complete memory initialization */
    FSP_HARDWARE_REGISTER_WAIT((R_DDRSS->DDR_MEMC_DENALI_CTL_323_b.INT_STATUS_INIT & 0x02), 0x02);

    /* MEMC MR write(setting copied from UNQ testbench) */
    bsp_prv_ddr_mc_mrw(BSP_DDR_REGNO_0F, BSP_DDR_OPECODE_00, 0b11);
    bsp_prv_ddr_mc_mrw(BSP_DDR_REGNO_14, BSP_DDR_OPECODE_00, 0b11);
    bsp_prv_ddr_mc_mrw(BSP_DDR_REGNO_20, BSP_DDR_OPECODE_AA, 0b11);
    bsp_prv_ddr_mc_mrw(BSP_DDR_REGNO_28, BSP_DDR_OPECODE_AA, 0b11);
}

/*******************************************************************************************************************//**
 * @brief Read Bit Leveling
 * @param bit_lvl_from_saved Use the saved trim trained by bit leveling before
 * @return result of read bit leveling
 **********************************************************************************************************************/
static uint32_t bsp_prv_ddr_init_read_bit_leveling (uint32_t bit_lvl_from_saved)
{
    uint32_t rddata;
    uint8_t  bit_lvl_failure_status;

    /* Bit-Leveling read MPR */
    R_DDR_PHY->DDR_PHY_SCL_START = ((BSP_DDR_MASK_C2 << 22) | (bit_lvl_from_saved << 21));
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* FAILURE CHECKING */
    rddata                 = R_DDR_PHY->DDR_PHY_DYNAMIC_BIT_LVL;
    bit_lvl_failure_status = (rddata >> 16) & 3;

    if (0 == bit_lvl_failure_status)
    {
        /* RBL: PASSED on all lanes */
    }
    else
    {

        /* RBL: FAILED: lanes failed */
        return BSP_PRV_DDRTOP_ERR;
    }

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * @brief Write Bit Leveling
 * @param bit_lvl_from_saved Use the saved trim trained by bit leveling before
 * @return result of Write Bit Leveling
 **********************************************************************************************************************/
static uint32_t bsp_prv_ddr_init_write_bit_leveling (uint32_t bit_lvl_from_saved)
{
    uint32_t rddata;
    uint8_t  bit_lvl_wr_failure_status;

    /* Bit-lvl from MPR */
    R_DDR_PHY->DDR_PHY_SCL_START = ((BSP_DDR_MASK_C2 << 22) | (bit_lvl_from_saved << 21) | (1 << 20));
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* FAILURE CHECKING */
    rddata = R_DDR_PHY->DDR_PHY_DYNAMIC_WRITE_BIT_LVL;
    bit_lvl_wr_failure_status = (rddata >> 20) & 3;

    if (0 == bit_lvl_wr_failure_status)
    {
        /* WBL: PASSED on all lanes */
    }
    else
    {
        /* WBL: FAILED: lanes failed */
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);

        return BSP_PRV_DDRTOP_ERR;
    }

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * @brief Run SCL
 * @param rank                Specify RANK-0 or RANK-1
 * @param bit_lvl_from_saved  Use the saved trim trained by bit leveling before.
 *                            Used in SCL routines and should not be set by the user.
 *                            If set, dynamic bit-leveling will use previously saved bit-leveled values.
 *                            Otherwise, each time dynamic bit-leveling is run, it will start bit-leveling
 *                            from scratch (i.e. will set all initial delay values for all bits to 0)
 * @param scl_second_try      Set to 1 to inhibit retry-on-fail for 2nd call of this task/sequence
 * @param run_WR_BIT_LEVELING Set to 1 to perform Write Bit Leveling before SCL retry
 * @param scl_start_addr_X    Bank, Column, and Row address bits
 * @param val_NATIVE_BURST8   Value to add in col_addr: Always set to 16 for LPDDR4/DDR5; set to 8 for half-rate controllers
 * @return result of SCL
 **********************************************************************************************************************/
static uint32_t bsp_prv_ddr_init_scl (uint32_t rank,
                                      uint32_t bit_lvl_from_saved,
                                      uint32_t scl_second_try,
                                      uint32_t run_WR_BIT_LEVELING,
                                      uint32_t scl_start_addr_X,
                                      uint32_t val_NATIVE_BURST8)
{
    uint32_t dll_mas_dly;
    uint32_t scl_rslt;
    uint32_t trim2_dly;
    uint32_t dqs_total_dly;
    uint32_t rddata;
    uint32_t main_clk_dly;

    /* Default pattern to read that is different from SCL data */
    for (uint32_t i = 0; i < 4; i++)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL   = i;
        R_DDR_PHY->DDR_PHY_SCL_DATA_0 = BSP_DDR_SET_AA00AA00; /* SCL_DATA_0.[31:0].scl_data[127:96],[95:64],[63:32],[31:0] */
    }

    /* Setup scl_start_row_addr, scl_start_col_addr, scl_start_bank_addr */
    R_DDR_PHY->DDR_PHY_SCL_START_ADDR = (scl_start_addr_X + (val_NATIVE_BURST8 << 16));
    R_DDR_PHY->DDR_PHY_DDR4_CONFIG_1  = (R_DDR_PHY->DDR_PHY_DDR4_CONFIG_1 & ~((uint32_t) 0b11 << 1)) |
                                        (1 << 2 | ((BSP_DDRTOP_SCL_ROW_ADDR >> 16) & 1) << 1); /* DDR4_CONFIG_1[2:1] */

    /* Write Pattern data */
    R_DDR_PHY->DDR_PHY_SCL_START = ((BSP_DDR_MASK_44 << 22) | (bit_lvl_from_saved << 21));
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* Replace 0 with the required value X described above */
    R_DDR_PHY->DDR_PHY_SCL_START_ADDR = scl_start_addr_X;

    /* Restore the default pattern SCL data */
    for (uint32_t i = 0; i < 4; i++)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL = i;
        switch (i)
        {
            case 0:
            {
                R_DDR_PHY->DDR_PHY_SCL_DATA_0 = BSP_DDR_SET_789A3CE0;
                break;                 /* SCL_DATA_0.[31:0].scl_data[ 31: 0] */
            }

            case 1:
            {
                R_DDR_PHY->DDR_PHY_SCL_DATA_0 = BSP_DDR_SET_710E4A56;
                break;                 /*            [31:0].scl_data[ 63:32] */
            }

            case 2:
            {
                R_DDR_PHY->DDR_PHY_SCL_DATA_0 = BSP_DDR_SET_0E71B1A9;
                break;                 /*            [31:0].scl_data[ 95:64] */
            }

            case 3:
            {
                R_DDR_PHY->DDR_PHY_SCL_DATA_0 = BSP_DDR_SET_8764C232;
                break;                 /*            [31:0].scl_data[127:96] */
            }
        }
    }

    /* Write the SCL data to the SCL address location in DRAM */
    R_DDR_PHY->DDR_PHY_SCL_START = (1 << 28 | 1 << 24 | bit_lvl_from_saved << 21);
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* Run SCL phase and latency calibration as an atomic operation */
    R_DDR_PHY->DDR_PHY_SCL_START = (1 << 29 | 1 << 28 | 1 << 26 | bit_lvl_from_saved << 21);
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* FAILURE CHECKING */
    /* Check whether SCL passed or failed on each byte lane */
    rddata   = R_DDR_PHY->DDR_PHY_SCL_START;
    scl_rslt = rddata & 0x00000003;

    if (0b11 == scl_rslt)
    {
        /* SCL: PASSED for all lanes */
        if (0 == rank)
        {
            /* Get SCL_LATENCY.[20:16].main_clk_dly of RANK-0 */
            R_DDR_PHY->DDR_PHY_LANE_SEL = 0;
            rddata       = R_DDR_PHY->DDR_PHY_SCL_LATENCY;
            main_clk_dly = (rddata >> 16) & 0x1F;

            /* Update main_clk_dly of RANK-1 */
            R_DDR_PHY->DDR_PHY_LANE_SEL    = (1 << 16);
            R_DDR_PHY->DDR_PHY_SCL_LATENCY = (R_DDR_PHY->DDR_PHY_SCL_LATENCY & ~((uint32_t) 0x1F << 16)) |
                                             (main_clk_dly << 16);
        }
    }
    else
    {
        /* Get PHY_PHY_DLL_ADRCTRL.[31:24].dll_mas_dly */
        rddata      = R_DDR_PHY->DDR_PHY_DLL_ADRCTRL;
        dll_mas_dly = rddata >> 24;

        if ((dll_mas_dly > BSP_DDR_MAS_DLY_200) && !scl_second_try)
        {
            /* SCL: Retrying SCL for rank n since it may have failed at low frequency due */
            /* to write leveling delay jump issue */
            /* Set-up RETRY for LANE-0 and LANE-1 */
            for (uint32_t i = 0; i < 2; i++)
            {
                if (0 == ((scl_rslt >> i) & 1))
                {
                    /* Get PHY_DLL_TRIM_2.[8:0].dlls_trim_2 */
                    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16 | (i * (8 + 1)));
                    rddata    = R_DDR_PHY->DDR_PHY_DLL_TRIM_2;
                    trim2_dly = rddata;

                    /* Get PHY_DLL_TRIM_OP_DQS.[7:0].dlls_trim_op_dqs, calculate "dqs_total_dly" */
                    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16 | i);

                    rddata        = R_DDR_PHY->DDR_PHY_DLL_TRIM_OP_DQS;
                    dqs_total_dly = trim2_dly + (uint32_t) ((int32_t) (rddata & BSP_DDR_MASK_FF) *
                                                            (rddata & BSP_DDR_MASK_0100 ? 4 : -4));

                    /* Get DQS_TRIM.[ 7: 0].op_dqs_trim, calculate "dqs_total_dly" */
                    rddata        = R_DDR_PHY->DDR_PHY_DQS_TRIM;
                    dqs_total_dly = dqs_total_dly + (rddata & BSP_DDR_MASK_FF) * 4;

                    /* Check "dqs_total_dly" */
                    if (0 == (dqs_total_dly & BSP_DDR_MASK_3F))
                    {
                        /* Confirmed that fine delay boundary was crossed and we can proceed with retry */
                        /* Set PHY_DLL_TRIM_2.[8:0].dlls_trim_2 */
                        R_DDR_PHY->DDR_PHY_LANE_SEL   = (rank << 16 | (i * (8 + 1)));
                        R_DDR_PHY->DDR_PHY_DLL_TRIM_2 = ((trim2_dly - 1) & BSP_DDR_MASK_01FF);
                    }
                    else
                    {
                        /* SCL: FAILED: An unrecoverable error: dqs_total_dly */
                        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);

                        return BSP_PRV_DDRTOP_ERR;
                    }
                }
            }

            if (run_WR_BIT_LEVELING)
            {
                bsp_prv_ddr_init_write_bit_leveling(bit_lvl_from_saved);
            }

            bsp_prv_ddr_init_scl(rank, bit_lvl_from_saved, 1, run_WR_BIT_LEVELING, scl_start_addr_X, val_NATIVE_BURST8);
        }
        else
        {
            /* SCL: FAILED: rank lanes failed */
            R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);

            return BSP_PRV_DDRTOP_ERR;
        }
    }

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * @brief Wrapper function of DQ VREF Training for SoC and DRAM
 * @param rank      Target rank
 * @param num_ranks Number of ranks
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_vref_dq_training_wrapper (uint32_t rank, uint32_t num_ranks)
{
    uint32_t DQ_vref_mid_level;
    uint8_t  DQ_vref_mid_level_code;
    uint8_t  DQ_sweep_range;

    uint32_t DRAM_vref_mid_level;
    uint8_t  DRAM_vref_mid_level_code;
    uint8_t  DRAM_sweep_range;

    uint32_t tmp_data;

    /* scl_for_dram_fast */
    if (BSP_DDRTOP_PRIMARY_RANK == rank) /* NOTE: VREF DQ Training only for PRIMARY_RANK ... */
    {
        R_DDR_PHY->DDR_PHY_RANK_SEL     = (R_DDR_PHY->DDR_PHY_RANK_SEL & ~((uint32_t) (((1 << 4) - 1)))) | rank;
        R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) (((1 << 2) - 1)))) |
                                          (1 << rank);

        /* Calculations for PHY side */
        DQ_vref_mid_level = param_phyinit_11;
        tmp_data          = ((DQ_vref_mid_level - BSP_DDR_DQ_VREF_CALC_1000) << 8);
        tmp_data          =
            (uint32_t) ((tmp_data / BSP_DDR_DQ_VREF_CALC_66) + BSP_DDR_DQ_VREF_CALC_512 - BSP_DDR_DQ_VREF_CALC_128);
        DQ_vref_mid_level_code = (uint8_t) ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));

        /* Sweep range of 0.15 (15%) is only a suggested value. User may customize to increase it if required. */
        tmp_data       = ((DQ_vref_mid_level * bsp_ddr_sweep_range_ratio) << 8);
        tmp_data       = (uint32_t) ((tmp_data / BSP_DDR_DQ_VREF_CALC_6600) - BSP_DDR_DQ_VREF_CALC_128);
        DQ_sweep_range = (uint8_t) ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));

        /* Calculations for DRAM side */
        DRAM_vref_mid_level      = param_phyinit_12;
        tmp_data                 = ((DRAM_vref_mid_level - BSP_DDR_DQ_VREF_CALC_1000) << 8);
        tmp_data                 = (uint32_t) ((tmp_data / BSP_DDR_DQ_VREF_CALC_40) - BSP_DDR_DQ_VREF_CALC_128);
        DRAM_vref_mid_level_code = (uint8_t) ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
        tmp_data                 = ((DRAM_vref_mid_level * bsp_ddr_sweep_range_ratio) << 8);
        tmp_data                 = (uint32_t) ((tmp_data / BSP_DDR_DQ_VREF_CALC_4000) - BSP_DDR_DQ_VREF_CALC_128);

        /* Sweep range of 0.15 (15%) is only a suggested value. User may customize to increase it if required. */
        DRAM_sweep_range = (uint8_t) ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));

        /* VREF DQ Training */
        bsp_prv_ddr_init_vref_dq_training(DQ_vref_mid_level,
                                          DQ_vref_mid_level_code,
                                          DQ_sweep_range,
                                          BSP_DDR_VREF_STEP_SIZE,
                                          BSP_DDR_PHY_MAX_VREF_TRIM,
                                          DRAM_vref_mid_level,
                                          DRAM_vref_mid_level_code,
                                          DRAM_sweep_range,
                                          BSP_DDR_VREF_STEP_SIZE,
                                          BSP_DDR_DRAM_MAX_VREF_TRIM,
                                          BSP_DDR_DRAM_SWEEP_LIMIT,
                                          (uint8_t) num_ranks,
                                          1, /* RUN_PHY_VREF */
                                          1, /* RUN_DRAM_VREF */
                                          4  /* bit_lvl_sample_qty */
                                          );
    }
}

/*******************************************************************************************************************//**
 * @brief DQ VREF Training for SoC and DRAM
 * @details Pass drive strength and ODT settings on SoC and DRAM side as input to the task
 *          so it can calculate the expected read and write VREF center points
 * @param DQ_vref_mid_level
 * @param DQ_vref_mid_level_code
 * @param DQ_sweep_range
 * @param DQ_vref_step_size      Step size of VREF code in SoC
 * @param DQ_max_vref_trim_phy   Max VREF trim value supported by PHY selected based on pull down or pull up ODT
 *                               Because UVREF supports 2 trim ranges depending on pull down or pull up ODT
 * @param DRAM_vref_mid_level
 * @param DRAM_vref_mid_level_code
 * @param DRAM_sweep_range
 * @param DRAM_vref_step_size    Step size of VREF code in DRAM
 * @param DRAM_max_vref_trim_phy Max VREF trim value supported by PHY selected based on pull down or pull up ODT
 *                               Because UVREF supports 2 trim ranges depending on pull down or pull up ODT
 * @param DRAM_sweep_limit       Total number of unique VREF trim settings
 * @param DRAM_mem_chip_selects  Set by MEM_CHIP_SELECTS
 * @param RUN_PHY_VREF           PHY side VREF training is always expected to be enabled
 * @param RUN_DRAM_VREF          Enable DRAM side (i.e. Write) VREF training only for DRAM types that support it
 * @param bit_lvl_sample_qty     Number of samples taken by bit-leveling (1 per half rate clock cycle)
 *                               to detect the edges of the bit-leveling window
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_vref_dq_training (uint32_t DQ_vref_mid_level,
                                               uint8_t  DQ_vref_mid_level_code,
                                               uint8_t  DQ_sweep_range,
                                               uint8_t  DQ_vref_step_size,
                                               uint8_t  DQ_max_vref_trim_phy,
                                               uint32_t DRAM_vref_mid_level,
                                               uint8_t  DRAM_vref_mid_level_code,
                                               uint8_t  DRAM_sweep_range,
                                               uint8_t  DRAM_vref_step_size,
                                               uint8_t  DRAM_max_vref_trim_phy,
                                               uint8_t  DRAM_sweep_limit,
                                               uint8_t  DRAM_mem_chip_selects,
                                               uint32_t RUN_PHY_VREF,
                                               uint32_t RUN_DRAM_VREF,
                                               uint32_t bit_lvl_sample_qty)
{
    uint32_t DQ_best_vref_setting_lane[2];
    uint32_t DRAM_best_vref_setting_lane[2];

    /* For VREF training, we only sample DQ0 on rising edge and DQ1 on falling edge of DQS */
    for (uint32_t i = 0; i < 2; i++)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL       = i;
        R_DDR_PHY->DDR_PHY_BIT_LVL_CONFIG = (1 << 4 | bit_lvl_sample_qty);
    }

    if (RUN_PHY_VREF)
    {
        bsp_prv_ddr_init_phy_vref_dq_training(DQ_vref_mid_level,
                                              DQ_vref_mid_level_code,
                                              DQ_sweep_range,
                                              DQ_vref_step_size,
                                              DQ_max_vref_trim_phy,
                                              DQ_best_vref_setting_lane);
    }

    if (RUN_DRAM_VREF)
    {
        bsp_prv_ddr_init_dram_vref_dq_training(DRAM_vref_mid_level,
                                               DRAM_vref_mid_level_code,
                                               DRAM_sweep_range,
                                               DRAM_vref_step_size,
                                               DRAM_max_vref_trim_phy,
                                               DRAM_sweep_limit,
                                               DRAM_mem_chip_selects,
                                               DRAM_best_vref_setting_lane);
    }

    /* For normal bit-leveling we sample every DQ bit on both rising and falling edges of DQS, so restore the original value */
    for (uint32_t i = 0; i < 2; i++)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL       = i;
        R_DDR_PHY->DDR_PHY_BIT_LVL_CONFIG = (3 << 4 | bit_lvl_sample_qty);
    }
}

/*******************************************************************************************************************//**
 * @brief PHY DQ VREF training (Read side)
 * @param vref_mid_level
 * @param vref_mid_level_code
 * @param sweep_range
 * @param vref_step_size step size of VREF code
 * @param max_vref_trim_phy Max VREF trim value supported by PHY selected based on pull down or pull up ODT
 *                          Because UVREF supports 2 trim ranges depending on pull down or pull up ODT
 * @param best_vref_setting_lane Best VREF setting
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_phy_vref_dq_training (uint32_t vref_mid_level,
                                                   uint32_t vref_mid_level_code,
                                                   uint32_t sweep_range,
                                                   uint32_t vref_step_size,
                                                   uint32_t max_vref_trim_phy,
                                                   uint32_t best_vref_setting_lane[2])
{
    uint8_t window_diff[2];                                        /* Difference between the width of '0' and '1' windows - minimizing this difference will */
                                                                   /* result in closest to 50% duty cycle and this is the main goal of VREF training */
    uint8_t best_window_diff_so_far[2];                            /* Smallest window difference recorded so far at any VREF setting per byte lane */
    uint8_t num_best_vref_matches[2];                              /* Total number of VREF settings that give the smallest window difference */
    uint8_t all_best_vref_matches[2][BSP_DDR_MAX_BEST_VREF_SAVED]; /* ALL VREF settings that result in smallest window difference */

    uint8_t highest_best_vref_val;                                 /* If multiple VREF settings gave the smallest window difference, the highest of those */
    uint8_t lowest_best_vref_val;                                  /* If multiple VREF settings gave the smallest window difference, the lowest of those */

    uint32_t current_vref;                                         /* Current VREF setting being trained and/or programmed */

    FSP_PARAMETER_NOT_USED(vref_mid_level);
    FSP_PARAMETER_NOT_USED(max_vref_trim_phy);

    for (uint32_t lane = 0; lane < 2; lane++)
    {
        best_window_diff_so_far[lane] = BSP_DDR_SET_FF; /* Set initial value prior to training */
        num_best_vref_matches[lane]   = 0;
    }

    /* j = 0 loop sweeps VREF from mid-level value to lower values and j = 1 loop sweeps from mid-level + 1 to higher values */
    /* i loop runs for each individual VREF setting */
    for (uint32_t j = 0; j < 2; j++)                                   /* VREF_range */
    {
        for (uint32_t i = 0; i < sweep_range + 1; i += vref_step_size) /* VREF_sweep */
        {
            if ((1 != j) || (0 != i))
            {
                if ((0 == j) && (i + 2 > vref_mid_level_code))
                {
                    /* If during negative sweep, the trim code becomes smaller than 2 (lowest supported UVREF */
                    /* trim code), we have to stop and resume with positive sweep above VREF mid-level */
                    break;
                }

                if ((1 == j) && (vref_mid_level_code + i > BSP_DDR_MAX_VREF_TRIM_PHY))
                {
                    /* If during positive sweep, the trim code overflows the maximum supported UVREF trim */
                    /* code, we have to end VREF training */
                    break;
                }

                if (1 == j)
                {
                    current_vref = vref_mid_level_code + i;
                }
                else
                {
                    current_vref = vref_mid_level_code - i;
                }

                /* Change UVREF trim code for each lane by programming VREF_TRAINING register */
                for (uint32_t lane = 0; lane < 2; lane++)
                {
                    R_DDR_PHY->DDR_PHY_LANE_SEL      = ((7 * lane) & BSP_DDR_MASK_FF);
                    R_DDR_PHY->DDR_PHY_VREF_TRAINING = (((current_vref & BSP_DDR_MASK_7F) << 4) | 1);

                    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

                    /* NOTE : Add > 1us delay in silicon to allow for VREF settling time */
                }

                bsp_prv_ddr_init_find_vref_window(window_diff, current_vref);

                /* For LANE-0 and 1:  Check if window_diff we got is the best so far */
                /*                        and if so save the information for later evaluation */
                for (uint32_t lane = 0; lane < 2; lane++)
                {
                    if (window_diff[lane] < best_window_diff_so_far[lane])
                    {
                        best_window_diff_so_far[lane]  = window_diff[lane];
                        all_best_vref_matches[lane][0] = (uint8_t) current_vref;
                        num_best_vref_matches[lane]    = 1;

                        /* Read VREF: CURRENT BEST VREF */
                    }
                    else if ((window_diff[lane] == best_window_diff_so_far[lane]) &&
                             (num_best_vref_matches[lane] < BSP_DDR_MAX_BEST_VREF_SAVED))
                    {
                        all_best_vref_matches[lane][num_best_vref_matches[lane]] = (uint8_t) current_vref;
                        num_best_vref_matches[lane] = num_best_vref_matches[lane] + 1;
                    }
                    else
                    {
                    }
                }
            }
        }
    }

    /* For LANE-0 and 1:  Select / calculate the best VREF setting */
    for (uint32_t lane = 0; lane < 2; lane++)
    {
        highest_best_vref_val = 0;
        lowest_best_vref_val  = BSP_DDR_SET_7F;

        /* Iterate over ALL VREF settings that gave smallest window_diff in each lane */
        /*     to find the highest and lowest such VREF value for each lane */
        for (uint32_t i = 0; i < num_best_vref_matches[lane]; i++)
        {
            highest_best_vref_val = all_best_vref_matches[lane][i] >
                                    highest_best_vref_val ? all_best_vref_matches[lane][i] : highest_best_vref_val;
            lowest_best_vref_val = all_best_vref_matches[lane][i] <
                                   lowest_best_vref_val ? all_best_vref_matches[lane][i] : lowest_best_vref_val;
        }

        /* Convert from unsigned char to unsigned int to avoid overflow on following line */
        current_vref = (uint32_t) highest_best_vref_val;

        /* Find midpoint of highest_best_vref_val and lowest_best_vref_val */
        current_vref = (current_vref + lowest_best_vref_val) >> 1;

        best_vref_setting_lane[lane] = current_vref;

        /* Program the final result of VREF training and turn off VREF training */
        R_DDR_PHY->DDR_PHY_LANE_SEL      = ((7 * lane) & BSP_DDR_MASK_FF);
        R_DDR_PHY->DDR_PHY_VREF_TRAINING = ((current_vref & BSP_DDR_MASK_7F) << 4);

        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);

        /* NOTE : Add > 1us delay in silicon to allow for VREF settling time */
        /* Read VREF: lane , Programmed VREF */
    }

    /* Read VREF: Finished VREF DQ Training */
}

/*******************************************************************************************************************//**
 * @brief Find VREF Window
 * @param window_diff
 * @param current_vref
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_find_vref_window (uint8_t window_diff[2], uint32_t current_vref)
{
    uint8_t  window_0;                 /* Width of '0' window read-out after VREF training */
    uint8_t  window_1;                 /* Width of '1' window read-out after VREF training */
    uint32_t rddata;

    FSP_PARAMETER_NOT_USED(current_vref);

    /* Run VREF training using DRAM MPR read pattern register, so we don't need to initialize any data pattern into the DRAM */
    R_DDR_PHY->DDR_PHY_SCL_START = ((BSP_DDR_MASK_C2 << 22) | 0 << 21);
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* Force update of VREF training result values from all the data lanes to the address PHY */
    R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG = (1 << 2);
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG & (1 << 2)), 0x00000000);

    /* Check VREF training windows for each byte lane */
    for (uint32_t lane = 0; lane < 2; lane++)
    {
        /* Check that this lane passed training by reading DYNAMIC_BIT_LVL.[17:16].bit_lvl_failure_status */
        rddata = R_DDR_PHY->DDR_PHY_DYNAMIC_BIT_LVL;

        if (0 == (rddata >> (16 + lane)))
        {
            /* Read out VREF training windows for this byte lane */
            R_DDR_PHY->DDR_PHY_LANE_SEL = (((lane * 2 * 7) & BSP_DDR_MASK_FF));
            rddata   = R_DDR_PHY->DDR_PHY_VREF_TRAINING;
            window_0 = (rddata >> 12) & BSP_DDR_MASK_FF; /* VREF_TRAINING.[18:12].window_0 */
            window_1 = (rddata >> 20) & BSP_DDR_MASK_FF; /* VREF_TRAINING.[26:20].window_1 */

            window_diff[lane] = (window_0 > window_1) ? window_0 - window_1 : window_1 - window_0;
        }
        else
        {
            window_diff[lane] = BSP_DDR_SET_FF;

            /* Read VREF: FAILED */
        }
    }
}

/*******************************************************************************************************************//**
 * @brief DRAM DQ VREF training (Write side)
 * @param vref_mid_level      DQ VREF value
 * @param vref_mid_level_code DQ VREF code
 * @param sweep_range         DQ VREF range
 * @param vref_step_size      Step size of DQ VREF code
 * @param max_vref_trim_phy   Max VREF trim value supported by PHY selected based on pull down or pull up ODT
 *                            Because UVREF supports 2 trim ranges depending on pull down or pull up ODT
 * @param sweep_limit         Total number of unique VREF trim settings
 * @param mem_chip_selects    Rank
 * @param best_vref_setting_lane Best VREF setting
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_dram_vref_dq_training (uint32_t vref_mid_level,
                                                    uint8_t  vref_mid_level_code,
                                                    uint8_t  sweep_range,
                                                    uint8_t  vref_step_size,
                                                    uint8_t  max_vref_trim_phy,
                                                    uint8_t  sweep_limit,
                                                    uint8_t  mem_chip_selects,
                                                    uint32_t best_vref_setting_lane[2])
{
    uint8_t window_0;                                              /* Width of '0' window read-out after VREF training */
    uint8_t window_1;                                              /* Width of '1' window read-out after VREF training */
    uint8_t window_diff;                                           /* Difference between the width of '0' and '1' windows - minimizing this difference will result */
                                                                   /* in closest to 50% duty cycle and this is the main goal of VREF training */
    uint8_t best_window_diff_so_far[2];                            /* Smallest window difference recorded so far at any VREF setting per byte lane */
    uint8_t num_best_vref_matches[2];                              /* Total number of VREF settings that give the smallest window difference */
    uint8_t all_best_vref_matches[2][BSP_DDR_MAX_BEST_VREF_SAVED]; /* ALL VREF settings that result in smallest window difference */

    uint8_t highest_best_vref_val;                                 /* If multiple VREF settings gave the smallest window difference, the highest of those */
    uint8_t lowest_best_vref_val;                                  /* If multiple VREF settings gave the smallest window difference, the lowest of those */

    uint8_t orig_cs_config;                                        /* Used to save the value of scl_test_cs register and restore it later */

    uint32_t current_vref;                                         /* Current VREF setting being trained and/or programmed */

    uint32_t rddata;
    uint32_t wr_bit_lvl_failure;                                   /* If VREF training fails, we don't read-out '1' and '0' window values on that iteration */

    FSP_PARAMETER_NOT_USED(vref_mid_level);
    FSP_PARAMETER_NOT_USED(vref_step_size);
    FSP_PARAMETER_NOT_USED(max_vref_trim_phy);
    FSP_PARAMETER_NOT_USED(sweep_limit);
    FSP_PARAMETER_NOT_USED(best_vref_setting_lane);

    rddata         = R_DDR_PHY->DDR_PHY_SCL_CONFIG_2;
    orig_cs_config = rddata & 0x3;

    /* Setup scl_test_cs such that when DRAM mode register is programmed, */
    /*     it is programmed for all ranks together */
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0x3)) |
                                      (uint32_t) ((1 << mem_chip_selects) - 1);

    /* Set the initial VREF value and turn on DRAM mode register bit(s) required for VREF training */
    bsp_prv_ddr_init_setup_vref_training_registers(vref_mid_level_code, /* VREF value to be programmed in DRAM */
                                                   0,                   /* Set to 1 to issue a multi-purpose register read command to DRAM */
                                                   1                    /* VREF training mode in DRAM: 1=Turn ON, 2=Turn OFF, others=Program VREF trim in MR14 */
                                                   );

    /* Restore scl_test_cs to the value of the rank we are using for training */
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0x3)) | (orig_cs_config & 0x3);

    /* Set the PHY to operate in VREF training mode : Turn on VREF training mode in the PHY */
    R_DDR_PHY->DDR_PHY_VREF_TRAINING = (R_DDR_PHY->DDR_PHY_VREF_TRAINING & ~((uint32_t) 1)) | 1;

    /* Set initial value prior to training */
    for (uint32_t lane = 0; lane < 2; lane++)
    {
        best_window_diff_so_far[lane] = BSP_DDR_SET_FF;
        num_best_vref_matches[lane]   = 0;
    }

    /* j = 0 loop sweeps VREF from mid-level value to lower values and j = 1 loop sweeps from mid-level + 1 to higher values */
    /* i loop runs for each individual VREF setting */
    for (uint32_t j = 0; j < 2; j++)                                             /*: VREF_range */
    {
        for (uint32_t i = 0U; i < sweep_range + 1U; i += BSP_DDR_VREF_STEP_SIZE) /*: VREF_sweep */
        {
            if ((1 != j) || (0 != i))
            {
                if ((0 == j) && (i > vref_mid_level_code))
                {
                    /* If during negative sweep, the trim code becomes smaller than 0 (lowest supported DRAM */
                    /* trim code), we have to stop and resume with positive sweep above VREF mid-level */
                    break;
                }

                if ((1 == j) && (vref_mid_level_code + i > BSP_DDR_SWEEP_LIMIT))
                {
                    /* If during positive sweep, the trim code overflows the maximum supported DRAM trim */
                    /* code, we have to end VREF training */
                    break;
                }

                if (1 == j)
                {
                    current_vref = vref_mid_level_code + i;
                }
                else
                {
                    current_vref = vref_mid_level_code - i;
                }

                bsp_prv_ddr_init_setup_vref_training_registers((uint8_t) current_vref, /* VREF value to be programmed in DRAM */
                                                               0,                      /* Set to 1 to issue a multi-purpose register read command to DRAM */
                                                               0                       /* VREF training mode in DRAM: 1=Turn ON, 2=Turn OFF, others=Program VREF trim in MR14 */
                                                               );

                /* Run VREF training for write side */
                /*     Use MPC FIFO for training */
                R_DDR_PHY->DDR_PHY_SCL_START = (BSP_DDR_MASK_C2 << 22 | 0 << 21 | 1 << 20);
                FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

                /* Force update of VREF training result values from all the data lanes to the address PHY */
                R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG = (1 << 2);
                FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG & (1 << 2)), 0x00000000);

                /* Check if all lanes passed training by reading DYNAMIC_WRITE_BIT_LVL.[21:20].bit_lvl_wr_failure_status */
                rddata             = R_DDR_PHY->DDR_PHY_DYNAMIC_WRITE_BIT_LVL;
                wr_bit_lvl_failure = (rddata >> 20) & 0x3;

                /* Check VREF training windows for each byte lane */
                for (uint32_t lane = 0; lane < 2 && ((BSP_DDRTOP_SCL_LANES >> lane) & 1); lane++)
                {
                    if (!wr_bit_lvl_failure)
                    {
                        /* Read out VREF training windows for this byte lane */
                        R_DDR_PHY->DDR_PHY_LANE_SEL = ((lane * 2 * 7) & BSP_DDR_MASK_FF);
                        rddata   = R_DDR_PHY->DDR_PHY_VREF_TRAINING;
                        window_0 = (rddata >> 12) & BSP_DDR_MASK_FF; /* VREF_TRAINING.[18:12].window_0 */
                        window_1 = (rddata >> 20) & BSP_DDR_MASK_FF; /* VREF_TRAINING.[26:20].window_1 */

                        window_diff = (window_0 > window_1) ? window_0 - window_1 : window_1 - window_0;

                        /* Check if window_diff we got is the best so far and if so save the information for later evaluation */
                        if (window_diff < best_window_diff_so_far[lane])
                        {
                            best_window_diff_so_far[lane]  = window_diff;
                            all_best_vref_matches[lane][0] = (uint8_t) current_vref;
                            num_best_vref_matches[lane]    = 1;
                        }
                        else if ((window_diff == best_window_diff_so_far[lane]) &&
                                 (num_best_vref_matches[lane] < BSP_DDR_MAX_BEST_VREF_SAVED))
                        {
                            all_best_vref_matches[lane][num_best_vref_matches[lane]] = (uint8_t) current_vref;
                            num_best_vref_matches[lane] = num_best_vref_matches[lane] + 1;
                        }
                        else
                        {
                        }
                    }
                    else
                    {
                        /*Write VREF: FAILED */
                    }
                }
            }
        }

        /*-- Dummy delay added to allow Controller issue REFRESH command to avoid any REFRESH postponed ERROR */
        /*   when bit-leveling exception hit without failure, which may longing the VREF training time. */
        /* UDELAY(4); --> No need dummy delay in thii design */
    }

    highest_best_vref_val = 0x0;
    lowest_best_vref_val  = BSP_DDR_SET_7F;

    /* Iterate over ALL VREF settings that gave smallest window_diff in each lane */
    /*     to find the highest and lowest such VREF value across all lanes */
    for (uint32_t lane = 0; lane < 2; lane++)
    {
        for (uint32_t i = 0; i < num_best_vref_matches[lane]; i++)
        {
            highest_best_vref_val = all_best_vref_matches[lane][i] >
                                    highest_best_vref_val ? all_best_vref_matches[lane][i] : highest_best_vref_val;
            lowest_best_vref_val = all_best_vref_matches[lane][i] <
                                   lowest_best_vref_val ? all_best_vref_matches[lane][i] : lowest_best_vref_val;
        }
    }

    current_vref = highest_best_vref_val; /* Convert from unsigned char to unsigned int to avoid overflow on following line */
    current_vref = (current_vref + lowest_best_vref_val) >> 1;

    /* Program trained VREF to all ranks */
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0x3)) |
                                      (((1 << mem_chip_selects) - 1) & 0x3);
    bsp_prv_ddr_init_setup_vref_training_registers((uint8_t) current_vref, /* VREF value to be programmed in DRAM */
                                                   0,                      /* Set to 1 to issue a multi-purpose register read command to DRAM */
                                                   0                       /* VREF training mode in DRAM: 1=Turn ON, 2=Turn OFF, others=Program VREF trim in MR14 */
                                                   );

    /* Write VREF */

    /* Turn off VREF training mode in the PHY */
    R_DDR_PHY->DDR_PHY_LANE_SEL      = 0;
    R_DDR_PHY->DDR_PHY_VREF_TRAINING = (R_DDR_PHY->DDR_PHY_VREF_TRAINING & ~((uint32_t) 1));

    /* Write VREF: Finished VREF DQ Training */

    /* Keep BEST VREF while turning off VrefDQ training mode in mode register */
    bsp_prv_ddr_init_setup_vref_training_registers((uint8_t) current_vref, /* VREF value to be programmed in DRAM */
                                                   0,                      /* Set to 1 to issue a multi-purpose register read command to DRAM */
                                                   2                       /* VREF training mode in DRAM: 1=Turn ON, 2=Turn OFF, others=Program VREF trim in MR14 */
                                                   );

    /* Restore scl_test_cs to the value of the rank we are using for training */
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0x3)) | (orig_cs_config & 0x3);
}

/*******************************************************************************************************************//**
 * @brief Setup VREF training registers
 * @param vref_value           VREF value to be programmed in DRAM
 * @param mpr_mode             Set to 1 to issue a multi-purpose register read command to DRAM
 * @param turn_on_off_training VREF training mode in DRAM: 1=Turn ON, 2=Turn OFF, others=Program VREF trim in MR14
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_setup_vref_training_registers (uint8_t vref_value,
                                                            uint8_t mpr_mode,
                                                            uint8_t turn_on_off_training)
{
    uint8_t  vref_op;
    uint32_t pval;
    uint8_t  mr13;

    FSP_PARAMETER_NOT_USED(mpr_mode);

    pval = R_DDRSS->DDR_MEMC_DENALI_CTL_203_b.MR13_DATA_0;
    mr13 = (pval & BSP_DDR_MASK_34);

    if (1 == turn_on_off_training)     /* Turn on VRCG in MR13 = Register Control.{ FSP-OP, FSP-WR, DMD, RRO, VRCG, VRO, RPT, CBT } */
    {
        pval = (BSP_DDR_SET_200000D << 8);
        pval = (uint32_t) (pval / (2 * param_dram_clk_period));
        pval = ((pval >> 8) + ((pval & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
        pval = (pval > BSP_DDR_SET_000001FF) ? BSP_DDR_SET_000001FF : pval;
        R_DDR_PHY->DDR_PHY_MRW_CTRL = (pval << 20 | 13 << 12 | (BSP_DDR_SET_C8 | mr13) << 4 | 1);
    }
    else if (2 == turn_on_off_training) /* Disable VRCG in MR13 = Register Control.{ FSP-OP, FSP-WR, DMD, RRO, VRCG, VRO, RPT, CBT } */
    {
        pval = (BSP_DDR_SET_100000D << 8);
        pval = (uint32_t) (pval / (2 * param_dram_clk_period));
        pval = ((pval >> 8) + ((pval & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
        pval = (pval > BSP_DDR_SET_000001FF) ? BSP_DDR_SET_000001FF : pval;
        R_DDR_PHY->DDR_PHY_MRW_CTRL = (pval << 20 | 13 << 12 | (BSP_DDR_SET_C0 | mr13) << 4 | 1);
    }
    else
    {
        /* Program VREF trim in MR14 = VREF(DQ).[7:0].{ RFU, VRDQ, VREF[5:0] } */
        if (BSP_DDR_DQ_VREF_CALC_50 < vref_value)
        {
            vref_op = (vref_value - 30) | (1 << 6);
        }
        else
        {
            vref_op = vref_value;
        }

        pval = (BSP_DDR_SET_250000D << 8);
        pval = (uint32_t) (pval / (2 * param_dram_clk_period));
        pval = ((pval >> 8) + ((pval & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
        pval = (pval > BSP_DDR_SET_000001FF) ? BSP_DDR_SET_000001FF : pval;

        R_DDR_PHY->DDR_PHY_MRW_CTRL = (pval << 20 | 14 << 12 | vref_op << 4 | 1);
    }

    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & BSP_DDR_SET_10000000), 0x00000000);
}

/*******************************************************************************************************************//**
 * @brief Write Levening
 * @param rank               Target rank
 * @param bit_lvl_from_saved Use the saved trim trained by bit leveling before
 * @return result of Write Leveling
 **********************************************************************************************************************/
uint32_t bsp_prv_ddr_init_write_leveling (uint32_t rank, uint32_t bit_lvl_from_saved)
{
    uint32_t rddata;
    uint8_t  look_for_zero;
    uint8_t  wrlvl_result;

    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16);

    R_DDR_PHY->DDR_PHY_RANK_SEL     = (R_DDR_PHY->DDR_PHY_RANK_SEL & ~((uint32_t) 0xF)) | rank;
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0x3)) | (1 << rank);

    /* Set start_wr_lvl for all lanes */
    R_DDR_PHY->DDR_PHY_WRLVL_AUTOINC_TRIM = 0b11;

    /* Clear all dlls_trim_2 registers */
    R_DDR_PHY->DDR_PHY_DLL_TRIM_2 = (1 << 18);

    /* Set wr level command */
    R_DDR_PHY->DDR_PHY_SCL_START = (1 << 30 | 1 << 28 | bit_lvl_from_saved << 21);

    /* Check for completion */
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_SCL_START & 0x10000000), 0x00000000);

    /* Write Leveling: Completed */

    /* Check DLL_TRIM_2[8:0].dlls_trim_2 of LANE-0 */
    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16 | (0 * (8 + 1)) << 0);
    FSP_REGISTER_READ(R_DDR_PHY->DDR_PHY_DLL_TRIM_2);

    /* Check DLL_TRIM_2[8:0].dlls_trim_2 of LANE-0 */
    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16 | (1 * (8 + 1)) << 0);
    FSP_REGISTER_READ(R_DDR_PHY->DDR_PHY_DLL_TRIM_2);

    /* FAILURE CHECKING */
    R_DDR_PHY->DDR_PHY_LANE_SEL = (rank << 16);

    /* Ensure 0 was detected during write leveling before 1 to confirm we locked on rising edge */
    rddata        = R_DDR_PHY->DDR_PHY_WRLVL_AUTOINC_TRIM;
    look_for_zero = (uint8_t) (rddata & 0b11);

    /* Final DQ sampling value during write leveling should be 1 */
    rddata       = R_DDR_PHY->DDR_PHY_WRLVL_CTRL; /* WRLVL_CTRL.[1:0].wrlvl_rslt */
    wrlvl_result = (uint8_t) (rddata & 0b11);

    if ((0b11 == wrlvl_result) && (0b00 == look_for_zero))
    {
        /* Write Leveling: PASSED */
    }
    else
    {
        /* Write leveling: FAILED */
        R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);

        return BSP_PRV_DDRTOP_ERR;
    }

    /* Re-write MR2 and MR11 with MC parameter values since they were overwritten by PHY during write-leveling */
    if (0 == rank)
    {
        rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_192_b.MR2_DATA_F1_0;
        bsp_prv_ddr_mc_mrw(02, (uint8_t) rddata, 0b01);
        rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_200_b.MR11_DATA_F1_0;
        bsp_prv_ddr_mc_mrw(11, (uint8_t) rddata, 0b01);
    }
    else
    {
        rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_194_b.MR2_DATA_F1_1;
        bsp_prv_ddr_mc_mrw(02, (uint8_t) rddata, 0b10);
        rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_201_b.MR11_DATA_F1_1;
        bsp_prv_ddr_mc_mrw(11, (uint8_t) rddata, 0b10);
    }

    return BSP_PRV_DDRTOP_OK;
}

/*******************************************************************************************************************//**
 * @brief PHY register initialization
 * @param num_ranks Number of ranks
 **********************************************************************************************************************/
static void bsp_prv_ddr_init_phy_routine (uint32_t num_ranks)
{
    /* Use MC parameter */
    uint8_t  rl;
    uint8_t  wl;
    uint8_t  mr2;
    uint8_t  mr11;
    uint32_t rd_cas_latency;
    uint32_t wr_cas_latency;
    uint32_t tmp_data;

    rl   = (uint8_t) (R_DDRSS->DDR_MEMC_DENALI_CTL_38_b.CASLAT_LIN_F1 >> 1);
    wl   = (uint8_t) R_DDRSS->DDR_MEMC_DENALI_CTL_38_b.WRLAT_F1;
    mr2  = (uint8_t) R_DDRSS->DDR_MEMC_DENALI_CTL_192_b.MR2_DATA_F1_0;
    mr11 = (uint8_t) R_DDRSS->DDR_MEMC_DENALI_CTL_200_b.MR11_DATA_F1_0;

    /* rd_cas_latency = (uint32_t)ceil((double)rl / 2.0); */
    /* wr_cas_latency = (uint32_t)ceil((double)wl / 2.0); */
    /* rd_cas_latency = (uint32_t)ceil(rl / 2.0); */
    /* wr_cas_latency = (uint32_t)ceil(wl / 2.0); */
    rd_cas_latency = (rl >> 1) + (rl & 1);
    wr_cas_latency = (wl >> 1) + (wl & 1);

    R_DDR_PHY->DDR_PHY_DQS_TRIM = BSP_DDR_SET_00002028;

    R_DDR_PHY->DDR_PHY_DLLM_WINDOW_SIZE = 0x00000004;
    R_DDR_PHY->DDR_PHY_DLL_INCR_TRIM_3  = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL         = 0x00000000;
    R_DDR_PHY->DDR_PHY_DLL_TRIM_3       = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL         = 0x00000006;
    R_DDR_PHY->DDR_PHY_DLL_TRIM_3       = 0x00000000;
    R_DDR_PHY->DDR_PHY_SCL_WINDOW_TRIM  = BSP_DDR_SET_140B002D;
    R_DDR_PHY->DDR_PHY_UNQ_ANALOG_DLL_1 = 0x00000000;
    R_DDR_PHY->DDR_PHY_PAD_CTRL         = BSP_DDR_SET_1000C000;

    /* Drive/ODT setting */
    R_DDR_PHY->DDR_PHY_LANE_SEL   = 0x00000000;
    R_DDR_PHY->DDR_PHY_PAD_CTRL_1 = ((param_phyinit_02 << 16) |
                                     (param_phyinit_01 << 8) |
                                     (param_phyinit_00 << 0));
    R_DDR_PHY->DDR_PHY_LANE_SEL   = 0x00000001;
    R_DDR_PHY->DDR_PHY_PAD_CTRL_1 = ((param_phyinit_02 << 16) |
                                     (param_phyinit_01 << 8) |
                                     (param_phyinit_00 << 0));
    R_DDR_PHY->DDR_PHY_LANE_SEL   = 0x00000000;
    R_DDR_PHY->DDR_PHY_PAD_CTRL_2 = (param_phyinit_03 << 0);
    R_DDR_PHY->DDR_PHY_LANE_SEL   = 0x00000001;
    R_DDR_PHY->DDR_PHY_PAD_CTRL_2 = (param_phyinit_03 << 0);

    R_DDR_PHY->DDR_PHY_LANE_SEL         = 0x00000000;
    R_DDR_PHY->DDR_PHY_VREF_TRAINING    = (param_phyinit_10 << 4) | (1 << 2);
    R_DDR_PHY->DDR_PHY_LANE_SEL         = 0x00000007;
    R_DDR_PHY->DDR_PHY_VREF_TRAINING    = (param_phyinit_10 << 4) | (1 << 2);
    R_DDR_PHY->DDR_PHY_VREF_CA_TRAINING = BSP_DDR_SET_7F;

    if (BSP_DDR_CLK_CHECK_1500 <= param_dram_clk_period)
    {
        R_DDR_PHY->DDR_PHY_DYNAMIC_IE_TIMER = BSP_DDR_SET_27;
    }
    else
    {
        R_DDR_PHY->DDR_PHY_DYNAMIC_IE_TIMER = BSP_DDR_SET_28;
    }

    tmp_data = BSP_DDR_CLK_CALC_1000 << 8;
    tmp_data = (uint32_t) (tmp_data / param_dram_clk_period);
    tmp_data = ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_1 = (((rd_cas_latency & 0xf) << 4) | (tmp_data << 12));

    R_DDR_PHY->DDR_PHY_DDR4_CONFIG_1 = 0x00000004;
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2  = ((1U << 0) | ((wr_cas_latency & 0xf) << 8) | ((1U - (wl & 1)) << 24) |
                                        ((wl >> 5) << 25) | ((rl >> 5) << 26) |
                                        (1U << 30));
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_3 = 0x00000000;

    tmp_data  = BSP_DDR_CAS_CALC_2500 << 8;
    tmp_data  = (uint32_t) (tmp_data / (param_dram_clk_period * 2));
    tmp_data -= BSP_DDR_CAS_CALC_256;
    tmp_data  = ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));

    R_DDR_PHY->DDR_PHY_DYNAMIC_WRITE_BIT_LVL = ((((BSP_DDR_CAS_CALC_62 + wr_cas_latency) << 4) |
                                                 ((BSP_DDR_CAS_CALC_51 + wr_cas_latency + rd_cas_latency + tmp_data) <<
                                                  12)));
    R_DDR_PHY->DDR_PHY_DYNAMIC_BIT_LVL = BSP_DDR_SET_00003E90;
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_4    = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL        = 0x00000000;

    R_DDR_PHY->DDR_PHY_SCL_GATE_TIMING = 0x00000003;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL        = BSP_DDR_SET_00010000;
        R_DDR_PHY->DDR_PHY_SCL_GATE_TIMING = 0x00000003;
    }

    /* Use MC parameter values for Write-Leveling */
    R_DDR_PHY->DDR_PHY_WRLVL_DYN_ODT = ((mr11 << 16) | ((mr11 & BSP_DDR_MASK_F8) << 0)); /* MR11 */
    R_DDR_PHY->DDR_PHY_WRLVL_ON_OFF  = (((mr2 | BSP_DDR_MASK_80) << 16) | (mr2 << 0));   /* MR2 */

    R_DDR_PHY->DDR_PHY_WRLVL_STEP_SIZE = BSP_DDR_SET_00001801;
    R_DDR_PHY->DDR_PHY_LANE_SEL        = 0x00000000;
    R_DDR_PHY->DDR_PHY_DLL_TRIM_CLK    = BSP_DDR_SET_00000100;

    if (BSP_DDR_CLK_CHECK_1364 > param_dram_clk_period)
    {
        tmp_data = BSP_DDR_SET_000C0104;
    }
    else if (BSP_DDR_CLK_CHECK_1500 > param_dram_clk_period)
    {
        tmp_data = BSP_DDR_SET_000A0106;
    }
    else if (BSP_DDR_CLK_CHECK_2500 > param_dram_clk_period)
    {
        tmp_data = BSP_DDR_SET_00080108;
    }
    else
    {
        tmp_data = BSP_DDR_SET_0006010A;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL           = 0x00000000;
    R_DDR_PHY->DDR_PHY_DLL_TRIM_OP_DQS    = (tmp_data & BSP_DDR_MASK_01FF);
    R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
        (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF0000)) |
        tmp_data;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL           = BSP_DDR_SET_00010000;
        R_DDR_PHY->DDR_PHY_DLL_TRIM_OP_DQS    = (tmp_data & BSP_DDR_MASK_01FF);
        R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
            (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF0000)) |
            tmp_data;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL           = 0x00000001;
    R_DDR_PHY->DDR_PHY_DLL_TRIM_OP_DQS    = (tmp_data & BSP_DDR_MASK_01FF);
    R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
        (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF0000)) |
        tmp_data;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL           = BSP_DDR_SET_00010001;
        R_DDR_PHY->DDR_PHY_DLL_TRIM_OP_DQS    = (tmp_data & BSP_DDR_MASK_01FF);
        R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
            (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF0000)) |
            tmp_data;
    }

    R_DDR_PHY->DDR_PHY_DLL_ADRCTRL   = BSP_DDR_SET_00000200;
    R_DDR_PHY->DDR_PHY_DLL_RISE_FALL = 0x00000006;

    tmp_data = (uint32_t) (param_dram_clk_period * BSP_DDR_CLK_CALC_3840 / BSP_DDR_CLK_CALC_1736);
    tmp_data = ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
    tmp_data = (tmp_data > 0xf) ? 0xf : tmp_data;
    R_DDR_PHY->DDR_PHY_DLL_RECALIB = ((BSP_DDR_MASK_0003FFFF << 8) | (1 << 26) | (1 << 27) | (tmp_data << 28));

    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_DLL_RISE_FALL & 0x00001000), 0x00001000);

    tmp_data = BSP_DDR_CLK_CALC_18560 << 8;
    tmp_data = (uint32_t) (tmp_data / param_dram_clk_period) - BSP_DDR_CLK_CALC_2176;
    tmp_data = ((tmp_data >> 8) + ((tmp_data & BSP_DDR_MASK_FF) > 0 ? 1 : 0));
    if (BSP_DDR_CLK_CHECK_1364 > param_dram_clk_period)
    {
        tmp_data += 4;
    }
    else if (BSP_DDR_CLK_CHECK_1500 > param_dram_clk_period)
    {
        tmp_data += 6;
    }
    else if (BSP_DDR_CLK_CHECK_2500 > param_dram_clk_period)
    {
        tmp_data += 8;
    }
    else
    {
        tmp_data += 10;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL      = 0x00000000;
    R_DDR_PHY->DDR_PHY_OP_DQ_TDQS2DQ = tmp_data;
    R_DDR_PHY->DDR_PHY_OP_DM_TDQS2DQ = tmp_data;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL      = BSP_DDR_SET_00010000;
        R_DDR_PHY->DDR_PHY_OP_DQ_TDQS2DQ = tmp_data;
        R_DDR_PHY->DDR_PHY_OP_DM_TDQS2DQ = tmp_data;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL      = 0x00000001;
    R_DDR_PHY->DDR_PHY_OP_DQ_TDQS2DQ = tmp_data;
    R_DDR_PHY->DDR_PHY_OP_DM_TDQS2DQ = tmp_data;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL      = BSP_DDR_SET_00010001;
        R_DDR_PHY->DDR_PHY_OP_DQ_TDQS2DQ = tmp_data;
        R_DDR_PHY->DDR_PHY_OP_DM_TDQS2DQ = tmp_data;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL           = 0x00000000;
    R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM = (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF)) |
                                            BSP_DDR_SET_00000123;
    R_DDR_PHY->DDR_PHY_LANE_SEL           = 0x00000001;
    R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM = (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF)) |
                                            BSP_DDR_SET_00000123;
    if (2 == num_ranks)
    {
        R_DDR_PHY->DDR_PHY_LANE_SEL           = BSP_DDR_SET_00010000;
        R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
            (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF)) |
            BSP_DDR_SET_00000123;
        R_DDR_PHY->DDR_PHY_LANE_SEL           = BSP_DDR_SET_00010001;
        R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM =
            (R_DDR_PHY->DDR_PHY_OP_DQ_DQS_OEN_TRIM & ~((uint32_t) BSP_DDR_MASK_01FF)) |
            BSP_DDR_SET_00000123;
    }

    R_DDR_PHY->DDR_PHY_LANE_SEL       = 0x00000000;
    R_DDR_PHY->DDR_PHY_SCL_LATENCY    = BSP_DDR_SET_000A5066;
    R_DDR_PHY->DDR_PHY_LANE_SEL       = BSP_DDR_SET_00010000;
    R_DDR_PHY->DDR_PHY_SCL_LATENCY    = BSP_DDR_SET_000A5066;
    R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG = 0x00000002;
    R_DDR_PHY->DDR_PHY_RANK_SEL       = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL       = 0x00000000;
    R_DDR_PHY->DDR_PHY_BIT_LVL_CONFIG = BSP_DDR_SET_34;
    R_DDR_PHY->DDR_PHY_LANE_SEL       = 0x00000001;
    R_DDR_PHY->DDR_PHY_BIT_LVL_CONFIG = BSP_DDR_SET_34;
    R_DDR_PHY->DDR_PHY_INT_WRLVL_CTRL = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL       = 0x00000000;
    R_DDR_PHY->DDR_PHY_BIT_LVL_MASK   = 0x00000000;
    R_DDR_PHY->DDR_PHY_LANE_SEL       = 0x00000001;
    R_DDR_PHY->DDR_PHY_BIT_LVL_MASK   = 0x00000000;
    R_DDR_PHY->DDR_PHY_PDA_CTRL       = BSP_DDR_SET_00000400;
    R_DDR_PHY->DDR_PHY_SCL_MASK_0     = 0x00000000;

    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_2 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_2 & ~((uint32_t) BSP_DDR_MASK_007FFFFF)) |
                                       0x00000000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000010;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_3 = BSP_DDR_SET_05011000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = 0x00000002;
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & 0x00000008), 0x00000008);

    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = 0x00000000;
    R_BSP_SoftwareDelay(BSP_DDR_SW_DLY_100, BSP_DELAY_UNITS_MICROSECONDS);

    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) BSP_DDR_MASK_BF000000)) |
                                       BSP_DDR_SET_9F000000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000010;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) BSP_DDR_MASK_BF000000)) |
                                       0x00000000;

    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_3 = BSP_DDR_SET_05009000;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = 0x00000001;
    FSP_HARDWARE_REGISTER_WAIT((R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & 0x00000004), 0x00000004);

    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000010;
    R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) 0x00000010)) | 0x00000000;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
}

/*******************************************************************************************************************//**
 * Initializes DDR.
 **********************************************************************************************************************/
void bsp_ddr_init (void)
{
    uint32_t          ret                 = BSP_PRV_DDRTOP_OK;
    volatile uint32_t bsp_ddr_proc_status = 0;
    volatile uint32_t rddata;
    uint32_t          num_ranks;
    uint32_t          scl_start_addr_X;

    /* DDR related register initial settings. */
    bsp_prv_ddr_init_reg();

    /* MC swizzle setting */
    bsp_prv_ddr_init_mc_swizzle();

    /* Intialize MC register setting */
    bsp_prv_ddr_init_mc_write_regmap(bsp_ddr_proc_status);

    rddata    = R_DDRSS->DDR_MEMC_DENALI_CTL_301_b.CS_MAP;
    num_ranks = (rddata == 3) ? 2 : 1;

    /* Initialize PHY registers */
    bsp_prv_ddr_init_phy_swizzle();
    bsp_prv_ddr_init_phy_routine(num_ranks);

    /* Initialize DRAM Mode Registers */
    bsp_prv_ddr_init_dram_sequence(num_ranks);

    /* MC-HWDFS start */
    /* MC HW-DFS: Start */
    ret = bsp_prv_ddr_init_hwdfs_start(1); /* target_fsp=1'b1 */
    if (BSP_PRV_DDRTOP_OK != ret)
    {
        return;
    }

    /* MC HW-DFS: Change Clock Frequency */
    bsp_prv_ddr_init_hwdfs_clock_change();

    /* MC HW-DFS: Finish */
    ret = bsp_prv_ddr_init_hwdfs_finish();
    if (BSP_PRV_DDRTOP_OK != ret)
    {
        return;
    }

    /* MC-HWDFS end */

    /* Enable WDQS Control */
    R_DDR_PHY->DDR_PHY_PAD_CTRL = (R_DDR_PHY->DDR_PHY_PAD_CTRL & ~((uint32_t) 1 << 11)) | (1 << 11);

    /* Enable Periodic Refresh */
    R_DDRSS->DDR_MEMC_DENALI_CTL_63_b.TREF_ENABLE = 1;

    /* Issue REF command twice */
    R_DDRSS->DDR_MEMC_DENALI_CTL_62_b.AREFRESH = 1;
    R_DDRSS->DDR_MEMC_DENALI_CTL_62_b.AREFRESH = 1;

    /* Training start */
    for (uint32_t rank = 0; rank < num_ranks; rank++)
    {
        /* Training: Start: rank */

        /* Before calling scl_for_ddr_fast() for RANK 0 & 1 */
        R_DDR_PHY->DDR_PHY_RANK_SEL       = rank;
        R_DDR_PHY->DDR_PHY_SCL_CONFIG_2   = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 3)) | (1 << rank);
        R_DDR_PHY->DDR_PHY_A2D_D2A_CONFIG = ((0 << 0) | (0 << 1));
        R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS); /* wait 50ns */

        R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) (1 << 4))) | (1 << 4);
        R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 = (R_DDR_PHY->DDR_PHY_UNIQUIFY_IO_1 & ~((uint32_t) (1 << 4))) | (0 << 4);

        /* Write Leveling: Start: rank */
        ret = bsp_prv_ddr_init_write_leveling(rank, 1); /* PRIMARY_RANK=0, SECONDARY_RANK=1 */
        if (BSP_PRV_DDRTOP_OK != ret)
        {
            return;
        }

        /* VREF DQ Training: Start: rank */
        bsp_prv_ddr_init_vref_dq_training_wrapper(rank, num_ranks);

        R_DDR_PHY->DDR_PHY_LANE_SEL               = (rank << 16);
        R_DDR_PHY->DDR_PHY_DISABLE_GATING_FOR_SCL = 0;

        /* RBL: Start: rank */
        ret = bsp_prv_ddr_init_read_bit_leveling(1);
        if (BSP_PRV_DDRTOP_OK != ret)
        {
            return;
        }

        /* WBL: Start: rank */
        ret = bsp_prv_ddr_init_write_bit_leveling(1);
        if (BSP_PRV_DDRTOP_OK != ret)
        {
            return;
        }

        R_DDR_PHY->DDR_PHY_LANE_SEL               = (rank << 16);
        R_DDR_PHY->DDR_PHY_DISABLE_GATING_FOR_SCL = 0b01;

        /* SCL: Start: rank */
        scl_start_addr_X = (BSP_DDRTOP_SCL_BA_ADDR << 29) | (0b000 << 26) |
                           ((BSP_DDRTOP_SCL_COL_ADDR & BSP_DDR_MASK_03FF) << 16) |
                           (BSP_DDRTOP_SCL_ROW_ADDR & BSP_DDR_MASK_0000FFFF);
        ret = bsp_prv_ddr_init_scl(rank,
                                   1,
                                   0,
                                   1,
                                   scl_start_addr_X,
                                   16  /* Column shift amount for SCL pattern data */
                                   );
        if (BSP_PRV_DDRTOP_OK != ret)
        {
            return;
        }

        R_DDR_PHY->DDR_PHY_LANE_SEL               = (rank << 16);
        R_DDR_PHY->DDR_PHY_DISABLE_GATING_FOR_SCL = 0b11;
    }

    /* Switch back to rank PRIMARY_RANK parameters */
    R_DDR_PHY->DDR_PHY_RANK_SEL     = 0;
    R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 = (R_DDR_PHY->DDR_PHY_SCL_CONFIG_2 & ~((uint32_t) 0b11)) | (1 << 0);

    /* Training: Finished SCL Training / Calibration */
    if (0 != R_DDRSS->DDR_MEMC_DENALI_CTL_220_b.ECC_ENABLE)
    {
        /* ECC address region */
        /* For start address */
        static uint64_t bsp_prv_ddr_ecc_prog0_range[][2] = {{BSP_DDRTOP_ECC_START_ADDR, BSP_DDRTOP_ECC_END_ADDR_DEF}};

        /* For end address */
        if (0x01 == R_DDRSS->DDR_MEMC_DENALI_CTL_301_b.CS_MAP)
        {
            rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_293_b.CS_VAL_UPPER_0;
        }
        else
        {
            rddata = R_DDRSS->DDR_MEMC_DENALI_CTL_295_b.CS_VAL_UPPER_1;
        }

        bsp_prv_ddr_ecc_prog0_range[0][1] = (((uint64_t) rddata << 16) | BSP_DDR_MASK_0000FFFFULL);

        /* Memory initialization for ECC */

        /* Memory initialization with Zero data pattern */
        bsp_prv_ddr_proc_ecc_init0(bsp_prv_ddr_ecc_prog0_range,
                                   (sizeof(bsp_prv_ddr_ecc_prog0_range) / sizeof(bsp_prv_ddr_ecc_prog0_range[0])));
    }

    /* Set MC registers after training */
    bsp_prv_ddr_init_mc_update_after_training();

    /* Set PHY registers after training */
    bsp_prv_ddr_init_phy_update_after_training();

    /* DDR Initialization: Finished */
}

 #endif
#endif
