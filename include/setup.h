#ifndef SETUP_H
#define SETUP_H

#include <stdint.h>
#include "stm32f103c8t6.h"

#define ON      1
#define OFF     0

void LED_Active(uint32_t ledBit, uint32_t ledState);

int Button(uint32_t buttonBit);

void setup(void);

#endif
