#ifndef SSTRING_H
#define SSTRING_h

typedef struct string_t
{
    char* data;
    size_t length;
    size_t capacity;
} String;

void initString(const char* c_string);
void concatenate(String* string, const char* c_string);

#endif // SSTRING_H