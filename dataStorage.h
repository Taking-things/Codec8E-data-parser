#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned long   timestamp;
    unsigned char   priority;

    //GPS ELEMENT
    int             longitude;
    int             latitude;
    short           altitude;
    short           angle;
    unsigned char   satellites;
    short           speed;

    //IO Element
    unsigned char   event_id;
    unsigned char   element_count;

    unsigned char   one_byte_element_count;
    unsigned char   *one_byte_elem_id;
    unsigned char   *onr_byte_elem;

    unsigned char   two_byte_element_count;
    unsigned char   *two_byte_elem_id;
    short           *two_byte_elem;

    unsigned char   four_byte_element_count;
    unsigned char   *four_byte_elem_id;
    int             *four_byte_elem;

    unsigned char   eight_byte_element_count;
    unsigned char   *eight_byte_elem_id;
    unsigned long   *eight_byte_elem;

}   AVL_8_Data_Element;

typedef struct {
    unsigned long   timestamp;
    unsigned char   priority;

    //GPS ELEMENT
    int             longitude;
    int             latitude;
    short           altitude;
    short           angle;
    unsigned char   satellites;
    short           speed;

    //IO Element
    short           event_id;
    short           element_count;

    short           one_byte_element_count;
    short           *one_byte_elem_id;
    unsigned char   *onr_byte_elem;

    short           two_byte_element_count;
    short           *two_byte_elem_id;
    short           *two_byte_elem;

    short           four_byte_element_count;
    short           *four_byte_elem_id;
    int             *four_byte_elem;

    short           eight_byte_element_count;
    short           *eight_byte_elem_id;
    unsigned long   *eight_byte_elem;

    short           x_byte_elem_count;
    short           *x_byte_elem_id;
    unsigned char   **x_byte_elem;

}   AVL_8E_Data_Element;


typedef struct  {

    int preamble;
    int AVL_Data_Length;

    unsigned char codec_id;

    //number of data in packet
    unsigned char   avl_data_count_1;

    AVL_8_Data_Element *data_element_8;

    //number of data in packet(confirmation)
    unsigned char   avl_data_count_2;

}   AVL_Packet_TCP_8;

typedef struct  {

    int preamble;
    int AVL_Data_Length;

    unsigned char codec_id;

    //number of data in packet
    unsigned char   avl_data_count_1;

    AVL_8E_Data_Element *data_element_8e;

    //number of data in packet(confirmation)
    unsigned char   avl_data_count_2;

}   AVL_Packet_TCP_8E;


typedef struct {

    //Protocol section
    short packet_length;
    short packet_id;
    unsigned char packet_type;
    unsigned char avl_packet_id;
    short imei_length;
    unsigned char *imei;


    //Data elements section
    unsigned char codec_id;

    //number of data in packet
    unsigned char   avl_data_count_1;

    AVL_8_Data_Element *data_element_8;
    AVL_8E_Data_Element *data_element_8e;

    //number of data in packet(confirmation)
    unsigned char   avl_data_count_2;


}   AVL_Packet_UDP_8;

typedef struct {

    //Protocol section
    short packet_length;
    short packet_id;
    unsigned char packet_type;
    unsigned char avl_packet_id;
    short imei_length;
    unsigned char *imei;


    //Data elements section
    unsigned char codec_id;

    //number of data in packet
    unsigned char   avl_data_count_1;

    AVL_8_Data_Element *data_element_8;
    AVL_8E_Data_Element *data_element_8e;

    //number of data in packet(confirmation)
    unsigned char   avl_data_count_2;


}   AVL_Packet_UDP_8E;

void storePacketTCP8(AVL_Packet_TCP_8);

void storePacketTCP8E(AVL_Packet_TCP_8E);

void storePacketUDP8(AVL_Packet_UDP_8);

void storePacketUDP8E(AVL_Packet_UDP_8E);





