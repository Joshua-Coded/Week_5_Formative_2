#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int size;
    char leaf_codes[MAX_SIZE][MAX_SIZE]; // For storing binary codes
} MaxHeap;

// Function declarations
void initHeap(MaxHeap *heap);
void swap(int *a, int *b);
void heapify(MaxHeap *heap, int index);
void buildMaxHeap(MaxHeap *heap);
void insertNode(MaxHeap *heap, int value);
int deleteMax(MaxHeap *heap);
void generateLeafCodes(MaxHeap *heap);
void printHeap(MaxHeap *heap);

#endif
