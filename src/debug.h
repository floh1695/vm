#ifndef _DEBUG_H_
#define _DEBUG_H_

#include <stdarg.h> //va_list
#include <stdio.h> //FILE

#define LL_ERROR 1
#define LL_WARN 2
#define LL_INFO 3
#define LL_DEBUG 4

#ifndef DEBUG
#define DEBUG LL_WARN
#endif // DEBUG

int debug_vfprintf(FILE *stream, int log_level, const char *format,
        va_list arg);
int debug_vprintf(int log_level, const char *format, va_list arg);
int debug_fprintf(FILE *stream, int loglevel,
        const char *format, ...);
int debug_printf(int loglevel, const char *format, ...);

#endif // _DEBUG_H_

