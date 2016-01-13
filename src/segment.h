#ifndef _PAGE_H_
#define _PAGE_H_

struct segment;
struct segment* segment_new();
uint8_t segment_read(struct segment *segment, uint16_t addr);
uint8_t segment_write(struct segment *segment, uint16_t addr, uint8_t data);

#endif // _PAGE_H_

