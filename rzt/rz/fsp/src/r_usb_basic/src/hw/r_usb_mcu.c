/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/******************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ******************************************************************************/

#include <r_usb_basic.h>
#include <r_usb_basic_api.h>
#include <r_usb_basic_cfg.h>

#include "../driver/inc/r_usb_typedef.h"
#include "../driver/inc/r_usb_extern.h"
#include "inc/r_usb_bitdefine.h"
#include "inc/r_usb_reg_access.h"

#if (BSP_CFG_RTOS == 2)
 #include "../driver/inc/r_usb_cstd_rtos.h"
#endif                                 /* #if (BSP_CFG_RTOS == 2) */

#if ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE))
 #include "inc/r_usb_dmac.h"
#endif                                 /* ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE)) */

/******************************************************************************
 * Macro definitions
 ******************************************************************************/

#if defined(USB_CFG_HHID_USE) || defined(USB_CFG_PHID_USE)
 #if USB_CFG_DTC == USB_CFG_ENABLE
  #error  In HID class, can not set USB_CFG_ENABLE to USB_CFG_DTC in r_usb_basic_cfg.h.
 #endif                                /* USB_CFG_DTC == USB_CFG_ENABLE */

 #if USB_CFG_DMA == USB_CFG_ENABLE
  #error  In HID class, can not set USB_CFG_ENABLE to USB_CFG_DMA in r_usb_basic_cfg.h.
 #endif                                /* USB_CFG_DMA == USB_CFG_ENABLE */

#endif                                 /* defined(USB_CFG_HHID_USE) || defined(USB_CFG_PHID_USE) */

#if USB_CFG_BC == USB_CFG_DISABLE
 #if USB_CFG_DCP == USB_CFG_ENABLE
  #error  Can not set USB_CFG_DISABLE to USB_CFG_BC when setting USB_CFG_ENABLE to USB_CFG_DCP \
    in r_usb_basic_cfg.h.

 #endif                                /* USB_CFG_DCP == USB_CFG_ENABLE */
#endif                                 /* USB_CFG_BC == USB_CFG_DISABLE */

#if USB_CFG_DMA == USB_CFG_ENABLE
 #if USB_CFG_DTC == USB_CFG_ENABLE
  #error  Can not set USB_CFG_ENABLE to the definitions (USB_CFG_DMA and USB_CFG_DTC) at the same time \
    in r_usb_basic_cfg.h.

 #endif                                /* USB_CFG_DTC == USB_CFG_ENABLE */
#endif                                 /* USB_CFG_DMA == USB_CFG_ENABLE */

#if USB_CFG_MODE == USB_CFG_HOST
 #if defined(USB_CFG_PCDC_USE) || defined(USB_CFG_PHID_USE) || defined(USB_CFG_PMSC_USE) || defined(USB_CFG_PVNDR_USE)
  #error  Can not enable these definitions(USB_CFG_PCDC_USE/USB_CFG_PHID_USE/USB_CFG_PMSC_USE/USB_CFG_PVNDR_USE) \
    when setting USB_MODE_HOST to USB_CFG_MODE in r_usb_basic_cfg.h.

 #endif                                /* defined(USB_CFG_PCDC_USE || USB_CFG_PHID_USE || USB_CFG_PMSC_USE || USB_CFG_PVNDR_USE) */
#endif                                 /* USB_CFG_MODE == USB_MODE_HOST */

#if USB_CFG_MODE == USB_CFG_PERI
 #if defined(USB_CFG_HCDC_USE) || defined(USB_CFG_HHID_USE) || defined(USB_CFG_HMSC_USE) || defined(USB_CFG_HVNDR_USE)
  #error  Can not enable these definitions(USB_CFG_HCDC_USE/USB_CFG_HHID_USE/USB_CFG_HMSC_USE/USB_CFG_HVNDR_USE) \
    when setting USB_MODE_PERI to USB_CFG_MODE in r_usb_basic_cfg.h.

 #endif                                /* defined(USB_CFG_HCDC_USE || USB_CFG_HHID_USE || USB_CFG_HMSC_USE || USB_CFG_HVNDR_USE) */
