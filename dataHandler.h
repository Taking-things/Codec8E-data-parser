#include "dataStorage.h"

void handleData(FILE *stream);

int detectPacketType(unsigned char *string);

void parseTcp8Packet(AVL_Packet_TCP_8 *packet, unsigned char *buffer);
