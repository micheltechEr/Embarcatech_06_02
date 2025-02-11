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

//Função responsável por realizar a movimentação de forma suave

void smooth_effect(){
    //Funcionamento padrão do bloco for, valor inicial;pulse_width deve ser menor ou igual ao valor máximo e o incremento de 5Us
    for(uint16_t pulse_width = 500; pulse_width<=2400;pulse_width+=5){
        define_duty_cycle(GPIO_SERVOMOTOR, pulse_width);
        sleep_ms(10);
    }

    //O mesmo, mas agora voltando do grau máximo ao grau 0

    for (uint16_t pulse_width = 2400; pulse_width >= 500; pulse_width -= 5) {
        define_duty_cycle(GPIO_SERVOMOTOR, pulse_width);
        sleep_ms(10); 
    }
}

//Função de setup, responsável por inicializar e chamar a movimentação do servomotor
void setup_pwm(){
    define_duty_cycle(GPIO_SERVOMOTOR,2400);
    gpio_put(LED_RGB,1);
    sleep_ms(5000);

    define_duty_cycle(GPIO_SERVOMOTOR,1470);
    gpio_put(LED_RGB,0);
    sleep_ms(5000);

    define_duty_cycle(GPIO_SERVOMOTOR,500);
    gpio_put(LED_RGB,1);
    sleep_ms(5000);
    smooth_effect();
}

int main() {
    stdio_init_all();
    gpio_init(LED_RGB);
    gpio_set_dir(LED_RGB,GPIO_OUT);
    configs_pwm(GPIO_SERVOMOTOR);
    while (true) {
       setup_pwm();
    }
}