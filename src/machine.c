#include "machine.h"

#include <stdlib.h> //calloc

struct machine* machine_new() {
    struct machine *new_machine = calloc(sizeof(struct machine), 1);
    new_machine->memory = memory_new();
    return new_machine;
}

