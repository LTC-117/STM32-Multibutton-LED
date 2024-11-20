/*
 * Firmware simples que define 3 pinos como entrada (A4, A5, A6)
 * e outros 3 pinos como saída (C13, C14, C15). O Firmware foi
 * feito com o intuito de fazer com que cada um dos pinos de entrada
 * listados interaja com cada um dos pinos de saída, respectivamente.
 * Os testes para este pequeno programa foram realizados com 3 botões
 * e 3 LEDS.
 * O header usado neste projeto foi feito por mim e pode ser encontrado
 * na pasta include desde mesmo projeto!
 */

#include "stm32f103c8t6.h"
#include "setup.h"
#include <stdint.h>
#include "loop.h"

int main(){
    setup();

    while(1){
        loop();
    }

    return 0;
}
