#include "machine.h"

#include <stdlib.h> //calloc

#include "memory.h"
#include "mmu.h"

struct machine* machine_new() {
    struct machine *new_machine = calloc(sizeof(struct machine), 1);
    new_machine->memory = memory_new();
    new_machine->memory_manager = mmu_init(new_machine->memory);
    return new_machine;
}

