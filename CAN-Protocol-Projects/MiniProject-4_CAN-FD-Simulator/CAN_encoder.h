#ifndef CAN_ENCODER_H
#define CAN_ENCODER_H
#include "CAN_type.h"
#include "CAN_message.h"
#include<stdint.h>

//Encoded CAN Message Format (Packed)

typedef struct encoded_message
{
// Header: 32-bit packed field with the following layout:
// Bits 31–21 : 11-bit CAN ID
// Bits 20–15 : DLC (Data Length Code)
// Bit  14    : Mode (0 = Standard CAN, 1 = CAN FD)
// Bit  13    : BRS (Bit Rate Switch)
// Bits 12–0  : Reserved (optional, currently unused)
 uint32_t header; 
// - Standard CAN: Max 8 bytes
// - CAN FD: Max 64 bytes
 uint8_t data[64]; 
 // Simulated CRC (copied directly from CAN_message)
uint16_t CRC; 
}encoded_message;
// Encodes a CAN_message into an encoded_message by packing ID, length, mode, and flags into the header.
encoded_message encode_CAN_message(CAN_message msg);
// Utility function to print a 32-bit value in binary format Useful for debugging the bit-packing structure.
void print_binary(uint32_t value);
#endif 