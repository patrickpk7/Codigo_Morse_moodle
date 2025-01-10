
#include <stdio.h>
#include "pico/stdlib.h"

#define led_pin 13 // DEFINIÇÃO DO LED NO GPIO 13
#define tempo1 200 // INTERVALO DE 0,2 SEGUNDOS PARA UM PONTO
#define tempo2 125 // INTERVALO DE 0,125 SEGUNDOS PARA UM TRAÇO

void ponto() // FUNÇÃO PARA UM PONTO
{
    for (int i = 0; i < 3; i++) // ESTRUTURA DE REPETIÇÃO PARA 3 PONTOS SEGUIDOS INDICANDO UM "S"
    {
        gpio_put(led_pin, 1);
        sleep_ms(tempo1);
        gpio_put(led_pin, 0);
        sleep_ms(tempo2);
    }
}

void traco() // FUNÇÃO PARA UM TRAÇO
{
    for (int i = 0; i < 3; i++) // ESTRUTURA DE REPETIÇÃO PARA 3 TRAÇOS SEGUIDOS INDICANDO UM "O"
    {
        gpio_put(led_pin, 1);
        sleep_ms(tempo1*4); // 0,8 SEGUNDOS (4 * 0,2 SEGUNDOS)
        gpio_put(led_pin, 0);
        sleep_ms(tempo2);
    }
}




int main()
{
    stdio_init_all();
    
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    while (1) // LOOP INFINITO PARA TRANSMITIR O CÓDIGO MORSE "SOS"
    {
        ponto();
        sleep_ms(250); // INTERVALO DE 0,25 SEGUNDOS
        traco();
        sleep_ms(250); // INTERVALO DE 0,25 SEGUNDOS
        ponto();
        sleep_ms(3000); // INTERVALO DE 3 SEGUNDOS PARA REINICIAR O CICLO
    }    
    
    
    
   return 0;

    
}
