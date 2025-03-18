#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct array_t 
{
    void *data;
    size_t size;
    size_t capacity;
    size_t element_size;
} Array;

void initArray(Array* array, size_t element_size);
void append(Array* array, void* element);
void* get(Array* array, size_t index); 

#endif // DYNAMIC_ARRAY_H