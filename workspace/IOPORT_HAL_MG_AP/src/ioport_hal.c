/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/**********************************************************************************************************************
 * The application project demonstrates the typical use of the I/O Port APIs. The application project main thread entry
 * initializes the I/O Port HAL Framework, and periodically reads S4 and S5 user buttons’ pins and writes to LED1,
 * LED2, and LED3 pins.
 **********************************************************************************************************************
 */

#include "hal_data.h"

void ioport_hal (void);

void ioport_hal (void)
{
    /* Variable to help handle error codes from functions */
    ssp_err_t  err;

    /* Variable to store LED information (pins) */
    bsp_leds_t leds;

    /* Get LED information (pins) for this board */
    R_BSP_LedsGet(&leds);

    /* Configure S5 button - enable interrupt and set direction to input.
     * Note: this is actually doubling something that is already done in
     * src/synergy_gen/pin_data.c - just for demonstration purposes. */
    err = g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_05, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_INPUT);
    if (SSP_SUCCESS != err)
    {
        while (1)
        {
        }
    }

    /* Configure S4 button - enable interrupt and set direction to input.
     * Note: this is actually doubling something that is already done in
     * src/synergy_gen/pin_data.c - just for demonstration purposes. */
    err = g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_06, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_INPUT);
    if (SSP_SUCCESS != err)
    {
        while (1)
        {
        }
    }


    //**************************** definir o pino como saída
    err = g_ioport.p_api->pinCfg(IOPORT_PORT_02_PIN_02, IOPORT_CFG_IRQ_ENABLE | IOPORT_CFG_PORT_DIRECTION_OUTPUT);
    if (SSP_SUCCESS != err)
    {
        while (1)
        {
        }
    }




    while (1)
    {
        /* Pin 005 (S5) and 006 (S4) levels read using pinRead() */
        ioport_level_t lvl_pin_s4;
        ioport_level_t lvl_pin_s5;

        /* Variable to store all port 0 pin levels */
        ioport_size_t  port_0_pin_levels;

        /* Pin 005 (S5) and 006 (S4) levels read using portRead() */
        ioport_level_t lvl_port_s5;
        ioport_level_t lvl_port_s4;

        /* SK-S7G2 LED 3 pin level - as a result of pin level comparison */
        ioport_level_t led3_lvl;

        /* Check whether button S4 is pressed or not - save pin 006 level */
        err = g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_06, &lvl_pin_s4);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }

        /* Check whether button S5 is pressed or not - save pin 005 level */
        err = g_ioport.p_api->pinRead(IOPORT_PORT_00_PIN_05, &lvl_pin_s5);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }

        /* Set the level read from S4 button pin (006) to LED 0 pin */
        err = g_ioport.p_api->pinWrite(leds.p_leds[0], lvl_pin_s4);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }

        /* Set the level read from S5 button pin (005) to LED 1 pin */
        err = g_ioport.p_api->pinWrite(leds.p_leds[1], lvl_pin_s5);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }


        //***************************************** definir o nível do led

        err = g_ioport.p_api->pinWrite(IOPORT_PORT_02_PIN_02, lvl_pin_s5);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }


        /*
        ////IOPORT_LEVEL_HIGH
        while(1)
        {
            err = g_ioport.p_api->pinWrite(IOPORT_PORT_02_PIN_02, IOPORT_LEVEL_HIGH);
            if (SSP_SUCCESS != err)
            {
                while (1)
                {
                }
            }

            R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

            err = g_ioport.p_api->pinWrite(IOPORT_PORT_02_PIN_02, IOPORT_LEVEL_LOW);
            if (SSP_SUCCESS != err)
            {
                while (1)
                {
                }
            }

            R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
        }
        */




        /* Read all pins levels on port 0, where pin 000 is the LSB
         * and pin 015 is the MSB, meaning pin 005 is on 5th bit and
         * pin 006 on 6th bit respectively. */
        err = g_ioport.p_api->portRead(IOPORT_PORT_00, &port_0_pin_levels);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }

        /* Extract pin 005 and 006 levels from the port variable */
        lvl_port_s5 = (ioport_level_t)((port_0_pin_levels >> 5) & 0x1);
        lvl_port_s4 = (ioport_level_t)((port_0_pin_levels >> 6) & 0x1);


        /* Set the level of LED3 pin via an EXOR of the S4 / S5 inputs read by portRead() */
        led3_lvl = (lvl_port_s5 ^ lvl_port_s4) ? IOPORT_LEVEL_HIGH : IOPORT_LEVEL_LOW;

        err = g_ioport.p_api->pinWrite(leds.p_leds[2], led3_lvl);
        if (SSP_SUCCESS != err)
        {
            while (1)
            {
            }
        }

        /* Next iteration after 100ms */
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    }
}


