#include "../../common/hal.h"
#include <windows.h>
#include <time.h>
boolean pin_LED1;

void InitHAL(){
    pin_LED1 = FALSE;
}

void LED1(boolean s){
    pin_LED1 = s;
}


void Pausa1s(){
    Sleep(1000);
}

uint32_t Now(){
    return clock();
}
