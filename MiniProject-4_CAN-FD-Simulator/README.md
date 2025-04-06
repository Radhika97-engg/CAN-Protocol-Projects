# MiniProject 4: CAN FD Message Simulator

This project simulates the encoding and decoding of **CAN FD (Flexible Data Rate)** messages in C. Unlike traditional CAN (8-byte max), CAN FD supports **up to 64 bytes of data**, making it essential for modern automotive systems.

This simulation demonstrates how messages are structured, packed into a 32-bit header, and decoded — supporting both **Standard CAN** and **CAN FD** modes with `FDF` and `BRS` flags.

## Project Goals
- Support both **Standard CAN** and **CAN FD**
- Pack message metadata (ID, DLC, mode, flags) into a 32-bit header
- Handle data payload up to 64 bytes
- Encode and decode messages properly
- Validate message parameters and simulate CRC field
- Print the packed header in **binary** for debugging

## Key Concepts Demonstrated

| Feature           | Description                                      |
|------------------|---------------------------------------------------|
| ✅ Standard & FD  | Supports both 11-bit Standard CAN and CAN FD     |
| ✅ Flag Handling  | Encodes and decodes FDF and BRS flags            |
| ✅ Bit Packing    | Header = ID + DLC + Mode + Flags (32 bits)       |
| ✅ CRC Simulation | Placeholder 16-bit CRC field                     |
| ✅ Input Check    | Validates ID, length, and flag correctness       |
| ✅ Binary Output  | Prints 32-bit header for debugging               |

## Header Format (Packed 32-bits)

| Bits     | Field      | Description                                  |
|----------|------------|----------------------------------------------|
| 31–21    | ID         | 11-bit CAN identifier                        |
| 20–15    | DLC        | Data Length Code (up to 64 bytes)            |
| 14       | FDF        | Set = CAN FD format                          |
| 13       | BRS        | Bit Rate Switch enabled                      |
| 12–0     | Reserved   | Currently unused                             |

## Project Structure
MiniProject-4_CAN-FD-Simulator/ 
├── main.c # Driver: encode → decode → validate 
├── CAN_type.h # Enum for CAN mode and flag definitions
├── CAN_message.h/.c # Message structure + validation functions 
├── CAN_encoder.h/.c # Header packing + binary printer 
├── CAN_decoder.h/.c # Header unpacking, flag restoration 
├── README.md # Project documentation

## Encode → Decode Flow
CAN_message msg = create_message(...);          // Create CAN or CAN FD message
encoded_message enc = encode_CAN_message(msg);  // Pack into 32-bit header + data
CAN_message decoded = decode_CAN_message(enc);  // Extract all fields back
print_message_info(decoded);                    // Show decoded fields
print_binary(enc.header);                       // Debug the header

Original message
======Mode: CAN FD=======
ID : 0x5A3
Length : 4
CRC : 0xABCD
Data : 0x11 0x22 0x33 0x44 
FDF(Flexible Data Format) is SET
BRS(Bit Switch Rate) is SET
Header in Binary: 10110100011000010000000000000000

## Tech Stack
Language: C
Platform: Windows / Linux
Tools: Code:GCC

## What I Learned
Structuring flexible message formats using struct
Bitwise header encoding/decoding
Flag masking and shifting logic
Designing clean modular code (message.c, encoder.c, decoder.c)
Validating message fields dynamically before transmission



