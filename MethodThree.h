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

void storeEdgesInMatrixAlgoThree(graphmap& theMap, double& totalDistance);

double tourHelperThree(graphmap& theMap, adjacencyMatrix& theMatrix);

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, unvisited3& offSubTour, visited3& onSubTour, double& totalDistance, unsigned int& RANDOM_NODE_KEY);

void setUnvisitedList(unvisited3& offSubTour, graphmap& theMap);

void traverseTourTwo(graphmap& theMap, unsigned int startnode);

#endif
 