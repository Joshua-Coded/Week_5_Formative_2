# Max Heap Implementation Project

This project implements a max heap data structure with the following features:
- Building a max heap from an array
- Generating binary codes for leaf nodes
- Inserting new elements
- Deleting the maximum element

## Project Structure
```
project/
├── include/
│   └── heap.h
├── src/
│   └── heap.c
├── main.c
├── Makefile
└── README.md
```

## Compilation and Usage
1. To compile the project:
   ```bash
   make
   ```
2. To run the program:
   ```bash
   ./heap_program
   ```
3. To clean build files:
   ```bash
   make clean
   ```

## Implementation Details
1. The program starts with the array {21,18,85,15,36,75,63,65,90,70,89}
2. Builds a max heap from this array
3. Generates binary codes for each node (0 for left edge, 1 for right edge)
4. Demonstrates insertion of 96
5. Demonstrates deletion of 96

## Functions
- `initHeap`: Initializes an empty heap
- `buildMaxHeap`: Converts an array into a max heap
- `heapify`: Maintains the max heap property
- `insertNode`: Inserts a new value into the heap
- `deleteMax`: Removes and returns the maximum value
- `generateLeafCodes`: Generates binary codes for each node
- `printHeap`: Displays the heap and leaf codes
