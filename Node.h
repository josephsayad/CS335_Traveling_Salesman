//
//  Node.h
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node {
  unsigned int name;
  double x_coord;
  double y_coord;
  bool isOnTour;

  Node *ptrOne;
  Node *ptrTwo; 

  /* Overloading the Struct Constructor */
  
  Node(const unsigned int& init_name, const double& init_x, const double& init_y) 
    : name{init_name}, x_coord{init_x}, y_coord{init_y}, isOnTour{false},
      ptrOne{nullptr}, ptrTwo{nullptr} {}

  /* Overloading the operator<< */
  
  friend ostream& operator<<(ostream& out, const Node& node) {
    out << node.name;
    return out;
  }

  bool hasTwoEdges() const { 
    return ptrOne != nullptr && ptrTwo != nullptr; 
  }

  bool hasOneEdge() const {
    if(ptrOne != nullptr && ptrTwo == nullptr) { return true; }
    if(ptrOne == nullptr && ptrTwo != nullptr) { return true; }
    else { return false; }
  }

  bool isAdjacent(Node& nodeToCompare) const {
   return ptrOne == &nodeToCompare || ptrTwo == &nodeToCompare;
  }
};

struct Edge {
  double weight;
    
  unsigned int nameOfNodeOne;
  unsigned int nameOfNodeTwo;

  Edge(const double& init_weight, const unsigned init_node_one, const unsigned init_node_two) 
    : weight{init_weight}, nameOfNodeOne{init_node_one}, nameOfNodeTwo{init_node_two}  {}
};

struct GreaterThanByWeight {
  bool operator()(const Edge& lhs, const Edge& rhs) const {
    return lhs.weight > rhs.weight;
  }
};

#endif
