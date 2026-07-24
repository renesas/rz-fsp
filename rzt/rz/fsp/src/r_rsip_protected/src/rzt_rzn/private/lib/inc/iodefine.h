/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef IODEFINE_H
#define IODEFINE_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include "bsp_api.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/* Module Base Addresses from RZT2_register_list_20200910.xlsx */
#define xSPI0_BASE               (0x80220000UL)
#define xSPI1_BASE               (0x80221000UL)
#define SYSTEM_BASE              (0x80280000UL)
#define OTP_BASE                 (0x81028000UL)
#define OTP_END                  (0x8102BFFFUL)
#define SYSTEM_SAFETY_BASE       (0x81280000UL)
#define PORT_SAFETY_BASE         (0x81030000UL)
#define BSC_BASE                 (0x80210000UL)
#define SCI0_BASE                (0x80001000UL)
#define OCDREG_BASE              (0xC0080000UL)
#define SBAREG_BASE              (0xC0090000UL)

#define SCKCR_OFFSET             (0x0000UL)
#define MD_MON_OFFSET            (0x1100UL)
#define BROM_DISABLE_OFFSET      (0x1300UL)
#define PRCRN_OFFSET             (0x1A10UL)
#define VECADDR_OFFSET           (0x1900UL)
#define PRCRS_OFFSET             (0x1A00UL)
#define SWRCPU0_OFFSET           (0x0220UL)
#define SWRCPU1_OFFSET           (0x0230UL)
#define MRCTLA_OFFSET            (0x0240UL)
#define MRCTL4_OFFSET            (0x0290UL)
#define MSTPCRA_OFFSET           (0x0300UL)
#define MSTPCR0_OFFSET           (0x0340UL)

#define VECADDR                  (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + VECADDR_OFFSET))
#define SWRCPU0                  (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + SWRCPU0_OFFSET))
#define SWRCPU1                  (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + SWRCPU1_OFFSET))

#define CPU_RESET                (0x4321A501UL)

#define PRCRS                    (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + PRCRS_OFFSET))

#define SCKCR                    (*(volatile uint32_t *) (SYSTEM_BASE + SCKCR_OFFSET))
#define MD_MON                   (*(volatile uint32_t *) (SYSTEM_BASE + MD_MON_OFFSET))
#define BROM_DISABLE             (*(volatile uint32_t *) (SYSTEM_BASE + BROM_DISABLE_OFFSET))
#define PRCRN                    (*(volatile uint32_t *) (SYSTEM_BASE + PRCRN_OFFSET))

/* Operation Mode Monitor (MD_MON) register bits */

/* JTAG hash authentication enable/disable */
#define MD_MON_MDDMON_BIT        (0U)
#define MD_MON_MDDMON_MSK        (1U)

/* Package Type */
#define MD_MON_MDP0_BIT          (8U)
#define MD_MON_MDPx_MSK          (3U)                   /* 2bits wide - MDP0 and MDP1*/
/* Boot Mode */
#define MD_MON_MD0MON_BIT        (12U)
#define MD_MON_MDxMON_MSK        (7U)                   /* 3 bits wide - MD0MON, MD1MON and MD2MON */

#define MD_MON_MDV3MON           (19U)
#define MD_MON_MDV3MON_MSK       (1U << MD_MON_MDV3MON) /* 1 bit wide - MDV3MON */

#define MD_MON_MDV4MON           (20U)
#define MD_MON_MDV4MON_MSK       (1U << MD_MON_MDV4MON) /* 1 bit wide - MDV4MON */

/* Vector Address (VECADDR) register bits */
#define VECADDR_ATCM             (0x00000002U)

/* Reset Control Registers */
#define MRCTLA                   (*(volatile uint32_t *) (SYSTEM_BASE + MRCTLA_OFFSET))
#define MRCTL4                   (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + MRCTL4_OFFSET))

/* Module stop registers */
#define MSTPCRA                  (*(volatile uint32_t *) (SYSTEM_BASE + MSTPCRA_OFFSET))
#define MSTPCR0                  (*(volatile uint32_t *) (SYSTEM_SAFETY_BASE + MSTPCR0_OFFSET))

/* Module Stop Control Register A (MSTPCRA) register bits */

#define MSTPCRA_MSTPCRA00        (0U)
#define MSTPCRA_MSTPCRA00_MSK    (0x00000001U << MSTPCRA_MSTPCRA00)

#define MSTPCRA_MSTPCRA04        (4U)
#define MSTPCRA_MSTPCRA04_MSK    (0x00000001U << MSTPCRA_MSTPCRA04)

#define MSTPCRA_MSTPCRA05        (5U)
#define MSTPCRA_MSTPCRA05_MSK    (0x00000001U << MSTPCRA_MSTPCRA05)

#define MSTPCRA_MSTPCRA08        (8U)
#define MSTPCRA_MSTPCRA08_MSK    (0x00000001U << MSTPCRA_MSTPCRA08)

#define MSTPCRA_MSTPCRA09        (9U)
#define MSTPCRA_MSTPCRA09_MSK    (0x00000001U << MSTPCRA_MSTPCRA09)

#define MSTPCRA_MSTPCRA10        (10U)
#define MSTPCRA_MSTPCRA10_MSK    (0x00000001U << MSTPCRA_MSTPCRA10)

#define MSTPCRA_MSTPCRA11        (11U)
#define MSTPCRA_MSTPCRA11_MSK    (0x00000001U << MSTPCRA_MSTPCRA11)

#define MSTPCRA_MSTPCRA12        (12U)
#define MSTPCRA_MSTPCRA12_MSK    (0x00000001U << MSTPCRA_MSTPCRA12)

/* Port Control Registers used for pin setting.  These registers are
 * accessible via safety or non-safety region.  The Boot ROM only
 * accesses then via the safety region. */
