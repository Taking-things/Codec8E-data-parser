#include "inputHandler.h"

//expecting HEX string as input? if yes store input in 1536 size array and validate each character as a hex character
//if ASCII string then store in 3072 size char array and perform translation into hex string
//assuming HEX string as input


void handleInput(FILE *stream){

    unsigned char inputString[3072];
    unsigned char byte;
    int size = 100;

    fgets(&inputString[0], 3072, stream);

    char *ptr;
    ptr = strchr(inputString, '\n');
    *ptr = 0;


    if(inputString[0] == '.')
    {
        handleCommand(inputString);
    }
    else
    {
        unsigned char processedBuffer[1536];
        int debugg = hexStringToBytes(inputString, processedBuffer, &size);
        if(debugg == 0)
        {
            //dumpHex(processedBuffer, size); //debugging
            handleData(processedBuffer);
        } else
        {
            printf("bad input");
        }
    }
};


int hexStringToBytes(const char *hexStr, unsigned char *output, unsigned int *outputLen) {
  size_t len = strlen(hexStr);
  if (len % 2 != 0) {
    return -1;
  }
  size_t finalLen = len / 2;
  *outputLen = finalLen;
  for (size_t inIdx = 0, outIdx = 0; outIdx < finalLen; inIdx += 2, outIdx++) {
    if ((hexStr[inIdx] - 48) <= 9 && (hexStr[inIdx + 1] - 48) <= 9) {
      goto convert;
    } else {
      if ((hexStr[inIdx] - 65) <= 5 && (hexStr[inIdx + 1] - 65) <= 5) {
        goto convert;
      } else {
        *outputLen = 0;
        return -1;
      }
    }
  convert:
    output[outIdx] =
        (hexStr[inIdx] % 32 + 9) % 25 * 16 + (hexStr[inIdx + 1] % 32 + 9) % 25;
  }
  output[finalLen] = '\0';
  return 0;
};

void dumpHex(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf("|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("|  %s \n", ascii);
			}
		}
	}
};
