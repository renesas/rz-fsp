/*
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "bsp_api.h"
#include "r_rsip_otp.h"

/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/* Write size at one time */
#if 1 == BSP_FEATURE_RSIP_OTP_ADDRESS_SPACE
 #define RSIP_PRV_OTP_ACCESS_SIZE      (2U)
 #define RSIP_PRV_OTP_ADDR_WHUK        (0x100U)
 #define RSIP_PRV_OTP_ADDR_WHRK        (0x118U)
#elif 2 == BSP_FEATURE_RSIP_OTP_ADDRESS_SPACE
 #define RSIP_PRV_OTP_ACCESS_SIZE      (4U)
 #define RSIP_PRV_OTP_ADDR_WHUK        (0x160U)
 #define RSIP_PRV_OTP_ADDR_WHRK        (0x16CU)
#else
 #error Unknown device.
#endif

#define RSIP_PRV_BYTE_SIZE_WHUK        (RSIP_PRV_WORD_SIZE_WHUK << 2)
#define RSIP_PRV_BYTE_SIZE_WHRK        (RSIP_PRV_WORD_SIZE_WHRK << 2)
#define RSIP_PRV_BYTE_SIZE_WHRK_NUM    (RSIP_PRV_WORD_SIZE_WHRK_NUM << 2)

#define RSIP_PRV_OTP_ADDR_WHRK_NUM     (RSIP_PRV_OTP_ADDR_WHRK + (RSIP_PRV_BYTE_SIZE_WHRK / RSIP_PRV_OTP_ACCESS_SIZE))

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Private function prototypes
 **********************************************************************************************************************/

static void       otp_power_state_get(uint8_t * p_power);
static uint8_t    otp_data_read(uint16_t otp_addr, void * p_data);
static rsip_ret_t otp_power_on_and_read(uint16_t addr, uint8_t * p_data, uint8_t bytes);

/***********************************************************************************************************************
 * Private global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * OTP power on.
 *
 * @retval 0   Success
 * @retval 1   Failure
 **********************************************************************************************************************/