#define PORT_PMC(n)         (*(volatile uint8_t *) (PORT_SAFETY_BASE + 0x0400UL + (n)))
#define PORT_PFC(n)         (*(volatile uint32_t *) (PORT_SAFETY_BASE + 0x0600UL + (4UL * (((uint32_t) n)))))
#define PORT_DRCTL_LO(n)    (*(volatile uint32_t *) (PORT_SAFETY_BASE + 0x0A00UL + (8UL * (((uint32_t) n)))))
#define PORT_DRCTL_HI(n)    (*(volatile uint32_t *) (PORT_SAFETY_BASE + 0x0A04UL + (8UL * (((uint32_t) n)))))
#define PORT_DRCTL_PIN_REG_HI      (4U) /* Pin where PORT_DRCTL_HI() needs to be started to be used  instead of PORT_DRCTL_LO() */
/* Pin current drive control */
#define DRCTL_Em0                  (0U)
#define DRCTL_Em0_MSK              (0x3U << DRCTL_Em0)
#define DRCTL_Em0_DRIVE_LO_MSK     (0x0U << DRCTL_Em0)
#define DRCTL_Em0_DRIVE_MI_MSK     (0x1U << DRCTL_Em0)
#define DRCTL_Em0_DRIVE_HI_MSK     (0x2U << DRCTL_Em0)
#define DRCTL_Em0_DRIVE_UHI_MSK    (0x3U << DRCTL_Em0)

/* Pin Schmitt control */
#define DRCTL_SMTm0                (4U)
#define DRCTL_SMTm0_MSK            (0x1U << DRCTL_SMTm0)

/* Pin Slew Rate control */
#define DRCTL_SRm0                 (5U)
#define DRCTL_SRm0_MSK             (0x1U << DRCTL_SRm0)

/*********************** Bus State Controller Registers ***********************/

#define CS0BCR                     (*(volatile uint32_t *) (BSC_BASE + 0x0004UL))
#define CS0WCR_0                   (*(volatile uint32_t *) (BSC_BASE + 0x0028UL))

/* Bits in CSNBCR register */
#define CSNBCR_BSZ                 (9U)
#define CSNBCR_BSZ_MSK             (0x00000003U << CSNBCR_BSZ)
#define CSNBCR_BSZ_8BIT            (0x00000001U << CSNBCR_BSZ)
#define CSNBCR_BSZ_16BIT           (0x00000002U << CSNBCR_BSZ)
#define CSNBCR_BSZ_32BIT           (0x00000003U << CSNBCR_BSZ)

#define CSNBCR_TYPE                (12U)
#define CSNBCR_TYPE_MSK            (0x00000007U << CSNBCR_TYPE)
#define CSNBCR_TYPE_NORMAL         (0x00000000U << CSNBCR_TYPE)
#define CSNBCR_TYPE_BURST_ROM_A    (0x00000001U << CSNBCR_TYPE)
#define CSNBCR_TYPE_MPX_IO         (0x00000002U << CSNBCR_TYPE)
#define CSNBCR_TYPE_SRAM           (0x00000003U << CSNBCR_TYPE)
#define CSNBCR_TYPE_SDRAM          (0x00000004U << CSNBCR_TYPE)
#define CSNBCR_TYPE_BURST_ROM_S    (0x00000007U << CSNBCR_TYPE)

#define CSNBCR_IWRRS               (16U)
#define CSNBCR_IWRRS_MSK           (0x00000007U << CSNBCR_IWRRS)
#define CSNBCR_IWRRD               (19U)
#define CSNBCR_IWRRD_MSK           (0x00000007U << CSNBCR_IWRRD)
#define CSNBCR_IWRWS               (22U)
#define CSNBCR_IWRWS_MSK           (0x00000007U << CSNBCR_IWRWS)
#define CSNBCR_IWRWD               (25U)
#define CSNBCR_IWRWD_MSK           (0x00000007U << CSNBCR_IWRWD)
#define CSNBCR_IWWW                (28U)
#define CSNBCR_IWWW_MSK            (0x00000007U << CSNBCR_IWWW)

/******************************* xSPI Registers *******************************/
#define XSPI_WRAPCFG_OFFSET        (0x000UL)
#define XSPI_COMCFG_OFFSET         (0x004UL)
#define XSPI_BMCFG_OFFSET          (0x008UL)
#define XSPI_CMCFG0CS0_OFFSET      (0x010UL)
#define XSPI_CMCFG1CS0_OFFSET      (0x014UL)
#define XSPI_CMCFG2CS0_OFFSET      (0x018UL)
#define XSPI_LIOCFGCS0_OFFSET      (0x050UL)
#define XSPI_BMCTL0_OFFSET         (0x060UL)
#define XSPI_CSSCTL_OFFSET         (0x06CUL)
#define XSPI_CDCTL0_OFFSET         (0x070UL)
#define XSPI_CDTBUF0_OFFSET        (0x080UL)
#define XSPI_CDABUF0_OFFSET        (0x084UL)
#define XSPI_CDD0BUF0_OFFSET       (0x088UL)
#define XSPI_LIOCTL_OFFSET         (0x108UL)
#define XSPI_INTS_OFFSET           (0x190UL)
#define XSPI_INTC_OFFSET           (0x194UL)

