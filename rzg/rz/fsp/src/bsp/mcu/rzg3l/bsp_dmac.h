/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_DMAC_H
 #define BSP_DMAC_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

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

 #define ACK_MODE_LEVEL_MODE            (1 << 16)
 #define ACK_MODE_BUS_CYCLE_MODE        (2 << 16)
 #define ACK_MODE_MASK_DACK_OUTPUT      (4 << 16)

 #define DETECTION_FALLING_EDGE         (1 << 24)
 #define DETECTION_RISING_EDGE          (2 << 24)
 #define DETECTION_LOW_LEVEL            (5 << 24)
 #define DETECTION_HIGH_LEVEL           (6 << 24)

 #define ACTIVATION_SOURCE_CLEAR_Msk    (R_DMAC_B0_EX_DMARS0_CH0_RID_Msk | R_DMAC_B0_EX_DMARS0_CH0_MID_Msk)

 #define R_BSP_DMAC_DREQ_DETECT_METHOD_SELECT(dmac_reg, channel, detection, dreq_pin)                         \
    do                                                                                                        \
    {                                                                                                         \
        if (dreq_pin != DMAC_B_EXTERNAL_INPUT_PIN_NO_INPUT)                                                   \
        {                                                                                                     \
            uint32_t reg_value = 0U;                                                                          \
            switch (detection)                                                                                \
            {                                                                                                 \
                case DMAC_B_EXTERNAL_DETECTION_FALLING_EDGE:                                                  \
                    reg_value = DMAC_B_INTERNAL_DETECTION_FALLING_EDGE;                                       \
                    break;                                                                                    \
                case DMAC_B_EXTERNAL_DETECTION_RISING_EDGE:                                                   \
                    reg_value = DMAC_B_INTERNAL_DETECTION_RISING_EDGE;                                        \
                    break;                                                                                    \
                case DMAC_B_EXTERNAL_DETECTION_LOW_LEVEL:                                                     \
                    reg_value = DMAC_B_INTERNAL_DETECTION_LOW_LEVEL;                                          \
                    break;                                                                                    \
                default:                                                                                      \
                    reg_value = DMAC_B_INTERNAL_DETECTION_HIGH_LEVEL;                                         \
                    break;                                                                                    \
            }                                                                                                 \
                                                                                                              \
            dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG |= reg_value << R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos; \
        }                                                                                                     \
                                                                                                              \
    } while (0)

 #define R_BSP_DMAC_B_TRANSFER_END_DETECT_METHOD_SELECT(unit, channel, dmaint_detect) \
    { /* No configuration required for this device. */;                               \
    }                                                                                 \

 #define R_BSP_DMAC_DREQ_STATUS_CLEAR(activation)  \
    { /* No clearing required for this device. */; \
    }                                              \

 #define R_BSP_DMAC_DACK_OUTPUT_PIN_SET(unit, channel, ack_output_pin) \
    { /* No clearing required for this device. */;                     \
    }                                                                  \

 #define R_BSP_DMAC_TEND_OUTPUT_PIN_SET(unit, channel, dtend_pin) \
    { /* No clearing required for this device. */;                \
    }                                                             \

 #define R_BSP_DMAC_EXTERNAL_OUTPUT_ACTIVE_LEVEL_SET(unit,                                 \
                                                     channel,                              \
                                                     ack_output_signal_active_level,       \
                                                     tend_output_signal_active_level)      \
    do                                                                                     \
    {                                                                                      \
        static volatile uint32_t * const DMAEOC_TABLE[2] = {                               \
            &R_DMAC_B0_EX->DMAEOC,                                                         \
            &R_DMAC_B1_EX->DMAEOC,                                                         \
        };                                                                                 \
        volatile uint32_t              * p_target_register = DMAEOC_TABLE[unit];           \
        uint32_t reg_value     = *p_target_register;                                       \
        uint32_t channel_shift = 1U << channel;                                            \
        reg_value &= ~(channel_shift | (channel_shift << R_DMAC_B0_EX_DMAEOC_ENDPC0_Pos)); \
        reg_value |= ack_output_signal_active_level |                                      \
                     (tend_output_signal_active_level << R_DMAC_B0_EX_DMAEOC_ENDPC0_Pos);  \
        *p_target_register = reg_value;                                                    \
    } while (0)

