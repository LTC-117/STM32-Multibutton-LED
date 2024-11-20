#include "stm32f103c8t6.h"
#include "setup.h"


void LED_Active(uint32_t ledBit, uint32_t ledState){
    if(ledState == ON){
        //LED ON
        GPIOC->BSRR = (0x1 << ledBit);
    }
    else{
        GPIOC->BSRR = (0x1 << (ledBit + 16));
    }
}


int Button(uint32_t buttonBit){
    if( (GPIOA->IDR & (0x1 << buttonBit)) == 0 ){
        return ON;
    } else{
        return OFF;
    }
}


void setup(){
    //Init RCC for:             GPIOA        GPIOC
    RCC_APB2ENR     |=      ( (0x1 << 2) | (0x1 << 4) );

    /*Output ports config*/

    //PC13 (LED1)
    GPIOC->CRH      &=     ~( 0xF << 20 );
    GPIOC->CRH      |=      ( 0x1 << 20 );

    //PC14 (LED2)
    GPIOC->CRH      &=     ~( 0xF << 24 );
    GPIOC->CRH      |=      ( 0x1 << 24 );

    //PC15 (LED3)
    GPIOC->CRH      &=     ~( 0xF << 28 );
    GPIOC->CRH      |=      ( 0x1 << 28 );

    //PB11 (BUZZER)
    GPIOB->CRH      &=     ~( 0xF << 12);
    GPIOB->CRH      |=      ( 0x1 << 12);

    /*Input ports config*/

    //PA4 (BUTTON1)
    GPIOA->CRL      &=     ~( 0xF << 16 );
    GPIOA->CRL      |=      ( 0x8 << 16 );
    GPIOA->ODR      |=      ( 0x1 <<  4 );

    //PA5 (BUTTON2)
    GPIOA->CRL      &=     ~( 0xF << 20 );
    GPIOA->CRL      |=      ( 0x8 << 20 );
    GPIOA->ODR      |=      ( 0x1 <<  5 );

    //PA6 (BUTTON3)
    GPIOA->CRL      &=     ~( 0xF << 24 );
    GPIOA->CRL      |=      ( 0x8 << 24 );
    GPIOA->ODR      |=      ( 0x1 <<  6 );
}


