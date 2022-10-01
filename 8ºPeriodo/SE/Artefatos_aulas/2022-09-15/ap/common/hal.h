#ifndef HAL_H
#define HAL_H
#include "datatypes.h"

void InitHAL();
uint32_t Now();

void valvula1(boolean status);
void bomba(boolean status);
boolean s11();
boolean s12();
boolean s21();
boolean s22();
#endif // HAL_H
