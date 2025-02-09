#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* createGraph(int V, int E) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

void addEdge(Graph* graph, int index, int src, int dest, int weight) {
    graph->edges[index].src = src;
    graph->edges[index].dest = dest;
    graph->edges[index].weight = weight;
}

DisjointSet* createSet(int V) {
    DisjointSet* set = (DisjointSet*)malloc(sizeof(DisjointSet));
    for (int i = 0; i < V; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
    return set;
}

int find(DisjointSet* set, int i) {
    if (set->parent[i] != i)
        set->parent[i] = find(set, set->parent[i]);
    return set->parent[i];
}

void Union(DisjointSet* set, int x, int y) {
    int xroot = find(set, x);
    int yroot = find(set, y);
    
    if (set->rank[xroot] < set->rank[yroot])
        set->parent[xroot] = yroot;
    else if (set->rank[xroot] > set->rank[yroot])
        set->parent[yroot] = xroot;
    else {
        set->parent[yroot] = xroot;
        set->rank[xroot]++;
    }
}

// Compare function for qsort
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void kruskalMST(Graph* graph) {
    Edge result[MAX_VERTICES - 1];  // MST will have V-1 edges
    int e = 0;  // Index for result[]
    int i = 0;  // Index for sorted edges
    int totalCost = 0;

    // Sort edges by weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    DisjointSet* set = createSet(graph->V);

    while (e < graph->V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];
        int x = find(set, next_edge.src);
        int y = find(set, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(set, x, y);
            totalCost += next_edge.weight;
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        printf("%c - %c: %d\n", 
               result[i].src + 'A', 
               result[i].dest + 'A', 
               result[i].weight);
    }
    printf("Total cost of MST: %d\n", totalCost);

    free(set);
}

void printAdjacencyMatrix(Graph* graph) {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    
    // Fill the adjacency matrix
    for (int i = 0; i < graph->E; i++) {
        int src = graph->edges[i].src;
        int dest = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        adjMatrix[src][dest] = weight;
        adjMatrix[dest][src] = weight;  // Undirected graph
    }
    
    printf("\nAdjacency Matrix:\n");
    printf("   A  B  C  D  E  F  G\n");
    for (int i = 0; i < graph->V; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < graph->V; j++) {
            printf("%3d", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
