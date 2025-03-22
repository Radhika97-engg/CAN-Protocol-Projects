# Mini Project 2: CAN Bus Simulation

## Objective
Simulate a basic Controller Area Network (CAN) communication setup in C, where one node logs messages and another node (Node B) filters and reads only relevant messages.

## Project Structure
CAN_logger.c     → Generates random CAN messages and logs them to a file  
CAN_logger.h     → Header file for logger definitions  
CAN_reader.c     → Reads and filters messages for a specific Node ID (e.g., Node B)  
CAN_reader.h     → Header file for reader definitions  
main.c           → Calls the logger and reader functions (simulation entry point)  
can_log.txt      → Generated log file storing messages (ignored in Git)  

## Features
- Random generation of:
  - Message ID (100–500)
  - Data length (1–8 bytes)
  - Data bytes (0x00–0xFF)
  - Timestamps
- Logging messages in a formatted structure
- Reading and filtering only messages addressed to **Node B**
- Debug print statements to trace the program flow
- Optional delay (`sleep`) to simulate real-time message logging

##  Sample Output
[DEBUG] Generated CAN ID: 141
[DEBUG] Generated DATA length: 4
[DEBUG] Generated Data Bytes: BE 84 E1 6C
[DEBUG] Writing to file: 141 BE 84 E1 6C 1742641234

[DEBUG] Checking can_log.txt contents:
[DEBUG] Read ID: 141, Length: 4, Timestamp: 1742641234
Message for Node B: ID: 200, Data: 2F A3 4C 1D Timestamp: 1742645678

## How to Run
1. Open terminal or CMD in the project folder  
2. Compile:
gcc main.c CAN_logger.c CAN_reader.c -o can_simulation
3. Run:
./can_simulation

## Note
- `can_log.txt` is created during simulation — not included in Git.
- `.exe` files are excluded from version control.

## Learnings
- File I/O in C
- Pointer arithmetic and `strchr()` parsing
- Bit-level data simulation
- Simulating embedded-style message logging in C
