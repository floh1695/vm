#include "page.h"

#include <stdint.h>
#include <stdlib.h>

#define SEGMENT_BYTES 256
struct segment {
    uint8_t bytes[SEGMENT_BYTES];
};

#define SEGMENTS 256
struct page {
    struct segment *segments[SEGMENTS];
};

struct page* page_new() {
    struct page *new_page = calloc(sizeof(struct page), 1);
    int i;
    for (i = 0; i < SEGMENTS; i++) {
        new_page->segments[i] = NULL;
    }
    return new_page;
}