#define XSPI_WRAPCFG(base)      (*(volatile uint32_t *) ((base) + XSPI_WRAPCFG_OFFSET))
#define XSPI_COMCFG(base)       (*(volatile uint32_t *) ((base) + XSPI_COMCFG_OFFSET))
#define XSPI_BMCFG(base)        (*(volatile uint32_t *) ((base) + XSPI_BMCFG_OFFSET))
#define XSPI_CMCFG0CS0(base)    (*(volatile uint32_t *) ((base) + XSPI_CMCFG0CS0_OFFSET))
#define XSPI_CMCFG1CS0(base)    (*(volatile uint32_t *) ((base) + XSPI_CMCFG1CS0_OFFSET))
#define XSPI_CMCFG2CS0(base)    (*(volatile uint32_t *) ((base) + XSPI_CMCFG2CS0_OFFSET))
#define XSPI_LIOCFGCS0(base)    (*(volatile uint32_t *) ((base) + XSPI_LIOCFGCS0_OFFSET))
#define XSPI_BMCTL0(base)       (*(volatile uint32_t *) ((base) + XSPI_BMCTL0_OFFSET))
#define XSPI_CSSCTL(base)       (*(volatile uint32_t *) ((base) + XSPI_CSSCTL_OFFSET))
#define XSPI_CDCTL0(base)       (*(volatile uint32_t *) ((base) + XSPI_CDCTL0_OFFSET))
#define XSPI_CDTBUF0(base)      (*(volatile uint32_t *) ((base) + XSPI_CDTBUF0_OFFSET))
#define XSPI_CDABUF0(base)      (*(volatile uint32_t *) ((base) + XSPI_CDABUF0_OFFSET))
#define XSPI_CDD0BUF0(base)     (*(volatile uint32_t *) ((base) + XSPI_CDD0BUF0_OFFSET))
#define XSPI_LIOCTL(base)       (*(volatile uint32_t *) ((base) + XSPI_LIOCTL_OFFSET))
#define XSPI_INTS(base)         (*(volatile uint32_t *) ((base) + XSPI_INTS_OFFSET))
#define XSPI_INTC(base)         (*(volatile uint32_t *) ((base) + XSPI_INTC_OFFSET))

/* WRAPCFG register */
#define XSPI_WRAPCFG_CKSFTCS0                  (0U)
#define XSPI_WRAPCFG_CKSFTCS0_MSK              (0x1FU << XSPI_WRAPCFG_CKSFTCS0)
#define XSPI_WRAPCFG_DSSFTCS0                  (8U)
#define XSPI_WRAPCFG_DSSFTCS0_MSK              (0x1FU << XSPI_WRAPCFG_DSSFTCS0)

/* COMCFG register */
#define XSPI_COMCFG_OEASTEX                    (16U)
#define XSPI_COMCFG_OEASTEX_MSK                (0x1U << XSPI_COMCFG_OEASTEX)
#define XSPI_COMCFG_OENEGEX                    (17U)
#define XSPI_COMCFG_OENEGEX_MSK                (0x1U << XSPI_COMCFG_OENEGEX)

/* xSPI Protocol Mode */
#define XSPI_LIOCFGCS_PRTMD_1S_1S_1S           (0x0000UL)
#define XSPI_LIOCFGCS_PRTMD_8D_8D_8D           (0x03FFUL)

/* CMCFG0CSN Register */
#define XSPI_CMCFG0CS_FFMT                     (0U)
#define XSPI_CMCFG0CS_ADDSIZE                  (2U)
#define XSPI_CMCFG0CS_ADDRPEN                  (16U)
#define XSPI_CMCFG0CS_ADDRPCD                  (24U)

/* CMCFG1CSn Register */
#define XSPI_CMCFG1CS_RDCMD                    (0U)
#define XSPI_CMCFG1CS_RDLATE                   (16U)

/* LIOCFGCSn Register */
#define XSPI_LIOCFGCS_PRTMD                    (0U)
#define XSPI_LIOCFGCS_LATEMD                   (10U)
#define XSPI_LIOCFGCS_WRMSKMD                  (11U)
#define XSPI_LIOCFGCS_SDRDRV                   (22U)
#define XSPI_LIOCFGCS_SDRSMPMD                 (23U)

/* BMCTL0 Register */
#define XSPI_BMCTL0_CS0ACC                     (0U)
#define XSPI_BMCTL0_CS0ACC_MSK                 (0x3U << XSPI_BMCTL0_CS0ACC)

/* CSSCTL Register */
#define XSPI_CSSCTL_CS0SIZE                    (0U)
#define XSPI_CSSCTL_CS0SIZE_MSK                (0x3FU << XSPI_CSSCTL_CS0SIZE)
#define XSPI_CSSCTL_CS1SIZE                    (8U)
#define XSPI_CSSCTL_CS1SIZE_MSK                (0x3FU << XSPI_CSSCTL_CS1SIZE)

/* BMCFGCHn Register */
#define XSPI_BMCFG_WRMD                        (0U)
#define XSPI_BMCFG_MWRCOMB                     (7U)
#define XSPI_BMCFG_MWRSIZE                     (8U)
#define XSPI_BMCFG_PREEN                       (16U)
#define XSPI_BMCFG_PREEN_MSK                   (01U << XSPI_BMCFG_PREEN)

/* INTC Register */
#define XSPI_INTC_CMDCMPC                      (0U)
#define XSPI_INTC_CMDCMPC_MSK                  (0x1U << XSPI_INTC_CMDCMPC)

/* INTS Register */
#define XSPI_INTS_CMDCMP                       (0U)
#define XSPI_INTS_CMDCMP_MSK                   (0x1U << XSPI_INTS_CMDCMP)

/* CDTBUFn Register */
#define XSPI_CDTBUF_CMDSIZE                    (0U)
#define XSPI_CDTBUF_CMDSIZE_MSK                (0x3U << XSPI_CDTBUF_CMDSIZE)
#define XSPI_CDTBUF_ADDSIZE                    (2U)
#define XSPI_CDTBUF_ADDSIZE_MSK                (0x7U << XSPI_CDTBUF_ADDSIZE)
#define XSPI_CDTBUF_DATASIZE                   (5U)
#define XSPI_CDTBUF_LATE                       (9U)
#define XSPI_CDTBUF_TRTYPE                     (15U)
#define XSPI_CDTBUF_CMD                        (16U)

