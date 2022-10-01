#include "sm3.h"
#include "hal.h"
#include "chrono.h"
#include "definitions.h"

StateMachine sm3;
chrono sm3_chrono;

STATE(sm3_init){
    if(ENTRY)
        valvula2(FALSE);
    if (s21()){
        if (!s32())
            NEXT_STATE(sm3_v2_on);
        else{
            if (!s31())
                if (s32())
                    NEXT_STATE(sm3_v2_error);
                else
                    NEXT_STATE(sm3_v2_off);
        }
    }
    else if (s22())
        NEXT_STATE(sm3_v2_error);
    else
        NEXT_STATE(sm3_v2_off);
}

STATE(sm3_v2_on){
    if(ENTRY)
        valvula2(TRUE);
    if ((!s21() && s22()) || (s32() && !s31())){
        NEXT_STATE(sm3_v2_error);
    } else {
        if(!s21() || (s31() && s32()))
            NEXT_STATE(sm3_v2_off);
    }
}

STATE(sm3_v2_off){
    if(ENTRY){
        ChronoStart(&sm3_chrono, SM3_TIME_MS);
        valvula2(FALSE);
    }
    if ((!s21() && s22()) || (s32() && !s31()))
        NEXT_STATE(sm3_v2_error);
    else {
        if (!s32() && s21()){
            if (ChronoIsFinished(&sm3_chrono))
                NEXT_STATE(sm3_v2_on);
        }
    }
}

STATE(sm3_v2_error){
    if(ENTRY){
        valvula2(FALSE);
    }
}
