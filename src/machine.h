#ifndef _MACHINE_H_
#define _MACHINE_H_

#include <stdio.h>

#include "memory.h"
#include "mmu.h"

struct machine {
    struct memory *memory; 
    mmu *memory_manager;
};

struct machine* machine_new();
void machine_free(struct machine *machine);

void machine_load_file_executable(struct machine *machine, FILE *stream);
void machine_load_executable(struct machine *machine, uint8_t *data, 
        int size);

#endif // _MACHINE_H_