/* CDCTL0 Register */
#define XSPI_CDCTL0_TRREQ                      (0U)
#define XSPI_CDCTL0_TRREQ_MSK                  (0x1U << XSPI_CDCTL0_TRREQ)

/* LIOCTL Register */
#define XSPI_LIOCTL_RSTCS0                     (16U)
#define XSPI_LIOCTL_RSTCS0_MSK                 (0x1U << XSPI_LIOCTL_RSTCS0)

/******************************* OTP Registers *******************************/

#define OTP_OTPPWR_OFFSET                      (0x0000U)
#define OTP_OTPSTR_OFFSET                      (0x0004U)
#define OTP_OTPSTAWR_OFFSET                    (0x0008U)
#define OTP_OTPADRWR_OFFSET                    (0x000CU)
#define OTP_OTPDATAWR_OFFSET                   (0x0010U)
#define OTP_OTPADRRD_OFFSET                    (0x0014U)
#define OTP_OTPDATARD_OFFSET                   (0x0018U)
#define OTP_OTPFLAG_OFFSET                     (0x001CU)

#define OTP_OTPPWR                             (*(volatile uint32_t *) (OTP_BASE + OTP_OTPPWR_OFFSET))
#define OTP_OTPSTR                             (*(volatile uint32_t *) (OTP_BASE + OTP_OTPSTR_OFFSET))
#define OTP_OTPSTAWR                           (*(volatile uint32_t *) (OTP_BASE + OTP_OTPSTAWR_OFFSET))
#define OTP_OTPADRWR                           (*(volatile uint32_t *) (OTP_BASE + OTP_OTPADRWR_OFFSET))
#define OTP_OTPDATAWR                          (*(volatile uint32_t *) (OTP_BASE + OTP_OTPDATAWR_OFFSET))
#define OTP_OTPADRRD                           (*(volatile uint32_t *) (OTP_BASE + OTP_OTPADRRD_OFFSET))
#define OTP_OTPDATARD                          (*(volatile uint32_t *) (OTP_BASE + OTP_OTPDATARD_OFFSET))
#define OTP_OTPFLAG                            (*(volatile uint32_t *) (OTP_BASE + OTP_OTPFLAG_OFFSET))

/* OTPPWR Register */
#define OTP_OTPPWR_PWR                         (0U)
#define OTP_OTPPWR_ACCL                        (4U)

/* OTPSTR Register */
#define OTP_OTPSTR_CMD_RDY                     (0U)
#define OTP_OTPSTR_ERR_WR                      (1U)
#define OTP_OTPSTR_ERR_WR_MASK                 (3U << OTP_OTPSTR_ERR_WR)
#define OTP_OTPSTR_ERR_WP                      (3U)
#define OTP_OTPSTR_ERR_RP                      (4U)
#define OTP_OTPSTR_ERR_RDY_WR                  (8U)
#define OTP_OTPSTR_ERR_RDY_RD                  (9U)
#define OTP_OTPSTR_OTP_PWOK                    (12U)
#define OTP_OTPSTR_OTP_CALIBRATED              (13U)
#define OTP_OTPSTR_OTP_CNT_ST_IDLE             (15U)
#define OTP_OTPSTR_OTP_FLAGSTATE               (16U)
#define OTP_OTPSTR_OTP_FLAGSTATE_MASK          (0xFU << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_POWER_DOWN    (0x0U << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_STAND_BY      (0x1U << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_READ_SC       (0x2U << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_PROG_SC       (0xBU << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_PROG          (0x3U << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_BIST_SBY      (0x4U << OTP_OTPSTR_OTP_FLAGSTATE)
#define OTP_OTPSTR_OTP_FLAGSTATE_BIST1         (0x5U << OTP_OTPSTR_OTP_FLAGSTATE)

/* OTPSTAWR Register */
#define OTP_OTPSTAWR_STAWR                     (0U)

/* OTPADRWR Register */

#define OTP_OTPADRWR_ADRWR                     (0U)
#define OTP_OTPADRWR_ADRWR_MASK                (0x1FFU << OTP_OTPADRWR_ADRWR)

/* OTPDATAWR Register */

#define OTP_OTPDATAWR_DATAWR                   (0U)
#define OTP_OTPDATAWR_DATAWR_MASK              (0xFFFFU << OTP_OTPDATAWR_DATAWR)

/* OTPADRRD Register */

#define OTP_OTPADRRD_ADRRD                     (0U)
#define OTP_OTPADRRD_ADRRD_MASK                (0x1FFU << OTP_OTPADRRD_ADRRD)

/* OTPDATARD Register */

#define OTP_OTPDATARD_DATARD                   (0U)
#define OTP_OTPDATARD_DATARD_MASK              (0xFFFFU << OTP_OTPDATARD_DATARD)

/* OTPFLAG Register */

#define OTP_OTPFLAG_SDSETTING                  (0U)

/* OTP Locations read by Boot ROM (and written on FPGA version) */

/*cstat -CERT-MSC41-C_b define values are common terms or offsets, not sensitive*/

