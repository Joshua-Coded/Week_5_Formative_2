#include <stdio.h>
#include "include/heap.h"

int main() {
    MaxHeap heap;
    initHeap(&heap);

    // Initial array
    int initial_array[] = {21, 18, 85, 15, 36, 75, 63, 65, 90, 70, 89};
    int array_size = sizeof(initial_array) / sizeof(initial_array[0]);

    // Build initial heap
    for (int i = 0; i < array_size; i++) {
        heap.array[i] = initial_array[i];
    }
    heap.size = array_size;

    printf("Original array:\n");
    printHeap(&heap);

    printf("\nBuilding max heap...\n");
    buildMaxHeap(&heap);
    printHeap(&heap);

    printf("\nGenerating leaf codes...\n");
    generateLeafCodes(&heap);
    printHeap(&heap);

    printf("\nInserting 96...\n");
    insertNode(&heap, 96);
    printHeap(&heap);

    printf("\nDeleting 96...\n");
    deleteMax(&heap);
    printHeap(&heap);

    return 0;
}

