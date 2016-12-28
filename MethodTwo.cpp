//
//  MethodTwo.h
//  Project 2
//
//  Created by Joseph Sayad on 12/22/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include "MethodTwo.h"

using namespace std;

void methodTwo(graphmap& theMap) {
  storeEdgesInMatrix(theMap);
}

void storeEdgesInMatrix(graphmap& theMap) {
  adjacencyMatrix theMatrix;
  double distance = 0.0;

  /* Set number of nodes in Matrix */

  for(auto i : theMap) {
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

  tourHelper(theMap, theMatrix);
}

matrixPosition searchForMinimum(adjacencyMatrix& theMatrix) {
  matrixPosition minimumEdge = make_pair(0, 1);
  
  for(unsigned int rowNode = 0; rowNode < theMatrix.size(); ++rowNode) {
    for(unsigned int columnNode = 0; columnNode < theMatrix.size(); ++columnNode) {
      if(theMatrix.at(rowNode).at(columnNode).weight == -1) {/* Skip no entry edge */}
      
      else {
        if(theMatrix.at(rowNode).at(columnNode).weight < theMatrix.at(minimumEdge.first).at(minimumEdge.second).weight) {
          minimumEdge.first = rowNode;
          minimumEdge.second = columnNode;
        }
      }
    }
  }

  return minimumEdge;
}

void updateUnvisited(unsigned int& nameOfNode, double& distance, unsigned int& nodeTo, list<unvisited>& offSubTour) {
  for(auto it = offSubTour.begin(); it != offSubTour.end(); ++it) {
    if(it->first.name == nameOfNode) {
      it->second.first = nodeTo; 
      it->second.second = distance; 
    }
  }
}

void tourHelper(graphmap& theMap, adjacencyMatrix& theMatrix) {
  matrixPosition smallestEdge;

  /* Step 1: Find Smallest Edge in Matrix */

  smallestEdge = searchForMinimum(theMatrix);
  unsigned int keytoNodeOne = smallestEdge.first + 1;
  unsigned int keytoNodeTwo = smallestEdge.second + 1;

  /* Step 2: Start Sub-Tour */

  unsigned int no_val = 0;
  connectAlgoTwo(theMap, keytoNodeTwo, keytoNodeOne, no_val);

  /*  Just a Quick Note | On Data Structures picks see README
   *  *******************************************************
   *  offSubTour: a linked list of all cities not visited. 
   *  onSubTour:  a vector of all visited cities. 
   *  *******************************************************
   */

  list<unvisited> offSubTour;
  vector<visited> onSubTour;

  onSubTour.push_back(theMap.at(keytoNodeOne));
  onSubTour.push_back(theMap.at(keytoNodeTwo));

  theMap.at(keytoNodeOne).isOnTour = true;
  theMap.at(keytoNodeTwo).isOnTour = true;

  unsigned int recursiveCall = 0; // for recursion at 1 and beyond call update, don't push!
  double totalDistance = 0.0;
  tour(theMap, theMatrix, offSubTour, onSubTour, totalDistance, recursiveCall);
  cout << "Distance for Nearest Insertion Algorithm: " << totalDistance << endl;
}

void tour(graphmap& theMap, adjacencyMatrix& theMatrix, list<unvisited>& offSubTour, vector<visited>& onSubTour, double& totalDistance, unsigned int& recursiveCall) {
  /*  At each Node off the sub-tour find the closest city on the 
   *  sub-tour, and the distance to it below.
   */

  unsigned int minKey; 

  for(int node = 1; node <= theMap.size(); ++node) {
    if(theMap.at(node).isOnTour) { /*cout << theMap.at(node) << " on tour!\n";*/ }

    else {
      double distance = closestCityOnSubTour(theMatrix, theMap.at(node), onSubTour, minKey);
      if(recursiveCall == 0) { offSubTour.push_front(make_pair(theMap.at(node), make_pair(minKey, distance))); }
      else { updateUnvisited(theMap.at(node).name, distance, minKey, offSubTour); }
    }
  }

 /*  Find the city that has the smallest distance listed to the 
  *  subtour below. This will be city A. 
  */

  auto closestNode = offSubTour.begin();

  double smallestDist = closestNode->second.second, distCompare = 0.0;

  for(auto it = offSubTour.begin(); it != offSubTour.end(); ++it) {
    distCompare = it->second.second;
    
    if(distCompare < smallestDist) {
      closestNode = it;
      smallestDist = distCompare;
    }
  }

  for(auto it = offSubTour.begin(); it != offSubTour.end(); ++it) {
    if(it == closestNode) {
      offSubTour.erase(it);
    }
  }
  
  nearestInsertion(onSubTour, *closestNode, totalDistance, theMatrix, theMap);
  ++recursiveCall; 

  if(recursiveCall == theMap.size() - 2) { 
    traverseTourAlgoThree(theMap);
    return; 
  }

  tour(theMap, theMatrix, offSubTour, onSubTour, totalDistance, recursiveCall);
}

double closestCityOnSubTour(const adjacencyMatrix& theMatrix, const Node& node, const vector<visited>& onSubTour, unsigned int& minKey) {
  unsigned int currNode = onSubTour.at(0).name;
  minKey = onSubTour.at(0).name; 
  
  double minDistance = theMatrix.at(currNode - 1).at(node.name - 1).weight;
  double distCompare = 0.0;

  for(int nodeCompare = 0; nodeCompare < onSubTour.size(); ++nodeCompare) {
    if(onSubTour.at(nodeCompare).name == currNode) { /* Skip */ }
    
    else {
      distCompare = theMatrix.at(onSubTour.at(nodeCompare).name - 1).at(node.name - 1).weight;

      if(distCompare < minDistance) {
        minKey = onSubTour.at(nodeCompare).name;
        minDistance = distCompare;
      }
    }
  }

  return minDistance;
}

void nearestInsertion(vector<visited>& onSubTour, unvisited& closestNode, double& distTour, adjacencyMatrix& theMatrix, graphmap& theMap) {
  /*  Find the second closest city to the unvisited city, which is 
   *  already in our sub-tour. This is city X.  
   */

  unsigned int listIndex;

  //  Avoid picking node Y as the second closest node. 
  if(onSubTour.at(0).name != closestNode.second.first) {
    listIndex = 0;
  }
  else {
    listIndex = 1;
  }

  unsigned int secondClosestNode = onSubTour.at(listIndex).name;
  double smallestDist = theMatrix.at(secondClosestNode - 1).at(closestNode.first.name - 1).weight, distCompare = 0.0;
  
  for(unsigned int i = 0; i < onSubTour.size(); ++i) {

    if(onSubTour.at(i).name != closestNode.second.first && isAdjacent(onSubTour.at(i).name, closestNode.second.first, theMap)) {
      distCompare = theMatrix.at(onSubTour.at(i).name - 1).at(closestNode.first.name - 1).weight;
      
      // cout << "Node " << onSubTour.at(i) << " makes it in!\n";

      if(distCompare < smallestDist) {
        smallestDist = distCompare;
        secondClosestNode = onSubTour.at(i).name;
      }
    }
  }

  // cout << closestNode.first << " to " << secondClosestNode << " and " << closestNode.second.first << endl;
  double distToAdd = getDistOfSubTour(closestNode, secondClosestNode, theMatrix);
  distTour += distToAdd;
  
  addToTour(onSubTour, theMap, closestNode.second.first, secondClosestNode, closestNode.first.name);
}

bool isAdjacent(unsigned int& nodeOne, unsigned int& nodeTwo, graphmap& theMap) {
  if(theMap.at(nodeOne).ptrOne != nullptr && theMap.at(nodeOne).ptrTwo != nullptr) {
    return theMap.at(nodeOne).ptrOne->name == theMap.at(nodeTwo).name || theMap.at(nodeOne).ptrTwo->name == theMap.at(nodeTwo).name;
  }

  else if(theMap.at(nodeOne).ptrOne != nullptr && theMap.at(nodeOne).ptrTwo == nullptr) {
    return theMap.at(nodeOne).ptrOne->name == theMap.at(nodeTwo).name;
  }
  
  else if(theMap.at(nodeOne).ptrTwo != nullptr && theMap.at(nodeOne).ptrOne == nullptr) {
    return theMap.at(nodeOne).ptrTwo->name == theMap.at(nodeTwo).name;
  }

  else {
    return false;
  }
}

double getDistOfSubTour(unvisited& closestNode, unsigned int& nodeX,  adjacencyMatrix& theMatrix) {
  double AX = theMatrix.at(closestNode.first.name - 1).at(nodeX - 1).weight;
  double AY = theMatrix.at(closestNode.first.name - 1).at(closestNode.second.first - 1).weight;
  double XY = theMatrix.at(nodeX - 1).at(closestNode.second.first - 1).weight;

  return AX + AY - XY;
}

void addToTour(vector<visited>& onSubTour, graphmap& theMap, unsigned int& nodeY, unsigned int& nodeX, unsigned int& nodeA) {
  theMap.at(nodeA).isOnTour = true;

  connectAlgoTwo(theMap, nodeY, nodeA, nodeX);
  connectAlgoTwo(theMap, nodeX, nodeA, nodeY);

  onSubTour.push_back(theMap.at(nodeA));
}

void connectAlgoTwo(graphmap& theMap, unsigned int& nodeOne, unsigned int& nodeTwo, unsigned int& detach) {
  if(theMap.at(nodeOne).hasTwoEdges()) {
    // cout << "Two edges!\n";

    if(theMap.at(nodeOne).ptrOne->name == detach) {
      theMap.at(nodeOne).ptrOne = nullptr;
      connectAlgoTwo(theMap, nodeOne, nodeTwo, detach);
    }

    else if(theMap.at(nodeOne).ptrTwo->name == detach) {
      theMap.at(nodeOne).ptrTwo = nullptr;
      connectAlgoTwo(theMap, nodeOne, nodeTwo, detach);
    }
  }

  else {
    // cout << "Does not have two edges!\n";
    if(theMap.at(nodeOne).ptrOne == nullptr) { // Node with 1 free edge
      if(theMap.at(nodeTwo).ptrOne == nullptr) {
        theMap.at(nodeOne).ptrOne = &theMap.at(nodeTwo);
        theMap.at(nodeTwo).ptrOne = &theMap.at(nodeOne);
      }

      else {
        theMap.at(nodeOne).ptrOne = &theMap.at(nodeTwo);
        theMap.at(nodeTwo).ptrTwo = &theMap.at(nodeOne);
      }
    }

    else if(theMap.at(nodeOne).ptrTwo == nullptr) { // Node with 1 free edge
      if(theMap.at(nodeTwo).ptrOne == nullptr) {
        theMap.at(nodeOne).ptrTwo = &theMap.at(nodeTwo);
        theMap.at(nodeTwo).ptrOne = &theMap.at(nodeOne);
      }

      else {
        theMap.at(nodeOne).ptrTwo = &theMap.at(nodeTwo);
        theMap.at(nodeTwo).ptrTwo = &theMap.at(nodeOne);
      }
    }
  }
}

/* Convenience Functions */

void printMatrix(const adjacencyMatrix& theMatrix) {
  for(unsigned int rowNode = 0; rowNode < theMatrix.size(); ++rowNode) {
    cout << "[Node" << rowNode + 1 << "] " << " "; 
    
    for(unsigned int columnNode = 0; columnNode < theMatrix.size(); ++columnNode) {
      cout << setw(10) << theMatrix.at(rowNode).at(columnNode).weight << " ";
    }

    cout << "\n";
  }
}

void traverseTourAlgoThree(graphmap& theMap) {
  Node *currNode; 
  Node *prevNode;  

  /* Start at any node: Node with key 1 */
  
  prevNode = theMap.at(1).ptrTwo;
  currNode = &theMap.at(1);
  
  cout << "Tour: " << currNode->name << " -> ";

  for(int i = 0; i < theMap.size(); ++i) {
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