#include <stdio.h>
#include <stdlib.h>
#include "shortest_path.h"

int main() {
    int V = 7;  // Number of vertices (A through G)
    int E = 10; // Number of edges
    
    Graph* graph = createGraph(V, E);
    
    // Add all edges from the graph
    addEdge(graph, 0, 'A', 'B', 6);
    addEdge(graph, 1, 'A', 'G', 15);
    addEdge(graph, 2, 'B', 'C', 11);
    addEdge(graph, 3, 'B', 'D', 5);
    addEdge(graph, 4, 'C', 'D', 17);
    addEdge(graph, 5, 'C', 'F', 9);
    addEdge(graph, 6, 'D', 'E', 22);
    addEdge(graph, 7, 'E', 'F', 10);
    addEdge(graph, 8, 'F', 'G', 12);
    addEdge(graph, 9, 'C', 'G', 25);
    
    // Find shortest paths from city A
    PathResult* result = bellmanFord(graph, charToIndex('A'));
    
    // Print all shortest paths from A
    printPaths(result, charToIndex('A'));
    
    // Cleanup
    free(result);
    free(graph->edges);
    free(graph);
    
    return 0;
}
