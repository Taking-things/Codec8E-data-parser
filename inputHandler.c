#include "inputHandler.h"


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
        int conversionFlag = hexStringToBytes(inputString, processedBuffer, &size);
        if(conversionFlag == 0)
        {
            handleData(processedBuffer);
        } else
        {
            printf("...\n");
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
