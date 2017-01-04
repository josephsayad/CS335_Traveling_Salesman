# Programming Assignment 2: Traveling Salesman Problem 

## About The Project

In this assignment: 3 heuristic approximation algorithms for the traveling salesman problem will be implemented.

1. Greedy TSP Algorithm 
2. Nearest Insertion Algorithm
3. Algorithm of Choice

## Data Structure Picks 

1. In method two, the Nearest insertion algorithm, I use a forward linked list for unvisited cities, and a vector for visited cities. But, why? Well - we only have to access the visited cities. But, for unvisited cities, there is a deletion following every edge added. To keep this constant, I'll keep a pointer to the closest city off the sub-tour. We can access, and delete this node from the list in constant time, or `O(1) steps`.

## Project Design

### Classes to be Implemented

1: `InputParser`

### A Driver Class: InputParser

An instance of the `InputParser` class will serve as *one* of the *driver programs*, which will read the a text file of

## How To Compile the Program

### Expected execution structure

The resulting program will compile, and execute via the following commands:

	make all
	./Project2 <input file name>

See the **data** directory for input files.