#if 1 == BSP_FEATURE_RSIP_OTP_ADDRESS_SPACE
 #define OTP_IP_ADDR_MIN                            (0x089U)
 #define OTP_IP_ADDR_MAX                            (0x1FFU)

 #define OTP_IP_ADDITIONAL_KEY4_ADDR                (0x1E8U)
 #define OTP_IP_ADDITIONAL_KEY3_ADDR                (0x1D0U)
 #define OTP_IP_SCI_AUTHENTICATION_ID_ADDR          (0x18FU)
 #define OTP_IP_SCI_AUTHENTICATION_TYPE_ADDR        (0x18EU)
 #define OTP_IP_SCI_AUTHENTICATION_MODE_ADDR        (0x18DU)
 #define OTP_IP_JTAG_AUTHENTICATION_ID4_ADDR        (0x17DU)
 #define OTP_IP_JTAG_AUTHENTICATION_ID1_ADDR        (0x16DU)
 #define OTP_IP_SECURE_BOOT_ENABLE_ADDR             (0x158U)
 #define OTP_IP_ROOT_PUBLIC_KEY_HASH_ADDR           (0x148U)
 #define OTP_IP_HARDWARE_UNIQUE_ID_ADDR             (0x100U)
 #define OTP_IP_ADDITIONAL_KEY2_ADDR                (0x0E8U)
 #define OTP_IP_ADDITIONAL_KEY1_ADDR                (0x0D0U)
 #define OTP_IP_SECURITY_DISABLE_ADDR               (0x0C1U)
 #define OTP_IP_SCI_AUTHENTICATION_ID_PLAIN_ADDR    (0x0A3U)
 #define OTP_IP_JTAG_AUTHENTICATION_TYPE_ADDR       (0x092U)
 #define OTP_IP_JTAG_AUTHENTICATION_MODE_ADDR       (0x091U)
 #define OTP_IP_UNIQUE_ID_ADDR                      (0x089U)
#elif 2 == BSP_FEATURE_RSIP_OTP_ADDRESS_SPACE
 #define OTP_IP_ADDR_MIN                            (0x0E5U)
 #define OTP_IP_ADDR_MAX                            (0x3FFU)

 #define OTP_IP_ADDITIONAL_KEY4_ADDR                (0x19CU)
 #define OTP_IP_ADDITIONAL_KEY3_ADDR                (0x190U)
 #define OTP_IP_SCI_AUTHENTICATION_ID_ADDR          (0x1CDU)
 #define OTP_IP_SCI_AUTHENTICATION_TYPE_ADDR        (0x1CCU)
 #define OTP_IP_SCI_AUTHENTICATION_MODE_ADDR        (0x1CBU)
 #define OTP_IP_JTAG_AUTHENTICATION_ID4_ADDR        (0x1C3U)
 #define OTP_IP_JTAG_AUTHENTICATION_ID1_ADDR        (0x1BBU)
 #define OTP_IP_SECURE_BOOT_ENABLE_ADDR             (0x1B0U)
 #define OTP_IP_ROOT_PUBLIC_KEY_HASH_ADDR           (0x1A8U)
 #define OTP_IP_HARDWARE_UNIQUE_ID_ADDR             (0x160U)
 #define OTP_IP_ADDITIONAL_KEY2_ADDR                (0x184U)
 #define OTP_IP_ADDITIONAL_KEY1_ADDR                (0x178U)
 #define OTP_IP_SECURITY_DISABLE_ADDR               (0x10AU)
 #define OTP_IP_SCI_AUTHENTICATION_ID_PLAIN_ADDR    (0x0F3U)
 #define OTP_IP_JTAG_AUTHENTICATION_TYPE_ADDR       (0x0EAU)
 #define OTP_IP_JTAG_AUTHENTICATION_MODE_ADDR       (0x0E9U)
 #define OTP_IP_UNIQUE_ID_ADDR                      (0x0E5U)
#else
 #error Unknown device.
#endif

/* OTP Location sizes in 16 bit units.  Sizes are defined in bits in
 * documentation but read unit is 16 bits. */

#define OTP_IP_ADDITIONAL_KEY4_SIZE                    (384U / 16U)
#define OTP_IP_ADDITIONAL_KEY3_SIZE                    (384U / 16U)
#define OTP_IP_SCI_AUTHENTICATION_ID_SIZE              (256U / 16U)
#define OTP_IP_SCI_AUTHENTICATION_TYPE_SIZE            (16U / 16U)
#define OTP_IP_SCI_AUTHENTICATION_MODE_SIZE            (16U / 16U)
#define OTP_IP_JTAG_AUTHENTICATION_ID4_SIZE            (256U / 16U)
#define OTP_IP_JTAG_AUTHENTICATION_ID1_SIZE            (256U / 16U)
#define OTP_IP_SECURE_BOOT_ENABLE_SIZE                 (16U / 16U)
#define OTP_IP_ROOT_PUBLIC_KEY_HASH_SIZE               (256U / 16U)
#define OTP_IP_HARDWARE_UNIQUE_ID_SIZE                 (384U / 16U)
#define OTP_IP_ADDITIONAL_KEY2_SIZE                    (384U / 16U)
#define OTP_IP_ADDITIONAL_KEY1_SIZE                    (384U / 16U)
#define OTP_IP_SECURITY_DISABLE_SIZE                   (16U / 16U)
#define OTP_IP_SCI_AUTHENTICATION_ID_PLAIN_SIZE        (128U / 16U)
#define OTP_IP_JTAG_AUTHENTICATION_TYPE_SIZE           (16U / 16U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_SIZE           (16U / 16U)
#define OTP_IP_UNIQUE_ID_SIZE                          (128U / 16U)

/* OTP Bit Masks */

#define OTP_IP_SCI_AUTHENTICATION_TYPE_MASK            (0x0001U)
#define OTP_IP_SCI_AUTHENTICATION_MODE_MASK            (0x0003U)
#define OTP_IP_SECURE_BOOT_ENABLE_MASK                 (0x0001U)
#define OTP_IP_SECURITY_DISABLE_MASK                   (0x0001U)
#define OTP_IP_JTAG_AUTHENTICATION_TYPE_MASK           (0x0001U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_MASK           (0x0007U)

/* OTP Flag Values */

#define OTP_IP_SCI_AUTHENTICATION_TYPE_PLAIN           (0x0000U)
#define OTP_IP_SCI_AUTHENTICATION_TYPE_HASH            (0x0001U)

