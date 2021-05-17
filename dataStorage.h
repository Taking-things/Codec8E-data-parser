#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//TODO: double check all values
typedef struct {
    int64_t   timestamp;
    int8_t   priority;

    //GPS ELEMENT
    int32_t         longitude;
    int32_t         latitude;
    int16_t         altitude;
    int16_t         angle;
    int8_t          satellites;
    int16_t         speed;

    //IO Element
    int8_t          event_id;
    int8_t          element_count;

    int8_t          one_byte_element_count;
    int8_t          *one_byte_elem_id;
    int8_t          *onr_byte_elem;

    int8_t          two_byte_element_count;
    int8_t          *two_byte_elem_id;
    int16_t         *two_byte_elem;

    int8_t          four_byte_element_count;
    int8_t          *four_byte_elem_id;
    int32_t         *four_byte_elem;

    int8_t          eight_byte_element_count;
    int8_t          *eight_byte_elem_id;
    int64_t         *eight_byte_elem;

}   AVL_8_Data_Element;

typedef struct {
    int64_t         timestamp;
    int8_t          priority;

    //GPS ELEMENT
    int32_t         longitude;
    int32_t         latitude;
    int16_t         altitude;
    int16_t         angle;
    int8_t          satellites;
    int16_t         speed;

    //IO Element
    int16_t         event_id;
    int16_t         element_count;

    int16_t         one_byte_element_count;
    int16_t         *one_byte_elem_id;
    int8_t          *onr_byte_elem;

    int16_t         two_byte_element_count;
    int16_t         *two_byte_elem_id;
    int16_t         *two_byte_elem;

    int16_t         four_byte_element_count;
    int16_t         *four_byte_elem_id;
    int             *four_byte_elem;

    int16_t         eight_byte_element_count;
    int16_t         *eight_byte_elem_id;
    int64_t         *eight_byte_elem;

    int16_t         x_byte_elem_count;
    int16_t         *x_byte_elem_id;
    int8_t          **x_byte_elem;

}   AVL_8E_Data_Element;


typedef struct  {

    int32_t         preamble;
    int32_t         avl_data_length;

    int8_t      codec_id;

    //number of data in packet
    int8_t          avl_data_count_1;

    AVL_8_Data_Element *data_element_8;

    //number of data in packet(confirmation)
    int8_t          avl_data_count_2;

    int32_t         crc;

}   AVL_Packet_TCP_8;

typedef struct  {

    int32_t         preamble;
    int32_t         avl_data_length;

    int8_t codec_id;

    //number of data in packet
    int8_t          avl_data_count_1;

    AVL_8E_Data_Element *data_element_8e;

    //number of data in packet(confirmation)
    int8_t          avl_data_count_2;

}   AVL_Packet_TCP_8E;


typedef struct {

    //Protocol section
    int16_t         packet_length;
    int16_t         packet_id;
    int8_t          packet_type;
    int8_t          avl_packet_id;
    int16_t         imei_length;
    int8_t          *imei;


    //Data elements section
    int8_t          codec_id;

    //number of data in packet
    int8_t          avl_data_count_1;

    AVL_8_Data_Element *data_element_8;

    //number of data in packet(confirmation)
    int8_t          avl_data_count_2;


}   AVL_Packet_UDP_8;

typedef struct {

    //Protocol section
    int16_t         packet_length;
    int16_t         packet_id;
    int8_t          packet_type;
    int8_t          avl_packet_id;
    int16_t         imei_length;
    int8_t          *imei;


    //Data elements section
    int8_t          codec_id;

    //number of data in packet
    int8_t          avl_data_count_1;

    AVL_8E_Data_Element *data_element_8e;

    //number of data in packet(confirmation)
    int8_t          avl_data_count_2;


}   AVL_Packet_UDP_8E;

void storeTcp8Packet(AVL_Packet_TCP_8 packet);

void storeTcp8EPacket(AVL_Packet_TCP_8E packet);

void storeUdp8Packet(AVL_Packet_UDP_8 packet);

void storeUdp8EPacket(AVL_Packet_UDP_8E packet);





