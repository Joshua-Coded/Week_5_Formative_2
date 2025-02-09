#include <stdio.h>
#include <stdlib.h>
#include "contact_trace.h"

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    
    // Initialize adjacency matrix with 0s
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addContact(Graph* graph, char person1, char person2, int contactTime) {
    int i = charToIndex(person1);
    int j = charToIndex(person2);
    
    graph->adjMatrix[i][j] = contactTime;
    graph->adjMatrix[j][i] = contactTime;  // Undirected graph
}

BFSResult* performBFS(Graph* graph, int startVertex) {
    BFSResult* result = (BFSResult*)malloc(sizeof(BFSResult));
    int queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;
    
    // Initialize arrays
    for (int i = 0; i < graph->V; i++) {
        result->distances[i] = 0;
        result->visited[i] = 0;
    }
    
    // Start BFS
    queue[rear++] = startVertex;
    result->visited[startVertex] = 1;
    result->max_contact_time = 0;
    result->highest_risk_person = startVertex;
    
    while (front < rear) {
        int currentPerson = queue[front++];
        
        for (int i = 0; i < graph->V; i++) {
            if (graph->adjMatrix[currentPerson][i] > 0 && !result->visited[i]) {
                queue[rear++] = i;
                result->visited[i] = 1;
                result->distances[i] = graph->adjMatrix[currentPerson][i];
                
                // Update highest risk person
                if (graph->adjMatrix[currentPerson][i] > result->max_contact_time) {
                    result->max_contact_time = graph->adjMatrix[currentPerson][i];
                    result->highest_risk_person = i;
                }
            }
        }
    }
    
    return result;
}

void printContactTracing(BFSResult* result, char suspectedPerson) {
    printf("\nContact Tracing Results for Person %c:\n", suspectedPerson);
    printf("Immediate contacts and duration:\n");
    
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (result->visited[i] && result->distances[i] > 0) {
            printf("Person %c: %d minutes of contact\n", indexToChar(i), result->distances[i]);
        }
    }
    
    printf("\nHighest Risk Contact:\n");
    printf("Person %c with %d minutes of contact\n", 
           indexToChar(result->highest_risk_person), 
           result->max_contact_time);
}

int charToIndex(char c) {
    return c - 'A';
}

char indexToChar(int i) {
    return i + 'A';
}
