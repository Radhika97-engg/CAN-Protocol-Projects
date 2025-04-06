#ifndef CAN_TYPES_H
#define CAN_TYPES_H

#define CAN_MAX_DATA_LEN 8
#define CANFD_MAX_DATA_LEN 64

typedef enum
{
    STANDARD_CAN,
    CAN_FD,
} CAN_Mode;

//CAN FD FLAG
//In CAN FD two optional bits are used (FDF, BRS)
//FDF- Flexible Data Format Required for a message to be FD
//BRS-Bit Rate Switch  -switches speed during data phase

typedef enum
{
    NO_FLAG =0, //00000000
    FDF = 1<<0,   //00000001
    BRS  = 1<<1   //00000010 
}CAN_Flag;

#endif