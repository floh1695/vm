#ifndef _MACHINE_H_
#define _MACHINE_H_

#include "memory.h"
#include "mmu.h"

struct machine {
    struct memory *memory; 
    mmu *memory_manager;
};

struct machine* machine_new();

#endif // _MACHINE_H_

