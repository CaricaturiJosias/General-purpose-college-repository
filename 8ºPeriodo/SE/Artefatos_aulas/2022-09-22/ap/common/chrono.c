#include "chrono.h"

void ChronoStart(chrono *c, uint32_t delta){
    *c = Now() + delta;
}

boolean ChronoIsFinished(chrono *c){
    return Now() > *c;
}
