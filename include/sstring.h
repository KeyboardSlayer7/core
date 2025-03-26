#ifndef SSTRING_H
#define SSTRING_H

typedef struct string_t
{
    char* data;
    size_t length;
    size_t capacity;
} String;

void initString(String* string);
void set(String* string, const char* c_string);
void concatenate(String* string, const char* c_string);
void freeString(String* string);

#endif // SSTRING_H