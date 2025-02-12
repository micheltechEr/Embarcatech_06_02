# Controle de Servomotor por PWM - Raspberry Pi Pico
## Descrição do Projeto
Este projeto foi desenvolvido para praticar o uso de **PWM (Pulse Width Modulation)** no controle de um servomotor e um LED RGB. O objetivo é demonstrar como configurar e gerenciar sinais PWM para controlar a posição de um servomotor e alternar o estado de um LED RGB.

O código utiliza as bibliotecas `pico/stdlib.h` e `hardware/pwm.h` para configurar o PWM nos pinos GPIO especificados. O servomotor é controlado através de variações no ciclo de trabalho (duty cycle), enquanto o LED RGB é usado para indicar diferentes estados do sistema.

Para assistir o vídeo, [clique aqui](https://drive.google.com/file/d/1aVixHrtmPYqcj5t81KJATaiBlj9ZR9wB/view?usp=sharing)

---
## Componentes Utilizados
- **Servomotor (Pino 22):** Controlado via PWM para realizar movimentos suaves entre ângulos específicos.
- **LED RGB (Pino 12):** Usado como indicador visual para diferentes estados do sistema.
- **Raspberry Pi Pico:** Placa utilizada para executar o código.
- **Resistores (opcional):** Para proteger o LED RGB, recomenda-se o uso de resistores limitadores de corrente (ex.: 220Ω ou 330Ω).

---
## Funcionalidades do Projeto
- **Movimentação Suave do Servomotor:**
  - O servomotor realiza uma transição suave entre os ângulos mínimos e máximos, com incrementos graduais no duty cycle.
- **Indicação Visual com LED RGB:**
  - O LED RGB é ligado e desligado em sincronia com as posições do servomotor, indicando diferentes estados do sistema.
- **Configuração de PWM:**
  - O PWM é configurado com uma frequência de 50 Hz (padrão para servomotores) e um período de 20 ms.

---
## Guia de Funcionamento na Sua Máquina
Para executar este projeto localmente, siga as instruções abaixo:
### 1. **Clone o repositório:**
   - Abra o **VS Code** e clone este repositório para sua máquina.
### 2. **Importe o projeto:**
   - Certifique-se de ter as extensões do **Raspberry Pi Pico** instaladas no VS Code.
   - Importe o projeto para poder compilá-lo e executá-lo na placa RP2040.
### 3. **Compile o código:**
   - Compile o código diretamente no VS Code.
### 4. **Simulação no Wokwi:**
   - Para simular o projeto, abra o arquivo `diagram.json` disponível nos arquivos do projeto e execute-o no [Wokwi](https://wokwi.com).
### 5. **Conecte a placa:** (Não é necessário para visualização do servomotor)
   - Conecte a placa ao computador via USB e coloque-a no modo **BOOTSEL**.
### 6. **Execute na placa:** (Não é necessário para visualização do servomotor)
   - A visualização na placa, sem o servomotor, é notável através do LED RGB, verificar seu comportamento ao conectar e testar.

---
## Funcionamento do Sistema
O sistema funciona da seguinte forma:
1. **Estado Inicial:**
   - O servomotor está posicionado no ângulo máximo (2400 µs).
   - O LED RGB está ligado.
2. **Primeira Transição:**
   - Após 5 segundos, o servomotor move-se para o ângulo médio (1470 µs).
   - O LED RGB é desligado.
3. **Segunda Transição:**
   - Após mais 5 segundos, o servomotor move-se para o ângulo mínimo (500 µs).
   - O LED RGB é ligado novamente.
4. **Movimento Suave:**
   - O servomotor realiza uma transição suave entre os ângulos mínimo e máximo, com incrementos graduais no duty cycle.

---
## Código Fonte
O código fonte está organizado da seguinte forma:
- **Função `configs_pwm`:** Configura o pino GPIO para funcionar como saída PWM, define o divisor de clock e habilita o PWM.
- **Função `define_duty_cycle`:** Calcula e configura o duty cycle para o PWM, ajustando a posição do servomotor.
- **Função `smooth_effect`:** Realiza a movimentação suave do servomotor entre os ângulos mínimo e máximo.
- **Função `setup_pwm`:** Define as posições iniciais do servomotor e controla o LED RGB.
- **Loop Principal (`main`):** Executa continuamente a função `setup_pwm`.

---
## Observações Finais
Este projeto foi desenvolvido com foco em boas práticas de programação, organização e documentação. Ele é ideal para estudantes que desejam praticar o uso de PWM no controle de servomotores e LEDs.

Caso tenha dúvidas ou sugestões, sinta-se à vontade para abrir uma **issue** ou entrar em contato.

---
### Créditos
- **Autor:** Ângelo Miguel Ribeiro Cerqueira Lima
- **Data:** 06/02

---
