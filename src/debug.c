#include "debug.h"

#define DEBUG_H_

#include <stdio.h> //FILE, fprintf, fclose, fopen, stdout

char* log_to_char(int log_level);

void debug_fprintf(FILE *stream, int log_level,
        const char *format, ...) {
    if (DEBUG >= log_level) {
        fprintf(stream, "%s", log_to_char(log_level));
        fprintf(stream, format);
    }
}

void debug_printf(int log_level, const char *format, ...) {
    if (DEBUG >= log_level) {
        #ifndef LOG_FILE
        FILE *log_file = stdout;
        #else
        FILE *log_file = fopen(LOG_FILE, "w");
        #endif // LOG_FILE 
        debug_fprintf(log_file, log_level, format);
        fclose(log_file);
    }
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

