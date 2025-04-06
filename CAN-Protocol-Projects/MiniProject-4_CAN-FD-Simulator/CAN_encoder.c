#include<stdint.h>
#include<stdio.h>
#include "CAN_type.h"
#include "CAN_message.h"
#include "CAN_encoder.h"
//encode CAN message: packs a CAN message into a compressed 32 bit header + payload+ CRC
encoded_message encode_CAN_message(CAN_message msg)
{
    encoded_message enco_msg;
    //1.construct packed header
    // Bit Mapping:
    // Bits 31–21 : ID (11 bits)
    // Bits 20–15 : Length (6 bits)
    // Bit  14    : FDF flag (set if msg.flags & FDF)
    // Bit  13    : BRS flag (set if msg.flags & BRS)
    enco_msg.header = (msg.id << 21) | (msg.length << 15) | ((msg.flags & FDF) ? (1 << 14) : 0) | ((msg.flags & BRS) ? (1 << 13) : 0);
    //2. Copy Data Bytes to Frame
    for(int i=0;i<msg.length;i++)
    {
    enco_msg.data[i] = msg.data[i];
    }
    // 3. Copy CRC to Encoded Frame
    enco_msg.CRC= msg.crc;
    return enco_msg;
}
//print a 32-bit header as binary to verify packed fields.
void print_binary(uint32_t value)
{
    printf("Header in Binary ");
    for(int i=31;i>=0;i--)
    {
        printf("%d", (value>>i)&1);
    }

}