#endif                                 /* USB_CFG_MODE == USB_MODE_PERI */

#define USB_VAL_50                     (50U)
#define USB_VAL_100                    (100U)
#define USB_VAL_250                    (250U)
#define USB_VAL_450                    (450U)
#define USB_VAL_500                    (500U)
#define USB_VAL_SUSPM                  (0x4000U)
#define USB_VAL_INTENB0                (0x9D00U)
#define USB_VAL_MSTPCRE_8              (0x00000100)

#if defined(BSP_MCU_GROUP_RZT2H) || defined(BSP_MCU_GROUP_RZT2N)
 #define BSP_PRV_PRCR_KEY              (0xA500U)
 #define REG_PROTECT_FOR_HS_CONNECT    (0x0010U)
 #define USB_VAL_MSTP                  (0x802803F0)
 #define USB_VAL_HS_SET_ADDR           (0x92042c10)
 #define USB_VAL_LS_SET_ADDR1          (0x92040304)
 #define USB_VAL_LS_SET_ADDR2          (0x92040318)
 #define USB_VAL_REG_PROTECT           (0x80294200)
 #define USB_VAL_LS_SET2               (0x8000018F)
 #define USB_VAL_LS_SET3               (0xFFFFFFFE)
 #define USB_VAL_HS_SET                (0x0000067C)
#endif                                 /* defined(BSP_MCU_GROUP_RZT2H) */

/******************************************************************************
 * Exported global variables (to be accessed by other files)
 ******************************************************************************/
usb_cfg_t * host_cfg;

/******************************************************************************
 * Private global variables and functions
 ******************************************************************************/
void usbf_interrupt_handler(void);
void usbf_usbi_isr(void);

#if  USB_IP_EHCI_OHCI == 1
void usb_ahb_pci_bridge_init(void);

#endif                                 /* USB_IP_EHCI_OHCI == 1 */

/******************************************************************************
 * Renesas Abstracted RSK functions
 ******************************************************************************/

/**************************************************************************//**
 * @brief This function stops USB module.
 *
 * @retval FSP_SUCCESS           Success.
 ******************************************************************************/
fsp_err_t usb_module_start (uint8_t ip_type)
{
    FSP_PARAMETER_NOT_USED(ip_type);
#if USB_CFG_MODE == USB_CFG_PERI
 #if 2 == BSP_FEATURE_USB_HOST_HS_SET_TYPE
    uint32_t * mstp_set;
    uint32_t * hs_set;
    mstp_set = (uint32_t *) USB_VAL_MSTP;
 #endif                                /*defined(BSP_MCU_GROUP_RZT2H)*/

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_USBHS, 0);
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MICROSECONDS);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
 #if 2 == BSP_FEATURE_USB_PERI_INIT_TYPE
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);

    R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_PRV_PRCR_KEY) | REG_PROTECT_FOR_HS_CONNECT);
    R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_PRV_PRCR_KEY) | REG_PROTECT_FOR_HS_CONNECT);

    *mstp_set &= 0x00000000;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);

    hs_set  = (uint32_t *) USB_VAL_HS_SET_ADDR;
    *hs_set = USB_VAL_HS_SET;

    R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_PRV_PRCR_KEY) & (uint16_t) (~REG_PROTECT_FOR_HS_CONNECT));
    R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_PRV_PRCR_KEY) & (uint16_t) (~REG_PROTECT_FOR_HS_CONNECT));
 #endif                                /* 2 == BSP_FEATURE_USB_PERI_INIT_TYPE */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);

    USB00->COMMCTRL_b.PERI = 1;
 #if 2 == BSP_FEATURE_USB_PERI_INIT_TYPE
    USB_M0->SYSCFG0_b.DRPD   = 0;
    USB_M0->LPSTS_b.SUSPM    = 1;
    USB00->VBCTRL_b.SIDDQREL = 1;
    USB00->USBCTR_b.PLL_RST  = 0;
    USB00->PHYCTRL_b.DRVVBUS = 1;
    R_BSP_SoftwareDelay(USB_VAL_250 * 10, BSP_DELAY_UNITS_MICROSECONDS);
    USB_M0->SYSCFG0_b.USBE = 1;
 #else                                 /* 2 == BSP_FEATURE_USB_PERI_INIT_TYPE */
    USB00->USBCTR &= ~0x00000002U;     /* UTMI+PHY reset OFF */
    R_BSP_SoftwareDelay(USB_VAL_100, BSP_DELAY_UNITS_MICROSECONDS);

    USB_M0->SYSCFG0_b.DRPD = 0;

    USB_M0->SYSCFG0_b.USBE = 1;
    USB_M0->LPSTS          = USB_VAL_SUSPM;
    R_BSP_SoftwareDelay(USB_VAL_100, BSP_DELAY_UNITS_MICROSECONDS);

    USB_M0->INTENB0 = USB_VAL_INTENB0;
 #endif                                /* 2 == BSP_FEATURE_USB_PERI_INIT_TYPE */
