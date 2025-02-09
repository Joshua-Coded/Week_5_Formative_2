# Auction Bidding System Implementation

## Overview
This implementation demonstrates an auction bidding system using a max heap data structure. The system manages multiple items, tracks the highest bids, and maintains a priority queue of items based on bid amounts.

## Problem Statement
Build an auction system where:
- Multiple items can be bid on (table, fridge, kettle, sofa sets, office chairs, TV)
- Only the highest bid for each item is maintained
- Items should be retrievable in order of bid amount
- System should efficiently update and track highest bids

## Project Structure
```
auction-system/
├── include/
│   └── auction.h       # Header files and data structures
├── src/
│   └── auction.c       # Implementation of auction operations
├── main.c             # Main program and example usage
├── Makefile          # Build instructions
└── README.md         # Project documentation
```

## Time Complexity Analysis

### Core Operations
1. **Bid Update (updateBid)**
   - Best Case: O(1) - New bid is smaller than current
   - Worst Case: O(log n) - When bid needs to bubble up to root
   - Space: O(1)

2. **Find Item (findItem)**
   - Time: O(n) - Linear search through items
   - Space: O(1)

3. **Extract Maximum (extractMax)**
   - Time: O(log n) - Remove root and heapify
   - Space: O(1)

4. **Heapify**
   - Time: O(log n) - Traverse down the heap
   - Space: O(log n) - Recursive call stack

### Overall Complexity
- Time Complexity: O(log n) for most operations
- Space Complexity: O(n) for storing n items

## Features
1. Bid Management
   - Add new items with bids
   - Update bids for existing items
   - Automatically maintain highest bid per item

2. Priority Queue
   - Extract items in order of bid amount
   - Maintain heap property after operations
   - Efficient updates and retrievals

3. Error Handling
   - Duplicate item prevention
   - Lower bid rejection
   - Heap overflow protection

## How to Build and Run

### Prerequisites
- GCC Compiler
- Make utility
- Unix-like environment (Linux/MacOS) or Windows with MinGW

### Compilation
1. Clone or download the project
2. Navigate to project directory
3. Compile using make:
```bash
make
```

### Running the Program
Execute the compiled program:
```bash
./auction_program
```

### Cleaning Build Files
Remove compiled files:
```bash
make clean
```

## Usage Example
```c
// Initialize auction system
MaxHeap auctionHeap;
initHeap(&auctionHeap);

// Place bids
updateBid(&auctionHeap, "TV", 1000.0);
updateBid(&auctionHeap, "Kettle", 50.0);

// Update with higher bid
updateBid(&auctionHeap, "TV", 1500.0);

// Extract highest bid item
AuctionItem highest = extractMax(&auctionHeap);
```

## Sample Output
```
Initial Auction Status:
----------------------
TV: $1000.00
Sofa Set: $1200.00
Fridge: $800.00
Office Chair: $300.00
Table: $150.00
Kettle: $50.00

After New Bids:
----------------------
TV: $1500.00
Sofa Set: $1200.00
Fridge: $800.00
Office Chair: $300.00
Table: $150.00
Kettle: $75.00
```

## Implementation Details
1. **Data Structures**
   ```c
   typedef struct {
       char itemName[MAX_NAME_LENGTH];
       double currentBid;
   } AuctionItem;

   typedef struct {
       AuctionItem items[MAX_ITEMS];
       int size;
   } MaxHeap;
   ```

2. **Key Functions**
   - `initHeap`: Initialize empty heap
   - `updateBid`: Update/add new bid
   - `extractMax`: Remove highest bid item
   - `heapify`: Maintain heap property

## Error Handling
1. Heap Overflow
   ```c
   if (heap->size >= MAX_ITEMS) {
       printf("Heap is full!\n");
       return;
   }
   ```

2. Invalid Operations
   - Checks for NULL pointers
   - Validates bid amounts
   - Handles empty heap conditions

