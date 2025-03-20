#include<stdio.h>
#include<stdlib.h>
//CAN FRAME
//   - ID (11 bits): Unique identifier for the CAN message
//   - DLC (4 bits): Data Length Code (0-8 bytes of data)
//   - Data (0-8 bytes): Payload data transmitted in the message
//   - CRC (15 bits): Error-checking field for data integrity
#pragma pack(1)    // to prevent padding
struct CAN_frame
{
    unsigned int ID;                 //11 bit id (stored in 16-bit int)
    unsigned char DLC;               //4 bit id (stored in 1 byte)
    unsigned char Data[8];           //0-8 bytes
    unsigned int CRC;                //15 bit(stored in 16 bit int)
};
#pragma pack()
#pragma pack(1)
struct CAN_frame_merged
{
    unsigned int packed_ID_DLC;     //stored ID(11 bit)+DLC(4 bits) (stored in 16-bit int)
    unsigned char Data[8];          //0-8 bytes
    unsigned int CRC;               //15 bit(stored in 16 bit int)
};
#pragma pack()


void encode_frame(struct CAN_frame message, struct CAN_frame_merged *encoded)
{
   encoded->packed_ID_DLC=(message.ID<<4)|message.DLC;
   encoded->CRC=message.CRC & 0x7FFF;
   for(int i=0;i<message.DLC;i++)
   {
     encoded->Data[i]=message.Data[i];
   }

}
void decode_frame(struct CAN_frame_merged *encoded,struct CAN_frame *message)
{
    message->ID=(encoded->packed_ID_DLC>>4) & 0x7FF;   //right shift to extract 11 bit DLC 
    message->DLC=(encoded->packed_ID_DLC) & 0xF;      //extract 4 bit DLC

    //copy back the Data bits
    for(int i=0;i<message->DLC;i++)
    {
        message->Data[i]=encoded->Data[i];
    }
    //restore CRC
    message->CRC=encoded->CRC;
}
int main()
{
    struct CAN_frame original_message=
    {
        .ID = 0X5A3,           
        .DLC = 4,               
        .Data = {0x40, 0x54, 0x67, 0x11},  
        .CRC = 0X1234          
    };
    struct CAN_frame_merged encoded_message;  
    struct CAN_frame decoded_message; 

    //encode the message
    encode_frame(original_message,&encoded_message);
    //decode the message
    decode_frame(&encoded_message, &decoded_message);

    //print original message
    printf("=====Original message======\n");
    printf("ID: 0x%X, DLC : %d, CRC : 0x%X\n", original_message.ID,original_message.DLC,original_message.CRC);
    printf("Data: ");
    for(int i=0;i<original_message.DLC;i++)
    {
        printf("0x%X ",original_message.Data[i]);
    }
    printf("\n");
    
    //print encoded message
    printf("=====Encoded message======\n");
    printf("Packed ID + DLC: 0x%X, CRC : 0x%X\n", encoded_message.packed_ID_DLC,encoded_message.CRC);
    for(int i=0;i<original_message.DLC;i++)
    {
        printf("0x%X ",encoded_message.Data[i]);
    }
    printf("\n");

    //print decoded message
    printf("=====Encoded message======\n");
    printf("ID: 0x%X,DLC: %d, CRC : 0x%X\n", decoded_message.ID,decoded_message.DLC,decoded_message.CRC);
    for(int i=0;i<original_message.DLC;i++)
    {
        printf("0x%X ",decoded_message.Data[i]);
    }
    printf("\n");

    return 0;

}