#else
    volatile unsigned long dummy;
 #if 2 == BSP_FEATURE_USB_HOST_HS_SET_TYPE
    uint32_t * mstp_set;
    uint32_t * hs_set;

    mstp_set = (uint32_t *) USB_VAL_MSTP;
 #endif

    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_BSP_MODULE_START(FSP_IP_USBHS, 0);
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
 #if 2 == BSP_FEATURE_USB_HOST_INIT_TYPE
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);

    R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_PRV_PRCR_KEY) | REG_PROTECT_FOR_HS_CONNECT);
    R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_PRV_PRCR_KEY) | REG_PROTECT_FOR_HS_CONNECT);

    *mstp_set &= 0x00000000;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);
    FSP_REGISTER_READ(*mstp_set);

    hs_set  = (uint32_t *) USB_VAL_HS_SET_ADDR;
    *hs_set = USB_VAL_HS_SET;

    R_RWP_NS->PRCRN = ((R_RWP_NS->PRCRN | BSP_PRV_PRCR_KEY) & (uint16_t) (~REG_PROTECT_FOR_HS_CONNECT));
    R_RWP_S->PRCRS  = ((R_RWP_S->PRCRS | BSP_PRV_PRCR_KEY) & (uint16_t) (~REG_PROTECT_FOR_HS_CONNECT));
 #endif                                        /* 2 == BSP_FEATURE_USB_HOST_INIT_TYPE  */
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    for (dummy = 0; dummy < (USB_VAL_450 * USB_VAL_500); dummy++)
    {
        ;                                      /* Wait 500us */
    }

    USB00->COMMCTRL_b.PERI = 0;                /* Operation mode setting (0 : Host, 1 : Peri) */
 #if 1 == BSP_FEATURE_USB_HOST_INIT_TYPE
    USB00->USBCTR &= ~(uint32_t) 0x00000002UL; /* UTMI+PHY reset OFF */               /* UTMI+PHY reset release */
 #else
    USB00->VBCTRL_b.SIDDQREL = 1;
    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MICROSECONDS);
    USB00->USBCTR_b.PLL_RST = 0;
    R_BSP_SoftwareDelay(USB_VAL_250, BSP_DELAY_UNITS_MICROSECONDS);
    USB00->PHYCTRL_b.DRVVBUS = 1;
 #endif

    for (dummy = 0; dummy < (USB_VAL_450 * USB_VAL_100); dummy++)
    {
        ;                              /* Wait 100us */
    }

    /* AHB-PCI bridge Register setting */
    usb_ahb_pci_bridge_init();

    /* Core defined register setting */

