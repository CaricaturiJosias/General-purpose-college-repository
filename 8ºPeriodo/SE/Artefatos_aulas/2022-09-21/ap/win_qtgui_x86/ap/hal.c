#include "../../common/hal.h"
#include <time.h>
boolean pin_v1, pin_v2, pin_bp, pin_r, pin_s11, pin_s12, pin_s21, pin_s22, pin_s31, pin_s32, pin_sr, pin_s1_e, pin_s2_e, pin_s3_e, histerese;

void InitHAL(){
    pin_v1 = FALSE;
    pin_bp = FALSE;
    pin_s11 = FALSE;
    pin_s12 = FALSE;
    pin_s22 = FALSE;
    pin_s21 = FALSE;
    pin_s32 = FALSE;
    pin_s31 = FALSE;
    pin_sr  = FALSE;
    pin_s2_e = FALSE;
    pin_s1_e = FALSE;
    pin_s3_e = FALSE;
    histerese = FALSE;
}

uint32_t Now(){
    return clock();
}

void valvula1(boolean status){
    pin_v1 = status;
}

void valvula2(boolean status){
    pin_v2 = status;
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

boolean s31(){
    return pin_s31;
}

boolean s32(){
    return pin_s32;
}

boolean sr(){
    return pin_sr;
}

void bomba(boolean status){
    pin_bp = status;
}

void aquecimento(boolean status){
    pin_r = status;
}

