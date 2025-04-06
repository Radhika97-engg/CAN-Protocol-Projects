# MiniProject 1: CAN Encoder & Decoder (Bit-Level Packing)
This project demonstrates how **CAN (Controller Area Network)** messages are **encoded and decoded** at the bit level using C. It simulates real-world low-level automotive data handling — a critical skill in embedded systems and automotive software roles.

## Project Goals
- Understand how CAN messages are structured (ID, DLC, Data, CRC).
- Use bit manipulation to **pack and unpack** message fields.
- Gain practical skills for **serialization & deserialization**.
- Learn how to implement and test **message integrity** handling.

## Project Structure

| Field     | Description                                   |
|-----------|-----------------------------------------------|
| `ID`      | 11-bit identifier for the CAN message          |
| `DLC`     | 4-bit Data Length Code (0–8 bytes)             |
| `Data`    | Up to 8 bytes of payload                       |
| `CRC`     | 15-bit simulated CRC for error-checking        |

Two structures are used:
- `CAN_frame` — raw structured message.
- `CAN_frame_merged` — bit-packed version for transmission.

## How It Works
1. **Encoding:**
   - Packs the 11-bit ID and 4-bit DLC into a 16-bit field.
   - Copies data and CRC into the merged frame.
2. **Decoding:**
   - Unpacks ID and DLC using bitwise operations.
   - Restores data and CRC to original structure.

## Sample Output
=====Original message====== ID: 0x5A3, DLC : 4, CRC : 0x1234 Data: 0x40 0x54 0x67 0x11
=====Encoded message====== Packed ID + DLC: 0x5A34, CRC : 0x1234 0x40 0x54 0x67 0x11
=====Encoded message====== ID: 0x5A3, DLC: 4, CRC : 0x1234 0x40 0x54 0x67 0x11

## File Overview
MiniProject-1_CAN-Encoder-Decoder/ 
├── main.c # Runs encoding & decoding simulation 
├── README.md # Project documentation

## Tools Used
- Language: **C**
- Compiler: GCC or any C compiler
- Platform: Windows / Linux Terminal

## What I Learned
- Bit-level data handling in C
- Message encoding & field extraction
- Struct alignment using `#pragma pack`
- Applying AND / SHIFT operations for embedded efficiency



