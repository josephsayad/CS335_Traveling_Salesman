//
//  MethodOne.h
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//


#ifndef METHODONE_H
#define METHODONE_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include <math.h>
#include "Node.h"

using namespace std;

typedef unordered_map<unsigned int, Node> graphmap;
typedef priority_queue<Edge, vector<Edge>, GreaterThanByWeight> minimumPriority;

void methodOne(graphmap& theMap, double& totalDistance);
//  precondition: Takes an obejct of type unordered_map and double by reference. 
//  Must include the C++ STL unordered_map header files. 
//  postcondition: Invokes tour() and all other functions. By passing totalDistance
//  to reference it's value is subject to change to the cost of the tour.

double getEuclideanDistance(const Node& currNode, const Node& nodeToCompare);
//  precondition: Takes an objects of type Node by reference. Must include the Node 
//  header file.
//  postcondition: Returns a value of type double that represent the distance between
//  two points via the Euclidean distance formula. 

void getWeights(graphmap& theMap, double& totalDistance);
//  precondition: Takes an obejct of type unordered_map and double by reference. 
//  Must include the C++ STL unordered_map and queue header files.
//  postcondition: Calculates all possible edges and fills a priority queue with 
//  a collection of edge structs. This take O(n*n) steps.

double tour(graphmap& theMap, minimumPriority queueOfEdges);
//  precondition: Takes an obejct of type unordered_map and queue by reference. 
//  Must include the C++ STL unordered_map and queue header files.
//  postcondition: Returns the total cost of the tour. 

bool formsDegreeOfThree(Node& nodeOne, Node& nodeTwo);
//  precondition: Takes an objects of type Node by reference. Must include the Node 
//  header file.
//  postcondition: Returns a bool. If a connection between two vertices will cause 
//  a node to have a third degree: returns true.

bool formsCycle(graphmap& theMap, Node& node, Node& nodeToConnectWith, unsigned int& numberOfEdges);
//  precondition: Takes an objects of type Node, unordered_map, and unsigned int by 
//  reference. 
//  Must the C++ STL unordered_map and the Node Header file.
//  postcondition:

void connect(Node& nodeOne, Node& nodeTwo);
//  precondition: Takes an objects of type Node by reference. Must include the Node 
//  header file.
//  postcondition: Set the value of node struct's pointers. 

/* Convenience Functions */

void traverseTour(graphmap& theMap); 
//  postcondition: Writes the tour to console.


#endif
