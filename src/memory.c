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

void memory_check(struct memory *memory, uint16_t segment_number);

void memory_read(struct memory *memory, uint32_t addr, int bytes,
        uint8_t *data) {
    uint32_t i;
    for (i = 0; i < bytes; i++) {
        uint16_t segment_number = ((addr + i) & 0xFF00) >> 16;
        uint16_t lower_addr = (addr + i) & 0x00FF;
        memory_check(memory, segment_number);
        data[i] = segment_read(memory->segments[segment_number], lower_addr);
    }
}

void memory_write(struct memory *memory, uint32_t addr, int bytes,
        uint8_t *data) {
    int i;
    for (i = 0; i < bytes; i++) {
        uint16_t segment_number = ((addr + i) & 0xFF00) >> 16;
        uint16_t lower_addr = (addr + i) & 0x00FF;
        memory_check(memory, segment_number);
        segment_write(memory->segments[segment_number], lower_addr, data[i]);
    }
}

void memory_check(struct memory *memory, uint16_t segment_number) {
    if (memory->segments[segment_number] == NULL) {
        memory->segments[segment_number] = segment_new();
    }
}

