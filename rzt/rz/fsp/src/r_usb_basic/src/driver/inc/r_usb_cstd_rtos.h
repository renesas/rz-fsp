/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "r_usb_basic.h"
#include "r_usb_typedef.h"
#if (BSP_CFG_RTOS == 2)
 #include "FreeRTOS.h"
 #include "task.h"
 #include "queue.h"



 #ifndef FREERTOS_USB_TASK_H_
  #define FREERTOS_USB_TASK_H_

/******************************************************************************
 * Macro definitions
 ******************************************************************************/

/** Size of a queue **/
  #define QUEUE_SIZE         (10)

  #if (BSP_CFG_RTOS == 2)
typedef TaskHandle_t      rtos_task_id_t;
typedef QueueHandle_t     rtos_mbx_id_t;
typedef QueueHandle_t     rtos_mem_id_t;
typedef SemaphoreHandle_t rtos_sem_id_t;
typedef TickType_t        rtos_time_t;
  #endif /* (BSP_CFG_RTOS == 2) */
  
/** USB task's priority **/
  #define HCI_TSK_PRI        (configMAX_PRIORITIES - 1)
  #define HUB_TSK_PRI        (configMAX_PRIORITIES - 3)
  #define MGR_TSK_PRI        (configMAX_PRIORITIES - 2)
  #define PCD_TSK_PRI        (configMAX_PRIORITIES - 1)
  #define PMSC_TSK_PRI       (configMAX_PRIORITIES - 2)
  #define HHID_TSK_PRI       (configMAX_PRIORITIES - 3)

/** USB task stack size in words **/
  #define HCI_STACK_SIZE     (1536)
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
usb_er_t       usb_hstd_rtos_rec_msg(uint8_t id, usb_msg_t ** mess, TickType_t tm);

 #endif
#endif                                 /* FREERTOS_USB_TASK_H_ */
