/* HAL-only entry function */
#include "hal_data.h"
void hal_entry(void)
{
    bsp_leds_t Leds;
    R_BSP_LedsGet (&Leds);

    while(1)
    {
        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED1], IOPORT_LEVEL_LOW);
        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED2], IOPORT_LEVEL_LOW);
        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED3], IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED1], IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED2], IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED3], IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED1], IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED2], IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED3], IOPORT_LEVEL_LOW);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);

        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED1], IOPORT_LEVEL_HIGH);
        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED2], IOPORT_LEVEL_HIGH);
        g_ioport.p_api->pinWrite(Leds.p_leds[BSP_LED_LED3], IOPORT_LEVEL_HIGH);
        R_BSP_SoftwareDelay(BSP_DELAY_UNITS_SECONDS, 1);
    }
}
