#include <stdlib.h>
#include <stdint.h>

#include "arena.h"

void initArena(Arena* arena)
{
  arena->base = malloc(sizeof(uint8_t) * INITIAL_ARENA_SIZE);
  arena->current = arena->base;
}

void* arenaAlloc(Arena* arena, size_t size)
{
  void* pointer = arena->current;
  arena->current += size;

  return ponter;
}

void freeArena(Arena* arena)
{
  free(arena->base);
}
