//
//  MethodThree.h
//  Project 2
//
//  Created by Joseph Sayad on 12/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODTHREE_H
#define METHODTHREE_H

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include "Node.h"
#include "MethodTwo.h" // printMatrix()
#include "MethodOne.h" // connect()

typedef unordered_map<unsigned int, Node> graphmap;

typedef list<unsigned int> unvisited3;
typedef vector<unsigned int> visited3;

double methodThree(graphmap& theMap, double& totalDistance); 
//  precondition: Takes an obejct of type unordered_map and double by reference. 
//  Must include the C++ STL unordered_map header files. 
//  postcondition: Invokes tour() and all other functions. By passing totalDistance
//  to reference it's value is subject to change to the cost of the tour.

void storeEdgesInMatrixAlgoThree(graphmap& theMap, double& totalDistance);
//  precondition: Takes an obejct of type unordered_map and double by reference. 
//  Must include the C++ STL unordered_map and queue header files.
//  postcondition: Calculates all possible edges and fills an adjacency matrix 
//  with edge structs. 

double tourHelperThree(graphmap& theMap, adjacencyMatrix& theMatrix);
//  precondition: Takes an obejct of type unordered_map and a vector of vectors 
//  by reference. Must include the C++ STL unordered_map and vector header files.
//  postcondition: Invokes the recursive tour function.

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, unvisited3& offSubTour, visited3& onSubTour, double& totalDistance, unsigned int& RANDOM_NODE_KEY);
//  precondition: Takes an obejct of type unordered_map, of std::vector<vector<Edge>>, 
//  unvisited3, visited3, double, and unsigned int by reference. Must include the 
//  C++ STL unordered_map and vector header files.
//  postcondition: Recursive function that builds a tour by logic of the Nearest Neighbor
//  algorithm.

void setUnvisitedList(unvisited3& offSubTour, graphmap& theMap);
//  precondition: Takes an obejct of type unordered_map, and unvisited3& by reference.
//  postcondition: Updates the offSubTour list. 

void traverseTourTwo(graphmap& theMap, unsigned int startnode);
//  postcondition: Writes the tour to console.

#endif
