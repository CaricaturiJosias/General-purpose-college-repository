#ifndef sm3_H
#define sm3_H

#include "sm.h"

extern StateMachine sm3;

STATE(sm3_init);
STATE(sm3_v2_on);
STATE(sm3_v2_off);
STATE(sm3_v2_error);

#endif // sm3_H
