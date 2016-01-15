#include "machine.h"

#include <stdio.h> //FILE
#include <stdlib.h> //calloc

#include "memory.h"
#include "mmu.h"

struct machine* machine_new() {
    struct machine *new_machine = calloc(sizeof(struct machine), 1);
    new_machine->memory = memory_new();
    new_machine->memory_manager = mmu_init(new_machine->memory);
    return new_machine;
}

void machine_free(struct machine *machine) {
    //TODO: Actually free memory here
}

void machine_load_file_executable(struct machine *machine, FILE *stream) {
    int c;
    while (1) {
        //fread(&c, 1, 1, FILE);
        c = getc(stream);
        if (c == -1) {
            break;
        }
        putchar(c);
    }
}

void machine_load_executable(struct machine *machine, uint8_t *data, 
        int size) {
    
}

