#include <stdio.h>
#include <string.h>
#include "../include/auction.h"

void initHeap(MaxHeap *heap) {
    heap->size = 0;
}

void swap(AuctionItem *a, AuctionItem *b) {
    AuctionItem temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->items[left].currentBid > heap->items[largest].currentBid)
        largest = left;

    if (right < heap->size && heap->items[right].currentBid > heap->items[largest].currentBid)
        largest = right;

    if (largest != index) {
        swap(&heap->items[index], &heap->items[largest]);
        heapify(heap, largest);
    }
}

int findItem(MaxHeap *heap, const char *itemName) {
    for (int i = 0; i < heap->size; i++) {
        if (strcmp(heap->items[i].itemName, itemName) == 0) {
            return i;
        }
    }
    return -1;
}

void updateBid(MaxHeap *heap, const char *itemName, double newBid) {
    int index = findItem(heap, itemName);
    
    if (index == -1) {  // New item
        if (heap->size >= MAX_ITEMS) {
            printf("Heap is full!\n");
            return;
        }
        strcpy(heap->items[heap->size].itemName, itemName);
        heap->items[heap->size].currentBid = newBid;
        
        // Fix the heap property upward
        int current = heap->size;
        while (current > 0 && heap->items[(current-1)/2].currentBid < heap->items[current].currentBid) {
            swap(&heap->items[current], &heap->items[(current-1)/2]);
            current = (current-1)/2;
        }
        
        heap->size++;
    } else {  // Existing item
        if (newBid > heap->items[index].currentBid) {
            heap->items[index].currentBid = newBid;
            
            // Fix the heap property
            int current = index;
            while (current > 0 && heap->items[(current-1)/2].currentBid < heap->items[current].currentBid) {
                swap(&heap->items[current], &heap->items[(current-1)/2]);
                current = (current-1)/2;
            }
        }
    }
}

AuctionItem extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        AuctionItem empty = {"", 0.0};
        return empty;
    }

    AuctionItem maxItem = heap->items[0];
    heap->items[0] = heap->items[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return maxItem;
}

void printHeap(MaxHeap *heap) {
    printf("\nCurrent Auction Status:\n");
    printf("----------------------\n");
    for (int i = 0; i < heap->size; i++) {
        printf("%s: $%.2f\n", heap->items[i].itemName, heap->items[i].currentBid);
    }
    printf("\n");
}

