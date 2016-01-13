#include "memory.h"

#include <stdint.h>
#include <stdlib.h> //calloc

#include "segment.h"

#define SEGMENTS 65536
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

void memory_check(struct memory *memory, uint32_t addr);

void memory_read(struct memory *memory, uint32_t addr, int bytes,
        uint8_t *data) {
    uint32_t i;
    for (i = addr; i < addr + bytes; i++) {
        
    }
}

void memory_write(struct memory *memory, uint32_t addr, int bytes,
        uint8_t *data) {
    
}

void memory_check(struct memory *memory, uint32_t addr) {
    uint16_t index = (addr & 0xFF00) >> 16;
    if (memory->segments[index] == NULL) {
        memory->segments[index] = segment_new();
    }
}

