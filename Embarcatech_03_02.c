#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_RGB_PIN 12

int main() {
    stdio_init_all();
    while (true) {
        printf("Ola mundo PWM COMMIT");
    }
}