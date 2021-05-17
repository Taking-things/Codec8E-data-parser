#include "dataStorage.h"

void handleData(unsigned char *inputBuffer);

int detectPacketType(unsigned char *string);

void parseTcp8Packet(const uint8_t *pBuffer, AVL_Packet_TCP_8 *pPacketOutput);

void parseTcp8EPacket(AVL_Packet_TCP_8 *packet, unsigned char *buffer);

void parseUdp8Packet(AVL_Packet_TCP_8 *packet, unsigned char *buffer);

void parseUdp8EPacket(AVL_Packet_TCP_8 *packet, unsigned char *buffer);
