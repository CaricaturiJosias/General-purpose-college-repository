#include "sm2.h"
#include "hal.h"
#include "chrono.h"
#include "definitions.h"

StateMachine sm2;
chrono sm2_chrono;

STATE(sm2_init){
    if(ENTRY)
        bomba(FALSE);
    if (s11()){
        if (!s22())
            NEXT_STATE(sm2_bp_on);
        else{
            if (!s21())
                NEXT_STATE(sm2_bp_error);
            else
                NEXT_STATE(sm2_bp_off);
        }
    }
    else
        NEXT_STATE(sm2_bp_off);
}

STATE(sm2_bp_on){
    if(ENTRY)
        bomba(TRUE);
    if ((!s11() && s12()) || (s22() && !s21())){
        NEXT_STATE(sm2_bp_error);
    } else {
        if(!s11() || (s21() && s22()))
            NEXT_STATE(sm2_bp_off);
    }
}

STATE(sm2_bp_off){
    if(ENTRY){
        ChronoStart(&sm2_chrono, SM2_TIME_MS);
        bomba(FALSE);
    }
    if ((!s11() && s12()) || (s22() && !s21()))
        NEXT_STATE(sm2_bp_error);
    else {
        if (!s22() && s11()){
            if (ChronoIsFinished(&sm2_chrono))
                NEXT_STATE(sm2_bp_on);
        }
    }
}

STATE(sm2_bp_error){
    if(ENTRY)
        bomba(FALSE);
}
