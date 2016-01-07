#include "debug.h"

#define DEBUG_H_

#include <stdio.h> //FILE, fprintf, fclose, fopen, stdout
//#include <string.h> //strcmp

#ifndef LOG_FILE
#define LOG_FILE NULL
#endif // LOG_FILE

char* log_to_char(int log_level);
FILE* get_log_file();

void debug_fprintf(FILE *stream, int log_level,
        const char *format, ...) {
    if (DEBUG >= log_level) {
        fprintf(stream, "%s", log_to_char(log_level));
        fprintf(stream, format);
    }
}

void debug_printf(int log_level, const char *format, ...) {
    FILE* log_file = get_log_file();
    debug_fprintf(log_file, log_level, format);
    if (log_file != stdout) {
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

FILE* get_log_file() { 
    FILE *log_file;
    if (LOG_FILE == NULL) {
        log_file = stdout;
    }
    else {
        log_file = fopen(LOG_FILE, "w");
    }
    return log_file;
}

