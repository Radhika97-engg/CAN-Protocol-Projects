#ifndef CAN_FRAME_H 
#define CAN_FRAME_H
#pragma pack(1) // Avoid padding 
// Structure of CAN frame
struct CAN_frame
{
    unsigned int msg_ID;         // Message Identifier [Standard ID - 11 bits/Extended ID - 29 bits]
    unsigned char DLC;           // Data Length -number of bytes in data field)
    unsigned char data[8];       // Data field 
    unsigned int CRC;            // 15-bit CRC for error detection
};
#pragma pack() 
// Calculates a 15-bit CRC for a given CAN frame
unsigned int calculate_crc(struct CAN_frame message);
// Injects a random bit error into the data field 
void inject_error(struct CAN_frame *message);
// Verifies if calculated CRC matches the original CRC
int check_crc(struct CAN_frame message);
// Logs the corrupted message details and error type to a log file
void log_error(struct CAN_frame message, unsigned int modified_crc, int error_type);
// Compares original and modified frame to determine type of error 
int identify_error_type(struct CAN_frame original, struct CAN_frame modified);

#endif
