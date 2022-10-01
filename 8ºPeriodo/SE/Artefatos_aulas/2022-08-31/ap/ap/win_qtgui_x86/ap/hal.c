#include "../../common/hal.h"
#include <time.h>
boolean pin_v1, pin_bp, pin_s11, pin_s12, pin_s21, pin_s22;

void InitHAL(){
    pin_v1 = FALSE;
    pin_bp = FALSE;
    pin_s11 = FALSE;
    pin_s12 = FALSE;
    pin_s22 = FALSE;
    pin_s21 = FALSE;
}

uint32_t Now(){
    return clock();
}

void valvula1(boolean status){
    pin_v1 = status;
}

boolean s11(){
    return pin_s11;
}

boolean s12(){
    return pin_s12;
}

boolean s21(){
    return pin_s21;
}

boolean s22(){
    return pin_s22;
}

void bomba(boolean status){
    pin_bp = status;
}

