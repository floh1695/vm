#include "machine.h"

#include <stdint.h>
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
    uint8_t data;
    uint32_t addr = 0;
    while (1) {
        c = getc(stream);
        data = (uint8_t) c;
        addr++;
        if (c == -1) {
            break;
        }
        memory_write(machine->memory, addr, 1, &data);
    }
}