#define OTP_IP_SCI_AUTHENTICATION_MODE_NONE            (0x0000U)
#define OTP_IP_SCI_AUTHENTICATION_MODE_ID              (0x0001U)
#define OTP_IP_SCI_AUTHENTICATION_MODE_PROHIBITED      (0x0002U)
#define OTP_IP_SCI_AUTHENTICATION_MODE_PROHIBITEDA     (0x0003U)

#define OTP_IP_SECURE_BOOT_ENABLE_TRUE                 (0x0001U)
#define OTP_IP_SECURE_BOOT_ENABLE_FALSE                (0x0000U)

#define OTP_IP_SECURITY_DISABLE_TRUE                   (0x0001U)
#define OTP_IP_SECURITY_DISABLE_FALSE                  (0x0000U)

#define OTP_IP_JTAG_AUTHENTICATION_TYPE_PLAIN          (0x0000U)
#define OTP_IP_JTAG_AUTHENTICATION_TYPE_HASH           (0x0001U)

#define OTP_IP_JTAG_AUTHENTICATION_MODE_NONE           (0x0000U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_LEVEL_1        (0x0001U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_LEVEL_4        (0x0002U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_LEVEL_4A       (0x0003U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_PROHIBITED     (0x0004U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_PROHIBITEDA    (0x0005U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_PROHIBITEDB    (0x0006U)
#define OTP_IP_JTAG_AUTHENTICATION_MODE_PROHIBITEDC    (0x0007U)

/*cstat +CERT-MSC41-C_b*/

/******************************* SCIF0 Registers *******************************/
#define SCI0_RDR_OFFSET                                (0x0000U)
#define SCI0_TDR_OFFSET                                (0x0004U)
#define SCI0_CCR0_OFFSET                               (0x0008U)
#define SCI0_CCR1_OFFSET                               (0x000CU)
#define SCI0_CCR2_OFFSET                               (0x0010U)
#define SCI0_CCR3_OFFSET                               (0x0014U)
#define SCI0_CCR4_OFFSET                               (0x0018U)
#define SCI0_FCR_OFFSET                                (0x0024U)
#define SCI0_CSR_OFFSET                                (0x0048U)
#define SCI0_FRSR_OFFSET                               (0x0050U)
#define SCI0_FTSR_OFFSET                               (0x0054U)
#define SCI0_CFCLR_OFFSET                              (0x0068U)

#define SCI0_RDR                                       (*(volatile uint32_t *) (SCI0_BASE + SCI0_RDR_OFFSET))
#define SCI0_TDR                                       (*(volatile uint32_t *) (SCI0_BASE + SCI0_TDR_OFFSET))

/* To avoid a Read-Modify-Write to protect reserved bits we can just write lower 8bits of the TDR TDAT field as operational mode is 8bits */
#define SCI0_TDR_TDAT_8                                (*(volatile uint8_t *) (SCI0_BASE + SCI0_TDR_OFFSET))
#define SCI0_CCR0                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_CCR0_OFFSET))
#define SCI0_CCR1                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_CCR1_OFFSET))
#define SCI0_CCR2                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_CCR2_OFFSET))
#define SCI0_CCR3                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_CCR3_OFFSET))
#define SCI0_CCR4                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_CCR4_OFFSET))
#define SCI0_FCR                                       (*(volatile uint32_t *) (SCI0_BASE + SCI0_FCR_OFFSET))
#define SCI0_CSR                                       (*(volatile uint32_t *) (SCI0_BASE + SCI0_CSR_OFFSET))
#define SCI0_FRSR                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_FRSR_OFFSET))
#define SCI0_FTSR                                      (*(volatile uint32_t *) (SCI0_BASE + SCI0_FTSR_OFFSET))
#define SCI0_CFCLR                                     (*(volatile uint32_t *) (SCI0_BASE + SCI0_CFCLR_OFFSET))

/*
 * RDR register bit mask definitions
 */
#define SCI_RDR_RDAT                                   (0u)  /* RDAT offset */
#define SCI_RDR_RDAT_MSK_8BIT                          (0x000000FFu << SCI_RDR_RDAT)

/*
 * TDR register bit mask definitions
 */
#define SCI_TDR_TDAT                                   (0u)  /* TDAT offset */
#define SCI_TDR_TDAT_MSK_8BIT                          (0x000000FFu << SCI_TDR_TDAT)

/*
 * CCR0 register bit mask definitions
 */
#define SCI_CCR0_RE                                    (0u)  /* RE offset */
#define SCI_CCR0_RE_MSK                                (0x00000001u << SCI_CCR0_RE)
#define SCI_CCR0_TE                                    (4u)  /* TE offset */
#define SCI_CCR0_TE_MSK                                (0x00000001u << SCI_CCR0_TE)

/*
 * CCR2 register bit mask definitions
 */
#define SCI_CCR2_BRR                                   (8u)  /* BRR offset */
#define SCI_CCR2_BRR_MSK                               (0x000000FFu << SCI_CCR2_BRR)
#define SCI_CCR2_CKS                                   (20u) /* CKS offset */
#define SCI_CCR2_CKS_MSK                               (0x00000003u << SCI_CCR2_CKS)

/*
 * CCR3 register bit mask definitions
 */
