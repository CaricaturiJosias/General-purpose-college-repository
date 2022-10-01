#ifndef HAL_H
#define HAL_H
#include "datatypes.h"

extern boolean pin_LED1;

void InitHAL();
void LED1(boolean s);
void Pausa1s();

#endif // HAL_H
