#include "sm1.h"
#include "hal.h"
#include "chrono.h"
#include "definitions.h"

StateMachine sm1;
chrono sm1_chrono;

STATE(sm1_init){
    if(s12()){
        if(s11())
            NEXT_STATE(sm1_v1_off);
        else
            NEXT_STATE(sm1_v1_error);
    }else
        NEXT_STATE(sm1_v1_on);
}

STATE(sm1_v1_on){
    if(ENTRY)
        valvula1(TRUE);
    if(s12()){
        if(s11())
            NEXT_STATE(sm1_v1_off);
        else
            NEXT_STATE(sm1_v1_error);
    }
}

STATE(sm1_v1_off){
    if(ENTRY){
        ChronoStart(&sm1_chrono, SM1_TIME_MS);
        valvula1(FALSE);
    }
    if(s12()){
        if(!s11())
            NEXT_STATE(sm1_v1_error);
    } else {
        if (ChronoIsFinished(&sm1_chrono))
            NEXT_STATE(sm1_v1_on);
    }
}

STATE(sm1_v1_error){
    if(ENTRY)
        valvula1(FALSE);
}