/*       USB00->REGEN_CG_CTRL.BIT.NONUSE_CLK_MSK  = 1;
 *     USB00.REGEN_CG_CTRL.BIT.HOST_CLK_MSK    = 0;
 *     USB00.REGEN_CG_CTRL.BIT.PERI_CLK_MSK    = 0;
 *
 *     USB00.SPD_CTRL.BIT.SUSPENDM_ENABLE      = 0;
 *     USB00.SPD_CTRL.BIT.SLEEPM_ENABLE        = 0;
 *     USB00.SPD_CTRL.BIT.WKCNNT_ENABLE        = 0;
 *     USB00.SPD_CTRL.BIT.GLOBAL_SUSPENDM_P1   = 0;*/
#endif

    return FSP_SUCCESS;
}

/******************************************************************************
 * End of function usb_module_start
 ******************************************************************************/

/**************************************************************************//**
 * @brief This function stops USB module.
 *
 * @retval FSP_SUCCESS           Success.
 * @retval FSP_ERR_USB_FAILED    The function could not be completed successfully.
 * @retval FSP_ERR_USB_NOT_OPEN  USB module is not open.
 * @retval FSP_ERR_USB_PARAMETER USB IP type is wrong.
 ******************************************************************************/
fsp_err_t usb_module_stop (uint8_t ip_type)
{
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    FSP_ERROR_RETURN(1 != R_SYSC_NS->MSTPCRE_b.MSTPCRE08, FSP_ERR_USB_FAILED)
    if (USB_IP0 == ip_type)
    {
        USB_M0->DVSTCTR0    = 0;
        USB_M0->DCPCTR      = USB_SQSET;
        USB_M0->PIPE_CTR[0] = 0;
        USB_M0->PIPE_CTR[1] = 0;
        USB_M0->PIPE_CTR[2] = 0;
        USB_M0->PIPE_CTR[3] = 0;
        USB_M0->PIPE_CTR[4] = 0;
        USB_M0->PIPE_CTR[5] = 0;
        USB_M0->PIPE_CTR[6] = 0;
        USB_M0->PIPE_CTR[7] = 0;
        USB_M0->PIPE_CTR[8] = 0;
        USB_M0->BRDYENB     = 0;
        USB_M0->NRDYENB     = 0;
        USB_M0->BEMPENB     = 0;
        USB_M0->INTENB0     = 0;
        USB_M0->INTENB1     = 0;
        USB_M0->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DPRPU));
        USB_M0->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DRPD));
        USB_M0->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_USBE));
        USB_M0->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DCFM));
        USB_M0->BRDYSTS     = 0;
        USB_M0->NRDYSTS     = 0;
        USB_M0->BEMPSTS     = 0;
    }
    else
    {
        USB_M1->DVSTCTR0    = 0;
        USB_M1->DCPCTR      = USB_SQSET;
        USB_M1->PIPE_CTR[0] = 0;
        USB_M1->PIPE_CTR[1] = 0;
        USB_M1->PIPE_CTR[2] = 0;
        USB_M1->PIPE_CTR[3] = 0;
        USB_M1->PIPE_CTR[4] = 0;
        USB_M1->PIPE_CTR[5] = 0;
        USB_M1->PIPE_CTR[6] = 0;
        USB_M1->PIPE_CTR[7] = 0;
        USB_M1->PIPE_CTR[8] = 0;
        USB_M1->BRDYENB     = 0;
        USB_M1->NRDYENB     = 0;
        USB_M1->BEMPENB     = 0;
        USB_M1->INTENB0     = 0;
        USB_M1->INTENB1     = 0;
        USB_M1->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DPRPU));
        USB_M1->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DRPD));
        USB_M1->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_USBE));
        USB_M1->SYSCFG0     = (uint16_t) (USB_M0->SYSCFG0 & (~USB_DCFM));
        USB_M1->BRDYSTS     = 0;
        USB_M1->NRDYSTS     = 0;
        USB_M1->BEMPSTS     = 0;
    }
    FSP_ERROR_RETURN(0 == R_SYSC_NS->MSTPCRE_b.MSTPCRE08, FSP_ERR_USB_NOT_OPEN)
