#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    while (true) {
        printf("Hello World PWM");
    }
}