# MiniProject 3: CAN Error Detection & Handling with CRC

This project simulates **bit-level errors** in a CAN message and uses **CRC checking** to detect and classify them. It’s a hands-on implementation of what happens when messages get corrupted in transmission — a **must-know topic** for embedded, automotive, and validation engineers.

## Objective
- Encode a valid CAN frame (ID, DLC, Data, CRC)
- Inject random bit-level errors into the frame
- Perform CRC checks to **detect corruption**
- Identify the **type of error** (form, single-bit, CRC error)
- Log the error information into a file

## Key Concepts Covered

| Component       | Description                                    |
|----------------|-----------------------------------------------  |
| **CAN Frame**  | Struct with ID, DLC, Data, and CRC              |
| **CRC Check**  | Validates integrity of received message         |
| **Error Injection** | Randomly flips a bit in the message        |
| **Error Classification** | Identifies error type (form/bit/CRC)  |
| **Logging**      | Stores error details to a file                |

## Functional Flow
1. Generate a valid CAN message
2. Calculate and attach **CRC**
3. Copy the message and inject a **random error**
4. Perform **CRC check**
5. Classify the type of error
6. Log results to a file (corrupted data, CRC, error type)

## Sample Output
=====Testing CAN frame===== ID: 0x5A3 DLC: 4 DATA: 0x11 0x22 0x33 0x44 CRC: 0xA56B
======CRC check results====== Error Detected - CRC Mismatch Single bit error detected

## File Structure
MiniProject-3_CAN-Error-Handling/ 
├── main.c # Simulates original + corrupted frame 
├── CAN_frame.h # CAN frame definition + CRC + error tools 
├── CAN_crc.c/.h # CRC calculation, checking 
├── error_logger.c/.h # Inject error & log to file 
├── logs.txt # Output log (auto-generated) 
└── README.md # Documentation

## Tools & Language
- Language: **C**
- Platform: Windows / Linux
- Tools: Code: GCC
- Optional: Use of `<windows.h>` for `Sleep()` timing

## What I Learned
- How CRC detects data corruption
- Injecting bit errors manually (simulation-level testing)
- File-based logging for diagnostics
- Embedded-style thinking: **validate every transmission**
- Modular C design with reusable CRC & logger functions

