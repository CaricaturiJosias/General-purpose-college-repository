#ifndef sm4_H
#define sm4_H

#include "sm.h"

extern StateMachine sm4;

STATE(sm4_init);
STATE(sm4_r_on);
STATE(sm4_r_off);
STATE(sm4_r_error);

#endif // sm4_H