#define SCI_CCR3_BPEN                                  (7u)  /* BPEN offset */
#define SCI_CCR3_BPEN_MSK                              (0x00000001u << SCI_CCR3_BPEN)
#define SCI_CCR3_CHCR                                  (8u)  /* CHCR offset */
#define SCI_CCR3_CHCR_MSK                              (0x00000003u << SCI_CCR3_CHCR)
#define SCI_CCR3_STP                                   (14u) /* STP offset */
#define SCI_CCR3_STP_MSK                               (0x00000001u << SCI_CCR3_STP)
#define SCI_CCR3_MOD                                   (16u) /* MOD offset */
#define SCI_CCR3_MOD_MSK                               (0x00000007u << SCI_CCR3_MOD)
#define SCI_CCR3_MP                                    (19u) /* MP offset */
#define SCI_CCR3_MP_MSK                                (0x00000001u << SCI_CCR3_MP)
#define SCI_CCR3_FM                                    (20u) /* FM offset */
#define SCI_CCR3_FM_MSK                                (0x00000001u << SCI_CCR3_FM)
#define SCI_CCR3_DEN                                   (21u) /* DEN offset */
#define SCI_CCR3_DEN_MSK                               (0x00000001u << SCI_CCR3_DEN)
#define SCI_CCR3_CKE                                   (24u) /* CKE offset */
#define SCI_CCR3_CKE_MSK                               (0x00000003u << SCI_CCR3_CKE)
#define SCI_CCR3_ACS0                                  (26u) /* ACS0 offset */
#define SCI_CCR3_ACS0_MSK                              (0x00000001u << SCI_CCR3_ACS0)

/*
 * CCR3 register values
 */
#define CCR3_CHCR_8BIT                                 (0x00000002u << SCI_CCR3_CHCR)
#define CCR3_STP_ONE                                   (0x00000000u << SCI_CCR3_STP)
#define CCR3_MOD_ASYNC                                 (0x00000000u << SCI_CCR3_MOD)
#define CCR3_MP_DISABLED                               (0x00000000u << SCI_CCR3_MP)
#define CCR3_DEN_DISABLED                              (0x00000000u << SCI_CCR3_DEN)

/*
 * CSR register bit mask definitions
 */
#define SCI_CSR_ORER                                   (24u) /* ORER offset */
#define SCI_CSR_ORER_MSK                               (0x00000001u << SCI_CSR_ORER)
#define SCI_CSR_PER                                    (27u) /* PER offset */
#define SCI_CSR_PER_MSK                                (0x00000001u << SCI_CSR_PER)
#define SCI_CSR_FER                                    (28u) /* FER offset */
#define SCI_CSR_FER_MSK                                (0x00000001u << SCI_CSR_FER)
#define SCI_CSR_TDRE                                   (29u) /* TDRE offset */
#define SCI_CSR_TDRE_MSK                               (0x00000001u << SCI_CSR_TDRE)
#define SCI_CSR_TEND                                   (30u) /* TEND offset */
#define SCI_CSR_TEND_MSK                               (0x00000001u << SCI_CSR_TEND)
#define SCI_CSR_RDRF                                   (31u) /* RDRF offset */
#define SCI_CSR_RDRF_MSK                               (0x00000001u << SCI_CSR_RDRF)

/*
 * FRSR register bit mask definitions
 */
#define SCI_FRSR_R                                     (8u)  /* R[5:0] offset */
#define SCI_FRSR_R_MSK                                 (0x0000003Fu << SCI_FRSR_R)

/*
 * FTSR register bit mask definitions
 */
#define SCI_FTSR_T                                     (0u)  /* T[5:0] offset */
#define SCI_FTSR_T_MSK                                 (0x0000003Fu << SCI_FTSR_T)

/*
 * CFCLR register bit mask definitions
 */
#define SCI_CFCLR_ERSC                                 (4u)  /* ERSC offset */
#define SCI_CFCLR_ERSC_MSK                             (0x00000001u << SCI_CFCLR_ERSC)
#define SCI_CFCLR_DCMFC                                (16u) /* DCMFC offset */
#define SCI_CFCLR_DCMFC_MSK                            (0x00000001u << SCI_CFCLR_DCMFC)
#define SCI_CFCLR_DPERC                                (17u) /* DPERC offset */
#define SCI_CFCLR_DPERC_MSK                            (0x00000001u << SCI_CFCLR_DPERC)
#define SCI_CFCLR_DFERC                                (18u) /* DFERC offset */
#define SCI_CFCLR_DFERC_MSK                            (0x00000001u << SCI_CFCLR_DFERC)
#define SCI_CFCLR_ORERC                                (24u) /* ORERC offset */
#define SCI_CFCLR_ORERC_MSK                            (0x00000001u << SCI_CFCLR_ORERC)
#define SCI_CFCLR_MFFC                                 (26u) /* ORERC offset */
#define SCI_CFCLR_MFFC_MSK                             (0x00000001u << SCI_CFCLR_MFFC)
#define SCI_CFCLR_PERC                                 (27u) /* PERC offset */
#define SCI_CFCLR_PERC_MSK                             (0x00000001u << SCI_CFCLR_PERC)
#define SCI_CFCLR_FERC                                 (28u) /* FERC offset */
#define SCI_CFCLR_FERC_MSK                             (0x00000001u << SCI_CFCLR_FERC)
#define SCI_CFCLR_TDREC                                (29u) /* TDREC offset */
#define SCI_CFCLR_TDREC_MSK                            (0x00000001u << SCI_CFCLR_TDREC)
#define SCI_CFCLR_RDRFC                                (31u) /* RDRFC offset */
#define SCI_CFCLR_RDRFC_MSK                            (0x00000001u << SCI_CFCLR_RDRFC)

/*
 * FCR register bit mask definitions
 */
#define SCI_FCR_TTRG                                   (8u)  /* TTRG offset */
#define SCI_FCR_TTRG_MSK                               (0x0000000fu << SCI_FCR_TTRG)
#define SCI_FCR_RTRG                                   (16u) /* RTRG offset */
#define SCI_FCR_RTRG_MSK                               (0x0000000fu << SCI_FCR_RTRG)

/*
 * OCDREG definitions
 */
#define OIR0_OFFSET                                    (0x0000U)
#define OIR1_OFFSET                                    (0x0004U)
#define OIR2_OFFSET                                    (0x0008U)
#define OIR3_OFFSET                                    (0x000CU)
#define OSR_OFFSET                                     (0x0010U)
#define OCR_OFFSET                                     (0x0014U)

