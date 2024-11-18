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
#include <stdint.h>

void setup(){
    //Init RCC for:             GPIOA        GPIOC
    RCC_APB2ENR     |=      ( (0x1 << 2) | (0x1 << 4) );

    /*Output ports config*/

    //PC13
    GPIOC->CRH      &=     ~( 0xF << 20 );
    GPIOC->CRH      |=      ( 0x1 << 20 );
    GPIOC->BSRR     |=      ( 0x1 << 13 );

    //PC14
    GPIOC->CRH      &=     ~( 0xF << 24 );
    GPIOC->CRH      |=      ( 0x1 << 24 );
    GPIOC->BSRR     |=      ( 0x1 << 14 );

    //PC15
    GPIOC->CRH      &=     ~( 0xF << 28 );
    GPIOC->CRH      |=      ( 0x1 << 28 );
    GPIOC->BSRR     |=      ( 0x1 << 15 );

    /*Input ports config*/

    //PA4
    GPIOA->CRL      &=     ~( 0xF << 16 );
    GPIOA->CRL      |=      ( 0x8 << 16 );
    GPIOA->ODR      |=      ( 0x1 <<  4 );

    //PA5
    GPIOA->CRL      &=     ~( 0xF << 20 );
    GPIOA->CRL      |=      ( 0x8 << 20 );
    GPIOA->ODR      |=      ( 0x1 <<  5 );

    //PA6
    GPIOA->CRL      &=     ~( 0xF << 24 );
    GPIOA->CRL      |=      ( 0x8 << 24 );
    GPIOA->ODR      |=      ( 0x1 <<  6 );
}

void loop(){
    /*PC13 -- PA4*/
    if( (GPIOA->IDR & (0X1 << 4)) == 0 ){
        GPIOC->ODR  |=  (0x1 << 13);
    } else{
        GPIOC->ODR  &= ~(0x1 << 13);
    }

    /*PC14 -- PA5*/
    if( (GPIOA->IDR & (0X1 << 5)) == 0 ){
        GPIOC->ODR  |=  (0x1 << 14);
    } else{
        GPIOC->ODR  &= ~(0x1 << 14);
    }

    /*PC15 -- PA6*/
    if( (GPIOA->IDR & (0X1 << 6)) == 0 ){
        GPIOC->ODR  |=  (0x1 << 15);
    } else{
        GPIOC->ODR  &= ~(0x1 << 15);
    }
}

int main(){
    setup();

    while(1){
        loop();
    }

    return 0;
}