#endif                                 /* ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI) */

    if (R_SYSC_NS->MSTPCRE_b.MSTPCRE08 == 1)
    {
        return FSP_ERR_USB_PARAMETER;
    }

    /* Disable power for USBA */
    R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_LPC_RESET);
    R_SYSC_NS->MSTPCRE = R_SYSC_NS->MSTPCRE | USB_VAL_MSTPCRE_8;
    R_BSP_SoftwareDelay(1, BSP_DELAY_UNITS_MILLISECONDS);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    FSP_REGISTER_READ(R_SYSC_NS->MSTPCRE_b.MSTPCRE08);
    R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_LPC_RESET);
    FSP_PARAMETER_NOT_USED(ip_type);

    return FSP_SUCCESS;
}

/******************************************************************************
 * End of function usb_module_stop
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_cpu_usbint_init
 * Description     : USB interrupt Initialize
 * Arguments       : uint8_t ip_type  : USB_IP0/USB_IP1
 * Return value    : void
 ******************************************************************************/
void usb_cpu_usbint_init (uint8_t ip_type, usb_cfg_t const * const cfg)
{
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
    R_BSP_IrqDetectTypeSet(cfg->irq, 1);
#else                                  /* ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)*/
    R_BSP_IrqDetectTypeSet(cfg->irq, 0);
#endif                                 /* ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)*/
#if ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE))
    R_BSP_IrqDetectTypeSet(cfg->irq_d0, 1);
    R_BSP_IrqDetectTypeSet(cfg->irq_d1, 1);
#endif                                 /* ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE)) */
    if (USB_IP0 == ip_type)
    {
        /* Interrupt enable register
         * b0 IEN0 Interrupt enable bit
         * b1 IEN1 Interrupt enable bit
         * b2 IEN2 Interrupt enable bit
         * b3 IEN3 Interrupt enable bit
         * b4 IEN4 Interrupt enable bit
         * b5 IEN5 Interrupt enable bit
         * b6 IEN6 Interrupt enable bit
         * b7 IEN7 Interrupt enable bit
         */
        host_cfg = (usb_cfg_t *) cfg;
        R_BSP_IrqCfgEnable(cfg->irq, cfg->ipl, (void *) cfg);       /* USBI enable */
#if ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE))
        R_BSP_IrqCfgEnable(cfg->irq_d0, cfg->ipl_d0, (void *) cfg); /* Enable D0FIFO interrupt */

        R_BSP_IrqCfgEnable(cfg->irq_d1, cfg->ipl_d1, (void *) cfg); /* Enable D1FIFO interrupt */
#endif  /* ((USB_CFG_DTC == USB_CFG_ENABLE) || (USB_CFG_DMA == USB_CFG_ENABLE)) */
#if defined(BSP_MCU_GROUP_RZT2H)
        USB_M0->INTENB0 = USB_VAL_INTENB0;
#endif /* defined(BSP_MCU_GROUP_RZT2H) */
    }

    if (ip_type == USB_IP1)
    {
    }
}

/******************************************************************************
 * End of function usb_cpu_usbint_init
 ******************************************************************************/

/******************************************************************************
 * TIMER function
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_cpu_delay_1us
 * Description     : 1us Delay timer
 * Arguments       : uint16_t  time        ; Delay time(*1us)
 * Return value    : none
 * Note            : Please change for your MPU
 ******************************************************************************/
void usb_cpu_delay_1us (uint16_t time)
{
    R_BSP_SoftwareDelay((uint32_t) time, BSP_DELAY_UNITS_MICROSECONDS);
}

