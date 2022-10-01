#include "../../common/hal.h"
#include <windows.h>
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
