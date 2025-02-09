#ifndef CONTACT_TRACE_H
#define CONTACT_TRACE_H

#define MAX_VERTICES 7  // Number of vertices (A through G)
#define MAX_QUEUE_SIZE 100

// Structure to represent the graph
typedef struct Graph {
    int V;  // Number of vertices
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];  // Adjacency matrix
} Graph;

// Structure to store BFS result
typedef struct BFSResult {
    int distances[MAX_VERTICES];  // Contact duration to each person
    int visited[MAX_VERTICES];    // Track visited nodes
    int highest_risk_person;      // Person with longest contact duration
    int max_contact_time;         // Longest contact duration
} BFSResult;

// Function declarations
Graph* createGraph(int V);
void addContact(Graph* graph, char person1, char person2, int contactTime);
BFSResult* performBFS(Graph* graph, int startVertex);
void printContactTracing(BFSResult* result, char suspectedPerson);
int charToIndex(char c);
char indexToChar(int i);

#endif
