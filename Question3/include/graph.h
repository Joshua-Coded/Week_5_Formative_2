#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 7  // Number of vertices (A through G)
#define MAX_EDGES 11    // Number of edges in the graph

// Structure to represent an edge
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Structure to represent a graph
typedef struct Graph {
    int V, E;
    Edge edges[MAX_EDGES];
} Graph;

// Structure for disjoint sets
typedef struct DisjointSet {
    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
} DisjointSet;

// Function declarations
Graph* createGraph(int V, int E);
void addEdge(Graph* graph, int index, int src, int dest, int weight);
DisjointSet* createSet(int V);
int find(DisjointSet* set, int i);
void Union(DisjointSet* set, int x, int y);
void kruskalMST(Graph* graph);
void printAdjacencyMatrix(Graph* graph);

#endif
