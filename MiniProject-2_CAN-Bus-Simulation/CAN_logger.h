#ifndef CAN_LOGGER_H
#define CAN_LOGGER_H

#include<time.h>
#define MAX_DATA_LENGTH 8 //CAN allows upto 8 bytes
struct CAN_message
{
    int ID;       //message ID from 100 to 500
    int data_length; //message data length from 1 to 8
    time_t timestamp;// current timestamp
    unsigned char Data[MAX_DATA_LENGTH]; // data of size 0 to 8
};
// Function to generate a random CAN message
void generate_random_can_message(struct CAN_message *msg);
void write_can_message_to_file(struct CAN_message *msg);

#endif
