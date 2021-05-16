#include "inputHandler.h"

//expecting HEX string as input? if yes store input in 1536 size array and validate each character as a hex character
//if ASCII string then store in 3072 size char array and perform translation into hex string
//assuming HEX string as input

char commandString[100];
unsigned char byte;
int size, read;


void handleInput(FILE *stream){

    fread(&byte, 1, 1, stream);
    if(byte == '.')
    {
        /*fseek(stream, 0, SEEK_END);
        size = ftell(stream);
        fseek(stream, 0, SEEK_SET);

        read  = fread(&commandString, 1, size, stream);*/

        //fread() didnt succesfully read into string. Abandoning for now.

        fgets(&commandString, 100, stream);

        printf("calling commandHandler with parameter: %s\n", commandString);

        handleCommand(&commandString);
    }
    else
    {
        fseek(stream, 0, SEEK_SET);
        handleData(stream);
    }

}
