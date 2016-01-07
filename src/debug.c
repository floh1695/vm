#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

void debug_printf(const char *format, ...) {
    #if DEBUG
    printf(format);
    #endif // DEBUG
}

#endif // DEBUG_H_
