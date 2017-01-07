//
//  MethodTwo.h
//  Project 2
//
//  Created by Joseph Sayad on 12/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODTWO_H
#define METHODTWO_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <iomanip>
#include <utility>
#include "Node.h"
#include "MethodOne.h" // connect()

using namespace std;

typedef unordered_map<unsigned int, Node> graphmap;
typedef vector<vector<Edge>> adjacencyMatrix;

typedef pair<unsigned int, unsigned int> matrixPosition;

typedef pair<Node, pair<unsigned int, double>> unvisited;
typedef Node visited;

void methodTwo(graphmap& theMap);
//  precondition: Takes an obejct of type unordered_map. 
//  Must include the C++ STL unordered_map header files. 
//  postcondition: Invokes tour() and all other functions. By passing totalDistance
//  to reference it's value is subject to change to the cost of the tour.

void storeEdgesInMatrix(graphmap& theMap);
//  precondition: Takes an obejct of type unordered_map and double by reference. 
//  Must include the C++ STL unordered_map and queue header files.
//  postcondition: Calculates all possible edges and fills an adjacency matrix 
//  with edge structs. 

matrixPosition searchForMinimum(adjacencyMatrix& theMatrix);
//  precondition: Definition of the matrixPosition type is required. 
//  postcondition: Returns the smallest edge in the adjacency matrix.

double closestCityOnSubTour(const adjacencyMatrix& theMatrix, const Node& node, const vector<visited>& onSubTour, unsigned int& minKey);
//  postcondition:  Select a city on the subtour, having the shortest 
//  distance to the node chosen from offSubTour.  

void updateUnvisited(unsigned int& nameOfNode, double& distance, unsigned int& nodeTo, list<unvisited>& offSubTour, graphmap& theMap);
//  postcondition: Updates offSubTour at every recursive call.

void nearestInsertion(vector<visited>& onSubTour, unvisited& closestNode, double& distTour, adjacencyMatrix& theMatrix, graphmap& theMap);

bool isAdjacent(unsigned int& nodeOne, unsigned int& nodeTwo, graphmap& theMap);
//  postcondition: Returns true if the two nodes are adjacent. 

void addToTour(vector<visited>& onSubTour, graphmap& theMap, unsigned int& nodeY, unsigned int& nodeX, unsigned int& nodeA);
//  postcondition: Adds a node to the sub-tour.

double getDistOfSubTour(unvisited& closestNode, unsigned int& nodeX, adjacencyMatrix& theMatrix);
//  postcondition: Gets the distance 3 nodes - two off and 1 on - that will grow the 
//  sub-tour.

void connectAlgoTwo(graphmap& theMap, unsigned int& nodeOne, unsigned int& nodeTwo, unsigned int& detach);
//  postcondition: Connects two nodes and is ready to disconnect an edge if in effort 
//  to grow the cycle. 

void tourHelper(graphmap& theMap, adjacencyMatrix& theMatrix);
//  precondition: Takes an obejct of type unordered_map and a vector of vectors 
//  by reference. Must include the C++ STL unordered_map and vector header files.
//  postcondition: Invokes the recursive tour function.

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, list<unvisited>& offSubTour, vector<visited>& onSubTour, double& totalDistance, unsigned int& recursiveCall);
//  precondition: Takes an obejct of type unordered_map, of std::vector<vector<Edge>>, 
//  unvisited, visited, double, and unsigned int by reference. Must include the C++ STL 
//  unordered_map and vector header files.
//  postcondition: Recursive function that builds a tour by logic of the Nearest Insertion 
//  algorithm. 

/* Convenience Functions */

void printMatrix(const adjacencyMatrix& theMatrix);
//  postcondition: Writes the matrix to console.

void traverseTourAlgoThree(graphmap& theMap);
//  postcondition: Writes the tour to console.

#endif
