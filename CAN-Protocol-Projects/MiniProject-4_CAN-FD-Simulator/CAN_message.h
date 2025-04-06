#ifndef CAN_MESSAGE_H
#define CAN_MESSAGE_H

#include "CAN_type.h"
//CAN message structure
typedef struct CAN_message
{
    int id;            //Standard 11-bit CAN ID
    CAN_Mode mode;     //CAN mode- Standard CAN or CAN FD
    int length;        //number of data bytes
    unsigned char data[CANFD_MAX_DATA_LEN];  //payload -upto 64 bytes for CAN FD
    CAN_Flag flags;  //flags FDF, BRS
    unsigned int crc; //Simulated CRC

}CAN_message;

//Function Prototypes
//creates and returns a CAN message
CAN_message create_message(CAN_Mode mode,int id,int length,unsigned char* data,CAN_Flag flags,unsigned int CRC);
//prints CAN message
void print_message_info(CAN_message msg);

#endif

