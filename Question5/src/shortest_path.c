#include <stdio.h>
#include <stdlib.h>
#include "shortest_path.h"

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*)malloc(E * sizeof(Edge));
    return graph;
}

void addEdge(Graph* graph, int index, char src, char dest, int weight) {
    graph->edges[index].src = charToIndex(src);
    graph->edges[index].dest = charToIndex(dest);
    graph->edges[index].weight = weight;
}

PathResult* bellmanFord(Graph* graph, int src) {
    PathResult* result = (PathResult*)malloc(sizeof(PathResult));
    
    // Initialize distances and predecessors
    for (int i = 0; i < graph->V; i++) {
        result->distances[i] = INF;
        result->predecessor[i] = -1;
    }
    result->distances[src] = 0;
    result->hasNegativeCycle = 0;
    
    // Relax edges |V|-1 times
    for (int i = 1; i <= graph->V - 1; i++) {
        for (int j = 0; j < graph->E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            
            if (result->distances[u] != INF && 
                result->distances[u] + weight < result->distances[v]) {
                result->distances[v] = result->distances[u] + weight;
                result->predecessor[v] = u;
            }
        }
    }
    
    // Check for negative weight cycles
    for (int i = 0; i < graph->E; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        
        if (result->distances[u] != INF && 
            result->distances[u] + weight < result->distances[v]) {
            result->hasNegativeCycle = 1;
            break;
        }
    }
    
    return result;
}

void printPath(PathResult* result, int src, int dest) {
    if (dest == src) {
        printf("%c", indexToChar(src));
        return;
    }
    if (result->predecessor[dest] == -1) {
        printf("No path exists");
        return;
    }
    printPath(result, src, result->predecessor[dest]);
    printf(" -> %c", indexToChar(dest));
}

void printPaths(PathResult* result, int src) {
    printf("\nShortest paths from city %c:\n", indexToChar(src));
    
    if (result->hasNegativeCycle) {
        printf("Graph contains negative weight cycle!\n");
        return;
    }
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (i != src) {
            printf("To %c (Cost: %d): ", indexToChar(i), result->distances[i]);
            printPath(result, src, i);
            printf("\n");
        }
    }
}

int charToIndex(char c) {
    return c - 'A';
}

char indexToChar(int i) {
    return i + 'A';
}
