# MiniProject 2: CAN Bus Message Simulation
This project simulates a **basic CAN Bus communication model** in C. It allows encoding multiple CAN messages, storing them in a virtual bus array, and simulating message transfer between sender and receiver — just like a real vehicle's ECU network.

## Objective
- Simulate how **CAN messages are transmitted** between ECUs.
- Encode/decode multiple messages using bitwise packing.
- Learn how data moves through a **bus-like structure**.
- Lay the foundation for future projects like arbitration, filtering, or error handling.

## Key Features
- Define and encode CAN messages (ID, DLC, Data, CRC)
- Simulate a message bus (using arrays)
- Decode messages at the receiver end
- Validate message transfer and integrity
- Show packed headers in binary (for debugging)

## CAN Frame Format

| Field     | Description                                     |
|-----------|-------------------------------------------------|
| `ID`      | 11-bit Standard CAN ID                          |
| `DLC`     | Data Length Code (4 bits for 0–8 bytes)         |
| `Data[]`  | Payload (up to 8 bytes per message)             |
| `CRC`     | Simulated CRC (15-bit stored as 16-bit)         |
| `Header`  | 16-bit field = ID (11 bits) + DLC (4 bits)      |

## Simulation Logic
1. **Message Encoding:**
   - Pack `ID` + `DLC` into one field using bitwise logic.
   - Store into a simulated bus (array of `struct`).

2. **Message Transfer:**
   - Receiver reads from the bus and decodes message.

3. **Validation:**
   - Print decoded info and match with original.

## Project Structure
MiniProject-2_CAN-Bus-Simulation/ 
├── main.c # Simulation driver code
├── encoder.c/.h # Packs CAN messages
├── decoder.c/.h # Decodes CAN messages
├── bus.c/.h # Simulated CAN Bus logic 
├── CAN_type.h # Enum for modes/flags 
└── README.md # Project overview

## Sample Output
=== Message Sent === ID: 0x245, Length: 3 Data: 0x11 0x22 0x33 Packed Header: 0x2453
=== Message Received === Decoded ID: 0x245 Decoded DLC: 3 Payload: 0x11 0x22 0x33 CRC: 0xA55A

## What I Learned
- Simulating real-world ECU-to-ECU communication
- Structuring modular code in C
- Implementing message buses in embedded-like systems
- Mastering bitwise operations and custom data packing

## Tech Stack
- Language: **C**
- Compiler: GCC 
- Platform: Windows CMD / Linux terminal

