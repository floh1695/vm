#include <getopt.h> //getopt_long
#include <stdio.h>

#include "debug.h"
#include "machine.h"
#include "memory.h"

int main(int argc, char **argv) {
    debug_printf(LL_DEBUG, "Begin Program\n");
    
    // All variables used for the option states
    char *executable_file = NULL;
    
    int c;
    int option_index = 0;
    while (optind < argc) {
        // All getopt_long options
        static struct option long_options[] = {
            {"file", required_argument, 0, 'f'}
        };
        // Getopt uses this to rememeber its index
        c = getopt_long(argc, argv, "f:",
                long_options, &option_index);

            switch (c) {
                case 'f': // Get the file to load into memory
                    executable_file = optarg;
                    break;
                case '?':
                    debug_printf(LL_WARN,
                            "Program exit due to invalid option\n");
                    return -1;
                default:
                    debug_printf(LL_ERROR, 
                            "Program exit due to an unknown error during argument parsing\n");
                return -1;
            }
    }

    struct machine *machine = machine_new();
    FILE *fp = fopen(executable_file, "r");
    machine_load_file_executable(machine, fp);
    fclose(fp);
    
    return 0;
}

