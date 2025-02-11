#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdio.h>

#define GPIO_SERVOMOTOR 22
#define LED_RGB 12
#define PWM_FREQ 50
#define PERIOD_US 20000
#define STEP_DELAY 10 


//Configuração do PWM, configurando sua saida, divisor de clock e habilitar o PWM
void configs_pwm(uint gpio){
    gpio_set_function(gpio,GPIO_FUNC_PWM);
    uint get_slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_clkdiv(get_slice_num,64.0);
    pwm_set_enabled(get_slice_num,true);
}

//Função responsável por trabalhar desde a obtenção do slice, cálculo e configuração até a sua definição ao PWM
void define_duty_cycle(uint gpio,uint16_t duty_us){
    uint get_slice_num = pwm_gpio_to_slice_num(gpio);
    uint wrap_value = clock_get_hz(clk_sys)/ (PWM_FREQ * 64); //O wrap é o valor máximo do contador
    pwm_set_wrap(get_slice_num,wrap_value);
    pwm_set_chan_level(get_slice_num,PWM_CHAN_A,(wrap_value*duty_us)/PERIOD_US);
    pwm_set_enabled(get_slice_num, true);
}


int main() {
    stdio_init_all();
    while (true) {
        printf("Hello World PWM");
    }
}