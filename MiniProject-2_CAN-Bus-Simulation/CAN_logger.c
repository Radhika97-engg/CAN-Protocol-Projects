#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CAN_logger.h"

void generate_random_can_message(struct CAN_message *msg)
{
   msg->ID = 100+(rand() % 401);   //Generates ID from 100 to 500
   printf("[DEBUG] Generated CAN ID: %d\n", msg->ID);
   msg->data_length=1+(rand() % MAX_DATA_LENGTH);  // Data length from 1 to 8
   printf("[DEBUG] Generated DATA length: %d\n", msg->data_length);
   msg->timestamp=time(NULL); //Current system time
   printf("[DEBUG] Generated timestamp: %ld\n", msg->timestamp);
   printf("[DEBUG] Generated Data Bytes: "); // fill data array with random bytes
   for(int i=0;i<msg->data_length;i++)
   {
    msg->Data[i]=rand() % 256;  // Random byte (0x00 - 0xFF)
    printf("%02X ",msg->Data[i]); //print in hex format
   }
   printf("\n");
}

void write_can_message_to_file(struct CAN_message *msg)
{
    FILE *file = fopen("can_log.txt","a");
    if(file==NULL)
    {
        printf("[ERROR] could not open file for writing. \n");
        return;
    }
    printf("[DEBUG] Writing to file: %d ", msg->ID);
    fprintf(file, "%d %d ",msg->ID,msg->data_length); //write CAN_ID
    for(int i=0;i<msg->data_length;i++) //write databyte in HEX format
    {
        printf("%02X ", msg->Data[i]);  // Debug Print
        fprintf(file, "%02x ", msg->Data[i]);
    }
    printf("[DEBUG] writing timstamp: %ld\n", msg->timestamp);
    fprintf(file,"%ld\n",msg->timestamp); //write timestamp

  fclose(file);
}