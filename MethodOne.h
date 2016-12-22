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

double getEuclideanDistance(const Node& currNode, const Node& nodeToCompare);

void calculateWeightsAndRunGreedyTour(graphmap& theMap, double& totalDistance);

double tour(graphmap& theMap, minimumPriority queueOfEdges);

bool formsDegreeOfThree(Node& nodeOne, Node& nodeTwo);

bool formsCycle(graphmap& theMap, Node& node, Node& nodeToConnectWith, unsigned int& numberOfEdges); 

void connect(Node& nodeOne, Node& nodeTwo);

void traverseTour(graphmap& theMap);

#endif
