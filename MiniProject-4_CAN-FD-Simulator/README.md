# MiniProject 4: CAN FD Message Simulator

This project simulates the encoding and decoding of **CAN FD (Flexible Data Rate)** messages in C. Unlike traditional CAN (8-byte max), CAN FD supports **up to 64 bytes of data**, making it essential for modern automotive systems.

This simulation demonstrates how messages are structured, packed into a 32-bit header, and decoded — supporting both **Standard CAN** and **CAN FD** modes with `FDF` and `BRS` flags.

## Project Goals
- Support both **Standard CAN** and **CAN FD**<br>
- Pack message metadata (ID, DLC, mode, flags) into a 32-bit header<br>
- Handle data payload up to 64 bytes<br>
- Encode and decode messages properly<br>
- Validate message parameters and simulate CRC field<br>
- Print the packed header in **binary** for debugging<br>

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
MiniProject-4_CAN-FD-Simulator/ <br>
├── main.c # Driver: encode → decode → validate <br>
├── CAN_type.h # Enum for CAN mode and flag definitions<br>
├── CAN_message.h/.c # Message structure + validation functions <br>
├── CAN_encoder.h/.c # Header packing + binary printer <br>
├── CAN_decoder.h/.c # Header unpacking, flag restoration <br>
├── README.md # Project documentation<br>

## Encode → Decode Flow  <br>
CAN_message msg = create_message(...);                // Create CAN or CAN FD message <br>
encoded_message enc = encode_CAN_message(msg);        // Pack into 32-bit header + data <br>
CAN_message decoded = decode_CAN_message(enc);        // Extract all fields back <br>
print_message_info(decoded);                          // Show decoded fields <br>
print_binary(enc.header);                             // Debug the header<br>

Original message<br>
======Mode: CAN FD=======<br>
ID : 0x5A3 <br>
Length : 4<br>
CRC : 0xABCD<br>
Data : 0x11 0x22 0x33 0x44 <br>
FDF(Flexible Data Format) is SET<br>
BRS(Bit Switch Rate) is SET<br>
Header in Binary: 10110100011000010000000000000000<br>

## Tech Stack
Language: C<br>
Platform: Windows / Linux<br>
Tools: Code:GCC<br>

## What I Learned
Structuring flexible message formats using struct <br>
Bitwise header encoding/decoding<br>
Flag masking and shifting logic<br>
Designing clean modular code (message.c, encoder.c, decoder.c)<br>
Validating message fields dynamically before transmission<br>



