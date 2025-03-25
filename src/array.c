#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "array.h"

void initArray(Array* array, size_t element_size, Destructor destructor)
{
    array->data = NULL;
    array->capacity = 0;
    array->size = 0;
    array->element_size = element_size;
    array->destructor = destructor; 
}

int resize(Array* array, size_t size)
{ 
    if (array->data == NULL)
    {
        array->capacity = size;
        array->data = malloc(array->capacity * array->element_size);

        if (array->data == NULL)
        {
            return MEMORY_ALLOCATION_ERROR;
        }
    }
    else
    {
        array->capacity = size;
        
        void* temp = realloc(array->data, array->capacity * array->element_size);

        if (temp == NULL)
        {
            return MEMORY_ALLOCATION_ERROR;
        }

        array->data = temp;
    }

    return NO_ERROR;
}

int append(Array* array, void* element)
{
    if (array->size >= array->capacity)
    {
        int ret = NO_ERROR;

        if (array->data == NULL)
        {
            ret = resize(array, 1);
        }
        else
        {
            ret = resize(array, array->capacity * 2);
        }
        
        if (ret != NO_ERROR)
        {
            return ret;
        }
    }

    void* destination = (void*)((uintptr_t)(array->data) + (array->size * array->element_size));

    memcpy(destination, element, array->element_size);
    array->size++;

    return NO_ERROR;
}

void* get(Array* array, size_t index)
{
    if (index >= array->size)
    {
        return NULL;
    }

    return (uintptr_t)(array->data) + (index * array->element_size);
}

void freeArray(Array* array)
{
    if (array->destructor != NULL)
    {
        for (int i = 0; i < array->size; ++i)
        {
            void* pointer = (uintptr_t)(array->data) + (i * array->element_size);
            array->destructor(pointer);
        }
    }

    free(array->data);
}