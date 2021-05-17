#include "dataHandler.h"

#define TCP_8 0
#define TCP_8E 1
#define UDP_8 2
#define UDP_8E 3

//following variables declared global due to being used in multiple functions
int16_t UdpDataLength = 0;
int32_t TcpDataLength = 0;

void handleData(unsigned char *inputBuffer){


    switch(detectPacketType(inputBuffer))
    {
        case TCP_8: ;
            AVL_Packet_TCP_8 packet;
            parseTcp8Packet(&packet, inputBuffer);
            storeTcp8Packet(packet);

            printf("switch statement, case tcp8");

            break;

        case TCP_8E:

            break;

        case UDP_8:

            break;

        case UDP_8E:

            break;
    };



};

int detectPacketType(unsigned char *string){

    unsigned char buffer[4] = {0, 0, 0, 0};

    //check if UDP
    if(  memcmp(string, buffer, 4) != 0  ){ //if condition met, preamble of tcp packet is not present. Look for udp packet validity

       UdpDataLength = (short)((string[0] << 8) | string[1]);

        if(string[UdpDataLength+2] == 0) //we are expecting '\0' character to be found at dataLength+2 position
        {
            if(string[23] == 0x08)
            {
                return UDP_8;
            } else if(string[23] == 0x8E)
            {
                return UDP_8E;
            }
        }

    };

    //otherwise look for tcp packet validity
    TcpDataLength = (int)(string[4] << 24 | string[5] << 16 | string[6] << 8 | string [7]);

    if(string[TcpDataLength + 15] == 0)
    {
            if(string[8] == 0x08)
            {
                return TCP_8;
            }
            else if(string[8] == 0x8E)
            {
                return TCP_8E;
            }
    };

};


void parseTcp8Packet(const uint8_t *pBuffer, AVL_Packet_TCP_8 *pPacketOutput){
    pPacketOutput->preamble = (int32_t*) &pBuffer[0];
    pPacketOutput->avl_data_length = (int*) &pBuffer[4];

    pPacketOutput->codec_id = (int8_t*) &pBuffer[8];

    pPacketOutput->avl_data_count_1 = (int8_t*) &pBuffer[9];

    //now begins variable length part of the packet...
    //use global TcpDataLength
    //pPacketOutput->data_element_8->timestamp = (int64_t*) &pBuffer[10];
    //pPacketOutput->data_element_8->priority = (int8_t*) &pBuffer[18];

    /* some pointer error. Will fix after the rest of functionality is implemented
    pPacketOutput->data_element_8->longitude = (int32_t*) &pBuffer[19];
    pPacketOutput->data_element_8->latitude = (int32_t*) &pBuffer[23];
    pPacketOutput->data_element_8->altitude = (int16_t*) &pBuffer[27];
    pPacketOutput->data_element_8->angle = (int16_t*) &pBuffer[29];
    pPacketOutput->data_element_8->satellites = (int8_t*) &pBuffer[31];
    pPacketOutput->data_element_8->speed = (int16_t*) &pBuffer[32];
    */



};

/*void parseTcp8EPacket(const uint8_t *pBuffer, AVL_Packet_TCP_8E *pPacketOutput){};

void parseUdp8Packet(const uint8_t *pBuffer, AVL_Packet_UDP_8 *pPacketOutput){};

void parseUdp8EPacket(const uint8_t *pBuffer, AVL_Packet_UDP_8E *pPacketOutput){};
*/
