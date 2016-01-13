#include "segment.h"

#include <stdint.h>
#include <stdlib.h>

#define PAGE_BYTES 256
struct page {
    uint8_t bytes[PAGE_BYTES];
};

#define PAGES 256
struct segment {
    struct page *pages[PAGES];
};

void segment_check(struct segment *segment, uint8_t page_number);

struct segment* segment_new() {
    struct segment *new_segment = calloc(sizeof(struct segment), 1);
    int i;
    for (i = 0; i < PAGES; i++) {
        new_segment->pages[i] = NULL;
    }
    return new_segment;
}

uint8_t segment_read(struct segment *segment, uint16_t addr) {
    uint8_t page_number = (addr & 0xF0) >> 8;
    uint8_t page_addr = addr & 0x0F;
    segment_check(segment, page_number);
    return segment->pages[page_number]->bytes[page_addr];
}

void segment_write(struct segment *segment, uint16_t addr, uint8_t data) {
    uint8_t page_number = (addr & 0xF0) >> 8;
    uint8_t page_addr = addr & 0x0F;
    segment_check(segment, page_number);
    segment->pages[page_number]->bytes[page_addr] = data;
}

void segment_check(struct segment *segment, uint8_t page_number) {
    if (segment->pages[page_number] == NULL) {
        segment->pages[page_number] = calloc(sizeof(struct page), 1);
    }
}

