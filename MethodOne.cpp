//
//  MethodOne.cpp
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include "MethodOne.h"

using namespace std;

void methodOne(graphmap& theMap, double& totalDistance) {
  getWeights(theMap, totalDistance);
  traverseTour(theMap);
}

void getWeights(graphmap& theMap, double& totalDistance) {
  minimumPriority queueOfEdges;
  double distance = 0.0;

  /* For each node in a collection of N nodes... */

  for (unsigned int keyToCurrNode = 1; keyToCurrNode <= theMap.size(); ++keyToCurrNode) {
    
    /* Caluclate the distance to all other nodes */

    for(unsigned int otherNodeKey = 1; otherNodeKey <= theMap.size(); ++otherNodeKey) {
      if(otherNodeKey == keyToCurrNode) { /* Do Nothing */ }
      
      /* Store distances in a Priority Queue : Underlying Heap Sort */

      else {
        distance = getEuclideanDistance(theMap.at(keyToCurrNode), theMap.at(otherNodeKey));
        Edge *nextEdge = new Edge(distance, theMap.at(keyToCurrNode).name, theMap.at(otherNodeKey).name);
        queueOfEdges.push(*nextEdge);
      } 
    }
  }
  
  totalDistance = tour(theMap, queueOfEdges);
}

double getEuclideanDistance(const Node& currNode, const Node& nodeToCompare) {
  double x_value = pow((currNode.x_coord - nodeToCompare.x_coord), 2.0);
  double y_value = pow((currNode.y_coord - nodeToCompare.y_coord), 2.0);

  return sqrt(x_value + y_value);
}

double tour(graphmap& theMap, minimumPriority queueOfEdges) {
  const unsigned int sizeOfQueue = queueOfEdges.size();
  unsigned int numberOfEdges = 0;
  double costOfTour = 0.0;

  for(int i = 0; i < sizeOfQueue; ++i) {
    const Edge *edgeToAdd = &queueOfEdges.top();
    unsigned int keyOne, keyTwo;

    keyOne = edgeToAdd->nameOfNodeOne;
    keyTwo = edgeToAdd->nameOfNodeTwo;
  
    if(formsDegreeOfThree(theMap.at(keyOne), theMap.at(keyTwo))) {}

    else if(formsCycle(theMap, theMap.at(keyOne), theMap.at(keyTwo), numberOfEdges)) {}

    else {
      costOfTour += edgeToAdd->weight;
      connect(theMap.at(keyOne), theMap.at(keyTwo));
      ++numberOfEdges;
    }

    queueOfEdges.pop();
  }

  return costOfTour;
}

bool formsDegreeOfThree(Node& nodeOne, Node& nodeTwo) {
  return nodeOne.hasTwoEdges() || nodeTwo.hasTwoEdges();
}

bool formsCycle(graphmap& theMap, Node& node, Node& nodeToConnectWith, unsigned int& numberOfEdges) {

  // A cycle can occur in this case...
  if(node.hasOneEdge() && nodeToConnectWith.hasOneEdge()) {
    Node *currNode; 
    Node *prevNode;  

    prevNode = nullptr; 
    currNode = &node;

    /* Traversal */
    while(currNode->ptrOne != nullptr || currNode->ptrTwo != nullptr) {
      if(currNode->name == nodeToConnectWith.name) {
        break;
      } 

      if(currNode->ptrOne != nullptr && currNode->ptrOne != prevNode) {      
        prevNode = currNode;
        currNode = currNode->ptrOne;
      }

      else if(currNode->ptrTwo != nullptr && currNode->ptrTwo != prevNode) {
        prevNode = currNode;
        currNode = currNode->ptrTwo;
      }

      else {
        break;
      }
    }

    /* Comparing Nodes */
    
    if(currNode->name == nodeToConnectWith.name) {
      
      /* If this is edge n - 1, then add! */
      if(numberOfEdges == theMap.size() - 1) { 
        return false; 
      }

      else { 
        return true; 
      }
    }

    else {
      return false;
    }
  }

  // Both nodes need to have an edge for cycle to occur...
  else { return false; }
}

void connect(Node& nodeOne, Node& nodeTwo) {
  if(nodeOne.ptrOne == &nodeTwo && nodeOne.ptrTwo == &nodeTwo) {
    nodeOne.ptrTwo = nullptr;
  }
  else if(nodeTwo.ptrOne == &nodeTwo && nodeOne.ptrTwo == &nodeTwo) {
    nodeTwo.ptrTwo = nullptr;
  }

  else {
  if(nodeOne.ptrOne == nullptr && nodeTwo.ptrTwo == nullptr) {
    nodeOne.ptrOne = &nodeTwo;
    nodeTwo.ptrTwo  = &nodeOne;
  }

  else if(nodeOne.ptrOne != nullptr && nodeTwo.ptrTwo != nullptr) {
    nodeOne.ptrTwo  = &nodeTwo;
    nodeTwo.ptrOne = &nodeOne;
  }
 
  else if(nodeOne.ptrOne != nullptr && nodeTwo.ptrTwo == nullptr) {
    nodeOne.ptrTwo  = &nodeTwo;
    nodeTwo.ptrTwo  = &nodeOne;
  }

  else if(nodeOne.ptrOne == nullptr && nodeTwo.ptrTwo != nullptr) {
    nodeOne.ptrOne = &nodeTwo;
    nodeTwo.ptrOne = &nodeOne;
  }
}
} 


void traverseTour(graphmap& theMap) {
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