uint8_t r_rsip_otp_power_on (void)
{
    /* Confirm that CMD_RDY bit of the OTP access status register (OTPSTR.CMD_RDY) is 1. */
    if (0U == R_OTP->OTPSTR_b.CMD_RDY)
    {
        /* Confirm completion of the power-down process. */
        if (1U == R_OTP->OTPPWR_b.PWR)
        {
            return 1U;
        }
    }

    /* Set the PWR and ACCL bits of the OTP Power Control Register. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;

    return 0U;
}

/*******************************************************************************************************************//**
 * OTP power off.
 **********************************************************************************************************************/
void r_rsip_otp_power_off (void)
{
    /* Set the PWR and ACCL bits to 0, and wait until CMD_RDY bit is set to 0. */
    R_OTP->OTPPWR = ~(uint32_t) (R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk);

    while (1)
    {
        if (0U == R_OTP->OTPSTR_b.CMD_RDY)
        {
            break;
        }
    }
}

/*******************************************************************************************************************//**
 * Read to the OTP area in 16/32-bit units.
 *
 * @param[in]  addr           Read destination address
 * @param[out] p_data         Data
 * @param[in]  data_len       Data length
 *
 * @retval 0   Success
 * @retval 1   Failure
 **********************************************************************************************************************/
uint8_t r_rsip_otp_multiple_data_read (uint16_t addr, uint8_t * p_data, uint8_t data_len)
{
    uint8_t  ret      = 0U;
    uint32_t comp_len = 0U;

    /* Check if the size is in 16/32-bit units. */
    if (0U != (data_len % RSIP_PRV_OTP_ACCESS_SIZE))
    {
        return 1U;
    }

    /* Read the data in 16/32-bit units. */
    while (comp_len < data_len)
    {
        uint32_t read_data = 0U;

        /* Read data. */
        uint8_t read_ret = otp_data_read(addr, &read_data);

        if (0U != read_ret)
        {
            ret = 1U;
            break;
        }

        memcpy(p_data + comp_len, &read_data, RSIP_PRV_OTP_ACCESS_SIZE);
        comp_len += RSIP_PRV_OTP_ACCESS_SIZE;
        addr++;
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Read W-HUK in OTP.
 *
 * @param[out] whuk W-HUK
 *
 * @retval RSIP_RET_PASS Success
 * @retval RSIP_RET_FAIL Failure
 **********************************************************************************************************************/
rsip_ret_t r_rsip_whuk_read (uint32_t whuk[RSIP_PRV_WORD_SIZE_WHUK])
{
    uint8_t err = otp_power_on_and_read(RSIP_PRV_OTP_ADDR_WHUK, (uint8_t *) whuk, RSIP_PRV_BYTE_SIZE_WHUK);

    /* Check error */
    return (0U == err) ? RSIP_RET_PASS : RSIP_RET_FAIL;
}

/*******************************************************************************************************************//**
 * Read W-HRK in OTP.
 *
 * @param[out] whrk_num W-HUK number
 * @param[out] whrk     W-HUK
 *
 * @retval RSIP_RET_PASS Success
 * @retval RSIP_RET_FAIL Failure
 **********************************************************************************************************************/
rsip_ret_t r_rsip_whrk_read (uint32_t whrk_num[RSIP_PRV_WORD_SIZE_WHRK_NUM], uint32_t whrk[RSIP_PRV_WORD_SIZE_WHRK])
{
    uint8_t err = 1U;

    err = otp_power_on_and_read(RSIP_PRV_OTP_ADDR_WHRK, (uint8_t *) whrk, RSIP_PRV_BYTE_SIZE_WHRK);

    if (0 == err)
    {
        err = otp_power_on_and_read(RSIP_PRV_OTP_ADDR_WHRK_NUM, (uint8_t *) whrk_num, RSIP_PRV_BYTE_SIZE_WHRK_NUM);
    }

    /* Check error */
    return (0U == err) ? RSIP_RET_PASS : RSIP_RET_FAIL;
}

/***********************************************************************************************************************
 * Private Functions
 **********************************************************************************************************************/

/*******************************************************************************************************************//**
 * Check OTP power.
 *
 * @param[out] p_power        0: Off, 1: On
 **********************************************************************************************************************/
static void otp_power_state_get (uint8_t * p_power)
{
    *p_power = R_OTP->OTPPWR_b.PWR;
}

/*******************************************************************************************************************//**
 * Read 16-bit of data from OTP.
 *
 * @param[in]  otp_addr       Read address
 * @param[out] p_data         Read data storage destination
 *
 * @retval 0   Success
 * @retval 1   Failure
 **********************************************************************************************************************/
static uint8_t otp_data_read (uint16_t otp_addr, void * p_data)
{
    uint8_t ret = 0U;

    /* Confirm that CMD_RDY bit of the OTP access status register (OTPSTR.CMD_RDY) is 1. */
    while (0U == R_OTP->OTPSTR_b.CMD_RDY)
    {
        /* Waiting */
    }

    /* Set the PWR and ACCL bits of the OTP Power Control Register. */
    R_OTP->OTPPWR = R_OTP_OTPPWR_PWR_Msk | R_OTP_OTPPWR_ACCL_Msk;

    /* Set the read address to the OTP Read Address Register. */
    R_OTP->OTPADRRD = otp_addr;

    /* Read the OTP Read Data Register. */
#if RSIP_PRV_OTP_ACCESS_SIZE == 2U
    *((uint16_t *) p_data) = R_OTP->OTPDATARD_b.DATARD;
#elif RSIP_PRV_OTP_ACCESS_SIZE == 4U
    *((uint32_t *) p_data) = R_OTP->OTPDATARD_b.DATARD;
#else
 #error Unknown definition.
#endif

    /* Poll the CMD_RDY bit until changing to 1 in order to detect the completion of the write command. */
    while (1)
    {
        if (1U == R_OTP->OTPSTR_b.CMD_RDY)
        {
            break;
        }
    }

    /* Check OTP read error. */
    if (0U != R_OTP->OTPSTR_b.ERR_RP)
    {
        ret = 1U;
    }

    if (0U != R_OTP->OTPSTR_b.ERR_RDY_RD)
    {
        ret = 1U;
        R_OTP->OTPSTR_b.ERR_RDY_RD = 0U;
    }

    return ret;
}

/*******************************************************************************************************************//**
 * Read to the OTP area in 16/32-bit units.
 *
 * @param[in]  addr           Read destination address
 * @param[out] p_data         Data
 * @param[in]  bytes          Data length
 *
 * @retval RSIP_RET_PASS Success
 * @retval RSIP_RET_FAIL Failure
 **********************************************************************************************************************/
static rsip_ret_t otp_power_on_and_read (uint16_t addr, uint8_t * p_data, uint8_t bytes)
{
    uint8_t err               = 1U;
    uint8_t otp_initial_power = 0U;

    otp_power_state_get(&otp_initial_power);

    /* Power on OTP if it is off */
    if (0U == otp_initial_power)
    {
        err = r_rsip_otp_power_on();
    }
    else
    {
        err = 0U;
    }

    /* Read OTP */
    if (0U == err)
    {
        err = r_rsip_otp_multiple_data_read(addr, p_data, bytes);
    }

    /* Power off OTP if it is off in the initial state */
    if (0U == otp_initial_power)
    {
        r_rsip_otp_power_off();
    }

    /* Check error */
    return (0U == err) ? RSIP_RET_PASS : RSIP_RET_FAIL;
}
