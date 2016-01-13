#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

struct memory;
struct memory* memory_new();
void memory_read(struct memory* memory, uint32_t addr, int bytes,
        uint8_t *data);
void memory_write(struct memory* memory, uint32_t addr, int bytes,
        uint8_t *data);

#endif // _MEMORY_H_