/******************************************************************************
 * End of function usb_cpu_delay_1us
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_cpu_delay_xms
 * Description     : xms Delay timer
 * Arguments       : uint16_t  time        ; Delay time(*1ms)
 * Return value    : void
 * Note            : Please change for your MPU
 ******************************************************************************/
void usb_cpu_delay_xms (uint16_t time)
{
#if (BSP_CFG_RTOS == 0)
    R_BSP_SoftwareDelay((uint32_t) time, BSP_DELAY_UNITS_MILLISECONDS);
#endif                                 /* (BSP_CFG_RTOS == 0) */

#if (BSP_CFG_RTOS == 2)
    vTaskDelay((TickType_t) (time / portTICK_PERIOD_MS));

/* R_BSP_SoftwareDelay((uint32_t)time, BSP_DELAY_UNITS_MILLISECONDS); */
#endif                                 /* (BSP_CFG_RTOS == 2) */
}

/******************************************************************************
 * End of function usb_cpu_delay_xms
 ******************************************************************************/

#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)

/******************************************************************************
 * Function Name   : usb_cpu_int_enable
 * Description     : USB Interrupt Enable
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void usb_cpu_int_enable (void)
{
    /* Interrupt enable register (USB0 USBIO enable)
     * b0 IEN0 Interrupt enable bit
     * b1 IEN1 Interrupt enable bit
     * b2 IEN2 Interrupt enable bit
     * b3 IEN3 Interrupt enable bit
     * b4 IEN4 Interrupt enable bit
     * b5 IEN5 Interrupt enable bit
     * b6 IEN6 Interrupt enable bit
     * b7 IEN7 Interrupt enable bit
     */
    R_BSP_IrqCfgEnable(host_cfg->irq, host_cfg->ipl, host_cfg); /* USBI enable */
}

/******************************************************************************
 * End of function usb_cpu_int_enable
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_cpu_int_disable
 * Description     : USB Interrupt disable
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
void usb_cpu_int_disable (void)
{
    /* Interrupt enable register (USB0 USBIO disable)
     * b0 IEN0 Interrupt enable bit
     * b1 IEN1 Interrupt enable bit
     * b2 IEN2 Interrupt enable bit
     * b3 IEN3 Interrupt enable bit
     * b4 IEN4 Interrupt enable bit
     * b5 IEN5 Interrupt enable bit
     * b6 IEN6 Interrupt enable bit
     * b7 IEN7 Interrupt enable bit
     */
    R_BSP_IrqDisable(host_cfg->irq);   /* USBI enable */
}

/******************************************************************************
 * End of function usb_cpu_int_disable
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_chattaring
 * Description     : Remove chattaring processing
 * Arguments       : uint16_t *syssts : SYSSTS register value
 * Return value    : LNST bit value
 ******************************************************************************/
uint16_t usb_chattaring (uint16_t * syssts)
{
    uint16_t lnst[4];

    /* WAIT_LOOP */
    while (1)
    {
        lnst[0] = (*syssts) & USB_LNST;
        usb_cpu_delay_xms((uint16_t) 1); /* 1ms wait */
        lnst[1] = (*syssts) & USB_LNST;
        usb_cpu_delay_xms((uint16_t) 1); /* 1ms wait */
        lnst[2] = (*syssts) & USB_LNST;
        if ((lnst[0] == lnst[1]) && (lnst[0] == lnst[2]))
        {
            break;
        }
    }

    return lnst[0];
}

/******************************************************************************
 * End of function usb_chattaring
 ******************************************************************************/

#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */

/*******************************************************************************
 * Function Name: usbf_usbi_isr
 * Description  : Interrupt service routine of USBF
 * Arguments    : none
 * Return Value : none
 *******************************************************************************/

void usbf_usbi_isr (void)
{
    /* Call USB interrupt routine */
    if (USB_MODE_HOST == g_usb_usbmode[USB_IP0])
    {
#if ((USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST)
#endif                                 /* (USB_CFG_MODE & USB_CFG_HOST) == USB_CFG_HOST */
    }
    else
    {
#if ((USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_PERI)
        usb_pstd_usb_handler();        /* Call interrupt routine */
#endif  /* (USB_CFG_MODE & USB_CFG_PERI) == USB_CFG_REPI */
    }
}

