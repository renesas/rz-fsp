/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef BSP_IRQ_ID_H
 #define BSP_IRQ_ID_H

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
 #define DMAC_B0_DMAINT0_IRQn     DMAC_DMAINT0_S_IRQn
 #define DMAC_B0_DMAINT1_IRQn     DMAC_DMAINT1_S_IRQn
 #define DMAC_B0_DMAINT2_IRQn     DMAC_DMAINT2_S_IRQn
 #define DMAC_B0_DMAINT3_IRQn     DMAC_DMAINT3_S_IRQn
 #define DMAC_B0_DMAINT4_IRQn     DMAC_DMAINT4_S_IRQn
 #define DMAC_B0_DMAINT5_IRQn     DMAC_DMAINT5_S_IRQn
 #define DMAC_B0_DMAINT6_IRQn     DMAC_DMAINT6_S_IRQn
 #define DMAC_B0_DMAINT7_IRQn     DMAC_DMAINT7_S_IRQn
 #define DMAC_B0_DMAINT8_IRQn     DMAC_DMAINT8_S_IRQn
 #define DMAC_B0_DMAINT9_IRQn     DMAC_DMAINT9_S_IRQn
 #define DMAC_B0_DMAINT10_IRQn    DMAC_DMAINT10_S_IRQn
 #define DMAC_B0_DMAINT11_IRQn    DMAC_DMAINT11_S_IRQn
 #define DMAC_B0_DMAINT12_IRQn    DMAC_DMAINT12_S_IRQn
 #define DMAC_B0_DMAINT13_IRQn    DMAC_DMAINT13_S_IRQn
 #define DMAC_B0_DMAINT14_IRQn    DMAC_DMAINT14_S_IRQn
 #define DMAC_B0_DMAINT15_IRQn    DMAC_DMAINT15_S_IRQn
 #define DMAC_B1_DMAINT0_IRQn     DMAC_DMAINT0_NS_IRQn
 #define DMAC_B1_DMAINT1_IRQn     DMAC_DMAINT1_NS_IRQn
 #define DMAC_B1_DMAINT2_IRQn     DMAC_DMAINT2_NS_IRQn
 #define DMAC_B1_DMAINT3_IRQn     DMAC_DMAINT3_NS_IRQn
 #define DMAC_B1_DMAINT4_IRQn     DMAC_DMAINT4_NS_IRQn
 #define DMAC_B1_DMAINT5_IRQn     DMAC_DMAINT5_NS_IRQn
 #define DMAC_B1_DMAINT6_IRQn     DMAC_DMAINT6_NS_IRQn
 #define DMAC_B1_DMAINT7_IRQn     DMAC_DMAINT7_NS_IRQn
 #define DMAC_B1_DMAINT8_IRQn     DMAC_DMAINT8_NS_IRQn
 #define DMAC_B1_DMAINT9_IRQn     DMAC_DMAINT9_NS_IRQn
 #define DMAC_B1_DMAINT10_IRQn    DMAC_DMAINT10_NS_IRQn
 #define DMAC_B1_DMAINT11_IRQn    DMAC_DMAINT11_NS_IRQn
 #define DMAC_B1_DMAINT12_IRQn    DMAC_DMAINT12_NS_IRQn
 #define DMAC_B1_DMAINT13_IRQn    DMAC_DMAINT13_NS_IRQn
 #define DMAC_B1_DMAINT14_IRQn    DMAC_DMAINT14_NS_IRQn
 #define DMAC_B1_DMAINT15_IRQn    DMAC_DMAINT15_NS_IRQn
 #define DMAC_B0_DMAERR_IRQn      DMAC_DMAERR_S_IRQn
 #define DMAC_B1_DMAERR_IRQn      DMAC_DMAERR_NS_IRQn

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

