#include<stdio.h>
#include"CAN_message.h"

//Creates and returns a CAN_message after validating the mode, ID, length, and flags. 
CAN_message create_message(CAN_Mode mode,int id,int length,unsigned char* data,CAN_Flag flags,unsigned int CRC)
{
     //1.Validate message ID
     //In standard CAN ID is 11 bit identifier
     CAN_message message; //creating an empty message 
     if(id<0 || id> 0x7FF) //checking if id is 11 bits long
     {
        printf("Invalid ID\n");
        message.id=-1;
        return message;
     }

     //2.validate length and flags based on mode
    if(mode==STANDARD_CAN)
    {
       if(length>CAN_MAX_DATA_LEN || (flags & FDF))
       {
        printf("Invalid lenght and flags for Standard CAN\n");
        message.id=-1; //error marker
        return message;
       }
    }
    if(mode==CAN_FD)
    {
        if(length>CANFD_MAX_DATA_LEN || !(flags & FDF))
        {
            printf("Invalid lenght and flags for CAN FD\n");
            message.id=-1; //error marker
            return message;
        }
    }

    //3.copy data and fill the struct field
    for(int i=0;i<length;i++)
    {
        message.data[i]=data[i];
    }
    message.id = id;
    message.mode = mode;
    message.length = length;
    message.flags = flags;
    message.crc = CRC;
    return message;

}
//prints CAN message
void print_message_info(CAN_message message)
{
    if(message.mode==STANDARD_CAN)
    {
        printf("======Mode: Standard CAN======\n");
        printf("ID : 0x%X\n",message.id);
        printf("Length : %d\n",message.length);
        printf("CRC : 0x%X\n", message.crc);
        printf("Data : ");
        for(int i=0;i<message.length;i++)
        {
            printf("0x%02X ", message.data[i]);
        }
        printf("\n");
        printf("Flags: Not applicable in Standard CAN\n");
        
    }
    if(message.mode==CAN_FD)
    {
        printf("======Mode: CAN FD=======\n");
        printf("ID : 0x%X\n",message.id);
        printf("Length : %d\n",message.length);
        printf("CRC : 0x%X\n", message.crc);
        printf("Data : ");
        for(int i=0;i<message.length;i++)
        {
            printf("0x%02X ", message.data[i]);
        }
        printf("\n");
        if(message.flags & FDF)
        {
            printf("FDF(Flexible Data Format) is SET\n");
        }
        if(message.flags & BRS)
        {
            printf("BRS(Bit Switch Rate) is SET\n");
        }
    }
}
