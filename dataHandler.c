#include "dataHandler.h"

#define TCP_8 0
#define TCP_8E 1
#define UDP_8 2
#define UDP_8E 3

void handleData(FILE *stream){

    unsigned char *inputBuffer;
    unsigned char *processedBuffer;
    char *ptr;

    inputBuffer = malloc(3072);
    processedBuffer = malloc(1536);

    fgets(inputBuffer, 3072, stream);
    ptr = strchr(inputBuffer, '\n');
    *ptr = 0;

    unsigned char uchr;

    for( size_t i = 0; i < strlen(inputBuffer); i += 2 )
    {
        sscanf( (char*)inputBuffer + i, "%2x", &uchr ); // conversion
        if(!processedBuffer){
            printf("not processed buffer not");
        }
        processedBuffer[i/2] = uchr; // save as char
    }


    switch(detectPacketType(processedBuffer))
    {
        case TCP_8: ;
            AVL_Packet_TCP_8 packet;
            parseTcp8Packet(&packet, processedBuffer);
            storePacketTCP8(packet);
            break;

        case TCP_8E:

            break;

        case UDP_8:

            break;

        case UDP_8E:

            break;
    };



};

int detectPacketType(unsigned char *string){ //return: 0 - tcp8, 1 - tcp8e, 2 - udp8, 3 - udp8e.


    unsigned char buffer[4] = {0, 0, 0, 0};
    short dataLength = 0;

    //check if UDP
    if(memcmp(string, buffer, 4) != 0){ //if condition met, preamble of tcp packet is not present. Look for udp packet validity

       dataLength = (short)((string[0] << 8) | string[1]);
       printf("%d", dataLength);

        if(string[dataLength*2+5] != '\n') //we are expecting '\n' character to be found at dataLength+3 position
        {
            printf("The string read did not meet the specification of a valid UDP packet.");
        } else if( string[47] == '0' && string[48] == '8');
        {
            printf("Packet determined to be of type UDP, codec version 8");
        };

    };

    //otherwise look for tcp packet validity

};


void parseTcp8Packet(AVL_Packet_TCP_8 *packet, unsigned char *buffer){};
