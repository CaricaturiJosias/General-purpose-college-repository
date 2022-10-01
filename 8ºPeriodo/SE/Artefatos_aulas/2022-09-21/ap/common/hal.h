#ifndef HAL_H
#define HAL_H
#include "datatypes.h"

void InitHAL();
uint32_t Now();

void valvula1(boolean status);
void valvula2(boolean status);
void bomba(boolean status);
void aquecimento(boolean status);

boolean s11();
boolean s12();
boolean s21();
boolean s22();
boolean s31();
boolean s32();
boolean sr();
#endif // HAL_H
