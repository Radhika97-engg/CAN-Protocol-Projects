#include <windows.h>
#include<stdio.h>
#include "CAN_logger.h"
#include "CAN_reader.h"

int main()
{
    struct CAN_message msg;
    int node_b_id = 200; 

    //Generate multiple messages for better testing
    for (int i = 0; i < 5; i++)
     {
        generate_random_can_message(&msg);
        write_can_message_to_file(&msg);

        //delay between messages
        int delay_ms= 500+rand()%1000;  //500 ms to 1500 ms
        printf("sleeping for %d ms before sending message\n",delay_ms);
        Sleep(delay_ms);
    }

    // Read and filter messages for Node B
    read_and_filter_message(node_b_id);
    
    return 0;
}
