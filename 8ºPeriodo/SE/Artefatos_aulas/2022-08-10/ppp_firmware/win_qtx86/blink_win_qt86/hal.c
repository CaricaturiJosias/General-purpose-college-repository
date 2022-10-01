#include <stdio.h>
#include <windows.h>
#include "../../common/behavior.h"

void InitHAL(){

}

void LED1(boolean s){
    if (s)
        printf("1\r\n");
    else
        printf("0\r\n");
}
void Pausa1s(){
    Sleep(1000);
}
