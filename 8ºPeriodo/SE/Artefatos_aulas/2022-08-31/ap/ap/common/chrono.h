#ifndef CHRONO_H
#define CHRONO_H

#include "hal.h"

typedef uint32_t chrono;

void ChronoStart(chrono *c, uint32_t delta);
boolean ChronoIsFinished(chrono *c);

#endif // CHRONO_H
