#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_log.h>
#include "uart_motor.h"
#include "led_pwm.h"

#define JOYSTICK_SAMPLE_PERIOD 20
#define READ_JOYSTICK_WAIT_PERIOD 250

void read_joystick(void* ptr) {
    while(1) {
        uint32_t reading = get_uart_reading();
        uint16_t duty_cycle = get_percentage(reading);
        set_duty_cycle(duty_cycle);
        vTaskDelay(READ_JOYSTICK_WAIT_PERIOD / portTICK_PERIOD_MS); 
    }
}

void app_main(void)
{
    init_uart_config();
    init_led_pwm();

    xTaskCreate(read_joystick, "read_joystick", 8000, NULL, 1, NULL);
}

//idf.py -p /dev/cu.SLAB_USBtoUART flash
//idf.py monitor