/******************************************************************************
 * End of function usbfs_usbi_isr
 ******************************************************************************/

#if USB_CFG_DTC == USB_CFG_ENABLE

/******************************************************************************
 * Function Name   : usb_cpu_d0fifo_int_hand
 * Description     : D0FIFO interrupt Handler
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
static void usb_cpu_d0fifo_int_hand (void)
{
    usb_cstd_dma_send_complete(USB_IP0, USB_D0USE);
}

/******************************************************************************
 * End of function usb_cpu_d0fifo_int_hand
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb_cpu_d1fifo_int_hand
 * Description     : D0FIFO interrupt Handler
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
static void usb_cpu_d1fifo_int_hand (void)
{
    usb_cstd_dma_send_complete(USB_IP0, USB_D1USE);
}

/******************************************************************************
 * End of function usb_cpu_d1fifo_int_hand
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb2_cpu_d0fifo_int_hand
 * Description     : D0FIFO interrupt Handler
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
static void usb2_cpu_d0fifo_int_hand (void)
{
    usb_cstd_dma_send_complete(USB_IP1, USB_D0USE);
}

/******************************************************************************
 * End of function usb2_cpu_d0fifo_int_hand
 ******************************************************************************/

/******************************************************************************
 * Function Name   : usb2_cpu_d1fifo_int_hand
 * Description     : D0FIFO interrupt Handler
 * Arguments       : none
 * Return value    : none
 ******************************************************************************/
static void usb2_cpu_d1fifo_int_hand (void)
{
    usb_cstd_dma_send_complete(USB_IP1, USB_D1USE);
}

/******************************************************************************
 * End of function usb2_cpu_d1fifo_int_hand
 ******************************************************************************/
#endif                                 /* USB_CFG_DTC == USB_CFG_ENABLE */

/******************************************************************************
 * Function Name   : usb_check_use_usba_module
 * Description     :
 * Arguments       : usb_utr_t *ptr     : Pointer to usb_utr_t structure
 * Return value    :
 ******************************************************************************/
bool usb_check_use_usba_module (usb_utr_t * ptr)
{
    bool ret_code = false;

    FSP_PARAMETER_NOT_USED(ptr);
    ret_code = true;

    return ret_code;
}                                      /* End of function usb_check_use_usba_module */

void usbf_interrupt_handler (void)
{
    USB_CFG_MULTIPLEX_INTERRUPT_ENABLE;
    usbf_usbi_isr();
    USB_CFG_MULTIPLEX_INTERRUPT_DISABLE;
}

#if  USB_IP_EHCI_OHCI == 1

/***********************************************************************************************************************
 * Function Name: usbh0_ahb_pci_bridge_init
 * Description  :
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
void usb_ahb_pci_bridge_init (void)
{
    USB00->INTENABLE_b.WAKEON_INTEN = 1;
    USB00->INTENABLE_b.UCOM_INTEN   = 1;
    USB00->INTENABLE_b.USBH_INTBEN  = 1;
    USB00->INTENABLE_b.USBH_INTAEN  = 1;
    USB00->INTENABLE_b.AHB_INTEN    = 1;

    USB00->AHBBUSCTR_b.PROT_TYPE     = 0;
    USB00->AHBBUSCTR_b.PROT_MODE     = 0;
    USB00->AHBBUSCTR_b.ALIGN_ADDRESS = 0;
    USB00->AHBBUSCTR_b.MAX_BURST_LEN = 0;
}                                      /* End of function usbh0_ahb_pci_bridge_init() */

#endif  /* USB_IP_EHCI_OHCI == 1 */

/******************************************************************************
 * End  Of File
 ******************************************************************************/
