#ifndef AUCTION_H
#define AUCTION_H

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char itemName[MAX_NAME_LENGTH];
    double currentBid;
} AuctionItem;

typedef struct {
    AuctionItem items[MAX_ITEMS];
    int size;
} MaxHeap;

// Function declarations
void initHeap(MaxHeap *heap);
void swap(AuctionItem *a, AuctionItem *b);
void heapify(MaxHeap *heap, int index);
void updateBid(MaxHeap *heap, const char *itemName, double newBid);
AuctionItem extractMax(MaxHeap *heap);
void printHeap(MaxHeap *heap);
int findItem(MaxHeap *heap, const char *itemName);

#endif
