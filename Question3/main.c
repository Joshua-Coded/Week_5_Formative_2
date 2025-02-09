#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int V = 7;  // Number of vertices (A through G)
    int E = 11; // Number of edges
    
    Graph* graph = createGraph(V, E);
    
    // Adding edges according to the given graph
    // Converting vertices A-G to 0-6 for array indexing
    addEdge(graph, 0, 0, 1, 6);   // A-B: 6
    addEdge(graph, 1, 0, 6, 15);  // A-G: 15
    addEdge(graph, 2, 1, 2, 11);  // B-C: 11
    addEdge(graph, 3, 1, 3, 5);   // B-D: 5
    addEdge(graph, 4, 2, 3, 17);  // C-D: 17
    addEdge(graph, 5, 2, 5, 9);   // C-F: 9
    addEdge(graph, 6, 3, 4, 22);  // D-E: 22
    addEdge(graph, 7, 4, 5, 10);  // E-F: 10
    addEdge(graph, 8, 5, 6, 12);  // F-G: 12
    addEdge(graph, 9, 2, 6, 25);  // C-G: 25
    
    printf("Original Graph:\n");
    printAdjacencyMatrix(graph);
    
    kruskalMST(graph);
    
    free(graph);
    return 0;
}
