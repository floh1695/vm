#include "memory.h"

#include <stdlib.h> //calloc

#include "page.h"

#define PAGES 256
struct memory {
    struct page *pages[PAGES];
};

struct memory* memory_new() {
    struct memory *new_memory = calloc(sizeof(struct memory), 1);
    int i;
    for (i = 0; i < PAGES; i++) {
        new_memory->pages[i] = NULL;
    }
    return new_memory;
}

