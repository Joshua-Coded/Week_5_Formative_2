# Max Heap Implementation Project

This project implements a max heap data structure that demonstrates heap operations, binary code generation for nodes, and maintaining the max heap property through insertions and deletions.

## Project Structure
```
project/
├── include/
│   └── heap.h      # Header files with function declarations
├── src/
│   └── heap.c      # Implementation of heap operations
├── main.c          # Main program demonstrating heap operations
├── Makefile        # Build instructions
└── README.md       # Project documentation
```

## Time Complexity Analysis

### Core Operations
1. **Building Max Heap (buildMaxHeap)**
   - Time Complexity: O(n)
   - Despite appearing to be O(n log n), it's actually O(n) due to the structure of a binary heap

2. **Heapify Operation (heapify)**
   - Time Complexity: O(log n)
   - Where n is the number of nodes in the heap
   - This operation maintains the max heap property by recursively adjusting nodes

3. **Insertion (insertNode)**
   - Time Complexity: O(log n)
   - Involves adding at the end and bubbling up to the correct position

4. **Deletion (deleteMax)**
   - Time Complexity: O(log n)
   - Involves removing root and restructuring the heap

5. **Generate Leaf Codes (generateLeafCodes)**
   - Time Complexity: O(n log n)
   - For each node (n), we may need to traverse up to the root (log n)

### Space Complexity
- Overall Space Complexity: O(n)
- Additional space for storing binary codes: O(n log n)
  - Each code can be up to log n bits long
  - We store codes for n nodes

## Features
1. Max Heap Construction
   - Converts array {21,18,85,15,36,75,63,65,90,70,89} into a max heap
   - Maintains parent > children property

2. Binary Code Generation
   - Generates unique binary codes for each node
   - Left child edge: 0
   - Right child edge: 1

3. Dynamic Operations
   - Insertion of new elements (demonstrated with 96)
   - Deletion of maximum element
   - Maintains max heap property after each operation

## Compilation and Usage
1. Compile the project:
   ```bash
   make
   ```

2. Run the program:
   ```bash
   ./heap_program
   ```

3. Clean build files:
   ```bash
   make clean
   ```

## Implementation Details

### Functions
1. `initHeap`
   - Initializes an empty heap structure
   - Time Complexity: O(1)

2. `buildMaxHeap`
   - Converts input array into a max heap
   - Time Complexity: O(n)

3. `heapify`
   - Maintains max heap property
   - Time Complexity: O(log n)

4. `insertNode`
   - Adds new value to heap
   - Time Complexity: O(log n)

5. `deleteMax`
   - Removes and returns maximum value
   - Time Complexity: O(log n)

6. `generateLeafCodes`
   - Creates binary path codes for each node
   - Time Complexity: O(n log n)

7. `printHeap`
   - Displays heap contents and codes
   - Time Complexity: O(n)

## Example Output
The program will display:
1. Original array
2. Max heap after construction
3. Binary codes for each node
4. Heap state after inserting 96
5. Final heap state after deleting 96

## Error Handling
- Checks for heap overflow during insertion
- Validates heap state during deletions
- Returns appropriate error messages for invalid operations

