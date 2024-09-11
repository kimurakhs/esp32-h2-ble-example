#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "driver/gpio.h"

#define LED_GPIO 5

void ledcontrol_set(uint8_t percent)
{
	if (percent == 0) {
	    gpio_set_level(LED_GPIO, 0);
    } else {
	    gpio_set_level(LED_GPIO, 1);
    }
}

void ledcontrol_init(void)
{
   	gpio_config_t ledpin_conf = {
	    .pin_bit_mask = (1ULL << LED_GPIO),
	    .mode = GPIO_MODE_OUTPUT,
	    .pull_up_en = GPIO_PULLUP_DISABLE,
	    .pull_down_en = GPIO_PULLDOWN_DISABLE,
	    .intr_type = GPIO_INTR_DISABLE,
	};
	gpio_config(&ledpin_conf);
	gpio_set_level(LED_GPIO, 1);
}
