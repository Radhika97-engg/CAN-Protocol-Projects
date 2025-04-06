#include<stdint.h>
#include<stdio.h>
#include "CAN_type.h"
#include "CAN_message.h"
#include "CAN_encoder.h"
#include "CAN_decoder.h"

int main()
{
    //1.Define Test Inputs
    int ID = 0x5A3;  //11 bit standard CAN ID
    CAN_Mode MODE= CAN_FD; //using CAN_FD mode
    int length = 4; //Data length(Bytes)
    unsigned char data[]={0x11,0x22,0x33,0x44}; //Sample payload
    unsigned int CRC = 0xABCD; //Simulated CRC
    CAN_Flag flags =FDF|BRS; //both FDF and BRS flag set
    //2.Input validation before message creation
    if(ID<0 || ID > 0X7FF || length>64 || (MODE==CAN_FD && !(flags & FDF)) || (MODE== STANDARD_CAN && (flags & FDF)))
    {
    printf("One or more input values are invalid\n");
    return -1;
    }
    //3.Encode--->Decode--->Display Flow
    //create CAN message
    CAN_message original_message =create_message(MODE,ID,length,data,flags,CRC);

    //Encode the message into a packed binary format
    encoded_message enc= encode_CAN_message(original_message);

    //Decode it back into a CAN message structure
    CAN_message decoded = decode_CAN_message(enc);

    //print all results
    printf("\nOriginal message\n");
    print_message_info(original_message);

    printf("\ndecoded Message\n");
    print_message_info(decoded);

    //Print header in binary
    print_binary(enc.header);
    return 0;
}