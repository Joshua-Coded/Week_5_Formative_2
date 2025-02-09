#include <stdio.h>
#include <string.h>
#include "../include/heap.h"

void initHeap(MaxHeap *heap) {
    heap->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        heap->array[i] = 0;
        heap->leaf_codes[i][0] = '\0';
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MaxHeap *heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest])
        largest = left;

    if (right < heap->size && heap->array[right] > heap->array[largest])
        largest = right;

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapify(heap, largest);
    }
}

void buildMaxHeap(MaxHeap *heap) {
    for (int i = (heap->size / 2) - 1; i >= 0; i--)
        heapify(heap, i);
}

void insertNode(MaxHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }

    // Insert at the end
    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Fix the max heap property
    while (i != 0 && heap->array[(i - 1) / 2] < heap->array[i]) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int deleteMax(MaxHeap *heap) {
    if (heap->size <= 0)
        return -1;

    int maxVal = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);

    return maxVal;
}

void generateLeafCodes(MaxHeap *heap) {
    for (int i = 0; i < heap->size; i++) {
        int current = i;
        int parent = (current - 1) / 2;
        char temp[MAX_SIZE] = "";
        char code[MAX_SIZE] = "";
        
        while (current > 0) {
            if (current == 2 * parent + 1) {
                strcat(temp, "0");
            } else {
                strcat(temp, "1");
            }
            current = parent;
            parent = (current - 1) / 2;
        }
        
        // Reverse the code
        int len = strlen(temp);
        for (int j = 0; j < len; j++) {
            code[j] = temp[len - 1 - j];
        }
        code[len] = '\0';
        
        strcpy(heap->leaf_codes[i], code);
    }
}

void printHeap(MaxHeap *heap) {
    printf("Heap array: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");

    printf("Leaf codes:\n");
    for (int i = 0; i < heap->size; i++) {
        printf("Node %d: %s\n", heap->array[i], heap->leaf_codes[i]);
    }
}
