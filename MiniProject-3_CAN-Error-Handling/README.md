# CAN Protocol Mini Project: Error Detection & Classification

This mini project demonstrates **error handling in CAN communication**, simulating how an embedded system detects and classifies data integrity issues in a CAN frame using **custom CRC logic** and **bit-level analysis**.

## Key Highlights
-  Simulates Real-World Automotive Scenarios
-  Detects & Classifies Errors: Form, Single Bit, CRC (Multi-Bit)
-  Low-level C Implementation (no external libraries)
-  Generates structured logs (`can_log.txt`) for debugging

## Technologies & Skills Demonstrated

- **Embedded C** | Bitwise Operations | Custom CRC (15-bit)
- **Protocol Simulation** | Data Corruption Testing
- **Error Logging** | Defensive Programming
- **Modular Code Design** using Header & Source files

## What This Project Does

| Feature                | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| `calculate_crc()`      | Simulates 15-bit CRC to verify frame integrity                              |
| `inject_error()`       | Randomly flips one bit in the data payload                                  |
| `check_crc()`          | Compares original vs. recalculated CRC                                      |
| `identify_error_type()`| Classifies errors into Form, Single Bit, or CRC Error                       |
| `log_error()`          | Logs ID, Data, CRC values, and Error Type to a text file                    |


## Project Structure

MiniProject-3_CAN-Error-Handling/ ├── CAN_frame.c // Core logic ├── CAN_frame.h // Structs & declarations ├── main.c // Simulation runner ├── can_log.txt // Output log └── README.md // Project documentation

## Run the Project

### Compile:
gcc main.c CAN_frame.c -o can_error_handler.exe

## Sample Log Output
ID: 0x5A3
DATA: 0x91 0x22 0x33 0x44
Original CRC: 0xE6
Recalculated CRC: 0x66
Error Type: Single Bit Error

## Potential Enhancements
Classify all 5 CAN error types (bit, stuff, form, ack, CRC)
Add real-time error logging using timestamps
Implement a visual dashboard for error stats
Simulate acknowledgment errors across nodes
Extend support to CAN-FD frames
