#include "setup.h"
#include "loop.h"

void loop(){
    /*PC13 -- PA4*/
    LED_Active(13, Button(4));

    /*PC14 -- PA5*/
    LED_Active(14, Button(5));

    /*PC15 -- PA6*/
    LED_Active(15, Button(6));
}

