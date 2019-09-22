#include "bluetooth.h"
#include "led_pwm.h"
#include "uart_motor.h"
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#define JOYSTICK_SAMPLE_PERIOD 20
#define READ_JOYSTICK_WAIT_PERIOD 250

void read_joystick(void* ptr)
{
    uint16_t ratio = get_ratio();
    
    while (1) {
        uint16_t reading = get_reading();
        
        uint16_t duty_cycle = get_duty_cycle(reading, ratio);
        set_duty_cycle(duty_cycle);
    }
}

void app_main(void)
{
    init_uart_config();
    init_led_pwm();
    init_bluetooth();

    xTaskCreate(read_joystick, "read_joystick", 8000, NULL, 1, NULL);
}

// idf.py -p /dev/cu.SLAB_USBtoUART flash
// idf.py monitor
