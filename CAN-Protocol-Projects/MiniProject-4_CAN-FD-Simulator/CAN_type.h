#ifndef CAN_TYPE_H
#define CAN_TYPE_H

#define CAN_MAX_DATA_LEN 8
#define CANFD_MAX_DATA_LEN 64

typedef enum 
{
    STANDARD_CAN,
    CAN_FD
} CAN_Mode;

typedef enum 
{
    FDF = 1 << 0,
    BRS = 1 << 1
} CAN_Flag;

#endif
