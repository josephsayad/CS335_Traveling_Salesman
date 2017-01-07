# Programming Assignment 2: Traveling Salesman Problem (TSP)

## About the Project

In this project: 3 heuristic approximation algorithms will be implemented for the traveling salesman problem.

1. Greedy TSP Algorithm 
2. Nearest Insertion Algorithm
3. Nearest Neighbor Algorithm

## Project Design

### Classes to be Implemented

1: `Country`
2: `InputParser`
3: `MethodControl`

### Structs to be Implemented

1: `Node`
2: `Edge`

## Algorithmic Analysis

### Greedy TSP Algorithm 

Implemented in the `MethodOne.cpp` and `MethodOne.h` files. 

Step 1: Calculate all possible edges `(n^2 operations)`.
Step 2: Sort all edges via underlying heap sort `(log n operations)`.
Step 3: Select the shortest edge from a collection of edges `(1 operation)`.
Step 4: If there are not `N` edges in the tour, repeat Step 2 `(1 operation)`. 

Big `O(n^2 log n)` time complexity.

### Nearest Insertion Algorithm 

Implemented in the `MethodTwo.cpp` and `MethodTwo.h` files. 

Step 1: Find the smallest edge `(n^2 operations)`.
Step 2: Select a node off the subtour with the shortest distance to any of the nodes on the subtour `(n operations)`.
Step 3: Find an edge on the subtour such that the cost of inserting is the smallest possible cost `(n operations)`.
Step 4: Loop to Step 2 (1 operation).

Big `O(n^2)` time complexity.

### Nearest Insertion Algorithm

Implemented in the `MethodThree.cpp` and `MethodThree.h` files. 

Step 1: Calculate all possible edges `(n^2 operations)`.
Step 2: Pick a random node `(1 operation)`.
Step 3: Visit the nearest, unvisited node `(n operations)`.
Step 4: Loop to Step 3 if there exists unvisited nodes `(1 operation)`.
Step 5: Return to first node `(1 operation)`.

Big `O(n^2)` time complexity.

## How To Compile the Program

### Expected execution structure

The resulting program will compile, and execute via the following commands:

	make all
	./FindTour <input file name>

See the **data** directory for input files.
