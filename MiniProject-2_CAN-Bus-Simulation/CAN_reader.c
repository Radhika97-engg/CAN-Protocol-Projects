#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "CAN_reader.h"

void read_and_filter_message(int target_id)
{
    FILE *file = fopen("can_log.txt", "r");
    if (file == NULL)
    {
        printf("[ERROR] Could not open file for reading.\n");
        return;
    }

    char line[100]; // Buffer to store from file
    printf("\n[DEBUG] Checking can_log.txt contents:\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        int msg_id, message_length;
        time_t time_stamp;
        unsigned char data[MAX_DATA_LENGTH] = {0}; // Ensuring no garbage value

        //Debugging: Print the raw file content
        printf("[DEBUG] Raw Log Line: %s", line);

        //Extract msg_id and message_length
        if(sscanf(line, "%d %d", &msg_id, &message_length)!=2)
        {
            printf("[ERROR] failed to extract message id and message lenght from  line %s : ",line);
            continue;
        }
        
        //Debugging: Confirm extraction
        printf("[DEBUG] Extracted ID: %d, Data Length: %d\n", msg_id, message_length);

        //Move pointer to first data byte
        char *ptr = strchr(line, ' ');
        if (ptr) ptr++;  // Move past msg_id safely
        ptr = strchr(ptr, ' ');
        if (ptr) ptr++;  // Move past message_length safely

        // Read data bytes
        for (int i = 0; i < message_length; i++)
        {
            sscanf(ptr, "%x", &data[i]);
            ptr = strchr(ptr, ' ');
            if (ptr) ptr++;  // Move only if ptr is not NULL
        }

        // Read timestamp
        ptr = strrchr(line, ' ');  // Move to last space before timestamp
        if (ptr) ptr++;  // Move only if ptr is not NULL
        sscanf(ptr, "%ld", &time_stamp);

        // Debugging: Print extracted message details
        printf("[DEBUG] Read ID: %d, Length: %d, Timestamp: %ld\n", msg_id, message_length, time_stamp);

        //Confirm filtering logic
        if (msg_id == target_id)
        {
            printf("Message for Node B: ID: %d, Data: ", msg_id);
            for (int i = 0; i < message_length; i++)
            {
                printf("%02X ", data[i]);
            }
            printf("Timestamp: %ld\n", time_stamp);
        }
    }

    fclose(file);  
}
