#include "debug.h"

#define DEBUG_H_

#include <stdarg.h> //va_list
#include <stdio.h> //FILE, fprintf, fclose, fopen, stdout

#ifndef LOG_FILE
#define LOG_FILE NULL
#endif // LOG_FILE

char* log_to_char(int log_level);
FILE* get_log_file();

FILE *log_file = NULL;

int debug_vfprintf(FILE *stream, int log_level, const char *format, 
        va_list arg) {
    int wrote = 0;
    if (stream == NULL) {
        stream = get_log_file();
    }
    if (DEBUG >= log_level) {
        wrote += fprintf(stream, "%s", log_to_char(log_level));
        wrote += vfprintf(stream, format, arg);
    }
    return wrote;
}

int debug_vprintf(int log_level, const char *format, va_list arg) {
    return debug_vfprintf(NULL, log_level, format, arg);
}

int debug_fprintf(FILE *stream, int log_level,
        const char *format, ...) {
    va_list args;
    va_start(args, format);
    int wrote = debug_vfprintf(stream, log_level, format, args);
    va_end(args);
    return wrote;
}

int debug_printf(int log_level, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int wrote = debug_vfprintf(log_file, log_level, format, args);
    va_end(args);
    return wrote;
}

char* log_to_char(int log_level) {
    switch (log_level) {
        case LL_ERROR:
            return "ERR:";
        case LL_WARN:
            return "WAR:";
        case LL_INFO:
            return "INF:";
        case LL_DEBUG:
            return "DBG:";
        default:
            return "???:";
    }
}

FILE* get_log_file() { 
    if (log_file != NULL) {
        return log_file;
    }
    if (LOG_FILE == NULL) {
        log_file = stdout;
    }
    else {
        log_file = fopen(LOG_FILE, "w");
    }
    return log_file;
}

