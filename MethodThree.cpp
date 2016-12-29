//
//  MethodThree.cpp
//  Project 2
//
//  Created by Joseph Sayad on 12/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include "MethodThree.h"

using namespace std;

/* Step 1: Start at a Random Node */

unsigned int RANDOM_NODE_KEY = 1;
const unsigned int FIRST_NODE = 1;

double methodThree(graphmap& theMap, double& totalDistance) {
  storeEdgesInMatrixAlgoThree(theMap, totalDistance);
  traverseTourTwo(theMap, FIRST_NODE);
  return totalDistance;
}

void storeEdgesInMatrixAlgoThree(graphmap& theMap, double& totalDistance) {
  adjacencyMatrix theMatrix;
  double distance = 0.0;

  /* Set number of nodes in Matrix */

  for(unsigned int i = 0; i < theMap.size(); ++i) {
    vector<Edge> *column = new vector<Edge>;
    theMatrix.push_back(*column);
  }
  
  /* Store Edges in Matrix */
  for (unsigned int rowNode = 0; rowNode < theMatrix.size(); ++rowNode) {
    for(unsigned int columnNode = 0; columnNode < theMatrix.size(); ++columnNode) {
      
      /* Cannot form an edge to same Node */
      
      if(rowNode == columnNode) {
        Edge *noEntry = new Edge(-1, -1, -1);
        theMatrix.at(rowNode).push_back(*noEntry);
      }

      /* Calculate edge between two distinct nodes */

      else {
        distance = getEuclideanDistance(theMap.at(rowNode + 1), theMap.at(columnNode + 1));
        
        Edge *nextEdge = new Edge(distance, rowNode + 1, columnNode + 1);
        theMatrix.at(rowNode).push_back(*nextEdge);
      }
    }
  }
  
  totalDistance = tourHelperThree(theMap, theMatrix);
}

double tourHelperThree(graphmap& theMap, adjacencyMatrix& theMatrix) {
  unvisited3 offSubTour; 
  visited3 onSubTour;

  theMap.at(RANDOM_NODE_KEY).isOnTour = true;
  onSubTour.push_back(theMap.at(RANDOM_NODE_KEY).name);

  setUnvisitedList(offSubTour, theMap);
  
  double totalDistance = 0.0;
  tour(theMap, theMatrix, offSubTour, onSubTour, totalDistance, RANDOM_NODE_KEY);
  
  return totalDistance;
}

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, unvisited3& offSubTour, visited3& onSubTour, double& totalDistance, unsigned int& RANDOM_NODE_KEY) {
  auto minKey = offSubTour.begin();
  double minDistance = theMatrix.at(*minKey - 1).at(RANDOM_NODE_KEY - 1).weight, distToCompare = 0.0;

  for(auto it = offSubTour.begin(); it != offSubTour.end(); ++it) {
    if(theMap.at(*it).isOnTour) { /* On tour - skip */ }
    else {
      distToCompare = theMatrix.at(*it - 1).at(RANDOM_NODE_KEY - 1).weight;

      if(distToCompare < minDistance) {
        minKey = it; 
        minDistance = distToCompare;
      }
    }
  }

  totalDistance += minDistance;
  connect(theMap.at(RANDOM_NODE_KEY), theMap.at(*minKey));

  theMap.at(RANDOM_NODE_KEY).isOnTour = true;
  onSubTour.push_back(theMap.at(RANDOM_NODE_KEY).name);
  offSubTour.erase(minKey);
  RANDOM_NODE_KEY = *minKey;

  if(offSubTour.size() == 0) {
  	connect(theMap.at(*minKey), theMap.at(FIRST_NODE));
    totalDistance += theMatrix.at(*minKey - 1).at(FIRST_NODE - 1).weight;
    return;
  }

  tour(theMap, theMatrix, offSubTour, onSubTour, totalDistance, RANDOM_NODE_KEY);
}

void setUnvisitedList(unvisited3& offSubTour, graphmap& theMap) {
  for(unsigned int node = 1; node <= theMap.size(); ++node)
    if(theMap.at(node).isOnTour) { /* Skip */ }
    else { offSubTour.push_front(node); }
}

void traverseTourTwo(graphmap& theMap, unsigned int startnode) {
  Node *currNode; 
  Node *prevNode;  

  /* Start at any node: Node with key 1 */
  
  prevNode = theMap.at(startnode).ptrTwo;
  currNode = &theMap.at(startnode);
  
  cout << "Tour: " << currNode->name << " -> ";

  for(unsigned int i = 0; i < theMap.size(); ++i) {
    if(currNode->ptrOne != prevNode) {
      prevNode = currNode;
      currNode = currNode->ptrOne;
    }

    else {
      prevNode = currNode;
      currNode = currNode->ptrTwo;
    }

    if(i == theMap.size() - 1) { cout << currNode->name << "\n"; }
    else { cout << currNode->name << " -> " << " "; } 
  }
}
