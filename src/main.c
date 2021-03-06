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
            {"file", required_argument, 0, 'f'},
            {"help", no_argument, 0, 'h'}
        };

        // Getopt uses this to rememeber its index
        c = getopt_long(argc, argv, "f:h",
                long_options, &option_index);

            switch (c) {
                case 'f': // Get the file to load into memory
                    executable_file = optarg;
                    break;
                case 'h': // Help message
                    printf("[-f  --file] [file]\n");
                    printf("    load $file into memory to be executed\n");
                    printf("[-h --help]\n");
                    printf("    display this message\n");
                    return 0;
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
    FILE *fp = NULL;
    if (executable_file) {
        fp = fopen(executable_file, "r");
    }
    else {
        debug_printf(LL_INFO,
                "Executble file is NULL\n");
        return 1;
    }
    machine_load_file_executable(machine, fp);
    fclose(fp);
    
    return 0;
}

