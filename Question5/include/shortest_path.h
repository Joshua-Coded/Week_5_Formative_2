#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#define MAX_VERTICES 7  // Number of vertices (A through G)
#define INF 99999      // Represents infinity

// Structure to represent an edge
typedef struct Edge {
    int src;
    int dest;
    int weight;
} Edge;

// Structure to represent the graph
typedef struct Graph {
    int V, E;
    Edge* edges;
} Graph;

// Structure to store Bellman-Ford results
typedef struct PathResult {
    int distances[MAX_VERTICES];  // Shortest distances from source
    int predecessor[MAX_VERTICES]; // Predecessor vertices
    int hasNegativeCycle;        // Flag for negative cycle detection
} PathResult;

// Function declarations
Graph* createGraph(int V, int E);
void addEdge(Graph* graph, int index, char src, char dest, int weight);
PathResult* bellmanFord(Graph* graph, int src);
void printPaths(PathResult* result, int src);
int charToIndex(char c);
char indexToChar(int i);
void printPath(PathResult* result, int src, int dest);

#endif
