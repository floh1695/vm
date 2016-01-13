#include "mmu.h"

mmu *mmu_init(struct memory *mem)
{
  mmu *unit = calloc(1,sizeof(mmu));
  unit->mem=mem;
  return unit;
}

void mmu_set_base(mmu *unit,uint32_t base)
{
  unit->baseaddr=base;
}

void mmu_void_entries(mmu *unit)
{
  int i;
  for(i=0;i<4;i++)
  {
    unit->tlb[i].flags=0;
  }
}

int mmu_fetch(mmu *unit,uint8_t vpage)
{
  struct tlb_entry read_entry;
  int i;
  for(i=0;i<4;i++)
  {
    if(unit->tlb[i].flags&MMU_ACTIVE&&unit->tlb[i].vaddr==vpage)
    {
      return 1;
    }
  }
  for(i=0;i<32;i++)
  {
    memory_read(unit->mem,unit->baseaddr+4*i,4,(uint8_t *)&read_entry);
    if(read_entry.vaddr==vpage&&read_entry.flags&MMU_ACTIVE)
    {
      unit->tlb[unit->lru]=read_entry;
      unit->lru++;
      unit->lru&=0x3;
      return 1;
    }
  }
  return 0;
}

int mmu_check_flags(int table_flags,int user_flags)
{
  if(user_flags&MMU_SUPER)
  {
    return 1;
  }
  else if(table_flags&MMU_SUPER)
  {
    return 0;
  }
  if(user_flags&(MMU_RD|MMU_WR|MMU_EX)==table_flags&(MMU_RD|MMU_WR|MMU_EX))
  {
    return 1;
  }
  return 0;
}

int mmu_translate(mmu *unit,uint32_t *addr,int flags)
{
  int i;
  uint8_t vpage = (*addr)>>16;
  if(unit->baseaddr==0)
  {
    return 1;
  }
  if(mmu_fetch(unit,vpage))
  {
    for(i=0;i<4;i++)
    {
      if(unit->tlb[i].vaddr == vpage)
      {
        break;
      }
    }
    if(mmu_check_flags(unit->tlb[i].flags,flags))
    {
      (*addr)&=0x0000FFFF;
      (*addr)|=(unit->tlb[i].paddr)<<16;
      return 1;
    }
  }
  return 0;
}

