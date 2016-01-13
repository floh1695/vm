#ifndef MMU_H
#define MMU_H

#include <stdint.h>
#include <stdlib.h>

#include "memory.h"

struct tlb_entry
{
  uint8_t flags;
  uint8_t vaddr;
  uint16_t paddr;
};

struct mmu
{
  struct tlb_entry tlb[4];
  uint32_t baseaddr;
  char lru;
  struct memory *mem;
};
typedef struct mmu mmu;

#define MMU_ACTIVE 1
#define MMU_RD 2
#define MMU_WR 4
#define MMU_EX 8
#define MMU_SUPER 16

//initializes MMU
mmu *mmu_init(struct memory *mem);
//sets the base address for the translation table in memory. this also voids
//the entries
void mmu_set_base(mmu *unit,uint32_t base);
//this tells the MMU that it should consider its entries all invalid. good for
//switching memory contexts.
void mmu_void_entries(mmu *unit);
//translates the address pointed to by addr (in place), returning 1 on success,
//0 on failure.
int mmu_translate(mmu *unit,uint32_t *addr,int flags);

#endif //MMU_H
