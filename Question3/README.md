# Minimum Spanning Tree Implementation Using Kruskal's Algorithm

## Project Overview
This implementation finds the Minimum Spanning Tree (MST) of an undirected weighted graph using Kruskal's Algorithm. The program is specifically designed to solve a network routing problem where vertices represent routers (A through G) and edges represent connection costs between them.

## Graph Specification
The input graph consists of:
- Vertices (V) = 7 (labeled A through G)
- Edges (E) = 11
- Edge weights as follows:
  ```
  A-B: 6
  A-G: 15
  B-C: 11
  B-D: 5
  C-D: 17
  C-F: 9
  D-E: 22
  E-F: 10
  F-G: 12
  C-G: 25
  ```

## Project Structure
```
.
├── include/
│   └── graph.h         # Header files containing data structures and function declarations
├── src/
│   └── graph.c         # Implementation of graph operations and Kruskal's algorithm
├── main.c              # Main program file
├── Makefile            # Build configuration
└── README.md           # Project documentation
```

## Compilation and Execution Instructions
1. Create necessary directories:
   ```bash
   make init
   ```

2. Compile the program:
   ```bash
   make
   ```

3. Run the executable:
   ```bash
   ./mst_program
   ```

4. Clean build files:
   ```bash
   make clean
   ```

## Time Complexity Analysis
1. Kruskal's Algorithm:
   - Sorting edges: O(E log E)
   - Find-Union operations: O(E log V)
   - Overall complexity: O(E log E) where E is the number of edges

2. Space Complexity:
   - Adjacency Matrix: O(V²)
   - Edge List: O(E)
   - Disjoint Set: O(V)
   - Overall space complexity: O(V² + E)

## Implementation Details

### Data Structures
1. Graph representation:
   ```c
   typedef struct Graph {
       int V, E;
       Edge edges[MAX_EDGES];
   } Graph;
   ```

2. Edge structure:
   ```c
   typedef struct Edge {
       int src;
       int dest;
       int weight;
   } Edge;
   ```

3. Disjoint Set:
   ```c
   typedef struct DisjointSet {
       int parent[MAX_VERTICES];
       int rank[MAX_VERTICES];
   } DisjointSet;
   ```

### Key Functions
1. `createGraph(int V, int E)`: Initializes graph with V vertices and E edges
2. `addEdge(Graph* graph, int index, int src, int dest, int weight)`: Adds edge to graph
3. `kruskalMST(Graph* graph)`: Implements Kruskal's algorithm
4. `printAdjacencyMatrix(Graph* graph)`: Displays graph in matrix form

## Expected Output
The program outputs:
1. Adjacency matrix representation of the original graph
2. Edges selected in the MST
3. Total cost of the MST

## Algorithmic Steps
1. Sort all edges in non-decreasing order of weight
2. Initialize disjoint sets for all vertices
3. For each edge in sorted order:
   - If including the edge doesn't create a cycle, add it to MST
   - Use Union-Find to detect cycles
4. Continue until V-1 edges are selected or all edges are processed

## Error Handling
- Memory allocation validation
- Graph initialization checks
- Input validation for edges and vertices

## Technical Requirements
- C compiler (gcc recommended)
- Make utility
- Standard C libraries: stdio.h, stdlib.h

## Notes on Implementation
- The implementation uses path compression in Find operations
- Union by rank is implemented for optimal performance
- The adjacency matrix provides O(1) access to edge weights
- Edge list enables efficient sorting for Kruskal's algorithm
