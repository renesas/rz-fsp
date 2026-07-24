/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef FREERTOS_USB_TASK_H_
#define FREERTOS_USB_TASK_H_
#if (BSP_CFG_RTOS == 1)

/* Azure RTOS */
 #include "tx_api.h"
#endif
#if (BSP_CFG_RTOS == 2)
 #include "r_usb_basic.h"
 #include "FreeRTOS.h"
 #include "task.h"
 #include "queue.h"
#endif
#include "r_usb_typedef.h"

/******************************************************************************
 * Macro definitions
 ******************************************************************************/

/** Size of a queue **/
#define QUEUE_SIZE    (10)

/** USB task's priority **/
#if (BSP_CFG_RTOS == 1)

/* Azure RTOS */
typedef TX_THREAD    rtos_task_id_t;
typedef TX_QUEUE     rtos_mbx_id_t;
typedef TX_BYTE_POOL rtos_mem_id_t;
typedef TX_SEMAPHORE rtos_sem_id_t;
typedef uint32_t     rtos_time_t;

 #define USB_TASK_PRI_BASE    (10)
 #define HCD_TSK_PRI          (USB_TASK_PRI_BASE)
 #define HUB_TSK_PRI          (HCD_TSK_PRI + 2)
 #define MGR_TSK_PRI          (HCD_TSK_PRI + 1)
 #define PCD_TSK_PRI          (USB_TASK_PRI_BASE)
 #define PMSC_TSK_PRI         (PCD_TSK_PRI + 1)
 #define HHID_TSK_PRI         (HCD_TSK_PRI + 2)
 #if defined(USB_CFG_HMSC_USE)
  #define HCD_STACK_SIZE      (2048)
  #define MGR_STACK_SIZE      (2048)
 #else
  #define HCD_STACK_SIZE      (1536 + 1024)
  #define MGR_STACK_SIZE      (1536 + 1024)
 #endif
 #define HUB_STACK_SIZE       (512)
 #define PCD_STACK_SIZE       (1024 * 2)
 #define PMSC_STACK_SIZE      (512)
 #define HCDC_STACK_SIZE      (512)
 #define HHID_STACK_SIZE      (512)

/* Number of Memory Block */
 #define    NUM_OF_BLOCK      (64)

/******************************************************************************
 * Typedef definitions
 ******************************************************************************/
typedef enum e_usb_rtos_err
{
    UsbRtos_Success = 0,               // Successful
    UsbRtos_Err_Init_Mbx,              // Failure of Mailbox Creation
    UsbRtos_Err_Init_Mpl,              // Failure of Memory Pool Creation
    UsbRtos_Err_Init_Tsk,              // Failure of Task Creation
 #if (BSP_CFG_RTOS == 1)
    UsbRtos_Err_Init_Sem,              // Failure of Semaphore Creation
 #endif
    UsbRtos_Err_Delete_Mbx,            // Failure of Mailbox Delete
    UsbRtos_Err_Delete_Mpl,            // Failure of Memory Pool Delete
    UsbRtos_Err_Delete_Tsk,            // Failure of Task Delete
} usb_rtos_err_t;

/******************************************************************************
 * Exported global variables
 ******************************************************************************/
extern rtos_mbx_id_t * g_mbx_table[];
extern rtos_mem_id_t * g_mpl_table[];

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 ******************************************************************************/
usb_rtos_err_t usb_rtos_configuration(void);
usb_rtos_err_t usb_rtos_delete(void);
usb_er_t       usb_hstd_rtos_snd_msg(uint8_t id, usb_msg_t * mess);
usb_er_t       usb_hstd_rtos_rec_msg(uint8_t id, usb_msg_t ** mess, rtos_time_t tm);

#elif (BSP_CFG_RTOS == 2)

/** USB task's priority **/
 #if USB_IP_EHCI_OHCI == 0
  #define HCD_TSK_PRI       (configMAX_PRIORITIES - 1)
 #else
  #define HCI_TSK_PRI       (configMAX_PRIORITIES - 1)
 #endif
 #define HUB_TSK_PRI        (configMAX_PRIORITIES - 3)
 #define MGR_TSK_PRI        (configMAX_PRIORITIES - 2)
 #define PCD_TSK_PRI        (configMAX_PRIORITIES - 1)
 #define PMSC_TSK_PRI       (configMAX_PRIORITIES - 2)
 #define HHID_TSK_PRI       (configMAX_PRIORITIES - 3)

/** USB task stack size in words **/
 #if USB_IP_EHCI_OHCI == 0
  #define HCD_STACK_SIZE    (512)
 #else
  #define HCI_STACK_SIZE    (1536)
 #endif
 #define HUB_STACK_SIZE     (1536)
 #define MGR_STACK_SIZE     (1536)
 #define PCD_STACK_SIZE     (1536)
 #define PMSC_STACK_SIZE    (512)
 #define HCDC_STACK_SIZE    (512)
 #define HHID_STACK_SIZE    (512)

/******************************************************************************
 * Typedef definitions
 ******************************************************************************/
typedef enum e_usb_rtos_err
{
    UsbRtos_Success = 0,               // Successful
    UsbRtos_Err_Init_Mbx,              // Failure of Mailbox Creation
    UsbRtos_Err_Init_Mpl,              // Failure of Memory Pool Creation
    UsbRtos_Err_Init_Tsk,              // Failure of Task Creation
    UsbRtos_Err_Delete_Mbx,            // Failure of Mailbox Delete
    UsbRtos_Err_Delete_Mpl,            // Failure of Memory Pool Delete
    UsbRtos_Err_Delete_Tsk,            // Failure of Task Delete
} usb_rtos_err_t;

typedef TaskHandle_t      rtos_task_id_t;
typedef QueueHandle_t     rtos_mbx_id_t;
typedef QueueHandle_t     rtos_mem_id_t;
typedef SemaphoreHandle_t rtos_sem_id_t;
typedef TickType_t        rtos_time_t;

/******************************************************************************
 * Exported global variables
 ******************************************************************************/
extern QueueHandle_t * g_mbx_table[];
extern QueueHandle_t * g_mpl_table[];

/******************************************************************************
 * Exported global functions (to be accessed by other files)
 ******************************************************************************/
usb_rtos_err_t usb_rtos_configuration(void);
usb_rtos_err_t usb_rtos_delete(void);
usb_er_t       usb_hstd_rtos_snd_msg(uint8_t id, usb_msg_t * mess);
usb_er_t       usb_hstd_rtos_rec_msg(uint8_t id, usb_msg_t ** mess, TickType_t tm);

#endif                                 /* #if (BSP_CFG_RTOS == 2) */
#endif                                 /* FREERTOS_USB_TASK_H_ */
