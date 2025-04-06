#ifndef CAN_DECODER_H
#define CAN_DECODER_H
#include<stdint.h>
#include "CAN_type.h"
#include "CAN_message.h"
#include "CAN_encoder.h"

// Decodes a packed encoded_message back into a readable CAN_message by extracting fields from the bit-packed header.
CAN_message decode_CAN_message(encoded_message enc_msg);

#endif
