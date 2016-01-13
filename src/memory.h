#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <stdint.h>

struct memory;
struct memory* memory_new();
uint8_t* memory_read(int bytes);
void memory_write(int bytes, uint8_t *data);

#endif // _MEMORY_H_

