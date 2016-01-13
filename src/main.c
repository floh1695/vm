#include <getopt.h> //getopt_long

#include "debug.h"
#include "memory.h"

int main(int argc, char **argv) {
    debug_printf(LL_DEBUG, "Begin Program\n");
    
    int c;
    while (1) {
        // All getopt_long options
        static struct option long_options[] = {
            {"file", required_argument, 0, 'f'}
        };
        
        // Getopt uses this to rememeber its index
        int option_index = 0;
        c = getopt_long(argc, argv, "f:",
                long_options, &option_index);

        if (c == -1) {
            break;
        }

        switch (c) {
            case 'f': // Get another file to feed into memory
                break;
            case '?':
                debug_printf(LL_WARN, "Program exit due to invalid option\n");
                return -1;
            default:
                debug_printf(LL_ERROR, 
                        "Program exit due to an unknown error during argument parsing\n");
                return -1;
        }
    }
    return 0;
}

