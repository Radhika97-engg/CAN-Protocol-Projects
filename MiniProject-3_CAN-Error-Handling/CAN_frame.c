#include<stdio.h>
#include<stdlib.h>
#include"CAN_frame.h"

// Function to calculate a 15-bit CRC for a CAN frame
unsigned int calculate_crc(struct CAN_frame message)
{
    unsigned int crc = 0;

    // Mix the message ID (2 bytes) into CRC
    unsigned char *ptr = (unsigned char*)& message.msg_ID;
    for(int i = 0; i < 2; i++)
    {
        crc ^= ptr[i]; // XOR each byte
    }

    // Mix DLC and data bytes into CRC
    crc ^= message.DLC;
    for(int i = 0; i < message.DLC; i++)
    {
        crc ^= message.data[i];
    }

    // Mask to keep only 15 bits
    crc = crc & 0x7FFF;
    return crc;
}

// Function to randomly flip a bit in the data field to simulate transmission error
void inject_error(struct CAN_frame *message)
{
    int random_byte = rand() % message->DLC;  // Select a random data byte
    int random_bit = rand() % 8;              // Select a random bit within that byte

    // Flip the selected bit
    message->data[random_byte] ^= (1 << random_bit);
    printf("Injected error at byte index [%d], bit position [%d]\n", random_byte, random_bit);
}

// Function to check if recalculated CRC matches the original CRC
int check_crc(struct CAN_frame message)
{
    unsigned int modified_crc = calculate_crc(message);
    return modified_crc == message.CRC; // returns 1 if equal, else 0
}

// Function to log CAN frame and error analysis to a text file
void log_error(struct CAN_frame message, unsigned int modified_crc, int error_type)
{
    FILE *log = fopen("can_log.txt", "a");
    if (log == NULL)
    {
        printf("Failed to open the log file!\n");
        return;
    }
    //printing result
    fprintf(log, "******* CAN LOG MESSAGE *******\n");
    fprintf(log, "ID: 0x%X\n", message.msg_ID);
    fprintf(log, "DLC: %d\n", message.DLC);
    fprintf(log, "DATA: ");
    for (int i = 0; i < message.DLC; i++)
    {
        fprintf(log, "0x%X ", message.data[i]);
    }
    fprintf(log, "\n");

    // CRC 
    fprintf(log, "Original CRC: 0x%X\n", message.CRC);
    fprintf(log, "Recalculated CRC: 0x%X\n", modified_crc);

    // Error type
    fprintf(log, "Error type: ");
    switch (error_type)
    {
        case 0:
            fprintf(log, "No Error\n");
            break;
        case 1:
            fprintf(log, "Form Error\n");
            break;
        case 2:
            fprintf(log, "Single Bit Error\n");
            break;
        case 3:
            fprintf(log, "CRC Error (multiple bits)\n");
            break;
        default:
            fprintf(log, "Unknown Error\n");
            break;
    }

    fprintf(log, "-------------------------------\n\n");
    fclose(log);
}

// Function to identify the type of error 
int identify_error_type(struct CAN_frame original, struct CAN_frame modified)
{
    // Form error
    if (original.msg_ID != modified.msg_ID || original.DLC != modified.DLC)
    {
        return 1; // Form error
    }
   // Count the number of bit differences in data field
    int changed_bits = 0;
    for (int i = 0; i < original.DLC; i++)
    {
        unsigned char diff = original.data[i] ^ modified.data[i];

     //count number of 1s using while loop
        while (diff)
        {
            changed_bits += diff & 1;
            diff >>= 1;
        }
    }

    if (changed_bits == 1)
        return 2; // Single bit error
    else if (changed_bits > 1)
        return 3; // CRC error
    else
        return 0; // No error
}
