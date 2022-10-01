#ifndef SM2_H
#define SM2_H

#include "sm.h"

extern StateMachine sm2;

STATE(sm2_init);
STATE(sm2_bp_on);
STATE(sm2_bp_off);
STATE(sm2_bp_error);

#endif // SM2_H
