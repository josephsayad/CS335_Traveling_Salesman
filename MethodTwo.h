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

void storeEdgesInMatrix(graphmap& theMap);

matrixPosition searchForMinimum(adjacencyMatrix& theMatrix);

double closestCityOnSubTour(const adjacencyMatrix& theMatrix, const Node& node, const vector<visited>& onSubTour, unsigned int& minKey);

void updateUnvisited(unsigned int& nameOfNode, double& distance, unsigned int& nodeTo, list<unvisited>& offSubTour);

void nearestInsertion(vector<visited>& onSubTour, unvisited& closestNode, double& distTour, adjacencyMatrix& theMatrix, graphmap& theMap);

bool isAdjacent(unsigned int& nodeOne, unsigned int& nodeTwo, graphmap& theMap);

void addToTour(vector<visited>& onSubTour, graphmap& theMap, unsigned int& nodeY, unsigned int& nodeX, unsigned int& nodeA);

double getDistOfSubTour(unvisited& closestNode, unsigned int& nodeX,  adjacencyMatrix& theMatrix);

void connectAlgoTwo(graphmap& theMap, unsigned int& nodeOne, unsigned int& nodeTwo, unsigned int& detach);

void tourHelper(graphmap& theMap, adjacencyMatrix& theMatrix);

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, list<unvisited>& offSubTour, vector<visited>& onSubTour, double& totalDistance, unsigned int& recursiveCall);

/* Convenience Functions */

void printMatrix(const adjacencyMatrix& theMatrix);

void traverseTourAlgoThree(graphmap& theMap);

#endif
