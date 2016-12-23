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
        Edge *noEntry = new Edge(-1, nullptr, nullptr);
        theMatrix.at(rowNode).push_back(*noEntry);
      }

      /* Calculate edge between two distinct nodes */

      else {
        distance = getEuclideanDistance(theMap.at(rowNode + 1), theMap.at(columnNode + 1));
        Edge *nextEdge = new Edge(distance, &theMap.at(rowNode + 1), &theMap.at(columnNode + 1));
        theMatrix.at(rowNode).push_back(*nextEdge);
      }
    }
  }

  tour(theMap, theMatrix);
}

void tour(graphmap& theMap, adjacencyMatrix& theMatrix) {
  matrixPosition forSmallestEdge;

  forSmallestEdge = searchForMinimum(theMatrix);
  unsigned int keytoNodeOne = forSmallestEdge.first + 1;
  unsigned int keytoNodeTwo = forSmallestEdge.second + 1;

  /* Starting SubTour At This Connection */
  connect(theMap.at(keytoNodeOne), theMap.at(keytoNodeTwo));

  /* List of Cities on and off */
  vector<unvisited> offSubTour;
  vector<visited> onSubTour;

  onSubTour.push_back(theMap.at(keytoNodeOne));
  onSubTour.push_back(theMap.at(keytoNodeTwo));

  unsigned int key; 

  for(int node = 1; node <= theMap.size(); ++node) {
    if(theMap.at(node).name == keytoNodeOne || theMap.at(node).name == keytoNodeTwo) {
      /* Already added to tour! */
    }

    else {
      double distance = findDistanceOfClosestOnSubTour(theMatrix, theMap.at(node), onSubTour, key);
      offSubTour.push_back(make_pair(theMap.at(node), make_pair(distance, key)));
    }
  }
  
  cout << "Off sub-tour:\n"; 
  for(auto i : offSubTour) {
    cout << i.first << " with the shortest dist of " << i.second.first << " to node " << i.second.second << endl;;
  }
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

double findDistanceOfClosestOnSubTour(const adjacencyMatrix& theMatrix, const Node& node, const vector<visited>& onSubTour, unsigned int& minKey) {
  unsigned int currNode = onSubTour.at(0).name;
  double minDistance = theMatrix.at(currNode - 1).at(node.name - 1).weight;
  double distCompare = 0.0;

  for(int nodeOnTour = 0; nodeOnTour < onSubTour.size(); ++nodeOnTour) {
    if(onSubTour.at(nodeOnTour).name == currNode) { 
      minKey = onSubTour.at(nodeOnTour).name; 
    }
    
    else {
      distCompare = theMatrix.at(onSubTour.at(nodeOnTour).name - 1).at(node.name - 1).weight;
      
      if(distCompare < minDistance) {
        minKey = onSubTour.at(nodeOnTour).name;
        minDistance = distCompare;
      }
    }
  }

  
  return minDistance;
}

/* Convenience Function */

void printMatrix(const adjacencyMatrix& theMatrix) {
  for(unsigned int rowNode = 0; rowNode < theMatrix.size(); ++rowNode) {
    cout << "[Node" << rowNode + 1 << "] " << " "; 
    
    for(unsigned int columnNode = 0; columnNode < theMatrix.size(); ++columnNode) {
      cout << setw(10) << theMatrix.at(rowNode).at(columnNode).weight << " ";
    }

    cout << "\n";
  }
}
