#include "memory.h"

#include <stdlib.h> //calloc

#include "segment.h"

#define SEGMENTS 256
struct memory {
    struct segment *segments[SEGMENTS];
};

struct memory* memory_new() {
    struct memory *new_memory = calloc(sizeof(struct memory), 1);
    int i;
    for (i = 0; i < SEGMENTS; i++) {
        new_memory->segments[i] = NULL;
    }
    return new_memory;
}

