#include"CAN_frame.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    // Seeding the random number generator to get different values on each time 
    srand(time(0));

    // Create and initialize a CAN frame message
    struct CAN_frame test_message;
    test_message.msg_ID = 0x5A3;
    test_message.DLC = 4;

    // insert data values
    unsigned char values[4] = {0x11, 0x22, 0x33, 0x44};
    for (int i = 0; i < test_message.DLC; i++)
    {
        test_message.data[i] = values[i];
    }

    // Calculate CRC for the original message
    test_message.CRC = calculate_crc(test_message);

    // Print original CAN frame info
    printf("\n=====Testing CAN frame=====\n");
    printf("ID: 0x%X\n", test_message.msg_ID);
    printf("DLC: %d\n", test_message.DLC);
    printf("DATA: ");
    for (int i = 0; i < test_message.DLC; i++)
    {
        printf("0x%X ", test_message.data[i]);
    }
    printf("\n");
    printf("CRC: 0x%X\n", test_message.CRC);

    // Create a copy of the message for error injection
    struct CAN_frame corrupted_message = test_message;

    // Inject a random bit error into the copy
    inject_error(&corrupted_message);

    // Check CRC of corrupted message
    int result = check_crc(corrupted_message);
    printf("\n======CRC check results======\n");
    if (result)
    {
        printf("Valid message - No error detected\n");
    }
    else
    {
        printf("Error Detected - CRC Mismatch\n");
    }

    // Recalculate CRC after corruption for comparison
    unsigned int modified_crc = calculate_crc(corrupted_message);

    // Identify type of error (form, single-bit, CRC, or none)
    int error_type = identify_error_type(test_message, corrupted_message);

    // Display error type in console
    switch (error_type)
    {
        case 0: printf("No Error detected\n"); break;
        case 1: printf("Form error detected\n"); break;
        case 2: printf("Single bit error detected\n"); break;
        case 3: printf("CRC error (multiple bits) detected\n"); break;
        default: printf("Unknown error type\n");
    }

    // Log the message and error details to a file
    log_error(corrupted_message, modified_crc, error_type);
}
