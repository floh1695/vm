#ifndef _PAGE_H_
#define _PAGE_H_

#include <stdint.h>

struct segment;
struct segment* segment_new();
uint8_t segment_read(struct segment *segment, uint16_t addr);
void segment_write(struct segment *segment, uint16_t addr, uint8_t data);

#endif // _PAGE_H_

