#ifndef HEAP_H
#define HEAP_H

#define MAX_SIZE 100

typedef struct {
int arr[MAX_SIZE];
int size;
char left_chars[MAX_SIZE] // stores characters for leaf nodes
} MaxHeap;

/* Core heap operations */

void initHeap(MaxHeap *heap);
void swap(int *a, int *b);
void heapify(MaxHeap *heap, int idx);
void buildMaxHeap(MaxHeap *heap);
void insertNode(MaxHeap *heap, int key);
int deleteMax(MaxHeap *heap);
void assignLeafChars(MaxHeap *heap);
void generateCodes(MaxHeap *heap, int index, char *code, int depth);
void printHeap(MaxHeap *heap);

#endif
