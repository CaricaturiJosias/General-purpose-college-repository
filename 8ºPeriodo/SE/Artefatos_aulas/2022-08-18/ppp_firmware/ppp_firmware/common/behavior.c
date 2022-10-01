#include "hal.h"
#include "behavior.h"

void behavior(){
    InitHAL();
    while(1){
        LED1(TRUE);
        Pausa1s();
        LED1(FALSE);
        Pausa1s();
    }
}
