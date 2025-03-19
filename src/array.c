#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "array.h"

void initArray(Array* array, size_t element_size)
{
    array->data = NULL;
    array->capacity = 0;
    array->size = 0;
    array->element_size = element_size; 
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

        if (array->data = NULL)
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

    memcpy((uint8_t*)array->data + (array->size * array->element_size), element, array->element_size);
    array->size++;

    return NO_ERROR;
}

void* get(Array* array, size_t index)
{
    if (index >= array->size)
    {
        return NULL;
    }

    return (uint8_t*)array->data + (index * array->element_size);
}