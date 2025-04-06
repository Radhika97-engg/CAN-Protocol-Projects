#include<stdint.h>
#include "CAN_type.h"
#include "CAN_message.h"
#include "CAN_encoder.h"
//Extracts a full CAN_message from the bit-packed encoded_message.
CAN_message decode_CAN_message(encoded_message enc_msg)
{
    CAN_message in_msg;
    //1. Extract ID (Bits 31–21)   
    in_msg.id= (enc_msg.header>>21) & 0x7FF;
    //2. Extract DLC (Bits 20–15)
    in_msg.length= (enc_msg.header>>15) & 0x3F;
    // 3. Extract Mode (Bit 14)
    in_msg.mode = ((enc_msg.header>>14) & 0x01) ==1 ? CAN_FD:STANDARD_CAN;
    // 4. Copy Payload Data  
    for(int i=0;i<in_msg.length;i++)
    {
    in_msg.data[i] = enc_msg.data[i];
    }
    //5. Extract Flags (Bits 14–13)
    CAN_Flag extracted_flags=0;
    if((enc_msg.header>>14) & 0x01)
        extracted_flags |=FDF;
    if((enc_msg.header>>13)& 0x01)
       extracted_flags |=BRS;
    in_msg.flags= extracted_flags;
    //6.copy CRC
    in_msg.crc=enc_msg.CRC;
    return in_msg;
}
