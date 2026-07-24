/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef R_ERROR_CODES_H
#define R_ERROR_CODES_H

/* Note: Only put #defines in this file as it is used in assembler and C code */

/***********************************************************************************************************************
 * Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/*--------------- Definitions of Boot Error Return Value ---------------------*/

#define D_BOOT_OK                         (0x078787a8) /* Successful operation */
#define D_BOOT_ERR                        (0x079d51d7) /* Fail - boot mode or general error */
#define D_BOOT_ERR_PARAM_CHECKSUM         (0x07e8ba4b) /* Fail - parameter checksum error */
#define D_BOOT_ERR_PARAM_ADDRESS          (0x0be34e75) /* Fail - parameter address error */
#define D_BOOT_ERR_COMMS                  (0x198df824) /* Fail - USB or SCIF communication error */
#define D_BOOT_ERR_S_RECORD               (0x19b2b1f9) /* Fail - S-record format error */

#define D_BOOT_ERR_UNDEFINED_EXCEPTION    (0x19f80786) /* Fail - undefined instruction exception occurred  */
#define D_BOOT_ERR_SVC_EXCEPTION          (0x1e1e664d) /* Fail - SVC exception occurred  */
#define D_BOOT_ERR_PREFETCH_EXCEPTION     (0x1e2e1ab2) /* Fail - prefetch exception occurred  */
#define D_BOOT_ERR_ABORT_EXCEPTION        (0x2acce4bb) /* Fail - abort exception occurred  */
#define D_BOOT_ERR_IRQ_EXCEPTION          (0x2b56590a) /* Fail - IRQ exception occurred  */
#define D_BOOT_ERR_FIQ_EXCEPTION          (0x2cb52b2f) /* Fail - FIQ exception occurred  */
#define D_BOOT_ERR_INVALID_MODE           (0x2ccb3550) /* Fail - device is in invalid CPU mode  */

#define D_BOOT_ERR_INVALID_PACKAGE        (0x356562d8) /* Fail - boot mode not supported by package */

/***********************************************************************************************************************
 * Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * Exported global functions (to be accessed by other files)
 ***********************************************************************************************************************/

#endif                                 /* R_ERROR_CODES_H */
