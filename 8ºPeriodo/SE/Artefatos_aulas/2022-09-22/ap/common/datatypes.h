#ifndef DATATYPES_H
#define DATATYPES_H

#ifdef  __WIN32
    #include <stdint.h>
#endif

#ifdef  __AVR
    #include <stdint.h>
#endif

typedef uint8_t boolean;
#define TRUE    1
#define FALSE   0

#endif // DATATYPES_H
