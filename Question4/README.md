# Contact Tracing System Implementation

## Project Overview
This implementation uses Breadth-First Search (BFS) to track contact patterns in a disease outbreak scenario. The program identifies immediate contacts of a suspected infected person and determines the person at highest risk based on contact duration.

## Graph Specification
The contact network consists of:
- 7 people (labeled A through G)
- Contact durations (in minutes) between people as edges
- Undirected weighted edges representing mutual contact time

## Time Complexity Analysis
1. BFS Algorithm:
   - Time Complexity: O(V + E) where:
     - V is the number of vertices (people)
     - E is the number of edges (contact relationships)
   - Space Complexity: O(V) for the queue and visited array

2. Finding Highest Risk Contact:
   - Time Complexity: O(V) as it's integrated into the BFS
   - Space Complexity: O(1) for storing maximum values

## Project Structure
```
.
├── include/
│   └── contact_trace.h    # Header files
├── src/
│   └── contact_trace.c    # Implementation files
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
   ./contact_tracer
   ```

4. Clean build files:
   ```bash
   make clean
   ```

## Usage Instructions
1. When prompted, enter a letter (A-G) representing the suspected infected person
2. The program will display:
   - All immediate contacts of the suspected person
   - Contact duration with each person
   - The person at highest risk (longest contact duration)
3. Enter 'Q' to quit the program

## Implementation Details

### Key Components
1. Graph representation using adjacency matrix
2. BFS implementation for contact tracing
3. Risk assessment based on contact duration

### Key Functions
- `createGraph()`: Initializes the contact network
- `addContact()`: Adds contact relationship between two people
- `performBFS()`: Implements BFS for contact tracing
- `printContactTracing()`: Displays results

## Output Format
The program outputs:
1. List of immediate contacts with contact durations
2. Identification of the person at highest risk
3. Total contact time with the highest risk person

## Error Handling
- Input validation for person identifiers
- Memory allocation validation
- Graph boundary checks

## Technical Requirements
- C compiler (gcc recommended)
- Make utility
- Standard C libraries

## Future Improvements
1. Support for larger networks
2. Multiple risk factors beyond contact duration
3. Contact path tracing
4. Time-based contact analysis
5. Risk level categorization

## References
1. Introduction to Algorithms (CLRS), Chapter 22: Elementary Graph Algorithms
2. Graph Theory with Applications to Engineering and Computer Science
