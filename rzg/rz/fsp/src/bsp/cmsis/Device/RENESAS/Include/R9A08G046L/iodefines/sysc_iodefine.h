/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/**********************************************************************************************************************
 * File Name    : sysc_iodefine.h
 * Version      : 1.00
 * Description  : IO define file for sysc.
 *********************************************************************************************************************//* =========================================================================================================================== */

/* ================                              Device Specific Cluster Section                              ================ */
/* =========================================================================================================================== */

/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */

#ifndef SYSC_IODEFINE_H
#define SYSC_IODEFINE_H

typedef struct
{
    union
    {
        __IOM uint32_t SYS_MSTACCCTL0;
        struct
        {
            __IOM uint32_t DMAC0_AWPU  : 1;
            __IOM uint32_t DMAC0_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t DMAC0_AWSEL : 1;
            __IOM uint32_t DMAC0_ARPU  : 1;
            __IOM uint32_t DMAC0_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t DMAC0_ARSEL : 1;
            __IM uint32_t  DMAC1_AWPU  : 1;
            __IM uint32_t  DMAC1_AWNS  : 1;
            uint32_t                   : 1;
            __IM uint32_t DMAC1_AWSEL  : 1;
            __IM uint32_t DMAC1_ARPU   : 1;
            __IM uint32_t DMAC1_ARNS   : 1;
            uint32_t                   : 1;
            __IM uint32_t  DMAC1_ARSEL : 1;
            __IOM uint32_t GPU_AWPU    : 1;
            __IOM uint32_t GPU_AWNS    : 1;
            uint32_t                   : 1;
            __IOM uint32_t GPU_AWSEL   : 1;
            __IOM uint32_t GPU_ARPU    : 1;
            __IOM uint32_t GPU_ARNS    : 1;
            uint32_t                   : 1;
            __IOM uint32_t GPU_ARSEL   : 1;
            uint32_t                   : 8;
        } SYS_MSTACCCTL0_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL1;
        struct
        {
            __IOM uint32_t SDHI0_AWPU    : 1;
            __IOM uint32_t SDHI0_AWNS    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SDHI0_AWSEL   : 1;
            __IOM uint32_t SDHI0_ARPU    : 1;
            __IOM uint32_t SDHI0_ARNS    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SDHI0_ARSEL   : 1;
            __IOM uint32_t SDHI1_AWPU    : 1;
            __IOM uint32_t SDHI1_AWNS    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SDHI1_AWSEL   : 1;
            __IOM uint32_t SDHI1_ARPU    : 1;
            __IOM uint32_t SDHI1_ARNS    : 1;
            uint32_t                     : 1;
            __IOM uint32_t SDHI1_ARSEL   : 1;
            __IOM uint32_t GEther0_AWPU  : 1;
            __IOM uint32_t GEther0_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t GEther0_AWSEL : 1;
            __IOM uint32_t GEther0_ARPU  : 1;
            __IOM uint32_t GEther0_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t GEther0_ARSEL : 1;
            __IOM uint32_t GEther1_AWPU  : 1;
            __IOM uint32_t GEther1_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t GEther1_AWSEL : 1;
            __IOM uint32_t GEther1_ARPU  : 1;
            __IOM uint32_t GEther1_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t GEther1_ARSEL : 1;
        } SYS_MSTACCCTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL2;
        struct
        {
            __IOM uint32_t USB2_0H_AWPU  : 1;
            __IOM uint32_t USB2_0H_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_0H_AWSEL : 1;
            __IOM uint32_t USB2_0H_ARPU  : 1;
            __IOM uint32_t USB2_0H_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_0H_ARSEL : 1;
            __IOM uint32_t USB2_0D_AWPU  : 1;
            __IOM uint32_t USB2_0D_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_0D_AWSEL : 1;
            __IOM uint32_t USB2_0D_ARPU  : 1;
            __IOM uint32_t USB2_0D_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_0D_ARSEL : 1;
            __IOM uint32_t USB2_1H_AWPU  : 1;
            __IOM uint32_t USB2_1H_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_1H_AWSEL : 1;
            __IOM uint32_t USB2_1H_ARPU  : 1;
            __IOM uint32_t USB2_1H_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_1H_ARSEL : 1;
            __IOM uint32_t USB2_1D_AWPU  : 1;
            __IOM uint32_t USB2_1D_AWNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_1D_AWSEL : 1;
            __IOM uint32_t USB2_1D_ARPU  : 1;
            __IOM uint32_t USB2_1D_ARNS  : 1;
            uint32_t                     : 1;
            __IOM uint32_t USB2_1D_ARSEL : 1;
        } SYS_MSTACCCTL2_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL3;
        struct
        {
            __IOM uint32_t H264_AWPU   : 1;
            __IOM uint32_t H264_AWNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t H264_AWSEL  : 1;
            __IOM uint32_t H264_ARPU   : 1;
            __IOM uint32_t H264_ARNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t H2642_ARSEL : 1;
            __IOM uint32_t LCDC_AWPU   : 1;
            __IOM uint32_t LCDC_AWNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t LCDC_AWSEL  : 1;
            __IOM uint32_t LCDC_ARPU   : 1;
            __IOM uint32_t LCDC_ARNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t LCDC_ARSEL  : 1;
            __IOM uint32_t DSI_AWPU    : 1;
            __IOM uint32_t DSI_AWNS    : 1;
            uint32_t                   : 1;
            __IOM uint32_t DSI_AWSEL   : 1;
            __IOM uint32_t DSI_ARPU    : 1;
            __IOM uint32_t DSI_ARNS    : 1;
            uint32_t                   : 1;
            __IOM uint32_t DSI_ARSEL   : 1;
            uint32_t                   : 8;
        } SYS_MSTACCCTL3_b;
    };
    union
    {
        __IOM uint32_t SYS_MSTACCCTL4;
        struct
        {
            __IOM uint32_t ISU_AWPU     : 1;
            __IOM uint32_t ISU_AWNS     : 1;
            uint32_t                    : 1;
            __IOM uint32_t ISU_AWSEL    : 1;
            __IOM uint32_t ISU_ARPU     : 1;
            __IOM uint32_t ISU_ARNS     : 1;
            uint32_t                    : 1;
            __IOM uint32_t ISU_ARSEL    : 1;
            uint32_t                    : 8;
            __IOM uint32_t CRU_VD_AWPU  : 1;
            __IOM uint32_t CRU_VD_AWNS  : 1;
            uint32_t                    : 1;
            __IOM uint32_t CRU_VD_AWSEL : 1;
            uint32_t                    : 12;
        } SYS_MSTACCCTL4_b;
    };
    __IM uint8_t RESERVED[4];
    union
    {
        __IOM uint32_t SYS_MSTACCCTL6;
        struct
        {
            __IOM uint32_t SDHI2_AWPU  : 1;
            __IOM uint32_t SDHI2_AWNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SDHI2_AWSEL : 1;
            __IOM uint32_t SDHI2_ARPU  : 1;
            __IOM uint32_t SDHI2_ARNS  : 1;
            uint32_t                   : 1;
            __IOM uint32_t SDHI2_ARSEL : 1;
            __IOM uint32_t PCIE_AWPU   : 1;
            __IOM uint32_t PCIE_AWNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t PCIE_AWSEL  : 1;
            __IOM uint32_t PCIE_ARPU   : 1;
            __IOM uint32_t PCIE_ARNS   : 1;
            uint32_t                   : 1;
            __IOM uint32_t PCIE_ARSEL  : 1;
            uint32_t                   : 16;
        } SYS_MSTACCCTL6_b;
    };
    __IM uint8_t RESERVED1[228];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL0;
        struct
        {
            __IOM uint32_t SRAM0_SL : 2;
            __IOM uint32_t SRAM1_SL : 2;
            uint32_t                : 28;
        } SYS_SLVACCCTL0_b;
    };
    __IM uint8_t RESERVED2[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL2;
        struct
        {
            __IOM uint32_t TZC0_SL : 2;
            __IOM uint32_t TZC1_SL : 2;
            uint32_t               : 6;
            __IOM uint32_t TZC5_SL : 2;
            __IOM uint32_t TZC6_SL : 2;
            uint32_t               : 18;
        } SYS_SLVACCCTL2_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL3;
        struct
        {
            __IOM uint32_t CST_SL       : 2;
            __IOM uint32_t CPG_SL       : 2;
            __IM uint32_t  SYSC_SL      : 2;
            __IOM uint32_t SYC_SL       : 2;
            __IOM uint32_t GIC_SL       : 2;
            __IOM uint32_t IA55_IM33_SL : 2;
            __IOM uint32_t GPIO_SL      : 2;
            __IOM uint32_t MHU_SL       : 2;
            __IOM uint32_t GPU_SL       : 2;
            __IOM uint32_t H264_SL      : 2;
            __IOM uint32_t CRU_SL       : 2;
            __IOM uint32_t ISU_SL       : 2;
            __IOM uint32_t DSIPHY_SL    : 2;
            __IOM uint32_t DSILINK_SL   : 2;
            __IOM uint32_t LCDC_SL      : 2;
            uint32_t                    : 2;
        } SYS_SLVACCCTL3_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL4;
        struct
        {
            __IOM uint32_t DMAC0_SL : 2;
            __IOM uint32_t DMAC1_SL : 2;
            __IOM uint32_t OSTM0_SL : 2;
            __IOM uint32_t OSTM1_SL : 2;
            __IOM uint32_t OSTM2_SL : 2;
            uint32_t                : 10;
            __IOM uint32_t WDT0_SL  : 2;
            __IOM uint32_t WDT1_SL  : 2;
            __IOM uint32_t WDT2_SL  : 2;
            uint32_t                : 2;
            __IOM uint32_t RTC_SL   : 2;
            uint32_t                : 2;
        } SYS_SLVACCCTL4_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL5;
        struct
        {
            __IOM uint32_t MTU3A_SL : 2;
            __IOM uint32_t POE3_SL  : 2;
            __IOM uint32_t GPT_SL   : 2;
            __IOM uint32_t POEG_SL  : 2;
            __IOM uint32_t DDR_SL   : 2;
            uint32_t                : 22;
        } SYS_SLVACCCTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL6;
        struct
        {
            __IOM uint32_t USBT_SL  : 2;
            __IOM uint32_t USB20_SL : 2;
            __IOM uint32_t USB21_SL : 2;
            __IOM uint32_t SDHI0_SL : 2;
            __IOM uint32_t SDHI1_SL : 2;
            __IOM uint32_t SDHI2_SL : 2;
            __IOM uint32_t ETH0_SL  : 2;
            __IOM uint32_t ETH1_SL  : 2;
            __IOM uint32_t PCIE_SL  : 2;
            uint32_t                : 14;
        } SYS_SLVACCCTL6_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL7;
        struct
        {
            __IOM uint32_t I2C0_SL  : 2;
            __IOM uint32_t I2C1_SL  : 2;
            __IOM uint32_t I2C2_SL  : 2;
            __IOM uint32_t I2C3_SL  : 2;
            __IOM uint32_t I3C_SL   : 2;
            __IOM uint32_t CANFD_SL : 2;
            __IOM uint32_t RSPI0_SL : 2;
            __IOM uint32_t RSPI1_SL : 2;
            __IOM uint32_t RSPI2_SL : 2;
            uint32_t                : 14;
        } SYS_SLVACCCTL7_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL8;
        struct
        {
            __IOM uint32_t SCIF0_SL : 2;
            __IOM uint32_t SCIF1_SL : 2;
            __IOM uint32_t SCIF2_SL : 2;
            __IOM uint32_t SCIF3_SL : 2;
            __IOM uint32_t SCIF4_SL : 2;
            __IOM uint32_t SCIF5_SL : 2;
            uint32_t                : 6;
            __IOM uint32_t RSCI0_SL : 2;
            __IOM uint32_t RSCI1_SL : 2;
            __IOM uint32_t RSCI2_SL : 2;
            __IOM uint32_t RSCI3_SL : 2;
            uint32_t                : 6;
        } SYS_SLVACCCTL8_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL9;
        struct
        {
            __IOM uint32_t SSIF0_SL : 2;
            __IOM uint32_t SSIF1_SL : 2;
            __IOM uint32_t SSIF2_SL : 2;
            __IOM uint32_t SSIF3_SL : 2;
            uint32_t                : 2;
            __IOM uint32_t SPDIF_SL : 2;
            __IOM uint32_t PDM_SL   : 2;
            uint32_t                : 18;
        } SYS_SLVACCCTL9_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL10;
        struct
        {
            __IOM uint32_t ADC_SL : 2;
            __IOM uint32_t TSU_SL : 2;
            uint32_t              : 28;
        } SYS_SLVACCCTL10_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL11;
        struct
        {
            uint32_t                : 2;
            __IOM uint32_t OTP_SL   : 2;
            uint32_t                : 6;
            __IOM uint32_t VBATT_SL : 2;
            __IOM uint32_t BSC_SL   : 2;
            uint32_t                : 18;
        } SYS_SLVACCCTL11_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL12;
        struct
        {
            __IOM uint32_t CA55_SL : 2;
            __IOM uint32_t CM33_SL : 2;
            uint32_t               : 28;
        } SYS_SLVACCCTL12_b;
    };
    __IM uint8_t RESERVED3[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL14;
        struct
        {
            __IOM uint32_t LSI_SL : 2;
            uint32_t              : 30;
        } SYS_SLVACCCTL14_b;
    };
    __IM uint8_t RESERVED4[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL16;
        struct
        {
            __IOM uint32_t AOF_SL : 2;
            uint32_t              : 30;
        } SYS_SLVACCCTL16_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL17;
        struct
        {
            __IOM uint32_t LP_SL : 2;
            uint32_t             : 30;
        } SYS_SLVACCCTL17_b;
    };
    union
    {
        __IOM uint32_t SYS_SLVACCCTL18;
        struct
        {
            __IOM uint32_t GPREG_SL : 2;
            uint32_t                : 30;
        } SYS_SLVACCCTL18_b;
    };
    __IM uint8_t RESERVED5[4];
    union
    {
        __IOM uint32_t SYS_SLVACCCTL20;
        struct
        {
            __IOM uint32_t IPCONT_SL : 2;
            uint32_t                 : 30;
        } SYS_SLVACCCTL20_b;
    };
    __IM uint8_t RESERVED6[172];
    union
    {
        __IOM uint32_t SYS_RAM0_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_RAM0_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM0_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_RAM0_EN_b;
    };
    __IM uint8_t RESERVED7[8];
    union
    {
        __IOM uint32_t SYS_RAM1_ECC;
        struct
        {
            __IOM uint32_t VECCEN : 1;
            uint32_t              : 31;
        } SYS_RAM1_ECC_b;
    };
    union
    {
        __IOM uint32_t SYS_RAM1_EN;
        struct
        {
            __IOM uint32_t VCEN  : 1;
            __IOM uint32_t VLWEN : 1;
            uint32_t             : 30;
        } SYS_RAM1_EN_b;
    };
    __IM uint8_t RESERVED8[56];
    union
    {
        __IOM uint32_t SYS_WDT0_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP     : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT0_CTRL_b;
    };
    __IM uint8_t RESERVED9[12];
    union
    {
        __IOM uint32_t SYS_WDT1_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP     : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT1_CTRL_b;
    };
    __IM uint8_t RESERVED10[12];
    union
    {
        __IOM uint32_t SYS_WDT2_CTRL;
        struct
        {
            __IOM uint32_t WDTSTOP     : 1;
            uint32_t                   : 15;
            __IOM uint32_t WDTSTOPMASK : 1;
            uint32_t                   : 15;
        } SYS_WDT2_CTRL_b;
    };
    __IM uint8_t RESERVED11[212];
    union
    {
        __IOM uint32_t SYS_XSPI_MAP_STAADD_CS0;
        struct
        {
            __IOM uint32_t MAP_STAADD_CS0 : 32;
        } SYS_XSPI_MAP_STAADD_CS0_b;
    };
    union
    {
        __IOM uint32_t SYS_XSPI_MAP_ENDADD_CS0;
        struct
        {
            __IOM uint32_t MAP_ENDADD_CS0 : 32;
        } SYS_XSPI_MAP_ENDADD_CS0_b;
    };
    union
    {
        __IOM uint32_t SYS_XSPI_MAP_STAADD_CS1;
        struct
        {
            __IOM uint32_t MAP_STAADD_CS1 : 32;
        } SYS_XSPI_MAP_STAADD_CS1_b;
    };
    union
    {
        __IOM uint32_t SYS_XSPI_MAP_ENDADD_CS1;
        struct
        {
            __IOM uint32_t MAP_ENDADD_CS1 : 32;
        } SYS_XSPI_MAP_ENDADD_CS1_b;
    };
    __IM uint8_t RESERVED12[40];
    union
    {
        __IM uint32_t SYS_GETH0_CFG;
        struct
        {
            uint32_t                     : 4;
            __IM uint32_t MAC_SPEED      : 2;
            uint32_t                     : 2;
            __IM uint32_t PHY_INTF_SEL_I : 3;
            uint32_t                     : 21;
        } SYS_GETH0_CFG_b;
    };
    __IM uint8_t RESERVED13[12];
    union
    {
        __IM uint32_t SYS_GETH1_CFG;
        struct
        {
            uint32_t                     : 4;
            __IM uint32_t MAC_SPEED      : 2;
            uint32_t                     : 2;
            __IM uint32_t PHY_INTF_SEL_I : 3;
            uint32_t                     : 21;
        } SYS_GETH1_CFG_b;
    };
    __IM uint8_t RESERVED14[12];
    union
    {
        __IOM uint32_t SYS_PCIE_CFG;
        struct
        {
            uint32_t                      : 8;
            __IOM uint32_t ALLOW_ENTER_L1 : 1;
            uint32_t                      : 23;
        } SYS_PCIE_CFG_b;
    };
    union
    {
        __IM uint32_t SYS_PCIE_MON;
        struct
        {
            __IM uint32_t PMU_POWEROFF   : 1;
            __IM uint32_t CLKL1PM_REQ    : 1;
            uint32_t                     : 2;
            __IM uint32_t D_STATE_OUT_F0 : 2;
            uint32_t                     : 26;
        } SYS_PCIE_MON_b;
    };
    __IM uint8_t RESERVED15[12];
    union
    {
        __IOM uint32_t SYS_PCIE_PHY;
        struct
        {
            __IOM uint32_t MODE_RXTERMINATION : 1;
            uint32_t                          : 31;
        } SYS_PCIE_PHY_b;
    };
    __IM uint8_t RESERVED16[72];
    union
    {
        __IOM uint32_t SYS_I2C0_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C0_CFG_b;
    };
    __IM uint8_t RESERVED17[12];
    union
    {
        __IOM uint32_t SYS_I2C1_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C1_CFG_b;
    };
    __IM uint8_t RESERVED18[12];
    union
    {
        __IOM uint32_t SYS_I2C2_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C2_CFG_b;
    };
    __IM uint8_t RESERVED19[12];
    union
    {
        __IOM uint32_t SYS_I2C3_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I2C3_CFG_b;
    };
    __IM uint8_t RESERVED20[12];
    union
    {
        __IOM uint32_t SYS_I3C_CFG;
        struct
        {
            __IOM uint32_t af_bypass : 1;
            uint32_t                 : 31;
        } SYS_I3C_CFG_b;
    };
    __IM uint8_t RESERVED21[972];
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL0;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL0 : 30;
        } SYS_CA55_CFG_RVAL0_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH0;
        struct
        {
            __IOM uint32_t RVBARADDRH0 : 8;
            uint32_t                   : 24;
        } SYS_CA55_CFG_RVAH0_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL1;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL1 : 30;
        } SYS_CA55_CFG_RVAL1_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH1;
        struct
        {
            __IOM uint32_t RVBARADDRH1 : 8;
            uint32_t                   : 24;
        } SYS_CA55_CFG_RVAH1_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL2;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL2 : 30;
        } SYS_CA55_CFG_RVAL2_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH2;
        struct
        {
            __IOM uint32_t RVBARADDRH2 : 8;
            uint32_t                   : 24;
        } SYS_CA55_CFG_RVAH2_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAL3;
        struct
        {
            uint32_t                   : 2;
            __IOM uint32_t RVBARADDRL3 : 30;
        } SYS_CA55_CFG_RVAL3_b;
    };
    union
    {
        __IOM uint32_t SYS_CA55_CFG_RVAH3;
        struct
        {
            __IOM uint32_t RVBARADDRH3 : 8;
            uint32_t                   : 24;
        } SYS_CA55_CFG_RVAH3_b;
    };
    __IM uint8_t RESERVED22[52];
    union
    {
        __IOM uint32_t SYS_CM33_CFG0;
        struct
        {
            __IOM uint32_t CONFIGSSYSTICK : 26;
            uint32_t                      : 6;
        } SYS_CM33_CFG0_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG1;
        struct
        {
            __IOM uint32_t CONFIGNSSYSTICK : 26;
            uint32_t                       : 6;
        } SYS_CM33_CFG1_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG2;
        struct
        {
            uint32_t                 : 7;
            __IOM uint32_t INITSVTOR : 25;
        } SYS_CM33_CFG2_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_CFG3;
        struct
        {
            uint32_t                  : 7;
            __IOM uint32_t INITNSVTOR : 25;
        } SYS_CM33_CFG3_b;
    };
    union
    {
        __IOM uint32_t SYS_CM33_LOCK;
        struct
        {
            __IOM uint32_t LOCKSVTAIRCR : 1;
            __IOM uint32_t LOCKNSVTOR   : 1;
            uint32_t                    : 30;
        } SYS_CM33_LOCK_b;
    };
    __IM uint8_t RESERVED23[392];
    union
    {
        __IM uint32_t SYS_LSI_MODE;
        struct
        {
            __IM uint32_t STAT_BOOTCPUSEL : 1;
            uint32_t                      : 3;
            __IM uint32_t STAT_MD_BOOT    : 3;
            uint32_t                      : 2;
            __IM uint32_t STAT_DEBUGEN    : 1;
            uint32_t                      : 2;
            __IM uint32_t STAT_MD_CLKS    : 1;
            __IM uint32_t STAT_MD_BYPASS  : 1;
            uint32_t                      : 2;
            __IM uint32_t STAT_SEC_EN     : 1;
            uint32_t                      : 15;
        } SYS_LSI_MODE_b;
    };
    union
    {
        __IM uint32_t SYS_LSI_DEVID;
        struct
        {
            __IM uint32_t DEV_ID : 32;
        } SYS_LSI_DEVID_b;
    };
    __IM uint32_t SYS_LSI_PRR;
    __IM uint8_t  RESERVED24[504];
    union
    {
        __IOM uint32_t SYS_AOF1;
        struct
        {
            __IOM uint32_t OFS00_SXGIGE_0 : 4;
            __IOM uint32_t OFS01_SXGIGE_0 : 4;
            __IOM uint32_t OFS10_SXGIGE_0 : 4;
            __IOM uint32_t OFS11_SXGIGE_0 : 4;
            __IOM uint32_t OFS00_SXGIGE_1 : 4;
            __IOM uint32_t OFS01_SXGIGE_1 : 4;
            __IOM uint32_t OFS10_SXGIGE_1 : 4;
            __IOM uint32_t OFS11_SXGIGE_1 : 4;
        } SYS_AOF1_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF2;
        struct
        {
            __IOM uint32_t OFS00_SXUSB2_0_H : 4;
            __IOM uint32_t OFS01_SXUSB2_0_H : 4;
            __IOM uint32_t OFS10_SXUSB2_0_H : 4;
            __IOM uint32_t OFS11_SXUSB2_0_H : 4;
            __IOM uint32_t OFS00_SXUSB2_0_F : 4;
            __IOM uint32_t OFS01_SXUSB2_0_F : 4;
            __IOM uint32_t OFS10_SXUSB2_0_F : 4;
            __IOM uint32_t OFS11_SXUSB2_0_F : 4;
        } SYS_AOF2_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF3;
        struct
        {
            __IOM uint32_t OFS00_SXUSB2_1_H : 4;
            __IOM uint32_t OFS01_SXUSB2_1_H : 4;
            __IOM uint32_t OFS10_SXUSB2_1_H : 4;
            __IOM uint32_t OFS11_SXUSB2_1_H : 4;
            __IOM uint32_t OFS00_SXUSB2_1_F : 4;
            __IOM uint32_t OFS01_SXUSB2_1_F : 4;
            __IOM uint32_t OFS10_SXUSB2_1_F : 4;
            __IOM uint32_t OFS11_SXUSB2_1_F : 4;
        } SYS_AOF3_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF4;
        struct
        {
            __IOM uint32_t OFS00_SXVCP : 4;
            __IOM uint32_t OFS01_SXVCP : 4;
            __IOM uint32_t OFS10_SXVCP : 4;
            __IOM uint32_t OFS11_SXVCP : 4;
            __IOM uint32_t OFS00_SXDSI : 4;
            __IOM uint32_t OFS01_SXDSI : 4;
            __IOM uint32_t OFS10_SXDSI : 4;
            __IOM uint32_t OFS11_SXDSI : 4;
        } SYS_AOF4_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF5;
        struct
        {
            __IOM uint32_t OFS00_SXLCDC : 4;
            __IOM uint32_t OFS01_SXLCDC : 4;
            __IOM uint32_t OFS10_SXLCDC : 4;
            __IOM uint32_t OFS11_SXLCDC : 4;
            uint32_t                    : 16;
        } SYS_AOF5_b;
    };
    union
    {
        __IOM uint32_t SYS_AOF6;
        struct
        {
            __IOM uint32_t OFS00_SXDMAC_S  : 4;
            __IOM uint32_t OFS01_SXDMAC_S  : 4;
            __IOM uint32_t OFS10_SXDMAC_S  : 4;
            __IOM uint32_t OFS11_SXDMAC_S  : 4;
            __IOM uint32_t OFS00_SXDMAC_NS : 4;
            __IOM uint32_t OFS01_SXDMAC_NS : 4;
            __IOM uint32_t OFS10_SXDMAC_NS : 4;
            __IOM uint32_t OFS11_SXDMAC_NS : 4;
        } SYS_AOF6_b;
    };
    __IM uint8_t RESERVED25[232];
    union
    {
        __IOM uint32_t SYS_LP_CTL1;
        struct
        {
            uint32_t                     : 8;
            __IOM uint32_t CA55SLEEP_REQ : 4;
            __IOM uint32_t CM33SLEEP_REQ : 1;
            uint32_t                     : 11;
            __IOM uint32_t CA55SLEEP_ACK : 4;
            __IOM uint32_t CM33SLEEP_ACK : 1;
            uint32_t                     : 3;
        } SYS_LP_CTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL2;
        struct
        {
            __IOM uint32_t CA55_STBYCTL : 1;
            uint32_t                    : 31;
        } SYS_LP_CTL2_b;
    };
    __IM uint8_t RESERVED26[8];
    union
    {
        __IOM uint32_t SYS_LP_CTL5;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQDENY_F : 1;
            __IOM uint32_t AMCLKQDENY_F : 1;
            uint32_t                    : 5;
            __IOM uint32_t CA55SLEEP0_F : 1;
            __IOM uint32_t CA55SLEEP1_F : 1;
            __IOM uint32_t CA55SLEEP2_F : 1;
            __IOM uint32_t CA55SLEEP3_F : 1;
            __IOM uint32_t CM33SLEEP_F  : 1;
            uint32_t                    : 1;
            __IOM uint32_t PSCLKQDENY_F : 1;
            __IOM uint32_t PMCLKQDENY_F : 1;
            uint32_t                    : 16;
        } SYS_LP_CTL5_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL6;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQDENY_E : 1;
            __IOM uint32_t AMCLKQDENY_E : 1;
            uint32_t                    : 5;
            __IOM uint32_t CA55SLEEP0_E : 1;
            __IOM uint32_t CA55SLEEP1_E : 1;
            __IOM uint32_t CA55SLEEP2_E : 1;
            __IOM uint32_t CA55SLEEP3_E : 1;
            __IOM uint32_t CM33SLEEP_E  : 1;
            uint32_t                    : 1;
            __IOM uint32_t PSCLKQDENY_E : 1;
            __IOM uint32_t PMCLKQDENY_E : 1;
            uint32_t                    : 16;
        } SYS_LP_CTL6_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CTL7;
        struct
        {
            __IOM uint32_t IM33_MASK : 1;
            uint32_t                 : 31;
        } SYS_LP_CTL7_b;
    };
    __IM uint8_t RESERVED27[4];
    union
    {
        __IM uint32_t SYS_LP_CM33CTL0;
        struct
        {
            __IM uint32_t SLEEPMODE   : 1;
            uint32_t                  : 3;
            __IM uint32_t SLEEPDEEP   : 1;
            uint32_t                  : 4;
            __IM uint32_t SYSRESETREQ : 1;
            uint32_t                  : 22;
        } SYS_LP_CM33CTL0_b;
    };
    __IM uint8_t RESERVED28[16];
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL1;
        struct
        {
            uint32_t                     : 1;
            __IM uint32_t ASCLKQACTIVE   : 1;
            __IM uint32_t AMCLKQACTIVE   : 1;
            __IM uint32_t PSCLKQACTIVE   : 1;
            __IM uint32_t PMCLKQACTIVE   : 1;
            uint32_t                     : 3;
            __IM uint32_t PCLKQACTIVE    : 1;
            __IM uint32_t ATCLKQACTIVE   : 1;
            __IM uint32_t GICCLKQACTIVE  : 1;
            __IM uint32_t PDBGCLKQACTIVE : 1;
            uint32_t                     : 20;
        } SYS_LP_CA55CK_CTL1_b;
    };
    union
    {
        __IOM uint32_t SYS_LP_CA55CK_CTL2;
        struct
        {
            uint32_t                    : 1;
            __IOM uint32_t ASCLKQREQn   : 1;
            __IOM uint32_t AMCLKQREQn   : 1;
            __IOM uint32_t PSCLKQREQn   : 1;
            __IOM uint32_t PMCLKQREQn   : 1;
            uint32_t                    : 3;
            __IOM uint32_t PCLKQREQn    : 1;
            __IOM uint32_t ATCLKQREQn   : 1;
            __IOM uint32_t GICCLKQREQn  : 1;
            __IOM uint32_t PDBGCLKQREQn : 1;
            uint32_t                    : 20;
        } SYS_LP_CA55CK_CTL2_b;
    };
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL3;
        struct
        {
            __IM uint32_t CA55_COREINSTRRUN0 : 1;
            __IM uint32_t ASCLKQACCEPTn      : 1;
            __IM uint32_t AMCLKQACCEPTn      : 1;
            __IM uint32_t PSCLKQACCEPTn      : 1;
            __IM uint32_t PMCLKQACCEPTn      : 1;
            uint32_t                         : 3;
            __IM uint32_t PCLKQACCEPTn       : 1;
            __IM uint32_t ATCLKQACCEPTn      : 1;
            __IM uint32_t GICCLKQACCEPTn     : 1;
            __IM uint32_t PDBGCLKQACCEPTn    : 1;
            uint32_t                         : 4;
            __IM uint32_t CA55_COREINSTRRUN1 : 1;
            __IM uint32_t ASCLKQDENY         : 1;
            __IM uint32_t AMCLKQDENY         : 1;
            __IM uint32_t PSCLKQDENY         : 1;
            __IM uint32_t PMCLKQDENY         : 1;
            uint32_t                         : 3;
            __IM uint32_t PCLKQDENY          : 1;
            __IM uint32_t ATCLKQDENY         : 1;
            __IM uint32_t GICCLKQDENY        : 1;
            __IM uint32_t PDBGCLKQDENY       : 1;
            uint32_t                         : 4;
        } SYS_LP_CA55CK_CTL3_b;
    };
    __IM uint8_t RESERVED29[8];
    union
    {
        __IM uint32_t SYS_LP_CA55CK_CTL4;
        struct
        {
            __IM uint32_t CA55_COREINSTRRUN0 : 1;
            __IM uint32_t CA55_COREINSTRRUN1 : 1;
            __IM uint32_t CA55_COREINSTRRUN2 : 1;
            __IM uint32_t CA55_COREINSTRRUN3 : 1;
            uint32_t                         : 28;
        } SYS_LP_CA55CK_CTL4_b;
    };
    __IM uint8_t RESERVED30[16];
    union
    {
        __IOM uint32_t SYS_PD_ISO_CTRL;
        struct
        {
            __IOM uint32_t PD_ISOVCC_ISOEN   : 1;
            uint32_t                         : 7;
            __IOM uint32_t PD_ISOVCC_ISORSTN : 1;
            uint32_t                         : 23;
        } SYS_PD_ISO_CTRL_b;
    };
    __IM uint8_t RESERVED31[8];
    union
    {
        __IOM uint32_t SYS_ISO_IOBUF_SE18_CTRL;
        struct
        {
            __IOM uint32_t ISO_IOBUF_SE18 : 1;
            uint32_t                      : 31;
        } SYS_ISO_IOBUF_SE18_CTRL_b;
    };
    union
    {
        __IOM uint32_t SYS_PWRRDY_N;
        struct
        {
            __IOM uint32_t PWRRDY_N : 3;
            uint32_t                : 29;
        } SYS_PWRRDY_N_b;
    };
    __IM uint8_t RESERVED32[140];
    union
    {
        __IOM uint32_t SYS_GPREG_0;
        struct
        {
            __IOM uint32_t GPREG0 : 32;
        } SYS_GPREG_0_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_1;
        struct
        {
            __IOM uint32_t GPREG1 : 32;
        } SYS_GPREG_1_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_2;
        struct
        {
            __IOM uint32_t GPREG2 : 32;
        } SYS_GPREG_2_b;
    };
    union
    {
        __IOM uint32_t SYS_GPREG_3;
        struct
        {
            __IOM uint32_t GPREG3 : 32;
        } SYS_GPREG_3_b;
    };
    __IM uint8_t RESERVED33[20];
    union
    {
        __IOM uint32_t SYS_IPCONT_IDAUZERONS;
        struct
        {
            __IOM uint32_t IDAUZERONS : 1;
            uint32_t                  : 31;
        } SYS_IPCONT_IDAUZERONS_b;
    };
    __IM uint8_t RESERVED34[4];
    union
    {
        __IOM uint32_t SYS_IPCONT_SEL_CLONECH;
        struct
        {
            __IOM uint32_t IPCONT_SEL_CLONECH : 16;
            uint32_t                          : 16;
        } SYS_IPCONT_SEL_CLONECH_b;
    };
} R_SYSC_Type;

/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */

#define R_SYSC_BASE    0x41020000

/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */

#define R_SYSC    ((R_SYSC_Type *) R_SYSC_BASE)

#endif
