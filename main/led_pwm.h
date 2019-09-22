#include "stdint.h"

#define DUTY_RESOLUTION LEDC_TIMER_13_BIT

void init_led_pwm();

uint16_t get_ratio();

uint16_t get_duty_cycle(uint16_t reading, uint16_t ratio);

void set_duty_cycle(uint32_t reading);