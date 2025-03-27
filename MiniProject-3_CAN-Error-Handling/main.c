#include"CAN_frame.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));  //to seed different random values everytime
    struct CAN_frame test_message;
    test_message.msg_ID= 0x5A3;
    test_message.DLC=4;
    unsigned char values[4]= {0x11,0x22,0x33,0x44};
    for (int i=0;i<test_message.DLC;i++)
    {
    test_message.data[i]= values[i];
    }
    test_message.CRC=calculate_crc(test_message);
    printf("\n=====Testing CAN frame=====\n");
    printf("ID: 0x%X\n",test_message.msg_ID);
    printf("DLC: %d\n",test_message.DLC);
    printf("DATA: ");
    for(int i=0;i<test_message.DLC;i++)
    {
        printf("0x%X ",test_message.data[i]);
    }
    printf("\n");
    printf("CRC: 0x%X\n", test_message.CRC);
    struct CAN_frame corrupted_message=test_message;
    inject_error(&corrupted_message);
    int result=check_crc(corrupted_message);
    printf("\n======CRC check results======\n");
    if(result)
    {
        printf("Valid message - No error detected\n");
    }
    else
    {
        printf("Error Detected - CRC Mismatch\n");
    }
    unsigned int modified_crc=calculate_crc(corrupted_message);
    int error_type = identify_error_type(test_message, corrupted_message);
    switch(error_type)
{
    case 0: printf("No Error detected\n"); break;
    case 1: printf("Form error detected\n"); break;
    case 2: printf("Single bit error detected\n"); break;
    case 3: printf("CRC error (multiple bits) detected\n"); break;
    default: printf("Unknown error type\n");
}
    log_error(corrupted_message,modified_crc,error_type);

}