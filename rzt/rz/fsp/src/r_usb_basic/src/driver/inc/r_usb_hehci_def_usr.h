/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * File Name    : r_usb_hEhciDefUsr.h
 * Version      : 1.0
 * Description  : EHCI User Define Header
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2017 1.00     First Release
 **********************************************************************************************************************/

#ifndef R_USB_HEHCIDEFUSR_H
#define R_USB_HEHCIDEFUSR_H

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Periodic Frame List Size */
#define USB_EHCI_PFL_SIZE    (256U)    // Minimum specification

// #define USB_EHCI_PFL_SIZE             (512U)
// #define USB_EHCI_PFL_SIZE             (1024U)

/* The maximum number of QH memory resources */
#define USB_EHCI_NUM_QH            (USB_HCI_TRREQ_NUM + USB_HCI_DEVICE_NUM)

/* The maximum number of QTD memory resources */
#define USB_EHCI_NUM_QTD           (64U) // 4 endpoints * 5 devices * 2 port + margin

#if defined(BSP_MCU_GROUP_RZT2L)

/* The maximum number of ITD memory resources */
 #define USB_EHCI_NUM_ITD          (2U)

/* The maximum number of SITD memory resources */
 #define USB_EHCI_NUM_SITD         (2U)

/* Maximum size that can be transed with one micro frame of ITD */
 #define USB_EHCI_ITD_DATA_SIZE    (1U)
#else

/* The maximum number of ITD memory resources */
 #define USB_EHCI_NUM_ITD          (4U)

/* The maximum number of SITD memory resources */
 #define USB_EHCI_NUM_SITD         (4U)

/* Maximum size that can be transed with one micro frame of ITD */
 #define USB_EHCI_ITD_DATA_SIZE    (1024U)
#endif

/* Time-out setting (msec) */
#define USB_EHCI_TIMEOUT           (3000U)

#endif                                 /* R_USB_HEHCIDEFUSR_H */
