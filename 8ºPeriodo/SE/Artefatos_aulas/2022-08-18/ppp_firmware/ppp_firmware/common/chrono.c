#include "../../common/chrono.h"

void ChronoStart(chrono * c, chrono delta_t){
    c += Now()+delta_t;
}
boolean ChronoIsFinished(chrono * c){
    return (Now() >= *c);
}
