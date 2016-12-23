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
#include <iomanip>
#include <utility>
#include "Node.h"
#include "MethodOne.h" // getEuclideanDistance()

using namespace std;


typedef unordered_map<unsigned int, Node> graphmap;
typedef vector<vector<Edge>> adjacencyMatrix;
typedef pair<unsigned int, unsigned int> matrixPosition;
typedef pair<Node, pair<double, unsigned int>> unvisited;
typedef Node visited;  

void methodTwo(graphmap& theMap);

void storeEdgesInMatrix(graphmap& theMap);

void tour(graphmap& theMap, adjacencyMatrix& theMatrix);

matrixPosition searchForMinimum(adjacencyMatrix& theMatrix);

double findDistanceOfClosestOnSubTour(const adjacencyMatrix& theMatrix, const Node& node, const vector<visited>& onSubTour, unsigned int& minKey);

/* Convenience Function */

void printMatrix(const adjacencyMatrix& theMatrix);

#endif
