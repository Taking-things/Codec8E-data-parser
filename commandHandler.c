#include "commandHandler.h"

void handleCommand(char *inputString){
    if(strcmp(inputString, ".exit") == 0)
    {
        freeBuffers();
        exitProgram();
    } else if(strcmp(&inputString, ".free") == 0)
    {
        freeBuffers();
    } else if(strcmp(&inputString, ".show") == 0)
    {
        printData();
    } else if(strcmp(&inputString, ".info") == 0)
    {
        printDetails();
    }
};

freeBuffers(){};

exitProgram(){};

printData(){};

printDetails(){};
