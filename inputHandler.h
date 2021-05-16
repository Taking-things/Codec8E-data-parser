#include <stdio.h>
#include <stdlib.h>

#include "commandHandler.h"
#include "dataHandler.h"

void handleInput(FILE *stream);

int stringIsHex(char *string);

int packetIsTcp(FILE *stream);
