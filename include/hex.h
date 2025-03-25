#ifndef HEX_H
#define HEX_H

#include <stdint.h>

#include "sstring.h"

#define HIGH 240
#define LOW 15

void toHex(String* string, uint8_t byte);
uint8_t fromHex(String* string);

#endif 