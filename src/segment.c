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

struct segment* segment_new() {
    struct segment *new_segment = calloc(sizeof(struct segment), 1);
    int i;
    for (i = 0; i < PAGES; i++) {
        new_segment->pages[i] = NULL;
    }
    return new_segment;
}

