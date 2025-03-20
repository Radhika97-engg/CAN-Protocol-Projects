This project implements a CAN message encoder and decoder in C, using bitwise operations to pack and unpack CAN frame fields.
It is part of a series of projects designed to reinforce CAN protocol fundamentals.

Features:
✔ Encodes a CAN message into a compact format.
✔ Decodes an encoded message back into its original structure.
✔ Uses bitwise operations to handle ID, DLC, Data, and CRC efficiently.
✔ Prints the original, encoded, and decoded messages for verification.

How to Compile & Run:
You can compile and run the program using GCC (or any C compiler):

Expected Output:
===== ORIGINAL MESSAGE =====  
ID: 0x5A3, DLC: 4, CRC: 0x1234  
Data: 0x40 0x54 0x67 0x11  

===== ENCODED MESSAGE =====  
Packed ID+DLC: 0x5A34, CRC: 0x1234  
Data: 0x40 0x54 0x67 0x11  

===== DECODED MESSAGE =====  
ID: 0x5A3, DLC: 4, CRC: 0x1234  
Data: 0x40 0x54 0x67 0x11  

Key Learnings:
🔹 Bitwise Operations: How to use <<, >>, &, and | for efficient data packing.
🔹 Memory Alignment: Understanding how to pack structs and optimize storage.
🔹 Encoding & Decoding Logic: How CAN messages are processed in automotive systems
