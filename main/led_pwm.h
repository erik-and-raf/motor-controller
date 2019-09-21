#include "stdint.h"

void init_led_pwm();

uint16_t get_percentage(uint32_t reading);

void set_duty_cycle(uint32_t reading);