typedef enum IRQn
{
    Reset_IRQn            = -15,
    NonMaskableInt_IRQn   = -14,
    HardFault_IRQn        = -13,
    MemoryManagement_IRQn = -12,
    BusFault_IRQn         = -11,
    UsageFault_IRQn       = -10,
    SecureFault_IRQn      = -9,
    SVCall_IRQn           = -5,
    DebugMonitor_IRQn     = -4,
    PendSV_IRQn           = -2,
    SysTick_IRQn          = -1,

    NMI_IRQn                   = 0,     /* IRQ No:0,   NMI */
    GPIO_IRQ0_IRQn             = 1,     /* IRQ No:1,   IRQ0 */
    GPIO_IRQ1_IRQn             = 2,     /* IRQ No:2,   IRQ1 */
    GPIO_IRQ2_IRQn             = 3,     /* IRQ No:3,   IRQ2 */
    GPIO_IRQ3_IRQn             = 4,     /* IRQ No:4,   IRQ3 */
    GPIO_IRQ4_IRQn             = 5,     /* IRQ No:5,   IRQ4 */
    GPIO_IRQ5_IRQn             = 6,     /* IRQ No:6,   IRQ5 */
    GPIO_IRQ6_IRQn             = 7,     /* IRQ No:7,   IRQ6 */
    GPIO_IRQ7_IRQn             = 8,     /* IRQ No:8,   IRQ7 */
    CM33_CTIIRQ1_IRQn          = 9,     /* IRQ No:9,   CTIIRQ[1] */
    CM33_CTIIRQ0_IRQn          = 10,    /* IRQ No:10,  CTIIRQ[0] */
    SYSTEMBUS_BUS_ERR_INT_IRQn = 11,    /* IRQ No:11,  BUS_ERR_INT */
                                        /* IRQ No:12,  Reserved */
    ECCRAM_EC7TIE1_IRQn     = 13,       /* IRQ No:13,  EC7TIE1_0 */
    ECCRAM_EC7TIE2_IRQn     = 14,       /* IRQ No:14,  EC7TIE2_0 */
    ECCRAM_EC7TIOVF_IRQn    = 15,       /* IRQ No:15,  EC7TIOVF_0 */
    DDR_CONTROLL_INT_IRQn   = 16,       /* IRQ No:16,  controller_int */
    DDR_DWC_DDRPHY_INT_IRQn = 17,       /* IRQ No:17,  dwc_ddrphy_int_n */
                                        /* IRQ No:18,  Reserved */
                                        /* IRQ No:19,  Reserved */
    XSPI_SPI_LEVEL_INT_IRQn     = 20,   /* IRQ No:20,  int_spi_level */
    XSPI_SPI_ERR_LEVEL_INT_IRQn = 21,   /* IRQ No:21,  int_spi_err_level */
    SYSC_LPM_INT_IRQn           = 22,   /* IRQ No:22,  SYS_LPM_INT */
    SYSC_CA55STBYDONE_INT_IRQn  = 23,   /* IRQ No:23,  SYS_CA55STBYDONE_INT */
    SYSC_CM33STBYR_INT_IRQn     = 24,   /* IRQ No:24,  SYS_CM33STBYR_INT */
    SYSC_CA55_DENY_IRQn         = 25,   /* IRQ No:25,  SYS_CA55_DENY */
    VBATTB_TAMPDI_IRQn          = 26,   /* IRQ No:26,  TAMPDI */
    GTM0_OSTM0INT_IRQn          = 27,   /* IRQ No:27,  OSTM0TINT */
    GTM1_OSTM1INT_IRQn          = 28,   /* IRQ No:28,  OSTM1TINT */
    GTM2_OSTM2INT_IRQn          = 29,   /* IRQ No:29,  OSTM2TINT */
                                        /* IRQ No:30,  PERROUT_NS */
                                        /* IRQ No:31,  WDTINT_NS */
                                        /* IRQ No:32,  PERROUT_S */
                                        /* IRQ No:33,  WDTINT_S */
    WDT2_PERROUT_IRQn = 34,             /* IRQ No:34,  PERROUT_M0 */
    WDT2_WDTINT_IRQn  = 35,             /* IRQ No:35,  WDTINT_M0 */
    MHU_MSG_NS_IRQn   = 36,             /* IRQ No:36,  MSG_NS_INT */
    MHU_RSP_NS_IRQn   = 37,             /* IRQ No:37,  RSP_NS_INT */
    MHU_MSG_S_IRQn    = 38,             /* IRQ No:38,  MSG_S_INT */
    MHU_RSP_S_IRQn    = 39,             /* IRQ No:39,  RSP_S_INT */
    MHU_SW_INT_IRQn   = 40,             /* IRQ No:40,  SW_INT */
                                        /* IRQ No:41,  Reserved */
                                        /* IRQ No:42,  Reserved */
                                        /* IRQ No:43,  Reserved */
                                        /* IRQ No:44,  Reserved */
                                        /* IRQ No:45,  Reserved */
                                        /* IRQ No:46,  Reserved */
                                        /* IRQ No:47,  Reserved */
                                        /* IRQ No:48,  Reserved */
                                        /* IRQ No:49,  Reserved */
                                        /* IRQ No:50,  Reserved */
                                        /* IRQ No:51,  Reserved */
                                        /* IRQ No:52,  Reserved */
                                        /* IRQ No:53,  Reserved */
                                        /* IRQ No:54,  Reserved */
                                        /* IRQ No:55,  Reserved */
                                        /* IRQ No:56,  Reserved */
                                        /* IRQ No:57,  Reserved */
                                        /* IRQ No:58,  Reserved */
                                        /* IRQ No:59,  Reserved */
                                        /* IRQ No:60,  Reserved */
                                        /* IRQ No:61,  Reserved */
                                        /* IRQ No:62,  Reserved */
                                        /* IRQ No:63,  Reserved */
                                        /* IRQ No:64,  Reserved */
                                        /* IRQ No:65,  Reserved */
                                        /* IRQ No:66,  Reserved */
                                        /* IRQ No:67,  Reserved */
                                        /* IRQ No:68,  Reserved */
                                        /* IRQ No:69,  Reserved */
                                        /* IRQ No:70,  Reserved */
                                        /* IRQ No:71,  Reserved */
                                        /* IRQ No:72,  Reserved */
                                        /* IRQ No:73,  Reserved */
                                        /* IRQ No:74,  Reserved */
    USB_U2H0_INT_IRQn           = 75,   /* IRQ No:75,  U2H0_INT */
    USB_U2H0_OHCI_INT_IRQn      = 76,   /* IRQ No:76,  U2H0_OHCI_INT */
    USB_U2H0_EHCI_INT_IRQn      = 77,   /* IRQ No:77,  U2H0_EHCI_INT */
    USB_U2H0_WAKEON_INT_IRQn    = 78,   /* IRQ No:78,  U2H0_WAKEON_INT */
    USB_U2H0_OBINT_IRQn         = 79,   /* IRQ No:79,  U2H0_OBINT */
    USB_U2H1_INT_IRQn           = 80,   /* IRQ No:80,  U2H1_INT */
    USB_U2H1_OHCI_INT_IRQn      = 81,   /* IRQ No:81,  U2H1_OHCI_INT */
    USB_U2H1_EHCI_INT_IRQn      = 82,   /* IRQ No:82,  U2H1_EHCI_INT */
    USB_U2H1_WAKEON_INT_IRQn    = 83,   /* IRQ No:83,  U2H1_WAKEON_INT */
    USB_U2H1_OBINT_IRQn         = 84,   /* IRQ No:84,  U2H1_OBINT */
    USB_U2P0_INT_DMAERR_IRQn    = 85,   /* IRQ No:85,  U2P0_INT_DMAERR */
    USB_U2P0_IXL_INT_IRQn       = 86,   /* IRQ No:86,  U2P0_IXL_INT */
    USB_U2P0_INT_DMA0_IRQn      = 87,   /* IRQ No:87,  U2P0_INT_DMA[0] */
    USB_U2P0_INT_DMA1_IRQn      = 88,   /* IRQ No:88,  U2P0_INT_DMA[1] */
    USB_U2P1_INT_DMAERR_IRQn    = 89,   /* IRQ No:89,  U2P1_INT_DMAERR */
    USB_U2P1_IXL_INT_IRQn       = 90,   /* IRQ No:90,  U2P1_IXL_INT */
    USB_U2P1_INT_DMA0_IRQn      = 91,   /* IRQ No:91,  U2P1_INT_DMA[0] */
    USB_U2P1_INT_DMA1_IRQn      = 92,   /* IRQ No:92,  U2P1_INT_DMA[1] */
    SDHI_eMMC0_OXMN_IRQn        = 93,   /* IRQ No:93,  OXMNIRQ0 */
    SDHI_eMMC0_OXASIO_IRQn      = 94,   /* IRQ No:94,  OXASIOIRQ0 */
    SDHI_eMMC1_OXMN_IRQn        = 95,   /* IRQ No:95,  OXMNIRQ1 */
    SDHI_eMMC1_OXASIO_IRQn      = 96,   /* IRQ No:96,  OXASIOIRQ1 */
    SDHI_eMMC2_OXMN_IRQn        = 97,   /* IRQ No:97,  OXMNIRQ2 */
    SDHI_eMMC2_OXASIO_IRQn      = 98,   /* IRQ No:98,  OXASIOIRQ2 */
    DMAC_DMAERR_S_IRQn          = 99,   /* IRQ No:99,  DMAERR_S */
    DMAC_DMAINT0_S_IRQn         = 100,  /* IRQ No:100,  DMAINT0_S */
    DMAC_DMAINT1_S_IRQn         = 101,  /* IRQ No:101,  DMAINT1_S */
    DMAC_DMAINT2_S_IRQn         = 102,  /* IRQ No:102,  DMAINT2_S */
    DMAC_DMAINT3_S_IRQn         = 103,  /* IRQ No:103,  DMAINT3_S */
    DMAC_DMAINT4_S_IRQn         = 104,  /* IRQ No:104,  DMAINT4_S */
    DMAC_DMAINT5_S_IRQn         = 105,  /* IRQ No:105, DMAINT5_S */
    DMAC_DMAINT6_S_IRQn         = 106,  /* IRQ No:106, DMAINT6_S */
    DMAC_DMAINT7_S_IRQn         = 107,  /* IRQ No:107, DMAINT7_S */
    DMAC_DMAINT8_S_IRQn         = 108,  /* IRQ No:108, DMAINT8_S */
    DMAC_DMAINT9_S_IRQn         = 109,  /* IRQ No:109, DMAINT9_S */
    DMAC_DMAINT10_S_IRQn        = 110,  /* IRQ No:110, DMAINT10_S */
    DMAC_DMAINT11_S_IRQn        = 111,  /* IRQ No:111, DMAINT11_S */
    DMAC_DMAINT12_S_IRQn        = 112,  /* IRQ No:112, DMAINT12_S */
    DMAC_DMAINT13_S_IRQn        = 113,  /* IRQ No:113, DMAINT13_S */
    DMAC_DMAINT14_S_IRQn        = 114,  /* IRQ No:114, DMAINT14_S */
    DMAC_DMAINT15_S_IRQn        = 115,  /* IRQ No:115, DMAINT15_S */
    DMAC_DMAERR_NS_IRQn         = 116,  /* IRQ No:116, DMAERR_NS */
    DMAC_DMAINT0_NS_IRQn        = 117,  /* IRQ No:117, DMAINT0_NS */
    DMAC_DMAINT1_NS_IRQn        = 118,  /* IRQ No:118, DMAINT1_NS */
    DMAC_DMAINT2_NS_IRQn        = 119,  /* IRQ No:119, DMAINT2_NS */
    DMAC_DMAINT3_NS_IRQn        = 120,  /* IRQ No:120, DMAINT3_NS */
    DMAC_DMAINT4_NS_IRQn        = 121,  /* IRQ No:121, DMAINT4_NS */
    DMAC_DMAINT5_NS_IRQn        = 122,  /* IRQ No:122, DMAINT5_NS */
    DMAC_DMAINT6_NS_IRQn        = 123,  /* IRQ No:123, DMAINT6_NS */
    DMAC_DMAINT7_NS_IRQn        = 124,  /* IRQ No:124, DMAINT7_NS */
    DMAC_DMAINT8_NS_IRQn        = 125,  /* IRQ No:125, DMAINT8_NS */
    DMAC_DMAINT9_NS_IRQn        = 126,  /* IRQ No:126, DMAINT9_NS */
    DMAC_DMAINT10_NS_IRQn       = 127,  /* IRQ No:127, DMAINT10_NS */
    DMAC_DMAINT11_NS_IRQn       = 128,  /* IRQ No:128, DMAINT11_NS */
    DMAC_DMAINT12_NS_IRQn       = 129,  /* IRQ No:129, DMAINT12_NS */
    DMAC_DMAINT13_NS_IRQn       = 130,  /* IRQ No:130, DMAINT13_NS */
    DMAC_DMAINT14_NS_IRQn       = 131,  /* IRQ No:131, DMAINT14_NS */
    DMAC_DMAINT15_NS_IRQn       = 132,  /* IRQ No:132, DMAINT15_NS */
    DSI_INT_SEQ0_IRQn           = 133,  /* IRQ No: 133, dsi_int_sq0 */
    DSI_INT_SEQ1_IRQn           = 134,  /* IRQ No: 134, dsi_int_sq1 */
    DSI_INT_VIN1_IRQn           = 135,  /* IRQ No: 135, dsi_int_vin1 */
    DSI_INT_RCV_IRQn            = 136,  /* IRQ No: 136, dsi_int_rcv */
    DSI_INT_FERR_IRQn           = 137,  /* IRQ No: 137, dsi_int_ferr */
    DSI_INT_PPI_IRQn            = 138,  /* IRQ No: 138, dsi_int_ppi */
    DSI_INT_DEBUG_IRQn          = 139,  /* IRQ No: 139, dsi_int_debug */
    LCDC0_VSPD_INT_IRQn         = 140,  /* IRQ No: 140, VSPD_INT */
    LCDC0_DU_INT_IRQn           = 141,  /* IRQ No: 141, DU_INT */
    ISU_INT_FRE0_IRQn           = 142,  /* IRQ No: 142, ISU_INT_FRE0 */
    ISU_INT_FRE1_IRQn           = 143,  /* IRQ No: 143, ISU_INT_FRE1 */
    ISU_INT_FRE2_IRQn           = 144,  /* IRQ No: 144, ISU_INT_FRE2 */
    ISU_INT_FRE3_IRQn           = 145,  /* IRQ No: 145, ISU_INT_FRE3 */
    ISU_INT_DESE_IRQn           = 146,  /* IRQ No: 146, ISU_INT_DESE */
    ISU_INT_STOPE_IRQn          = 147,  /* IRQ No: 147, ISU_INT_STOPE */
    ISU_INT_ERR_IRQn            = 148,  /* IRQ No: 148, ISU_INT_ERR */
    CRU0_CSI2_LINK_INT_IRQn     = 149,  /* IRQ No: 149, csi2_link_int */
    CRU0_IMAGE_CONV_INT_IRQn    = 150,  /* IRQ No: 150, image_conv_int */
    CRU0_AXI_MST_ERR_INT_IRQn   = 151,  /* IRQ No: 151, axi_mst_err_int */
    CRU0_CRU_VD_ADDR_WEND_IRQn  = 152,  /* IRQ No: 152, cru_vd_addr_wend */
    CRU0_CRU_SD_ADDR_WEND_IRQn  = 153,  /* IRQ No: 153, cru_sd_addr_wend */
    CRU0_CRU_VSD_ADDR_WEND_IRQn = 154,  /* IRQ No: 154, cru_vsd_addr_wend */

    /*
     * The interrupt factors for GPT and MTU3 are bundled.
     * This block defines the interrupt factor for GPT.
     */
    GPT0_CCMPA_IRQn  = 155,             /* IRQ No:155, CCMPA0 */
    GPT0_CCMPB_IRQn  = 156,             /* IRQ No:156, CCMPB0 */
    GPT0_CMPC_IRQn   = 157,             /* IRQ No:157, CMPC0 */
    GPT0_CMPD_IRQn   = 158,             /* IRQ No:158, CMPD0 */
    GPT0_CMPE_IRQn   = 159,             /* IRQ No:159, CMPE0 */
    GPT0_CMPF_IRQn   = 160,             /* IRQ No:160, CMPF0 */
    GPT0_ADTRGA_IRQn = 161,             /* IRQ No:161, ADTRGA0 */
    GPT0_ADTRGB_IRQn = 162,             /* IRQ No:162, ADTRGB0 */
                                        /* IRQ No:163, Reserved */
                                        /* IRQ No:164, Reserved */
                                        /* IRQ No:165, Reserved */
    GPT0_OVFUNF_IRQn = 166,             /* IRQ No:166, OVFUNF0 */
    GPT1_CCMPA_IRQn  = 167,             /* IRQ No:167, CCMPA1 */
    GPT1_CCMPB_IRQn  = 168,             /* IRQ No:168, CCMPB1 */
    GPT1_CMPC_IRQn   = 169,             /* IRQ No:169, CMPC1 */
    GPT1_CMPD_IRQn   = 170,             /* IRQ No:170, CMPD1 */
    GPT1_CMPE_IRQn   = 171,             /* IRQ No:171, CMPE1 */
    GPT1_CMPF_IRQn   = 172,             /* IRQ No:172, CMPF1 */
    GPT1_ADTRGA_IRQn = 173,             /* IRQ No:173, ADTRGA1 */
    GPT1_ADTRGB_IRQn = 174,             /* IRQ No:174, ADTRGB1 */
                                        /* IRQ No:175, Reserved */
                                        /* IRQ No:176, Reserved */
                                        /* IRQ No:177, Reserved */
    GPT1_OVFUNF_IRQn = 178,             /* IRQ No:178, OVFUNF1 */
    GPT2_CCMPA_IRQn  = 179,             /* IRQ No:179, CCMPA2 */
    GPT2_CCMPB_IRQn  = 180,             /* IRQ No:180, CCMPB2 */
    GPT2_CMPC_IRQn   = 181,             /* IRQ No:181, CMPC2 */
    GPT2_CMPD_IRQn   = 182,             /* IRQ No:182, CMPD2 */
    GPT2_CMPE_IRQn   = 183,             /* IRQ No:183, CMPE2 */
    GPT2_CMPF_IRQn   = 184,             /* IRQ No:184, CMPF2 */
    GPT2_ADTRGA_IRQn = 185,             /* IRQ No:185, ADTRGA2 */
    GPT2_ADTRGB_IRQn = 186,             /* IRQ No:186, ADTRGB2 */
                                        /* IRQ No:187, Reserved */
                                        /* IRQ No:188, Reserved */
                                        /* IRQ No:189, Reserved */
    GPT2_OVFUNF_IRQn = 190,             /* IRQ No:190, OVFUNF2 */
    GPT3_CCMPA_IRQn  = 191,             /* IRQ No:191, CCMPA3 */
    GPT3_CCMPB_IRQn  = 192,             /* IRQ No:192, CCMPB3 */
    GPT3_CMPC_IRQn   = 193,             /* IRQ No:193, CMPC3 */
    GPT3_CMPD_IRQn   = 194,             /* IRQ No:194, CMPD3 */
    GPT3_CMPE_IRQn   = 195,             /* IRQ No:195, CMPE3 */
    GPT3_CMPF_IRQn   = 196,             /* IRQ No:196, CMPF3 */
    GPT3_ADTRGA_IRQn = 197,             /* IRQ No:197, ADTRGA3 */
    GPT3_ADTRGB_IRQn = 198,             /* IRQ No:198, ADTRGB3 */
                                        /* IRQ No:199, Reserved */
                                        /* IRQ No:200, Reserved */
                                        /* IRQ No:201, Reserved */
    GPT3_OVFUNF_IRQn = 202,             /* IRQ No:202, OVFUNF3 */
    GPT4_CCMPA_IRQn  = 203,             /* IRQ No:203, CCMPA4 */
    GPT4_CCMPB_IRQn  = 204,             /* IRQ No:204, CCMPB4 */
    GPT4_CMPC_IRQn   = 205,             /* IRQ No:205, CMPC4 */
    GPT4_CMPD_IRQn   = 206,             /* IRQ No:206, CMPD4 */
    GPT4_CMPE_IRQn   = 207,             /* IRQ No:207, CMPE4 */
    GPT4_CMPF_IRQn   = 208,             /* IRQ No:208, CMPF4 */
    GPT4_ADTRGA_IRQn = 209,             /* IRQ No:209, ADTRGA4 */
    GPT4_ADTRGB_IRQn = 210,             /* IRQ No:210, ADTRGB4 */
                                        /* IRQ No:211, Reserved */
                                        /* IRQ No:212, Reserved */
                                        /* IRQ No:213, Reserved */
    GPT4_OVFUNF_IRQn = 214,             /* IRQ No:214, OVFUNF4 */
    GPT5_CCMPA_IRQn  = 215,             /* IRQ No:215, CCMPA5 */
    GPT5_CCMPB_IRQn  = 216,             /* IRQ No:216, CCMPB5 */
    GPT5_CMPC_IRQn   = 217,             /* IRQ No:217, CMPC5 */
    GPT5_CMPD_IRQn   = 218,             /* IRQ No:218, CMPD5 */
    GPT5_CMPE_IRQn   = 219,             /* IRQ No:219, CMPE5 */
    GPT5_CMPF_IRQn   = 220,             /* IRQ No:220, CMPF5 */
    GPT5_ADTRGA_IRQn = 221,             /* IRQ No:221, ADTRGA5 */
    GPT5_ADTRGB_IRQn = 222,             /* IRQ No:222, ADTRGB5 */
                                        /* IRQ No:223, Reserved */
                                        /* IRQ No:224, Reserved */
                                        /* IRQ No:225, Reserved */
    GPT5_OVFUNF_IRQn = 226,             /* IRQ No:226, OVFUNF5 */
    GPT6_CCMPA_IRQn  = 227,             /* IRQ No:227, CCMPA6 */
    GPT6_CCMPB_IRQn  = 228,             /* IRQ No:228, CCMPB6 */
    GPT6_CMPC_IRQn   = 229,             /* IRQ No:229, CMPC6 */
    GPT6_CMPD_IRQn   = 230,             /* IRQ No:230, CMPD6 */
    GPT6_CMPE_IRQn   = 231,             /* IRQ No:231, CMPE6 */
    GPT6_CMPF_IRQn   = 232,             /* IRQ No:232, CMPF6 */
    GPT6_ADTRGA_IRQn = 233,             /* IRQ No:233, ADTRGA6 */
    GPT6_ADTRGB_IRQn = 234,             /* IRQ No:234, ADTRGB6 */
                                        /* IRQ No:235, Reserved */
                                        /* IRQ No:236, Reserved */
                                        /* IRQ No:237, Reserved */
    GPT6_OVFUNF_IRQn = 238,             /* IRQ No:238, OVFUNF6 */
    GPT7_CCMPA_IRQn  = 239,             /* IRQ No:239, CCMPA7 */
    GPT7_CCMPB_IRQn  = 240,             /* IRQ No:240, CCMPB7 */
    GPT7_CMPC_IRQn   = 241,             /* IRQ No:241, CMPC7 */
    GPT7_CMPD_IRQn   = 242,             /* IRQ No:242, CMPD7 */
    GPT7_CMPE_IRQn   = 243,             /* IRQ No:243, CMPE7 */
    GPT7_CMPF_IRQn   = 244,             /* IRQ No:244, CMPF7 */
    GPT7_ADTRGA_IRQn = 245,             /* IRQ No:245, ADTRGA7 */
    GPT7_ADTRGB_IRQn = 246,             /* IRQ No:246, ADTRGB7 */
                                        /* IRQ No:247, Reserved */
                                        /* IRQ No:248, Reserved */
                                        /* IRQ No:249, Reserved */
    GPT7_OVFUNF_IRQn = 250,             /* IRQ No:250, OVFUNF7 */

    /*
     * The interrupt factors for GPT and MTU3 are bundled.
     * This block defines the interrupt factor for MTU3.
     */
    MTU0_TGIA_PLS_IRQn = 159,           /* IRQ No:159, TGIA0 */
    MTU0_TGIB_PLS_IRQn = 160,           /* IRQ No:160, TGIB0 */
    MTU0_TGIC_PLS_IRQn = 161,           /* IRQ No:161, TGIC0 */
    MTU0_TGID_PLS_IRQn = 162,           /* IRQ No:162, TGID0 */
    MTU0_TCIV_PLS_IRQn = 163,           /* IRQ No:163, TCIV0 */
    MTU0_TGIE_PLS_IRQn = 164,           /* IRQ No:164, TGIE0 */
    MTU0_TGIF_PLS_IRQn = 171,           /* IRQ No:171, TGIF0 */
    MTU1_TGIA_PLS_IRQn = 172,           /* IRQ No:172, TGIA1 */
    MTU1_TGIB_PLS_IRQn = 173,           /* IRQ No:173, TGIB1 */
    MTU1_TCIV_PLS_IRQn = 174,           /* IRQ No:174, TCIV1 */
    MTU1_TCIU_PLS_IRQn = 175,           /* IRQ No:175, TCIU1 */
    MTU2_TGIA_PLS_IRQn = 176,           /* IRQ No:176, TGIA2 */
    MTU2_TGIB_PLS_IRQn = 183,           /* IRQ No:183, TGIB2 */
    MTU2_TCIV_PLS_IRQn = 184,           /* IRQ No:184, TCIV2 */
    MTU2_TCIU_PLS_IRQn = 185,           /* IRQ No:185, TCIU2 */
    MTU3_TGIA_PLS_IRQn = 186,           /* IRQ No:186, TGIA3 */
    MTU3_TGIB_PLS_IRQn = 187,           /* IRQ No:187, TGIB3 */
    MTU3_TGIC_PLS_IRQn = 188,           /* IRQ No:188, TGIC3 */
    MTU3_TGID_PLS_IRQn = 195,           /* IRQ No:195, TGID3 */
    MTU3_TCIV_PLS_IRQn = 196,           /* IRQ No:196, TCIV3 */
    MTU4_TGIA_PLS_IRQn = 197,           /* IRQ No:197, TGIA4 */
    MTU4_TGIB_PLS_IRQn = 198,           /* IRQ No:198, TGIB4 */
    MTU4_TGIC_PLS_IRQn = 199,           /* IRQ No:199, TGIC4 */
    MTU4_TGID_PLS_IRQn = 200,           /* IRQ No:200, TGID4 */
    MTU4_TCIV_PLS_IRQn = 207,           /* IRQ No:207, TCIV4 */
    MTU5_TGIU_PLS_IRQn = 208,           /* IRQ No:208, TGIU5 */
    MTU5_TGIV_PLS_IRQn = 209,           /* IRQ No:209, TGIV5 */
    MTU5_TGIW_PLS_IRQn = 210,           /* IRQ No:210, TGIW5 */
    MTU6_TGIA_PLS_IRQn = 211,           /* IRQ No:211, TGIA6 */
    MTU6_TGIB_PLS_IRQn = 212,           /* IRQ No:212, TGIB6 */
    MTU6_TGIC_PLS_IRQn = 219,           /* IRQ No:219, TGIC6 */
    MTU6_TGID_PLS_IRQn = 220,           /* IRQ No:220, TGID6 */
    MTU6_TCIV_PLS_IRQn = 221,           /* IRQ No:221, TCIV6 */
    MTU7_TGIA_PLS_IRQn = 222,           /* IRQ No:222, TGIA7 */
    MTU7_TGIB_PLS_IRQn = 223,           /* IRQ No:223, TGIB7 */
    MTU7_TGIC_PLS_IRQn = 224,           /* IRQ No:224, TGIC7 */
    MTU7_TGID_PLS_IRQn = 231,           /* IRQ No:231, TGID7 */
    MTU7_TCIV_PLS_IRQn = 232,           /* IRQ No:232, TCIV7 */
    MTU8_TGIA_PLS_IRQn = 233,           /* IRQ No:233, TGIA8 */
    MTU8_TGIB_PLS_IRQn = 234,           /* IRQ No:234, TGIB8 */
    MTU8_TGIC_PLS_IRQn = 235,           /* IRQ No:235, TGIC8 */
    MTU8_TGID_PLS_IRQn = 236,           /* IRQ No:236, TGID8 */
    MTU8_TCIV_PLS_IRQn = 243,           /* IRQ No:243, TCIV8 */
                                        /* IRQ No:244, Reserved */

    POE3_OEI1_IRQn    = 251,            /* IRQ No:251, OEI1 */
    POE3_OEI2_IRQn    = 252,            /* IRQ No:252, OEI2 */
    POE3_OEI3_IRQn    = 253,            /* IRQ No:253, OEI3 */
    POE3_OEI4_IRQn    = 254,            /* IRQ No:254, OEI4 */
    POEG_GROUP0_IRQn  = 255,            /* IRQ No:255, POEGA_GROUP0 */
    POEG_GROUP1_IRQn  = 256,            /* IRQ No:256, POEGB_GROUP1 */
    POEG_GROUP2_IRQn  = 257,            /* IRQ No:257, POEGC_GROUP2 */
    POEG_GROUP3_IRQn  = 258,            /* IRQ No:258, POEGD_GROUP3 */
    I2S0_INT_REQ_IRQn = 259,            /* IRQ No:259, INT_ssif_int_req_0 */
    I2S0_DMA_RX_IRQn  = 260,            /* IRQ No:260, INT_ssif_dma_rx_0 */
    I2S0_DMA_TX_IRQn  = 261,            /* IRQ No:261, INT_ssif_dma_tx_0 */
    I2S1_INT_REQ_IRQn = 262,            /* IRQ No:262, INT_ssif_int_req_1 */
    I2S1_DMA_RX_IRQn  = 263,            /* IRQ No:263, INT_ssif_dma_rx_1 */
    I2S1_DMA_TX_IRQn  = 264,            /* IRQ No:264, INT_ssif_dma_tx_1 */
    I2S2_INT_REQ_IRQn = 265,            /* IRQ No:265, INT_ssif_int_req_2 */
    I2S2_DMA_RX_IRQn  = 266,            /* IRQ No:266, INT_ssif_dma_rx_1 */
    I2S2_DMA_TX_IRQn  = 267,            /* IRQ No:267, INT_ssif_dma_tx_1 */
    I2S3_INT_REQ_IRQn = 268,            /* IRQ No:268, INT_ssif_int_req_3 */
    I2S3_DMA_RX_IRQn  = 269,            /* IRQ No:269, INT_ssif_dma_rx_3 */
    I2S3_DMA_TX_IRQn  = 270,            /* IRQ No:270, INT_ssif_dma_tx_3 */
                                        /* IRQ No:271, Reserved */
                                        /* IRQ No:272, Reserved */
                                        /* IRQ No:273, Reserved */
                                        /* IRQ No:274, Reserved */
                                        /* IRQ No:275, Reserved */
    RIIC0_TEI_IRQn             = 276,   /* IRQ No:276, INTRIICTEI0 */
    RIIC0_NAKI_IRQn            = 277,   /* IRQ No:277, INTRIICNAKI0 */
    RIIC0_SPI_IRQn             = 278,   /* IRQ No:278, INTRIICSPI0 */
    RIIC0_STI_IRQn             = 279,   /* IRQ No:279, INTRIICSTI0 */
    RIIC0_ALI_IRQn             = 280,   /* IRQ No:280, INTRIICALI0 */
    RIIC0_TMOI_IRQn            = 281,   /* IRQ No:281, INTRIICTMOI0 */
    RIIC0_RI_IRQn              = 282,   /* IRQ No:282, INTRIICRI0 */
    RIIC0_TI_IRQn              = 283,   /* IRQ No:283, INTRIICTI0 */
    RIIC1_TEI_IRQn             = 284,   /* IRQ No:284, INTRIICTEI0 */
    RIIC1_NAKI_IRQn            = 285,   /* IRQ No:285, INTRIICNAKI0 */
    RIIC1_SPI_IRQn             = 286,   /* IRQ No:286, INTRIICSPI0 */
    RIIC1_STI_IRQn             = 287,   /* IRQ No:287, INTRIICSTI0 */
    RIIC1_ALI_IRQn             = 288,   /* IRQ No:288, INTRIICALI0 */
    RIIC1_TMOI_IRQn            = 289,   /* IRQ No:289, INTRIICTMOI0 */
    RIIC1_RI_IRQn              = 290,   /* IRQ No:290, INTRIICRI0 */
    RIIC1_TI_IRQn              = 291,   /* IRQ No:291, INTRIICTI0 */
    RIIC2_TEI_IRQn             = 292,   /* IRQ No:292, INTRIICTEI0 */
    RIIC2_NAKI_IRQn            = 293,   /* IRQ No:293, INTRIICNAKI0 */
    RIIC2_SPI_IRQn             = 294,   /* IRQ No:294, INTRIICSPI0 */
    RIIC2_STI_IRQn             = 295,   /* IRQ No:295, INTRIICSTI0 */
    RIIC2_ALI_IRQn             = 296,   /* IRQ No:296, INTRIICALI0 */
    RIIC2_TMOI_IRQn            = 297,   /* IRQ No:297, INTRIICTMOI0 */
    RIIC2_RI_IRQn              = 298,   /* IRQ No:298, INTRIICRI0 */
    RIIC2_TI_IRQn              = 299,   /* IRQ No:299, INTRIICTI0 */
    RIIC3_TEI_IRQn             = 300,   /* IRQ No:300, INTRIICTEI0 */
    RIIC3_NAKI_IRQn            = 301,   /* IRQ No:301, INTRIICNAKI0 */
    RIIC3_SPI_IRQn             = 302,   /* IRQ No:302, INTRIICSPI0 */
    RIIC3_STI_IRQn             = 303,   /* IRQ No:303, INTRIICSTI0 */
    RIIC3_ALI_IRQn             = 304,   /* IRQ No:304, INTRIICALI0 */
    RIIC3_TMOI_IRQn            = 305,   /* IRQ No:305, INTRIICTMOI0 */
    RIIC3_RI_IRQn              = 306,   /* IRQ No:306, INTRIICRI0 */
    RIIC3_TI_IRQn              = 307,   /* IRQ No:307, INTRIICTI0 */
    I3C_B_INT_RI3C_IERR_N_IRQn = 308,   /* IRQ No:308, INT_ri3c_ierr_n */
    I3C_B_INT_RI3C_TERR_N_IRQn = 309,   /* IRQ No:309, INT_ri3c_terr_n */
                                        /* IRQ No:310, Reserved */
                                        /* IRQ No:311, Reserved */
    I3C_B_INT_RI3C_ABORT_N_IRQn = 312,  /* IRQ No:312, INT_ri3c_abort_n */
    I3C_B_INT_RI3C_RESP_N_IRQn  = 313,  /* IRQ No:313, INT_ri3c_resp_n */
    I3C_B_INT_RI3C_CMD_N_IRQn   = 314,  /* IRQ No:314, INT_ri3c_cmd_n */
    I3C_B_INT_RI3C_IBI_N_IRQn   = 315,  /* IRQ No:315, INT_ri3c_ibi_n */
    I3C_B_INT_RI3C_RX_N_IRQn    = 316,  /* IRQ No:316, INT_ri3c_rx_n */
    I3C_B_INT_RI3C_TX_N_IRQn    = 317,  /* IRQ No:317, INT_ri3c_tx_n */
    I3C_B_INT_RI3C_RCV_N_IRQn   = 318,  /* IRQ No:318, INT_ri3c_rcv_n */
                                        /* IRQ No:319, Reserved */
                                        /* IRQ No:320, Reserved */
                                        /* IRQ No:321, Reserved */
                                        /* IRQ No:322, Reserved */
    I3C_B_INT_RI3C_ST_N_IRQn = 323,     /* IRQ No:323, INT_ri3c_st_n */
    I3C_B_INT_RI3C_SP_N_IRQn = 324,     /* IRQ No:324, INT_ri3c_sp_n */
                                        /* IRQ No:325, Reserved */
    I3C_B_INT_RI3C_TEND_N_IRQn = 326,   /* IRQ No:326, INT_ri3c_tend_n */
    I3C_B_INT_RI3C_NACK_N_IRQn = 327,   /* IRQ No:327, INT_ri3c_nack_n */
    I3C_B_INT_RI3C_AL_N_IRQn   = 328,   /* IRQ No:328, INT_ri3c_al_n */
    I3C_B_INT_RI3C_TMO_N_IRQn  = 329,   /* IRQ No:329, INT_ri3c_tmo_n */
    I3C_B_INT_RI3C_WU_N_IRQn   = 330,   /* IRQ No:330, INT_ri3c_wu_n */
    ADC0_INTAD_IRQn            = 331,   /* IRQ No:331, ADC0_INTAD */
    ADC1_INTAD_IRQn            = 332,   /* IRQ No:332, ADC1_INTAD */
                                        /* IRQ No:333, Reserved */
                                        /* IRQ No:334, Reserved */
    RTC_INTREQ_RTC_ALMPLS_N_IRQn = 335, /* IRQ No:335, INT_intreq_rtc_alm_n */
    RTC_INTREQ_RTC_CUPPLS_N_IRQn = 336, /* IRQ No:336, INT_intreq_rtc_cup_n */
    RTC_INTREQ_RTC_PRDPLS_N_IRQn = 337, /* IRQ No:337, INT_intreq_rtc_prd_n */
    /* IRQ No:338, Reserved */
    /* IRQ No:339, Reserved */
    SCIF0_RERR_IRQn         = 340,      /* IRQ No:340, ERI0 */
    SCIF0_BRK_IRQn          = 341,      /* IRQ No:341, BRI0 */
    SCIF0_RXI_IRQn          = 342,      /* IRQ No:342, RXI0 */
    SCIF0_TXI_IRQn          = 343,      /* IRQ No:343, TXI0 */
    SCIF0_TEI_DRI_IRQn      = 344,      /* IRQ No:344, TEI0_DRI0 */
    SCIF1_RERR_IRQn         = 345,      /* IRQ No:345, ERI1 */
    SCIF1_BRK_IRQn          = 346,      /* IRQ No:346, BRI1 */
    SCIF1_RXI_IRQn          = 347,      /* IRQ No:347, RXI1 */
    SCIF1_TXI_IRQn          = 348,      /* IRQ No:348, TXI1 */
    SCIF1_TEI_DRI_IRQn      = 349,      /* IRQ No:349, TEI1_DRI1 */
    SCIF2_RERR_IRQn         = 350,      /* IRQ No:350, ERI2 */
    SCIF2_BRK_IRQn          = 351,      /* IRQ No:351, BRI2 */
    SCIF2_RXI_IRQn          = 352,      /* IRQ No:352, RXI2 */
    SCIF2_TXI_IRQn          = 353,      /* IRQ No:353, TXI2 */
    SCIF2_TEI_DRI_IRQn      = 354,      /* IRQ No:354, TEI2_DRI2 */
    SCIF3_RERR_IRQn         = 355,      /* IRQ No:355, ERI3 */
    SCIF3_BRK_IRQn          = 356,      /* IRQ No:356, BRI3 */
    SCIF3_RXI_IRQn          = 357,      /* IRQ No:357, RXI3 */
    SCIF3_TXI_IRQn          = 358,      /* IRQ No:358, TXI3 */
    SCIF3_TEI_DRI_IRQn      = 359,      /* IRQ No:359, TEI3_DRI3 */
    SCIF4_RERR_IRQn         = 360,      /* IRQ No:360, ERI4 */
    SCIF4_BRK_IRQn          = 361,      /* IRQ No:361, BRI4 */
    SCIF4_RXI_IRQn          = 362,      /* IRQ No:362, RXI4 */
    SCIF4_TXI_IRQn          = 363,      /* IRQ No:363, TXI4 */
    SCIF4_TEI_DRI_IRQn      = 364,      /* IRQ No:364, TEI4_DRI4 */
    SCIF5_RERR_IRQn         = 365,      /* IRQ No:365, ERI5 */
    SCIF5_BRK_IRQn          = 366,      /* IRQ No:366, BRI5 */
    SCIF5_RXI_IRQn          = 367,      /* IRQ No:367, RXI5 */
    SCIF5_TXI_IRQn          = 368,      /* IRQ No:368, TXI5 */
    SCIF5_TEI_DRI_IRQn      = 369,      /* IRQ No:369, TEI5_DRI5 */
    SCI0_ERI_IRQn           = 370,      /* IRQ No:370, ERI0 */
    SCI0_RXI_IRQn           = 371,      /* IRQ No:371, RXI0 */
    SCI0_TXI_IRQn           = 372,      /* IRQ No:372, TXI0 */
    SCI0_TEI_IRQn           = 373,      /* IRQ No:373, TEI0 */
    SCI0_AED_IRQn           = 374,      /* IRQ No:374, AED0 */
    SCI0_BFD_IRQn           = 375,      /* IRQ No:375, BFD0 */
    SCI1_ERI_IRQn           = 376,      /* IRQ No:376, ERI1 */
    SCI1_RXI_IRQn           = 377,      /* IRQ No:377, RXI1 */
    SCI1_TXI_IRQn           = 378,      /* IRQ No:378, TXI1 */
    SCI1_TEI_IRQn           = 379,      /* IRQ No:379, TEI1 */
    SCI1_AED_IRQn           = 380,      /* IRQ No:380, AED1 */
    SCI1_BFD_IRQn           = 381,      /* IRQ No:381, BFD1 */
    SCI2_ERI_IRQn           = 382,      /* IRQ No:382, ERI2 */
    SCI2_RXI_IRQn           = 383,      /* IRQ No:383, RXI2 */
    SCI2_TXI_IRQn           = 384,      /* IRQ No:384, TXI2 */
    SCI2_TEI_IRQn           = 385,      /* IRQ No:385, TEI2 */
    SCI2_AED_IRQn           = 386,      /* IRQ No:386, AED2 */
    SCI2_BFD_IRQn           = 387,      /* IRQ No:387, BFD2 */
    SCI3_ERI_IRQn           = 388,      /* IRQ No:388, ERI3 */
    SCI3_RXI_IRQn           = 389,      /* IRQ No:389, RXI3 */
    SCI3_TXI_IRQn           = 390,      /* IRQ No:390, TXI3 */
    SCI3_TEI_IRQn           = 391,      /* IRQ No:391, TEI3 */
    SCI3_AED_IRQn           = 392,      /* IRQ No:392, AED3 */
    SCI3_BFD_IRQn           = 393,      /* IRQ No:393, BFD3 */
    SPI0_IDLE_IRQn          = 394,      /* IRQ No:394, SPII0 */
    SPI0_ERI_IRQn           = 395,      /* IRQ No:395, SPEI0 */
    SPI0_CE_IRQn            = 396,      /* IRQ No:396, SPCEND0 */
    SPI0_RXI_IRQn           = 397,      /* IRQ No:397, SPRI0 */
    SPI0_TXI_IRQn           = 398,      /* IRQ No:398, SPTI0 */
    SPI1_IDLE_IRQn          = 399,      /* IRQ No:399, SPII1 */
    SPI1_ERI_IRQn           = 400,      /* IRQ No:400, SPEI1 */
    SPI1_CE_IRQn            = 401,      /* IRQ No:401, SPCEND1 */
    SPI1_RXI_IRQn           = 402,      /* IRQ No:402, SPRI1 */
    SPI1_TXI_IRQn           = 403,      /* IRQ No:403, SPTI1 */
    SPI2_IDLE_IRQn          = 404,      /* IRQ No:404, SPII2 */
    SPI2_ERI_IRQn           = 405,      /* IRQ No:405, SPEI2 */
    SPI2_CE_IRQn            = 406,      /* IRQ No:406, SPCEND2 */
    SPI2_RXI_IRQn           = 407,      /* IRQ No:407, SPRI2 */
    SPI2_TXI_IRQn           = 408,      /* IRQ No:408, SPTI2 */
    CANFD_INTRCANGERR_IRQn  = 409,      /* IRQ No:409, INTRCANGERR */
    CANFD_INTRCANGRECC_IRQn = 410,      /* IRQ No:410, INTRCANGRECC */
    CANFD_INTRCAN0ERR_IRQn  = 411,      /* IRQ No:411, INTRCAN0ERR */
    CANFD_INTRCAN0REC_IRQn  = 412,      /* IRQ No:412, INTRCAN0REC */
    CANFD_INTRCAN0TRX_IRQn  = 413,      /* IRQ No:413, INTRCAN0TRX */
                                        /* IRQ No:414, Reserved */
                                        /* IRQ No:415, Reserved */
                                        /* IRQ No:416, Reserved */
    CANFD_INTRCAN1ERR_IRQn = 417,       /* IRQ No:417, INTRCAN1ERR */
    CANFD_INTRCAN1REC_IRQn = 418,       /* IRQ No:418, INTRCAN1REC */
    CANFD_INTRCAN1TRX_IRQn = 419,       /* IRQ No:419, INTRCAN1TRX */
                                        /* IRQ No:420, Reserved */
                                        /* IRQ No:421, Reserved */
                                        /* IRQ No:422, Reserved */
    CANFD_INTRCAN2ERR_IRQn = 423,       /* IRQ No:423, INTRCAN2ERR */
    CANFD_INTRCAN2REC_IRQn = 424,       /* IRQ No:424, INTRCAN2REC */
    CANFD_INTRCAN2TRX_IRQn = 425,       /* IRQ No:425, INTRCAN2TRX */
                                        /* IRQ No:426, Reserved */
                                        /* IRQ No:427, Reserved */
                                        /* IRQ No:428, Reserved */
    SPDIF_SPDIF_IRQn     = 429,         /* IRQ No:429, intreq_spdif */
    PDM0_ERR0_IRQn       = 430,         /* IRQ No:430, INT_PDM_ERR0 */
    PDM0_ERR1_IRQn       = 431,         /* IRQ No:431, INT_PDM_ERR1 */
    PDM0_ERR2_IRQn       = 432,         /* IRQ No:432, INT_PDM_ERR2 */
    PDM0_DAT0_IRQn       = 433,         /* IRQ No:433, INT_PDM_DAT0 */
    PDM0_DAT1_IRQn       = 434,         /* IRQ No:434, INT_PDM_DAT1 */
    PDM0_DAT2_IRQn       = 435,         /* IRQ No:435, INT_PDM_DAT2 */
    PDM0_SDET_IRQn       = 436,         /* IRQ No:436, INT_PDM_SDET */
    PCIE_INT_ALL_IRQn    = 437,         /* IRQ No:437, INT_ALL */
    EBSC_INTREQ_WTO_IRQn = 438,         /* IRQ No:438, intreq_wto */
                                        /* IRQ No:439, Reserved */
                                        /* IRQ No:440, Reserved */
                                        /* IRQ No:441, Reserved */
                                        /* IRQ No:442, Reserved */
                                        /* IRQ No:443, Reserved */
    GPIO_TINT0_IRQn  = 444,             /* IRQ No:444, TINT0 */
    GPIO_TINT1_IRQn  = 445,             /* IRQ No:445, TINT1 */
    GPIO_TINT2_IRQn  = 446,             /* IRQ No:446, TINT2 */
    GPIO_TINT3_IRQn  = 447,             /* IRQ No:447, TINT3 */
    GPIO_TINT4_IRQn  = 448,             /* IRQ No:448, TINT4 */
    GPIO_TINT5_IRQn  = 449,             /* IRQ No:449, TINT5 */
    GPIO_TINT6_IRQn  = 450,             /* IRQ No:450, TINT6 */
    GPIO_TINT7_IRQn  = 451,             /* IRQ No:451, TINT7 */
    GPIO_TINT8_IRQn  = 452,             /* IRQ No:452, TINT8 */
    GPIO_TINT9_IRQn  = 453,             /* IRQ No:453, TINT9 */
    GPIO_TINT10_IRQn = 454,             /* IRQ No:454, TINT10 */
    GPIO_TINT11_IRQn = 455,             /* IRQ No:455, TINT11 */
    GPIO_TINT12_IRQn = 456,             /* IRQ No:456, TINT12 */
    GPIO_TINT13_IRQn = 457,             /* IRQ No:457, TINT13 */
    GPIO_TINT14_IRQn = 458,             /* IRQ No:458, TINT14 */
    GPIO_TINT15_IRQn = 459,             /* IRQ No:459, TINT15 */
    GPIO_TINT16_IRQn = 460,             /* IRQ No:460, TINT16 */
    GPIO_TINT17_IRQn = 461,             /* IRQ No:461, TINT17 */
    GPIO_TINT18_IRQn = 462,             /* IRQ No:462, TINT18 */
    GPIO_TINT19_IRQn = 463,             /* IRQ No:463, TINT19 */
    GPIO_TINT20_IRQn = 464,             /* IRQ No:464, TINT20 */
    GPIO_TINT21_IRQn = 465,             /* IRQ No:465, TINT21 */
    GPIO_TINT22_IRQn = 466,             /* IRQ No:466, TINT22 */
    GPIO_TINT23_IRQn = 467,             /* IRQ No:467, TINT23 */

    /*
     * The interrupt factors for INTC_IRQ and INTC_TINT are bundled.
     * This block defines the interrupt factor for INTC_TINT (24->31).
     */
    GPIO_TINT24_IRQn = 468,             /* IRQ No:468, TINT24 */
    GPIO_TINT25_IRQn = 469,             /* IRQ No:469, TINT25 */
    GPIO_TINT26_IRQn = 470,             /* IRQ No:470, TINT26 */
    GPIO_TINT27_IRQn = 471,             /* IRQ No:471, TINT27 */
    GPIO_TINT28_IRQn = 472,             /* IRQ No:472, TINT28 */
    GPIO_TINT29_IRQn = 473,             /* IRQ No:473, TINT29 */
    GPIO_TINT30_IRQn = 474,             /* IRQ No:474, TINT30 */
    GPIO_TINT31_IRQn = 475,             /* IRQ No:465, TINT31 */

    /*
     * The interrupt factors for INTC_IRQ and INTC_TINT are bundled.
     * This block defines the interrupt factor for INTC_IRQ (8->15).
     */
    GPIO_IRQ8_IRQn  = 468,              /* IRQ No:468, IRQ8 */
    GPIO_IRQ9_IRQn  = 469,              /* IRQ No:469, IRQ9 */
    GPIO_IRQ10_IRQn = 470,              /* IRQ No:470, IRQ10 */
    GPIO_IRQ11_IRQn = 471,              /* IRQ No:471, IRQ11 */
    GPIO_IRQ12_IRQn = 472,              /* IRQ No:472, IRQ12 */
    GPIO_IRQ13_IRQn = 473,              /* IRQ No:473, IRQ13 */
    GPIO_IRQ14_IRQn = 474,              /* IRQ No:474, IRQ14 */
    GPIO_IRQ15_IRQn = 475,              /* IRQ No:475, IRQ15 */

    /* IRQ No:476, Reserved */
    /* IRQ No:477, Reserved */
    /* IRQ No:478, Reserved */
    /* IRQ No:479, Reserved */
} IRQn_Type;

/** @} (end addtogroup RZG_BSP_MPU_RZG3L) */

 #ifdef __FOR_FSP_DOCUMENT__
  #ifdef __cplusplus
}
  #endif
 #endif

#endif                                 /* BSP_IRQ_ID_H */
