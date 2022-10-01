#include "sm4.h"
#include "hal.h"
#include "chrono.h"
#include "definitions.h"

StateMachine sm4;
chrono sm4_chrono;

STATE(sm4_init){
    if(ENTRY)
        aquecimento(FALSE);

    if ((!s21() && s22()) || (s32() && !s31()))
        NEXT_STATE(sm4_r_error);
    else if (s31())
        NEXT_STATE(sm4_r_on);
    else
        NEXT_STATE(sm4_r_off);
}

STATE(sm4_r_on){
    if(ENTRY)
        aquecimento(TRUE);
    if ((!s21() && s22()) || (s32() && !s31()))
        NEXT_STATE(sm4_r_error);
     else {
        if(!s31())
            NEXT_STATE(sm4_r_off);
    }
}

STATE(sm4_r_off){
    if(ENTRY){
        aquecimento(FALSE);
    }
    if ((!s21() && s32()) || (s32() && !s31()))
        NEXT_STATE(sm4_r_error);

    else {
        if (s31())
            NEXT_STATE(sm4_r_on);
    }
}

STATE(sm4_r_error){
    if(ENTRY){
        aquecimento(FALSE);
    }
}
