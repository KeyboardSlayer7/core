#include <stdio.h>
#include <stdint.h>

#include "hex.h"
#include "sstring.h"

void toHex(String* string, uint8_t byte)
{
    char values[16] = "0123456789ABCDEF"; 

    char hex[3];
    hex[2] = '\0';

    hex[0] = values[(byte >> 4) & 0xF];
    hex[1] = values[byte & 0xF];

    set(string, hex);
}

uint8_t fromHex(String* string)
{

}