#define OIR0                                           (*(volatile uint32_t *) (OCDREG_BASE + OIR0_OFFSET))
#define OIR1                                           (*(volatile uint32_t *) (OCDREG_BASE + OIR1_OFFSET))
#define OIR2                                           (*(volatile uint32_t *) (OCDREG_BASE + OIR2_OFFSET))
#define OIR3                                           (*(volatile uint32_t *) (OCDREG_BASE + OIR3_OFFSET))
#define OSR                                            (*(volatile uint32_t *) (OCDREG_BASE + OSR_OFFSET))
#define OCR                                            (*(volatile uint32_t *) (OCDREG_BASE + OCR_OFFSET))

#define OSR_NO_COMP                                    (0u)            /* No authentication */
#define OSR_LEVEL1_PASSED                              (1u)            /* Level 1 Passed (Non-invasive and Invasive for EL2 and EL1/EL0) */
#define OSR_LEVEL4_PASSED                              (2u)            /* Level 4 Passed (Non-invasive and Invasive for EL1/EL0) */
#define OSR_FAIL                                       (3u)            /* Failed or access prohibited permanently */
#define OSR_OIRn_VALUES_WRITTEN                        (OSR_WRFLG_MSK) /* 1: Written */
#define OSR_RESULT                                     (0u)            /* RESULT offset */
#define OSR_RESULT_MSK                                 (0x00000003u << OSR_RESULT)
#define OSR_WRFLG                                      (2u)            /* WFLG offset */
#define OSR_WRFLG_MSK                                  (0x00000001u << OSR_WRFLG)
#define OCR_RESULT_NO_COMP                             (0u)            /* No comparison by BootROM */
#define OCR_RESULT_LEVEL1_PASSED                       (1u)            /* Level 1 passed */
#define OCR_RESULT_LEVEL4_PASSED                       (2u)            /* Level 4 passed*/
#define OCR_RESULT_COMP_FAIL                           (3u)            /* Comparison Failed*/
#define OCR_RD_PROTECT                                 (30u)           /* RDPROT offset */
#define OCR_RD_PROTECT_MSK                             (0x00000001u << OCR_RD_PROTECT)
#define OCR_OW_PROTECT                                 (31u)           /* OWPROT offset */
#define OCR_OW_PROTECT_MSK                             (0x00000001u << OCR_OW_PROTECT)
#define OCR_RESULT                                     (0u)            /* RESULT offset */
#define OCR_RESULT_MSK                                 (0x00000003u << OCR_RESULT)

/*
 * SBAREG definitions
 */
#define SIR0_OFFSET                                    (0x0000U)
#define SIR1_OFFSET                                    (0x0004U)
#define SIR2_OFFSET                                    (0x0008U)
#define SIR3_OFFSET                                    (0x000CU)
#define SSR_OFFSET                                     (0x0010U)
#define SCR_OFFSET                                     (0x0014U)

#define SIR0                                           (*(volatile uint32_t *) (SBAREG_BASE + SIR0_OFFSET))
#define SIR1                                           (*(volatile uint32_t *) (SBAREG_BASE + SIR1_OFFSET))
#define SIR2                                           (*(volatile uint32_t *) (SBAREG_BASE + SIR2_OFFSET))
#define SIR3                                           (*(volatile uint32_t *) (SBAREG_BASE + SIR3_OFFSET))
#define SSR                                            (*(volatile uint32_t *) (SBAREG_BASE + SSR_OFFSET))
#define SCR                                            (*(volatile uint32_t *) (SBAREG_BASE + SCR_OFFSET))

/*cstat -CERT-MSC41-C_b define values are common terms or offsets, not sensitive*/

#define SSR_PASSWORD_NO_COMP                           (0u)  /* No comparison yet made */
#define SSR_PASSWORD_VALID                             (1u)  /* Password is verified successfully */
#define SSR_PASSWORD_NG                                (2u)  /* Password is not a match */
#define SSR_PASSWORD_NA                                (3u)  /* Password is not available */
#define SCR_RD_PROTECT                                 (30u) /* RDPROT offset */
#define SCR_RD_PROTECT_MSK                             (0x00000001u << SCR_RD_PROTECT)
#define SCR_OW_PROTECT                                 (31u) /* OWPROT offset */
#define SCR_OW_PROTECT_MSK                             (0x00000001u << SCR_OW_PROTECT)

/*cstat +CERT-MSC41-C_b*/

/*
 * SCKCR definitions
 */
#define SCKCR_FSELXSPI0                                (0u)
#define SCKCR_FSELXSPI0_MASK                           (7u << SCKCR_FSELXSPI0)
#define SCKCR_DIVSELXSPI0                              (6u)
#define SCKCR_DIVSELXSPI0_MASK                         (1u << SCKCR_DIVSELXSPI0)
#define SCKCR_FSELXSPI1                                (8u)
#define SCKCR_FSELXSPI1_MASK                           (7u << SCKCR_FSELXSPI1)
#define SCKCR_DIVSELXSPI1                              (14u)
#define SCKCR_DIVSELXSPI1_MASK                         (1u << SCKCR_DIVSELXSPI1)

/* Valid range for SCKCR_FSELXSPIx field */
#define SCKCR_FSELXSPI0_MIN                            (2u)
#define SCKCR_FSELXSPI0_MAX                            (6u)

/* Valid range for SCKCR_FSELXSPIx field if DIVSELXSPIx is set to 1 */
#define SCKCR_FSELXSPI0_DIVSELXSPI_SET_MIN             (3u)
#define SCKCR_FSELXSPI0_DIVSELXSPI_SET_MAX             (4u)

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/

#endif                                 /* IODEFINE_H */
