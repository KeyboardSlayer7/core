#ifndef ARENA_H
#define ARENA_H

#define INITIAL_ARENA_SIZE 4096

typedef struct arena_t
{
  void* base;
  void* current;
} Arena;

void initArena(Arena* arena);
void freeArena(Arena* arena);

void* arenaAlloc(Arena* arena, size_t size);
