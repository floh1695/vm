#include "memory.h"

#include <stdint.h>
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

uint8_t* memory_read(int bytes) {
    
}

void memory_write(int bytes, uint8_t *data) {
    
}