// *UNCRUSTIFY-OFF*

typedef enum e_dmac_trigger_event
{
    DMAC_TRIGGER_EVENT_SOFTWARE_TRIGGER      = 0,
    DMAC_TRIGGER_EVENT_GTM_OSTM0TINT         = ((0x8 << 2UL) | 0x3) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM1TINT         = ((0x9 << 2UL) | 0x3) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GTM_OSTM2TINT         = ((0xA << 2UL) | 0x3) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA0            = ((0x10 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB0            = ((0x11 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC0            = ((0x12 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID0            = ((0x13 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA1            = ((0x14 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB1            = ((0x15 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA2            = ((0x16 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB2            = ((0x17 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA3            = ((0x18 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB3            = ((0x19 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC3            = ((0x1A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID3            = ((0x1B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA4            = ((0x1C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB4            = ((0x1D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC4            = ((0x1E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID4            = ((0x1F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TCIV4            = ((0x20 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIU5            = ((0x21 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIV5            = ((0x22 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIW5            = ((0x23 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA6            = ((0x24 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB6            = ((0x25 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC6            = ((0x26 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID6            = ((0x27 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA7            = ((0x28 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB7            = ((0x29 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC7            = ((0x2A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID7            = ((0x2B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TCIV7            = ((0x2C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIA8            = ((0x2D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIB8            = ((0x2E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGIC8            = ((0x2F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_MTU3_TGID8            = ((0x30 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA0            = ((0x31 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB0            = ((0x32 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC0             = ((0x33 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD0             = ((0x34 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE0             = ((0x35 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF0             = ((0x36 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA0           = ((0x37 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB0           = ((0x38 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF0              = ((0x39 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF0              = ((0x3A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC0AB_HIGH     = ((0x3B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC0AB_LOW      = ((0x3C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT0DTERR         = ((0x3D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA1            = ((0x3E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB1            = ((0x3F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC1             = ((0x40 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD1             = ((0x41 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE1             = ((0x42 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF1             = ((0x43 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA1           = ((0x44 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB1           = ((0x45 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF1              = ((0x46 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF1              = ((0x47 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC1AB_HIGH     = ((0x48 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC1AB_LOW      = ((0x49 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT1DTERR         = ((0x4A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA2            = ((0x4B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB2            = ((0x4C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC2             = ((0x4D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD2             = ((0x4E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE2             = ((0x4F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF2             = ((0x50 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA2           = ((0x51 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB2           = ((0x52 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF2              = ((0x53 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF2              = ((0x54 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC2AB_HIGH     = ((0x55 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC2AB_LOW      = ((0x56 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT2DTERR         = ((0x57 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA3            = ((0x58 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB3            = ((0x59 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC3             = ((0x5A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD3             = ((0x5B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE3             = ((0x5C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF3             = ((0x5D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA3           = ((0x5E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB3           = ((0x5F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF3              = ((0x60 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF3              = ((0x61 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC3AB_HIGH     = ((0x62 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC3AB_LOW      = ((0x63 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT3DTERR         = ((0x64 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA4            = ((0x65 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB4            = ((0x66 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC4             = ((0x67 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD4             = ((0x68 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE4             = ((0x69 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF4             = ((0x6A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA4           = ((0x6B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB4           = ((0x6C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF4              = ((0x6D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF4              = ((0x6E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC4AB_HIGH     = ((0x6F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC4AB_LOW      = ((0x70 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT4DTERR         = ((0x71 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA5            = ((0x72 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB5            = ((0x73 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC5             = ((0x74 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD5             = ((0x75 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE5             = ((0x76 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF5             = ((0x77 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA5           = ((0x78 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB5           = ((0x79 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF5              = ((0x7A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF5              = ((0x7B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC5AB_HIGH     = ((0x7C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC5AB_LOW      = ((0x7D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT5DTERR         = ((0x7E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA6            = ((0x7F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB6            = ((0x80 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC6             = ((0x81 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD6             = ((0x82 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE6             = ((0x83 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF6             = ((0x84 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA6           = ((0x85 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB6           = ((0x86 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF6              = ((0x87 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF6              = ((0x88 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC6AB_HIGH     = ((0x89 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC6AB_LOW      = ((0x8A << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT6DTERR         = ((0x8B << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPA7            = ((0x8C << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CCMPB7            = ((0x8D << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPC7             = ((0x8E << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPD7             = ((0x8F << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPE7             = ((0x90 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_CMPF7             = ((0x91 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGA7           = ((0x92 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_ADTRGB7           = ((0x93 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_OVF7              = ((0x94 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_UNF7              = ((0x95 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC7AB_HIGH     = ((0x96 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GTIOC7AB_LOW      = ((0x97 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_GPT_GPT7DTERR         = ((0x98 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX0          = ((0x99 << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX0          = ((0x99 << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX1          = ((0x9A << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX1          = ((0x9A << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX2          = ((0x9B << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX2          = ((0x9B << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_RX3          = ((0x9C << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SSIF_DMA_TX3          = ((0x9C << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SRC_IDEI              = ((0x9D << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SRC_ODFI              = ((0x9D << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI0       = ((0xA2 << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI0       = ((0xA2 << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI1       = ((0xA3 << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI1       = ((0xA3 << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI2       = ((0xA4 << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI2       = ((0xA4 << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_RI3       = ((0xA5 << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I2C_INTRIIC_TI3       = ((0xA5 << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRESP           = ((0xA6 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTCMD            = ((0xA7 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTIBI            = ((0xA8 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRX             = ((0xA9 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTTX             = ((0xA9 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_I3C_INTRCV            = ((0xAA << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCIF_RXI0             = ((0xAE << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI0             = ((0xAE << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI1             = ((0xAF << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI1             = ((0xAF << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI2             = ((0xB0 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI2             = ((0xB0 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI3             = ((0xB1 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI3             = ((0xB1 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI4             = ((0xB2 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI4             = ((0xB2 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_RXI5             = ((0xB3 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCIF_TXI5             = ((0xB3 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SCI0_RXI              = ((0xB4 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI0_TXI              = ((0xB4 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI0_AED              = ((0xB5 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_RXI              = ((0xB6 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_TXI              = ((0xB6 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI1_AED              = ((0xB7 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_RXI              = ((0xB8 << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_TXI              = ((0xB8 << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI2_AED              = ((0xB9 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_RXI              = ((0xBA << 2UL) | 0x2) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_TXI              = ((0xBA << 2UL) | 0x1) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SCI3_AED              = ((0xBB << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI0_RXI              = ((0xBC << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI0_TXI              = ((0xBC << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI1_RXI              = ((0xBD << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI1_TXI              = ((0xBD << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI2_RXI              = ((0xBE << 2UL) | 0x2) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPI2_TXI              = ((0xBE << 2UL) | 0x1) | ACK_MODE_BUS_CYCLE_MODE | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA0        = ((0xBF << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA1        = ((0xC0 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA2        = ((0xC1 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA3        = ((0xC2 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA4        = ((0xC3 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA5        = ((0xC4 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA6        = ((0xC5 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_RXF_DMA7        = ((0xC6 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA0        = ((0xC7 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA1        = ((0xC8 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_CANFD_COM_DMA2        = ((0xC9 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_TX    = ((0x9E << 2UL) | 0x1) | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SPDIF_RBDMAREQN_RX    = ((0x9E << 2UL) | 0x2) | ACK_MODE_LEVEL_MODE | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT0     = ((0x9F << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT1     = ((0xA0 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_PDM0_INT_PDM_DAT2     = ((0xA1 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_HIGH_LEVEL,
    DMAC_TRIGGER_EVENT_SHIP_INTEGRATE_RDRDYB = ((0xD0 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_SHIP_INTEGRATE_WRRDYB = ((0xD1 << 2UL) | 0x3) | ACK_MODE_MASK_DACK_OUTPUT | DETECTION_RISING_EDGE,
    DMAC_TRIGGER_EVENT_DMAC_REQ0_IN_DACK_PULSE = ((0x0 << 2UL) | 0x3),
    DMAC_TRIGGER_EVENT_DMAC_REQ1_IN_DACK_PULSE = ((0x1 << 2UL) | 0x3),
    DMAC_TRIGGER_EVENT_DMAC_REQ2_IN_DACK_PULSE = ((0x2 << 2UL) | 0x3),
    DMAC_TRIGGER_EVENT_DMAC_REQ3_IN_DACK_PULSE = ((0x3 << 2UL) | 0x3),
    DMAC_TRIGGER_EVENT_DMAC_REQ4_IN_DACK_PULSE = ((0x4 << 2UL) | 0x3),
    DMAC_TRIGGER_EVENT_DMAC_REQ0_IN_DACK_LEVEL = ((0x0 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_DMAC_REQ1_IN_DACK_LEVEL = ((0x1 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_DMAC_REQ2_IN_DACK_LEVEL = ((0x2 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_DMAC_REQ3_IN_DACK_LEVEL = ((0x3 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE,
    DMAC_TRIGGER_EVENT_DMAC_REQ4_IN_DACK_LEVEL = ((0x4 << 2UL) | 0x3) | ACK_MODE_LEVEL_MODE,
} dmac_trigger_event_t;

// *UNCRUSTIFY-ON*

typedef enum e_dmac_b_external_input_pin
{
    DMAC_B_EXTERNAL_INPUT_PIN_INPUT    = 0,
    DMAC_B_EXTERNAL_INPUT_PIN_NO_INPUT = 0x7F
} dmac_b_external_input_pin_t;

typedef enum e_dmac_b_external_output_pin
{
    DMAC_B_EXTERNAL_OUTPUT_PIN_OUTPUT    = 0,
    DMAC_B_EXTERNAL_OUTPUT_PIN_NO_OUTPUT = 0x7F
} dmac_b_external_output_pin_t;

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
 #define R_BSP_DMAC_ACTIVATION_SOURCE_ENABLE(dmac_reg, unit, channel, activation)                             \
    do                                                                                                        \
    {                                                                                                         \
        static volatile uint32_t * const DMARSk_TABLE[2][8] = {                                               \
            {&R_DMAC_B0_EX->DMARS0, &R_DMAC_B0_EX->DMARS1, &R_DMAC_B0_EX->DMARS2, &R_DMAC_B0_EX->DMARS3,      \
             &R_DMAC_B0_EX->DMARS4, &R_DMAC_B0_EX->DMARS5, &R_DMAC_B0_EX->DMARS6, &R_DMAC_B0_EX->DMARS7},     \
            {&R_DMAC_B1_EX->DMARS0, &R_DMAC_B1_EX->DMARS1, &R_DMAC_B1_EX->DMARS2, &R_DMAC_B1_EX->DMARS3,      \
             &R_DMAC_B1_EX->DMARS4, &R_DMAC_B1_EX->DMARS5, &R_DMAC_B1_EX->DMARS6, &R_DMAC_B1_EX->DMARS7},     \
        };                                                                                                    \
        volatile uint32_t              * p_target_register = DMARSk_TABLE[unit][channel / 2];                 \
        uint32_t reg_value    = *p_target_register;                                                           \
        uint32_t bit_position = (channel % 2) * 16U;                                                          \
        uint32_t clear_mask   = ACTIVATION_SOURCE_CLEAR_Msk << bit_position;                                  \
        reg_value         &= ~clear_mask;                                                                     \
        reg_value         |= ((uint16_t) activation) << bit_position;                                         \
        *p_target_register = reg_value;                                                                       \
                                                                                                              \
        p_target_register = &dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG;                                \
        reg_value         = *p_target_register;                                                               \
        uint32_t ack_clear_mask    = R_DMAC_B0_GRP_CH_CHCFG_AM_Msk;                                           \
        uint32_t ack_value         = ((activation >> 16U) << R_DMAC_B0_GRP_CH_CHCFG_AM_Pos) & ack_clear_mask; \
        uint32_t detect_clear_mask = R_DMAC_B0_GRP_CH_CHCFG_LOEN_Msk | R_DMAC_B0_GRP_CH_CHCFG_HIEN_Msk |      \
                                     R_DMAC_B0_GRP_CH_CHCFG_LVL_Msk;                                          \
        uint32_t detect_value = ((activation >> 24U) << R_DMAC_B0_GRP_CH_CHCFG_LOEN_Pos) & detect_clear_mask; \
        reg_value         &= ~(ack_clear_mask | detect_clear_mask);                                           \
        reg_value         |= ack_value | detect_value;                                                        \
        *p_target_register = reg_value;                                                                       \
    } while (0)

/* If this macro is intended for use only within r_dmac_b.c, it is advisable to redefine it as a file-scoped static
 * function inside r_dmac_b.c, instead of placing it in a header file. */
 #define R_BSP_DMAC_ACTIVATION_SOURCE_DISABLE(dmac_reg, unit, channel)                                    \
    do                                                                                                    \
    {                                                                                                     \
        static volatile uint32_t * const DMARSk_TABLE[2][8] = {                                           \
            {&R_DMAC_B0_EX->DMARS0, &R_DMAC_B0_EX->DMARS1, &R_DMAC_B0_EX->DMARS2, &R_DMAC_B0_EX->DMARS3,  \
             &R_DMAC_B0_EX->DMARS4, &R_DMAC_B0_EX->DMARS5, &R_DMAC_B0_EX->DMARS6, &R_DMAC_B0_EX->DMARS7}, \
            {&R_DMAC_B1_EX->DMARS0, &R_DMAC_B1_EX->DMARS1, &R_DMAC_B1_EX->DMARS2, &R_DMAC_B1_EX->DMARS3,  \
             &R_DMAC_B1_EX->DMARS4, &R_DMAC_B1_EX->DMARS5, &R_DMAC_B1_EX->DMARS6, &R_DMAC_B1_EX->DMARS7}, \
        };                                                                                                \
        volatile uint32_t              * p_target_register = DMARSk_TABLE[unit][channel / 2];             \
        uint32_t bit_position = (channel % 2) * 16U;                                                      \
        uint32_t clear_mask   = ACTIVATION_SOURCE_CLEAR_Msk << bit_position;                              \
        *p_target_register &= ~clear_mask;                                                                \
                                                                                                          \
        /* Clear the DMA Transfer Request Detection and DMA acknowledge output settings. */               \
        p_target_register = &dmac_reg->GRP[channel / 8].CH[channel % 8].CHCFG;                            \
        uint32_t reg_value         = *p_target_register;                                                  \
        uint32_t ack_clear_mask    = R_DMAC_B0_GRP_CH_CHCFG_AM_Msk;                                       \
        uint32_t detect_clear_mask = R_DMAC_B0_GRP_CH_CHCFG_LOEN_Msk | R_DMAC_B0_GRP_CH_CHCFG_HIEN_Msk |  \
                                     R_DMAC_B0_GRP_CH_CHCFG_LVL_Msk;                                      \
        reg_value         &= ~(ack_clear_mask | detect_clear_mask);                                       \
        reg_value         |= DMAC_B_ACK_MODE_MASK_DACK_OUTPUT;                                            \
        *p_target_register = reg_value;                                                                   \
    } while (0)

/** @} (end addtogroup RZG_BSP_MPU_RZG3L) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif                                 /* BSP_DMAC_H */
