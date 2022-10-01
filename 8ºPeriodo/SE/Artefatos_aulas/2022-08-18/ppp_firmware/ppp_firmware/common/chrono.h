#ifndef CHRONO_H
#define CHRONO_H

#include "hal.h"

typedef uint32_t chrono;

void ChronoStart(chrono* c, chrono delta_t);
boolean ChronoIsFinished();
#endif // CHRONO_H
