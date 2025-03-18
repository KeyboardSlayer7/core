#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
typedef enum array_errors_t
{
    NO_ERROR,
    MEMORY_ALLOCATION_ERROR
} ArrayErrors;

typedef struct array_t 
{
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Array;

void initArray(Array* array, size_t element_size);
int append(Array* array, void* element);
void* get(Array* array, size_t index); 

#endif // ARRAY_H