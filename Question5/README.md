# Shortest Path System Using Bellman-Ford Algorithm

## Project Overview
This implementation solves John's traveling salesman optimization problem using the Bellman-Ford algorithm to find the cheapest paths from city A to all other cities in the network.

## Graph Specification
- Cities: 7 nodes (labeled A through G)
- Travel costs as edge weights
- Undirected edges representing travel fares between cities

## Time Complexity Analysis
1. Bellman-Ford Algorithm:
   - Time Complexity: O(VE) where:
     - V is the number of vertices (cities)
     - E is the number of edges (routes)
   - Space Complexity: O(V) for storing distances and predecessors

## Project Structure
```
.
├── include/
│   └── shortest_path.h    # Header files
├── src/
│   └── shortest_path.c    # Implementation files
├── main.c                 # Main program
├── Makefile              # Build configuration
└── README.md             # Documentation
```

## How to Build and Run

1. Create necessary directories:
   ```bash
   make init
   ```

2. Compile the program:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./path_finder
   ```

4. Clean build files:
   ```bash
   make clean
   ```

## Implementation Details

### Key Components
1. Graph representation using edge list
2. Bellman-Ford algorithm implementation
3. Path reconstruction and cost calculation
4. Negative cycle detection

### Key Functions
- `createGraph()`: Initializes the city network
- `addEdge()`: Adds a route between two cities
- `bellmanFord()`: Implements the shortest path algorithm
- `printPaths()`: Displays all shortest paths and costs

## Output Format
The program outputs:
1. Shortest path to each city from city A
2. Total cost for each path
3. Complete route information

## Features
1. Finds cheapest paths from source city A to all other cities
2. Detects negative cycles (if present)
3. Provides complete path information
4. Calculates total cost for each route

## Error Handling
- Memory allocation validation
- Negative cycle detection
- Path existence validation
- Graph boundary checks

## Technical Requirements
- C compiler (gcc recommended)
- Make utility
- Standard C libraries

## Advantages of Bellman-Ford for This Problem
1. Handles negative edge weights (if present)
2. Detects negative cycles
3. Guarantees shortest paths from source
4. Simple to implement and maintain

## Future Improvements
1. Support for dynamic route updates
2. Multiple starting cities
3. Time-based cost variations
4. Interactive city selection
5. Path visualization

## References
1. Introduction to Algorithms (CLRS), Chapter 24: Single-Source Shortest Paths
2. Network Flows: Theory, Algorithms, and Applications
