#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sstring.h"
#include "array.h"

void initString(String* string)
{
    string->length = 0;
    string->capacity = 0;
    string->data = NULL;    
}

void set(String* string, const char* c_string)
{
    if (string->data != NULL)
    {
        free(string->data);
    }
    
    string->length = strlen(c_string);
    string->capacity = string->length;
    
    string->data = malloc(sizeof(char) * (string->length + 1));
    string->data[string->length] = '\0';

    memcpy(string->data, c_string, string->length);
}

void concatenate(String* string, const char* c_string)
{
    int length = strlen(c_string);

    char* temp = (char*)realloc(string->data, sizeof(char) * (string->length + length + 1));

    if (temp == NULL)
    {
        printf("Temp is null\n");
        exit(EXIT_FAILURE);
    }

    string->data = temp;
    strcpy(&string->data[string->length], c_string);

    string->length += length;

    string->data[string->length] = '\0';
}