#ifndef _MACHINE_H_
#define _MACHINE_H_

#include "memory.h"

struct machine {
   struct memory* memory; 
};

struct machine* machine_new();

#endif // _MACHINE_H_

