#ifndef CAN_READER_H
#define CAN_READER_H

#include<time.h>
#define MAX_DATA_LENGTH 8 //CAN allows upto 8 bytes

// Function to read CAN log file and print messages matching target_id
void read_and_filter_message(int target_id);


#endif