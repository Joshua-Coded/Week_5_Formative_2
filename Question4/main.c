#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "contact_trace.h"

int main() {
    Graph* graph = createGraph(7);  // 7 people (A through G)
    
    // Add contact times from the graph
    addContact(graph, 'A', 'B', 6);
    addContact(graph, 'A', 'G', 15);
    addContact(graph, 'B', 'C', 11);
    addContact(graph, 'B', 'D', 5);
    addContact(graph, 'C', 'D', 17);
    addContact(graph, 'C', 'F', 9);
    addContact(graph, 'D', 'E', 22);
    addContact(graph, 'E', 'F', 10);
    addContact(graph, 'F', 'G', 12);
    addContact(graph, 'C', 'G', 25);
    
    char suspectedPerson;
    while (1) {
        printf("\nEnter suspected person (A-G) or Q to quit: ");
        scanf(" %c", &suspectedPerson);
        suspectedPerson = toupper(suspectedPerson);
        
        if (suspectedPerson == 'Q') {
            break;
        }
        
        if (suspectedPerson < 'A' || suspectedPerson > 'G') {
            printf("Invalid input. Please enter a person between A and G.\n");
            continue;
        }
        
        BFSResult* result = performBFS(graph, charToIndex(suspectedPerson));
        printContactTracing(result, suspectedPerson);
        free(result);
    }
    
    free(graph);
    return 0;
}
