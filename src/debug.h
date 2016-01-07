#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h> //FILE

#define LL_ERROR 1
#define LL_WARN 2
#define LL_INFO 3
#define LL_DEBUG 4

#ifndef DEBUG
#define DEBUG LL_ERROR
#endif // DEBUG

void debug_fprintf(FILE *stream, int loglevel,
        const char *format, ...);
void debug_printf(int loglevel, const char *format, ...);

#endif // DEBUG_H_

