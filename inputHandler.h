#include <stdio.h>
#include <stdlib.h>

#include "commandHandler.h"
#include "dataHandler.h"

void handleInput(FILE *stream);

int stringIsHex(char *string);

int packetIsTcp(FILE *stream);

int8_t convertString(unsigned char *inputBuffer, unsigned char *outputBuffer);

int hexStringToBytes(const char *hexStr, unsigned char *output, unsigned int *outputLen);
