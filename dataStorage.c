#include "dataStorage.h"

AVL_Packet_TCP_8 *tcp_8_packets;
int tcp_8_packet_memory_bound = 0;

AVL_Packet_TCP_8E *tcp_8E_packets;


AVL_Packet_UDP_8 *udp_8_packets;
AVL_Packet_UDP_8E *udp_8E_packets;


void storeTcp8Packet(AVL_Packet_TCP_8 packet){

    if(tcp_8_packet_memory_bound == 0)
    {
        tcp_8_packets = malloc(packet.avl_data_length + 15);
        *tcp_8_packets = packet;
        tcp_8_packet_memory_bound = packet.avl_data_length + 15;
    } else
    {
        realloc(tcp_8_packets, ((packet.avl_data_length + 15) + tcp_8_packet_memory_bound));
        tcp_8_packets[tcp_8_packet_memory_bound] = packet;
        tcp_8_packet_memory_bound += packet.avl_data_length + 15;
    }
};

void storeTcp8EPacket(AVL_Packet_TCP_8E packet){};

void storeUdp8Packet(AVL_Packet_UDP_8 packet){};

void storeUdp8EPacket(AVL_Packet_UDP_8E packet){};
